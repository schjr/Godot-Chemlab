extends SceneTree
## Failed primitive responses must not masquerade as completed native calls.
const Frame=preload("res://scripts/original/original_particle_frame.gd")
const Vm=preload("res://scripts/original/original_particle_vm.gd")
var failures:Array=[]
func failed_reply_tests(address:int,reply:Variant)->void:
	var frame=Frame.new();frame.vm=Vm.new()
	var machine=frame.vm;var sp:=int(machine.registers.esp)
	machine.put(sp,0x12345678);machine.pc=address
	frame.presentation=func(_request:Dictionary)->Variant:return reply
	frame._presentation_helper(machine,address)
	if machine.error.is_empty() or machine.pc!=address or int(machine.registers.esp)!=sp or machine.integer(sp)!=0x12345678:failures.append("Malformed or blank-error provider response released helper at 0x%x"%address)
	frame.presentation=Callable()
func _initialize()->void:
	var cases:=0
	for address in [0x4e3e50,0x4e4158,0x4e4274,0x4e4744,0x4e44a8,0x5552de,0x5553e0,0x55542e]:
		var frame=Frame.new();frame.vm=Vm.new()
		var machine=frame.vm;var sp:=int(machine.registers.esp)
		var original:=PackedByteArray();original.resize(32)
		for index in 8:original.encode_u32(index*4,0x12340000+index)
		machine.write(sp,original);machine.pc=address
		machine.put(0x600000,0x11223344)
		frame.bitmap_meta={0x500000:{"name":"test_dib","width":1,"height":1,"words":[0x11223344],"rows":{0:0x600000}}}
		frame.presentation=func(_request:Dictionary)->Dictionary:
			return {"ok":false,"error":"deliberate unavailable primitive","bitmap_words":{"test_dib":[0xdeadbeef]}}
		frame._presentation_helper(machine,address)
		if machine.error!="deliberate unavailable primitive":failures.append("Failure lost at 0x%x"%address)
		if machine.pc!=address or int(machine.registers.esp)!=sp or machine.read(sp,32)!=original:failures.append("Failed call consumed stack/return state at 0x%x"%address)
		if frame.bitmap_meta[0x500000].words!=[0x11223344] or machine.integer(0x600000)!=0x11223344:failures.append("Failed call adopted pixel output at 0x%x"%address)
		# A successful provider still releases exactly this helper's arguments.
		machine.error=""
		frame.presentation=func(_request:Dictionary)->Dictionary:return {"ok":true}
		frame._presentation_helper(machine,address)
		var cleanup:=20 if address in [0x5552de,0x5553e0] else 16 if address==0x55542e else 8 if address==0x4e4744 else 4 if address==0x4e44a8 else 0
		if not machine.error.is_empty() or machine.pc!=0x12340000 or int(machine.registers.esp)!=sp+4+cleanup:failures.append("Successful helper return differs at 0x%x"%address)
		frame.presentation=Callable();cases+=1
		for reply in [{"ok":false,"error":""},null,{"ok":"yes"}]:
			failed_reply_tests(address,reply);cases+=1
	for reply in [{"ok":false,"error":"scanline refused","bitmap_words":{"test_dib":[0xdeadbeef]}},{"ok":false,"error":""},null,{"ok":"yes"}]:
		var frame=Frame.new();frame._init_vm({},Callable())
		var machine=frame.vm;var sp:=int(machine.registers.esp)
		machine.put(sp,0x12345678);machine.pc=0x4e95b0
		machine.registers.eax=0x500000;machine.registers.edx=0
		frame.bitmap_meta={0x500000:{"name":"test_dib","width":1,"height":1,"words":[],"rows":{}}}
		frame.presentation=func(_request:Dictionary)->Variant:return reply
		machine.helpers[0x4e95b0].call(machine)
		if machine.error.is_empty() or machine.pc!=0x4e95b0 or int(machine.registers.esp)!=sp or machine.integer(sp)!=0x12345678:failures.append("Failed scanline consumed native call state")
		if not frame.bitmap_meta[0x500000].words.is_empty() or not frame.bitmap_meta[0x500000].rows.is_empty():failures.append("Failed scanline adopted pixels/cache rows")
		machine.helpers.clear();frame.presentation=Callable();cases+=1
	print(JSON.stringify({"cases":cases,"failures":failures,"scope":"Primitive failure boundary and native stack cleanup; no raster parity claim"}))
	if failures.is_empty():print("PASS failed drawing calls preserve stack and reject pixel feedback; successful calls release exact arguments")
	quit(0 if failures.is_empty() else 1)
