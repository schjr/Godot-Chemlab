extends SceneTree
const Frame=preload("res://scripts/original/original_particle_frame.gd")
var failures:Array=[]
var checks:=0
func check(ok:bool,label:String)->void:
	checks+=1
	if not ok:failures.append(label)
func vessel(index:int)->Dictionary:
	return {"label":"container"+str(index),"type_id":102,"position":[20+index*100,20],"native_fields":{"0x18":"0"},"native_bitmap_width":4,"native_bitmap_height":5,"native_liquid_height":5.0,"native_liquid_color":0xffffff,"solid_4318":0.0,"gas_3cc0":0.0,"native_particle_3cc8":0.0,"contents":{},"solid_3cd8":{},"solid_3ff8":{}}
func provider(request:Dictionary)->Dictionary:
	if request.get("operation","")=="scanline_words":
		var meta:Dictionary=request.bitmaps[int(request.bitmap)];var words:Array=[];words.resize(int(meta.width)*int(meta.height));words.fill(0)
		return {"ok":true,"bitmap_words":{str(meta.name):words}}
	return {"ok":true}
func audit_ir()->void:
	var ir:Dictionary=JSON.parse_string(FileAccess.get_file_as_string("res://data/original_particle_ir.json"))
	var references:=0
	for name in ir.functions:
		var instructions:Array=ir.functions[name].instructions
		for index in instructions.size():
			var instruction:Dictionary=instructions[index]
			for operand in instruction.operands:
				if int(operand.get("disp",0)) not in [0x595214,0x5940b0]:continue
				references+=1
				check(name in ["frame_solid","frame_gas"] and index>0,"pool tables only referenced by frame slices")
				var prior:Dictionary=instructions[index-1]
				var operands:Array=prior.operands
				check(prior.mnemonic=="mov" and operands.size()==2 and operands[0].get("reg")==operand.get("index") and operands[1].get("base")=="ebp" and int(operands[1].get("disp",0))==-0x60,"every source pool lookup obtains current vessel index immediately beforehand")
	check(references==20,"all20 retained pool lookups audited")
func _initialize()->void:
	audit_ir()
	var source:Array=[vessel(0),vessel(1)]
	var full_vessels:Array=source.duplicate(true);var partial_vessels:Array=source.duplicate(true)
	var full_scene:=Frame.create_scene(full_vessels)
	for pool in full_scene.pools:
		var primary:Array=[];var retained:Array=[]
		for index in 20:primary.append(0x112200+index);retained.append(0x334400+index)
		pool.solid.primary_words=primary;pool.solid.retained_words=retained
	var partial_scene:=full_scene.duplicate(true)
	var frame=Frame.new();var full_rng:Dictionary={"low":1,"high":0};var partial_rng:=full_rng.duplicate()
	var context:Dictionary={"run_flag":1,"pause_flag":0}
	var full:=frame.step(full_vessels,{},[],full_scene,context,full_rng,Callable(),Callable(self,"provider"))
	check(full.ok,"default all-pool source execution succeeds")
	var unselected:Dictionary=partial_scene.pools[1].duplicate(true)
	var first=Frame.new();var part:=first.step_vessel(0,partial_vessels,{},[],partial_scene,context,partial_rng,Callable(),Callable(self,"provider"))
	check(part.ok,"selected source phase succeeds")
	check(partial_scene.pools[0]==full_scene.pools[0] and partial_vessels[0]==full_vessels[0],"selected first-phase output matches full source prefix")
	check(partial_scene.pools[1]==unselected and partial_vessels[1]==source[1],"unselected persistent state remains unchanged")
	check(first.solid_addresses[1]==0 and first.bubble_addresses[1]==0,"unselected pool allocation omitted")
	check(not first.vm.contains_span(0x595214+4,4) and not first.vm.contains_span(0x5940b0+4,4),"unselected pool table cells stay unknown")
	check(first.vm.contains_span(0x585850+4,4),"global other-vessel geometry metadata remains mapped")
	for meta in first.bitmap_meta.values():check(not str(meta.name).ends_with("_1") or str(meta.name)=="vessel_1","unselected pool bitmap backing omitted")
	check(first.vm.helpers.is_empty(),"successful selected source phase releases callbacks")
	var second=Frame.new();part=second.step_vessel(1,partial_vessels,{},[],partial_scene,context,partial_rng,Callable(),Callable(self,"provider"))
	check(part.ok and partial_scene==full_scene and partial_vessels==full_vessels and partial_rng==full_rng,"sequential selected phases equal complete source execution")
	print(JSON.stringify({"checks":checks,"failures":failures}))
	if failures.is_empty():print("PASS source current-vessel pool lookups and selected-phase isolation preserve full-prefix output")
	quit(0 if failures.is_empty() else 1)
