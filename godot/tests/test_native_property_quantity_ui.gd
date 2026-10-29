extends SceneTree
const Model=preload("res://scripts/lab_model.gd")
const Dialogs=preload("res://scripts/lab_dialogs.gd")
var owner:Control
func number(hex:String)->float:return hex.hex_decode().decode_double(0)
func bits(value:float)->String:return PackedFloat64Array([value]).to_byte_array().hex_encode()
func select_row(window:Window,species:String)->TreeItem:
	var tree:Tree=window.find_child("ChemicalRows",true,false)
	var item:TreeItem=tree.get_root().get_first_child()
	while item!=null:
		if str(item.get_metadata(0))==species:item.select(0);tree.item_selected.emit();return item
		item=item.get_next()
	return null
func press(window:Window,name:String)->void:
	var button:Button=window.find_child(name,true,false);assert(button!=null);button.pressed.emit()
func _initialize()->void:call_deferred("_run")
func _run()->void:
	owner=Control.new();root.add_child(owner)
	var reagents:Array=JSON.parse_string(FileAccess.get_file_as_string("res://data/reagents.json"));var data:Dictionary=JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_property_quantity.json"))
	var tested:=0;var errors:Array=[]
	# UI path edits the existing chemical identity; rename/binding migration is separate.
	for c in data.cases:
		if c.species!="HCl(溶解)":continue
		var model:=Model.new();model.configure(reagents,[])
		var vessel:=model.add_apparatus("sb100")
		assert(model.add_reagent(vessel.id,"H2O(液体)",0.123456789012345));assert(model.add_reagent(vessel.id,"HCl(溶解)",0.02))
		vessel.native_species_mass["H2O(液体)"]=2.224197;vessel.native_species_mass["HCl(溶解)"]=0.7292
		var dialogs:=Dialogs.new();dialogs.configure(owner,model);dialogs.show_properties(vessel.id)
		var window:Window=owner.get_child(owner.get_child_count()-1);var item:=select_row(window,"HCl(溶解)")
		var moles:LineEdit=window.find_child("ChemicalMoles",true,false);var mass:LineEdit=window.find_child("ChemicalMass",true,false)
		assert(item.get_text(2)=="0.7292")
		var radio:CheckBox=window.find_child("ChemicalMassMode" if c.mode=="mass" else "ChemicalMolesMode",true,false);radio.button_pressed=true
		if c.mode=="mass":mass.text=c.text
		else:moles.text=c.text
		assert(vessel.contents["HCl(溶解)"]==0.02)
		press(window,"ChemicalApply");item=select_row(window,"HCl(溶解)")
		if not c.messages.is_empty():
			var feedback:Label=window.find_child("ChemicalFeedback",true,false);assert(not feedback.text.is_empty());assert(item.get_text(1)=="0.02" and item.get_text(2)=="0.7292")
			press(window,"PropertiesCancel")
		else:
			if item.get_text(1)!=c.rows[1][1] or item.get_text(2)!=c.rows[1][2]:errors.append([c.mode,c.text,"native text"])
			assert(vessel.contents["HCl(溶解)"]==0.02)
			press(window,"PropertiesCommit")
			if bits(vessel.contents["HCl(溶解)"])!=c.stored_bits[1].moles:errors.append([c.mode,c.text,"committed amount"])
			#49F0C8 copies grid mass first;417750 aggregates after modal destruction.
			for stored in c.stored_bits:
				if bits(vessel.native_species_mass[stored.species])!=stored.mass:errors.append([c.mode,c.text,"pre-close stored mass",stored.species])
			await process_frame
			for species in c.recalculated_mass_bits:
				if bits(vessel.native_species_mass[species])!=c.recalculated_mass_bits[species]:errors.append([c.mode,c.text,"caller aggregate",species])
		tested+=1;await process_frame
	# NativeFormShow prevents substance/reaction mutation while run global!=0.
	for run_state in [1,2]:
		var paused_model:=Model.new();paused_model.configure(reagents,[]);var v:=paused_model.add_apparatus("sb100");paused_model.running=run_state==1;paused_model.paused=run_state==2
		var dialogs:=Dialogs.new();dialogs.configure(owner,paused_model);dialogs.show_properties(v.id);var window:Window=owner.get_child(owner.get_child_count()-1)
		for name in ["PropertiesCommit","ChemicalDefineVariable","ChemicalAdd","ChemicalApply","ChemicalDelete","ChemicalClear","ReactionSearch","ReactionAdd","ReactionApply","ReactionDelete","ReactionClear"]:assert(window.find_child(name,true,false).disabled)
		press(window,"PropertiesCancel");await process_frame
	print(JSON.stringify({"ui_quantity_cases":tested,"errors":errors,"error_count":errors.size()}))
	if errors.is_empty():print("PASS native property quantity/mass radio/Modify/confirm/cancel/run-lock")
	owner.free();quit(0 if errors.is_empty() else 1)
