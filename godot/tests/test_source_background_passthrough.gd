extends SceneTree
## NativeF8 SRCPAINT +4926E0 white pixels must reveal the actual preceding
## canvas through492560, including bottle/beaker pixels behind a dropper.
var failures:Array=[]
func check(value:bool,label:String)->void:
	if not value:failures.append(label);push_error(label)
func raw_words(stem:String)->Dictionary:
	var image:=Image.new()
	var result:=image.load_png_from_buffer(FileAccess.get_file_as_bytes("res://assets/apparatus/"+stem.get_basename()+".png"))
	if result!=OK:return {}
	image.convert(Image.FORMAT_RGBA8)
	var bytes:=image.get_data();var words:Array=[];words.resize(image.get_width()*image.get_height())
	for i in words.size():words[i]=(int(bytes[i*4])<<16)|(int(bytes[i*4+1])<<8)|int(bytes[i*4+2])
	return {"words":words,"width":image.get_width(),"height":image.get_height()}
func _initialize()->void:call_deferred("_run")
func _run()->void:
	var app=load("res://scenes/main.tscn").instantiate();root.add_child(app)
	await process_frame;await process_frame
	# A colored canvas makes a white/gray opaque square observable even where
	# the original CEM's otherwise-white background concealed its edge.
	var background:=0x2a7cb4
	app.canvas.background=Color8(0x2a,0x7c,0xb4)
	app.run_experiment()
	await process_frame;await process_frame
	var vessels:Array=app.model.native_apparatus()
	var withdrawn:Dictionary=app.model.manual_action(int(vessels[2].id),1)
	check(withdrawn.ok,"Actual source withdrawal executes before background rendering")
	app.canvas.queue_redraw()
	await process_frame;await process_frame
	check(app.model.running and app.model.last_error.is_empty() and app.canvas.source_render_errors.is_empty(),"Normal application and source rendering remain active")
	var frames:Array=app.canvas.source_render_snapshot()
	check(frames.size()==6,"Every opening apparatus has an actual canvas frame")
	var checked:=0;var overlapped:=0;var colored_background:=0;var wrong:Array=[]
	for index in mini(frames.size(),vessels.size()):
		var v:Dictionary=vessels[index];var frame:Dictionary=frames[index]
		var body:=raw_words(str(v.get("native_bitmap_plain",v.kind)))
		var mask:=raw_words(str(v.get("native_bitmap_fill","_"+str(v.get("native_bitmap_plain",v.kind)))))
		if body.is_empty() or mask.is_empty():failures.append("Original raw bitmap is absent");continue
		for y in int(frame.height):
			for x in int(frame.width):
				if x>=int(mask.width) or y>=int(mask.height):continue
				if int(body.words[y*int(body.width)+x])!=0xffffff or int(mask.words[y*int(mask.width)+x])!=0xffffff:continue
				var wx:=int(frame.top_left[0])+x;var wy:=int(frame.top_left[1])+y;var expected:=background;var overlap:=false
				for previous_index in index:
					var previous:Dictionary=frames[previous_index]
					var px:=wx-int(previous.top_left[0]);var py:=wy-int(previous.top_left[1])
					if px>=0 and py>=0 and px<int(previous.width) and py<int(previous.height):
						expected=int(previous.words[py*int(previous.width)+px]);overlap=true
				checked+=1
				if overlap:overlapped+=1
				else:colored_background+=1
				if (int(frame.words[y*int(frame.width)+x])&0xffffff)!=(expected&0xffffff) and wrong.size()<12:wrong.append([index,x,y,expected,frame.words[y*int(frame.width)+x]])
	check(checked>2000,"White-key regression covers original apparatus exteriors")
	check(overlapped>0 and colored_background>0,"Regression includes actual dropper/bottle overlap and exposed colored canvas")
	check(wrong.is_empty(),"Source white exteriors preserve the actual underlying canvas without opaque squares: "+str(wrong))
	print(JSON.stringify({"failures":failures,"checked_white_exterior_pixels":checked,"actual_overlap_pixels":overlapped,"exposed_colored_background_pixels":colored_background,"normal_run":true,"profiles_injected":false}))
	if failures.is_empty():print("PASS actual source canvas: original white exteriors preserve colored background and dropper/bottle overlap")
	app.free();quit(0 if failures.is_empty() else 1)
