extends SceneTree
const Pen=preload("res://scripts/original/original_pen.gd")
var failures:Array=[]
var checks:=0
var next_address:=0x2010000
var outcomes:Dictionary={}
func boundary(request:Dictionary)->Dictionary:
	match str(request.api):
		"EnterCriticalSection","LeaveCriticalSection":return {"ok":true}
		"GetMem":
			var address:int=next_address;next_address=(address+int(request.size)+15)&~15
			var raw:=PackedByteArray();raw.resize(int(request.size));raw.fill(0xa5)
			return {"ok":true,"address":address,"raw_hex":raw.hex_encode()}
		"FreeMem":return {"ok":true,"memory_writes":[]}
		"DeleteObject":return {"ok":true,"result":int(outcomes.delete)}
		"SelectObject":return {"ok":true,"result":0x11220000}
		"CreatePenIndirect":return {"ok":true,"result":int(outcomes.create)}
		"GetSysColor":return {"ok":true,"result":0x224466}
		"event":return {"ok":true}
	return {"ok":false,"error":"Undeclared diagnostic API"}
func check(ok:bool,label:String)->void:
	checks+=1
	if not ok:failures.append(label)
func _initialize()->void:
	var fixture:Dictionary=JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_pen.json"))
	var steps:=0
	for test_case in fixture.cases:
		next_address=0x2010000;outcomes=test_case.api_outcomes
		var pen=Pen.new();var initialized:Dictionary=pen.initialize(test_case.world,Callable(self,"boundary"))
		if not initialized.ok:failures.append([test_case.name,"init",initialized]);pen.close();continue
		for step in test_case.steps:
			var result:Dictionary=pen.set_color(0x2000100,int(step.operation.color)) if step.operation.op=="color" else pen.get_handle(0x2000100)
			if not result.ok:failures.append([test_case.name,step.operation,result]);break
			check(result.value==int(step.value),str(test_case.name)+" source return")
			for segment in step.state.segments:
				var actual:Dictionary=pen.read_bytes(int(segment.address),str(segment.hex).hex_decode().size())
				check(actual.ok and actual.bytes.hex_encode()==segment.hex,str(test_case.name)+" complete graph/old/new node bytes")
			check(pen.vm.integer(0)==int(step.state.fs_head),str(test_case.name)+" original finally FS restoration")
			var ordered:Array=[];var pointer:int=pen.vm.integer(0x2000004)
			while pointer!=0 and ordered.size()<100:ordered.append(pointer);pointer=pen.vm.integer(pointer)
			var expected:Array=[]
			for address in step.state.ordered_nodes:expected.append(int(address))
			check(ordered==expected,str(test_case.name)+" original registry order")
			check(pen.events.size()==step.state.events.size(),str(test_case.name)+" boundary count")
			for index in mini(pen.events.size(),step.state.events.size()):
				for key in step.state.events[index]:
					var value=step.state.events[index][key]
					if value is float:value=int(value)
					check(pen.events[index].get(key)==value,str(test_case.name)+" source API/event order "+str(index)+" "+str(key))
			steps+=1
		pen.close()
	print(JSON.stringify({"native_steps":steps,"checks":checks,"failures":failures}))
	if failures.is_empty() and steps==25:print("PASS original TPen registry arithmetic finally events and lazy handle native references")
	quit(0 if failures.is_empty() and steps==25 else 1)
