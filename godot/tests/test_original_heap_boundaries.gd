extends SceneTree
const Memory=preload("res://scripts/original/original_heap_memory.gd")
const Heap=preload("res://scripts/original/original_shared_heap.gd")
var failures:Array=[]
var local_next:=0x6000000
func check(ok:bool,message:String)->void:
	if not ok:failures.append(message)
func boundary(request:Dictionary)->Dictionary:
	match str(request.api):
		"LocalAlloc":
			var address:int=local_next;local_next=(address+int(request.size)+15)&~15
			return {"ok":true,"address":address}
		"VirtualAlloc":return {"ok":true,"address":0x4000000 if int(request.address)==0 else int(request.address)}
		"VirtualFree":return {"ok":true,"result":1}
		"InitializeCriticalSection","EnterCriticalSection","LeaveCriticalSection":return {"ok":true,"result":0}
	return {"ok":false,"error":"Unsupported boundary"}
func _initialize()->void:
	var memory=Memory.new();memory.map_unknown(0x1000,16)
	check(not memory.contains_span(0x1000,1),"Unknown allocation is not fabricated zero")
	check(memory.read(0x1000,1).is_empty() and memory.error.contains("Unobserved"),"Unknown read fails explicitly")
	memory.error="";memory.write(0x1004,PackedByteArray([0xa5,0]))
	check(memory.read(0x1004,2)==PackedByteArray([0xa5,0]),"Only source-written cells are known")
	var restored=Memory.new();check(restored.from_state(memory.to_state()).ok,"Validity state restoration")
	check(restored.contains_span(0x1004,2) and not restored.contains_span(0x1000,1),"Checkpoint retains unknown bytes")
	memory.commit_zero(0x2000);check(memory.read(0x2000,4096).count(0)==4096,"Fresh committed page has defined zero origin")
	memory.write(0x2000,PackedByteArray([0x77]));memory.decommit(0x2000)
	check(not memory.contains_span(0x2000,1),"Decommit removes old payload")
	memory.commit_zero(0x2000);check(memory.read(0x2000,1)==PackedByteArray([0]),"New committed page does not retain decommitted bytes")
	var heap=Heap.new()
	var initialized:Dictionary=heap.initialize_fresh(Callable(self,"boundary"),Heap.DEFAULT_MANAGER,{"fs_base":0,"exception_head":0xffffffff,"stack_base":0x9000000,"stack_size":0x100000,"stack_pointer":0x90ffe00,"stack_origin":"fresh_committed_pages","scope":"Explicit unknown LocalAlloc boundary test, not GUI startup"})
	check(initialized.ok,"Kernel initializes with explicit unknown LocalAlloc payload")
	if initialized.ok:
		var result:Dictionary=heap.get_mem(0x4348)
		check(result.ok and result.value==0x4000004,"Original allocator writes its own required list cells")
		var saw_unknown:=false
		for address in heap.vm.byte_memory.pages:
			if int(address)>=0x6000000:
				var page:Dictionary=heap.vm.byte_memory.pages[address]
				for index in 4096:
					if page.accessible[index]==1 and page.known[index]==0:saw_unknown=true
		check(saw_unknown,"Unwritten LocalAlloc bytes remain unknown after allocator execution")
	heap.close()
	print(JSON.stringify({"failures":failures}))
	if failures.is_empty():print("PASS original heap explicit page origins and unknown-byte boundaries")
	quit(0 if failures.is_empty() else 1)
