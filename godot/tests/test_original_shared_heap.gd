extends SceneTree
const Heap=preload("res://scripts/original/original_shared_heap.gd")
var failures:Array=[]
var virtual_next:=0x4000000
var local_next:=0x6000000
var checks:=0
func boundary(request:Dictionary)->Dictionary:
	match str(request.api):
		"LocalAlloc":
			var address:int=local_next;local_next=(address+int(request.size)+15)&~15
			var raw:=PackedByteArray();raw.resize(int(request.size));raw.fill(0xa5)
			return {"ok":true,"address":address,"bytes":raw}
		"VirtualAlloc":
			var address:int=int(request.address)
			if int(request.flags)==0x2000:
				if address==0:address=virtual_next
				virtual_next=maxi(virtual_next,address+((int(request.size)+0xffff)&~0xffff))
			return {"ok":true,"address":address}
		"VirtualFree":return {"ok":true,"result":1}
		"InitializeCriticalSection","EnterCriticalSection","LeaveCriticalSection":return {"ok":true,"result":0}
	return {"ok":false,"error":"Unsupported test API"}
func check(condition:bool,label:String)->void:
	checks+=1
	if not condition:failures.append(label)
func hash_bytes(bytes:PackedByteArray)->String:
	var hash:=HashingContext.new();hash.start(HashingContext.HASH_SHA256);hash.update(bytes);return hash.finish().hex_encode()
func compare_state(heap,expected:Dictionary,label:String)->void:
	var globals:Dictionary=heap.read_bytes(0x59b170,0x78)
	check(globals.ok and globals.bytes.hex_encode()==expected.globals_59b170,label+" allocator globals")
	for block in expected.local_blocks:
		var address:int=str(block.address).trim_prefix("0x").hex_to_int()
		var actual:Dictionary=heap.read_bytes(address,int(block.size))
		check(actual.ok and actual.bytes.hex_encode()==block.bytes,label+" LocalAlloc table/list bytes")
	check(heap.committed.size()==expected.pages.size(),label+" committed page count")
	for page in expected.pages:
		var address:int=str(page.address).trim_prefix("0x").hex_to_int()
		var actual:Dictionary=heap.read_bytes(address,4096)
		check(actual.ok and hash_bytes(actual.bytes)==page.sha256,label+" committed page0x%x"%address)
	check(heap.reservations.size()==expected.reservations.size(),label+" reservation count")
	for address in expected.reservations:
		check(heap.reservations.get(str(address).trim_prefix("0x").hex_to_int(),-1)==int(expected.reservations[address]),label+" reserved range")
	check(heap.api_events.size()==expected.api_events.size(),label+" API call count")
	for index in mini(heap.api_events.size(),expected.api_events.size()):
		var actual:Dictionary=heap.api_events[index];var event:Dictionary=expected.api_events[index]
		for field in ["api","address","size","flags","protect"]:
			if not event.has(field):continue
			var value=event[field]
			if value is String and str(value).begins_with("0x"):value=str(value).trim_prefix("0x").hex_to_int()
			check(actual.get(field,null)==value,label+" API"+str(index)+" "+field)
func _initialize()->void:
	var corpus:Dictionary=JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_shared_heap.json"))
	var steps:=0
	for fixture in corpus.cases:
		virtual_next=0x4000000;local_next=0x6000000
		var heap=Heap.new()
		var initialized:Dictionary=heap.initialize_fresh(Callable(self,"boundary"),Heap.DEFAULT_MANAGER,{"fs_base":0,"exception_head":0xffffffff,"stack_base":0x9000000,"stack_size":0x100000,"stack_pointer":0x90ffe00,"stack_origin":"fresh_committed_pages","scope":"Native kernel oracle test; chosen API addresses, not GUI startup"})
		if not initialized.ok:failures.append([fixture.name,"bootstrap",initialized]);heap.close();continue
		var pointers:Dictionary={}
		for index in fixture.steps.size():
			var step:Dictionary=fixture.steps[index];var operation:Dictionary=step.operation;var result:Dictionary
			match str(operation.op):
				"get":result=heap.get_mem(int(operation.size))
				"free":result=heap.free_mem(int(pointers[operation.id]))
				"fill":result=heap.write_bytes(int(pointers[operation.id]),str(operation.hex).hex_decode())
				"realloc":result=heap.realloc_mem(int(pointers[operation.id]),int(operation.size))
			if not result.ok:failures.append([fixture.name,index,result]);break
			if operation.op in ["get","realloc"]:pointers[operation.id]=result.value
			if step.value!=null:check(result.value==int(step.value),str(fixture.name)+" operation"+str(index)+" original return/address")
			for key in step.pointers:check(pointers[key]==int(step.pointers[key]),str(fixture.name)+" native pointer"+str(key))
			compare_state(heap,step.state,str(fixture.name)+" step"+str(index));steps+=1
		heap.close()
	print(JSON.stringify({"native_steps":steps,"byte_address_list_checks":checks,"failures":failures}))
	if failures.is_empty() and steps==74:print("PASS original shared byte-heap native GetMem FreeMem realloc reuse/decommit and list state")
	quit(0 if failures.is_empty() and steps==74 else 1)

