extends SceneTree
## Bounded hypothesis comparison, never a production VCL attestation.
const Renderer = preload("res://scripts/original/original_vessel_bitmap_renderer.gd")
const Raster = preload("res://scripts/original/original_material_rasterizer.gd")
const Solid = preload("res://scripts/original/original_solid_visual.gd")
func fail(message: String) -> void:
	push_error(message)
	quit(1)
func words(base64: String, count: int) -> Array:
	var raw := Marshalls.base64_to_raw(base64)
	if raw.size() != count*4: return []
	var result: Array = []
	for index in count: result.append(int(raw.decode_u32(index*4)))
	return result
func plain_rgb_projection(bitmap: Dictionary) -> Array:
	# Analysis only: unpack visible BGR bytes, retaining row padding. Zero in
	# the unused byte is a placeholder, never a native GDI conversion claim.
	var width := int(bitmap.width)
	var height := int(bitmap.height)
	var stride := int(bitmap.row_stride)
	var raw := Marshalls.base64_to_raw(str(bitmap.topdown_base64))
	if stride != ((width*3+3)&~3) or raw.size() != stride*height: return []
	var result: Array = []
	for y in height:
		for x in width:
			var offset := y*stride+x*3
			result.append(int(raw[offset])|(int(raw[offset+1])<<8)|(int(raw[offset+2])<<16))
	return result
func _initialize() -> void:
	var args := OS.get_cmdline_user_args()
	if args.size() not in [3,5]:
		print("PENDING: requires validated comparison input, its SHA256 and a new output directory")
		quit(2); return
	if not FileAccess.file_exists(args[0]) or FileAccess.get_sha256(args[0]) != args[1]: fail("Validated DIB comparison input identity differs"); return
	if DirAccess.dir_exists_absolute(args[2]): fail("Preserve existing comparison output; choose a new directory"); return
	var input: Variant = JSON.parse_string(FileAccess.get_file_as_string(args[0]))
	if not input is Dictionary or input.get("format","") != "chemlab-original-dib-comparison-input-v1" or input.get("native_vcl_verified",true) != false or input.get("inputs",[]).size() != 6:
		fail("Validated DIB comparison format differs"); return
	var overlap: Dictionary = {}
	if args.size()==5:
		if not FileAccess.file_exists(args[3]) or FileAccess.get_sha256(args[3])!=args[4]: fail("Canvas overlap hypothesis identity differs"); return
		var value: Variant = JSON.parse_string(FileAccess.get_file_as_string(args[3]))
		if not value is Dictionary or value.get("format","")!="chemlab-original-canvas-overlap-hypothesis-v1" or value.get("positions",[]).size()!=6 or value.get("native_scale",0)!=1 or value.get("background_rgb",-1)!=0xFFFFFF:
			fail("Unsupported bounded canvas hypothesis"); return
		if value.get("source_examples_sha256","")!=FileAccess.get_sha256("res://data/examples.json"): fail("Hypothesized source CEM identity differs"); return
		for position in value.positions:
			if not position is Array or position.size()!=2: fail("Canvas hypothesis position is incomplete"); return
			for coordinate in position:
				if coordinate!=int(coordinate) or coordinate<1024*-1 or coordinate>1024: fail("Canvas hypothesis coordinate is unsupported"); return
		overlap=value
	for row in input.inputs:
		if str(row.gas_delta_hex).hex_decode().decode_double(0) != 0.0: fail("Observed gas delta differs from the material corpus hypothesis"); return
		for field in ["0xfc","0xf4"]:
			var bitmap: Dictionary = row.bitmaps[field]
			if int(bitmap.bitmap_format) != 32 or int(bitmap.row_stride) != int(row.width)*4:
				fail("Material/fill source format requires evidenced native conversion"); return
		if int(row.bitmaps["0xf8"].bitmap_format) not in [24,32]:
			fail("Unsupported source format for bounded RGB hypothesis"); return
	if DirAccess.make_dir_recursive_absolute(args[2]) != OK: fail("Cannot create bounded comparison output directory"); return
	var rows: Array = []
	var observed_canvas: Dictionary = {}
	for row in input.inputs:
		var count := int(row.width)*int(row.height)
		var material := words(str(row.material_bgra), count)
		var actual := words(str(row.bitmaps["0xfc"].topdown_base64), count)
		var plain_is24 := int(row.bitmaps["0xf8"].bitmap_format)==24
		var plain := plain_rgb_projection(row.bitmaps["0xf8"]) if plain_is24 else words(str(row.bitmaps["0xf8"].topdown_base64), count)
		var fill := words(str(row.bitmaps["0xf4"].topdown_base64), count)
		if material.size()!=count or actual.size()!=count or plain.size()!=count or fill.size()!=count: fail("Validated native pixel payload is incomplete"); return
		var vessel := {"type_id":int(row.type_id),"native_fields":{"0x0c":str(row.native_type_parameter)}}
		var candidate: Array = []
		var differences := {"word_differences":0,"rgb_pixel_differences":0,"reserved_byte_differences":0}
		var origin := Vector2i.ZERO
		if not overlap.is_empty():
			var position: Array = overlap.positions[int(row.native_index)]
			# Source40FC4E/8D/C5/FD FTOL(center±size*.5+.5) capture
			# and40FE60 center-TRUNC(size/2) SRCCOPY agree here for positive
			# integer centers and these same-size source rectangles.
			if int(position[0])<=int(row.width) or int(position[1])<=int(row.height): fail("Unsupported source overlap rounding/clip branch"); return
			origin=Vector2i(int(position[0])-(int(row.width)>>1),int(position[1])-(int(row.height)>>1))
		for index in count:
			# This candidate deliberately retains the documented omitted-stage
			# boundary. No verified-material flag is fabricated to bypass a gate.
			var value := Renderer.fill_pixel((int(material[index])|int(plain[index]))&0xFFFFFFFF,int(fill[index]),Renderer.fill_weight(vessel))
			if value < 0: fail("Original4926E0 arithmetic is unresolved"); return
			if plain_is24:
				#4926E0 tests only RGB, then either copies the complete32-bit
				# fill word or clears the output reserved byte. Both extremes
				# confirm the projected plain byte cannot affect final words.
				var alternative := Renderer.fill_pixel(((int(material[index])|int(plain[index]))&0xFFFFFF)|0xFF000000,int(fill[index]),Renderer.fill_weight(vessel))
				if alternative!=value: fail("Unobserved24-bit source byte affects final pixels"); return
			if not overlap.is_empty():
				var point := origin+Vector2i(index%int(row.width),int(index/int(row.width)))
				value=Solid.composite_pixel(value,int(observed_canvas.get(point,0xFFFFFF)),0.5)
				if value<0: fail("Original492560 background blend is unresolved"); return
			candidate.append(value)
			if value != actual[index]: differences.word_differences += 1
			if (value&0xFFFFFF) != (int(actual[index])&0xFFFFFF): differences.rgb_pixel_differences += 1
			if (value>>24) != (int(actual[index])>>24): differences.reserved_byte_differences += 1
		if not overlap.is_empty():
			# Earlier canvas pixels come from actual captured FC, not a passing
			# candidate substituted as evidence. Background outside them stays
			# the explicit hypothesis and does not establish runtime provenance.
			for index in count:
				observed_canvas[origin+Vector2i(index%int(row.width),int(index/int(row.width)))]=actual[index]
		var prefix := args[2].path_join("vessel-"+str(int(row.native_index)))
		if Raster.words_to_image(actual,int(row.width),int(row.height)).save_png(prefix+"-original.png") != OK or Raster.words_to_image(candidate,int(row.width),int(row.height)).save_png(prefix+"-candidate.png") != OK:
			fail("Cannot save bounded comparison preview"); return
		rows.append({"native_index":row.native_index,"width":row.width,"height":row.height,"differences":differences,"native_vcl_verified":false,"plain_bitmap_format":row.bitmaps["0xf8"].bitmap_format,"native_24_to_32_reserved_byte_verified":false,"unobserved_plain_byte_eliminated_by_4926e0":plain_is24,"comparison_scope":"Final-word hypothesis from same-size RGB SRCPAINT and original4926E0 arithmetic; native24-to32 intermediate byte remains unobserved but cannot affect fill output","omitted_stages":["retained particles","running overlays"],"original_png":prefix+"-original.png","candidate_png":prefix+"-candidate.png"})
	var report := {"format":"chemlab-original-dib-bounded-comparison-v1","input_sha256":args[1],"native_vcl_verified":false,"scope":input.scope,"vessels":rows}
	if not overlap.is_empty():
		report["canvas_overlap_hypothesis"]=overlap
		report["canvas_overlap_hypothesis_sha256"]=args[4]
		report["runtime_canvas_coordinates_verified"]=false
	var output := FileAccess.open(args[2].path_join("comparison.json"),FileAccess.WRITE)
	if output == null: fail("Cannot save bounded comparison report"); return
	output.store_string(JSON.stringify(report,"\t")); output.close()
	print(JSON.stringify(report))
	quit(0)
