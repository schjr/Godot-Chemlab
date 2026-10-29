extends SceneTree
const Adapter=preload("res://scripts/experiment_adapter.gd")
const Canvas=preload("res://scripts/lab_canvas.gd")
class DispatchHost extends "res://scripts/lab_model.gd":
	var calls:Array=[]
	func manual_action(id:int,command:int)->Dictionary:
		var apparatus:=native_apparatus();var index:=index_for_id(id,apparatus)
		calls.append({"index":index,"type":int(apparatus[index].type_id),"command":command})
		return {"ok":true}
func _initialize()->void:
	var data:Dictionary=JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_controls_dispatch.json"))
	var docs:Array=JSON.parse_string(FileAccess.get_file_as_string("res://data/examples.json"))
	var reagents:Array=JSON.parse_string(FileAccess.get_file_as_string("res://data/reagents.json"))
	var reactions:Array=JSON.parse_string(FileAccess.get_file_as_string("res://data/reactions.json"))
	var lab:DispatchHost;var canvas;var name:="";var errors:Array=[];var tested:=0
	for c in data.cases:
		if c.name!=name:
			if canvas!=null:canvas.free()
			lab=DispatchHost.new();lab.configure(reagents,reactions)
			var doc:Dictionary={}
			for d in docs:
				if d.name==c.name:doc=d;break
			assert(lab.from_state(Adapter.to_state(doc)))
			canvas=Canvas.new();root.add_child(canvas);canvas.configure(lab);canvas.zoom=1.0;canvas.pan=Vector2.ZERO;name=c.name
		lab.calls.clear();lab.running=int(c.run)==1;lab.paused=int(c.run)==2
		canvas.reset_native_selection();canvas.selected_id=int(lab.native_apparatus()[int(c.index)].id)
		# Source42AA18 has no MouseDown latch requirement.
		var event:=InputEventMouseButton.new();event.button_index=MOUSE_BUTTON_LEFT;event.pressed=false;event.position=Vector2(c.point[0],c.point[1]);canvas._gui_input(event)
		var equal:bool=lab.calls.size()==c.expected.size()
		if equal:
			for i in lab.calls.size():
				for key in ["index","type","command"]:
					if int(lab.calls[i][key])!=int(c.expected[i][key]):equal=false
		if not equal:errors.append({"name":c.name,"run":c.run,"profile":c.profile,"actual":lab.calls.duplicate(true),"expected":c.expected})
		tested+=1
	if canvas!=null:canvas.free()
	print(JSON.stringify({"dispatch_cases":tested,"native_failures":data.errors.size(),"errors":errors.slice(0,10)}))
	if errors.is_empty() and data.errors.is_empty():print("PASS native control MouseUp dispatch")
	quit(0 if errors.is_empty() and data.errors.is_empty() else 1)
