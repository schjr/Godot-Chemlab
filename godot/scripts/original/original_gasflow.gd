class_name OriginalGasflow
extends RefCounted
const X87 = preload("res://scripts/original/original_x87.gd")
const Quantities = preload("res://scripts/original/original_quantities.gd")
const INERT := "惰性气体(气体)"
const CONVERSION_A := "3bdf4f8d976e1283f53f"
const CONVERSION_B := "1fba6ddbb66ddbb6fa3f"
static var _routes: Array = []

static func _less_pair(a: Array, b: Array) -> bool:
	return float(a[0]) < float(b[0]) or (float(a[0]) == float(b[0]) and float(a[1]) < float(b[1]))

static func _error(message: String) -> Dictionary:
	return {"ok": false, "resolved": false, "error": message}

static func _field(v: Dictionary, offset: String, key: String, fallback: Variant = null) -> Variant:
	if v.get("native_fields", {}).has(offset): return v.native_fields[offset]
	return v.get(key, fallback)

static func _type(v: Dictionary) -> int:
	return int(_field(v, "0x08", "type_id", -1))

static func _number(pair: Array) -> float:
	return X87.stored_double(pair)

static func _inert_amount(volume: Array) -> Array:
	if volume.is_empty(): return []
	# 48EBC9/46F3E5 store the difference to QWORD before the two x87
	# products. 48EBCC..48EBDD/46F418..46F42A multiply A*volume, then B.
	var converted := X87.multiply(X87.from_extended80_hex(CONVERSION_A), _number(volume))
	return X87.multiply_pair(converted, X87.from_extended80_hex(CONVERSION_B))

static func initialize_air(vessels: Array, reagent_map: Dictionary) -> Dictionary:
	# FUN_0048E9B4; source placeholder name is not "空气".
	if not reagent_map.has(INERT): return _error("原药品库缺少惰性气体记录。")
	var copies := vessels.duplicate(true)
	for v in copies:
		if not v.get("contents", null) is Dictionary or not v.has("native_liquid_volume"): return _error("原始气体初始化缺少药品数组或液体体积。")
		if not v.has("native_species_mass"): v.native_species_mass = {}
		if not v.has("native_species_volume"): v.native_species_volume = {}
		# Existing slot is reset; an absent slot is appended at the end.
		v.contents[INERT] = 0.0
		v.native_species_mass[INERT] = 0.0
		v.native_species_volume[INERT] = 0.0
		var capacity := float(_field(v, "0x28", "volume_ml", 0.0))
		var free_volume := _number(X87.add([capacity, 0.0], -float(v.native_liquid_volume)))
		var gas_moles := 0.0
		for species in v.contents:
			if Quantities.phase_suffix(str(species)) == "(气体)": gas_moles = _number(X87.add([float(v.contents[species]), 0.0], gas_moles))
		var gas_volume := X87.multiply(X87.multiply([gas_moles, 0.0], 22.4), 1000.0)
		if gas_volume.is_empty(): return _error("原始气体体积算术未解析。")
		var stored_gas_volume := _number(gas_volume)
		if stored_gas_volume < free_volume:
			var amount := _inert_amount(X87.add([free_volume, 0.0], -stored_gas_volume))
			if amount.is_empty(): return _error("原始惰性气体转换算术未解析。")
			v.contents[INERT] = _number(amount)
			v.native_species_mass[INERT] = _number(X87.multiply([float(reagent_map[INERT].molar_mass), 0.0], float(v.contents[INERT])))
	for i in range(vessels.size()): vessels[i].merge(copies[i], true)
	return {"ok": true, "resolved": true, "native_entry": "0048E9B4"}

static func _submerged_receiver(vessels: Array, selected: int) -> Dictionary:
	# FUN_0046EABC; first qualifying stored object, no guessed vessel-type filter.
	var own: Dictionary = vessels[selected]
	if not own.has("native_bitmap_height"): return _error("原始倒置气瓶高度未解析。")
	var x := int(own.position[0])
	var own_bottom := int(own.position[1]) + int(int(own.native_bitmap_height) / 2)
	for i in range(vessels.size()):
		if i == selected: continue
		var v: Dictionary = vessels[i]
		if not v.has("native_bitmap_width") or not v.has("native_bitmap_height") or (not v.has("native_liquid_height") and not v.get("native_fields", {}).has("0x30")): return _error("原始浸没位置需要位图尺寸与液柱高度。")
		var half_width := int(int(v.native_bitmap_width) / 2)
		var bottom := int(v.position[1]) + int(int(v.native_bitmap_height) / 2)
		if int(v.position[0]) - half_width + 3 < x - 8 and x + 8 < half_width + int(v.position[0]) - 3 and own_bottom < bottom:
			var surface := X87.add([float(bottom), 0.0], -float(v.get("native_liquid_height", v.get("native_fields", {}).get("0x30", 0.0))))
			if surface.is_empty(): return _error("原始浸没表面算术未解析。")
			if _number(surface) < float(own_bottom): return {"ok": true, "index": i}
	return {"ok": true, "index": -1}

static func _gas_totals(v: Dictionary, reagents: Dictionary) -> Dictionary:
	var n := 0.0
	var mass := 0.0
	for species in v.contents:
		if Quantities.phase_suffix(str(species)) != "(气体)": continue
		if not reagents.has(str(species)): return _error("原始气体摩尔质量查找失败。")
		n = _number(X87.add([float(v.contents[species]), 0.0], n))
		var added := X87.add(X87.multiply([float(reagents[species].molar_mass), 0.0], float(v.contents[species])), mass)
		if added.is_empty(): return _error("原始气体质量算术未解析。")
		mass = _number(added)
	return {"ok": true, "moles": n, "mass": mass}

static func _subtract_fraction(value: float, numerator: float, denominator: float) -> Array:
	var taken := X87.divide(X87.multiply([value, 0.0], numerator), denominator)
	if taken.is_empty(): return []
	return X87.add_pair([value, 0.0], X87.multiply(taken, -1.0))

static func advance_open(vessels: Array, reagent_map: Dictionary) -> Dictionary:
	# FUN_0046EC50, including original orientation/molar-mass displacement.
	var copies := vessels.duplicate(true)
	for index in range(copies.size()):
		var v: Dictionary = copies[index]
		var typ := _type(v)
		if typ <= 100 or typ >= 300 or int(_field(v, "0x38", "native_mouth_state", -1)) != 0: continue
		if not v.has("native_liquid_volume") or not v.get("native_species_mass", null) is Dictionary: return _error("原始开放气体处理缺少数量缓存。")
		var capacity := float(_field(v, "0x28", "volume_ml", 0.0))
		var free := maxf(0.0, _number(X87.add([capacity, 0.0], -float(v.native_liquid_volume))))
		var totals := _gas_totals(v, reagent_map)
		if not totals.ok: return totals
		if float(totals.moles) < 1e-20: continue
		var gas_volume := _number(X87.multiply(X87.multiply([float(totals.moles), 0.0], 22.4), 1000.0))
		var orientation := int(_field(v, "0x18", "native_orientation", -1))
		var submerged := -1
		if typ == 107 and orientation == 1:
			var found := _submerged_receiver(copies, index)
			if not found.ok: return found
			submerged = int(found.index)
		if typ == 107 and orientation == 1 and submerged != -1:
			if float(v.native_liquid_volume) > 1e-10 and free < gas_volume:
				var excess := _number(X87.add([gas_volume, 0.0], -free))
				for species in v.contents:
					if Quantities.phase_suffix(str(species)) not in ["(液体)", "(溶解)"]: continue
					var mass := _subtract_fraction(float(v.native_species_mass[species]), excess, float(v.native_liquid_volume))
					var moles := _subtract_fraction(float(v.contents[species]), excess, float(v.native_liquid_volume))
					if mass.is_empty() or moles.is_empty(): return _error("原始排水比例算术未解析。")
					v.native_species_mass[species] = _number(mass)
					v.contents[species] = _number(moles)
					if float(v.native_species_mass[species]) < 0.0 or float(v.contents[species]) < 0.0:
						v.native_species_mass[species] = 0.0
						v.contents[species] = 0.0
		else:
			if orientation in [0, 1]:
				var mean := X87.divide([float(totals.mass), 0.0], float(totals.moles))
				if mean.is_empty(): return _error("原始气体平均质量算术未解析。")
				var boundary := X87.add(mean, -0.01 if orientation == 0 else 0.01)
				for species in v.contents:
					if Quantities.phase_suffix(str(species)) != "(气体)": continue
					var molar_mass := float(reagent_map[species].molar_mass)
					var remove := molar_mass < _number(boundary) if orientation == 0 else _number(boundary) < molar_mass
					if remove:
						v.native_species_mass[species] = 0.0
						v.contents[species] = 0.0
			totals = _gas_totals(v, reagent_map)
			gas_volume = _number(X87.multiply(X87.multiply([float(totals.moles), 0.0], 22.4), 1000.0))
			if gas_volume < free:
				if not v.contents.has(INERT): return _error("原始惰性气体槽未初始化。")
				var increased := X87.add(_inert_amount(X87.add([free, 0.0], -gas_volume)), float(v.contents[INERT]))
				if increased.is_empty(): return _error("原始气体回填算术未解析。")
				v.contents[INERT] = _number(increased)
		var recalculated := Quantities.recalc(v, reagent_map)
		if not recalculated.ok: return recalculated
		free = maxf(0.0, _number(X87.add([capacity, 0.0], -float(v.native_liquid_volume))))
		totals = _gas_totals(v, reagent_map)
		gas_volume = _number(X87.multiply(X87.multiply([float(totals.moles), 0.0], 22.4), 1000.0))
		if free < gas_volume and gas_volume > 1e-20:
			var excess := _number(X87.add([gas_volume, 0.0], -free))
			for species in v.contents:
				if Quantities.phase_suffix(str(species)) != "(气体)": continue
				v.native_species_mass[species] = _number(_subtract_fraction(float(v.native_species_mass[species]), excess, gas_volume))
				v.contents[species] = _number(_subtract_fraction(float(v.contents[species]), excess, gas_volume))
		recalculated = Quantities.recalc(v, reagent_map)
		if not recalculated.ok: return recalculated
	for i in range(vessels.size()): vessels[i].merge(copies[i], true)
	return {"ok": true, "resolved": true, "native_entry": "0046EC50"}

static func _surface(v: Dictionary) -> Dictionary:
	if not v.has("native_bitmap_height") or not v.has("native_liquid_height"): return _error("原始导管端点缺少位图/液柱高度。")
	var bottom := int(v.position[1]) + int(int(v.native_bitmap_height) / 2)
	var pair := X87.add([float(bottom), 0.0], -float(v.native_liquid_height))
	if pair.is_empty(): return _error("原始导管浸没算术未解析。")
	return {"ok": true, "value": _number(pair), "pair": pair}

static func _resolve_conduit(records: Array, index: int, side: int, context: Dictionary) -> Dictionary:
	# FUN_0046CEE0: marks each visited record; 1001 follows side 2,1002 side 1.
	context.visited[index] = true
	context.last = index
	var rec: Array = records[index]
	var typ := int(rec[12 if side == 1 else 15])
	var name := str(rec[11 if side == 1 else 14])
	if typ > 100 and typ < 300:
		context.end_connector = str(rec[1])
		context.end_selector = side
		return {"ok": true, "name": name}
	if typ == 0: return {"ok": true, "name": "空"}
	if typ not in [1001, 1002]: return _error("原始导管连接类型未解析：" + str(typ))
	var next := -1
	for i in range(records.size()):
		if str(records[i][1]) == name: next = i; break
	if next < 0: return _error("原始导管名称查找失败：" + name)
	if context.visited.has(next): return {"ok": true, "name": "导管封闭"}
	return _resolve_conduit(records, next, 2 if typ == 1001 else 1, context)

static func advance_conduits(vessels: Array, raw_connectors: Array, _reagent_map: Dictionary, _delta: float, _scale: float) -> Dictionary:
	# FUN_0046D414 builds the ordered pressure-sharing graph, not a guessed rate.
	_routes = []
	var names: Dictionary = {}
	for i in range(vessels.size()):
		var v: Dictionary = vessels[i]
		var name := str(_field(v, "0x04", "legacy_name", v.get("label", "")))
		if not names.has(name): names[name] = i
	var records: Array = []
	for c in raw_connectors:
		if not c.has("metadata") or c.metadata.size() != 25: return _error("原始25字段导管记录缺失。")
		records.append(Array(c.metadata))
	var context := {"visited": {}, "last": -1, "end_connector": "", "end_selector": 0}
	for index in range(records.size()):
		if context.visited.has(index): continue
		var rec: Array = records[index]
		# Both endpoint branches run for a direct vessel-vessel record, even after
		# the first branch marks it visited. Native keeps both pressure-sharing rows.
		for side in [1, 2]:
			var typ := int(rec[12 if side == 1 else 15])
			if typ <= 100 or typ >= 300: continue
			var source_name := str(rec[11 if side == 1 else 14])
			if not names.has(source_name): return _error("原始容器名称查找失败：" + source_name)
			context.end_connector = ""
			context.end_selector = 0
			var resolved := _resolve_conduit(records, index, 2 if side == 1 else 1, context)
			if not resolved.ok: return resolved
			if _routes.size() >= 100: return _error("原始流路超过100条。")
			var source: Dictionary = vessels[int(names[source_name])]
			var surface := _surface(source)
			if not surface.ok: return surface
			var source_flag := 1 if int(_field(source, "0x38", "native_mouth_state", -1)) == 0 or _less_pair(surface.pair, [float(rec[3]), 0.0]) else 0
			# The second endpoint branch also uses record+0x0c (first endpoint Y).
			var destination_flag := 0
			var last: Array = records[int(context.last)]
			for chain_side in [1, 2]:
				if int(last[12 if chain_side == 1 else 15]) not in [1001, 1002]: continue
				var opposite := 2 if chain_side == 1 else 1
				var end_type := int(last[12 if opposite == 1 else 15])
				if end_type == 0: destination_flag = 1
				if end_type > 100 and end_type < 300:
					var end_name := str(last[11 if opposite == 1 else 14])
					if not names.has(end_name): return _error("原始终端容器查找失败。")
					var end: Dictionary = vessels[int(names[end_name])]
					var end_surface := _surface(end)
					if not end_surface.ok: return end_surface
					if int(_field(end, "0x38", "native_mouth_state", -1)) == 0 or _less_pair(end_surface.pair, [float(last[3 if opposite == 1 else 5]), 0.0]): destination_flag = 1
			var mode: int = [[0, 1, -1], [-1, 2, -1], [1, 1, 2]][source_flag][destination_flag]
			var destination_name := str(resolved.name)
			if destination_name not in ["空", "导管封闭"]:
				if not names.has(destination_name): return _error("原始目标容器查找失败。")
				var destination: Dictionary = vessels[int(names[destination_name])]
				if not source.has("native_pressure") or not destination.has("native_pressure"): return _error("原始导管压力缓存缺失。")
				if float(source.native_pressure) <= float(destination.native_pressure):
					if mode == 0: mode = -1
					elif mode == 1: mode = 2
				else:
					if mode == 0: mode = 1
					elif mode == -1: mode = 2
			else:
				if mode == 0: mode = 1
				elif mode == -1: mode = 2
			_routes.append({"mode": mode, "source_name": source_name, "target_name": destination_name, "source_connector": str(rec[1]), "target_connector": str(context.end_connector), "source_selector": side, "target_selector": int(context.end_selector), "amount": 0.0})
	for route in _routes:
		if int(route.mode) == -1:
			for keys in [["source_name", "target_name"], ["source_connector", "target_connector"], ["source_selector", "target_selector"]]:
				var saved: Variant = route[keys[0]]
				route[keys[0]] = route[keys[1]]
				route[keys[1]] = saved
			route.mode = 1
	for route_index in range(_routes.size()):
		var route: Dictionary = _routes[route_index]
		if int(route.mode) != 1: continue
		if str(route.source_name) in ["空", "导管封闭"]: return _error("原始流路源为空/封闭导管。")
		var degree := 1
		for other_index in range(_routes.size()):
			var other: Dictionary = _routes[other_index]
			if other_index != route_index and int(other.mode) == 1 and str(other.source_name) == str(route.source_name): degree += 1
		var source: Dictionary = vessels[int(names[str(route.source_name)])]
		var amount := X87.divide([float(source.native_pressure), 0.0], float(degree))
		if amount.is_empty(): return _error("原始分路压力除法未解析。")
		route.amount = maxf(0.0, _number(amount))
	var visited: Array = []
	for i in range(records.size()):
		visited.append(1 if context.visited.has(i) else 0)
		raw_connectors[i]["native_state_0x44"] = 0
		raw_connectors[i]["native_state_0x4c"] = visited[-1]
	return {"ok": true, "resolved": true, "native_entry": "0046D414", "native_network": _routes.duplicate(true), "visited": visited}

static func advance_remaining(vessels: Array, raw_connectors: Array, _reagent_map: Dictionary, _delta: float, _scale: float, native_context: Dictionary = {}) -> Dictionary:
	# FUN_0046F704. Cached gas totals stay unchanged throughout this phase.
	var copies := vessels.duplicate(true)
	var connectors := raw_connectors.duplicate(true)
	var names: Dictionary = {}
	for i in range(copies.size()):
		var name := str(_field(copies[i], "0x04", "legacy_name", copies[i].get("label", "")))
		if not names.has(name): names[name] = i
	var connector_names: Dictionary = {}
	for i in range(connectors.size()): connector_names[str(connectors[i].metadata[1])] = i
	var excess_defined := native_context.has("observed_stack_excess")
	var last_excess := float(native_context.get("observed_stack_excess", 0.0))
	# An explicit observation remains the diagnostic override. Production may
	# instead bind the actual physical local in its owned source-ABI stack.
	var owned_stack:bool=not excess_defined and (native_context.has("source_stack_read_excess") or native_context.has("source_stack_write_excess"))
	for route in _routes:
		if int(route.mode) != 1: continue
		if not names.has(str(route.source_name)): return _error("原始气体流路源查找失败。")
		var source: Dictionary = copies[int(names[str(route.source_name)])]
		if not source.has("native_gas_moles"): return _error("原始气体流路摩尔总量缓存缺失。")
		var total := float(source.native_gas_moles)
		var amount := float(route.amount)
		var fraction := 0.0
		if absf(amount) > 1e-20 and total > 1e-20:
			var divided := X87.divide([amount, 0.0], total)
			if divided.is_empty(): return _error("原始气体分路比例未解析。")
			fraction = maxf(0.0, _number(divided))
		var target_name := str(route.target_name)
		for species in source.contents.keys():
			if Quantities.phase_suffix(str(species)) != "(气体)": continue
			var current := float(source.contents[species])
			var transfer := 0.0
			if target_name == "导管封闭": continue
			if target_name == "空":
				if not source.has("native_liquid_volume"): return _error("原始开放导管液体缓存缺失。")
				var free := _number(X87.add([float(_field(source, "0x28", "volume_ml", 0.0)), 0.0], -float(source.native_liquid_volume)))
				var gas_total := 0.0
				for item in source.contents:
					if Quantities.phase_suffix(str(item)) == "(气体)": gas_total = _number(X87.add([float(source.contents[item]), 0.0], gas_total))
				var gas_volume := _number(X87.multiply(X87.multiply([gas_total, 0.0], 22.4), 1000.0))
				if free < gas_volume:
					last_excess = _number(X87.add([gas_volume, 0.0], -free))
					excess_defined = true
					if owned_stack:
						var writer:Variant=native_context.get("source_stack_write_excess",null)
						if not writer is Callable or not writer.is_valid():return _error("Original46FADA stack store boundary is unavailable")
						var stored:Variant=writer.call(last_excess)
						if not stored is Dictionary or stored.get("ok",null)!=true:return _error(str(stored.get("error","Original46FADA stack store failed")) if stored is Dictionary else "Original46FADA stack store response is malformed")
				if gas_volume >= 1e-100:
					if owned_stack:
						var reader:Variant=native_context.get("source_stack_read_excess",null)
						if not reader is Callable or not reader.is_valid():return _error("Original46FB18 physical stack read boundary is unavailable")
						var loaded:Variant=reader.call()
						if not loaded is Dictionary or loaded.get("ok",null)!=true or not loaded.get("value",null) is float:return _error(str(loaded.get("error","Original46FB18 physical stack read failed")) if loaded is Dictionary else "Original46FB18 physical stack response is malformed")
						last_excess=float(loaded.value)
						if not is_finite(last_excess):return _error("Original46FB18 physical stack operand is nonfinite")
						excess_defined=true
					if not excess_defined: return _error("原始0046F704开放导管读取未初始化的栈变量local_80，需原运行时证据。")
					var divided := X87.divide(X87.multiply([current, 0.0], last_excess), gas_volume)
					if divided.is_empty(): return _error("原始开放导管排出量未解析。")
					transfer = _number(divided)
			else:
				if not names.has(target_name): return _error("原始气体流路目标查找失败。")
				transfer = _number(X87.multiply([current, 0.0], fraction))
			transfer = minf(current, maxf(0.0, transfer))
			source.contents[species] = _number(X87.add([current, 0.0], -transfer))
			if target_name == "空": continue
			var target: Dictionary = copies[int(names[target_name])]
			# Native append writes name and moles only: other arrays remain undefined.
			if target.contents.has(species): target.contents[species] = _number(X87.add([transfer, 0.0], float(target.contents[species])))
			else:
				target.contents[species] = transfer
				if target.contents.size() >= 100: return _error("原始气体流路药品达到100槽，原程序停止。")
			var conduit_name := str(route.target_connector)
			if conduit_name.is_empty(): continue
			if not connector_names.has(conduit_name): return _error("原始气体目标导管查找失败。")
			var conduit: Dictionary = connectors[int(connector_names[conduit_name])]
			var selector := int(route.target_selector)
			if selector not in [1, 2]: return _error("原始气体导管端点栈值未定义。")
			var endpoint_y := float(conduit.metadata[3 if selector == 1 else 5])
			var surface := _surface(target)
			if not surface.ok: return surface
			if not _less_pair(surface.pair, [endpoint_y, 0.0]): conduit.native_state_0x70 = 0.0
			else:
				if not conduit.has("native_state_0x70"): return _error("原始导管气泡量缓存未初始化。")
				conduit.native_state_0x70 = _number(X87.add(X87.multiply([transfer, 0.0], 200000.0), float(conduit.native_state_0x70)))
				conduit.native_state_0x78 = selector
	for i in range(vessels.size()): vessels[i].merge(copies[i], true)
	for i in range(raw_connectors.size()): raw_connectors[i].merge(connectors[i], true)
	return {"ok": true, "resolved": true, "native_entry": "0046F704"}
