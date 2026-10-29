extends SceneTree
const Geometry = preload("res://scripts/original/original_heat_geometry.gd")
var failures: int = 0
func _initialize() -> void:
	var fixture: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_heat_geometry.json"))
	for test in fixture.cases:
		var vessels: Array = test.vessels.duplicate(true)
		var result: Dictionary = Geometry.derive(vessels, str(test.scale_bits).hex_decode().decode_double(0))
		if not result.ok:
			failures += 1
			push_error("Geometry unresolved: " + str(test.name) + " / " + str(result))
			continue
		for index in vessels.size():
			for field in test.after[index]:
				if (int(vessels[index][field]) & 0xffffffff) != int(test.after[index][field]):
					failures += 1
					push_error("Native heater geometry mismatch: %s / %s / %s = %s != %s" % [test.name, vessels[index].label, field, vessels[index][field], test.after[index][field]])
	print("Original heater geometry checks: ", "PASS" if failures == 0 else "FAIL (%s)" % failures, " / ", fixture.cases.size(), " native cases")
	quit(0 if failures == 0 else 1)
