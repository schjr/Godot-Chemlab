extends SceneTree
const Dialogs=preload("res://scripts/lab_dialogs.gd")
const Model=preload("res://scripts/lab_model.gd")
func _initialize()->void:
	var model:=Model.new();model.configure(JSON.parse_string(FileAccess.get_file_as_string("res://data/reagents.json")),[])
	var dialogs:=Dialogs.new();dialogs.configure(Control.new(),model)
	var data:Dictionary=JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_property_quantity.json"));var errors:Array=[]
	for c in data.cases:
		var rows:Array=[["H2O(液体)","0.123456789012345","2.224197"],["HCl(溶解)","0.02","0.7292"]]
		var result:=dialogs.modify_property_quantity_rows(rows,1,c.species,c.text,c.mode=="mass")
		if not c.messages.is_empty():
			if result.ok:errors.append([c.species,c.mode,c.text,"native rejection"])
			continue
		if not result.ok:errors.append([c.species,c.mode,c.text,result]);continue
		if result.rows!=c.rows:errors.append([c.species,c.mode,c.text,"grid text",result.rows,c.rows])
		for row in c.stored_bits:
			for field in ["mass","moles"]:
				var value:float=result.masses[row.species] if field=="mass" else result.contents[row.species]
				if PackedFloat64Array([value]).to_byte_array().hex_encode()!=row[field]:errors.append([c.species,c.mode,c.text,"stored",field])
	print(JSON.stringify({"quantity_cases":data.cases.size(),"errors":errors.slice(0,10),"error_count":errors.size(),"native_errors":data.errors.size()}))
	if errors.is_empty() and data.errors.is_empty():print("PASS original Form4 quantity/mass Modify")
	dialogs.host.free();quit(0 if errors.is_empty() and data.errors.is_empty() else 1)
