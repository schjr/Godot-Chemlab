class_name OriginalHeapVm
extends "res://scripts/original/original_particle_vm.gd"
## Isolated extensions for actual integer allocator instructions; no allocator
## algorithm is hosted here. The source IR controls lists, coalescing and copies.
const Bytes=preload("res://scripts/original/original_heap_memory.gd")
var byte_memory=Bytes.new()
var backwards:=false
func read(address:int,size:int)->PackedByteArray:
	var result:PackedByteArray=byte_memory.read(address,size)
	if not byte_memory.error.is_empty():error=byte_memory.error
	return result
func write(address:int,bytes:PackedByteArray)->void:
	byte_memory.write(address,bytes)
	if not byte_memory.error.is_empty():error=byte_memory.error
func put(address:int,value:int,size:int=4)->void:
	var bytes:=PackedByteArray();bytes.resize(size)
	for offset in size:bytes[offset]=(value>>(offset*8))&255
	write(address,bytes)
func contains_span(address:int,size:int)->bool:return byte_memory.contains_span(address,size)
func _helper(address:int)->bool:
	if instructions.has(address):
		var ins:Dictionary=instructions[address];var ops:Array=ins.operands
		match str(ins.mnemonic):
			"or":
				var a:int=_value(ops[0]);var b:int=_value(ops[1]);var value:int=a|b
				_flags(a,b,value,int(ops[0].size),false);carry=false;overflow=false;_assign(ops[0],value)
			"xchg":
				var a:int=_value(ops[0]);var b:int=_value(ops[1]);_assign(ops[0],b);_assign(ops[1],a)
			"cld":backwards=false
			"std":backwards=true
			"js":
				pc=_value(ops[0]) if sign_flag else int(ins.next);return true
			"movsd","rep movsd","rep movsb":
				var count:int=1 if ins.mnemonic=="movsd" else int(registers.ecx)
				var size:int=1 if ins.mnemonic=="rep movsb" else 4
				if count>0x4000000:error="Native copy instruction exceeds memory boundary budget";return true
				for _index in count:
					var bytes:PackedByteArray=read(int(registers.esi),size)
					if not error.is_empty():return true
					write(int(registers.edi),bytes)
					registers.esi=(int(registers.esi)+(-size if backwards else size))&0xffffffff
					registers.edi=(int(registers.edi)+(-size if backwards else size))&0xffffffff
				if ins.mnemonic!="movsd":registers.ecx=0
			_:return super._helper(address)
		pc=int(ins.next);return true
	return super._helper(address)
