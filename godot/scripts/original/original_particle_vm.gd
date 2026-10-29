class_name OriginalParticleVm
extends RefCounted
## Direct execution of retained original instruction IR for complex particle
## branches. Unsupported instructions/memory/primitive calls fail explicitly.
const X = preload("res://scripts/original/original_x87.gd")
const Rng = preload("res://scripts/original/original_particle_rng.gd")
const Actions = preload("res://scripts/original/original_apparatus_actions.gd")
const POOL := 0x1000000
const STACK := 0x9000000
const STOP := 0x8000000
var registers := {"eax":0,"ebx":0,"ecx":0,"edx":0,"esi":0,"edi":0,"ebp":0,"esp":STACK+0xff00}
var memory: Dictionary = {}
## Explicit source InitInstance/zero stores. Sparse writes override these known
## zero intervals; all addresses outside intervals and writes remain unknown.
var zero_spans:Array=[]
var zero_pages:Dictionary={} # Full-page marker or exact partial intervals.
var fp: Array = []
var carry := false
var zero := false
var sign_flag := false
var overflow := false
var parity := false
var fp_status := 0
var pc := 0
var error := ""
var rng: Dictionary
var trig: Callable
var width := 0
var height := 0
var instructions: Dictionary = {}
var helpers: Dictionary = {}

func _s32(value: int) -> int: return (value&0xffffffff)-0x100000000 if (value&0x80000000)!=0 else value&0xffffffff
func _mask(size: int) -> int: return (1<<(size*8))-1
func _register(name: String) -> int:
	if registers.has(name): return int(registers[name])
	var roots := {"ax":"eax","bx":"ebx","cx":"ecx","dx":"edx","al":"eax","bl":"ebx","cl":"ecx","dl":"edx","ah":"eax","bh":"ebx","ch":"ecx","dh":"edx"}
	if not roots.has(name): error="Unsupported native register "+name; return 0
	var value := int(registers[roots[name]])
	if name.ends_with("h"): return (value>>8)&255
	return value& (65535 if name.ends_with("x") else 255)
func _set_register(name: String, value: int) -> void:
	if registers.has(name): registers[name]=value&0xffffffff; return
	var root := "e"+name if name.ends_with("x") else "e"+name.substr(0,1)+"x"
	var shift := 8 if name.ends_with("h") else 0
	var mask := 65535 if name.ends_with("x") else 255
	registers[root]=(int(registers[root])&~(mask<<shift))|((value&mask)<<shift)
func read(address: int, size: int) -> PackedByteArray:
	var bytes := PackedByteArray()
	for offset in size:
		var at:int=address+offset
		if memory.has(at):bytes.append(int(memory[at]))
		elif _zero_byte(at):bytes.append(0)
		else:error="Read of undefined native byte at 0x%x"%at; return []
	return bytes
func _zero_byte(address:int)->bool:
	var page:int=address&~4095
	if not zero_pages.has(page):return false
	var ranges:Variant=zero_pages[page]
	if ranges is bool:return true
	for span in ranges:
		if int(span[0])<=address and address<int(span[1]):return true
	return false
func has_byte(address:int)->bool:return memory.has(address) or _zero_byte(address)
func overlaps_known_span(address:int,size:int)->bool:
	if size<=0:return false
	for span in zero_spans:
		if address<int(span[1]) and int(span[0])<address+size:return true
	for offset in size:
		if memory.has(address+offset):return true
	return false
func map_zero(address:int,size:int)->void:
	if address<0 or address>0xffffffff or size<=0 or size>0x100000000 or address+size>0x100000000:
		error="Invalid explicit native zero span";return
	var first:=address;var end:=address+size;var combined:Array=[];var inserted:=false
	for span in zero_spans:
		if int(span[1])<first:combined.append(span)
		elif end<int(span[0]):
			if not inserted:combined.append([first,end]);inserted=true
			combined.append(span)
		else:first=mini(first,int(span[0]));end=maxi(end,int(span[1]))
	if not inserted:combined.append([first,end])
	zero_spans=combined
	# Most instruction reads land in a complete cleared object page. Keep those
	# lookups constant-time without allocating a byte mask/Dictionary per byte.
	for page in range(address&~4095,(address+size+4095)&~4095,4096):
		var ranges:Array=[]
		for span in zero_spans:
			if int(span[0])>=page+4096:break
			if page<int(span[1]) and int(span[0])<page+4096:
				ranges.append([maxi(page,int(span[0])),mini(page+4096,int(span[1]))])
		zero_pages[page]=true if ranges.size()==1 and ranges[0]==[page,page+4096] else ranges
	# A repeated explicit source zero operation overwrites prior sparse writes.
	# Small object construction must not scan the entire retained thread stack.
	# Both branches erase exactly the explicitly cleared address interval.
	if size<memory.size():
		for offset in size:memory.erase(address+offset)
	else:
		for at in memory.keys():
			if address<=int(at) and int(at)<address+size:memory.erase(at)
func write(address: int, bytes: PackedByteArray) -> void:
	for offset in bytes.size(): memory[address+offset]=bytes[offset]
func contains_span(address: int,size: int) -> bool:
	for offset in size:
		if not has_byte(address+offset):return false
	return true
func put(address: int, value: int, size: int=4) -> void:
	for offset in size: memory[address+offset]=(value>>(offset*8))&255
func integer(address: int, size: int=4) -> int:
	var bytes := read(address,size)
	if bytes.size()!=size: return 0
	var value := 0
	for offset in size: value |= int(bytes[offset])<<(offset*8)
	return value
func _address(op: Dictionary) -> int:
	return (int(op.disp)+(_register(op.base) if not str(op.base).is_empty() else 0)+((_register(op.index)*int(op.scale)) if not str(op.index).is_empty() else 0))&0xffffffff
func _value(op: Dictionary) -> int:
	if op.kind=="imm": return int(op.value)
	if op.kind=="reg": return _register(op.reg)
	return integer(_address(op),int(op.size))
func _assign(op: Dictionary,value: int) -> void:
	if op.kind=="reg": _set_register(op.reg,value)
	elif op.kind=="mem": put(_address(op),value,int(op.size))
	else: error="Native write operand is not assignable"
func _float(op: Dictionary, integer_operand: bool=false) -> Array:
	if op.kind=="reg": return fp[int(str(op.reg).replace("st(","").replace(")",""))].duplicate()
	var bytes := read(_address(op),int(op.size))
	if bytes.is_empty(): return []
	if integer_operand:
		var value := integer(_address(op),int(op.size))
		if int(op.size)==4: value=_s32(value)
		return [float(value),0.0]
	if int(op.size)==10: return X.from_extended80_hex(bytes.hex_encode())
	if int(op.size)==8: return [bytes.decode_double(0),0.0]
	if int(op.size)==4: return [bytes.decode_float(0),0.0]
	error="Unsupported native floating operand width"; return []
func _push(value: int) -> void:
	registers.esp=(int(registers.esp)-4)&0xffffffff; put(int(registers.esp),value)
func _pop() -> int:
	var result:=integer(int(registers.esp)); registers.esp=(int(registers.esp)+4)&0xffffffff; return result
func return_helper(eax_value = null, stack_cleanup: int=0) -> void:
	if eax_value!=null:registers.eax=int(eax_value)&0xffffffff
	pc=_pop();registers.esp=int(registers.esp)+stack_cleanup
func _flags(a: int,b: int,result: int,size: int,subtract: bool) -> void:
	var mask:=_mask(size);var msb:=1<<(size*8-1);var aa:=a&mask;var bb:=b&mask;var rr:=result&mask
	carry=aa<bb if subtract else result>mask
	zero=rr==0;sign_flag=(rr&msb)!=0
	overflow=(((aa^bb)&(aa^rr)&msb)!=0) if subtract else (((~(aa^bb))&(aa^rr)&msb)!=0)
	var bit_count:=0
	for bit in 8: bit_count+=(rr>>bit)&1
	parity=bit_count%2==0
func _compare_fp(a: Array,b: Array) -> void:
	var difference:=X.add_pair(a,X.multiply(b,-1.0))
	if difference.is_empty(): error="Unresolved original x87 comparison"; return
	var comparison:=X.compare_to_double(difference,0.0)
	fp_status=0x100 if comparison<0 else 0x4000 if comparison==0 else 0
func _observed_rng_dword(value:Variant)->bool:
	if value is int:return value>=0 and value<=0xffffffff
	# Lossless JSON decoding may carry an observed DWORD as an integral double.
	return value is float and is_finite(value) and value>=0.0 and value<=4294967295.0 and value==floor(value)
func _helper(address: int) -> bool:
	if helpers.has(address):
		var callback: Callable=helpers[address]
		callback.call(self)
		return true
	if address==0x4028ec:
		var bound:=_s32(integer(int(registers.esp)+4))
		if bound!=0 and (not _observed_rng_dword(rng.get("low",null)) or not _observed_rng_dword(rng.get("high",null))):
			error="Original random thread-state bytes are unresolved";return true
		registers.eax=Rng.bounded(rng,bound)
	elif address==0x539238 or address==0x53aca8:
		if not trig.is_valid(): error="Original FSIN/FCOS provider is unresolved";return true
		var bytes:=read(int(registers.esp)+4,8)
		var result: Array=trig.call(bytes.decode_double(0),"cos" if address==0x539238 else "sin")
		if result.is_empty(): error="Original trig primitive result is unresolved"; return true
		fp.push_front(result)
	elif address==0x5394d4:
		var bytes:=read(int(registers.esp)+4,8);fp.push_front([absf(bytes.decode_double(0)),0.0])
	elif address==0x5394fc:
		if fp.is_empty(): error="Native FTOL stack underflow";return true
		var value: Array=fp.pop_front();var converted:=Actions._trunc(value)
		registers.eax=converted&0xffffffff;registers.edx=(converted>>32)&0xffffffff
	elif address==0x8000040: registers.eax=height
	elif address==0x8000050: registers.eax=width
	else: return false
	pc=_pop();return true
func execute(program: Dictionary, entry: int, max_instructions: int=2000000) -> Dictionary:
	instructions.clear()
	for instruction in program.instructions: instructions[int(instruction.address)]=instruction
	pc=entry;_push(STOP)
	for _step in max_instructions:
		if pc==STOP or pc==int(program.get("end",-1)): return {"ok":error.is_empty(),"error":error}
		if not error.is_empty(): return {"ok":false,"error":error,"pc":pc}
		if _helper(pc): continue
		if not instructions.has(pc): return {"ok":false,"error":"Unresolved original particle instruction 0x%x"%pc}
		var ins: Dictionary=instructions[pc];var ops: Array=ins.operands;var mnemonic:=str(ins.mnemonic);pc=int(ins.next)
		match mnemonic:
			"nop": pass
			"neg":
				var value := _value(ops[0])
				_flags(0,value,-value,int(ops[0].size),true)
				_assign(ops[0],-value)
			"mov": _assign(ops[0],_value(ops[1]))
			"lea": _assign(ops[0],_address(ops[1]))
			"push": _push(_value(ops[0]))
			"pop": _assign(ops[0],_pop())
			"add","sub","cmp","adc","and","xor","test":
				var a:=_value(ops[0]);var b:=_value(ops[1]);var result:=a+b
				if mnemonic=="adc": b+=1 if carry else 0;result=a+b
				if mnemonic in ["sub","cmp"]: result=a-b
				if mnemonic in ["and","test"]:result=a&b
				if mnemonic=="xor":result=a^b
				_flags(a,b,result,int(ops[0].size),mnemonic in ["sub","cmp"])
				if mnemonic in ["and","xor","test"]:carry=false;overflow=false
				if mnemonic not in ["cmp","test"]:_assign(ops[0],result)
			"cdq":registers.edx=0xffffffff if _s32(int(registers.eax))<0 else 0
			"idiv":
				var dividend:=_s32(int(registers.edx))*0x100000000+(int(registers.eax)&0xffffffff)
				var divisor:=_s32(_value(ops[0]))
				if divisor==0:error="Native integer division by zero";continue
				var quotient:=int(dividend/divisor)
				registers.eax=quotient&0xffffffff;registers.edx=(dividend-quotient*divisor)&0xffffffff
			"inc","dec":
				var old_carry:=carry;var a:=_value(ops[0]);var b:=1 if mnemonic=="inc" else -1
				_flags(a,1,a+b,int(ops[0].size),mnemonic=="dec");carry=old_carry;_assign(ops[0],a+b)
			"imul":
				var a:=_s32(_value(ops[1] if ops.size()==3 else ops[0]));var b:=_s32(_value(ops[2] if ops.size()==3 else ops[1]));_assign(ops[0],a*b)
			"sar":
				var a:=_s32(_value(ops[0]));var shift:=_value(ops[1])&31
				if shift>0:carry=((a>>(shift-1))&1)!=0;_assign(ops[0],a>>shift);zero=(a>>shift)==0;sign_flag=(a>>shift)<0;overflow=false
			"rep movsd":
				for _index in int(registers.ecx):
					put(int(registers.edi),integer(int(registers.esi)));registers.edi=int(registers.edi)+4;registers.esi=int(registers.esi)+4
				registers.ecx=0
			"call":_push(pc);pc=_value(ops[0])
			"ret":pc=_pop();registers.esp=int(registers.esp)+(int(ops[0].value) if not ops.is_empty() else 0)
			"jmp":pc=_value(ops[0])
			"je","jne","jl","jg","jle","jge","jns","ja","jae","jb","jbe":
				var taken:=false
				match mnemonic:
					"je":taken=zero
					"jne":taken=not zero
					"jl":taken=sign_flag!=overflow
					"jg":taken=not zero and sign_flag==overflow
					"jle":taken=zero or sign_flag!=overflow
					"jge":taken=sign_flag==overflow
					"jns":taken=not sign_flag
					"ja":taken=not carry and not zero
					"jae":taken=not carry
					"jb":taken=carry
					"jbe":taken=carry or zero
				if taken:pc=_value(ops[0])
			"seta":_assign(ops[0],1 if not carry and not zero else 0)
			"setge":_assign(ops[0],1 if sign_flag==overflow else 0)
			"fld","fild":fp.push_front(_float(ops[0],mnemonic=="fild"))
			"fadd","fsub","fsubr","fmul","fdiv","fdivr":
				var other:=_float(ops[0]);var result: Array
				if mnemonic=="fmul":result=X.multiply_pair(fp[0],other)
				elif mnemonic=="fdiv":result=X.divide_pair(fp[0],other)
				elif mnemonic=="fdivr":result=X.divide_pair(other,fp[0])
				elif mnemonic=="fadd":result=X.add_pair(fp[0],other)
				elif mnemonic=="fsub":result=X.add_pair(fp[0],X.multiply(other,-1.0))
				else:result=X.add_pair(other,X.multiply(fp[0],-1.0))
				if result.is_empty():error="Unsupported original x87 arithmetic";continue
				fp[0]=result
			"faddp","fmulp","fsubp","fsubrp":
				var index:=int(str(ops[0].reg).replace("st(","").replace(")","")) if not ops.is_empty() else 1
				var result: Array
				if mnemonic=="faddp": result=X.add_pair(fp[index],fp[0])
				elif mnemonic=="fmulp": result=X.multiply_pair(fp[index],fp[0])
				elif mnemonic=="fsubp": result=X.add_pair(fp[index],X.multiply(fp[0],-1.0))
				else: result=X.add_pair(fp[0],X.multiply(fp[index],-1.0))
				if result.is_empty():error="Unsupported original x87 pop arithmetic";continue
				fp[index]=result;fp.pop_front()
			"fcomp":_compare_fp(fp[0],_float(ops[0]));fp.pop_front()
			"fcompp":_compare_fp(fp[0],fp[1]);fp.pop_front();fp.pop_front()
			"fnstsw":_assign(ops[0],fp_status)
			"sahf":
				var value:=_register("ah");carry=(value&1)!=0;parity=(value&4)!=0;zero=(value&64)!=0;sign_flag=(value&128)!=0
			"fstp":
				var value: Array=fp[0]
				if ops[0].kind=="reg":fp[int(str(ops[0].reg).replace("st(","").replace(")",""))]=value.duplicate()
				elif int(ops[0].size)==4:write(_address(ops[0]),PackedFloat32Array([X.stored_float32(value)]).to_byte_array())
				elif int(ops[0].size)==8:write(_address(ops[0]),PackedFloat64Array([X.stored_double(value)]).to_byte_array())
				else:error="Unsupported native floating store width"
				fp.pop_front()
			_:error="Unsupported original instruction "+mnemonic
	return {"ok":false,"error":"Original particle instruction budget exceeded","pc":pc}
