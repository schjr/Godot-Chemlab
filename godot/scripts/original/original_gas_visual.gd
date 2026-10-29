class_name OriginalGasVisual
extends RefCounted
## Numeric/draw-operation transcription of native 0x0047692C.
const X87 = preload("res://scripts/original/original_x87.gd")
const Quantities = preload("res://scripts/original/original_quantities.gd")
const Actions = preload("res://scripts/original/original_apparatus_actions.gd")
const ENTRY := 0x0047692C

static func _error(message: String) -> Dictionary:
	return {"ok": false, "error": message, "native_function": ENTRY}

static func compute(vessel: Dictionary, reagent_map: Dictionary) -> Dictionary:
	var result := {"ok": true, "native_function": ENTRY, "draw_operations": []}
	if not vessel.has("volume_ml") or not vessel.has("native_liquid_volume"):
		return _error("Original gas drawing requires capacity +0x28 and liquid volume +0x4320")
	var free: Array = X87.add([float(vessel["volume_ml"]), 0.0], -float(vessel["native_liquid_volume"]))
	if free.is_empty(): return _error("Original headspace subtraction is outside supported x87 range")
	var headspace := X87.stored_double(free)
	result["headspace"] = headspace
	if headspace <= 0.0: return result
	if not vessel.get("contents", null) is Dictionary:
		return _error("Original gas drawing requires ordered species/mole cells")
	var gas_volume := 0.0
	for species in vessel["contents"]:
		if Quantities.phase_suffix(str(species)) != "(气体)": continue
		var volume: Array = X87.multiply(X87.multiply([float(vessel["contents"][species]), 0.0], 22.4), 1000.0)
		var sum: Array = X87.add(volume, gas_volume)
		if sum.is_empty(): return _error("Original gas-volume sum is outside supported x87 range")
		gas_volume = X87.stored_double(sum)
	result["gas_volume"] = gas_volume
	if gas_volume < 0.1: return result
	var rows: Array = []
	for species in vessel["contents"]:
		if Quantities.phase_suffix(str(species)) != "(气体)": continue
		if not reagent_map.has(str(species)) or not reagent_map[str(species)].has("color_integer"):
			return _error("Original gas color +0x28 is missing for " + str(species))
		var volume: Array = X87.multiply(X87.multiply([float(vessel["contents"][species]), 0.0], 22.4), 1000.0)
		if volume.is_empty(): return _error("Original gas-species volume is outside supported range")
		var stored_volume := X87.stored_double(volume)
		var color := int(reagent_map[str(species)]["color_integer"])
		var channels: Array = []
		for shift in [0, 8, 16]:
			var weighted: Array = X87.divide(X87.multiply([float((color >> shift) & 255), 0.0], stored_volume), gas_volume)
			if weighted.is_empty(): return _error("Original gas-color ratio is outside supported range")
			channels.append(X87.stored_double(weighted))
		rows.append(channels)
	var mean: Array = [0.0, 0.0, 0.0]
	for row in rows:
		for channel in range(3):
			var accumulated: Array = X87.add([float(row[channel]), 0.0], float(mean[channel]))
			if accumulated.is_empty(): return _error("Original gas-color accumulation is outside supported range")
			mean[channel] = X87.stored_double(accumulated)
	var bytes: Array = []
	for channel in mean:
		bytes.append(Actions._trunc([float(channel), 0.0]) & 255)
	if gas_volume < headspace:
		for channel in range(3):
			# 476C6D..CF5: ((free-gas)*255/free)+(truncated_mean*gas/free).
			var white: Array = X87.divide(X87.multiply(X87.add([headspace, 0.0], -gas_volume), 255.0), headspace)
			var gas: Array = X87.divide(X87.multiply([float(bytes[channel]), 0.0], gas_volume), headspace)
			var blended: Array = X87.add_pair(white, gas)
			if blended.is_empty(): return _error("Original gas/headspace color blend is outside supported range")
			bytes[channel] = Actions._trunc(blended) & 255
	var packed: int = int(bytes[0]) | (int(bytes[1]) << 8) | (int(bytes[2]) << 16)
	if int(bytes[0]) > 252 and int(bytes[1]) > 252 and int(bytes[2]) > 252: packed = 0xFFFFFF
	result["color_integer"] = packed
	if not vessel.has("native_bitmap_width") or not vessel.has("native_bitmap_height") or not vessel.has("native_liquid_height"):
		return _error("Original gas rectangle requires current bitmap dimensions and liquid height +0x30")
	var bottom: Array = X87.add([float(vessel["native_bitmap_height"]), 0.0], -float(vessel["native_liquid_height"]))
	if bottom.is_empty(): return _error("Original gas rectangle limit is outside supported range")
	result["draw_operations"].append({"op": "rectangle", "left": 0, "top": 0,
		"right": int(vessel["native_bitmap_width"]), "bottom": Actions._trunc(bottom),
		"pen_color": packed, "brush_color": packed, "brush_style": 0})
	return result
