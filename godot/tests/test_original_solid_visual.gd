extends SceneTree
const Solid = preload("res://scripts/original/original_solid_visual.gd")
var failures := 0

func _initialize() -> void:
	var path := ProjectSettings.globalize_path("res://").path_join("../evidence/original_logic/native-solid-visual-oracle.json").simplify_path()
	var fixture: Dictionary = JSON.parse_string(FileAccess.get_file_as_string(path))
	var reagents: Dictionary = {}
	for name in fixture["reagent_fields"]:
		var record: Dictionary = fixture["reagent_fields"][name]
		reagents[name] = {"molar_mass": decode(record["molar_mass_bits"]), "density_or_render_parameter": String.num(decode(record["density_bits"]), 17), "color_integer": int(record["color_integer"])}
	for case in fixture["cases"]:
		var vessel := {"contents": {}, "native_species_volume": {}, "solid_3cd8": {},
			"volume_ml": decode(case["capacity_bits"]), "native_liquid_volume": decode(case["liquid_volume_bits"]),
			"type_id": int(case["type"]), "native_fields": {"0x0c": str(int(case["subtype"]))},
			"native_bitmap_width": int(case["width"]), "native_bitmap_height": int(case["height"])}
		for name in case["contents_bits"]: vessel["contents"][name] = decode(case["contents_bits"][name])
		for name in case["volumes_bits"]: vessel["native_species_volume"][name] = decode(case["volumes_bits"][name])
		for name in case["precipitated_bits"]: vessel["solid_3cd8"][name] = decode(case["precipitated_bits"][name])
		var result: Dictionary = Solid.compute(vessel, reagents)
		check(result.get("ok", false), "%s: original solid frame rejected: %s" % [case["name"], result])
		if not result.get("ok", false): continue
		var expected: Array = case["native_operations"]
		var actual: Array = result["draw_operations"]
		check(actual.size() == expected.size(), "%s: original solid operation count differs: native=%s port=%s" % [case["name"], expected, actual])
		for i in range(mini(actual.size(), expected.size())):
			for field in expected[i]:
				var same := str(actual[i].get(field, "")) == str(expected[i][field]) if field in ["op", "source", "weight_bits"] else int(actual[i].get(field, -9999)) == int(expected[i][field])
				check(same, "%s: original solid op%d %s differs: native=%s port=%s" % [case["name"], i, field, expected[i][field], actual[i].get(field, null)])
	var pixel_path := ProjectSettings.globalize_path("res://").path_join("../evidence/original_logic/native-solid-pixels-oracle.json").simplify_path()
	var pixels: Dictionary = JSON.parse_string(FileAccess.get_file_as_string(pixel_path))
	for case in pixels["cases"]:
		var actual: int
		if case["op"] == "tint":
			actual = Solid.tint_pixel(int(case["pixel"]), int(case["color"]), decode(case["weight_bits"]))
		else:
			actual = Solid.composite_pixel(int(case["destination"]), int(case["source"]), decode(case["weight_bits"]))
		check(actual == int(case["native_result"]), "Original tint/white-key pixel bits differ: " + str(case) + " port=" + str(actual))
	print("Original solid visual oracle comparison: %s; %d original draw frames and %d original pixel frames, RGB/shading, ordered stencil/texture/tint/arc/composite operations and integer geometry" % ["PASS" if failures == 0 else "FAIL (%d)" % failures, fixture["cases"].size(), pixels["cases"].size()])
	quit(0 if failures == 0 else 1)

func check(value: bool, message: String) -> void:
	if not value:
		failures += 1
		if failures <= 10: push_error(message)

func decode(word: String) -> float:
	return word.hex_decode().decode_double(0)
