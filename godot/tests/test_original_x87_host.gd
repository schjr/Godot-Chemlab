extends SceneTree
const Host = preload("res://scripts/original/original_x87_host.gd")
const X87 = preload("res://scripts/original/original_x87.gd")
func _init() -> void:
	var host := Host.new()
	var data: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_trig.json"))
	var differences := 0
	for c in data.cases:
		var actual := host.evaluate(str(c.x_bits).hex_decode().decode_double(0),str(c.kind))
		var expected := X87.from_extended80_hex(str(c.extended_bits))
		if actual.is_empty() or expected.is_empty() or actual != expected: differences += 1
	host.stop()
	print("Native x87 host ",data.cases.size()," cases; differences ",differences)
	if differences == 0: print("PASS exact FSIN/FCOS instruction provider")
	quit(0 if differences == 0 else 1)
