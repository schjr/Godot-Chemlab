extends SceneTree
const Frame=preload("res://scripts/original/original_particle_frame.gd")
func vessel(type:int)->Dictionary:
	return {"label":"container","type_id":type,"position":[20,20],"native_fields":{"0x18":"0"},"native_bitmap_width":40,"native_bitmap_height":50,"native_liquid_height":30.0,"native_liquid_color":0xffffff,"solid_4318":0.0,"gas_3cc0":0.0,"native_particle_3cc8":0.0,"contents":{"H2O(液体)":1.0,"惰性气体(气体)":0.001},"solid_3cd8":{"H2O(液体)":0.0},"solid_3ff8":{"H2O(液体)":0.0}}
func _initialize()->void:
	var failures:Array=[];var catalog:Dictionary={"H2O(液体)":{"color_integer":0xffffff},"惰性气体(气体)":{"color_integer":0xffffff}}
	var present:=func(request:Dictionary)->Dictionary:
		if request.get("operation","")=="scanline_words":
			var meta:Dictionary=request.bitmaps[int(request.bitmap)];var words:Array=[];words.resize(int(meta.width)*int(meta.height));words.fill(0)
			return {"ok":true,"bitmap_words":{str(meta.name):words}}
		return {"ok":true}
	var beaker:=vessel(102);var frame=Frame.new();var scene:=Frame.create_scene([beaker])
	var result:=frame.step([beaker],catalog,[],scene,{"run_flag":1,"pause_flag":0},{"low":1,"high":0},Callable(),present)
	if result.ok or not str(result.get("error","")).contains("undefined native byte"):failures.append(["active unknown read must fail",result])
	if beaker.solid_3ff8.has("惰性气体(气体)"):failures.append("unknown slot was invented")
	frame.vm.helpers.clear()
	var bottle:=vessel(201);frame=Frame.new();scene=Frame.create_scene([bottle])
	result=frame.step([bottle],catalog,[],scene,{"run_flag":0,"pause_flag":0},{"low":1,"high":0},Callable(),present)
	if not result.ok:failures.append(["unread unknown must remain unknown",result])
	if bottle.solid_3ff8.has("惰性气体(气体)"):failures.append("unread slot was invented")
	frame.vm.helpers.clear()
	print(JSON.stringify({"unknown_memory_checks":4,"failures":failures}))
	if failures.is_empty():print("PASS native particle unknown-memory boundaries")
	quit(0 if failures.is_empty() else 1)
