class_name LabDialogs
extends RefCounted

signal status(text: String)
signal variable_defined(name: String, id: int, species: String, metric: String)
signal catalogs_changed
signal property_closed(vessel_id:int,confirmed:bool)
var property_close_pending:=false
var _property_window:Window
const Model = preload("res://scripts/lab_model.gd")
const X87 = preload("res://scripts/original/original_x87.gd")
const NativeReaction = preload("res://scripts/original/original_reaction.gd")
const Quantities = preload("res://scripts/original/original_quantities.gd")
const NativeProgram = preload("res://scripts/original/original_program.gd")
const LiveProperty = preload("res://scripts/original/original_live_property.gd")
const WindowInputGate=preload("res://scripts/original/original_window_input_gate.gd")
var host: Control
var model: Model
var forms: Dictionary = {}

class NativeReactionRows extends ItemList:
	signal row_swapped(from_index: int, to_index: int)
	func _get_drag_data(at_position: Vector2):
		var index := get_item_at_position(at_position, true)
		if index < 0: return null
		return {"native_reaction_row": index, "owner": get_instance_id()}
	func _can_drop_data(at_position: Vector2, data) -> bool:
		return data is Dictionary and int(data.get("owner", -1)) == get_instance_id() and get_item_at_position(at_position, true) >= 0
	func _drop_data(at_position: Vector2, data) -> void:
		if not _can_drop_data(at_position, data): return
		row_swapped.emit(int(data.native_reaction_row), get_item_at_position(at_position, true))

func configure(owner: Control, lab: Model) -> void:
	host = owner
	model = lab
	var parsed = JSON.parse_string(FileAccess.get_file_as_string("res://data/forms.json"))
	if parsed is Dictionary: forms = parsed

func _find_caption(node: Dictionary, name: String) -> String:
	if node.get("name", "") == name: return str(node.get("properties", {}).get("Caption", ""))
	for child in node.get("children", []):
		var found: String = _find_caption(child, name)
		if not found.is_empty(): return found
	return ""

func _caption(form: String, name: String, fallback: String) -> String:
	var found: String = _find_caption(forms.get("_main/" + form, {}), name)
	return fallback if found.is_empty() else found

func _window(title: String, size: Vector2i = Vector2i(730, 560), modal_parent:Window=null) -> Dictionary:
	var window := Window.new()
	window.title = title
	window.size = size
	window.min_size = Vector2i(500, 390)
	window.transient = true
	window.exclusive = false
	window.theme = host.theme
	if is_instance_valid(modal_parent):modal_parent.add_child(window);window.exclusive=true
	else:host.add_child(window)
	var margin := MarginContainer.new()
	margin.set_anchors_and_offsets_preset(Control.PRESET_FULL_RECT)
	for side in ["left", "right", "top", "bottom"]: margin.add_theme_constant_override("margin_" + side, 10)
	window.add_child(margin)
	var root := VBoxContainer.new()
	margin.add_child(root)
	var input_gate:WindowInputGate
	if host.has_method("dispatch_ui"):
		input_gate=preload("res://scripts/original/original_window_input_gate.gd").new()
		input_gate.dispatch=Callable(host,"dispatch_ui");window.add_child(input_gate)
	var close_callback:Callable=func():
		if host.has_method("dispatch_ui"):host.dispatch_ui(Callable(input_gate.target,"close_window"),[input_gate.target])
		else:window.queue_free()
	window.close_requested.connect(close_callback)
	window.popup_centered()
	return {"window": window, "root": root,"close_callback":close_callback}

func _label(parent: Node, text: String) -> Label:
	var label := Label.new()
	label.text = text
	parent.add_child(label)
	return label

func _button(parent: Node, text: String, callback: Callable) -> Button:
	var button := Button.new()
	button.text = text
	parent.add_child(button)
	button.pressed.connect(callback)
	return button

func _row(parent: Node) -> HBoxContainer:
	var row := HBoxContainer.new()
	parent.add_child(row)
	return row

func _line(parent: Node, title: String, text: String = "") -> LineEdit:
	var row := _row(parent)
	var label := _label(row, title)
	label.custom_minimum_size.x = 115
	var edit := LineEdit.new()
	edit.text = text
	edit.size_flags_horizontal = Control.SIZE_EXPAND_FILL
	row.add_child(edit)
	return edit

func _spin(parent: Node, title: String, value: float, minimum: float = 0.0, maximum: float = 1000000.0, step_value: float = 0.001) -> SpinBox:
	var row := _row(parent)
	_label(row, title).custom_minimum_size.x = 115
	var spin := SpinBox.new()
	spin.min_value = minimum
	spin.max_value = maximum
	spin.step = step_value
	spin.value = value
	spin.size_flags_horizontal = Control.SIZE_EXPAND_FILL
	row.add_child(spin)
	return spin

func _check(parent: Node, text: String, value: bool) -> CheckBox:
	var check := CheckBox.new()
	check.text = text
	check.button_pressed = value
	parent.add_child(check)
	return check

func _list(parent: Node) -> ItemList:
	var list := ItemList.new()
	list.size_flags_vertical = Control.SIZE_EXPAND_FILL
	list.custom_minimum_size.y = 140
	parent.add_child(list)
	return list

func _options(parent: Node, labels: Array) -> OptionButton:
	var option := OptionButton.new()
	for title in labels: option.add_item(str(title))
	parent.add_child(option)
	return option

func _species_record(species: String) -> Dictionary:
	for r in model.reagents:
		if str(r.species) == species: return r
	return {}

func _refresh_catalogs() -> void:
	model.configure(model.reagents, model.reactions)
	model.changed.emit()
	catalogs_changed.emit()

func _stored_product(a: float, b: float) -> float:
	return X87.stored_double(X87.multiply([a, 0.0], b))

func _stored_quotient(a: float, b: float) -> float:
	return X87.stored_double(X87.divide([a, 0.0], b))

func modify_property_quantity_rows(rows: Array, index: int, species: String, text: String, by_mass: bool) -> Dictionary:
	# Native49FE58: selected radio ->541348 ->QWORD, then540F7C grid text.
	if index < 0 or index >= rows.size() or rows.size() > 100:
		return {"ok":false,"error":"原始药品行索引无效。"}
	var reagent := _species_record(species)
	if reagent.is_empty(): return {"ok":false,"error":"药品名称未在原始药品库中找到。"}
	for i in rows.size():
		if i != index and str(rows[i][0]) == species: return {"ok":false,"error":"容器中已有这个药品。"}
	var parsed := NativeProgram.parse_number(text)
	if parsed.is_empty(): return {"ok":false,"error":"原始数值解析失败；该输入未写入。"}
	var amount := X87.stored_double(parsed)
	if not is_finite(amount): return {"ok":false,"error":"原始非有限数值异常路径未完成。"}
	if amount < 0.0: return {"ok":false,"error":"药品的质量不能为负数" if by_mass else "药品的mol量不能为负数"}
	var molar := float(reagent.molar_mass)
	if by_mass and molar == 0.0: return {"ok":false,"error":"原始零摩尔质量除法异常路径未完成。"}
	var mol := _stored_quotient(amount,molar) if by_mass else amount
	var mass := amount if by_mass else _stored_product(amount,molar)
	var updated := rows.duplicate(true)
	updated[index] = [species,NativeProgram.format_number(mol),NativeProgram.format_number(mass)]
	return parse_property_quantity_rows(updated)

func parse_property_quantity_rows(rows: Array) -> Dictionary:
	var contents: Dictionary = {}; var masses: Dictionary = {}
	for row in rows:
		var mol := NativeProgram.parse_number(str(row[1])); var mass := NativeProgram.parse_number(str(row[2]))
		if mol.is_empty() or mass.is_empty(): return {"ok":false,"error":"原始药品表数值解析失败。"}
		contents[str(row[0])] = X87.stored_double(mol); masses[str(row[0])] = X87.stored_double(mass)
	return {"ok":true,"rows":rows,"contents":contents,"masses":masses}

func reagent_addition_rows(species: String, amount: float, unit: int, concentration: float = 1.0) -> Dictionary:
	# Form5 004A62DC: liquid ml uses density, solution ml inserts water FIRST.
	if not model._species.has(species) or not is_finite(amount) or amount < 0.0:
		return {"ok": false, "error": "请选择原药品库中的药品；数量不得为负。"}
	var record: Dictionary = model._species[species]
	var molar := float(record.molar_mass)
	if molar <= 0.0: return {"ok": false, "error": "原始摩尔质量无效。"}
	var mol := amount
	var dose_mass := _stored_product(amount,molar)
	var rows: Array = []
	if unit == 1:
		mol = _stored_quotient(amount, molar)
		dose_mass = amount
	elif unit == 2:
		var phase := Quantities.phase_suffix(species)
		if phase == "(液体)":
			if not record.has("density_or_render_parameter"): return {"ok": false, "error": "缺少原始液体密度字段。"}
			dose_mass = _stored_product(float(record.density_or_render_parameter),amount)
			mol = _stored_quotient(dose_mass, molar)
		elif phase in ["(溶解)", "(离子)"]:
			if not is_finite(concentration) or concentration < 0.0 or not model._species.has("H2O(液体)"):
				return {"ok": false, "error": "原始溶液浓度或水记录无效。"}
			var water: Dictionary = model._species["H2O(液体)"]
			if not water.has("density_or_render_parameter"): return {"ok": false, "error": "缺少原始水密度字段。"}
			var water_mol := _stored_quotient(_stored_product(float(water.density_or_render_parameter), amount), float(water.molar_mass))
			rows.append({"species": "H2O(液体)", "moles": water_mol,"mass":_stored_product(float(water.density_or_render_parameter),amount)})
			mol = _stored_quotient(_stored_product(concentration, amount), 1000.0)
			dose_mass = _stored_product(mol,molar)
		else: return {"ok": false, "error": "原程序仅允许液体或溶液按体积添加。"}
	elif unit != 0: return {"ok": false, "error": "未恢复该添加单位。"}
	if not is_finite(mol): return {"ok": false, "error": "原始添加数量超出范围。"}
	rows.append({"species": species, "moles": mol,"mass":dose_mass})
	return {"ok": true, "rows": rows}

func append_reagent_rows(vessel: Dictionary, rows: Array, live: bool = false) -> bool:
	for row in rows:
		var name := str(row.species)
		if not model._species.has(name) or not is_finite(float(row.moles)) or float(row.moles) < 0.0: return false
		var new_slot: bool = not vessel.contents.has(name)
		if new_slot and vessel.contents.size() >= 100:
			status.emit("容器中的药品已有100钟！")
			return false # Keep prior water/species writes, as original Form5 does.
		if live:
			if not model.add_reagent(int(vessel.id), name, float(row.moles)): return false
		else:
			var mass_table:Dictionary=vessel.get("native_editor_mass_rows",vessel.get("native_species_mass",{}))
			if not new_slot and not mass_table.has(name):status.emit("原始药品质量槽位未知，未添加药品。");return false
			var dose_mass:float=float(row.get("mass",_stored_product(float(row.moles),float(model._species[name].molar_mass))))
			var previous_mass:float=0.0 if new_slot else float(mass_table[name])
			if not vessel.has("native_editor_mass_rows"):vessel.native_editor_mass_rows=vessel.get("native_species_mass",{}).duplicate(true)
			vessel.native_editor_mass_rows[name]=X87.stored_double(X87.add([previous_mass,0.0],dose_mass))
			vessel.contents[name] = X87.stored_double(X87.add([float(vessel.contents.get(name, 0.0)), 0.0], float(row.moles)))
		# Form5 explicitly writes zero volume for nonphysical new rows.
		if new_slot and Quantities.phase_suffix(name) not in ["(固体)", "(液体)", "(气体)"]:
			vessel.native_species_volume[name] = 0.0
			if not live:
				if not vessel.has("native_editor_volume_writes"):vessel.native_editor_volume_writes={}
				vessel.native_editor_volume_writes[vessel.contents.keys().find(name)]="0000000000000000"
	return true

func sync_native_reaction_rows(v: Dictionary) -> void:
	# 49F0C8 commits the entire ordered 0xE8-record temporary array. IDs and
	# override dictionaries are UI mirrors, never a substitute native array.
	v.reaction_ids = []
	v.reaction_overrides = {}
	v.rate_overrides = {}
	for record in v.native_reaction_records:
		var key := str(record.get("name", record.get("id", "")))
		v.reaction_ids.append(key)
		v.reaction_overrides[key] = record
		v.rate_overrides[key] = float(record.reaction_rate)

func append_native_reaction_row(v: Dictionary, source: Dictionary) -> bool:
	if source.is_empty(): return false
	var record := NativeReaction.normalize_record(source, false) if source.has("optional_note_lines") else source.duplicate(true)
	if record.has("error"): status.emit(str(record.error)); return false
	# Native Form2/8 selectors call462B48: duplicate chemistry, not UI ID.
	for existing in v.native_reaction_records:
		if NativeReaction.native_duplicate(record, existing): return false
	if v.native_reaction_records.size() >= 50:
		status.emit("原始反应记录已达到50条；不能写入未恢复的越界槽位。")
		return false
	v.native_reaction_records.append(record.duplicate(true))
	sync_native_reaction_rows(v)
	return true

func remove_native_reaction_row(v: Dictionary, index: int) -> bool:
	if index < 0 or index >= v.native_reaction_records.size(): return false
	# 4A169C shifts full records; remaining order must survive deletion.
	v.native_reaction_records.remove_at(index)
	sync_native_reaction_rows(v)
	return true

func swap_native_reaction_rows(v: Dictionary, first: int, second: int) -> bool:
	if first < 0 or second < 0 or first >= v.native_reaction_records.size() or second >= v.native_reaction_records.size(): return false
	# 4A253C StringGrid2RowMoved swaps complete 0xE8 records, not insertion.
	var saved: Dictionary = v.native_reaction_records[second]
	v.native_reaction_records[second] = v.native_reaction_records[first]
	v.native_reaction_records[first] = saved
	sync_native_reaction_rows(v)
	return true

func set_native_reaction_rate(v: Dictionary, key: String, value: float) -> bool:
	if not is_finite(value): return false
	for record in v.native_reaction_records:
		if str(record.get("name", record.get("id", ""))) == key:
			record.reaction_rate = value # 4A14E4 edits the selected complete record.
			if record.has("parameters"): record.parameters[2] = str(value)
			sync_native_reaction_rows(v)
			return true
	return false

func modify_native_reaction_fields(v:Dictionary,index:int,texts:Array)->Dictionary:
	# Native4A14E4 writes selected record fields, no sign/range/string whitelist.
	if index<0 or index>=v.native_reaction_records.size() or texts.size()!=5:return {"ok":false,"error":"原始反应行索引无效。"}
	var parsed:Array=[]
	for field in [0,2,3]:
		var pattern:=RegEx.new();pattern.compile("^[+-]?(?:[0-9]+(?:\\.[0-9]*)?|\\.[0-9]+)(?:[eE][+-]?[0-9]+)?$")
		if pattern.search(str(texts[field]).strip_edges())==null:return {"ok":false,"error":"原始数值异常呈现尚未完成；输入未写入。"}
		var operand:=NativeProgram.parse_number(str(texts[field]))
		if operand.is_empty():return {"ok":false,"error":"原始数值解析尚不支持该输入。"}
		var number:=X87.stored_double(operand)
		# Native541348 preserves the sign of a textual zero.
		if number==0.0 and str(texts[field]).strip_edges().begins_with("-"):number="0000000000000080".hex_decode().decode_double(0)
		if not is_finite(number):return {"ok":false,"error":"原始非有限数异常路径尚未完成。"}
		parsed.append(number)
	var record:Dictionary=v.native_reaction_records[index]
	record.reaction_rate=parsed[0];record.condition=str(texts[1]);record.reaction_heat=parsed[1]
	record.equilibrium_degree_or_constant=parsed[2];record.equilibrium_mode=str(texts[4])
	if record.has("parameters"):
		record.parameters=[str(texts[2]),str(texts[1]),str(texts[0]),str(texts[3]),str(texts[4])]
	sync_native_reaction_rows(v)
	return {"ok":true}

func show_add_reagent(vessel_id: int, draft: Dictionary = {}, refresh: Callable = Callable()) -> void:
	var vessel: Dictionary = draft if not draft.is_empty() else model.get_vessel(vessel_id)
	if vessel.is_empty(): status.emit("请先选择容器。"); return
	var ui: Dictionary = _window("添加药品 — " + str(vessel.label), Vector2i(490, 490),_property_window if not draft.is_empty() else null)
	var root: VBoxContainer = ui.root
	var search := _line(root, "药品名称")
	var category := _options(root, ["显示所有药品", "显示所有固体", "显示所有液体", "显示所有气体", "显示所有溶质", "显示所有离子"])
	var list := _list(root)
	list.name = "AddReagentRows"
	var amount := _spin(root, "加入量", 0.01, 0.0, 1000000.0, 0.0001)
	amount.name = "AddReagentAmount"
	var units := _options(root, ["物质的量 (mol)", "质量 (g)", "液体／溶液体积 (mL)"])
	units.name = "AddReagentUnits"
	var concentration := _spin(root, "浓度 (mol/L)", 1.0, 0.000001, 1000.0, 0.001)
	var feedback := _label(root, "质量按药品摩尔质量换算；溶液体积按指定浓度换算。")
	var refresh_list: Callable = func():
		list.clear()
		var categories: Array = ["", "固体", "液体", "气体", "溶解", "离子"]
		for r in model.reagents:
			if not search.text.is_empty() and not (str(r.name) + str(r.species)).to_lower().contains(search.text.to_lower()): continue
			if category.selected > 0 and str(r.category).strip_edges() != categories[category.selected]: continue
			list.add_item(str(r.name))
			list.set_item_metadata(list.item_count - 1, str(r.species))
		if list.item_count > 0: list.select(0)
	search.text_changed.connect(func(_text): refresh_list.call())
	category.item_selected.connect(func(_index): refresh_list.call())
	refresh_list.call()
	var actions := _row(root)
	_button(actions, "添加", func():
		var selected: PackedInt32Array = list.get_selected_items()
		if selected.is_empty(): feedback.text = "请选择药品。"; return
		var species: String = str(list.get_item_metadata(selected[0]))
		var additions := reagent_addition_rows(species, amount.value, units.selected, concentration.value)
		if not additions.get("ok", false): feedback.text = str(additions.error); return
		if append_reagent_rows(vessel, additions.rows, draft.is_empty()):
			feedback.text = "已添加：" + species
			status.emit(feedback.text)
			if refresh.is_valid(): refresh.call()
		else: feedback.text = "原始药品添加未完成；请检查容器和药品槽位。"
	).name = "AddReagentCommit"
	_button(actions, "关闭", ui.window.queue_free).name = "AddReagentClose"

func _equation_text(r: Dictionary) -> String:
	var left: PackedStringArray = []
	var right: PackedStringArray = []
	for t in r.get("reactants", []): left.append((str(t.coefficient) if float(t.coefficient) != 1.0 else "") + str(t.species))
	for t in r.get("products", []): right.append((str(t.coefficient) if float(t.coefficient) != 1.0 else "") + str(t.species))
	return " + ".join(left) + (" ⇌ " if r.get("equilibrium_mode", "") == "可逆" else " → ") + " + ".join(right)

func _reaction_record(v: Dictionary, id: String) -> Dictionary:
	for record in v.get("native_reaction_records", []):
		if str(record.get("name", record.get("id", ""))) == id: return record
	if v.get("reaction_overrides", {}).has(id): return v.reaction_overrides[id]
	for r in model.reactions:
		if str(r.id) == id: return r
	return {}

func show_properties(vessel_id: int) -> void:
	var original: Dictionary = model.get_vessel(vessel_id)
	if original.is_empty(): status.emit("请先选择容器。"); return
	# Form4 callbacks edit temporary globals;49F0C8 commits on 确定.
	var v: Dictionary = original.duplicate(true)
	sync_native_reaction_rows(v)
	var ui: Dictionary = _window(_caption("TFORM4", "Form4", "容器属性"), Vector2i(790, 440))
	ui.window.exclusive=true
	_property_window=ui.window
	var close_state:Dictionary={"confirmed":false,"closing":false}
	var close_property:Callable=func(confirmed:bool=false):
		if close_state.closing:return
		close_state.closing=true;close_state.confirmed=confirmed;property_close_pending=true
		ui.window.hide();ui.window.queue_free()
	ui.window.close_requested.disconnect(ui.close_callback)
	ui.window.close_requested.connect(func():
		if host.has_method("dispatch_ui"):host.dispatch_ui(close_property,[false])
		else:close_property.call(false)
	)
	ui.window.tree_exited.connect(func():
		if _property_window==ui.window:_property_window=null
		# Menu_property417750 resumes after the modal window leaves its owner.
		if host.has_method("_original_property_closed"):host._original_property_closed(vessel_id,bool(close_state.confirmed))
		elif not model.running and not model.paused:
			model.recalc();model.refresh_render_state();model.changed.emit()
		property_closed.emit(vessel_id,bool(close_state.confirmed));property_close_pending=false
	)
	var root: VBoxContainer = ui.root
	var tabs := TabContainer.new()
	tabs.size_flags_vertical = Control.SIZE_EXPAND_FILL
	root.add_child(tabs)
	var chemicals := HBoxContainer.new()
	chemicals.name = _caption("TFORM4", "TabSheet1", "容器中的药品")
	chemicals.add_theme_constant_override("separation", 16)
	tabs.add_child(chemicals)
	var contents := Tree.new()
	contents.name = "ChemicalRows"
	contents.columns = 3
	contents.hide_root = true
	contents.select_mode = Tree.SELECT_ROW
	contents.column_titles_visible = true
	contents.set_column_title(0, "药品名称")
	contents.set_column_title(1, "物质的量 (mol)")
	contents.set_column_title(2, "质量 (g)")
	contents.set_column_expand(0, true)
	contents.set_column_expand(1, false)
	contents.set_column_expand(2, false)
	contents.set_column_custom_minimum_width(1, 110)
	contents.set_column_custom_minimum_width(2, 100)
	contents.custom_minimum_size = Vector2(430, 250)
	contents.size_flags_horizontal = Control.SIZE_EXPAND_FILL
	contents.size_flags_vertical = Control.SIZE_EXPAND_FILL
	chemicals.add_child(contents)
	var chemical_editor := VBoxContainer.new()
	chemical_editor.custom_minimum_size.x = 270
	chemical_editor.add_theme_constant_override("separation", 8)
	chemicals.add_child(chemical_editor)
	_label(chemical_editor, "药品名称")
	var chemical_name := LineEdit.new()
	chemical_name.editable = false
	chemical_editor.add_child(chemical_name)
	var moles_row:=_row(chemical_editor)
	var choose_moles:=CheckBox.new();choose_moles.text=_caption("TFORM4","RadioButton1","物质的量");choose_moles.name="ChemicalMolesMode";choose_moles.custom_minimum_size.x=115;moles_row.add_child(choose_moles)
	var quantity:=LineEdit.new();quantity.text="0";quantity.size_flags_horizontal=Control.SIZE_EXPAND_FILL;moles_row.add_child(quantity)
	var mass_row:=_row(chemical_editor)
	var choose_mass:=CheckBox.new();choose_mass.text=_caption("TFORM4","RadioButton2","质量");choose_mass.name="ChemicalMassMode";choose_mass.custom_minimum_size.x=115;mass_row.add_child(choose_mass)
	var mass:=LineEdit.new();mass.text="0";mass.size_flags_horizontal=Control.SIZE_EXPAND_FILL;mass_row.add_child(mass)
	var unit_group:=ButtonGroup.new();choose_moles.button_group=unit_group;choose_mass.button_group=unit_group;choose_moles.button_pressed=true
	quantity.name = "ChemicalMoles"
	mass.name = "ChemicalMass"
	mass.editable=false
	choose_moles.toggled.connect(func(active):quantity.editable=active)
	choose_mass.toggled.connect(func(active):mass.editable=active)
	var chemical_feedback:=_label(chemical_editor, "")
	chemical_feedback.name="ChemicalFeedback"
	var quantity_rows:Array=[]
	var updating: Dictionary = {"active": false, "selected": ""}
	var refresh_contents: Callable = func():
		contents.clear()
		var tree_root := contents.create_item()
		var first: TreeItem = null
		var selected: TreeItem = null
		var next_rows:Array=[]
		for s in v.contents:
			var previous:Array=[]
			for row in quantity_rows:
				if str(row[0])==str(s):previous=row;break
			var moles_text:=NativeProgram.format_number(float(v.contents[s]))
			var mass_text:String
			if not previous.is_empty() and NativeProgram.round_number(float(v.contents[s]))==X87.stored_double(NativeProgram.parse_number(str(previous[1]))) and (not v.get("native_editor_mass_rows",{}).has(s) or NativeProgram.round_number(float(v.native_editor_mass_rows[s]))==X87.stored_double(NativeProgram.parse_number(str(previous[2])))):
				moles_text=str(previous[1]);mass_text=str(previous[2])
			elif v.get("native_editor_mass_rows",{}).has(s):mass_text=NativeProgram.format_number(float(v.native_editor_mass_rows[s]))
			elif v.get("native_species_mass",{}).has(s):mass_text=NativeProgram.format_number(float(v.native_species_mass[s]))
			else:chemical_feedback.text="原始药品质量槽位未知，不能显示替代质量。";return
			next_rows.append([str(s),moles_text,mass_text])
			var item := contents.create_item(tree_root)
			item.set_text(0, str(s))
			item.set_text(1, moles_text)
			item.set_text(2, mass_text)
			item.set_metadata(0, str(s))
			if first == null: first = item
			if str(s) == str(updating.selected): selected = item
		quantity_rows.clear();quantity_rows.append_array(next_rows)
		if selected == null: selected = first
		if selected != null: selected.select(0); contents.item_selected.emit()
		else:
			updating.selected = ""
			chemical_name.text = ""
			updating.active = true
			quantity.text = "0"; mass.text = "0"
			updating.active = false
	contents.item_selected.connect(func():
		if contents.get_selected() == null: return
		var s: String = str(contents.get_selected().get_metadata(0))
		updating.selected = s
		chemical_name.text = s
		updating.active = true
		quantity.text = contents.get_selected().get_text(1)
		mass.text = contents.get_selected().get_text(2)
		updating.active = false
	)
	refresh_contents.call()
	var chemical_actions := GridContainer.new()
	chemical_actions.columns = 2
	chemical_editor.add_child(chemical_actions)
	_button(chemical_actions, "添加", func(): show_add_reagent(vessel_id, v, refresh_contents)).name = "ChemicalAdd"
	var modify_button := _button(chemical_actions, "修改", func():
		if contents.get_selected() == null: return
		var species:String=str(contents.get_selected().get_metadata(0))
		var index:int=v.contents.keys().find(species)
		var modified:=modify_property_quantity_rows(quantity_rows,index,species,mass.text if choose_mass.button_pressed else quantity.text,choose_mass.button_pressed)
		if not modified.ok:chemical_feedback.text=str(modified.error);return
		quantity_rows.clear();quantity_rows.append_array(modified.rows)
		v.contents=modified.contents;v.native_editor_mass_rows=modified.masses
		chemical_feedback.text=""
		refresh_contents.call()
	)
	modify_button.name = "ChemicalApply"
	_button(chemical_actions, "删除", func():
		if contents.get_selected() == null: return
		v.contents.erase(str(contents.get_selected().get_metadata(0)))
		refresh_contents.call()
	).name = "ChemicalDelete"
	_button(chemical_actions, "全部删除", func(): v.contents.clear(); refresh_contents.call()).name = "ChemicalClear"
	_button(chemical_actions, "定义变量", func():
		if contents.get_selected() == null: return
		_define_variable(vessel_id, str(contents.get_selected().get_metadata(0)))
	).name="ChemicalDefineVariable"
	for button in chemical_actions.get_children():
		button.custom_minimum_size.x = 128
	var editor_space := Control.new()
	editor_space.size_flags_vertical = Control.SIZE_EXPAND_FILL
	chemical_editor.add_child(editor_space)
	var equations := VBoxContainer.new()
	equations.name = _caption("TFORM4", "TabSheet2", "容器中的反应")
	tabs.add_child(equations)
	var reaction_panel:=HBoxContainer.new();reaction_panel.size_flags_vertical=Control.SIZE_EXPAND_FILL;equations.add_child(reaction_panel)
	var equation_list := NativeReactionRows.new()
	equation_list.size_flags_vertical = Control.SIZE_EXPAND_FILL
	equation_list.custom_minimum_size.y = 140
	equation_list.size_flags_horizontal=Control.SIZE_EXPAND_FILL
	reaction_panel.add_child(equation_list)
	var reaction_editor:=VBoxContainer.new();reaction_editor.custom_minimum_size.x=285;reaction_panel.add_child(reaction_editor)
	equation_list.name = "ReactionRows"
	var rate:=_line(reaction_editor,"反应速度：","0");rate.name="ReactionRate"
	var condition:=_line(reaction_editor,"反应条件：","");condition.name="ReactionCondition"
	var heat:=_line(reaction_editor,"反应热：","0");heat.name="ReactionHeat";heat.get_parent().visible=false # ShippedEdit4/Label3 are hidden.
	var equilibrium:=_line(reaction_editor,"平衡常数：","0");equilibrium.name="ReactionEquilibrium"
	var mode:=_line(reaction_editor,"平衡方式：","");mode.name="ReactionMode"
	var live_rate:=LineEdit.new();live_rate.name="LiveReactionRate";live_rate.editable=false;live_rate.visible=false
	equations.add_child(live_rate)
	var details := _label(equations, "反应热：  反应条件：  平衡常数：")
	details.autowrap_mode = TextServer.AUTOWRAP_WORD_SMART
	var refresh_reactions: Callable = func():
		equation_list.clear()
		for id in v.reaction_ids:
			var r: Dictionary = _reaction_record(v, str(id))
			if not r.is_empty():
				equation_list.add_item(_equation_text(r))
				equation_list.set_item_metadata(equation_list.item_count - 1, str(id))
	equation_list.item_selected.connect(func(index):
		var id: String = str(equation_list.get_item_metadata(index))
		var r: Dictionary = _reaction_record(v, id)
		if model.running or model.paused:
			var live:Dictionary=model.get_vessel(vessel_id)
			var records:Array=live.get("native_reaction_records",[])
			if index<records.size():r=records[index]
			if not r.is_empty():
				live_rate.text=NativeProgram.format_number(float(r.reaction_rate))
				condition.text=str(r.condition);heat.text=NativeProgram.format_number(float(r.reaction_heat))
				equilibrium.text=NativeProgram.format_number(float(r.equilibrium_degree_or_constant));mode.text=str(r.equilibrium_mode)
				details.text="反应热：%s  反应条件：%s  平衡常数：%s  平衡方式：%s" % [NativeProgram.format_number(float(r.reaction_heat)),r.condition,NativeProgram.format_number(float(r.equilibrium_degree_or_constant)),r.equilibrium_mode]
				return
		if not r.is_empty():
			rate.text=NativeProgram.format_number(float(r.reaction_rate))
			condition.text=str(r.condition);heat.text=NativeProgram.format_number(float(r.reaction_heat))
			equilibrium.text=NativeProgram.format_number(float(r.equilibrium_degree_or_constant));mode.text=str(r.equilibrium_mode)
			details.text = "反应热：%s  反应条件：%s  平衡常数：%s  平衡方式：%s" % [r.reaction_heat, r.condition, r.equilibrium_degree_or_constant, r.equilibrium_mode]
	)
	equation_list.row_swapped.connect(func(first, second):
		if swap_native_reaction_rows(v, int(first), int(second)):
			refresh_reactions.call()
			if equation_list.item_count > 0: equation_list.select(0); equation_list.item_selected.emit(0)
	)
	refresh_reactions.call()
	var equation_actions := _row(equations)
	_button(equation_actions, "自动搜索", func(): _select_reactions(v, true, refresh_reactions)).name="ReactionSearch"
	_button(equation_actions, "添加", func(): _select_reactions(v, false, refresh_reactions)).name="ReactionAdd"
	_button(equation_actions, "修改", func():
		if not equation_list.get_selected_items().is_empty():
			var index:int=equation_list.get_selected_items()[0]
			var modified:=modify_native_reaction_fields(v,index,[rate.text,condition.text,heat.text,equilibrium.text,mode.text])
			if not modified.ok:details.text=str(modified.error)
	).name = "ReactionApply"
	_button(equation_actions, "删除", func():
		if not equation_list.get_selected_items().is_empty():
			remove_native_reaction_row(v, int(equation_list.get_selected_items()[0]))
			refresh_reactions.call()
	).name = "ReactionDelete"
	_button(equation_actions, "全部删除", func(): v.native_reaction_records.clear(); sync_native_reaction_rows(v); refresh_reactions.call()).name = "ReactionClear"
	_button(equation_actions, "复制方程式", func():
		if not equation_list.get_selected_items().is_empty(): DisplayServer.clipboard_set(equation_list.get_item_text(equation_list.get_selected_items()[0]))
	)
	var settings_scroll := ScrollContainer.new()
	settings_scroll.name = _caption("TFORM4", "TabSheet3", "容器相关设置")
	tabs.add_child(settings_scroll)
	var settings := VBoxContainer.new()
	settings.size_flags_horizontal = Control.SIZE_EXPAND_FILL
	settings_scroll.add_child(settings)
	var name_display:=_label(settings,"容器名称："+str(v.label));name_display.name="NativeApparatusName"
	_label(settings,"容器标签：")
	var label_text:String=str(v.get("native_label_record",{}).get("text",""))
	var label:=TextEdit.new();label.name="NativeLabelMemo";label.text=label_text;label.custom_minimum_size=Vector2(350,90);settings.add_child(label)
	var label_feedback:=_label(settings,"");label_feedback.name="NativeLabelFeedback"
	# NativeEdit9(+388) is hidden in the shipped DFM and commits native+94.
	var hint:=LineEdit.new();hint.name="NativeHint";hint.text=str(v.native_fields.get("0x94",""));hint.visible=false;settings.add_child(hint)
	# Original TFORM4 has no temperature/capacity edits;49F0C8 copies globals.
	# Keep these as information only. Factory/thermal logic owns their values.
	var temperature_display := _label(settings, "温度 (℃)：" + str(v.native_fields.get("0x88", v.temperature)))
	temperature_display.name = "NativeTemperatureValue"
	var volume_display := _label(settings, "容器体积 (mL)：" + str(v.native_fields.get("0x28", v.volume_ml)))
	volume_display.name = "NativeCapacityValue"
	var smart := _check(settings, _caption("TFORM4", "CheckBox1", "智能处理反应"), v.smart)
	var ions := _check(settings, _caption("TFORM4", "CheckBox2", "考虑离子反应"), v.consider_ions)
	var dissolution := _check(settings, "考虑药品的溶解", v.dissolution)
	var native_speed := _spin(settings,"速度调节",float(v.native_rate_slider),1,19,1)
	var scale := _row(settings)
	_label(scale, "反应速度调节：")
	for factor in [10.0, 0.1]:
		_button(scale, "*10" if factor == 10.0 else "*0.1", func():
			for id in v.reaction_ids:
				var r: Dictionary = _reaction_record(v, str(id))
				if not r.is_empty(): set_native_reaction_rate(v, str(id), _stored_product(float(r.reaction_rate), factor))
		)
	# Native4018B0 refreshes live grid cells without firing grid-selection callbacks.
	# Draft/temp Form4 globals and the selected chemical edits remain untouched.
	var live_refresh:Callable=func(apparatus:Array):
		if not is_instance_valid(ui.window) or not model.running or model.paused:return
		var live:Dictionary={}
		for candidate in apparatus:
			if int(candidate.id)==vessel_id:live=candidate;break
		if live.is_empty() or int(live.type_id)<=100 or int(live.type_id)>=300:return
		var rendered:=LiveProperty.rows(live)
		if not rendered.ok:chemical_feedback.text=str(rendered.error);return
		var selected_index:=-1
		var old:TreeItem=contents.get_root().get_first_child() if contents.get_root()!=null else null
		var index:=0
		while old!=null:
			if old==contents.get_selected():selected_index=index
			old=old.get_next();index+=1
		contents.set_block_signals(true);contents.clear()
		var live_root:=contents.create_item()
		for row_index in rendered.rows.size():
			var row:Array=rendered.rows[row_index];var item:=contents.create_item(live_root)
			for column in 3:item.set_text(column,str(row[column]))
			item.set_metadata(0,str(row[0]))
			if row_index==selected_index:item.select(0)
		contents.set_block_signals(false)
		var selected_reaction:=0
		if not equation_list.get_selected_items().is_empty():selected_reaction=equation_list.get_selected_items()[0]
		equation_list.set_block_signals(true);equation_list.clear()
		var records:Array=live.get("native_reaction_records",[])
		for record in records:
			var left:PackedStringArray=[];var right:PackedStringArray=[]
			for term in record.get("reactants",[]):left.append(str(int(term.coefficient))+str(term.species))
			for term in record.get("products",[]):right.append(str(int(term.coefficient))+str(term.species))
			equation_list.add_item(" + ".join(left)+(" == " if not left.is_empty() else "")+" + ".join(right))
			equation_list.set_item_metadata(equation_list.item_count-1,str(record.get("name",record.get("id",""))))
		if not records.is_empty() and selected_reaction<records.size():equation_list.select(selected_reaction)
		equation_list.set_block_signals(false)
		rate.visible=false;live_rate.visible=true
		if records.is_empty():
			live_rate.text="";condition.text="";heat.text="";equilibrium.text="";mode.text=""
			details.text="反应热：  反应条件：  平衡常数：  平衡方式："
		elif selected_reaction<records.size():
			var record:Dictionary=records[selected_reaction]
			live_rate.text=NativeProgram.format_number(float(record.reaction_rate))
			condition.text=str(record.condition);heat.text=NativeProgram.format_number(float(record.reaction_heat))
			equilibrium.text=NativeProgram.format_number(float(record.equilibrium_degree_or_constant));mode.text=str(record.equilibrium_mode)
			details.text="反应热：%s  反应条件：%s  平衡常数：%s  平衡方式：%s" % [NativeProgram.format_number(float(record.reaction_heat)),record.condition,NativeProgram.format_number(float(record.equilibrium_degree_or_constant)),record.equilibrium_mode]
	model.native_property_refresh.connect(live_refresh)
	ui.window.tree_exiting.connect(func():
		if model.native_property_refresh.is_connected(live_refresh):model.native_property_refresh.disconnect(live_refresh)
	)
	var actions := _row(root)
	var manual_refresh:=_button(actions, "刷新", func(): refresh_contents.call(); refresh_reactions.call())
	# The native running refresh is timer-driven; never display the stale draft.
	manual_refresh.disabled=model.running or model.paused
	var action_space := Control.new()
	action_space.size_flags_horizontal = Control.SIZE_EXPAND_FILL
	actions.add_child(action_space)
	_button(actions, "确定", func():
		if label.text!=label_text:
			label_feedback.text="原始标签提交需要已验证的字体测量；当前修改尚未写入。"
			status.emit(label_feedback.text);return
		var parsed_rows:=parse_property_quantity_rows(quantity_rows)
		if not parsed_rows.ok:chemical_feedback.text=str(parsed_rows.error);return
		v.contents=parsed_rows.contents;v.native_editor_mass_rows=parsed_rows.masses
		# Form4 has no apparatus-name input; keep +04 and connector names intact.
		v.label=original.label
		v.hint=hint.text
		v.native_fields["0x94"]=hint.text
		# Preserve exact live binary64 scalars and raw native fields for readonly values.
		var preserved_temperature: float = original.temperature
		var preserved_capacity: float = original.volume_ml
		v.temperature = preserved_temperature
		v.volume_ml = preserved_capacity
		v.smart = smart.button_pressed
		v.consider_ions = ions.button_pressed
		v.native_fields["0x04"] = original.native_fields["0x04"]
		v.native_fields["0x28"] = original.native_fields["0x28"]
		v.native_fields["0x88"] = original.native_fields["0x88"]
		v.native_fields["0xa4"] = "1" if smart.button_pressed else "0"
		v.native_simulation_fields[0] = "1" if ions.button_pressed else "0"
		v.native_simulation_fields[1] = "1" if dissolution.button_pressed else "0"
		v.native_simulation_fields[2] = str(int(native_speed.value))
		if model.get_vessel(vessel_id).is_empty(): status.emit("容器已被删除。"); return
		if host.has_method("cleanup_deleted_chemical_bindings"):
			var cleanup:Dictionary=host.cleanup_deleted_chemical_bindings(original,v)
			if not cleanup.ok:status.emit(str(cleanup.error));return
		sync_native_reaction_rows(v)
		if model.has_method("commit_property_slots") and not model.commit_property_slots(original,v):status.emit(model.last_error);return
		original.merge(v, true)
		model._bind_native(original)
		# _bind_native reparses its string capacity; readonly confirmation must
		# not replace the existing double with another decimal-parser result.
		original.temperature = preserved_temperature
		original.volume_ml = preserved_capacity
		close_property.call(true)
	).name = "PropertiesCommit"
	if model.running or model.paused:
		for node_name in ["PropertiesCommit","ChemicalDefineVariable","ChemicalAdd","ChemicalApply","ChemicalDelete","ChemicalClear","ReactionSearch","ReactionAdd","ReactionApply","ReactionDelete","ReactionClear"]:
			var button:Button=ui.window.find_child(node_name,true,false)
			if button!=null:button.disabled=true
	_button(actions, "关闭", func():close_property.call(false)).name = "PropertiesCancel"

func _define_variable(id: int, species: String) -> void:
	var ui: Dictionary = _window(_caption("TFORM4_SUB_BL", "Form4_sub_bl", "为实验数据定义变量"), Vector2i(540, 400),_property_window)
	_label(ui.root, "药品名称：" + species)
	var name := _line(ui.root, "变量名：", "n_" + str(id))
	var metric := _options(ui.root, ["物质的量 (mol)", "质量 (g)", "温度 (℃)", "pH"])
	_button(ui.root, "确定", func():
		if name.text.strip_edges().is_empty(): return
		variable_defined.emit(name.text.strip_edges(), id, species, ["moles", "mass", "temperature", "ph"][metric.selected])
		status.emit("已定义变量：" + name.text)
		ui.window.queue_free()
	)

func _select_reactions(v: Dictionary, search_only: bool, refresh: Callable) -> void:
	var ui: Dictionary = _window("搜索方程式",Vector2i(730,560),_property_window)
	var query := _line(ui.root, "名称查询")
	var ions := _check(ui.root, "考虑离子反应", v.consider_ions)
	var extended := _check(ui.root, "考虑扩展方程式", false) # Original Form2 DFM default is unchecked.
	var include_products := _check(ui.root, "根据反应物和生成物搜索", false)
	var list := _list(ui.root)
	list.select_mode = ItemList.SELECT_MULTI
	var update: Callable = func():
		list.clear()
		for r in model.reactions:
			if r.equation_type == "离子" and not ions.button_pressed: continue
			if r.equation_type == "扩展" and not extended.button_pressed: continue
			if search_only:
				# Form2 "reactants and products" is AND, not a products fallback.
				var present := NativeReaction.native_names_present({"moles": v.contents}, r.reactants)
				if include_products.button_pressed:
					present = present and NativeReaction.native_names_present({"moles": v.contents}, r.products)
				if not present: continue
			var text: String = _equation_text(r)
			if not query.text.is_empty() and not text.to_lower().contains(query.text.to_lower()): continue
			list.add_item(text)
			list.set_item_metadata(list.item_count - 1, str(r.id))
	query.text_changed.connect(func(_t): update.call())
	for check in [ions, extended, include_products]: check.toggled.connect(func(_v): update.call())
	update.call()
	var actions := _row(ui.root)
	_button(actions, "全选", func(): for i in list.item_count: list.select(i, false))
	_button(actions, "添加", func():
		for index in list.get_selected_items():
			var id: String = str(list.get_item_metadata(index))
			append_native_reaction_row(v, _reaction_record(v, id))
		refresh.call()
		ui.window.queue_free()
	)

func show_reagent_editor() -> void:
	var ui: Dictionary = _window(_caption("TFORM_YP_EDIT", "Form_yp_edit", "药品编辑器"), Vector2i(900, 670))
	var search := _line(ui.root, "名称查询")
	var category := _options(ui.root, ["显示所有药品", "显示所有固体", "显示所有液体", "显示所有气体", "显示所有溶质", "显示所有离子"])
	var split := HSplitContainer.new()
	split.size_flags_vertical = Control.SIZE_EXPAND_FILL
	ui.root.add_child(split)
	var list := _list(split)
	list.custom_minimum_size.x = 300
	var editor := VBoxContainer.new()
	split.add_child(editor)
	var name := _line(editor, "名称：")
	var species := _line(editor, "药品名称：")
	var mass := _spin(editor, "摩尔质量 (g/mol)", 18.0, 0.000001, 1000000.0)
	var charge := _spin(editor, "化合价：", 0.0, -20.0, 20.0, 1.0)
	var phase := _options(editor, ["固体", "液体", "气体", "溶解", "离子", "指示剂"])
	var color := _spin(editor, "颜色 (VCL BGR)", 0.0, 0.0, 16777215.0, 1.0)
	var solubility := _line(editor, "20℃溶解度：", "0")
	var feedback := _label(editor, "选择药品后可修改；新增药品须使用唯一名称。")
	feedback.autowrap_mode = TextServer.AUTOWRAP_WORD_SMART
	var selected: Dictionary = {"species": ""}
	var refresh: Callable = func():
		list.clear()
		var phases: Array = ["", "固体", "液体", "气体", "溶解", "离子"]
		for r in model.reagents:
			if not search.text.is_empty() and not (str(r.name) + str(r.species)).to_lower().contains(search.text.to_lower()): continue
			if category.selected > 0 and str(r.category).strip_edges() != phases[category.selected]: continue
			list.add_item(str(r.name))
			list.set_item_metadata(list.item_count - 1, str(r.species))
	list.item_selected.connect(func(index):
		selected.species = str(list.get_item_metadata(index))
		var r: Dictionary = _species_record(selected.species)
		name.text = str(r.name)
		species.text = str(r.species)
		mass.value = float(r.molar_mass)
		charge.value = float(r.get("charge", 0.0))
		color.value = float(r.color_integer)
		solubility.text = str(r.solubility_at_20_C)
		for i in phase.item_count:
			if phase.get_item_text(i) == str(r.category).strip_edges(): phase.select(i)
	)
	search.text_changed.connect(func(_v): refresh.call())
	category.item_selected.connect(func(_v): refresh.call())
	refresh.call()
	var apply: Callable = func(add: bool):
		var key: String = species.text.strip_edges()
		if key.is_empty() or name.text.strip_edges().is_empty(): feedback.text = "名称不能为空。"; return
		var existing: Dictionary = _species_record(key)
		if (add and not existing.is_empty()) or (not add and key != selected.species): feedback.text = "药品名称须唯一；修改时保留原药品名称以维护实验引用。"; return
		var record: Dictionary = {"id": 0, "name": name.text.strip_edges(), "species": key, "category": phase.get_item_text(phase.selected), "molar_mass": mass.value, "charge": charge.value, "color_integer": int(color.value), "solubility_at_20_C": solubility.text, "raw_fields": []}
		if add:
			for r in model.reagents: record.id = maxi(int(record.id), int(r.id) + 1)
			model.reagents.append(record)
		else:
			var r: Dictionary = _species_record(str(selected.species))
			if r.is_empty(): feedback.text = "请先选择药品。"; return
			for field in record:
				if field != "id" and field != "raw_fields": r[field] = record[field]
		_refresh_catalogs()
		refresh.call()
		feedback.text = "药品库已更新；点击保存写入本机药品库。"
	var buttons := _row(ui.root)
	_button(buttons, "添加", func(): apply.call(true))
	_button(buttons, "修改", func(): apply.call(false))
	_button(buttons, "删除", func():
		var key: String = str(selected.species)
		for v in model.vessels:
			if float(v.contents.get(key, 0.0)) > 1e-12: feedback.text = "此药品仍在容器中，无法删除。"; return
		for r in model.reactions:
			for t in r.reactants + r.products:
				if str(t.species) == key: feedback.text = "方程式引用了此药品，请先修改相关方程式。"; return
		model.reagents = model.reagents.filter(func(r): return str(r.species) != key)
		_refresh_catalogs(); refresh.call()
	)
	_button(buttons, "按字母排序", func(): model.reagents.sort_custom(func(a,b): return str(a.name).naturalnocasecmp_to(str(b.name)) < 0); refresh.call())
	_button(buttons, "保存", func(): feedback.text = "已保存本机药品库。" if save_custom_catalogs() == OK else "保存失败。")
	_button(buttons, "重新加载", func(): feedback.text = "已重新加载本机药品库。" if load_custom_catalogs() == OK else "没有可加载的本机药品库。"; refresh.call())
	_button(buttons, "确定", ui.window.queue_free)

func _terms_text(side: Array) -> String:
	var lines: PackedStringArray = []
	for t in side: lines.append("%s | %s" % [t.species, t.coefficient])
	return "\n".join(lines)

func _parse_terms(text: String) -> Array:
	var result: Array = []
	for line in text.split("\n", false):
		var parts: PackedStringArray = line.split("|")
		if parts.size() != 2 or _species_record(parts[0].strip_edges()).is_empty() or not parts[1].strip_edges().is_valid_float() or float(parts[1]) <= 0.0: return []
		result.append({"species": parts[0].strip_edges(), "coefficient": parts[1].strip_edges()})
	return result

func show_reaction_editor() -> void:
	var ui: Dictionary = _window(_caption("TFORM_FCS_EDIT", "Form_fcs_edit", "方程式编辑器"), Vector2i(1050, 740))
	var query := _line(ui.root, "名称查询")
	var filter := _options(ui.root, ["显示所有方程式", "根据反应物查询", "根据生成物查询", "根据反应物与生成物查询", "显示所有离子反应方程式", "显示所有可逆反应方程式"])
	var split := HSplitContainer.new()
	split.size_flags_vertical = Control.SIZE_EXPAND_FILL
	ui.root.add_child(split)
	var list := _list(split)
	list.custom_minimum_size.x = 460
	var editor := VBoxContainer.new()
	split.add_child(editor)
	var identifier := _line(editor, "方程式名称：")
	_label(editor, "反应物：每行填写 药品名称 | 系数")
	var reactants := TextEdit.new()
	reactants.custom_minimum_size.y = 95
	editor.add_child(reactants)
	_label(editor, "生成物：每行填写 药品名称 | 系数")
	var products := TextEdit.new()
	products.custom_minimum_size.y = 95
	editor.add_child(products)
	var condition := _line(editor, "反应条件：")
	var rate := _spin(editor, "反应速度：", 0.001, 0.0, 100000000.0, 0.000001)
	var heat := _spin(editor, "反应热：", 0.0, -1000000.0, 1000000.0)
	var mode := _options(editor, ["单向", "可逆"])
	var equilibrium := _line(editor, "平衡常数：", "100")
	var type := _options(editor, ["普通", "离子", "扩展"])
	var feedback := _label(editor, "药品名称必须与药品库一致；点击打开药品编辑器可查询名称。")
	feedback.autowrap_mode = TextServer.AUTOWRAP_WORD_SMART
	var selected: Dictionary = {"id": ""}
	var refresh: Callable = func():
		list.clear()
		for r in model.reactions:
			if filter.selected == 4 and r.equation_type != "离子": continue
			if filter.selected == 5 and r.equilibrium_mode != "可逆": continue
			var searchable: String = _equation_text(r)
			if filter.selected == 1: searchable = _terms_text(r.reactants)
			elif filter.selected == 2: searchable = _terms_text(r.products)
			if not query.text.is_empty() and not searchable.to_lower().contains(query.text.to_lower()): continue
			list.add_item(str(r.id) + "  " + _equation_text(r))
			list.set_item_metadata(list.item_count - 1, str(r.id))
	list.item_selected.connect(func(index):
		selected.id = str(list.get_item_metadata(index))
		for r in model.reactions:
			if str(r.id) != selected.id: continue
			identifier.text = str(r.id)
			reactants.text = _terms_text(r.reactants)
			products.text = _terms_text(r.products)
			condition.text = str(r.condition)
			rate.value = float(r.reaction_rate)
			heat.value = float(r.reaction_heat)
			equilibrium.text = str(r.equilibrium_degree_or_constant)
			mode.select(1 if r.equilibrium_mode == "可逆" else 0)
			type.select(["普通", "离子", "扩展"].find(r.equation_type))
	)
	query.text_changed.connect(func(_v): refresh.call())
	filter.item_selected.connect(func(_v): refresh.call())
	refresh.call()
	var apply: Callable = func(add: bool):
		var id: String = identifier.text.strip_edges()
		var left: Array = _parse_terms(reactants.text)
		var right: Array = _parse_terms(products.text)
		if id.is_empty() or left.is_empty() or right.is_empty() or not equilibrium.text.is_valid_float() or float(equilibrium.text) <= 0.0: feedback.text = "请填写有效方程式名称、库中药品、正系数和平衡常数。"; return
		for r in model.reactions:
			if add and str(r.id) == id: feedback.text = "方程式名称已存在。"; return
		if not add and id != selected.id: feedback.text = "修改时保留方程式名称以维护实验引用。"; return
		var r: Dictionary = {"id": id, "reactant_count": left.size(), "product_count": right.size(), "reactants": left, "products": right, "condition": condition.text, "reaction_rate": str(rate.value), "reaction_heat": str(heat.value), "equilibrium_degree_or_constant": equilibrium.text, "equilibrium_mode": mode.get_item_text(mode.selected), "equation_type": type.get_item_text(type.selected), "optional_note_lines": []}
		if add: model.reactions.append(r)
		else:
			for i in model.reactions.size():
				if str(model.reactions[i].id) == id: model.reactions[i] = r
		_refresh_catalogs(); refresh.call()
		feedback.text = "方程式库已更新；点击保存写入本机方程式库。"
	var actions := _row(ui.root)
	_button(actions, "添加", func(): apply.call(true))
	_button(actions, "修改", func(): apply.call(false))
	_button(actions, "删除", func():
		model.reactions = model.reactions.filter(func(r): return str(r.id) != str(selected.id))
		for v in model.vessels: v.reaction_ids.erase(str(selected.id)); v.rate_overrides.erase(str(selected.id))
		_refresh_catalogs(); refresh.call()
	)
	_button(actions, "按字母排序", func(): model.reactions.sort_custom(func(a,b): return str(a.id).naturalnocasecmp_to(str(b.id)) < 0); refresh.call())
	_button(actions, "打开药品编辑器", show_reagent_editor)
	_button(actions, "保存", func(): feedback.text = "已保存本机方程式库。" if save_custom_catalogs() == OK else "保存失败。")
	_button(actions, "重新加载", func(): feedback.text = "已重新加载本机方程式库。" if load_custom_catalogs() == OK else "没有可加载的本机方程式库。"; refresh.call())
	_button(actions, "确定", ui.window.queue_free)

func save_custom_catalogs() -> Error:
	var file := FileAccess.open("user://catalogs.json", FileAccess.WRITE)
	if file == null: return FileAccess.get_open_error()
	file.store_string(JSON.stringify({"format": "ChemLab-Godot-Catalogs", "version": 1, "reagents": model.reagents, "reactions": model.reactions}, "\t"))
	return OK

func load_custom_catalogs() -> Error:
	if not FileAccess.file_exists("user://catalogs.json"): return ERR_FILE_NOT_FOUND
	var data = JSON.parse_string(FileAccess.get_file_as_string("user://catalogs.json"))
	if not data is Dictionary or data.get("format", "") != "ChemLab-Godot-Catalogs" or not data.get("reagents", null) is Array or not data.get("reactions", null) is Array: return ERR_INVALID_DATA
	var known: Dictionary = {}
	for r in data.reagents:
		if not r is Dictionary or not r.get("species", null) is String or not r.has("name") or not r.has("category") or not r.has("id") or not r.has("color_integer") or not r.has("solubility_at_20_C"): return ERR_INVALID_DATA
		if known.has(r.species) or float(r.get("molar_mass", 0.0)) <= 0.0: return ERR_INVALID_DATA
		known[r.species] = true
	var equation_ids: Dictionary = {}
	for r in data.reactions:
		if not r is Dictionary or not r.has("id") or not r.get("reactants", null) is Array or not r.get("products", null) is Array: return ERR_INVALID_DATA
		if equation_ids.has(str(r.id)): return ERR_INVALID_DATA
		equation_ids[str(r.id)] = true
		for key in ["condition", "reaction_rate", "reaction_heat", "equilibrium_mode", "equilibrium_degree_or_constant", "equation_type"]:
			if not r.has(key): return ERR_INVALID_DATA
		for t in r.reactants + r.products:
			if not t is Dictionary or not known.has(str(t.get("species", ""))) or float(t.get("coefficient", 0.0)) <= 0.0: return ERR_INVALID_DATA
	model.configure(data.reagents, data.reactions)
	catalogs_changed.emit()
	model.changed.emit()
	return OK
