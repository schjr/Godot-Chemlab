extends SceneTree
const Formats = preload("res://scripts/legacy_formats.gd")
const Encoding = preload("res://scripts/legacy_encoding.gd")
func _initialize() -> void:
	var count := 0
	var temporary_path := ProjectSettings.globalize_path("user://legacy-roundtrip-%d.cem" % OS.get_process_id())
	for file in ["examples.json", "molecules.json"]:
		for model in Formats.read_json("res://data/" + file):
			var path := str(model.fixture)
			var bytes := FileAccess.get_file_as_bytes(path)
			var decoded := Encoding.decode(bytes, model.format == "model")
			assert(decoded == model.raw_text, model.name + " decode")
			assert(Encoding.encode(decoded) == bytes, model.name + " byte exact round trip")
			var doc := Formats.load_document(path)
			assert(not doc.has("error"), str(doc))
			assert(doc.format == model.format)
			if doc.format == "cem":
				assert(Formats.save_document(temporary_path, doc) == OK)
				assert(FileAccess.get_file_as_bytes(temporary_path) == bytes, model.name + " saved original bytes")
			count += 1
	var extended := "中文🧪𠀀€Ā\r\n"
	assert(Encoding.decode(Encoding.encode(extended)) == extended)
	assert(Encoding.decode(extended.to_utf8_buffer()) == extended)
	assert(Encoding.decode(PackedByteArray([0x81])) == "")
	assert(DirAccess.remove_absolute(temporary_path) == OK)
	print("ENCODING VALIDATION: ", count, " original GB18030 files byte-exact; UTF-8 and four-byte Unicode passed")
	print("PASS test_legacy_encoding")
	quit()
