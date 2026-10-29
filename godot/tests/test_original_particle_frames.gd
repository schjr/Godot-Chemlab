extends SceneTree
const Model=preload("res://scripts/original_model_host.gd")
const Formats=preload("res://scripts/legacy_formats.gd")
const Adapter=preload("res://scripts/experiment_adapter.gd")
const Frame=preload("res://scripts/original/original_particle_frame.gd")
const Host=preload("res://scripts/original/original_x87_host.gd")
const Slots=preload("res://scripts/original/original_slots.gd")
func number(hex:String)->float:return hex.hex_decode().decode_double(0)
func bits(value:float)->String:return PackedFloat64Array([value]).to_byte_array().hex_encode()
func _initialize()->void:
	var fixture:Dictionary=JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_particle_frames.json"))
	if fixture.get("status","")!="executed":print("FAIL original live-cache fixture unresolved");quit(1);return
	var model=Model.new();var reagents:Array=JSON.parse_string(FileAccess.get_file_as_string("res://data/reagents.json"))
	model.configure(reagents,JSON.parse_string(FileAccess.get_file_as_string("res://data/reactions.json")))
	if not model.from_state(Adapter.to_state(Formats.load_document(fixture.fixture_path))):print("FAIL original live-cache import: ",model.last_error);quit(1);return
	# Explicit oracle numerical heap profile, never a production default.
	var zero_cells:=PackedByteArray();zero_cells.resize(800)
	for v in model.native_apparatus():
		for field in Slots.FIELDS:
			Slots.observe(v,field,zero_cells.hex_encode(),{"source":"native oracle explicit zero allocation profile"})
	if not model.start():print("FAIL original live-cache start: ",model.last_error);quit(1);return
	var host=Host.new();if not host.start():print("FAIL native trig: ",host.last_error);quit(1);return
	var scene:=Frame.create_scene(model.native_apparatus());var frame=Frame.new();var rng:Dictionary=fixture.start.rng.duplicate();var failures:Array=[];var progress:Dictionary={"frames":0}
	var present:=func(request:Dictionary)->Dictionary:
		# Explicit reference-only zero DIB profile. Only native GDI raster
		# operations are hosted; all retained-layer numeric IR executes.
		if request.get("operation","")=="scanline_words":
			var meta:Dictionary=request.bitmaps[int(request.bitmap)];var words:Array=[];words.resize(int(meta.width)*int(meta.height));words.fill(0)
			return {"ok":true,"bitmap_words":{str(meta.name):words}}
		return {"ok":true,"scope":"recorded VCL/GDI primitive reference"}
	var render:=func()->bool:
		var context:Dictionary={"run_flag":1,"pause_flag":0}
		if "--production-pixel-loop" in OS.get_cmdline_user_args():context.production_pixel_loop=true
		var result:=frame.step(model.native_apparatus(),model._species,model.native_connectors,scene,context,rng,Callable(host,"evaluate"),present)
		progress.frames=int(progress.frames)+1
		if not result.ok:failures.append(["render",progress.frames,result]);frame.vm.helpers.clear();return false
		return true
	for action_index in fixture.actions.size():
		var action:Dictionary=fixture.actions[action_index];var selected:Dictionary=model.native_apparatus()[int(action.selected)]
		selected.position=action.position.duplicate();selected.native_fields["0x10"]=str(int(action.position[0]));selected.native_fields["0x14"]=str(int(action.position[1]))
		var result:Dictionary=model.manual_action(int(selected.id),int(action.command))
		if not result.ok:failures.append(["manual",action_index,result]);break
		if not render.call():break
		var stop:=false
		for _tick in int(action.ticks):
			model.step(number(fixture.delta_bits))
			if not model.last_error.is_empty():failures.append(["physics",action_index,model.last_error]);stop=true;break
			if not render.call():stop=true;break
		if stop:break
		var expected:Dictionary=fixture.frames[action_index]
		for index in model.native_apparatus().size():
			var v:Dictionary=model.native_apparatus()[index];var e:Dictionary=expected.vessels[index]
			for key in ["contents","solid_3cd8","solid_3ff8"]:
				for species in e.bits[key]:
					if not v[key].has(species) or bits(float(v[key][species]))!=str(e.bits[key][species]):failures.append([action_index,index,key,species,bits(float(v[key].get(species,0.0))),e.bits[key][species]])
			if bits(float(v.native_particle_3cc8))!=e.particle_accumulator_bits:failures.append([action_index,index,"gas_particle_accumulator"])
			if expected.pools[index].is_empty():continue
			for kind in ["solid","bubbles"]:
				var pool:Dictionary=scene.pools[index][kind];var ep:Dictionary=expected.pools[index][kind]
				for key in ep:
					if key=="slots":
						for slot in mini(int(pool.count),int(ep.count)):
							for word in 13:
								if int(pool.slots[slot][word])!=int(ep.slots[slot][word]):failures.append([action_index,index,kind,slot,word])
					elif ep[key] is Array:
						for cell in ep[key].size():
							if int(pool[key][cell])!=int(ep[key][cell]):failures.append([action_index,index,kind,key])
					elif int(pool[key])!=int(ep[key]):failures.append([action_index,index,kind,key,pool[key],ep[key]])
		if int(rng.low)!=int(expected.rng.low) or int(rng.high)!=int(expected.rng.high):failures.append([action_index,"shared_thread_rng",rng.duplicate(),expected.rng])
	host.stop();if frame.vm!=null:frame.vm.helpers.clear()
	print(JSON.stringify({"live_render_passes":progress.frames,"physics_ticks":60,"failures":failures}))
	if failures.is_empty() and int(progress.frames)==66:print("PASS native opening chemistry with full persistent particle/cache feedback")
	quit(0 if failures.is_empty() and int(progress.frames)==66 else 1)
