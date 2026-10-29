extends SceneTree
const Renderer = preload("res://scripts/original/original_vessel_bitmap_renderer.gd")
var failures := 0
func check(condition: bool, message: String) -> void:
	if not condition:
		failures += 1
		push_error(message)
func decode(hex: String) -> float:
	var data := PackedByteArray()
	for i in range(0, hex.length(), 2): data.append(hex.substr(i, 2).hex_to_int())
	return data.decode_double(0)
func _initialize() -> void:
	var path := ProjectSettings.globalize_path("res://").path_join("../evidence/original_logic/native-vessel-pixels-oracle.json").simplify_path()
	var fixture: Dictionary = JSON.parse_string(FileAccess.get_file_as_string(path))
	for case in fixture["cases"]:
		var actual := Renderer.fill_pixel(int(case.destination), int(case.mask), decode(case.weight_bits))
		check(actual == int(case.native_result), "Original 4926E0 final fill-mask pixel differs: " + str(case) + " actual=" + str(actual))
	var empty := {"type_id": 102, "native_fields": {"0x18": "0", "0x0c": "0"}, "contents": {},
		"native_species_volume": {}, "native_liquid_volume": 0.0, "native_liquid_height": 123.0,
		"native_solid_volume": 0.0, "volume_ml": 100.0, "native_bitmap_width": 2, "native_bitmap_height": 1}
	var frame_plan: Dictionary = Renderer.plan(empty, {})
	check(frame_plan.get("ok", false), "Original empty vessel plan failed")
	if frame_plan.get("ok", false):
		check(empty.native_liquid_height == 0.0 and empty.native_liquid_height_fresh, "Native height-reset/liquid refresh order differs")
		check(frame_plan.stages[2].native_function == 0x471650 and frame_plan.stages[3].native_function == 0x47692C and frame_plan.stages[6].native_function == 0x4744DC, "Native liquid/gas/solid stage order differs")
		check(frame_plan.stages[4].requires_capture and frame_plan.stages[7].requires_capture, "Unresolved particle/overlay stages silently omitted")
	empty.contents = {"H2O(液体)": 1.0}
	empty.native_species_volume = {"H2O(液体)": 18.0}
	empty.native_bitmap_width = 43
	empty.native_bitmap_height = 101
	var water_plan: Dictionary = Renderer.plan(empty, {"H2O(液体)": {"color_integer": 0xF8F5EB}})
	check(water_plan.get("ok", false), "Native liquid+surface plan failed")
	if water_plan.get("ok", false):
		var liquid_op: Dictionary = water_plan.stages[2].draw_operations[0]
		check(liquid_op.left == 0 and liquid_op.right == 43 and liquid_op.bottom == 101, "Liquid geometry is not serialized in native GDI operation contract")
		check(water_plan.stages[5].draw_operations[0].brush_style == 1, "Surface stage still lacks the ported hollow Rectangle")
	empty.native_fields["0x18"] = "2"
	check(not Renderer.plan(empty, {}).ok, "Unported tilted branch silently used upright geometry")
	var vessel := {"type_id": 201, "native_fields": {"0x0c": "1000"}, "native_bitmap_width": 2, "native_bitmap_height": 1}
	check(Renderer.fill_weight(vessel) == 0.3, "201/202 1000mL native composition weight differs")
	vessel.type_id = 202
	check(Renderer.fill_weight(vessel) == 0.3, "202 1000mL native composition weight differs")
	vessel.native_fields["0x0c"] = "500"
	check(Renderer.fill_weight(vessel) == 1.0, "Other native fill weight differs")
	var result: Dictionary = Renderer.compose_native_words(vessel, [0x112233, 0x77112233], [0xFFFFFF, 0], [0x123456, 0], {})
	check(not result.ok, "Unverified native material input was accepted")
	result = Renderer.compose_native_words(vessel, [0x112233, 0x77112233], [0xFFFFFF, 0], [0x123456, 0], {"native_material_verified": true, "native_srcpaint_word_format_verified": true})
	check(result.get("ok", false), "Verified native pixel composition failed")
	if result.get("ok", false): check(result.words == [0x123456, 0x112233], "Native OR-before-mask order or reserved byte clearing differs")
	check(not Renderer.compose_native_words(vessel, [0], [0], [0], {"native_material_verified": true, "native_srcpaint_word_format_verified": true}).ok, "Mismatched native bitmap geometry accepted")
	print("Original vessel bitmap renderer: %s; %d original executable fill-mask pixel frames, SRCPAINT ordering, special weights, native reserved-byte cases; prior GDI material stages remain capture-required" % ["PASS" if failures == 0 else "FAIL", fixture.cases.size()])
	quit(0 if failures == 0 else 1)
