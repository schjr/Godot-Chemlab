class_name OriginalBitmapConstructor
extends RefCounted
## Retained actual TBitmap/InitInstance/shared-image initialization, not a
## synthetic minimal bitmap. Allocation and RTL errors are explicit boundaries.
const Vm=preload("res://scripts/original/original_bitmap_constructor_vm.gd")
const ApiReply=preload("res://scripts/original/original_api_reply.gd")
const SOURCE_SHA="7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c"
var vm=Vm.new()
var program:Dictionary={}
var api:Callable
var context:Dictionary={}
var events:Array=[]
var allocated_blocks:Dictionary={}
var initialized:=false
var runtime_error:=false
func _fail(message:String)->Dictionary:return {"ok":false,"error":message}
func _hash(raw:PackedByteArray)->String:
	var h:=HashingContext.new();h.start(HashingContext.HASH_SHA256);h.update(raw);return h.finish().hex_encode()
func initialize(world:Dictionary,boundary:Callable)->Dictionary:
	if initialized:return _fail("Use a new constructor instance for an independent world")
	if world.get("source_sha256","")!=SOURCE_SHA or str(world.get("scope","")).is_empty() or not boundary.is_valid():return _fail("Explicit original world provenance/allocation boundary required")
	if not world.get("segments") is Array or not world.get("globals") is Dictionary or not world.get("thread") is Dictionary:return _fail("Original graph/global/thread inputs required")
	for field in ["0x575604","0x574b54"]:
		if not world.globals.has(field):return _fail("Observed selected GetMem/bitmap policy input required: "+field)
	if int(world.globals["0x575604"])<=0 or int(world.globals["0x575604"])>0xffffffff or int(world.globals["0x574b54"])<0 or int(world.globals["0x574b54"])>255:return _fail("Selected manager/policy operand is outside original byte width")
	context=world.thread.duplicate(true)
	for field in ["fs_base","exception_head","stack_base","stack_size","stack_pointer","stack_origin"]:
		if not context.has(field):return _fail("Original constructor thread input missing: "+field)
	var base:int=int(context.stack_base);var size:int=int(context.stack_size);var pointer:int=int(context.stack_pointer)
	if base&4095!=0 or base<0x10000 or size<=0 or size>0x100000 or size&4095!=0 or pointer<base+4096 or pointer>=base+size-16:return _fail("Invalid constructor stack mapping")
	program=JSON.parse_string(FileAccess.get_file_as_string("res://data/original_bitmap_constructor_ir.json"))
	var image:=FileAccess.get_file_as_bytes(str(program.image_file))
	if program.source_sha256!=SOURCE_SHA or image.size()!=int(program.image_size) or _hash(image)!=str(program.mapped_image_sha256):return _fail("Original bitmap instruction/image identity differs")
	if base<int(program.image_base)+image.size() and int(program.image_base)<base+size:return _fail("Constructor stack overlaps original image")
	vm.byte_memory.map_known(int(program.image_base),image)
	for address in world.globals:
		if address not in ["0x575604","0x574b54"]:return _fail("Unsupported original bitmap global")
		vm.put(str(address).trim_prefix("0x").hex_to_int(),int(world.globals[address]),1 if address=="0x574b54" else 4)
	for segment in world.segments:
		if not segment is Dictionary or not segment.has("address") or not segment.has("hex"):return _fail("Incomplete original object segment")
		var raw:=str(segment.hex).hex_decode();var at:int=int(segment.address)
		if raw.size()*2!=str(segment.hex).length():return _fail("Object bytes are not complete hexadecimal backing")
		if at<int(program.image_base)+image.size() and int(program.image_base)<at+raw.size():return _fail("Object segment overlaps original image")
		if raw.is_empty() or at<=0 or at>0xffffffff-raw.size():return _fail("Invalid object segment")
		vm.byte_memory.map_known(at,raw)
	if context.stack_origin=="fresh_committed_pages":
		for page in range(base,base+size,4096):vm.byte_memory.commit_zero(page)
	elif context.has("stack_raw"):
		var raw:=str(context.stack_raw).hex_decode()
		if raw.size()!=size:return _fail("Observed stack bytes incomplete")
		vm.byte_memory.map_known(base,raw)
	else:return _fail("Explicit stack byte origin required")
	if int(context.fs_base)<0 or int(context.fs_base)>0xfffffffc:return _fail("Original FS base is outside DWORD address domain")
	vm.fs_base=int(context.fs_base)
	var fs:=PackedByteArray();fs.resize(4);fs.encode_u32(0,int(context.exception_head));vm.byte_memory.map_known(vm.fs_base,fs)
	var manager:int=vm.integer(0x575604)
	if manager<=0:return _fail("Selected original GetMem pointer is unresolved")
	for instruction in program.instructions:
		if int(instruction.address)==manager:return _fail("Selected allocator collides with retained constructor code")
	api=boundary
	vm.helpers={manager:Callable(self,"_get_mem"),0x530d64:Callable(self,"_runtime_error")}
	initialized=true;return {"ok":true}
func _get_mem(_machine)->void:
	var size:int=int(vm.registers.eax);var manager:int=vm.pc
	var request:={"api":"MemoryManager.GetMem","address":manager,"size":size}
	var response:=ApiReply.validate(api.call(request),"Original raw manager allocation unavailable")
	if not response.ok:
		vm.error=response.error;return
	if not response.has("address"):
		vm.error="Original raw manager allocation unavailable";return
	var address:int=int(response.address)
	if address<0 or address>0xffffffff-size or size<=0 or size>0x100000:vm.error="Invalid original raw allocation boundary";return
	var event:=request.duplicate(true);event["result"]=address;events.append(event)
	if address!=0:
		if address<int(program.image_base)+int(program.image_size) and int(program.image_base)<address+size:vm.error="Raw allocation overlaps retained original image";return
		if address<int(context.stack_base)+int(context.stack_size) and int(context.stack_base)<address+size:vm.error="Raw allocation overlaps constructor stack";return
		for old in allocated_blocks:
			if address<int(old)+int(allocated_blocks[old]) and int(old)<address+size:vm.error="Overlapping live original allocation";return
		vm.byte_memory.map_unknown(address,size)
		if response.has("raw_hex"):
			var raw:=str(response.raw_hex).hex_decode()
			if raw.size()!=size:vm.error="Incomplete actual allocated payload";return
			vm.write(address,raw)
		for write in response.get("memory_writes",[]):
			if not write is Dictionary or not write.has("address") or not write.has("raw_hex"):vm.error="Incomplete allocator backing effects";return
			vm.byte_memory.map_known(int(write.address),str(write.raw_hex).hex_decode())
		allocated_blocks[address]=size
	vm.return_helper(address)
func _runtime_error(_machine)->void:
	runtime_error=true;events.append({"api":"OriginalRuntimeError","code":int(vm.registers.eax)&255})
	vm.error="Original RTL allocation error reached530D64; exception/termination boundary unresolved"
func _execute(entry:int,eax:int,edx:int=0)->Dictionary:
	if not initialized:return _fail("Original bitmap world is uninitialized")
	if not vm.error.is_empty():return _fail(vm.error)
	vm.registers={"eax":eax,"edx":edx,"ecx":0,"ebx":0,"esi":0,"edi":0,"ebp":0,"esp":int(context.stack_pointer)+4}
	return vm.execute(program,entry)
func construct(vmt_or_instance:int=0x4e2af4,allocation_flag:int=1)->Dictionary:
	if allocation_flag&255 in [0,129]:
		if vm.integer(vmt_or_instance)!=0x4e2af4:return _fail("Existing TBitmap VMT/backing unresolved")
	elif allocation_flag!=1 or vmt_or_instance!=0x4e2af4:return _fail("Unported bitmap subclass/allocation convention")
	var result:=_execute(0x4e8edc,vmt_or_instance,allocation_flag)
	if result.ok:result["bitmap"]=int(vm.registers.eax);result["shared_image"]=vm.integer(int(vm.registers.eax)+0x20)
	result["runtime_error"]=runtime_error
	return result
func add_reference(shared:int)->Dictionary:
	if vm.integer(shared)!=0x4e2a94:return _fail("Original shared-image VMT/backing unresolved")
	return _execute(0x4e843c,shared)
func read_bytes(address:int,size:int)->Dictionary:
	var raw:=vm.read(address,size);return {"ok":vm.error.is_empty(),"bytes":raw,"error":vm.error}
func close()->void:vm.helpers.clear();api=Callable()
