class_name OriginalQuantities
extends RefCounted
## Direct branch/field port of main.exe 0x00461E54.
## Loader 0x00460D84 establishes molar mass=record field3, density=field8.
## This module has no chemistry, capacity clipping, or replacement physics.

const X87 = preload("res://scripts/original/original_x87.gd")

const NATIVE_OFFSETS := {
	"native_species_mass": 0x298,
	"native_species_volume": 0x5b8,
	"contents": 0x8d8,
	"native_liquid_volume": 0x4320,
	"native_gas_moles": 0x4328,
	"native_gas_volume": 0x4330,
	"native_solid_volume": 0x4338,
	"native_pressure": 0xa8,
	"volume_ml": 0x28,
}
const PRESSURE_CONSTANT_004624BC_HEX: String = "1fba6ddbb66ddbb6fa3f"
const PRESSURE_CONSTANT_004624C8_HEX: String = "3bdf4f8d976e1283f53f"

static func phase_suffix(species: String) -> String:
	# 0x00452ACC searches backward for the final '(' and copies up to the next space.
	# It does not inspect category fields or search for arbitrary phase substrings.
	var opening: int = species.rfind("(")
	if opening < 0: return ""
	var suffix: String = species.substr(opening)
	var space: int = suffix.find(" ")
	return suffix.substr(0, space) if space >= 0 else suffix

static func _error(text: String, stop: bool = false) -> Dictionary:
	return {"ok": false, "error": text, "stop": stop, "stop_requested": stop, "native_function": "0x00461E54"}

static func recalc(vessel: Dictionary, reagent_map: Dictionary) -> Dictionary:
	if not vessel.get("contents", null) is Dictionary: return _error("原始数量计算缺少药品数组。")
	if not vessel.has("volume_ml") or not is_finite(float(vessel.volume_ml)): return _error("原始数量计算缺少容量字段 +0x28。")
	if vessel.has("native_species_mass") and not vessel.native_species_mass is Dictionary: return _error("质量缓存 +0x298 类型无效。")
	if vessel.has("native_species_volume") and not vessel.native_species_volume is Dictionary: return _error("体积缓存 +0x5B8 类型无效。")
	for slots in ["native_species_mass_slots", "native_species_volume_slots"]:
		if vessel.has(slots) and (not vessel[slots] is Array or vessel[slots].size() < vessel.contents.size()): return _error("原始槽位缓存长度无效：" + slots)
	if not vessel.has("native_species_mass"): vessel.native_species_mass = {}
	if not vessel.has("native_species_volume"): vessel.native_species_volume = {}
	# Native code resets these four accumulators before iterating its ordered species slots.
	vessel.native_liquid_volume = 0.0
	vessel.native_gas_moles = 0.0
	vessel.native_gas_volume = 0.0
	vessel.native_solid_volume = 0.0
	var slot: int = 0
	for species in vessel.contents:
		if not reagent_map.has(str(species)): return _error("原药品库查找未解析：" + str(species))
		var record: Dictionary = reagent_map[str(species)]
		if not record.has("molar_mass"): return _error("药品缺少原始摩尔质量字段 +0x10：" + str(species))
		var molar_mass: float = float(record.molar_mass)
		var moles: float = float(vessel.contents[species])
		if not is_finite(molar_mass) or not is_finite(moles): return _error("原始药品数量含有非有限数值。")
		var mass_value: Array = X87.multiply([molar_mass, 0.0], moles)
		if mass_value.is_empty(): return _error("原始质量计算 x87 数值超出已实现范围。")
		vessel.native_species_mass[str(species)] = X87.stored_double(mass_value)
		if vessel.has("native_species_mass_slots"): vessel.native_species_mass_slots[slot] = vessel.native_species_mass[str(species)]
		# Original writes the current mass before checking invalid negative moles.
		if moles < -1e-10: return _error("容器中的药品mol量<0", true) # Original C string at 0x0056379E.
		var phase: String = phase_suffix(str(species))
		if phase in ["(固体)", "(液体)", "(气体)"]:
			if phase == "(气体)":
				var gas_value: Array = X87.multiply(X87.multiply([moles, 0.0], 22.4), 1000.0)
				if gas_value.is_empty(): return _error("原始气体体积计算 x87 数值超出已实现范围。")
				vessel.native_species_volume[str(species)] = X87.stored_double(gas_value)
			else:
				# Field8 is loaded into native reagent +0x30; no chemical-density guesses.
				if not record.has("density_or_render_parameter"): return _error("药品缺少原始密度字段 +0x30：" + str(species))
				var raw_density = record.density_or_render_parameter
				if not (raw_density is float or raw_density is int) and not str(raw_density).is_valid_float(): return _error("原始密度字段不是数值：" + str(species))
				var density: float = float(raw_density)
				if not is_finite(density) or density == 0.0: return _error("原始密度除法未定义：" + str(species))
				var volume_value: Array = X87.divide([float(vessel.native_species_mass[str(species)]), 0.0], density)
				if volume_value.is_empty(): return _error("原始密度除法 x87 数值超出已实现范围。")
				vessel.native_species_volume[str(species)] = X87.stored_double(volume_value)
			if vessel.has("native_species_volume_slots"): vessel.native_species_volume_slots[slot] = vessel.native_species_volume[str(species)]
		# Other phase values leave their previous +0x5B8 slot untouched, exactly as native code.
		if phase == "(固体)":
			var aggregate: Array = X87.add([float(vessel.native_species_volume[str(species)]), 0.0], float(vessel.native_solid_volume))
			if aggregate.is_empty(): return _error("原始固体体积累加 x87 数值超出已实现范围。")
			vessel.native_solid_volume = X87.stored_double(aggregate)
		if phase == "(液体)":
			var aggregate: Array = X87.add([float(vessel.native_species_volume[str(species)]), 0.0], float(vessel.native_liquid_volume))
			if aggregate.is_empty(): return _error("原始液体体积累加 x87 数值超出已实现范围。")
			vessel.native_liquid_volume = X87.stored_double(aggregate)
		if phase == "(气体)":
			var aggregate: Array = X87.add([moles, 0.0], float(vessel.native_gas_moles))
			if aggregate.is_empty(): return _error("原始气体摩尔量累加 x87 数值超出已实现范围。")
			vessel.native_gas_moles = X87.stored_double(aggregate)
		slot += 1
	var gas_total: Array = X87.multiply(X87.multiply([float(vessel.native_gas_moles), 0.0], 22.4), 1000.0)
	if gas_total.is_empty(): return _error("原始气体总体积 x87 数值超出已实现范围。")
	vessel.native_gas_volume = X87.stored_double(gas_total)
	# The x87 code stores headspace and excess as doubles, then multiplies excess by
	# constant 0x4624BC first and by constant 0x4624C8 second (0x462417..0x46245E).
	var headspace_value: Array = X87.add([float(vessel.volume_ml), 0.0], -float(vessel.native_liquid_volume))
	if headspace_value.is_empty(): return _error("原始气相容量 x87 数值超出已实现范围。")
	var headspace: float = X87.stored_double(headspace_value)
	var excess_value: Array = X87.add([float(vessel.native_gas_volume), 0.0], -headspace)
	if excess_value.is_empty(): return _error("原始气相差值 x87 数值超出已实现范围。")
	var excess_gas_volume: float = X87.stored_double(excess_value)
	var pressure: Array = X87.multiply(X87.from_extended80_hex(PRESSURE_CONSTANT_004624BC_HEX), excess_gas_volume)
	pressure = X87.multiply_pair(X87.from_extended80_hex(PRESSURE_CONSTANT_004624C8_HEX), pressure)
	if pressure.is_empty(): return _error("原始压力计算 x87 数值超出已实现范围。")
	vessel.native_pressure = X87.stored_double(pressure)
	if float(vessel.native_pressure) < 0.0: vessel.native_pressure = 0.0
	return {"ok": true, "native_function": "0x00461E54"}
