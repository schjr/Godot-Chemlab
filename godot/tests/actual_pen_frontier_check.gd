extends SceneTree
## Actual graph prefix only; every primitive request is refused.
const Pen=preload("res://scripts/original/original_pen.gd")
const CAPTURE_SHA:="55efb5a1c8cba1556689dee25ca6bcc984b3740e80e47866fd100e9ef5ce7787"
const FIXTURE_SHA:="a90c7f6013967d13e84f9188a9e36a3b62893989d6b672d71c61a4a7182cf334"
var failures:Array=[]
var attempts:Array=[]
func check(ok:bool,label:String)->void:
	if not ok:failures.append(label)
func refuse(request:Dictionary)->Dictionary:
	attempts.append(request.duplicate(true))
	return {"ok":false,"error":"Actual captured primitive unavailable: "+str(request.api)}
func _initialize()->void:
	var path:="res://tests/fixtures/actual_pen_frontier.json"
	if not FileAccess.file_exists(path):
		print("Actual pen fixture unavailable; run pinned capture builder first")
		quit(1);return
	var hash:=HashingContext.new();hash.start(HashingContext.HASH_SHA256);hash.update(FileAccess.get_file_as_bytes(path))
	check(hash.finish().hex_encode()==FIXTURE_SHA,"Actual original-PE fixture byte identity")
	var fixture:Dictionary=JSON.parse_string(FileAccess.get_file_as_string(path))
	check(fixture.get("format","")=="chemlab-actual-pen-frontier-v1","Fixture format")
	check(fixture.get("capture_sha256","")==CAPTURE_SHA,"Actual capture identity")
	check(not fixture.get("completed_setter",true) and not fixture.get("native_vcl_verified",true) and not fixture.get("target_handles_usable",true),"Diagnostic frontier cannot attest completed/live operation")
	var pen=Pen.new()
	var initialized:Dictionary=pen.initialize(fixture.world,Callable(self,"refuse"))
	check(initialized.ok,"Actual raw graph initialization: "+str(initialized.get("error","")))
	if initialized.ok:
		var result:Dictionary=pen.set_color(int(fixture.operation.pen),int(fixture.operation.color))
		check(not result.ok and str(result.error).contains("Actual captured primitive unavailable"),"Setter must stop at unprovided actual primitive")
		var expected:Dictionary=fixture.frontier.duplicate(true)
		for key in ["address","source_pc"]:expected[key]=int(expected[key])
		check(attempts==[expected],"Native and port first primitive/address/instruction agree")
		check(pen.events.is_empty(),"No fabricated successful primitive")
		# Preserve the refusal result above, then clear only its diagnostic error
		# for inspection. No instruction execution resumes after this frontier.
		pen.vm.error=""
		for segment in fixture.after_segments:
			var bytes:Dictionary=pen.read_bytes(int(segment.address),str(segment.hex).hex_decode().size())
			check(bytes.ok and bytes.get("bytes",PackedByteArray()).hex_encode()==segment.hex,"Native raw prefix graph bytes at "+str(segment.address))
	pen.close()
	print(JSON.stringify({"failures":failures,"operation":fixture.operation,"frontier":attempts,"completed_setter":false,"native_vcl_verified":false}))
	if failures.is_empty():print("VALIDATION: actual captured pen prefix matches native; unprovided lock remains explicit")
	var require_complete:bool="--require-complete-setter" in OS.get_cmdline_user_args()
	quit(0 if failures.is_empty() and not require_complete else 1)
