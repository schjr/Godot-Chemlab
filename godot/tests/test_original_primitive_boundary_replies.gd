extends SceneTree
const Replies=preload("res://scripts/original/original_api_reply.gd")
const Pen=preload("res://scripts/original/original_pen.gd")
const Brush=preload("res://scripts/original/original_brush.gd")
const Canvas=preload("res://scripts/original/original_canvas_constructor.gd")
const Heap=preload("res://scripts/original/original_shared_heap.gd")
const Bitmap=preload("res://scripts/original/original_bitmap_constructor.gd")
var failures:Array=[]
var calls:=0
func _initialize()->void:
	var checks:=0
	var invalid:Array=[null,[],{}, {"ok":false}, {"ok":false,"error":""}, {"ok":"yes"}, {"ok":1}, {"ok":true,"error":"ignored diagnostic"}]
	# Last row is a successful reply and must pass through with all values intact.
	var valid:Dictionary=invalid.pop_back()
	if not is_same(Replies.validate(valid,"fallback"),valid):failures.append("Success reply was altered")
	if Replies.validate({"ok":false,"error":"specific source failure"},"fallback").error!="specific source failure":failures.append("Specific failure was lost")
	if Replies.validate(null,"").error.is_empty():failures.append("Missing fallback left an empty failure")
	checks+=3
	for reply in invalid:
		for original in [Pen.new(),Brush.new(),Canvas.new(),Heap.new()]:
			calls=0;original.vm.pc=0x554ec4
			var sp:int=int(original.vm.registers.esp)
			original.api=func(_request:Dictionary)->Variant:
				calls+=1;return reply
			var result:Dictionary=original._request({"api":"EnterCriticalSection","address":0x2000038})
			if result.ok or original.vm.error.is_empty():failures.append("Malformed refusal left VM without an error")
			if calls!=1 or original.vm.pc!=0x554ec4 or int(original.vm.registers.esp)!=sp:failures.append("Refusal changed source call state or repeated primitive")
			calls=0;original.vm.error="unresolved original operand"
			result=original._request({"api":"EnterCriticalSection","address":0})
			if calls!=0 or result.ok or result.error!="unresolved original operand":failures.append("Host primitive ran after a prior operand failure")
			original.close();checks+=3
		var bitmap=Bitmap.new();bitmap.vm.pc=0x5306b0;bitmap.vm.registers.eax=0x74;calls=0
		bitmap.api=func(_request:Dictionary)->Variant:
			calls+=1;return reply
		bitmap._get_mem(bitmap.vm)
		if bitmap.vm.error.is_empty() or calls!=1 or bitmap.vm.pc!=0x5306b0 or not bitmap.events.is_empty():failures.append("Bitmap raw allocator accepted a malformed reply")
		bitmap.close();checks+=1
	var incomplete=Bitmap.new();incomplete.vm.pc=0x5306b0;incomplete.vm.registers.eax=0x74
	incomplete.api=func(_request:Dictionary)->Dictionary:return {"ok":true,"error":""}
	incomplete._get_mem(incomplete.vm)
	if incomplete.vm.error.is_empty() or incomplete.vm.pc!=0x5306b0:failures.append("Missing allocation address left an empty failure")
	incomplete.close();checks+=1
	print(JSON.stringify({"checks":checks,"failures":failures,"scope":"Host protocol guards; native constructor/setter arithmetic covered by separate PE references"}))
	if failures.is_empty():print("PASS malformed and blank-error primitive replies fail once with source call state preserved")
	quit(0 if failures.is_empty() else 1)
