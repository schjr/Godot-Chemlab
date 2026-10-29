extends SceneTree
const Live=preload("res://scripts/original/original_live_property.gd")
func _initialize():
	var fixture=JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_live_property.json"))
	var errors:Array=[]
	for c in fixture.cases:
		var value:float=str(c.bits).hex_decode().decode_double(0)
		var actual:=Live.format_number(value)
		if actual!=c.text:errors.append({"bits":c.bits,"expected":c.text,"actual":actual})
	print(JSON.stringify({"native_live_formats":fixture.cases.size(),"mismatches":errors}))
	if errors.is_empty():print("PASS original live properties")
	quit(0 if errors.is_empty() else 1)
