class_name OriginalCanvasDrawing
extends "res://scripts/original/original_vcl_memory_world.gd"
## Complete source Rectangle wrapper and required pen/brush state, same graph/VM.
## Actual DC creation and Win32 raster results remain explicit dependencies.
const DrawingVm=preload("res://scripts/original/original_canvas_drawing_vm.gd")
func _init()->void:vm=DrawingVm.new()
func initialize_fresh(world:Dictionary,os_boundary:Callable,owned_primitives:Object=null)->Dictionary:
	var result:=super.initialize_fresh(world,os_boundary,owned_primitives)
	if not result.ok:return result
	var ir:Dictionary=JSON.parse_string(FileAccess.get_file_as_string("res://data/original_canvas_drawing_ir.json"))
	if ir.source_sha256!=Heap.SOURCE_SHA or ir.image_file!=heap.program.image_file or int(ir.image_size)!=int(heap.program.image_size) or ir.image_sha256!=heap.program.mapped_image_sha256:return _error("Drawing instruction source/image differs")
	var indexed:Dictionary={}
	for ins in program.instructions:indexed[int(ins.address)]=ins
	for ins in ir.instructions:
		if indexed.has(int(ins.address)) and indexed[int(ins.address)]!=ins:return _error("Conflicting retained drawing instruction")
		indexed[int(ins.address)]=ins
	program.instructions=indexed.values()
	for spec in [[0x5553e0,"Rectangle",5],[0x55547c,"UnrealizeObject",1],[0x55540a,"SetBkColor",2],[0x555410,"SetBkMode",2],[0x555434,"SetROP2",2],[0x555678,"GetSysColor",1],[0x5552b4,"CreatePenIndirect",1],[0x555272,"CreateBrushIndirect",1]]:
		vm.helpers[int(spec[0])]=Callable(self,"_drawing_api").bind(str(spec[1]),int(spec[2]))
	return result
func _signed(value:int)->int:return value-0x100000000 if value&0x80000000 else value
func _drawing_api(_machine,name:String,count:int)->void:
	var args:=_args(count);var request:Dictionary={"api":name}
	match name:
		"Rectangle":request.merge({"hdc":args[0],"left":_signed(args[1]),"top":_signed(args[2]),"right":_signed(args[3]),"bottom":_signed(args[4])})
		"CreatePenIndirect","CreateBrushIndirect":
			var raw:=vm.read(int(args[0]),12)
			if not vm.error.is_empty():return
			request["logpen_hex" if name=="CreatePenIndirect" else "logbrush_hex"]=raw.hex_encode()
		"UnrealizeObject":request.handle=args[0]
		"GetSysColor":request.index=args[0]
		"SetBkColor":request.merge({"hdc":args[0],"color":args[1]})
		"SetROP2":request.merge({"hdc":args[0],"mode":args[1]})
		"SetBkMode":request.merge({"hdc":args[0],"mode":args[1]})
	var response:Dictionary=_os(request)
	if not response.get("ok",false):vm.error=str(response.get("error","Original drawing primitive unresolved"));return
	if not response.has("result") or not _whole(response.result):vm.error="Original drawing primitive result must be an explicit DWORD";return
	vm.return_helper(int(response.result),count*4)
func register_external_event(target:int)->Dictionary:
	if not initialized or target<=0 or target>0xffffffff:return _error("Explicit external event target required")
	for ins in program.instructions:
		if int(ins.address)==target:return _error("External event cannot replace retained source instructions")
	if vm.helpers.has(target):return _error("External target already bound")
	vm.helpers[target]=Callable(self,"_drawing_event").bind(target);return {"ok":true}
func _drawing_event(_machine,target:int)->void:
	var response:Dictionary=_os({"api":"event","target":target,"owner":int(vm.registers.eax),"sender":int(vm.registers.edx)})
	if response.get("ok",false):vm.return_helper(response.get("eax_after",null))
	else:vm.error=str(response.get("error","Original external event unresolved"))
func rectangle(canvas:int,left:int,top:int,right:int,bottom:int)->Dictionary:
	if not initialized:return _error("Original Canvas drawing world is uninitialized")
	if not vm.error.is_empty():return _error(vm.error)
	# Delphi register convention: bottom/right are the two source stack inputs.
	vm.put(int(context.stack_pointer)+4,bottom&0xffffffff)
	vm.put(int(context.stack_pointer)+8,right&0xffffffff)
	return execute_entry(0x4e4744,canvas,left,top)
func required_state(canvas:int,mask:int)->Dictionary:return execute_entry(0x4e4c58,canvas,mask)
