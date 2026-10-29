class_name OriginalParticlePixelLoops
extends RefCounted
## Exact retained49C620/49CDD8 loop bodies. Prefix and final pixel/suffix remain IR.
const X=preload("res://scripts/original/original_x87.gd")
const Actions=preload("res://scripts/original/original_apparatus_actions.gd")
static func _rgb(color:int)->int:return ((color>>16)&255)|(color&0xff00)|((color&255)<<16)
static func _rows(vm,metadata:Dictionary,primary:bool)->Dictionary:
	var bp:int=vm.registers.ebp
	if not vm.contains_span(bp-4,4):return {}
	var pool:int=vm.integer(bp-4)
	if not vm.contains_span(pool+0x34678,4):return {}
	var bitmap:int=vm.integer(pool+0x34678)
	if not metadata.has(bitmap):return {}
	var w:int=metadata[bitmap].width;var h:int=metadata[bitmap].height
	if w<3 or h<2 or h>800 or w>10000:return {}
	var output:Dictionary={"pool":pool,"width":w,"height":h,"retained":[],"retained_addresses":[],"primary":[]}
	var spans:Array=[]
	for table in ([0x339e8,0x32d68] if primary else [0x339e8]):
		if not vm.contains_span(pool+table,h*4):return {}
		for y in h:
			var address:int=vm.integer(pool+table+y*4)
			if address<=0 or not vm.contains_span(address,w*4):return {}
			spans.append([address,address+w*4])
			if table==0x339e8:output.retained.append(vm.read(address,w*4));output.retained_addresses.append(address)
			else:output.primary.append(vm.read(address,w*4))
	spans.sort_custom(func(a,b):return int(a[0])<int(b[0]))
	for index in range(1,spans.size()):
		if int(spans[index][0])<int(spans[index-1][1]):return {} # Aliased rows need original ordering.
	return output
static func _mix_stack(vm,pool:int,old_word:int,average:int,mixed:int,run:bool)->void:
	var bp:int=vm.registers.ebp;var nested:int=bp-0x28
	vm.put(bp-0x24,0x49cc68);vm.put(nested,bp)
	for pair in [[-0xc,0x5951e0],[-8,0x595204],[-4,pool],[-0x10,0x3f7ae148 if run else 0],[-0x14,0x3ca3d70a if run else 0x3f800000],[-0x18,mixed],[-0x1c,average],[-0x20,(old_word>>16)&255],[-0x24,(average>>16)&255]]:vm.put(nested+int(pair[0]),int(pair[1]))
	vm.put(nested-0x28,0x49bab7)
static func solid(vm,metadata:Dictionary)->void:
	var bp:int=vm.registers.ebp
	var state:=_rows(vm,metadata,true)
	if not state.is_empty() and vm.contains_span(0x59520c,8) and vm.contains_span(0x57a6f8,4):
		var w:int=state.width;var h:int=state.height;var pool:int=state.pool
		var background:int=vm.integer(0x59520c);var previous:int=vm.integer(0x595210)
		var target:=_rgb(background);var old_target:=_rgb(previous)
		var run:bool=vm.integer(0x57a6f8)!=0
		var old_weight:float=PackedByteArray([0x48,0xe1,0x7a,0x3f]).decode_float(0) if run else 0.0
		var new_weight:float=PackedByteArray([0x0a,0xd7,0xa3,0x3c]).decode_float(0) if run else 1.0
		var last_neighbors:Array=[];var last_average:=0;var last_old_word:=0;var last_mixed:=0
		var last_retained:=0;var last_current:=0;var processed:=false
		for y in range(1,h):
			var retained:PackedByteArray=state.retained[y]
			for x in range(1,w-1):
				if y==h-1 and x==w-2:break # Exact final pixel and exits execute original IR.
				var old_word:int=retained.decode_u32(x*4);var current:int=state.primary[y].decode_u32(x*4)
				var mixed:=old_word
				if (current&0xffffff)!=target:
					var below:int=y+1 if y+1<h else y
					var neighbors:Array=[state.primary[y].decode_u32((x+1)*4),state.primary[y].decode_u32((x-1)*4),state.primary[y-1].decode_u32(x*4),state.primary[below].decode_u32(x*4),state.primary[y-1].decode_u32((x-1)*4),state.primary[below].decode_u32((x-1)*4),state.primary[y-1].decode_u32((x+1)*4),state.primary[below].decode_u32((x+1)*4)]
					var average:=0
					for shift in [0,8,16]:
						var sum:=0
						for word in neighbors:sum+=(int(word)>>shift)&255
						var channel:int=sum>>3;average|=channel<<shift
						# Two float32 weights ×8-bit integers and their sum fit exactly
						# in binary64, matching source x87 before truncation.
						var value:int=int(float((old_word>>shift)&255)*old_weight+float(channel)*new_weight)
						mixed=(mixed&~(255<<shift))|((value&255)<<shift)
					last_neighbors=neighbors;last_average=average;last_old_word=old_word;last_mixed=mixed
				elif background!=previous and (old_word&0xffffff)==old_target and (old_word&0xffffff)!=target:mixed=(old_word&0xff000000)|target
				retained.encode_u32(x*4,mixed);last_retained=mixed;last_current=current;processed=true
			vm.write(int(state.retained_addresses[y]),retained)
		if not last_neighbors.is_empty():
			for index in 8:vm.put(0x5951e4+index*4,int(last_neighbors[index]))
			vm.put(0x5951e0,last_average);_mix_stack(vm,pool,last_old_word,last_average,last_mixed,run)
		if processed:vm.put(0x595204,last_retained);vm.put(0x595208,last_current)
		vm.put(bp-0x14,h-1);vm.put(bp-0x18,w-2)
	# Execute the original first MOV of this loop, including the fallback path.
	vm.registers.edx=vm.integer(bp-0x14);vm.pc=0x49c999
static func fade(vm,metadata:Dictionary)->void:
	var bp:int=vm.registers.ebp
	var state:=_rows(vm,metadata,false)
	if not state.is_empty() and state.height>=3 and vm.contains_span(bp+8,8) and vm.contains_span(bp-0x18,8) and vm.contains_span(0x49cf58,4) and vm.contains_span(int(state.pool)+0x32d50,4):
		var factor:float=vm.read(bp+8,8).decode_double(0);var inverse:float=vm.read(bp-0x18,8).decode_double(0)
		var half:float=vm.read(0x49cf58,4).decode_float(0)
		# This bound keeps all source truncations inside signed32-bit range;
		# negative channels retain the source low-byte wrap, without a new clamp.
		if is_finite(factor) and is_finite(inverse) and absf(factor)<=1000000.0 and absf(inverse)<=1000000.0 and half==0.5:
			var background:=_rgb(vm.integer(int(state.pool)+0x32d50));var lookup:Array=[];var valid:=true
			for shift in [0,8,16]:
				var channels:Array=[];var base:Array=X.add(X.multiply([float((background>>shift)&255),0.0],inverse),half)
				for value in 256:
					var pair:Array=X.add_pair(X.add(X.multiply([float(value),0.0],factor),half),base)
					if pair.is_empty():valid=false;break
					channels.append(mini(255,Actions._trunc(pair))&255)
				lookup.append(channels)
			if valid:
				var w:int=state.width;var h:int=state.height
				for y in range(1,h-1):
					var retained:PackedByteArray=state.retained[y]
					for x in range(1,w-1):
						if y==h-2 and x==w-2:break
						var word:int=retained.decode_u32(x*4)
						retained.encode_u32(x*4,(word&0xff000000)|int(lookup[0][word&255])|(int(lookup[1][(word>>8)&255])<<8)|(int(lookup[2][(word>>16)&255])<<16))
					vm.write(int(state.retained_addresses[y]),retained)
				vm.put(bp-0x30,h-2);vm.put(bp-0x34,w-2)
	vm.registers.eax=vm.integer(bp-0x30);vm.pc=0x49ce0b
