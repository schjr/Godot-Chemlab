extends SceneTree

const Solubility = preload("res://scripts/original/original_solubility.gd")
const Reaction = preload("res://scripts/original/original_reaction.gd")
var failures: int = 0

func check(value: bool, message: String) -> void:
	if not value:
		failures += 1
		push_error(message)

func decoded(bits: String) -> float:
	return bits.hex_decode().decode_double(0)

func decoded_map(values: Dictionary) -> Dictionary:
	var result: Dictionary = {}
	for key in values: result[key] = decoded(str(values[key]))
	return result

func _initialize() -> void:
	var fixtures: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_solubility.json"))
	check(fixtures.provenance.binary_sha256 == "7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c", "Solubility oracle must identify the recovered original binary")
	var records: Dictionary = {}
	for record in JSON.parse_string(FileAccess.get_file_as_string("res://data/reagents.json")):
		for field in fixtures.reagent_operand_bits[str(record.species)]: record[field] = decoded(str(fixtures.reagent_operand_bits[str(record.species)][field]))
		records[str(record.species)] = record
	for fixture in fixtures.cases:
		var b: Dictionary = fixture.before_bits
		var v: Dictionary = {"contents": decoded_map(b.contents), "temperature": decoded(b.temperature), "native_species_mass": decoded_map(b.masses), "native_species_volume": decoded_map(b.volumes), "solid_3cd8": decoded_map(b.solid_3cd8), "solid_3ff8": decoded_map(b.solid_3ff8)}
		var result: Dictionary = Solubility.advance(v, records, decoded(fixture.delta_bits))
		check(result.ok, "Original solubility pass must resolve: " + fixture.name + " / " + str(result))
		var metrics: Dictionary = {"contents": "contents", "masses": "native_species_mass", "volumes": "native_species_volume", "solid_3cd8": "solid_3cd8", "solid_3ff8": "solid_3ff8"}
		for metric in metrics:
			var actual: Dictionary = v[metrics[metric]]
			var expected: Dictionary = fixture.after_bits[metric]
			check(actual.keys() == expected.keys(), "Original slot names/order must match: %s / %s" % [fixture.name, metric])
			for species in expected:
				if not actual.has(species): continue
				var actual_bits: String = PackedFloat64Array([float(actual[species])]).to_byte_array().hex_encode()
				check(actual_bits == str(expected[species]), "Original solubility double mismatch: %s / %s / %s / %s != %s" % [fixture.name, metric, species, actual_bits, expected[species]])
	for fixture in fixtures.driver_cases:
		var b: Dictionary = fixture.before_bits
		var v: Dictionary = {"contents": decoded_map(b.contents), "temperature": decoded(b.temperature), "native_species_mass": decoded_map(b.masses), "native_species_volume": decoded_map(b.volumes), "solid_3cd8": decoded_map(b.solid_3cd8), "solid_3ff8": decoded_map(b.solid_3ff8)}
		var dt: float = decoded(fixture.delta_bits)
		if int(fixture.flag) == 1: check(Solubility.advance(v, records, dt).ok, "Native driver first solubility pass must execute")
		var state: Dictionary = {"moles": v.contents, "volumes": v.native_species_volume, "solid_3cd8": v.solid_3cd8, "solid_3ff8": v.solid_3ff8, "temperature": v.temperature, "heating_flag": 0, "speed_setting": 10, "liquid_height": 20.0, "smart_flag": 0, "reactions": [Reaction.normalize_record(fixture.reaction, true)]}
		check(Reaction.step_core(state, [], dt).resolved, "Native driver selected reaction must execute")
		v.contents = state.moles
		v.solid_3cd8 = state.solid_3cd8
		v.solid_3ff8 = state.solid_3ff8
		if int(fixture.flag) == 1: check(Solubility.advance(v, records, dt).ok, "Native driver second solubility pass must execute")
		for metric in ["contents", "solid_3cd8", "solid_3ff8"]:
			check(v[metric].keys() == fixture.after_bits[metric].keys(), "Driver must retain original slot order")
			for species in fixture.after_bits[metric]:
				var actual_bits: String = PackedFloat64Array([float(v[metric][species])]).to_byte_array().hex_encode()
				check(actual_bits == str(fixture.after_bits[metric][species]), "Driver original mismatch: %s / %s / %s" % [fixture.name, metric, species])
		check(PackedFloat64Array([float(state.gas_3cc0)]).to_byte_array().hex_encode() == str(fixture.gas_3cc0_bits), "Driver gas reset must follow native core")
	print("Original solubility checks: ", "PASS" if failures == 0 else "FAIL (%s)" % failures, " / ", fixtures.cases.size(), " actual native cases")
	quit(0 if failures == 0 else 1)
