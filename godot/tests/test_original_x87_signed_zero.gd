extends SceneTree
const X=preload("res://scripts/original/original_x87.gd")
func _initialize()->void:
	var failures:Array=[]
	var positive:float="0000000000000000".hex_decode().decode_double(0)
	var negative:float="0000000000000080".hex_decode().decode_double(0)
	for a in [positive,negative]:
		for b in [positive,negative]:
			var actual:=PackedFloat64Array([X.stored_double(X.add_pair([a,positive],[b,positive]))]).to_byte_array().hex_encode()
			var negative_a:bool=PackedFloat64Array([a]).to_byte_array()[7]==128
			var negative_b:bool=PackedFloat64Array([b]).to_byte_array()[7]==128
			var expected:String="0000000000000080" if negative_a and negative_b else "0000000000000000"
			if actual!=expected:failures.append(["nearest-even FADD zeros",negative_a,negative_b,actual,expected])
	var direct:=PackedFloat64Array([X.stored_double([negative,positive])]).to_byte_array().hex_encode()
	if direct!="0000000000000080":failures.append(["negative-zero direct store",direct])
	print(JSON.stringify({"failures":failures}))
	if failures.is_empty():print("PASS native nearest-even signed-zero addition and direct negative-zero store")
	quit(0 if failures.is_empty() else 1)
