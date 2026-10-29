class_name MoleculeView
extends Control
## Reconstructed interactive molecule renderer using recovered coordinates.
## Atom/bond indices are zero-based. The legacy OpenGL renderer is not reused.

signal atom_selected(index: int, atom: Dictionary)
signal bond_selected(index: int, bond: Dictionary)

const ELEMENT_COLORS := {
	"H": Color(0.92, 0.92, 0.92), "C": Color(0.35, 0.35, 0.35),
	"N": Color(0.18, 0.28, 0.94), "O": Color(0.95, 0.15, 0.12),
	"S": Color(0.98, 0.84, 0.10), "P": Color(1.0, 0.50, 0.12),
	"F": Color(0.35, 0.9, 0.35), "Cl": Color(0.12, 0.8, 0.18),
	"Br": Color(0.62, 0.2, 0.12), "I": Color(0.6, 0.18, 0.78),
	"Na": Color(0.6, 0.5, 0.95), "Mg": Color(0.4, 0.9, 0.4),
	"Ca": Color(0.4, 0.85, 0.4), "Fe": Color(0.8, 0.4, 0.15),
	"Cu": Color(0.7, 0.45, 0.25), "Zn": Color(0.55, 0.55, 0.7)
}
const VDW_RADII := {"H": 1.20, "C": 1.70, "N": 1.55, "O": 1.52,
	"S": 1.80, "P": 1.80, "F": 1.47, "Cl": 1.75, "Br": 1.85, "I": 1.98}

var molecule: Dictionary = {"atoms": [], "bonds": []}
var display_mode := "ball-stick"
var selected_atom := -1
var selected_bond := -1
var auto_rotate := false
var rotation_axis := Vector3.UP
var show_labels := false
var atom_colors: Dictionary = {}
var line_width := 0.045
var _viewport: SubViewport
var _root: Node3D
var _camera: Camera3D
var _environment: Environment
var _light: DirectionalLight3D
var _center := Vector3.ZERO
var _radius := 3.0
var _distance := 10.0
var _yaw := 0.0
var _pitch := 0.0
var _roll := 0.0
var _drag_origin := Vector2.ZERO
var _dragging := false
var _drag_distance := 0.0
var _positions: Array[Vector3] = []
var _atom_meshes: Array[MeshInstance3D] = []

func _ready() -> void:
	mouse_filter = Control.MOUSE_FILTER_STOP
	focus_mode = Control.FOCUS_ALL
	var container := SubViewportContainer.new()
	container.set_anchors_and_offsets_preset(Control.PRESET_FULL_RECT)
	container.stretch = true
	container.mouse_filter = Control.MOUSE_FILTER_IGNORE
	add_child(container)
	_viewport = SubViewport.new()
	_viewport.own_world_3d = true
	_viewport.size = Vector2i(maxi(int(size.x), 2), maxi(int(size.y), 2))
	_viewport.render_target_update_mode = SubViewport.UPDATE_WHEN_VISIBLE
	_viewport.msaa_3d = Viewport.MSAA_2X
	container.add_child(_viewport)
	_root = Node3D.new()
	_viewport.add_child(_root)
	_camera = Camera3D.new()
	_camera.fov = 42.0
	_camera.near = 0.01
	_camera.far = 10000.0
	_viewport.add_child(_camera)
	_camera.current = true
	_environment = Environment.new()
	_environment.background_mode = Environment.BG_COLOR
	_environment.background_color = Color(0.0, 0.0, 0.0)
	_environment.ambient_light_source = Environment.AMBIENT_SOURCE_COLOR
	_environment.ambient_light_color = Color.WHITE
	_environment.ambient_light_energy = 0.55
	var world_environment := WorldEnvironment.new()
	world_environment.environment = _environment
	_viewport.add_child(world_environment)
	_light = DirectionalLight3D.new()
	_light.rotation_degrees = Vector3(-35, -35, 0)
	_light.light_energy = 1.2
	_viewport.add_child(_light)
	_rebuild()
	reset_view()

func set_molecule(data: Dictionary) -> void:
	molecule = data.duplicate(true)
	selected_atom = -1
	selected_bond = -1
	if is_node_ready():
		_rebuild()
		reset_view()

func set_display_mode(mode: String) -> void:
	var aliases := {"ball_stick": "ball-stick", "space_fill": "space-fill",
		"proportion": "space-fill", "framework": "wireframe", "symbols": "labels"}
	display_mode = str(aliases.get(mode, mode))
	if display_mode not in ["ball-stick", "space-fill", "wireframe", "labels", "labels-3d"]:
		display_mode = "ball-stick"
	if is_node_ready():
		_rebuild()

func set_auto_rotate(enabled: bool, axis: Vector3 = Vector3.UP) -> void:
	auto_rotate = enabled
	rotation_axis = axis.normalized()

func set_rotation_axis(axis: String) -> void:
	rotation_axis = {"X": Vector3.RIGHT, "Y": Vector3.UP, "Z": Vector3.BACK}.get(axis.to_upper(), Vector3.UP)
	auto_rotate = true

func set_background_color(color: Color) -> void:
	if _environment:
		_environment.background_color = color

func set_lighting(ambient: Color, light_color: Color, direction: Vector3 = Vector3(-35, -35, 0)) -> void:
	if _environment:
		_environment.ambient_light_color = ambient
	if _light:
		_light.light_color = light_color
		_light.rotation_degrees = direction

func set_element_color(element: String, color: Color) -> void:
	atom_colors[element] = color
	if is_node_ready():
		_rebuild()

func set_labels_visible(visible_labels: bool) -> void:
	show_labels = visible_labels
	if is_node_ready():
		_rebuild()

func set_line_width(width: float) -> void:
	line_width = clampf(width, 0.008, 0.3)
	if is_node_ready():
		_rebuild()

func reset_view() -> void:
	_yaw = 0.0
	_pitch = 0.0
	_roll = 0.0
	_distance = maxf(_radius * 3.4, 4.0)
	auto_rotate = false
	_update_camera()

func zoom(factor: float) -> void:
	_distance = clampf(_distance * factor, maxf(_radius * 0.35, 0.8), maxf(_radius * 40.0, 100.0))
	_update_camera()

func get_image() -> Image:
	return _viewport.get_texture().get_image() if _viewport else Image.new()

func select_atom(index: int) -> void:
	selected_atom = index if index >= 0 and index < _positions.size() else -1
	selected_bond = -1
	_update_selection()
	if selected_atom >= 0:
		atom_selected.emit(selected_atom, molecule.get("atoms", [])[selected_atom])

func add_atom(atom: Dictionary) -> int:
	var atoms: Array = molecule.get("atoms", [])
	atoms.append(atom.duplicate(true))
	molecule["atoms"] = atoms
	if is_node_ready():
		_rebuild()
	return atoms.size() - 1

func set_atom_position(index: int, position: Vector3) -> bool:
	var atoms: Array = molecule.get("atoms", [])
	if index < 0 or index >= atoms.size():
		return false
	atoms[index]["position"] = [position.x, position.y, position.z]
	if is_node_ready():
		_rebuild()
	return true

func add_bond(a: int, b: int, order: int = 1) -> bool:
	var count: int = molecule.get("atoms", []).size()
	if a < 0 or b < 0 or a >= count or b >= count or a == b:
		return false
	var bonds: Array = molecule.get("bonds", [])
	for bond in bonds:
		if (int(bond.get("a", -1)) == a and int(bond.get("b", -1)) == b) or (int(bond.get("a", -1)) == b and int(bond.get("b", -1)) == a):
			return false
	bonds.append({"a": a, "b": b, "order": clampi(order, 1, 3)})
	molecule["bonds"] = bonds
	if is_node_ready():
		_rebuild()
	return true

func delete_atom(index: int) -> bool:
	var atoms: Array = molecule.get("atoms", [])
	if index < 0 or index >= atoms.size():
		return false
	atoms.remove_at(index)
	var new_bonds: Array = []
	for bond in molecule.get("bonds", []):
		var a := int(bond.get("a", -1))
		var b := int(bond.get("b", -1))
		if a == index or b == index:
			continue
		var remapped: Dictionary = bond.duplicate(true)
		remapped["a"] = a - 1 if a > index else a
		remapped["b"] = b - 1 if b > index else b
		new_bonds.append(remapped)
	molecule["bonds"] = new_bonds
	selected_atom = -1
	selected_bond = -1
	if is_node_ready():
		_rebuild()
	return true

func delete_bond(index: int) -> bool:
	var bonds: Array = molecule.get("bonds", [])
	if index < 0 or index >= bonds.size():
		return false
	bonds.remove_at(index)
	selected_bond = -1
	if is_node_ready():
		_rebuild()
	return true

func rotate_bond(index: int, angle_degrees: float) -> bool:
	## Rotate the component on the B side of a single bond. Ring bonds are refused.
	var bonds: Array = molecule.get("bonds", [])
	var atoms: Array = molecule.get("atoms", [])
	if index < 0 or index >= bonds.size() or int(bonds[index].get("order", 1)) != 1:
		return false
	var a := int(bonds[index].get("a", -1))
	var b := int(bonds[index].get("b", -1))
	if a < 0 or b < 0 or a >= atoms.size() or b >= atoms.size():
		return false
	var visited: Dictionary = {b: true}
	var pending: Array[int] = [b]
	while not pending.is_empty():
		var current: int = pending.pop_back()
		for i in range(bonds.size()):
			if i == index:
				continue
			var left := int(bonds[i].get("a", -1))
			var right := int(bonds[i].get("b", -1))
			var other := right if left == current else (left if right == current else -1)
			if other < 0 or other >= atoms.size() or visited.has(other):
				continue
			visited[other] = true
			pending.append(other)
	if visited.has(a):
		return false
	var pivot := _position(atoms[a])
	var axis := (_position(atoms[b]) - pivot).normalized()
	if axis.length_squared() < 0.5:
		return false
	for atom_index in visited:
		var point := pivot + (_position(atoms[atom_index]) - pivot).rotated(axis, deg_to_rad(angle_degrees))
		atoms[atom_index]["position"] = [point.x, point.y, point.z]
	if is_node_ready():
		_rebuild()
	return true

func _process(delta: float) -> void:
	if auto_rotate and _root:
		_yaw += rotation_axis.y * delta * 0.5
		_pitch += rotation_axis.x * delta * 0.5
		_roll += rotation_axis.z * delta * 0.5
		_update_camera()

func _gui_input(event: InputEvent) -> void:
	if event is InputEventMouseButton:
		if event.button_index == MOUSE_BUTTON_WHEEL_UP and event.pressed:
			zoom(0.88)
		elif event.button_index == MOUSE_BUTTON_WHEEL_DOWN and event.pressed:
			zoom(1.14)
		elif event.button_index == MOUSE_BUTTON_LEFT:
			if event.pressed:
				grab_focus()
				_drag_origin = event.position
				_drag_distance = 0.0
				_dragging = true
			else:
				_dragging = false
				if _drag_distance < 5.0:
					_pick(event.position)
		accept_event()
	elif event is InputEventMouseMotion and _dragging:
		_drag_distance += event.relative.length()
		_yaw += event.relative.x * 0.008
		_pitch += event.relative.y * 0.008
		_update_camera()
		accept_event()
	elif event is InputEventKey and event.pressed:
		match event.keycode:
			KEY_A: zoom(0.88)
			KEY_S: zoom(1.14)
			KEY_SPACE: auto_rotate = false
			KEY_LEFT: _yaw -= 0.12
			KEY_RIGHT: _yaw += 0.12
			KEY_UP: _pitch -= 0.12
			KEY_DOWN: _pitch += 0.12
			KEY_HOME: reset_view()
		_update_camera()
		accept_event()

func _update_camera() -> void:
	if not _camera:
		return
	_camera.position = Vector3(0, 0, _distance)
	_root.rotation = Vector3(_pitch, _yaw, _roll)

func _position(atom: Dictionary) -> Vector3:
	var value: Variant = atom.get("position", atom.get("pos", null))
	if value is Vector3:
		return value
	if value is Array and value.size() >= 3:
		return Vector3(float(value[0]), float(value[1]), float(value[2]))
	return Vector3(float(atom.get("x", 0)), float(atom.get("y", 0)), float(atom.get("z", 0)))

func _element(atom: Dictionary) -> String:
	return str(atom.get("element", atom.get("symbol", "C")))

func _color(element: String) -> Color:
	return atom_colors.get(element, ELEMENT_COLORS.get(element, Color(0.7, 0.6, 0.8)))

func _material(color: Color, unshaded: bool = false) -> StandardMaterial3D:
	var material := StandardMaterial3D.new()
	material.albedo_color = color
	material.roughness = 0.34
	if unshaded:
		material.shading_mode = BaseMaterial3D.SHADING_MODE_UNSHADED
	return material

func _atom_radius(element: String) -> float:
	if display_mode == "space-fill":
		return float(VDW_RADII.get(element, 1.7))
	if display_mode in ["wireframe", "labels", "labels-3d"]:
		return 0.055
	return 0.25 if element == "H" else 0.40

func _rebuild() -> void:
	for child in _root.get_children():
		child.free()
	_positions.clear()
	_atom_meshes.clear()
	var atoms: Array = molecule.get("atoms", [])
	_center = Vector3.ZERO
	for atom in atoms:
		var point := _position(atom)
		_positions.append(point)
		_center += point
	if not atoms.is_empty():
		_center /= atoms.size()
	_radius = 1.0
	for i in range(atoms.size()):
		_positions[i] -= _center
		_radius = maxf(_radius, _positions[i].length() + 1.8)
		var element := _element(atoms[i])
		var instance := MeshInstance3D.new()
		var sphere := SphereMesh.new()
		sphere.radius = _atom_radius(element)
		sphere.height = sphere.radius * 2
		sphere.radial_segments = 20
		sphere.rings = 12
		instance.mesh = sphere
		instance.material_override = _material(_color(element))
		instance.position = _positions[i]
		_root.add_child(instance)
		_atom_meshes.append(instance)
		if show_labels or display_mode in ["labels", "labels-3d"]:
			var label := Label3D.new()
			label.text = element
			label.font_size = 42
			label.pixel_size = 0.009
			label.modulate = _color(element).lightened(0.25)
			label.outline_size = 8
			label.position = _positions[i] + Vector3(0, 0.22, 0)
			label.billboard = BaseMaterial3D.BILLBOARD_DISABLED if display_mode == "labels-3d" else BaseMaterial3D.BILLBOARD_ENABLED
			_root.add_child(label)
	if display_mode != "space-fill":
		var bonds: Array = molecule.get("bonds", [])
		for bond_index in range(bonds.size()):
			var bond: Dictionary = bonds[bond_index]
			var a := int(bond.get("a", -1))
			var b := int(bond.get("b", -1))
			if a < 0 or b < 0 or a >= atoms.size() or b >= atoms.size() or a == b:
				continue
			var start := _positions[a]
			var finish := _positions[b]
			var direction := (finish - start).normalized()
			var side := direction.cross(Vector3.UP)
			if side.length_squared() < 0.01:
				side = direction.cross(Vector3.RIGHT)
			side = side.normalized()
			var order := clampi(int(bond.get("order", 1)), 1, 3)
			for strand in range(order):
				var offset := side * (float(strand) - float(order - 1) / 2.0) * 0.16
				var midpoint := (start + finish) / 2.0 + offset
				var thickness := line_width if display_mode != "ball-stick" else 0.09
				_cylinder(start + offset, midpoint, thickness, _color(_element(atoms[a])), bond_index)
				_cylinder(midpoint, finish + offset, thickness, _color(_element(atoms[b])), bond_index)
	_update_selection()

func _cylinder(start: Vector3, finish: Vector3, radius: float, color: Color, bond_index: int) -> void:
	var direction := finish - start
	if direction.length() < 0.00001:
		return
	var mesh := CylinderMesh.new()
	mesh.top_radius = radius
	mesh.bottom_radius = radius
	mesh.height = direction.length()
	mesh.radial_segments = 10
	var instance := MeshInstance3D.new()
	instance.mesh = mesh
	instance.material_override = _material(color, display_mode != "ball-stick")
	instance.set_meta("bond_index", bond_index)
	instance.set_meta("base_color", color)
	instance.position = (start + finish) / 2.0
	var y_axis := direction.normalized()
	var helper := Vector3.RIGHT if absf(y_axis.dot(Vector3.UP)) > 0.95 else Vector3.UP
	var x_axis := helper.cross(y_axis).normalized()
	instance.basis = Basis(x_axis, y_axis, x_axis.cross(y_axis))
	_root.add_child(instance)

func _update_selection() -> void:
	var atoms: Array = molecule.get("atoms", [])
	for i in range(_atom_meshes.size()):
		_atom_meshes[i].material_override = _material(Color.WHITE if i == selected_atom else _color(_element(atoms[i])))
		_atom_meshes[i].scale = Vector3.ONE * (1.17 if i == selected_atom else 1.0)
	for child in _root.get_children():
		if child is MeshInstance3D and child.has_meta("bond_index"):
			var color: Color = Color.WHITE if child.get_meta("bond_index") == selected_bond else child.get_meta("base_color")
			child.material_override = _material(color, display_mode != "ball-stick")

func _pick(point: Vector2) -> void:
	var origin := _camera.project_ray_origin(point)
	var ray := _camera.project_ray_normal(point)
	var nearest := INF
	var hit := -1
	var atoms: Array = molecule.get("atoms", [])
	for i in range(_positions.size()):
		var center := _root.to_global(_positions[i])
		var radius := maxf(_atom_radius(_element(atoms[i])), 0.2)
		var offset := origin - center
		var projection := offset.dot(ray)
		var discriminant := projection * projection - (offset.length_squared() - radius * radius)
		if discriminant >= 0:
			var distance := -projection - sqrt(discriminant)
			if distance > 0 and distance < nearest:
				nearest = distance
				hit = i
	select_atom(hit)
	if hit >= 0:
		return
	var best_distance := 10.0
	var bonds: Array = molecule.get("bonds", [])
	for i in range(bonds.size()):
		var a := int(bonds[i].get("a", -1))
		var b := int(bonds[i].get("b", -1))
		if a < 0 or b < 0 or a >= _positions.size() or b >= _positions.size():
			continue
		var start := _camera.unproject_position(_root.to_global(_positions[a]))
		var finish := _camera.unproject_position(_root.to_global(_positions[b]))
		var closest := Geometry2D.get_closest_point_to_segment(point, start, finish)
		var distance := closest.distance_to(point)
		if distance < best_distance:
			best_distance = distance
			selected_bond = i
	if selected_bond >= 0:
		_update_selection()
		bond_selected.emit(selected_bond, bonds[selected_bond])
