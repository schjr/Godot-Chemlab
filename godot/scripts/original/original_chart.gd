class_name OriginalChart
extends RefCounted
const X87 = preload("res://scripts/original/original_x87.gd")
static func _error(message: String) -> Dictionary:
	return {"ok":false,"resolved":false,"error":message}
static func _value(name: String, variables: Dictionary) -> Dictionary:
	if name == "数值0": return {"ok":true,"value":0.0}
	if not variables.has(name) or not str(variables[name]).is_valid_float(): return _error("Original chart variable lookup/StrToFloat input unresolved: " + name)
	var parsed := preload("res://scripts/original/original_program.gd").parse_number(str(variables[name]))
	if parsed.is_empty(): return _error("Original chart numeric parser input unsupported")
	return {"ok":true,"value":X87.stored_double(parsed)}
static func _trunc(pair: Array) -> int:
	var result := int(pair[0])
	if float(result) == float(pair[0]):
		if result > 0 and float(pair[1]) < 0.0: result -= 1
		elif result < 0 and float(pair[1]) > 0.0: result += 1
	return result
static func _point(x: float,y: float,metadata: Array) -> Dictionary:
	var px := X87.add(X87.add(X87.multiply(X87.divide([x,0.0],float(metadata[3])),30.0),float(metadata[5])),0.5)
	var py := X87.add(X87.add_pair(X87.add([240.0,0.0],-float(metadata[6])),X87.multiply(X87.multiply(X87.divide([y,0.0],float(metadata[4])),30.0),-1.0)),0.5)
	if px.is_empty() or py.is_empty() or px.size()>2 or py.size()>2: return _error("Original graph coordinate arithmetic unsupported")
	return {"ok":true,"point":[_trunc(px),_trunc(py)]}
static func state_from_record(record: Array) -> Dictionary:
	if record.size()!=55: return _error("Original chart requires55 stored fields")
	var previous: Array = []
	for i in range(5): previous.append([float(record[12+9*i]),float(record[15+9*i])])
	return {"ok":true,"metadata":record.duplicate(),"previous":previous}
static func sample(state: Dictionary, native_variable_texts: Dictionary) -> Dictionary:
	# Native48D6E0: call once per accepted physics tick AFTER binding/program work.
	if not state.has("metadata") or state.metadata.size()!=55 or not state.has("previous") or state.previous.size()!=5: return _error("Original chart state missing")
	var metadata: Array = state.metadata
	if int(metadata[0])==0: return {"ok":true,"resolved":true,"segments":[]}
	if float(metadata[3])==0.0 or float(metadata[4])==0.0: return _error("Original chart zero axis divisor")
	var next: Array = state.previous.duplicate(true)
	var segments: Array = []
	for i in range(5):
		var x_name := str(metadata[17+9*i]); var y_name := str(metadata[18+9*i])
		if x_name=="数值0" and y_name=="数值0": continue
		var x := _value(x_name,native_variable_texts); var y := _value(y_name,native_variable_texts)
		if not x.ok: return x
		if not y.ok: return y
		var start := _point(float(state.previous[i][0]),float(state.previous[i][1]),metadata)
		var end := _point(float(x.value),float(y.value),metadata)
		if not start.ok: return start
		if not end.ok: return end
		segments.append({"slot":i,"a":start.point,"b":end.point,"color_integer":int(metadata[10+9*i]),"width":2})
		next[i]=[float(x.value),float(y.value)]
	state.previous=next
	return {"ok":true,"resolved":true,"segments":segments,"native_entry":"0048D6E0","coordinate_size":[240,240]}

static func initialize(state: Dictionary, native_variable_texts: Dictionary) -> Dictionary:
	# Native48DB24 sanitizes missing names AFTER drawing the original axis grid.
	if not state.has("metadata") or state.metadata.size()!=55: return _error("Original chart metadata missing")
	var next: Dictionary = state.duplicate(true)
	for i in range(5):
		for index in [17+9*i,18+9*i]:
			if not native_variable_texts.has(str(next.metadata[index])): next.metadata[index]="数值0"
		var x_name := str(next.metadata[17+9*i]); var y_name := str(next.metadata[18+9*i])
		if x_name=="数值0" and y_name=="数值0": continue
		var x := _value(x_name,native_variable_texts); var y := _value(y_name,native_variable_texts)
		if not x.ok: return x
		if not y.ok: return y
		next.previous[i]=[float(x.value),float(y.value)]
	var grid := grid_commands(next.metadata)
	if not grid.ok: return grid
	state.merge(next,true)
	return {"ok":true,"resolved":true,"grid":grid,"native_entry":"0048DB24"}
static func _f32(value: float) -> float:
	return PackedFloat32Array([value])[0]
static func grid_commands(metadata: Array) -> Dictionary:
	# Native48C9A8; returned commands are original240pixel primitives, not pixels.
	if metadata.size()!=55: return _error("Original chart requires55 fields")
	var background := int(metadata[7]); var foreground := int(metadata[8])
	var grid_color := background & 0xff000000
	for shift in [0,8,16]: grid_color |= ((((background>>shift)&255)>>2)*3+(((foreground>>shift)&255)>>2))<<shift
	var ox := float(metadata[5]); var oy := 240.0-float(metadata[6])
	if absf(ox)>300000.0 or absf(oy)>300000.0: return _error("Original chart grid exceeds verification iteration bound")
	var lines: Array = []; var texts: Array = []
	for family in range(4):
		var k := 1
		while k < 10000:
			var coordinate: float
			if family==0: coordinate=oy-float(k*30)
			elif family==1: coordinate=float(k*30)+oy
			elif family==2: coordinate=ox-float(k*30)
			else: coordinate=float(k*30)+ox
			if coordinate>=0.0 and coordinate<=240.0:
				lines.append({"a":[0,int(coordinate)] if family<2 else [int(coordinate),0],"b":[240,int(coordinate)] if family<2 else [int(coordinate),240],"color_integer":grid_color,"width":1})
			if (family in [0,2] and coordinate<0.0) or (family in [1,3] and coordinate>240.0): break
			k+=1
	if oy>=0.0 and oy<=240.0: lines.append({"a":[0,int(oy)],"b":[240,int(oy)],"color_integer":foreground,"width":1})
	if ox>=0.0 and ox<=240.0: lines.append({"a":[int(ox),0],"b":[int(ox),240],"color_integer":foreground,"width":1})
	texts.append({"position":[int(ox+2.0),int(oy)],"text":"0","color_integer":foreground})
	for family in range(4):
		var k := 1
		while k < 10000:
			var coordinate := ox+float(k*30) if family==0 else ox-float(k*30) if family==1 else oy-float(k*30) if family==2 else float(k*30)+oy
			if (family in [0,3] and coordinate>240.0) or (family in [1,2] and coordinate<0.0): break
			if family==1 or (coordinate>0.0 and coordinate<240.0):
				var value := X87.multiply([float(k),0.0],float(metadata[3 if family<2 else 4]))
				if family in [1,3]: value=X87.multiply(value,-1.0)
				if value.is_empty(): return _error("Original chart label arithmetic unsupported")
				texts.append({"position":[int(coordinate-2.0),int(oy)] if family<2 else [int(ox+3.0),int(coordinate-8.0)],"text":preload("res://scripts/original/original_program.gd").format_number(X87.stored_double(value)),"color_integer":foreground})
			k+=1
	return {"ok":true,"resolved":true,"rectangle":[0,0,240,240],"background_color_integer":background,"lines":lines,"texts":texts,"font_source":"Form1+0x4b0 control+0x58 font","native_entry":"0048C9A8"}
