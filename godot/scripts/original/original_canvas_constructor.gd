class_name OriginalCanvasConstructor
extends RefCounted
## Retained complete normal Canvas/graphic-object constructors and registration.
## Allocation, lock backing and source runtime font inputs are explicit.
const Vm=preload("res://scripts/original/original_canvas_constructor_vm.gd")
const ApiReply=preload("res://scripts/original/original_api_reply.gd")
const SOURCE_SHA:="7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c"
var vm=Vm.new()
var program:Dictionary={}
var api:Callable
var events:Array=[]
var allocated_blocks:Dictionary={}
var context:Dictionary={}
var initialized:=false
func _error(message:String)->Dictionary:return {"ok":false,"error":message}
func _hash(raw:PackedByteArray)->String:
	var hash:=HashingContext.new();hash.start(HashingContext.HASH_SHA256);hash.update(raw);return hash.finish().hex_encode()
func initialize(world:Dictionary,boundary:Callable)->Dictionary:
	if initialized:return _error("Use a new constructor world for an independent graph")
	if world.get("source_sha256","")!=SOURCE_SHA or str(world.get("scope","")).is_empty() or not boundary.is_valid():return _error("Original source graph provenance and API boundary are required")
	if not world.get("segments",null) is Array or not world.get("globals",null) is Dictionary or not world.get("thread",null) is Dictionary:return _error("Original complete graph/globals/thread inputs are required")
	context=world.thread.duplicate(true)
	for field in ["fs_base","exception_head","stack_base","stack_size","stack_pointer","stack_origin"]:
		if not context.has(field):return _error("Original Canvas thread input missing: "+field)
	program=JSON.parse_string(FileAccess.get_file_as_string("res://data/original_canvas_constructor_ir.json"))
	var image:=FileAccess.get_file_as_bytes(str(program.image_file))
	if program.source_sha256!=SOURCE_SHA or image.size()!=int(program.image_size) or _hash(image)!=program.image_sha256:return _error("Original Canvas IR/image identity differs")
	vm.byte_memory.map_known(int(program.image_base),image)
	# These runtime globals must never inherit PE BSS zero as live evidence.
	for address in [0x59a9e0,0x59a9e4,0x59a9e8,0x59a99c,0x59a9ec]:
		var page:Dictionary=vm.byte_memory.pages[address&~4095]
		for byte in 4:page.known[(address+byte)&4095]=0
	# Startup mutates the default font descriptor before Canvas construction.
	# Mapped file bytes are not an observation of that live runtime descriptor.
	for offset in 44:
		var address:int=0x574b28+offset
		vm.byte_memory.pages[address&~4095].known[address&4095]=0
	if not world.globals.has("0x59a99c"):return _error("Explicit font stock/global input is required")
	for address in world.globals:
		var at:int=str(address).trim_prefix("0x").hex_to_int()
		if at not in [0x59a9e0,0x59a9e4,0x59a9e8,0x59a99c,0x59a9ec]:return _error("Unsupported brush runtime global")
		vm.put(at,int(world.globals[address]))
	for segment in world.segments:
		if not segment is Dictionary or not segment.has("address") or not segment.has("hex"):return _error("Incomplete original graph segment")
		var raw:=str(segment.hex).hex_decode();var at:int=int(segment.address)
		if raw.is_empty() or at<=0 or at>0xffffffff-raw.size():return _error("Invalid original graph byte span")
		vm.byte_memory.map_known(at,raw)
	var stack_base:int=int(context.stack_base);var stack_size:int=int(context.stack_size)
	if stack_base&4095!=0 or stack_size<=0 or stack_size&4095!=0:return _error("Pen thread stack is not page aligned")
	if context.stack_origin=="fresh_committed_pages":
		for page in range(stack_base,stack_base+stack_size,4096):vm.byte_memory.commit_zero(page)
	elif context.has("stack_raw"):
		var raw:=str(context.stack_raw).hex_decode()
		if raw.size()!=stack_size:return _error("Observed brush stack bytes are incomplete")
		vm.byte_memory.map_known(stack_base,raw)
	else:return _error("Pen thread stack origin is unresolved")
	var fs:=PackedByteArray();fs.resize(4);fs.encode_u32(0,int(context.exception_head));vm.byte_memory.map_known(int(context.fs_base),fs)
	api=boundary
	vm.helpers={0x554ec4:Callable(self,"_critical").bind("EnterCriticalSection"),0x555020:Callable(self,"_critical").bind("LeaveCriticalSection"),
		0x530c70:Callable(self,"_get_mem"),0x530c88:Callable(self,"_free_mem"),0x5552d8:Callable(self,"_delete_object"),0x5553f8:Callable(self,"_select_object"),0x555272:Callable(self,"_create_brush"),0x555678:Callable(self,"_system_color")}
	vm.helpers[0x555008]=Callable(self,"_initialize_critical")
	vm.helpers[0x530ca0]=Callable(self,"_realloc_mem")
	initialized=true;return {"ok":true}
func _request(request:Dictionary)->Dictionary:
	if not vm.error.is_empty():return {"ok":false,"error":vm.error}
	request.source_pc=vm.pc
	var reply:=ApiReply.validate(api.call(request),"Original Canvas API boundary unresolved")
	if not reply.ok:
		vm.error=reply.error;return reply
	events.append(request.duplicate(true));return reply
func _argument(index:int)->int:return vm.integer(int(vm.registers.esp)+4+index*4)
func _critical(_machine:Vm,name:String)->void:
	var reply:=_request({"api":name,"address":_argument(0)})
	if reply.ok:vm.return_helper(reply.get("eax_after",null),4)
func _get_mem(_machine:Vm)->void:
	var size:int=int(vm.registers.eax);var reply:=_request({"api":"GetMem","size":size})
	if not reply.ok:return
	if not reply.has("address") or int(reply.address)<=0:vm.error="Original allocation failure/exception boundary unresolved";return
	var address:int=int(reply.address)
	vm.byte_memory.map_unknown(address,size)
	if reply.has("raw_hex"):
		var raw:=str(reply.raw_hex).hex_decode()
		if raw.size()!=size:vm.error="Original allocated backing is incomplete";return
		vm.write(address,raw)
	if not _apply_memory_writes(reply):return
	allocated_blocks[address]=size;vm.return_helper(address)
func _apply_memory_writes(reply:Dictionary)->bool:
	for segment in reply.get("memory_writes",[]):
		if not segment is Dictionary or not segment.has("address") or not segment.has("raw_hex"):vm.error="Original API backing write is unresolved";return false
		var raw:=str(segment.raw_hex).hex_decode();var address:int=int(segment.address)
		if raw.is_empty() or address<=0 or address>0xffffffff-raw.size():vm.error="Invalid original API memory write";return false
		vm.byte_memory.map_known(address,raw)
	return true
func _free_mem(_machine:Vm)->void:
	var address:int=int(vm.registers.eax);var reply:=_request({"api":"FreeMem","address":address})
	if reply.ok:
		if not reply.get("memory_writes",null) is Array:vm.error="Original FreeMem backing effects must be explicit";return
		if _apply_memory_writes(reply):vm.return_helper(reply.get("eax_after",null))
func _delete_object(_machine:Vm)->void:
	var reply:=_request({"api":"DeleteObject","handle":_argument(0)})
	if reply.ok and reply.has("result"):vm.return_helper(int(reply.result),4)
	elif reply.ok:vm.error="Original DeleteObject result is unresolved"
func _select_object(_machine:Vm)->void:
	var reply:=_request({"api":"SelectObject","hdc":_argument(0),"handle":_argument(1)})
	if reply.ok and reply.has("result"):vm.return_helper(int(reply.result),8)
	elif reply.ok:vm.error="Original SelectObject result is unresolved"
func _create_brush(_machine:Vm)->void:
	var pointer:int=_argument(0)
	var raw:=vm.read(pointer,12)
	if not vm.error.is_empty():return
	var reply:=_request({"api":"CreateBrushIndirect","logbrush_hex":raw.hex_encode()})
	if reply.ok and reply.has("result"):vm.return_helper(int(reply.result),4)
	elif reply.ok:vm.error="Original CreateBrushIndirect result is unresolved"
func _system_color(_machine:Vm)->void:
	var reply:=_request({"api":"GetSysColor","index":_argument(0)})
	if reply.ok and reply.has("result"):vm.return_helper(int(reply.result),4)
	elif reply.ok:vm.error="Original GetSysColor result is unresolved"

func _initialize_critical(_machine:Vm)->void:
	var reply:=_request({"api":"InitializeCriticalSection","address":_argument(0)})
	if reply.ok:
		if not reply.get("memory_writes",null) is Array:vm.error="InitializeCriticalSection backing effects must be explicit";return
		if _apply_memory_writes(reply):vm.return_helper(reply.get("eax_after",null),4)
func _execute(entry:int,endpoint:int,eax:int,edx:int=0)->Dictionary:
	if not initialized:return _error("Canvas construction world is uninitialized")
	if not vm.error.is_empty():return _error(vm.error)
	vm.registers={"eax":eax,"edx":edx&0xffffffff,"ecx":0,"ebx":0,"esi":0,"edi":0,"ebp":0,"esp":int(context.stack_pointer)+4}
	var bounded:Dictionary=program.duplicate();bounded.end=endpoint
	return vm.execute(bounded,entry)
func construct_registries()->Dictionary:
	return _execute(0x4eb398,0x4eb3d7,0)
func construct_canvas_list()->Dictionary:
	return _execute(0x4eb3e8,0x4eb40a,0)
func construct(vmt_or_instance:int,allocation_flag:int=1)->Dictionary:
	var result:=_execute(0x4e42a8,-1,vmt_or_instance,allocation_flag)
	result.canvas=int(vm.registers.eax)
	return result
func _realloc_mem(_machine:Vm)->void:
	var pointer:int=int(vm.registers.eax);var size:int=int(vm.registers.edx)
	var reply:=_request({"api":"ReallocMem","pointer_address":pointer,"old_address":vm.integer(pointer),"size":size})
	if not reply.ok:return
	if not reply.has("address") or not reply.has("raw_hex"):vm.error="Original reallocation backing must be explicit";return
	var raw:=str(reply.raw_hex).hex_decode()
	if raw.size()!=size:vm.error="Original reallocation backing size differs";return
	vm.byte_memory.map_known(int(reply.address),raw);vm.put(pointer,int(reply.address))
	if _apply_memory_writes(reply):vm.return_helper(reply.get("eax_after",null))
func read_bytes(address:int,size:int)->Dictionary:
	var raw:=vm.read(address,size)
	return {"ok":vm.error.is_empty(),"bytes":raw,"error":vm.error}
func close()->void:vm.helpers.clear();api=Callable()
