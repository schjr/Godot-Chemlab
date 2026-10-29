extends SceneTree
const Profile = preload("res://scripts/original/original_runtime_profile.gd")
const Slots = preload("res://scripts/original/original_slots.gd")
func _init() -> void:
	# Synthetic transport/identity checks only; this is not a Windows observation.
	var bytes := PackedByteArray(); bytes.resize(800)
	bytes.encode_double(8,0.125)
	var record := {"status":"read","species_identity_stable_during_read":true,"native_index":0,"type_id":102,"native_type_parameter":100,"label":{"text":"烧杯"},"species":[{"status":"read","text":"H2O(液体)"}],"arrays":{}}
	for field in Profile.FIELDS: record.arrays[field] = {"count":100,"raw_hex":bytes.hex_encode()}
	var fixture := {"format":"ChemLab-original-read-only-memory-profile","version":1,"provenance":{"image_sha256":Profile.ORIGINAL_SHA256},"snapshots":[{"apparatus_identity_stable_during_read":true,"run_state_before":{"simulation_advancing":false},"run_state_after":{"simulation_advancing":false},"vessels":[record]}]}
	var vessel := {"label":"烧杯","type_id":102,"native_fields":{"0x0c":"100"},"contents":{"H2O(液体)":1.0},"solid_3cd8":{"H2O(液体)":0.75}}
	var result := Profile.decode(fixture,[vessel])
	assert(result.ok)
	assert(Profile.apply_active(vessel,result.slots[0]).ok)
	assert(vessel.solid_3cd8["H2O(液体)"] == 0.75) # An explicit native write wins.
	vessel.contents["惰性气体(气体)"] = 0.01
	assert(Profile.apply_active(vessel,result.slots[0]).ok)
	assert(vessel.solid_3cd8["惰性气体(气体)"] == 0.125) # Use the actual slot index.
	var bad: Dictionary = fixture.duplicate(true); bad.provenance.image_sha256 = "wrong"
	assert(not Profile.decode(bad,[vessel]).ok)
	bad = fixture.duplicate(true); bad.snapshots[0].run_state_after.simulation_advancing = true
	assert(not Profile.decode(bad,[vessel]).ok)
	bad = fixture.duplicate(true); bad.snapshots[0].apparatus_identity_stable_during_read = false
	assert(not Profile.decode(bad,[vessel]).ok)
	assert(not Profile.decode(fixture,[vessel]).ok) # Changed species must not reuse a cold profile.
	var amounts:=PackedByteArray();amounts.resize(800);amounts.encode_double(0,1.0)
	var full:Dictionary=fixture.duplicate(true)
	full.snapshots[0].vessels[0].arrays.moles_0x8d8={"count":100,"raw_hex":amounts.hex_encode()}
	full.snapshots[0].vessels[0].arrays.mass_0x298={"count":100,"raw_hex":amounts.hex_encode()}
	var fresh:Dictionary={"label":"烧杯","type_id":102,"native_fields":{"0x0c":"100"},"contents":{"H2O(液体)":1.0}}
	result=Profile.decode(full,[fresh]);assert(result.ok)
	assert(Profile.apply_active(fresh,result.slots[0]).ok)
	assert(fresh.native_slot_backing.arrays.contents.size()==100)
	assert(fresh.native_runtime_observation.arrays.mass_0x298.raw_hex==amounts.hex_encode())
	assert(Slots.write_hex(fresh,"solid_3cd8",1,"0000000000000040").ok)
	fresh.contents["new(气体)"]=0.1
	assert(Profile.apply_active(fresh,result.slots[0]).ok)
	assert(fresh.solid_3cd8["new(气体)"]==2.0) # Do not resurrect original 0.125.
	fresh.contents={"H2O(液体)":2.0}
	assert(not Profile.decode(full,[fresh]).ok)
	# +3CC0 can be read by the first particle paint before the reaction core
	# assigns it. Absence stays unknown; an observed signed zero/subnormal
	# remains exact, while an explicit source write retains priority.
	for raw_hex in ["0000000000000080","0100000000000080"]:
		var scalar_profile:Dictionary=fixture.duplicate(true)
		scalar_profile.snapshots[0].vessels[0].scalars={"0x3cc0":{"ieee754_le_hex":raw_hex}}
		var scalar_vessel:Dictionary={"label":"烧杯","type_id":102,"native_fields":{"0x0c":"100"},"contents":{"H2O(液体)":1.0}}
		var scalar_result:=Profile.decode(scalar_profile,[scalar_vessel]);assert(scalar_result.ok)
		assert(Profile.apply_active(scalar_vessel,scalar_result.slots[0]).ok)
		assert(PackedFloat64Array([float(scalar_vessel.gas_3cc0)]).to_byte_array().hex_encode()==raw_hex)
		scalar_vessel.gas_3cc0=2.0
		assert(Profile.apply_active(scalar_vessel,scalar_result.slots[0]).ok)
		assert(scalar_vessel.gas_3cc0==2.0)
	var absent:Dictionary={"label":"烧杯","type_id":102,"native_fields":{"0x0c":"100"},"contents":{"H2O(液体)":1.0}}
	result=Profile.decode(fixture,[absent]);assert(result.ok)
	assert(Profile.apply_active(absent,result.slots[0]).ok)
	assert(not absent.has("gas_3cc0"))
	for malformed in ["0000","gg00000000000000"]:
		bad=fixture.duplicate(true)
		bad.snapshots[0].vessels[0].scalars={"0x3cc0":{"ieee754_le_hex":malformed}}
		assert(not Profile.decode(bad,[absent]).ok)
	print("PASS runtime-profile transport guards: synthetic only; image/identity/pause/slot order and preservation of explicit writes")
	quit()
