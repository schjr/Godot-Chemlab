extends SceneTree
const Parser = preload("res://scripts/original/original_program.gd")
const X87 = preload("res://scripts/original/original_x87.gd")
func _init() -> void:
	var fixture: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_decimal.json"))
	var mismatches: Array = []
	for c in fixture.cases:
		var expected := X87.from_extended80_hex(str(c.operand_extended_bits))
		var actual := Parser.parse_number(str(c.text))
		if actual != expected: mismatches.append([c.text,actual,expected])
	print(JSON.stringify({"native_decimal_cases":fixture.cases.size(),"mismatches":mismatches}))
	if mismatches.is_empty(): print("PASS original full-significance decimal parser")
	quit(0 if mismatches.is_empty() else 1)
