class_name OriginalPenVm
extends "res://scripts/original/original_heap_vm.gd"
## Isolated exact integer string-comparison/dynamic-table operations.
func _register(name:String)->int:
	if name in ["si","di","bp","sp"]:return int(registers["e"+name])&0xffff
	return super._register(name)
func _set_register(name:String,value:int)->void:
	if name in ["si","di","bp","sp"]:
		var root:="e"+name;registers[root]=(int(registers[root])&0xffff0000)|(value&0xffff);return
	super._set_register(name,value)
func _helper(address:int)->bool:
	if instructions.has(address):
		var ins:Dictionary=instructions[address];var ops:Array=ins.operands
		match str(ins.mnemonic):
			"movzx":_assign(ops[0],_value(ops[1])&_mask(int(ops[1].size)))
			"sete":_assign(ops[0],1 if zero else 0)
			"rol":
				var bits:int=int(ops[0].size)*8;var count:int=(_value(ops[1])&31)%bits
				if count>0:
					var value:int=_value(ops[0])&_mask(int(ops[0].size))
					var result:int=((value<<count)|(value>>(bits-count)))&_mask(int(ops[0].size))
					_assign(ops[0],result);carry=(result&1)!=0
					if count==1:overflow=(((result>>(bits-1))&1)!=0)!=carry
			"shr":
				var size:int=int(ops[0].size);var value:int=_value(ops[0])&_mask(size);var count:int=_value(ops[1])&31
				if count>0:
					var result:int=value>>count;_flags(value,0,result,size,false);carry=((value>>(count-1))&1)!=0
					if count==1:overflow=((value>>(size*8-1))&1)!=0
					_assign(ops[0],result)
			"repe cmpsb","repe cmpsd","repne scasw":
				var scan:bool=ins.mnemonic=="repne scasw";var size:int=2 if scan else 1 if ins.mnemonic=="repe cmpsb" else 4
				if int(registers.ecx)>0x100000:error="Original pen comparison instruction budget exceeded";return true
				while int(registers.ecx)>0:
					var a:int=_register("ax") if scan else integer(int(registers.esi),size)
					var b:int=integer(int(registers.edi),size)
					if not error.is_empty():return true
					_flags(a,b,a-b,size,true)
					var delta:int=-size if backwards else size
					if not scan:registers.esi=(int(registers.esi)+delta)&0xffffffff
					registers.edi=(int(registers.edi)+delta)&0xffffffff;registers.ecx=int(registers.ecx)-1
					if zero if scan else not zero:break
			_:return super._helper(address)
		pc=int(ins.next);return true
	return super._helper(address)
