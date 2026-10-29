extends SceneTree
## Canvas/host transport guards use explicitly synthetic providers, never
## production reference pixels. Arithmetic checks use actual native fixtures.
const Model=preload("res://scripts/lab_model.gd")
const Canvas=preload("res://scripts/lab_canvas.gd")
const Finish=preload("res://scripts/original/original_canvas_presentation.gd")
class TransportGdi extends RefCounted:
	var delay_frames := 0
	var fail_render := false
	var tree: SceneTree
	func render_ops(w:int,h:int,_ops:Array,initial:Array=[],_probe:bool=false,_format:int=32,mode:int=1)->Dictionary:
		var delay:=delay_frames;delay_frames=0
		for _frame in delay:await tree.process_frame
		if fail_render:return {"ok":false,"error":"Synthetic delayed provider failure"}
		var words:=initial.duplicate()
		if words.is_empty():words.resize(w*h);words.fill(0xFFFFFF)
		return {"ok":true,"words":words,"stretch_mode":mode,"native_vcl_verified":true,"scope":"Synthetic transport test only"}
	func render_solid(words:Array,_w:int,_h:int,_recipe:Dictionary,_probe:bool=false)->Dictionary:return {"ok":true,"words":words.duplicate(),"native_vcl_verified":true}
	func copy_rect()->void:pass
func particle(request:Dictionary)->Dictionary:
	return {"ok":true,"words":request.words.duplicate(),"canvas_state":request.canvas_state.duplicate(),"stretch_mode":request.canvas_state.stretch_mode,"native_vcl_verified":true,"scope":"Synthetic transport test only"}
func overlay(request:Dictionary)->Dictionary:
	return {"ok":true,"words":request.words.duplicate(),"stretch_mode":request.canvas_state.stretch_mode,"native_vcl_verified":true,"scope":"Synthetic transport test only"}
func background(request:Dictionary)->Dictionary:
	var words:Array=[];words.resize(request.width*request.height);words.fill(0x00112233)
	return Finish.compose(request.words,words,request.width,request.height,request.vessel.position,{"native_scale_bits":"000000000000f03f","canvas_background_verified":true,"native_vcl_verified":true,"scope":"Synthetic transport test only"})
func _initialize()->void:
	var fixture:Dictionary=JSON.parse_string(FileAccess.get_file_as_string(ProjectSettings.globalize_path("res://")+"../evidence/original_logic/native-solid-pixels-oracle.json"))
	var compared:=0
	for case in fixture.cases:
		if case.op!="composite" or case.weight_bits!="000000000000e03f":continue
		var result:=Finish.compose([int(case.destination)],[int(case.source)],1,1,[10,10],{"native_scale_bits":"000000000000f03f"},true)
		assert(result.ok and result.words[0]==int(case.native_result))
		assert(result.image.get_pixel(0,0).a==1.0,"Reserved byte used as alpha")
		compared+=1
	assert(compared>0)
	var model:=Model.new()
	model.configure(JSON.parse_string(FileAccess.get_file_as_string("res://data/reagents.json")),JSON.parse_string(FileAccess.get_file_as_string("res://data/reactions.json")))
	var added:Dictionary=model.add_apparatus("xkp",Vector2(429,224))
	assert(not added.is_empty())
	var id:=int(added.id)
	var canvas:=Canvas.new();root.add_child(canvas);canvas.configure(model)
	await process_frame
	var unavailable:Dictionary=await canvas.render_native_presentation()
	assert(not unavailable.ok,"Missing actual profile unexpectedly rendered")
	assert(canvas.native_presentation_mode and not canvas.native_presentation_status.is_empty(),"Native mode silently reverted to an unlabelled preview")
	var v:Dictionary=model.native_apparatus()[0];var w:int=v.native_bitmap_width;var h:int=v.native_bitmap_height
	var words:Array=[];words.resize(w*h);words.fill(0)
	var config:Dictionary={"profile":{"source_sha256":Model.Factory.EXPECTED_SHA,"native_vcl_verified":true,"runtime_state_verified":true,"scope":"Synthetic Canvas/host transport guard only; no actual VCL claim","evidence_sha256":"0".repeat(64)},"scene":{"pools":[{}]},"rng":{"low":3,"high":0},"context":{"run_flag":0,"pause_flag":0},"apparatus_identity":model._presentation_identity(),"bitmaps":[{"original_bitmap_profile_verified":true,"material":{"width":w,"height":h,"bitmap_format":32,"initial_stretch_mode":3},"plain":{"width":w,"height":h,"bitmap_format":32,"words":words.duplicate()},"fill":{"width":w,"height":h,"bitmap_format":32,"words":words.duplicate()},"copy_rect":{"destination_rect":[0,0,w,h],"source_rect":[0,0,w,h]}}],"providers":{"gdi":TransportGdi.new(),"particles":Callable(self,"particle"),"overlays":Callable(self,"overlay"),"canvas_composite":Callable(self,"background")}}
	assert(canvas.configure_native_presentation(config).ok)
	# The active Canvas path schedules render/capture/adopt itself after explicit
	# verified configuration; no test-only direct frame commit is needed.
	await process_frame
	await process_frame
	assert(canvas.native_frame_revision()==model.presentation_revision and canvas._native_frames.has(id))
	var stored:Dictionary=canvas._native_frames[id]
	assert(stored.width==w and stored.height==h and stored.top_left==Vector2(429-int(w/2),224-int(h/2)))
	assert(stored.image.get_pixel(0,0).a==1.0)
	assert(canvas._native_owned_ids.has(id),"Legacy tint suppression ownership missing")
	var result:Dictionary={"ok":true,"frames":model.native_presentation_frames,"native_vcl_verified":true,"probe_only":true}
	assert(not canvas.commit_native_frames(result,model.presentation_revision).ok,"Probe result committed")
	assert(not canvas.commit_native_frames(result,model.presentation_revision-1).ok,"Stale result committed")
	# Direct mutation without a changed signal must invalidate via the host stamp.
	v.temperature+=1.0
	assert(canvas.native_frame_revision()==-1 and canvas._native_frames.is_empty())
	assert(canvas._native_owned_ids.has(id),"Invalidation re-enabled guessed material tint")
	model.changed.emit();assert(canvas._native_frames.is_empty())
	# A delayed native provider must hold the host's source timer/physics gate;
	# failure releases only its own token without discarding timer duration.
	canvas.set_process(false)
	model.running=true;model.paused=false
	config.context={"run_flag":1,"pause_flag":0}
	var delayed:=TransportGdi.new();delayed.tree=self;delayed.delay_frames=3;delayed.fail_render=true
	config.providers.gdi=delayed
	assert(model.configure_native_presentation(config).ok)
	var outcome:Dictionary={}
	var request:=func()->void:outcome.result=await canvas.render_native_presentation()
	request.call()
	await process_frame
	assert(model.native_presentation_is_pending())
	var elapsed_before:=model.elapsed;model._last_tick_ms=1000
	model.tick(2000);model.step(0.5)
	assert(model.elapsed==elapsed_before and model._last_tick_ms==1000,"Physics accepted during pending native paint")
	for _frame in 5:await process_frame
	assert(outcome.has("result") and not outcome.result.ok)
	assert(not model.native_presentation_is_pending(),"Renderer failure leaked the host physics gate")
	# Cancellation is queued until the already-issued provider settles.
	delayed.delay_frames=3;delayed.fail_render=false;outcome.clear()
	assert(model.configure_native_presentation(config).ok)
	request.call();await process_frame
	assert(model.native_presentation_is_pending())
	var cancelled:=canvas.cancel_native_presentation()
	assert(cancelled.ok and cancelled.release_after_provider_returns)
	assert(model.native_presentation_is_pending(),"Cancellation released while GDI provider still owned its state")
	for _frame in 5:await process_frame
	assert(outcome.has("result") and not outcome.result.ok and not model.native_presentation_is_pending())
	# A real viewport draw callback, rather than texture creation, releases the
	# next running physics step. Synthetic providers exercise transport only.
	canvas.size=Vector2(900,600);canvas.show();canvas.set_process(true)
	delayed.delay_frames=2
	var observed:Dictionary={"commits":0,"acks":0,"first_ack":false,"second_step":false}
	var draw_observer:=func(_revision:int)->void:
		observed.acks+=1;observed.first_ack=true
	canvas.native_frame_draw_submitted.connect(draw_observer)
	var commit_observer:=func(_result:Dictionary,_revision:int)->void:
		observed.commits+=1
		var before:=model.elapsed
		model.tick(9000)
		assert(model.elapsed==before,"Physics resumed before source frame draw submission")
		assert(model.native_presentation_is_pending(),"Adoption omitted display gate")
	model.native_presentation_committed.connect(commit_observer)
	canvas.hide()
	assert(canvas.configure_native_presentation(config).ok)
	for _frame in 6:await process_frame
	assert(observed.commits==1 and observed.acks==0 and model.native_presentation_is_pending(),"Hidden canvas acknowledged an undisplayed frame")
	var retained_texture=canvas._native_frames[id].texture
	canvas._native_frames[id].texture=null
	canvas.show();canvas.queue_redraw()
	for _frame in 2:await process_frame
	assert(observed.acks==0 and model.native_presentation_is_pending(),"Missing native texture acknowledged a frame")
	canvas._native_frames[id].texture=retained_texture;canvas.queue_redraw()
	for _frame in 2:await process_frame
	assert(observed.commits>0 and observed.acks>0,"Headless viewport never submitted native draw commands")
	var elapsed_before_display:=model.elapsed
	model._last_tick_ms=1000
	for frame_index in 10:
		model.tick(1001+frame_index)
		if model.elapsed>elapsed_before_display:
			assert(observed.first_ack,"Second source physics step preceded first frame draw acknowledgement")
			observed.second_step=true
		await process_frame
	assert(observed.second_step and observed.acks>=2,"Running native pipeline stalled after first submitted frame")
	print("Canvas native connection guards PASS; %d native half-weight compositor comparisons. Synthetic integration providers do not certify production raster/VCL profile."%compared)
	canvas.set_process(false)
	canvas.cancel_native_presentation()
	for _frame in 5:await process_frame
	canvas.native_frame_draw_submitted.disconnect(draw_observer)
	model.native_presentation_committed.disconnect(commit_observer)
	canvas.queue_free();await process_frame
	quit()
