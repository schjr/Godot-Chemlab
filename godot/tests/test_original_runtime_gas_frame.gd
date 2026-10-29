extends SceneTree
const Owner=preload("res://scripts/original/original_runtime_allocation.gd")
const Frame=preload("res://scripts/original/original_runtime_gas_frame.gd")
const Gas=preload("res://scripts/original/original_gasflow.gd")
var failures:Array=[]
var checks:=0
func check(condition:bool,label:String)->void:
	checks+=1
	if not condition:failures.append(label)
func number(raw:String)->float:return raw.hex_decode().decode_double(0)
func bits(value:float)->String:return PackedFloat64Array([value]).to_byte_array().hex_encode()
func _initialize()->void:
	var owner=Owner.new();check(owner.initialize().ok,"owned source stack initialization")
	var frame=Frame.new();var bound:=frame.bind(owner.heap,0x900f000)
	check(bound.ok and frame.cell_address==0x900ee88,"actual4018B0/F4 ->CALL/pushEBP ->46F704/7C ABI offset")
	check(not Frame.new().bind(owner.heap,0x9000000).ok,"out-of-stack ABI frame rejected")
	check(not Frame.new().bind(owner.heap,0x900f001).ok,"unaligned frame rejected")
	var reagents:Dictionary={}
	for r in JSON.parse_string(FileAccess.get_file_as_string("res://data/reagents.json")):reagents[str(r.species)]=r
	var corpus:Dictionary=JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_gas_stack_boundary.json"))
	check(corpus.binary_sha256==owner.heap.SOURCE_SHA,"original native stack reference identity")
	var events:=0
	for fixture in corpus.cases:
		var vessels:Array=[]
		for i in fixture.vessels.size():
			var v:Dictionary=fixture.vessels[i];var before:Dictionary=fixture.before_remaining[i]
			var state:Dictionary={"type_id":v.type,"legacy_name":v.get("name","v"+str(i)),"volume_ml":float(v.capacity),"temperature":float(v.temperature),"position":[v.x,v.y],"native_orientation":v.orientation,"native_mouth_state":v.mouth,"native_bitmap_width":v.width,"native_bitmap_height":v.height,"native_liquid_height":float(v.liquid_height),"native_liquid_volume":number(before.scalar_bits.liquid_volume),"native_gas_moles":number(before.scalar_bits.gas_moles),"native_pressure":number(before.scalar_bits.pressure),"contents":{},"native_species_mass":{},"native_species_volume":{}}
			for table in ["contents","masses","volumes"]:
				for species in before.bits[table]:state["contents" if table=="contents" else "native_species_mass" if table=="masses" else "native_species_volume"][species]=number(before.bits[table][species])
			vessels.append(state)
		var connectors:Array=fixture.get("connectors",[]).duplicate(true)
		for c in connectors:c.native_state_0x70=0.0
		check(Gas.advance_conduits(vessels,connectors,reagents,0.001,1.0).ok,"original conduit graph")
		check(owner.heap.write_bytes(frame.cell_address,str(fixture.initial_stack_hex).hex_decode()).ok,"explicit diagnostic physical stack input")
		frame.accesses.clear()
		var result:=Gas.advance_remaining(vessels,connectors,reagents,0.001,1.0,frame.context())
		check(result.ok,"original physical gas operand: "+str(result))
		for i in vessels.size():
			for species in fixture.after_remaining[i].bits.contents:check(bits(vessels[i].contents[species])==fixture.after_remaining[i].bits.contents[species],"native remaining gas amount "+str(fixture.name)+"/"+species)
		check(owner.heap.read_bytes(frame.cell_address,8).bytes.hex_encode()==fixture.final_stack_hex,"source physical stack retains exact final bytes")
		check(frame.accesses.size()==fixture.stack_events.size(),"source exact lazy stack access count")
		for i in mini(frame.accesses.size(),fixture.stack_events.size()):
			for field in ["pc","operation","raw_hex"]:check(frame.accesses[i][field]==fixture.stack_events[i][field],"source exact stack access "+field)
			events+=1
	# Physical stale bytes survive calls without an excess assignment; no
	# statement elsewhere in the bridge replaces them with zero or a fixture.
	check(frame.write_excess(31.75).ok,"source exact store boundary")
	check(frame.read_excess().raw_hex==bits(31.75),"later source read retains physical QWORD")
	check(owner.heap.write_bytes(frame.cell_address,"000000000000f87f".hex_decode()).ok,"diagnostic nonfinite stack bytes")
	check(not frame.read_excess().ok,"nonfinite source stack is not normalized into an invented value")
	Gas._routes=[]
	frame.accesses.clear()
	check(Gas.advance_remaining([],[],reagents,0.001,1.0,frame.context()).ok and frame.accesses.is_empty(),"unused source branch never reads its unknown/nonfinite stack cell")
	owner.close()
	print(JSON.stringify({"native_cases":corpus.cases.size(),"native_stack_accesses":events,"checks":checks,"failures":failures}))
	if failures.is_empty():print("PASS source gas physical-stack ABI reads/stores, stale values, lazy access and exact native transfer results")
	quit(0 if failures.is_empty() else 1)
