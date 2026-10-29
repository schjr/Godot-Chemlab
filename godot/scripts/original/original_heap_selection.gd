class_name OriginalHeapSelection
extends RefCounted
## Actual retained534368→53418C selection instructions. No host module result,
## export, selected allocator or AddRef success is manufactured.
const Vm=preload("res://scripts/original/original_heap_vm.gd")
const SOURCE_SHA="7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c"
const GLOBALS=[0x575980,0x575984,0x575988,0x57598c,0x575990,0x575994,0x575604,0x575608,0x57560c,0x59b224,0x59b228,0x59b22c,0x59b230,0x59b234,0x59b238]
var vm=Vm.new()
var api:Callable
var events:Array=[]
var fatal:=false
var used:=false
func _hash(raw:PackedByteArray)->String:
	var h:=HashingContext.new();h.start(HashingContext.HASH_SHA256);h.update(raw);return h.finish().hex_encode()
func _cstring(pointer:int)->String:
	var bytes:=PackedByteArray()
	for i in 512:
		var b:int=vm.integer(pointer+i,1)
		if not vm.error.is_empty():return ""
		if b==0:return bytes.hex_encode()
		bytes.append(b)
	vm.error="Original startup API string exceeds explicit512-byte boundary";return ""
func _argument(index:int)->int:return vm.integer(int(vm.registers.esp)+4+index*4)
func _dword(value:Variant)->bool:
	return (value is int and value>=0 and value<=0xffffffff) or (value is float and is_finite(value) and value==floor(value) and value>=0 and value<=4294967295.0)
func _call_boundary(request:Dictionary,pop:int)->void:
	if not vm.error.is_empty():return
	var reply=api.call(request)
	if not reply is Dictionary or not reply.get("ok",false) or not _dword(reply.get("result")):
		vm.error=str(reply.get("error","Explicit original startup API result is missing")) if reply is Dictionary else "Original startup API boundary returned no result";return
	var result:int=int(reply.result);var event:=request.duplicate(true);event.result=result;events.append(event)
	if str(request.api)=="GetProcAddress" and str(request.name_hex).hex_decode().get_string_from_ascii().contains("HeapAddRef") and result!=0:
		vm.helpers[result]=Callable(self,"_addref")
	vm.return_helper(result,pop)
func _module(_machine)->void:_call_boundary({"api":"GetModuleHandleA","name_hex":_cstring(_argument(0))},4)
func _load(_machine)->void:_call_boundary({"api":"LoadLibraryA","name_hex":_cstring(_argument(0))},4)
func _proc(_machine)->void:_call_boundary({"api":"GetProcAddress","module":_argument(0),"name_hex":_cstring(_argument(1))},8)
func _addref(_machine)->void:_call_boundary({"api":"HeapAddRef","address":vm.pc},0)
func _abort(_machine)->void:
	fatal=true;events.append({"api":"original_fatal","message_hex":_cstring(_argument(0))});vm.error="Original memory-manager startup rejected its inputs at53B954"
func select_fresh(boundary:Callable,stack_context:Dictionary,initial_globals:Dictionary={},argument:int=1)->Dictionary:
	if used:return {"ok":false,"error":"Use a fresh selection instance"}
	if not boundary.is_valid():return {"ok":false,"error":"Explicit module/load/export/AddRef boundary required"}
	for field in ["stack_base","stack_size","stack_pointer","stack_origin","scope"]:
		if not stack_context.has(field):return {"ok":false,"error":"Explicit startup stack context missing: "+field}
	var base:int=int(stack_context.stack_base);var size:int=int(stack_context.stack_size);var pointer:int=int(stack_context.stack_pointer)
	if base<0x10000 or base&4095!=0 or size<=0 or size>0x100000 or size&4095!=0 or base+size>0x100000000 or pointer<base+4096 or pointer>base+size-16:
		return {"ok":false,"error":"Original startup stack mapping is invalid"}
	if stack_context.stack_origin!="fresh_committed_pages":return {"ok":false,"error":"This isolated fresh selector requires explicit fresh committed-page stack origin"}
	var program:Dictionary=JSON.parse_string(FileAccess.get_file_as_string("res://data/original_heap_selection_ir.json"))
	var image:=FileAccess.get_file_as_bytes(str(program.image_file))
	if program.source_sha256!=SOURCE_SHA or image.size()!=int(program.image_size) or _hash(image)!=str(program.mapped_image_sha256):return {"ok":false,"error":"Retained original selection/image identity differs"}
	if base<int(program.image_base)+image.size() and int(program.image_base)<base+size:return {"ok":false,"error":"Startup stack overlaps original PE mapping"}
	used=true;api=boundary
	vm.byte_memory.map_known(int(program.image_base),image)
	for page in range(base,base+size,4096):vm.byte_memory.commit_zero(page)
	for a in initial_globals:
		var address:int=str(a).trim_prefix("0x").hex_to_int()
		if address not in GLOBALS or not _dword(initial_globals[a]):return {"ok":false,"error":"Unsupported/unknown original initial selection global"}
		vm.put(address,int(initial_globals[a]))
	vm.helpers={0x554f66:Callable(self,"_module"),0x555026:Callable(self,"_load"),0x554f72:Callable(self,"_proc"),0x53b954:Callable(self,"_abort")}
	vm.registers.esp=pointer;vm.put(pointer,argument)
	var executed:Dictionary=vm.execute(program,0x534368)
	var globals:Dictionary={}
	for a in GLOBALS:globals["0x%x"%a]=vm.integer(a)
	var manager:={"allocation_dispatch":globals["0x57598c"],"system_get":globals["0x575604"],"system_free":globals["0x575608"],"system_realloc":globals["0x57560c"]}
	return {"ok":executed.ok,"error":executed.get("error",""),"fatal":fatal,"manager":manager,"globals":globals,"api_events":events.duplicate(true),"source_sha256":SOURCE_SHA,"selection_mode":globals["0x575984"],"compatible_with_existing_system_heap":manager=={"allocation_dispatch":0x534428,"system_get":0x5306b0,"system_free":0x530838,"system_realloc":0x530bac},"scope":"Isolated original fresh memory-manager selection; explicit host API outcomes; no complete GUI startup attestation"}
func close()->void:vm.helpers.clear();api=Callable()
