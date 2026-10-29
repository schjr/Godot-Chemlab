class_name OriginalLiquid
extends RefCounted
## FUN_00471650 numeric branch port. Bitmap dimensions are original asset pixels.
## Rendering owns +0x30 and can clamp +0x4320; neither is an estimated fill ratio.

const X87 = preload("res://scripts/original/original_x87.gd")
const Quantities = preload("res://scripts/original/original_quantities.gd")
const Math = preload("res://scripts/original/original_math.gd")
const THIRD_HEX = "abaaaaaaaaaaaaaafd3f"
const PEN_HEX = "4992244992244992fc3f"
const LONG_FUNNEL_HEX = "cdccccccccccccccfc3f"

static func _store(pair: Array) -> float:
	return X87.stored_double(pair)

static func _trunc(pair: Array) -> int:
	var result := int(pair[0])
	if float(result) == float(pair[0]):
		if result > 0 and float(pair[1]) < 0.0: result -= 1
		elif result < 0 and float(pair[1]) > 0.0: result += 1
	return result

static func _channels(color: int) -> Array:
	return [color & 255, (color >> 8) & 255, (color >> 16) & 255]

static func _pack(channels: Array) -> int:
	return (int(channels[0]) & 255) | ((int(channels[1]) & 255) << 8) | ((int(channels[2]) & 255) << 16)

static func _indicator(color: int, water_color: int, kind: String, ph: float) -> int:
	# The original updates bytes in order; later channels use the updated red byte.
	var rgb := _channels(color)
	var red: int
	if kind == "甲基橙(指示剂)":
		if ph < 3.2:
			if color == water_color: return 0x7f7fff
			red = (int(rgb[0]) + 220) >> 1
			return _pack([red, (red + 50) >> 1, (red + 50) >> 1])
		if ph < 4.5:
			if color == water_color: return 0x7fb9ff
			red = (int(rgb[0]) + 255) >> 1
			return _pack([red, (red + 115) >> 1, red >> 1])
		if color == water_color: return 0x7fe5ff
		red = (int(rgb[0]) + 255) >> 1
		return _pack([red, (red + 204) >> 1, red >> 1])
	if kind == "石蕊(指示剂)":
		if ph < 5.0:
			if color == water_color: return 0x7f7fff
			red = (int(rgb[0]) + 220) >> 1
			return _pack([red, (red + 50) >> 1, (red + 50) >> 1])
		if ph < 8.0:
			if color == water_color: return 0xc37fc3
			red = (int(rgb[0]) + 135) >> 1
			return _pack([red, red >> 1, (red + 135) >> 1])
		if color == water_color: return 0xd9a7a2
		red = (int(rgb[0]) + 70) >> 1
		return _pack([red, (red + 80) >> 1, (red + 180) >> 1])
	if kind == "酚酞(指示剂)" and ph >= 8.0:
		if ph < 10.0:
			if color == water_color: return 0xf0b6f0
			red = (int(rgb[0]) + 225) >> 1
			return _pack([red, (red + 110) >> 1, (red + 225) >> 1])
		if color == water_color: return 0x9d7ff0
		red = (int(rgb[0]) + 225) >> 1
		return _pack([red, red >> 1, (red + 60) >> 1])
	return color

static func refresh(vessel: Dictionary, reagent_map: Dictionary) -> Dictionary:
	# Renderer 0x40A4B8 writes zero before calling this routine each frame.
	vessel.native_liquid_height = 0.0
	vessel.native_liquid_height_fresh = false
	if not vessel.get("native_species_volume", null) is Dictionary:
		return {"ok": false, "error": "原始绘图缺少体积缓存。"}
	var volume := 0.0
	var water := 0.0
	for species in vessel.contents:
		if Quantities.phase_suffix(str(species)) == "(液体)":
			if not vessel.native_species_volume.has(species): return {"ok": false, "error": "原始液体槽位体积未解析。"}
			volume = _store(X87.add([float(vessel.native_species_volume[species]), 0.0], volume))
		if str(species) == "H2O(液体)": water = float(vessel.native_species_volume[species])
	if volume < 1e-10:
		vessel.native_liquid_height_fresh = true
		return {"ok": true}
	var liquid_rgb := [0.0, 0.0, 0.0]
	for species in vessel.contents:
		if not reagent_map.has(species): return {"ok": false, "error": "原药品颜色未解析：" + str(species)}
		if Quantities.phase_suffix(str(species)) != "(液体)": continue
		var rgb := _channels(int(reagent_map[species].color_integer))
		for channel in 3:
			var contribution := _store(X87.divide(X87.multiply([float(rgb[channel]), 0.0], float(vessel.native_species_volume[species])), volume))
			liquid_rgb[channel] = _store(X87.add([contribution, 0.0], float(liquid_rgb[channel])))
	for i in 3: liquid_rgb[i] = int(liquid_rgb[i]) & 255
	var solute_colors: Array = []
	var concentrations: Array = []
	var concentration_sum := 0.0
	for species in vessel.contents:
		if Quantities.phase_suffix(str(species)) not in ["(溶解)", "(离子)"] or float(vessel.contents[species]) <= 1e-10: continue
		var color := int(reagent_map[species].color_integer)
		if color == 0: continue
		if water == 0.0: return {"ok": false, "error": "原始溶液颜色除法的水体积为零。"}
		var concentration := _store(X87.multiply(X87.divide([float(vessel.contents[species]), 0.0], water), 1000.0))
		concentrations.append(concentration)
		concentration_sum = _store(X87.add([concentration, 0.0], concentration_sum))
		var rgb := _channels(color)
		if concentration <= 0.5:
			for channel in 3:
				var background: float = [235.0, 245.0, 248.0][channel]
				var term := X87.multiply(X87.multiply(X87.add([-float(rgb[channel]), 0.0], background), concentration), 2.0)
				rgb[channel] = _store(X87.add(X87.multiply(term, -1.0), background))
		solute_colors.append(rgb)
	var solute_rgb := [0.0, 0.0, 0.0]
	for i in range(solute_colors.size()):
		for channel in 3:
			var term := X87.divide(X87.multiply([float(solute_colors[i][channel]), 0.0], float(concentrations[i])), concentration_sum)
			solute_rgb[channel] = _store(X87.add(term, float(solute_rgb[channel])))
	for channel in 3: solute_rgb[channel] = int(solute_rgb[channel]) & 255
	if solute_colors.is_empty(): solute_rgb = liquid_rgb.duplicate()
	var combined: Array = []
	for channel in 3:
		var a := X87.multiply(X87.from_extended80_hex(THIRD_HEX), float(liquid_rgb[channel]))
		var b := X87.multiply(X87.multiply(X87.from_extended80_hex(THIRD_HEX), float(solute_rgb[channel])), 2.0)
		combined.append(_trunc(X87.add_pair(a, b)) & 255)
	var color := _pack(combined)
	var ph := 7.0
	if vessel.contents.has("H+(离子)"):
		if water == 0.0: return {"ok": false, "error": "原始指示剂计算的水体积为零。"}
		var concentration := _store(X87.multiply(X87.divide([float(vessel.contents["H+(离子)"]), 0.0], water), 1000.0))
		if concentration > 1e-100: ph = -_store(Math.log10_native(concentration))
	for species in vessel.contents:
		if float(vessel.contents[species]) <= 1e-10: continue
		for indicator in ["甲基橙(指示剂)", "石蕊(指示剂)", "酚酞(指示剂)"]:
			if str(species) == indicator: color = _indicator(color, int(reagent_map["H2O(液体)"].color_integer), indicator, ph)
	vessel.native_liquid_color = color
	vessel.native_ph = ph
	var pen: Array = []
	for channel in _channels(color): pen.append(_trunc(X87.multiply(X87.multiply(X87.from_extended80_hex(PEN_HEX), float(channel)), 6.0)) & 255)
	vessel.native_liquid_pen_color = _pack(pen)
	volume = minf(volume, float(vessel.volume_ml))
	if not vessel.has("native_bitmap_height"): return {"ok": false, "error": "原始位图高度未解析。"}
	var height: float = float(vessel.native_bitmap_height)
	var liquid_height: float
	var bottom: int = int(height)
	var typ := int(vessel.type_id)
	if typ in [101, 102, 106, 107, 108, 121, 201, 202, 204, 212]:
		liquid_height = _store(X87.add(X87.multiply(X87.divide([volume, 0.0], float(vessel.volume_ml)), height), 0.5))
		if typ == 204: liquid_height = minf(liquid_height, 53.7)
	elif typ in [103, 104, 105]:
		var base := _store(X87.divide(X87.add([-volume, 0.0], float(vessel.volume_ml)), float(vessel.volume_ml)))
		var power := _store(Math.pow_native(base, 1.0 / 3.0))
		var product := _store(X87.multiply([height, 0.0], power))
		liquid_height = _store(X87.add([-product, 0.0], height))
	elif typ in [207, 208]:
		liquid_height = _store(X87.add(X87.multiply([volume, 0.0], 4.0), 22.0)); bottom -= 22
	elif typ == 209:
		volume = minf(volume, 50.0)
		var base := _store(X87.divide(X87.add(X87.add([volume, 0.0], -50.0), float(vessel.volume_ml)), float(vessel.volume_ml)))
		liquid_height = _store(X87.add(X87.multiply(Math.pow_native(base, 1.0 / 3.0), 25.0), 30.0)); bottom -= 30
	elif typ == 210:
		liquid_height = _store(X87.add(X87.multiply(X87.multiply(X87.from_extended80_hex(LONG_FUNNEL_HEX), volume), 2.0), 76.0)); bottom -= 77
	elif typ == 211:
		liquid_height = _store(X87.add(X87.multiply([volume, 0.0], 0.5), 77.0)); bottom -= 77
	else: return {"ok": false, "error": "原始液体绘图的容器分支未定义：" + str(typ)}
	vessel.native_liquid_height = liquid_height
	vessel.native_liquid_volume = volume
	vessel.native_liquid_rectangle = [0, _trunc(X87.add([-liquid_height, 0.0], height)), int(vessel.native_bitmap_width), bottom]
	vessel.native_liquid_height_fresh = true
	return {"ok": true}
