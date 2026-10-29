extends SceneTree
const Reaction = preload("res://scripts/original/original_reaction.gd")
func _number(hex: String) -> float:
	var bytes := PackedByteArray()
	for i in range(0, hex.length(), 2): bytes.append(hex.substr(i, 2).hex_to_int())
	return bytes.decode_double(0)
func _initialize() -> void:
	var corpus: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_reactions.json"))
	var tested := 0
	var counter_mismatches := []
	var unresolved := []
	var mismatches := []
	var bit_mismatches := []
	for fixture in corpus.cases:
		if fixture.status != "executed": continue
		var old: Dictionary = fixture.reaction
		var reaction: Dictionary = {}
		if not old.is_empty():
			reaction = {"name": old.get("name", "smart"), "native_note": old.get("native_note", ""), "equilibrium_mode": old.parameters[4], "condition": old.parameters[1], "reaction_rate": float(old.parameters[2]), "equilibrium_degree_or_constant": float(old.parameters[3]), "reactants": old.reactants, "products": old.products}
		var library: Array = []
		for r in fixture.get("library", []):
			library.append({"name": r.name, "native_note": r.get("native_note", ""), "equation_type": r.get("equation_type", ""), "equilibrium_mode": r.parameters[4], "condition": r.parameters[1], "reaction_rate": float(r.parameters[2]), "equilibrium_degree_or_constant": float(r.parameters[3]), "reactants": r.reactants, "products": r.products})
		var state := {"moles": fixture.before.contents.duplicate(), "volumes": fixture.before.volumes.duplicate(), "temperature": fixture.temperature, "heating_flag": fixture.heating_flag, "speed_setting": fixture.speed_setting, "liquid_height": fixture.liquid_height, "smart_flag": int(fixture.get("smart_flag", 0)), "ion_flag": int(fixture.get("ion_flag", 0)), "reactions": [reaction] if not reaction.is_empty() else []}
		for table in ["contents", "volumes"]:
			for key in fixture.before_bits[table]:
				state["moles" if table == "contents" else "volumes"][key] = _number(fixture.before_bits[table][key])
		for table in ["solid_3cd8", "solid_3ff8"]:
			state[table] = {}
			for species in fixture.before_counter_bits[table]: state[table][species] = _number(fixture.before_counter_bits[table][species])
		var result := Reaction.step_core(state, library, fixture.delta_seconds)
		if not result.resolved:
			unresolved.append([fixture.example, old.get("name", "smart"), result.get("error", "")]); continue
		var selected: Array = []
		for r in state.reactions: selected.append(str(r.get("name", r.get("id", ""))))
		assert(selected == fixture.after_reactions, fixture.example + " native selection order")
		for scalar in ["gas_3cc0", "solid_4318"]:
			if PackedFloat64Array([float(state.get(scalar, 0))]).to_byte_array() != PackedFloat64Array([_number(fixture.counter_bits[scalar])]).to_byte_array(): counter_mismatches.append([fixture.example, scalar])
		for table in ["solid_3cd8", "solid_3ff8"]:
			for species in fixture.counter_bits[table]:
				if PackedFloat64Array([float(state.get(table, {}).get(species, 0))]).to_byte_array() != PackedFloat64Array([_number(fixture.counter_bits[table][species])]).to_byte_array(): counter_mismatches.append([fixture.example, table, species])
		tested += 1
		for species in fixture.after.contents:
			var actual := float(state.moles.get(species, 0.0))
			var expected := _number(fixture.after_bits[species])
			if PackedFloat64Array([actual]).to_byte_array() != PackedFloat64Array([expected]).to_byte_array(): bit_mismatches.append([fixture.example, old.get("name", "smart"), species, actual, expected])
			if absf(actual - expected) > 1e-12 * maxf(1.0, absf(expected)):
				mismatches.append([fixture.example, old.get("name", "smart"), species, actual, expected])
	print(JSON.stringify({"tested": tested, "unresolved": unresolved, "mismatches": mismatches, "bit_mismatches": bit_mismatches, "counter_mismatches": counter_mismatches}))
	if not (not mismatches.is_empty() or not bit_mismatches.is_empty() or not counter_mismatches.is_empty() or not unresolved.is_empty()): print("PASS test_original_reaction_corpus")
	quit(1 if not mismatches.is_empty() or not bit_mismatches.is_empty() or not counter_mismatches.is_empty() or not unresolved.is_empty() else 0)
