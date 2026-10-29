extends SceneTree
const Owner=preload("res://scripts/original/original_runtime_allocation.gd")
const Slots=preload("res://scripts/original/original_slots.gd")
const Host=preload("res://scripts/original_model_host.gd")
const Formats=preload("res://scripts/legacy_formats.gd")
const Adapter=preload("res://scripts/experiment_adapter.gd")
var failures:Array=[]
var checks:=0
func check(ok:bool,label:String)->void:
	checks+=1
	if not ok:failures.append(label)
func _initialize()->void:
	var owner=Owner.new()
	check(owner.initialize().ok,"fresh reconstructed process initialization")
	check(owner.heap.get_mem(4096).ok,"leading source arena guard")
	var a:Dictionary={"contents":{"water":1.0}}
	var guard:Dictionary={"contents":{}}
	check(owner.bind(a).ok,"source allocator apparatus backing")
	check(Slots.read(a,"solid_3cd8",99).ok,"fresh known page supplies inactive particle cell")
	check(owner.bind(guard).ok,"adjacent allocated guard prevents source arena reclamation")
	var token:String=a[Owner.TOKEN];var pointer:int=owner.allocations[token]
	check(Slots.write_hex(a,"solid_3cd8",99,"000000000000d03f").ok,"explicit stale numeric write")
	check(owner.commit(a).ok,"commit exact physical cells")
	check(owner.release(a).ok,"actual source free")
	var b:Dictionary={"contents":{}}
	check(owner.bind(b).ok,"actual source subsequent allocation")
	check(owner.allocations[b[Owner.TOKEN]]==pointer,"source selects guarded freed apparatus chunk")
	check(Slots.read(b,"solid_3cd8",99).raw_hex=="000000000000d03f","inactive reused particle bytes preserved")
	owner.close()
	var corpus:Dictionary=JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_run_corpus.json"))
	var tested:=0
	for c in corpus.cases:
		var model=Host.new()
		var imported:bool=model.from_state(Adapter.to_state(Formats.load_document(c.fixture_path)))
		check(imported,str(c.name)+" default import: "+model.last_error)
		if not imported:continue
		check(not JSON.stringify(model.to_state()).contains(Owner.TOKEN),"owned process identity excluded from save")
		if not model.start():check(false,str(c.name)+" default Run: "+model.last_error);continue
		for tick in 2:
			model.step(0.001)
			if not model.last_error.is_empty():break
		check(model.last_error.is_empty(),str(c.name)+" default frames: "+model.last_error)
		if model.last_error.is_empty():tested+=1
		if tested==1:
			var first:Dictionary=model.native_apparatus()[0]
			check(Slots.write_hex(first,"solid_3cd8",99,"000000000000e03f").ok and model._sync_slots(first),"source inactive write before save")
			var state:Dictionary=model.to_state()
			check(model.from_state(state),"saved allocation bytes restored into new owned identities")
			check(Slots.read(model.native_apparatus()[0],"solid_3cd8",99).raw_hex=="000000000000e03f","saved inactive stale particle QWORD survives load")
			var added:Dictionary=model.add_apparatus("djqp",Vector2(200,200))
			check(not added.is_empty(),"normal palette creates owned numerical allocation")
			if not added.is_empty():model.remove_apparatus(int(added.id))
			check(model.runtime_allocation.allocations.size()==model.native_apparatus().size(),"palette removal frees exact allocation lifetime")
		model.reset()
		check(model.runtime_allocation.allocations.is_empty(),"document reset releases all apparatus blocks")
	print(JSON.stringify({"examples":tested,"checks":checks,"failures":failures}))
	if failures.is_empty():print("PASS production-owned source allocator startup all28 examples without observations or fixture allocation cells")
	quit(0 if failures.is_empty() and tested==28 else 1)
