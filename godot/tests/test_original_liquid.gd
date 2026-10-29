extends SceneTree
const Liquid = preload("res://scripts/original/original_liquid.gd")
func _init() -> void:
	var data: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_liquid.json"))
	var reagents: Array = JSON.parse_string(FileAccess.get_file_as_string("res://data/reagents.json"))
	var lookup := {}
	for r in reagents: lookup[str(r.species)] = r
	var height_differences := 0
	var failures := 0
	for c in data.cases:
		var v := {"contents":{}, "native_species_volume":{}, "volume_ml":c.capacity_bits.hex_decode().decode_double(0),"type_id":c.type,"native_bitmap_width":c.width,"native_bitmap_height":c.height,"native_liquid_volume":0.0}
		for s in c.contents_bits: v.contents[s] = str(c.contents_bits[s]).hex_decode().decode_double(0)
		for s in c.volumes_bits: v.native_species_volume[s] = str(c.volumes_bits[s]).hex_decode().decode_double(0)
		var result := Liquid.refresh(v,lookup)
		if not result.ok: print("FAIL ",c.name," ",result); failures += 1; continue
		var height_expected := str(c.height_bits).hex_decode().decode_double(0)
		if PackedFloat64Array([float(v.native_liquid_height)]).to_byte_array().hex_encode() != c.height_bits:
			height_differences += 1
			print("HEIGHT BITS ",c.name," ",PackedFloat64Array([float(v.native_liquid_height)]).to_byte_array().hex_encode()," ",c.height_bits)
			if absf(float(v.native_liquid_height)-height_expected) > 1e-12: print("HEIGHT FAIL ",c.name); failures += 1
		if int(v.get("native_liquid_color",0)) != int(c.color): print("COLOR FAIL ",c.name," ",v.get("native_liquid_color",0)," != ",c.color); failures += 1
		if not c.rectangles.is_empty():
			var rect: Array = c.rectangles[0]
			if v.native_liquid_rectangle != [int(rect[0]),int(rect[1]),int(rect[3]),int(rect[2])]: print("RECT FAIL ",c.name," ",v.native_liquid_rectangle," ",rect); failures += 1
	print("Original liquid renderer ",data.cases.size()," frames; failures ",failures,"; CRT height rounding differences ",height_differences)
	if failures == 0: print("PASS original liquid formulas, colors and rectangles")
	quit(0 if failures == 0 else 1)
