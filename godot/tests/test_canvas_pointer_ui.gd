extends SceneTree
## Exercise viewport routing; calling canvas/menu callbacks directly misses GUI bugs.
var app
var failures:Array=[]
func check(condition:bool,message:String)->void:
	if not condition:failures.append(message);push_error(message)
func _initialize()->void:call_deferred("_run")
func pointer(point:Vector2,button:int=0,pressed:bool=false)->void:
	var event:InputEvent
	if button==0:event=InputEventMouseMotion.new()
	else:event=InputEventMouseButton.new();event.button_index=button;event.pressed=pressed
	event.position=point;event.global_position=point
	root.push_input(event,true)
func click(point:Vector2,button:int=MOUSE_BUTTON_LEFT)->void:
	pointer(point);pointer(point,button,true);pointer(point,button,false)
func _run()->void:
	app=load("res://scenes/main.tscn").instantiate();root.add_child(app)
	await process_frame;await process_frame
	app.set_process(false) # Input/presentation test, no unobserved numerical allocation profile.
	var canvas=app.canvas
	var dropper:Dictionary=app.model.native_apparatus()[2]
	var bulb:=Vector2(dropper.position[0],dropper.position[1]-30)
	var point:Vector2=canvas.get_global_transform_with_canvas()*(canvas.pan+bulb*canvas.zoom)
	pointer(point)
	check(canvas.selected_id==-1,"Hover must not invent selection absent from original MouseMove")
	check("单击" in canvas.tooltip_text and "吸取" in canvas.tooltip_text,"Dropper hover must explain how to reveal its controls")
	click(point)
	check(canvas.selected_id==int(dropper.id),"Viewport click must select exposed dropper bulb")
	app.model.running=true # Source run flag controls visibility; no chemistry is simulated here.
	canvas.queue_redraw();await process_frame
	var rects:Array=canvas.Controls.rectangles(dropper)
	check(rects.size()==2,"Selected running dropper must expose both original controls")
	if not rects.is_empty():
		var r:Dictionary=rects[0]
		var control:Vector2=canvas.get_global_transform_with_canvas()*(canvas.pan+Vector2((r.left+r.right)/2.0,(r.top+r.bottom)/2.0)*canvas.zoom)
		pointer(control)
		check(canvas.mouse_default_cursor_shape==Control.CURSOR_POINTING_HAND,"Original helper hover must show an actionable cursor")
		check(canvas.selected_id==int(dropper.id),"Moving onto helper must preserve dropper selection")
	if "--screenshots" in OS.get_cmdline_user_args() and DisplayServer.get_name()!="headless":
		await RenderingServer.frame_post_draw
		root.get_texture().get_image().save_png(ProjectSettings.globalize_path("res://")+"../evidence/godot/dropper-controls-2026-10-18.png")
	app.model.running=false
	click(point,MOUSE_BUTTON_RIGHT)
	await process_frame
	check(app.context_menu.visible,"Viewport right click must open a visible menu")
	var expected:=Vector2i(point if app.context_menu.is_embedded() else root.get_screen_transform()*point)
	check(app.context_menu.position.distance_to(expected)<4,"Context menu must open at the click in its own window coordinate system")
	check(app.context_menu.get_theme_color("font_color").get_luminance()<0.2,"Menu text must be readable on the gray panel")
	if "--screenshots" in OS.get_cmdline_user_args() and DisplayServer.get_name()!="headless":
		await RenderingServer.frame_post_draw
		root.get_texture().get_image().save_png(ProjectSettings.globalize_path("res://")+"../evidence/godot/dropper-context-2026-10-18.png")
	# Root viewport routing must reach the embedded popup rather than the canvas.
	var panel:StyleBox=app.context_menu.get_theme_stylebox("panel")
	var top:=panel.get_margin(SIDE_TOP);var bottom:=panel.get_margin(SIDE_BOTTOM)
	var row_height:float=(app.context_menu.size.y-top-bottom)/app.context_menu.item_count
	var item:=Vector2(app.context_menu.size.x/2.0,top+row_height*(app.context_menu.get_item_index(7)+0.5))
	if app.context_menu.is_embedded():click(Vector2(app.context_menu.position)+item)
	else:
		# Native-window input routing is also checked in the visible desktop run.
		app.context_menu.set_focused_item(app.context_menu.get_item_index(7))
		var enter:=InputEventKey.new();enter.keycode=KEY_ENTER;enter.pressed=true;app.context_menu.push_input(enter,true)
	await process_frame
	check(not app.copied_vessel.is_empty() and int(app.copied_vessel.id)==int(dropper.id),"Clicking Copy in actual popup must execute its action")
	if failures.is_empty():print("PASS viewport dropper selection, helper hover, context position/contrast and popup action")
	app.free();quit(0 if failures.is_empty() else 1)
