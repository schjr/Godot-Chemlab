extends SceneTree
const Constructor=preload("res://scripts/original/original_canvas_constructor.gd")
var failures:Array=[]
var checks:=0
var next_address:=0x2010000
var poison:=0xa5
var blocks:Dictionary={}
var instance
var omit_allocation_bytes:=false
func check(ok:bool,label:String)->void:
	checks+=1
	if not ok:failures.append(label)
func allocate(size:int)->int:
	var address:=next_address;next_address=(address+size+15)&~15;blocks[address]=size;return address
func boundary(request:Dictionary)->Dictionary:
	match str(request.api):
		"GetMem":
			var size:int=int(request.size);var address:=allocate(size);var raw:=PackedByteArray();raw.resize(size);raw.fill(poison)
			return {"ok":true,"address":address} if omit_allocation_bytes else {"ok":true,"address":address,"raw_hex":raw.hex_encode()}
		"InitializeCriticalSection":
			var raw:=PackedByteArray();raw.resize(24);raw.fill(0xc3)
			return {"ok":true,"memory_writes":[{"address":request.address,"raw_hex":raw.hex_encode()}]}
		"EnterCriticalSection","LeaveCriticalSection":return {"ok":true}
		"ReallocMem":
			var size:int=int(request.size);var old:int=int(request.old_address);var raw:=PackedByteArray()
			if old!=0:
				var result:Dictionary=instance.read_bytes(old,mini(size,int(blocks[old])))
				if not result.ok:return result
				raw=result.bytes
			var copied:int=raw.size();raw.resize(size)
			for i in range(copied,size):raw[i]=poison
			return {"ok":true,"address":allocate(size),"raw_hex":raw.hex_encode(),"memory_writes":[]}
	return {"ok":false,"error":"Undeclared constructor API"}
func _initialize()->void:
	var fixture:Dictionary=JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_canvas_constructor.json"));var steps:=0
	for c in fixture.cases:
		poison=int(c.poison);next_address=0x2010000;blocks={};instance=Constructor.new()
		var result:Dictionary=instance.initialize(c.world,Callable(self,"boundary"))
		if not result.ok:failures.append([c.name,"init",result]);continue
		for step in c.steps:
			match str(step.operation):
				"registries":result=instance.construct_registries()
				"canvas_lists":result=instance.construct_canvas_list()
				"canvas":result=instance.construct(int(step.input),int(step.allocation_flag))
			if not result.ok:failures.append([c.name,step.operation,result]);break
			if step.operation=="canvas":
				check(result.canvas==int(step.canvas),str(c.name)+" original constructor return")
				var canvas:int=int(result.canvas);var lock_pointer:int=canvas+0x38
				for pair in [[12,0x4e4dcc],[16,0x4e4dec],[20,0x4e4e0c]]:
					var object_pointer:int=instance.vm.integer(canvas+int(pair[0]))
					check(instance.vm.integer(object_pointer+0x14)==lock_pointer,str(c.name)+" shared Canvas lock alias")
					check(instance.vm.integer(object_pointer+0x0c)==canvas and instance.vm.integer(object_pointer+8)==int(pair[1]),str(c.name)+" owner/event source binding")
			for segment in step.state.segments:
				var actual:Dictionary=instance.read_bytes(int(segment.address),str(segment.hex).hex_decode().size())
				check(actual.ok and actual.bytes.hex_encode()==segment.hex,str(c.name)+" complete native backing at "+str(segment.address))
			for address in step.state.globals:
				check(instance.vm.integer(str(address).trim_prefix("0x").hex_to_int())==int(step.state.globals[address]),str(c.name)+" source runtime global "+str(address))
			check(instance.vm.integer(0)==int(step.state.fs_head),str(c.name)+" native FS restoration")
			check(instance.events.size()==step.state.events.size(),str(c.name)+" primitive event count")
			for index in mini(instance.events.size(),step.state.events.size()):
				for key in step.state.events[index]:
					var value=step.state.events[index][key]
					if value is float:value=int(value)
					check(instance.events[index].get(key)==value,str(c.name)+" primitive order/arguments "+str(index)+" "+str(key))
			steps+=1
		instance.close()
	guard_checks(fixture.cases[0])
	print(JSON.stringify({"native_steps":steps,"checks":checks,"failures":failures}))
	if failures.is_empty() and steps==20:print("PASS original Canvas InitInstance constructors registry list lock event graph native references")
	quit(0 if failures.is_empty() and steps==20 else 1)

func guard_checks(c:Dictionary)->void:
	poison=int(c.poison);next_address=0x2010000;blocks={};instance=Constructor.new()
	check(instance.initialize(c.world,Callable(self,"boundary")).ok,"isolated missing-collection input initializes")
	check(instance.construct_registries().ok,"actual registry source constructors")
	var result:Dictionary=instance.construct(0x4e25e4)
	check(not result.ok and "Unobserved" in str(result.error),"unknown Canvas list cannot inherit PE BSS zero")
	instance.close()
	next_address=0x2010000;blocks={};omit_allocation_bytes=true;instance=Constructor.new()
	check(instance.initialize(c.world,Callable(self,"boundary")).ok,"unknown allocation backing input initializes")
	check(instance.construct_registries().ok and instance.construct_canvas_list().ok,"source InitInstance defines object bytes even without allocator fill")
	result=instance.construct(0x4e25e4)
	check(result.ok,"source writes construct from unobserved allocation backing")
	var pen:int=instance.vm.integer(int(result.canvas)+0x10)
	var node:int=instance.vm.integer(pen+0x10)
	result=instance.read_bytes(node+14,2)
	check(not result.ok and "Unobserved" in str(result.error),"registry unwritten header padding stays unknown")
	instance.close();omit_allocation_bytes=false
	next_address=0x2010000;blocks={};instance=Constructor.new()
	var absent:Dictionary=c.world.duplicate(true);absent.segments=[]
	check(instance.initialize(absent,Callable(self,"boundary")).ok,"font descriptor requires separate live observation")
	check(instance.construct_registries().ok and instance.construct_canvas_list().ok,"registry creation does not read descriptor")
	result=instance.construct(0x4e25e4)
	check(not result.ok and "Unobserved" in str(result.error),"unknown runtime font descriptor cannot use file defaults")
	instance.close()
