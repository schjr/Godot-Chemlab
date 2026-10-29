class_name OriginalFlow
extends RefCounted
## Native 004849FC ordinary-vessel branches and 004433B4 N18 orientation toggle.
## Type 311's GDI region/conduit path is explicitly unresolved, never approximated.
const Actions = preload("res://scripts/original/original_apparatus_actions.gd")
const Transfer = preload("res://scripts/original/original_transfer.gd")
const Quantities = preload("res://scripts/original/original_quantities.gd")
const X87 = preload("res://scripts/original/original_x87.gd")
const ENTRY := 0x004849FC
const N18_ENTRY := 0x004433B4
const EXTENDED_MULTIPLIER_0048C3F4 := "d4feffffffffffc70540"
const POUR_OUTLETS := {101: [0, 0], 102: [1, 1], 104: [12, 15],
	105: [9, 14], 106: [1, 1], 121: [0, 0], 201: [2, 7], 202: [2, 7]}
const OPEN_SOURCES := [204, 207, 208, 209, 210, 211]
const RECEIVERS := [101, 102, 103, 104, 105, 107, 121, 201, 202, 209, 210]

static func _error(message: String) -> Dictionary:
	return {"ok": false, "error": message, "native_entry": ENTRY}

static func toggle_pour(vessel: Dictionary) -> Dictionary:
	# Original changes 0 -> 2 and 2 -> 0. Orientation 1 is untouched.
	var fields: Dictionary = vessel.get("native_fields", {})
	if not fields.has("0x18") or not fields.has("0x0c"):
		return _error("Original N18Click requires +0x18 orientation and +0x0C subtype")
	var orientation := int(fields["0x18"])
	var result := {"ok": true, "native_entry": N18_ENTRY, "changed": false}
	if orientation not in [0, 2]:
		return result
	var next := 2 if orientation == 0 else 0
	fields["0x18"] = str(next)
	vessel["native_fields"] = fields
	result["changed"] = true
	result["orientation"] = next
	result["menu_checked"] = next == 2
	var type := Actions._type(vessel)
	var size := int(fields["0x0c"])
	var assets := _orientation_assets(type, size, next)
	if not assets.is_empty():
		# Native loads +F4/+F8 paths then assigns +F4 to the active +FC bitmap.
		result["bitmap_plain"] = assets[0]
		result["bitmap_fill"] = assets[1]
		result["bitmap_active"] = assets[0]
	return result

static func _orientation_assets(type: int, size: int, orientation: int) -> Array:
	var prefix := "d" if orientation == 2 else ""
	var stem := ""
	match type:
		101:
			if orientation == 2: stem = "sg"
			elif size == 0: stem = "sg0"
			elif size == 45: stem = "sg45"
		102:
			if size in [100, 200, 500]: stem = "sb" + str(size)
		103:
			if size in [100, 250]: stem = "zxp" + str(size)
		104: stem = "ydsp100"
		105: stem = "pdsp100"
		106: stem = "blg"
		121: stem = "zfm_50"
		201:
			if size == 100: stem = "gkp"
			elif size == 1000: stem = "gkp_z"
		202:
			if size == 100: stem = "xkp"
			elif size == 1000: stem = "xkp_z"
	if stem.is_empty():
		return []
	var plain := prefix + stem + ".bmp"
	# Exact original quirk: both size-1000 bottle types keep the size-100 mask.
	var fill_stem := ("xkp" if type == 202 else "gkp") if type in [201, 202] and size == 1000 else stem
	return [plain, "_" + prefix + fill_stem + ".bmp"]

static func plan_frame(vessels: Array, delta: float, scale: float, reagent_map: Dictionary) -> Dictionary:
	# Capture-mode reference follows native calls without executing their side effects;
	# matches the oracle transfer-entry boundary and still runs native 624D8 recalc.
	return _frame(vessels.duplicate(true), delta, scale, reagent_map, true)

static func advance(vessels: Array, delta: float, scale: float, reagent_map: Dictionary) -> Dictionary:
	return _frame(vessels, delta, scale, reagent_map, false)

static func _frame(vessels: Array, delta: float, scale: float, reagent_map: Dictionary, capture: bool) -> Dictionary:
	if not is_finite(delta) or not is_finite(scale):
		return _error("Original continuous-flow delta/scale must be finite")
	for vessel in vessels:
		if not vessel is Dictionary or not vessel.has("native_fields") or not vessel["native_fields"] is Dictionary or not vessel["native_fields"].has("0x18"):
			return _error("Original flow requires the native apparatus array and +0x18 fields")
		if Actions._type(vessel) == 311:
			return _error("Original type-311 GDI polygon/conduit geometry is unresolved; no rectangular or nearest-target substitute is used")
	var result := {"ok": true, "native_entry": ENTRY, "calls": [], "transfer_results": [], "stop_requested": false}
	var pour_amount := _amount(0.25, delta)
	var open_amount := _amount(0.2, delta)
	if pour_amount.is_empty() or open_amount.is_empty():
		return _error("Original continuous-flow x87 rate multiplication is outside supported range")
	# Native first type-311 route pass is empty for this explicitly supported profile.
	# Next comes orientation==2 pouring; orientation==1 is not processed here.
	for source_index in range(vessels.size()):
		var source: Dictionary = vessels[source_index]
		if int(source["native_fields"]["0x18"]) != 2:
			continue
		var outlet := _pour_outlet(source, scale)
		if not outlet.get("ok", false):
			return outlet
		var target := _recipient(vessels, outlet["x"], outlet["y"], scale, true)
		if not target.get("ok", false):
			return target
		if target["index"] < 0:
			continue
		var call := _call(vessels, source_index, target["index"], pour_amount[0], false, reagent_map, capture, result)
		if not call.get("ok", false):
			return call
		if not source.has("native_liquid_volume"):
			return _error("Original pouring depletion check lacks +0x4320")
		if float(source["native_liquid_volume"]) < 1e-10:
			call = _call(vessels, source_index, target["index"], pour_amount[0], true, reagent_map, capture, result)
			if not call.get("ok", false):
				return call
	# 004624D8 runs after the whole rotated-pour scan, before open outflow.
	for vessel in vessels:
		var type := Actions._type(vessel)
		if type > 100 and type < 300:
			var calculated: Dictionary = Quantities.recalc(vessel, reagent_map)
			if not calculated.get("ok", false):
				result["stop_requested"] = bool(calculated.get("stop", false))
				return _error(str(calculated.get("error", "Native quantity recalculation failed")))
	for source_index in range(vessels.size()):
		var source: Dictionary = vessels[source_index]
		var type := Actions._type(source)
		if int(source["native_fields"]["0x18"]) in [1, 2] or type not in OPEN_SOURCES:
			continue
		if not source["native_fields"].has("0x68"):
			return _error("Original open-outflow source lacks +0x68 control state")
		if int(source["native_fields"]["0x68"]) == 1:
			continue
		var geometry: Dictionary = Actions._geometry(source)
		if not geometry.get("ok", false):
			return geometry
		var px: Array = [float(geometry["x"]), 0.0]
		if type == 207:
			px = Actions._subtract_scaled(px, 4.0, scale)
		var py: Array = X87.add(X87.multiply([float(geometry["height"]) * 0.5, 0.0], scale), float(geometry["y"]))
		if px.is_empty() or py.is_empty():
			return _error("Original continuous outlet calculation is outside supported range")
		var target := _recipient(vessels, Actions._trunc(px), Actions._trunc(py), scale, false)
		if not target.get("ok", false):
			return target
		if target["index"] < 0:
			continue
		var call := _call(vessels, source_index, target["index"], open_amount[0], false, reagent_map, capture, result)
		if not call.get("ok", false):
			return call
		if type == 209:
			if not source["native_fields"].has("0x6c"):
				return _error("Original type-209 solid-outflow check lacks +0x6C")
			if float(source["native_liquid_volume"]) < 1e-10 and int(source["native_fields"]["0x6c"]) == 0:
				call = _call(vessels, source_index, target["index"], pour_amount[0], true, reagent_map, capture, result)
				if not call.get("ok", false):
					return call
	return result

static func _call(vessels: Array, source: int, target: int, amount: float, solid: bool,
		reagents: Dictionary, capture: bool, result: Dictionary) -> Dictionary:
	result["calls"].append({"source_index": source, "target_index": target,
		"requested_volume": amount, "solid": solid, "native_function": 0x00477330 if solid else 0x00476DDC})
	if capture:
		return {"ok": true}
	var moved: Dictionary = Transfer.move_solid(vessels, source, target, amount, reagents) if solid else Transfer.move_liquid(vessels, source, target, amount, reagents)
	result["transfer_results"].append(moved)
	result["stop_requested"] = result["stop_requested"] or moved.get("stop_requested", false)
	return moved

static func _amount(rate: float, delta: float) -> Array:
	var value: Array = X87.multiply([rate, 0.0], delta)
	value = X87.multiply_pair(value, X87.from_extended80_hex(EXTENDED_MULTIPLIER_0048C3F4))
	return [] if value.is_empty() else [X87.stored_double(value)]

static func _pour_outlet(vessel: Dictionary, scale: float) -> Dictionary:
	var type := Actions._type(vessel)
	var offset: Array = POUR_OUTLETS.get(type, [])
	if type == 103:
		if not vessel["native_fields"].has("0x0c"):
			return _error("Original tilted conical vessel lacks +0x0C size")
		var size := int(vessel["native_fields"]["0x0c"])
		if size == 100: offset = [12, 14]
		elif size == 250: offset = [16, 18]
	if offset.is_empty():
		return _error("Original tilted outlet is unassigned for this type/subtype; stale native locals are not invented")
	var geometry: Dictionary = Actions._geometry(vessel)
	if not geometry.get("ok", false):
		return geometry
	var x: Array = Actions._subtract_scaled([float(geometry["x"]), 0.0], float(geometry["width"]) * 0.5, scale)
	x = X87.add_pair(X87.multiply([float(offset[0]), 0.0], scale), x)
	var y: Array = X87.add(X87.multiply([float(geometry["height"]) * 0.5, 0.0], scale), float(geometry["y"]))
	y = Actions._subtract_scaled(y, float(offset[1]), scale)
	if x.is_empty() or y.is_empty():
		return _error("Original tilted outlet arithmetic is outside supported range")
	return {"ok": true, "x": Actions._trunc(x), "y": Actions._trunc(y)}

static func _recipient(vessels: Array, px: int, py: int, scale: float, pouring: bool) -> Dictionary:
	var result := {"ok": true, "index": -1}
	var best := 0
	for index in range(vessels.size()):
		var vessel: Dictionary = vessels[index]
		if int(vessel["native_fields"]["0x18"]) in [1, 2] or Actions._type(vessel) not in RECEIVERS:
			continue
		var band := _receiver_band(vessel, scale, pouring)
		if not band.get("ok", false):
			return band
		if not band.get("eligible", false) or not Actions._inside(band, px, py):
			continue
		var score: Array = X87.add(Actions._negate(band["top"]), float(py))
		if score.is_empty():
			return _error("Original continuous recipient score is outside supported range")
		if Actions._compare(score, float(best)) > 0:
			best = Actions._trunc(score)
			result["index"] = index
	return result

static func _receiver_band(vessel: Dictionary, scale: float, pouring: bool) -> Dictionary:
	var type := Actions._type(vessel)
	var fields: Dictionary = vessel["native_fields"]
	if type in [101, 103] and not fields.has("0x0c"):
		return _error("Original continuous recipient lacks +0x0C subtype")
	var size := int(fields.get("0x0c", 0))
	if (type == 101 and size != 0 and (not pouring or size != 45)) or (type == 103 and size not in [100, 250]):
		return {"ok": true, "eligible": false}
	var geometry: Dictionary = Actions._geometry(vessel)
	if not geometry.get("ok", false):
		return geometry
	var x: int = geometry["x"]
	var y: int = geometry["y"]
	var width: int = geometry["width"]
	var height: int = geometry["height"]
	# Native open-output branch uses integer half-heights for 107/201/202.
	var half_height: float = float(int(height / 2)) if not pouring and type in [107, 201, 202] else float(height) * 0.5
	var top: Array = Actions._subtract_scaled([float(y), 0.0], half_height, scale)
	var result := {"ok": true, "eligible": true}
	var radius := 7.0 if type in [101, 107, 201] or (type == 103 and size == 250) else 5.0
	if type == 121 or type == 210: radius = 10.0
	if type == 209: radius = 18.0
	if type == 102 or type == 121:
		var left_inset := 7.0 if type == 102 else 5.0
		result["left"] = X87.add_pair(Actions._subtract_scaled([float(x), 0.0], float(width) * 0.5, scale), X87.multiply([left_inset, 0.0], scale))
		result["right"] = Actions._subtract_scaled(X87.add(X87.multiply([float(width) * 0.5, 0.0], scale), float(x)), 2.0 if pouring and type == 102 else 1.0, scale)
	else:
		result["left"] = Actions._subtract_scaled([float(x), 0.0], radius, scale)
		result["right"] = X87.add(X87.multiply([radius, 0.0], scale), float(x))
	if type == 101 and size == 45:
		result["left"] = X87.add(X87.multiply([24.0, 0.0], scale), float(x))
		result["right"] = X87.add(X87.multiply([36.0, 0.0], scale), float(x))
	result["top"] = Actions._subtract_scaled(top, 50.0, scale)
	if pouring or type in [121, 209, 210]:
		result["bottom"] = X87.add_pair(X87.multiply([13.0 if type == 101 and size == 45 else 5.0, 0.0], scale), top)
	else:
		result["bottom"] = Actions._subtract_scaled(X87.add(X87.multiply([half_height, 0.0], scale), float(y)), 3.0, scale)
	for key in ["left", "right", "top", "bottom"]:
		if result[key].is_empty():
			return _error("Original continuous recipient band arithmetic is outside supported range")
	return result
