class_name OriginalHeapVesselView
extends RefCounted
## Read-only typed views of an explicitly scoped original apparatus allocation.
## Does not allocate, construct, migrate, or fill missing bytes.
const Slots=preload("res://scripts/original/original_slots.gd")
const SOURCE_SHA:="7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c"
const SCALARS:={"gas_3cc0":0x3cc0,"native_particle_3cc8":0x3cc8,"solid_4318":0x4318,"native_solid_volume":0x4338}
var heap
var pointer:=0
var provenance:Dictionary={}
func bind(shared_heap,address:int,allocation_provenance:Dictionary)->Dictionary:
	if shared_heap==null or not shared_heap.initialized:return {"ok":false,"error":"An initialized source heap is required"}
	if allocation_provenance.get("source_sha256","")!=SOURCE_SHA or int(allocation_provenance.get("pointer",-1))!=address or int(allocation_provenance.get("request_size",0))!=0x4348 or str(allocation_provenance.get("scope","")).is_empty():
		return {"ok":false,"error":"Exact apparatus pointer, request and scope provenance are required"}
	if address<=0 or address>0xffffffff-0x4348:return {"ok":false,"error":"Invalid original apparatus address"}
	heap=shared_heap;pointer=address;provenance=allocation_provenance.duplicate(true)
	return {"ok":true}
func cell(offset:int)->Dictionary:
	if heap==null:return {"ok":false,"error":"Original apparatus view is unbound"}
	if offset<0 or offset+8>0x4348:return {"ok":false,"error":"Cell is outside original apparatus allocation"}
	# Checking masks avoids reading unknown bytes or poisoning interpreter state.
	if not heap.vm.byte_memory.contains_span(pointer+offset,8):return {"ok":true,"known":false,"raw_hex":null}
	var raw:Dictionary=heap.read_bytes(pointer+offset,8)
	if not raw.ok:return raw
	return {"ok":true,"known":true,"raw_hex":raw.bytes.hex_encode()}
func snapshot(ordered_names:Array)->Dictionary:
	if ordered_names.size()>100:return {"ok":false,"error":"Original apparatus supports at most100 species rows"}
	var names:=ordered_names.duplicate()
	for name in names:
		if not name is String:return {"ok":false,"error":"Source-ordered species names are required"}
	var arrays:Dictionary={};var scalars:Dictionary={}
	for field in Slots.FIELDS:
		var cells:Array=[]
		for index in 100:
			var result:=cell(int(Slots.FIELDS[field])+index*8)
			if not result.ok:return result
			cells.append(result.raw_hex)
		arrays[field]=cells
	for field in SCALARS:
		var result:=cell(int(SCALARS[field]))
		if not result.ok:return result
		scalars[field]=result.raw_hex
	return {"ok":true,"backing":{"version":1,"names":names,"arrays":arrays,"observations":[{"kind":"original_byte_heap_view","provenance":provenance.duplicate(true)}]},"scalar_raw_hex":scalars,"pointer":pointer}
