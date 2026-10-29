extends SceneTree
const Math = preload("res://scripts/original/original_math.gd")
const X87 = preload("res://scripts/original/original_x87.gd")
func _init() -> void:
	var data: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_math.json"))
	var differences := 0
	for c in data.cases:
		var x := str(c.x_bits).hex_decode().decode_double(0)
		var y := str(c.y_bits).hex_decode().decode_double(0)
		var actual := Math.log10_native(x) if c.kind == "log10" else Math.pow_native(x,y)
		if actual.is_empty(): print("UNSUPPORTED ",c); differences += 1; continue
		var expected := str(c.double_bits).hex_decode().decode_double(0)
		if PackedFloat64Array([X87.stored_double(actual)]).to_byte_array() != PackedFloat64Array([expected]).to_byte_array():
			differences += 1; print("DIFF ",c.kind," ",x," ",y," ",PackedFloat64Array([X87.stored_double(actual)]).to_byte_array().hex_encode()," ",c.double_bits)
	print("x87 reference ",data.cases.size()," cases; differences ",differences)
	if differences == 0: print("PASS original CRT x87 logarithm/power sequence")
	quit(0 if differences == 0 else 1)
