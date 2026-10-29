class_name OriginalWindowInputGate
extends Node
## Viewport._input precedes GUI dispatch. Retain an allocation-specific lease,
## not a callback to this Node: closing its window must not poison the FIFO.
class Target extends RefCounted:
	var viewport:WeakRef
	var allocation:int
	var gate:WeakRef
	var closed:=false
	func _init(owner:Viewport,node:OriginalWindowInputGate):viewport=weakref(owner);gate=weakref(node);allocation=owner.get_instance_id()
	func replay(event:InputEvent,_keepalive:RefCounted=null)->Dictionary:
		var owner=viewport.get_ref()
		if closed or not is_instance_valid(owner):return {"disposition":"closed_target","allocation":allocation,"event_class":event.get_class()}
		var receiver=gate.get_ref()
		if not is_instance_valid(receiver):return {"disposition":"missing_gate","allocation":allocation}
		receiver.replaying=true;owner.push_input(event,true);receiver.replaying=false
		return {"disposition":"delivered","allocation":allocation}
	func close_window(_keepalive:RefCounted=null)->Dictionary:
		var owner=viewport.get_ref()
		if closed or not is_instance_valid(owner):return {"disposition":"closed_target","allocation":allocation,"event_class":"close_request"}
		closed=true;owner.hide();owner.queue_free()
		return {"disposition":"delivered","allocation":allocation}
var dispatch:Callable
var replaying:=false
var target:Target
func _ready()->void:
	target=Target.new(get_viewport(),self)
	get_viewport().tree_exiting.connect(func():target.closed=true)
func _input(event:InputEvent)->void:
	if replaying or not dispatch.is_valid():return
	get_viewport().set_input_as_handled()
	# Argument retain makes the lease survive this Node/window destruction.
	dispatch.call(Callable(target,"replay"),[event,target])
	get_viewport().set_input_as_handled()
