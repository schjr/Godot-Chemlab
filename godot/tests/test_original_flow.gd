extends SceneTree
const Flow = preload("res://scripts/original/original_flow.gd")
var failures := 0

func _initialize() -> void:
	var path := ProjectSettings.globalize_path("res://").path_join("../evidence/original_logic/native-flow-oracle.json").simplify_path()
	var fixture: Dictionary = JSON.parse_string(FileAccess.get_file_as_string(path))
	var reagents: Dictionary = {}
	for name in fixture["reagent_bits"]:
		var record: Dictionary = fixture["reagent_bits"][name]
		reagents[name] = {"molar_mass": decode(record["molar_mass"]), "density_or_render_parameter": String.num(decode(record["density"]), 17)}
	for case in fixture["cases"]:
		var vessels: Array = []
		for i in range(case["vessels"].size()):
			var input: Dictionary = case["vessels"][i]
			var before: Dictionary = case["before"][i]
			var contents: Dictionary = {}
			var volumes: Dictionary = {}
			for name in before["contents"]: contents[name] = decode(before["contents"][name])
			for name in before["volumes"]: volumes[name] = decode(before["volumes"][name])
			vessels.append({"type_id": int(input["type"]), "position": [int(input["x"]), int(input["y"])],
				"native_fields": {"0x0c": str(input["size"]), "0x18": str(input.get("orientation", 0)), "0x68": str(input.get("state", 1)), "0x6c": str(input.get("solid_mode", 0))},
				"native_bitmap_width": int(input["width"]), "native_bitmap_height": int(input["height"]),
				"volume_ml": decode(before["capacity_bits"]), "temperature": decode(before["temperature_bits"]),
				"contents": contents, "native_species_volume": volumes,
				"native_liquid_volume": decode(before["native_liquid_volume_bits"]),
				"native_solid_volume": decode(before["native_solid_volume_bits"])})
		var plan: Dictionary = Flow.plan_frame(vessels, decode(case["delta_bits"]), decode(case["scale_bits"]), reagents)
		check(plan.get("ok", false), "%s: port rejected original frame: %s" % [case["name"], plan])
		if not plan.get("ok", false): continue
		var expected: Array = case["native_calls"]
		check(plan["calls"].size() == expected.size(), "%s: original transfer-call count differs: native=%s port=%s" % [case["name"], expected, plan["calls"]])
		for i in range(mini(plan["calls"].size(), expected.size())):
			var actual: Dictionary = plan["calls"][i]
			check(actual["source_index"] == expected[i]["source_index"] and actual["target_index"] == expected[i]["target_index"] and actual["solid"] == expected[i]["solid"], "%s: source/recipient/phase differs: native=%s port=%s" % [case["name"], expected[i], actual])
			check(bits(actual["requested_volume"]) == expected[i]["requested_bits"], "%s: original x87 rate-dose bits differ: native=%s port=%s" % [case["name"], expected[i]["requested_bits"], bits(actual["requested_volume"])])
	var orientation_path := ProjectSettings.globalize_path("res://").path_join("../evidence/original_logic/native-orientation-oracle.json").simplify_path()
	var orientations: Dictionary = JSON.parse_string(FileAccess.get_file_as_string(orientation_path))
	for case in orientations["cases"]:
		var vessel := {"type_id": int(case["type"]), "native_fields": {"0x0c": str(int(case["subtype"])), "0x18": str(int(case["orientation_before"]))}}
		var result: Dictionary = Flow.toggle_pour(vessel)
		check(result.get("ok", false), "Original N18 toggle unexpectedly rejected")
		check(int(vessel["native_fields"]["0x18"]) == int(case["orientation_after"]), "Original N18 orientation write differs: " + str(case))
		var paths: Array = []
		if result.has("bitmap_plain"):
			paths = [result["bitmap_plain"], result["bitmap_fill"]]
		check(paths == case["loaded_paths"], "Original N18 bitmap file/mask selection differs: " + str(case))
		if case["menu_checked"] != null:
			check(bool(result.get("menu_checked", false)) == bool(case["menu_checked"]), "Original menu check state differs")
	var unsupported: Dictionary = Flow.plan_frame([{"type_id": 311, "native_fields": {"0x18": "0"}}], 0.1, 1.0, reagents)
	check(not unsupported.get("ok", true) and str(unsupported.get("error", "")).contains("GDI"), "Unresolved GDI conduit geometry must fail explicitly")
	var material_path := ProjectSettings.globalize_path("res://").path_join("../evidence/original_logic/native-flow-material-oracle.json").simplify_path()
	var material: Dictionary = JSON.parse_string(FileAccess.get_file_as_string(material_path))
	var material_reagents: Dictionary = {}
	for name in material["reagent_bits"]:
		material_reagents[name] = {"molar_mass": decode(material["reagent_bits"][name]["molar_mass"]), "density_or_render_parameter": String.num(decode(material["reagent_bits"][name]["density"]), 17)}
	for case in material["cases"]:
		var vessels: Array = []
		for i in range(case["before"].size()):
			var old: Dictionary = case["before"][i]
			var record: Dictionary = case["records"][i]
			var v := {"type_id": int(record["type"]), "position": [int(record["x"]), int(record["y"])], "contents": {}, "native_species_volume": {},
				"native_fields": {"0x18": str(int(record["orientation"])), "0x0c": str(int(record["size"])), "0x68": str(int(record["state"])), "0x6c": "0"},
				"native_bitmap_width": int(record["width"]), "native_bitmap_height": int(record["height"]),
				"volume_ml": decode(old["capacity"]), "temperature": decode(old["temperature"]),
				"native_liquid_volume": decode(old["liquid_volume"]), "native_solid_volume": decode(old["solid_volume"])}
			for name in old["contents"]: v["contents"][name] = decode(old["contents"][name])
			for name in old["volumes"]: v["native_species_volume"][name] = decode(old["volumes"][name])
			var slots: Array = []; slots.resize(100); slots.fill(0.0)
			var slot := 0
			for name in v["contents"]: slots[slot] = v["native_species_volume"][name]; slot += 1
			v["native_species_volume_slots"] = slots
			vessels.append(v)
		var advanced: Dictionary = Flow.advance(vessels, decode(case["delta_bits"]), decode(case["scale_bits"]), material_reagents)
		check(advanced.get("ok", false), "Original material-flow frame unexpectedly rejected: " + str(advanced))
		if not advanced.get("ok", false): continue
		check(advanced["calls"].size() == case["calls"].size(), "Native liquid-depletion/solid-fallback call count differs")
		for i in range(vessels.size()):
			var expected: Dictionary = case["after"][i]
			for mapping in [["contents", "contents"], ["masses", "native_species_mass"], ["volumes", "native_species_volume"]]:
				var actual: Dictionary = vessels[i][mapping[1]]
				check(actual.keys() == expected[mapping[0]].keys(), "Native material-flow species ordering differs")
				for name in expected[mapping[0]]:
					check(bits(float(actual.get(name, INF))) == expected[mapping[0]][name], "%s: material-flow bits differ vessel%d %s/%s: native=%s port=%s" % [case["name"], i, mapping[0], name, expected[mapping[0]][name], bits(float(actual.get(name, INF)))])
			for mapping in [["temperature", "temperature"], ["liquid_volume", "native_liquid_volume"], ["solid_volume", "native_solid_volume"], ["gas_moles", "native_gas_moles"], ["gas_volume", "native_gas_volume"], ["pressure", "native_pressure"]]:
				check(bits(float(vessels[i][mapping[1]])) == expected[mapping[0]], "%s: material-flow scalar bits differ vessel%d %s" % [case["name"], i, mapping[0]])
	print("Original continuous-flow/N18 oracle comparison: %s; %d native call frames, %d orientation/bitmap toggles, %d full native material-flow frames with every recorded binary64 result" % ["PASS" if failures == 0 else "FAIL (%d)" % failures, fixture["cases"].size(), orientations["cases"].size(), material["cases"].size()])
	quit(0 if failures == 0 else 1)

func check(value: bool, message: String) -> void:
	if not value:
		failures += 1
		if failures <= 10: push_error(message)

func decode(word: String) -> float:
	return word.hex_decode().decode_double(0)

func bits(value: float) -> String:
	return PackedFloat64Array([value]).to_byte_array().hex_encode()
