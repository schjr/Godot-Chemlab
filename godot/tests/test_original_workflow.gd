extends SceneTree
const Slots=preload("res://scripts/original/original_slots.gd")
const Host = preload("res://scripts/original_model_host.gd")
const Formats = preload("res://scripts/legacy_formats.gd")
const Adapter = preload("res://scripts/experiment_adapter.gd")
func number(hex: String) -> float:
	var bytes := PackedByteArray()
	for i in range(0,hex.length(),2): bytes.append(hex.substr(i,2).hex_to_int())
	return bytes.decode_double(0)
func equal_bits(a: float,b: float) -> bool:
	return PackedFloat64Array([a]).to_byte_array() == PackedFloat64Array([b]).to_byte_array()
func _initialize() -> void:
	var fixture: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_workflow_run_order.json"))
	if fixture.status != "executed":
		print(JSON.stringify({"unresolved":fixture.get("error","")})); quit(1); return
	var reagents: Array = JSON.parse_string(FileAccess.get_file_as_string("res://data/reagents.json"))
	var model = Host.new()
	model.configure(reagents,JSON.parse_string(FileAccess.get_file_as_string("res://data/reactions.json")))
	assert(model.from_state(Adapter.to_state(Formats.load_document(fixture.fixture_path))))
	# Declared physical100-cell oracle profile, never production defaults.
	var zero_cells:=PackedByteArray();zero_cells.resize(800);zero_cells.fill(0)
	for v in model.native_apparatus():
		for field in ["native_species_volume","solid_3cd8","solid_3ff8"]:
			assert(Slots.observe(v,field,zero_cells.hex_encode(),{"source":"original oracle explicit zero numerical allocation profile"}).ok)
	assert(model.start())
	var mismatches: Array = []
	var completed := 0
	var frame_count:=0
	assert(fixture.startup_events==["43F7BC stopped refresh-boundary","004624D8","42DC3C save-boundary","0046C894","0048E9B4"])
	check_snapshot(model.native_apparatus(),fixture.start,"native Run return",mismatches)
	for action_index in range(fixture.actions.size()):
		var action: Dictionary = fixture.actions[action_index]
		var selected: Dictionary = model.native_apparatus()[int(action.selected)]
		selected.position = action.position.duplicate()
		selected.native_fields["0x10"] = str(int(action.position[0]))
		selected.native_fields["0x14"] = str(int(action.position[1]))
		if action.get("orientation_toggle",false): assert(model.toggle_pour(int(selected.id)))
		else:
			var result: Dictionary = model.manual_action(int(selected.id),int(action.command))
			assert(result.ok,str(result.get("error","")))
		for _tick in range(int(action.get("ticks",0))):
			model.step(number(fixture.delta_bits))
			if not model.last_error.is_empty():
				print(JSON.stringify({"actions_completed":completed,"unresolved":[action.name,model.last_error],"bit_mismatches":mismatches})); quit(1); return
			check_snapshot(model.native_apparatus(),fixture.frames[frame_count],"%s frame%d"%[action.name,frame_count],mismatches)
			frame_count+=1
		if action.get("orientation_toggle",false): assert(model.toggle_pour(int(selected.id)))
		check_snapshot(model.native_apparatus(),fixture.states[action_index],str(action.name),mismatches)
		completed += 1
	assert(frame_count==63 and completed==7)
	print(JSON.stringify({"actions_tested":completed,"physics_frames":frame_count,"bit_mismatches":mismatches}))
	if not (not mismatches.is_empty()): print("PASS test_original_workflow")
	quit(1 if not mismatches.is_empty() else 0)

func check_snapshot(actual:Array,expected:Array,label:String,mismatches:Array)->void:
	for i in range(actual.size()):
		var v: Dictionary = actual[i]
		if v.contents.keys() != expected[i].contents.keys(): mismatches.append([label,i] + ["species_order"])
		var selected_names: Array = []
		for r in v.native_reaction_records: selected_names.append(str(r.get("name",r.get("id",""))))
		if selected_names != expected[i].reaction_names: mismatches.append([label,i] + ["reaction_order"])
		for key in ["contents","masses","volumes","solid_3cd8","solid_3ff8"]:
			var table: Dictionary = v[key if key in ["contents","solid_3cd8","solid_3ff8"] else "native_species_mass" if key=="masses" else "native_species_volume"]
			for species in expected[i].bits[key]:
				if not table.has(species) or not equal_bits(float(table.get(species,0)),number(expected[i].bits[key][species])): mismatches.append([label,i,key,species,PackedFloat64Array([float(table.get(species,0))]).to_byte_array().hex_encode(),expected[i].bits[key][species]])
		for pair in [["temperature","temperature"],["native_liquid_volume","liquid_volume"],["native_gas_moles","gas_moles"],["native_gas_volume","gas_volume"],["native_pressure","pressure"],["gas_3cc0","gas_3cc0"],["solid_4318","solid_4318"]]:
			if not equal_bits(float(v.get(pair[0],0)),number(expected[i].bits[pair[1]])): mismatches.append([label,i,pair[1]])
