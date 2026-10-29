class_name OriginalVesselBitmapRenderer
extends RefCounted
## Per-vessel native call-order plan and final 004926E0 pixel composition.
## Requires exact pre-apparatus material raster; does not replace unported GDI,
## suspended particles, optional overlays or the rotated-vessel branch.
const Liquid = preload("res://scripts/original/original_liquid.gd")
const Gas = preload("res://scripts/original/original_gas_visual.gd")
const Surface = preload("res://scripts/original/original_surface_outline.gd")
const Solid = preload("res://scripts/original/original_solid_visual.gd")
const Raster = preload("res://scripts/original/original_material_rasterizer.gd")
const X87 = preload("res://scripts/original/original_x87.gd")
const Actions = preload("res://scripts/original/original_apparatus_actions.gd")

static func _error(message: String) -> Dictionary:
	return {"ok": false, "error": message, "native_function": 0x0040A4B8}

static func plan(vessel: Dictionary, reagents: Dictionary) -> Dictionary:
	if int(vessel.get("native_fields", {}).get("0x18", -1)) != 0:
		return _error("Original rotated vessel rendering is a separate 0040A4B8 branch")
	var liquid: Dictionary = Liquid.refresh(vessel, reagents)
	if not liquid.get("ok", false): return liquid
	var gas: Dictionary = Gas.compute(vessel, reagents)
	if not gas.get("ok", false): return gas
	var surface := {"ok": true, "draw_operations": []}
	if float(vessel.native_liquid_height) > 1.0:
		surface = Surface.compute(vessel)
		if not surface.get("ok", false): return surface
	var solid: Dictionary = Solid.compute(vessel, reagents)
	if not solid.get("ok", false): return solid
	var liquid_ops: Array = []
	if float(vessel.native_liquid_height) != 0.0:
		var bounds: Array = vessel.native_liquid_rectangle
		liquid_ops.append({"op": "rectangle", "left": int(bounds[0]), "top": int(bounds[1]), "right": int(bounds[2]), "bottom": int(bounds[3]),
			"pen_color": vessel.native_liquid_pen_color, "brush_color": vessel.native_liquid_color, "brush_style": 0})
	return {"ok": true, "native_function": 0x0040A4B8,
		"stages": [
			{"stage": "transparent", "value": true, "native_slot": 0x3C},
			{"stage": "clear_white"},
			{"stage": "liquid", "native_function": 0x00471650, "draw_operations": liquid_ops},
			{"stage": "gas", "native_function": 0x0047692C, "draw_operations": gas.draw_operations},
			{"stage": "suspended_particles_or_particle_bitmap", "native_function": 0x0040A4B8, "requires_capture": true},
			{"stage": "liquid_surface_outline", "native_function": 0x00473E6C, "enabled": float(vessel.native_liquid_height) > 1.0, "draw_operations": surface.draw_operations},
			{"stage": "settled_solid", "native_function": 0x004744DC, "recipe": solid},
			{"stage": "running_overlays", "requires_capture": true},
			{"stage": "plain_apparatus_srcpaint", "field": 0xF8, "copy_mode": 0xEE0086},
			{"stage": "fill_bitmap_blend", "field": 0xF4, "native_function": 0x004926E0, "weight": fill_weight(vessel)}],
		"complete_native_material_raster_required": true}

static func fill_weight(vessel: Dictionary) -> float:
	return 0.3 if int(vessel.get("type_id", -1)) in [201, 202] and int(vessel.get("native_fields", {}).get("0x0c", -1)) == 1000 else 1.0

static func fill_pixel(destination: int, mask: int, weight: float) -> int:
	# 492748..492769: destination RGB white copies the entire mask word.
	if (destination & 0xFFFFFF) == 0xFFFFFF: return mask
	# 492779..492794: mask RED * literal0.00392 stored-double;
	# (1-product)+literal0.65 stored-double, capped to1.
	var product: Array = X87.multiply([float((mask >> 16) & 255), 0.0], 0.00392)
	if product.is_empty(): return -1
	var factor_pair: Array = X87.add(X87.add([-X87.stored_double(product), 0.0], 1.0), 0.65)
	if factor_pair.is_empty(): return -1
	var factor := minf(X87.stored_double(factor_pair), 1.0)
	var output := 0
	for channel in range(3):
		var inverse: Array = X87.add(Actions._negate(X87.multiply([weight, 0.0], factor)), 1.0)
		var mask_term: Array = X87.multiply(inverse, float((mask >> (channel * 8)) & 255))
		var destination_term: Array = X87.multiply(X87.multiply([float((destination >> (channel * 8)) & 255), 0.0], weight), factor)
		var total: Array = X87.add_pair(mask_term, destination_term)
		if total.is_empty(): return -1
		output |= (Actions._trunc(total) & 255) << (channel * 8)
	return output # 49284D clears native reserved byte for nonwhite destination.

static func compose_native_words(vessel: Dictionary, material: Array, plain: Array, fill: Array, capture: Dictionary) -> Dictionary:
	# Inputs are exact same-size native words AFTER caller has resolved all
	# preceding material/overlay stages, not guessed fill colors or particles.
	if not capture.get("native_material_verified", false) or not capture.get("native_srcpaint_word_format_verified", false):
		return _error("Original material raster and same-format GDI SRCPAINT words require verified capture provenance")
	var width := int(vessel.get("native_bitmap_width", 0))
	var height := int(vessel.get("native_bitmap_height", 0))
	if width <= 0 or height <= 0 or material.size() != width * height or plain.size() != material.size() or fill.size() != material.size():
		return _error("Original +FC/+F8/+F4 bitmap dimensions do not agree")
	var output: Array = []
	output.resize(material.size())
	var weight := fill_weight(vessel)
	for i in range(material.size()):
		var painted := (int(material[i]) | int(plain[i])) & 0xFFFFFFFF
		var final_word := fill_pixel(painted, int(fill[i]), weight)
		if final_word < 0: return _error("Original final bitmap pixel arithmetic is unsupported")
		output[i] = final_word
	return {"ok": true, "words": output, "image": Raster.words_to_image(output, width, height),
		"native_function": 0x004926E0, "weight": weight, "native_transparent_color": 0xFFFFFF,
		"white_key_alpha_applied": false}
