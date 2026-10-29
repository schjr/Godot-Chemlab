class_name OriginalX87Host
extends RefCounted
## Exact instruction provider; never substitutes host sin/cos when unavailable.
const X87 = preload("res://scripts/original/original_x87.gd")
var pipe: FileAccess
var process_id := -1
var last_error := ""
var cache: Dictionary = {}
var extracted_path := ""
func start() -> bool:
	if pipe != null: return true
	if OS.get_name() != "macOS": last_error = "Original x87 host is not built for this platform"; return false
	var path := ProjectSettings.globalize_path("res://bin/original-x87-macos-x86_64")
	if OS.has_feature("standalone") or not path.is_absolute_path():
		var executable := FileAccess.get_file_as_bytes("res://bin/original-x87-macos-x86_64")
		if executable.is_empty(): last_error = "Original x87 instruction host is missing from the package"; return false
		path = ProjectSettings.globalize_path("user://native/original-x87-%d-%d" % [OS.get_process_id(),get_instance_id()])
		var folder_result := DirAccess.make_dir_recursive_absolute(path.get_base_dir())
		if folder_result != OK: last_error = "Original x87 instruction host directory cannot be created"; return false
		var file := FileAccess.open(path,FileAccess.WRITE)
		if file == null: last_error = "Original x87 instruction host cannot be extracted"; return false
		file.store_buffer(executable); file.close()
		extracted_path = path
		if OS.execute("/bin/chmod",["u+x",path]) != 0: last_error = "Original x87 instruction host cannot be made executable"; return false
	if not FileAccess.file_exists(path): last_error = "Original x87 instruction host is missing"; return false
	var launched := OS.execute_with_pipe(path,[],true)
	if launched.is_empty(): last_error = "Original x87 instruction host could not start"; return false
	pipe = launched.stdio; process_id = int(launched.pid)
	return true
func evaluate(value: float, kind: String) -> Array:
	if kind not in ["sin","cos","sqrt","tan"] or not is_finite(value): return []
	if kind != "sqrt" and absf(value) >= pow(2.0,53): last_error = "Original CRT large-angle reduction is not yet ported"; return []
	var bytes := PackedFloat64Array([value]).to_byte_array()
	var key := kind+bytes.hex_encode()
	if cache.has(key): return cache[key].duplicate()
	if not start(): return []
	pipe.store_8({"sin":1,"cos":2,"sqrt":3,"tan":4}[kind])
	pipe.store_buffer(bytes); pipe.flush()
	var reply := pipe.get_buffer(10)
	if reply.size() != 10: last_error = "Original x87 host returned an incomplete instruction result"; return []
	var result := X87.from_extended80_hex(reply.hex_encode())
	if result.is_empty(): last_error = "Unsupported native x87 instruction result"; return []
	cache[key] = result.duplicate(); return result
func stop() -> void:
	if pipe != null:
		pipe.store_buffer(PackedByteArray([0,0,0,0,0,0,0,0,0])); pipe.flush(); pipe.close(); pipe = null
	if process_id > 0 and OS.is_process_running(process_id): OS.kill(process_id)
	process_id = -1
	if not extracted_path.is_empty():DirAccess.remove_absolute(extracted_path);extracted_path = ""
