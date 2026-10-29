extends SceneTree
const Raster = preload("res://scripts/original/original_material_rasterizer.gd")
const Solid = preload("res://scripts/original/original_solid_visual.gd")
var failures := 0
func check(condition: bool, message: String) -> void:
	if not condition:
		failures += 1
		push_error(message)
func _initialize() -> void:
	var operations := [
		{"op": "transparent", "value": 1},
		{"op": "rectangle", "left": 0, "top": 0, "right": 2, "bottom": 1, "pen_color": 0xFFFFFF, "brush_color": 0xFFFFFF},
		{"op": "texture", "source": "guti.bmp", "left": 0, "top": 0, "copy_mode": 0xEE0086},
		{"op": "tint_nonwhite", "color_integer": 0x123456, "weight_bits": Raster.WEIGHT_BITS},
		{"op": "arc", "left": -2, "top": -1, "right": 5, "bottom": 3, "start_x": 2, "start_y": 1, "end_x": 0, "end_y": 1, "pen_color": 0xABCDEF},
		{"op": "composite_white_key", "left": 0, "top": 0, "weight_bits": Raster.WEIGHT_BITS}]
	var recipe := {"ok": true, "draw_operations": operations}
	var key := Raster.mask_key(2, 1, operations)
	check(key == "2;1;rectangle;0;0;2;1;arc;-2;-1;5;3;2;1;0;1", "Mask key loses native signed geometry or arc endpoints")
	var words := PackedByteArray()
	words.resize(8)
	words.encode_u32(0, 0xFFFFFFFF)
	words.encode_u32(4, 0)
	# Synthetic capture tests routing only. It is not a GDI raster golden.
	var atlas := {"format": "chemlab-gdi-mask-atlas-v2", "guti_sha256": Raster.GUTI_SHA256,
		"native_vcl_verified": false, "entries": {key: {"stencil_texture_bgra": Marshalls.raw_to_base64(words), "arc_coverage": Marshalls.raw_to_base64(PackedByteArray([0, 1]))}}}
	check(not Raster.render_solid_words([0x77112233, 0xFFFFFF], 2, 1, recipe, atlas)["ok"], "Unverified GDI probe accepted")
	atlas["native_vcl_verified"] = true
	var result: Dictionary = Raster.render_solid_words([0x77112233, 0xFFFFFF], 2, 1, recipe, atlas)
	check(result.get("ok", false), "Verified capture could not render: " + str(result))
	if result.get("ok", false):
		check(result["words"] == [0x77112233, 0xEFCDAB], "White-key preservation or COLORREF arc-to-DIB byte order differs")
		var image: Image = result["image"]
		check(image.get_data() == PackedByteArray([0x11, 0x22, 0x33, 255, 0xEF, 0xCD, 0xAB, 255]), "Native reserved high byte was incorrectly used as image opacity")
	var changed: Array = operations.duplicate(true)
	changed[4]["left"] = -3
	check(not Raster.render_solid_words([0, 0], 2, 1, {"ok": true, "draw_operations": changed}, atlas)["ok"], "Missing ellipse/arc mask silently approximated")
	changed = operations.duplicate(true)
	changed[2]["copy_mode"] = 0xCC0020
	check(not Raster.render_solid_words([0, 0], 2, 1, {"ok": true, "draw_operations": changed}, atlas)["ok"], "Unsupported SRCCOPY accepted in original SRCPAINT recipe")
	# Native binary pixel fixtures validate the rasterizer's actual tint/composite
	# route with exact captured source words, not a copied expected formula.
	var path := ProjectSettings.globalize_path("res://").path_join("../evidence/original_logic/native-solid-pixels-oracle.json").simplify_path()
	var fixtures: Dictionary = JSON.parse_string(FileAccess.get_file_as_string(path))
	var tested := 0
	for case in fixtures["cases"]:
		if case["op"] != "composite" or str(case["weight_bits"]) != Raster.WEIGHT_BITS: continue
		var source := int(case["source"])
		# White remains white under native tint; zero-color black remains black.
		if (source & 0xFFFFFF) != 0xFFFFFF and source != 0: continue
		var pixel_ops := [operations[0], operations[2], {"op": "tint_nonwhite", "color_integer": 0, "weight_bits": Raster.WEIGHT_BITS}, operations[5]]
		var pixel_key := Raster.mask_key(1, 1, pixel_ops)
		var raw := PackedByteArray()
		raw.resize(4)
		raw.encode_u32(0, source)
		var capture := {"format": atlas["format"], "guti_sha256": Raster.GUTI_SHA256, "native_vcl_verified": true,
			"entries": {pixel_key: {"stencil_texture_bgra": Marshalls.raw_to_base64(raw), "arc_coverage": "AA=="}}}
		var actual: Dictionary = Raster.render_solid_words([int(case["destination"])], 1, 1, {"ok": true, "draw_operations": pixel_ops}, capture)
		check(actual.get("ok", false) and actual["words"][0] == int(case["native_result"]), "Raster native pixel fixture differs: " + str(case))
		tested += 1
	check(tested > 0, "No native composite frames exercised raster route")
	print("Original material rasterizer: %s; %d native pixel routing frames; synthetic mask plumbing; uncaptured/unverified GDI fail explicitly" % ["PASS" if failures == 0 else "FAIL", tested])
	quit(0 if failures == 0 else 1)
