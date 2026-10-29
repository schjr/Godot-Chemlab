extends SceneTree
## Compare against actual original x86 oracle output, not replacement formulas.
const Transfer = preload("res://scripts/original/original_transfer.gd")
var failures := 0

func _initialize() -> void:
	var fixture_path := ProjectSettings.globalize_path("res://").path_join("../evidence/original_logic/transfer-rawbits-from-native.json").simplify_path()
	var fixture: Dictionary = JSON.parse_string(FileAccess.get_file_as_string(fixture_path))
	var reagents: Dictionary = {}
	for species in fixture["reagents"]:
		var record: Dictionary = fixture["reagents"][species]
		reagents[species] = {"molar_mass": _decode(record["molar_mass_bits"]), "density_or_render_parameter": String.num(_decode(record["density_bits"]), 17)}
	var vessels: Array = []
	for before in fixture["before"]:
		var vessel := _decode_vessel(before)
		# Native oracle explicitly allocates zeroed 100-slot arrays. Retain those
		# exact unused caches rather than assuming an unknown native slot is zero.
		var slots: Array = []
		slots.resize(100)
		slots.fill(0.0)
		var index := 0
		for name in vessel["contents"]:
			slots[index] = vessel["native_species_volume"][name]
			index += 1
		vessel["native_species_volume_slots"] = slots
		vessels.append(vessel)
	var result: Dictionary = Transfer.move_liquid(vessels, 0, 1, _decode(fixture["requested_bits"]), reagents)
	check(result["ok"], "Native transfer unexpectedly rejected: " + str(result))
	for index in range(vessels.size()):
		var expected: Dictionary = fixture["after"][index]
		for field in expected:
			if expected[field] is Dictionary:
				check(vessels[index][field].keys() == expected[field].keys(), "Native species order changed: " + field)
				for species in expected[field]:
					check(_bits(float(vessels[index][field].get(species, INF))) == expected[field][species], "Original double bits differ: vessel %d %s/%s expected %s actual %s" % [index, field, species, expected[field][species], _bits(float(vessels[index][field].get(species, INF)))])
			else:
				check(_bits(float(vessels[index][field])) == expected[field], "Original double bits differ: vessel %d %s expected %s actual %s" % [index, field, expected[field], _bits(float(vessels[index][field]))])
	print("Original liquid-transfer oracle comparison: %s; source/target species order and every recorded binary64 field" % ("PASS" if failures == 0 else "FAIL (%d)" % failures))
	quit(0 if failures == 0 else 1)

func check(value: bool, message: String) -> void:
	if not value:
		failures += 1
		push_error(message)

func _decode(bits: String) -> float:
	return bits.hex_decode().decode_double(0)

func _bits(value: float) -> String:
	return PackedFloat64Array([value]).to_byte_array().hex_encode()

func _decode_vessel(source: Dictionary) -> Dictionary:
	var result: Dictionary = {}
	for field in source:
		if source[field] is Dictionary:
			result[field] = {}
			for name in source[field]:
				result[field][name] = _decode(source[field][name])
		else:
			result[field] = _decode(source[field])
	return result
