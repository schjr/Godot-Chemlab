extends SceneTree
## Normal application startup and clocks, real viewport gestures, no cache/profile injection.
const Controls=preload("res://scripts/original/original_controls.gd")
var app
var milestones:Array=[]
var failures:Array=[]
var started_usec:int=Time.get_ticks_usec()
var capture_date:String="2026-10-18"
func _initialize()->void:call_deferred("_run")
func check(value:bool,label:String)->bool:
	if not value:failures.append(label);push_error(label)
	else:milestones.append(label)
	return value
func send(point:Vector2,button:int=0,pressed:bool=false)->void:
	var event:InputEvent
	if button==0:event=InputEventMouseMotion.new()
	else:event=InputEventMouseButton.new();event.button_index=button;event.pressed=pressed
	event.position=point;event.global_position=point
	root.push_input(event,true)
func click(point:Vector2,button:int=MOUSE_BUTTON_LEFT)->void:
	send(point);send(point,button,true);send(point,button,false)
func point(world:Vector2)->Vector2:
	return app.canvas.get_global_transform_with_canvas()*(app.canvas.pan+world*app.canvas.zoom)
func center(v:Dictionary)->Vector2:return Vector2(v.position[0],v.position[1])
func select_dropper(v:Dictionary)->void:
	click(point(center(v)+Vector2(0,-30)))
	check(app.selected_id==int(v.id),"Select dropper exposed bulb")
func helper(v:Dictionary,command:int)->void:
	for r in Controls.rectangles(v):
		if r.command==command:
			click(point(Vector2((r.left+r.right)/2.0,(r.top+r.bottom)/2.0)));return
	check(false,"Missing source helper rectangle")
func drag_dropper(v:Dictionary,destination:Vector2)->void:
	var from:=point(center(v)+Vector2(0,-30))
	var to:=point(destination+Vector2(0,-30))
	send(from);send(from,MOUSE_BUTTON_LEFT,true);send(to);send(to,MOUSE_BUTTON_LEFT,false)
	# The source truncates mouse coordinates before computing integer offsets.
	# A zoomed screen pixel can therefore move the stored center by one unit.
	check(center(v).distance_to(destination)<=1.5,"Drag dropper through canvas")
func running()->bool:
	return check(app.model.running and app.model.last_error.is_empty() and app.canvas.source_render_errors.is_empty(),"Normal simulation and source rendering remain active: "+app.model.last_error+str(app.canvas.source_render_errors))
func settle(seconds:float=0.35)->void:
	await create_timer(seconds).timeout
func capture(label:String)->void:
	if "--screenshots" in OS.get_cmdline_user_args() and DisplayServer.get_name()!="headless":
		await RenderingServer.frame_post_draw
		root.get_texture().get_image().save_png(ProjectSettings.globalize_path("res://")+"../evidence/godot/opening-live-"+label+"-"+capture_date+".png")
func pour_menu(v:Dictionary)->void:
	click(point(center(v)),MOUSE_BUTTON_RIGHT)
	check(app.context_menu.visible,"Pour menu opens from right click")
	var menu=app.context_menu
	var index:int=menu.get_item_index(2)
	if not check(index>=0,"Original vessel exposes pouring item"):return
	var panel:StyleBox=menu.get_theme_stylebox("panel")
	var height:float=(menu.size.y-panel.get_margin(SIDE_TOP)-panel.get_margin(SIDE_BOTTOM))/menu.item_count
	click(Vector2(menu.position)+Vector2(menu.size.x/2.0,panel.get_margin(SIDE_TOP)+height*(index+0.5)))
func finish()->void:
	print(JSON.stringify({"normal_startup":true,"fixture_profiles_injected":false,"milestones":milestones,"failures":failures,"simulation_elapsed":app.model.elapsed,"wall_seconds":float(Time.get_ticks_usec()-started_usec)/1000000.0,"last_error":app.model.last_error,"source_particle_frames":app.model.source_particle_frames}))
	if failures.is_empty():print("PASS normal opening: Run, NaOH aspiration, two precipitates, HCl dissolution and continuous pouring via viewport gestures")
	app.free();quit(0 if failures.is_empty() else 1)
func _run()->void:
	for argument in OS.get_cmdline_user_args():
		if argument.begins_with("--capture-date="):capture_date=argument.trim_prefix("--capture-date=")
	app=load("res://scenes/main.tscn").instantiate();root.add_child(app)
	await process_frame;await process_frame
	check(app.current_title=="氢氧化铜与氢氧化铁","Normal opening document")
	click(app._run_button.get_global_rect().get_center())
	await settle()
	if not running():finish();return
	var vessels:Array=app.model.native_apparatus()
	var copper:Dictionary=vessels[0];var naoh:Dictionary=vessels[1];var dropper:Dictionary=vessels[2]
	var iron:Dictionary=vessels[3];var acid:Dictionary=vessels[4];var acid_dropper:Dictionary=vessels[5]
	var naoh_before:float=naoh.contents["NaOH(溶解)"]
	select_dropper(dropper);helper(dropper,1)
	check(float(dropper.contents.get("NaOH(溶解)",0.0))>0.0 and float(naoh.contents["NaOH(溶解)"])<naoh_before,"NaOH actually leaves bottle and enters dropper")
	check(absf(float(dropper.native_liquid_volume)-2.0)<1e-6,"Original two ml aspiration limit")
	await capture("withdrawal")
	drag_dropper(dropper,Vector2(179,190));helper(dropper,2)
	await settle()
	check(float(copper.contents.get("Cu(OH)2(固体)",0.0))>0.0,"Copper hydroxide forms after actual drop")
	drag_dropper(dropper,Vector2(306,190));helper(dropper,2)
	await settle()
	check(float(iron.contents.get("Fe(OH)3(固体)",0.0))>0.0,"Iron hydroxide forms after actual drop")
	check(app.model.source_particle_frames>0,"Live source particle instructions execute during presentation")
	await capture("precipitates")
	if not running():finish();return
	select_dropper(acid_dropper);helper(acid_dropper,1)
	check(float(acid_dropper.contents.get("HCl(溶解)",0.0))>0.0,"HCl actually enters its dropper")
	var copper_solid:float=copper.contents.get("Cu(OH)2(固体)",0.0)
	var iron_solid:float=iron.contents.get("Fe(OH)3(固体)",0.0)
	drag_dropper(acid_dropper,Vector2(179,190));helper(acid_dropper,2)
	await settle(0.7)
	check(float(copper.contents.get("Cu(OH)2(固体)",0.0))<copper_solid,"HCl dissolves copper precipitate")
	drag_dropper(acid_dropper,Vector2(306,190));helper(acid_dropper,2)
	await settle(0.7)
	check(float(iron.contents.get("Fe(OH)3(固体)",0.0))<iron_solid,"HCl dissolves iron precipitate")
	# Move the bottle with the same pointer gesture as a user, then use its menu.
	var from:=point(center(acid)+Vector2(0,15));var destination:=Vector2(203,175)
	var to:=point(destination+Vector2(0,15))
	send(from);send(from,MOUSE_BUTTON_LEFT,true);send(to);send(to,MOUSE_BUTTON_LEFT,false)
	check(center(acid)==destination,"Drag acid bottle above copper beaker")
	var acid_before:float=acid.contents["HCl(溶解)"]
	var water_before:float=copper.contents["H2O(液体)"]
	pour_menu(acid)
	check(int(acid.native_fields["0x18"])==2,"Pour menu changes original orientation")
	await settle(0.3)
	check(float(acid.contents["HCl(溶解)"])<acid_before and float(copper.contents["H2O(液体)"])>water_before,"Continuous pouring actually transfers liquid")
	await capture("pouring")
	pour_menu(acid)
	check(int(acid.native_fields["0x18"])==0,"Menu restores upright bottle")
	running()
	click(app._stop_button.get_global_rect().get_center())
	check(not app.model.running,"Stop restores baseline")
	await process_frame
	await process_frame
	click(app._run_button.get_global_rect().get_center())
	await settle()
	if running():
		dropper=app.model.native_apparatus()[2]
		select_dropper(dropper);helper(dropper,1)
		check(float(dropper.contents.get("NaOH(溶解)",0.0))>0.0 and absf(float(dropper.native_liquid_volume)-2.0)<1e-6,"Withdrawal works again after Stop/Run and allocation reuse")
	finish()
