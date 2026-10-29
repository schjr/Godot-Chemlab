extends SceneTree
const Branch=preload("res://scripts/original/original_vessel_display_branch.gd")
const Scale=preload("res://scripts/original/original_bitmap_scale.gd")
func _initialize()->void:
	var path:=ProjectSettings.globalize_path("res://")+"../evidence/original_logic/native-bitmap-scale-oracle.json"
	var fixture:Dictionary=JSON.parse_string(FileAccess.get_file_as_string(path))
	assert(fixture.binary_sha256=="7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c")
	var words_checked:=0
	for c in fixture.cases:
		var source:Array=[]
		for word in c.source_words:source.append(int(word))
		var result:=Scale.resample(source,int(c.width),int(c.height),c.scale32_bits.hex_decode().decode_float(0),int(c.reserved_byte))
		assert(result.ok,str(result))
		assert(result.native_return==int(c.native_return))
		if result.native_return==0:
			assert(result.width==int(c.destination_width) and result.height==int(c.destination_height))
			for i in result.words.size():
				assert(result.words[i]==int(c.native_words[i]),"Native scaling pixel mismatch case %s index %d actual %x expected %x"%[c.scale32_bits,i,result.words[i],int(c.native_words[i])])
				words_checked+=1
	assert(not Scale.resample([0,0,0,0],2,2,1.5).ok,"Unknown stack high byte was fabricated")
	assert(not Scale.resample([0],2,2,1.0,0).ok)
	var tall:Array=[];tall.resize(600);tall.fill(0)
	assert(not Scale.resample(tall,2,300,4.0,0).ok,"Native stack overflow was silently approximated")
	var v:Dictionary={"native_fields":{"0x18":2,"0x38":0}}
	assert(Branch.classify(v).branch=="fixed_tilted_material")
	v.native_fields["0x38"]=1
	assert(Branch.classify(v).branch=="direct_canvas_geometry_then_common_material")
	v.native_fields["0x38"]=3
	assert(Branch.classify(v).branch=="common_material")
	assert(not Branch.plan(v,1.5,{}).ok,"Nonzero orientation silently assumed upright resources")
	var binding:={"source_state_bitmap_binding_verified":true,"source_orientation":2,"source_geometry_state":3}
	var recipe:=Branch.plan(v,1.5,binding)
	assert(recipe.ok and recipe.scaled and not recipe.generic_rotation)
	assert(recipe.stages[3]=="48F1E0_scale_into_5867F0")
	assert(not Branch.plan(v,1.001,binding).scaled)
	var normal:=Branch.placement(5,7,[-10,-20],false)
	var scaled:=Branch.placement(5,7,[-10,-20],true)
	assert(normal.display_top_left==[-12,-23] and scaled.display_top_left==[-12,-23])
	assert(normal.background_source_rect==[-12,-23,-7,-16])
	assert(not Branch.placement(5,7,[-10.0,-20.0],false).ok)
	print("Original48F1E0 scaling PASS: %d native cases, %d full uint32 words; VCL conversion and scanline callbacks remain explicit boundaries"%[fixture.cases.size(),words_checked])
	quit()
