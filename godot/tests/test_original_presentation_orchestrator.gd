extends SceneTree
## Synthetic provider/control-flow tests only. No invented pixel goldens.
const Orchestrator = preload("res://scripts/original/original_presentation_orchestrator.gd")
const Frame = preload("res://scripts/original/original_particle_frame.gd")
class TraceGdi extends RefCounted:
	var calls: Array = []
	func render_ops(w:int,h:int,ops:Array,initial:Array=[],_probe:bool=false,_format:int=32,mode:int=1)->Dictionary:
		calls.append(ops.duplicate(true))
		var words := initial.duplicate()
		if words.is_empty():words.resize(w*h);words.fill(0xFFFFFF)
		return {"ok":true,"words":words,"stretch_mode":mode,"native_vcl_verified":false}
	func render_solid(words:Array,_w:int,_h:int,_recipe:Dictionary,_probe:bool=false)->Dictionary:return {"ok":true,"words":words.duplicate(),"native_vcl_verified":false}
	func copy_rect()->void:pass
func vessel(index:int)->Dictionary:
	return {"label":"v"+str(index),"type_id":202,"position":[0,0],"native_fields":{"0x18":"0","0x0c":"100"},"volume_ml":100.0,"native_bitmap_width":2,"native_bitmap_height":2,"contents":{},"native_species_volume":{},"native_liquid_volume":0.0,"native_liquid_height":6.5,"solid_3cd8":{},"solid_3ff8":{}}
func bitmap()->Dictionary:
	return {"material":{"bitmap_format":32,"width":2,"height":2,"initial_stretch_mode":3},"plain":{"bitmap_format":32,"width":2,"height":2,"words":[0,0,0,0]},"fill":{"bitmap_format":32,"width":2,"height":2,"words":[0xFFFFFF,0xFFFFFF,0xFFFFFF,0xFFFFFF]},"copy_rect":{"destination_rect":[0,0,2,2],"source_rect":[0,0,2,2]}}
func _initialize()->void:
	var orchestrator := Orchestrator.new()
	var gdi := TraceGdi.new()
	var seen: Array = []
	var particle := func(request:Dictionary)->Dictionary:
		seen.append([request.native_index,"particles",request.vessels[1].native_liquid_height])
		return {"ok":true,"words":request.words.duplicate(),"stretch_mode":request.canvas_state.stretch_mode,"canvas_state":request.canvas_state.duplicate(),"native_vcl_verified":false}
	var overlay := func(request:Dictionary)->Dictionary:
		seen.append([request.native_index,"overlays"])
		return {"ok":true,"words":request.words.duplicate(),"stretch_mode":request.canvas_state.stretch_mode,"native_vcl_verified":false}
	var snapshot := {"vessels":[vessel(0),vessel(1)],"connectors":[],"scene":{"pools":[{},{}]},"rng":{"low":123,"high":456},"context":{"run_flag":0,"pause_flag":0},"catalog":{},"bitmaps":[bitmap(),bitmap()]}
	var providers := {"gdi":gdi,"particles":particle,"overlays":overlay}
	var rejected: Dictionary = await orchestrator.render(snapshot,providers,{})
	assert(not rejected.ok and str(rejected.error).contains("unverified"))
	var result: Dictionary = await orchestrator.render(snapshot,providers,{},true)
	assert(result.ok,str(result))
	var expected: Array = []
	for i in 2:
		for stage in ["clear","liquid","gas","particles","surface","settled","overlays","plain_srcpaint","fill_blend"]:expected.append([i,stage])
	assert(result.order==expected)
	assert(seen[0]==[0,"particles",6.5] and seen[2]==[1,"particles",0.0],"Following vessel cache refreshed prematurely")
	assert(snapshot.vessels[0].native_liquid_height==6.5,"Input snapshot mutated before caller adoption")
	assert(not result.native_vcl_verified and result.probe_only)
	var missing := providers.duplicate();missing.erase("particles")
	rejected=await orchestrator.render(snapshot,missing,{},true)
	assert(not rejected.ok and str(rejected.error).contains("particles"))
	var wrong: Dictionary = snapshot.duplicate(true);wrong.bitmaps[0].plain.bitmap_format=24
	rejected=await orchestrator.render(wrong,providers,{},true)
	assert(not rejected.ok and str(rejected.error).contains("source32"))
	var frame := Frame.new()
	rejected=frame.step_vessel(2,snapshot.vessels,{},[],snapshot.scene,snapshot.context,snapshot.rng,Callable(),Callable())
	assert(not rejected.ok and str(rejected.error).contains("index"))
	var context: Dictionary = snapshot.context.duplicate();context.native_material_words={0:[0,1,2,3]}
	var step := frame.step_vessel(0,snapshot.vessels,{},[],snapshot.scene,context,snapshot.rng,Callable(),Callable())
	assert(step.ok,str(step));assert(step.selected_vessel==0 and step.material_words[0]==[0,1,2,3])
	assert(not step.material_words.has(1),"Unknown other-vessel words synthesized")
	print("Presentation orchestrator source-order and explicit-provider guards PASS; synthetic transport only, no native raster/full-frame claim")
	quit()
