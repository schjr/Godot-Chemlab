extends SceneTree
const Live=preload("res://scripts/original/original_live_particles.gd")
var failures:Array=[]
func check(ok:bool,message:String)->void:
	if not ok:failures.append(message)
func exact_zero_trig(value:float,kind:String)->Array:
	if value!=0.0:return []
	return [1.0,0.0] if kind=="cos" else [0.0,0.0]
func record()->Array:
	var row:Array=[];row.resize(13);row.fill(0)
	row[0]=PackedFloat32Array([5.0]).to_byte_array().decode_u32(0)
	row[1]=PackedFloat32Array([10.0]).to_byte_array().decode_u32(0)
	row[3]=0x3f800000;row[5]=0x3f800000;row[6]=0x3dcccccd
	return row
func _initialize()->void:
	for unknown in [{},{"low":null,"high":null},{"low":-1,"high":0},{"low":0.5,"high":0}]:
		var untouched:Dictionary=unknown.duplicate(true)
		var solid:=Live.create_solid([0,0,40,50]);solid.count=2000
		check(Live.emit_solid(solid,[],[],0,0,unknown).ok,"Source cap no-op does not read RNG")
		solid=Live.create_solid([0,0,40,50])
		check(Live.emit_solid(solid,[],[],0,0,unknown).ok,"Empty emission does not read RNG")
		check(Live.emit_solid(solid,[0x112233],[0.99],0,0,unknown).ok,"Subunit emission does not read RNG")
		check(Live.update_solid(solid,unknown,Callable()).ok,"Empty update does not require RNG or trig")
		solid.count=1;solid.slots=[record()];solid.frozen=true
		check(Live.update_solid(solid,unknown,Callable()).ok,"Frozen update does not read RNG")
		solid.frozen=false;solid.slots[0][5]=0
		check(Live.update_solid(solid,unknown,Callable()).ok and solid.count==0,"Delete-only native update reaches no trig/random access")
		var bubble:=Live.create_bubbles([0,0,40,50],20,0x112233,0xffffff)
		check(Live.emit_bubbles(bubble,10,40,0,0,0,3,8,1,5,unknown).ok and bubble.call_count==1,"Throttled bubble call preserves source pre-access writes")
		bubble.call_count=2
		check(Live.emit_bubbles(bubble,10,40,0,0,0,3,8,0,5,unknown).ok and bubble.call_count==3,"Zero requested bubbles do not read RNG")
		check(Live.update_bubbles(bubble,unknown,Callable()).ok,"Empty retained bubble VM does not read RNG")
		check(unknown==untouched,"No-op never writes missing/malformed TLS bytes")
		solid=Live.create_solid([0,0,40,50])
		var emission:=Live.emit_solid(solid,[0x112233],[1.0],10,20,unknown)
		check(not emission.ok and str(emission.error).contains("RNG"),"Actual solid emission random access rejects unknown state")
		check(solid.count==0 and solid.slots[0][0]==PackedFloat32Array([20.0]).to_byte_array().decode_u32(0),"Source coordinates are written before first random access")
		solid=Live.create_solid([0,0,40,50]);solid.count=1;solid.slots=[record()]
		var update:=Live.update_solid(solid,unknown,Callable(self,"exact_zero_trig"))
		check(not update.ok and str(update.error).contains("RNG"),"Live solid rejects unknown RNG only at drift access")
		check(solid.slots[0][0]==PackedFloat32Array([6.0]).to_byte_array().decode_u32(0),"Deterministic movement precedes native drift random access")
		bubble=Live.create_bubbles([0,0,40,50],20,0x112233,0xffffff);bubble.call_count=2
		var emitted:=Live.emit_bubbles(bubble,10,40,0,0,0,3,8,1,5,unknown)
		check(not emitted.ok and str(emitted.error).contains("RNG") and bubble.call_count==3,"Eligible bubble random access rejects after source throttle writes")
		bubble=Live.create_bubbles([0,0,20,50],20,0x112233,0xffffff);bubble.call_count=2
		var zero_position:=Live.emit_bubbles(bubble,10,20,0,0,0,3,8,1,5,unknown)
		check(not zero_position.ok and str(zero_position.error).contains("RNG"),"Zero-bound position defers rejection until nonzero angle access")
		check(bubble.slots[0][0]==PackedFloat32Array([10.0]).to_byte_array().decode_u32(0) and bubble.slots[0][1]==PackedFloat32Array([45.0]).to_byte_array().decode_u32(0),"Zero-bound source position stores occur without observing RNG")
	print(JSON.stringify({"failures":failures}))
	if failures.is_empty():print("PASS direct original particle helpers require RNG only at source random accesses")
	quit(0 if failures.is_empty() else 1)
