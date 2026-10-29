class_name LegacyEncoding
extends RefCounted
## Complete GB18030 mappings generated with Python's standard codec.
static var _two: Dictionary = {}
static var _reverse: Dictionary = {}
static var _ranges: Array = []

static func _ready_tables() -> void:
	if not _two.is_empty(): return
	var tables: Variant = JSON.parse_string(FileAccess.get_file_as_string("res://data/gb18030.json"))
	if not tables is Dictionary: return
	_two = tables.two_byte
	_ranges = tables.four_byte_ranges
	for key in _two:
		_reverse[int(_two[key])] = int(key)

static func is_utf8(bytes: PackedByteArray) -> bool:
	var i := 0
	while i < bytes.size():
		var a := int(bytes[i])
		if a < 0x80:
			i += 1
			continue
		var n := 0
		var cp := 0
		var minimum := 0
		if a >= 0xc2 and a <= 0xdf: n = 1; cp = a & 31; minimum = 0x80
		elif a >= 0xe0 and a <= 0xef: n = 2; cp = a & 15; minimum = 0x800
		elif a >= 0xf0 and a <= 0xf4: n = 3; cp = a & 7; minimum = 0x10000
		else: return false
		if i + n >= bytes.size(): return false
		for j in range(1, n + 1):
			var b := int(bytes[i + j])
			if b < 0x80 or b > 0xbf: return false
			cp = (cp << 6) | (b & 63)
		if cp < minimum or cp > 0x10ffff or (cp >= 0xd800 and cp <= 0xdfff): return false
		i += n + 1
	return true

static func decode(bytes: PackedByteArray, prefer_gb18030: bool = false) -> String:
	if not prefer_gb18030 and is_utf8(bytes): return bytes.get_string_from_utf8()
	_ready_tables()
	var pieces := PackedStringArray()
	var i := 0
	while i < bytes.size():
		var a := int(bytes[i])
		if a < 0x80:
			pieces.append(String.chr(a)); i += 1; continue
		if a < 0x81 or a > 0xfe or i + 1 >= bytes.size(): return ""
		var b := int(bytes[i + 1])
		if b >= 0x30 and b <= 0x39:
			if i + 3 >= bytes.size(): return ""
			var c := int(bytes[i + 2])
			var d := int(bytes[i + 3])
			if c < 0x81 or c > 0xfe or d < 0x30 or d > 0x39: return ""
			var index := (((a - 0x81) * 10 + b - 0x30) * 126 + c - 0x81) * 10 + d - 0x30
			var cp := -1
			for r in _ranges:
				if index >= int(r[0]) and index <= int(r[1]):
					cp = int(r[2]) + index - int(r[0]); break
			if cp < 0: return ""
			pieces.append(String.chr(cp)); i += 4
		else:
			var key := str((a << 8) | b)
			if not _two.has(key): return ""
			pieces.append(String.chr(int(_two[key]))); i += 2
	return "".join(pieces)

static func encode(text: String) -> PackedByteArray:
	_ready_tables()
	var out := PackedByteArray()
	for i in range(text.length()):
		var cp := text.unicode_at(i)
		if cp < 0x80:
			out.append(cp); continue
		if _reverse.has(cp):
			var code := int(_reverse[cp])
			out.append(code >> 8); out.append(code & 255); continue
		var index := -1
		for r in _ranges:
			if cp >= int(r[2]) and cp <= int(r[2]) + int(r[1]) - int(r[0]):
				index = int(r[0]) + cp - int(r[2]); break
		if index < 0: return PackedByteArray()
		var d := index % 10 + 0x30
		index /= 10
		var c := index % 126 + 0x81
		index /= 126
		var b := index % 10 + 0x30
		index /= 10
		var a := index + 0x81
		out.append(a); out.append(b); out.append(c); out.append(d)
	return out
