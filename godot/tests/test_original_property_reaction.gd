extends SceneTree
const Dialogs=preload("res://scripts/lab_dialogs.gd")
func bits(v:float)->String:return PackedFloat64Array([v]).to_byte_array().hex_encode()
func _initialize():
	var d:=Dialogs.new();var fixture=JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_property_reaction.json"))
	for c in fixture.cases:
		var vessel:Dictionary={"native_reaction_records":[]}
		for i in 50:vessel.native_reaction_records.append({"name":"row"+str(i),"reaction_rate":10.0,"parameters":["0","","10","0","单向"],"unknown_preserved":"sentinel"})
		var result:=d.modify_native_reaction_fields(vessel,int(c.row)-1,c.texts);assert(result.ok)
		var r:Dictionary=vessel.native_reaction_records[int(c.row)-1]
		if bits(r.reaction_rate)!=c.rate_bits or bits(r.reaction_heat)!=c.heat_bits or bits(r.equilibrium_degree_or_constant)!=c.equilibrium_bits:
			print(c, " GOT ",bits(r.reaction_rate)," ",bits(r.reaction_heat)," ",bits(r.equilibrium_degree_or_constant));quit(1);return
		assert(r.condition==c.condition and r.equilibrium_mode==c.mode and r.unknown_preserved=="sentinel")
		for i in 50:
			if i!=int(c.row)-1:assert(vessel.native_reaction_records[i].reaction_rate==10.0)
	print("PASS original five-field reaction Modify: ",fixture.cases.size()," native references")
	quit()
