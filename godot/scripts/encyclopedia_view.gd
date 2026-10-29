class_name EncyclopediaView
extends Control
## Native reader for all recovered encyclopedia database records.
signal request_status(message: String)

const FIELD_LABELS := {"chemname": "名称", "mf": "化学式", "popularname": "别名",
	"describe1": "性质与介绍", "chemicname": "姓名", "flname": "外文姓名", "nationality": "国籍",
	"alllife": "生平", "conceptname": "概念", "conceptcontent": "内容", "elenum": "原子序数",
	"finder": "发现者", "findtime": "发现时间", "howtofind": "发现过程", "nameby": "命名",
	"source": "来源与制备", "use": "用途", "excontent": "相关资料", "elesymbol": "元素符号",
	"eletitle": "中文名称", "elewt": "相对原子质量", "eletype": "类别", "eleename": "英文名称",
	"elefengdu": "丰度（原数据库数值）", "elemeltingp": "熔点（原数据库数值）",
	"eleboilingp": "沸点（原数据库数值）", "id": "编号", "idname": "索引名称",
	"idvalue": "索引值", "resid": "资源编号", "parentid": "上级编号", "titlename": "标题",
	"resinfo": "资源内容", "restype": "类型"}
var tables: Array = []
var entries: Array[Dictionary] = []
var filtered_entries: Array[Dictionary] = []
var current_entry: Dictionary = {}
var periodic_buttons: Dictionary = {}
var last_error := ""
var _source_tables: Array = []
var _category := ""
var _search: LineEdit
var _tree: Tree
var _article: RichTextLabel
var _title: Label
var _count: Label
var _pages: TabContainer
var _periodic_grid: GridContainer
var _export_dialog: FileDialog
var _element_records: Dictionary = {}
var _element_info: Dictionary = {}
var _edit_dialog: ConfirmationDialog
var _delete_dialog: ConfirmationDialog
var _edit_fields: Dictionary = {}
var _edit_table_index := -1
var _edit_record_index := -1
var _edit_error: Label
var _delete_target: Dictionary = {}

func _ready() -> void:
	if tables.is_empty() and FileAccess.file_exists("res://data/encyclopedia.json"):
		var parsed: Variant = JSON.parse_string(FileAccess.get_file_as_string("res://data/encyclopedia.json"))
		if parsed is Array:
			tables = parsed
	_source_tables = tables.duplicate(true)
	if not "--testing" in OS.get_cmdline_user_args() and FileAccess.file_exists("user://encyclopedia.json"):
		load_catalog("user://encyclopedia.json")
	_index_tables()
	_build_ui()
	refresh_search("")
	if not entries.is_empty():
		open_record(int(entries[0]["table_index"]), int(entries[0]["record_index"]))

func set_tables(data: Array) -> void:
	tables = data.duplicate(true)
	_source_tables = data.duplicate(true)
	current_entry = {}
	_index_tables()
	if is_node_ready():
		refresh_search(_search.text)
		_build_periodic_table()

func _index_tables() -> void:
	entries.clear()
	_element_records.clear()
	_element_info.clear()
	for table_index in range(tables.size()):
		var table: Dictionary = tables[table_index]
		var records: Array = table.get("records", [])
		for record_index in range(records.size()):
			var record: Dictionary = records[record_index]
			var search_parts := PackedStringArray()
			for value in record.values():
				search_parts.append(str(value))
			var entry := {"table_index": table_index, "record_index": record_index,
				"table": str(table.get("name", "")), "title": record_title(str(table.get("name", "")), record),
				"search": "\n".join(search_parts).to_lower()}
			entries.append(entry)
			if table.get("name") == "elements":
				_element_records[int(str(record.get("elenum", "0")))] = entry
			elif table.get("name") == "eleinfo":
				_element_info[int(str(record.get("elenum", "0")))] = entry

func record_title(table_name: String, record: Dictionary) -> String:
	match table_name:
		"chemicals": return str(record.get("chemname", "物质"))
		"chemics": return str(record.get("chemicname", "化学家"))
		"concepts": return str(record.get("conceptname", "概念"))
		"elements": return "%s  %s %s" % [record.get("elenum", ""), record.get("elesymbol", ""), record.get("eletitle", "")]
		"eleinfo": return "元素 %s · 详细资料" % record.get("elenum", "")
		"resdiy": return str(record.get("titlename", "自定义资源"))
		"idlib": return str(record.get("idname", "索引"))
	return str(record.values()[0]) if not record.is_empty() else "（空记录）"

func _build_ui() -> void:
	var layout := VBoxContainer.new()
	layout.set_anchors_and_offsets_preset(Control.PRESET_FULL_RECT)
	layout.add_theme_constant_override("separation", 6)
	add_child(layout)
	var toolbar := HBoxContainer.new()
	layout.add_child(toolbar)
	for item in [["全部资料", ""], ["元素周期表", "elements"], ["化学药品", "chemicals"], ["概念常识", "concepts"], ["化学家", "chemics"], ["用户DIY", "resdiy"]]:
		var button := Button.new()
		button.text = item[0]
		button.pressed.connect(select_category.bind(item[1]))
		toolbar.add_child(button)
	var edit_toolbar := HBoxContainer.new()
	layout.add_child(edit_toolbar)
	for item in [["编辑资料", "edit"], ["新增资料", "new"], ["删除资料", "delete"], ["保存资料库", "save"]]:
		var button := Button.new()
		button.text = item[0]
		button.pressed.connect(_edit_action.bind(item[1]))
		edit_toolbar.add_child(button)
	var search_row := HBoxContainer.new()
	layout.add_child(search_row)
	var search_label := Label.new()
	search_label.text = "检索："
	search_row.add_child(search_label)
	_search = LineEdit.new()
	_search.placeholder_text = "输入名称、化学式或正文关键字"
	_search.size_flags_horizontal = Control.SIZE_EXPAND_FILL
	_search.text_changed.connect(refresh_search)
	search_row.add_child(_search)
	var clear_button := Button.new()
	clear_button.text = "清除"
	clear_button.pressed.connect(func(): _search.text = ""; refresh_search(""))
	search_row.add_child(clear_button)
	_count = Label.new()
	search_row.add_child(_count)
	var split := HSplitContainer.new()
	split.size_flags_vertical = Control.SIZE_EXPAND_FILL
	split.split_offset = 235
	layout.add_child(split)
	_tree = Tree.new()
	_tree.custom_minimum_size.x = 190
	_tree.hide_root = true
	_tree.item_selected.connect(_on_tree_selected)
	split.add_child(_tree)
	_pages = TabContainer.new()
	_pages.size_flags_horizontal = Control.SIZE_EXPAND_FILL
	split.add_child(_pages)
	var reading := VBoxContainer.new()
	reading.name = "资料内容"
	_pages.add_child(reading)
	var action_row := HBoxContainer.new()
	reading.add_child(action_row)
	for item in [["上一条", -1], ["下一条", 1]]:
		var button := Button.new()
		button.text = item[0]
		button.pressed.connect(_navigate.bind(item[1]))
		action_row.add_child(button)
	var copy_button := Button.new()
	copy_button.text = "复制资料"
	copy_button.pressed.connect(func(): DisplayServer.clipboard_set(get_current_article()))
	action_row.add_child(copy_button)
	var export_button := Button.new()
	export_button.text = "导出资料"
	export_button.pressed.connect(func(): _export_dialog.popup_centered_ratio(0.7))
	action_row.add_child(export_button)
	_title = Label.new()
	_title.add_theme_font_size_override("font_size", 22)
	_title.autowrap_mode = TextServer.AUTOWRAP_WORD_SMART
	reading.add_child(_title)
	_article = RichTextLabel.new()
	_article.size_flags_vertical = Control.SIZE_EXPAND_FILL
	_article.selection_enabled = true
	_article.add_theme_font_size_override("normal_font_size", 17)
	_article.add_theme_constant_override("line_separation", 5)
	reading.add_child(_article)
	var periodic_scroll := ScrollContainer.new()
	periodic_scroll.name = "元素周期表"
	_pages.add_child(periodic_scroll)
	var periodic_column := VBoxContainer.new()
	periodic_scroll.add_child(periodic_column)
	var note := Label.new()
	note.text = "点击元素查看资料。保留原数据库的 112 个元素及历史名称。"
	periodic_column.add_child(note)
	_periodic_grid = GridContainer.new()
	_periodic_grid.columns = 19
	_periodic_grid.add_theme_constant_override("h_separation", 2)
	_periodic_grid.add_theme_constant_override("v_separation", 2)
	periodic_column.add_child(_periodic_grid)
	_export_dialog = FileDialog.new()
	_export_dialog.file_mode = FileDialog.FILE_MODE_SAVE_FILE
	_export_dialog.access = FileDialog.ACCESS_FILESYSTEM
	_export_dialog.filters = PackedStringArray(["*.txt ; 文本资料"])
	_export_dialog.current_file = "化学资料.txt"
	_export_dialog.file_selected.connect(_export_article)
	add_child(_export_dialog)
	_edit_dialog = ConfirmationDialog.new()
	_edit_dialog.dialog_hide_on_ok = false
	_edit_dialog.ok_button_text = "确定"
	_edit_dialog.cancel_button_text = "取消"
	_edit_dialog.confirmed.connect(_confirm_edit)
	add_child(_edit_dialog)
	_delete_dialog = ConfirmationDialog.new()
	_delete_dialog.title = "删除资料"
	_delete_dialog.dialog_text = "确定删除这条资料？保存资料库后此更改会保留。"
	_delete_dialog.confirmed.connect(func():
		if not _delete_target.is_empty():
			delete_record(int(_delete_target["table_index"]), int(_delete_target["record_index"]))
	)
	add_child(_delete_dialog)
	_build_periodic_table()

func _fail(message: String) -> bool:
	last_error = message
	request_status.emit(message)
	return false

func validate_catalog(data: Array) -> bool:
	if data.size() != _source_tables.size():
		return _fail("资料库的表数量与原数据库不一致")
	for table_index in range(data.size()):
		if not data[table_index] is Dictionary:
			return _fail("资料表格式错误")
		var table: Dictionary = data[table_index]
		var original: Dictionary = _source_tables[table_index]
		if table.get("name") != original.get("name") or table.get("columns") != original.get("columns") or not table.get("records", null) is Array:
			return _fail("资料表名称或字段结构与原数据库不一致")
		var primary := _primary_field(str(table["name"]))
		var seen: Dictionary = {}
		for record in table["records"]:
			if not record is Dictionary or record.size() != table["columns"].size():
				return _fail("资料字段数量错误")
			for column in table["columns"]:
				if not record.has(column) or not record[column] is String:
					return _fail("资料字段必须是文本：" + str(column))
			var key := str(record.get(primary, "")).strip_edges()
			if key.is_empty() or seen.has(key):
				return _fail("名称或编号不能为空，也不能重复：" + key)
			seen[key] = true
			if str(table["name"]) in ["elements", "eleinfo"]:
				if not key.is_valid_int() or int(key) < 1 or int(key) > 112 or key != str(int(key)):
					return _fail("元素原子序数必须在原数据库的 1–112 范围内")
		if table["name"] == "elements":
			if table["records"].size() != 112:
				return _fail("必须保留原周期表的 112 个元素")
			for number in range(1, 113):
				if not seen.has(str(number)):
					return _fail("周期表缺少元素：" + str(number))
	last_error = ""
	return true

func _primary_field(table_name: String) -> String:
	return str({"chemicals": "chemname", "chemics": "chemicname", "concepts": "conceptname", "elements": "elenum", "eleinfo": "elenum", "idlib": "idname", "resdiy": "resid"}.get(table_name, ""))

func _commit_catalog(candidate: Array) -> bool:
	if not validate_catalog(candidate):
		return false
	tables = candidate
	current_entry = {}
	_index_tables()
	if _tree:
		refresh_search(_search.text)
		_build_periodic_table()
		_title.text = "资料库已更新"
		_article.text = "请选择左侧资料。点击“保存资料库”保留此次修改。"
	return true

func create_record(table_index: int, record: Dictionary) -> bool:
	if table_index < 0 or table_index >= tables.size():
		return _fail("资料表不存在")
	if tables[table_index].get("name") == "elements":
		return _fail("原元素周期表固定为 112 个元素；可编辑已有元素资料")
	var candidate := tables.duplicate(true)
	candidate[table_index]["records"].append(record.duplicate(true))
	if not _commit_catalog(candidate):
		return false
	open_record(table_index, tables[table_index]["records"].size() - 1)
	return true

func update_record(table_index: int, record_index: int, record: Dictionary) -> bool:
	if table_index < 0 or table_index >= tables.size() or record_index < 0 or record_index >= tables[table_index]["records"].size():
		return _fail("资料记录不存在")
	var candidate := tables.duplicate(true)
	candidate[table_index]["records"][record_index] = record.duplicate(true)
	if not _commit_catalog(candidate):
		return false
	open_record(table_index, record_index)
	return true

func delete_record(table_index: int, record_index: int) -> bool:
	if table_index < 0 or table_index >= tables.size() or record_index < 0 or record_index >= tables[table_index]["records"].size():
		return _fail("资料记录不存在")
	if tables[table_index].get("name") == "elements":
		return _fail("周期表元素不能删除；可删除或修改其详细资料")
	var candidate := tables.duplicate(true)
	candidate[table_index]["records"].remove_at(record_index)
	return _commit_catalog(candidate)

func save_catalog(path: String = "user://encyclopedia.json") -> bool:
	if path.begins_with("res://"):
		return _fail("原资料库保留不变；请保存到用户资料目录")
	if not validate_catalog(tables):
		return false
	var file := FileAccess.open(path, FileAccess.WRITE)
	if not file:
		return _fail("无法保存资料库：" + error_string(FileAccess.get_open_error()))
	file.store_string(JSON.stringify(tables, "\t"))
	request_status.emit("资料库已保存：" + path)
	return true

func load_catalog(path: String = "user://encyclopedia.json") -> bool:
	var file := FileAccess.open(path, FileAccess.READ)
	if not file:
		return _fail("无法读取资料库：" + error_string(FileAccess.get_open_error()))
	var parser := JSON.new()
	if parser.parse(file.get_as_text()) != OK or not parser.data is Array:
		return _fail("资料库 JSON 格式错误")
	return _commit_catalog(parser.data)

func _edit_action(action: String) -> void:
	if action == "save":
		save_catalog()
		return
	if action == "delete":
		if current_entry.is_empty():
			_fail("请先选择资料")
			return
		if tables[current_entry["table_index"]].get("name") == "elements":
			_fail("周期表元素不能删除；可编辑元素属性")
			return
		_delete_target = current_entry.duplicate()
		_delete_dialog.popup_centered()
		return
	if action == "edit" and current_entry.is_empty():
		_fail("请先选择资料")
		return
	_edit_record_index = -1 if action == "new" else int(current_entry["record_index"])
	_edit_table_index = int(current_entry.get("table_index", -1))
	if action == "new":
		for i in range(tables.size()):
			if tables[i].get("name") == (_category if not _category.is_empty() else "resdiy"):
				_edit_table_index = i
				break
	if _edit_table_index < 0 or (_edit_record_index < 0 and tables[_edit_table_index].get("name") == "elements"):
		_fail("请选择可新增的类别；元素周期表只允许编辑已有元素")
		return
	for child in _edit_dialog.get_children():
		if child.has_meta("editor_body"):
			child.free()
	_edit_fields.clear()
	var body := VBoxContainer.new()
	body.set_meta("editor_body", true)
	_edit_dialog.add_child(body)
	_edit_error = Label.new()
	_edit_error.autowrap_mode = TextServer.AUTOWRAP_WORD_SMART
	_edit_error.modulate = Color.DARK_RED
	body.add_child(_edit_error)
	var scroll := ScrollContainer.new()
	scroll.custom_minimum_size = Vector2(570, 440)
	scroll.size_flags_vertical = Control.SIZE_EXPAND_FILL
	body.add_child(scroll)
	var fields := VBoxContainer.new()
	fields.size_flags_horizontal = Control.SIZE_EXPAND_FILL
	scroll.add_child(fields)
	var table: Dictionary = tables[_edit_table_index]
	var record: Dictionary = table["records"][_edit_record_index] if _edit_record_index >= 0 else {}
	for column in table["columns"]:
		var label := Label.new()
		label.text = str(FIELD_LABELS.get(column, column))
		fields.add_child(label)
		var input := TextEdit.new()
		input.text = str(record.get(column, ""))
		input.custom_minimum_size.y = 140 if column in ["describe1", "alllife", "conceptcontent", "howtofind", "source", "use", "excontent", "resinfo"] else 40
		input.wrap_mode = TextEdit.LINE_WRAPPING_BOUNDARY
		fields.add_child(input)
		_edit_fields[column] = input
	if _edit_record_index < 0 and table.get("name") == "resdiy":
		var next_id := 1
		for resource in table["records"]:
			if str(resource.get("resid", "")).is_valid_int():
				next_id = maxi(next_id, int(resource["resid"]) + 1)
		_edit_fields["resid"].text = "%08d" % next_id
		_edit_fields["parentid"].text = "00000000"
		_edit_fields["restype"].text = "1"
	_edit_dialog.title = ("编辑" if _edit_record_index >= 0 else "新增") + str(table.get("title", "资料"))
	_edit_dialog.popup_centered(Vector2i(650, 560))

func _confirm_edit() -> void:
	var record: Dictionary = {}
	for column in _edit_fields:
		record[column] = _edit_fields[column].text
	var success := update_record(_edit_table_index, _edit_record_index, record) if _edit_record_index >= 0 else create_record(_edit_table_index, record)
	if success:
		_edit_dialog.hide()
		request_status.emit("资料已修改，点击“保存资料库”保留更改")
	else:
		_edit_error.text = last_error

func select_category(category: String) -> void:
	_category = category
	refresh_search(_search.text)
	if category == "elements":
		_pages.current_tab = 1
	else:
		_pages.current_tab = 0
		if not filtered_entries.is_empty():
			var entry: Dictionary = filtered_entries[0]
			open_record(int(entry["table_index"]), int(entry["record_index"]))

func search_records(query: String, category: String = "") -> Array[Dictionary]:
	var results: Array[Dictionary] = []
	var key := query.strip_edges().to_lower()
	for entry in entries:
		if (category.is_empty() or entry["table"] == category) and (key.is_empty() or str(entry["search"]).contains(key)):
			results.append(entry)
	return results

func refresh_search(query: String) -> void:
	filtered_entries = search_records(query, _category)
	if not _tree:
		return
	_tree.clear()
	var root := _tree.create_item()
	var categories: Dictionary = {}
	for entry in filtered_entries:
		var table_index := int(entry["table_index"])
		if not categories.has(table_index):
			var category_item := _tree.create_item(root)
			category_item.set_text(0, str(tables[table_index].get("title", entry["table"])))
			category_item.set_selectable(0, false)
			categories[table_index] = category_item
		var item := _tree.create_item(categories[table_index])
		item.set_text(0, entry["title"])
		item.set_metadata(0, entry)
	_count.text = "%d 条" % filtered_entries.size()
	request_status.emit("百科检索：%d / %d 条资料" % [filtered_entries.size(), entries.size()])

func _on_tree_selected() -> void:
	var item := _tree.get_selected()
	if item and item.get_metadata(0) is Dictionary:
		var entry: Dictionary = item.get_metadata(0)
		open_record(int(entry["table_index"]), int(entry["record_index"]))

func open_record(table_index: int, record_index: int) -> bool:
	if table_index < 0 or table_index >= tables.size():
		return false
	var records: Array = tables[table_index].get("records", [])
	if record_index < 0 or record_index >= records.size():
		return false
	current_entry = {"table_index": table_index, "record_index": record_index}
	if _article:
		_title.text = record_title(str(tables[table_index].get("name", "")), records[record_index])
		_article.text = article_text(table_index, record_index)
		_article.scroll_to_line(0)
		_pages.current_tab = 0
	request_status.emit("百科：" + record_title(str(tables[table_index].get("name", "")), records[record_index]))
	return true

func article_text(table_index: int, record_index: int) -> String:
	if table_index < 0 or table_index >= tables.size():
		return ""
	var table: Dictionary = tables[table_index]
	var records: Array = table.get("records", [])
	if record_index < 0 or record_index >= records.size():
		return ""
	var record: Dictionary = records[record_index]
	var sections := PackedStringArray()
	for column in table.get("columns", record.keys()):
		var value := str(record.get(column, "")).strip_edges()
		if not value.is_empty():
			sections.append("%s\n%s" % [FIELD_LABELS.get(column, column), value])
	if table.get("name") == "elements":
		var number := int(str(record.get("elenum", "0")))
		if _element_info.has(number):
			var detail: Dictionary = _element_info[number]
			sections.append("详细资料\n" + article_text(int(detail["table_index"]), int(detail["record_index"])))
	return "\n\n".join(sections)

func get_current_article() -> String:
	if current_entry.is_empty():
		return ""
	var table_index := int(current_entry["table_index"])
	var record_index := int(current_entry["record_index"])
	return record_title(str(tables[table_index].get("name", "")), tables[table_index]["records"][record_index]) + "\n\n" + article_text(table_index, record_index)

func _navigate(direction: int) -> void:
	if filtered_entries.is_empty():
		return
	var index := -1
	for i in range(filtered_entries.size()):
		if filtered_entries[i]["table_index"] == current_entry.get("table_index", -1) and filtered_entries[i]["record_index"] == current_entry.get("record_index", -1):
			index = i
			break
	index = posmod(index + direction, filtered_entries.size()) if index >= 0 else (0 if direction > 0 else filtered_entries.size() - 1)
	var entry: Dictionary = filtered_entries[index]
	open_record(int(entry["table_index"]), int(entry["record_index"]))

func _export_article(path: String) -> void:
	var file := FileAccess.open(path, FileAccess.WRITE)
	if file:
		file.store_string(get_current_article())
		request_status.emit("资料已保存：" + path)
	else:
		request_status.emit("无法保存资料：" + error_string(FileAccess.get_open_error()))

func periodic_position(number: int) -> Vector2i:
	## Grid coordinates: group 1..18, period 1..7; f blocks in rows 9/10.
	if number == 1: return Vector2i(1, 1)
	if number == 2: return Vector2i(18, 1)
	if number >= 3 and number <= 10:
		return Vector2i(number - 2 if number <= 4 else number + 8, 2)
	if number >= 11 and number <= 18:
		return Vector2i(number - 10 if number <= 12 else number, 3)
	if number >= 19 and number <= 36: return Vector2i(number - 18, 4)
	if number >= 37 and number <= 54: return Vector2i(number - 36, 5)
	if number >= 55 and number <= 56: return Vector2i(number - 54, 6)
	if number >= 57 and number <= 71: return Vector2i(number - 54, 9)
	if number >= 72 and number <= 86: return Vector2i(number - 68, 6)
	if number >= 87 and number <= 88: return Vector2i(number - 86, 7)
	if number >= 89 and number <= 103: return Vector2i(number - 86, 10)
	if number >= 104 and number <= 118: return Vector2i(number - 100, 7)
	return Vector2i(-1, -1)

func _build_periodic_table() -> void:
	if not _periodic_grid:
		return
	for child in _periodic_grid.get_children():
		child.free()
	periodic_buttons.clear()
	var positions: Dictionary = {}
	for number in _element_records:
		positions[periodic_position(number)] = number
	for row in range(11):
		for column in range(19):
			var cell := Vector2i(column, row)
			if positions.has(cell):
				var number: int = positions[cell]
				var entry: Dictionary = _element_records[number]
				var record: Dictionary = tables[entry["table_index"]]["records"][entry["record_index"]]
				var button := Button.new()
				button.text = "%d\n%s\n%s" % [number, record.get("elesymbol", ""), record.get("eletitle", "")]
				button.custom_minimum_size = Vector2(50, 66)
				button.tooltip_text = record_title("elements", record)
				button.pressed.connect(open_record.bind(int(entry["table_index"]), int(entry["record_index"])))
				_periodic_grid.add_child(button)
				periodic_buttons[number] = button
			else:
				var label := Label.new()
				label.horizontal_alignment = HORIZONTAL_ALIGNMENT_CENTER
				label.custom_minimum_size = Vector2(50, 24)
				if row == 0 and column > 0:
					label.text = str(column)
				elif column == 0 and row > 0 and row < 8:
					label.text = str(row)
				elif cell == Vector2i(3, 6):
					label.text = "57–71"
				elif cell == Vector2i(3, 7):
					label.text = "89–103"
				elif cell == Vector2i(1, 9):
					label.text = "镧系"
				elif cell == Vector2i(1, 10):
					label.text = "锕系"
				_periodic_grid.add_child(label)
