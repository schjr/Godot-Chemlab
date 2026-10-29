class_name OriginalMaterialRasterizer
extends RefCounted
## Exact native pixel arithmetic applied to captured GDI masks. No substitute
## ellipse/arc rasterizer: every geometry must have a verified native mask.
const Solid = preload("res://scripts/original/original_solid_visual.gd")
const GUTI_SHA256 := "c4087e0532dfa5aa9e6a148c1da5a34f0845b03b0ef7af003b66a93b0fcb4f31"
const WEIGHT_BITS := "333333333333c33f"

static func mask_key(width: int, height: int, operations: Array) -> String:
	var parts: PackedStringArray = [str(width), str(height)]
	for operation in operations:
		var kind := str(operation.get("op", ""))
		if kind in ["rectangle", "ellipse", "arc"]:
			parts.append(kind)
			for field in ["left", "top", "right", "bottom"]:
				parts.append(str(int(operation.get(field, 0))))
			if kind == "arc":
				for field in ["start_x", "start_y", "end_x", "end_y"]:
					parts.append(str(int(operation.get(field, 0))))
	return ";".join(parts)

static func _error(message: String) -> Dictionary:
	return {"ok": false, "error": message, "boundary": "native GDI / VCL bitmap capture"}

static func render_solid_words(destination: Array, width: int, height: int, recipe: Dictionary, atlas: Dictionary) -> Dictionary:
	if not recipe.get("ok", false): return _error(str(recipe.get("error", "Original solid recipe failed")))
	if width <= 0 or height <= 0 or destination.size() != width * height:
		return _error("Original raster destination dimensions do not match native bitmap")
	var operations: Array = recipe.get("draw_operations", [])
	if operations.is_empty(): return {"ok": true, "words": destination.duplicate(), "image": words_to_image(destination, width, height)}
	if atlas.get("format", "") != "chemlab-gdi-mask-atlas-v2" or atlas.get("guti_sha256", "") != GUTI_SHA256:
		return _error("Missing or incompatible original guti / GDI mask atlas")
	if not atlas.get("native_vcl_verified", false):
		return _error("The GDI probe atlas has not been compared with original VCL bitmap output")
	var key := mask_key(width, height, operations)
	if not atlas.get("entries", {}) is Dictionary or not atlas["entries"].has(key):
		return _error("Uncaptured original GDI geometry: " + key)
	var entry: Dictionary = atlas["entries"][key]
	if int(entry.get("width", width)) != width or int(entry.get("height", height)) != height:
		return _error("Captured GDI entry dimensions differ from its geometry key")
	var pixels := Marshalls.base64_to_raw(str(entry.get("stencil_texture_bgra", "")))
	var arc_mask := Marshalls.base64_to_raw(str(entry.get("arc_coverage", "")))
	if pixels.size() != width * height * 4 or arc_mask.size() != width * height:
		return _error("Original GDI mask payload dimensions are invalid")
	var tint_color := -1
	var arc_color := -1
	var has_texture := false
	var has_composite := false
	for operation in operations:
		match str(operation.get("op", "")):
			"transparent":
				if int(operation.get("value", -1)) != 1: return _error("Unsupported original stencil transparency")
			"rectangle", "ellipse": pass # Captured together before texture conversion.
			"texture":
				if operation.get("source", "") != "guti.bmp" or int(operation.get("copy_mode", 0)) != 0xEE0086 or int(operation.get("left", -1)) != 0 or int(operation.get("top", -1)) != 0:
					return _error("Unsupported original texture operation")
				has_texture = true
			"tint_nonwhite":
				if operation.get("weight_bits", "") != WEIGHT_BITS: return _error("Original stencil tint weight differs")
				tint_color = int(operation.get("color_integer", -1))
			"arc": arc_color = int(operation.get("pen_color", -1))
			"composite_white_key":
				if operation.get("weight_bits", "") != WEIGHT_BITS or int(operation.get("left", -1)) != 0 or int(operation.get("top", -1)) != 0:
					return _error("Unsupported original final composite")
				has_composite = true
			_: return _error("Unported original drawing operation: " + str(operation.get("op", "")))
	if not has_texture or tint_color < 0 or not has_composite:
		return _error("Incomplete original solid draw recipe")
	var output: Array = []
	output.resize(destination.size())
	for i in range(destination.size()):
		var source_word := int(pixels.decode_u32(i * 4))
		var tinted := Solid.tint_pixel(source_word, tint_color)
		if arc_mask[i] != 0:
			if arc_color < 0: return _error("Captured arc coverage has no original arc operation")
			# COLORREF 00BBGGRR -> native DIB reserved/R/G/B bytes.
			tinted = ((arc_color & 255) << 16) | (arc_color & 0xFF00) | ((arc_color >> 16) & 255)
		var composed := Solid.composite_pixel(int(destination[i]), tinted)
		if tinted < 0 or composed < 0: return _error("Original pixel arithmetic is unsupported")
		output[i] = composed
	return {"ok": true, "words": output, "image": words_to_image(output, width, height), "mask_key": key}

static func words_to_image(words: Array, width: int, height: int) -> Image:
	# Native pf32bit high byte is reserved, not opacity. Keep it in words;
	# Godot presentation gets opaque RGB so a native zero byte is not transparent.
	var rgba := PackedByteArray()
	rgba.resize(width * height * 4)
	for i in range(words.size()):
		var pixel := int(words[i])
		rgba[i * 4] = (pixel >> 16) & 255
		rgba[i * 4 + 1] = (pixel >> 8) & 255
		rgba[i * 4 + 2] = pixel & 255
		rgba[i * 4 + 3] = 255
	return Image.create_from_data(width, height, false, Image.FORMAT_RGBA8, rgba)
