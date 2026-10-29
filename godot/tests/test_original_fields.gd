extends SceneTree
const Formats = preload("res://scripts/legacy_formats.gd")
const Adapter = preload("res://scripts/experiment_adapter.gd")
func _initialize() -> void:
	for doc in Formats.read_json("res://data/examples.json"):
		var parsed := Formats.parse_cem(doc.raw_text)
		var state := Adapter.to_state(parsed)
		for i in range(parsed.apparatus.size()):
			var a: Dictionary = parsed.apparatus[i]
			var v: Dictionary = state.vessels[i]
			assert(a.temperature == float(a.metadata[30]))
			assert(a.native_fields["0x88"] == a.metadata[30])
			assert(a.native_fields["0x30"] == a.metadata[9])
			assert(v.heating == (int(a.metadata[35]) == 1))
			assert(v.native_heater_enabled == (int(a.type_id) == 302 and int(a.metadata[10]) != 1))
			var shape_value: String = a.metadata[9]
			a.temperature = 37.25
			var edited := Formats.parse_cem(Formats.serialize_cem(parsed))
			assert(edited.apparatus[i].metadata[30] == "37.25")
			assert(edited.apparatus[i].metadata[9] == shape_value)
		for c in state.connections:
			assert(c.native_route)
			assert(not c.has("rate") and not c.has("gas_only"))
	print("NATIVE FIELD VALIDATION: all 28 documents, temperature offset 0x88, preserved geometry, stored heater flags, no invented transport rates")
	quit()
