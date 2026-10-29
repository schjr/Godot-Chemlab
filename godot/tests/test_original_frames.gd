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
	var corpus: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_frames.json"))
	var reagents: Array = JSON.parse_string(FileAccess.get_file_as_string("res://data/reagents.json"))
	var reactions: Array = JSON.parse_string(FileAccess.get_file_as_string("res://data/reactions.json"))
	var mismatches: Array = []
	var unresolved: Array = []
	var tested := 0
	for fixture in corpus.cases:
		if fixture.status != "executed": unresolved.append([fixture.name,"oracle",fixture.get("stage"),fixture.get("error")]); continue
		var doc: Dictionary = Formats.load_document(fixture.fixture_path)
		var model = Host.new()
		model.configure(reagents,reactions)
		if not model.from_state(Adapter.to_state(doc)): unresolved.append([fixture.name,"import",model.last_error]); continue
		# Actual oracle boundary: all100 numeric cells observed zero before RUN.
		var zero_cells:=PackedByteArray();zero_cells.resize(800);zero_cells.fill(0)
		for v in model.native_apparatus():
			for field in ["native_species_volume","solid_3cd8","solid_3ff8"]:
				assert(Slots.observe(v,field,zero_cells.hex_encode(),{"source":"original oracle explicit zero numerical allocation profile"}).ok)
		if not model.start(): unresolved.append([fixture.name,"start",model.last_error]); continue
		for c in model.native_connectors:
			c.native_state_0x70 = 0.0; c.native_state_0x78 = 0
		for frame_index in range(fixture.frames.size()):
			var context: Dictionary = {}
			var reads: Array = fixture.get("stack_reads_by_frame", [])[frame_index] if fixture.has("stack_reads_by_frame") else fixture.stack_reads
			if not reads.is_empty(): context.observed_stack_excess = number(str(reads[0]))
			model.step(number(corpus.delta_bits),context)
			if not model.last_error.is_empty(): unresolved.append([fixture.name,frame_index,model.last_error]); break
			var actual: Array = model.native_apparatus()
			var expected: Array = fixture.frames[frame_index]
			for i in range(actual.size()):
				var v: Dictionary = actual[i]
				if v.contents.keys() != expected[i].contents.keys(): mismatches.append([fixture.name,frame_index,i] + ["species_order"])
				var selected_names: Array = []
				for r in v.native_reaction_records: selected_names.append(str(r.get("name",r.get("id",""))))
				if selected_names != expected[i].reaction_names: mismatches.append([fixture.name,frame_index,i] + ["reaction_order"])
				for key in ["contents","masses","volumes","solid_3cd8","solid_3ff8"]:
					var table: Dictionary = v[key if key in ["contents","solid_3cd8","solid_3ff8"] else "native_species_mass" if key=="masses" else "native_species_volume"]
					for species in expected[i].bits[key]:
						if not table.has(species) or not equal_bits(float(table.get(species,0)),number(expected[i].bits[key][species])): mismatches.append([fixture.name,frame_index,i,key,species,table.get(species),PackedFloat64Array([float(table.get(species,0))]).to_byte_array().hex_encode(),expected[i].bits[key][species]])
				for pair in [["temperature","temperature"],["native_liquid_volume","liquid_volume"],["native_gas_moles","gas_moles"],["native_gas_volume","gas_volume"],["native_pressure","pressure"],["gas_3cc0","gas_3cc0"],["solid_4318","solid_4318"]]:
					if not equal_bits(float(v.get(pair[0],0)),number(expected[i].bits[pair[1]])): mismatches.append([fixture.name,frame_index,i,pair[1],v.get(pair[0]),number(expected[i].bits[pair[1]])])
				if int(v.native_heating) != int(expected[i].heating): mismatches.append([fixture.name,frame_index,i,"heating"])
				if int(v.get("native_liquid_color",0)) != int(expected[i].liquid_color) and int(v.type_id)>100 and int(v.type_id)<300: mismatches.append([fixture.name,frame_index,i,"color"])
			tested += 1
	print(JSON.stringify({"frames_tested":tested,"unresolved":unresolved,"mismatches":mismatches}))
	if not (not unresolved.is_empty() or not mismatches.is_empty()): print("PASS test_original_frames")
	quit(1 if not unresolved.is_empty() or not mismatches.is_empty() else 0)
