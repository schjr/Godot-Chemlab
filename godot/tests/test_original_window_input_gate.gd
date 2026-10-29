extends SceneTree
const Gate=preload("res://scripts/original/original_window_input_gate.gd")
const Dispatch=preload("res://scripts/original/original_ui_dispatch.gd")
func _initialize():call_deferred("_run")
func _run():
	var w:=Window.new();w.size=Vector2i(300,180);root.add_child(w);w.show()
	var edit:=LineEdit.new();edit.position=Vector2(10,10);edit.size=Vector2(200,30);w.add_child(edit)
	var button:=Button.new();button.text="Modify";button.position=Vector2(10,50);button.size=Vector2(100,30);w.add_child(button)
	var state:Dictionary={"blocked":true,"seen":[]}
	var d:=Dispatch.new();d.blocked=func():return state.blocked
	var gate:=Gate.new();gate.dispatch=func(callback:Callable,args:Array):
		if d.active:callback.callv(args)
		else:d.deliver(callback,args)
	w.add_child(gate)
	button.pressed.connect(func():state.seen.append(edit.text))
	await process_frame;edit.grab_focus()
	# All three key events arrive while a source presentation message is blocked.
	for letter in ["a","b","c"]:
		var event:=InputEventKey.new();event.pressed=true;event.unicode=letter.unicode_at(0);event.keycode=event.unicode
		w.push_input(event,true)
	assert(edit.text.is_empty() and d.queue.size()==3)
	for key in [KEY_TAB,KEY_SPACE]:
		var event:=InputEventKey.new();event.pressed=true;event.keycode=key;w.push_input(event,true)
	var up:=InputEventKey.new();up.keycode=KEY_SPACE;up.pressed=false;w.push_input(up,true)
	assert(d.queue.size()==6 and state.seen.is_empty())
	state.blocked=false;d.drain()
	if edit.text!="abc" or state.seen!=["abc"] or not d.queue.is_empty():print(edit.text," ",state.seen);w.free();quit(1);return
	# Immediate replay is still single delivery, including the handled-flag reset.
	edit.grab_focus();var event:=InputEventKey.new();event.pressed=true;event.unicode=100;event.keycode=100;w.push_input(event,true)
	assert(edit.text=="abcd")
	print("PASS raw dialog viewport input:3queuedtextkeys+Tab/Space/buttonrelease preserveUIstate,immediate replayexactlyonce")
	w.free();quit()
