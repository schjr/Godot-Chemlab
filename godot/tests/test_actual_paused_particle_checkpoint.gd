extends SceneTree
## Real PID9348 paused checkpoint. No TLS/GDI provider or pause substitution.
const Frame=preload("res://scripts/original/original_particle_frame.gd")
const Objects=preload("res://scripts/original/original_observed_particle_object.gd")
func hash_bytes(raw:PackedByteArray)->String:return Objects.hash_bytes(raw)
func _initialize()->void:
	var fixture_bytes:=FileAccess.get_file_as_bytes("res://tests/fixtures/actual_paused_particle_checkpoint.json")
	if hash_bytes(fixture_bytes)!="c4c8dda5c9df815c0a5d0213228eacd7cc4488c8852295c44e13b334b60b4636":print("FAIL actual checkpoint fixture hash differs");quit(1);return
	var fixture:Dictionary=JSON.parse_string(fixture_bytes.get_string_from_utf8())
	var failures:Array=[]
	if fixture.source_sha256!=Objects.SOURCE_SHA or fixture.capture_sha256!="d290a1db6a5d2e268da8d9e688464649bae47c7c4fd82b5838448a033fa72995" or fixture.validation_sha256!="ac8ff5ccc81c81bb3489214fc143800eccc2314bef141b55e5ee5db41c316132":failures.append("Capture/source identity differs")
	if hash_bytes(FileAccess.get_file_as_bytes("res://data/reagents.json"))!=fixture.catalog_sha256:failures.append("Recovered catalog identity differs")
	if fixture.context.run_flag!=2 or fixture.context.pause_flag!=0 or not fixture.rng.is_empty():failures.append("Actual paused control or unobserved TLS replaced")
	var context:Dictionary=fixture.context.duplicate(true)
	var material:Dictionary={}
	for key in context.native_material_words:
		var words:Array=[]
		for word in context.native_material_words[key]:words.append(int(word))
		material[int(key)]=words
	context.native_material_words=material
	var scene:Dictionary=fixture.scene.duplicate(true)
	for pool in scene.pools:
		for name in pool:
			var descriptor:Dictionary=pool[name].native_raw_object
			descriptor.original_address=int(descriptor.original_address)
			for binding in descriptor.bitmap_bindings.values():
				binding.original_pointer=int(binding.original_pointer)
				var words:Array=[];var rows:Array=[]
				for word in binding.words:words.append(int(word))
				for row in binding.row_addresses:rows.append(int(row))
				binding.words=words;binding.row_addresses=rows
			var check:=Objects.validate(descriptor,name=="solid")
			if not check.ok:failures.append(check)
	if not failures.is_empty():print(JSON.stringify({"failures":failures}));quit(1);return
	var frame=Frame.new();var unknown_rng:Dictionary={}
	var catalog:Dictionary={}
	for reagent in JSON.parse_string(FileAccess.get_file_as_string("res://data/reagents.json")):catalog[reagent.species]=reagent
	var vessels:Array=fixture.vessels.duplicate(true)
	var result:=frame.step(vessels,catalog,fixture.connectors.duplicate(true),scene,context,unknown_rng,Callable(),Callable())
	print(JSON.stringify({"scope":fixture.scope,"result":result,"rng":unknown_rng,"native_pc":frame.vm.pc if frame.vm!=null else null,"failures":failures}))
	if not unknown_rng.is_empty():failures.append("Unobserved RNG was fabricated")
	var expected_boundary:bool=not result.ok and result.get("error","")=="Original VCL particle presentation boundary is unresolved at 0x4e3e50" and int(result.get("pc",0))==0x4e3e50
	if not expected_boundary:failures.append("Actual paused source prefix no longer reaches the documented VCL frontier")
	if frame.vm!=null and frame.vm.integer(int(frame.vm.registers.esp))!=0x49b6cf:failures.append("Unresolved VCL call consumed its original return address")
	if frame.vm!=null:
		for index in [0,3]:
			for name in ["solid","bubbles"]:
				var source:Dictionary=fixture.scene.pools[index][name].native_raw_object
				var pointer:int=frame.solid_addresses[index] if name=="solid" else frame.bubble_addresses[index]
				var prefix_raw:PackedByteArray=frame.vm.read(pointer,int(source.byte_size))
				for rebase in scene.pools[index][name].get("_native_frame_rebases",[]):prefix_raw.encode_u32(int(rebase.offset),int(rebase.original_pointer))
				if prefix_raw.hex_encode()!=source.raw_hex:failures.append("Observed raw object changed before unresolved VCL call: "+str(index)+"/"+name)
		frame.vm.helpers.clear()
	if "--require-complete-frame" in OS.get_cmdline_user_args():print("UNRESOLVED actual paused frame requires original TPen.SetColor4E3E50/VCL state");quit(1);return
	print(JSON.stringify({"failures":failures,"completed_frame":false,"validated_prefix_boundary":"0x004e3e50","paused_control":[2,0]}))
	if failures.is_empty():print("VALIDATION: actual captured raw objects and paused source prefix; VCL boundary explicitly unresolved")
	quit(0 if failures.is_empty() else 1)
