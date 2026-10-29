extends SceneTree
const Model=preload("res://scripts/original_model_host.gd")
const Formats=preload("res://scripts/legacy_formats.gd")
const Adapter=preload("res://scripts/experiment_adapter.gd")
const Actions=preload("res://scripts/original/original_apparatus_actions.gd")
const Slots=preload("res://scripts/original/original_slots.gd")
const Profile=preload("res://scripts/original/original_runtime_profile.gd")
const CAPTURE_HASHES={"full80-run.json":"bc77afab8ba5ea08ff7c8af19d5daddc422ea63057e7157ca1b01430e7d9f782","full80-naoh.json":"9f6793c5f8729e0dc99ae35de1446230c07f45c7c6c7e1b35c154c3b99b99887"}
func read_capture(directory:String,name:String)->Dictionary:
	var raw:=FileAccess.get_file_as_bytes(directory+name)
	var hash:=HashingContext.new();hash.start(HashingContext.HASH_SHA256);hash.update(raw)
	assert(hash.finish().hex_encode()==CAPTURE_HASHES[name])
	var value:Dictionary=JSON.parse_string(raw.get_string_from_utf8().trim_prefix("\ufeff"))
	assert(value.format=="ChemLab-original-read-only-memory-profile" and value.version==1)
	assert(value.provenance.image_sha256==Profile.ORIGINAL_SHA256)
	assert(value.provenance.process_pointer_bits==32 and value.provenance.runtime_module_base=="0x00400000")
	var snapshot:Dictionary=value.snapshots[0]
	assert(snapshot.apparatus_identity_stable_during_read)
	assert(not snapshot.run_state_before.simulation_advancing and not snapshot.run_state_after.simulation_advancing)
	return value
func _initialize()->void:
	var directory:=ProjectSettings.globalize_path("res://../evidence/windows-runtime/precision-and-graphics-2026-10-14/")
	var before:=read_capture(directory,"full80-run.json")
	var after:=read_capture(directory,"full80-naoh.json")
	assert(before.provenance.process_id==after.provenance.process_id)
	var model=Model.new()
	model.configure(JSON.parse_string(FileAccess.get_file_as_string("res://data/reagents.json")),JSON.parse_string(FileAccess.get_file_as_string("res://data/reactions.json")))
	assert(model.from_state(Adapter.to_state(Formats.load_document("res://tests/fixtures/examples/氢氧化铜与氢氧化铁.cem"))))
	var vessels:Array=model.native_apparatus()
	var fields:Dictionary={"contents":"moles_0x8d8","native_species_mass":"mass_0x298","native_species_volume":"volume_0x5b8","solid_3cd8":"solid_0x3cd8","solid_3ff8":"solid_0x3ff8"}
	for index in vessels.size():
		var vessel:Dictionary=vessels[index];var record:Dictionary=before.snapshots[0].vessels[index]
		assert(record.status=="read" and record.species_identity_stable_during_read)
		assert(record.native_index==index and record.type_id==vessel.type_id and record.label.text==vessel.label)
		assert(record.pointer==after.snapshots[0].vessels[index].pointer)
		for field in fields:
			vessel[field]={}
			var raw:=str(record.arrays[fields[field]].raw_hex).hex_decode()
			for slot in record.species.size(): vessel[field][record.species[slot].text]=raw.decode_double(slot*8)
			assert(Slots.observe(vessel,field,raw.hex_encode(),{"source":"Actual original full80 pre-action allocation; isolated action comparison only"}).ok)
		assert(Slots.commit(vessel).ok)
	var result:=Actions.execute_manual_action(vessels,2,1,model.native_scale,model._species)
	if not result.ok:quit(1);return
	assert(result.transfer and result.transfer_result.performed and result.source_index==1 and result.target_index==2 and result.requested_volume==2.0)
	var failures:Array=[]
	var checks:=0
	for index in [1,2]:
		var record:Dictionary=after.snapshots[0].vessels[index]
		for field in ["contents","native_species_mass","native_species_volume"]:
			for slot in record.species.size():
				var name:String=record.species[slot].text
				# The later paused capture includes gas displacement/refill ticks.
				# This comparison certifies the four transferred reagent rows only.
				if name=="惰性气体(气体)":continue
				checks+=1
				var expected:String=record.arrays[fields[field]].slots[slot].ieee754_le_hex
				var actual:=PackedFloat64Array([float(vessels[index][field].get(name,0.0))]).to_byte_array().hex_encode()
				if actual!=expected:failures.append([index,field,name,actual,expected])
	assert(vessels[2].contents.keys()==["惰性气体(气体)","H2O(液体)","NaOH(溶解)"])
	assert(checks==12)
	print(JSON.stringify({"checks":checks,"failures":failures,"scope":"Actual pre-action allocation; exact water/NaOH moles, mass and volume rows after withdrawal. Gas ticks, elapsed history and full render remain separate."}))
	if failures.is_empty():print("PASS actual Windows NaOH withdrawal: 12 reagent-row values and source/recipient/species order")
	quit(0 if failures.is_empty() else 1)
