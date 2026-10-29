extends SceneTree

const Quantities = preload("res://scripts/original/original_quantities.gd")
const Thermal = preload("res://scripts/original/original_thermal.gd")
var failures: int = 0

func check(value: bool, message: String) -> void:
	if not value:
		failures += 1
		push_error(message)

func near(a: float, b: float) -> bool:
	return absf(a - b) < 1e-10

func _initialize() -> void:
	var fixtures: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_thermal.json"))
	check(fixtures.provenance.sha256 == "7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c", "Fixtures must identify the actual recovered binary")
	var numerical_differences: int = 0
	for original in fixtures.cases:
		var v: Dictionary = original.duplicate(true)
		# Godot's decimal JSON parsing can differ by one ULP; the oracle records exact operands.
		v.temperature = str(original.input_temperature_bits).hex_decode().decode_double(0)
		v.native_liquid_volume = str(original.input_liquid_volume_bits).hex_decode().decode_double(0)
		var exact_delta: float = str(original.input_delta_bits).hex_decode().decode_double(0)
		var result: Dictionary = Thermal.advance(v, exact_delta, Thermal.slider_multiplier(int(original.native_rate_slider)))
		check(result.ok, "Resolved original thermal fields must be accepted")
		check(near(float(v.temperature), float(original.expected_temperature)), "Thermal native branch/quantity mismatch: " + str(original))
		var actual_bits: String = PackedFloat64Array([float(v.temperature)]).to_byte_array().hex_encode()
		if actual_bits != str(original.expected_temperature_bits):
			numerical_differences += 1
			if numerical_differences <= 5: print("Native floating-point difference: ", original, " / actual ", v.temperature, " ", actual_bits)
	check(numerical_differences == 0, "Original temperature arithmetic must match native double stores exactly; mismatches: " + str(numerical_differences))
	# Quantities assertions below describe instruction branches until independent PE fixtures arrive.
	var records: Dictionary = {}
	for r in JSON.parse_string(FileAccess.get_file_as_string("res://data/reagents.json")): records[str(r.species)] = r
	var quantity_fixtures: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_quantities.json"))
	var exact_records: Dictionary = records.duplicate(true)
	for species in quantity_fixtures.reagent_operand_bits:
		for field in quantity_fixtures.reagent_operand_bits[species]:
			exact_records[species][field] = str(quantity_fixtures.reagent_operand_bits[species][field]).hex_decode().decode_double(0)
	var quantity_differences: int = 0
	for original in quantity_fixtures.cases:
		var vessel: Dictionary = {"contents": {}, "volume_ml": str(original.input_bits.volume_ml).hex_decode().decode_double(0), "native_species_volume": {}}
		for species in original.input_bits.contents: vessel.contents[species] = str(original.input_bits.contents[species]).hex_decode().decode_double(0)
		for species in original.input_bits.native_species_volume: vessel.native_species_volume[species] = str(original.input_bits.native_species_volume[species]).hex_decode().decode_double(0)
		check(Quantities.recalc(vessel, exact_records).ok, "Native quantities fixture must compute")
		var metrics: Dictionary = {"masses": "native_species_mass", "volumes": "native_species_volume", "liquid_volume": "native_liquid_volume", "solid_volume": "native_solid_volume", "gas_moles": "native_gas_moles", "gas_volume": "native_gas_volume", "pressure": "native_pressure"}
		for metric in metrics:
			var actual = vessel[metrics[metric]]
			var expected_bits = original.expected_bits[metric]
			if expected_bits is Dictionary:
				for species in expected_bits:
					var bits: String = PackedFloat64Array([float(actual[species])]).to_byte_array().hex_encode()
					if bits != str(expected_bits[species]):
						quantity_differences += 1
						if quantity_differences <= 5: print("Quantity native difference: ", metric, " ", species, " ", bits, " / ", expected_bits[species])
			else:
				var bits: String = PackedFloat64Array([float(actual)]).to_byte_array().hex_encode()
				if bits != str(expected_bits):
					quantity_differences += 1
					if quantity_differences <= 5: print("Quantity native difference: ", metric, " ", bits, " / ", expected_bits)
	check(quantity_differences == 0, "Original quantity double stores must match native fixtures; mismatches: " + str(quantity_differences))
	var q: Dictionary = {"contents": {"H2O(液体)": 1.0, "NaOH(溶解)": 0.02, "H2(气体)": 0.001, "Cu(OH)2(固体)": 0.002}, "volume_ml": 100.0, "native_species_volume": {"NaOH(溶解)": 17.0}, "native_species_volume_slots": [1.0, 17.0, 1.0, 1.0]}
	check(Quantities.recalc(q, records).ok, "Native quantity fields must compute")
	check(near(q.native_species_mass["NaOH(溶解)"], float(records["NaOH(溶解)"].molar_mass) * 0.02), "Dissolved species mass must be calculated")
	check(near(q.native_species_volume["NaOH(溶解)"], 17.0) and near(q.native_species_volume_slots[1], 17.0), "Native quantity helper must preserve dissolved species volume slots")
	check(near(q.native_gas_volume, 22.4), "Native gas volume must use 22.4 L/mol")
	check(near(q.native_liquid_volume, float(records["H2O(液体)"].molar_mass) / float(records["H2O(液体)"].density_or_render_parameter)), "Liquid volume must use actual library field8 density")
	check(near(q.native_species_volume_slots[0], q.native_liquid_volume), "Physical volume slot array must be updated")
	check(near(q.native_pressure, 0.0), "Original negative pressure is clamped to zero")
	check(Quantities.phase_suffix("Fe(OH)3(固体) note") == "(固体)", "Native phase extraction uses last parenthesis and first subsequent space")
	check(Quantities.phase_suffix("H2O(液体)ignored") == "(液体)ignored", "Native phase extraction must not guess malformed suffixes")
	var negative: Dictionary = {"contents": {"H2O(液体)": -1e-9}, "volume_ml": 100.0}
	check(Quantities.recalc(negative, records).get("stop", false), "Original negative mole check must request simulation stop")
	check(negative.native_species_mass.has("H2O(液体)"), "Native mass write precedes the negative mole check")
	var missing: Dictionary = {"contents": {"unknown": 1.0}, "volume_ml": 100.0}
	check(not Quantities.recalc(missing, records).ok, "Unresolved native reagent lookup must fail explicitly")
	print("Original quantities/thermal checks: ", "PASS" if failures == 0 else "FAIL (%s)" % failures)
	quit(0 if failures == 0 else 1)
