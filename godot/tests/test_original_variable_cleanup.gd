extends SceneTree
const Cleanup = preload("res://scripts/original/original_variable_cleanup.gd")
var failures := 0
func check(condition: bool, message: String) -> void:
	if not condition:
		failures += 1
		push_error(message)
func table_fixture() -> Dictionary:
	var rows: Array = []
	for row_index in range(300):
		var row: Array = []
		for field in range(17): row.append(row_index * 100 + field)
		row[13] = "v" + str(row_index)
		rows.append(row)
	return {"count": 4, "rows": rows}
func _initialize() -> void:
	var table := table_fixture()
	check(Cleanup.find_name(table, "v2").index == 2, "Exact native variable-name lookup differs")
	check(Cleanup.find_name(table, "V2").index == -1, "Native variable-name lookup lost case sensitivity")
	var last: Array = table.rows[299].duplicate()
	var saved: Array = table.rows[2].duplicate()
	check(Cleanup.remove_name(table, "v1").removed, "Native variable deletion failed")
	check(table.count == 3 and table.rows[1] == saved, "Native deletion did not shift the full17-field record")
	check(table.rows[298] == last and table.rows[299] == last, "Native deletion changed the uncleared physical tail semantics")
	table = table_fixture()
	table.rows[1][13] = ""
	check(Cleanup.find_name(table, "v2").index == -1, "Native lookup skipped an empty-name sentinel")
	check(not Cleanup.remove_name(table, "missing").removed and table.count == 4, "Missing binding changed native count")
	table = table_fixture()
	check(Cleanup.remove_chemical_bindings(table, "v1", "v3").removed_names == ["v1", "v3"], "Mole/mass cleanup order differs")
	check(table.count == 2 and table.rows[0][13] == "v0" and table.rows[1][13] == "v2", "Unrelated native variable was deleted")
	table = table_fixture()
	table.rows[2][13] = "v1"
	check(Cleanup.remove_chemical_bindings(table, "v1", "v1").removed_names.size() == 2, "Native two independent lookups were collapsed into one deduplicated cleanup")
	check(not Cleanup.find_name({"count": 1, "rows": []}, "x").ok, "Unpreserved native physical slots silently synthesized")
	var path := ProjectSettings.globalize_path("res://").path_join("../evidence/original_logic/native-variable-cleanup-oracle.json").simplify_path()
	var oracle: Dictionary = JSON.parse_string(FileAccess.get_file_as_string(path))
	for case in oracle.cases:
		table = table_fixture()
		table.count = int(case.count)
		for i in range(300):
			table.rows[i][13] = str(case.overrides.get(str(i), "v" + str(i)))
			table.rows[i][14] = "aux" + str(i)
			table.rows[i][15] = "expr" + str(i)
			table.rows[i][16] = "note" + str(i)
		var actual: Dictionary = Cleanup.find_name(table, str(case.query))
		check(actual.ok and int(actual.index) == int(case.native_index), "Original variable lookup index differs: " + str(case.name))
		if case.delete: check(Cleanup.remove_index(table, int(actual.index)).ok, "Native variable deletion rejected")
		check(int(table.count) == int(case.native_count), "Native variable table count differs: " + str(case.name))
		for i in range(300):
			for field in range(17):
				var same: bool = int(table.rows[i][field]) == int(case.native_rows[i][field]) if field < 13 else str(table.rows[i][field]) == str(case.native_rows[i][field])
				check(same, "Native physical variable slot differs: %s row%d field%d" % [case.name, i, field])
	print("Original variable cleanup: %s; %d original executable helper frames, all300x17 physical fields, name/sentinel lookup and unchanged tail; source regressions for separate mole/mass cleanup" % ["PASS" if failures == 0 else "FAIL", oracle.cases.size()])
	quit(0 if failures == 0 else 1)
