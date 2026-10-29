class_name OriginalInteraction
extends RefCounted
## Retained original MouseMove geometry and MouseUp association instructions.
## VCL bitmap dimensions and strings are explicit ABI boundaries, never raster substitutes.
const Vm=preload("res://scripts/original/original_particle_vm.gd")
const Host=preload("res://scripts/original/original_x87_host.gd")
const Encoding=preload("res://scripts/legacy_encoding.gd")
var vm:Vm
var host=Host.new()
var ir:Dictionary
static var cached_ir:Dictionary={}
var allocated:=0x1000000
var strings:Dictionary={}
var bitmaps:Dictionary={}
var vessels:Array=[]
var connectors:Array=[]
var form:=0
func _alloc(size:int)->int:
	var p:=allocated;allocated=(allocated+size+15)&~15;return p
func _string(text:String)->int:
	if text.is_empty():return 0
	var p:=_alloc(4);strings[p]=text;return p
func _text(p:int)->String:
	if p==0:return ""
	if strings.has(p):return str(strings[p])
	var bytes:=PackedByteArray()
	for i in 256:
		if not vm.has_byte(p+i):vm.error="Undefined original interaction string at0x%x"%p;return ""
		var b:=vm.integer(p+i,1);if b==0:return Encoding.decode(bytes)
		bytes.append(b)
	vm.error="Unterminated original interaction string";return ""
func _bitmap(w:int,h:int)->int:
	var p:=_alloc(4);var vt:=_alloc(0x44);vm.put(p,vt)
	for pair in [[0x20,0x8000100],[0x2c,0x8000110],[0x34,0x8000120],[0x40,0x8000130]]:vm.put(vt+pair[0],pair[1])
	bitmaps[p]={"width":w,"height":h};return p
func _setup(scene:Dictionary,decision:Dictionary)->void:
	vm=Vm.new();vm.rng={};vm.trig=Callable(host,"evaluate")
	if cached_ir.is_empty():cached_ir=JSON.parse_string(FileAccess.get_file_as_string("res://data/original_interaction_ir.json"))
	ir=cached_ir
	for a in ir.constants:vm.write(str(a).hex_to_int(),str(ir.constants[a]).hex_decode())
	vm.put(0,0xffffffff) # Declared exception-registration boundary; no allocator bytes are supplied.
	vm.helpers[0x540ec4]=func(m:Vm):m.put(int(m.registers.eax),_string(_text(int(m.registers.edx))));m.return_helper(int(m.registers.eax))
	for address in [0x540efc,0x541018]:vm.helpers[address]=func(m:Vm):m.put(int(m.registers.eax),m.integer(int(m.registers.edx)));m.return_helper(int(m.registers.eax))
	vm.helpers[0x540fe8]=func(m:Vm):m.put(int(m.registers.eax),0);m.return_helper(int(m.registers.eax))
	vm.helpers[0x5410cc]=func(m:Vm):
		var equal:=_text(m.integer(int(m.registers.eax)))==_text(m.integer(int(m.registers.edx)))
		m.zero=not equal;m.parity=not equal;m.carry=false;m.sign_flag=false;m.overflow=false;m.return_helper(1 if equal else 0)
	vm.helpers[0x8000100]=func(m:Vm):m.return_helper(int(bitmaps[int(m.registers.eax)].height))
	vm.helpers[0x8000110]=func(m:Vm):m.return_helper(int(bitmaps[int(m.registers.eax)].width))
	vm.helpers[0x8000120]=func(m:Vm):bitmaps[int(m.registers.eax)].height=m._s32(int(m.registers.edx));m.return_helper()
	vm.helpers[0x8000130]=func(m:Vm):bitmaps[int(m.registers.eax)].width=m._s32(int(m.registers.edx));m.return_helper()
	vm.helpers[0x53ad24]=func(m:Vm):
		var bytes:=m.read(int(m.registers.esp)+4,8)
		var pair:Array=host.evaluate(bytes.decode_double(0),"tan") if bytes.size()==8 else []
		if pair.is_empty():m.error="Original FPTAN provider is unresolved";return
		m.fp.push_front(pair);m.return_helper()
	form=_alloc(0x600);vm.put(0x5799c4,_alloc(4));vm.put(vm.integer(0x5799c4),form)
	for pair in [[0x5ac,int(decision.get("dx",0))],[0x5b0,int(decision.get("dy",0))],[0x5b4,0],[0x5b8,0],[0x504,int(decision.get("start_width",0))],[0x508,int(decision.get("start_height",0))],[0x50c,int(decision.get("start_x",0))],[0x510,int(decision.get("start_y",0))]]:vm.put(form+pair[0],pair[1])
	vm.put(0x57a730,int(decision.get("type",0)));vm.put(0x57a734,int(decision.get("index",0)));vm.put(0x57a738,int(decision.get("command",0)))
	vm.write(0x5636c0,PackedFloat64Array([float(scene.get("scale",1.0))]).to_byte_array())
	for v in scene.vessels:
		var p:=_alloc(0x100);vessels.append(p);vm.put(0x585850+(vessels.size()-1)*4,p)
		for key in v.native_fields:
			var off:=str(key).hex_to_int();var value=v.native_fields[key]
			if off in [4,0x80,0x90,0x94,0x98]:vm.put(p+off,_string(str(value)))
			elif off in [0x20,0x28,0x30,0x88,0xa8,0xb0,0xb8]:vm.write(p+off,PackedFloat64Array([float(value)]).to_byte_array())
			else:vm.put(p+off,int(value))
		vm.put(p+0x10,int(v.position[0]));vm.put(p+0x14,int(v.position[1]));vm.put(p+0xfc,_bitmap(int(v.native_bitmap_width),int(v.native_bitmap_height)))
	vm.put(0x58779c,vessels.size());vm.put(0x58ca8c,scene.connectors.size())
	var offsets:Array=[0,4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,64,68,72,76,80,84,88,96,104]
	for c in scene.connectors:
		var p:=_alloc(0x80);connectors.append(p);vm.put(0x58baec+(connectors.size()-1)*4,p)
		for i in 25:
			if i in [1,11,14]:vm.put(p+int(offsets[i]),_string(str(c.metadata[i])))
			elif i>=22:vm.write(p+int(offsets[i]),PackedFloat64Array([float(c.metadata[i])]).to_byte_array())
			else:vm.put(p+int(offsets[i]),int(c.metadata[i]))
	for i in scene.get("buttons",[]).size():
		var b:Dictionary=scene.buttons[i];var p:int=0x58ca94+i*0x5c
		for pair in [[0,b.active],[4,b.position[0]],[8,b.position[1]],[0x34,b.size[0]],[0x38,b.size[1]]]:vm.put(p+pair[0],int(pair[1]))
func _run(name:String,body:bool=false,point:Vector2=Vector2.ZERO)->Dictionary:
	var program:Dictionary=ir.functions[name];var instructions:Array=[]
	for f in ir.functions.values():instructions.append_array(f.instructions)
	vm.registers.esp=Vm.STACK+0xff00;vm.registers.ebp=Vm.STACK+0xf000
	if body:
		vm.registers.esp=Vm.STACK+0xe000;vm.put(int(vm.registers.ebp)-4,form);vm.put(int(vm.registers.ebp)+8,int(point.y));vm.put(int(vm.registers.ebp)+12,int(point.x))
	return vm.execute({"instructions":instructions,"end":program.end},int(program.entry))
func _adopt(scene:Dictionary,decision:Dictionary)->void:
	for i in vessels.size():
		var p:int=vessels[i];var v:Dictionary=scene.vessels[i]
		for off in [0x10,0x14,0x84]:
			if vm.contains_span(p+off,4):v.native_fields["0x%02x"%off]=str(vm._s32(vm.integer(p+off)))
		v.native_fields["0x80"]=_text(vm.integer(p+0x80));v.position=[vm._s32(vm.integer(p+0x10)),vm._s32(vm.integer(p+0x14))]
		var b:Dictionary=bitmaps[vm.integer(p+0xfc)]
		v.native_bitmap_width=int(b.width);v.native_bitmap_height=int(b.height)
	for i in connectors.size():
		var p:int=connectors[i];var c:Dictionary=scene.connectors[i]
		for j in range(2,19):
			c.metadata[j]=_text(vm.integer(p+j*4)) if j in [11,14] else str(vm._s32(vm.integer(p+j*4)))
		c.start=[int(c.metadata[2]),int(c.metadata[3])];c.end=[int(c.metadata[4]),int(c.metadata[5])];c.from_vessel=str(c.metadata[11]);c.to_vessel=str(c.metadata[14])
	for i in scene.get("buttons",[]).size():
		var b:Dictionary=scene.buttons[i];var p:int=0x58ca94+i*0x5c
		b.position=[vm._s32(vm.integer(p+4)),vm._s32(vm.integer(p+8))];b.size=[vm._s32(vm.integer(p+0x34)),vm._s32(vm.integer(p+0x38))]
		for pair in [[1,b.position[0]],[2,b.position[1]],[16,b.size[0]],[17,b.size[1]]]:b.metadata[pair[0]]=str(pair[1])
	decision.dx=vm._s32(vm.integer(form+0x5ac));decision.dy=vm._s32(vm.integer(form+0x5b0))
static func begin(scene:Dictionary,decision:Dictionary)->void:
	if int(decision.type) in [316,318]:
		var v:Dictionary=scene.vessels[int(decision.index)]
		decision.start_width=int(v.native_bitmap_width);decision.start_height=int(v.native_bitmap_height);decision.start_x=int(v.position[0]);decision.start_y=int(v.position[1])
	elif int(decision.type)==2000:
		var b:Dictionary=scene.buttons[int(decision.index)]
		decision.start_width=int(b.size[0]);decision.start_height=int(b.size[1]);decision.start_x=int(b.position[0]);decision.start_y=int(b.position[1])
static func resize(scene:Dictionary,decision:Dictionary,point:Vector2)->Dictionary:
	var runner:=OriginalInteraction.new();runner._setup(scene,decision)
	var result:=runner._run("drag_geometry",true,point)
	if result.ok:runner._adopt(scene,decision)
	runner.vm.helpers.clear();runner.host.stop()
	return result
static func sync_dimensions(scene:Dictionary,decision:Dictionary)->void:
	# Original postgeometry drawing07F24/08A3C clamps then stores these fields.
	if int(decision.type) not in [316,318]:return
	var v:Dictionary=scene.vessels[int(decision.index)]
	var limit:=Vector2i(800,600) if int(decision.type)==316 else Vector2i(2000,2000)
	v.native_bitmap_width=mini(int(v.native_bitmap_width),limit.x);v.native_bitmap_height=mini(int(v.native_bitmap_height),limit.y)
	v.native_fields["0x3c"]=str(v.native_bitmap_width);v.native_fields["0x40"]=str(v.native_bitmap_height)
static func release(scene:Dictionary,decision:Dictionary)->Dictionary:
	var runner:=OriginalInteraction.new();runner._setup(scene,decision)
	var result:=runner._run("apparatus_association")
	if not result.ok:runner.vm.helpers.clear();runner.host.stop();return result
	result=runner._run("conduit_association")
	if result.ok:runner._adopt(scene,decision)
	runner.vm.helpers.clear();runner.host.stop()
	return result
