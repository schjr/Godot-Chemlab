extends SceneTree
const Selection=preload("res://scripts/original/original_heap_selection.gd")
var expected_events:Array=[]
var observed:=0
func boundary(request:Dictionary)->Dictionary:
	assert(observed<expected_events.size(),"Unexpected startup API call")
	var expected:Dictionary=expected_events[observed]
	for key in request:assert(request[key]==expected[key],"Startup API operands/order differ: "+str(request))
	observed+=1
	return {"ok":true,"result":expected.result}
func _initialize()->void:
	var fixture:Dictionary=JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_heap_selection.json"))
	assert(fixture.source_sha256==Selection.SOURCE_SHA)
	var checks:=0
	for c in fixture.cases:
		expected_events=c.events;observed=0
		var selector:=Selection.new()
		var result:Dictionary=selector.select_fresh(Callable(self,"boundary"),{"stack_base":0x9000000,"stack_size":0x100000,"stack_pointer":0x90ffe04,"stack_origin":"fresh_committed_pages","scope":"Explicit synthetic native-oracle stack mapping"},c.input.initial,int(c.input.argument))
		assert(result.fatal==c.fatal and result.ok!=c.fatal,str(result))
		assert(int(c.initial_globals["0x57598c"])==0x5343c8,"Fixture bypassed original lazy initial dispatch")
		if c.input.name=="absent":assert(result.compatible_with_existing_system_heap)
		if result.selection_mode==2:assert(not result.compatible_with_existing_system_heap)
		for key in c.final_globals:assert(result.globals[key]==int(c.final_globals[key]),"Native selection global differs %s: %s"%[key,c.input.name]);checks+=1
		assert(result.api_events.size()==c.events.size())
		for i in c.events.size():
			for key in c.events[i]:assert(result.api_events[i][key]==c.events[i][key],"Native startup API events differ")
		assert(observed==c.events.size()-(1 if c.fatal else 0))
		selector.close()
	var missing:=Selection.new()
	assert(not missing.select_fresh(Callable(),{}).ok)
	assert(not missing.select_fresh(Callable(self,"boundary"),{}).ok)
	missing.close()
	var unavailable:=Selection.new()
	var rejected:Dictionary=unavailable.select_fresh(func(_request:Dictionary)->Dictionary:return {"ok":false,"error":"Unobserved module result"},{"stack_base":0x9000000,"stack_size":0x10000,"stack_pointer":0x900ff04,"stack_origin":"fresh_committed_pages","scope":"Explicit missing-input test"})
	assert(not rejected.ok and rejected.error=="Unobserved module result")
	assert(int(rejected.globals["0x57598c"])==0x5343c8,"Missing host input guessed a selected fallback")
	unavailable.close()
	print("Original memory-manager selection PASS: %d native cases / %d exact global DWORDs; host module/export/AddRef outcomes explicit"%[fixture.cases.size(),checks])
	quit()
