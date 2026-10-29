class_name OriginalGDICaptureProvider
extends RefCounted
## Exact whole-request replay of validated Windows pixels. No shape inference,
## color substitution, nearest geometry, or VCL production attestation.
const Raster = preload("res://scripts/original/original_material_rasterizer.gd")
const CORPUS_SHA256 := "dc4656123ec877953b2cbbc53b2ba630df0cc942119ff6b4516994c49a631ea1"
const BINARY_SHA256 := "7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c"
var _capture: Dictionary = {}
func _error(message: String) -> Dictionary:
	return {"ok":false, "error":message, "boundary":"Exact recorded Windows GDI request"}
func _sha(raw: PackedByteArray) -> String:
	var ctx := HashingContext.new()
	ctx.start(HashingContext.HASH_SHA256)
	ctx.update(raw)
	return ctx.finish().hex_encode()
func load_capture(path: String, expected_import_sha256: String) -> Dictionary:
	_capture.clear()
	if expected_import_sha256.length() != 64: return _error("A trusted imported-file SHA256 is required")
	var file := FileAccess.open(path, FileAccess.READ)
	if file == null or file.get_length() > 32 * 1024 * 1024: return _error("Missing or oversized imported GDI capture")
	var raw := file.get_buffer(file.get_length())
	if _sha(raw) != expected_import_sha256: return _error("Imported GDI file hash differs")
	var value = JSON.parse_string(raw.get_string_from_utf8())
	if not value is Dictionary: return _error("Imported GDI file is not a dictionary")
	if value.get("format", "") != "chemlab-exact-gdi-capture-v1" or value.get("native_vcl_verified", true) != false: return _error("Capture format or unsupported VCL attestation differs")
	if value.get("corpus_sha256", "") != CORPUS_SHA256 or value.get("original_binary_sha256", "") != BINARY_SHA256 or value.get("guti_sha256", "") != Raster.GUTI_SHA256: return _error("Capture native/corpus/texture identity differs")
	var entries = value.get("entries")
	if not entries is Array or entries.size() != 57: return _error("Capture case set is incomplete")
	var ids := {}
	for entry in entries:
		if not entry is Dictionary or not entry.get("request") is Dictionary: return _error("Malformed capture entry")
		var id := str(entry.get("id", ""))
		if id.is_empty() or ids.has(id): return _error("Duplicate capture entry")
		ids[id] = true
		var request: Dictionary = entry.request
		var width := int(request.get("width", 0))
		var height := int(request.get("height", 0))
		if width <= 0 or height <= 0 or width > 256 or height > 256: return _error("Capture bitmap geometry differs")
		var pixels := Marshalls.base64_to_raw(str(entry.get("bgra", "")))
		if pixels.size() != width * height * 4 or _sha(pixels) != entry.get("pixel_sha256", ""): return _error("Capture pixel size or hash differs")
	_capture = value
	return {"ok":true,"cases":entries.size(),"capture_sha256":value.capture_sha256,"native_vcl_verified":false}
func _equal(a: Variant, b: Variant) -> bool:
	if a is Dictionary and b is Dictionary:
		if a.size() != b.size(): return false
		for key in a:
			if not b.has(key) or not _equal(a[key], b[key]): return false
		return true
	if a is Array and b is Array:
		if a.size() != b.size(): return false
		for i in range(a.size()):
			if not _equal(a[i], b[i]): return false
		return true
	# JSON integral numeric fields may load as float; no rounding/truncation.
	if (a is int or a is float) and (b is int or b is float): return a == b
	return typeof(a) == typeof(b) and a == b
func render_ops(width: int, height: int, operations: Array, initial_words: Array = [], probe: bool = false, bitmap_format: int = 32, initial_stretch_mode: int = 1) -> Dictionary:
	if not probe: return _error("Recorded GDI profile has no original live VCL verification; explicit probe mode is required")
	if _capture.is_empty(): return _error("No validated actual Windows GDI capture is loaded")
	if not initial_words.is_empty() and initial_words.size() != width * height: return _error("Initial bitmap dimensions differ")
	var initial := PackedByteArray()
	if not initial_words.is_empty():
		initial.resize(initial_words.size() * 4)
		for i in range(initial_words.size()):
			if not initial_words[i] is int or initial_words[i] < 0 or initial_words[i] > 0xFFFFFFFF: return _error("Initial word is not native unsigned32")
			initial.encode_u32(i * 4, initial_words[i])
	var initial_bgra := "" if initial.is_empty() else Marshalls.raw_to_base64(initial)
	var request := {"width":width,"height":height,"operations":operations,"initial_bgra":initial_bgra,"bitmap_format":bitmap_format,"initial_stretch_mode":initial_stretch_mode}
	for entry in _capture.entries:
		if not _equal(request, entry.request): continue
		var raw := Marshalls.base64_to_raw(entry.bgra)
		var words: Array = []
		words.resize(width * height)
		for i in range(words.size()): words[i] = int(raw.decode_u32(i * 4))
		return {"ok":true,"words":words,"image":Raster.words_to_image(words,width,height),"capture_case":entry.id,"capture_sha256":_capture.capture_sha256,"pixel_sha256":entry.pixel_sha256,"stretch_mode":entry.stretch_mode,"probe_only":true,"native_vcl_verified":false}
	return _error("No exact captured request: geometry, operations/colors, initial pixels, format and DC stretch state must all match")
