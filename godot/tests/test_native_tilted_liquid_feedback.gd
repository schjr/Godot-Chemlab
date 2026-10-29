extends SceneTree
const Host=preload("res://scripts/original_model_host.gd")
const Formats=preload("res://scripts/legacy_formats.gd")
const Adapter=preload("res://scripts/experiment_adapter.gd")
var failures:Array=[]
func check(value:bool,label:String)->void:
	if not value:failures.append(label)
func same_bits(a:float,b:float)->bool:
	return PackedFloat64Array([a]).to_byte_array()==PackedFloat64Array([b]).to_byte_array()
func _initialize()->void:
	# Source40A4B8 open-tilted branch bypasses471650; unlike common material,
	# it does not write liquid height or cap the physical liquid-volume cache.
	# Import the shipped example through the normal model path, with no profile.
	var model=Host.new()
	var doc:Dictionary=Formats.load_document("res://tests/fixtures/examples/氢氧化铜与氢氧化铁.cem")
	check(model.from_state(Adapter.to_state(doc)),"normal shipped example import")
	if not failures.is_empty():print(JSON.stringify({"failures":failures}));quit(1);return
	var bottle:Dictionary=model.native_apparatus()[1]
	var initial_height:float=bottle.native_liquid_height
	var initial_volume:float=bottle.native_liquid_volume
	check(int(bottle.native_fields["0x38"])==0,"opening reagent bottle is open")
	check(model.toggle_pour(int(bottle.id)),"normal pouring orientation toggle")
	check(bottle.native_bitmap_plain=="dxkp" and bottle.native_bitmap_width==52 and bottle.native_bitmap_height==30,"toggle loads original tilted bitmap dimensions")
	check(same_bits(bottle.native_liquid_height,initial_height),"tilted branch retains actual preceding upright liquid height")
	check(same_bits(bottle.native_liquid_volume,initial_volume),"tilted toggle retains current physical liquid volume")
	# Source quantity calculation permits over-capacity liquids. Only the common
	# 471650 display path clips +4320; the fixed tilted branch must leave it alone.
	bottle.contents["H2O(液体)"]=200.0/18.016
	check(model.recalc(),"source over-capacity quantity pass")
	var untrimmed:float=bottle.native_liquid_volume
	check(untrimmed>float(bottle.volume_ml),"source quantities retain over-capacity volume")
	check(model.refresh_render_state(),"normal tilted material refresh")
	check(same_bits(bottle.native_liquid_volume,untrimmed),"tilted refresh never applies upright capacity clamp")
	check(same_bits(bottle.native_liquid_height,initial_height),"tilted refresh never resets stored liquid height")
	# The source predicate is both orientation2 AND open: a closed tilted bottle
	# still takes common material, and returning upright restores the same path.
	bottle.native_fields["0x38"]="1"
	check(model.refresh_render_state(),"closed tilted common material refresh")
	check(same_bits(bottle.native_liquid_volume,float(bottle.volume_ml)),"closed tilted common material keeps source display clamp")
	check(same_bits(bottle.native_liquid_height,30.5),"closed tilted common material uses actual tilted height")
	bottle.native_fields["0x38"]="0"
	check(model.recalc(),"restore source quantities before upright toggle")
	check(model.toggle_pour(int(bottle.id)),"normal upright orientation toggle")
	check(bottle.native_bitmap_plain=="xkp" and bottle.native_bitmap_width==30 and bottle.native_bitmap_height==52,"toggle restores original upright bitmap dimensions")
	check(same_bits(bottle.native_liquid_volume,float(bottle.volume_ml)) and same_bits(bottle.native_liquid_height,52.5),"upright common material retains original scalar feedback")
	print(JSON.stringify({"failures":failures}))
	if failures.is_empty():print("PASS normal pouring orientation preserves source tilted liquid feedback and common-material frontier")
	quit(0 if failures.is_empty() else 1)
