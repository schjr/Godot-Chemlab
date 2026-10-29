extends SceneTree
const Math = preload("res://scripts/original/original_math.gd")
const X87 = preload("res://scripts/original/original_x87.gd")
func _init() -> void:
	var data: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_sqrt.json"))
	var differences := 0
	for c in data.cases:
		var actual := Math.sqrt_native(str(c.x_bits).hex_decode().decode_double(0))
		var expected := X87.from_extended80_hex(str(c.extended_bits))
		if actual.is_empty() or PackedFloat64Array([X87.stored_double(actual)]).to_byte_array().hex_encode() != c.double_bits:
			differences += 1; print("SQRT DIFF ",c); continue
		if not expected.is_empty() and X87.add_pair(actual,[-float(expected[0]),-float(expected[1])]) != [0.0,0.0]:
			differences += 1; print("SQRT EXTENDED DIFF ",c)
	print("FSQRT ",data.cases.size()," native cases; differences ",differences)
	if differences == 0: print("PASS original FSQRT precision")
	quit(0 if differences == 0 else 1)
