extends SceneTree
var app
func _initialize()->void:call_deferred("_run")
func _run()->void:
	app=load("res://scenes/main.tscn").instantiate();root.add_child(app);await process_frame;await process_frame
	var data:Dictionary=JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_pour_menu.json"));var errors:Array=[]
	for c in data.cases:
		var v:Dictionary={"native_fields":{"0x08":str(int(c.type)),"0x0c":str(int(c.size)),"0x38":str(int(c.closed)),"0x18":str(int(c.orientation))}}
		app._populate_context(v)
		var present:bool=app.context_menu.get_item_index(2)>=0
		if present!=bool(c.expected.visible):errors.append(c)
		if present and c.expected.checked!=null:
			if app.context_menu.is_item_checked(app.context_menu.get_item_index(2))!=bool(c.expected.checked):errors.append(c)
	print(JSON.stringify({"pour_menu_cases":data.cases.size(),"native_failures":data.errors.size(),"mismatches":errors.slice(0,5)}))
	if errors.is_empty() and data.errors.is_empty():print("PASS original pouring menu visibility/checked state")
	app.free();quit(0 if errors.is_empty() and data.errors.is_empty() else 1)
