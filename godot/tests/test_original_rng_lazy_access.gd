extends SceneTree
const Vm=preload("res://scripts/original/original_particle_vm.gd")
const Frame=preload("res://scripts/original/original_particle_frame.gd")
var failures:Array=[]
func check(ok:bool,message:String)->void:
	if not ok:failures.append(message)
func call_bound(state:Dictionary,bound:int)->Dictionary:
	var vm=Vm.new();vm.rng=state;vm.put(int(vm.registers.esp),bound)
	var result:Dictionary=vm.execute({"instructions":[]},0x4028ec)
	result.value=vm.registers.eax;return result
func _initialize()->void:
	var absent:Dictionary={};var zero:=call_bound(absent,0)
	check(zero.ok and zero.value==0 and absent.is_empty(),"Zero-bound source helper never accesses or fabricates RNG")
	var missing:=call_bound(absent,5)
	check(not missing.ok and str(missing.error).contains("thread-state") and absent.is_empty(),"First actual random access fails explicitly without seed")
	var unknown:Dictionary={"low":null,"high":null}
	check(call_bound(unknown,0).ok,"Unused unknown cells can remain unknown")
	check(not call_bound(unknown,5).ok and unknown.low==null and unknown.high==null,"Present-but-unobserved cells cannot convert to zero seed")
	for invalid in [-1,4294967296,0.5,NAN]:
		check(not call_bound({"low":invalid,"high":0},5).ok,"Malformed observed RNG DWORD rejected")
	var source:Dictionary={"low":0x12345678,"high":0x9abcdef0}
	var generated:=call_bound(source,5)
	check(generated.ok and generated.value==2 and source.low==0xb72e76d9 and source.high==0x2fc42b6f,"Actual native positive-bound reference retained")
	var vessel:Dictionary={"label":"Explicit frame test","type_id":102,"position":[0,0],"native_fields":{"0x18":"0"},"native_bitmap_width":10,"native_bitmap_height":10,"native_liquid_height":0.0,"native_liquid_color":0xffffff,"contents":{},"solid_3cd8":{},"solid_3ff8":{},"solid_4318":0.0,"gas_3cc0":0.0,"native_particle_3cc8":0.0}
	var scene:=Frame.create_scene([vessel]);var pixels:Array=[];pixels.resize(100);pixels.fill(0)
	scene.pools[0].solid.primary_words=pixels.duplicate();scene.pools[0].solid.retained_words=pixels.duplicate()
	var frame=Frame.new();var untouched:Dictionary={}
	var result:=frame.step([vessel],{},[],scene,{"run_flag":2,"pause_flag":1},untouched,Callable(),Callable())
	check(result.ok and untouched.is_empty(),"Full retained frame branch preserves unaccessed RNG")
	if frame.vm!=null:frame.vm.helpers.clear()
	print(JSON.stringify({"failures":failures}))
	if failures.is_empty():print("PASS original particle RNG remains unobserved until actual source access")
	quit(0 if failures.is_empty() else 1)
