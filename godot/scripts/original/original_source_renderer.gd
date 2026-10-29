class_name OriginalSourceRenderer
extends RefCounted
## Production source drawing recipes with a portable primitive backend.
## This path makes no Windows VCL/DC/pixel-attestation claim. It does not
## initialize, advance or substitute any chemistry or particle-state cells.
const Liquid=preload("res://scripts/original/original_liquid.gd")
const Gas=preload("res://scripts/original/original_gas_visual.gd")
const Surface=preload("res://scripts/original/original_surface_outline.gd")
const Solid=preload("res://scripts/original/original_solid_visual.gd")
const Fill=preload("res://scripts/original/original_vessel_bitmap_renderer.gd")
const Raster=preload("res://scripts/original/original_portable_raster.gd")
const Images=preload("res://scripts/original/original_material_rasterizer.gd")
const X=preload("res://scripts/original/original_x87.gd")
const Actions=preload("res://scripts/original/original_apparatus_actions.gd")
var _assets:Dictionary={}
var _fill_pixels:Dictionary={}
var _composite_pixels:Dictionary={}
var _cache:Dictionary={}
var runtime_profile:Dictionary={}
var _profile_enabled:bool=OS.get_cmdline_user_args().has("--profile-runtime")
func _profile(stage:String,started:int)->void:
	if not _profile_enabled:return
	if not runtime_profile.has(stage):runtime_profile[stage]={"calls":0,"usec":0}
	runtime_profile[stage].calls+=1;runtime_profile[stage].usec+=Time.get_ticks_usec()-started

func _particle_words(meta:Dictionary,machine)->Array:
	var words:Array=meta.words.duplicate();var width:=int(meta.width);var height:=int(meta.height)
	if words.size()!=width*height:return words
	for row in meta.rows:
		if int(row)<0 or int(row)>=height:continue
		for x in width:words[int(row)*width+x]=machine.integer(int(meta.rows[row])+x*4)
	return words

func particle_presentation(request:Dictionary)->Dictionary:
	var bitmaps:Dictionary=request.bitmaps;var machine=request.memory
	if request.get("operation","")=="scanline_words":
		return {"ok":false,"error":"Source particle scanline requested before its bitmap has been painted"}
	var address:=int(request.address);var target:int=int(request.eax)
	if address in [0x8000108,0x800010c]:
		if not bitmaps.has(target):return {"ok":false,"error":"Original particle resize bitmap is not bound"}
		# Raw4E894C/4E8969 continue after DIB allocation into the common
		# FillRect/current-brush and4E8B4C BitBlt/SRCCOPY path. Ghidra's
		# apparent early return at the cleanup boundary is incorrect.
		var resized:Dictionary=bitmaps[target];var pixels:Array=[];pixels.resize(int(resized.width)*int(resized.height));pixels.fill(Raster.color_word(int(resized.get("brush_color",0xffffff))))
		var previous:Dictionary=resized.get("resize_previous",{})
		if previous.get("words",[]).size()==int(previous.get("width",0))*int(previous.get("height",0)):
			for y in mini(int(resized.height),int(previous.get("height",0))):
				for x in mini(int(resized.width),int(previous.get("width",0))):pixels[y*int(resized.width)+x]=previous.words[y*int(previous.width)+x]
		resized.erase("resize_previous")
		resized.words=pixels;resized.rows.clear();return {"ok":true}
	if address in [0x4e3e50,0x4e4158,0x4e4274]:
		for meta in bitmaps.values():
			if (address==0x4e3e50 and int(meta.pen)==target) or (address!=0x4e3e50 and int(meta.brush)==target):
				meta["pen_color" if address==0x4e3e50 else "brush_color" if address==0x4e4158 else "brush_style"]=(int(request.edx)&255) if address==0x4e4274 else int(request.edx)
				return {"ok":true}
		return {"ok":false,"error":"Original particle drawing object is not bound"}
	var stack:=int(request.stack);var meta:Dictionary={}
	if address in [0x5552de,0x5553e0,0x55542e]:target=machine.integer(stack+4)
	for candidate in bitmaps.values():
		if int(candidate.canvas)==target:meta=candidate;break
	if meta.is_empty():return {"ok":false,"error":"Original particle drawing canvas is not bound"}
	var w:=int(meta.width);var h:=int(meta.height)
	var words:Array=_particle_words(meta,machine)
	if words.is_empty():words.resize(w*h);words.fill(0xffffff)
	if address in [0x4e4744,0x5552de,0x5553e0]:
		var l:int;var t:int;var r:int;var b:int
		if address==0x4e4744:
			l=machine._s32(int(request.edx));t=machine._s32(int(request.ecx));r=machine._s32(machine.integer(stack+8));b=machine._s32(machine.integer(stack+4))
		else:
			l=machine._s32(machine.integer(stack+8));t=machine._s32(machine.integer(stack+12));r=machine._s32(machine.integer(stack+16));b=machine._s32(machine.integer(stack+20))
		var result:=Raster.operations(words,w,h,[{"op":"ellipse" if address==0x5552de else "rectangle","left":l,"top":t,"right":r,"bottom":b,"pen_color":meta.get("pen_color",0),"brush_color":meta.get("brush_color",0xffffff),"brush_style":meta.get("brush_style",0)}])
		if not result.ok:return result
	elif address==0x55542e:
		Raster.pixel(words,w,h,machine._s32(machine.integer(stack+8)),machine._s32(machine.integer(stack+12)),Raster.color_word(machine.integer(stack+16)))
	elif address==0x4e44a8:
		var source_pointer:int=machine.integer(stack+4)
		if source_pointer==0:return {"ok":true} #4E44A8 outer source<>nil guard.
		if not bitmaps.has(source_pointer):return {"ok":false,"error":"Original particle Draw bitmap is not bound"}
		var source:Dictionary=bitmaps[source_pointer]
		var source_words:=_particle_words(source,machine)
		if source_words.size()!=int(source.width)*int(source.height):return {"ok":false,"error":"Original particle Draw source has not been painted: %s %dx%d has%d"%[source.name,source.width,source.height,source_words.size()]}
		var dx:int=machine._s32(int(request.edx));var dy:int=machine._s32(int(request.ecx))
		for y in int(source.height):
			for x in int(source.width):
				var color:int=source_words[y*int(source.width)+x]
				#49BBF8 constructs opaque TBitmap layers. Its Draw call copies
				# all source pixels; generic white-key alpha would alter feedback.
				Raster.pixel(words,w,h,x+dx,y+dy,color)
	else:return {"ok":false,"error":"Original particle primitive is not ported: 0x%x"%address}
	return {"ok":true,"bitmap_words":{str(meta.name):words}}

func _asset(stem:String)->Dictionary:
	stem=stem.get_basename().to_lower()
	if _assets.has(stem):return _assets[stem]
	var path:="res://assets/apparatus/"+stem+".png"
	if not ResourceLoader.exists(path):return {"ok":false,"error":"Original drawing resource missing: "+stem}
	var texture:Texture2D=load(path);var image:=texture.get_image();image.convert(Image.FORMAT_RGBA8)
	var bytes:=image.get_data();var words:Array=[];words.resize(image.get_width()*image.get_height())
	# prepare_godot preserves source RGB while introducing display-only alpha.
	# Native +F4/+F8 process the original RGB, including transparent key pixels.
	# All apparatus imports MUST keep process/fix_alpha_border=false: edge
	# color dilation would overwrite source-white RGB before this native read.
	for i in words.size():words[i]=(int(bytes[i*4])<<16)|(int(bytes[i*4+1])<<8)|int(bytes[i*4+2])
	var result:={"ok":true,"words":words,"width":image.get_width(),"height":image.get_height()};_assets[stem]=result;return result

func _settled(words:Array,w:int,h:int,recipe:Dictionary)->Dictionary:
	if recipe.draw_operations.is_empty():return {"ok":true}
	var started:=Time.get_ticks_usec()
	var stencil:Array=[];stencil.resize(w*h);stencil.fill(0xffffff)
	var primitives:Array=[];var arcs:Array=[]
	for op in recipe.draw_operations:
		if op.op in ["rectangle","ellipse"]:primitives.append(op)
		elif op.op=="arc":arcs.append(op)
	var result:=Raster.operations(stencil,w,h,primitives)
	if not result.ok:return result
	var texture:=_asset("guti")
	if not texture.ok:return texture
	# 4744DC TCanvas.Draw uses the original90x90 guti image at0,0, clipped
	# to the destination; it does not scale the texture to the vessel.
	for y in h:
		for x in w:
			var source:int=int(texture.words[y*texture.width+x]) if x<int(texture.width) and y<int(texture.height) else 0
			stencil[y*w+x]=Solid.tint_pixel(int(stencil[y*w+x])|source,int(recipe.color_integer))
	result=Raster.operations(stencil,w,h,arcs)
	if not result.ok:return result
	for i in words.size():words[i]=Solid.composite_pixel(int(words[i]),int(stencil[i]))
	_profile("settled_raster_tint_blend",started)
	return {"ok":true}

func _tilted(words:Array,w:int,h:int,v:Dictionary,catalog:Dictionary)->Dictionary:
	# Fixed source polygons40A4B8, not texture rotation or upright fill ratios.
	var typ:=int(v.type_id);var size:=int(v.native_fields["0x0c"])
	if (typ==101 and size not in [0,45]) or (typ==102 and size not in [100,200,500]) or (typ==103 and size not in [100,250]) or (typ in [104,105] and size!=100) or (typ==121 and size!=50):
		# The source type branch performs no clear or primitive for unmatched
		# subtypes. N18 already assigned the body resource to the active bitmap.
		return {"ok":true,"keep_active_bitmap":true}
	var specs:Dictionary={101:[1,15,87,26,"0ad7a3703d0ad7a3f83f"],201:[3,29,48,60,"0ad7a3703d0ad7a3f83f"],202:[3,29,51,60,"0ad7a3703d0ad7a3f83f"],104:[9,46,84,40,"0ad7a3703d0ad7a3f83f"],105:[9,46,84,39,"0ad7a3703d0ad7a3f83f"],106:[2,96,16,93,"0ad7a3703d0ad7a3f83f"],121:[1,39,15,78,"0ad7a3703d0ad7a3f83f"]}
	if typ==103:
		if size==100:specs[103]=[12,41,62,37,"0ad7a3703d0ad7a3f83f"]
		elif size==250:specs[103]=[16,55,81,51,"3bdf4f8d976e1283f73f"]
	if typ==102:
		if size==100:specs[102]=[1,35,45,70,"0ad7a3703d0ad7a3f83f"]
		elif size==200:specs[102]=[1,46,57,90,"0ad7a3703d0ad7a3f73f"]
		elif size==500:specs[102]=[1,68,81,136,"3bdf4f8d976e1283f63f"]
	if not specs.has(typ):return {"ok":false,"error":"Original tilted polygon branch is not yet ported for type "+str(typ)}
	var spec:Array=specs[typ];var color_state:Dictionary=v.duplicate(true)
	var liquid:=Liquid.refresh(color_state,catalog)
	if not liquid.ok:return liquid
	var solid:=Solid.compute(v,catalog)
	if not solid.ok:return solid
	var layers:Array=[[float(v.get("native_liquid_volume",0.0)),int(color_state.get("native_liquid_color",0xffffff)),int(color_state.get("native_liquid_pen_color",0xffffff))],[float(v.get("native_solid_volume",0.0)),int(solid.get("color_integer",0)),int(solid.get("pen_color",0))]]
	var polygon_pen:=0xffffff #White clear leaves a white pen for the first Polygon.
	for layer_index in layers.size():
		var layer:Array=layers[layer_index]
		if typ==106 and layer_index==1:
			#40C9AB..40CAE6: the tilted horizontal tube uses a separate
			# solid ellipse, with a double-stored volume/capacity height.
			var level:=X.stored_double(X.multiply(X.divide([float(layer[0]),0.0],float(v.volume_ml)),float(h)))
			var left:=Actions._trunc(X.add(Actions._negate(X.multiply([level,0.0],0.5)),float(w-4)))
			var right:=Actions._trunc(X.add(X.multiply(X.multiply([level,0.0],0.5),3.0),float(w-3)))
			var top:=Actions._trunc(X.add([-level,0.0],float(int(h/2))))
			var bottom:=Actions._trunc(X.add([level,0.0],float(int(h/2))))
			return Raster.operations(words,w,h,[{"op":"ellipse","left":left,"top":top,"right":right,"bottom":bottom,"brush_color":layer[1],"pen_color":layer[2]}])
		var product:=X.multiply(X.multiply(X.from_extended80_hex(spec[4]),float(spec[3])),float(layer[0]))
		var y:=Actions._trunc(X.add(Actions._negate(product),float(spec[1])))
		var color:=Raster.color_word(int(layer[1]))
		var points:Array=[[spec[0],spec[1]],[spec[2],spec[1]],[spec[2],y]]
		Raster.triangle(words,w,h,points,color)
		for edge in points.size():
			var a:Array=points[edge];var b:Array=points[(edge+1)%points.size()]
			Raster.line(words,w,h,Vector2i(a[0],a[1]),Vector2i(b[0],b[1]),polygon_pen)
		if typ==121 and layer_index==1:y=Actions._trunc(X.add(Actions._negate(product),35.0)) #Original solid LineTo differs from its polygon.
		polygon_pen=Raster.color_word(int(layer[2]))
		Raster.line(words,w,h,Vector2i(spec[0],spec[1]),Vector2i(spec[2],y),polygon_pen)
	return {"ok":true}

func render(vessel:Dictionary,catalog:Dictionary,preceding:Array=[],background:int=0xffffff,particle_stage:Callable=Callable())->Dictionary:
	var started:=Time.get_ticks_usec();var stage_started:=started
	var v:Dictionary=vessel.duplicate(true)
	var w:=int(v.get("native_bitmap_width",0));var h:=int(v.get("native_bitmap_height",0))
	if w<=0 or h<=0:return {"ok":false,"error":"Original bitmap dimensions missing"}
	var identity:=[v.get("native_bitmap_plain",v.kind),v.get("native_bitmap_fill",""),v.native_fields.get("0x18"),v.native_fields.get("0x38"),v.native_fields.get("0x0c"),v.type_id,v.volume_ml,v.contents,v.get("native_species_volume",{}),v.get("solid_3cd8",{}),v.get("native_liquid_volume",0),v.get("native_solid_volume",0),w,h]
	var key:=str(hash(identity));var material:Dictionary
	if not particle_stage.is_valid() and _cache.has(key):material=_cache[key]
	else:
		var body_stem:=str(v.get("native_bitmap_plain",v.get("native_texture_kind",v.kind))).get_basename()
		var mask_stem:=str(v.get("native_bitmap_fill","_"+body_stem)).get_basename()
		if not mask_stem.begins_with("_"):mask_stem="_"+mask_stem
		var body:=_asset(body_stem);var mask:=_asset(mask_stem)
		if not body.ok:return body
		if not mask.ok:return mask
		if body.width!=w or body.height!=h:return {"ok":false,"error":"Original active/body bitmap resource dimensions differ"}
		var words:Array=[];words.resize(w*h);words.fill(0xffffff)
		var result:Dictionary
		if int(v.native_fields["0x18"])==2 and int(v.native_fields["0x38"])==0:
			result=_tilted(words,w,h,v,catalog)
			if result.get("keep_active_bitmap",false):words=body.words.duplicate()
		else:
			result=Liquid.refresh(v,catalog)
			if result.ok and float(v.native_liquid_height)!=0.0:
				var r:Array=v.native_liquid_rectangle
				result=Raster.operations(words,w,h,[{"op":"rectangle","left":r[0],"top":r[1],"right":r[2],"bottom":r[3],"pen_color":v.native_liquid_pen_color,"brush_color":v.native_liquid_color}])
			if result.ok:
				var gas:=Gas.compute(v,catalog);result=gas
				if gas.ok:result=Raster.operations(words,w,h,gas.draw_operations)
			if result.ok and particle_stage.is_valid():
				_profile("liquid_gas_recipes",stage_started);stage_started=Time.get_ticks_usec()
				result=particle_stage.call(words,Callable(self,"particle_presentation"),"solid")
				_profile("solid_particle_vm",stage_started);stage_started=Time.get_ticks_usec()
				if result.ok:
					words=result.words
					for field in ["solid_3cd8","solid_3ff8","native_particle_3cc8"]:
						if vessel.has(field):v[field]=vessel[field].duplicate(true) if vessel[field] is Dictionary else vessel[field]
			if result.ok and float(v.native_liquid_height)>1.0:
				var surface:=Surface.compute(v);result=surface
				if surface.ok:result=Raster.operations(words,w,h,surface.draw_operations)
			if result.ok:
				var solid:=Solid.compute(v,catalog);result=solid
				if solid.ok:result=_settled(words,w,h,solid)
			if result.ok and particle_stage.is_valid():
				_profile("surface_solid_recipes",stage_started);stage_started=Time.get_ticks_usec()
				result=particle_stage.call(words,Callable(self,"particle_presentation"),"gas")
				_profile("gas_particle_vm",stage_started)
				if result.ok:words=result.words
		if not result.ok:return result
		var weight:=Fill.fill_weight(v)
		stage_started=Time.get_ticks_usec()
		for i in words.size():
			# CopyRect uses identical0,0,w,h source/destination rectangles.
			# _dzxp250 is84x79 while its active body is84x80: source GDI
			# clipping leaves the last destination row untouched, not stretched.
			var x:=i%w;var y:=int(i/w)
			var mask_word:=int(mask.words[y*int(mask.width)+x]) if x<int(mask.width) and y<int(mask.height) else 0
			var painted:=int(words[i])|mask_word;var pair:="%x:%x:%s"%[painted,int(body.words[i]),weight]
			if not _fill_pixels.has(pair):_fill_pixels[pair]=Fill.fill_pixel(painted,int(body.words[i]),weight)
			words[i]=_fill_pixels[pair]
		_profile("fill_mask_blend",stage_started)
		material={"words":words,"width":w,"height":h}
		if not particle_stage.is_valid():_cache[key]=material
	var words:Array=material.words.duplicate();var left:=int(v.position[0])-int(w/2);var top:=int(v.position[1])-int(h/2)
	stage_started=Time.get_ticks_usec()
	for y in h:
		for x in w:
			var beneath:=background
			for earlier in preceding:
				var ex:=left+x-int(earlier.top_left[0]);var ey:=top+y-int(earlier.top_left[1])
				if ex>=0 and ey>=0 and ex<int(earlier.width) and ey<int(earlier.height):beneath=int(earlier.words[ey*int(earlier.width)+ex])
			var foreground:int=words[y*w+x];var pair:="%x:%x"%[foreground,beneath]
			if not _composite_pixels.has(pair):_composite_pixels[pair]=Solid.composite_pixel(foreground,beneath,0.5)
			words[y*w+x]=_composite_pixels[pair]
	_profile("canvas_overlap_blend",stage_started);_profile("render_total",started)
	if _profile_enabled and int(runtime_profile.render_total.calls)%30==0:print(JSON.stringify({"source_renderer_profile":runtime_profile}))
	return {"ok":true,"words":words,"width":w,"height":h,"top_left":[left,top],"image":Images.words_to_image(words,w,h),"source_logic":0x40a4b8,"portable_raster":true,"native_vcl_verified":false}
