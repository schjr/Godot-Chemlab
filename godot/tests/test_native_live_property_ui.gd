extends SceneTree
const Slots=preload("res://scripts/original/original_slots.gd")
const Live=preload("res://scripts/original/original_live_property.gd")
var app
func _initialize():call_deferred("_run")
func _run():
	app=load("res://scenes/main.tscn").instantiate();root.add_child(app)
	await process_frame;await process_frame
	var cases:=0
	for index in app.examples.size():
		assert(app.load_example(index))
		var zero:=PackedByteArray();zero.resize(800);zero.fill(0)
		for vessel in app.model.native_apparatus():
			for field in ["native_species_volume","solid_3cd8","solid_3ff8"]:assert(Slots.observe(vessel,field,zero.hex_encode(),{"source":"declared native oracle numerical allocation profile"}).ok)
		assert(app.model.start())
		var vessel:Dictionary={}
		for candidate in app.model.native_apparatus():
			if int(candidate.type_id)>100 and int(candidate.type_id)<300 and not candidate.contents.is_empty():vessel=candidate;break
		assert(not vessel.is_empty())
		app.dialogs.show_properties(vessel.id)
		var window:Window=app.get_child(app.get_child_count()-1)
		var tree:Tree=window.find_child("ChemicalRows",true,false)
		var amount:LineEdit=window.find_child("ChemicalMoles",true,false)
		amount.text="retained selection edit"
		var state:Dictionary={"hook":false,"program":false}
		var program:Callable=app.model.program_callback
		app.model.program_callback=func(a:Array,t:float):
			var result:Dictionary=program.call(a,t);state.program=true;return result
		var before_segments:=0
		for v in app.model.vessels:before_segments+=v.get("native_chart_segments",[]).size()
		var observer:Callable=func(a:Array):
			assert(state.program);state.hook=true
			var current:=0
			for v in a:current+=v.get("native_chart_segments",[]).size()
			assert(current==before_segments)
		app.model.native_property_refresh.connect(observer)
		app.model.step(0.02,{"observed_stack_excess":0.0})
		assert(app.model.last_error.is_empty(),app.model.last_error);assert(state.hook)
		assert(amount.text=="retained selection edit")
		var expected:=Live.rows(app.model.get_vessel(vessel.id));assert(expected.ok)
		var item:=tree.get_root().get_first_child()
		for row in expected.rows:
			assert(item!=null)
			for column in 3:assert(item.get_text(column)==str(row[column]))
			item=item.get_next()
		assert(item==null)
		# Paused source timer skips the live refresh block and never updates cells.
		app.model.running=false;app.model.paused=true
		item=tree.get_root().get_first_child();item.set_text(1,"paused retained")
		app.model.step(0.02,{"observed_stack_excess":0.0});assert(item.get_text(1)=="paused retained")
		app.model.native_property_refresh.disconnect(observer);app.model.program_callback=program
		window.queue_free();await process_frame
		assert(app.model.native_property_refresh.get_connections().is_empty())
		cases+=1
	print("PASS native live Form4 grid: ",cases," imports/accepted ticks, program→grid→chart, unchanged selection edits, pause and close")
	app.free();quit()
