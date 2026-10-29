extends SceneTree
const Host = preload("res://scripts/original/original_gdi_host.gd")
var failures := 0
func check(condition: bool, message: String) -> void:
	if not condition:
		failures += 1
		push_error(message)
func _initialize() -> void:
	var bridge := Host.new()
	root.add_child(bridge)
	await process_frame
	var rejected: Dictionary = await bridge.render_ops(1, 1, [])
	check(not rejected.ok and str(rejected.error).contains("not been verified"), "Unverified native GDI construction was silently accepted")
	rejected = await bridge.render_ops(0, 1, [], [], true)
	check(not rejected.ok and str(rejected.error).contains("dimensions"), "Native host allowed invalid bitmap dimensions")
	rejected = await bridge.render_ops(2, 1, [], [0], true)
	check(not rejected.ok and str(rejected.error).contains("Initial native"), "Native host allowed malformed initial DIB payload")
	var empty: Dictionary = await bridge.render_solid([0xFF123456], 1, 1, {"ok": true, "draw_operations": []})
	check(empty.ok and empty.words == [0xFF123456], "Empty original solid pass changed preserved native words")
	rejected = await bridge.render_solid([0], 1, 1, {"ok": true, "draw_operations": [{"op": "flame"}]})
	check(not rejected.ok and str(rejected.error).contains("Unported"), "Unported rendering operation silently substituted")
	print("Original native GDI bridge guards: %s; construction provenance, bounded dimensions, exact DIB payload, empty native pass, unsupported operation rejection. Windows raster output not executed by this macOS test." % ["PASS" if failures == 0 else "FAIL"])
	quit(0 if failures == 0 else 1)
