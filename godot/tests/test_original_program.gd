extends SceneTree
const Program = preload("res://scripts/original/original_program.gd")
func _init() -> void:
	var data: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_program.json"))
	var differences := 0
	var emulator_differences := 0
	for f in data.formats:
		var value := str(f.bits).hex_decode().decode_double(0)
		var actual := Program.format_number(value)
		if actual != str(f.text): print("FORMAT DIFF ",f.bits," ",actual," ",f.text); differences += 1
	for c in data.cases:
		var values := {}
		for key in c.inputs_bits: values[key] = str(c.inputs_bits[key]).hex_decode().decode_double(0)
		var result := Program.assignment(c.expression,values)
		if result.ok != c.ok: print("RESULT DIFF ",c.expression," ",result); differences += 1; continue
		if not result.ok: continue
		for key in c.outputs:
			var expected: String = str(c.get("x87_reference_outputs",{}).get(key,c.outputs[key]))
			if expected != str(c.outputs[key]): emulator_differences += 1
			if Program.format_number(float(values[key])) != expected: print("VALUE DIFF ",c.expression," ",key); differences += 1
	print("Original program ",data.cases.size()," cases; ",data.formats.size()," formatting values; differences ",differences,"; separately verified emulator transcendental differences ",emulator_differences)
	if differences == 0: print("PASS original arithmetic assignments and formatting")
	quit(0 if differences == 0 else 1)
