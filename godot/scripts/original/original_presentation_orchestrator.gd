class_name OriginalPresentationOrchestrator
extends RefCounted
## Ordered chemical-vessel branch of original0040A4B8. Providers are explicit
## native boundaries, not a license to invent omitted pixels/particle state.
const Liquid = preload("res://scripts/original/original_liquid.gd")
const Gas = preload("res://scripts/original/original_gas_visual.gd")
const Surface = preload("res://scripts/original/original_surface_outline.gd")
const Solid = preload("res://scripts/original/original_solid_visual.gd")
const Renderer = preload("res://scripts/original/original_vessel_bitmap_renderer.gd")
const Raster = preload("res://scripts/original/original_material_rasterizer.gd")
var _busy := false
func _error(message: String, stage: String="preflight", index: int=-1) -> Dictionary:
	return {"ok":false,"error":message,"stage":stage,"native_index":index,"native_function":0x40a4b8}
func _words_valid(words: Variant, size: int) -> bool:
	if not words is Array or words.size()!=size:return false
	for word in words:
		if not word is int or word<0 or word>0xFFFFFFFF:return false
	return true
func _reply(result: Variant, size: int, stage: String, index: int, probe: bool) -> Dictionary:
	if not result is Dictionary:return _error("Native stage did not return a boundary result dictionary",stage,index)
	if not result.get("ok",false):return _error(str(result.get("error","Native stage failed")),stage,index)
	if not _words_valid(result.get("words"),size):return _error("Native stage did not return complete unsigned32 bitmap words",stage,index)
	if int(result.get("stretch_mode",0)) not in [1,2,3,4]:return _error("Native stage did not preserve explicit DC stretch state",stage,index)
	if not probe and not result.get("native_vcl_verified",false):return _error("Native stage has no verified original VCL profile",stage,index)
	return result
func render(snapshot: Dictionary, providers: Dictionary, profile: Dictionary, probe: bool=false) -> Dictionary:
	if _busy:return _error("A source-ordered presentation is already pending")
	_busy=true
	var result: Dictionary = await _render(snapshot,providers,profile,probe)
	_busy=false
	return result
func _render(snapshot: Dictionary, providers: Dictionary, profile: Dictionary, probe: bool) -> Dictionary:
	if not probe and not profile.get("native_vcl_verified",false):return _error("Original live VCL/GDI profile remains unverified")
	for field in ["vessels","connectors","scene","rng","context","catalog","bitmaps"]:
		if not snapshot.has(field):return _error("Explicit presentation input missing: "+field)
	for field in ["vessels","connectors","bitmaps"]:
		if not snapshot[field] is Array:return _error("Presentation array input differs: "+field)
	for field in ["scene","rng","context","catalog"]:
		if not snapshot[field] is Dictionary:return _error("Presentation dictionary input differs: "+field)
	var vessels: Array = snapshot.vessels.duplicate(true)
	var connectors: Array = snapshot.connectors.duplicate(true)
	var scene: Dictionary = snapshot.scene.duplicate(true)
	var rng: Dictionary = snapshot.rng.duplicate(true)
	var context: Dictionary = snapshot.context.duplicate(true)
	if not context.has("run_flag") or not context.has("pause_flag") or not rng.has("low") or not rng.has("high"):return _error("Original run/pause globals and shared TLS RNG are required")
	if scene.get("pools",[]).size()!=vessels.size() or snapshot.bitmaps.size()!=vessels.size():return _error("Persistent pools/bitmap inputs must retain complete apparatus order")
	if not providers.has("gdi") or not providers.gdi is Object:return _error("Native GDI provider is missing")
	for method in ["render_ops","render_solid","copy_rect"]:
		if not providers.gdi.has_method(method):return _error("Native GDI provider lacks "+method)
	for name in ["particles","overlays"]:
		if not providers.get(name,Callable()) is Callable or not providers.get(name,Callable()).is_valid():return _error("Source-faithful per-vessel "+name+" provider is unresolved")
	if not providers.get("plain_copy",Callable()) is Callable:return _error("Optional native source-format CopyRect provider must be Callable")
	if not providers.get("canvas_composite",Callable()) is Callable:return _error("Original final canvas compositor provider must be Callable")
	if not probe and not providers.get("canvas_composite",Callable()).is_valid():return _error("Original final canvas background composition is unresolved")
	var frames: Array = []
	var order: Array = []
	# Never pre-refresh all vessels. Each particle/connector stage sees preceding
	# vessels refreshed and following vessels at their previous source state.
	for index in vessels.size():
		var v: Dictionary = vessels[index]
		var width := int(v.get("native_bitmap_width",0))
		var height := int(v.get("native_bitmap_height",0))
		if width<=0 or height<=0 or width*height>4*1024*1024:return _error("Native vessel bitmap dimensions are unresolved","preflight",index)
		if int(v.get("native_fields",{}).get("0x18",-1))!=0:return _error("Rotated original vessel branch is not represented by the upright recipe","preflight",index)
		if int(v.get("type_id",0))<=100 or int(v.get("type_id",0))>=300:return _error("Original nonchemical apparatus drawing requires a separate native branch","preflight",index)
		var size := width*height
		var bitmap: Dictionary = snapshot.bitmaps[index]
		if not bitmap.get("material",null) is Dictionary:return _error("Original +FC bitmap format and initial DC state are required","preflight",index)
		var material: Dictionary = bitmap.material
		if int(material.get("bitmap_format",0))!=32 or int(material.get("width",0))!=width or int(material.get("height",0))!=height:return _error("This branch requires matching observed native32 +FC; conversion is not inferred","preflight",index)
		var stretch := int(material.get("initial_stretch_mode",0))
		if stretch not in [1,2,3,4]:return _error("Initial +FC DC stretch mode is unresolved","preflight",index)
		var canvas_state := {"pen_color":0xFFFFFF,"brush_color":0xFFFFFF,"brush_style":0,"stretch_mode":stretch}
		var clear := [{"op":"rectangle","left":0,"top":0,"right":width,"bottom":height,"pen_color":0xFFFFFF,"brush_color":0xFFFFFF,"brush_style":0}]
		order.append([index,"clear"])
		var pixels: Dictionary = _reply(await providers.gdi.render_ops(width,height,clear,[],probe,32,stretch),size,"clear",index,probe)
		if not pixels.ok:return pixels
		var liquid := Liquid.refresh(v,snapshot.catalog)
		if not liquid.get("ok",false):return _error(str(liquid.error),"liquid",index)
		order.append([index,"liquid"])
		if float(v.native_liquid_height)!=0:
			var rect: Array = v.native_liquid_rectangle
			var ops := [{"op":"rectangle","left":rect[0],"top":rect[1],"right":rect[2],"bottom":rect[3],"pen_color":v.native_liquid_pen_color,"brush_color":v.native_liquid_color,"brush_style":0}]
			pixels=_reply(await providers.gdi.render_ops(width,height,ops,pixels.words,probe,32,int(pixels.stretch_mode)),size,"liquid",index,probe)
			if not pixels.ok:return pixels
			canvas_state.pen_color=v.native_liquid_pen_color;canvas_state.brush_color=v.native_liquid_color;canvas_state.brush_style=0
		var gas := Gas.compute(v,snapshot.catalog)
		if not gas.ok:return _error(str(gas.error),"gas",index)
		order.append([index,"gas"])
		if not gas.draw_operations.is_empty():
			pixels=_reply(await providers.gdi.render_ops(width,height,gas.draw_operations,pixels.words,probe,32,int(pixels.stretch_mode)),size,"gas",index,probe)
			if not pixels.ok:return pixels
			canvas_state.pen_color=gas.color_integer;canvas_state.brush_color=gas.color_integer;canvas_state.brush_style=0
		order.append([index,"particles"])
		canvas_state.stretch_mode=int(pixels.stretch_mode)
		var particle_request := {"native_index":index,"vessels":vessels,"catalog":snapshot.catalog,"connectors":connectors,"scene":scene,"context":context,"rng":rng,"words":pixels.words,"width":width,"height":height,"canvas_state":canvas_state,"probe_only":probe}
		pixels=_reply(await providers.particles.call(particle_request),size,"particles",index,probe)
		if not pixels.ok:return pixels
		if not pixels.get("canvas_state",null) is Dictionary or not pixels.canvas_state.has("brush_color"):return _error("Particle stage must retain actual destination canvas brush state","particles",index)
		canvas_state=pixels.canvas_state
		order.append([index,"surface"])
		if float(v.native_liquid_height)>1:
			var surface := Surface.compute(v)
			if not surface.ok:return _error(str(surface.error),"surface",index)
			# The source keeps the current destination brush color while hollow,
			# including any particle-presentation changes; never infer its state.
			var brush_color := int(canvas_state.brush_color)
			for op in surface.draw_operations:op.brush_color=brush_color
			pixels=_reply(await providers.gdi.render_ops(width,height,surface.draw_operations,pixels.words,probe,32,int(pixels.stretch_mode)),size,"surface",index,probe)
			if not pixels.ok:return pixels
			canvas_state.pen_color=surface.pen_color;canvas_state.brush_style=1
		order.append([index,"settled"])
		var settled := Solid.compute(v,snapshot.catalog)
		if not settled.ok:return _error(str(settled.error),"settled",index)
		if not settled.draw_operations.is_empty():
			var prior_stretch := int(pixels.stretch_mode)
			var settled_pixels: Dictionary = await providers.gdi.render_solid(pixels.words,width,height,settled,probe)
			# Source4744DC modifies a temporary DC;492560 updates destination
			# scanline words. It does not select a new stretch mode on +FC.
			settled_pixels.stretch_mode=prior_stretch
			pixels=_reply(settled_pixels,size,"settled",index,probe)
			if not pixels.ok:return pixels
		order.append([index,"overlays"])
		canvas_state.stretch_mode=int(pixels.stretch_mode)
		pixels=_reply(await providers.overlays.call({"native_index":index,"vessel":v,"context":context,"words":pixels.words,"width":width,"height":height,"canvas_state":canvas_state,"probe_only":probe}),size,"overlays",index,probe)
		if not pixels.ok:return pixels
		if not bitmap.has("plain") or not bitmap.has("fill"):return _error("Original +F8/+F4 source bitmaps are unresolved","apparatus",index)
		var plain: Dictionary = bitmap.plain
		var fill: Dictionary = bitmap.fill
		for source_bitmap in [plain,fill]:
			if int(source_bitmap.get("width",0))<=0 or int(source_bitmap.get("height",0))<=0 or int(source_bitmap.get("width",0))*int(source_bitmap.get("height",0))>4*1024*1024:return _error("Original source bitmap dimensions are unresolved","apparatus",index)
		if int(plain.get("bitmap_format",0))!=32 and not providers.get("plain_copy",Callable()).is_valid():return _error("Original source bitmap format requires an exact native CopyRect provider; source32 is not inferred from24/device pixels","apparatus",index)
		if int(fill.get("bitmap_format",0))!=32:return _error("Original fill bitmap native32 conversion must be supplied explicitly","fill",index)
		if not _words_valid(plain.get("words"),int(plain.get("width",0))*int(plain.get("height",0))) or not _words_valid(fill.get("words"),int(fill.get("width",0))*int(fill.get("height",0))):return _error("Original source bitmap words are incomplete","apparatus",index)
		if not probe and not bitmap.get("original_bitmap_profile_verified",false):return _error("Original +F8/+F4 bitmap provenance is unverified","apparatus",index)
		if not bitmap.get("copy_rect",null) is Dictionary:return _error("Source CopyRect rectangles and inherited DC stretch mode are required","apparatus",index)
		var copy: Dictionary = bitmap.copy_rect
		if not copy.has("destination_rect") or not copy.has("source_rect"):return _error("Incomplete original CopyRect state","apparatus",index)
		# Current host.copy_rect has no stretch-state argument: use exact render_ops
		# request instead, retaining native StretchBlt input/ROP and current state.
		var raw := PackedByteArray();raw.resize(plain.words.size()*4)
		for i in plain.words.size():raw.encode_u32(i*4,int(plain.words[i]))
		var dr: Array = copy.destination_rect;var sr: Array = copy.source_rect
		if dr.size()!=4 or sr.size()!=4:return _error("Original CopyRect rectangle geometry is unresolved","apparatus",index)
		var copy_ops := [{"op":"copy_rect","source_bgra":Marshalls.raw_to_base64(raw),"source_width":plain.width,"source_height":plain.height,"copy_mode":0xEE0086,"left":dr[0],"top":dr[1],"right":dr[2],"bottom":dr[3],"source_left":sr[0],"source_top":sr[1],"source_right":sr[2],"source_bottom":sr[3]}]
		order.append([index,"plain_srcpaint"])
		if providers.get("plain_copy",Callable()).is_valid():
			pixels=_reply(await providers.plain_copy.call({"native_index":index,"source":plain,"width":width,"height":height,"words":pixels.words,"destination_rect":dr,"source_rect":sr,"copy_mode":0xEE0086,"initial_stretch_mode":int(pixels.stretch_mode),"probe_only":probe}),size,"plain_srcpaint",index,probe)
		else:
			pixels=_reply(await providers.gdi.render_ops(width,height,copy_ops,pixels.words,probe,32,int(pixels.stretch_mode)),size,"plain_srcpaint",index,probe)
		if not pixels.ok:return pixels
		if int(fill.width)!=width or int(fill.height)!=height:return _error("Original fill-blend dimension relationship is unresolved; no resizing substituted","fill",index)
		order.append([index,"fill_blend"])
		var words: Array = []
		words.resize(size)
		for i in size:
			words[i]=Renderer.fill_pixel(int(pixels.words[i]),int(fill.words[i]),Renderer.fill_weight(v))
			if words[i]<0:return _error("Original4926E0 pixel arithmetic is unresolved","fill",index)
		var frame := {"native_index":index,"words":words,"image":Raster.words_to_image(words,width,height),"width":width,"height":height,"probe_only":probe,"native_vcl_verified":not probe,"presentation_stage":"post_fill_pre_canvas"}
		if providers.get("canvas_composite",Callable()).is_valid():
			order.append([index,"canvas_background"])
			var presented: Variant = await providers.canvas_composite.call({"native_index":index,"vessel":v,"words":words,"width":width,"height":height,"preceding_frames":frames,"context":context,"probe_only":probe})
			if not presented is Dictionary or not presented.get("ok",false):return _error(str(presented.get("error","Final original canvas compositor failed")) if presented is Dictionary else "Final original canvas compositor returned no result","canvas_background",index)
			if not _words_valid(presented.get("words"),size) or presented.get("presentation_stage","")!="background_composited_srccopy" or presented.get("display_mode","")!="opaque":return _error("Original final display bitmap/background stage is incomplete","canvas_background",index)
			if not probe and (not presented.get("native_vcl_verified",false) or not presented.get("canvas_background_verified",false)):return _error("Original final canvas compositor is unverified","canvas_background",index)
			frame=presented;frame.native_index=index;frame.probe_only=probe
		frames.append(frame)
	return {"ok":true,"frames":frames,"state":{"vessels":vessels,"connectors":connectors,"scene":scene,"rng":rng,"context":context},"order":order,"probe_only":probe,"native_vcl_verified":not probe,"scope":"Ordered upright chemical-vessel branch; caller owns scene adoption and canvas presentation"}
