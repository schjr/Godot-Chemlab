class_name OriginalTransfer
extends RefCounted
## Transcription of native 0x00476DDC and 0x00477330. No capacity/valence rules.
## OriginalX87 preserves native precision-control=64 intermediates before qword stores.

const Quantities = preload("res://scripts/original/original_quantities.gd")
const X87 = preload("res://scripts/original/original_x87.gd")
const LIQUID_ENTRY_VA := 0x00476DDC
const SOLID_ENTRY_VA := 0x00477330
const PHASE_ENTRY_VA := 0x00452ACC
const SOURCE_VOLUME_THRESHOLD := 1e-20
const THERMAL_VOLUME_THRESHOLD := 1e-10
const MAX_RECORDED_SPECIES := 100
const LIQUID_PHASES := ["(液体)", "(溶解)", "(离子)", "(指示剂)"]
const LIQUID_COUNT_ERROR_VA := 0x00563E19
const SOLID_COUNT_ERROR_VA := 0x00563E3F
const SPECIES_COUNT_MESSAGE := "容器中的药品已有100钟！"
static var _reagents: Dictionary = {}

static func configure_reagents(reagent_map: Dictionary) -> void:
	_reagents = reagent_map

static func phase_suffix(species: String) -> String:
	# 00452ACC scans backwards to the LAST '(' and copies until ASCII space/end.
	# Do not use catalog.category or a contains() phase guess.
	var start := species.rfind("(")
	if start < 0:
		return ""
	var end := species.find(" ", start)
	return species.substr(start) if end < 0 else species.substr(start, end - start)

static func move_liquid(vessels: Array, source_index: int, target_index: int,
		requested_volume: float, reagent_map: Dictionary = {}) -> Dictionary:
	return _move(vessels, source_index, target_index, requested_volume, false,
		_reagents if reagent_map.is_empty() else reagent_map)

static func move_solid(vessels: Array, source_index: int, target_index: int,
		requested_volume: float, reagent_map: Dictionary = {}) -> Dictionary:
	return _move(vessels, source_index, target_index, requested_volume, true,
		_reagents if reagent_map.is_empty() else reagent_map)

static func _result(solid: bool, requested: float) -> Dictionary:
	return {"ok": true, "performed": false, "requested_volume": requested,
		"actual_volume": 0.0, "source_phase_volume": 0.0,
		"moved_moles": {}, "appended_species": [], "stop_requested": false,
		"native_entry": SOLID_ENTRY_VA if solid else LIQUID_ENTRY_VA,
		"native_messages": [], "errors": []}

static func _error(result: Dictionary, message: String) -> Dictionary:
	result["ok"] = false
	result["errors"].append(message)
	result["error"] = message
	return result

static func _move(vessels: Array, source_index: int, target_index: int,
		requested_volume: float, solid: bool, reagent_map: Dictionary) -> Dictionary:
	var result := _result(solid, requested_volume)
	# Adapter validation only: native callers pass valid array addresses and doubles.
	# No positive-request clamp: the native helpers accept negative/zero requests.
	if source_index < 0 or target_index < 0 or source_index >= vessels.size() or target_index >= vessels.size():
		return _error(result, "Native transfer requires valid source/target array indices")
	if not vessels[source_index] is Dictionary or not vessels[target_index] is Dictionary or not is_finite(requested_volume):
		return _error(result, "Native transfer requires vessel dictionaries and a finite request")
	var source: Dictionary = vessels[source_index]
	var target: Dictionary = vessels[target_index]
	if not source.get("contents", null) is Dictionary or not target.get("contents", null) is Dictionary:
		return _error(result, "Native transfer requires ordered contents dictionaries")
	var source_contents: Dictionary = source["contents"]
	var target_contents: Dictionary = target["contents"]
	if source_contents.size() > MAX_RECORDED_SPECIES or target_contents.size() > MAX_RECORDED_SPECIES:
		return _error(result, "Native species arrays exceed their recorded 100-slot layout; memory corruption is not emulated")
	if not source.get("native_species_volume", null) is Dictionary:
		return _error(result, "Missing native +0x5B8 species-volume cache; call OriginalQuantities.recalc first")
	var source_volumes: Dictionary = source["native_species_volume"]
	var denominator := 0.0
	var source_phase := "(固体)" if solid else "(液体)"
	var source_names := source_contents.keys()
	for name in source_names:
		if phase_suffix(str(name)) == source_phase:
			if not source_volumes.has(name) or not _finite_number(source_volumes[name]):
				return _error(result, "Missing/invalid native physical volume for source species: " + str(name))
			var total: Array = X87.add([float(source_volumes[name]), 0.0], denominator)
			if total.is_empty():
				return _error(result, "Native x87 source-volume accumulation is outside the supported arithmetic range")
			denominator = X87.stored_double(total)
	result["source_phase_volume"] = denominator
	# Native comparison is 1e-20 <= denominator. No recalc or writes on this return.
	if denominator < SOURCE_VOLUME_THRESHOLD:
		return result
	for vessel in [source, target]:
		if not _finite_number(vessel.get("temperature", null)) or not _finite_number(vessel.get("native_liquid_volume", null)) or not _finite_number(vessel.get("native_solid_volume", null)):
			return _error(result, "Missing native temperature/liquid/solid caches; call OriginalQuantities.recalc first")
		for name in vessel["contents"]:
			if not _finite_number(vessel["contents"][name]) or not reagent_map.has(str(name)):
				return _error(result, "Invalid moles or missing original reagent metadata: " + str(name))
	var amount := requested_volume
	if denominator < requested_volume:
		amount = denominator
	result["actual_volume"] = amount
	result["performed"] = true
	# +4320/+4338 remain stale until both native recalculations after the loop.
	var occupied: Array = X87.add([float(target["native_liquid_volume"]), 0.0], float(target["native_solid_volume"]))
	if occupied.is_empty():
		return _error(result, "Native x87 recipient-volume accumulation is outside the supported arithmetic range")
	var occupied_volume := X87.stored_double(occupied)
	for name in source_names:
		var phase := phase_suffix(str(name))
		if (solid and phase != "(固体)") or (not solid and phase not in LIQUID_PHASES):
			continue
		# Liquid 476F0F/476F12/476F15 and solid 477460/477463/477466
		# store the quotient to a qword BEFORE multiplying source moles.
		# Liquid 47713F / solid 477522 then FMUL that rounded double.
		var quotient: Array = X87.divide([amount, 0.0], denominator)
		if quotient.is_empty():
			return _error(result, "Native x87 transfer-ratio division is outside the supported arithmetic range")
		var moved_extended: Array = X87.multiply([X87.stored_double(quotient), 0.0], float(source_contents[name]))
		if moved_extended.is_empty():
			return _error(result, "Native x87 moved-moles calculation is outside the supported arithmetic range")
		var moved := X87.stored_double(moved_extended)
		var remaining: Array = X87.add([float(source_contents[name]), 0.0], -moved)
		if remaining.is_empty():
			return _error(result, "Native x87 source subtraction is outside the supported arithmetic range")
		source_contents[name] = X87.stored_double(remaining)
		result["moved_moles"][name] = moved
		if target_contents.has(name):
			# The lookup follows source subtraction, including source==target calls.
			var merged: Array = X87.add([moved, 0.0], float(target_contents[name]))
			if merged.is_empty():
				return _error(result, "Native x87 recipient addition is outside the supported arithmetic range")
			target_contents[name] = X87.stored_double(merged)
		else:
			var target_count := target_contents.size()
			if target_count >= MAX_RECORDED_SPECIES:
				result["stop_requested"] = true
				return _error(result, "Native transfer would overwrite memory beyond the 100th species slot; partial native writes are preserved")
			target_contents[name] = moved
			result["appended_species"].append(name)
			# The helper writes NAME and MOLES only. Preserve an existing unused
			# volume slot if the caller supplied it; otherwise leave its cache unknown.
			_preserve_volume_slot(target, str(name), target_count)
			if target_contents.size() > 99:
				result["stop_requested"] = true
				result["native_messages"].append({"address": SOLID_COUNT_ERROR_VA if solid else LIQUID_COUNT_ERROR_VA,
					"message": SPECIES_COUNT_MESSAGE})
	# Native thermal mixing uses pre-recalc recipient occupied physical volume,
	# not total moles. It intentionally contains no target-capacity cap.
	var thermal_denominator: Array = X87.add([occupied_volume, 0.0], amount)
	var compared: Array = X87.add(thermal_denominator, -THERMAL_VOLUME_THRESHOLD)
	if compared.is_empty():
		return _error(result, "Native x87 thermal denominator is outside the supported arithmetic range")
	if float(compared[0]) > 0.0 or (float(compared[0]) == 0.0 and float(compared[1]) > 0.0):
		var source_heat: Array = X87.multiply([float(source["temperature"]), 0.0], amount)
		var target_heat: Array = X87.multiply([float(target["temperature"]), 0.0], occupied_volume)
		var numerator: Array = X87.add_pair(source_heat, target_heat)
		var temperature: Array = X87.divide_pair(numerator, thermal_denominator)
		if temperature.is_empty():
			return _error(result, "Native x87 thermal mixing is outside the supported arithmetic range")
		target["temperature"] = X87.stored_double(temperature)
	# Native call order verified at 004772F3/004772FC and 004776CA/004776D3.
	var source_recalc: Dictionary = Quantities.recalc(source, reagent_map)
	var target_recalc: Dictionary = Quantities.recalc(target, reagent_map)
	for recalc in [source_recalc, target_recalc]:
		if not recalc.get("ok", false):
			result["stop_requested"] = true
			_error(result, str(recalc.get("error", "Original quantity recalculation failed")))
	return result

static func _preserve_volume_slot(vessel: Dictionary, name: String, index: int) -> void:
	var slots: Variant = vessel.get("native_species_volume_slots", null)
	if slots is Array and index < slots.size() and _finite_number(slots[index]):
		var cache: Dictionary = vessel.get("native_species_volume", {})
		cache[name] = float(slots[index])
		vessel["native_species_volume"] = cache

static func _finite_number(value: Variant) -> bool:
	return (value is int or value is float) and is_finite(float(value))
