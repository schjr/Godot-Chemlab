extends SceneTree
## Desktop rendering verification; use normal display mode, not --headless.
var app
func _initialize() -> void:
	call_deferred("_run")
func _run() -> void:
	app = load("res://scenes/main.tscn").instantiate()
	root.add_child(app)
	root.size = Vector2i(1100, 740)
	await process_frame
	await process_frame
	await RenderingServer.frame_post_draw
	assert(app.model.vessels.size() == 6)
	assert(app.canvas.annotations.size() == 6)
	var output: String = ProjectSettings.globalize_path("res://../build/")
	var image: Image = root.get_texture().get_image()
	assert(not image.is_empty())
	assert(image.save_png(output + "preview-laboratory.png") == OK)
	app.dialogs.show_properties(1)
	await process_frame
	await RenderingServer.frame_post_draw
	root.get_texture().get_image().save_png(output + "preview-properties.png")
	for child in app.get_children():
		if child is Window: child.queue_free()
	await process_frame
	app.modules.current_tab = 1
	for i in app.molecular_catalog.size():
		if app.molecular_catalog[i].name == "乙醇": app._select_molecule(i); break
	await process_frame
	await process_frame
	await RenderingServer.frame_post_draw
	root.get_texture().get_image().save_png(output + "preview-molecule.png")
	app.modules.current_tab = 2
	await process_frame
	await RenderingServer.frame_post_draw
	root.get_texture().get_image().save_png(output + "preview-encyclopedia.png")
	print("PASS desktop renderer: native startup, lab workspace, container properties, molecule viewport, encyclopedia")
	app.free()
	quit()
