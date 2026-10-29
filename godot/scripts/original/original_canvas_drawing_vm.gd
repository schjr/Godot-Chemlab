class_name OriginalCanvasDrawingVm
extends "res://scripts/original/original_canvas_constructor_vm.gd"
func _helper(address:int)->bool:
	if instructions.has(address):
		var ins:Dictionary=instructions[address]
		if str(ins.mnemonic)=="not":
			var op:Dictionary=ins.operands[0]
			_assign(op,(~_value(op))&_mask(int(op.size))) # NOT leaves all flags unchanged.
			pc=int(ins.next);return true
	return super._helper(address)
