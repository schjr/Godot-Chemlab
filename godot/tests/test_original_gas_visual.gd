extends SceneTree
const Gas = preload("res://scripts/original/original_gas_visual.gd")
var failures := 0

func _initialize() -> void:
	var path := ProjectSettings.globalize_path("res://").path_join("../evidence/original_logic/native-gas-visual-oracle.json").simplify_path()
	var fixture: Dictionary = JSON.parse_string(FileAccess.get_file_as_string(path))
	var reagents: Dictionary = {}
	for name in fixture["reagent_fields"]:
		reagents[name] = {"color_integer": int(fixture["reagent_fields"][name]["color_integer"])}
	for case in fixture["cases"]:
		var contents: Dictionary = {}
		for name in case["contents_bits"]: contents[name] = decode(case["contents_bits"][name])
		var vessel := {"contents": contents, "volume_ml": decode(case["capacity_bits"]),
			"native_liquid_volume": decode(case["liquid_volume_bits"]), "native_liquid_height": decode(case["liquid_height_bits"]),
			"native_bitmap_width": int(case["width"]), "native_bitmap_height": int(case["height"])}
		var result: Dictionary = Gas.compute(vessel, reagents)
		check(result.get("ok", false), "%s: original gas frame rejected: %s" % [case["name"], result])
		if not result.get("ok", false): continue
		var expected: Array = case["native_operations"]
		var actual: Array = result["draw_operations"]
		check(actual.size() == expected.size(), "%s: original gas drawing eligibility differs" % case["name"])
		for i in range(mini(actual.size(), expected.size())):
			for field in expected[i]:
				var same := str(actual[i].get(field, "")) == str(expected[i][field]) if field == "op" else int(actual[i].get(field, -9999)) == int(expected[i][field])
				check(same, "%s: original gas %s differs: native=%s port=%s" % [case["name"], field, expected[i][field], actual[i].get(field, null)])
	print("Original gas visual oracle comparison: %s; %d original frames, drawing eligibility, exact RGB/brush values and rectangle bounds" % ["PASS" if failures == 0 else "FAIL (%d)" % failures, fixture["cases"].size()])
	quit(0 if failures == 0 else 1)

func check(value: bool, message: String) -> void:
	if not value:
		failures += 1
		if failures <= 10: push_error(message)

func decode(word: String) -> float:
	return word.hex_decode().decode_double(0)
