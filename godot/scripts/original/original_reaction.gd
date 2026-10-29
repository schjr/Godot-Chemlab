class_name OriginalReaction
extends RefCounted
## Source port of only FUN_00462c18's ordinary one-way pass.
## Unsupported phases are explicit; this is not a replacement equilibrium solver.

static func begin_reaction_cycle(state: Dictionary) -> void:
	# FUN_00462c18 resets native 0x3cc0 once, before smart selection/passes.
	state["gas_3cc0"] = 0.0

static func phase_suffix(species: String) -> String:
	# FUN_00452acc: from the last '(' up to the first ASCII space.
	var at := species.rfind("(")
	if at < 0: return ""
	var tail := species.substr(at)
	var space := tail.find(" ")
	return tail.left(space) if space >= 0 else tail

static func speed_factor(setting: int) -> float:
	# FUN_00462c18 initialization: clamp 1..19, 10 is unity.
	# Literal decimal values reproduce stored-double rounding of extended .1*s.
	var s := clampi(setting, 1, 19)
	if s < 10: return [0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9][s]
	return float(s - 9)

static func ordinary_condition(condition: String, heating_flag: int, temperature: float) -> Dictionary:
	# FUN_005410cc is equality, not substring matching.
	if condition in ["加热", "加强热"] and heating_flag == 0:
		return {"resolved": true, "allowed": false}
	if condition == "加强热" and temperature < 200.0:
		return {"resolved": true, "allowed": false}
	if condition == "点燃":
		return {"resolved": true, "allowed": false}
	if condition.begins_with("温度>") or condition.begins_with("温度<"):
		var number := condition.substr(3)
		if not number.is_valid_float():
			return {"resolved": false, "error": "Native StrToFloat condition would reject this number"}
		var threshold := float(number)
		return {"resolved": true, "allowed": temperature >= threshold if condition[2] == ">" else temperature <= threshold}
	# The ordinary pass does not gate 水溶液, 高温, PH, or composite conditions.
	return {"resolved": true, "allowed": true}

static func ensure_species(state: Dictionary, reaction: Dictionary, products_first: bool = false) -> void:
	# FUN_0046c894: ensure all reactant/product names have zero-valued slots.
	for side in ([reaction.products, reaction.reactants] if products_first else [reaction.reactants, reaction.products]):
		for item in side:
			var species := str(item.get("species", item.get("name", "")))
			var new_slot: bool = not state.moles.has(species)
			if new_slot:
				state.moles[species] = 0.0
				for cache in ["volumes", "masses"]:
					if state.has(cache): state[cache][species] = 0.0
			for table in ["solid_3cd8", "solid_3ff8"]:
				if not state.has(table): state[table] = {}
				if new_slot: state[table][species] = 0.0

static func step_one_way(state: Dictionary, reaction: Dictionary, native_delta_seconds: float) -> Dictionary:
	# This function mutates moles and the exact native particle-counter analogues.
	# The caller must supply the original note field; cold .cem load does not store it.
	if not reaction.has("native_note"):
		return {"resolved": false, "error": "Native reaction note at 0x1000 is required"}
	var mode := str(reaction.get("equilibrium_mode", ""))
	if mode == "可逆" or str(reaction.native_note) == "水的电离":
		return {"resolved": true, "selected": false, "extent": 0.0}
	if not state.get("moles", null) is Dictionary or not reaction.get("reactants", null) is Array or not reaction.get("products", null) is Array:
		return {"resolved": false, "error": "Native state/side arrays required"}
	if reaction.reactants.is_empty():
		return {"resolved": false, "error": "Zero-reactant native record is undefined in the insufficient branch"}
	for side in [reaction.reactants, reaction.products]:
		for item in side:
			if int(item.get("coefficient", 0)) <= 0:
				return {"resolved": false, "error": "Nonpositive native coefficient is outside this verified port"}
	var gate := ordinary_condition(str(reaction.get("condition", "")), int(state.get("heating_flag", 0)), float(state.get("temperature", 20.0)))
	if not gate.resolved: return gate
	if not gate.allowed: return {"resolved": true, "selected": false, "extent": 0.0}
	ensure_species(state, reaction)
	var solid_reactant := 0
	var gas_reactant := 0
	# Native scan breaks at its first nonzero solid OR gas reactant.
	for item in reaction.reactants:
		var species := str(item.get("species", item.get("name", "")))
		if float(state.moles[species]) > 1e-10:
			if phase_suffix(species) == "(固体)": solid_reactant = 1; break
			if phase_suffix(species) == "(气体)": gas_reactant = 1; break
	for side in [reaction.reactants, reaction.products]:
		for item in side:
			var species := str(item.get("species", item.get("name", "")))
			if phase_suffix(species) == "(固体)" and (not state.solid_3cd8.has(species) or not state.solid_3ff8.has(species)):
				return {"resolved": false, "error": "Native solid particle cache is uninitialized: " + species}
	var rate := float(reaction.get("reaction_rate", 0.0))
	var multiplier := speed_factor(int(state.get("speed_setting", 10)))
	var base_rate := X87.multiply(X87.multiply([rate, 0.0], native_delta_seconds), multiplier)
	if base_rate.is_empty(): return {"resolved": false, "error": "Native rate arithmetic unsupported"}
	var extent := X87.stored_double(base_rate)
	var sufficient := true
	for item in reaction.reactants:
		var species := str(item.get("species", item.get("name", "")))
		var q := X87.multiply(X87.multiply(X87.multiply([float(item.coefficient), 0.0], rate), native_delta_seconds), multiplier)
		if q.is_empty(): return {"resolved": false, "error": "Native coefficient/rate arithmetic unsupported"}
		if _pair_less([float(state.moles[species]), 0.0], q): sufficient = false
	if not sufficient:
		var first: Dictionary = reaction.reactants[0]
		var first_species := str(first.get("species", first.get("name", "")))
		extent = X87.stored_double(X87.divide([float(state.moles[first_species]), 0.0], float(first.coefficient)))
		for item in reaction.reactants:
			var species := str(item.get("species", item.get("name", "")))
			if _pair_less([float(state.moles[species]), 0.0], X87.multiply([float(item.coefficient), 0.0], extent)):
				extent = X87.stored_double(X87.divide([float(state.moles[species]), 0.0], float(item.coefficient)))
	var quantities: Array = []
	for side in [reaction.reactants, reaction.products]:
		var amounts: Array = []
		for item in side:
			var q: Array = X87.multiply(X87.multiply(X87.multiply([float(item.coefficient), 0.0], rate), native_delta_seconds), multiplier) if sufficient else X87.multiply([float(item.coefficient), 0.0], extent)
			if q.is_empty(): return {"resolved": false, "error": "Native mutation arithmetic unsupported"}
			amounts.append(q)
		quantities.append(amounts)
	# Per-entry mutation order is retained; duplicate species are not aggregated.
	for i in range(reaction.reactants.size()):
		var item: Dictionary = reaction.reactants[i]
		var species := str(item.get("species", item.get("name", "")))
		var consumed: Array = quantities[0][i]
		var remaining := X87.add_pair([float(state.moles[species]), 0.0], X87.multiply(consumed, -1.0))
		if remaining.is_empty(): return {"resolved": false, "error": "Native reactant subtraction arithmetic unsupported"}
		state.moles[species] = X87.stored_double(remaining)
		if phase_suffix(species) == "(固体)" and float(state.solid_3cd8[species]) > 0.0:
			if not _pair_less(consumed, [float(state.solid_3cd8[species]), 0.0]):
				state.solid_3ff8[species] = X87.stored_double(X87.add([float(state.solid_3ff8[species]), 0.0], -float(state.solid_3cd8[species])))
				state.solid_3cd8[species] = 0.0
			else:
				for table in ["solid_3cd8", "solid_3ff8"]:
					state[table][species] = X87.stored_double(X87.add_pair([float(state[table][species]), 0.0], X87.multiply(consumed, -1.0)))
	for i in range(reaction.products.size()):
		var item: Dictionary = reaction.products[i]
		var species := str(item.get("species", item.get("name", "")))
		var produced: Array = quantities[1][i]
		state.moles[species] = X87.stored_double(X87.add_pair([float(state.moles[species]), 0.0], produced))
		if phase_suffix(species) == "(固体)" and float(state.get("liquid_height", 0.0)) > 1.0 and solid_reactant == 0:
			for table in ["solid_3cd8", "solid_3ff8"]:
				state[table][species] = X87.stored_double(X87.add_pair([float(state[table][species]), 0.0], produced))
		if phase_suffix(species) == "(气体)" and gas_reactant == 0:
			state["gas_3cc0"] = X87.stored_double(X87.add_pair([float(state.get("gas_3cc0", 0.0)), 0.0], produced))
	return {"resolved": true, "selected": true, "extent": extent, "full_rate_branch": sufficient}

const X87 = preload("res://scripts/original/original_x87.gd")
const NativeMath = preload("res://scripts/original/original_math.gd")

static func _pair_less(a: Array, b: Array) -> bool:
	if b.size() == 2 and float(b[1]) == 0.0: return X87.compare_to_double(a, float(b[0])) < 0
	if a.size() == 2 and float(a[1]) == 0.0: return X87.compare_to_double(b, float(a[0])) > 0
	var difference := X87.add_pair(a, X87.multiply(b, -1.0))
	return float(difference[0]) < 0.0 or (float(difference[0]) == 0.0 and float(difference[1]) < 0.0)

static func _power_native_integer(base: float, exponent: int) -> Array:
	# FUN_005399d8 integer-power fast path, 00539b5c..00539bad.
	if exponent <= 0 or not is_finite(base): return []
	if exponent >= 4096: return NativeMath.pow_native(base, float(exponent))
	if base == 0.0: return [0.0, 0.0]
	var log_exponent := 0
	var shifted := exponent
	while shifted > 1:
		shifted >>= 1
		log_exponent += 1
	var bits := PackedFloat64Array([base]).to_byte_array()
	var high_word := int(bits[6]) | (int(bits[7]) << 8)
	var raw_bx := ((high_word << 1) - 0x7fe0) & 0xffff
	var signed_bx := raw_bx - 0x10000 if raw_bx >= 0x8000 else raw_bx
	var shifted_bx := (raw_bx << (log_exponent + 1)) & 0xffff
	var signed_shifted := shifted_bx - 0x10000 if shifted_bx >= 0x8000 else shifted_bx
	if (signed_shifted >> (log_exponent + 1)) != signed_bx:
		# Native falls through the verified original CRT logarithm/exp compatibility.
		return NativeMath.pow_native(base, float(exponent))
	var result: Array = [base, 0.0]
	for bit in range(log_exponent - 1, -1, -1):
		result = X87.multiply_pair(result, result)
		if result.is_empty(): return []
		if (exponent & (1 << bit)) != 0:
			result = X87.multiply(result, base)
			if result.is_empty(): return []
	return result

static func _equilibrium_products(state: Dictionary, reaction: Dictionary) -> Dictionary:
	if not state.get("volumes", null) is Dictionary:
		return {"resolved": false, "error": "Native per-species 0x5b8 volume cache required"}
	var sums := {"(液体)": 0.0, "(气体)": 0.0, "(固体)": 0.0}
	for species in state.moles:
		var phase := phase_suffix(str(species))
		if sums.has(phase):
			if not state.volumes.has(species): return {"resolved": false, "error": "Uninitialized native physical volume slot"}
			sums[phase] = float(sums[phase]) + float(state.volumes[species])
	var products: Array = []
	for side in [reaction.reactants, reaction.products]:
		var accumulated := 1.0
		for item in side:
			var species := str(item.get("species", item.get("name", "")))
			var phase := phase_suffix(species)
			var denominator := 0.0
			if phase in ["(液体)", "(溶解)", "(离子)"]: denominator = float(sums["(液体)"])
			elif phase in ["(气体)", "(固体)"]: denominator = float(sums[phase])
			else: return {"resolved": false, "error": "Native activity slot phase is unresolved"}
			if denominator <= 1e-10:
				return {"resolved": false, "error": "Native activity slot is unwritten for absent phase volume"}
			var concentration := X87.multiply(X87.divide([float(state.moles[species]), 0.0], denominator), 1000.0)
			if concentration.is_empty(): return {"resolved": false, "error": "Activity arithmetic unsupported"}
			var powered := _power_native_integer(X87.stored_double(concentration), int(item.coefficient))
			if powered.is_empty(): return {"resolved": false, "error": "Native power logarithm path not yet ported"}
			# Native stores the power result to a qword before product multiplication.
			var combined := X87.multiply([accumulated, 0.0], X87.stored_double(powered))
			if combined.is_empty(): return {"resolved": false, "error": "Activity product arithmetic unsupported"}
			accumulated = X87.stored_double(combined)
		products.append(accumulated)
	return {"resolved": true, "reactant_product": products[0], "product_product": products[1]}

static func _native_limit(state: Dictionary, side: Array, fallback_raw_moles: bool = false) -> float:
	var limit := 0.0
	var selected_amount := 0.0
	for i in range(side.size()):
		var item: Dictionary = side[i]
		var species := str(item.get("species", item.get("name", "")))
		var amount := float(state.moles[species])
		var division := X87.divide([amount, 0.0], float(item.coefficient))
		var ratio := X87.stored_double(division)
		if i == 0 or ratio < limit:
			limit = ratio
			selected_amount = amount
	return selected_amount if fallback_raw_moles else limit

static func _native_equilibrium_mutation(state: Dictionary, reaction: Dictionary, extent: float, forward: bool) -> bool:
	for side_index in range(2):
		var side: Array = reaction.reactants if side_index == 0 else reaction.products
		for item in side:
			var species := str(item.get("species", item.get("name", "")))
			var quantity := X87.multiply([float(item.coefficient), 0.0], extent)
			if quantity.is_empty(): return false
			var sign_value := -1.0 if (side_index == 0) == forward else 1.0
			var signed := X87.multiply(quantity, sign_value)
			var changed := X87.add_pair([float(state.moles[species]), 0.0], signed)
			if changed.is_empty(): return false
			state.moles[species] = X87.stored_double(changed)
			# These counter directions are copied literally even in the reverse branch.
			if side_index == 0 and phase_suffix(species) == "(固体)" and float(state.solid_3cd8[species]) > 0.0:
				if float(state.solid_3cd8[species]) <= X87.stored_double(quantity):
					state.solid_3ff8[species] = X87.stored_double(X87.add([float(state.solid_3ff8[species]), 0.0], -float(state.solid_3cd8[species])))
					state.solid_3cd8[species] = 0.0
				else:
					for table in ["solid_3cd8", "solid_3ff8"]:
						state[table][species] = X87.stored_double(X87.add_pair([float(state[table][species]), 0.0], X87.multiply(quantity, -1.0)))
			if side_index == 1 and phase_suffix(species) == "(固体)" and float(state.get("liquid_height", 0.0)) > 1.0:
				for table in ["solid_3cd8", "solid_3ff8"]:
					state[table][species] = X87.stored_double(X87.add_pair([float(state[table][species]), 0.0], quantity))
			if side_index == 1 and phase_suffix(species) == "(气体)":
				state.gas_3cc0 = X87.stored_double(X87.add_pair([float(state.get("gas_3cc0", 0.0)), 0.0], quantity))
	return true

static func step_equilibrium(state: Dictionary, reaction: Dictionary, native_delta_seconds: float) -> Dictionary:
	if not reaction.has("native_note"): return {"resolved": false, "error": "Native note required"}
	if str(reaction.get("equilibrium_mode", "")) == "单向": return {"resolved": true, "selected": false}
	var gate := ordinary_condition(str(reaction.get("condition", "")), int(state.get("heating_flag", 0)), float(state.get("temperature", 20.0)))
	if not gate.resolved: return gate
	if not gate.allowed: return {"resolved": true, "selected": false}
	if reaction.reactants.is_empty() or reaction.products.is_empty(): return {"resolved": false, "error": "Empty native equilibrium side"}
	var working := state.duplicate(true)
	ensure_species(working, reaction)
	for side in [reaction.reactants, reaction.products]:
		for item in side:
			var species := str(item.get("species", item.get("name", "")))
			if phase_suffix(species) == "(固体)" and (not working.solid_3cd8.has(species) or not working.solid_3ff8.has(species)):
				return {"resolved": false, "error": "Native solid particle cache is uninitialized: " + species}
	var k := float(reaction.get("equilibrium_degree_or_constant", 0.0))
	var rate_pair := X87.multiply(X87.multiply([float(reaction.get("reaction_rate", 0.0)), 0.0], native_delta_seconds), speed_factor(int(state.get("speed_setting", 10))))
	if rate_pair.is_empty(): return {"resolved": false, "error": "Native rate arithmetic unsupported"}
	var step_size := 0.0
	var sum_extent := 0.0
	var iterations := 0
	while iterations < 10000:
		iterations += 1
		var forward_limit := _native_limit(working, reaction.reactants)
		var reverse_limit := _native_limit(working, reaction.products)
		var products := _equilibrium_products(working, reaction)
		if not products.resolved: return products
		var denominator := float(products.reactant_product)
		var numerator := float(products.product_product)
		if denominator < 1e-100 and numerator < 1e-100: break
		var forward := false
		if denominator >= 1e-100:
			var ratio_pair := X87.divide([numerator, 0.0], denominator)
			if ratio_pair.is_empty(): return {"resolved": false, "error": "Native quotient arithmetic unsupported"}
			var quotient := X87.stored_double(ratio_pair)
			var difference := X87.add([quotient, 0.0], -k)
			if float(difference[0]) < 0: difference = X87.multiply(difference, -1.0)
			var tolerance := X87.multiply(X87.from_extended80_hex("2c6519e25817b7d1f13f"), k)
			if difference.is_empty() or tolerance.is_empty(): return {"resolved": false, "error": "Native convergence arithmetic unsupported"}
			if _pair_less(difference, tolerance) or quotient == k: break
			forward = quotient < k
		var limit := forward_limit if forward else reverse_limit
		if limit < 1e-100:
			limit = _native_limit(working, reaction.reactants if forward else reaction.products, true)
		step_size = step_size * 0.5 if step_size >= 1e-100 else limit * 0.5
		var clipped := _pair_less(rate_pair, [step_size, 0.0])
		var extent := X87.stored_double(rate_pair) if clipped else step_size
		if not _native_equilibrium_mutation(working, reaction, extent, forward): return {"resolved": false, "error": "Native update arithmetic unsupported"}
		sum_extent += extent if forward else -extent
		if clipped: break
	if iterations >= 10000: return {"resolved": false, "error": "Native iteration did not finish within verification bound"}
	state.merge(working, true)
	return {"resolved": true, "selected": true, "extent": sum_extent, "iterations": iterations, "pass": "water" if str(reaction.native_note) == "水的电离" else "general"}

static func normalize_record(record: Dictionary, cold_cem: bool) -> Dictionary:
	var result := record.duplicate(true)
	if record.has("parameters"):
		var p: Array = Array(record.parameters)
		if p.size() != 5: return {"error": "Five native parameters required"}
		result["condition"] = str(p[1])
		result["reaction_rate"] = float(p[2])
		result["equilibrium_degree_or_constant"] = float(p[3])
		result["equilibrium_mode"] = str(p[4])
		result["reaction_heat"] = float(p[0])
	if cold_cem:
		result["native_note"] = ""
		result["equation_type"] = ""
	else:
		if not record.has("optional_note_lines") or record.optional_note_lines.size() != 3:
			return {"error": "Native library's three note strings required"}
		result["native_note"] = str(record.optional_note_lines[2])
	for side in ["reactants", "products"]:
		var items: Array = []
		for item in record[side]:
			items.append({"species": str(item.get("species", item.get("name", ""))), "coefficient": int(item.coefficient)})
		result[side] = items
	return result

static func native_duplicate(incoming: Dictionary, existing: Dictionary) -> bool:
	# FUN_00462b48 counts all cross-matching names; coefficients/IDs ignored.
	for side in ["reactants", "products"]:
		var matches := 0
		for a in incoming[side]:
			for b in existing[side]:
				if str(a.get("species", a.get("name", ""))) == str(b.get("species", b.get("name", ""))): matches += 1
		if matches != incoming[side].size(): return false
	return true

static func native_names_present(state: Dictionary, side: Array) -> bool:
	# FUN_00462520 / 004625c0 use names, including zero-amount slots.
	var matches := 0
	for item in side:
		var species := str(item.get("species", item.get("name", "")))
		for stored in state.moles:
			if str(stored) == species: matches += 1
	return matches == side.size()

static func smart_condition(condition: String, heating_flag: int, temperature: float) -> Dictionary:
	# Original tokenizer uses ASCII spaces, up to ten nonempty tokens.
	var tokens := condition.split(" ", false)
	for i in range(mini(10, tokens.size())):
		var token := str(tokens[i])
		if token in ["加热", "加强热", "高温"] and heating_flag == 0: return {"resolved": true, "allowed": false}
		if token in ["加强热", "高温"] and temperature < 200.0: return {"resolved": true, "allowed": false}
		if token == "点燃": return {"resolved": true, "allowed": false}
		if token.begins_with("温度>") or token.begins_with("温度<"):
			var number := token.substr(3)
			if not number.is_valid_float(): return {"resolved": false, "error": "Native smart StrToFloat token invalid"}
			# Both original smart branches test vessel temperature < threshold.
			if temperature < float(number): return {"resolved": true, "allowed": false}
	return {"resolved": true, "allowed": true}

static func select_smart(state: Dictionary, library: Array) -> Dictionary:
	if not state.get("reactions", null) is Array: return {"resolved": false, "error": "Native ordered reaction records required"}
	var working := state.duplicate(true)
	var added: Array = []
	for candidate in library:
		var duplicate := false
		for existing in working.reactions:
			if native_duplicate(candidate, existing): duplicate = true; break
		if duplicate: continue
		if int(working.get("ion_flag", 0)) == 0 and str(candidate.get("equation_type", "")) == "离子": continue
		var can_insert := native_names_present(working, candidate.reactants)
		if not can_insert:
			can_insert = str(candidate.get("equilibrium_mode", "")) == "可逆" and native_names_present(working, candidate.products)
		if not can_insert: continue
		var gate := smart_condition(str(candidate.get("condition", "")), int(working.get("heating_flag", 0)), float(working.get("temperature", 20)))
		if not gate.resolved: return gate
		if not gate.allowed: continue
		if working.reactions.size() < 50:
			working.reactions.append(candidate.duplicate(true))
			added.append(str(candidate.get("id", candidate.get("name", ""))))
		# Native calls 00462660 even if the fifty-record limit prevents insertion.
		ensure_species(working, candidate, true)
	state.merge(working, true)
	return {"resolved": true, "added": added}

static func step_core(state: Dictionary, library: Array, native_delta_seconds: float) -> Dictionary:
	if not state.get("reactions", null) is Array: return {"resolved": false, "error": "Native ordered reaction records required"}
	var working := state.duplicate(true)
	begin_reaction_cycle(working)
	if int(working.get("smart_flag", 0)) == 1:
		var smart := select_smart(working, library)
		if not smart.resolved: return smart
	var results: Array = []
	for record in working.reactions:
		var result := step_one_way(working, record, native_delta_seconds)
		if not result.resolved: return result
		results.append(result)
	for water_pass in [false, true]:
		for record in working.reactions:
			if not record.has("native_note"): return {"resolved": false, "error": "Native note missing"}
			if (str(record.native_note) == "水的电离") != water_pass: continue
			var result := step_equilibrium(working, record, native_delta_seconds)
			if not result.resolved: return result
			results.append(result)
	var suspended := 0.0
	for species in working.moles:
		if not working.get("solid_3cd8", {}).has(species):
			return {"resolved": false, "error": "Native particle slot 0x3CD8 is uninitialized: " + str(species)}
		suspended += float(working.solid_3cd8[species])
	working["solid_4318"] = maxf(float(working.get("solid_4318", 0)), suspended) if suspended >= 1e-10 else 0.0
	state.merge(working, true)
	return {"resolved": true, "passes": results}

static func prepare_selected_records(state: Dictionary) -> Dictionary:
	# FUN_0046c894 invoked by native run-start: reactants then products per record.
	if not state.get("reactions", null) is Array: return {"resolved": false, "error": "Native ordered reaction records required"}
	for record in state.reactions: ensure_species(state, record)
	return {"resolved": true}
