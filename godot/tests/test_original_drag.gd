extends SceneTree
const Selection=preload("res://scripts/original/original_selection.gd")
func _initialize()->void:
	var fixture:Dictionary=JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_drag.json"))
	var mismatches:Array=[]
	for c in fixture.cases:
		var scene:Dictionary=c.scene.duplicate(true);var v:Dictionary=scene.vessels[int(c.index)]
		var decision:Dictionary={"type":int(v.type_id),"index":int(c.index),"command":0,"dx":0,"dy":0}
		var result:=Selection.drag(scene,decision,Vector2(v.position[0]+7,v.position[1]+9))
		if not result.ok:mismatches.append([c.name,c.index,result.error]);continue
		for i in range(scene.vessels.size()):
			for axis in range(2):
				if int(scene.vessels[i].position[axis])!=int(c.expected_positions[i][axis]):mismatches.append([c.name,c.index,"vessel",i,axis])
		for i in range(scene.connectors.size()):
			for j in range(6):
				if int(scene.connectors[i].metadata[[2,3,4,5,13,16][j]])!=int(c.expected_connector_endpoints[i][j]):mismatches.append([c.name,c.index,"connector",i,j,scene.connectors[i].metadata[[2,3,4,5,13,16][j]],c.expected_connector_endpoints[i][j]])
	print(JSON.stringify({"native_drag_cases":fixture.cases.size(),"mismatches":mismatches}))
	if mismatches.is_empty():print("PASS original attachment/conduit drag helpers")
	quit(1 if not mismatches.is_empty() else 0)
