class_name OriginalUiClock
extends RefCounted
const X87=preload("res://scripts/original/original_x87.gd")
const TICK_CONSTANT="3bdf4f8d976e1283f53f"
static func signed32(value:int)->int:
	var word:=value&0xffffffff
	return word-4294967296 if word>=2147483648 else word
static func poll(state:Dictionary,milliseconds:int,run_flag:int,held:bool)->Dictionary:
	#4018B0:5A8 outer cadence,57A74C accepted-physics timestamp.
	var now:=signed32(milliseconds)
	var outer:bool=signed32(now-int(state.poll_ms))>5
	var accepted:bool=outer and run_flag==1 and not held
	var delta:=0.0
	if accepted:
		delta=X87.stored_double(X87.multiply(X87.from_extended80_hex(TICK_CONSTANT),float(now)-float(signed32(int(state.physics_ms)))))
		state.physics_ms=now
	if outer:state.poll_ms=now
	return {"accepted":accepted,"outer":outer,"delta":delta}
static func mouse_up(state:Dictionary,milliseconds:int,run_flag:int)->void:
	if run_flag==1:state.physics_ms=signed32(milliseconds)
static func resume(state:Dictionary,milliseconds:int,run_flag:int)->int:
	if run_flag==2:state.physics_ms=signed32(milliseconds);return 1
	return 2 if run_flag==1 else run_flag
