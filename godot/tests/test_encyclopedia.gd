extends SceneTree
const Encyclopedia = preload("res://scripts/encyclopedia_view.gd")

func _initialize() -> void:
	call_deferred("_run")

func _run() -> void:
	var viewer = Encyclopedia.new()
	viewer.size = Vector2(1100, 700)
	root.add_child(viewer)
	await process_frame
	# Tests always use the packaged baseline; do not overwrite any saved user catalog.
	viewer.set_tables(JSON.parse_string(FileAccess.get_file_as_string("res://data/encyclopedia.json")))
	assert(viewer.tables.size() == 7)
	assert(viewer.entries.size() == 475, "All recovered database records must remain accessible")
	assert(viewer.search_records("").size() == 475)
	assert(viewer.search_records("", "elements").size() == 112)
	assert(viewer.search_records("", "chemicals").size() == 83)
	assert(viewer.search_records("", "concepts").size() == 153)
	assert(viewer.search_records("", "chemics").size() == 22)
	assert(viewer.search_records("饱和溶液").size() > 0, "Unicode names must be searchable")
	assert(viewer.search_records("Svante").size() == viewer.search_records("svante").size(), "Latin search is case insensitive")
	assert(viewer.search_records("CH3COONa").size() > 0, "Chemical formulas must be searchable")
	assert(viewer.search_records("@@no-such-encyclopedia-record@@").is_empty())
	for entry in viewer.entries:
		assert(viewer.open_record(entry["table_index"], entry["record_index"]))
		assert(not viewer.get_current_article().is_empty(), "Every recovered record must be readable")
		var table: Dictionary = viewer.tables[entry["table_index"]]
		var record: Dictionary = table["records"][entry["record_index"]]
		for column in table["columns"]:
			var value := str(record.get(column, "")).strip_edges()
			if not value.is_empty():
				assert(viewer.get_current_article().contains(value), "Reader must not omit or truncate nonempty fields")
	assert(not viewer.open_record(-1, 0))
	assert(not viewer.open_record(0, 10000))
	assert(viewer.periodic_buttons.size() == 112)
	assert(viewer.periodic_position(1) == Vector2i(1, 1))
	assert(viewer.periodic_position(2) == Vector2i(18, 1))
	assert(viewer.periodic_position(8) == Vector2i(16, 2))
	assert(viewer.periodic_position(26) == Vector2i(8, 4))
	assert(viewer.periodic_position(57) == Vector2i(3, 9))
	assert(viewer.periodic_position(71) == Vector2i(17, 9))
	assert(viewer.periodic_position(92) == Vector2i(6, 10))
	assert(viewer.periodic_position(112) == Vector2i(12, 7))
	var occupied: Dictionary = {}
	for number in range(1, 113):
		var position: Vector2i = viewer.periodic_position(number)
		assert(not occupied.has(position), "Periodic grid must not overlap elements")
		occupied[position] = number
	viewer.periodic_buttons[1].pressed.emit()
	assert(viewer.get_current_article().contains("卡文迪许"), "Periodic cell links to joined detailed element history")
	viewer.refresh_search("饱和溶液")
	assert(viewer.filtered_entries.size() > 0)
	viewer._navigate(1)
	assert(not viewer.current_entry.is_empty())
	var baseline: Array = viewer.tables.duplicate(true)
	assert(viewer.validate_catalog(baseline))
	var concepts_index := -1
	var diy_index := -1
	var elements_index := -1
	for i in range(viewer.tables.size()):
		match viewer.tables[i]["name"]:
			"concepts": concepts_index = i
			"resdiy": diy_index = i
			"elements": elements_index = i
	var concept := {"conceptname": "测试新增概念", "conceptcontent": "新增与检索：保留 Unicode 正文。"}
	assert(viewer.create_record(concepts_index, concept))
	assert(viewer.entries.size() == 476)
	assert(viewer.search_records("保留 Unicode 正文").size() == 1)
	assert(not viewer.create_record(concepts_index, concept), "Duplicate primary names must be rejected")
	assert(not viewer.create_record(concepts_index, {"conceptname": "不完整"}), "Incomplete column schemas must be rejected")
	assert(viewer.entries.size() == 476, "Rejected edits cannot mutate the catalog")
	var row: int = viewer.tables[concepts_index]["records"].size() - 1
	concept["conceptcontent"] = "修改后的内容"
	assert(viewer.update_record(concepts_index, row, concept))
	assert(viewer.get_current_article().contains("修改后的内容"))
	var diy := {"resid": "00000001", "parentid": "00000000", "titlename": "用户实验笔记", "resinfo": "这是用户自定义的资料。", "restype": "1"}
	assert(viewer.create_record(diy_index, diy))
	assert(viewer.entries.size() == 477)
	assert(not viewer.delete_record(elements_index, 0), "The original periodic table must retain all elements")
	assert(not viewer.save_catalog("res://data/encyclopedia.json"), "Packaged source must not be overwritten")
	var temporary_path := ProjectSettings.globalize_path("user://encyclopedia-crud-%d.json" % OS.get_process_id())
	assert(viewer.save_catalog(temporary_path))
	viewer.set_tables(baseline)
	assert(viewer.entries.size() == 475)
	assert(viewer.load_catalog(temporary_path))
	assert(viewer.entries.size() == 477 and viewer.search_records("用户实验笔记").size() == 1)
	assert(viewer.delete_record(concepts_index, row))
	assert(viewer.entries.size() == 476)
	assert(viewer.periodic_buttons.size() == 112)
	assert(DirAccess.remove_absolute(temporary_path) == OK)
	viewer.free()
	print("PASS encyclopedia: all 475 records/fields, Unicode/full-text search, 112 periodic elements, element-detail joins, navigation, validated CRUD, rejected duplicate/schema edits, temporary-file persistence roundtrip, packaged source protection")
	quit()
