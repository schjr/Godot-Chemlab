extends SceneTree
const Gas=preload("res://scripts/original/original_gasflow.gd")
const X87=preload("res://scripts/original/original_x87.gd")
const Host=preload("res://scripts/original_model_host.gd")
const Slots=preload("res://scripts/original/original_slots.gd")
func number(hex:String)->float:return hex.hex_decode().decode_double(0)
func bits(value:float)->String:return PackedFloat64Array([value]).to_byte_array().hex_encode()
func _initialize():
	var fixture=JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_gas_operand_order.json"))
	var mismatches:Array=[]
	var source_checks:=0
	for c in fixture.cases:
		var operand:Dictionary=c.operands[0]
		var difference:=X87.add([number(operand.free_volume_bits),0.0],-number(operand.existing_gas_volume_bits))
		assert(bits(X87.stored_double(difference))==operand.stored_difference_bits)
		#48EBC9 QWORD,48EBCC A*storedDifference,48EBD5 B,48EBDB multiply.
		var native:=X87.multiply(X87.from_extended80_hex(fixture.constants["0048EC7C"]),number(operand.stored_difference_bits))
		native=X87.multiply_pair(native,X87.from_extended80_hex(fixture.constants["0048EC88"]))
		var expected:String=c.after_bits.contents[Gas.INERT]
		assert(bits(X87.stored_double(native))==expected)
		source_checks+=1
		var actual:=bits(X87.stored_double(Gas._inert_amount(difference)))
		if actual!=expected:mismatches.append({"capacity_bits":c.capacity_bits,"expected":expected,"actual":actual})
	assert(fixture.run.events==["43F7BC stopped refresh-boundary","004624D8","42DC3C save-boundary","0046C894","0048E9B4"])
	assert(fixture.run.run_flag==1 and fixture.run.after_bits.volumes[Gas.INERT]=="0000000000000000" and fixture.run.aggregate_bits.gas_volume=="0000000000000000")
	var model:=Host.new();model.configure(JSON.parse_string(FileAccess.get_file_as_string("res://data/reagents.json")),JSON.parse_string(FileAccess.get_file_as_string("res://data/reactions.json")))
	var v:Dictionary=model.add_apparatus("jtdg_2")
	var zero:=PackedByteArray();zero.resize(800);zero.fill(0)
	for field in ["native_species_volume","solid_3cd8","solid_3ff8"]:assert(Slots.observe(v,field,zero.hex_encode(),{"source":"same explicitly zero numeric allocation boundary as original Run oracle; not production"}).ok)
	assert(model.start(),model.last_error)
	var actual:=bits(float(v.native_species_volume[Gas.INERT]))
	if actual!=fixture.run.after_bits.volumes[Gas.INERT]:mismatches.append({"stage":"Run-before-idle","expected_volume":fixture.run.after_bits.volumes[Gas.INERT],"actual_volume":actual})
	print(JSON.stringify({"native_conversion_cases":source_checks,"current_port_mismatches":mismatches,"source_run_sequence":"verified first-Run flag0; graphics/save are declared boundaries"}))
	if mismatches.is_empty():print("PASS original gas operand/store/native Run reference", " + current port")
	quit(0 if mismatches.is_empty() else 1)
