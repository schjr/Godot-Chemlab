class_name LegacyFormats
extends RefCounted
const METADATA_OFFSETS := ["0x00", "0x04", "0x08", "0x0c", "0x10", "0x14", "0x18", "0x20", "0x28", "0x30", "0x38", "0x3c", "0x40", "0x44", "0x48", "0x4c", "0x50", "0x54", "0x58", "0x5c", "0x60", "0x64", "0x68", "0x6c", "0x70", "0x74", "0x78", "0x7c", "0x80", "0x84", "0x88", "0x90", "0x94", "0x98", "0x9c", "0xa0", "0xa4", "0xa8", "0xb0", "0xb8"]
## Text format port of ChemLab's stored vessel and molecule records.
## Import/export supports both UTF-8 and original GB18030 encoding.

static func read_json(path: String) -> Variant:
	if not FileAccess.file_exists(path):
		return null
	return JSON.parse_string(FileAccess.get_file_as_string(path))

static func load_document(path: String) -> Dictionary:
	if not FileAccess.file_exists(path):
		return {"error": "文件不存在"}
	var bytes := FileAccess.get_file_as_bytes(path)
	var encoding := preload("res://scripts/legacy_encoding.gd")
	var prefer_gb := path.get_extension().is_empty() and bytes.size() >= 4 and bytes.slice(0, 4).get_string_from_ascii() == "2107"
	var text := encoding.decode(bytes, prefer_gb)
	if text.is_empty() and not bytes.is_empty():
		return {"error": "文件编码损坏"}
	var doc: Dictionary
	if path.get_extension().to_lower() == "cl3":
		doc = parse_cl3(text, path.get_file().get_basename())
	elif path.get_extension().to_lower() == "cem":
		doc = parse_cem(text, path.get_file().get_basename())
	elif text.begins_with("2107"):
		doc = parse_model(text, path.get_file())
	else:
		var value: Variant = JSON.parse_string(text)
		return value if value is Dictionary else {"error": "无法识别文件格式"}
	doc["legacy_encoding"] = "utf-8" if not prefer_gb and encoding.is_utf8(bytes) else "gb18030"
	doc["raw_text"] = text
	return doc

static func _lines(text: String) -> PackedStringArray:
	var lines := text.replace("\r", "").split("\n")
	if lines.size() > 0 and lines[-1].is_empty():
		lines.remove_at(lines.size() - 1)
	return lines

static func parse_cem(text: String, title: String = "实验") -> Dictionary:
	var lines := _lines(text)
	if lines.size() < 5 or not lines[0].contains("仿真化学实验室"):
		return {"error": "需要 UTF-8 格式的 ChemLab 实验文件"}
	var apparatus: Array = []
	var p := 5
	for _index in range(int(lines[1])):
		if p + 41 > lines.size():
			return {"error": "容器记录不完整"}
		var meta := lines.slice(p, p + 40)
		var obj := {"id": int(meta[0]), "name": meta[1], "type_id": int(meta[2]),
			"x": float(meta[4]), "y": float(meta[5]), "capacity": float(meta[8]),
			"temperature": float(meta[30]), "metadata": meta, "chemicals": [], "reactions": []}
		obj["native_fields"] = {}
		for field in range(40): obj.native_fields[METADATA_OFFSETS[field]] = meta[field]
		p += 40
		var count := int(lines[p])
		p += 1
		if count < 0 or p + count * 3 >= lines.size():
			return {"error": "药品记录不完整"}
		for _chemical in range(count):
			obj.chemicals.append({"name": lines[p], "mass": float(lines[p + 1]), "moles": float(lines[p + 2]), "raw_mass": lines[p + 1], "raw_moles": lines[p + 2]})
			p += 3
		count = int(lines[p])
		p += 1
		for _reaction in range(count):
			if p + 4 > lines.size():
				return {"error": "反应记录不完整"}
			var id := lines[p]
			var name := lines[p + 1]
			var nr := int(lines[p + 2])
			var np := int(lines[p + 3])
			p += 4
			if nr < 0 or np < 0 or p + (nr + np) * 2 + 5 > lines.size():
				return {"error": "方程式记录不完整"}
			var sides: Array = []
			for size in [nr, np]:
				var side: Array = []
				for _item in range(size):
					side.append({"name": lines[p], "coefficient": int(lines[p + 1])})
					p += 2
				sides.append(side)
			var tail := lines.slice(p, p + 5)
			p += 5
			obj.reactions.append({"id": id, "name": name, "reactants": sides[0], "products": sides[1], "parameters": tail, "direction": tail[4]})
		if p + 20 > lines.size():
			return {"error": "模拟参数不完整"}
		obj["simulation_fields"] = lines.slice(p, p + 20)
		p += 20
		apparatus.append(obj)
	var connectors: Array = []
	for _connector in range(int(lines[3])):
		if p + 25 > lines.size():
			return {"error": "导管记录不完整"}
		var rec := lines.slice(p, p + 25)
		p += 25
		connectors.append({"id": int(rec[0]), "name": rec[1], "start": [float(rec[2]), float(rec[3])], "end": [float(rec[4]), float(rec[5])], "from_vessel": rec[11], "to_vessel": rec[14], "metadata": rec})
	for vessel in apparatus:
		for chemical in vessel.chemicals:
			if p + 2 > lines.size():
				return {"error": "药品变量记录不完整"}
			chemical["moles_variable"] = lines[p]
			chemical["mass_variable"] = lines[p + 1]
			p += 2
	var doc := {"name": title, "format": "cem", "apparatus": apparatus, "connectors": connectors, "header": lines.slice(0, 5), "trailing_lines": lines.slice(p), "raw_lines": lines}
	doc.merge(preload("res://scripts/experiment_adapter.gd").parse_trailer(lines.slice(p)))
	return doc

static func _atom(atoms: Array, lookup: Dictionary, label: String, coords: PackedStringArray, scale: float) -> int:
	if label.is_empty():
		return -1
	if not lookup.has(label):
		var element := label.left(1)
		if label.length() > 1 and label[1] >= "a" and label[1] <= "z":
			element += label[1]
		lookup[label] = atoms.size()
		atoms.append({"element": element, "label": label,
			"position": [float(coords[0]) / scale, float(coords[1]) / scale, float(coords[2]) / scale],
			"legacy_position": [float(coords[0]), float(coords[1]), float(coords[2])]})
	return int(lookup[label])

static func parse_cl3(text: String, title: String = "分子") -> Dictionary:
	var lines := _lines(text)
	if lines.size() < 62 or lines[0] != "2107":
		return {"error": "需要 UTF-8 格式的 ChemLab 三维文件"}
	var atoms: Array = []
	var bonds: Array = []
	var lookup: Dictionary = {}
	var seen: Dictionary = {}
	var p := 61
	for _group in range(int(lines[60])):
		if p >= lines.size():
			return {"error": "分子记录不完整"}
		var count := int(lines[p])
		p += 1
		if count < 0 or p + count * 46 > lines.size():
			return {"error": "分子连接记录不完整"}
		for _record in range(count):
			var rec := lines.slice(p, p + 46)
			p += 46
			var a := _atom(atoms, lookup, rec[2], rec.slice(3, 6), 10.0)
			for slot in range(4):
				var s := rec.slice(6 + slot * 10, 16 + slot * 10)
				var b := _atom(atoms, lookup, s[1], s.slice(2, 5), 10.0)
				if a >= 0 and b >= 0 and not s[6].is_empty():
					var low := mini(a, b)
					var high := maxi(a, b)
					var key := str(low) + ":" + str(high)
					if not seen.has(key):
						seen[key] = true
						bonds.append({"a": low, "b": high, "order": maxi(1, int(s[5])), "label": s[6]})
	if p >= lines.size():
		return {"error": "导入分子记录不完整"}
	var free_count := int(lines[p])
	p += 1
	for _free_group in range(free_count):
		if p + 3 > lines.size():
			return {"error": "导入分子标题不完整"}
		var na := int(lines[p + 1])
		var nb := int(lines[p + 2])
		p += 3
		if na < 0 or nb < 0 or p + na * 109 + nb * 111 > lines.size():
			return {"error": "导入分子几何数据不完整"}
		var group_atoms: Array = []
		for _a in range(na):
			var rec := lines.slice(p, p + 109)
			p += 109
			var idx := _atom(atoms, lookup, rec[0], rec.slice(3, 6), 1.0)
			if idx >= 0:
				group_atoms.append(idx)
				atoms[idx]["radius"] = float(rec[2])
				atoms[idx]["color"] = [float(rec[6]), float(rec[7]), float(rec[8])]
		for _b in range(nb):
			var rec := lines.slice(p, p + 111)
			p += 111
			var ends: Array = []
			for xyz in [rec.slice(1, 4), rec.slice(4, 7)]:
				var found := -1
				for idx in group_atoms:
					var v: Array = atoms[idx].position
					if Vector3(v[0], v[1], v[2]).distance_squared_to(Vector3(float(xyz[0]), float(xyz[1]), float(xyz[2]))) < 0.00000001:
						found = idx
						break
				ends.append(found)
			if ends[0] >= 0 and ends[1] >= 0:
				bonds.append({"a": ends[0], "b": ends[1], "order": 1, "label": rec[0]})
	return {"name": title, "format": "cl3", "atoms": atoms, "bonds": bonds, "settings": lines.slice(0, 61), "trailing_lines": lines.slice(p), "raw_lines": lines}

static func _preserved_number(value: Variant, original: String) -> String:
	return original if original.is_valid_float() and float(value) == float(original) else str(value)

static func serialize_cem(doc: Dictionary) -> String:
	var out := PackedStringArray(doc.get("header", ["仿真化学实验室 金华科 V3.0", "0", "0", "0", "0"]))
	var vessels: Array = doc.get("apparatus", [])
	var connectors: Array = doc.get("connectors", [])
	out[1] = str(vessels.size())
	out[3] = str(connectors.size())
	for vessel in vessels:
		var meta := PackedStringArray(vessel.get("metadata", []))
		if meta.size() != 40:
			return ""
		for pair in [[0, "id"], [2, "type_id"], [4, "x"], [5, "y"], [8, "capacity"], [30, "temperature"]]:
			if vessel.has(pair[1]):
				meta[pair[0]] = _preserved_number(vessel[pair[1]], meta[pair[0]])
		meta[1] = str(vessel.get("name", meta[1]))
		out.append_array(meta)
		var chemicals: Array = vessel.get("chemicals", [])
		out.append(str(chemicals.size()))
		# Match the original triplets to retain decimal formatting when unchanged.
		for chemical in chemicals:
			out.append(str(chemical.name))
			for key in ["mass", "moles"]:
				out.append(_preserved_number(chemical.get(key, 0), str(chemical.get("raw_" + key, ""))))
		var reactions: Array = vessel.get("reactions", [])
		out.append(str(reactions.size()))
		for reaction in reactions:
			out.append(str(reaction.id))
			out.append(str(reaction.name))
			out.append(str(reaction.reactants.size()))
			out.append(str(reaction.products.size()))
			for side in [reaction.reactants, reaction.products]:
				for item in side:
					out.append(str(item.name))
					out.append(str(item.coefficient))
			var params := PackedStringArray(reaction.parameters)
			params[4] = str(reaction.get("direction", params[4]))
			out.append_array(params)
		out.append_array(PackedStringArray(vessel.get("simulation_fields", [])))
	for connector in connectors:
		var meta := PackedStringArray(connector.metadata)
		for pair in [[2, connector.start[0]], [3, connector.start[1]], [4, connector.end[0]], [5, connector.end[1]]]:
			meta[pair[0]] = _preserved_number(pair[1], meta[pair[0]])
		meta[11] = str(connector.from_vessel)
		meta[14] = str(connector.to_vessel)
		out.append_array(meta)
	for vessel in vessels:
		for chemical in vessel.chemicals:
			out.append(str(chemical.get("moles_variable", "")))
			out.append(str(chemical.get("mass_variable", "")))
	out.append_array(PackedStringArray(doc.get("trailing_lines", [])))
	# Preserve every lexical value on unchanged numeric records, including long precision.
	var originals := PackedStringArray(doc.get("raw_lines", []))
	if out.size() == originals.size():
		for i in range(out.size()):
			if out[i].is_valid_float() and originals[i].is_valid_float() and float(out[i]) == float(originals[i]):
				out[i] = originals[i]
	return "\r\n".join(out) + "\r\n"

static func serialize_cl3(doc: Dictionary) -> String:
	return str(doc.raw_text) if doc.has("raw_text") else "\r\n".join(PackedStringArray(doc.get("raw_lines", []))) + "\r\n"

static func save_document(path: String, doc: Dictionary) -> Error:
	var text := serialize_cem(doc) if path.get_extension().to_lower() == "cem" else serialize_cl3(doc) if path.get_extension().to_lower() == "cl3" else JSON.stringify(doc, "\t")
	if text.is_empty():
		return ERR_INVALID_DATA
	var file := FileAccess.open(path, FileAccess.WRITE)
	if file == null:
		return FileAccess.get_open_error()
	if doc.get("legacy_encoding", "gb18030") == "gb18030" and path.get_extension().to_lower() in ["cem", "cl3"]:
		var bytes := preload("res://scripts/legacy_encoding.gd").encode(text)
		if bytes.is_empty() and not text.is_empty(): return ERR_INVALID_DATA
		file.store_buffer(bytes)
	else:
		file.store_string(text)
	return OK

static func parse_model(text: String, title: String = "分子") -> Dictionary:
	var lines := _lines(text)
	if lines.size() < 7 or lines[0] != "2107":
		return {"error": "模型格式无法识别"}
	var na := int(lines[2])
	var nb := int(lines[3])
	if na < 0 or nb < 0 or 7 + na * 9 + nb * 7 != lines.size():
		return {"error": "模型几何记录不完整"}
	var atoms: Array = []
	var bonds: Array = []
	var lookup: Dictionary = {}
	var p := 7
	for _a in range(na):
		var rec := lines.slice(p, p + 9)
		p += 9
		var idx := _atom(atoms, lookup, rec[0], rec.slice(6, 9), 1.0)
		atoms[idx]["radius"] = float(rec[2])
		atoms[idx]["color"] = [float(rec[3]), float(rec[4]), float(rec[5])]
	for _b in range(nb):
		var rec := lines.slice(p, p + 7)
		p += 7
		var ends: Array = []
		for xyz in [rec.slice(1, 4), rec.slice(4, 7)]:
			var found := -1
			for idx in range(atoms.size()):
				var v: Array = atoms[idx].position
				if Vector3(v[0], v[1], v[2]).distance_squared_to(Vector3(float(xyz[0]), float(xyz[1]), float(xyz[2]))) < 0.00000001:
					found = idx
					break
			ends.append(found)
		if ends[0] >= 0 and ends[1] >= 0:
			bonds.append({"a": ends[0], "b": ends[1], "order": 1, "label": rec[0]})
	return {"name": title, "format": "model", "atoms": atoms, "bonds": bonds, "raw_lines": lines, "raw_text": text}
