class_name OriginalRuntimeGasFrame
extends RefCounted
## Physical source-ABI local in this process's owned thread stack. Source
## 4018B0 ->46F704 places [gas EBP-7C] at [idle EBP-178].
## The byte world belongs to this reconstructed process, not a Windows capture.
const CALLER_FRAME_BYTES:=0xf4
const CALLEE_EBP_DELTA:=CALLER_FRAME_BYTES+8
const EXCESS_EBP_OFFSET:=0x7c
var heap
var caller_ebp:=0
var cell_address:=0
var accesses:Array=[]
func _error(message:String)->Dictionary:return {"ok":false,"error":message}
func bind(shared_heap,idle_frame_ebp:int)->Dictionary:
	if shared_heap==null or not shared_heap.initialized:return _error("Original gas stack requires the owned source heap")
	var address:int=idle_frame_ebp-CALLEE_EBP_DELTA-EXCESS_EBP_OFFSET
	var base:int=shared_heap.context.get("stack_base",0)
	var count:int=shared_heap.context.get("stack_size",0)
	if idle_frame_ebp&3!=0 or address<base or idle_frame_ebp+4>base+count:return _error("Original gas ABI frame lies outside the owned thread stack")
	if not shared_heap.vm.byte_memory.contains_span(address,8):return _error("Original gas stack cell has unknown physical bytes")
	heap=shared_heap;caller_ebp=idle_frame_ebp;cell_address=address
	return {"ok":true,"address":cell_address,"scope":str(heap.context.scope),"origin":"Owned reconstructed-thread ABI stack; original predecessor native stack effects are limited to the routines connected to this byte world"}
func read_excess()->Dictionary:
	if heap==null:return _error("Original gas stack frame is unbound")
	var result:Dictionary=heap.read_bytes(cell_address,8)
	if not result.ok:return result
	var value:float=result.bytes.decode_double(0)
	if not is_finite(value):return _error("Original gas physical stack operand is nonfinite; native exception path required")
	accesses.append({"pc":0x46fb18,"operation":"read","address":cell_address,"raw_hex":result.bytes.hex_encode()})
	return {"ok":true,"value":value,"raw_hex":result.bytes.hex_encode(),"address":cell_address}
func write_excess(value:float)->Dictionary:
	if heap==null:return _error("Original gas stack frame is unbound")
	if not is_finite(value):return _error("Original gas excess store is nonfinite; native exception path required")
	var bytes:=PackedFloat64Array([value]).to_byte_array()
	var result:Dictionary=heap.write_bytes(cell_address,bytes)
	if result.ok:accesses.append({"pc":0x46fada,"operation":"write","address":cell_address,"raw_hex":bytes.hex_encode()})
	return result
func context()->Dictionary:
	return {"source_stack_read_excess":Callable(self,"read_excess"),"source_stack_write_excess":Callable(self,"write_excess")}
