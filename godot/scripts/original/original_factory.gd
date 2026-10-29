class_name OriginalFactory
extends RefCounted
## Finite original palette factory specialization, verified from actual native
## 0x00453A28 and 0x00417EE0 metadata-writing creation kernels.
## Native bitmap/list/region object ownership remains a declared rendering boundary.

const METADATA_OFFSETS := ["0x00", "0x04", "0x08", "0x0c", "0x10", "0x14", "0x18", "0x20", "0x28", "0x30", "0x38", "0x3c", "0x40", "0x44", "0x48", "0x4c", "0x50", "0x54", "0x58", "0x5c", "0x60", "0x64", "0x68", "0x6c", "0x70", "0x74", "0x78", "0x7c", "0x80", "0x84", "0x88", "0x90", "0x94", "0x98", "0x9c", "0xa0", "0xa4", "0xa8", "0xb0", "0xb8"]
const EXPECTED_SHA: String = "7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c"
static var _templates: Dictionary = {}

static func _load() -> Dictionary:
	if not _templates.is_empty(): return {"ok": true}
	var parsed = JSON.parse_string(FileAccess.get_file_as_string("res://data/original_factory_templates.json"))
	if not parsed is Dictionary or not parsed.get("templates", null) is Dictionary or parsed.get("provenance", {}).get("binary_sha256", "") != EXPECTED_SHA:
		return {"ok": false, "error": "原始器件创建模板缺失或来源不符。"}
	_templates = parsed.templates
	return {"ok": true}

static func choices() -> Array:
	if not _load().ok: return []
	return _templates.keys()

static func create(kind: String, position: Vector2, id: int, native_label_counter = null) -> Dictionary:
	var loaded: Dictionary = _load()
	if not loaded.ok: return loaded
	if not _templates.has(kind):
		return {"ok": false, "error": "此对象的原始创建分支尚未移植：" + kind, "native_function": "0x00417EE0"}
	if native_label_counter == null:
		return {"ok": false, "error": "原始创建计数器 +DAT_005877A0 必须由调用方提供；不能从对象 ID 推测。"}
	var counter: int = int(native_label_counter)
	if counter < -2147483648 or counter > 2147483647: return {"ok": false, "error": "原始创建计数器超出有符号 32 位范围。"}
	if not is_finite(position.x) or not is_finite(position.y): return {"ok": false, "error": "原始鼠标整数坐标无效。"}
	var x: int = int(position.x)
	var y: int = int(position.y)
	if x < -2147483648 or x > 2147483647 or y < -2147483648 or y > 2147483647:
		return {"ok": false, "error": "原始鼠标坐标超出有符号 32 位范围。"}
	var source: Dictionary = _templates[kind]
	var fields: Dictionary = source.native_fields.duplicate(true)
	# Native CString prefix and decimal creation counter are separate from the live-array index.
	fields["0x04"] = "容器" + str(counter)
	fields["0x10"] = x
	fields["0x14"] = y
	var metadata: PackedStringArray = []
	for offset in METADATA_OFFSETS: metadata.append(str(fields[offset]))
	var simulation: PackedStringArray = []
	for value in source.native_simulation_fields: simulation.append(str(int(value)))
	var control_records: Array = [
		{"state": int(fields["0x38"]), "start_offset": [int(fields["0x3c"]), int(fields["0x40"])], "end_offset": [int(fields["0x44"]), int(fields["0x48"])], "color_integer": int(fields["0x4c"]), "native_state_offset": "0x38"},
		{"state": int(fields["0x50"]), "start_offset": [int(fields["0x54"]), int(fields["0x58"])], "end_offset": [int(fields["0x5c"]), int(fields["0x60"])], "color_integer": int(fields["0x64"]), "native_state_offset": "0x50"},
		{"state": int(fields["0x68"]), "subtype": int(fields["0x6c"]), "start_offset": [int(fields["0x70"]), int(fields["0x74"])], "end_offset": [int(fields["0x78"]), int(fields["0x7c"])], "native_state_offset": "0x68"},
	]
	var vessel: Dictionary = {"id": id, "kind": kind, "type_id": int(fields["0x08"]), "label": str(fields["0x04"]), "position": [x, y], "temperature": float(fields["0x88"]), "volume_ml": float(fields["0x28"]), "contents": {}, "native_reaction_records": [], "native_fields": fields, "native_metadata": metadata, "native_simulation_fields": simulation, "native_control_records": control_records, "native_bitmap_files": source.bitmap_files.duplicate(), "native_sprite_width": int(source.sprite_size[0]), "native_sprite_height": int(source.sprite_size[1]), "native_type_parameter": int(fields["0x0c"]), "native_cap_flag": int(fields["0x38"]), "native_flame_style": int(fields["0x50"]), "native_flame_width": int(fields["0x5c"]), "native_flame_height": int(fields["0x60"]), "native_platform_mode": int(fields["0x6c"]), "native_platform_offset": int(fields["0x7c"]), "native_attachment": str(fields["0x80"]), "native_ignition": int(fields["0x9c"]), "native_heating": int(fields["0xa0"]), "native_rate_slider": int(source.native_simulation_fields[2]), "native_liquid_volume": 0.0, "native_gas_moles": 0.0, "native_gas_volume": 0.0, "native_pressure": float(fields["0xa8"])}
	if not source.bitmap_files.is_empty(): vessel.native_texture_kind = str(source.bitmap_files[0]).get_basename()
	# +0x4338 and unused per-species numeric cells are not initialized by the
	# original constructor: intentionally do not manufacture their values here.
	var next_counter: int = (counter + 1) & 0xffffffff
	if next_counter >= 0x80000000: next_counter -= 0x100000000
	return {"ok": true, "vessel": vessel, "next_native_label_counter": next_counter, "native_creation_entry": source.entry}
