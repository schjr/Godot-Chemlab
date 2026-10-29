extends SceneTree
const Dispatch=preload("res://scripts/original/original_ui_dispatch.gd")
func _initialize():
	var d:=Dispatch.new();var state:Dictionary={"blocked":true,"clock":100,"seen":[],"completions":0}
	d.blocked=func():return state.blocked
	d.after_dispatch=func():state.completions+=1;state.blocked=true
	var raw:=InputEventMouseMotion.new();raw.position=Vector2(179,190)
	d.deliver(func(event):state.seen.append([event.position,state.clock]),[raw])
	raw.position=Vector2(999,999)
	d.deliver(func(event):state.seen.append([event.position,state.clock]),[raw])
	d.deliver(func():state.seen.append(["release",state.clock]))
	assert(d.queue.size()==3 and state.seen.is_empty())
	for clock in [120,150,190]:
		state.clock=clock;state.blocked=false;d.drain();assert(state.blocked)
	assert(state.seen==[[Vector2(179,190),120],[Vector2(999,999),150],["release",190]])
	assert(d.queue.is_empty() and state.completions==3)
	# No mouse-motion compression even when all delivered positions are identical.
	state.blocked=true
	for i in 100:d.deliver(func():state.seen.append("motion"))
	for i in 100:state.blocked=false;d.drain()
	assert(state.seen.size()==103 and d.queue.is_empty())
	print("PASS ordered UI dispatch: immutable raw input,dispatch-time clock,3blocked callbacks+100uncoalescedmotions")
	quit()
