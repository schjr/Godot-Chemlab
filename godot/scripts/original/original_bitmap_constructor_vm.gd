class_name OriginalBitmapConstructorVm
extends "res://scripts/original/original_canvas_constructor_vm.gd"
## Source FS operands retain the explicitly supplied thread segment base.
var fs_base:=0
func _address(op:Dictionary)->int:
	var address:int=super._address(op)
	return (address+fs_base)&0xffffffff if str(op.get("segment",""))=="fs" else address
