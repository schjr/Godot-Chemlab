extends SceneTree
const Interaction=preload("res://scripts/original/original_interaction.gd")
func compare_scene(actual:Dictionary,expected:Dictionary)->String:
	for i in actual.vessels.size():
		var a:Dictionary=actual.vessels[i];var b:Dictionary=expected.vessels[i]
		if int(a.position[0])!=int(b.position[0]) or int(a.position[1])!=int(b.position[1]):return "vessel%d position %s / %s"%[i,str(a.position),str(b.position)]
		if int(a.native_fields["0x84"])!=int(b.parent_type) or str(a.native_fields["0x80"])!=str(b.parent_name):return "vessel%d parent %s/%s expected %s/%s"%[i,str(a.native_fields["0x84"]),str(a.native_fields["0x80"]),str(b.parent_type),str(b.parent_name)]
		if int(a.native_bitmap_width)!=int(b.width) or int(a.native_bitmap_height)!=int(b.height):return "vessel%d size"%i
	for i in actual.connectors.size():
		for j in range(2,19):
			if str(actual.connectors[i].metadata[j])!=str(expected.connectors[i].metadata[j]):return "connector%d field%d"%[i,j]
	for i in actual.buttons.size():
		if Vector2(actual.buttons[i].position[0],actual.buttons[i].position[1])!=Vector2(expected.buttons[i].position[0],expected.buttons[i].position[1]) or Vector2(actual.buttons[i].size[0],actual.buttons[i].size[1])!=Vector2(expected.buttons[i].size[0],expected.buttons[i].size[1]):return "button%d bounds"%i
	return ""
func _initialize()->void:
	var fixture:Dictionary=JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_interaction.json"))
	var errors:Array=[];var resize_count:=0;var release_count:=0
	for c in fixture.resize_cases:
		var scene:Dictionary=c.scene.duplicate(true);var decision:Dictionary=c.decision.duplicate(true)
		var r:=Interaction.resize(scene,decision,Vector2(c.point[0],c.point[1]))
		if not r.ok:errors.append({"resize":resize_count,"error":r});resize_count+=1;continue
		var difference:=compare_scene(scene,c.expected.scene)
		if not difference.is_empty():errors.append({"resize":resize_count,"error":difference})
		if decision.dx!=c.expected.dx or decision.dy!=c.expected.dy:errors.append({"resize":resize_count,"error":"mutable drag offsets"})
		resize_count+=1
	for c in fixture.release_cases:
		var scene:Dictionary=c.scene.duplicate(true);var r:=Interaction.release(scene,{})
		if not r.ok:errors.append({"release":c.name,"error":r});release_count+=1;continue
		var difference:=compare_scene(scene,c.expected)
		if not difference.is_empty():errors.append({"release":c.name,"error":difference})
		release_count+=1
	print(JSON.stringify({"resize_cases":resize_count,"release_cases":release_count,"errors":errors.slice(0,15),"error_count":errors.size()}))
	if errors.is_empty():print("PASS original interaction")
	quit(0 if errors.is_empty() else 1)
