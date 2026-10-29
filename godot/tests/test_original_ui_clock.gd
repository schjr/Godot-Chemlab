extends SceneTree
const Clock=preload("res://scripts/original/original_ui_clock.gd")
const Host=preload("res://scripts/original_model_host.gd")
func _initialize():
	var f=JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_ui_clock.json"))
	for c in f.cases:
		var state:Dictionary={"poll_ms":int(c.poll),"physics_ms":int(c.physics)}
		var result:=Clock.poll(state,int(c.now),int(c.run),bool(c.held))
		assert(result.accepted==c.accepted and state.poll_ms==int(c.after_poll) and state.physics_ms==int(c.after_physics))
		if result.accepted:assert(PackedFloat64Array([result.delta]).to_byte_array().hex_encode()==c.elapsed_bits)
	for c in f.mouse_up_cases:
		var run:=int(c.run);var host:=Host.new();host.running=run==1;host.paused=run==2;host._last_tick_ms=80;host.native_clock=func():return 1234
		host.begin_pointer();host.end_pointer();assert(not host.pointer_held and host._last_tick_ms==int(c.after_physics))
	for c in f.pause_cases:
		var run:=int(c.run);var host:=Host.new();host.running=run==1;host.paused=run==2;host._last_tick_ms=80;host.native_clock=func():return 140
		host.toggle_pause();assert((1 if host.running else (2 if host.paused else 0))==int(c.after_run) and host._last_tick_ms==int(c.after_physics))
	print("PASS original UI two-clock idle: ",f.cases.size()," native references plus6native MouseUp/pause/resume references")
	quit()
