class_name OriginalBitmapCanvas
extends "res://scripts/original/original_canvas_constructor.gd"
## Complete original lazy GetCanvas/derived constructor; source Handle prefix
## stops before true Win32 DC creation or unported shared-image copy.
const BitmapVm=preload("res://scripts/original/original_bitmap_canvas_vm.gd")
var frontier:Dictionary={}
func initialize(world:Dictionary,boundary:Callable)->Dictionary:
	vm=BitmapVm.new()
	var ready:Dictionary=super.initialize(world,boundary)
	if not ready.ok:return ready
	vm.fs_base=int(world.thread.fs_base)
	var extension:Dictionary=JSON.parse_string(FileAccess.get_file_as_string("res://data/original_bitmap_canvas_ir.json"))
	if extension.source_sha256!=SOURCE_SHA or str(extension.mapped_image_sha256)!=str(program.image_sha256) or int(extension.image_size)!=int(program.image_size):return _error("Original lazy Canvas source image differs")
	var instructions:Dictionary={}
	for instruction in program.instructions:instructions[int(instruction.address)]=instruction
	for instruction in extension.instructions:
		var address:int=int(instruction.address)
		if instructions.has(address) and instructions[address]!=instruction:return _error("Conflicting original Canvas instruction")
		instructions[address]=instruction
	program.instructions=instructions.values()
	vm.helpers[0x55527e]=Callable(self,"_dc_frontier")
	vm.helpers[0x4e9070]=Callable(self,"_copy_frontier")
	return {"ok":true,"scope":"Original lazy Canvas and bounded source Handle prefix only","native_vcl_verified":false}
func _dc_frontier(_machine)->void:
	frontier={"api":"CreateCompatibleDC","address":0x55527e,"hdc":_argument(0)}
	events.append(frontier.duplicate(true));vm.error="Original Win32 CreateCompatibleDC result remains unresolved; no handle fabricated"
func _copy_frontier(_machine)->void:
	frontier={"api":"unported_native_bitmap_copy","address":0x4e9070}
	events.append(frontier.duplicate(true));vm.error="Original shared-image copy4E9070 remains unresolved"
func get_canvas(bitmap:int)->Dictionary:
	if not initialized:return _error("Original Canvas world is uninitialized")
	if vm.integer(bitmap)!=0x4e2af4:return _error("Original TBitmap VMT/backing unresolved")
	var result:Dictionary=_execute(0x4e9448,-1,bitmap)
	if result.ok:result["canvas"]=int(vm.registers.eax)
	return result
func handle_prefix(canvas:int)->Dictionary:
	if not initialized:return _error("Original Canvas world is uninitialized")
	if vm.integer(canvas)!=0x4e80d0:return _error("Original TBitmapCanvas VMT/backing unresolved")
	var result:Dictionary=_execute(0x4e4b84,-1,canvas)
	result["frontier"]=frontier.duplicate(true)
	return result
