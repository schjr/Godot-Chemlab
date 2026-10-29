extends SceneTree
const Selection=preload("res://scripts/original/original_selection.gd")
func _initialize() -> void:
	var corpus: Dictionary=JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_selection.json"))
	var failures: Array=[];var unresolved: Array=[];var tested:=0
	for c in corpus.cases:
		for s in c.samples:
			var result:=Selection.press(c.scene,Vector2(s.point[0],s.point[1]))
			if not result.ok:unresolved.append([c.name,s.point,result.error]);continue
			for key in ["type","index","command","dx","dy"]:
				if int(result[key])!=int(s.expected[key]):failures.append([c.name,s.point,key,result[key],s.expected[key]])
			tested+=1
	print(JSON.stringify({"decisions_tested":tested,"mismatches":failures,"unresolved_count":unresolved.size(),"unresolved_first":unresolved.slice(0,4)}))
	if not (not failures.is_empty() or not unresolved.is_empty()): print("PASS test_original_selection")
	quit(1 if not failures.is_empty() or not unresolved.is_empty() else 0)
