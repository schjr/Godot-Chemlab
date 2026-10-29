extends SceneTree
const Frame=preload("res://scripts/original/original_particle_frame.gd")
const Vm=preload("res://scripts/original/original_particle_vm.gd")
var failures:Array=[]
var checks:=0
func check(ok:bool,label:String)->void:
	checks+=1
	if not ok:failures.append(label)
func run_frame(context:Dictionary)->Dictionary:
	var frame=Frame.new()
	var result:=frame.step([],{},[],{"pools":[]},context,{},Callable(),Callable())
	return {"frame":frame,"result":result}
func _initialize()->void:
	var original:=PackedByteArray();original.resize(0x10000);original.fill(0x5a)
	var context:Dictionary={"run_flag":0,"pause_flag":0,"owned_stack_bytes":original}
	var first:=run_frame(context);var result:Dictionary=first.result;var vm:Vm=first.frame.vm
	check(result.ok and result.owned_stack_bytes.size()==0x10000,"owned stack complete input/output protocol")
	check(result.owned_stack_bytes[0x1234]==0x5a and result.owned_stack_bytes[0xffff]==0x5a,"untouched actual prior stack bytes preserved")
	check(result.owned_stack_bytes.decode_u32(0xefc8)==0,"source handler local zero write retained in returned stack")
	check(result.owned_stack_bytes.decode_u32(0xefa8)==0x1000000,"source form-pointer local write retained")
	check(original[0xefc8]==0x5a,"input stack buffer not mutated")
	check(not vm.has_byte(Vm.STACK-1) and not vm.has_byte(Vm.STACK+0x10000),"stack binding exposes exact64k span only")
	context.owned_stack_bytes=result.owned_stack_bytes
	var second:=run_frame(context)
	check(second.result.ok and second.result.owned_stack_bytes==result.owned_stack_bytes,"returned source stack reused without restoring old sentinel locals")
	for malformed in [PackedByteArray(),PackedByteArray([0]),[],"0000",null]:
		var attempt:=run_frame({"run_flag":0,"pause_flag":0,"owned_stack_bytes":malformed})
		check(not attempt.result.ok and attempt.frame.vm==null,"malformed owned stack rejected before VM setup")
	var absent:=run_frame({"run_flag":0,"pause_flag":0})
	check(absent.result.ok and not absent.result.has("owned_stack_bytes") and not absent.frame.vm.has_byte(Vm.STACK+0x1234),"omitted stack preserves unknown-memory contract")
	var beaker:Dictionary={"label":"container","type_id":102,"position":[20,20],"native_fields":{"0x18":"0"},"native_bitmap_width":40,"native_bitmap_height":50,"native_liquid_height":30.0,"native_liquid_color":0xffffff,"solid_4318":0.0,"gas_3cc0":0.0,"native_particle_3cc8":0.0,"contents":{"H2O(液体)":1.0},"solid_3cd8":{},"solid_3ff8":{}}
	var frame=Frame.new();var scene:=Frame.create_scene([beaker])
	result=frame.step([beaker],{"H2O(液体)":{"color_integer":0xffffff}},[],scene,{"run_flag":1,"pause_flag":0,"owned_stack_bytes":original},{},Callable(),Callable())
	check(not result.ok and result.has("owned_stack_bytes") and result.owned_stack_bytes.size()==0x10000,"unresolved source read returns actual prior stack and completed source writes")
	check(not beaker.solid_3cd8.has("H2O(液体)"),"owned stack does not initialize unrelated unknown apparatus cells")
	frame.vm.helpers.clear()
	for record in [first,second,absent]:record.frame.vm.helpers.clear()
	print(JSON.stringify({"checks":checks,"failures":failures}))
	if failures.is_empty():print("PASS owned particle stack preserves actual supplied prior bytes and source writes without unknown fallbacks")
	quit(0 if failures.is_empty() else 1)
