class_name OriginalCanvasFrames
extends RefCounted
## Validate full source-composited frame transport before Canvas texture commit.
const Raster = preload("res://scripts/original/original_material_rasterizer.gd")
static func error(message: String)->Dictionary:return {"ok":false,"error":message}
static func prepare(result: Dictionary, apparatus: Array)->Dictionary:
	if not result.get("ok",false) or result.get("probe_only",true) or not result.get("native_vcl_verified",false):return error("Probe or unverified pixels cannot be committed to native presentation")
	if not result.get("frames",null) is Array or result.frames.size()!=apparatus.size():return error("Complete native apparatus frame order is required")
	var entries := {}
	for index in apparatus.size():
		var v: Dictionary=apparatus[index]
		var frame=result.frames[index]
		if not frame is Dictionary or int(frame.get("native_index",-1))!=index or frame.get("probe_only",true) or not frame.get("native_vcl_verified",false):return error("Native frame index/provenance differs")
		if frame.get("presentation_stage","")!="background_composited_srccopy" or frame.get("display_mode","")!="opaque" or not frame.get("canvas_background_verified",false) or int(frame.get("source_compositor",0))!=0x492560 or frame.get("source_weight_bits","")!="000000000000e03f":return error("Final original canvas background composition is required; white alpha is not substituted")
		var width:=int(v.get("native_bitmap_width",0));var height:=int(v.get("native_bitmap_height",0))
		if width<=0 or height<=0 or width*height>4*1024*1024 or int(frame.get("width",0))!=width or int(frame.get("height",0))!=height:return error("Native image dimensions differ from original apparatus")
		if not frame.get("words",null) is Array or frame.words.size()!=width*height:return error("Native bitmap words are incomplete")
		for word in frame.words:
			if not word is int or word<0 or word>0xFFFFFFFF:return error("Native bitmap word is outside unsigned32")
		if not v.get("position",null) is Array or v.position.size()!=2:return error("Native center is unresolved")
		for coordinate in v.position:
			if not (coordinate is int or coordinate is float) or not is_finite(float(coordinate)) or float(int(coordinate))!=float(coordinate):return error("Native center must retain original integer coordinates")
		var top_left := [int(v.position[0])-int(width/2),int(v.position[1])-int(height/2)]
		if frame.get("display_top_left",null)!=top_left:return error("Native centered BitBlt destination differs")
		var image=frame.get("image")
		if not image is Image or image.is_empty() or image.get_width()!=width or image.get_height()!=height or image.get_format()!=Image.FORMAT_RGBA8:return error("Returned exact native Image is missing or malformed")
		var expected:=Raster.words_to_image(frame.words,width,height)
		if image.get_data()!=expected.get_data():return error("Returned Image differs from native words or misuses reserved byte as alpha")
		var id:=int(v.get("id",-1))
		if id<0 or entries.has(id):return error("Native UI apparatus identity is invalid/duplicated")
		entries[id]={"native_index":index,"image":image.duplicate(),"words":frame.words.duplicate(),"top_left":Vector2(top_left[0],top_left[1]),"width":width,"height":height}
	return {"ok":true,"entries":entries}
