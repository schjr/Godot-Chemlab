extends SceneTree
const View=preload("res://scripts/original/original_heap_vessel_view.gd")
const Profile=preload("res://scripts/original/original_runtime_profile.gd")
const Quantities=preload("res://scripts/original/original_quantities.gd")
const Memory=preload("res://scripts/original/original_heap_memory.gd")
class ScopedHeap:
	var initialized:=true
	var vm:Dictionary={"byte_memory":Memory.new()}
	func read_bytes(address:int,size:int)->Dictionary:
		var bytes:PackedByteArray=vm.byte_memory.read(address,size)
		return {"ok":bytes.size()==size,"bytes":bytes}
var failures:Array=[]
func check(ok:bool,message:String)->void:
	if not ok:failures.append(message)
func _initialize()->void:
	var heap=ScopedHeap.new();var pointer:=0x4001008
	heap.vm.byte_memory.map_unknown(pointer,0x4348)
	var view=View.new()
	check(not view.bind(heap,pointer,{}).ok,"Unscoped attachment rejected")
	check(view.bind(heap,pointer,{"source_sha256":View.SOURCE_SHA,"pointer":pointer,"request_size":0x4348,"scope":"Explicit byte-mask adapter test, not live allocation"}).ok,"Scoped attachment")
	var bits:="0100000000000080" # negative subnormal preserved without interpretation
	heap.vm.byte_memory.write(pointer+0x3cd8+63*8,bits.hex_decode())
	heap.vm.byte_memory.write(pointer+0x8d8,PackedFloat64Array([0.1]).to_byte_array())
	for offset in Profile.SCALAR_FIELDS:
		check(View.SCALARS.get(Profile.SCALAR_FIELDS[offset],-1)==str(offset).trim_prefix("0x").hex_to_int(),"RuntimeProfile scalar mapping "+str(offset))
	check(not View.SCALARS.has("native_gas_volume") and not View.SCALARS.has("native_liquid_volume"),"Particle counters are not physical volume aliases")
	check(View.SCALARS.native_solid_volume==Quantities.NATIVE_OFFSETS.native_solid_volume,"Solid volume remains source physical4338")
	heap.vm.byte_memory.write(pointer+0x3cc8,PackedFloat64Array([3.0]).to_byte_array())
	heap.vm.byte_memory.write(pointer+0x4318,PackedFloat64Array([7.0]).to_byte_array())
	var result:Dictionary=view.snapshot(["NaOH(aq)"])
	check(result.ok and result.backing.arrays.solid_3cd8[63]==bits,"Inactive subnormal raw bits retained")
	check(result.backing.arrays.contents[0]==PackedFloat64Array([0.1]).to_byte_array().hex_encode(),"Known source cell retained")
	check(result.backing.arrays.contents[1]==null and result.scalar_raw_hex.gas_3cc0==null,"Unwritten values remain unknown")
	check(result.scalar_raw_hex.native_particle_3cc8==PackedFloat64Array([3.0]).to_byte_array().hex_encode(),"Gas particle counter mapped at3CC8")
	check(result.scalar_raw_hex.solid_4318==PackedFloat64Array([7.0]).to_byte_array().hex_encode(),"Solid particle counter mapped at4318")
	check(heap.vm.byte_memory.error.is_empty(),"Observation never reads unknown cells")
	check(result.backing.names==["NaOH(aq)"],"Names follow explicit source row order")
	print(JSON.stringify({"failures":failures}))
	if failures.is_empty():print("PASS original heap vessel view preserves scoped raw bytes and unknown cells")
	quit(0 if failures.is_empty() else 1)
