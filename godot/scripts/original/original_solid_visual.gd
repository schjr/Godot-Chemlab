class_name OriginalSolidVisual
extends RefCounted
## Source-based 004744DC stencil, original guti texture/tint/arc/composite recipe.
## Suspended particles in 0040A4B8 are a separate native renderer, not invented here.
const X87 = preload("res://scripts/original/original_x87.gd")
const Math = preload("res://scripts/original/original_math.gd")
const Quantities = preload("res://scripts/original/original_quantities.gd")
const Actions = preload("res://scripts/original/original_apparatus_actions.gd")
const ENTRY := 0x004744DC
const POINT_TWO_HEX := "cdccccccccccccccfc3f"
const POINT_ONE_HEX := "cdccccccccccccccfb3f"
const BLEND_WEIGHT_BITS := "333333333333c33f"

static func _error(message: String) -> Dictionary:
	return {"ok": false, "error": message, "native_function": ENTRY}

static func compute(vessel: Dictionary, reagents: Dictionary) -> Dictionary:
	var result := {"ok": true, "native_function": ENTRY, "draw_operations": []}
	if not vessel.get("contents", null) is Dictionary:
		return _error("Original solid drawing requires ordered species cells")
	var total := 0.0
	var remaining_volumes: Dictionary = {}
	for species in vessel["contents"]:
		if Quantities.phase_suffix(str(species)) != "(固体)": continue
		if not vessel.has("native_liquid_volume") or not vessel.get("native_species_volume", {}) is Dictionary or not vessel["native_species_volume"].has(species):
			return _error("Original solid drawing lacks physical-volume +0x5B8/+0x4320 caches")
		if not vessel.get("solid_3cd8", {}) is Dictionary or not vessel["solid_3cd8"].has(species):
			return _error("Original solid drawing lacks the preserved +0x3CD8 mole slot: " + str(species))
		if not reagents.has(str(species)) or not reagents[str(species)].has("molar_mass") or not reagents[str(species)].has("density_or_render_parameter"):
			return _error("Original solid molar mass/density is unresolved: " + str(species))
		var record: Dictionary = reagents[str(species)]
		# Native stores M*n_3CD8 as a double across its second reagent lookup.
		var mass: Array = X87.multiply([float(record["molar_mass"]), 0.0], float(vessel["solid_3cd8"][species]))
		if mass.is_empty(): return _error("Original solid reserved-mass product is unsupported")
		var equivalent: Array = X87.divide([X87.stored_double(mass), 0.0], float(record["density_or_render_parameter"]))
		if equivalent.is_empty(): return _error("Original solid reserved-volume division is unsupported")
		var volume := float(vessel["native_species_volume"][species])
		var sum: Array
		if X87.compare_to_double(equivalent, float(vessel["native_liquid_volume"])) >= 0:
			sum = X87.add([volume, 0.0], total)
		else:
			sum = X87.add(X87.add(Actions._negate(equivalent), volume), total)
		if sum.is_empty(): return _error("Original solid volume accumulation is unsupported")
		total = X87.stored_double(sum)
		# The color numerator ALWAYS subtracts the reserved volume, even when
		# the denominator's conditional branch counted the whole solid volume.
		var remainder: Array = X87.add(Actions._negate(equivalent), volume)
		if remainder.is_empty(): return _error("Original solid color-volume subtraction is unsupported")
		remaining_volumes[species] = X87.stored_double(remainder)
	result["solid_volume_unclamped"] = total
	if total < 1e-10: return result
	var mean: Array = [0.0, 0.0, 0.0]
	for species in remaining_volumes:
		if not reagents[species].has("color_integer"):
			return _error("Original solid color field +0x28 is unresolved")
		var color := int(reagents[species]["color_integer"])
		for channel in range(3):
			var weighted: Array = X87.divide(X87.multiply([float((color >> (channel * 8)) & 255), 0.0], float(remaining_volumes[species])), total)
			if weighted.is_empty(): return _error("Original solid color ratio is unsupported")
			var value := X87.stored_double(weighted)
			var accumulated: Array = X87.add([value, 0.0], float(mean[channel]))
			if accumulated.is_empty(): return _error("Original solid color accumulation is unsupported")
			mean[channel] = X87.stored_double(accumulated)
	var color_bytes: Array = []
	var pen_bytes: Array = []
	for value in mean:
		var byte: int = Actions._trunc([float(value), 0.0]) & 255
		color_bytes.append(byte)
		pen_bytes.append(Actions._trunc(X87.multiply(X87.multiply([float(byte), 0.0], 0.25), 3.0)) & 255)
	var color := _pack(color_bytes)
	var pen := _pack(pen_bytes)
	result["color_integer"] = color
	result["pen_color"] = pen
	if not vessel.has("volume_ml") or not vessel.has("native_bitmap_width") or not vessel.has("native_bitmap_height") or not vessel.has("type_id"):
		return _error("Original solid stencil requires capacity, type and active bitmap dimensions")
	var capacity := float(vessel["volume_ml"])
	var volume := total
	if capacity < volume: volume = capacity
	result["solid_volume"] = volume
	var width := int(vessel["native_bitmap_width"])
	var height := int(vessel["native_bitmap_height"])
	var type := int(vessel["type_id"])
	var size := int(vessel.get("native_fields", {}).get("0x0c", -1))
	var geometry := _geometry(type, size, capacity, volume, width, height)
	if not geometry.get("ok", false): return geometry
	var operations: Array = result["draw_operations"]
	operations.append({"op": "transparent", "value": 1})
	operations.append(_shape("rectangle", 0, 0, width, height, 0xFFFFFF))
	for shape in geometry["stencil"]: operations.append(shape)
	operations.append({"op": "texture", "source": "guti.bmp", "left": 0, "top": 0, "copy_mode": 0xEE0086})
	operations.append({"op": "tint_nonwhite", "color_integer": color, "weight_bits": BLEND_WEIGHT_BITS})
	if geometry.has("arc"):
		var arc: Dictionary = geometry["arc"]
		arc["pen_color"] = pen
		operations.append(arc)
	operations.append({"op": "composite_white_key", "left": 0, "top": 0, "weight_bits": BLEND_WEIGHT_BITS})
	return result

static func _geometry(type: int, size: int, capacity: float, volume: float, width: int, height: int) -> Dictionary:
	var result := {"ok": true, "stencil": []}
	if type == 108:
		result["stencil"].append(_shape("rectangle", 0, 3, width, height, 0))
		return result
	if type not in [101, 102, 103, 104, 105, 106, 107, 121, 201, 202, 209] or (type == 101 and size not in [0, 45, 97]):
		return result
	if capacity == 0.0: return _error("Original solid height divides by zero capacity; no substitute height is supplied")
	var ratio: Array = X87.divide([volume, 0.0], capacity)
	if ratio.is_empty(): return _error("Original solid fraction is outside supported range")
	var level: float
	if type in [103, 104, 105, 209]:
		var base := _store(X87.divide(X87.add([-volume, 0.0], capacity), capacity))
		var power := _store(Math.pow_native(base, 1.0 / 3.0))
		var product := _store(X87.multiply([float(height), 0.0], power))
		level = _store(X87.add([-product, 0.0], float(height)))
	else:
		level = _store(X87.multiply(ratio, float(width if type == 106 or (type == 101 and size == 97) else height)))
	if not is_finite(level): return _error("Original solid height is outside supported x87/CRT range")
	if type in [101, 102, 103, 104, 105, 107, 121, 201, 202, 209]:
		if type == 101 and size not in [0, 45, 97]: return result
		var left := 0
		var right := width
		var top: int
		var bottom: int
		var endpoint: int
		if type == 101 and size == 45:
			left = _trunc(X87.add([level, 0.0], -8.0))
			right = _trunc(X87.add([level, 0.0], 8.0))
			top = _trunc(X87.add([-level, 0.0], float(height - 5)))
			bottom = _trunc(X87.add([-level, 0.0], float(height + 8)))
			var adjusted := _store(X87.add(X87.add([-level, 0.0], float(height - 5)), 8.0))
			endpoint = _trunc(X87.multiply(X87.add(X87.add([adjusted, 0.0], float(height)), -level), 0.5))
			result["stencil"].append(_shape("ellipse", left, top, right, bottom, 0))
			result["stencil"].append(_shape("rectangle", 0, _trunc(X87.add([-level, 0.0], float(height))), width, height, 0))
		elif type == 101 and size == 97:
			var fifth: Array = X87.multiply(X87.from_extended80_hex(POINT_TWO_HEX), level)
			left = _trunc(X87.add(Actions._negate(X87.multiply(X87.from_extended80_hex(POINT_ONE_HEX), level)), 5.0))
			right = _trunc(X87.add(X87.multiply([level, 0.0], 2.0), 5.0))
			var upper: Array = X87.add(Actions._negate(fifth), 11.0)
			var lower: Array = X87.add(X87.multiply(X87.add(Actions._negate(fifth), 12.0), 2.0), float(height))
			top = _trunc(upper)
			bottom = _trunc(lower)
			endpoint = _trunc(X87.multiply(X87.add_pair(upper, lower), 0.5))
			result["stencil"].append(_shape("ellipse", left, top, right, bottom, 0))
		else:
			var anchor: int = height - int(height / 2) if type == 209 else height
			var upper := _store(X87.add([-level, 0.0], float(anchor - 2)))
			var lower := _store(X87.add([-level, 0.0], float(anchor)))
			top = _trunc([upper, 0.0])
			bottom = _trunc(X87.add([lower, 0.0], float(int(width / 2))))
			result["stencil"].append(_shape("ellipse", left, top, right, bottom, 0))
			result["stencil"].append(_shape("rectangle", 0, _trunc(X87.add([lower, 0.0], float(int(width / 4)))), width, anchor, 0))
			var compound := _store(X87.add(X87.add([upper, 0.0], float(height)), -level))
			var horizontal: float = float(int(width / 2)) if type == 101 else float(width) * 0.5
			endpoint = _trunc(X87.multiply(X87.add([compound, 0.0], horizontal), 0.5))
		result["arc"] = {"op": "arc", "left": left, "top": top, "right": right, "bottom": bottom,
			"start_x": width, "start_y": endpoint, "end_x": 0, "end_y": endpoint}
	elif type == 106:
		var left := _trunc(X87.add([-level, 0.0], float(int(width / 2))))
		var right := _trunc(X87.add([level, 0.0], float(int(width / 2))))
		var upper := _store(X87.add(Actions._negate(X87.multiply([level, 0.0], 0.5)), float(height - 4)))
		var lower: Array = X87.add(X87.multiply(X87.multiply([level, 0.0], 0.5), 3.0), float(height - 3))
		var top := _trunc([upper, 0.0])
		var bottom := _trunc(lower)
		var endpoint := _trunc(X87.multiply(X87.add_pair([upper, 0.0], lower), 0.5))
		result["stencil"].append(_shape("ellipse", left, top, right, bottom, 0))
		result["arc"] = {"op": "arc", "left": left, "top": top, "right": right, "bottom": bottom,
			"start_x": width, "start_y": endpoint, "end_x": 0, "end_y": endpoint}
	return result

static func _shape(kind: String, left: int, top: int, right: int, bottom: int, color: int) -> Dictionary:
	return {"op": kind, "left": left, "top": top, "right": right, "bottom": bottom,
		"pen_color": color, "brush_color": color, "brush_style": 0}

static func _pack(bytes: Array) -> int:
	return int(bytes[0]) | (int(bytes[1]) << 8) | (int(bytes[2]) << 16)

static func tint_pixel(pixel_word: int, colorref: int, weight: float = 0.15) -> int:
	## Native 4928A0: 32-bit DIB BGR word, COLORREF color uses reversed R/B bytes.
	if (pixel_word & 0xFFFFFF) == 0xFFFFFF: return pixel_word
	var output := 0
	for channel in range(3):
		var old_byte: int = (pixel_word >> (8 * channel)) & 255
		var color_byte: int = (colorref >> (8 * (2 - channel))) & 255
		var value: Array = _pixel_channel(old_byte, color_byte, weight)
		if value.is_empty(): return -1
		output |= (_trunc(value) & 255) << (8 * channel)
	return output

static func composite_pixel(destination_word: int, source_word: int, weight: float = 0.15) -> int:
	## Native 492560: source-white keeps dest, dest-white copies source, otherwise blend.
	if (source_word & 0xFFFFFF) == 0xFFFFFF: return destination_word
	if (destination_word & 0xFFFFFF) == 0xFFFFFF: return source_word
	var output := 0
	for channel in range(3):
		var value: Array = _pixel_channel((destination_word >> (8 * channel)) & 255,
			(source_word >> (8 * channel)) & 255, weight)
		if value.is_empty(): return -1
		output |= (_trunc(value) & 255) << (8 * channel)
	return output

static func _pixel_channel(old_byte: int, color_byte: int, weight: float) -> Array:
	var inverse: Array = X87.add([-weight, 0.0], 1.0)
	var color: Array = X87.multiply(inverse, float(color_byte))
	var old: Array = X87.multiply([float(old_byte), 0.0], weight)
	return X87.add_pair(color, old)

static func _store(pair: Array) -> float:
	return NAN if pair.is_empty() else X87.stored_double(pair)

static func _trunc(pair: Array) -> int:
	return Actions._trunc(pair)
