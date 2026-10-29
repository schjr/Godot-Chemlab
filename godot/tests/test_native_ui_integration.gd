extends SceneTree
var app
const Slots=preload("res://scripts/original/original_slots.gd")
const Selection=preload("res://scripts/original/original_selection.gd")
func _initialize()->void:call_deferred("_run")
func _run()->void:
	app=load("res://scenes/main.tscn").instantiate();root.add_child(app)
	await process_frame;await process_frame
	var imported:=0;var chart_count:=0
	for i in range(app.examples.size()):
		assert(app.load_example(i),str(app.examples[i].name))
		await process_frame
		assert(app.canvas.annotations==app.model.annotations)
		var scene:Dictionary=app.canvas.selection_scene()
		for v in app.model.native_apparatus():
			var point:=Vector2(v.position[0],v.position[1]);var native:=Selection.press(scene,point)
			assert(native.ok)
			assert(app.canvas.hit_test(point)==app.canvas._decision_id(native))
		for v in app.model.vessels:
			if v.kind!="chart":continue
			chart_count+=1
			assert(app.canvas.vessel_size(v)==Vector2(240,240))
			assert(v.has("native_chart_state") and v.has("native_chart_grid"))
			assert(v.native_chart_segments.is_empty())
			# An accepted chart update reads native strings, independent of UI wall time.
			var before:Dictionary=v.native_chart_state.duplicate(true)
			assert(app.model.sample_charts(app.model.vessels))
			assert(v.native_chart_segments.size()>0)
			var count:int=v.native_chart_segments.size()
			app.canvas._process(1.0)
			assert(v.native_chart_segments.size()==count)
			assert(not before.is_empty())
		# Explicit physical100-cell fixture observation; no production defaults.
		var zero_cells:=PackedByteArray();zero_cells.resize(800);zero_cells.fill(0)
		for vessel in app.model.native_apparatus():
			for field in ["native_species_volume","solid_3cd8","solid_3ff8"]:
				assert(Slots.observe(vessel,field,zero_cells.hex_encode(),{"source":"original oracle explicit zero numerical allocation profile"}).ok)
		assert(app.model.start())
		app.model.step(0.02,{"observed_stack_excess":0.0})
		if not app.model.last_error.is_empty():
			print("FAIL accepted UI tick ",app.examples[i].name,": ",app.model.last_error);app.free();quit(1);return
		assert(app.model.elapsed==0.02)
		app.model.running=false
		imported+=1
	# Native body dragging updates the real position and native fields together.
	for i in range(app.examples.size()):
		if app.examples[i].name=="氢氧化铜与氢氧化铁":assert(app.load_example(i));break
	app.canvas.zoom=1.0;app.canvas.pan=Vector2.ZERO
	var source:Dictionary=app.model.native_apparatus()[2]
	var press:=InputEventMouseButton.new();press.button_index=MOUSE_BUTTON_LEFT;press.pressed=true;press.position=app.canvas.pan+Vector2(source.position[0],source.position[1]-36)*app.canvas.zoom
	app.canvas._gui_input(press)
	assert(app.canvas.selected_id==int(source.id))
	var motion:=InputEventMouseMotion.new();motion.position=app.canvas.pan+Vector2(179,154)*app.canvas.zoom
	app.canvas._gui_input(motion)
	press.pressed=false;press.position=motion.position;app.canvas._gui_input(press)
	assert(source.position==[179,190])
	assert(int(source.native_fields["0x10"])==179 and int(source.native_fields["0x14"])==190)
	# Actual wood corner drag: native MouseMove fixture records28x21 at189,273.
	for i in range(app.examples.size()):
		if app.examples[i].name=="加热碱式碳酸铜":assert(app.load_example(i));break
	app.canvas.zoom=1.0;app.canvas.pan=Vector2.ZERO
	press.pressed=true;press.position=Vector2(168,254);app.canvas._gui_input(press)
	assert(int(app.canvas._selection.type)==316 and int(app.canvas._selection.command)==1)
	motion.position=Vector2(175,263);app.canvas._gui_input(motion)
	var wood:Dictionary=app.model.native_apparatus()[4]
	assert(wood.position==[189,273] and int(wood.native_bitmap_width)==28 and int(wood.native_bitmap_height)==21)
	press.pressed=false;press.position=motion.position;app.canvas._gui_input(press)
	var saved:=preload("res://scripts/experiment_adapter.gd").from_state(app.legacy_doc,app.model.to_state())
	assert(not saved.has("error"))
	assert(int(saved.apparatus[4].metadata[11])==28 and int(saved.apparatus[4].metadata[12])==21)
	# Native Form4 cleanup projects only proven active-order/exact-name effects.
	var binding_doc:Dictionary={}
	for d in app.examples:
		if d.name=="酸碱中和滴定":binding_doc=d;break
	assert(app.import_document(binding_doc))
	var bound:Dictionary={};var species:=""
	for vessel in app.model.native_apparatus():
		for name in vessel.get("native_binding_names",{}):
			if not str(vessel.native_binding_names[name].moles).is_empty():bound=vessel;species=str(name);break
		if not bound.is_empty():break
	var edited:Dictionary=bound.duplicate(true);edited.contents.erase(species)
	var variable_name:=str(bound.native_binding_names[species].moles)
	var cleanup:Dictionary=app.cleanup_deleted_chemical_bindings(bound,edited)
	assert(cleanup.ok and not app.program.variables.has(variable_name))
	print("PASS native UI integration: %d original imports, %d fixed charts,28accepted original-program ticks, actual mouse drag/wood resize/release/CEM save and proven binding cleanup"%[imported,chart_count])
	app.free();quit()
