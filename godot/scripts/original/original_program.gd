class_name OriginalProgram
extends RefCounted
## Native arithmetic assignment path 0044DACC/E2D8/ECF8/F658.
## Unported statement/function branches report an error; no Godot Expression fallback.
const X87 = preload("res://scripts/original/original_x87.gd")
const Math = preload("res://scripts/original/original_math.gd")

static func format_number(value: float) -> String:
	if value == 0.0: return "0"
	var negative := value < 0.0
	var absolute := absf(value)
	var exponent := int(floor(X87.stored_double(Math.log10_native(absolute))))
	var scale := Math.pow_native(10.0,float(14-exponent))
	var scaled := X87.multiply_pair([absolute,0.0],scale)
	if scaled.is_empty(): return ""
	var integer := int(scaled[0])
	var fractional := X87.add(scaled,-float(integer))
	if X87.compare_to_double(fractional,0.5) >= 0: integer += 1
	var digits := str(integer)
	if digits.length() == 16: digits = digits.left(15); exponent += 1
	while digits.length() > 1 and digits.ends_with("0"): digits = digits.left(digits.length()-1)
	var text: String
	# FloatToStr's general mode: precision 15, fixed for exponent -4..14.
	if exponent >= -4 and exponent < 15:
		var position := exponent+1
		if position <= 0: text = "0."+"0".repeat(-position)+digits
		elif position >= digits.length(): text = digits+"0".repeat(position-digits.length())
		else: text = digits.left(position)+"."+digits.substr(position)
	else:
		text = digits.left(1)
		if digits.length() > 1: text += "."+digits.substr(1)
		text += "E"+str(exponent)
	return "-"+text if negative else text

static func round_number(value: float) -> float:
	return X87.stored_double(parse_number(format_number(value)))

static func parse_number(text: String) -> Array:
	# Native StrToFloat yields an extended operand; Godot's String.to_float can
	# lose significant digits in fixed decimal strings with leading zeros.
	var value := text.strip_edges()
	var negative := value.begins_with("-")
	if value.begins_with("-") or value.begins_with("+"): value = value.substr(1)
	var exponent := 0
	var at := value.to_lower().find("e")
	if at >= 0: exponent = int(value.substr(at+1)); value = value.left(at)
	at = value.find(".")
	if at >= 0: exponent -= value.length()-at-1; value = value.replace(".","")
	while value.length() > 1 and value.begins_with("0"): value = value.substr(1)
	if value.length() > 18: return []
	var integer := int(value)
	# FILD/decimal accumulation retains the full integer before decimal scaling.
	# Splitting into exact32-bit limbs avoids a premature binary64 conversion.
	var integer_operand := X87.add(X87.multiply([float(integer >> 32),0.0],4294967296.0),float(integer & 0xffffffff))
	var out: Array
	if exponent >= 0: out = X87.multiply_pair(integer_operand,Math.pow_native(10.0,float(exponent)))
	else: out = X87.divide_pair(integer_operand,Math.pow_native(10.0,float(-exponent)))
	return X87.multiply(out,-1.0) if negative else out

static func _result(value: float) -> Dictionary:
	var text := format_number(value)
	var operand := parse_number(text)
	return {"ok":true,"value":X87.stored_double(operand),"extended":operand}

static func _failure(message: String) -> Dictionary:
	return {"ok":false,"error":message}

static func _unwrap(text: String) -> String:
	if not text.begins_with("(") or not text.ends_with(")"): return text
	var depth := 0
	for i in text.length():
		if text[i] == "(": depth += 1
		elif text[i] == ")": depth -= 1
		if depth == 0 and i != text.length()-1: return text
	return text.substr(1,text.length()-2)

static func expression(source: String, variables: Dictionary, depth: int = 0) -> Dictionary:
	if depth > 100: return _failure("原版表达式超过已验证的递归范围。")
	var text := _unwrap(source)
	var nesting := 0
	var boundaries: Array = []
	for operators in [["+","-"],["*","/"]]:
		boundaries.clear(); nesting = 0
		for i in text.length():
			if text[i] == "(": nesting += 1
			elif text[i] == ")": nesting -= 1
			elif nesting == 0 and text[i] in operators and not (i > 0 and text[i-1] in ["e","E"]): boundaries.append(i)
		if not boundaries.is_empty():
			var previous := 0
			var operator := "+" if operators[0] == "+" else "*"
			var accumulator := 0.0
			var first := true
			var ends := boundaries.duplicate(); ends.append(text.length())
			for at in ends:
				var child := expression(text.substr(previous,at-previous),variables,depth+1)
				if not child.ok: return child
				var operand := float(child.value)
				var extended: Array = child.get("extended",[operand,0.0])
				if first: accumulator = operand; first = false
				else:
					var pair: Array
					match operator:
						"+": pair = X87.add(extended,accumulator)
						"-": pair = X87.add_pair([accumulator,0.0],X87.multiply(extended,-1.0))
						"*": pair = X87.multiply(extended,accumulator)
						"/": pair = X87.divide_pair([accumulator,0.0],extended)
					if pair.is_empty(): return _failure("原版表达式计算未定义。")
					accumulator = X87.stored_double(pair)
				if at < text.length(): operator = text[at]
				previous = at+1
			return _result(accumulator)
	if text.begins_with("log10(") and text.ends_with(")"):
		var child := expression(text.substr(6,text.length()-7),variables,depth+1)
		if not child.ok: return child
		if float(child.value) <= 0.0: return _failure("原版 log10 参数必须大于零。")
		return _result(X87.stored_double(Math.log10_native(float(child.value))))
	if text.is_empty(): return {"ok":true,"value":0.0} # Native unary +/- empty first cell.
	if text.is_valid_float():
		var operand := parse_number(text)
		return _failure("原版数字超出已验证范围。") if operand.is_empty() else {"ok":true,"value":X87.stored_double(operand),"extended":operand}
	if variables.has(text):
		var value := round_number(float(variables[text]))
		return {"ok":true,"value":0.0,"extended":[0.0,0.0]} if absf(value) < 1e-20 else _result(value)
	return _failure("原版语句或函数尚未移植："+text)

static func assignment(line: String, variables: Dictionary) -> Dictionary:
	var text := line.replace(" ","") # 0044D43C removes ASCII spaces only.
	var equal := text.find("=")
	if equal < 0: return _failure("此原版程序语句尚未移植。")
	var name := text.left(equal)
	if not variables.has(name): return _failure("原版变量不存在："+name)
	var result := expression(text.substr(equal+1),variables)
	if not result.ok: return result
	variables[name] = round_number(float(result.value))
	return {"ok":true}

static func frame(groups: Array, variables: Dictionary) -> Dictionary:
	# FUN_004018B0 calls FUN_00402928(form,0) once, after first binding refresh.
	if groups.is_empty(): return {"ok":true}
	for line in groups[0].lines:
		var result := assignment(str(line),variables)
		if not result.ok: return result
	return {"ok":true}
