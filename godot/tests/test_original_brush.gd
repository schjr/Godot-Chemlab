extends SceneTree
const Brush=preload("res://scripts/original/original_brush.gd")
var failures:Array=[]
var checks:=0
var next_address:=0x2010000
var outcomes:Dictionary={}
var rejected_api:=""
func boundary(request:Dictionary)->Dictionary:
	if str(request.api)==rejected_api:return {"ok":false,"error":"diagnostic unavailable "+rejected_api}
	match str(request.api):
		"EnterCriticalSection","LeaveCriticalSection":return {"ok":true}
		"GetMem":
			var address:int=next_address;next_address=(address+int(request.size)+15)&~15
			var raw:=PackedByteArray();raw.resize(int(request.size));raw.fill(0xa5)
			return {"ok":true,"address":address,"raw_hex":raw.hex_encode()}
		"FreeMem":return {"ok":true,"memory_writes":[]}
		"DeleteObject":return {"ok":true,"result":int(outcomes.delete)}
		"SelectObject":return {"ok":true,"result":0x11220000}
		"CreateBrushIndirect":return {"ok":true,"result":int(outcomes.create)}
		"GetSysColor":return {"ok":true,"result":0x224466}
		"event":return {"ok":true}
	return {"ok":false,"error":"Undeclared diagnostic API"}
func check(ok:bool,label:String)->void:
	checks+=1
	if not ok:failures.append(label)
func _initialize()->void:
	var fixture:Dictionary=JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_brush.json"))
	var steps:=0
	for test_case in fixture.cases:
		next_address=0x2010000;outcomes=test_case.api_outcomes
		var brush=Brush.new();var initialized:Dictionary=brush.initialize(test_case.world,Callable(self,"boundary"))
		if not initialized.ok:failures.append([test_case.name,"init",initialized]);brush.close();continue
		for step in test_case.steps:
			var result:Dictionary
			match str(step.operation.op):
				"color":result=brush.set_color(0x2000100,int(step.operation.value))
				"style":result=brush.set_style(0x2000100,int(step.operation.value))
				"handle":result=brush.get_handle(0x2000100)
			if not result.ok:failures.append([test_case.name,step.operation,result]);break
			check(result.value==int(step.value),str(test_case.name)+" source return")
			for segment in step.state.segments:
				var actual:Dictionary=brush.read_bytes(int(segment.address),str(segment.hex).hex_decode().size())
				check(actual.ok and actual.bytes.hex_encode()==segment.hex,str(test_case.name)+" complete graph/old/new node bytes")
			check(brush.vm.integer(0)==int(step.state.fs_head),str(test_case.name)+" original finally FS restoration")
			var ordered:Array=[];var pointer:int=brush.vm.integer(0x2000004)
			while pointer!=0 and ordered.size()<100:ordered.append(pointer);pointer=brush.vm.integer(pointer)
			var expected:Array=[]
			for address in step.state.ordered_nodes:expected.append(int(address))
			check(ordered==expected,str(test_case.name)+" original registry order")
			check(brush.events.size()==step.state.events.size(),str(test_case.name)+" boundary count")
			for index in mini(brush.events.size(),step.state.events.size()):
				for key in step.state.events[index]:
					var value=step.state.events[index][key]
					if value is float:value=int(value)
					check(brush.events[index].get(key)==value,str(test_case.name)+" source API/event order "+str(index)+" "+str(key))
			steps+=1
		brush.close()
	guard_checks(fixture)
	print(JSON.stringify({"native_steps":steps,"checks":checks,"failures":failures}))
	if failures.is_empty() and steps==47:print("PASS original TBrush registry arithmetic finally events and lazy handle native references")
	quit(0 if failures.is_empty() and steps==47 else 1)

func guard_checks(fixture:Dictionary)->void:
	var first:Dictionary=fixture.cases[0]
	var absent:Dictionary=first.world.duplicate(true);absent.globals.erase("0x59a9e8")
	var brush=Brush.new()
	check(not brush.initialize(absent,Callable(self,"boundary")).ok,"unknown shared registry cannot inherit image BSS")
	brush.close()
	var bitmap:Dictionary=fixture.cases[10].world.duplicate(true)
	for segment in bitmap.segments:
		if int(segment.address)==0x2001000:
			var raw:String=str(segment.hex);var bytes:=raw.hex_decode();bytes.encode_u32(24,0x2005000);segment.hex=bytes.hex_encode()
	brush=Brush.new();outcomes=fixture.cases[10].api_outcomes
	check(brush.initialize(bitmap,Callable(self,"boundary")).ok,"bitmap descriptor explicit input initializes")
	var result:Dictionary=brush.get_handle(0x2000100)

	check(not result.ok and str(result.error)=="Read outside mapped original memory at0x2005000","missing bitmap virtual state remains explicit")
	brush.close()
	var selected:Dictionary=fixture.cases[1].world.duplicate(true);selected.globals.erase("0x59a9a4")
	brush=Brush.new();outcomes=fixture.cases[1].api_outcomes
	check(brush.initialize(selected,Callable(self,"boundary")).ok,"unobserved stock brush remains unknown")
	result=brush.set_color(0x2000100,0xabcdef)
	check(not result.ok and "Unobserved" in str(result.error),"selected Canvas requires observed stock brush")
	brush.close()
	brush=Brush.new();rejected_api="EnterCriticalSection"
	check(brush.initialize(first.world,Callable(self,"boundary")).ok,"lock graph input initializes")
	result=brush.set_color(0x2000100,0xabcdef)
	check(not result.ok and "unavailable EnterCriticalSection" in str(result.error),"missing lock provider stops retained setter")
	brush.close();rejected_api=""
