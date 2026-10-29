class_name OriginalLiveParticles
extends RefCounted
## Persistent native particles; emission 0049BF44. Each record retains the
## original 13 DWORDs at +4 + index*0x34. No chemistry rules are added here.
const X = preload("res://scripts/original/original_x87.gd")
const Rng = preload("res://scripts/original/original_particle_rng.gd")
const Actions = preload("res://scripts/original/original_apparatus_actions.gd")
static var _constants: Dictionary = {}

static func _error(message: String) -> Dictionary: return {"ok":false,"error":message}
static func _constant(address: String) -> Array:
	if _constants.is_empty(): _constants = JSON.parse_string(FileAccess.get_file_as_string("res://data/original_particle_constants.json"))
	var record: Dictionary = _constants[address]
	if int(record.length) == 10: return X.from_extended80_hex(str(record.hex))
	var bytes: PackedByteArray = str(record.hex).hex_decode()
	return [bytes.decode_float(0) if int(record.length) == 4 else bytes.decode_double(0), 0.0]
static func _number(address: String) -> float: return X.stored_double(_constant(address))
static func _word(value: float) -> int: return PackedFloat32Array([value]).to_byte_array().decode_u32(0)
static func _float(word: int) -> float:
	var bytes := PackedByteArray([0,0,0,0]); bytes.encode_u32(0,word); return bytes.decode_float(0)
static func _single(pair: Array) -> int: return _word(X.stored_float32(pair))
static func _neg(pair: Array) -> Array: return X.multiply(pair,-1.0)
static func _rng_valid(rng: Dictionary) -> bool:
	for field in ["low","high"]:
		var value=rng.get(field,null)
		if value is int:
			if value<0 or value>0xffffffff:return false
		elif value is float:
			if not is_finite(value) or value<0.0 or value>4294967295.0 or value!=floor(value):return false
		else:return false
	return true

static func create_solid(rect: Array) -> Dictionary:
	# VMT5674E4 NewInstance53139C ->InitInstance531414 zeros0x3468C bytes.
	# 49BBF8 sets32D4C=1, constructs/resizes both bitmaps and clears both
	# using background32D50 (the InitInstance-zero field), then binds rows.
	var width:=absi(int(rect[2])-int(rect[0]));var height:=absi(int(rect[3])-int(rect[1]))
	var pixels:Array=[];pixels.resize(width*height);pixels.fill(0)
	return {"count":0,"slots":[],"frozen":false,"already_drawn":false,"background":0,"previous_background":0,"palette":[],"rect":rect.duplicate(),"width":width,"height":height,"primary_words":pixels,"retained_words":pixels.duplicate(),"native_draw_mode":1,"native_constructor":0x49bbf8}

static func emit_solid(pool: Dictionary, colors: Array, amounts: Array, y: int, x: int, rng: Dictionary, stack_color_profile: Array = []) -> Dictionary:
	var count := int(pool.count)
	if count >= 2000: return {"ok":true,"emitted":0}
	if colors.size() != amounts.size(): return _error("Native particle color/amount array count mismatch")
	var to_emit := 0
	var total := 0.0
	for amount in amounts:
		var single := X.stored_float32([float(amount),0.0])
		to_emit = Actions._trunc(X.add([float(to_emit),0.0],single))
		total = X.stored_float32(X.add([single,0.0],total))
	var distribution: Array = stack_color_profile.duplicate()
	distribution.resize(maxi(100,distribution.size()))
	var cursor := 0
	for index in amounts.size():
		var single := X.stored_float32([float(amounts[index]),0.0])
		var weighted := X.divide(X.multiply(_constant("0x49c240"),single),total)
		if weighted.is_empty(): return _error("Native particle distribution division is unresolved")
		var allocation := Actions._trunc(weighted)
		if allocation < 0 or cursor+allocation > 100: return _error("Native particle color distribution would overwrite its 100-cell stack array")
		for cell in range(cursor,cursor+allocation): distribution[cell] = int(colors[index])
		cursor += allocation
	if to_emit <= 0: return {"ok":true,"emitted":0}
	if count + to_emit > 4000: return _error("Native solid particles exceed the physical 4000-record object allocation")
	var slots: Array = pool.slots
	for index in range(count,count+to_emit):
		while slots.size() <= index: slots.append([0,0,0,0,0,0,0,0,0,0,0,0,0])
		var p: Array = slots[index]
		p[0] = _word(float(x)); p[1] = _word(float(y))
		# First source random access49C08B follows coordinate stores.
		if not _rng_valid(rng):return _error("Native particle RNG thread-state bytes are unresolved")
		var speed := X.add(X.multiply([float(Rng.bounded(rng,2)),0.0],_number("0x49c244")),_number("0x49c248"))
		p[3] = _single(X.multiply_pair(speed,_constant("0x49c250")))
		var angle := X.multiply(X.multiply([float(Rng.bounded(rng,5)),0.0],_number("0x49c25c")),_number("0x49c264"))
		p[2] = _single(X.add(_neg(angle),_number("0x49c26c")))
		var turning := X.multiply_pair([float(Rng.bounded(rng,3)),0.0],_constant("0x49c270"))
		p[4] = _single(X.add(_neg(turning),_number("0x49c27c")))
		p[5] = 0x3eb33333
		var decay := X.add(X.multiply_pair([float(Rng.bounded(rng,2)),0.0],_constant("0x49c284")),_number("0x49c290"))
		decay = [X.stored_double(decay),0.0]
		decay = X.add(X.multiply_pair([float(Rng.bounded(rng,2)),0.0],_constant("0x49c284")),X.stored_double(decay))
		decay = [X.stored_double(decay),0.0]
		decay = X.add(_neg(X.multiply_pair([float(Rng.bounded(rng,2)),0.0],_constant("0x49c284"))),X.stored_double(decay))
		decay = [X.stored_double(decay),0.0]
		decay = X.add(X.multiply_pair([float(Rng.bounded(rng,2)),0.0],_constant("0x49c284")),X.stored_double(decay))
		p[6] = _single(decay)
		var color_index := Rng.bounded(rng,100)
		if distribution[color_index] == null: return _error("Native particle selected an uninitialized stack color cell; provide its observed profile")
		p[12] = color_index; p[7] = int(distribution[color_index]); p[8] = p[5]; p[11] = 0x40c00000
		pool.count = int(pool.count)+1
	return {"ok":true,"emitted":to_emit,"color_slots_written":cursor}

static func update_solid(pool: Dictionary, rng: Dictionary, native_trig: Callable) -> Dictionary:
	if bool(pool.frozen): return {"ok":true,"updated":0}
	var slots: Array = pool.slots
	var index := 0
	# Native deletion deliberately advances after shifting; adjacent expired
	# entries can survive one frame. Preserve this source loop behavior.
	while index < int(pool.count):
		if _float(int(slots[index][5])) <= 0.0:
			for destination in range(index,int(pool.count)-1): slots[destination] = slots[destination+1].duplicate()
			pool.count = int(pool.count)-1
		index += 1
	for current in int(pool.count):
		var p: Array = slots[current]
		var angle := _float(int(p[2]))
		var speed := _float(int(p[3]))
		if not native_trig.is_valid():return _error("Native x87 FSIN/FCOS primitive provider is unresolved")
		var cosine: Array = native_trig.call(angle,"cos")
		if cosine.is_empty(): return _error("Native FCOS result is unresolved")
		p[0] = _single(X.add(X.multiply(cosine,speed),_float(int(p[0]))))
		var sine: Array = native_trig.call(angle,"sin")
		if sine.is_empty(): return _error("Native FSIN result is unresolved")
		p[1] = _single(X.add(_neg(X.multiply(sine,speed)),_float(int(p[1]))))
		p[2] = _single(X.add([_float(int(p[4])),0.0],angle))
		p[5] = _single(X.add([_float(int(p[5])),0.0],-_float(int(p[6]))))
		#49C3C8 is reached only after deletion and deterministic movement.
		if not _rng_valid(rng):return _error("Native particle RNG thread-state bytes are unresolved")
		var drift := X.multiply_pair([float(Rng.bounded(rng,5)),0.0],_constant("0x49c5ec"))
		p[1] = _single(X.add(drift,_float(int(p[1]))))
		if X.compare_to_double(X.add([_float(int(p[0])),0.0],-_number("0x49c5f8")),0.0)<0:
			p[2] = _single(X.add([_number("0x49c5fc"),0.0],-_float(int(p[2]))))
		if float(int(pool.height)-1) < _float(int(p[1])):
			p[2] = _single(X.add([_number("0x49c604"),0.0],_float(int(p[2]))))
		if X.compare_to_double(X.add([_float(int(p[0])),0.0],_number("0x49c5f8")),float(pool.width))>0:
			p[2] = _single(X.add([_number("0x49c5fc"),0.0],-_float(int(p[2]))))
		if _float(int(p[1])) < _number("0x49c5f8"):
			p[2] = _single(X.add([_number("0x49c604"),0.0],_float(int(p[2]))))
		var color := int(p[7]); var background := int(pool.background)
		for channel in range(3):
			var old := (color>>(8*channel))&255
			var target := (background>>(8*channel))&255
			var mixed := Actions._trunc(X.add(X.multiply_pair([float(target-old),0.0],_constant("0x49c60c")),float(old)))&255
			color = (color & ~(255 << (8*channel))) | (mixed << (8*channel))
		p[7] = color
		p[11] = _single(X.add([_float(int(p[11])),0.0],_number("0x49c618")))
	return {"ok":true,"updated":int(pool.count)}

static func clear_solid(pool: Dictionary) -> void:
	# Native 49BAC8 updates coordinates in old slots, retains their other cells.
	for index in int(pool.count): pool.slots[index][0] = 0xc1200000; pool.slots[index][1] = 0xc1200000
	pool.count = 0; pool.already_drawn = true

static func create_bubbles(rect: Array, surface: int, color: int, background: int, region_profile: Dictionary = {}) -> Dictionary:
	return {"count":0,"slots":[],"call_count":0,"enabled":true,"rect":rect.duplicate(),"width":absi(int(rect[2])-int(rect[0])),"height":absi(int(rect[3])-int(rect[1])),"surface":surface,"color":color,"background":background,"center_x":0,"center_y":0,"region":region_profile.duplicate(true),"native_constructor":0x499328}

static func emit_bubbles(pool: Dictionary, left: int, right: int, orientation: int, center_y: int, center_x: int, shape: int, speed: int, requested_count: int, bottom_offset: int, rng: Dictionary) -> Dictionary:
	pool.center_x = center_x; pool.center_y = center_y
	shape = mini(shape,4)
	if requested_count<0: requested_count=1
	pool.call_count = (int(pool.call_count)+1)&0xffffffff
	if int(pool.call_count)>=0x80000000: pool.call_count = int(pool.call_count)-0x100000000
	if int(pool.count)>400 or not bool(pool.enabled) or int(pool.call_count)%3!=0: return {"ok":true,"emitted":0}
	if int(pool.count)+requested_count>400: return _error("Native bubble emission overwrites the particle-array boundary at +5150")
	var region: Dictionary = pool.region
	var collided := not region.is_empty()
	if collided and not region.get("points",null) is Array: return _error("Native region bubble source-point array +BD88 is missing")
	if collided:
		var eligible := false
		for point in region.points:
			if int(point[0])>left+1 and int(point[0])<right-1: eligible=true
		if not eligible and requested_count>0: return _error("Native region bubble rejection loop has no eligible original point")
	var count := int(pool.count)
	var slots: Array = pool.slots
	for index in range(count,count+requested_count):
		while slots.size()<=index: slots.append([0,0,0,0,0,0,0,0,0,0,0,0,0])
		var p: Array = slots[index]
		if collided:
			if region.points.size()!=0 and not _rng_valid(rng):return _error("Native bubble RNG thread-state bytes are unresolved")
			var point: Array
			while true:
				point = region.points[Rng.bounded(rng,region.points.size())]
				if int(point[0])>left+1 and int(point[0])<right-1: break
			p[0] = _word(float(point[0])); p[1] = _word(float(int(point[1])-5))
		else:
			if center_x==0 and center_y==0:
				p[10] = int(p[10])&0xffffff00
				var source_bound:int=int(pool.rect[2])-int(pool.rect[0])-left-10
				if source_bound!=0 and not _rng_valid(rng):return _error("Native bubble RNG thread-state bytes are unresolved")
				p[0] = _word(float(Rng.bounded(rng,source_bound)+left))
				p[1] = _word(float(int(pool.rect[3])-int(pool.rect[1])-bottom_offset))
			else:
				p[10] = (int(p[10])&0xffffff00)|1
				if not _rng_valid(rng):return _error("Native bubble RNG thread-state bytes are unresolved")
				var first_x := Rng.bounded(rng,2)
				p[0] = _word(float(first_x+center_x-Rng.bounded(rng,2)))
				var first_y := Rng.bounded(rng,2)
				p[1] = _word(float(first_y+center_y-Rng.bounded(rng,2)))
			if orientation==1: p[10] = int(p[10])&0xffffff00
		if not _rng_valid(rng):return _error("Native bubble RNG thread-state bytes are unresolved")
		var angle := X.add(X.multiply(X.multiply([float(Rng.bounded(rng,3)),0.0],_number("0x49aa5c")),_number("0x49aa64")),_number("0x49aa6c"))
		p[2] = _single(angle)
		p[4] = _single(X.add(X.multiply(X.multiply([float(Rng.bounded(rng,3)),0.0],_number("0x49aa74")),_number("0x49aa64")),_number("0x49aa7c")))
		p[5] = 0x3f800000; p[7] = int(pool.color); p[8] = p[5]
		if shape<1:
			p[9] = 1
			p[3] = _word(float(Rng.bounded(rng,speed-5)+1))
		else:
			if shape<4: shape=2
			p[9] = Rng.bounded(rng,shape)+1
			p[3] = _word(float(int(float(speed)/float(p[9]))))
			if _float(int(p[3]))==0.0: p[3] = 0x3f800000
		pool.count = int(pool.count)+1
	return {"ok":true,"emitted":requested_count}

static var _ir: Dictionary = {}
static func update_bubbles(pool: Dictionary, rng: Dictionary, native_trig: Callable) -> Dictionary:
	if _ir.is_empty(): _ir = JSON.parse_string(FileAccess.get_file_as_string("res://data/original_particle_ir.json"))
	var Vm = preload("res://scripts/original/original_particle_vm.gd")
	var vm = Vm.new()
	vm.rng=rng;vm.trig=native_trig;vm.width=int(pool.width);vm.height=int(pool.height)
	for address in _ir.constants: vm.write(str(address).hex_to_int(),str(_ir.constants[address]).hex_decode())
	var base: int=Vm.POOL
	# This allocation is an explicitly zeroed Delphi InitInstance object,
	# unlike the plain apparatus block. Preserve every active DWORD record.
	vm.map_zero(base+0x10,0xfc20-0x10)
	for index in pool.slots.size():
		for cell in 13: vm.put(base+0x10+index*52+cell*4,int(pool.slots[index][cell]))
	vm.put(base+0x5150,int(pool.count))
	vm.put(base+0x515c,int(pool.rect[0]));vm.put(base+0x5160,int(pool.rect[1]));vm.put(base+0x5164,int(pool.rect[2]));vm.put(base+0x5168,int(pool.rect[3]))
	vm.put(base+0x7f00,int(pool.surface));vm.put(base+0xfc18,int(pool.center_x));vm.put(base+0xfc1c,int(pool.center_y))
	var region: Dictionary=pool.region
	if not region.is_empty():
		if not region.get("boundary",null) is Array or not region.get("angles",null) is Array: return _error("Original bubble collision boundary/angle arrays are unresolved")
		if region.boundary.size()!=region.angles.size(): return _error("Original bubble collision boundary/angle counts differ")
		vm.put(base+0x7ef8,1);vm.put(base+0xfc0c,region.boundary.size())
		for index in region.boundary.size():
			vm.put(base+0x7f08+8*index,int(region.boundary[index][0]));vm.put(base+0x7f0c+8*index,int(region.boundary[index][1]))
			vm.write(base+0xdccc+4*index,PackedFloat32Array([float(region.angles[index])]).to_byte_array())
	vm.registers.eax=base
	var result: Dictionary=vm.execute(_ir.functions.bubble_update,0x49aa88)
	if not result.ok:return result
	pool.count=vm.integer(base+0x5150)
	if int(pool.count)>400:return _error("Original bubble update corrupted its array count beyond the object boundary")
	var slots: Array=pool.slots
	while slots.size()<int(pool.count): slots.append([0,0,0,0,0,0,0,0,0,0,0,0,0])
	# Retain old inactive entries too: native deletion shifts, then decrements;
	# it does not clear the former final record.
	for index in slots.size():
		for cell in 13: slots[index][cell]=vm.integer(base+0x10+index*52+cell*4)
	return {"ok":true,"updated":int(pool.count),"native_function":0x49aa88}
