extends SceneTree
## Actual original FC bytes, with declared CEM-coordinate/background hypotheses.
## This is a bounded checkpoint comparison, never a production VCL profile.
const Renderer = preload("res://scripts/original/original_vessel_bitmap_renderer.gd")
const Solid = preload("res://scripts/original/original_solid_visual.gd")
const EXAMPLES_SHA := "2e92fdb024ad9b5b13acfe1c8f9814001a4903196c279fd7e12ef410cf3dc56c"
var failures: Array = []
func require_input(condition: bool, message: String)->bool:
	if not condition: failures.append(message)
	return condition
func unpack32(bitmap: Dictionary)->Array:
	var raw := Marshalls.base64_to_raw(str(bitmap.topdown_base64))
	var count := int(bitmap.width)*int(bitmap.height)
	if raw.size()!=count*4 or int(bitmap.row_stride)!=int(bitmap.width)*4:return []
	var result: Array = []
	for index in count:result.append(int(raw.decode_u32(index*4)))
	return result
func unpack24_rgb(bitmap: Dictionary)->Array:
	var width := int(bitmap.width);var height := int(bitmap.height)
	var stride := (width*3+3)&~3
	var raw := Marshalls.base64_to_raw(str(bitmap.topdown_base64))
	if raw.size()!=stride*height or int(bitmap.row_stride)!=stride:return []
	var result: Array = []
	for y in height:
		for x in width:
			var offset := y*stride+x*3
			result.append(int(raw[offset])|(int(raw[offset+1])<<8)|(int(raw[offset+2])<<16))
	return result
func _initialize()->void:
	var path := OS.get_environment("CHEMLAB_DIB_INPUT_PATH")
	var digest := OS.get_environment("CHEMLAB_DIB_INPUT_SHA256")
	if path.is_empty() and digest.is_empty():
		print("PENDING: requires validated original DIB comparison input and SHA256");quit(2);return
	if not require_input(digest.length()==64 and FileAccess.file_exists(path) and FileAccess.get_sha256(path)==digest,"Validated original DIB input identity differs"): finish(0);return
	var input: Variant = JSON.parse_string(FileAccess.get_file_as_string(path))
	if not require_input(input is Dictionary and input.get("format","")=="chemlab-original-dib-comparison-input-v1" and input.get("native_vcl_verified",true)==false and input.get("inputs",[]).size()==6,"Actual comparison input format differs"): finish(0);return
	if not require_input(FileAccess.get_sha256("res://data/examples.json")==EXAMPLES_SHA,"Source CEM coordinate hypothesis identity differs"): finish(0);return
	var documents: Array = JSON.parse_string(FileAccess.get_file_as_string("res://data/examples.json"))
	var source: Dictionary = {}
	for document in documents:
		if document.name=="氢氧化铜与氢氧化铁":source=document;break
	if not require_input(source.get("apparatus",[]).size()==6,"Original six-apparatus CEM is absent"): finish(0);return
	var observed_canvas: Dictionary = {}
	var checked := 0
	for row in input.inputs:
		var native_index := int(row.native_index)
		var width := int(row.width);var height := int(row.height);var count := width*height
		if not require_input(native_index>=0 and native_index<6 and int(row.bitmaps["0xfc"].bitmap_format)==32 and int(row.bitmaps["0xf4"].bitmap_format)==32 and int(row.bitmaps["0xf8"].bitmap_format)==24,"Original observed bitmap format differs"):finish(checked);return
		if not require_input(str(row.gas_delta_hex).hex_decode().decode_double(0)==0.0,"Observed gas delta changed from the native material input"):finish(checked);return
		var actual := unpack32(row.bitmaps["0xfc"]);var fill := unpack32(row.bitmaps["0xf4"]);var plain := unpack24_rgb(row.bitmaps["0xf8"])
		var raw := Marshalls.base64_to_raw(str(row.material_bgra))
		if not require_input(actual.size()==count and fill.size()==count and plain.size()==count and raw.size()==count*4,"Observed bitmap payload is incomplete"):finish(checked);return
		var original: Dictionary = source.apparatus[native_index]
		if not require_input(int(original.type_id)==int(row.type_id) and int(original.native_fields["0x0c"])==int(row.native_type_parameter),"Source CEM type/parameter hypothesis differs"):finish(checked);return
		var origin := Vector2i(int(original.native_fields["0x10"])-(width>>1),int(original.native_fields["0x14"])-(height>>1))
		var vessel := {"type_id":int(row.type_id),"native_fields":{"0x0c":str(row.native_type_parameter)}}
		for index in count:
			var painted := (int(raw.decode_u32(index*4))|int(plain[index]))&0xFFFFFFFF
			var foreground := Renderer.fill_pixel(painted,int(fill[index]),Renderer.fill_weight(vessel))
			var alternative := Renderer.fill_pixel((painted&0xFFFFFF)|0xFF000000,int(fill[index]),Renderer.fill_weight(vessel))
			if foreground<0 or foreground!=alternative:
				failures.append("24-bit source reserved-byte elimination failed");finish(checked);return
			var point := origin+Vector2i(index%width,int(index/width))
			var final_word := Solid.composite_pixel(foreground,int(observed_canvas.get(point,0xFFFFFF)),0.5)
			if final_word!=int(actual[index]):
				failures.append("Original FC word differs at vessel "+str(native_index)+" pixel "+str(index));finish(checked);return
			checked+=1
		for index in count:observed_canvas[origin+Vector2i(index%width,int(index/width))]=actual[index]
	finish(checked)
func finish(checked: int)->void:
	if failures.is_empty() and checked==11548:
		print("PASS actual original six-vessel capture: 11548 final native words; explicit CEM overlap hypothesis; no complete VCL attestation")
		quit(0)
	else:
		print(JSON.stringify({"observed_pixel_checks":checked,"failures":failures}))
		quit(1)
