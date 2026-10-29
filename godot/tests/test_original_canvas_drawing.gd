extends SceneTree
const Drawing=preload("res://scripts/original/original_canvas_drawing.gd")
const Api=preload("res://scripts/original/original_owned_memory_api.gd")
var world
var canvas:=0
var graphics:Array=[]
var next_handle:=0x71000001
var creation_failure:=false
var rectangle_result:=1
var checks:=0
var failures:Array=[]
func check(ok:bool,label:String)->void:
	checks+=1
	if not ok:failures.append(label)
func digest(bytes:PackedByteArray)->String:
	var h:=HashingContext.new();h.start(HashingContext.HASH_SHA256);h.update(bytes);return h.finish().hex_encode()
func nonlock(address:int,size:int,opaque:Array)->PackedByteArray:
	var bytes:=PackedByteArray()
	for offset in size:
		var at:=address+offset;var skip:=false
		for lock in opaque:
			if int(lock)<=at and at<int(lock)+24:skip=true;break
		if not skip:bytes.append(world.vm.integer(at,1))
	return bytes
func boundary(request:Dictionary)->Dictionary:
	graphics.append({"request":request.duplicate(true),"canvas_state":world.read_bytes(canvas+8,1).bytes.hex_encode(),"pen_record":world.vm.integer(world.vm.integer(canvas+16)+16),"brush_record":world.vm.integer(world.vm.integer(canvas+20)+16)})
	match str(request.api):
		"event":return {"ok":true}
		"Rectangle":return {"ok":true,"result":rectangle_result}
		"CreatePenIndirect","CreateBrushIndirect":
			var handle:int=0 if creation_failure else next_handle
			if not creation_failure:next_handle+=1
			return {"ok":true,"result":handle}
		"SelectObject":return {"ok":true,"result":0 if int(request.handle)==0 else 0x11220000}
		"DeleteObject","UnrealizeObject":return {"ok":true,"result":1}
		"GetSysColor":return {"ok":true,"result":0x224466}
		"SetBkColor":return {"ok":true,"result":0x334455}
		"SetBkMode":return {"ok":true,"result":2}
		"SetROP2":return {"ok":true,"result":13}
	return {"ok":false,"error":"Undeclared original drawing primitive"}
func native_state(state:Dictionary,label:String)->void:
	check(digest(nonlock(0x59b170,0x78,state.opaque_locks))==state.heap_globals_sha256,label+" all allocator global bytes")
	for page in state.pages:check(digest(nonlock(int(page.address),4096,state.opaque_locks))==page.sha256,label+" complete shared native page/object/node bytes")
	for segment in state.local_known_segments:
		var bytes:Dictionary=world.read_bytes(int(segment.address),str(segment.hex).hex_decode().size())
		check(bytes.ok and bytes.bytes.hex_encode()==segment.hex,label+" source local metadata")
	check(world.vm.integer(0)==int(state.fs_head),label+" FS chain")
	var locks:Array=[]
	for event in world.events:
		if str(event.api).ends_with("CriticalSection"):locks.append({"api":event.api,"address":int(event.address)})
	check(locks==integer_trace(state.locks),label+" exact real lock order")
func _initialize()->void:
	var absent=Drawing.new();check(not absent.rectangle(0,0,0,1,1).ok,"uninitialized drawing does not mutate unknown memory");absent.close()
	var fixture:Dictionary=JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_canvas_drawing.json"));var executed:=0;var boundaries:=0
	for c in fixture.cases:
		graphics=[];next_handle=0x71000001;creation_failure=false;rectangle_result=1;canvas=0
		var api=Api.new();check(api.initialize({"scope":"isolated source Canvas drawing graph","page_size":4096,"allocation_granularity":65536,"local_alignment":16,"virtual_domains":[{"address":0x4000000,"size":0x400000}],"local_domains":[{"address":0x6000000,"size":0x100000}],"exclusions":[],"lock_domains":[{"address":0x59b184,"size":24}]}).ok,"owned shared primitive setup")
		world=Drawing.new();var ready:Dictionary=world.initialize_fresh(c.world,Callable(self,"boundary"),api)
		if not ready.ok:failures.append([c.name,"init",ready]);world.close();continue
		for step in c.setup:
			var built:Dictionary=world.execute_entry(int(step.entry),int(step.eax),int(step.edx),0,int(step.endpoint))
			check(built.ok and built.value==int(step.value),"actual source graph construction")
		canvas=int(c.canvas)
		for write in c.input_writes:world.vm.write(int(write.address),str(write.hex).hex_decode())
		for target in c.event_targets:check(world.register_external_event(int(target)).ok,"explicit external method binding")
		for step in c.steps:
			var op:Dictionary=step.operation;creation_failure=bool(op.get("creation_failure",false));rectangle_result=int(op.get("rectangle_result",1))
			var result:Dictionary
			if op.op=="rectangle":result=world.rectangle(canvas,int(op.coords[0]),int(op.coords[1]),int(op.coords[2]),int(op.coords[3]))
			else:result=world.execute_entry(0x4e3e50 if op.op=="pen_color" else 0x4e4158 if op.op=="brush_color" else 0x4e4274,int(c.pen) if op.op=="pen_color" else int(c.brush),int(op.value))
			if step.status=="boundary":
				check(not result.ok and world.vm.pc==int(step.pc),"original missing-HDC exception frontier stays unresolved")
				boundaries+=1
			else:
				if not result.ok:failures.append([c.name,op,result]);break
				check(result.value==int(step.value),"source wrapper return including ignored GDI failure")
				native_state(step.state,str(op.op));executed+=1
			check(world.read_bytes(canvas+8,1).bytes.hex_encode()==step.canvas_state,"source dirty/selected byte")
			check(graphics==integer_trace(step.graphics),"exact API/event timing and transient selection state")
		world.close()
	print(JSON.stringify({"native_steps":executed,"explicit_exception_frontiers":boundaries,"checks":checks,"failures":failures}))
	if failures.is_empty() and executed==12 and boundaries==1:print("PASS source Canvas Rectangle required state Pen/Brush selection event timing native references")
	quit(0 if failures.is_empty() and executed==12 and boundaries==1 else 1)

func integer_trace(value):
	# Godot's JSON loader represents all numeric tokens as Float; these traces
	# contain only exact DWORD/signed-coordinate integers, not measured floats.
	if value is float:
		assert(is_finite(value) and value==floor(value) and absf(value)<=0xffffffff)
		return int(value)
	if value is Array:
		var result:Array=[]
		for item in value:result.append(integer_trace(item))
		return result
	if value is Dictionary:
		var result:Dictionary={}
		for key in value:result[key]=integer_trace(value[key])
		return result
	return value
