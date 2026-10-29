extends SceneTree
## Run: Godot --headless --path godot --script res://tests/test_molecule.gd
const Viewer = preload("res://scripts/molecule_view.gd")

func _initialize() -> void:
	call_deferred("_run")

func _run() -> void:
	var viewer = Viewer.new()
	viewer.size = Vector2(800, 500)
	root.add_child(viewer)
	var water := {
		"atoms": [{"element": "O", "position": [0, 0, 0]},
			{"element": "H", "position": [0.96, 0, 0]},
			{"element": "H", "position": [-0.3, 0.9, 0]}],
		"bonds": [{"a": 0, "b": 1, "order": 1}, {"a": 0, "b": 2, "order": 1}]
	}
	viewer.set_molecule(water)
	await process_frame
	assert(viewer._positions.size() == 3)
	assert(is_equal_approx(viewer._positions[0].distance_to(viewer._positions[1]), 0.96), "Imported distances must be preserved")
	assert(viewer._positions[0].is_equal_approx(-viewer._center))
	for mode in ["ball-stick", "space-fill", "wireframe", "labels", "labels-3d"]:
		viewer.set_display_mode(mode)
		assert(viewer._atom_meshes.size() == 3)
		var bond_halves := 0
		var labels := 0
		for child in viewer._root.get_children():
			if child.has_meta("bond_index"):
				bond_halves += 1
			if child is Label3D:
				labels += 1
		assert(bond_halves == (0 if mode == "space-fill" else 4), "Space-fill hides bonds; other modes preserve topology")
		assert(labels == (3 if mode in ["labels", "labels-3d"] else 0))
		await process_frame
	viewer.set_display_mode("ball-stick")
	viewer.select_atom(0)
	assert(viewer.selected_atom == 0)
	assert(viewer._atom_meshes[0].scale.x > 1.0)
	viewer.set_auto_rotate(true, Vector3.UP)
	viewer._process(1.0)
	assert(viewer._yaw > 0.0)
	var distance: float = viewer._distance
	viewer.zoom(0.88)
	assert(viewer._distance < distance)
	viewer.reset_view()
	assert(not viewer.auto_rotate and viewer._yaw == 0.0 and viewer._pitch == 0.0)
	assert(viewer._root.rotation.is_equal_approx(Vector3.ZERO))
	assert(viewer.add_atom({"element": "C", "position": [2.5, 0, 0]}) == 3)
	assert(viewer.add_bond(1, 3, 2))
	assert(not viewer.add_bond(3, 1))
	assert(not viewer.add_bond(4, 0))
	assert(viewer.set_atom_position(3, Vector3(2.6, 0, 0)))
	assert(viewer.delete_atom(1))
	assert(viewer.molecule["atoms"].size() == 3)
	assert(viewer.molecule["bonds"].size() == 1)
	assert(viewer.molecule["bonds"][0]["b"] == 1, "Deleting atoms remaps surviving bonds")
	assert(not viewer.delete_atom(-1))
	viewer.set_molecule({"atoms": [{"element": "C", "position": [0, 0, 0]}, {"element": "C", "position": [1.5, 0, 0]}, {"element": "H", "position": [1.5, 1, 0]}], "bonds": [{"a": 0, "b": 1, "order": 1}, {"a": 1, "b": 2, "order": 1}]})
	assert(viewer.rotate_bond(0, 90))
	var rotated: Array = viewer.molecule["atoms"][2]["position"]
	assert(is_equal_approx(float(rotated[1]), 0.0) and is_equal_approx(absf(float(rotated[2])), 1.0), "Single-bond rotation moves its connected component")
	viewer.add_bond(0, 2)
	assert(not viewer.rotate_bond(0, 90), "Ring bond rotations must be refused")
	viewer.set_molecule({"atoms": [{"element": "O", "position": [0, 0, 0]}], "bonds": [{"a": 0, "b": 999}, {"a": -1, "b": 0}]})
	assert(viewer._atom_meshes.size() == 1)
	viewer.set_molecule({"atoms": [], "bonds": []})
	assert(viewer._root.get_child_count() == 0)
	viewer.free()
	print("PASS molecule renderer: geometry, five modes, selection, orbit/zoom/reset, graph edits, single-bond rotation, invalid indices, empty model")
	quit()
