extends SceneTree
const Factory = preload("res://scripts/original/original_factory.gd")
var failures: int = 0
func check(value: bool, text: String) -> void:
	if not value: failures += 1; push_error(text)
func _initialize() -> void:
	var fixture: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_factory.json"))
	check(Factory.choices().size() == 33, "All 33 recovered finite apparatus palette choices must be supported")
	for original in fixture.cases:
		check(not original.has("error"), "Original metadata kernel must have completed: " + str(original.kind))
		var result: Dictionary = Factory.create(str(original.kind), Vector2(333, 222), 7, 0)
		check(result.ok, "Original factory must resolve: " + str(original.kind))
		if not result.ok: continue
		var v: Dictionary = result.vessel
		for offset in original.native_fields:
			check(v.native_fields[offset] == original.native_fields[offset], "Factory native field mismatch: %s / %s" % [original.kind, offset])
		check(v.native_sprite_width == int(original.sprite_size[0]) and v.native_sprite_height == int(original.sprite_size[1]), "Factory must preserve native bitmap dimensions")
		check(v.contents.is_empty() and v.native_reaction_records.is_empty(), "New original apparatus must contain no invented chemicals or equations")
		check(not v.has("native_solid_volume") and not v.has("native_species_volume_slots"), "Uninitialized original numeric caches must remain unknown")
		var moved: Dictionary = Factory.create(str(original.kind), Vector2(-10, 25), 15, 19)
		check(moved.ok and moved.vessel.label == "容器19" and moved.vessel.position == [-10, 25] and moved.next_native_label_counter == 20, "Counter and coordinate specialization must match original writes")
	check(not Factory.create("conduit", Vector2.ZERO, 1, 0).ok, "Separate connector pool must not become a fake chemical vessel")
	check(not Factory.create("sb100", Vector2.ZERO, 1).ok, "Missing original name counter must fail rather than derive it from ID")
	var wrapped: Dictionary = Factory.create("sb100", Vector2.ZERO, 1, 2147483647)
	check(wrapped.ok and wrapped.next_native_label_counter == -2147483648, "Native 32-bit counter increment must wrap as original machine code")
	check(Factory.create("gkp1000", Vector2.ZERO, 1, 0).vessel.native_texture_kind == "gkp_z", "Original large bottle choice must use its actual gkp_z bitmap")
	print("Original factory metadata checks: ", "PASS" if failures == 0 else "FAIL (%s)" % failures, " / ", fixture.cases.size(), " native kernels")
	quit(0 if failures == 0 else 1)
