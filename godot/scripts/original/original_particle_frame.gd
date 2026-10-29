class_name OriginalParticleFrame
extends RefCounted
## Native 40A4B8 live-cache blocks. Source instruction IR preserves emission,
## dissolution clearing, connector bubbles and their shared random-call order.
const Live = preload("res://scripts/original/original_live_particles.gd")
const Vm = preload("res://scripts/original/original_particle_vm.gd")
const ObservedObject=preload("res://scripts/original/original_observed_particle_object.gd")
const Quantities = preload("res://scripts/original/original_quantities.gd")
const PixelLoops=preload("res://scripts/original/original_particle_pixel_loops.gd")
var vm: Vm
var bitmap_meta: Dictionary = {}
var strings: Dictionary = {}
var allocated := 0x01000000
var reserved_native_spans:Array=[]
var presentation: Callable
var reagent_indices: Dictionary = {}
var input_catalog: Dictionary = {}
var data: Dictionary = {}
static var cached_data:Dictionary={}
static var cached_programs:Array=[]
var programs: Array = []
var solid_addresses: Array = []
var bubble_addresses: Array = []
var vessel_addresses: Array = []
var current_scene: Dictionary = {}
var current_context: Dictionary = {}

static func create_scene(vessels: Array) -> Dictionary:
	var pools: Array=[]
	for v in vessels:
		if int(v.type_id)>100 and int(v.type_id)<200:
			var rect := [0,0,int(v.native_bitmap_width),int(v.native_bitmap_height)]
			pools.append({"solid":Live.create_solid(rect),"bubbles":Live.create_bubbles(rect,0,0,0xffffff)})
		else:pools.append({})
	return {"pools":pools,"native_factory":0x43dcd8}
func _alloc(size: int, zeroed: bool=false) -> int:
	var result:=allocated
	var collided:=true
	while collided:
		collided=false
		for span in reserved_native_spans:
			if result<int(span[0])+int(span[1]) and int(span[0])<result+size:
				result=(int(span[0])+int(span[1])+15)&~15;collided=true;break
	if result<=0 or result>0xffffffff-size:vm.error="Hosted particle address space exhausted";return 0
	allocated=(result+size+15)&~15
	if zeroed:
		vm.map_zero(result,size)
	return result
func _reserve_observed_pointer_domains(scene:Dictionary)->Dictionary:
	reserved_native_spans.clear()
	for pool in scene.pools:
		for name in ["solid","bubbles"]:
			if not pool.get(name,{}) is Dictionary or not pool.get(name,{}).has("native_raw_object"):continue
			var record:Dictionary=pool[name].native_raw_object
			var observed:=ObservedObject.validate(record,name=="solid")
			if not observed.ok:return observed
			var raw:PackedByteArray=observed.bytes
			for offset in ([0x34678,0x3467c] if name=="solid" else [4]):
				var address:int=raw.decode_u32(offset)
				if address!=0:reserved_native_spans.append([address,0x30])
			# These raw DWORDs are source-established scanline pointer tables.
			# Reserve even unbound rows so stale native addresses cannot alias
			# unrelated hosted allocations and accidentally become readable.
			if name=="solid":
				var row_width:int=maxi(1,int(pool[name].get("width",0)))
				for start in [0x32d68,0x339e8]:
					for row in 800:
						var address:int=raw.decode_u32(start+row*4)
						if address!=0:reserved_native_spans.append([maxi(1,address-4),row_width*4+8])
			for binding in observed.bindings.values():
				for address in binding.row_addresses:reserved_native_spans.append([int(address),int(binding.width)*4])
	return {"ok":true}

func _bitmap_metric(machine:Vm,axis:String)->void:
	var pointer:int=int(machine.registers.eax)
	if not bitmap_meta.has(pointer):machine.error="Original bitmap metadata/pointer backing is unobserved";return
	machine.return_helper(int(bitmap_meta[pointer][axis]))
func _bitmap_canvas(machine:Vm)->void:
	var pointer:int=int(machine.registers.eax)
	if not bitmap_meta.has(pointer):machine.error="Original bitmap canvas backing is unobserved";return
	machine.return_helper(int(bitmap_meta[pointer].canvas))

func _string(value: String) -> int:
	if value.is_empty():return 0
	var pointer:=_alloc(4);strings[pointer]=value;return pointer
func _text(pointer: int) -> String:
	if pointer==0:return ""
	if not strings.has(pointer):vm.error="Unresolved original string pointer 0x%x"%pointer;return ""
	return str(strings[pointer])
func _init_vm(rng: Dictionary,trig: Callable) -> void:
	if vm!=null:vm.helpers.clear()
	vm=Vm.new();vm.rng=rng;vm.trig=trig
	# Retained IR is immutable across frames. Parse/flatten it once per process.
	if cached_data.is_empty():
		var parsed:Variant=JSON.parse_string(FileAccess.get_file_as_string("res://data/original_particle_ir.json"))
		if not parsed is Dictionary or not parsed.get("functions") is Dictionary or not parsed.get("constants") is Dictionary:
			vm.error="Original particle instruction data is invalid";return
		cached_data=parsed
		for name in cached_data.functions:
			if name not in ["frame_solid","frame_gas"]:cached_programs.append_array(cached_data.functions[name].instructions)
	data=cached_data;programs=cached_programs
	if current_context.get("production_pixel_loop",false)==true:
		vm.helpers[0x49c996]=func(m):PixelLoops.solid(m,bitmap_meta)
		vm.helpers[0x49ce08]=func(m):PixelLoops.fade(m,bitmap_meta)
	for address in data.constants:vm.write(str(address).hex_to_int(),str(data.constants[address]).hex_decode())
	# Literal source string used in the original solid phase comparisons.
	strings[0x55673d]="(固体)"
	vm.helpers[0x4016e8]=func(m: Vm):m.put(int(m.registers.eax),0);m.return_helper(int(m.registers.eax))
	vm.helpers[0x540ec4]=func(m: Vm):m.put(int(m.registers.eax),_string(_text(int(m.registers.edx))));m.return_helper(int(m.registers.eax))
	vm.helpers[0x540fe8]=func(m: Vm):m.put(int(m.registers.eax),0);m.return_helper(int(m.registers.eax))
	vm.helpers[0x5410cc]=func(m: Vm):
		var equal := _text(m.integer(int(m.registers.eax)))==_text(m.integer(int(m.registers.edx)))
		m.zero=not equal;m.parity=not equal;m.carry=false;m.sign_flag=false;m.overflow=false;m.return_helper(1 if equal else 0)
	vm.helpers[0x452acc]=func(m: Vm):
		var sp:=int(m.registers.esp);var destination:=m.integer(sp+4);var species:=_text(m.integer(sp+8))
		m.put(destination,_string(Quantities.phase_suffix(species)));m.return_helper()
	vm.helpers[0x452d9c]=func(m: Vm):
		var species:=_text(m.integer(int(m.registers.esp)+4))
		if not reagent_indices.has(species):m.error="Original particle reagent lookup unresolved: "+species
		m.return_helper(int(reagent_indices.get(species,-1)))
	vm.helpers[0x8000100]=Callable(self,"_bitmap_metric").bind("height")
	vm.helpers[0x8000104]=Callable(self,"_bitmap_metric").bind("width")
	vm.helpers[0x8000108]=func(m: Vm):
		_resize(int(m.registers.eax),int(m.registers.edx),true)
		if m.error.is_empty():m.return_helper()
	vm.helpers[0x800010c]=func(m: Vm):
		_resize(int(m.registers.eax),int(m.registers.edx),false)
		if m.error.is_empty():m.return_helper()
	vm.helpers[0x4e9448]=Callable(self,"_bitmap_canvas") # Explicit VCL handle boundary.
	for address in [0x4e3e50,0x4e4158,0x4e4274,0x4e4744,0x4e44a8,0x5552de,0x5553e0,0x55542e]:
		vm.helpers[address]=Callable(self,"_presentation_helper").bind(address)
	vm.helpers[0x4e4b84]=func(m: Vm):m.return_helper(int(m.registers.eax))
	vm.helpers[0x4e95b0]=func(m: Vm):
		# Native4E95B0 returns visual top-down rows (positive biHeight is
		# reversed explicitly). Never synthesize unknown initial pixel bytes.
		var row:=int(m.registers.edx);var bmp:=int(m.registers.eax)
		if not bitmap_meta.has(bmp):m.error="Original particle scanline bitmap backing is unobserved";return
		var meta:Dictionary=bitmap_meta[bmp]
		if not meta.rows.has(row):
			if meta.words.size()!=int(meta.width)*int(meta.height):
				var result=presentation.call({"operation":"scanline_words","bitmap":bmp,"bitmaps":bitmap_meta,"memory":vm}) if presentation.is_valid() else {}
				if not _accept_presentation_result(result,"Native particle DIB words are unresolved for "+str(meta.name)):return
			if meta.words.size()!=int(meta.width)*int(meta.height):m.error="Native particle DIB words are unresolved for "+str(meta.name);return
			meta.rows[row]=_alloc(maxi(4,int(meta.width)*4))
			for column in int(meta.width):m.put(int(meta.rows[row])+column*4,int(meta.words[row*int(meta.width)+column]))
		m.return_helper(int(meta.rows[row]))
func _presentation_helper(m: Vm,address: int) -> void:
	_present(address)
	# An unresolved call has not returned. Keep the original return address and
	# arguments intact instead of consuming them as if presentation succeeded.
	if not m.error.is_empty():return
	var cleanup:=20 if address in [0x5552de,0x5553e0] else 16 if address==0x55542e else 8 if address==0x4e4744 else 4 if address==0x4e44a8 else 0
	m.return_helper(0,cleanup)
func _resize(bitmap: int,size: int,width_axis: bool) -> void:
	if not bitmap_meta.has(bitmap):vm.error="Original bitmap resize backing is unobserved";return
	var meta:Dictionary=bitmap_meta[bitmap]
	# VCL SetWidth/SetHeight return without reallocating an unchanged axis.
	# Keeping the persistent pixel backing is essential to49C620's Draw path.
	if size==int(meta.width if width_axis else meta.height):return
	if meta.get("observed_raw_binding",false) and size!=int(meta.width if width_axis else meta.height):
		vm.error="Observed raw particle bitmap resize requires new exact backing";return
	var old_words:Array=meta.words.duplicate()
	if old_words.size()==int(meta.width)*int(meta.height):
		for row in meta.rows:
			if int(row)<0 or int(row)>=int(meta.height):continue
			for column in int(meta.width):old_words[int(row)*int(meta.width)+column]=vm.integer(int(meta.rows[row])+column*4)
	meta.resize_previous={"width":int(meta.width),"height":int(meta.height),"words":old_words}
	if width_axis:meta.width=size
	else:meta.height=size
	_present(0x8000108 if width_axis else 0x800010c)
func _present(address: int) -> void:
	if not presentation.is_valid():vm.error="Original VCL particle presentation boundary is unresolved at 0x%x"%address;return
	var result=presentation.call({"address":address,"eax":int(vm.registers.eax),"edx":int(vm.registers.edx),"ecx":int(vm.registers.ecx),"stack":int(vm.registers.esp),"memory":vm,"bitmaps":bitmap_meta})
	_accept_presentation_result(result,"Original particle presentation failed")
func _accept_presentation_result(result:Variant,fallback:String)->bool:
	if not result is Dictionary:
		vm.error=fallback;return false
	if not result.get("ok",false) is bool or not result.get("ok",false):
		vm.error=str(result.get("error",fallback))
		if vm.error.is_empty():vm.error=fallback
		return false
	_apply_words(result)
	return vm.error.is_empty()
func _apply_words(result: Dictionary) -> void:
	for name in result.get("bitmap_words",{}):
		for pointer in bitmap_meta:
			var meta:Dictionary=bitmap_meta[pointer]
			if str(meta.name)!=str(name):continue
			var words:Array=result.bitmap_words[name]
			if words.size()!=int(meta.width)*int(meta.height):vm.error="Native DIB size differs from original bitmap dimensions";return
			meta.words=words.duplicate()
			for row in meta.rows:
				if int(row)>=int(meta.height):continue
				for column in int(meta.width):vm.put(int(meta.rows[row])+column*4,int(words[int(row)*int(meta.width)+column]))
func _bitmap(name: String,width: int,height: int) -> int:
	var pointer:=_alloc(0x10,true);var table:=_alloc(0x44,true)
	vm.put(pointer,table);vm.put(table+0x20,0x8000100);vm.put(table+0x2c,0x8000104);vm.put(table+0x40,0x8000108);vm.put(table+0x34,0x800010c)
	var canvas:=_alloc(0x18,true);var pen:=_alloc(4,true);var brush:=_alloc(4,true)
	vm.put(canvas+0x10,pen);vm.put(canvas+0x14,brush)
	bitmap_meta[pointer]={"name":name,"width":width,"height":height,"rows":{},"words":[],"canvas":canvas,"pen":pen,"brush":brush}
	return pointer
func _observed_pool(pool:Dictionary,solid:bool,index:int)->int:
	var observed:=ObservedObject.validate(pool.native_raw_object,solid)
	if not observed.ok:vm.error=str(observed.error);return 0
	if not pool.get("slots",null) is Array:vm.error="Observed particle record view is required";return 0
	var pointer:=_alloc(observed.bytes.size())
	vm.write(pointer,observed.bytes)
	var installed:Array=[]
	for key in observed.bindings:
		var offset:int=str(key).trim_prefix("0x").hex_to_int();var binding:Dictionary=observed.bindings[key]
		var name:="solid_primary_"+str(index) if offset==0x34678 else "solid_retained_"+str(index) if offset==0x3467c else "bubble_bitmap_"+str(index)
		var bitmap:=_bitmap(name,int(binding.width),int(binding.height));var meta:Dictionary=bitmap_meta[bitmap]
		meta.words=binding.words.duplicate();meta.observed_raw_binding=true
		for row in int(binding.height):
			var address:int=binding.row_addresses[row];var words:=PackedByteArray();words.resize(int(binding.width)*4)
			for column in int(binding.width):words.encode_u32(column*4,int(binding.words[row*int(binding.width)+column]))
			# Original captured rows must not alias hosted allocations/constants.
			if vm.overlaps_known_span(address,words.size()):vm.error="Observed scanline address aliases existing hosted memory";return 0
			vm.write(address,words);meta.rows[row]=address
		vm.put(pointer+offset,bitmap);installed.append({"offset":offset,"original_pointer":int(binding.original_pointer),"bitmap":bitmap,"key":key})
	pool["_native_frame_rebases"]=installed
	return pointer

func _pool(pool: Dictionary,solid: bool,index: int) -> int:
	if pool.has("native_raw_object"):return _observed_pool(pool,solid,index)
	var pointer:=_alloc(0x3468c if solid else 0xfc20,true)
	var start:=4 if solid else 0x10
	for slot in pool.slots.size():
		for word in 13:vm.put(pointer+start+slot*52+word*4,int(pool.slots[slot][word]))
	var width:=int(pool.width);var height:=int(pool.height)
	if solid:
		vm.put(pointer+0x32d4c,int(pool.get("native_draw_mode",1))) #49BBF8 explicit constructor store.
		vm.put(pointer+0x34684,int(pool.count));vm.put(pointer+0x34680,1 if pool.frozen else 0,1);vm.put(pointer+0x34688,1 if pool.already_drawn else 0,1)
		vm.put(pointer+0x32d50,int(pool.background));vm.put(pointer+0x32d54,int(pool.previous_background))
		for axis in 4:vm.put(pointer+0x32d58+axis*4,int(pool.rect[axis]))
		var primary:=_bitmap("solid_primary_"+str(index),width,height);var retained:=_bitmap("solid_retained_"+str(index),width,height)
		bitmap_meta[primary].words=pool.get("primary_words",[]).duplicate();bitmap_meta[retained].words=pool.get("retained_words",[]).duplicate()
		vm.put(pointer+0x34678,primary);vm.put(pointer+0x3467c,retained)
		# Rebase source49BBF8's two scanline tables onto this machine's actual
		# persistent pixel backing; do not leave source pointers as zero.
		for layer in [[primary,0x32d68],[retained,0x339e8]]:
			var meta:Dictionary=bitmap_meta[int(layer[0])]
			if meta.words.size()!=width*height:continue
			for row in height:
				var row_address:=_alloc(maxi(4,width*4));meta.rows[row]=row_address
				for column in width:vm.put(row_address+column*4,int(meta.words[row*width+column]))
				vm.put(pointer+int(layer[1])+row*4,row_address)
	else:
		vm.put(pointer+0x5150,int(pool.count));vm.put(pointer+0x7ef4,1 if pool.enabled else 0,1)
		vm.put(pointer+0xfc10,int(pool.call_count));vm.put(pointer+0xfc18,int(pool.center_x));vm.put(pointer+0xfc1c,int(pool.center_y));vm.put(pointer+0x7f00,int(pool.surface))
		vm.put(pointer+0x5154,int(pool.color));vm.put(pointer+0x5158,int(pool.background))
		for axis in 4:vm.put(pointer+0x515c+axis*4,int(pool.rect[axis]))
		if not pool.region.is_empty():vm.error="Original frame collision-region allocation profile is unresolved"
	return pointer
func _vessel(v: Dictionary,index: int) -> int:
	var pointer:=_alloc(0x4348)
	vm.put(pointer+4,_string(str(v.label)));vm.put(pointer+8,int(v.type_id))
	vm.put(pointer+0x10,int(v.position[0]));vm.put(pointer+0x14,int(v.position[1]));vm.put(pointer+0x18,int(v.native_fields["0x18"]))
	if v.has("native_liquid_height"):vm.write(pointer+0x30,PackedFloat64Array([float(v.native_liquid_height)]).to_byte_array())
	if v.has("native_liquid_color"):vm.put(pointer+0x3cd0,int(v.native_liquid_color))
	for pair in [["solid_4318",0x4318],["gas_3cc0",0x3cc0],["native_particle_3cc8",0x3cc8]]:
		if v.has(pair[0]):vm.write(pointer+int(pair[1]),PackedFloat64Array([float(v[pair[0]])]).to_byte_array())
	vm.put(pointer+0xfc,_bitmap("vessel_"+str(index),int(v.native_bitmap_width),int(v.native_bitmap_height)))
	vm.put(pointer+0x104,v.contents.size())
	var slot:=0
	for species in v.contents:
		vm.put(pointer+0x108+slot*4,_string(str(species)))
		for pair in [["solid_3cd8",0x3cd8],["solid_3ff8",0x3ff8]]:
			if v.get(pair[0],{}) is Dictionary and v.get(pair[0],{}).has(species):vm.write(pointer+int(pair[1])+slot*8,PackedFloat64Array([float(v[pair[0]][species])]).to_byte_array())
		slot+=1
	return pointer
func _adopt_pool(pool: Dictionary,pointer: int,solid: bool) -> void:
	if pool.has("native_raw_object"):
		var size:=0x3468c if solid else 0xfc20
		var raw:=vm.read(pointer,size)
		for rebase in pool.get("_native_frame_rebases",[]):
			# Retain original pointer identity in the source-address snapshot.
			raw.encode_u32(int(rebase.offset),int(rebase.original_pointer))
			var binding:Dictionary=pool.native_raw_object.bitmap_bindings[rebase.key]
			var meta:Dictionary=bitmap_meta[int(rebase.bitmap)];var words:Array=meta.words.duplicate()
			for row in meta.rows:
				for column in int(meta.width):words[int(row)*int(meta.width)+column]=vm.integer(int(meta.rows[row])+4*column)
			binding.words=words
			var pixels:=PackedByteArray();pixels.resize(words.size()*4)
			for pixel in words.size():pixels.encode_u32(pixel*4,int(words[pixel]))
			binding.pixels_sha256=ObservedObject.hash_bytes(pixels)
		pool.native_raw_object.raw_hex=raw.hex_encode();pool.native_raw_object.sha256=ObservedObject.hash_bytes(raw)
		pool.erase("_native_frame_rebases")
	var count:=vm.integer(pointer+(0x34684 if solid else 0x5150))
	if count>(4000 if solid else 400):vm.error="Native particle count exceeds its physical object-array layout";return
	pool.count=count
	var records:=maxi(pool.slots.size(),count)
	while pool.slots.size()<records:pool.slots.append([0,0,0,0,0,0,0,0,0,0,0,0,0])
	for index in records:
		for word in 13:pool.slots[index][word]=vm.integer(pointer+(4 if solid else 0x10)+index*52+word*4)
	if solid:
		pool.frozen=vm.integer(pointer+0x34680,1)!=0;pool.already_drawn=vm.integer(pointer+0x34688,1)!=0
		pool.background=vm.integer(pointer+0x32d50);pool.previous_background=vm.integer(pointer+0x32d54)
		for axis in 4:pool.rect[axis]=vm._s32(vm.integer(pointer+0x32d58+axis*4))
		var primary:=vm.integer(pointer+0x34678)
		if bitmap_meta.has(primary):pool.width=int(bitmap_meta[primary].width);pool.height=int(bitmap_meta[primary].height)
		for pair in [["primary_words",primary],["retained_words",vm.integer(pointer+0x3467c)]]:
			if not bitmap_meta.has(int(pair[1])):continue # Unaccessed/unavailable stays explicit.
			var meta:Dictionary=bitmap_meta[int(pair[1])];var words:Array=meta.words.duplicate()
			for row in meta.rows:
				if int(row)>=int(meta.height) or words.size()!=int(meta.width)*int(meta.height):continue
				for column in int(meta.width):words[int(row)*int(meta.width)+column]=vm.integer(int(meta.rows[row])+4*column)
			pool[pair[0]]=words
	else:
		pool.surface=vm._s32(vm.integer(pointer+0x7f00));pool.center_x=vm._s32(vm.integer(pointer+0xfc18));pool.center_y=vm._s32(vm.integer(pointer+0xfc1c));pool.call_count=vm._s32(vm.integer(pointer+0xfc10))
func step_vessel(index: int,vessels: Array,catalog: Dictionary,connectors: Array,scene: Dictionary,context: Dictionary,rng: Dictionary,native_trig: Callable,native_presentation: Callable) -> Dictionary:
	return step(vessels,catalog,connectors,scene,context,rng,native_trig,native_presentation,index)
func step(vessels: Array,catalog: Dictionary,connectors: Array,scene: Dictionary,context: Dictionary,rng: Dictionary,native_trig: Callable,native_presentation: Callable,selected_vessel: int=-1) -> Dictionary:
	# Optional owned process stack supplies actual prior bytes for source locals
	# read before a write. Absence deliberately retains unknown-memory failures.
	if context.has("owned_stack_bytes"):
		if not context.owned_stack_bytes is PackedByteArray or context.owned_stack_bytes.size()!=0x10000:
			return {"ok":false,"error":"Owned original particle stack requires exactly65536 known bytes at0x%08x"%Vm.STACK}
	var previous_vm:Vm=vm
	var result:=_step_impl(vessels,catalog,connectors,scene,context,rng,native_trig,native_presentation,selected_vessel)
	if context.has("owned_stack_bytes") and vm!=null and vm!=previous_vm and vm.contains_span(Vm.STACK,0x10000):
		# Return writes even on an unresolved primitive/instruction boundary. The
		# caller decides process lifecycle; neither zeros nor old input resurrect.
		result.owned_stack_bytes=vm.read(Vm.STACK,0x10000)
	return result
func _step_impl(vessels: Array,catalog: Dictionary,connectors: Array,scene: Dictionary,context: Dictionary,rng: Dictionary,native_trig: Callable,native_presentation: Callable,selected_vessel: int=-1) -> Dictionary:
	var phases:Array=context.get("phases",["frame_solid","frame_gas"])
	if phases not in [["frame_solid"],["frame_gas"],["frame_solid","frame_gas"]]:return {"ok":false,"error":"Original particle phases must preserve solid then gas order"}
	if selected_vessel < -1 or selected_vessel >= vessels.size():return {"ok":false,"error":"Selected original particle vessel index is invalid"}
	if not context.get("native_material_words",{}) is Dictionary:return {"ok":false,"error":"Explicit material word profile must retain native apparatus indices"}
	if not context.has("run_flag") or not context.has("pause_flag"):return {"ok":false,"error":"Original render run/pause globals are required"}
	if scene.get("pools",[]).size()!=vessels.size():return {"ok":false,"error":"Original persistent particle pool order differs from apparatus order"}
	current_scene=scene;current_context=context;presentation=native_presentation;input_catalog=catalog
	allocated=0x1000000;bitmap_meta.clear();strings.clear();reagent_indices.clear();solid_addresses.clear();bubble_addresses.clear();vessel_addresses.clear()
	_init_vm(rng,native_trig)
	if not vm.error.is_empty():return {"ok":false,"error":vm.error}
	if context.has("owned_stack_bytes"):vm.write(Vm.STACK,context.owned_stack_bytes)
	var domains:=_reserve_observed_pointer_domains(scene)
	if not domains.ok:return domains
	var reagent_index:=0
	for species in catalog:
		reagent_indices[species]=reagent_index
		var record:=_alloc(0x30,true);vm.put(record+0x28,int(catalog[species].color_integer));vm.put(0x57bc08+reagent_index*4,record);reagent_index+=1
	for index in vessels.size():
		var pointer:=_vessel(vessels[index],index);vessel_addresses.append(pointer);vm.put(0x585850+index*4,pointer)
		var observed_words: Dictionary = context.get("native_material_words",{})
		if observed_words.has(index):
			var meta: Dictionary = bitmap_meta[vm.integer(pointer+0xfc)]
			if not observed_words[index] is Array:return {"ok":false,"error":"Explicit material words must be a native unsigned32 array"}
			var words: Array = observed_words[index]
			if words.size()!=int(meta.width)*int(meta.height):return {"ok":false,"error":"Explicit material words differ from original vessel bitmap dimensions"}
			for word in words:
				if not word is int or word<0 or word>0xFFFFFFFF:return {"ok":false,"error":"Explicit material word is outside unsigned32"}
			meta.words=words.duplicate()
		# Both retained frame slices resolve pool tables solely with the current
		# [EBP-60] vessel index. Keep other persistent pools entirely untouched in
		# a selected-vessel phase; apparatus metadata remains available globally.
		if (selected_vessel==-1 or selected_vessel==index) and not scene.pools[index].is_empty():
			var solid:=_pool(scene.pools[index].solid,true,index);solid_addresses.append(solid);vm.put(0x595214+index*4,solid)
			var bubbles:=_pool(scene.pools[index].bubbles,false,index);bubble_addresses.append(bubbles);vm.put(0x5940b0+index*4,bubbles)
		else:solid_addresses.append(0);bubble_addresses.append(0)
	vm.put(0x58ca8c,connectors.size());vm.put(0x57a6f8,int(context.run_flag))
	var connector_addresses:Array=[]
	for index in connectors.size():
		var c:Dictionary=connectors[index];var pointer:=_alloc(0x80)
		connector_addresses.append(pointer);vm.put(0x58baec+index*4,pointer)
		for pair in [[0x08,c.start[0]],[0x0c,c.start[1]],[0x10,c.end[0]],[0x14,c.end[1]]]:vm.put(pointer+int(pair[0]),int(pair[1]))
		vm.put(pointer+0x2c,_string(str(c.from_vessel)));vm.put(pointer+0x38,_string(str(c.to_vessel)))
		if c.has("native_state_0x70"):vm.write(pointer+0x70,PackedFloat64Array([float(c.native_state_0x70)]).to_byte_array())
		if c.has("native_state_0x78"):vm.put(pointer+0x78,int(c.native_state_0x78))
	var form:=_alloc(0x5c0);vm.put(form+0x5bc,int(context.pause_flag))
	vm.registers.ebp=Vm.STACK+0xf000;vm.registers.esp=int(vm.registers.ebp)-0x2000
	vm.put(int(vm.registers.ebp)-0x58,form)
	# 40A4D3 calls534BE0 with558804. Its handler-frame offset is-54;
	# 534C03 explicitly initializes handler+1C (EBP-38) to zero.
	vm.put(int(vm.registers.ebp)-0x38,0)
	var execution_order: Array = range(vessels.size()) if selected_vessel == -1 else [selected_vessel]
	for index in execution_order:
		vm.put(int(vm.registers.ebp)-0x60,index)
		for name in phases:
			var program:Dictionary=data.functions[name]
			var combined:Dictionary={"instructions":program.instructions+programs,"end":program.end}
			var result:=vm.execute(combined,int(program.entry))
			if not result.ok:return result
	if not vm.error.is_empty():return {"ok":false,"error":vm.error}
	for index in vessels.size():
		if selected_vessel>=0 and selected_vessel!=index:continue
		var v:Dictionary=vessels[index];var pointer:int=vessel_addresses[index]
		var slot:=0
		for species in v.contents:
			for pair in [["solid_3cd8",0x3cd8],["solid_3ff8",0x3ff8]]:
				var address:=pointer+int(pair[1])+slot*8
				# Inactive/nonparticle branches may never read an unknown slot.
				# Adoption must not turn such a no-operation into a guessed zero.
				if not vm.contains_span(address,8):continue
				var bytes:=vm.read(address,8)
				if not bytes.is_empty():v[pair[0]][species]=bytes.decode_double(0)
			slot+=1
		for pair in [["native_particle_3cc8",0x3cc8],["solid_4318",0x4318]]:
			if v.has(pair[0]) and vm.contains_span(pointer+int(pair[1]),8):v[pair[0]]=vm.read(pointer+int(pair[1]),8).decode_double(0)
		if int(solid_addresses[index])!=0:_adopt_pool(scene.pools[index].solid,int(solid_addresses[index]),true);_adopt_pool(scene.pools[index].bubbles,int(bubble_addresses[index]),false)
	for index in connectors.size():
		if connectors[index].has("native_state_0x70"):connectors[index].native_state_0x70=vm.read(int(connector_addresses[index])+0x70,8).decode_double(0)
	vm.helpers.clear()
	if not vm.error.is_empty():return {"ok":false,"error":vm.error}
	var material_words := {}
	for index in vessels.size():
		var meta: Dictionary = bitmap_meta[vm.integer(int(vessel_addresses[index])+0xfc)]
		if meta.words.size()!=int(meta.width)*int(meta.height):continue
		var words: Array = meta.words.duplicate()
		for row in meta.rows:
			if int(row)<0 or int(row)>=int(meta.height):return {"ok":false,"error":"Native particle scanline lies outside supplied material bitmap"}
			for column in int(meta.width):words[int(row)*int(meta.width)+column]=vm.integer(int(meta.rows[row])+4*column)
		material_words[index]=words
	if not vm.error.is_empty():return {"ok":false,"error":vm.error}
	return {"ok":true,"native_function":0x40a4b8,"selected_vessel":selected_vessel,"material_words":material_words,"presentation_boundary":"VCL/GDI bitmap operations; retained pixel arithmetic executes original IR"}
