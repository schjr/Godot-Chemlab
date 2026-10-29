extends SceneTree
const Chart = preload("res://scripts/original/original_chart.gd")
func _initialize() -> void:
	var fixture: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_chart.json"))
	var mismatches: Array = []
	for c in fixture.cases:
		var state := Chart.state_from_record(c.record)
		assert(state.ok)
		if not c.get("initialize_only",false):
			var output := Chart.sample(state,c.variables)
			assert(output.ok,str(output.get("error","")))
			if output.segments.size()!=c.lines.size(): mismatches.append([c.name,"count"])
			else:
				for i in range(c.lines.size()):
					for j in range(2):
						var point: Array = output.segments[i]["a" if j==0 else "b"]
						for axis in range(2):
							if int(point[axis])!=int(c.lines[i][j][axis]): mismatches.append([c.name,i,j,axis,point,c.lines[i][j]])
			for i in range(5):
				for j in range(2):
					if PackedFloat64Array([float(state.previous[i][j])]).to_byte_array().hex_encode()!=c.after_previous_bits[i][j]: mismatches.append([c.name,"previous",i,j])
		if c.has("initialize"):
			var reset := Chart.state_from_record(c.record)
			var initialized := Chart.initialize(reset,c.variables)
			assert(initialized.ok,str(initialized.get("error","")))
			var grid: Dictionary = initialized.grid
			for i in range(5):
				if reset.metadata[17+9*i]!=c.initialize.after_names[i][0] or reset.metadata[18+9*i]!=c.initialize.after_names[i][1]: mismatches.append([c.name,"sanitize",i])
			if grid.lines.size()!=c.initialize.lines.size(): mismatches.append([c.name,"grid linecount"])
			else:
				for i in range(grid.lines.size()):
					for j in range(2):
						for axis in range(2):
							if int(grid.lines[i]["a" if j==0 else "b"][axis])!=int(c.initialize.lines[i][j][axis]): mismatches.append([c.name,"grid",i,j,axis])
			if grid.texts.size()!=c.initialize.texts.size(): mismatches.append([c.name,"textcount"])
			else:
				for i in range(grid.texts.size()):
					if str(grid.texts[i].text)!=str(c.initialize.texts[i][2]) or int(grid.texts[i].position[0])!=int(c.initialize.texts[i][0]) or int(grid.texts[i].position[1])!=int(c.initialize.texts[i][1]): mismatches.append([c.name,"text",i,grid.texts[i],c.initialize.texts[i]])
			for i in range(5):
				for j in range(2):
					if PackedFloat64Array([float(reset.previous[i][j])]).to_byte_array().hex_encode()!=c.initialize.after_previous_bits[i][j]: mismatches.append([c.name,"initialize previous",i,j])
	print(JSON.stringify({"native_chart_cases":fixture.cases.size(),"mismatches":mismatches}))
	if not (not mismatches.is_empty()): print("PASS test_original_chart")
	quit(1 if not mismatches.is_empty() else 0)
