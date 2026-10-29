extends SceneTree
const Frame=preload("res://scripts/original/original_particle_frame.gd")
const Live=preload("res://scripts/original/original_live_particles.gd")
const Vm=preload("res://scripts/original/original_particle_vm.gd")
var failures:Array=[]
func execute_case(fast:bool,name:String,w:int,h:int,run:int,bg:int,previous:int,factor:float,mode:String="")->Dictionary:
	var frame=Frame.new();frame.current_context={"production_pixel_loop":fast};frame._init_vm({},Callable())
	var vm=frame.vm;var stack:=PackedByteArray();stack.resize(0x10000);stack.fill(0x55)
	if mode!="sparse":vm.write(Vm.STACK,stack)
	var pool:=Live.create_solid([0,0,w,h]);pool.background=bg;pool.previous_background=previous
	pool.primary_words=[];pool.retained_words=[]
	for index in w*h:
		pool.primary_words.append(0x332211 if index%3==0 else (index*0x112353)&0xffffff)
		var old_background:int=((previous>>16)&255)|(previous&0xff00)|((previous&255)<<16)
		pool.retained_words.append(0xa5000000|(old_background if index%3==0 else (index*0x789451)&0xffffff))
	pool.primary_words[(h-1)*w+w-2]=0x332211
	var pointer:int=frame._pool(pool,true,0)
	if mode=="alias":vm.put(pointer+0x32d68+4,vm.integer(pointer+0x339e8+4))
	elif mode=="unknown":vm.put(pointer+0x339e8+4,0x6100000)
	vm.put(0x57a6f8,run);vm.registers.eax=pointer;vm.registers.edx=0x12345678
	vm.write(int(vm.registers.esp),PackedFloat64Array([factor]).to_byte_array())
	frame.presentation=func(_request:Dictionary)->Dictionary:return {"ok":true}
	var program:Dictionary=frame.data.functions[name]
	var result:Dictionary=vm.execute({"instructions":program.instructions+frame.programs,"end":program.end},int(program.entry))
	vm.helpers.clear();frame.presentation=Callable()
	return {"frame":frame,"vm":vm,"result":result}
func _initialize()->void:
	var cases:=0
	for name in ["solid_pixels","solid_fade"]:
		for settings in [[3,3,1,0x112233,0x334455,0.123456789012345,""],[5,4,1,0x112233,0x112233,0.9999999999999999,""],[7,5,0,0x112233,0x334455,0.0,""],[4,2,1,0x112233,0,1.0,""],[4,4,1,0xffffff,0x123456,0.0,""],[4,4,1,0x112233,0,1.5,""],[4,4,1,0x112233,0,-0.25,""],[4,4,1,0x112233,0,1000001.0,""],[4,4,1,0x112233,0,0.5,"alias"],[4,4,1,0x112233,0,0.5,"unknown"],[5,4,1,0x112233,0x334455,0.5,"sparse"]]:
			var reference:=execute_case(false,name,settings[0],settings[1],settings[2],settings[3],settings[4],settings[5],settings[6])
			var optimized:=execute_case(true,name,settings[0],settings[1],settings[2],settings[3],settings[4],settings[5],settings[6])
			if reference.result!=optimized.result:failures.append([name,"execution",reference.result,optimized.result]);continue
			var original:Dictionary=reference.vm.memory;var actual:Dictionary=optimized.vm.memory
			var mismatch:Array=[]
			for address in original:
				if not actual.has(address) or original[address]!=actual[address]:mismatch.append("0x%x"%int(address))
			for address in actual:
				if not original.has(address):mismatch.append("extra0x%x"%int(address))
			if not mismatch.is_empty():failures.append([name,settings,"memory",mismatch.slice(0,30),mismatch.size()])
			if reference.vm.registers!=optimized.vm.registers:failures.append([name,settings,"registers",reference.vm.registers,optimized.vm.registers])
			for flag in ["carry","zero","sign_flag","overflow","parity","fp_status","fp"]:
				if reference.vm.get(flag)!=optimized.vm.get(flag):failures.append([name,settings,flag])
			cases+=1
	print(JSON.stringify({"cases":cases,"failures":failures}))
	if failures.is_empty():print("PASS exact source pixel-loop ports match all VM bytes registers flags and x87 state")
	quit(0 if failures.is_empty() else 1)
