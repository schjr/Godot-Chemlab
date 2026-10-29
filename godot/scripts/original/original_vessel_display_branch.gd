class_name OriginalVesselDisplayBranch
extends RefCounted
## Source40A4B8 branch/operand recipe. Does not rasterize tilted polygons,
## resize through GDI, replace assets, or attest a VCL profile.
const X87=preload("res://scripts/original/original_x87.gd")
const Actions=preload("res://scripts/original/original_apparatus_actions.gd")
static func classify(vessel:Dictionary)->Dictionary:
	var fields:Dictionary=vessel.get("native_fields",{})
	if not fields.has("0x18") or not fields.has("0x38"):return {"ok":false,"error":"Original +18 and +38 state fields are required"}
	var branch:String
	if int(fields["0x18"])==2 and int(fields["0x38"])==0:branch="fixed_tilted_material"
	elif int(fields["0x38"])==1:branch="direct_canvas_geometry_then_common_material"
	else:branch="common_material"
	return {"ok":true,"branch":branch,"native_function":0x40A4B8,"generic_rotation":false,"source_orientation":int(fields["0x18"]),"source_geometry_state":int(fields["0x38"])}
static func plan(vessel:Dictionary,scale:float,bitmap_binding:Dictionary)->Dictionary:
	var selected:=classify(vessel)
	if not selected.ok:return selected
	# No implicit upright asset binding for any nonzero original orientation.
	if int(selected.source_orientation)!=0:
		if not bitmap_binding.get("source_state_bitmap_binding_verified",false) or int(bitmap_binding.get("source_orientation",-1))!=int(selected.source_orientation) or int(bitmap_binding.get("source_geometry_state",-1))!=int(selected.source_geometry_state):
			return {"ok":false,"error":"Nonzero source orientation requires observed +F4/+F8/+FC bitmap bindings for the exact +18/+38 state","selected_branch":selected.branch}
	if not is_finite(scale):return {"ok":false,"error":"Native scale is not finite"}
	var difference:=absf(X87.stored_double(X87.add([scale,0.0],-1.0))) #40FBB5..40FBBE
	selected.scaled= difference>=0.01
	selected.scale_argument32=X87.stored_float32([scale,0.0])
	selected.stages=["material_branch", "F8_SRCPAINT", "4926E0_fill"]
	if selected.scaled:
		selected.stages.append_array(["48F1E0_scale_into_5867F0", "CopyRect_canvas_background_into_local88", "492560_background_into_5867F0_weight0.5", "BitBlt_SRCCOPY_5867F0"])
		selected.required_boundaries=["native_pf32_conversion_source_and_shared_destination", "shared5867F0_prior_dimensions_when_scale_helper_returns1", "interpolated_EBP_minus11_reserved_byte", "original_scanline_layout", "canvas_CopyRect_DC_and_clipping", "original_canvas_background_words"]
	else:
		selected.stages.append_array(["CopyRect_canvas_background_into_local88", "492560_background_into_FC_weight0.5", "SetTransparentColorFFFFFF", "BitBlt_SRCCOPY_FC"])
		selected.required_boundaries=["original_canvas_background_words", "canvas_CopyRect_DC_and_clipping"]
	if selected.branch=="fixed_tilted_material":selected.required_boundaries.append("type_and_subtype_specific_fixed_polygons_and_lines")
	if selected.branch=="direct_canvas_geometry_then_common_material":selected.required_boundaries.append("original_direct_canvas_geometry_before_material_and_background_capture")
	return selected
static func placement(width:int,height:int,center:Array,scaled:bool)->Dictionary:
	if width<0 or height<0 or center.size()!=2:return {"ok":false,"error":"Native bitmap dimensions and integer center required"}
	for value in center:
		if not value is int:return {"ok":false,"error":"Original +10/+14 center must be integer"}
	var bounds:Array=[]
	for spec in [[center[0],width,-0.5],[center[1],height,-0.5],[center[0],width,0.5],[center[1],height,0.5]]:
		bounds.append(Actions._trunc(X87.add(X87.add(X87.multiply([float(spec[1]),0.0],spec[2]),float(spec[0])),0.5)))
	# Scaled destination FTOL(center-size*.5+.5); unscaled uses center-IDIV2.
	return {"ok":true,"background_source_rect":bounds,"background_destination_rect":[0,0,width,height],"display_top_left":bounds.slice(0,2) if scaled else [center[0]-int(width/2),center[1]-int(height/2)],"display_dimensions":[width,height],"display_rop":0xCC0020,"compositor":0x492560,"compositor_weight":0.5}
