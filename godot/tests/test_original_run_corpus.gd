extends SceneTree
const Host=preload("res://scripts/original_model_host.gd")
const Slots=preload("res://scripts/original/original_slots.gd")
const Formats=preload("res://scripts/legacy_formats.gd")
const Adapter=preload("res://scripts/experiment_adapter.gd")
func number(hex:String)->float:return hex.hex_decode().decode_double(0)
func bits(value:float)->String:return PackedFloat64Array([value]).to_byte_array().hex_encode()
func _initialize():
	var corpus:Dictionary=JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_run_corpus.json"))
	var reagents:Array=JSON.parse_string(FileAccess.get_file_as_string("res://data/reagents.json"))
	var reactions:Array=JSON.parse_string(FileAccess.get_file_as_string("res://data/reactions.json"))
	var failures:Array=[];var tested:=0;var cells:=0;var untouched:=0;var written_active:=0;var written_inactive:=0
	assert(corpus.cases.size()==28)
	for c in corpus.cases:
		if c.status!="executed":failures.append([c.name,"oracle",c.get("error")]);continue
		assert(c.events==["43F7BC stopped refresh-boundary","004624D8","42DC3C save-boundary","0046C894","0048E9B4"])
		var model:=Host.new();model.configure(reagents,reactions)
		if not model.from_state(Adapter.to_state(Formats.load_document(c.fixture_path))):failures.append([c.name,"import",model.last_error]);continue
		var apparatus:Array=model.native_apparatus()
		assert(apparatus.size()==c.before.size())
		for index in apparatus.size():
			var v:Dictionary=apparatus[index];var initial:Dictionary=c.before[index]
			assert(v.contents.keys()==initial.names)
			for field in initial.arrays:assert(Slots.observe(v,field,initial.arrays[field],{"source":"explicit nonzero numeric input from original Run corpus; not production allocator"}).ok)
			assert(Slots.project(v).ok)
			for field in initial.scalars:v[field]=number(initial.scalars[field])
		for connector in model.native_connectors:connector.native_state_0x70=19.75;connector.native_state_0x78=2
		if not model.start():failures.append([c.name,"start",model.last_error]);continue
		apparatus=model.native_apparatus()
		for index in apparatus.size():
			var v:Dictionary=apparatus[index];var expected:Dictionary=c.after[index];var initial:Dictionary=c.before[index]
			if v.contents.keys()!=expected.names:failures.append([c.name,index,"species order"])
			var names:Array=[]
			for r in v.native_reaction_records:names.append(str(r.get("name",r.get("id",""))))
			if names!=expected.reaction_names:failures.append([c.name,index,"reaction order",names,expected.reaction_names])
			for field in expected.arrays:
				var written:Dictionary={}
				for key in c.writes:
					if key.ends_with(":%d:%s"%[index,field]):
						for slot in c.writes[key]:written[int(slot)]=true
				for slot in 100:
					var want:String=expected.arrays[field].substr(slot*16,16)
					var actual=v.native_slot_backing.arrays[field][slot]
					cells+=1
					if actual!=want:failures.append([c.name,index,field,slot,actual,want])
					if not written.has(slot):
						assert(want==initial.arrays[field].substr(slot*16,16));untouched+=1
					elif slot<initial.names.size():written_active+=1
					else:written_inactive+=1
			for field in expected.scalars:
				var actual:=bits(float(v.get(field,NAN)))
				if actual!=expected.scalars[field]:failures.append([c.name,index,field,actual,expected.scalars[field]])
		for index in model.native_connectors.size():
			var connector:Dictionary=model.native_connectors[index]
			if bits(connector.native_state_0x70)!=c.connector_after[index].amount_bits or connector.native_state_0x78!=c.connector_after[index].direction:failures.append([c.name,index,"connector Run clear"])
		assert(model.running and not model.paused and model.elapsed==0.0 and c.run_flag==1)
		tested+=1
	print(JSON.stringify({"examples":tested,"physical_qword_checks":cells,"untouched_cells":untouched,"written_active_cells":written_active,"written_inactive_cells":written_inactive,"failures":failures}))
	if failures.is_empty() and tested==28:print("PASS original Run all28 numeric corpus; explicit allocation/save/graphics boundaries")
	quit(0 if failures.is_empty() and tested==28 else 1)
