extends SceneTree
const Host = preload("res://scripts/original/original_x87_host.gd")
const X87 = preload("res://scripts/original/original_x87.gd")
func _init() -> void:
	var host := Host.new()
	var fixture: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_tan.json"))
	var differences := 0
	for c in fixture.cases:
		var actual := host.evaluate(str(c.input_bits).hex_decode().decode_double(0),"tan")
		var expected := X87.from_extended80_hex(str(c.extended_bits))
		if actual.is_empty() or expected.is_empty() or actual != expected:
			differences += 1
			print("TAN mismatch ",c.input_bits," actual=",actual," expected=",expected)
		elif PackedFloat64Array([X87.stored_double(actual)]).to_byte_array().hex_encode() != c.stored_bits:
			differences += 1
			print("TAN store mismatch ",c.input_bits," actual=",PackedFloat64Array([X87.stored_double(actual)]).to_byte_array().hex_encode()," expected=",c.stored_bits)
	assert(host.evaluate(pow(2.0,53),"tan").is_empty())
	host.stop()
	print("FPTAN instruction provider ",fixture.cases.size()," references; differences ",differences)
	if differences == 0: print("PASS exact bounded FPTAN instruction provider and qword stores")
	quit(0 if differences == 0 else 1)
