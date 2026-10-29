extends SceneTree
const Lazy=preload("res://scripts/original/original_bitmap_canvas.gd")
var current:Dictionary={}
var module
var next_block:=0
func boundary(request:Dictionary)->Dictionary:
	match str(request.api):
		"GetMem":
			var n:int=int(request.size);var address:=next_block;next_block=(address+n+15)&~15
			return {"ok":true,"address":address,"raw_hex":("%02x"%int(current.poison)).repeat(n)}
		"ReallocMem":
			var n:int=int(request.size);var address:=next_block;next_block=(address+n+15)&~15
			var raw:=PackedByteArray();raw.resize(n);raw.fill(int(current.poison))
			if int(request.old_address)!=0:
				var old:PackedByteArray=module.vm.byte_memory.read(int(request.old_address),mini(n,16))
				for i in old.size():raw[i]=old[i]
			return {"ok":true,"address":address,"raw_hex":raw.hex_encode()}
		"InitializeCriticalSection":return {"ok":true,"memory_writes":[{"address":request.address,"raw_hex":"c3".repeat(24)}]}
		"EnterCriticalSection","LeaveCriticalSection":return {"ok":true}
	return {"ok":false,"error":"No primitive result is supplied for "+str(request.api)}
func _initialize()->void:
	var fixture:Dictionary=JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_bitmap_canvas.json"))
	assert(fixture.source_sha256==Lazy.SOURCE_SHA)
	var bytes_checked:=0;var aliases:=0;var frontiers:=0
	for c in fixture.cases:
		current=c;next_block=int(c.initial_next_block);module=Lazy.new()
		assert(module.initialize(c.world,Callable(self,"boundary")).ok)
		var first_canvas:=0;var first_events:=0
		for step in c.steps:
			var result:Dictionary=module.get_canvas(int(c.bitmap)) if step.op=="get_canvas" else module.handle_prefix(first_canvas)
			if step.op=="get_canvas":
				assert(result.ok and result.canvas==int(step.value),str(result))
				if first_canvas==0:first_canvas=int(result.canvas);first_events=module.events.size()
				else:assert(result.canvas==first_canvas and module.events.size()==first_events,"Repeated GetCanvas allocated or notified");aliases+=1
				assert(module.vm.integer(first_canvas)==0x4e80d0)
				assert(module.vm.integer(first_canvas+0x58)==int(c.bitmap))
				assert(module.vm.integer(first_canvas+0x2c)==int(c.bitmap) and module.vm.integer(first_canvas+0x34)==int(c.bitmap))
				assert(module.vm.integer(first_canvas+0x30)==0x4e9130)
				assert(module.vm.integer(first_canvas+0x28)==module.vm.integer(0x4e2af4+0x10))
			else:
				assert(not result.ok,str(result))
				for key in step.frontier:assert(result.frontier.get(key)==step.frontier[key],"Native Handle frontier differs: "+str(result))
				assert(module.vm.integer(first_canvas+4)==0,"Missing DC result was fabricated")
				frontiers+=1
			for span in step.state.segments:
				var expected:=str(span.hex).hex_decode();var actual:PackedByteArray=module.vm.byte_memory.read(int(span.address),expected.size())
				assert(actual==expected,"Native lazy Canvas object/list/registry bytes differ")
				bytes_checked+=expected.size()
			assert(module.vm.integer(0)==int(step.state.fs_head),"Native FS prefix differs")
			assert(module.events.size()==step.state.events.size())
			for i in step.state.events.size():
				for key in step.state.events[i]:assert(module.events[i][key]==step.state.events[i][key],"Native lazy Canvas API order/operands differ")
		module.close()
	print("Original lazy TBitmapCanvas PASS: %d native graphs, %d aliases, %d explicit Handle frontiers, %d exact object/list/registry bytes; no fabricated DC"%[fixture.cases.size(),aliases,frontiers,bytes_checked])
	quit()
