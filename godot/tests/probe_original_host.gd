extends SceneTree
const Model = preload("res://scripts/lab_model.gd")
const Adapter = preload("res://scripts/experiment_adapter.gd")
func _init() -> void:
	var docs: Array = JSON.parse_string(FileAccess.get_file_as_string("res://data/examples.json"))
	for doc in docs:
		var m := Model.new()
		var state := Adapter.to_state(doc)
		var ok := m.from_state(state)
		print(doc.name," import=",ok," error=",m.last_error," programgroups=",state.program_groups.size()," code=",state.program.length())
		if not state.program.is_empty(): print(JSON.stringify(state.program_groups))
		if ok:
			m.start()
			m.step(0.02)
			print("native frame ",m.running," ",m.last_error)
	quit()
