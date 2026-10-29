class_name OriginalSharedHeap
extends RefCounted
## Actual original default System allocator instruction execution.
## The caller supplies Win32 API outcomes and an explicit bootstrap world.
const Vm=preload("res://scripts/original/original_heap_vm.gd")
const ApiReply=preload("res://scripts/original/original_api_reply.gd")
const SOURCE_SHA:="7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c"
const DEFAULT_MANAGER:={"allocation_dispatch":0x534428,"system_get":0x5306b0,"system_free":0x530838,"system_realloc":0x530bac}
var vm=Vm.new()
var program:Dictionary={}
var api:Callable
var manager:Dictionary={}
var context:Dictionary={}
var reservations:Dictionary={}
var committed:Dictionary={}
var api_events:Array=[]
var initialized:=false
var last_error:=""
func _fail(message:String)->Dictionary:
	last_error=message;vm.error=message;return {"ok":false,"error":message}
func _sha256(bytes:PackedByteArray)->String:
	var hash:=HashingContext.new();hash.start(HashingContext.HASH_SHA256);hash.update(bytes);return hash.finish().hex_encode()
func initialize_fresh(boundary:Callable,observed_manager:Dictionary,thread_context:Dictionary)->Dictionary:
	if not boundary.is_valid():return _fail("Original Win32 memory API boundary is required")
	for field in DEFAULT_MANAGER:
		if int(observed_manager.get(field,-1))!=int(DEFAULT_MANAGER[field]):return _fail("Original selected memory manager is absent or unsupported: "+field)
	for field in ["fs_base","exception_head","stack_base","stack_size","stack_pointer","scope"]:
		if not thread_context.has(field):return _fail("Original allocator thread context is required: "+field)
	if initialized:return _fail("Use a new shared heap instance for a fresh allocation world")
	program=JSON.parse_string(FileAccess.get_file_as_string("res://data/original_heap_ir.json"))
	if program.get("source_sha256","")!=SOURCE_SHA:return _fail("Original allocator source identity differs")
	var image:=FileAccess.get_file_as_bytes(str(program.image_file))
	if image.size()!=int(program.image_size) or _sha256(image)!=str(program.mapped_image_sha256):return _fail("Original mapped heap image is incomplete")
	api=boundary;manager=observed_manager.duplicate(true);context=thread_context.duplicate(true)
	vm.byte_memory.map_known(int(program.image_base),image)
	var stack_base:int=int(context.stack_base);var stack_size:int=int(context.stack_size)
	if stack_base&4095!=0 or stack_size<=0 or stack_size&4095!=0:return _fail("Original stack mapping is not page-aligned")
	if context.get("stack_origin","")=="fresh_committed_pages":
		for page in range(stack_base,stack_base+stack_size,4096):vm.byte_memory.commit_zero(page)
	elif context.get("stack_raw",null) is String:
		var raw:=str(context.stack_raw).hex_decode()
		if raw.size()!=stack_size:return _fail("Original observed stack is incomplete")
		vm.byte_memory.map_known(stack_base,raw)
	else:return _fail("Explicit fresh-page or observed-stack origin is required")
	vm.byte_memory.map_known(int(context.fs_base),PackedInt32Array([int(context.exception_head)]).to_byte_array())
	# Runtime manager selection is an explicit input, not an inferred fallback.
	for pair in [[0x57598c,"allocation_dispatch"],[0x575604,"system_get"],[0x575608,"system_free"],[0x57560c,"system_realloc"]]:vm.put(int(pair[0]),int(manager[pair[1]]))
	vm.helpers={0x5550c2:Callable(self,"_virtual_alloc"),0x5550c8:Callable(self,"_virtual_free"),0x555038:Callable(self,"_local_alloc"),
		0x555008:Callable(self,"_critical_section"),0x554ec4:Callable(self,"_critical_section"),0x555020:Callable(self,"_critical_section")}
	initialized=true;return {"ok":true,"scope":"Fresh allocator kernel world only; original GUI startup clients not replayed"}
func _arguments(count:int)->Array:
	var values:Array=[]
	for index in count:values.append(vm.integer(int(vm.registers.esp)+4+index*4))
	return values
func _request(request:Dictionary)->Dictionary:
	if not vm.error.is_empty():return {"ok":false,"error":vm.error}
	var result:=ApiReply.validate(api.call(request),"Original API boundary unresolved")
	if not result.ok:
		vm.error=result.error;return result
	return result
func _virtual_alloc(_machine)->void:
	var args:=_arguments(4);var address:int=int(args[0]);var size:int=int(args[1]);var flags:int=int(args[2]);var protect:int=int(args[3])
	var response:=_request({"api":"VirtualAlloc","address":address,"size":size,"flags":flags,"protect":protect})
	if not response.ok:return
	var returned:int=int(response.get("address",0))
	if returned!=0:
		if flags==0x2000:
			var rounded:int=(size+4095)&~4095
			if returned&0xffff!=0 or rounded<=0:vm.error="Invalid original VirtualAlloc reserve outcome";return
			for base in reservations:
				if returned<int(base)+int(reservations[base]) and int(base)<returned+rounded:vm.error="Overlapping original reservation";return
			reservations[returned]=rounded
		elif flags==0x1000:
			var first:int=address&~4095;var end:int=(address+size+4095)&~4095;var valid:=false
			for base in reservations:
				if int(base)<=first and end<=int(base)+int(reservations[base]):valid=true
			if not valid or returned!=first:vm.error="Original commit outcome does not match reservation";return
			for page in range(first,end,4096):
				if not committed.has(page):vm.byte_memory.commit_zero(page);committed[page]=true
		else:vm.error="Original VirtualAlloc flags are unsupported:0x%x"%flags;return
	api_events.append({"api":"VirtualAlloc","address":returned,"size":size,"flags":flags,"protect":protect})
	vm.return_helper(returned,16)
func _virtual_free(_machine)->void:
	var args:=_arguments(3);var address:int=int(args[0]);var size:int=int(args[1]);var flags:int=int(args[2])
	var response:=_request({"api":"VirtualFree","address":address,"size":size,"flags":flags})
	if not response.ok:return
	var success:int=int(response.get("result",0))
	if success!=0:
		if flags==0x4000:
			for page in range(address&~4095,(address+size+4095)&~4095,4096):committed.erase(page);vm.byte_memory.decommit(page)
		elif flags==0x8000:
			if not reservations.has(address) or size!=0:vm.error="Invalid original release outcome";return
			var count:int=int(reservations[address]);reservations.erase(address)
			for page in range(address,address+count,4096):committed.erase(page);vm.byte_memory.decommit(page)
		else:vm.error="Original VirtualFree flags are unsupported";return
	api_events.append({"api":"VirtualFree","address":address,"size":size,"flags":flags,"result":success})
	vm.return_helper(success,12)
func _local_alloc(_machine)->void:
	var args:=_arguments(2);var flags:int=int(args[0]);var size:int=int(args[1])
	var response:=_request({"api":"LocalAlloc","flags":flags,"size":size})
	if not response.ok:return
	var address:int=int(response.get("address",0))
	if address!=0:
		if flags!=0 or size<=0:vm.error="Original LocalAlloc boundary flags unsupported";return
		vm.byte_memory.map_unknown(address,size)
		if response.has("bytes"):
			var raw:PackedByteArray=response.bytes
			if raw.size()!=size:vm.error="Original LocalAlloc observation is incomplete";return
			vm.write(address,raw)
	api_events.append({"api":"LocalAlloc","address":address,"size":size,"flags":flags})
	vm.return_helper(address,8)
func _critical_section(_machine)->void:
	var name:String="InitializeCriticalSection" if vm.pc==0x555008 else "EnterCriticalSection" if vm.pc==0x554ec4 else "LeaveCriticalSection"
	var response:=_request({"api":name,"address":vm.integer(int(vm.registers.esp)+4)})
	if not response.ok:return
	vm.return_helper(response.get("result",null),4)
func _call(entry:int,eax:int,edx:int=0,ecx:int=0)->Dictionary:
	if not initialized:return _fail("Original shared heap is not initialized")
	if not last_error.is_empty():return {"ok":false,"error":last_error}
	vm.registers.esp=int(context.stack_pointer);vm.registers.ebp=0;vm.registers.eax=eax&0xffffffff;vm.registers.edx=edx&0xffffffff;vm.registers.ecx=ecx&0xffffffff
	var result:Dictionary=vm.execute(program,entry)
	if not result.ok:return _fail(str(result.error))
	return {"ok":true,"value":int(vm.registers.eax)}
func get_mem(size:int)->Dictionary:return _call(0x5306b0,size)
func free_mem(pointer:int)->Dictionary:return _call(0x530838,pointer)
func realloc_mem(pointer:int,size:int)->Dictionary:return _call(0x530bac,pointer,size)
func read_bytes(address:int,size:int)->Dictionary:
	var bytes:PackedByteArray=vm.read(address,size)
	return {"ok":true,"bytes":bytes} if vm.error.is_empty() else _fail(vm.error)
func write_bytes(address:int,bytes:PackedByteArray)->Dictionary:
	vm.write(address,bytes)
	return {"ok":true} if vm.error.is_empty() else _fail(vm.error)
func to_state()->Dictionary:
	return {"format":"Original-shared-byte-heap","version":1,"source_sha256":SOURCE_SHA,"manager":manager.duplicate(true),"context":context.duplicate(true),
		"memory":vm.byte_memory.to_state(),"reservations":reservations.duplicate(),"committed":committed.keys(),"api_events":api_events.duplicate(true)}
func close()->void:vm.helpers.clear();api=Callable()
