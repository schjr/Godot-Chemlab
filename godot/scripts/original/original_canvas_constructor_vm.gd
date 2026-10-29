class_name OriginalCanvasConstructorVm
extends "res://scripts/original/original_pen_vm.gd"
## Source InitInstance string stores; no object-level zeroing shortcut.
func _helper(address:int)->bool:
	if instructions.has(address):
		var ins:Dictionary=instructions[address]
		if str(ins.mnemonic)=="shl":
			var ops:Array=ins.operands;var size:int=int(ops[0].size);var width:int=size*8
			var count:int=_value(ops[1])&31;var value:int=_value(ops[0])&_mask(size)
			if count>0:
				var shifted:int=(value<<count)&_mask(size)
				_flags(value,0,shifted,size,false)
				carry=((value>>(width-count))&1)!=0 if count<=width else false
				if count==1:overflow=(((shifted>>(width-1))&1)!=0)!=carry
				_assign(ops[0],shifted)
			pc=int(ins.next);return true
		if str(ins.mnemonic) in ["stosd","rep stosd","rep stosb"]:
			var size:int=1 if str(ins.mnemonic)=="rep stosb" else 4
			var count:int=1 if str(ins.mnemonic)=="stosd" else int(registers.ecx)
			if count>0x100000:error="Original InitInstance instruction budget exceeded";return true
			for index in count:
				put(int(registers.edi),int(registers.eax),size)
				if not error.is_empty():return true
				registers.edi=(int(registers.edi)+(-size if backwards else size))&0xffffffff
			if str(ins.mnemonic)!="stosd":registers.ecx=0
			pc=int(ins.next);return true
	return super._helper(address)
