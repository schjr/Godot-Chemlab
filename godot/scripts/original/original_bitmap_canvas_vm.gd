class_name OriginalBitmapCanvasVm
extends "res://scripts/original/original_bitmap_constructor_vm.gd"
## RequiredState byte complement changes no x86 condition flags.
func _helper(address:int)->bool:
	if instructions.has(address) and str(instructions[address].mnemonic)=="not":
		var ins:Dictionary=instructions[address];var op:Dictionary=ins.operands[0]
		_assign(op,(~_value(op))&_mask(int(op.size)));pc=int(ins.next);return true
	return super._helper(address)
