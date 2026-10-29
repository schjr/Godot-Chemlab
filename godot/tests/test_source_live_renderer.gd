extends SceneTree
## The production drawing path must reflect actual vessel state without probes.
const Renderer=preload("res://scripts/original/original_source_renderer.gd")
const Raster=preload("res://scripts/original/original_portable_raster.gd")
var failures:Array=[]
func check(value:bool,message:String)->void:
	if not value:failures.append(message);push_error(message)
func _initialize()->void:call_deferred("_run")
func _run()->void:
	var app=load("res://scenes/main.tscn").instantiate();root.add_child(app)
	await process_frame;await process_frame
	var model=app.model
	check(app.canvas.source_render_errors.is_empty(),"Opening source recipes draw without missing operands")
	check(app.canvas.source_render_snapshot().size()==6,"All six opening apparatus have source-rendered frames")
	check(model.start(),"Normal source allocation starts")
	await process_frame;await process_frame
	check(model.running and model.last_error.is_empty(),"Source particle presentation keeps normal Run active")
	check(model.source_particle_frames>0,"Normal canvas executes persistent source particle feedback")
	check(app.canvas.source_render_errors.is_empty(),"Normal canvas source particle bitmaps are fully backed")
	for i in [0,3]:
		var v:Dictionary=model.native_apparatus()[i];var pool:Dictionary=model.source_particle_scene.pools[i].solid
		var expected:=Raster.color_word(int(v.native_liquid_color))
		check(pool.primary_words.size()==int(pool.width)*int(pool.height) and pool.primary_words[0]==expected,"Stopped painting initialized the actual primary particle surface color")
		check(pool.retained_words.size()==int(pool.width)*int(pool.height) and pool.retained_words[0]==expected,"Run retained the prepainted particle surface instead of showing a black fill")
	var dropper:Dictionary=model.native_apparatus()[2]
	var renderer=Renderer.new()
	var before:Dictionary=renderer.render(dropper,model._species)
	check(before.ok,"Empty dropper draws")
	var action:Dictionary=model.manual_action(int(dropper.id),1)
	check(action.ok,"Normal original aspiration executes")
	var full:Dictionary=renderer.render(dropper,model._species)
	check(full.ok and before.words!=full.words,"Actual two ml withdrawal changes visible dropper pixels")
	var bottle:Dictionary=model.native_apparatus()[4]
	check(model.toggle_pour(int(bottle.id)),"Original pouring orientation changes")
	var tilted:Dictionary=renderer.render(bottle,model._species)
	check(tilted.ok,"Source tilted bottle polygon draws")
	check(tilted.width==52 and tilted.height==30,"Source pouring uses the original sideways bottle bitmap")
	check(not tilted.native_vcl_verified and tilted.portable_raster,"Portable raster never claims native GDI pixel attestation")
	var beaker:Dictionary=model.native_apparatus()[0]
	var old_height:int=model.source_particle_scene.pools[0].solid.height
	var water_before:float=beaker.contents["H2O(液体)"]
	bottle.position=[203,175];bottle.native_fields["0x10"]="203";bottle.native_fields["0x14"]="175"
	for tick in 10:model.step(0.02)
	await process_frame;await process_frame
	check(float(beaker.contents["H2O(液体)"])>water_before,"Original continuous pouring raises the recipient's actual liquid level")
	var raised_pool:Dictionary=model.source_particle_scene.pools[0].solid
	check(int(raised_pool.height)>old_height,"Actual pouring resized the persistent particle bitmap")
	check(not raised_pool.retained_words.is_empty() and int(raised_pool.retained_words[0])&0xffffff!=0,"Live resize preserves colored particle backing instead of turning the solution black")
	check(model.last_error.is_empty() and app.canvas.source_render_errors.is_empty(),"Continuous pouring and live bitmap resize complete without errors")
	print(JSON.stringify({"failures":failures,"normal_production":true,"test_profiles_injected":false,"empty_dropper_hash":hash(before.get("words",[])),"filled_dropper_hash":hash(full.get("words",[])),"tilted_dimensions":[tilted.get("width"),tilted.get("height")]}))
	if failures.is_empty():print("PASS production live source rendering, actual withdrawal pixels, continuous pouring and retained colored bitmap resize")
	app.free();quit(0 if failures.is_empty() else 1)
