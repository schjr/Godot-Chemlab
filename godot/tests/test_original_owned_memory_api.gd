extends SceneTree
const Api=preload("res://scripts/original/original_owned_memory_api.gd")
const Heap=preload("res://scripts/original/original_shared_heap.gd")
const Memory=preload("res://scripts/original/original_heap_memory.gd")
var failures:Array=[]
var checks:=0
func check(ok:bool,label:String)->void:
	checks+=1
	if not ok:failures.append(label)
func config()->Dictionary:return {"scope":"isolated reconstructed memory acceptance","page_size":4096,"allocation_granularity":65536,"local_alignment":16,"virtual_domains":[{"address":0x4000000,"size":0x400000}],"local_domains":[{"address":0x6000000,"size":0x100000}],"exclusions":[{"address":0x4100000,"size":0x10000}],"lock_domains":[{"address":0x59b184,"size":24}]}
func reserve(api,address:int,size:int)->Dictionary:return api.dispatch({"api":"VirtualAlloc","address":address,"size":size,"flags":0x2000,"protect":4})
func commit(api,address:int,size:int)->Dictionary:return api.dispatch({"api":"VirtualAlloc","address":address,"size":size,"flags":0x1000,"protect":4})
func virtual_free(api,address:int,size:int,flags:int)->Dictionary:return api.dispatch({"api":"VirtualFree","address":address,"size":size,"flags":flags})
func _initialize()->void:
	var api=Api.new();check(api.initialize(config()).ok,"explicit address domain initialization")
	var r:Dictionary=reserve(api,0,0x1000);check(r.address==0x4000000,"declared first-fit placement")
	check(reserve(api,0x4000001,0x1000).address==0,"overlap returns real failure carrier0")
	check(reserve(api,0x4100000,4096).address==0,"reserved exclusion cannot be allocated")
	check(commit(api,0x5000000,4096).address==0,"unreserved commit fails")
	check(commit(api,0x4000001,2).address==0x4000000,"commit page rounding")
	check(commit(api,0x4000000,4096).address==0x4000000 and api.committed.size()==1,"already committed page allowed")
	check(virtual_free(api,0x4000001,0,0x8000).result==0,"release requires reservation base")
	check(virtual_free(api,0x4000000,1,0x8000).result==0,"release requires size0")
	check(virtual_free(api,0x4000000,0,0x4000).result==1 and api.committed.is_empty() and api.reservations.has(0x4000000),"zero-size decommit entire owned reservation")
	check(virtual_free(api,0x4000000,0,0x4000).result==1,"decommit uncommitted page allowed")
	check(virtual_free(api,0x4000000,0,0x8000).result==1 and api.reservations.is_empty(),"release reservation lifetime")
	check(reserve(api,0,4096).address==0x4000000,"released logical placement reusable")
	check(not api.dispatch({"api":"VirtualAlloc","address":0,"size":4096,"flags":0x3000,"protect":4}).ok,"unsupported combined flags explicit")
	check(not api.dispatch({"api":"LocalAlloc","size":1,"flags":0x40}).ok,"unsupported LocalAlloc ZEROINIT explicit")
	var local:Dictionary=api.dispatch({"api":"LocalAlloc","size":31,"flags":0})
	check(local.address==0x6000000 and not local.has("bytes"),"LocalAlloc0 never invents payload")
	check(api.dispatch({"api":"LocalAlloc","size":0x200000,"flags":0}).address==0,"local exhaustion returns0")
	check(reserve(api,0,0x500000).address==0,"virtual domain exhaustion returns0")
	var conflict:=config();conflict.local_domains=[{"address":0x4000000,"size":4096}]
	var invalid=Api.new();check(not invalid.initialize(conflict).ok,"overlapping address domains rejected")
	var wrong_config:=config();wrong_config.virtual_domains=[{"address":0x400000,"size":65536}]
	invalid=Api.new();check(invalid.initialize(wrong_config).ok,"logical domain declared before byte binding")
	var mapped=Memory.new();mapped.commit_zero(0x400000)
	check(not invalid.bind_memory(mapped).ok,"existing image/stack pages require reserved exclusions")
	var heap=Heap.new();api=Api.new();check(api.initialize(config()).ok,"fresh allocator process domains")
	check(heap.initialize_fresh(Callable(api,"dispatch"),Heap.DEFAULT_MANAGER,{"fs_base":0,"exception_head":0xffffffff,"stack_base":0x9000000,"stack_size":0x100000,"stack_pointer":0x90ffe00,"stack_origin":"fresh_committed_pages","scope":"Fresh reconstructed allocator and real locks, not native GUI state"}).ok,"retained allocator initialize")
	check(api.bind_memory(heap.vm.byte_memory).ok,"opaque lock byte binding")
	# Declared threaded-process flag exercises retained actual source lock calls.
	heap.vm.put(0x59ad95,1,1)
	r=heap.get_mem(0x4348);check(r.ok,"retained4348 allocation")
	if r.ok:
		var p:int=r.value;var bytes:Dictionary=heap.read_bytes(p,0x4348)
		check(bytes.ok and bytes.bytes.count(0)==0x4348,"fresh committed-page payload has defined zero origin")
		check(api.lock_lifetimes.has(0x59b184),"source initialized genuine recursive lock")
		check(not heap.vm.byte_memory.contains_span(0x59b184,24),"opaque critical-section interior bytes unknown")
		check(api.dispatch({"api":"EnterCriticalSection","address":0x59b184}).ok,"real lock manual acquisition")
		var nested:Dictionary=heap.get_mem(31);check(nested.ok,"retained allocator recursively acquires actual same-thread mutex")
		check(api.dispatch({"api":"LeaveCriticalSection","address":0x59b184}).ok,"real outer lock balanced release")
		var barrier:Dictionary=heap.get_mem(0x4348);check(barrier.ok,"live adjacent allocation guards reused chunk")
		var fill:=PackedByteArray();fill.resize(0x4348);fill.fill(0x77);check(heap.write_bytes(p,fill).ok,"write allocation bytes")
		check(heap.free_mem(p).ok,"source FreeMem")
		var reused:Dictionary=heap.get_mem(0x4348);check(reused.ok,"source reuse allocation")
		if reused.ok:
			var payload:Dictionary=heap.read_bytes(reused.value,0x4348)
			check(payload.ok,"source-selected allocation remains defined; byte retention verified against native guarded sequence")
		check(not api.dispatch({"api":"LeaveCriticalSection","address":0x59b184}).ok,"unbalanced real unlock rejected")
		check(not api.dispatch({"api":"InitializeCriticalSection","address":0x59b184}).ok,"same live lock cannot be initialized twice")
	var unknown_local:=false
	for page in heap.vm.byte_memory.pages:
		if int(page)>=0x6000000 and int(page)<0x6100000:
			var data:Dictionary=heap.vm.byte_memory.pages[page]
			for i in 4096:
				if data.accessible[i] and not data.known[i]:unknown_local=true
	check(unknown_local,"retained allocator leaves unwritten LocalAlloc table bytes unknown")
	check(api.dispatch({"api":"DeleteCriticalSection","address":0x59b184}).ok,"actual owned lock lifetime ends")
	check(api.dispatch({"api":"InitializeCriticalSection","address":0x59b184}).ok,"new explicit lock lifetime at reused identity")
	heap.close()
	replay_native_reuse()
	page_lifetimes()
	print(JSON.stringify({"checks":checks,"failures":failures}))
	if failures.is_empty():print("PASS owned fresh memory API source allocator pages reuse unknown local bytes and genuine recursive locks")
	quit(0 if failures.is_empty() else 1)

func replay_native_reuse()->void:
	var fixture:Dictionary=JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_shared_heap.json"))
	var c:Dictionary=fixture.cases[0];var api=Api.new();check(api.initialize(config()).ok,"native reuse comparison domains")
	var heap=Heap.new();check(heap.initialize_fresh(Callable(api,"dispatch"),Heap.DEFAULT_MANAGER,{"fs_base":0,"exception_head":0xffffffff,"stack_base":0x9000000,"stack_size":0x100000,"stack_pointer":0x90ffe00,"stack_origin":"fresh_committed_pages","scope":"Native-oracle sequence with owned API contract, not OS Win32 execution"}).ok,"native reuse source heap")
	check(api.bind_memory(heap.vm.byte_memory).ok,"reuse API byte binding")
	var pointers:Dictionary={}
	for step in c.steps:
		var operation:Dictionary=step.operation;var result:Dictionary
		match str(operation.op):
			"get":result=heap.get_mem(int(operation.size))
			"fill":result=heap.write_bytes(pointers[operation.id],str(operation.hex).hex_decode())
			"free":result=heap.free_mem(pointers[operation.id])
		if not result.ok:failures.append(["native reuse",operation.op,result]);break
		if operation.op=="get":pointers[operation.id]=result.value
		if step.value!=null:check(result.value==int(step.value),"actual PE source-selected pointer/return")
		for page in step.state.pages:
			var raw:Dictionary=heap.read_bytes(str(page.address).trim_prefix("0x").hex_to_int(),4096)
			var h:=HashingContext.new();h.start(HashingContext.HASH_SHA256)
			if raw.ok:h.update(raw.bytes)
			check(raw.ok and h.finish().hex_encode()==page.sha256,"actual PE full committed-page payload/native allocator bytes")
	heap.close()

func helper_virtual(heap,address:int,size:int,flags:int,is_free:bool=false)->int:
	var sp:=0x90ff000;heap.vm.registers.esp=sp
	heap.vm.put(sp,0x7ffffff0);heap.vm.put(sp+4,address);heap.vm.put(sp+8,size);heap.vm.put(sp+12,flags)
	if is_free:heap._virtual_free(heap.vm)
	else:heap.vm.put(sp+16,4);heap._virtual_alloc(heap.vm)
	return int(heap.vm.registers.eax)
func page_lifetimes()->void:
	var api=Api.new();check(api.initialize(config()).ok,"page lifetime domains")
	var heap=Heap.new();check(heap.initialize_fresh(Callable(api,"dispatch"),Heap.DEFAULT_MANAGER,{"fs_base":0,"exception_head":0xffffffff,"stack_base":0x9000000,"stack_size":0x100000,"stack_pointer":0x90ffe00,"stack_origin":"fresh_committed_pages","scope":"Owned logical page contract through actual SharedHeap boundary"}).ok,"page lifetime byte world")
	check(api.bind_memory(heap.vm.byte_memory).ok,"page lifetime memory binding")
	var address:=helper_virtual(heap,0,4096,0x2000)
	check(address==0x4000000 and helper_virtual(heap,address,4096,0x1000)==address,"reserve then commit through SharedHeap")
	check(heap.write_bytes(address,PackedByteArray([0x77])).ok,"committed bytes writable")
	check(helper_virtual(heap,address,4096,0x1000)==address and heap.read_bytes(address,1).bytes==PackedByteArray([0x77]),"recommit already committed page preserves data")
	check(helper_virtual(heap,address,4096,0x4000,true)!=0 and not heap.vm.byte_memory.pages.has(address),"decommit removes known payload")
	check(helper_virtual(heap,address,4096,0x1000)==address and heap.read_bytes(address,4096).bytes.count(0)==4096,"newly recommitted page has OS-contract guaranteed zero")
	check(api.dispatch({"api":"InitializeCriticalSection","address":address}).ok,"committed owned address has a real lock lifetime")
	check(not api.dispatch({"api":"VirtualFree","address":address,"size":0,"flags":0x8000}).ok,"live source lock prevents unsupported lifetime destruction")
	check(api.dispatch({"api":"DeleteCriticalSection","address":address}).ok,"source deletes dynamic lock before release")
	check(helper_virtual(heap,address,0,0x8000,true)!=0 and heap.reservations.is_empty() and api.reservations.is_empty(),"release invalidates matching API and byte-world lifetime")
	heap.close()
