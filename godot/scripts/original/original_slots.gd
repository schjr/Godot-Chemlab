class_name OriginalSlots
extends RefCounted
## Numeric apparatus allocation cells are indexed, not owned by species names.
## Null denotes an unobserved cell. Hex preserves every observed IEEE bit.
const FIELDS := {"native_species_mass":0x298,"native_species_volume":0x5b8,"contents":0x8d8,"solid_3cd8":0x3cd8,"solid_3ff8":0x3ff8}
const KEY := "native_slot_backing"
static func _error(message: String) -> Dictionary: return {"ok":false,"error":message}
static func initialize(vessel: Dictionary) -> Dictionary:
	if not vessel.get("contents",null) is Dictionary or vessel.contents.size()>100: return _error("Original ordered contents are invalid")
	if vessel.has(KEY):
		var backing=vessel[KEY]
		if not backing is Dictionary or int(backing.get("version",0))!=1 or not backing.get("names",null) is Array or not backing.get("arrays",null) is Dictionary:return _error("Invalid original allocation backing")
		for field in FIELDS:
			if not backing.arrays.get(field,null) is Array or backing.arrays[field].size()!=100:return _error("Incomplete original allocation backing")
			for cell in backing.arrays[field]:
				if cell!=null and (not cell is String or cell.hex_decode().size()!=8):return _error("Invalid original QWORD allocation cell")
		return {"ok":true}
	var arrays := {}
	for field in FIELDS:
		var cells: Array = []; cells.resize(100)
		if vessel.get(field+"_slots",null) is Array:
			if vessel[field+"_slots"].size()!=100:return _error("An explicit native slot array must contain 100 cells")
			for index in 100:cells[index]=PackedFloat64Array([float(vessel[field+"_slots"][index])]).to_byte_array().hex_encode()
		arrays[field] = cells
	vessel[KEY] = {"version":1,"names":vessel.contents.keys(),"arrays":arrays,"observations":[]}
	return commit(vessel)
static func observe(vessel: Dictionary, field: String, raw_hex: String, provenance: Dictionary = {}) -> Dictionary:
	if not FIELDS.has(field): return _error("Unknown native apparatus array")
	var bytes := raw_hex.hex_decode()
	if bytes.size()!=800: return _error("Observation must contain all 100 original QWORD cells")
	var result := initialize(vessel)
	if not result.ok: return result
	var cells: Array = vessel[KEY].arrays[field]
	for index in 100: cells[index] = bytes.slice(index*8,index*8+8).hex_encode()
	vessel[KEY].observations.append({"field":field,"raw_hex":raw_hex,"provenance":provenance.duplicate(true)})
	return {"ok":true}
static func write_hex(vessel: Dictionary, field: String, index: int, raw_hex: String) -> Dictionary:
	if not vessel.has(KEY) or not FIELDS.has(field) or index<0 or index>=100 or raw_hex.hex_decode().size()!=8:
		return _error("Invalid original slot write")
	vessel[KEY].arrays[field][index] = raw_hex.to_lower()
	return {"ok":true}
static func read(vessel: Dictionary, field: String, index: int) -> Dictionary:
	if not vessel.has(KEY) or not FIELDS.has(field) or index<0 or index>=100: return _error("Invalid original slot read")
	var cell = vessel[KEY].arrays[field][index]
	if cell == null: return _error("Unobserved original slot +0x%x[%d]"%[FIELDS[field],index])
	var bytes := str(cell).hex_decode()
	var value := bytes.decode_double(0)
	if not is_finite(value): return _error("Observed nonfinite original slot requires its native exception path")
	return {"ok":true,"value":value,"raw_hex":cell}
static func commit(vessel: Dictionary) -> Dictionary:
	if not vessel.has(KEY): return initialize(vessel)
	var names: Array = vessel.contents.keys()
	var old: Array = vessel[KEY].names
	if names.size()>100: return _error("Original species slot capacity exceeded")
	# Automatic migration would invent writes. Appends alone keep existing indices.
	for index in old.size():
		if index>=names.size() or old[index]!=names[index]: return _error("Species order changed without explicit native slot writes")
	for field in FIELDS:
		var table: Dictionary = vessel.get(field,{})
		for index in names.size():
			if table.has(names[index]):
				vessel[KEY].arrays[field][index] = PackedFloat64Array([float(table[names[index]])]).to_byte_array().hex_encode()
	vessel[KEY].names = names
	return {"ok":true}
static func project(vessel: Dictionary) -> Dictionary:
	if not vessel.has(KEY): return _error("Original allocation backing is absent")
	var names: Array = vessel.contents.keys()
	if names != vessel[KEY].names: return _error("Commit the source slot writes before projecting")
	for field in FIELDS:
		if field=="contents": continue
		var table := {}
		for index in names.size():
			var cell = vessel[KEY].arrays[field][index]
			if cell == null: continue # Preserve unknown; no source read has occurred yet.
			var decoded := read(vessel,field,index)
			if not decoded.ok: continue # Raw nonfinite bytes remain preserved until actually read.
			table[names[index]] = decoded.value
		vessel[field] = table
	return {"ok":true}
static func replace_names(vessel: Dictionary, names: Array, numeric_writes: Dictionary) -> Dictionary:
	# Caller supplies exact source writes for a loader/editor rewrite. No shift implied.
	if names.size()>100 or not vessel.has(KEY): return _error("Invalid original name rewrite")
	for field in numeric_writes:
		for index in numeric_writes[field]:
			var result := write_hex(vessel,field,int(index),str(numeric_writes[field][index]))
			if not result.ok: return result
	var contents := {}
	for index in names.size():
		var decoded := read(vessel,"contents",index)
		if not decoded.ok: return decoded
		contents[str(names[index])] = decoded.value
	vessel.contents = contents; vessel[KEY].names = names.duplicate()
	return project(vessel)
static func clear_run_particles(vessel: Dictionary) -> Dictionary:
	var result := commit(vessel)
	if not result.ok: return result
	for field in ["solid_3cd8","solid_3ff8"]:
		for index in vessel.contents.size():
			write_hex(vessel,field,index,"0000000000000000")
	return project(vessel)

static func commit_editor_rows(original:Dictionary,draft:Dictionary,rows:Array)->Dictionary:
	# 49F0C8 rebuilds temporary mass/mole rows. Its full-array copy leaves
	# volume and particle arrays at their original physical slot indices.
	var initialized:=initialize(original)
	if not initialized.ok:return initialized
	draft[KEY]=original[KEY].duplicate(true)
	var writes:Dictionary={"contents":{},"native_species_mass":{}}
	for field in writes:
		for index in original.contents.size():writes[field][index]="0000000000000000"
	var names:Array=[]
	for index in rows.size():
		var row:Dictionary=rows[index]
		names.append(str(row.species))
		writes.contents[index]=PackedFloat64Array([float(row.moles)]).to_byte_array().hex_encode()
		writes.native_species_mass[index]=PackedFloat64Array([float(row.mass)]).to_byte_array().hex_encode()
	# Nested Form5 writes volume only where its handler actually added a row.
	if draft.has("native_editor_volume_writes"):writes.native_species_volume=draft.native_editor_volume_writes
	var result:=replace_names(draft,names,writes)
	if result.ok:draft.erase("native_editor_volume_writes")
	return result
