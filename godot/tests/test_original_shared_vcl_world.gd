extends SceneTree
const Api=preload("res://scripts/original/original_owned_memory_api.gd")
const World=preload("res://scripts/original/original_vcl_memory_world.gd")
const FIXTURE_SHA:="56e4abb5d568a8f860728256ea7bd7b8b6c9d2d19e9cb0c6d2869b82ed0748ff"
var failures:Array=[]
var checks:=0
var os_events:Array=[]
var event_index:=0
var malformed_reply:Dictionary={}
var malformed_calls:=0
func malformed_graphics(_request:Dictionary)->Dictionary:
	malformed_calls+=1
	return malformed_reply
func check(ok:bool,label:String)->void:
	checks+=1
	if not ok:failures.append(label)
func os_boundary(request:Dictionary)->Dictionary:
	return {"ok":false,"error":"Explicit shared-world graphics/other boundary: "+str(request.api)}
func digest(raw:PackedByteArray)->String:
	var hash:=HashingContext.new();hash.start(HashingContext.HASH_SHA256);hash.update(raw);return hash.finish().hex_encode()
func nonlock(world,address:int,size:int,opaque:Array)->PackedByteArray:
	var bytes:=PackedByteArray()
	for offset in size:
		var at:int=address+offset;var skip:=false
		for lock in opaque:
			if int(lock)<=at and at<int(lock)+24:skip=true;break
		if not skip:bytes.append(world.vm.integer(at,1))
	return bytes
func _initialize()->void:
	var raw:=FileAccess.get_file_as_bytes("res://tests/fixtures/original_shared_vcl_world.json")
	check(digest(raw)==FIXTURE_SHA,"Pinned original PE shared-world fixture")
	var fixture:Dictionary=JSON.parse_string(raw.get_string_from_utf8())
	os_events=fixture.steps[-1].state.events
	# Reject input that would mutate code, RTL manager globals or another byte
	# width before allocating any shared object or initializing any lock.
	for bad in [{"segments":[{"address":0x4e3e50,"hex":"90"}]},{"segments":[{"address":0x574b28,"hex":"00"}]},{"globals":{"0x575604":0x5306b0}},{"globals":{"0x574b54":256}},{"globals":{"0x574b54":0.5}}]:
		var invalid:Dictionary=fixture.world.duplicate(true)
		for key in bad:invalid[key]=bad[key]
		var rejected=World.new();check(not rejected.initialize_fresh(invalid,Callable(self,"os_boundary")).ok,"Unsafe or invalid initial runtime input rejected");rejected.close()
	var absent:Dictionary=fixture.world.duplicate(true);absent.segments=[]
	var guarded=World.new();check(guarded.initialize_fresh(absent,Callable(self,"os_boundary")).ok,"Unused runtime metadata may remain absent")
	check(not guarded.vm.contains_span(0x574b28,44) and not guarded.vm.contains_span(0x574b54,1),"PE literals cannot supply missing runtime font descriptor or bitmap policy")
	var missing:Dictionary=guarded.read_bytes(0x574b54,1)
	check(not missing.ok and str(missing.error).contains("Unobserved"),"Actual absent-policy read fails explicitly")
	guarded.close()
	var owned=Api.new()
	check(owned.initialize({"scope":"shared VCL reconstructed process","page_size":4096,"allocation_granularity":65536,"local_alignment":16,"virtual_domains":[{"address":0x4000000,"size":0x400000}],"local_domains":[{"address":0x6000000,"size":0x100000}],"exclusions":[],"lock_domains":[{"address":0x59b184,"size":24}]}).ok,"Fresh owned process memory API")
	var world=World.new()
	var initialized:Dictionary=world.initialize_fresh(fixture.world,Callable(self,"os_boundary"),owned)
	check(initialized.ok,"Single shared VCL world initialization: "+str(initialized.get("error","")))
	if not initialized.ok:world.close();print(JSON.stringify(failures));quit(1);return
	check(is_same(world.vm,world.heap.vm),"Same VM and same actor stack for source allocator and VCL")
	check(not world.initialize_fresh(fixture.world,Callable(self,"os_boundary"),owned).ok,"Cannot reinitialize and wipe shared graph")
	for step in fixture.steps:
		var result:Dictionary=world.execute_entry(int(step.entry),int(step.eax),int(step.edx),int(step.ecx),int(step.endpoint))
		check(result.ok,str(step.operation)+" source completes: "+str(result.get("error","")))
		if not result.ok:break
		var state:Dictionary=step.state
		check(world.vm.integer(int(fixture.world.thread.fs_base))==int(state.fs_head),"Same actor normal finally restores FS")
		check(digest(nonlock(world,0x59b170,0x78,state.opaque_locks))==state.heap_globals_sha256,"All original allocator global metadata writes")
		for address in state.registry_globals:check(world.vm.integer(str(address).hex_to_int())==int(state.registry_globals[address]),"Shared source-written registry globals remain in one memory world")
		for page in state.pages:check(digest(nonlock(world,int(page.address),4096,state.opaque_locks))==page.sha256,"Complete source heap page non-lock bytes, object bodies and node metadata")
		for block in state.local_known_segments:
			var bytes:Dictionary=world.read_bytes(int(block.address),str(block.hex).hex_decode().size())
			check(bytes.ok and bytes.bytes.hex_encode()==block.hex,"Original allocator LocalAlloc table metadata propagated")
			if bytes.ok and bytes.bytes.hex_encode()!=block.hex:
				var expected_bytes:=str(block.hex).hex_decode()
				for offset in expected_bytes.size():
					if bytes.bytes[offset]!=expected_bytes[offset]:
						print("Local first mismatch ",step.operation," address ",int(block.address)+offset," expected ",expected_bytes[offset]," actual ",bytes.bytes[offset]);break
		var trace:Array=[]
		for event in world.events:
			if str(event.api).ends_with("CriticalSection"):trace.append({"api":event.api,"address":int(event.address)})
		var expected:Array=[]
		for event in state.locks:expected.append({"api":event.api,"address":int(event.address)})
		check(trace==expected,"All source-ordered real recursive-lock calls including heap bootstrap")
		for identity in state.opaque_locks:
			check(not world.vm.contains_span(int(identity),24),"Opaque owned CS bytes remain unknown")
			check(world.locks.state(str(owned.lock_lifetimes[int(identity)]),int(identity)).depth==0,"All actor lock debts balanced after source call")
	if failures.is_empty():
		check(world.vm.integer(int(fixture.canvas)+0x10)==int(fixture.pen),"Actual constructor Pen association")
		check(world.vm.integer(int(fixture.canvas)+0x14)==int(fixture.brush),"Actual constructor Brush association")
		check(world.vm.integer(int(fixture.pen)+0x14)==int(fixture.canvas)+0x38 and world.vm.integer(int(fixture.brush)+0x14)==int(fixture.canvas)+0x38,"Pen/Brush share actual Canvas lock identity")
	check(owned.local_blocks.size()==2 and owned.reservations.size()==1 and owned.committed.size()==4,"Owned process page/local boundaries exercised")
	var unknown_local:=0
	for address in owned.local_blocks:
		for offset in int(owned.local_blocks[address]):
			if not world.vm.contains_span(int(address)+offset,1):unknown_local+=1
	check(unknown_local>0,"Unwritten LocalAlloc payload remains unknown without A5/zero default")
	check(world.vm.integer(int(fixture.bitmap)+0x24)==0,"Actual new TBitmap keeps lazy Canvas absent")
	# Direct original import-boundary cleanup: source uses stdcall argument at
	# ESP+4; this is not a claim that a complete Canvas destructor is ported.
	var lock_address:int=int(fixture.canvas)+0x38
	var old_lifetime:String=owned.lock_lifetimes[lock_address]
	var previous_events:int=world.events.size()
	var stack:int=int(world.context.stack_pointer)
	world.vm.registers.esp=stack;world.vm.put(stack,0x8000000);world.vm.put(stack+4,lock_address);world.vm.pc=0x554eb2
	world._delete_lock(world.vm)
	check(world.vm.error.is_empty(),"Valid per-generation source lock delete boundary succeeds")
	check(not owned.lock_lifetimes.has(lock_address) and world.locks.state(old_lifetime,lock_address).deleted,"Actual owned Mutex lifetime removed and tombstoned")
	check(world.events.size()==previous_events+1 and world.events[-1]=={"api":"DeleteCriticalSection","address":lock_address},"Delete goes through the common ordered primitive ledger exactly once")
	check(not owned.dispatch({"api":"EnterCriticalSection","address":lock_address}).ok,"Deleted lock cannot silently reacquire")
	check(not world.vm.contains_span(lock_address,24),"Deleted opaque lock bytes remain unknown")
	# A malformed successful reply is not a result. No source continuation or
	# fake graphics call is allowed; reset only the diagnostic stop for each case.
	world.boundary=Callable(self,"malformed_graphics")
	for reply in [{"ok":true,"error":""},{"ok":true,"result":"1"},{"ok":true,"result":0.5},{"ok":true,"result":-1},{"ok":true,"result":0x100000000},{"ok":true,"result":false}]:
		malformed_reply=reply;world.vm.error="";world.vm.registers.esp=stack;world.vm.put(stack,0x8000000);world.vm.put(stack+4,123);world.vm.pc=0x5552d8
		world._graphics(world.vm,"DeleteObject",1)
		check(not world.vm.error.is_empty() and world.vm.pc==0x5552d8,"Missing/non-DWORD graphics result stops with nonempty error before helper return")
	var calls_before:int=malformed_calls;var events_before:int=world.events.size()
	world.vm.error="Unobserved source operand before primitive"
	var refused:Dictionary=world._os({"api":"DeleteObject","handle":0})
	check(not refused.ok and refused.error==world.vm.error,"Existing operand error preserved before primitive")
	check(malformed_calls==calls_before and world.events.size()==events_before,"Operand failure causes no provider call or primitive ledger append")
	world.close()
	print(JSON.stringify({"checks":checks,"failures":failures,"native_win32_verified":false,"native_vcl_verified":false}))
	if failures.is_empty():print("PASS one original VCL/allocator memory world real constructors interleaved Pen Brush and recursive locks")
	quit(0 if failures.is_empty() else 1)
