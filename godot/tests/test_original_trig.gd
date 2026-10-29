extends SceneTree
const Math = preload("res://scripts/original/original_math.gd")
const X87 = preload("res://scripts/original/original_x87.gd")
func _init() -> void:
	var data: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_trig.json"))
	var stored_differences := 0; var extended_differences := 0
	for c in data.cases:
		var actual := Math.trig_compatible(str(c.x_bits).hex_decode().decode_double(0),str(c.kind))
		var expected := X87.from_extended80_hex(str(c.extended_bits))
		if actual.is_empty() or PackedFloat32Array([X87.stored_float32(actual)]).to_byte_array() != PackedFloat32Array([str(c.double_bits).hex_decode().decode_double(0)]).to_byte_array():
			stored_differences += 1; print("TRIG STORED DIFFERENCE ",c)
		if not expected.is_empty() and X87.add_pair(actual,[-float(expected[0]),-float(expected[1])]) != [0.0,0.0]: extended_differences += 1
	print("TRIG ",data.cases.size()," native cases; binary32 differences ",stored_differences," extended intrinsic differences ",extended_differences)
	if stored_differences == 0: print("PASS experimental binary32 trig compatibility; extended differences remain")
	quit(0 if stored_differences == 0 else 1)
