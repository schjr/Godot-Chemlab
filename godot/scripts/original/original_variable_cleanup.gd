class_name OriginalVariableCleanup
extends RefCounted
## Raw Form4 variable-table helpers004A0F50/004A1050.
## A table must preserve300 physical rows, each17 DWORD/string fields.
## No invented mapping from vessel/species to variable names.
const CAPACITY := 300
const NAME_FIELD := 13 # table+4 +row*0x44 +0x34 =table+(row*17+14)*4.
static func _valid(table: Dictionary) -> bool:
	if not table.get("rows", null) is Array or not table.has("count"): return false
	if int(table.count) < 0 or int(table.count) > CAPACITY or table.rows.size() != CAPACITY: return false
	for row in table.rows:
		if not row is Array or row.size() != 17: return false
	return true
static func find_name(table: Dictionary, name: String) -> Dictionary:
	if not _valid(table): return {"ok": false, "error": "Native variable table requires count and300 preserved17-field physical rows"}
	for i in range(int(table.count)):
		var stored := str(table.rows[i][NAME_FIELD])
		#4A0F50 tests the empty-name sentinel BEFORE checking the requested name.
		if stored.is_empty(): break
		if stored == name: return {"ok": true, "index": i}
	return {"ok": true, "index": -1}
static func remove_index(table: Dictionary, index: int) -> Dictionary:
	if not _valid(table): return {"ok": false, "error": "Native variable table lacks its physical slot cache"}
	if index == -1: return {"ok": true, "removed": false}
	# Native caller supplies only lookup results; other indices are unresolved.
	if index < 0 or index >= int(table.count): return {"ok": false, "error": "Index is outside native caller's lookup contract"}
	for i in range(index, CAPACITY - 1): table.rows[i] = table.rows[i + 1].duplicate(true)
	table.count = int(table.count) - 1
	# Original does NOT clear physical row299, even after deleting all active rows.
	return {"ok": true, "removed": true, "index": index}
static func remove_name(table: Dictionary, name: String) -> Dictionary:
	var found := find_name(table, name)
	if not found.get("ok", false): return found
	return remove_index(table, int(found.index))
static func remove_chemical_bindings(table: Dictionary, mole_name: String, mass_name: String) -> Dictionary:
	#4A0A98/4A2194 pass the two stored grid binding names independently.
	var removed: Array = []
	for name in [mole_name, mass_name]:
		if str(name).is_empty(): continue
		var result := remove_name(table, str(name))
		if not result.get("ok", false): return result
		if result.removed: removed.append(str(name))
	return {"ok": true, "removed_names": removed}
