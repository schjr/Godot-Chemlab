extends SceneTree
const Gas = preload("res://scripts/original/original_gasflow.gd")
func _number(hex: String) -> float:
	var bytes := PackedByteArray()
	for i in range(0, hex.length(), 2): bytes.append(hex.substr(i, 2).hex_to_int())
	return bytes.decode_double(0)
func _initialize() -> void:
	var reagent_map: Dictionary = {}
	for r in JSON.parse_string(FileAccess.get_file_as_string("res://data/reagents.json")):
		reagent_map[str(r.species)] = r
	var corpus: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_gasflow.json"))
	var unresolved: Array = []
	var mismatches: Array = []
	var tested := 0
	for fixture in corpus.cases:
		if fixture.status != "executed": continue
		var vessels: Array = []
		for i in range(fixture.vessels.size()):
			var v: Dictionary = fixture.vessels[i]
			var before: Dictionary = fixture.before[i]
			var state := {"type_id": v.type, "legacy_name": v.get("name", "v" + str(i)), "volume_ml": float(v.capacity), "temperature": float(v.temperature), "position": [v.x, v.y], "native_orientation": v.orientation, "native_mouth_state": v.mouth, "native_bitmap_width": v.width, "native_bitmap_height": v.height, "native_liquid_height": float(v.liquid_height), "native_liquid_volume": _number(before.scalar_bits.liquid_volume), "contents": {}, "native_species_mass": {}, "native_species_volume": {}}
			for table in ["contents", "masses", "volumes"]:
				for species in before.bits[table]:
					state["contents" if table == "contents" else "native_species_mass" if table == "masses" else "native_species_volume"][species] = _number(before.bits[table][species])
			vessels.append(state)
		var result := Gas.initialize_air(vessels, reagent_map)
		if not result.ok: unresolved.append([fixture.name, "air", result.error]); continue
		for i in range(vessels.size()):
			for table in ["contents", "masses", "volumes"]:
				var actual_table: Dictionary = vessels[i]["contents" if table == "contents" else "native_species_mass" if table == "masses" else "native_species_volume"]
				for species in fixture.after_air[i].bits[table]:
					var actual := float(actual_table.get(species, 0))
					var expected := _number(fixture.after_air[i].bits[table][species])
					if PackedFloat64Array([actual]).to_byte_array() != PackedFloat64Array([expected]).to_byte_array(): mismatches.append([fixture.name, "air", i, table, species, actual, expected])
		result = Gas.advance_open(vessels, reagent_map)
		if not result.ok: unresolved.append([fixture.name, "open", result.error]); continue
		for i in range(vessels.size()):
			for table in ["contents", "masses", "volumes"]:
				var actual_table: Dictionary = vessels[i]["contents" if table == "contents" else "native_species_mass" if table == "masses" else "native_species_volume"]
				for species in fixture.after[i].bits[table]:
					var actual := float(actual_table.get(species, 0))
					var expected := _number(fixture.after[i].bits[table][species])
					if PackedFloat64Array([actual]).to_byte_array() != PackedFloat64Array([expected]).to_byte_array(): mismatches.append([fixture.name, "open", i, table, species, actual, expected])
		for v in vessels:
			if int(v.type_id) > 100 and int(v.type_id) < 300:
				var calc := preload("res://scripts/original/original_quantities.gd").recalc(v, reagent_map)
				assert(calc.ok)
		var conduits: Array = fixture.get("connectors", []).duplicate(true)
		result = Gas.advance_conduits(vessels, conduits, reagent_map, 0.1, 1.0)
		if not result.ok: unresolved.append([fixture.name, "graph", result.error]); continue
		if result.native_network.size() != fixture.network.size(): mismatches.append([fixture.name, "graph", "count", result.native_network.size(), fixture.network.size()])
		else:
			for i in range(fixture.network.size()):
				for key in ["mode", "source_name", "target_name", "source_connector", "target_connector", "source_selector", "target_selector"]:
					if result.native_network[i][key] != fixture.network[i][key]: mismatches.append([fixture.name, "graph", i, key, result.native_network[i][key], fixture.network[i][key]])
				if PackedFloat64Array([float(result.native_network[i].amount)]).to_byte_array() != PackedFloat64Array([_number(fixture.network[i].amount_bits)]).to_byte_array(): mismatches.append([fixture.name, "graph", i, "amount"])
		for i in range(fixture.visited.size()):
			if int(result.visited[i]) != int(fixture.visited[i]): mismatches.append([fixture.name, "graph", "visited", i])
		# Fixture allocator supplies explicit zero bubble-cache bytes only for tests.
		for conduit in conduits: conduit.native_state_0x70 = 0.0
		var context: Dictionary = {}
		if not fixture.uninitialized_transport_stack_reads.is_empty():
			var unchanged := vessels.duplicate(true)
			var refused := Gas.advance_remaining(vessels, conduits, reagent_map, 0.1, 1.0)
			assert(not refused.ok and "local_80" in refused.error)
			assert(vessels == unchanged)
			# Use observed machine stack bytes only in oracle verification.
			context.observed_stack_excess = _number(fixture.uninitialized_transport_stack_reads[0])
		result = Gas.advance_remaining(vessels, conduits, reagent_map, 0.1, 1.0, context)
		if not result.ok: unresolved.append([fixture.name, "transport", result.error]); continue
		for i in range(vessels.size()):
			for species in fixture.after_remaining[i].bits.contents:
				var actual := float(vessels[i].contents.get(species, 0))
				var expected := _number(fixture.after_remaining[i].bits.contents[species])
				if PackedFloat64Array([actual]).to_byte_array() != PackedFloat64Array([expected]).to_byte_array(): mismatches.append([fixture.name, "transport", i, species, actual, expected])
		for i in range(conduits.size()):
			if PackedFloat64Array([float(conduits[i].native_state_0x70)]).to_byte_array() != PackedFloat64Array([_number(fixture.connector_states[i].amount_bits)]).to_byte_array(): mismatches.append([fixture.name, "transport", i, "bubble"])
			if int(conduits[i].get("native_state_0x78", 0)) != int(fixture.connector_states[i].direction): mismatches.append([fixture.name, "transport", i, "direction"])
		tested += 1
	print(JSON.stringify({"tested": tested, "unresolved": unresolved, "bit_mismatches": mismatches}))
	if not (not unresolved.is_empty() or not mismatches.is_empty()): print("PASS test_original_gasflow")
	quit(1 if not unresolved.is_empty() or not mismatches.is_empty() else 0)
