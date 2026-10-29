class_name OriginalSolubility
extends RefCounted
## Direct operation/branch port of main.exe 0x0046B858.
## Native 0x0046C84C invokes this before and after reactions iff +0x3C74==1.

const X87 = preload("res://scripts/original/original_x87.gd")
const Quantities = preload("res://scripts/original/original_quantities.gd")
const SATURATION_CONSTANT_0046C838: String = "0ad7a3703d0ad7a3f83f"
const DISSOLUTION_RATE_0046C844: float = 0.1

static func _error(text: String) -> Dictionary:
	return {"ok": false, "error": text, "native_function": "0x0046B858"}

static func base_species(species: String) -> String:
	# 0x00452C3C: copy bytes before the final '('; absent '(' gives an empty result.
	var opening: int = species.rfind("(")
	return species.substr(0, opening) if opening > 0 else ""

static func _insert(vessel: Dictionary, species: String) -> Dictionary:
	# Only the paths that explicitly insert in 0x0046B858 initialize these cells.
	var slot: int = vessel.contents.size()
	for field in ["native_species_mass_slots", "native_species_volume_slots", "solid_3cd8_slots", "solid_3ff8_slots"]:
		if vessel.has(field) and (not vessel[field] is Array or vessel[field].size() <= slot): return _error("原始槽位缓冲区未提供新增位置：" + field)
	vessel.contents[species] = 0.0
	for field in ["native_species_mass", "native_species_volume", "solid_3cd8", "solid_3ff8", "moles_variables", "mass_variables"]:
		if not vessel.has(field): vessel[field] = {}
		if not vessel[field] is Dictionary: return _error("原始槽位表类型无效：" + field)
		vessel[field][species] = "" if field in ["moles_variables", "mass_variables"] else 0.0
	for field in ["native_species_mass_slots", "native_species_volume_slots", "solid_3cd8_slots", "solid_3ff8_slots"]:
		if vessel.has(field): vessel[field][slot] = 0.0
	return {"ok": true}

static func _move(vessel: Dictionary, source: String, target: String, amount: float) -> Dictionary:
	# The original stores each subtraction/addition as a double separately.
	var remaining: Array = X87.add([float(vessel.contents[source]), 0.0], -amount)
	if remaining.is_empty(): return _error("原始析出/溶解减法 x87 数值未解析。")
	vessel.contents[source] = X87.stored_double(remaining)
	var added: Array = X87.add([amount, 0.0], float(vessel.contents[target]))
	if added.is_empty(): return _error("原始析出/溶解加法 x87 数值未解析。")
	vessel.contents[target] = X87.stored_double(added)
	return {"ok": true}

static func advance(vessel: Dictionary, reagent_map: Dictionary, delta_seconds: float) -> Dictionary:
	if not vessel.get("contents", null) is Dictionary or not is_finite(delta_seconds): return _error("原始溶解计算缺少药品槽位或时间差。")
	var water_mass: float = 0.0
	if vessel.contents.has("H2O(液体)"):
		if not reagent_map.has("H2O(液体)"): return _error("原药品库中缺少 H2O(液体)。")
		var water: Array = X87.multiply([float(reagent_map["H2O(液体)"].molar_mass), 0.0], float(vessel.contents["H2O(液体)"]))
		if water.is_empty(): return _error("原始水质量计算 x87 数值未解析。")
		water_mass = X87.stored_double(water)
	var slot: int = 0
	while slot < vessel.contents.size():
		var species: String = str(vessel.contents.keys()[slot])
		if not reagent_map.has(species): return _error("原药品库查找未解析：" + species)
		var record: Dictionary = reagent_map[species]
		if not record.has("molar_mass") or not record.has("solubility_at_20_C"): return _error("原药品库字段 +0x10/+0x50 缺失：" + species)
		var molar: float = float(record.molar_mass)
		var raw_solubility = record.solubility_at_20_C
		if not (raw_solubility is float or raw_solubility is int) and not str(raw_solubility).is_valid_float(): return _error("原始 +0x50 溶解度数值未解析：" + species)
		var scalar_solubility: float = float(raw_solubility)
		if not is_finite(molar) or molar == 0.0 or not is_finite(scalar_solubility): return _error("原始摩尔质量/溶解度运算未定义：" + species)
		# Assembly 0x46B9CC: water_mass * +0x50, then multiply original .01 xword.
		var saturation: Array = X87.multiply([water_mass, 0.0], scalar_solubility)
		saturation = X87.multiply_pair(X87.from_extended80_hex(SATURATION_CONSTANT_0046C838), saturation)
		if saturation.is_empty(): return _error("原始饱和质量 x87 数值未解析。")
		var limit_mass: float = X87.stored_double(saturation)
		var phase: String = Quantities.phase_suffix(species)
		var base: String = base_species(species)
		if phase == "(溶解)":
			var current_mass: Array = X87.multiply([molar, 0.0], float(vessel.contents[species]))
			if current_mass.is_empty(): return _error("原始溶质质量 x87 数值未解析。")
			if X87.compare_to_double(current_mass, limit_mass) > 0:
				# 0x46BADB stores the numerator as qword before the separate division.
				var numerator: Array = X87.add(current_mass, -limit_mass)
				if numerator.is_empty(): return _error("原始析出质量差值 x87 数值未解析。")
				var excess: Array = X87.divide([X87.stored_double(numerator), 0.0], molar)
				if excess.is_empty(): return _error("原始析出量 x87 数值未解析。")
				var amount: float = X87.stored_double(excess)
				var destination: String = base + "(固体)"
				if not vessel.contents.has(destination):
					if not reagent_map.has(destination): destination = base + "(气体)"
					if not vessel.contents.has(destination):
						if not reagent_map.has(destination) or vessel.contents.size() >= 100:
							slot += 1
							continue
						var inserted: Dictionary = _insert(vessel, destination)
						if not inserted.ok: return inserted
				var result: Dictionary = _move(vessel, species, destination, amount)
				if not result.ok: return result
		if phase in ["(固体)", "(气体)"]:
			var destination: String = base + "(溶解)"
			if not vessel.contents.has(destination):
				if not reagent_map.has(destination) or vessel.contents.size() >= 100:
					slot += 1
					continue
				var inserted: Dictionary = _insert(vessel, destination)
				if not inserted.ok: return inserted
			if not reagent_map.has(destination): return _error("原溶解药品查找未解析：" + destination)
			var destination_molar: float = float(reagent_map[destination].molar_mass)
			var dissolved_mass: Array = X87.multiply([destination_molar, 0.0], float(vessel.contents[destination]))
			if dissolved_mass.is_empty(): return _error("原始已溶质量 x87 数值未解析。")
			if X87.compare_to_double(dissolved_mass, limit_mass) < 0:
				# 0x46C6C1 uses the dissolved counterpart's molar mass for the numerator.
				var source_mass: Array = X87.multiply([destination_molar, 0.0], float(vessel.contents[destination]))
				if source_mass.is_empty(): return _error("原始溶解差值 x87 数值未解析。")
				var numerator: Array = X87.add([-float(source_mass[0]), -float(source_mass[1])], limit_mass)
				if numerator.is_empty(): return _error("原始溶解质量差值 x87 数值未解析。")
				# 0x46C6E0 stores this numerator as qword before FDIVR.
				var requested: Array = X87.divide([X87.stored_double(numerator), 0.0], destination_molar)
				if requested.is_empty(): return _error("原始溶解量 x87 数值未解析。")
				var amount: float = X87.stored_double(requested)
				if float(vessel.contents[species]) < amount: amount = float(vessel.contents[species])
				var rate_cap: Array = X87.multiply([DISSOLUTION_RATE_0046C844, 0.0], delta_seconds)
				if rate_cap.is_empty(): return _error("原始溶解速度 x87 数值未解析。")
				if X87.compare_to_double(rate_cap, amount) < 0: amount = X87.stored_double(rate_cap)
				var result: Dictionary = _move(vessel, species, destination, amount)
				if not result.ok: return result
		slot += 1
	return {"ok": true, "native_function": "0x0046B858"}
