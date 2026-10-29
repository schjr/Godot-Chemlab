extends SceneTree
func _initialize():call_deferred("_run")
func _run():
	var app=load("res://scenes/main.tscn").instantiate();root.add_child(app)
	await process_frame;await process_frame
	var vessel:Dictionary=app.model.add_apparatus("sb100");app.model.native_clock=func():return 0
	app.dialogs.show_properties(vessel.id)
	var w:Window=app.get_child(app.get_child_count()-1)
	var allocation:=w.get_instance_id()
	var guard:Dictionary={"hold":true,"live":false}
	app.ui_dispatch.blocked=func():return guard.hold or app._ui_dispatch_blocked()
	app.dispatch_ui(func():w.find_child("PropertiesCancel",true,false).pressed.emit())
	# These events were delivered to this Form4 before its queued Close executes.
	for key in [KEY_A,KEY_B]:
		var e:=InputEventKey.new();e.pressed=true;e.keycode=key;e.unicode=key;w.push_input(e,true)
	app.dispatch_ui(func():guard.live=true)
	assert(app.ui_dispatch.queue.size()==4 and not guard.live)
	guard.hold=false;app.ui_dispatch.drain()
	assert(app.dialogs.property_close_pending and app.ui_dispatch.queue.size()==3)
	await process_frame;app.ui_dispatch.drain()
	assert(not is_instance_valid(w) and guard.live and app.ui_dispatch.error.is_empty() and app.ui_dispatch.queue.is_empty())
	var closed:=0
	for result in app.ui_dispatch.dispositions:
		if result.disposition=="closed_target":assert(result.allocation==allocation);closed+=1
	assert(closed==2)
	# A subsequently created window is a distinct allocation, never a replacement target.
	app.dialogs.show_properties(vessel.id);var next:Window=app.get_child(app.get_child_count()-1)
	assert(next.get_instance_id()!=allocation)
	var name:LineEdit=next.find_child("NativeHint",true,false);assert(name.text.is_empty())
	next.find_child("PropertiesCancel",true,false).pressed.emit();await process_frame
	print("PASS closed Form4 FIFO:Close→2closed-target dispositions→live message;no stale callback/no reroute/no global deadlock")
	app.free();quit()
