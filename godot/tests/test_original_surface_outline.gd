extends SceneTree
const Surface = preload("res://scripts/original/original_surface_outline.gd")
var failures := 0
func check(condition: bool, message: String) -> void:
	if not condition:
		failures += 1
		push_error(message)
func decode(hex: String) -> float:
	var bytes := PackedByteArray()
	for i in range(0, hex.length(), 2): bytes.append(hex.substr(i, 2).hex_to_int())
	return bytes.decode_double(0)
func _initialize() -> void:
	var path := ProjectSettings.globalize_path("res://").path_join("../evidence/original_logic/native-surface-oracle.json").simplify_path()
	var fixture: Dictionary = JSON.parse_string(FileAccess.get_file_as_string(path))
	for case in fixture.cases:
		var result: Dictionary = Surface.compute({"type_id": int(case.type), "native_liquid_color": int(case.color),
			"native_liquid_height": decode(case.height_bits), "native_bitmap_width": int(case.width), "native_bitmap_height": int(case.height)})
		check(result.get("ok", false), "Original outline frame rejected")
		if not result.get("ok", false): continue
		check(result.pen_color == int(case.native_pen_color) and result.brush_style == int(case.native_brush_style), "Original outline pen/brush state differs: " + str(case))
		check(result.draw_operations.size() == case.native_operations.size(), "Original outline branch eligibility differs: " + str(case.type))
		for i in range(mini(result.draw_operations.size(), case.native_operations.size())):
			for field in result.draw_operations[i]:
				check(str(result.draw_operations[i][field]) == str(case.native_operations[i][field]) if field == "op" else int(result.draw_operations[i][field]) == int(case.native_operations[i][field]), "Original outline operand differs: " + field)
	check(not Surface.compute({"type_id": 101}).ok, "Missing original liquid color silently synthesized")
	print("Original surface outline: %s; %d original instruction frames, exact shaded pen, hollow Rectangle, supported-type branches and integer bounds" % ["PASS" if failures == 0 else "FAIL", fixture.cases.size()])
	quit(0 if failures == 0 else 1)
