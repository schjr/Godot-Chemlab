extends SceneTree
const Slots=preload("res://scripts/original/original_slots.gd")
const Host = preload("res://scripts/original_model_host.gd")
const Formats = preload("res://scripts/legacy_formats.gd")
const Adapter = preload("res://scripts/experiment_adapter.gd")
func number(hex: String) -> float:
	var bytes := PackedByteArray()
	for i in range(0,hex.length(),2): bytes.append(hex.substr(i,2).hex_to_int())
	return bytes.decode_double(0)
func equal_bits(a: float,b: float) -> bool:
	return PackedFloat64Array([a]).to_byte_array() == PackedFloat64Array([b]).to_byte_array()
var app
func canvas_event(event:InputEventMouseButton)->void:
	# Enter through the viewport, including the window gate and Control routing.
	event.position=app.canvas.get_global_transform_with_canvas()*(app.canvas.pan+event.position*app.canvas.zoom)
	event.global_position=event.position
	root.push_input(event,true)
func pour_menu(v:Dictionary)->void:
	var event:=InputEventMouseButton.new();event.button_index=MOUSE_BUTTON_RIGHT;event.pressed=true;event.position=Vector2(v.position[0],v.position[1])
	canvas_event(event)
	assert(app.context_menu.visible)
	assert(app.context_menu.is_embedded())
	var menu=app.context_menu
	var panel:StyleBox=menu.get_theme_stylebox("panel")
	var top:=panel.get_margin(SIDE_TOP);var bottom:=panel.get_margin(SIDE_BOTTOM)
	var height:float=(menu.size.y-top-bottom)/menu.item_count
	var point:=Vector2(menu.position)+Vector2(menu.size.x/2.0,top+height*(menu.get_item_index(2)+0.5))
	for pressed in [true,false]:
		var click:=InputEventMouseButton.new();click.button_index=MOUSE_BUTTON_LEFT;click.pressed=pressed;click.position=point;click.global_position=point;root.push_input(click,true)
func _initialize()->void:call_deferred("_run")
func _run() -> void:
	var fixture: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_workflow_run_order.json"))
	if fixture.status != "executed":
		print(JSON.stringify({"unresolved":fixture.get("error","")})); quit(1); return
	app=load("res://scenes/main.tscn").instantiate();root.add_child(app)
	await process_frame;await process_frame
	assert(app.import_document(Formats.load_document(fixture.fixture_path)))
	var model=app.model
	app.canvas.zoom=1.0;app.canvas.pan=Vector2.ZERO
	# Declared physical100-cell oracle profile, never production defaults.
	var zero_cells:=PackedByteArray();zero_cells.resize(800);zero_cells.fill(0)
	for v in model.native_apparatus():
		for field in ["native_species_volume","solid_3cd8","solid_3ff8"]:
			assert(Slots.observe(v,field,zero_cells.hex_encode(),{"source":"original oracle explicit zero numerical allocation profile"}).ok)
	assert(model.start())
	# Original global2 pauses physics AND suppresses477708 helper dispatch.
	var dropper:Dictionary=model.native_apparatus()[2]
	app._select_apparatus(int(dropper.id));model.toggle_pause()
	var before:Array=[]
	for v in model.native_apparatus():before.append(v.contents.duplicate(true))
	var pause_click:=InputEventMouseButton.new();pause_click.button_index=MOUSE_BUTTON_LEFT;pause_click.pressed=false;pause_click.position=Vector2(460,178)
	assert(preload("res://scripts/original/original_controls.gd").command_at(dropper,pause_click.position)==1)
	canvas_event(pause_click)
	for i in before.size():assert(model.native_apparatus()[i].contents==before[i])
	assert(model.paused and not model.running)
	model.toggle_pause();assert(model.running)
	var mismatches: Array = []
	var completed := 0
	var frame_count:=0
	assert(fixture.startup_events==["43F7BC stopped refresh-boundary","004624D8","42DC3C save-boundary","0046C894","0048E9B4"])
	check_snapshot(model.native_apparatus(),fixture.start,"native Run return",mismatches)
	for action_index in range(fixture.actions.size()):
		var action: Dictionary = fixture.actions[action_index]
		var selected: Dictionary = model.native_apparatus()[int(action.selected)]
		selected.position = action.position.duplicate()
		selected.native_fields["0x10"] = str(int(action.position[0]))
		selected.native_fields["0x14"] = str(int(action.position[1]))
		app._select_apparatus(int(selected.id))
		if action.get("orientation_toggle",false):pour_menu(selected)
		else:
			var rects:=preload("res://scripts/original/original_controls.gd").rectangles(selected)
			var rectangle:Dictionary={}
			for r in rects:
				if int(r.command)==int(action.command):rectangle=r;break
			assert(not rectangle.is_empty())
			var event:=InputEventMouseButton.new();event.button_index=MOUSE_BUTTON_LEFT;event.pressed=false;event.position=Vector2((rectangle.left+rectangle.right)/2,(rectangle.top+rectangle.bottom)/2)
			var down:InputEventMouseButton=event.duplicate();down.pressed=true;canvas_event(down)
			canvas_event(event)
			assert(model.last_error.is_empty(),model.last_error)
		for _tick in range(int(action.get("ticks",0))):
			model.step(number(fixture.delta_bits))
			if not model.last_error.is_empty():
				print(JSON.stringify({"actions_completed":completed,"unresolved":[action.name,model.last_error],"bit_mismatches":mismatches})); quit(1); return
			check_snapshot(model.native_apparatus(),fixture.frames[frame_count],"%s frame%d"%[action.name,frame_count],mismatches)
			frame_count+=1
		if action.get("orientation_toggle",false):pour_menu(selected)
		check_snapshot(model.native_apparatus(),fixture.states[action_index],str(action.name),mismatches)
		completed += 1
	assert(frame_count==63 and completed==7)
	print(JSON.stringify({"actions_tested":completed,"physics_frames":frame_count,"bit_mismatches":mismatches}))
	if not (not mismatches.is_empty()): print("PASS actual UI paused no-op/resume/withdrawal/drop/context pouring:7actions63ticks exact native bits")
	app.free()
	quit(1 if not mismatches.is_empty() else 0)

func check_snapshot(actual:Array,expected:Array,label:String,mismatches:Array)->void:
	for i in range(actual.size()):
		var v: Dictionary = actual[i]
		if v.contents.keys() != expected[i].contents.keys(): mismatches.append([label,i] + ["species_order"])
		var selected_names: Array = []
		for r in v.native_reaction_records: selected_names.append(str(r.get("name",r.get("id",""))))
		if selected_names != expected[i].reaction_names: mismatches.append([label,i] + ["reaction_order"])
		for key in ["contents","masses","volumes","solid_3cd8","solid_3ff8"]:
			var table: Dictionary = v[key if key in ["contents","solid_3cd8","solid_3ff8"] else "native_species_mass" if key=="masses" else "native_species_volume"]
			for species in expected[i].bits[key]:
				if not table.has(species) or not equal_bits(float(table.get(species,0)),number(expected[i].bits[key][species])): mismatches.append([label,i,key,species,PackedFloat64Array([float(table.get(species,0))]).to_byte_array().hex_encode(),expected[i].bits[key][species]])
		for pair in [["temperature","temperature"],["native_liquid_volume","liquid_volume"],["native_gas_moles","gas_moles"],["native_gas_volume","gas_volume"],["native_pressure","pressure"],["gas_3cc0","gas_3cc0"],["solid_4318","solid_4318"]]:
			if not equal_bits(float(v.get(pair[0],0)),number(expected[i].bits[pair[1]])): mismatches.append([label,i,pair[1]])
