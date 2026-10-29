class_name OriginalApparatusActions
extends RefCounted
## Native numeric/state branch of newly recovered 0x00477708.
## VCL bitmap drawing is a separate boundary. No polygon/rectangle substitute.
const Transfer = preload("res://scripts/original/original_transfer.gd")
const X87 = preload("res://scripts/original/original_x87.gd")
const NATIVE_ENTRY := 0x00477708
const ASPIRATION_LIMIT_0047E6D4 := 2.0
const DROP_DOSES := {204: 0.2, 207: 0.25, 208: 0.25, 211: 1.0}
const CANDIDATE_TYPES := [101, 102, 103, 104, 105, 107, 201, 202]

static func _error(message: String) -> Dictionary:
	return {"ok": false, "error": message, "native_entry": NATIVE_ENTRY}

static func plan_manual_action(vessels: Array, selected_index: int, command: int,
		scale: float) -> Dictionary:
	# Run gating and command-latch MouseDown/MouseUp belong to the original caller.
	if selected_index < 0 or selected_index >= vessels.size() or not vessels[selected_index] is Dictionary:
		return _error("Native manual action requires a valid selected array index")
	if not is_finite(scale):
		return _error("Native canvas scale is not finite")
	var selected: Dictionary = vessels[selected_index]
	var type := _type(selected)
	var result := {"ok": true, "native_entry": NATIVE_ENTRY, "writes": {},
		"transfer": false, "source_index": -1, "target_index": -1,
		"requested_volume": 0.0, "animation_boundary": false}
	if type not in [204, 207, 208, 211]:
		return result
	if type != 204:
		if command in [1, 2, 3]:
			result["writes"]["0x68"] = 0 if command == 1 else 1
		if command != 3:
			return result
	elif command not in [1, 2]:
		return result
	var geometry: Dictionary = _geometry(selected)
	if not geometry["ok"]:
		return geometry
	var x: int = geometry["x"]
	var y: int = geometry["y"]
	var h: int = geometry["height"]
	var tip_x: Array = [float(x), 0.0]
	if type == 207:
		tip_x = _subtract_scaled(tip_x, 4.0, scale)
	var half_height: float = float(int(h / 2)) if type == 211 else float(h) * 0.5
	var tip_y: Array = X87.add(X87.multiply([half_height, 0.0], scale), float(y))
	if tip_x.is_empty() or tip_y.is_empty():
		return _error("Native outlet x87 calculation is outside supported arithmetic range")
	var px := _trunc(tip_x)
	var py := _trunc(tip_y)
	result["tip"] = [px, py]
	if type == 204 and command == 1:
		# Original scans in stored order and returns at the FIRST submerged match.
		for candidate_index in range(vessels.size()):
			var candidate: Dictionary = vessels[candidate_index]
			if _type(candidate) not in CANDIDATE_TYPES:
				continue
			var bounds := _candidate(candidate, type, true, scale)
			if not bounds.get("ok", false):
				return bounds
			if not bounds.get("eligible", false) or not _inside(bounds, px, py):
				continue
			if not selected.get("contents", null) is Dictionary or not selected.get("native_species_volume", null) is Dictionary:
				return _error("Native aspiration requires current dropper species/physical-volume caches")
			var used := 0.0
			for species in selected["contents"]:
				if Transfer.phase_suffix(str(species)) != "(液体)":
					continue
				if not selected["native_species_volume"].has(species):
					return _error("Native aspiration lacks current liquid slot volume: " + str(species))
				var accumulated: Array = X87.add([float(selected["native_species_volume"][species]), 0.0], used)
				if accumulated.is_empty():
					return _error("Native aspiration volume sum is outside supported arithmetic range")
				used = X87.stored_double(accumulated)
			var requested: Array = X87.add([ASPIRATION_LIMIT_0047E6D4, 0.0], -used)
			if requested.is_empty():
				return _error("Native aspiration subtraction is outside supported arithmetic range")
			result["transfer"] = true
			result["source_index"] = candidate_index
			result["target_index"] = selected_index
			result["requested_volume"] = X87.stored_double(requested)
			return result
		return result
	var best_score := 0
	var target_index := -1
	for candidate_index in range(vessels.size()):
		var candidate: Dictionary = vessels[candidate_index]
		if _type(candidate) not in CANDIDATE_TYPES:
			continue
		var bounds := _candidate(candidate, type, false, scale)
		if not bounds.get("ok", false):
			return bounds
		if not bounds.get("eligible", false) or not _inside(bounds, px, py):
			continue
		var score: Array = X87.add(_negate(bounds["score_top"]), float(py))
		if score.is_empty():
			return _error("Native recipient score is outside supported arithmetic range")
		if _compare(score, float(best_score)) > 0:
			best_score = _trunc(score)
			target_index = candidate_index
	if target_index >= 0:
		result["transfer"] = true
		result["source_index"] = selected_index
		result["target_index"] = target_index
		result["requested_volume"] = DROP_DOSES[type]
		# Native draws its falling-drop animation only if +4320 > 1e-10.
		if not selected.has("native_liquid_volume"):
			return _error("Native manual action lacks source +0x4320 liquid cache")
		result["animation_boundary"] = float(selected["native_liquid_volume"]) > 1e-10
	return result

static func execute_manual_action(vessels: Array, selected_index: int, command: int,
		scale: float, reagent_map: Dictionary) -> Dictionary:
	var plan := plan_manual_action(vessels, selected_index, command, scale)
	if not plan.get("ok", false):
		return plan
	for offset in plan["writes"]:
		var fields: Dictionary = vessels[selected_index].get("native_fields", {})
		fields[offset] = str(plan["writes"][offset])
		vessels[selected_index]["native_fields"] = fields
	if plan["transfer"]:
		plan["transfer_result"] = Transfer.move_liquid(vessels, plan["source_index"], plan["target_index"], plan["requested_volume"], reagent_map)
		if not plan["transfer_result"].get("ok", false):
			plan["ok"] = false
			plan["error"] = plan["transfer_result"].get("error", "Native liquid transfer failed")
	return plan

static func _type(vessel: Dictionary) -> int:
	if vessel.has("native_fields") and vessel["native_fields"].has("0x08"):
		return int(vessel["native_fields"]["0x08"])
	return int(vessel.get("type_id", -1))

static func _geometry(vessel: Dictionary) -> Dictionary:
	if not vessel.has("position") or not vessel["position"] is Array or vessel["position"].size() < 2:
		return _error("Native apparatus center fields +0x10/+0x14 are missing")
	for coordinate in vessel["position"]:
		if not is_finite(float(coordinate)) or float(coordinate) != float(int(coordinate)):
			return _error("Native apparatus centers must retain their stored integer coordinates")
	if not vessel.has("native_bitmap_width") or not vessel.has("native_bitmap_height"):
		return _error("Native active-bitmap dimensions are unresolved; no rectangle estimate is supplied")
	var width := int(vessel["native_bitmap_width"])
	var height := int(vessel["native_bitmap_height"])
	if width < 0 or height < 0:
		return _error("Native bitmap dimensions are invalid")
	return {"ok": true, "x": int(vessel["position"][0]), "y": int(vessel["position"][1]), "width": width, "height": height}

static func _candidate(vessel: Dictionary, selected_type: int, aspiration: bool, scale: float) -> Dictionary:
	var type := _type(vessel)
	var fields: Dictionary = vessel.get("native_fields", {})
	if type in [101, 103] and not fields.has("0x0c"):
		return _error("Native candidate size/subtype field +0x0C is unresolved")
	var size: int = int(fields.get("0x0c", 0))
	if (type == 101 and size != 0) or (type == 103 and size not in [100, 250]):
		return {"ok": true, "eligible": false}
	var geometry := _geometry(vessel)
	if not geometry["ok"]:
		return geometry
	var x: int = geometry["x"]
	var y: int = geometry["y"]
	var width: int = geometry["width"]
	var height: int = geometry["height"]
	var integer_bounds := selected_type == 211 or (selected_type == 208 and type == 202)
	var half_h: float = float(int(height / 2)) if integer_bounds else float(height) * 0.5
	var half_w: float = float(int(width / 2)) if integer_bounds else float(width) * 0.5
	var top: Array = _subtract_scaled([float(y), 0.0], half_h, scale)
	var bottom: Array = X87.add(X87.multiply([half_h, 0.0], scale), float(y))
	var result := {"ok": true, "eligible": true}
	var radius: float = 7.0 if type in [101, 107, 201] or (type == 103 and size == 250) else 5.0
	if type == 102:
		result["left"] = X87.add_pair(_subtract_scaled([float(x), 0.0], half_w, scale), X87.multiply([7.0, 0.0], scale))
		var right_inset := 2.0 if aspiration or selected_type == 211 else 1.0
		result["right"] = _subtract_scaled(X87.add(X87.multiply([half_w, 0.0], scale), float(x)), right_inset, scale)
	else:
		result["left"] = _subtract_scaled([float(x), 0.0], radius, scale)
		result["right"] = X87.add(X87.multiply([radius, 0.0], scale), float(x))
	result["bottom"] = _subtract_scaled(bottom, 3.0, scale)
	if aspiration:
		# +0x30 must be the value from the CURRENT original 71650 draw pass.
		# Saved .cem heights or guessed liquid fractions do not meet this contract.
		if not vessel.has("native_liquid_height") or not vessel.get("native_liquid_height_fresh", false):
			return _error("Native submerged check requires fresh liquid height +0x30 from original renderer")
		result["top"] = _subtract_scaled(bottom, float(vessel["native_liquid_height"]), scale)
	else:
		result["top"] = _subtract_scaled(top, 50.0, scale)
		# The 208/201 branch uses floating half-height for bounds but integer
		# half-height for its strict score comparison and integer score update.
		if selected_type == 208 and type == 201:
			top = _subtract_scaled([float(y), 0.0], float(int(height / 2)), scale)
		result["score_top"] = _subtract_scaled(top, 50.0, scale)
	for key in ["left", "right", "top", "bottom"]:
		if result[key].is_empty():
			return _error("Native recipient band is outside supported x87 arithmetic range")
	return result

static func _inside(bounds: Dictionary, x: int, y: int) -> bool:
	return _compare(bounds["left"], float(x)) < 0 and _compare(bounds["right"], float(x)) > 0 and _compare(bounds["top"], float(y)) < 0 and _compare(bounds["bottom"], float(y)) > 0

static func _subtract_scaled(pair: Array, coefficient: float, scale: float) -> Array:
	return X87.add_pair(pair, _negate(X87.multiply([coefficient, 0.0], scale)))

static func _negate(pair: Array) -> Array:
	return [] if pair.is_empty() else [-float(pair[0]), -float(pair[1])]

static func _compare(pair: Array, value: float) -> int:
	var difference: Array = X87.add(pair, -value)
	if difference.is_empty():
		return 0
	if float(difference[0]) != 0.0:
		return 1 if float(difference[0]) > 0.0 else -1
	return 1 if float(difference[1]) > 0.0 else (-1 if float(difference[1]) < 0.0 else 0)

static func _trunc(pair: Array) -> int:
	# 005394FC changes x87 RC to truncate, converts to int64, then restores RC.
	var high := float(pair[0])
	var low := float(pair[1])
	var value := int(high)
	if high == float(value):
		if value > 0 and low < 0.0: value -= 1
		elif value < 0 and low > 0.0: value += 1
	return value
