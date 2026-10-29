class_name OriginalRuntimeProfile
extends RefCounted
const Slots = preload("res://scripts/original/original_slots.gd")
## Consume read-only observations without turning an allocation into a default.
const ORIGINAL_SHA256 := "7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c"
const FIELDS := {"volume_0x5b8":"native_species_volume","solid_0x3cd8":"solid_3cd8","solid_0x3ff8":"solid_3ff8"}
const SCALAR_FIELDS := {"0x4318":"solid_4318","0x3cc8":"native_particle_3cc8","0x4338":"native_solid_volume","0x3cc0":"gas_3cc0"}
static func _error(message: String) -> Dictionary:
	return {"ok":false,"error":message}
static func _valid_hex(value: String, byte_count: int) -> bool:
	if value.length()!=byte_count*2: return false
	for index in value.length():
		if not "0123456789abcdef".contains(value[index].to_lower()): return false
	return true
static func decode(profile: Dictionary, apparatus: Array, snapshot_index: int = 0) -> Dictionary:
	if profile.get("format","") != "ChemLab-original-read-only-memory-profile" or int(profile.get("version",0)) != 1:
		return _error("Unrecognized original allocation observation")
	if profile.get("provenance",{}).get("image_sha256","") != ORIGINAL_SHA256:
		return _error("Allocation observation belongs to another executable")
	var snapshots: Array = profile.get("snapshots",[])
	if snapshot_index < 0 or snapshot_index >= snapshots.size(): return _error("Original observation snapshot is absent")
	var snapshot: Dictionary = snapshots[snapshot_index]
	if not snapshot.get("apparatus_identity_stable_during_read",false): return _error("Apparatus changed during original memory observation")
	if snapshot.get("run_state_before",{}).get("simulation_advancing",true) != false or snapshot.get("run_state_after",{}).get("simulation_advancing",true) != false:
		return _error("Original allocation observation was not captured in a stable stopped/paused state")
	var records: Array = snapshot.get("vessels",[])
	if records.size() != apparatus.size(): return _error("Original allocation observation has a different apparatus count")
	var decoded: Array = []
	for i in records.size():
		var record: Dictionary = records[i]; var vessel: Dictionary = apparatus[i]
		if record.get("status","") != "read" or not record.get("species_identity_stable_during_read",false): return _error("Incomplete original apparatus observation")
		if int(record.get("native_index",-1)) != i or int(record.get("type_id",-1)) != int(vessel.type_id) or int(record.get("native_type_parameter",-1)) != int(vessel.native_fields["0x0c"]):
			return _error("Original apparatus identity differs from the imported document")
		if record.get("label",{}).get("text","") != str(vessel.label): return _error("Original apparatus label differs from the imported document")
		var names: Array = []
		for entry in record.get("species",[]):
			if entry.get("status","") != "read": return _error("Original species identity is unreadable")
			names.append(str(entry.text))
		if names != vessel.contents.keys(): return _error("Original species order differs from the imported document")
		var memory: Dictionary = {"raw_arrays":{},"native_record":record.duplicate(true)}
		for offset in SCALAR_FIELDS:
			if not record.get("scalars",{}).has(offset): continue
			var scalar = record.scalars[offset]
			if not scalar is Dictionary or not scalar.get("ieee754_le_hex",null) is String:
				return _error("Original scalar observation is malformed: " + offset)
			var raw_hex: String = scalar.ieee754_le_hex
			if not _valid_hex(raw_hex,8): return _error("Original scalar bytes are incomplete: " + offset)
			var raw_bytes := raw_hex.hex_decode()
			if raw_hex.length()!=16 or raw_bytes.size()!=8 or raw_bytes.hex_encode()!=raw_hex.to_lower():
				return _error("Original scalar bytes are incomplete: " + offset)
		for source in FIELDS:
			var array: Dictionary = record.get("arrays",{}).get(source,{})
			if not _valid_hex(str(array.get("raw_hex","")),800): return _error("Original 100-slot allocation bytes are incomplete")
			var bytes := str(array.get("raw_hex","")).hex_decode()
			if int(array.get("count",0)) != 100 or bytes.size() != 800: return _error("Original 100-slot allocation bytes are incomplete")
			var values: Array = []
			for slot in 100:
				var value := bytes.decode_double(slot*8)
				values.append(value)
			memory[FIELDS[source]] = values
			memory.raw_arrays[FIELDS[source]] = bytes.hex_encode()
		var amount:Dictionary=record.get("arrays",{}).get("moles_0x8d8",{})
		if not amount.is_empty():
			if not _valid_hex(str(amount.get("raw_hex","")),800): return _error("Original amount observation is incomplete")
			var amount_bytes:=str(amount.get("raw_hex","")).hex_decode()
			if int(amount.get("count",-1))!=100 or amount_bytes.size()!=800:return _error("Original amount observation is incomplete")
			for index in names.size():
				if amount_bytes.slice(index*8,index*8+8)!=PackedFloat64Array([float(vessel.contents[names[index]])]).to_byte_array():return _error("Original amounts differ from this document state")
			memory.raw_arrays.contents=amount_bytes.hex_encode()
		var mass:Dictionary=record.get("arrays",{}).get("mass_0x298",{})
		if not mass.is_empty():
			if not _valid_hex(str(mass.get("raw_hex","")),800): return _error("Original mass observation is incomplete")
			var mass_bytes:=str(mass.get("raw_hex","")).hex_decode()
			if int(mass.get("count",-1))!=100 or mass_bytes.size()!=800:return _error("Original mass observation is incomplete")
			memory.raw_arrays.native_species_mass=mass_bytes.hex_encode()
		decoded.append(memory)
	return {"ok":true,"slots":decoded,"provenance":profile.provenance.duplicate(true),"scope":"This observed allocation only; not constructor defaults or live hardware control-word capture"}
static func apply_active(vessel: Dictionary, observed_slots: Dictionary) -> Dictionary:
	if vessel.contents.size() > 100: return _error("Original apparatus species count exceeds 100 slots")
	for field in FIELDS.values():
		if not observed_slots.get(field,null) is Array or observed_slots[field].size() != 100: return _error("Original slot observation is missing")
	var initialized:=Slots.initialize(vessel)
	if not initialized.ok:return initialized
	# Attach allocation bytes once. Subsequent calls must not resurrect old bytes
	# after a proven writer has overwritten an inactive or active cell.
	if not vessel.has("native_runtime_observation"):
		for field in FIELDS.values():
			var raw_hex:String=str(observed_slots.get("raw_arrays",{}).get(field,""))
			if raw_hex.is_empty():raw_hex=PackedFloat64Array(observed_slots[field]).to_byte_array().hex_encode()
			var attached:=Slots.observe(vessel,field,raw_hex,{"source":"validated runtime observation"})
			if not attached.ok:return attached
		for field in ["contents","native_species_mass"]:
			if observed_slots.get("raw_arrays",{}).has(field):
				var attached:=Slots.observe(vessel,field,str(observed_slots.raw_arrays[field]),{"source":"validated runtime observation"})
				if not attached.ok:return attached
		vessel.native_runtime_observation=observed_slots.get("native_record",{}).duplicate(true)
		for offset in SCALAR_FIELDS:
			var scalar:Dictionary=vessel.native_runtime_observation.get("scalars",{}).get(offset,{})
			var raw:=str(scalar.get("ieee754_le_hex","")).hex_decode()
			if raw.size()==8 and not vessel.has(SCALAR_FIELDS[offset]):
				var value:=raw.decode_double(0)
				if is_finite(value):vessel[SCALAR_FIELDS[offset]]=value
	var index := 0
	for species in vessel.contents:
		for field in FIELDS.values():
			if not vessel.get(field,null) is Dictionary: vessel[field] = {}
			if not vessel[field].has(species):
				var cell:=Slots.read(vessel,field,index)
				if cell.ok:vessel[field][species] = cell.value
		index += 1
	var committed:=Slots.commit(vessel)
	if not committed.ok:return committed
	return Slots.project(vessel)
