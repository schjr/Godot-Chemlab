extends SceneTree
const Pen=preload("res://scripts/original/original_pen.gd")
var failures:Array=[]
var mode:="normal"
func check(ok:bool,label:String)->void:
	if not ok:failures.append(label)
func boundary(request:Dictionary)->Dictionary:
	match str(request.api):
		"EnterCriticalSection","LeaveCriticalSection":return {"ok":true}
		"GetMem":
			if mode=="unknown_padding":return {"ok":true,"address":0x2010000}
			var raw:=PackedByteArray();raw.resize(int(request.size));raw.fill(0xa5)
			return {"ok":true,"address":0x2010000,"raw_hex":raw.hex_encode()}
		"FreeMem":return {"ok":true,"memory_writes":[]}
		"DeleteObject":return {"ok":true,"result":1}
		"SelectObject":return {"ok":true,"result":0x11220000}
		"CreatePenIndirect":
			return {"ok":false,"error":"Explicit unprovided native CreatePen boundary"} if mode=="missing_create" else {"ok":true,"result":0x77770001}
	return {"ok":false,"error":"Explicit boundary absent"}
func _initialize()->void:
	var fixture:Dictionary=JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_pen.json"))
	var base:Dictionary=fixture.cases[1].world
	var absent:=base.duplicate(true);absent.globals.erase("0x59a9e4")
	var pen=Pen.new();check(not pen.initialize(absent,Callable(self,"boundary")).ok,"Registry pointer cannot default to PE BSS zero");pen.close()
	var no_stock:=base.duplicate(true);no_stock.globals.erase("0x59a9a0")
	pen=Pen.new();check(pen.initialize(no_stock,Callable(self,"boundary")).ok,"Unused stock handle may remain unobserved")
	var error:Dictionary=pen.set_color(0x2000100,0xabcdef)
	check(not error.ok and str(error.error).contains("Unobserved"),"Actual selected-canvas stock-handle read fails explicitly")
	check((pen.vm.integer(0x2000208,1)&4)==0,"Source Canvas selected bit clears before unobserved stock read")
	pen.close()
	mode="unknown_padding";pen=Pen.new();check(pen.initialize(base,Callable(self,"boundary")).ok,"Unknown allocation backing initializes scoped world")
	var result:Dictionary=pen.set_color(0x2000100,0xabcdef)
	check(result.ok,"Source writes required new-node bytes without demanding untouched allocator padding")
	check(not pen.vm.contains_span(0x201000e,2),"Untouched allocation padding remains unknown")
	check(pen.vm.contains_span(0x2010010,16),"Full actual key record is source-written")
	pen.close()
	mode="missing_create";pen=Pen.new();check(pen.initialize(base,Callable(self,"boundary")).ok,"Scoped lazy handle fixture initializes")
	check(pen.set_color(0x2000100,0xabcdef).ok,"Actual registry setter completes before lazy handle creation")
	var missing:Dictionary=pen.get_handle(0x2000100)
	check(not missing.ok and str(missing.error).contains("unprovided"),"Lazy CreatePen cannot use a fake handle default")
	pen.close()
	print(JSON.stringify({"failures":failures}))
	if failures.is_empty():print("PASS original pen unknown state and explicit allocation/graphics boundaries")
	quit(0 if failures.is_empty() else 1)
