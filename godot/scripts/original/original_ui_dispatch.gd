class_name OriginalUiDispatch
extends RefCounted
## Preserve every delivered callback while a source presentation continuation waits.
var queue:Array=[]
var active:=false
var blocked:Callable
var after_dispatch:Callable
var error:=""
var dispositions:Array=[]
static func snapshot(value):
	if value is InputEvent:return value.duplicate(true)
	if value is Array:
		var out:Array=[]
		for item in value:out.append(snapshot(item))
		return out
	if value is Dictionary:
		var out:Dictionary={}
		for key in value:out[key]=snapshot(value[key])
		return out
	return value
func deliver(callback:Callable,args:Array=[])->void:
	queue.append({"callback":callback,"args":snapshot(args)})
	drain()
func drain()->void:
	if active or not error.is_empty():return
	while not queue.is_empty():
		if blocked.is_valid() and blocked.call():return
		var item:Dictionary=queue[0]
		if not item.callback.is_valid():error="Delivered UI callback owner disappeared; message retained";return
		queue.pop_front();active=true
		var result=item.callback.callv(item.args)
		if result is Dictionary and result.has("disposition"):
			dispositions.append(result)
			if result.disposition=="missing_gate":
				queue.push_front(item);error="Live viewport input gate disappeared; message retained, routing unresolved"
		active=false
		if not error.is_empty():return
		if after_dispatch.is_valid():after_dispatch.call()
