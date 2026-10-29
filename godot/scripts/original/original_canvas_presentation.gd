class_name OriginalCanvasPresentation
extends RefCounted
## Exact scale1 40FD82 background compositor followed by 40FE60 SRCCOPY.
## The source does not display post-fill pixels with generic alpha blending.
const Solid = preload("res://scripts/original/original_solid_visual.gd")
const Raster = preload("res://scripts/original/original_material_rasterizer.gd")
const WEIGHT_BITS := "000000000000e03f"
static func _error(message: String) -> Dictionary:return {"ok":false,"error":message,"boundary":"Original main canvas background composition"}
static func compose(foreground: Array, background: Array, width: int, height: int, position: Array, proof: Dictionary, probe: bool=false) -> Dictionary:
	if width<=0 or height<=0 or width*height>4*1024*1024 or foreground.size()!=width*height or background.size()!=foreground.size():return _error("Exact foreground/background bitmap dimensions are required")
	if position.size()!=2:return _error("Native vessel center is required")
	for coordinate in position:
		if not (coordinate is int or coordinate is float) or not is_finite(float(coordinate)) or float(int(coordinate))!=float(coordinate):return _error("Native centers must preserve source integer coordinates")
	if proof.get("native_scale_bits","")!="000000000000f03f":return _error("Only the evidenced exact scale1 final-display branch is represented")
	if not probe and (not proof.get("native_vcl_verified",false) or not proof.get("canvas_background_verified",false)):return _error("Original canvas background/DC provenance is unverified")
	var words: Array=[];words.resize(foreground.size())
	for i in foreground.size():
		if not foreground[i] is int or not background[i] is int or foreground[i]<0 or foreground[i]>0xFFFFFFFF or background[i]<0 or background[i]>0xFFFFFFFF:return _error("Native foreground/background words must be unsigned32")
		# Stack+10=background source(local88),stack+14=destination(+FC).
		words[i]=Solid.composite_pixel(int(foreground[i]),int(background[i]),0.5)
		if words[i]<0:return _error("Native492560 arithmetic is unresolved")
	return {"ok":true,"words":words,"image":Raster.words_to_image(words,width,height),"width":width,"height":height,"display_top_left":[int(position[0])-int(width/2),int(position[1])-int(height/2)],"presentation_stage":"background_composited_srccopy","display_mode":"opaque","source_compositor":0x492560,"source_weight_bits":WEIGHT_BITS,"canvas_background_verified":proof.get("canvas_background_verified",false),"native_vcl_verified":not probe and proof.get("native_vcl_verified",false),"probe_only":probe}
