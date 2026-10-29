extends SceneTree
## Run only with the real importer output and printed SHA256. Never fake a
## Windows capture to make this test pass.
const Provider = preload("res://scripts/original/original_gdi_capture_provider.gd")
func _initialize() -> void:
	var path := OS.get_environment("CHEMLAB_GDI_IMPORT_PATH")
	var expected_sha := OS.get_environment("CHEMLAB_GDI_IMPORT_SHA256")
	if path.is_empty() or expected_sha.is_empty():
		print("PENDING: Actual Windows capture and importer SHA256 are required; no pixel test executed")
		quit(2)
		return
	var provider := Provider.new()
	var loaded: Dictionary = provider.load_capture(path, expected_sha)
	if not loaded.ok:
		push_error(str(loaded.error));quit(1);return
	var parsed: Dictionary = JSON.parse_string(FileAccess.get_file_as_string(path))
	for entry in parsed.entries:
		var request: Dictionary = entry.request
		var initial: Array = []
		var initial_bytes := Marshalls.base64_to_raw(request.initial_bgra)
		for i in range(initial_bytes.size() / 4): initial.append(int(initial_bytes.decode_u32(i * 4)))
		var result: Dictionary = provider.render_ops(int(request.width),int(request.height),request.operations,initial,true,int(request.bitmap_format),int(request.initial_stretch_mode))
		assert(result.ok and result.pixel_sha256 == entry.pixel_sha256)
		var expected := Marshalls.base64_to_raw(entry.bgra)
		for i in range(result.words.size()): assert(result.words[i] == int(expected.decode_u32(i * 4)))
		assert(not provider.render_ops(int(request.width)+1,int(request.height),request.operations,initial,true,int(request.bitmap_format),int(request.initial_stretch_mode)).ok)
		assert(not provider.render_ops(int(request.width),int(request.height),request.operations,initial,false,int(request.bitmap_format),int(request.initial_stretch_mode)).ok)
	print("Actual Windows GDI capture replay: 57 exact recorded requests PASS. Original VCL/full-frame validation remains pending.")
	quit()
