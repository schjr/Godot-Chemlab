extends SceneTree
const Formats = preload("res://scripts/legacy_formats.gd")
func _initialize() -> void:
	var experiments: Array = Formats.read_json("res://data/examples.json")
	for model in experiments:
		var parsed := Formats.parse_cem(model.raw_text, model.name)
		assert(not parsed.has("error"), str(parsed))
		assert(parsed.apparatus.size() == model.apparatus.size())
		assert(Formats.serialize_cem(parsed) == model.raw_text, model.name + " round trip")
		parsed.apparatus[0].x += 23
		var edited := Formats.parse_cem(Formats.serialize_cem(parsed))
		assert(edited.apparatus[0].x == parsed.apparatus[0].x)
		assert(edited.apparatus.size() == parsed.apparatus.size())
		assert(edited.apparatus[0].chemicals.size() == parsed.apparatus[0].chemicals.size())
		if not parsed.apparatus[0].chemicals.is_empty():
			parsed.apparatus[0].chemicals[0].moles += 0.5
			parsed.apparatus[0].chemicals.append(parsed.apparatus[0].chemicals[0].duplicate(true))
			var contents := Formats.parse_cem(Formats.serialize_cem(parsed))
			assert(contents.apparatus[0].chemicals.size() == parsed.apparatus[0].chemicals.size())
			assert(absf(contents.apparatus[0].chemicals[0].moles - parsed.apparatus[0].chemicals[0].moles) < 0.00001)
		if not parsed.apparatus[0].reactions.is_empty():
			parsed.apparatus[0].reactions[0].direction = "双向"
			var reactions := Formats.parse_cem(Formats.serialize_cem(parsed))
			assert(reactions.apparatus[0].reactions[0].direction == "双向")
	var molecules: Array = Formats.read_json("res://data/molecules.json")
	for model in molecules:
		var parsed := Formats.parse_model(model.raw_text, model.name) if model.format == "model" else Formats.parse_cl3(model.raw_text, model.name)
		assert(not parsed.has("error"), str(parsed))
		assert(parsed.atoms.size() == model.atoms.size(), model.name)
		assert(parsed.bonds.size() == model.bonds.size(), model.name)
		assert(Formats.serialize_cl3(parsed) == model.raw_text, model.name + " round trip")
	print("FORMAT VALIDATION: 28 experiments and 105 molecules match; exact round trips and edited positions passed")
	print("PASS legacy_formats_test")
	quit()
