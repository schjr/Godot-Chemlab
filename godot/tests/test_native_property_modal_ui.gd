extends SceneTree
const Slots=preload("res://scripts/original/original_slots.gd")
func _initialize():call_deferred("_run")
func _run():
	var fixture=JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_property_modal.json"))
	for c in fixture.cases:
		var expected:Array=["create","modal","destroy"] if int(c.type)>100 else []
		if int(c.type)>100 and int(c.run)==0:expected.append("caller43F7BC")
		assert(c.events==expected)
	var app=load("res://scenes/main.tscn").instantiate();root.add_child(app)
	await process_frame;await process_frame
	for i in app.examples.size():
		if app.examples[i].name=="酸碱中和滴定":assert(app.load_example(i));break
	app.model.native_clock=func():return 100
	var zero:=PackedByteArray();zero.resize(800);zero.fill(0)
	for v in app.model.native_apparatus():
		for field in ["native_species_volume","solid_3cd8","solid_3ff8"]:assert(Slots.observe(v,field,zero.hex_encode(),{"source":"explicit numerical oracle allocation profile"}).ok)
	var vessel:Dictionary=app.model.native_apparatus()[0]
	for confirm in [false,true]:
		for v in app.model.vessels:
			if v.kind=="chart":v.native_chart_segments.append({"old_marker":true})
		app.dialogs.show_properties(vessel.id);var w:Window=app.get_child(app.get_child_count()-1)
		assert(w.exclusive and not app.dialogs.property_close_pending)
		# NestedForm5 belongs toForm4, not to the main owner.
		w.find_child("ChemicalAdd",true,false).pressed.emit()
		var nested:Window=w.get_child(w.get_child_count()-1);assert(nested is Window and nested.exclusive and nested.get_parent()==w)
		nested.queue_free();await process_frame
		var observed:Dictionary={"closed":false}
		var closure:Callable=func(_id:int,_confirmed:bool):
			assert(not w.is_inside_tree());assert(_confirmed==confirm);observed.closed=true
		app.dialogs.property_closed.connect(closure)
		w.find_child("PropertiesCommit" if confirm else "PropertiesCancel",true,false).pressed.emit()
		assert(app.dialogs.property_close_pending and not observed.closed)
		await process_frame
		assert(observed.closed and not app.dialogs.property_close_pending)
		for v in app.model.vessels:
			if v.kind=="chart":assert(v.native_chart_segments.is_empty())
		app.dialogs.property_closed.disconnect(closure)
	# Modality restricts owner input; it does not pause the source timer.
	assert(app.model.start());app.dialogs.show_properties(vessel.id)
	var w:Window=app.get_child(app.get_child_count()-1);assert(w.exclusive and w.find_child("PropertiesCommit",true,false).disabled)
	app.model.step(0.02,{"observed_stack_excess":0.0});assert(app.model.last_error.is_empty() and app.model.elapsed==0.02)
	w.find_child("PropertiesCancel",true,false).pressed.emit();await process_frame
	assert(app.model.running and app.model.elapsed==0.02)
	print("PASS native Form4 modal:15original caller refs,Confirm/Cancelafterclose,chartreset,nestedownership,livephysics")
	app.free();quit()
