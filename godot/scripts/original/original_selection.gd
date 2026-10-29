class_name OriginalSelection
extends RefCounted
const X87 = preload("res://scripts/original/original_x87.gd")
const Math = preload("res://scripts/original/original_math.gd")
const Controls = preload("res://scripts/original/original_controls.gd")
const Interaction = preload("res://scripts/original/original_interaction.gd")
static func _error(message: String) -> Dictionary:
	return {"ok":false,"resolved":false,"error":message}
static func _f(v: Dictionary,offset: String,key: String,fallback: Variant=0) -> Variant:
	return v.get("native_fields",{}).get(offset,v.get(key,fallback))
static func _type(v: Dictionary) -> int: return int(_f(v,"0x08","type_id"))
static func _xy(v: Dictionary) -> Array:
	return [int(v.position[0]),int(v.position[1])]
static func _at(center: int,offset: float,scale: float) -> Array:
	return X87.add(X87.multiply([offset,0.0],scale),float(center))
static func _inside(p: Array,left: Array,top: Array,right: Array,bottom: Array) -> bool:
	return X87.compare_to_double(left,float(p[0]))<0 and X87.compare_to_double(right,float(p[0]))>0 and X87.compare_to_double(top,float(p[1]))<0 and X87.compare_to_double(bottom,float(p[1]))>0
static func _rect(p: Array,x: float,y: float,w: float,h: float) -> bool:
	return x<float(p[0]) and float(p[0])<x+w and y<float(p[1]) and float(p[1])<y+h
static func _result(typ: int,index: int,command: int,dx: int,dy: int) -> Dictionary:
	return {"ok":true,"resolved":true,"type":typ,"index":index,"command":command,"dx":dx,"dy":dy,"native_entry":"00417EE0 decision before004256BD"}
static func _body(p: Array,v: Dictionary,scale: float,margin: float=0.0) -> bool:
	var xy := _xy(v); var w:=float(v.native_bitmap_width)*0.5; var h:=float(v.native_bitmap_height)*0.5
	return _inside(p,X87.add(_at(xy[0],-w,scale),-margin),X87.add(_at(xy[1],-h,scale),-margin),X87.add(_at(xy[0],w,scale),margin),X87.add(_at(xy[1],h,scale),margin))
static func _resize_command(p: Array,v: Dictionary,scale: float) -> int:
	var xy:=_xy(v);var w:=float(v.native_bitmap_width)*0.5;var h:=float(v.native_bitmap_height)*0.5
	var command:=0
	for i in range(4):
		var x:=_at(xy[0],-w if i in [0,2] else w,scale);var y:=_at(xy[1],-h if i<2 else h,scale)
		if _inside(p,X87.add(x,-4.0),X87.add(y,-4.0),X87.add(x,4.0),X87.add(y,4.0)): command=i+1
	return command
static func _distance(a: Array,b: Array) -> Array:
	var x := float(a[0])-float(b[0]); var y := float(a[1])-float(b[1])
	var square := X87.add_pair(X87.multiply([x,0.0],x),X87.multiply([y,0.0],y))
	if square.is_empty(): return []
	return Math.sqrt_native(X87.stored_double(square))
static func _ellipse_hit(p: Array,a: Array,b: Array,tolerance: float,inclusive: bool) -> Dictionary:
	var length := _distance(a,b); var first := _distance(p,a); var second := _distance(p,b)
	if length.is_empty() or first.is_empty() or second.is_empty(): return _error("Original FSQRT geometry arithmetic unresolved")
	var difference := X87.add(X87.add(second,X87.stored_double(first)),-X87.stored_double(length))
	if X87.compare_to_double(difference,0.0)<0:difference=X87.multiply(difference,-1.0)
	var cmp:=X87.compare_to_double(difference,tolerance)
	return {"ok":true,"hit":cmp<=0 if inclusive else cmp<0}
static func from_state(state: Dictionary) -> Dictionary:
	return {"vessels":state.get("vessels",[]).filter(func(v):return v.has("native_fields")),"connectors":state.get("native_connectors",[]),"annotations":state.get("annotations",[]),"charts":state.get("charts",[]),"buttons":state.get("native_buttons",[]),"scale":state.get("native_canvas_scale",1.0)}
static func press(scene: Dictionary,point: Vector2,previous: Dictionary={}) -> Dictionary:
	# Left button, selection tool: apparatus-creation branches are separate callbacks.
	var p: Array=[int(point.x),int(point.y)];var scale:=float(scene.get("scale",1.0));var vessels: Array=scene.get("vessels",[]);var records: Array=scene.get("connectors",[])
	var dx:=int(previous.get("dx",0));var dy:=int(previous.get("dy",0));var selected:=int(previous.get("index",0));var old_type:=int(previous.get("type",0))
	if old_type in [204,207,208,211] and selected>=0 and selected<vessels.size():
		var cmd:=Controls.command_at(vessels[selected],Vector2(p[0],p[1]))
		if cmd>0:return _result(old_type,selected,cmd,p[0]-int(vessels[selected].position[0]),p[1]-int(vessels[selected].position[1]))
	for i in range(records.size()):
		var r: Array=Array(records[i].metadata)
		if r.size()!=25:return _error("Original connector25 fields missing")
		for side in [1,2]:
			var x:=int(r[2 if side==1 else 4]);var y:=int(r[3 if side==1 else 5])
			if _rect(p,x-4,y-4,8,8):return _result(1001,i,side,p[0]-x,p[1]-y)
	for i in range(records.size()):
		var r: Array=Array(records[i].metadata);var typ:=int(r[10]);var x1:=int(r[2]);var y1:=int(r[3]);var x2:=int(r[4]);var y2:=int(r[5]);var hit:=false
		if typ==1:hit=_rect(p,x1-5,mini(y1,y2)-5,10,absi(y2-y1)+10) or _rect(p,mini(x1,x2)-5,y2-5,absi(x2-x1)+10,10)
		elif typ==2:hit=_rect(p,mini(x1,x2)-5,y1-5,absi(x2-x1)+10,10) or _rect(p,x2-5,mini(y1,y2)-5,10,absi(y2-y1)+10)
		elif typ==3:hit=_rect(p,mini(x1,x2)-5,y1-5,absi(x2-x1)+10,10)
		elif typ==4:hit=_rect(p,x1-5,mini(y1,y2)-5,10,absi(y2-y1)+10)
		elif typ==5:
			var ellipse := _ellipse_hit(p,[x1,y1],[x2,y2],1.0,false)
			if not ellipse.ok:return ellipse
			hit=ellipse.hit
		if hit:return _result(1001,i,0,p[0]-x1,p[1]-y1)
	for v in vessels:
		if not v.has("native_bitmap_width") or not v.has("native_bitmap_height"):return _error("Original selection requires original bitmap dimensions")
	for i in range(vessels.size()):
		var v: Dictionary=vessels[i]
		if _type(v)!=301:continue
		var xy:=_xy(v);var hw:=int(int(v.native_bitmap_width)/2);var hh:=int(int(v.native_bitmap_height)/2);var subtype:=int(_f(v,"0x0c","native_type_parameter"));var offset:=int(_f(v,"0x74","native_0x74"))
		var base:=float(hh-offset)
		var a:=subtype==0 and _inside(p,_at(xy[0],-hw,scale),_at(xy[1],base,scale),_at(xy[0],hw-24,scale),_at(xy[1],base+15,scale))
		var b:=subtype==1 and _inside(p,_at(xy[0],14-hw,scale),_at(xy[1],base,scale),_at(xy[0],36-hw,scale),_at(xy[1],base+22,scale))
		if (a or b) and int(_f(v,"0x68","native_0x68"))!=0:
			return _result(301,i,1,dx,int(X87.stored_double(X87.add(_at(xy[1],float(v.native_bitmap_height)*0.5-offset,scale),-float(p[1])))))
		var platform:=float(v.native_bitmap_height)*0.5-float(_f(v,"0x7c","native_platform_offset"))
		if int(_f(v,"0x6c","native_platform_mode"))!=0 and _inside(p,_at(xy[0],-float(v.native_bitmap_width)*0.5,scale),_at(xy[1],platform+4,scale),_at(xy[0],float(v.native_bitmap_width)*0.5-4,scale),_at(xy[1],platform+12,scale)):
			return _result(301,i,2,dx,int(X87.stored_double(X87.add(_at(xy[1],platform,scale),-float(p[1])))))
	for i in range(vessels.size()):
		var v: Dictionary=vessels[i]
		if _type(v)==311 and int(_f(v,"0x0c","native_type_parameter"))==2:
			var xy:=_xy(v)
			var ellipse:=_ellipse_hit(p,[xy[0]+int(_f(v,"0x3c","native_0x3c")),xy[1]+int(_f(v,"0x40","native_0x40"))],[xy[0]+int(_f(v,"0x44","native_0x44")),xy[1]+int(_f(v,"0x48","native_0x48"))],2.0,true)
			if not ellipse.ok:return ellipse
			if ellipse.hit:return _result(311,i,0,p[0]-xy[0],p[1]-xy[1])
	for i in range(mini(100,scene.get("buttons",[]).size())):
		var b: Dictionary=scene.buttons[i]
		if int(b.active)==0:break
		var xy: Array=b.position;var hw:=int(int(b.size[0])/2);var hh:=int(int(b.size[1])/2)
		if not _rect(p,xy[0]-hw-4,xy[1]-hh-4,hw*2+8,hh*2+8):continue
		var cmd:=0
		for corner in range(4):
			if _rect(p,xy[0]+(-hw if corner in [0,2] else hw)-4,xy[1]+(-hh if corner<2 else hh)-4,8,8):cmd=corner+1
		return _result(2000,i,cmd,p[0]-int(xy[0]),p[1]-int(xy[1]))
	for i in range(vessels.size()):
		var v: Dictionary=vessels[i];var typ:=_type(v)
		if typ in [301,316,318] or (typ==311 and int(_f(v,"0x0c","native_type_parameter"))==2):continue
		if _body(p,v,scale):return _result(typ,i,0,p[0]-int(v.position[0]),p[1]-int(v.position[1]))
	for i in range(vessels.size()):
		var v: Dictionary=vessels[i]
		if _type(v)==316 and _body(p,v,scale,4.0):return _result(316,i,_resize_command(p,v,scale),p[0]-int(v.position[0]),p[1]-int(v.position[1]))
	for i in range(vessels.size()):
		var v: Dictionary=vessels[i]
		if _type(v)==301 and _body(p,v,scale):return _result(301,i,0,p[0]-int(v.position[0]),p[1]-int(v.position[1]))
	for i in range(vessels.size()):
		var v: Dictionary=vessels[i];var typ:=_type(v)
		if typ in [301,316,318] or (typ==311 and int(_f(v,"0x0c","native_type_parameter"))==2):continue
		if not v.has("native_label_rect"):return _error("Original selection requires supplied live label metrics")
		var r: Array=v.native_label_rect;var xy:=_xy(v);var left:=_at(xy[0],float(r[0]),scale);var top:=_at(xy[1],float(r[1]),scale)
		if _inside(p,left,top,X87.add(left,float(r[2])),X87.add_pair(top,X87.multiply([float(r[3]),0.0],scale))):
			return _result(typ,i,1,int(X87.stored_double(X87.add_pair([float(p[0]),0.0],X87.multiply(X87.multiply([float(r[0]),0.0],scale),-1.0)))),int(X87.stored_double(X87.add_pair([float(p[1]),0.0],X87.multiply(X87.multiply([float(r[1]),0.0],scale),-1.0)))))
	for i in range(mini(100,scene.get("annotations",[]).size())):
		var a: Dictionary=scene.annotations[i]
		if a.has("metadata") and int(a.metadata[0])==0:break
		if _inside(p,[float(a.position[0]),0.0],[float(a.position[1]),0.0],_at(int(a.position[0]),float(a.size[0]),scale),_at(int(a.position[1]),float(a.size[1]),scale)):return _result(1000,i,0,p[0]-int(a.position[0]),p[1]-int(a.position[1]))
	for i in range(mini(10,scene.get("charts",[]).size())):
		var c: Dictionary=scene.charts[i]
		if c.has("metadata") and int(c.metadata[0])==0:break
		if c.has("native_chart_record") and int(c.native_chart_record[0])==0:break
		if _rect(p,float(c.position[0])-120.0,float(c.position[1])-120.0,240.0,240.0):return _result(3000,i,0,p[0]-int(c.position[0]),p[1]-int(c.position[1]))
	for i in range(vessels.size()):
		var v: Dictionary=vessels[i]
		if _type(v)==318 and _body(p,v,scale,4.0):return _result(318,i,_resize_command(p,v,scale),p[0]-int(v.position[0]),p[1]-int(v.position[1]))
	return _result(-1,0,0,dx,dy)

static func _write_position(v: Dictionary,x: int,y: int) -> void:
	v.position=[x,y]
	if v.has("native_fields"):v.native_fields["0x10"]=str(x);v.native_fields["0x14"]=str(y)
static func _align_connector(r: Array,side: int) -> void:
	if int(r[10])==3:r[5 if side==1 else 3]=str(int(r[3 if side==1 else 5]))
	if int(r[10])==4:r[4 if side==1 else 2]=str(int(r[2 if side==1 else 4]))
static func _sync_chain(records: Array,name: String,selected: int,depth: int=0) -> Dictionary:
	if depth>100:return _error("Original conduit recursion exceeds verification bound")
	var parent: Array=[]
	for c in records:
		if str(c.metadata[1])==name:parent=c.metadata;break
	if parent.is_empty():return _error("Original conduit name lookup failed")
	for i in range(records.size()):
		var r: Array=Array(records[i].metadata)
		if str(r[1])==name or i==selected:continue
		for side in [1,2]:
			var typ:=int(r[12 if side==1 else 15]);var flag:=13 if side==1 else 16
			if typ==0 or str(r[11 if side==1 else 14])!=name or int(r[flag])!=0:continue
			var xindex:=2 if side==1 else 4;var yindex:=3 if side==1 else 5;var ox:=int(r[xindex]);var oy:=int(r[yindex])
			if typ in [1001,1002]:r[xindex]=str(int(parent[2 if typ==1001 else 4]));r[yindex]=str(int(parent[3 if typ==1001 else 5]))
			r[flag]="1"
			var other:=15 if side==1 else 12
			if int(r[other])==0:
				r[4 if side==1 else 2]=str(int(r[4 if side==1 else 2])+int(r[xindex])-ox);r[5 if side==1 else 3]=str(int(r[5 if side==1 else 3])+int(r[yindex])-oy)
			_align_connector(r,side);records[i].metadata=r
			if int(r[other])!=0:
				var result:=_sync_chain(records,str(r[1]),selected,depth+1)
				if not result.ok:return result
	return {"ok":true}
static func _move_connections(records: Array,name: String,dx: int,dy: int,selected: int=-1) -> Dictionary:
	for c in records:c.metadata[13]="0";c.metadata[16]="0"
	for i in range(records.size()):
		var r: Array=Array(records[i].metadata)
		for side in [1,2]:
			var typ:=int(r[12 if side==1 else 15])
			if typ==0 or typ>=1001 or str(r[11 if side==1 else 14])!=name:continue
			r[2 if side==1 else 4]=str(int(r[2 if side==1 else 4])+dx);r[3 if side==1 else 5]=str(int(r[3 if side==1 else 5])+dy);r[13 if side==1 else 16]="1"
			if int(r[15 if side==1 else 12])==0:r[4 if side==1 else 2]=str(int(r[4 if side==1 else 2])+dx);r[5 if side==1 else 3]=str(int(r[5 if side==1 else 3])+dy)
			_align_connector(r,side);records[i].metadata=r
			if int(r[15 if side==1 else 12])!=0:
				var result:=_sync_chain(records,str(r[1]),selected)
				if not result.ok:return result
	return {"ok":true}
static func _move_attachments(scene: Dictionary,name: String,dx: int,dy: int,command: int,stack: Array=[]) -> Dictionary:
	if stack.has(name):return _error("Original apparatus attachment recursion is cyclic")
	var next:=stack.duplicate();next.append(name)
	for v in scene.vessels:
		var parent_type:=int(_f(v,"0x84","native_parent_type"));var parent_name:=str(_f(v,"0x80","native_parent_name"))
		var eligible:=parent_type!=0 if command==0 else parent_type==3011 or (parent_type!=0 and parent_type not in [301,3011,3012]) if command==1 else parent_type==3012 or (parent_type!=0 and parent_type not in [301,3011,3012])
		if not eligible or parent_name!=name:continue
		_write_position(v,int(v.position[0])+dx,int(v.position[1])+dy)
		var child:=str(_f(v,"0x04","legacy_name",v.get("label","")))
		var moved:=_move_attachments(scene,child,dx,dy,command,next)
		if not moved.ok:return moved
		moved=_move_connections(scene.connectors,child,dx,dy)
		if not moved.ok:return moved
	return {"ok":true}
static func drag(scene: Dictionary,decision: Dictionary,point: Vector2) -> Dictionary:
	var working:Dictionary=scene.duplicate(true)
	var result:=_drag_native(working,decision,point)
	if not result.ok:return result
	for key in ["vessels","connectors","annotations","charts","buttons"]:
		for i in range(scene.get(key,[]).size()):scene[key][i].merge(working[key][i],true)
	return result
static func _drag_native(scene: Dictionary,decision: Dictionary,point: Vector2) -> Dictionary:
	var typ:=int(decision.type);var index:=int(decision.index);var command:=int(decision.command);var x:=int(point.x);var y:=int(point.y);var scale:=float(scene.get("scale",1.0))
	if typ in [204,207,208,211] and command!=0:return {"ok":true,"performed":false}
	if typ>100 and typ<400:
		if index<0 or index>=scene.vessels.size():return _error("Original selected apparatus index invalid")
		var v: Dictionary=scene.vessels[index]
		if typ in [316,318] and command!=0:
			var resized:=Interaction.resize(scene,decision,point)
			if resized.ok: Interaction.sync_dimensions(scene,decision)
			return resized
		if typ==301 and command in [1,2]:
			var key:="0x74" if command==1 else "0x7c";var old:=int(_f(v,key,"native_platform_offset"));var baseline:=_at(int(v.position[1]),float(v.native_bitmap_height)*0.5,scale)
			var offset:=int(X87.stored_double(X87.divide(X87.add(baseline,-float(y)-float(decision.dy)),scale)));offset=clampi(offset,30,200);v.native_fields[key]=str(offset)
			return _move_attachments(scene,str(_f(v,"0x04","legacy_name")),0,int(X87.stored_double(X87.multiply([float(old-offset),0.0],scale))),command)
		if command==1:
			if not v.has("native_label_rect"):return _error("Original label drag requires metrics")
			v.native_label_rect[0]=int(X87.stored_double(X87.divide([float(x-int(decision.dx)),0.0],scale)));v.native_label_rect[1]=int(X87.stored_double(X87.divide([float(y-int(decision.dy)),0.0],scale)))
			return {"ok":true,"performed":true}
		if command!=0:return _error("Original apparatus drag command unresolved")
		var dx:=x-int(decision.dx)-int(v.position[0]);var dy:=y-int(decision.dy)-int(v.position[1]);_write_position(v,x-int(decision.dx),y-int(decision.dy))
		var name:=str(_f(v,"0x04","legacy_name",v.get("label","")));var moved:=_move_attachments(scene,name,dx,dy,0)
		if not moved.ok:return moved
		return _move_connections(scene.connectors,name,dx,dy)
	if typ==1000:
		var a: Dictionary=scene.annotations[index];a.position=[x-int(decision.dx),y-int(decision.dy)];return {"ok":true}
	if typ==3000:
		var c: Dictionary=scene.charts[index];c.position=[x-int(decision.dx),y-int(decision.dy)];return {"ok":true}
	if typ==1001:
		var r:Array=Array(scene.connectors[index].metadata);var xindex:=2 if command in [0,1] else 4;var yindex:=3 if command in [0,1] else 5
		var nx:=x-int(decision.dx);var ny:=y-int(decision.dy);var dx:=nx-int(r[xindex]);var dy:=ny-int(r[yindex])
		if command==0:r[2]=str(nx);r[3]=str(ny);r[4]=str(int(r[4])+dx);r[5]=str(int(r[5])+dy)
		elif int(r[10])==3:r[xindex]=str(nx)
		elif int(r[10])==4:r[yindex]=str(ny)
		else:r[xindex]=str(nx);r[yindex]=str(ny)
		_align_connector(r,1);scene.connectors[index].metadata=r
		for c in scene.connectors:c.metadata[13]="0";c.metadata[16]="0"
		return _sync_chain(scene.connectors,str(r[1]),index)
	if typ==2000:return Interaction.resize(scene,decision,point)
	return {"ok":true,"performed":false}
