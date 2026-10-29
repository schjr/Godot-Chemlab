extends SceneTree
const Bitmap=preload("res://scripts/original/original_bitmap_constructor.gd")
var current:Dictionary={}
var observed:=0
var omit_payload:=false
func boundary(request:Dictionary)->Dictionary:
	var expected:Dictionary=current.events[observed];observed+=1
	for key in request:assert(request[key]==expected[key],"Raw allocator operands differ")
	var response:={"ok":true,"address":expected.result}
	if int(expected.result)!=0:
		var block:Dictionary=current.allocations[observed-1]
		if not omit_payload:response["raw_hex"]=block.initial_hex
		response["memory_writes"]=[{"address":int(block.address)-16,"raw_hex":"cc".repeat(16)},{"address":int(block.address)+int(block.size),"raw_hex":"cc".repeat(16)}]
	return response
func world(c:Dictionary,fs_base:int=0)->Dictionary:
	var segments:Array=[]
	if int(c.input.flag) in [0,129]:
		var first:Dictionary=c.blocks[0]
		segments.append({"address":int(first.address)-16,"hex":"cc".repeat(16)+str(first.initial_hex)+"cc".repeat(16)})
	return {"source_sha256":Bitmap.SOURCE_SHA,"scope":"Explicit synthetic poisoned-allocation native-oracle world","globals":{"0x575604":0x5306b0,"0x574b54":int(c.input.monochrome)},"segments":segments,"thread":{"fs_base":fs_base,"exception_head":0xffffffff,"stack_base":0x9000000,"stack_size":0x100000,"stack_pointer":0x90ffe00,"stack_origin":"fresh_committed_pages"}}
func _initialize()->void:
	var fixture:Dictionary=JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_bitmap_constructor.json"))
	assert(fixture.source_sha256==Bitmap.SOURCE_SHA)
	var checks:=0
	for c in fixture.cases:
		current=c;observed=0;omit_payload=false
		var constructor:=Bitmap.new();assert(constructor.initialize(world(c),Callable(self,"boundary")).ok)
		var receiver:int=0x4e2af4 if int(c.input.flag)==1 else int(c.blocks[0].address)
		var result:Dictionary=constructor.construct(receiver,int(c.input.flag))
		assert(result.ok!=c.failed and result.runtime_error==c.failed,str(result))
		if not c.failed:assert(result.bitmap==int(c.constructor_return))
		for b in c.blocks:
			var raw:PackedByteArray=constructor.vm.byte_memory.read(int(b.address),int(b.size))
			assert(raw.hex_encode()==b.final_hex,"Constructor object bytes differ")
			assert(constructor.vm.byte_memory.read(int(b.address)-16,16).hex_encode()==b.prefix_hex)
			assert(constructor.vm.byte_memory.read(int(b.address)+int(b.size),16).hex_encode()==b.suffix_hex)
			checks+=int(b.size)+32
		assert(constructor.vm.integer(0)==int(c.fs_after),"Original FS frame restoration differs")
		assert(constructor.events.size()==c.events.size())
		for i in c.events.size():
			for key in c.events[i]:assert(constructor.events[i][key]==c.events[i][key],"Original constructor event differs")
		if not c.failed:
			var alias:Dictionary=c.alias_addref
			assert(constructor.vm.read(int(alias.shared),0x74).hex_encode()==alias.before_hex)
			assert(constructor.add_reference(int(alias.shared)).ok)
			assert(constructor.vm.read(int(alias.shared),0x74).hex_encode()==alias.after_hex,"Shared-image alias reference differs")
		constructor.close()
	# Actual InitInstance writes establish these bytes even with unknown raw
	# allocation payload; absence is not replaced by a synthetic zero struct.
	current=fixture.cases[0];observed=0;omit_payload=true
	var unknown:=Bitmap.new();assert(unknown.initialize(world(current,0x7000000),Callable(self,"boundary")).ok)
	var result:Dictionary=unknown.construct()
	assert(result.ok and unknown.vm.integer(0x7000000)==0xffffffff)
	for b in current.blocks:assert(unknown.vm.read(int(b.address),int(b.size)).hex_encode()==b.final_hex)
	assert(unknown.vm.integer(int(result.bitmap)+0x24)==0,"Constructor invented a Canvas")
	unknown.close()
	var missing:=Bitmap.new();var invalid:=world(current);invalid.globals.erase("0x575604")
	assert(not missing.initialize(invalid,Callable(self,"boundary")).ok)
	missing.close()
	print("Original TBitmap constructor PASS: %d native cases / %d object+guard byte comparisons; actual InitInstance/AddRef, poisoned and unknown allocation payloads"%[fixture.cases.size(),checks])
	quit()
