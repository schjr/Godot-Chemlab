extends SceneTree
const Adapter = preload("res://scripts/experiment_adapter.gd")
const Formats = preload("res://scripts/legacy_formats.gd")
const Model = preload("res://scripts/lab_model.gd")
func _reaction_commit_roundtrip(doc: Dictionary) -> void:
	var sample := doc.duplicate(true)
	var selected := -1
	for index in sample.apparatus.size():
		if sample.apparatus[index].reactions.size() >= 2: selected = index; break
	if selected < 0: return
	# Distinct source rows can share an ID. Complete records, order and all five
	# native parameters must survive editing and CEM save/reopen independently.
	sample.apparatus[selected].reactions[1].id = sample.apparatus[selected].reactions[0].id
	var state := Adapter.to_state(sample)
	var vessel: Dictionary = state.vessels[selected]
	var first: Dictionary = vessel.native_reaction_records[0]
	first.reaction_heat = -17.25
	first.condition = "温度>35"
	first.reaction_rate = -0.003125
	first.equilibrium_degree_or_constant = 0.0625
	first.equilibrium_mode = "可逆"
	# Deliberately leave the UI mirror stale; it must not overwrite the record.
	vessel.native_reaction_records[0] = vessel.native_reaction_records[1]
	vessel.native_reaction_records[1] = first
	var saved := Adapter.from_state(sample, state)
	assert(not saved.has("error"), str(saved))
	var parsed := Formats.parse_cem(Formats.serialize_cem(saved), str(doc.name))
	var reaction: Dictionary = parsed.apparatus[selected].reactions[1]
	assert(reaction.name == sample.apparatus[selected].reactions[0].name)
	assert(Array(reaction.parameters) == ["-17.25","温度>35","-0.003125","0.0625","可逆"])
	assert(reaction.direction == "可逆")
	assert(Array(parsed.apparatus[selected].reactions[0].parameters) == Array(sample.apparatus[selected].reactions[1].parameters))
	vessel.native_reaction_records.remove_at(0)
	var inserted: Dictionary = first.duplicate(true)
	inserted.erase("native_cem_source_index")
	inserted.name = "已提交的新反应"
	vessel.native_reaction_records.append(inserted)
	saved = Adapter.from_state(sample, state)
	assert(not saved.has("error"), str(saved))
	parsed = Formats.parse_cem(Formats.serialize_cem(saved), str(doc.name))
	assert(parsed.apparatus[selected].reactions.size() == vessel.native_reaction_records.size())
	assert(parsed.apparatus[selected].reactions[-1].name == inserted.name)
	assert(parsed.apparatus[selected].reactions[0].name == first.name)
	# Clear-all is an empty complete array, not the old reactions restored.
	vessel.native_reaction_records.clear()
	saved = Adapter.from_state(sample, state)
	assert(saved.apparatus[selected].reactions.is_empty())

func _initialize() -> void:
	var examples: Array = Formats.read_json("res://data/examples.json")
	var annotations := 0
	for doc in examples:
		_reaction_commit_roundtrip(doc)
		var disk_doc := Formats.parse_cem(str(doc.raw_text), str(doc.name))
		assert(Formats.serialize_cem(Adapter.from_state(disk_doc, Adapter.to_state(disk_doc))) == doc.raw_text)
		var state := Adapter.to_state(doc)
		if not doc.apparatus[0].chemicals.is_empty():
			var chemical_state := state.duplicate(true)
			var species: String = str(doc.apparatus[0].chemicals[0].name)
			chemical_state.vessels[0].native_species_mass = chemical_state.vessels[0].native_masses.duplicate()
			chemical_state.vessels[0].native_species_mass[species] = 1.9999999999999998
			var chemical_saved := Adapter.from_state(doc, chemical_state)
			assert(not chemical_saved.has("error"), str(chemical_saved))
			assert(chemical_saved.apparatus[0].chemicals[0].moles == doc.apparatus[0].chemicals[0].moles)
			assert(PackedFloat64Array([chemical_saved.apparatus[0].chemicals[0].mass]).to_byte_array() == PackedFloat64Array([1.9999999999999998]).to_byte_array())
		assert(state.bindings is Array)
		for value in state.variables.values(): assert(value is float or value is int)
		for binding in state.bindings:
			assert(binding.has("name") and binding.has("metric"))
		if doc.name == "酸碱中和滴定":
			assert(state.program.contains("ph1=-log10"))
			assert(state.variables.has("ph1"))
			assert(not state.bindings.is_empty())
		if doc.name == "铁和盐酸的反应":
			assert(state.charts.size() == 1)
			assert(state.charts[0].series[0].y_variable == "fe_mol")
		var model := Model.new()
		assert(model.from_state(state), doc.name)
		var ids: Dictionary = {}
		for v in state.vessels:
			assert(not ids.has(v.id))
			ids[v.id] = true
			assert(v.kind != "unknown")
		for link in state.connections:
			assert(ids.has(link.source) and ids.has(link.target))
		annotations += state.annotations.size()
		var exported := Adapter.from_state(doc, state)
		assert(not exported.has("error"), str(exported))
		if Formats.serialize_cem(exported) != doc.raw_text:
			var a := Formats.serialize_cem(exported).split("\r\n")
			var b := str(doc.raw_text).split("\r\n")
			for i in range(mini(a.size(), b.size())):
				if a[i] != b[i]: print(doc.name, " DIFF ", i, " ", a[i], " / ", b[i])
			quit(1)
			return
		state.vessels[0].position[0] += 10
		exported = Adapter.from_state(doc, state)
		assert(float(exported.apparatus[0].x) == float(doc.apparatus[0].x) + 10)
		for v in state.vessels:
			if v.kind == "chart":
				v.position[0] += 7
				v.native_chart_record[3] = str(float(v.native_chart_record[3]) + 0.25)
				v.native_chart_record[17] = "t"
				var with_chart := Adapter.from_state(doc, state)
				var rebuilt := Adapter.to_state(with_chart)
				assert(float(rebuilt.charts[int(v.legacy_chart_index)].position[0]) == float(v.position[0]))
				assert(float(rebuilt.charts[int(v.legacy_chart_index)].metadata[3]) == float(v.native_chart_record[3]))
				assert(rebuilt.charts[int(v.legacy_chart_index)].metadata[17] == "t")
		if not state.annotations.is_empty():
			state.annotations[0].position[0] += 11
			var moved := Adapter.to_state(Adapter.from_state(doc,state))
			assert(moved.annotations[0].position[0] == state.annotations[0].position[0])
		if state.vessels[0].has("native_label_rect"):
			state.vessels[0].native_label_rect[0] += 3
			var moved := Adapter.to_state(Adapter.from_state(doc,state))
			assert(moved.vessels[0].native_label_rect[0] == state.vessels[0].native_label_rect[0])
	print("ADAPTER VALIDATION: all 28 experiments, unique IDs, connectors, exact round trips; ", annotations, " annotations")
	print("PASS test_adapter")
	quit()
