class_name LabProgram
extends RefCounted
## Bounded interpreter for the recovered arithmetic/event-program vocabulary.
signal command_requested(command: String, arguments: Array)

var model: LabModel
var variables: Dictionary = {"t": 0.0}
var bindings: Array = []
var code := ""
var errors: Array[String] = []
var max_instructions := 1024
const FUNCTIONS := {"cos": "cos", "arccos": "acos", "acos": "acos", "sin": "sin",
	"arcsin": "asin", "asin": "asin", "tan": "tan", "arctan": "atan", "atan": "atan",
	"exp": "exp", "fabs": "abs", "abs": "abs", "log": "log", "log10": "log10",
	"sqrt": "sqrt", "pow": "pow", "signum": "sign", "sign": "sign", "min": "min", "max": "max"}

func configure(lab: LabModel) -> void:
	model = lab

func set_variable(name: String, value: float) -> bool:
	if name.strip_edges().is_empty() or not is_finite(value):
		return false
	variables[name] = value
	return true

func bind_variable(name: String, vessel_id: int, species: String = "", metric: String = "moles") -> bool:
	if name.strip_edges().is_empty() or metric not in ["moles", "mass", "temperature", "pH", "time"]:
		return false
	for index in range(bindings.size() - 1, -1, -1):
		if str(bindings[index].get("name", "")) == name:
			bindings.remove_at(index)
	bindings.append({"name": name, "vessel_id": vessel_id, "species": species, "metric": metric})
	if not variables.has(name):
		variables[name] = 0.0
	return true

func _refresh_bindings() -> void:
	if model == null:
		return
	variables["t"] = model.elapsed
	for binding in bindings:
		var name := str(binding.get("name", ""))
		var metric := str(binding.get("metric", "moles"))
		if metric == "time":
			variables[name] = model.elapsed
			continue
		var vessel: Dictionary = model.get_vessel(int(binding.get("vessel_id", -1)))
		if vessel.is_empty():
			errors.append("变量 %s：容器不存在" % name)
			continue
		var species := str(binding.get("species", ""))
		match metric:
			"temperature": variables[name] = float(vessel.get("temperature", 20.0))
			"pH": variables[name] = model.ph(vessel)
			"moles": variables[name] = float(vessel.get("contents", {}).get(species, 0.0))
			"mass":
				var reagent: Dictionary = model._species.get(species, {})
				if reagent.is_empty():
					errors.append("变量 %s：药品 %s 不存在" % [name, species])
					continue
				variables[name] = float(vessel.get("contents", {}).get(species, 0.0)) * float(reagent.get("molar_mass", 0.0))

func expand(text: String) -> String:
	var regex := RegEx.new()
	regex.compile("\\{([^{}]+)\\}")
	var result := text
	var hits := regex.search_all(text)
	for index in range(hits.size() - 1, -1, -1):
		var hit: RegExMatch = hits[index]
		var name := hit.get_string(1)
		if variables.has(name):
			var value := String.num(float(variables[name]), 6)
			result = result.substr(0, hit.get_start()) + value + result.substr(hit.get_end())
		else:
			errors.append("标签变量不存在：" + name)
	return result

func evaluate_frame() -> Array[String]:
	errors.clear()
	var kernel = preload("res://scripts/original/original_program.gd")
	var result: Dictionary = kernel.frame([{"lines":code.replace("\r", "").split("\n")}],variables)
	if not result.ok: errors.append(str(result.error))
	return errors.duplicate()

func _parse_statement(line: String) -> Dictionary:
	var regex := RegEx.new()
	regex.compile("^判断([0-9]*):如果\\((.*)\\)则执行$")
	var hit := regex.search(line)
	if hit:
		return {"kind": "if", "id": hit.get_string(1), "expression": hit.get_string(2)}
	regex.compile("^循环([0-9]*):当\\((.*)\\)成立$")
	hit = regex.search(line)
	if hit:
		return {"kind": "while", "id": hit.get_string(1), "expression": hit.get_string(2)}
	regex.compile("^结束(判断|循环)([0-9]*)$")
	hit = regex.search(line)
	if hit:
		return {"kind": "end", "block": "if" if hit.get_string(1) == "判断" else "while", "id": hit.get_string(2)}
	if line.begins_with("if ") or line.begins_with("while "):
		var kind := "if" if line.begins_with("if ") else "while"
		return {"kind": kind, "id": "", "expression": line.substr(kind.length()).strip_edges().trim_suffix(":").trim_suffix(" then").strip_edges()}
	if line in ["end", "endif", "endwhile"]:
		return {"kind": "end", "block": {"endif": "if", "endwhile": "while"}.get(line, ""), "id": ""}
	if line in ["简单发声", "重新运行", "暂停", "停止", "退出"]:
		return {"kind": "command", "command": line, "arguments": []}
	for command in ["播放声音", "打开"]:
		if line.begins_with(command + "(") and line.ends_with(")"):
			return {"kind": "command", "command": command, "arguments": [line.substr(command.length() + 1, line.length() - command.length() - 2).strip_edges().trim_prefix('"').trim_suffix('"')]}
	var equal := line.find("=")
	if equal > 0 and line.substr(equal, 2) != "==":
		var name := line.substr(0, equal).strip_edges().trim_suffix(":")
		if not name.is_empty() and not name.contains(" ") and not name.contains("<") and not name.contains(">"):
			return {"kind": "assign", "name": name, "expression": line.substr(equal + 1).strip_edges()}
	return {"kind": "error"}

func evaluate_expression(source: String, condition: bool = false) -> Variant:
	if condition:
		errors.append("原版条件表达式分支尚未完成移植。")
		return null
	var result := preload("res://scripts/original/original_program.gd").expression(source.replace(" ",""),variables)
	if not result.ok:
		errors.append(str(result.error)); return null
	return float(result.value)

func _rewrite_functions(text: String) -> String:
	var regex := RegEx.new()
	regex.compile("([A-Za-z_][A-Za-z_0-9]*)\\s*\\(")
	var hits := regex.search_all(text)
	for index in range(hits.size() - 1, -1, -1):
		var hit: RegExMatch = hits[index]
		var name := hit.get_string(1)
		if not FUNCTIONS.has(name):
			continue
		if name != "log10":
			text = text.substr(0, hit.get_start(1)) + FUNCTIONS[name] + text.substr(hit.get_end(1))
			continue
		var depth := 1
		var end := hit.get_end()
		while end < text.length() and depth > 0:
			if text[end] == "(": depth += 1
			elif text[end] == ")": depth -= 1
			end += 1
		if depth != 0:
			return ""
		var argument := text.substr(hit.get_end(), end - hit.get_end() - 1)
		text = text.substr(0, hit.get_start()) + "(log(" + argument + ")/log(10.0))" + text.substr(end)
	return text

func _regex_escape(value: String) -> String:
	var result := ""
	for character in value:
		if character in "\\.^$|?*+()[]{}":
			result += "\\"
		result += character
	return result

func to_state() -> Dictionary:
	return {"variables": variables.duplicate(true), "bindings": bindings.duplicate(true), "code": code}

func from_state(state: Dictionary) -> bool:
	if not state.get("variables", {}) is Dictionary or not state.get("bindings", []) is Array:
		return false
	for value in state.get("variables", {}).values():
		if not (value is int or value is float) or not is_finite(float(value)):
			return false
	for binding in state.get("bindings", []):
		if not binding is Dictionary or str(binding.get("metric", "")) not in ["moles", "mass", "temperature", "pH", "time"]:
			return false
	variables = state.get("variables", {"t": 0.0}).duplicate(true)
	bindings = state.get("bindings", []).duplicate(true)
	code = str(state.get("code", ""))
	return true
