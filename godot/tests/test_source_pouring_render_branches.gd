extends SceneTree
const Model=preload("res://scripts/original_model_host.gd")
const Factory=preload("res://scripts/original/original_factory.gd")
const Renderer=preload("res://scripts/original/original_source_renderer.gd")
var failures:Array=[]
func _initialize()->void:
	var model=Model.new();model.configure(JSON.parse_string(FileAccess.get_file_as_string("res://data/reagents.json")),JSON.parse_string(FileAccess.get_file_as_string("res://data/reactions.json")))
	var renderer=Renderer.new();var cases:Array=[]
	for kind in Factory.choices():
		var template:Dictionary=Factory.create(kind,Vector2(100,100),1,0)
		if int(template.vessel.type_id) not in [101,102,103,104,105,106,121,201,202]:continue
		model.reset()
		var v:Dictionary=model.add_apparatus(kind,Vector2(100,100))
		if v.is_empty():failures.append([kind,"allocation",model.last_error]);continue
		if not model.add_reagent(v.id,"H2O(液体)",0.5):failures.append([kind,"water",model.last_error]);continue
		if not model.toggle_pour(v.id):failures.append([kind,"orientation",model.last_error]);continue
		var frame:Dictionary=renderer.render(v,model._species)
		if not frame.ok:failures.append([kind,"render",frame.error]);continue
		cases.append([kind,int(v.type_id),int(v.native_fields["0x0c"]),frame.width,frame.height,hash(frame.words)])
	print(JSON.stringify({"source_pouring_branches":cases,"failures":failures,"profiles_injected":false}))
	if failures.is_empty():print("PASS every pourable original factory choice renders its source orientation branch")
	quit(0 if failures.is_empty() else 1)
