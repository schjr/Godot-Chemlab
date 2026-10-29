extends SceneTree
const Model = preload("res://scripts/lab_model.gd")
const Dialogs = preload("res://scripts/lab_dialogs.gd")
var failures := 0
func check(condition: bool, message: String) -> void:
	if not condition:
		failures += 1
		push_error(message)
func _initialize() -> void:
	create_timer(20.0).timeout.connect(func(): push_error("Dialog test did not complete"); quit(1))
	_run.call_deferred()
func press(window: Node, name: String) -> void:
	var button: Button = window.find_child(name, true, false)
	check(button != null, "Missing original dialog action: " + name)
	if button != null: button.pressed.emit()
func select_chemical(window: Node, species: String) -> void:
	var tree: Tree = window.find_child("ChemicalRows", true, false)
	var item: TreeItem = tree.get_root().get_first_child()
	while item != null:
		if str(item.get_metadata(0)) == species:
			item.select(0); tree.item_selected.emit(); return
		item = item.get_next()
	check(false, "Original ordered chemical row missing: " + species)
func _run() -> void:
	var owner := Control.new()
	root.add_child(owner)
	var model = Model.new()
	model.configure(JSON.parse_string(FileAccess.get_file_as_string("res://data/reagents.json")), JSON.parse_string(FileAccess.get_file_as_string("res://data/reactions.json")))
	var vessel: Dictionary = model.add_apparatus("sb100")
	check(not vessel.is_empty(), "Original sb100 factory apparatus failed")
	if vessel.is_empty(): quit(1); return
	check(model.add_reagent(vessel.id, "H2O(液体)", 1.0), "Original water addition failed")
	check(model.add_reagent(vessel.id, "HCl(溶解)", 0.02), "Original dissolved reagent addition failed")
	var dialogs = Dialogs.new()
	dialogs.configure(owner, model)
	check(dialogs.append_reagent_rows(vessel, [{"species": "NaOH(溶解)", "moles": 0.0}], true), "Original zero-valued named slot must be retained")
	check(dialogs.append_native_reaction_row(vessel, model.reactions[0]), "Complete native reaction row was not added")
	check(dialogs.append_native_reaction_row(vessel, model.reactions[1]), "Second native reaction row was not added")
	check(not dialogs.append_native_reaction_row(vessel, model.reactions[0]), "Native chemistry duplicate check was bypassed")
	vessel.native_species_volume["NaOH(溶解)"] = 12.5
	check(dialogs.append_reagent_rows(vessel, [{"species": "NaOH(溶解)", "moles": 0.0}], false), "Existing named zero row merge failed")
	check(vessel.native_species_volume["NaOH(溶解)"] == 12.5, "Existing nonphysical cached volume was invented/reset instead of retained")
	check(vessel.native_reaction_records.size() == 2 and vessel.reaction_ids.size() == 2, "Native reaction/UI row mirrors are out of sync")
	var initial_ids: Array = vessel.reaction_ids.duplicate()
	var first_native_record: Dictionary = vessel.native_reaction_records[0]
	check(dialogs.swap_native_reaction_rows(vessel, 0, 1), "Native RowMoved complete-record swap failed")
	check(vessel.reaction_ids == [initial_ids[1], initial_ids[0]] and vessel.native_reaction_records[1] == first_native_record, "Native row move was reduced to IDs or insertion instead of complete-record swap")
	check(dialogs.swap_native_reaction_rows(vessel, 0, 1), "Native row move restore failed")
	var retained_id: String = str(vessel.reaction_ids[1])
	var original_rate := float(vessel.native_reaction_records[1].reaction_rate)
	dialogs.show_add_reagent(vessel.id)
	dialogs.show_properties(vessel.id)
	dialogs.show_reagent_editor()
	dialogs.show_reaction_editor()
	check(owner.get_child_count() == 4, "All four original dialog windows should be constructed")
	var properties: Node = owner.get_child(1)
	select_chemical(properties, "NaOH(溶解)")
	select_chemical(properties, "HCl(溶解)")
	var moles: LineEdit = properties.find_child("ChemicalMoles", true, false)
	var mass: LineEdit = properties.find_child("ChemicalMass", true, false)
	check(moles != null and mass != null, "Original quantity/mass fields missing")
	check(absf(float(moles.text) - 0.02) < 1e-12, "Selected original chemical amount differs")
	var molar := float(model._species["HCl(溶解)"].molar_mass)
	var mass_mode:CheckBox=properties.find_child("ChemicalMassMode",true,false)
	mass_mode.button_pressed=true
	mass.text = str(dialogs._stored_product(0.04,molar))
	check(absf(float(moles.text) - 0.02) < 1e-12, "Original Form4 must not convert before Modify")
	press(properties, "ChemicalApply")
	check(vessel.contents["HCl(溶解)"] == 0.02, "Form4 修改 prematurely mutated the live vessel")
	press(properties, "PropertiesCancel")
	await process_frame
	check(vessel.contents["HCl(溶解)"] == 0.02, "Form4 cancel did not discard temporary edits")
	dialogs.show_properties(vessel.id)
	properties = owner.get_child(owner.get_child_count() - 1)
	select_chemical(properties, "HCl(溶解)")
	moles = properties.find_child("ChemicalMoles", true, false)
	moles.text = "0.04"
	press(properties, "ChemicalApply")
	press(properties, "ChemicalAdd")
	var addition_window: Node = owner.get_child(owner.get_child_count() - 1)
	var reagent_rows: ItemList = addition_window.find_child("AddReagentRows", true, false)
	var found := false
	for i in range(reagent_rows.item_count):
		if str(reagent_rows.get_item_metadata(i)) == "HCl(溶解)": reagent_rows.select(i); found = true; break
	check(found, "Original reagent catalog row missing in add dialog")
	var amount: SpinBox = addition_window.find_child("AddReagentAmount", true, false)
	amount.value = 0.005
	press(addition_window, "AddReagentCommit")
	check(vessel.contents["HCl(溶解)"] == 0.02, "Nested Form5 addition bypassed Form4 temporary rows")
	press(addition_window, "AddReagentClose")
	await process_frame
	var reactions: ItemList = properties.find_child("ReactionRows", true, false)
	reactions.select(1); reactions.item_selected.emit(1)
	var rate: LineEdit = properties.find_child("ReactionRate", true, false)
	rate.text = "0.003"
	press(properties, "ReactionApply")
	reactions.select(0)
	press(properties, "ReactionDelete")
	check(vessel.native_reaction_records.size() == 2 and float(vessel.native_reaction_records[1].reaction_rate) == original_rate, "Temporary reaction edit/delete leaked into simulation")
	press(properties, "PropertiesCommit")
	await process_frame
	check(absf(float(vessel.contents["HCl(溶解)"]) - 0.045) < 1e-15, "Original 确定 did not commit the quantity and nested addition rows")
	check(vessel.native_reaction_records.size() == 1 and vessel.reaction_ids == [retained_id], "Deleting native row did not preserve following complete record/order")
	check(float(vessel.native_reaction_records[0].reaction_rate) == 0.003 and float(vessel.rate_overrides[retained_id]) == 0.003, "Native reaction rate and UI mirror did not commit together")
	# Volume addition is phase-specific; original solution inserts water first.
	var solution: Dictionary = dialogs.reagent_addition_rows("HCl(溶解)", 2.0, 2, 1.0)
	check(solution.ok and solution.rows[0].species == "H2O(液体)" and solution.rows[1].species == "HCl(溶解)", "Original solution water-before-solute insertion order differs")
	check(absf(float(solution.rows[1].moles) - 0.002) < 1e-15, "Original solution volume/concentration quantity differs")
	check(not dialogs.reagent_addition_rows("Zn(固体)", 2.0, 2).ok, "Unsupported solid-by-volume addition invented")
	check(not dialogs.reagent_addition_rows("HCl(溶解)", -1.0, 0).ok, "Negative original reagent quantity accepted")
	dialogs.show_properties(vessel.id)
	properties = owner.get_child(owner.get_child_count() - 1)
	press(properties, "ChemicalClear"); press(properties, "ReactionClear")
	check(not vessel.contents.is_empty() and vessel.native_reaction_records.size() == 1, "Delete-all bypassed original temporary rows")
	press(properties, "PropertiesCommit")
	await process_frame
	check(vessel.contents.is_empty() and vessel.native_reaction_records.is_empty() and vessel.reaction_ids.is_empty() and vessel.rate_overrides.is_empty(), "Original clear-all commit left stale active rows")
	# TFORM4 has no temperature/capacity edits. Native zero-capacity stands
	# and preexisting full-precision values must survive open/confirm bit-exact.
	var stand: Dictionary = model.add_apparatus("tiejt0")
	check(not stand.is_empty() and float(stand.volume_ml) == 0.0, "Original stand zero capacity changed at factory")
	var stand_temperature_bits := PackedFloat64Array([float(stand.temperature)]).to_byte_array()
	var stand_capacity_bits := PackedFloat64Array([float(stand.volume_ml)]).to_byte_array()
	dialogs.show_properties(int(stand.id))
	properties = owner.get_child(owner.get_child_count() - 1)
	check(properties.find_child("NativeCapacityValue", true, false) is Label and properties.find_child("NativeTemperatureValue", true, false) is Label, "Foreign temperature/capacity input controls remain exposed")
	press(properties, "PropertiesCommit")
	await process_frame
	check(PackedFloat64Array([float(stand.temperature)]).to_byte_array() == stand_temperature_bits and PackedFloat64Array([float(stand.volume_ml)]).to_byte_array() == stand_capacity_bits, "Readonly confirmation changed original stand double bits")
	# Source49F0C8 has no scalar range check; these are preserved input state,
	# not newly exposed controls for assigning foreign temperature/capacity.
	for pair in [[-500.1234567890123, 0.0], [29.31415926535898, 0.00025], [2000.123456789012, 1000000.123456789]]:
		vessel.temperature = float(pair[0]); vessel.volume_ml = float(pair[1])
		vessel.native_fields["0x88"] = String.num(float(pair[0]), 17)
		vessel.native_fields["0x28"] = String.num(float(pair[1]), 17)
		var temp_bits := PackedFloat64Array([float(vessel.temperature)]).to_byte_array()
		var cap_bits := PackedFloat64Array([float(vessel.volume_ml)]).to_byte_array()
		var temp_raw: String = vessel.native_fields["0x88"]
		var cap_raw: String = vessel.native_fields["0x28"]
		dialogs.show_properties(vessel.id)
		properties = owner.get_child(owner.get_child_count() - 1)
		press(properties, "PropertiesCommit")
		await process_frame
		check(PackedFloat64Array([float(vessel.temperature)]).to_byte_array() == temp_bits and PackedFloat64Array([float(vessel.volume_ml)]).to_byte_array() == cap_bits, "Readonly scalar confirmation imposed a range/step/parser")
		check(vessel.native_fields["0x88"] == temp_raw and vessel.native_fields["0x28"] == cap_raw, "Readonly scalar raw native text changed")
	check(dialogs._parse_terms("HCl(溶解) | 2").size() == 1, "Valid chemical terms must parse")
	check(dialogs._parse_terms("missing | 2").is_empty(), "Unknown chemicals must fail validation")
	check(dialogs._parse_terms("HCl(溶解) | -2").is_empty(), "Negative stoichiometry must fail validation")
	for child in owner.get_children(): child.queue_free()
	owner.queue_free()
	await process_frame
	print("Original dialog row/commit regression: %s; sb100 factory, zero-mole rows, mass conversion, temporary edits/cancel/commit, ordered full reaction deletion/rate synchronization, water-first solution addition, native clear-all" % ["PASS" if failures == 0 else "FAIL"])
	quit(0 if failures == 0 else 1)
