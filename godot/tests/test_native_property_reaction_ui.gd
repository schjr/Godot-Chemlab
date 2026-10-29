extends SceneTree
const Model=preload("res://scripts/lab_model.gd")
const Dialogs=preload("res://scripts/lab_dialogs.gd")
func bits(v:float)->String:return PackedFloat64Array([v]).to_byte_array().hex_encode()
func press(w:Window,name:String):w.find_child(name,true,false).pressed.emit()
func _initialize():call_deferred("_run")
func _run():
	var owner:=Control.new();root.add_child(owner)
	var reagents:Array=JSON.parse_string(FileAccess.get_file_as_string("res://data/reagents.json"))
	var reactions:Array=JSON.parse_string(FileAccess.get_file_as_string("res://data/reactions.json"))
	var fixture=JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_property_reaction.json"))
	var tested:=0
	for c in fixture.cases:
		if int(c.row)!=1:continue
		for confirm in [false,true]:
			var model:=Model.new();model.configure(reagents,reactions);var vessel:=model.add_apparatus("sb100")
			var dialogs:=Dialogs.new();dialogs.configure(owner,model);assert(dialogs.append_native_reaction_row(vessel,reactions[0]))
			var previous:Dictionary=vessel.native_reaction_records[0].duplicate(true);var name:String=vessel.label
			dialogs.show_properties(vessel.id);var w:Window=owner.get_child(owner.get_child_count()-1)
			var list:ItemList=w.find_child("ReactionRows",true,false);list.select(0);list.item_selected.emit(0)
			var fields:= ["ReactionRate","ReactionCondition","ReactionHeat","ReactionEquilibrium","ReactionMode"]
			for i in 5:w.find_child(fields[i],true,false).text=c.texts[i]
			press(w,"ReactionApply");assert(vessel.native_reaction_records[0]==previous)
			press(w,"PropertiesCommit" if confirm else "PropertiesCancel");await process_frame
			if confirm:
				var r:Dictionary=vessel.native_reaction_records[0]
				assert(bits(r.reaction_rate)==c.rate_bits and bits(r.reaction_heat)==c.heat_bits and bits(r.equilibrium_degree_or_constant)==c.equilibrium_bits)
				assert(r.condition==c.condition and r.equilibrium_mode==c.mode)
			else:assert(vessel.native_reaction_records[0]==previous)
			assert(vessel.label==name and str(vessel.native_fields["0x04"])==name)
			tested+=1
	# Label edits fail explicitly until originalGDI metrics are supplied; no name changes.
	var model:=Model.new();model.configure(reagents,reactions);var v:=model.add_apparatus("sb100")
	var dialogs:=Dialogs.new();dialogs.configure(owner,model);dialogs.show_properties(v.id)
	var w:Window=owner.get_child(owner.get_child_count()-1);var before:Dictionary=v.duplicate(true)
	w.find_child("NativeLabelMemo",true,false).text="NaOH溶液\n第二行"
	press(w,"PropertiesCommit");assert(v==before and not w.find_child("NativeLabelFeedback",true,false).text.is_empty())
	press(w,"PropertiesCancel");await process_frame
	print("PASS native five-field reaction UI: ",tested," Modify/Confirm/Cancel transactions; label-metrics guard/name preservation")
	owner.free();quit()
