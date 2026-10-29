extends SceneTree
func _init() -> void:
	var cases: Array = JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_liquid.json")).cases
	for c in cases:
		if not str(c.name).begins_with("甲基橙"): continue
		var n := str(c.contents_bits["H+(离子)"]).hex_decode().decode_double(0)
		var v := str(c.volumes_bits["H2O(液体)"]).hex_decode().decode_double(0)
		var conc: float = n / v * 1000.0
		print(c.name," ", -log(conc)/log(10.0)," ", -log(conc)*0.4342944819032518," ", -log(conc)/2.302585092994046)
	quit()
