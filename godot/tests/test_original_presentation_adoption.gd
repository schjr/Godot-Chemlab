extends SceneTree
## Source feedback plus synthetic pixel-boundary contract tests. This does not
## verify Windows VCL pixels or turn fixture declarations into production data.
const Model=preload("res://scripts/original_model_host.gd")
const Formats=preload("res://scripts/legacy_formats.gd")
const Adapter=preload("res://scripts/experiment_adapter.gd")
const Frame=preload("res://scripts/original/original_particle_frame.gd")
const Slots=preload("res://scripts/original/original_slots.gd")
const Liquid=preload("res://scripts/original/original_liquid.gd")
const Host=preload("res://scripts/original/original_x87_host.gd")
class GuardOnlyGdi extends RefCounted:
	func render_ops()->Dictionary:return {"ok":false,"error":"Contract test never supplies production pixels"}
	func render_solid()->Dictionary:return {"ok":false,"error":"Contract test never supplies production pixels"}
	func copy_rect()->Dictionary:return {"ok":false,"error":"Contract test never supplies production pixels"}
var failures:Array=[]
var signals:Array=[]
var checks:=0
var synthetic_resizes:Array=[]
func check(ok:bool,message:String)->void:
	checks+=1
	if not ok:failures.append(message);print("FAIL ",message)
func present(request:Dictionary)->Dictionary:
	if request.get("operation","")=="scanline_words" or int(request.get("address",0)) in [0x8000108,0x800010c]:
		# The source resize now exposes its changed object dimensions. This
		# synthetic provider must supply matching pixels, just as for scanlines;
		# a bare success would leave an incomplete attested bitmap checkpoint.
		var bitmap:int=int(request.get("bitmap",request.get("eax",0)))
		var meta:Dictionary=request.bitmaps[bitmap];var words:Array=[];words.resize(int(meta.width)*int(meta.height));words.fill(0)
		if int(request.get("address",0)) in [0x8000108,0x800010c]:synthetic_resizes.append([meta.name,meta.width,meta.height])
		return {"ok":true,"bitmap_words":{str(meta.name):words}}
	return {"ok":true,"scope":"Explicit numeric-oracle-only VCL primitive boundary"}
func stage(_request:Dictionary)->Dictionary:return {"ok":false,"error":"Synthetic adoption test does not render pixels"}
func _initialize()->void:
	var fixture:Dictionary=JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_particle_frames.json"))
	var model=Model.new();model.configure(JSON.parse_string(FileAccess.get_file_as_string("res://data/reagents.json")),JSON.parse_string(FileAccess.get_file_as_string("res://data/reactions.json")))
	if not model.from_state(Adapter.to_state(Formats.load_document(fixture.fixture_path))):print("FAIL import ",model.last_error);quit(1);return
	check(not model.capture_native_presentation().ok,"Absent profile rejected")
	var zero:=PackedByteArray();zero.resize(800)
	for v in model.native_apparatus():
		for field in Slots.FIELDS:Slots.observe(v,field,zero.hex_encode(),{"source":"Explicit native numerical fixture test allocation"})
	if not model.start():print("FAIL start ",model.last_error);quit(1);return
	var scene:=Frame.create_scene(model.native_apparatus());var bitmaps:Array=[]
	for index in model.native_apparatus().size():
		var v:Dictionary=model.native_apparatus()[index];var width:int=v.native_bitmap_width;var height:int=v.native_bitmap_height
		var words:Array=[];words.resize(width*height);words.fill(0)
		if not scene.pools[index].is_empty():scene.pools[index].solid.primary_words=words.duplicate();scene.pools[index].solid.retained_words=words.duplicate()
		bitmaps.append({"original_bitmap_profile_verified":true,"material":{"width":width,"height":height,"bitmap_format":32,"initial_stretch_mode":1},"plain":{"width":width,"height":height,"bitmap_format":32,"words":words.duplicate()},"fill":{"width":width,"height":height,"bitmap_format":32,"words":words.duplicate()},"copy_rect":{"destination_rect":[0,0,width,height],"source_rect":[0,0,width,height]}})
	var config:Dictionary={"profile":{"source_sha256":Model.Factory.EXPECTED_SHA,"native_vcl_verified":true,"runtime_state_verified":true,"scope":"Synthetic host guard test + original numerical fixture; no production VCL claim","evidence_sha256":model._presentation_hash(fixture)},"scene":scene,"rng":fixture.start.rng.duplicate(),"context":{"run_flag":1,"pause_flag":0},"bitmaps":bitmaps,"apparatus_identity":model._presentation_identity(),"providers":{"gdi":GuardOnlyGdi.new(),"particles":Callable(self,"stage"),"overlays":Callable(self,"stage"),"canvas_composite":Callable(self,"stage")}}
	config.rng={"low":int(fixture.start.rng.low),"high":int(fixture.start.rng.high)}
	var probe:=config.duplicate(true);probe.profile.native_vcl_verified=false
	check(not model.configure_native_presentation(probe).ok,"Probe profile rejected")
	var no_rng:=config.duplicate(true);no_rng.rng={}
	check(not model.configure_native_presentation(no_rng).ok,"Missing RNG never initialized")
	var no_pixels:=config.duplicate(true);no_pixels.scene.pools[0].solid.erase("primary_words")
	check(not model.configure_native_presentation(no_pixels).ok,"Missing retained pixel state rejected")
	for missing in ["particles","overlays","canvas_composite"]:
		var absent:=config.duplicate(true);absent.providers.erase(missing)
		var rejected:Dictionary=model.configure_native_presentation(absent)
		check(not rejected.ok and str(rejected.error).contains(missing),"Missing provider rejects explicitly: "+missing)
	var configured:Dictionary=model.configure_native_presentation(config)
	if not configured.ok:print("FAIL configure ",configured);quit(1);return
	var apparatus:=model.native_apparatus()
	apparatus[0].native_liquid_height=6.5;apparatus[1].native_liquid_height=9.75
	check(model.refresh_render_state(),"Configured render defers liquid prepass")
	check(apparatus[0].native_liquid_height==6.5 and apparatus[1].native_liquid_height==9.75,"Previous liquid caches remain until each native vessel stage")
	var ordered_snapshot:Dictionary=model.capture_native_presentation().snapshot
	var first_liquid:Dictionary=Liquid.refresh(ordered_snapshot.vessels[0],ordered_snapshot.catalog)
	check(first_liquid.ok and ordered_snapshot.vessels[1].native_liquid_height==9.75,"First source liquid refresh leaves following vessel's previous cache")
	check(model.release_native_presentation(ordered_snapshot,"ordering-only request finished").ok,"Ordering request explicitly released")
	model.native_presentation_committed.connect(func(result:Dictionary,revision:int):signals.append([result.frames.size(),revision]))
	var captured:Dictionary=model.capture_native_presentation();var snapshot:Dictionary=captured.snapshot
	var native=Host.new();if not native.start():print("FAIL exact trig ",native.last_error);quit(1);return
	var frame=Frame.new();var state:Dictionary={}
	for key in ["vessels","connectors","scene","rng","context"]:state[key]=snapshot[key].duplicate(true)
	var feedback:Dictionary=frame.step(state.vessels,snapshot.catalog,state.connectors,state.scene,state.context,state.rng,Callable(native,"evaluate"),Callable(self,"present"))
	check(feedback.ok,"Original40A4B8 produces numeric feedback")
	check(not synthetic_resizes.is_empty(),"Explicit synthetic provider supplies resized bitmap pixels")
	var frames:Array=[]
	for index in snapshot.vessels.size():
		var v:Dictionary=snapshot.vessels[index];var words:Array=[];words.resize(int(v.native_bitmap_width)*int(v.native_bitmap_height));words.fill(0)
		frames.append({"presentation_stage":"background_composited_srccopy","display_mode":"opaque","canvas_background_verified":true,"source_compositor":0x492560,"source_weight_bits":"000000000000e03f","display_top_left":[int(v.position[0])-int(int(v.native_bitmap_width)/2),int(v.position[1])-int(int(v.native_bitmap_height)/2)],"native_index":index,"width":v.native_bitmap_width,"height":v.native_bitmap_height,"words":words,"probe_only":false,"native_vcl_verified":true})
	var result:Dictionary={"ok":true,"state":state,"frames":frames,"probe_only":false,"native_vcl_verified":true}
	var before_stamp:=model.native_presentation_stamp()
	var incomplete_frame:=result.duplicate(true);incomplete_frame.frames[0].erase("canvas_background_verified")
	check(not model.adopt_native_presentation(snapshot,incomplete_frame).ok,"Precomposition output rejected")
	var incomplete_pixels:=result.duplicate(true);incomplete_pixels.state.scene.pools[0].solid.primary_words.pop_back()
	var pixel_rejection:Dictionary=model.adopt_native_presentation(snapshot,incomplete_pixels)
	check(not pixel_rejection.ok and str(pixel_rejection.get("error","")).contains("bitmap pixels are incomplete"),"Incomplete resized bitmap checkpoint remains rejected")
	var old_reference:Dictionary=model.native_apparatus()[0]
	var bad:Dictionary=result.duplicate(true);bad.state.vessels[0].contents.clear()
	check(not model.adopt_native_presentation(snapshot,bad).ok,"Nonpresentation chemistry changes rejected atomically")
	check(model.native_apparatus()[0].contents==snapshot.vessels[0].contents,"Rejected output leaves live chemistry untouched")
	var adopted:Dictionary=model.adopt_native_presentation(snapshot,result)
	if not adopted.ok:print("ADOPTION FAILURE ",adopted)
	check(adopted.ok,"Source numeric feedback atomically adopted")
	check(model.native_presentation_stamp()!=before_stamp,"Committed state updates native canvas stamp")
	check(signals.size()==1 and signals[0][0]==snapshot.vessels.size(),"Committed notification follows complete adoption")
	check(model.native_apparatus()[0].solid_3cd8==state.vessels[0].solid_3cd8,"Actual particle feedback retained")
	var committed_stamp:=model.native_presentation_stamp()
	check(model.native_presentation_is_pending(),"Committed frame gates timer until draw submission")
	var display_last:int=model._last_tick_ms;var display_elapsed:float=model.elapsed
	model.tick(display_last+15)
	check(model._last_tick_ms==display_last and model.elapsed==display_elapsed,"Adoption-before-draw cannot starve accepted frame")
	var stale_stamp:=committed_stamp.duplicate(true);stale_stamp.revision=int(stale_stamp.revision)-1
	check(not model.acknowledge_native_presentation_display(stale_stamp).ok and model.native_presentation_is_pending(),"Stale draw acknowledgement cannot release current frame")
	var acknowledged:Dictionary=model.acknowledge_native_presentation_display(committed_stamp)
	check(acknowledged.ok and acknowledged.acknowledged and not model.native_presentation_is_pending(),"Exact current draw submission releases gate")
	old_reference["reference_probe"]=true
	check(model.native_apparatus()[0].get("reference_probe",false),"Live vessel dictionary reference remains stable")
	old_reference.erase("reference_probe")
	check(not model.adopt_native_presentation(snapshot,result).ok,"Duplicate adoption rejected")
	var next:Dictionary=model.capture_native_presentation();model.native_apparatus()[0].temperature+=1.0
	check(not model.adopt_native_presentation(next.snapshot,result).ok,"Direct in-place model mutation rejects stale async output")
	check(model.release_native_presentation(next.snapshot,"stale mutation test").ok,"Stale request can be explicitly released")
	model.native_apparatus()[0].temperature-=1.0
	var changed_request:Dictionary=model.capture_native_presentation();model.changed.emit()
	check(not model.adopt_native_presentation(changed_request.snapshot,result).ok,"Revision change rejects stale output")
	check(model.release_native_presentation(changed_request.snapshot,"revision test").ok,"Revision-failed request released")
	var reference_request:Dictionary=model.capture_native_presentation()
	var original:Dictionary=model.vessels[0];model.vessels[0]=original.duplicate(true)
	check(not model.adopt_native_presentation(reference_request.snapshot,result).ok,"Equal-value replacement of original vessel reference rejected")
	model.vessels[0]=original
	check(model.release_native_presentation(reference_request.snapshot,"reference test").ok,"Reference-failed request released")
	var changed_input:Dictionary=model.capture_native_presentation();changed_input.snapshot.rng.low=7
	check(not model.adopt_native_presentation(changed_input.snapshot,result).ok,"Modified snapshot rejected")
	check(model.release_native_presentation(changed_input.snapshot,"modified input test").ok,"Failed input request released")
	# A canceled adopted frame must release its display gate too.
	var display_request:Dictionary=model.capture_native_presentation()
	var canceled_output:=result.duplicate(true)
	for key in ["vessels","connectors","scene","rng","context"]:canceled_output.state[key]=display_request.snapshot[key].duplicate(true)
	check(model.adopt_native_presentation(display_request.snapshot,canceled_output).ok,"Second current frame commits")
	check(not model.acknowledge_native_presentation_display(committed_stamp).ok,"Previous committed stamp cannot release a newer display")
	check(model.release_native_presentation(display_request.snapshot,"canvas submission canceled").ok and not model.native_presentation_is_pending(),"Canceled display does not deadlock physics")
	var pending:Dictionary=model.capture_native_presentation()
	check(model.native_presentation_is_pending() and model.native_presentation_is_configured(),"Accepted frame owns pending single-thread gate")
	check(not model.capture_native_presentation().ok,"Second capture cannot supersede pending source event")
	var before_elapsed:float=model.elapsed;var before_last:int=model._last_tick_ms
	model.tick(before_last+20);model.step(0.01)
	check(model.elapsed==before_elapsed and model._last_tick_ms==before_last,"Pending render blocks physics without dropping tick time")
	check(not model.release_native_presentation(snapshot,"stale token").ok and model.native_presentation_is_pending(),"Stale release cannot unlock current frame")
	check(model.release_native_presentation(pending.snapshot,"explicit renderer failure").ok and not model.native_presentation_is_pending(),"Failed renderer releases physics gate")
	model.tick(before_last+20)
	check(model._last_tick_ms==before_last+20 and model.elapsed>before_elapsed,"First accepted timer includes full outstanding render duration")
	frame.vm.helpers.clear();native.stop()
	print(JSON.stringify({"failures":failures,"commits":signals.size(),"checks":checks,"synthetic_resize_events":synthetic_resizes.size()}))
	if failures.is_empty():print("PASS original model presentation snapshot source-feedback adoption and stale-result guards")
	quit(0 if failures.is_empty() else 1)
