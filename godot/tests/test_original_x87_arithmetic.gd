extends SceneTree
const X = preload("res://scripts/original/original_x87.gd")
func value(hex: String) -> float: return hex.hex_decode().decode_double(0)
func _initialize() -> void:
	var fixture: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_x87_arithmetic.json"))
	var failures: Array = []
	for index in range(fixture.cases.size()):
		var c: Dictionary = fixture.cases[index]
		var a := value(c.a_bits)
		var b := value(c.b_bits)
		var operand_c := value(c.c_bits)
		var result: Array
		if c.kind == "multiply_divide":
			result = X.divide(X.multiply([a, 0.0], b), operand_c)
		else:
			result = X.add(X.multiply(X.multiply(X.divide([a, 0.0], b), operand_c), -1.0), operand_c)
		if result.is_empty(): failures.append([index, "unsupported"]); continue
		var actual := PackedFloat64Array([X.stored_double(result)]).to_byte_array().hex_encode()
		if actual != c.expected_bits: failures.append([index, actual, c.expected_bits])
	var subnormal := value("0000000001000000")
	if X.compare_to_double(X.multiply([subnormal, 0.0], .001), 0.0) != 1: failures.append("subnormal sign comparison")
	if X.stored_double(X.add([subnormal, 0.0], 0.0)) != subnormal: failures.append("subnormal plus zero")
	# Native instruction results include signed zero and values smaller than a
	# binary64 normal. Verify conversion independently of arithmetic equality.
	for c in [
		["00000000000000000000", "0000000000000000"],
		["00000000000000000080", "0000000000000080"],
		["0000000000000080cd3b", "0100000000000000"],
		["0000000000000080cdbb", "0100000000000080"],
		["0000000000000080cc3b", "0000000000000000"],
		["0100000000000080cc3b", "0100000000000000"]
	]:
		var decoded := X.from_extended80_hex(c[0])
		var actual := PackedFloat64Array([X.stored_double(decoded)]).to_byte_array().hex_encode()
		if actual != c[1]: failures.append(["extended qword store", c[0], actual, c[1]])
	print(JSON.stringify({"x87_arithmetic_cases":fixture.cases.size(),"failures":failures}))
	if failures.is_empty():print("PASS original x87 subnormal arithmetic references")
	quit(0 if failures.is_empty() else 1)
