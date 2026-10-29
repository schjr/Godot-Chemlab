extends SceneTree
## Compare selection, command states and physical doses against original x86.
const Actions = preload("res://scripts/original/original_apparatus_actions.gd")
var failures := 0

func _initialize() -> void:
	var path := ProjectSettings.globalize_path("res://").path_join("../evidence/original_logic/native-actions-oracle.json").simplify_path()
	var fixture: Dictionary = JSON.parse_string(FileAccess.get_file_as_string(path))
	for case in fixture["cases"]:
		var vessels: Array = []
		for input in case["vessels"]:
			var liquid: float = str(input["liquid_volume_bits"]).hex_decode().decode_double(0)
			var contents: Dictionary = {"H2O(液体)": 0.0} if liquid != 0.0 else {}
			vessels.append({"type_id": int(input["type"]), "position": [int(input["x"]), int(input["y"])],
				"native_bitmap_width": int(input["width"]), "native_bitmap_height": int(input["height"]),
				"native_fields": {"0x0c": str(input["size"]), "0x68": str(input.get("state", 7))},
				"native_liquid_height": str(input["liquid_height_bits"]).hex_decode().decode_double(0),
				"native_liquid_height_fresh": true, "native_liquid_volume": 0.0,
				"contents": contents, "native_species_volume": {"H2O(液体)": liquid} if liquid != 0.0 else {}})
		var plan: Dictionary = Actions.plan_manual_action(vessels, int(case["selected"]), int(case["command"]), str(case["scale_bits"]).hex_decode().decode_double(0))
		check(plan.get("ok", false), "%s: port rejected original action frame: %s" % [case["name"], plan])
		if not plan.get("ok", false):
			continue
		var transfers: Array = case["native_transfers"]
		check(bool(plan["transfer"]) == (transfers.size() == 1), "%s: original transfer eligibility differs; native=%s port=%s" % [case["name"], transfers, plan])
		if plan["transfer"] and transfers.size() == 1:
			check(plan["source_index"] == transfers[0]["source_index"] and plan["target_index"] == transfers[0]["target_index"], "%s: original source/recipient differs; native=%s port=%s" % [case["name"], transfers, plan])
			check(PackedFloat64Array([float(plan["requested_volume"])]).to_byte_array().hex_encode() == transfers[0]["requested_bits"], "%s: physical-dose binary64 bits differ" % case["name"])
		var states: Array = []
		for vessel in vessels:
			states.append(int(vessel["native_fields"]["0x68"]))
		if plan["writes"].has("0x68"):
			states[int(case["selected"])] = int(plan["writes"]["0x68"])
		for i in range(states.size()):
			check(int(states[i]) == int(case["native_states"][i]), "%s: original +0x68 command-state writes differ: native=%s port=%s" % [case["name"], case["native_states"], states])
	print("Original manual-action oracle comparison: %s; %d original x86 frames, transfer indices, binary64 doses, +0x68 states" % ["PASS" if failures == 0 else "FAIL (%d)" % failures, fixture["cases"].size()])
	quit(0 if failures == 0 else 1)

func check(value: bool, message: String) -> void:
	if not value:
		failures += 1
		if failures <= 10:
			push_error(message)
