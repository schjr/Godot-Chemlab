class_name ExperimentAdapter
extends RefCounted
static var _molar_masses: Dictionary = {}
const TYPE_KINDS := {101:"sg0",102:"sb100",103:"zxp100",104:"ydsp100",105:"pdsp100",106:"blg",107:"jqp",108:"uxg",121:"zfm_50",201:"gkp",202:"xkp",204:"jtdg_2",207:"ssddg",208:"jsddg",209:"ld",210:"cjld",211:"fyld",212:"shuic",301:"tiejt0",302:"jjd",303:"wendj",311:"bolb",316:"wood",318:"image",1000:"annotation",2000:"button",3000:"chart"}

static func _molar_mass(species: String) -> float:
	if _molar_masses.is_empty():
		var data: Variant = JSON.parse_string(FileAccess.get_file_as_string("res://data/reagents.json"))
		if data is Array:
			for chemical in data:
				_molar_masses[str(chemical.get("species", chemical.name))] = float(chemical.get("molar_mass", 0))
	return float(_molar_masses.get(species, 0))

static func kind_for(v: Dictionary) -> String:
	var typ := int(v.type_id)
	var kind := str(TYPE_KINDS.get(typ, "unknown"))
	var meta := PackedStringArray(v.get("metadata", []))
	var size := absf(float(meta[3])) if meta.size() > 3 else float(v.get("capacity", 100))
	if typ == 102:
		kind = "sb500" if size >= 500 else "sb200" if size >= 200 else "sb100"
	elif typ == 103:
		kind = "zxp250" if size >= 250 else "zxp100"
	elif typ == 101:
		kind = "sg97" if size >= 90 else "sg45" if size >= 40 else "sg0"
	elif typ == 107 and meta.size() > 3 and float(meta[3]) < 0:
		kind = "djqp"
	return kind

static func _resolve(endpoint: String, names: Dictionary, connectors: Dictionary, visited: Array) -> int:
	if names.has(endpoint): return int(names[endpoint])
	if visited.has(endpoint) or not connectors.has(endpoint): return -1
	var next := visited.duplicate()
	next.append(endpoint)
	var c: Dictionary = connectors[endpoint]
	for label in [c.from_vessel, c.to_vessel]:
		var found := _resolve(str(label), names, connectors, next)
		if found >= 0: return found
	return -1

static func to_state(doc: Dictionary) -> Dictionary:
	var vessels: Array = []
	var links: Array = []
	var names: Dictionary = {}
	var bindings: Array = []
	for i in range(doc.get("apparatus", []).size()):
		var old: Dictionary = doc.apparatus[i]
		var meta := PackedStringArray(old.get("metadata", []))
		var sim := PackedStringArray(old.get("simulation_fields", []))
		var contents: Dictionary = {}
		var ids: Array = []
		var rates: Dictionary = {}
		var defs: Dictionary = {}
		for chemical in old.get("chemicals", []):
			contents[str(chemical.name)] = float(chemical.moles)
			for pair in [["moles_variable", "moles"], ["mass_variable", "mass"]]:
				var variable := str(chemical.get(pair[0], ""))
				if not variable.is_empty():
					bindings.append({"name": variable, "vessel_id": i + 1, "species": chemical.name, "metric": pair[1]})
		for reaction in old.get("reactions", []):
			var key := str(reaction.name)
			ids.append(key)
			var params := PackedStringArray(reaction.parameters)
			if params.size() == 5:
				rates[key] = maxf(0.0, float(params[2]))
				defs[key] = {"id": key, "condition": params[1], "reaction_rate": float(params[2]), "equilibrium_degree_or_constant": float(params[3]), "equilibrium_mode": params[4], "reaction_heat": float(params[0]), "reactants": [], "products": []}
				for side in ["reactants", "products"]:
					for item in reaction[side]:
						defs[key][side].append({"species": item.name, "coefficient": item.coefficient})
		var v := {"id": i + 1, "legacy_index": i, "legacy_name": old.name, "legacy_type_id": old.type_id, "type_id": old.type_id, "kind": kind_for(old), "label": old.name, "position": [old.x, old.y], "contents": contents, "temperature": float(old.temperature), "volume_ml": maxf(1.0, float(old.capacity)), "legacy_capacity": old.capacity, "heating": meta.size() > 35 and int(meta[35]) == 1, "strong_heat": false, "burning": int(old.type_id) == 302 and meta.size() > 10 and int(meta[10]) != 1, "light": false, "electrolysis": false, "discharge": false, "sealed": false, "open": true, "smart": meta.size() > 36 and int(meta[36]) == 1, "consider_ions": sim.size() > 0 and int(sim[0]) == 1, "consider_extended": true, "dissolution": sim.size() > 1 and int(sim[1]) == 1, "reaction_ids": ids, "rate_overrides": rates, "reaction_overrides": defs, "reaction_extents": {}}
		v["native_reaction_records"] = []
		for reaction_index in old.get("reactions", []).size():
			var record: Dictionary = preload("res://scripts/original/original_reaction.gd").normalize_record(old.reactions[reaction_index], true)
			record["native_cem_source_index"] = reaction_index
			v.native_reaction_records.append(record)
		v["native_binding_names"] = {}
		for chemical in old.get("chemicals", []): v.native_binding_names[str(chemical.name)]={"moles":str(chemical.get("moles_variable","")),"mass":str(chemical.get("mass_variable",""))}
		v["native_moles"] = contents.duplicate()
		v["native_masses"] = {}
		for chemical in old.get("chemicals", []): v.native_masses[str(chemical.name)] = float(chemical.mass)
		v["native_fields"] = old.get("native_fields", {}).duplicate(true)
		v["native_metadata"] = meta
		v["native_control_records"] = [
			{"state": int(meta[10]), "start_offset": [int(meta[11]), int(meta[12])], "end_offset": [int(meta[13]), int(meta[14])], "color_integer": int(meta[15]), "native_state_offset": "0x38"},
			{"state": int(meta[16]), "start_offset": [int(meta[17]), int(meta[18])], "end_offset": [int(meta[19]), int(meta[20])], "color_integer": int(meta[21]), "native_state_offset": "0x50"},
			{"state": int(meta[22]), "subtype": int(meta[23]), "start_offset": [int(meta[24]), int(meta[25])], "end_offset": [int(meta[26]), int(meta[27])], "native_state_offset": "0x68"}]
		v["native_simulation_fields"] = sim
		v["native_heater_enabled"] = int(old.type_id) == 302 and meta.size() > 10 and int(meta[10]) != 1
		v["native_parent_name"] = meta[28] if meta.size() > 28 else ""
		v["native_parent_type"] = int(meta[29]) if meta.size() > 29 else 0
		vessels.append(v)
		names[str(old.name)] = i + 1
	var connector_names: Dictionary = {}
	var connected_pairs: Dictionary = {}
	for c in doc.get("connectors", []): connector_names[str(c.name)] = c
	for i in range(doc.get("connectors", []).size()):
		var c: Dictionary = doc.connectors[i]
		var source := _resolve(str(c.from_vessel), names, connector_names, [str(c.name)])
		var target := _resolve(str(c.to_vessel), names, connector_names, [str(c.name)])
		var pair := str(source) + ":" + str(target)
		if source >= 0 and target >= 0 and source != target and not connected_pairs.has(pair):
			connected_pairs[pair] = true
			links.append({"source": source, "target": target, "native_route": true, "legacy_index": i, "start": c.start, "end": c.end})
	var trailer := parse_trailer(PackedStringArray(doc.get("trailing_lines", [])))
	for i in range(trailer.get("charts", []).size()):
		var chart: Dictionary = trailer.charts[i]
		vessels.append({"id": vessels.size() + 1, "kind": "chart", "label": "曲线", "position": chart.position.duplicate(), "size": [240,240], "native_chart_record": Array(chart.metadata), "contents": {}, "temperature": 20.0, "volume_ml": 1.0, "legacy_chart_index": i, "series": chart.series.duplicate(true), "chart_series": chart.series.duplicate(true), "smart": false, "reaction_ids": [], "rate_overrides": {}, "reaction_extents": {}})
	for i in range(mini(trailer.get("apparatus_labels", []).size(), doc.get("apparatus", []).size())):
		vessels[i].native_label_record = trailer.apparatus_labels[i].duplicate(true)
		vessels[i].native_label_rect = trailer.apparatus_labels[i].bounds.duplicate()
	var variables: Dictionary = {}
	for record in trailer.get("variables", []):
		variables[str(record.name)] = float(record.value) if str(record.value).is_valid_float() else 0.0
	for binding in bindings:
		var v: Dictionary = vessels[int(binding.vessel_id) - 1]
		var value := float(v.contents.get(str(binding.species), 0.0))
		if binding.metric == "mass": value *= _molar_mass(str(binding.species))
		variables[str(binding.name)] = value
	return {"version": 1, "native_label_counter": int(doc.header[2]) if doc.get("header",[]).size() > 2 else 0, "name": doc.get("name", "实验"), "vessels": vessels, "connections": links, "native_connectors": doc.get("connectors", []).duplicate(true), "native_buttons": trailer.get("native_buttons", []).duplicate(true), "native_canvas_scale": trailer.get("native_canvas_scale", 1.0), "elapsed": 0.0, "events": [], "bindings": bindings, "variables": variables, "legacy_variables": trailer.get("variables", []), "annotations": trailer.get("annotations", []), "decorators": trailer.get("annotations", []), "charts": trailer.get("charts", []), "program": trailer.get("program", ""), "program_groups": trailer.get("program_groups", [])}

static func _cem_reaction_record(record: Dictionary, originals: Array) -> Dictionary:
	# The native editor owns complete ordered records. Names/IDs are not unique
	# row handles; retain the original source row through swaps and deletions.
	var source_index := int(record.get("native_cem_source_index", -1))
	var result: Dictionary = {}
	if source_index >= 0 and source_index < originals.size():
		var source: Dictionary = originals[source_index]
		if str(source.name) == str(record.get("name", "")) and str(source.id) == str(record.get("id", "")):
			result = source.duplicate(true)
	var raw_parameters: Variant = record.get("parameters", null)
	if not record.has("id") or not record.has("name") or not (raw_parameters is Array or raw_parameters is PackedStringArray) or raw_parameters.size() != 5:
		return {"error": "原始反应记录不完整，无法保存 CEM。"}
	result["id"] = str(record.id)
	result["name"] = str(record.name)
	for side in ["reactants", "products"]:
		if not record.get(side, null) is Array: return {"error": "原始反应物或生成物记录不完整。"}
		var rows: Array = []
		for item in record[side]:
			if not item is Dictionary or not item.has("coefficient"): return {"error": "原始方程式记录不完整。"}
			rows.append({"name":str(item.get("species", item.get("name", ""))), "coefficient":int(item.coefficient)})
		result[side] = rows
	var parameters: Array = Array(record.parameters).duplicate()
	for pair in [[0,"reaction_heat"], [2,"reaction_rate"], [3,"equilibrium_degree_or_constant"]]:
		if not record.has(pair[1]): return {"error": "原始反应数值字段不完整。"}
		# Keep source spelling when the native field is unchanged. An edited
		# field must come from the committed record, never an ID-keyed mirror.
		if float(parameters[pair[0]]) != float(record[pair[1]]): parameters[pair[0]] = str(record[pair[1]])
	parameters[1] = str(record.get("condition", parameters[1]))
	parameters[4] = str(record.get("equilibrium_mode", parameters[4]))
	result["parameters"] = parameters
	result["direction"] = parameters[4]
	return result

static func from_state(doc: Dictionary, state: Dictionary) -> Dictionary:
	var out := doc.duplicate(true)
	var original_program := str(parse_trailer(PackedStringArray(doc.get("trailing_lines", []))).get("program", ""))
	if state.has("program") and str(state.program) != original_program:
		return {"error": "修改后的程序请保存为 ChemLab JSON，以保留代码"}
	var vessels: Array = []
	var names: Dictionary = {}
	var deltas: Dictionary = {}
	for v in state.get("vessels", []):
		if v.get("kind", "") == "chart" and v.has("legacy_chart_index"):
			continue
		var index := int(v.get("legacy_index", -1))
		if index < 0 or index >= doc.get("apparatus", []).size():
			return {"error": "新器材没有原始格式记录，请保存为 ChemLab JSON"}
		var old: Dictionary = doc.apparatus[index].duplicate(true)
		for field in range(40):
			var offset: String = preload("res://scripts/legacy_formats.gd").METADATA_OFFSETS[field]
			if v.get("native_fields",{}).has(offset) and str(v.native_fields[offset]) != str(old.metadata[field]):
				old.metadata[field] = str(v.native_fields[offset])
		var delta := [float(v.position[0]) - float(old.x), float(v.position[1]) - float(old.y)]
		deltas[int(v.id)] = delta
		old.x = v.position[0]
		old.y = v.position[1]
		old.temperature = v.temperature
		if float(v.get("volume_ml", 1.0)) != maxf(1.0, float(old.capacity)):
			old.capacity = v.volume_ml
		old.name = str(v.get("label", old.name))
		names[int(v.id)] = old.name
		var chemicals: Array = []
		for species in v.contents:
			var chemical: Dictionary = {}
			for prior in old.chemicals:
				if str(prior.name) == str(species):
					chemical = prior.duplicate(true)
					break
			if chemical.is_empty():
				if _molar_mass(str(species)) <= 0.0:
					return {"error": "新药品的原始质量信息未知，请保存为 ChemLab JSON"}
				chemical = {"name": species, "mass": 0.0, "moles": 0.0, "moles_variable": "", "mass_variable": ""}
			var molar_mass := float(chemical.mass) / float(chemical.moles) if float(chemical.moles) > 0.0 else _molar_mass(str(species))
			var n := float(v.contents[species])
			if n != float(chemical.moles) and molar_mass <= 0.0 and n > 0.0:
				return {"error": "药品摩尔质量未知，请保存为 ChemLab JSON"}
			var previous_moles := float(chemical.moles)
			chemical.moles = n
			var native_masses: Variant = v.get("native_species_mass", v.get("native_masses", null))
			if native_masses is Dictionary:
				if not native_masses.has(species): return {"error": "原始药品质量字段尚未恢复，无法保存 CEM。"}
				chemical.mass = float(native_masses[species])
			elif n != previous_moles and molar_mass > 0.0:
				chemical.mass = n * molar_mass
			chemicals.append(chemical)
		old.chemicals = chemicals
		old.metadata[36] = "1" if v.get("smart", false) else "0"
		old.simulation_fields[0] = "1" if v.get("consider_ions", false) else "0"
		if v.has("native_reaction_records"):
			var reactions: Array = []
			for record in v.native_reaction_records:
				var exported := _cem_reaction_record(record, old.reactions)
				if exported.has("error"): return exported
				reactions.append(exported)
			old.reactions = reactions
		else:
			for reaction in old.reactions:
				if v.get("rate_overrides", {}).has(str(reaction.name)):
					if float(reaction.parameters[2]) != float(v.rate_overrides[str(reaction.name)]):
						reaction.parameters[2] = str(v.rate_overrides[str(reaction.name)])
		vessels.append(old)
	var updated_connectors: Dictionary = {}
	for link in state.get("connections", []):
		var index := int(link.get("legacy_index", -1))
		if index < 0 or index >= doc.get("connectors", []).size():
			return {"error": "新导管没有原始格式记录，请保存为 ChemLab JSON"}
		var c: Dictionary = doc.connectors[index].duplicate(true)
		if str(c.from_vessel) not in doc.connectors.map(func(item): return str(item.name)):
			c.from_vessel = names[int(link.source)]
		if str(c.to_vessel) not in doc.connectors.map(func(item): return str(item.name)):
			c.to_vessel = names[int(link.target)]
		for pair in [["start", int(link.source)], ["end", int(link.target)]]:
			c[pair[0]][0] += deltas[pair[1]][0]
			c[pair[0]][1] += deltas[pair[1]][1]
		updated_connectors[index] = c
	var removed_names: Array = []
	for original in doc.get("apparatus", []):
		if original.name not in names.values(): removed_names.append(original.name)
	var connectors: Array = []
	for i in range(doc.get("connectors", []).size()):
		var c: Dictionary = updated_connectors.get(i, doc.connectors[i]).duplicate(true)
		if c.from_vessel not in removed_names and c.to_vessel not in removed_names:
			connectors.append(c)
	out.apparatus = vessels
	out.connectors = connectors
	if state.get("native_connectors",[]).size() == doc.get("connectors",[]).size():
		for i in out.connectors.size():
			if PackedStringArray(state.native_connectors[i].metadata) != PackedStringArray(doc.connectors[i].metadata):
				out.connectors[i] = state.native_connectors[i].duplicate(true)
	var original_trailer := PackedStringArray(doc.get("trailing_lines", []))
	var trailer := parse_trailer(original_trailer)
	var annotations: Array = state.get("annotations", trailer.annotations)
	if annotations.size() != trailer.annotations.size():
		return {"error": "新增或删除的文字请保存为 ChemLab JSON"}
	for i in annotations.size():
		var original: Dictionary = trailer.annotations[i]
		for axis in 2:
			if float(annotations[i].position[axis]) != float(original.position[axis]):
				original_trailer[int(original.line_offset) + 1 + axis] = str(annotations[i].position[axis])
	for v in state.get("vessels", []):
		if not v.has("native_label_rect"): continue
		var index := int(v.get("legacy_index", -1))
		if index < 0 or index >= trailer.apparatus_labels.size(): continue
		var original: Dictionary = trailer.apparatus_labels[index]
		for field in 4:
			if int(v.native_label_rect[field]) != int(original.bounds[field]):
				original_trailer[int(original.line_offset) + 1 + field] = str(v.native_label_rect[field])
	var buttons: Array = state.get("native_buttons",trailer.native_buttons)
	if buttons.size() != trailer.native_buttons.size():
		return {"error": "按钮数量已修改，请保存为 ChemLab JSON"}
	for i in buttons.size():
		var original: Dictionary = trailer.native_buttons[i]
		for pair in [[1,buttons[i].position[0]],[2,buttons[i].position[1]],[16,buttons[i].size[0]],[17,buttons[i].size[1]]]:
			if int(pair[1]) != int(original.metadata[pair[0]]):
				original_trailer[int(original.line_offset)+int(pair[0])] = str(pair[1])
	var chart_start := 1 + int(original_trailer[0]) * 7
	var chart_end := chart_start + 1 + int(original_trailer[chart_start]) * 55
	var records: Array = []
	for v in state.get("vessels", []):
		if v.get("kind", "") != "chart": continue
		var index := int(v.get("legacy_chart_index", -1))
		if index < 0 or index >= trailer.get("charts", []).size():
			return {"error": "新曲线没有原始格式记录，请保存为 ChemLab JSON"}
		var rec := PackedStringArray(trailer.charts[index].metadata)
		if v.has("native_chart_record"):
			if v.native_chart_record.size() != 55:
				return {"error": "曲线的原始记录长度错误"}
			# Keep unchanged spelling/precision and all opaque fields. Only the
			# source-defined editable axis/series fields are replaced.
			for field in [3,4,5,6,17,18,26,27,35,36,44,45,53,54]:
				var edited := str(v.native_chart_record[field])
				if field < 7:
					if float(edited) != float(rec[field]): rec[field] = edited
				elif edited != rec[field]: rec[field] = edited
		rec[1] = str(v.position[0])
		rec[2] = str(v.position[1])
		var series: Array = v.get("series", v.get("chart_series", []))
		for i in range(mini(5, series.size()) if not v.has("native_chart_record") else 0):
			rec[17 + i * 9] = str(series[i].get("x_variable", rec[17 + i * 9]))
			rec[18 + i * 9] = str(series[i].get("y_variable", rec[18 + i * 9]))
		records.append(rec)
	var revised := original_trailer.slice(0, chart_start)
	revised.append(str(records.size()))
	for record in records: revised.append_array(record)
	revised.append_array(original_trailer.slice(chart_end))
	out.trailing_lines = revised
	return out

static func parse_trailer(lines: PackedStringArray) -> Dictionary:
	var variables: Array = []
	var annotations: Array = []
	var charts: Array = []
	var groups: Array = []
	var result := {"variables": variables, "annotations": annotations, "charts": charts, "program": "", "program_groups": groups, "apparatus_labels": [], "native_buttons": []}
	if lines.is_empty(): return result
	var p := 1
	for _variable in range(int(lines[0])):
		if p + 7 > lines.size(): return result
		var rec := lines.slice(p, p + 7)
		p += 7
		variables.append({"name": rec[3], "description": rec[4], "value": rec[5], "record": rec})
	if p >= lines.size(): return result
	var count := int(lines[p])
	p += 1
	for _chart in range(count):
		if p + 55 > lines.size(): return result
		var rec := lines.slice(p, p + 55)
		p += 55
		var series: Array = []
		for slot in range(5):
			var entry := rec.slice(10 + slot * 9, 19 + slot * 9)
			if entry[7] != "数值0" or entry[8] != "数值0":
				series.append({"x_variable": entry[7], "y_variable": entry[8], "color_integer": int(entry[0]), "metadata": entry})
		charts.append({"kind": "chart", "position": [float(rec[1]), float(rec[2])], "size": [240, 240], "series": series, "metadata": rec, "size_is_new_display_default": false})
	if p >= lines.size(): return result
	count = int(lines[p])
	p += 1
	for _annotation in range(count):
		if p + 16 > lines.size(): return result
		var rec := lines.slice(p, p + 16)
		p += 16
		var n := int(rec[15])
		if n < 0 or p + n > lines.size(): return result
		annotations.append({"kind": "annotation", "position": [float(rec[1]), float(rec[2])], "size": [float(rec[3]), float(rec[4])], "color_integer": int(rec[6]), "font_size": abs(int(rec[7])), "font": rec[14], "text": "\n".join(lines.slice(p, p + n)), "metadata": rec, "line_offset":p-16})
		p += n
	if p >= lines.size(): return result
	count = int(lines[p])
	p += 1
	var program := PackedStringArray()
	for _group in range(count):
		if p + 4 > lines.size(): return result
		var meta := lines.slice(p, p + 4)
		p += 4
		var n := int(meta[0])
		if n < 0 or p + n > lines.size(): return result
		var code := lines.slice(p, p + n)
		p += n
		groups.append({"metadata": meta, "lines": code, "program": "\n".join(code)})
		program.append_array(code)
	result.program = "\n".join(program)
	# Native CEM version3 footer, loader13194..13560: scale,26-field buttons,
	# then16-field apparatus label/font records with memo line count.
	if p < lines.size(): result.native_canvas_scale = float(lines[p]); p += 1
	if p >= lines.size(): return result
	count = int(lines[p]); p += 1
	for _button in range(count):
		if p+26>lines.size(): return result
		var record := lines.slice(p,p+26); p += 26
		result.native_buttons.append({"metadata":record,"active":int(record[0]),"position":[int(record[1]),int(record[2])],"size":[int(record[16]),int(record[17])],"line_offset":p-26})
	while p+16<=lines.size():
		var record := lines.slice(p,p+16); p += 16
		var n := int(record[15])
		if n<0 or p+n>lines.size(): return result
		result.apparatus_labels.append({"metadata":record,"bounds":[int(record[1]),int(record[2]),int(record[3]),int(record[4])],"text":"\n".join(lines.slice(p,p+n)),"line_offset":p-16})
		p += n
	result.trailer_consumed = p
	return result
