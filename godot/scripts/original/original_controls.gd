class_name OriginalControls
extends RefCounted
## Original Image1MouseDown/MouseUp helper rectangles. Strict inequalities.
## MouseUp itself writes the command; it does not require a matching down latch.
static func rectangles(v: Dictionary) -> Array:
	if not v.has("native_bitmap_width") or not v.has("native_bitmap_height"): return []
	var half_w := int(int(v.native_bitmap_width)/2)
	var half_h := int(int(v.native_bitmap_height)/2)
	var x := int(v.position[0])+half_w
	var y := int(v.position[1])
	var entries: Array = []
	match int(v.type_id):
		204:
			entries = [[1,y-half_h,y-half_h+20,"吸取"],[2,y-half_h+23,y-half_h+43,"点滴"]]
		207,208:
			entries = [[1,y+half_h-70,y+half_h-50,"打开"],[2,y+half_h-47,y+half_h-27,"关闭"],[3,y+half_h-24,y+half_h-4,"点滴"]]
		211:
			entries = [[1,y-half_h,y-half_h+20,"打开"],[2,y-half_h+23,y-half_h+43,"关闭"],[3,y-half_h+46,y-half_h+66,"点滴"]]
	var result: Array = []
	for entry in entries:
		result.append({"command":entry[0],"left":x+10,"right":x+45,"top":entry[1],"bottom":entry[2],"caption":entry[3]})
	return result

static func command_at(v: Dictionary, point: Vector2) -> int:
	# Native event parameters are integers, and boundary points are excluded.
	var x := int(point.x); var y := int(point.y)
	for r in rectangles(v):
		if r.left < x and x < r.right and r.top < y and y < r.bottom: return int(r.command)
	return 0
