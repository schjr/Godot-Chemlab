extends SceneTree
const Slots=preload("res://scripts/original/original_slots.gd")
var failures:Array=[]
func check(condition:bool,label:String)->void:
	if not condition: failures.append(label)
func _initialize()->void:
	# Declared allocation observation; no claim that constructors zero heap cells.
	var raw:=PackedByteArray();raw.resize(800)
	raw.encode_double(0,0.75);raw.encode_double(8,-0.125);raw.encode_double(16,0.5)
	var v:Dictionary={"contents":{"water":1.0},"solid_3cd8":{"water":0.0}}
	check(Slots.initialize(v).ok,"initialize unknown allocation")
	check(not Slots.read(v,"solid_3ff8",1).ok,"unobserved remains unknown")
	for field in ["solid_3cd8","solid_3ff8","native_species_volume"]:
		check(Slots.observe(v,field,raw.hex_encode(),{"fixture":"declared sentinel cells"}).ok,"attach full observation")
	check(Slots.commit(v).ok,"source write overrides observation")
	check(Slots.project(v).ok,"project current index")
	check(v.solid_3cd8.water==0.0,"existing Run write wins")
	check(Slots.clear_run_particles(v).ok,"native active-only Run clear")
	check(Slots.read(v,"solid_3ff8",1).value==-0.125,"Run preserves inactive stale cell")
	# Native 48E9B4 writes mass/moles/volume only for the new inert name.
	v.contents.inert=0.001;v.native_species_mass={"inert":0.028};v.native_species_volume.inert=0.0
	check(Slots.commit(v).ok and Slots.project(v).ok,"native inert append")
	check(v.solid_3ff8.inert==-0.125,"new name reads original raw index")
	# Explicit loader/editor rewrite changes mass/moles, never shifts particle caches.
	var writes:Dictionary={"contents":{0:PackedFloat64Array([0.001]).to_byte_array().hex_encode()}}
	check(Slots.replace_names(v,["inert"],writes).ok,"explicit source rewrite")
	check(v.solid_3ff8.inert==0.0,"reorder uses unchanged physical index")
	check(Slots.read(v,"solid_3ff8",1).value==-0.125,"removed tail retains bytes")
	v.contents.second=0.0;v.solid_3cd8.second=0.0;v.solid_3ff8.second=0.0
	check(Slots.commit(v).ok,"reaction explicit zero write")
	check(Slots.read(v,"solid_3ff8",1).raw_hex=="0000000000000000","zero append overwrites stale cell")
	check(Slots.write_hex(v,"solid_3ff8",99,"010000000000f87f").ok,"preserve NaN payload")
	check(not Slots.read(v,"solid_3ff8",99).ok,"nonfinite read explicit boundary")
	check(v.native_slot_backing.arrays.solid_3ff8[99]=="010000000000f87f","NaN bits unchanged")
	var original:Dictionary={"contents":{"a":1.0,"b":2.0,"c":3.0}}
	Slots.initialize(original)
	for field in Slots.FIELDS:Slots.observe(original,field,raw.hex_encode(),{"fixture":"explicit editor allocation"})
	var draft:Dictionary=original.duplicate(true)
	check(Slots.commit_editor_rows(original,draft,[{"species":"b","moles":2.0,"mass":20.0},{"species":"c","moles":3.0,"mass":30.0}]).ok,"native editor row rebuild")
	check(draft.solid_3ff8.b==0.75 and draft.solid_3ff8.c==-0.125,"editor does not migrate particle values with names")
	check(Slots.read(draft,"native_species_mass",2).value==0.0,"editor clears former active tail mass")
	check(Slots.read(draft,"native_species_volume",2).value==0.5,"editor leaves same tail volume untouched")
	var restored:Dictionary=JSON.parse_string(JSON.stringify(draft))
	check(Slots.initialize(restored).ok and Slots.read(restored,"solid_3ff8",1).raw_hex==Slots.read(draft,"solid_3ff8",1).raw_hex,"serialized allocation retains cell bits")
	v.contents.erase("inert")
	check(not Slots.commit(v).ok,"implicit compaction prohibited")
	print(JSON.stringify({"failures":failures}))
	if failures.is_empty():print("PASS original raw-index slot lifecycle and unknown-byte boundaries")
	quit(0 if failures.is_empty() else 1)
