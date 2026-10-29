extends SceneTree
const Model=preload("res://scripts/original_model_host.gd")
const Formats=preload("res://scripts/legacy_formats.gd")
const Adapter=preload("res://scripts/experiment_adapter.gd")
const Profile=preload("res://scripts/original/original_runtime_profile.gd")
const Slots=preload("res://scripts/original/original_slots.gd")
var failures:Array=[]
var checks:=0
func load_capture(name:String)->Dictionary:
	var path:=ProjectSettings.globalize_path("res://../evidence/windows-runtime/original-captures-2026-10-14/"+name+".json")
	return JSON.parse_string(FileAccess.get_file_as_string(path).trim_prefix("\ufeff"))
func compare(model,profile:Dictionary,stage:String)->void:
	var source_to_field:Dictionary=Profile.FIELDS.duplicate()
	source_to_field.moles_0x8d8="contents";source_to_field.mass_0x298="native_species_mass"
	var records:Array=profile.snapshots[0].vessels
	var vessels:Array=model.native_apparatus()
	for index in records.size():
		var v:Dictionary=vessels[index];var record:Dictionary=records[index]
		var names:Array=[]
		for entry in record.species:names.append(str(entry.text))
		checks+=1
		if names!=v.contents.keys():failures.append([stage,index,"names",v.contents.keys(),names])
		for source in source_to_field:
			var field:String=source_to_field[source]
			var bytes:=str(record.arrays[source].raw_hex).hex_decode()
			for slot in 100:
				checks+=1
				var actual=v.native_slot_backing.arrays[field][slot]
				var expected:String=bytes.slice(slot*8,slot*8+8).hex_encode()
				if actual!=expected:failures.append([stage,index,field,slot,actual,expected])
		for pair in [["0x4318","solid_4318"],["0x3cc8","native_particle_3cc8"],["0x4338","native_solid_volume"]]:
			checks+=1
			var actual:=PackedFloat64Array([float(v.get(pair[1],0.0))]).to_byte_array().hex_encode()
			var expected:String=record.scalars[pair[0]].ieee754_le_hex
			if actual!=expected:failures.append([stage,index,pair[1],actual,expected])
func _initialize()->void:
	var cold:=load_capture("cold-opening");var stopped:=load_capture("after-run-paused");var after_action:=load_capture("after-naoh")
	var model=Model.new()
	model.configure(JSON.parse_string(FileAccess.get_file_as_string("res://data/reagents.json")),JSON.parse_string(FileAccess.get_file_as_string("res://data/reactions.json")))
	if not model.from_state(Adapter.to_state(Formats.load_document("res://tests/fixtures/examples/氢氧化铜与氢氧化铁.cem"))):print("FAIL import ",model.last_error);quit(1);return
	if not model.attach_profile(cold):print("FAIL exact cold allocation attach ",model.last_error);quit(1);return
	compare(model,cold,"cold attachment")
	if not "--compare-live" in OS.get_cmdline_user_args():
		print(JSON.stringify({"checks":checks,"failures":failures,"scope":"Actual cold allocation attachment only; no live tick equivalence claim"}))
		if failures.is_empty():print("PASS actual Windows cold allocation: all 3000 QWORD cells, names and captured scalars")
		quit(0 if failures.is_empty() else 1);return
	if not model.start():print("FAIL original Run ",model.last_error);quit(1);return
	compare(model,stopped,"Run state")
	# This is a source-driven first tick; the native capture has a later clock.
	# Its stationary material/slot state can be compared, not its timing history.
	model.step(0.001)
	if not model.last_error.is_empty():failures.append(["first tick",model.last_error])
	else:compare(model,stopped,"first tick stationary slots")
	var progression:Array=[]
	for iteration in 4:
		var vessel:Dictionary=model.native_apparatus()[2]
		progression.append({"tick":iteration+1,"moles":PackedFloat64Array([float(vessel.contents["惰性气体(气体)"])]).to_byte_array().hex_encode(),"volume":PackedFloat64Array([float(vessel.native_species_volume["惰性气体(气体)"])]).to_byte_array().hex_encode()})
		model.step(0.001)
	for index in stopped.snapshots[0].vessels.size():
		var a:Dictionary=stopped.snapshots[0].vessels[index];var b:Dictionary=after_action.snapshots[0].vessels[index]
		for field in a.arrays:
			checks+=1
			if a.arrays[field].raw_hex!=b.arrays[field].raw_hex:failures.append(["post-click capture changed",index,field])
		checks+=1
		if a.scalars!=b.scalars:failures.append(["post-click scalars changed",index])
	print(JSON.stringify({"checks":checks,"failures":failures,"progression":progression,"clock_scope":"Later paused capture is not a first-tick timing trace; stationary slot state only"}))
	if failures.is_empty():print("PASS actual Windows cold allocation, Run and stationary first-tick slots; no observed NaOH withdrawal")
	quit(0 if failures.is_empty() else 1)
