extends SceneTree
## Fresh reconstructed lock execution over actual observed non-lock graph bytes.
## This is not execution of captured target locks or native Win32 attestation.
const Pen=preload("res://scripts/original/original_pen.gd")
const Locks=preload("res://scripts/original/original_owned_recursive_locks.gd")
const FIXTURE_SHA:="f75bb4c52ff082a9bccc0f5d2da09bd1af2d570d14bd43d2863e61fa888924f4"
var locks=Locks.new()
var scope:="actual-graph-diagnostic-explicit-fresh-lifetime-1"
var trace:Array=[]
var failures:Array=[]
var checks:=0
func check(ok:bool,label:String)->void:
	checks+=1
	if not ok:failures.append(label)
func primitive(request:Dictionary)->Dictionary:
	trace.append(request.duplicate(true))
	return locks.dispatch(request,scope)
func _initialize()->void:
	var path:="res://tests/fixtures/actual_pen_owned_locks.json"
	var raw:=FileAccess.get_file_as_bytes(path)
	var hash:=HashingContext.new();hash.start(HashingContext.HASH_SHA256);hash.update(raw)
	check(hash.finish().hex_encode()==FIXTURE_SHA,"Original PE with genuine host-lock reference fixture byte identity")
	var fixture:Dictionary=JSON.parse_string(raw.get_string_from_utf8())
	check(fixture.get("format","")=="chemlab-actual-pen-fresh-owned-locks-v1","Fresh reconstruction scope")
	check(fixture.get("capture_sha256","")=="55efb5a1c8cba1556689dee25ca6bcc984b3740e80e47866fd100e9ef5ce7787","Actual graph input identity")
	check(not fixture.native_win32_verified and not fixture.native_vcl_verified and not fixture.target_handles_usable,"No live Windows/target-handle attestation")
	for identity in fixture.lock_identities:check(locks.create(scope,int(identity)).ok,"Explicit fresh lock lifetime")
	var pen=Pen.new()
	var initialized:Dictionary=pen.initialize(fixture.world,Callable(self,"primitive"))
	check(initialized.ok,"Original graph initialization")
	if initialized.ok:
		# All historical lock interiors become unknown, including overlapping
		# Canvas/registry spans; the source must not read these opaque bytes.
		for span in fixture.historical_lock_ranges:
			for offset in int(span.size):
				var at:int=int(span.address)+offset
				var page:Dictionary=pen.vm.byte_memory.pages[at&~4095]
				var known:PackedByteArray=page.known
				known[at&4095]=0;page.known=known
		var result:Dictionary=pen.set_color(int(fixture.operation.pen),int(fixture.operation.color))
		check(result.ok,"Full source setter completes using synchronous actual recursive Mutex operations: "+str(result.get("error","")))
		var expected:Array=[]
		for call in fixture.trace:
			var copy:Dictionary=call.duplicate(true)
			for key in ["address","source_pc"]:copy[key]=int(copy[key])
			expected.append(copy)
		check(trace==expected,"Eight source-ordered lock calls match original PE with genuine fresh host locks")
		check(pen.events==trace,"No allocation/event/GDI or omitted primitive")
		for segment in fixture.after_nonlock_segments:
			var actual:Dictionary=pen.read_bytes(int(segment.address),str(segment.hex).hex_decode().size())
			check(actual.ok and actual.bytes.hex_encode()==segment.hex,"All observed non-lock prefix/final graph bytes at "+str(segment.address))
		for span in fixture.historical_lock_ranges:check(not pen.vm.contains_span(int(span.address),int(span.size)),"Historical opaque lock storage never filled or adopted")
	pen.close()
	for identity in fixture.lock_identities:
		var state:Dictionary=locks.state(scope,int(identity))
		check(state.depth==0 and state.pending==0,"Original finally balanced all actual owned mutexes")
		check(locks.destroy(scope,int(identity)).ok,"Balanced explicit lifetime destruction")
	print(JSON.stringify({"checks":checks,"failures":failures,"source_calls":trace.size(),"completed_reconstructed_setter":true,"native_win32_verified":false,"native_vcl_verified":false}))
	if failures.is_empty():print("PASS original PE actual non-lock graph setter parity with real fresh Godot recursive mutexes")
	quit(0 if failures.is_empty() else 1)
