class_name OriginalSurfaceOutline
extends RefCounted
## Original 00473E6C: a hollow Rectangle around the liquid column.
## Caller0040F31A invokes this helper only when liquid height >1.
const X87 = preload("res://scripts/original/original_x87.gd")
const Actions = preload("res://scripts/original/original_apparatus_actions.gd")
const PEN_HEX := "4992244992244992fc3f"
const TYPES := [101,102,103,104,105,106,107,108,121,201,202,204,207,208,209,210,211,212]
static func compute(vessel: Dictionary) -> Dictionary:
	if not vessel.has("native_liquid_color"):
		return {"ok": false, "error": "Original surface outline needs liquid color +3CD0", "native_function": 0x473E6C}
	var color := int(vessel.native_liquid_color)
	var pen := 0
	for channel in range(3):
		# Preserve the complete extended80 coefficient before the final *6.
		var value: Array = X87.multiply(X87.multiply_pair([float((color >> (channel*8)) & 255), 0.0], X87.from_extended80_hex(PEN_HEX)), 6.0)
		if value.is_empty(): return {"ok": false, "error": "Original outline color arithmetic unsupported"}
		pen |= (Actions._trunc(value) & 255) << (channel*8)
	var result := {"ok": true, "native_function": 0x473E6C, "pen_color": pen, "brush_style": 1, "draw_operations": []}
	if int(vessel.get("type_id", -1)) not in TYPES: return result
	if not vessel.has("native_bitmap_width") or not vessel.has("native_bitmap_height") or not vessel.has("native_liquid_height"):
		return {"ok": false, "error": "Original outline requires actual bitmap dimensions and current liquid height"}
	var top: Array = X87.add([-float(vessel.native_liquid_height), 0.0], float(vessel.native_bitmap_height))
	if top.is_empty(): return {"ok": false, "error": "Original outline coordinate arithmetic unsupported"}
	result.draw_operations.append({"op": "rectangle", "left": 0, "top": Actions._trunc(top),
		"right": int(vessel.native_bitmap_width), "bottom": int(vessel.native_bitmap_height),
		"pen_color": pen, "brush_style": 1})
	return result
