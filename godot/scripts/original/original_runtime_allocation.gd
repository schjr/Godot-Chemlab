class_name OriginalRuntimeAllocation
extends RefCounted
## Numeric apparatus storage for this reconstructed process. The retained
## System allocator owns bytes; absent fields never become synthetic defaults.
## This process has its own allocation history, not the old Windows GUI heap.
const Heap=preload("res://scripts/original/original_shared_heap.gd")
const Api=preload("res://scripts/original/original_owned_memory_api.gd")
const View=preload("res://scripts/original/original_heap_vessel_view.gd")
const Slots=preload("res://scripts/original/original_slots.gd")
const TOKEN:="native_owned_allocation"
var heap=Heap.new()
var api=Api.new()
var allocations:Dictionary={}
var written:Dictionary={}
var serial:=0
var initialized:=false
var scope:=""
func _error(message:String)->Dictionary:return {"ok":false,"error":message}
func initialize()->Dictionary:
	if initialized:return {"ok":true}
	scope="ChemLab reconstructed process / "+str(get_instance_id())
	var result:Dictionary=api.initialize({"scope":scope,"page_size":4096,"allocation_granularity":65536,"local_alignment":16,
		"virtual_domains":[{"address":0x4000000,"size":0x4000000}],"local_domains":[{"address":0xa000000,"size":0x1000000}],
		"exclusions":[],"lock_domains":[{"address":0x59b184,"size":24}]})
	if not result.ok:return result
	result=heap.initialize_fresh(Callable(api,"dispatch"),Heap.DEFAULT_MANAGER,{"fs_base":0,"exception_head":0xffffffff,"stack_base":0x9000000,"stack_size":0x100000,"stack_pointer":0x90ffe00,"stack_origin":"fresh_committed_pages","scope":scope})
	if not result.ok:return result
	result=api.bind_memory(heap.vm.byte_memory)
	if not result.ok:return result
	heap.vm.put(0x59ad95,1,1) # This Godot process uses source threaded locking.
	initialized=true
	return {"ok":true}
func owns(vessel:Dictionary)->bool:
	return allocations.has(str(vessel.get(TOKEN,"")))
func bind(vessel:Dictionary)->Dictionary:
	if owns(vessel):return {"ok":true}
	var result:=initialize()
	if not result.ok:return result
	result=heap.get_mem(0x4348)
	if not result.ok:return result
	var address:int=result.value
	if address==0:return _error("Original apparatus allocation failed")
	serial+=1
	var token:=scope+"/apparatus"+str(serial)
	allocations[token]=address
	written[token]={}
	vessel[TOKEN]=token
	var view=View.new()
	result=view.bind(heap,address,{"source_sha256":Heap.SOURCE_SHA,"pointer":address,"request_size":0x4348,"scope":scope,"origin":"retained System allocator in reconstructed process"})
	if not result.ok:return result
	result=view.snapshot(vessel.contents.keys())
	if not result.ok:return result
	# Restore explicit saved/observed physical cells over this process's storage.
	# Unspecified cells retain the actual allocator payload, including reused data.
	var valid:=Slots.initialize(vessel)
	if not valid.ok:return valid
	var previous:Dictionary=vessel.get(Slots.KEY,{})
	if not previous.is_empty():
		for field in Slots.FIELDS:
			for index in 100:
				if previous.arrays[field][index]!=null:result.backing.arrays[field][index]=previous.arrays[field][index]
	vessel[Slots.KEY]=result.backing
	for field in result.scalar_raw_hex:
		if vessel.has(field) or result.scalar_raw_hex[field]==null:continue
		var value:float=str(result.scalar_raw_hex[field]).hex_decode().decode_double(0)
		if is_finite(value):vessel[field]=value
	var committed:=Slots.commit(vessel)
	if not committed.ok:return committed
	committed=Slots.project(vessel)
	if not committed.ok:return committed
	return commit(vessel)
func commit(vessel:Dictionary)->Dictionary:
	if not owns(vessel):return _error("Apparatus does not belong to this runtime allocation owner")
	var token:=str(vessel[TOKEN])
	var address:int=allocations[token]
	var prior:Dictionary=written[token]
	for field in Slots.FIELDS:
		var start:int=Slots.FIELDS[field]
		var cells:Array=vessel[Slots.KEY].arrays[field]
		if not prior.has(field):prior[field]=[]
		var old:Array=prior[field]
		if old.is_empty():old.resize(100)
		for index in 100:
			if cells[index]==null or old[index]==cells[index]:continue
			var result:Dictionary=heap.write_bytes(address+start+index*8,str(cells[index]).hex_decode())
			if not result.ok:return result
			old[index]=cells[index]
	for field in View.SCALARS:
		if not vessel.has(field):continue
		var raw:=PackedFloat64Array([float(vessel[field])]).to_byte_array()
		if prior.get(field)==raw:continue
		var result:Dictionary=heap.write_bytes(address+int(View.SCALARS[field]),raw)
		if not result.ok:return result
		prior[field]=raw
	return {"ok":true}
func release(vessel:Dictionary)->Dictionary:
	if not owns(vessel):return {"ok":true}
	var token:=str(vessel[TOKEN])
	var result:=commit(vessel)
	if not result.ok:return result
	result=heap.free_mem(int(allocations[token]))
	if not result.ok:return result
	allocations.erase(token);written.erase(token);vessel.erase(TOKEN)
	return {"ok":true}
func close()->void:
	heap.close()
