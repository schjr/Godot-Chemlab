extends SceneTree
## Scoped sentinel blobs test preservation/relocation, not a Windows capture.
const ObjectBytes=preload("res://scripts/original/original_observed_particle_object.gd")
const Frame=preload("res://scripts/original/original_particle_frame.gd")
var failures:Array=[]
func check(ok:bool,message:String)->void:
	if not ok:failures.append(message)
func bitmap(pointer:int,rows_base:int)->Dictionary:
	var words:Array=[];words.resize(100);words.fill(0x112233)
	var rows:Array=[]
	for row in 10:rows.append(rows_base+row*40)
	var raw:=PackedByteArray();raw.resize(words.size()*4)
	for index in words.size():raw.encode_u32(index*4,int(words[index]))
	return {"bitmap_format":32,"pixels_sha256":ObjectBytes.hash_bytes(raw),"source_sha256":ObjectBytes.SOURCE_SHA,"scope":"Explicit source-address scanline backing test","original_pointer":pointer,"width":10,"height":10,"words":words,"row_addresses":rows}
func descriptor(raw:PackedByteArray,address:int,bindings:Dictionary)->Dictionary:
	return {"source_sha256":ObjectBytes.SOURCE_SHA,"scope":"Complete diagnostic object bytes; no process/default inference","original_address":address,"byte_size":raw.size(),"raw_hex":raw.hex_encode(),"sha256":ObjectBytes.hash_bytes(raw),"bitmap_bindings":bindings}
func _initialize()->void:
	var vessel:Dictionary={"label":"Raw frame test","type_id":102,"position":[0,0],"native_fields":{"0x18":"0"},"native_bitmap_width":10,"native_bitmap_height":10,"native_liquid_height":0.0,"native_liquid_color":0xffffff,"contents":{},"solid_3cd8":{},"solid_3ff8":{},"solid_4318":0.0,"gas_3cc0":0.0,"native_particle_3cc8":0.0}
	var scene:=Frame.create_scene([vessel])
	var solid:=PackedByteArray();solid.resize(0x3468c)
	solid.encode_u32(0,0x5674e4);solid.encode_u32(0x100,0xa5b6c7d8)
	solid.encode_u32(0x34678,0x7000000);solid.encode_u32(0x3467c,0x7001000)
	solid.encode_u32(0x32d60,10);solid.encode_u32(0x32d64,10)
	var bindings:Dictionary={"0x34678":bitmap(0x7000000,0x6000000),"0x3467c":bitmap(0x7001000,0x6010000)}
	for row in 10:
		solid.encode_u32(0x32d68+row*4,0x6000000+row*40);solid.encode_u32(0x339e8+row*4,0x6010000+row*40)
	scene.pools[0].solid.native_raw_object=descriptor(solid,0x7100000,bindings)
	var bubble:=PackedByteArray();bubble.resize(0xfc20);bubble.encode_u32(0x100,0x10203040);bubble.encode_u32(0x7ef4,1)
	scene.pools[0].bubbles.native_raw_object=descriptor(bubble,0x7200000,{})
	var truncated:Dictionary=scene.pools[0].solid.native_raw_object.duplicate(true);truncated.raw_hex="00"
	check(not ObjectBytes.validate(truncated,true).ok,"Incomplete original raw object rejected")
	var wrong_hash:Dictionary=scene.pools[0].solid.native_raw_object.duplicate(true);wrong_hash.sha256="bad"
	check(not ObjectBytes.validate(wrong_hash,true).ok,"Raw object hash mismatch rejected")
	var missing_rows:Dictionary=scene.pools[0].solid.native_raw_object.duplicate(true);missing_rows.bitmap_bindings["0x34678"].erase("row_addresses")
	check(not ObjectBytes.validate(missing_rows,true).ok,"Scanline pointer target is never inferred")
	var frame=Frame.new();var rng:Dictionary={}
	var result:=frame.step([vessel],{},[],scene,{"run_flag":2,"pause_flag":1},rng,Callable(),Callable())
	check(result.ok,"Actual retained source frame accepts scoped raw no-emission objects")
	var after:=str(scene.pools[0].solid.native_raw_object.raw_hex).hex_decode()
	check(after.size()==0x3468c and after.decode_u32(0x100)==0xa5b6c7d8,"Inactive solid record bytes remain exact")
	check(after.decode_u32(0x34678)==0x7000000 and after.decode_u32(0x3467c)==0x7001000,"Hosted bitmap addresses never replace source snapshot identity")
	check(after.decode_u32(0x32d68)==0x6000000,"Uninterpreted raw scanline cache retained")
	check(str(scene.pools[0].bubbles.native_raw_object.raw_hex).hex_decode().decode_u32(0x100)==0x10203040,"Inactive bubble bytes retained")
	check(rng.is_empty(),"Unaccessed observed TLS remains absent")
	check(scene.pools[0].solid.native_raw_object.sha256==ObjectBytes.hash_bytes(after),"Source-updated raw snapshot hash retained")
	if frame.vm!=null:frame.vm.helpers.clear()
	# A source no-operation may retain unavailable DDBs without adoption
	# consulting them. Native pointer identities must not alias hosted objects.
	var absent_scene:=scene.duplicate(true)
	var absent_raw:=str(absent_scene.pools[0].solid.native_raw_object.raw_hex).hex_decode()
	absent_raw.encode_u32(0x34678,0x1000000);absent_raw.encode_u32(0x3467c,0x1000010)
	absent_scene.pools[0].solid.native_raw_object=descriptor(absent_raw,0x7100000,{})
	var unavailable=Frame.new();var no_access:=unavailable.step([vessel],{},[],absent_scene,{"run_flag":2,"pause_flag":1},{},Callable(),Callable())
	check(no_access.ok,"Unaccessed/unavailable solid bitmap binding does not fail adoption")
	check(absent_scene.pools[0].solid.native_raw_object.bitmap_bindings.is_empty(),"Unavailable DDBs remain explicitly unbound")
	check(not unavailable.bitmap_meta.has(0x1000000) and not unavailable.vm.contains_span(0x1000000,4),"Unbound original pointer cannot alias hosted apparatus/bitmap bytes")
	check(unavailable.vm.read(0x1000000,4).is_empty() and not unavailable.vm.error.is_empty(),"Actual unbound pointer read fails explicitly")
	unavailable.vm.error="";unavailable.vm.registers.eax=0x1000000
	unavailable._bitmap_canvas(unavailable.vm)
	check(unavailable.vm.error.contains("unobserved"),"Actual missing bitmap callback rejects without Dictionary error")
	unavailable.vm.helpers.clear()
	print(JSON.stringify({"failures":failures,"native_result":result}))
	if failures.is_empty():print("PASS scoped original particle object bytes and exact bitmap pointer backing")
	quit(0 if failures.is_empty() else 1)
