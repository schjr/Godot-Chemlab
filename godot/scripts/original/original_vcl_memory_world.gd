class_name OriginalVclMemoryWorld
extends RefCounted
## Single instruction/memory/stack world. Allocator wrappers execute inline;
## never call a second heap VM from a VCL allocation callback.
const Reply=preload("res://scripts/original/original_api_reply.gd")
const Heap=preload("res://scripts/original/original_shared_heap.gd")
const Vm=preload("res://scripts/original/original_canvas_constructor_vm.gd")
const Locks=preload("res://scripts/original/original_owned_recursive_locks.gd")
var heap=Heap.new()
var vm=Vm.new()
var locks=Locks.new()
var program:Dictionary={}
var context:Dictionary={}
var boundary:Callable
var primitives:Object
var scope:=""
var events:Array=[]
var initialized:=false
func _whole(value:Variant,maximum:int=0xffffffff)->bool:
	return (value is int or value is float) and is_finite(float(value)) and float(value)>=0 and float(value)<=float(maximum) and float(value)==floor(float(value))
func _error(message:String)->Dictionary:return {"ok":false,"error":message}
func initialize_fresh(world:Dictionary,os_boundary:Callable,owned_primitives:Object=null)->Dictionary:
	if initialized:return _error("Shared VCL world already initialized; reinitialization would destroy object/heap identity")
	if world.get("source_sha256","")!=Heap.SOURCE_SHA or str(world.get("scope","")).is_empty() or not os_boundary.is_valid():return _error("Explicit reconstructed shared-world identity/scope/OS boundary required")
	if not world.get("thread",null) is Dictionary or not world.get("manager",null) is Dictionary:return _error("Explicit actor context and selected source memory manager required")
	if int(world.thread.get("fs_base",-1))!=0:return _error("Shared constructor VM currently supports only explicit flat FS0 diagnostic context")
	# Initial inputs are bounded runtime metadata, never arbitrary PE/stack/RTL
	# writes. Object allocations are made by the actual source constructors.
	if not world.get("segments",[]) is Array or not world.get("globals",{}) is Dictionary:return _error("Malformed shared initial inputs")
	for segment in world.get("segments",[]):
		if not segment is Dictionary or not _whole(segment.get("address")) or not segment.get("hex") is String:return _error("Malformed initial runtime byte span")
		var text:String=segment.hex
		if text.is_empty() or text.length()%2!=0:return _error("Invalid initial runtime byte length")
		for character in text:
			if not character.to_lower() in "0123456789abcdef":return _error("Invalid initial runtime hex bytes")
		var length:int=text.length()/2
		if not ((int(segment.address)==0x574b28 and length==44) or (int(segment.address)==0x574b54 and length==1)):return _error("Initial segment may only supply exact font descriptor or bitmap policy bytes")
	for address in world.get("globals",{}):
		var at:int=str(address).trim_prefix("0x").hex_to_int()
		if at not in [0x59a9e0,0x59a9e4,0x59a9e8,0x59a9ec,0x59a99c,0x59a9a0,0x59a9a4,0x574b54] or not _whole(world.globals[address]):return _error("Unsupported initial runtime global; code/manager/stack writes forbidden")
		var value:int=world.globals[address]
		if value<0 or value>(255 if at==0x574b54 else 0xffffffff):return _error("Runtime global width differs from original source")
	for field in ["stack_base","stack_size","stack_pointer","exception_head"]:
		if not _whole(world.thread.get(field)):return _error("Invalid shared actor DWORD context: "+field)
	var stack_base:int=int(world.thread.stack_base);var stack_end:int=stack_base+int(world.thread.stack_size)
	if stack_end>0x100000000 or int(world.thread.stack_pointer)<stack_base or int(world.thread.stack_pointer)+16>stack_end:return _error("Actor stack pointer outside explicit stack")
	if stack_base<0x400000+2125824 and 0x400000<stack_end:return _error("Actor stack must not overwrite original PE image")
	scope=str(world.scope);context=world.thread.duplicate(true);context.scope=scope;boundary=os_boundary;primitives=owned_primitives
	var ready:Dictionary=heap.initialize_fresh(Callable(self,"_os"),world.manager,context)
	if not ready.ok:return ready
	vm.byte_memory=heap.vm.byte_memory;vm.helpers=heap.vm.helpers;heap.vm=vm
	if primitives!=null:
		var bound:Dictionary=Reply.validate(primitives.bind_memory(vm.byte_memory),"Shared owned memory binding unavailable")
		if not bound.ok:return bound
		locks=primitives.locks
	var instructions:Dictionary={}
	for name in ["heap","pen","brush","canvas_constructor","bitmap_constructor"]:
		var module:Dictionary=JSON.parse_string(FileAccess.get_file_as_string("res://data/original_"+name+"_ir.json"))
		if module.source_sha256!=Heap.SOURCE_SHA:return _error("Shared instruction source identity differs")
		if module.image_file!=heap.program.image_file or int(module.image_base)!=int(heap.program.image_base) or int(module.image_size)!=int(heap.program.image_size) or str(module.get("image_sha256",module.get("mapped_image_sha256","")))!=str(heap.program.mapped_image_sha256):return _error("Merged module mapped-image identity differs")
		for instruction in module.instructions:
			var address:int=int(instruction.address)
			if instructions.has(address) and instructions[address]!=instruction:return _error("Conflicting original instruction at 0x%x"%address)
			instructions[address]=instruction
	program={"instructions":instructions.values(),"source_sha256":Heap.SOURCE_SHA}
	# Runtime values remain unknown unless an explicit world observation or the
	# actual source bootstrap writes them. PE BSS is not GUI-startup evidence.
	for address in [0x59a9e0,0x59a9e4,0x59a9e8,0x59a9ec,0x59a99c,0x59a9a0,0x59a9a4]:
		var page:Dictionary=vm.byte_memory.pages[address&~4095]
		var known:PackedByteArray=page.known
		for byte in 4:known[(address+byte)&4095]=0
		page.known=known
	for span in [[0x574b28,44],[0x574b54,1]]:
		for offset in int(span[1]):
			var at:int=int(span[0])+offset
			var page:Dictionary=vm.byte_memory.pages[at&~4095]
			var known:PackedByteArray=page.known;known[at&4095]=0;page.known=known
	for segment in world.get("segments",[]):vm.byte_memory.map_known(int(segment.address),str(segment.hex).hex_decode())
	for address in world.get("globals",{}):vm.put(str(address).trim_prefix("0x").hex_to_int(),int(world.globals[address]),1 if str(address).trim_prefix("0x").hex_to_int()==0x574b54 else 4)
	vm.helpers[0x554eb2]=Callable(self,"_delete_lock")
	vm.helpers[0x5552d8]=Callable(self,"_graphics").bind("DeleteObject",1)
	vm.helpers[0x5553f8]=Callable(self,"_graphics").bind("SelectObject",2)
	# No GetMem/FreeMem/ReallocMem helper: exact original wrapper/allocator bytes
	# remain in the merged instruction stream and propagate every metadata write.
	initialized=true;return {"ok":true,"scope":scope,"native_vcl_verified":false}
func _os(request:Dictionary)->Dictionary:
	if not vm.error.is_empty():return _error(vm.error)
	events.append(request.duplicate(true))
	if primitives!=null and str(request.api) in ["InitializeCriticalSection","EnterCriticalSection","LeaveCriticalSection","VirtualAlloc","VirtualFree","LocalAlloc","DeleteCriticalSection"]:return Reply.validate(primitives.dispatch(request),"Shared owned memory primitive unavailable")
	match str(request.api):
		"InitializeCriticalSection":
			var result:Dictionary=locks.create(scope,int(request.address))
			if result.ok:
				for offset in 24:
					var at:int=int(request.address)+offset
					var page:Dictionary=vm.byte_memory.pages[at&~4095]
					var known:PackedByteArray=page.known;known[at&4095]=0;page.known=known
			return result
		"EnterCriticalSection","LeaveCriticalSection":return locks.dispatch(request,scope)
		"DeleteCriticalSection":return locks.destroy(scope,int(request.address))
	return Reply.validate(boundary.call(request),"Shared VCL primitive unavailable")
func _args(count:int)->Array:
	var args:Array=[]
	for i in count:args.append(vm.integer(int(vm.registers.esp)+4+i*4))
	return args
func _delete_lock(_machine)->void:
	var result:Dictionary=_os({"api":"DeleteCriticalSection","address":int(_args(1)[0])})
	if result.ok:vm.return_helper(null,4)
	else:vm.error=result.error
func _graphics(_machine,name:String,count:int)->void:
	var args:=_args(count)
	var request:Dictionary={"api":name,"handle":args[0]} if count==1 else {"api":name,"hdc":args[0],"handle":args[1]}
	var result:Dictionary=_os(request)
	if not result.ok:
		vm.error=result.error;return
	if not result.has("result") or not _whole(result.result):
		vm.error="Shared graphics primitive requires an explicit DWORD result";return
	vm.return_helper(int(result.result),count*4)
func execute_entry(entry:int,eax:int=0,edx:int=0,ecx:int=0,endpoint:int=-1)->Dictionary:
	if not initialized:return _error("Shared VCL world is uninitialized")
	if not vm.error.is_empty():return _error(vm.error)
	if vm.integer(int(context.fs_base))!=int(context.exception_head):return _error("Previous source operation did not restore actor FS exception chain")
	vm.registers.esp=int(context.stack_pointer)+4;vm.registers.ebp=0;vm.registers.eax=eax&0xffffffff;vm.registers.edx=edx&0xffffffff;vm.registers.ecx=ecx&0xffffffff
	var bounded:Dictionary=program.duplicate();bounded.end=endpoint
	var result:Dictionary=vm.execute(bounded,entry)
	result.value=int(vm.registers.eax)
	return result
func construct_registries()->Dictionary:return execute_entry(0x4eb398,0,0,0,0x4eb3d7)
func construct_canvas_list()->Dictionary:return execute_entry(0x4eb3e8,0,0,0,0x4eb40a)
func construct_canvas(vmt_or_instance:int,allocation_flag:int=1)->Dictionary:return execute_entry(0x4e42a8,vmt_or_instance,allocation_flag)
func read_bytes(address:int,size:int)->Dictionary:
	var raw:=vm.read(address,size);return {"ok":vm.error.is_empty(),"bytes":raw,"error":vm.error}
func close()->void:heap.close();vm.helpers.clear();boundary=Callable()
