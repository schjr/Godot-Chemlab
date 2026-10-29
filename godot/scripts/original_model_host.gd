extends RefCounted
## Godot state host for source-traced native routines. No substitute simulator.
signal changed
signal fidelity_error(message: String)
signal native_property_refresh(apparatus: Array)
const Quantities = preload("res://scripts/original/original_quantities.gd")
const Thermal = preload("res://scripts/original/original_thermal.gd")
const Heat = preload("res://scripts/original/original_heat_geometry.gd")
const Reaction = preload("res://scripts/original/original_reaction.gd")
const Solubility = preload("res://scripts/original/original_solubility.gd")
const Liquid = preload("res://scripts/original/original_liquid.gd")
const Actions = preload("res://scripts/original/original_apparatus_actions.gd")
const Flow = preload("res://scripts/original/original_flow.gd")
const X87 = preload("res://scripts/original/original_x87.gd")
const Factory = preload("res://scripts/original/original_factory.gd")
const Slots = preload("res://scripts/original/original_slots.gd")
const RuntimeAllocation = preload("res://scripts/original/original_runtime_allocation.gd")
const SourceParticles = preload("res://scripts/original/original_particle_frame.gd")
const SourceRuntimeRng = preload("res://scripts/original/original_runtime_rng.gd")
const SourceTrig = preload("res://scripts/original/original_x87_host.gd")
const RuntimeGasFrame = preload("res://scripts/original/original_runtime_gas_frame.gd")
const RuntimeProfile = preload("res://scripts/original/original_runtime_profile.gd")
const TICK_CONSTANT = "3bdf4f8d976e1283f53f"
var reagents: Array = []
var reactions: Array = []
var vessels: Array = []
var connections: Array = []
var native_connectors: Array = []
var running := false
var paused := false
var elapsed := 0.0
var events: Array = []
var native_scale := 1.0
var last_error := ""
var runtime_allocation=RuntimeAllocation.new()
var source_particle_scene:Dictionary={}
var source_particle_rng:Dictionary={}
var source_particle_provenance:Dictionary={}
var _source_particle_tokens:Array=[]
var _source_particle_frame=SourceParticles.new()
var _source_particle_trig=SourceTrig.new()
var source_particle_frames:=0
var source_gas_frame=RuntimeGasFrame.new()
var _species: Dictionary = {}
var _equations: Dictionary = {}
var _native_library: Array = []
var _sprites: Dictionary = {}
var _next_id := 1
var native_label_counter := 0
var _last_tick_ms := 0
var _last_timer_poll_ms := 0
var native_clock:Callable
const UiClock=preload("res://scripts/original/original_ui_clock.gd")

func clock_milliseconds()->int:
	return int(native_clock.call()) if native_clock.is_valid() else Time.get_ticks_msec()
var pointer_held := false
var program_callback: Callable
var native_variable_callback: Callable
var annotations: Array = []
var native_buttons: Array = []
const Chart = preload("res://scripts/original/original_chart.gd")

func begin_pointer() -> void:
	pointer_held = true

func end_pointer() -> void:
	pointer_held = false
	if running:_last_tick_ms = UiClock.signed32(clock_milliseconds()) #42AA18 onlyRun1.

func toggle_pause() -> void:
	if running: running = false; paused = true
	elif paused: _last_tick_ms = UiClock.signed32(clock_milliseconds()); running = true; paused = false

func configure(new_reagents: Array, new_reactions: Array) -> void:
	var startup:=SourceRuntimeRng.start()
	if startup.ok:
		source_particle_rng=startup.state
		source_particle_provenance=startup.provenance
	reagents = new_reagents; reactions = new_reactions
	_species.clear(); _equations.clear(); _native_library.clear()
	for r in reagents: _species[str(r.get("species",r.get("name","")))] = r
	for r in reactions:
		_equations[str(r.get("id",""))] = r
		_native_library.append(Reaction.normalize_record(r,false))
	_sprites = JSON.parse_string(FileAccess.get_file_as_string("res://data/sprites.json"))

func _fail(message: String) -> bool:
	last_error = message; running = false; paused = false; fidelity_error.emit(message)
	return false

func native_apparatus(source = null) -> Array:
	var input: Array = vessels if source == null else source
	return input.filter(func(v): return v.has("native_fields"))

func get_vessel(id: int) -> Dictionary:
	for v in vessels:
		if int(v.id) == id: return v
	return {}

func index_for_id(id: int, source: Array) -> int:
	for i in source.size():
		if int(source[i].id) == id: return i
	return -1

func _bind_native(v: Dictionary) -> bool:
	if not v.get("native_fields",null) is Dictionary: return _fail("此器件缺少原始状态，不能运行。")
	var f: Dictionary = v.native_fields
	for key in ["0x08","0x0c","0x18","0x28","0x38","0x50","0x5c","0x60","0x68","0x6c","0x7c","0x80","0x9c","0xa0","0xa4"]:
		if not f.has(key): return _fail("原始器件状态未完整恢复：" + key)
	var aliases := {"native_type_parameter":"0x0c", "native_cap_flag":"0x38", "native_flame_style":"0x50", "native_flame_width":"0x5c", "native_flame_height":"0x60", "native_platform_mode":"0x6c", "native_platform_offset":"0x7c", "native_ignition":"0x9c", "native_heating":"0xa0"}
	for key in aliases: v[key] = int(f[aliases[key]])
	v.native_attachment = str(f["0x80"]); v.type_id = int(f["0x08"])
	v.volume_ml = float(f["0x28"])
	if not v.has("native_liquid_height"): v.native_liquid_height = float(f["0x30"])
	v.native_rate_slider = int(v.native_simulation_fields[2]) if v.get("native_simulation_fields",[]).size() > 2 else 10
	return _bind_bitmap(v)

func _bind_bitmap(v: Dictionary) -> bool:
	var kind := str(v.kind)
	if v.has("native_texture_kind"): kind = str(v.native_texture_kind)
	if v.has("native_bitmap_plain"): kind = str(v.native_bitmap_plain).get_basename()
	elif int(v.native_fields["0x18"]) == 2:
		var assets := Flow._orientation_assets(int(v.type_id),int(v.native_fields["0x0c"]),2)
		if not assets.is_empty(): kind = str(assets[0]).get_basename()
	elif int(v.type_id) == 107 and int(v.native_fields["0x18"]) == 1: kind = "djqp"
	if not _sprites.has(kind):
		if int(v.type_id) == 316:
			v.native_bitmap_width = int(v.native_fields["0x3c"]); v.native_bitmap_height = int(v.native_fields["0x40"])
			v.native_sprite_width = v.native_bitmap_width; v.native_sprite_height = v.native_bitmap_height
			return true
		if int(v.type_id) > 100 and int(v.type_id) < 300: return _fail("原始器件位图未恢复：" + kind)
		return true
	v.native_bitmap_plain = kind
	v.native_bitmap_width = int(_sprites[kind].size[0]); v.native_bitmap_height = int(_sprites[kind].size[1])
	v.native_sprite_width = v.native_bitmap_width; v.native_sprite_height = v.native_bitmap_height
	return true

func _write_native(v: Dictionary) -> void:
	var f: Dictionary = v.native_fields
	for pair in [["native_heating","0xa0"],["native_ignition","0x9c"],["native_flame_style","0x50"],["native_flame_width","0x5c"],["native_flame_height","0x60"]]:
		if v.has(pair[0]): f[pair[1]] = str(v[pair[0]])
	f["0x88"] = str(v.temperature)
	v.heating = int(v.get("native_heating",0)) == 1
	v.burning = int(v.type_id) == 302 and int(f["0x38"]) != 1
	v.sealed = int(f["0x38"]) == 1; v.smart = int(f["0xa4"]) == 1
	v.consider_ions = int(v.native_simulation_fields[0]) == 1
	v.dissolution = int(v.native_simulation_fields[1]) == 1

func recalc(source = null) -> bool:
	for v in native_apparatus(source):
		if not _sync_slots(v): return false
		if int(v.type_id) > 100 and int(v.type_id) < 300:
			var r := Quantities.recalc(v,_species)
			if not r.ok: return _fail(str(r.error))
			if not _sync_slots(v): return false
	return true

func _sync_slots(v:Dictionary)->bool:
	var allocated:=runtime_allocation.bind(v)
	if not allocated.ok:return _fail(str(allocated.error))
	var result:=Slots.commit(v)
	if not result.ok:return _fail(str(result.error))
	result=Slots.project(v)
	if not result.ok:return _fail(str(result.error))
	result=runtime_allocation.commit(v)
	return true if result.ok else _fail(str(result.error))

func attach_profile(profile:Dictionary,snapshot_index:int=0)->bool:
	# Explicit attachment to this validated document, never a process-wide default.
	var working:=vessels.duplicate(true)
	var apparatus:=native_apparatus(working)
	var decoded:=RuntimeProfile.decode(profile,apparatus,snapshot_index)
	if not decoded.ok:return _fail(str(decoded.error))
	for index in apparatus.size():
		if apparatus[index].has("native_runtime_observation"):return _fail("This allocation already has an attached runtime observation")
		# An explicitly requested validated checkpoint replaces this reconstructed
		# world's projected allocation cells. They are no longer absent values.
		# Direct RuntimeProfile users retain its existing explicit-write semantics.
		if runtime_allocation.owns(apparatus[index]):
			for field in RuntimeProfile.FIELDS.values():apparatus[index].erase(field)
			for offset in RuntimeProfile.SCALAR_FIELDS:
				if decoded.slots[index].native_record.get("scalars",{}).has(offset):apparatus[index].erase(RuntimeProfile.SCALAR_FIELDS[offset])
		var result:=RuntimeProfile.apply_active(apparatus[index],decoded.slots[index])
		if not result.ok:return _fail(str(result.error))
		result=runtime_allocation.commit(apparatus[index])
		if not result.ok:return _fail(str(result.error))
	_commit(working);changed.emit();return true

func refresh_render_state(source = null) -> bool:
	for v in native_apparatus(source):
		if not _bind_bitmap(v): return false
		if int(v.type_id) > 100 and int(v.type_id) < 300:
			# A verified live presentation owns source40A4B8 liquid/particle
			# order. Refreshing every cache here would expose following vessels'
			# new state too early. Explicit working-array import diagnostics keep
			# their existing contract; they are not a configured live paint.
			if source==null and not _presentation_configuration.is_empty():continue
			# 40A4B8's open tilted branch draws its fixed material polygons
			# from +4320/+4338 and skips 471650 entirely. Preserve +30 and
			# the quantity pass's unclipped +4320 instead of applying upright
			# bitmap-height feedback to the newly loaded tilted asset.
			if int(v.native_fields["0x18"])==2 and int(v.native_fields["0x38"])==0:continue
			var r := Liquid.refresh(v,_species)
			if not r.ok: return _fail(str(r.error))
	return true

func _reaction_state(v: Dictionary) -> Dictionary:
	return {"moles":v.contents,"volumes":v.get("native_species_volume",{}),"masses":v.get("native_species_mass",{}),
		"temperature":v.temperature,"heating_flag":v.native_heating,"speed_setting":v.native_rate_slider,
		"liquid_height":v.get("native_liquid_height",0.0),"smart_flag":int(v.native_fields["0xa4"]),
		"ion_flag":int(v.native_simulation_fields[0]),"reactions":v.native_reaction_records,
		"gas_3cc0":v.get("gas_3cc0",0.0),"solid_3cd8":v.get("solid_3cd8",{}),
		"solid_3ff8":v.get("solid_3ff8",{}),"solid_4318":v.get("solid_4318",0.0)}

func _adopt_reactions(v: Dictionary, state: Dictionary) -> void:
	v.contents = state.moles; v.native_species_volume = state.volumes; v.native_species_mass = state.masses
	v.native_reaction_records = state.reactions
	for key in ["gas_3cc0","solid_3cd8","solid_3ff8","solid_4318"]:
		if state.has(key): v[key] = state[key]
	v.reaction_ids = []; v.reaction_overrides = {}; v.rate_overrides = {}
	for record in state.reactions:
		var name := str(record.get("name",record.get("id","")))
		v.reaction_ids.append(name); v.reaction_overrides[name] = record; v.rate_overrides[name] = float(record.reaction_rate)

func start() -> bool:
	last_error = ""
	var working := vessels.duplicate(true)
	for v in native_apparatus(working):
		v.native_particle_3cc8 = 0.0; v.solid_4318 = 0.0
		var cleared:=Slots.clear_run_particles(v)
		if not cleared.ok:return _fail(str(cleared.error))
	for connector in native_connectors:
		connector.native_state_0x70 = 0.0; connector.native_state_0x78 = 0
	# 43DE5C clears Run counters, then calls43F7BC before46C894/48E9B4.
	if not recalc(working): return false
	if not initialize_charts(working): return false
	if not refresh_render_state(working): return false
	for v in native_apparatus(working):
		var state := _reaction_state(v)
		var r := Reaction.prepare_selected_records(state)
		if not r.resolved: return _fail(str(r.error))
		_adopt_reactions(v,state)
	var gas = _gas_module()
	if gas == null: return _fail("原版气体处理尚未完成移植；实验暂不能完整运行。")
	var air: Dictionary = gas.initialize_air(native_apparatus(working),_species)
	if not air.ok: return _fail(str(air.error))
	# Commit only the initializer's explicit slot stores. Native Run does not
	# recalculate the newly filled gas caches; the next accepted idle does.
	for v in native_apparatus(working):
		if not _sync_slots(v):return false
	_commit(working)
	elapsed = 0.0 # Native Run clears 005636CC/005636D0 before accepting ticks.
	running = true; paused = false; _last_tick_ms = UiClock.signed32(clock_milliseconds()); _presentation_configuration.clear(); _presentation_pending.clear()
	#43DE5C clears numeric counters, retaining the particle objects initialized
	# by stopped40A4B8 painting. Document allocation changes rebuild their pools.
	changed.emit()
	return true

func advance_source_particles(index:int,material_words:Array,presentation:Callable,phase:String="all")->Dictionary:
	var profile_started:=Time.get_ticks_usec()
	# This is the original live renderer's numerical stage, not cosmetic dots:
	# it reserves/releases solid amounts used by the next reaction-core call.
	if source_particle_rng.is_empty():return {"ok":false,"error":"Original process startup RNG could not read the host clock"}
	var apparatus:=native_apparatus()
	if index<0 or index>=apparatus.size():return {"ok":false,"error":"Source particle apparatus index is invalid"}
	# Both retained frame blocks guard the particle objects with100<type<200.
	# Bottle/dropper material still uses the normal source drawing recipes.
	if int(apparatus[index].type_id)<=100 or int(apparatus[index].type_id)>=200:return {"ok":true,"words":material_words}
	var tokens:Array=[]
	for v in apparatus:tokens.append(str(v.get(RuntimeAllocation.TOKEN,"")))
	if tokens!=_source_particle_tokens:
		var fresh:=SourceParticles.create_scene(apparatus)
		# Preserve existing objects across a palette insertion/removal. Run creates
		# new particle objects, while pointer movement retains their full records.
		for i in tokens.size():
			var old:=_source_particle_tokens.find(tokens[i])
			if old>=0 and source_particle_scene.get("pools",[]).size()>old:fresh.pools[i]=source_particle_scene.pools[old]
		source_particle_scene=fresh;_source_particle_tokens=tokens
	var working:Array=apparatus.duplicate(true)
	var scene:Dictionary=source_particle_scene.duplicate(true)
	var rng:Dictionary=source_particle_rng.duplicate(true)
	var connectors:Array=native_connectors.duplicate(true)
	var stack:Dictionary=runtime_allocation.heap.read_bytes(0x9000000,0x10000)
	if not stack.ok:return {"ok":false,"error":str(stack.error)}
	var context:Dictionary={"run_flag":1 if running else (2 if paused else 0),"pause_flag":1 if pointer_held else 0,"native_material_words":{index:material_words},"owned_stack_bytes":stack.bytes,"production_pixel_loop":true}
	if phase!="all":context.phases=["frame_"+phase]
	var result:=_source_particle_frame.step_vessel(index,working,_species,connectors,scene,context,rng,Callable(_source_particle_trig,"evaluate"),presentation)
	if _source_particle_frame.vm!=null:_source_particle_frame.vm.helpers.clear()
	if result.has("owned_stack_bytes"):
		var saved_stack:Dictionary=runtime_allocation.heap.write_bytes(0x9000000,result.owned_stack_bytes)
		if not saved_stack.ok:return {"ok":false,"error":str(saved_stack.error)}
	if not result.ok:
		_fail(str(result.error));return result
	for i in apparatus.size():
		var altered:=false
		for field in ["solid_3cd8","solid_3ff8","solid_4318","native_particle_3cc8"]:
			if working[i].has(field) and apparatus[i].get(field)!=working[i][field]:apparatus[i][field]=working[i][field];altered=true
		if altered and not _sync_slots(apparatus[i]):return {"ok":false,"error":last_error}
	for i in native_connectors.size():native_connectors[i].merge(connectors[i],true)
	source_particle_scene=scene;source_particle_rng.merge(rng,true);source_particle_frames+=1
	if "--profile-runtime" in OS.get_cmdline_user_args():print("PROFILE particle ",index," ",phase," ",(Time.get_ticks_usec()-profile_started)/1000.0," ms")
	return {"ok":true,"words":result.material_words.get(index,material_words)}

func _gas_module():
	var path := "res://scripts/original/original_gasflow.gd"
	return load(path) if ResourceLoader.exists(path) else null

func _commit(working: Array) -> void:
	# Native vessel addresses stay stable while a property window is open.
	for i in working.size(): vessels[i].merge(working[i],true)

func tick(milliseconds: int) -> void:
	# Native40A4B8 completes on the single UI thread before the next timer.
	# Keep the previous timestamp: rendering duration belongs to the next dt.
	if native_presentation_is_pending():return
	var clocks:Dictionary={"poll_ms":_last_timer_poll_ms,"physics_ms":_last_tick_ms}
	var poll:=UiClock.poll(clocks,milliseconds,1 if running else (2 if paused else 0),pointer_held)
	_last_timer_poll_ms=int(clocks.poll_ms);_last_tick_ms=int(clocks.physics_ms)
	if poll.accepted:step(float(poll.delta))

func step(dt: float, native_context: Dictionary = {}) -> void:
	if native_presentation_is_pending():return
	if not running or not is_finite(dt): return
	# Atomic host tick: an unresolved native branch never falls back to a prototype.
	var working := vessels.duplicate(true)
	var apparatus := native_apparatus(working)
	var heat := Heat.derive(apparatus,native_scale)
	if not heat.ok: _fail(str(heat.error)); return
	for v in apparatus:
		var r := Thermal.advance(v,dt,Thermal.slider_multiplier(int(v.native_rate_slider)))
		if not r.ok: _fail(str(r.error)); return
	var flow := Flow.advance(apparatus,dt,native_scale,_species)
	if not flow.ok: _fail(str(flow.error)); return
	for v in apparatus:
		if not _sync_slots(v):return
		if int(v.native_fields["0x18"]) != 0: continue
		if int(v.native_simulation_fields[1]) == 1:
			var r := Solubility.advance(v,_species,dt)
			if not r.ok: _fail(str(r.error)); return
			if not _sync_slots(v):return
		var state := _reaction_state(v)
		var core := Reaction.step_core(state,_native_library,dt)
		if not core.resolved: _fail(str(core.error)); return
		_adopt_reactions(v,state)
		if int(v.native_simulation_fields[1]) == 1:
			var r := Solubility.advance(v,_species,dt)
			if not r.ok: _fail(str(r.error)); return
	if not recalc(working): return
	var gas = _gas_module()
	if gas == null: _fail("原版气体处理尚未完成移植；已保留实验状态。"); return
	var open_result: Dictionary = gas.advance_open(apparatus,_species)
	if not open_result.ok: _fail(str(open_result.error)); return
	var conduit_result: Dictionary = gas.advance_conduits(apparatus,native_connectors,_species,dt,native_scale)
	if not conduit_result.ok: _fail(str(conduit_result.error)); return
	var gas_context:Dictionary=native_context.duplicate()
	if not gas_context.has("observed_stack_excess") and not gas_context.has("source_stack_read_excess"):
		if source_gas_frame.heap==null:
			# Source ABI4018B0→46F704, in this runtime's owned UI-thread stack.
			# Renderer writes in the same physical region persist between messages.
			var bound:Dictionary=source_gas_frame.bind(runtime_allocation.heap,0x900f000)
			if not bound.ok:_fail(str(bound.error));return
		gas_context.merge(source_gas_frame.context())
	var remainder: Dictionary = gas.advance_remaining(apparatus,native_connectors,_species,dt,native_scale,gas_context)
	if not remainder.ok: _fail(str(remainder.error)); return
	if not recalc(working): return
	var next_elapsed := X87.stored_double(X87.add([dt,0.0],elapsed))
	if program_callback.is_valid():
		var program_result: Dictionary = program_callback.call(apparatus,next_elapsed)
		if not program_result.ok: _fail(str(program_result.error)); return
		if not recalc(working): return
	# Original 4018B0 refreshes the open Form4 grid after the program's
	# quantity writes and before chart sampling, using this accepted state.
	native_property_refresh.emit(apparatus)
	if not sample_charts(working): return
	for v in apparatus: _write_native(v)
	_commit(working); elapsed = next_elapsed
	if not refresh_render_state(): return
	changed.emit()

func initialize_charts(source = null, native_texts = null) -> bool:
	var input: Array = vessels if source == null else source
	var texts:Dictionary=native_texts if native_texts is Dictionary else (native_variable_callback.call(native_apparatus(input)) if native_variable_callback.is_valid() else {})
	var chart_index := 0
	for v in input:
		if str(v.get("kind","")) != "chart": continue
		if not v.has("native_chart_record"): return _fail("曲线缺少原始55字段记录。")
		if chart_index >= 8 or int(v.native_chart_record[0]) == 0: break
		chart_index += 1
		var state := Chart.state_from_record(v.native_chart_record)
		if not state.ok: return _fail(str(state.error))
		var result := Chart.initialize(state,texts)
		if not result.ok: return _fail(str(result.error))
		v.native_chart_state = state; v.native_chart_grid = result.grid; v.native_chart_segments = []
	return true

func sample_charts(source: Array) -> bool:
	var texts: Dictionary = native_variable_callback.call(native_apparatus(source)) if native_variable_callback.is_valid() else {}
	var chart_index := 0
	for v in source:
		if str(v.get("kind","")) != "chart": continue
		if not v.has("native_chart_record"): return _fail("曲线缺少原始55字段记录。")
		if chart_index >= 8 or int(v.native_chart_record[0]) == 0: break
		chart_index += 1
		if not v.has("native_chart_state"): return _fail("曲线尚未完成原始初始化。")
		var result := Chart.sample(v.native_chart_state,texts)
		if not result.ok: return _fail(str(result.error))
		v.native_chart_segments.append_array(result.segments)
	return true

func manual_action(id: int, command: int) -> Dictionary:
	var apparatus := native_apparatus()
	for v in apparatus:
		if not _sync_slots(v):return {"ok":false,"error":last_error}
	var r := Actions.execute_manual_action(apparatus,index_for_id(id,apparatus),command,native_scale,_species)
	if not r.ok: _fail(str(r.error)); return r
	for v in apparatus:
		if not _sync_slots(v):return {"ok":false,"error":last_error}
	if r.get("transfer_result",{}).get("stop_requested",false): running = false
	refresh_render_state(); changed.emit(); return r

func toggle_pour(id: int) -> bool:
	var v := get_vessel(id)
	if v.is_empty(): return false
	var result := Flow.toggle_pour(v)
	if not result.ok: return _fail(str(result.error))
	if result.has("bitmap_plain"): v.native_bitmap_plain = str(result.bitmap_plain).get_basename()
	if result.has("bitmap_fill"): v.native_bitmap_fill = str(result.bitmap_fill).get_basename()
	refresh_render_state(); changed.emit(); return true

func add_apparatus(kind: String, position: Vector2 = Vector2.ZERO) -> Dictionary:
	var result := Factory.create(kind,position,_next_id,native_label_counter)
	if not result.ok: _fail(str(result.error)); return {}
	var v: Dictionary = result.vessel
	v.reaction_ids = []; v.rate_overrides = {}; v.reaction_overrides = {}; v.reaction_extents = {}
	if not _bind_native(v): return {}
	v.native_species_mass = {}; v.native_species_volume = {}
	var allocated:=runtime_allocation.bind(v)
	if not allocated.ok:_fail(str(allocated.error));return {}
	_write_native(v)
	vessels.append(v); _next_id += 1; native_label_counter = int(result.next_native_label_counter)
	recalc(); refresh_render_state(); changed.emit(); return v

func add_reagent(id: int, species, moles: float) -> bool:
	var v := get_vessel(id)
	var name := str(species)
	if species is int:
		for r in reagents:
			if int(r.id) == species: name = str(r.species); break
	if v.is_empty() or not _species.has(name) or not is_finite(moles): return false
	if not v.contents.has(name) and v.contents.size() >= 100: return _fail("容器中的药品已有100钟！")
	v.contents[name] = X87.stored_double(X87.add([float(v.contents.get(name,0.0)),0.0],moles))
	if not recalc() or not refresh_render_state(): return false
	changed.emit(); return true

func commit_property_slots(original:Dictionary,draft:Dictionary)->bool:
	var rows:Array=[]
	for species in draft.contents:
		var amount:float=float(draft.contents[species])
		if not _species.has(species):return _fail("Original edited species is not in the catalog")
		var mass:float=X87.stored_double(X87.multiply([amount,0.0],float(_species[species].molar_mass)))
		if draft.get("native_editor_mass_rows",{}).has(species):mass=float(draft.native_editor_mass_rows[species])
		rows.append({"species":species,"moles":amount,"mass":mass})
	var result:=Slots.commit_editor_rows(original,draft,rows)
	if result.ok:draft.erase("native_editor_mass_rows")
	return true if result.ok else _fail(str(result.error))

func remove_apparatus(id: int) -> void:
	for i in range(vessels.size()-1,-1,-1):
		if int(vessels[i].id) == id:
			var released:Dictionary=runtime_allocation.release(vessels[i])
			if not released.ok:_fail(str(released.error));return
			vessels.remove_at(i)
	connections = connections.filter(func(c): return int(c.source) != id and int(c.target) != id)
	changed.emit()

func total_moles(v: Dictionary) -> float:
	var total := 0.0
	for n in v.contents.values(): total += float(n)
	return total

func ph(v: Dictionary) -> float:
	return float(v.get("native_ph",7.0))

func chemistry_summary(id: int) -> Dictionary:
	var v := get_vessel(id)
	if v.is_empty(): return {}
	var color := int(v.get("native_liquid_color",0))
	return {"pH":ph(v),"color":Color(float(color&255)/255.0,float((color>>8)&255)/255.0,float((color>>16)&255)/255.0),
		"gas_moles":v.get("native_gas_moles",0.0),"liquid_ml":v.get("native_liquid_volume",0.0),"total_moles":total_moles(v),"solid_moles":0.0}

func to_state() -> Dictionary:
	var saved_vessels:=vessels.duplicate(true)
	for v in saved_vessels:v.erase(RuntimeAllocation.TOKEN)
	return {"format":"ChemLab-Godot","version":2,"vessels":saved_vessels,"connections":connections.duplicate(true),
		"native_connectors":native_connectors.duplicate(true),"annotations":annotations.duplicate(true),"native_buttons":native_buttons.duplicate(true),"native_canvas_scale":native_scale,"elapsed":elapsed,"events":events.duplicate(),"next_id":_next_id,"native_label_counter":native_label_counter}

func from_state(state: Dictionary) -> bool:
	if _species.is_empty(): configure(JSON.parse_string(FileAccess.get_file_as_string("res://data/reagents.json")),JSON.parse_string(FileAccess.get_file_as_string("res://data/reactions.json")))
	if not state.get("vessels",null) is Array: return false
	var working: Array = state.vessels.duplicate(true)
	for v in working:
		if not v is Dictionary or not v.get("contents",null) is Dictionary:return false
	for v in native_apparatus():
		var released:Dictionary=runtime_allocation.release(v)
		if not released.ok:return _fail(str(released.error))
	for v in working:
		if not v is Dictionary or not v.get("contents",null) is Dictionary: return false
		v.erase(RuntimeAllocation.TOKEN) # Saved/foreign address identities are never trusted.
		if v.has("native_fields"):
			if not _bind_native(v): return false
			if not v.has("native_reaction_records"): return _fail("文件缺少原始反应记录，不能恢复旧版近似模拟。")
			if not v.has("native_species_mass"): v.native_species_mass = v.get("native_masses",{}).duplicate()
			if not v.has("native_species_volume"): v.native_species_volume = {}
			for key in ["native_liquid_volume","native_gas_volume","native_gas_moles"]:
				if not v.has(key): v[key] = 0.0 # Explicit FUN_00453A28 writes.
			var slots:=runtime_allocation.bind(v)
			if not slots.ok:return _fail(str(slots.error))
			_write_native(v)
		_next_id = maxi(_next_id,int(v.id)+1)
	if not recalc(working) or not refresh_render_state(working): return false
	native_label_counter = int(state.get("native_label_counter",0))
	vessels = working; connections = state.get("connections",[]).duplicate(true)
	native_connectors = state.get("native_connectors",[]).duplicate(true)
	annotations = state.get("annotations",[]).duplicate(true); native_buttons = state.get("native_buttons",[]).duplicate(true); native_scale = float(state.get("native_canvas_scale",1.0))
	elapsed = float(state.get("elapsed",0.0)); events = state.get("events",[]).duplicate(); running = false; paused = false
	last_error = ""; _presentation_configuration.clear(); _presentation_pending.clear(); changed.emit(); return true

func save_experiment(path: String = "user://experiment.chemlab.json") -> Error:
	var file := FileAccess.open(path,FileAccess.WRITE)
	if file == null: return FileAccess.get_open_error()
	file.store_string(JSON.stringify(to_state(),"\t")); return OK

func load_experiment(path: String = "user://experiment.chemlab.json") -> Error:
	var file := FileAccess.open(path,FileAccess.READ)
	if file == null: return FileAccess.get_open_error()
	var parser := JSON.new()
	if parser.parse(file.get_as_text()) != OK or not parser.data is Dictionary: return ERR_PARSE_ERROR
	return OK if from_state(parser.data) else ERR_INVALID_DATA

func reset() -> void:
	for v in native_apparatus():
		var released:Dictionary=runtime_allocation.release(v)
		if not released.ok:_fail(str(released.error));return
	vessels.clear(); connections.clear(); native_connectors.clear(); annotations.clear(); native_buttons.clear(); events.clear()
	elapsed = 0.0; _next_id = 1; native_label_counter = 0; running = false; paused = false; last_error = ""; _presentation_configuration.clear(); _presentation_pending.clear(); changed.emit()

# Native presentation is a separately verified, persistent runtime boundary.
# No pool/RNG/bitmap startup state is synthesized by this host.
var presentation_revision:=0
var native_presentation_frames:Array=[]
var _presentation_configuration:Dictionary={}
var _presentation_token:=0
var _presentation_pending:Dictionary={}
var _presentation_display_pending:Dictionary={}
signal native_presentation_committed(result:Dictionary,revision:int)

func _init()->void:
	changed.connect(_native_presentation_model_changed)

func _notification(what:int)->void:
	if what==NOTIFICATION_PREDELETE:
		runtime_allocation.close();_source_particle_trig.stop()
		if _source_particle_frame.vm!=null:_source_particle_frame.vm.helpers.clear()

func _native_presentation_model_changed()->void:
	_presentation_display_pending.clear()
	presentation_revision+=1
	native_presentation_frames.clear()

func _presentation_error(message:String)->Dictionary:
	return {"ok":false,"error":message}

func _presentation_hash(value:Variant)->String:
	var hash:=HashingContext.new();hash.start(HashingContext.HASH_SHA256)
	hash.update(var_to_bytes(value));return hash.finish().hex_encode()

func _presentation_identity()->Array:
	var identity:Array=[]
	for vessel in native_apparatus():
		identity.append([vessel.get("id"),vessel.get("type_id"),vessel.get("native_type_parameter"),vessel.get("label"),vessel.get("native_bitmap_width"),vessel.get("native_bitmap_height")])
	return identity

func native_presentation_stamp()->Dictionary:
	return {"revision":presentation_revision,"fingerprint":_presentation_fingerprint(),"identity":_presentation_identity()}

func _presentation_fingerprint()->String:
	return _presentation_hash({"model":to_state(),"running":running,"paused":paused,"pointer_held":pointer_held,"catalog":_species,
		"scene":_presentation_configuration.get("scene"),"rng":_presentation_configuration.get("rng"),"context":_presentation_configuration.get("context"),"bitmaps":_presentation_configuration.get("bitmaps")})

func _validate_presentation_runtime(scene:Dictionary,rng:Dictionary,count:int)->Dictionary:
	for key in ["low","high"]:
		if not rng.get(key,null) is int or int(rng[key])<0 or int(rng[key])>0xffffffff:return _presentation_error("Observed native TLS RNG DWORDs are required")
	if not scene.get("pools",null) is Array or scene.pools.size()!=count:return _presentation_error("Observed particle pools must retain full native apparatus order")
	for index in count:
		var pool=scene.pools[index]
		if not pool is Dictionary:return _presentation_error("Invalid observed particle pool")
		if pool.is_empty():continue # Nonparticle apparatus have no particle objects.
		for name in ["solid","bubbles"]:
			if not pool.get(name,null) is Dictionary:return _presentation_error("Observed solid/bubble object state is incomplete")
			var object:Dictionary=pool[name]
			var required:Array=["count","slots","rect","width","height"]
			required.append_array(["frozen","already_drawn","background","previous_background","palette","primary_words","retained_words"] if name=="solid" else ["call_count","enabled","surface","color","background","center_x","center_y","region"])
			for field in required:
				if not object.has(field):return _presentation_error("Observed persistent particle object field is missing: "+field)
			if name=="solid":
				for field in ["primary_words","retained_words"]:
					if not object[field] is Array or object[field].size()!=int(object.width)*int(object.height):return _presentation_error("Observed persistent particle bitmap pixels are incomplete")
			if not object.get("count",null) is int or not object.get("slots",null) is Array:return _presentation_error("Observed native particle records are incomplete")
			if int(object.count)<0 or int(object.count)>(4000 if name=="solid" else 400) or object.slots.size()<int(object.count):return _presentation_error("Observed native particle count exceeds its record storage")
			for record in object.slots:
				if not record is Array or record.size()!=13:return _presentation_error("Original particle records require all13 DWORDs")
				for word in record:
					if not word is int or word<0 or word>0xffffffff:return _presentation_error("Invalid original particle DWORD")
	return {"ok":true}

func configure_native_presentation(configuration:Dictionary)->Dictionary:
	var profile=configuration.get("profile",null)
	if not profile is Dictionary or profile.get("source_sha256","")!=Factory.EXPECTED_SHA or not profile.get("native_vcl_verified",false) or not profile.get("runtime_state_verified",false) or str(profile.get("scope","")).is_empty() or str(profile.get("evidence_sha256","")).length()!=64:
		return _presentation_error("Verified original VCL and scoped runtime-state provenance are required; probes cannot configure production")
	for field in ["scene","rng","context","providers"]:
		if not configuration.get(field,null) is Dictionary:return _presentation_error("Explicit native presentation input required: "+field)
	var apparatus:=native_apparatus()
	if not configuration.get("bitmaps",null) is Array or configuration.bitmaps.size()!=apparatus.size():return _presentation_error("Observed bitmaps must retain full native apparatus order")
	if configuration.get("apparatus_identity",null)!=_presentation_identity():return _presentation_error("Presentation profile belongs to a different apparatus allocation/order")
	var validation:=_validate_presentation_runtime(configuration.scene,configuration.rng,apparatus.size())
	if not validation.ok:return validation
	for key in ["run_flag","pause_flag"]:
		if not configuration.context.get(key,null) is int:return _presentation_error("Observed native run/pause globals are required")
	for bitmap in configuration.bitmaps:
		if not bitmap is Dictionary or not bitmap.get("original_bitmap_profile_verified",false):return _presentation_error("Original source bitmap profile is unverified")
		for name in ["plain","fill","material"]:
			if not bitmap.get(name,null) is Dictionary:return _presentation_error("Original bitmap state is incomplete: "+name)
		for name in ["plain","fill"]:
			var original:Dictionary=bitmap[name]
			if not original.get("words",null) is Array or int(original.get("width",0))<=0 or int(original.get("height",0))<=0 or original.words.size()!=int(original.width)*int(original.height):return _presentation_error("Observed original bitmap pixels are incomplete")
			for word in original.words:
				if not word is int or word<0 or word>0xffffffff:return _presentation_error("Invalid original bitmap DWORD")
		var material:Dictionary=bitmap.material
		if int(material.get("bitmap_format",0))!=32 or int(material.get("width",0))<=0 or int(material.get("height",0))<=0 or int(material.get("initial_stretch_mode",0)) not in [1,2,3,4]:return _presentation_error("Observed material bitmap format/DC state is unresolved")
		if not bitmap.get("copy_rect",null) is Dictionary or not bitmap.copy_rect.get("destination_rect",null) is Array or not bitmap.copy_rect.get("source_rect",null) is Array or bitmap.copy_rect.destination_rect.size()!=4 or bitmap.copy_rect.source_rect.size()!=4:return _presentation_error("Observed CopyRect state is required")
	var providers:Dictionary=configuration.providers
	if not providers.get("gdi",null) is Object:return _presentation_error("Exact native GDI provider is required")
	for method in ["render_ops","render_solid","copy_rect"]:
		if not providers.gdi.has_method(method):return _presentation_error("Exact native GDI method is missing: "+method)
	for name in ["particles","overlays","canvas_composite"]:
		var provider=providers.get(name,Callable())
		if not provider is Callable or not provider.is_valid():return _presentation_error("Exact native presentation provider is missing: "+name)
	for bitmap in configuration.bitmaps:
		if int(bitmap.plain.get("bitmap_format",0))!=32 and (not providers.get("plain_copy",Callable()) is Callable or not providers.get("plain_copy",Callable()).is_valid()):return _presentation_error("Observed source bitmap format requires an exact CopyRect boundary")
	_presentation_configuration=configuration.duplicate(true)
	_presentation_configuration.host_control_identity=[running,paused]
	_presentation_pending.clear();_native_presentation_model_changed()
	return {"ok":true,"revision":presentation_revision}

func native_presentation_is_configured()->bool:
	return not _presentation_configuration.is_empty() and _presentation_configuration.host_control_identity==[running,paused] and _presentation_configuration.apparatus_identity==_presentation_identity()

func native_presentation_is_pending()->bool:
	# Direct mutable-dictionary changes may emit no changed signal. Such a
	# frame cannot be drawn/acknowledged as current and must not deadlock dt.
	if not _presentation_display_pending.is_empty() and _presentation_display_pending.stamp!=native_presentation_stamp():
		_native_presentation_model_changed()
	return not _presentation_configuration.is_empty() and (not _presentation_pending.is_empty() or not _presentation_display_pending.is_empty())

func acknowledge_native_presentation_display(stamp:Dictionary)->Dictionary:
	if _presentation_display_pending.is_empty():return {"ok":true,"acknowledged":false}
	if stamp!=_presentation_display_pending.stamp or stamp!=native_presentation_stamp():return _presentation_error("Stale display acknowledgement cannot release another native frame")
	_presentation_display_pending.clear()
	return {"ok":true,"acknowledged":true}

func release_native_presentation(snapshot:Dictionary,reason:String="")->Dictionary:
	if _presentation_pending.is_empty():
		if _presentation_display_pending.is_empty():return {"ok":true,"released":false}
		if snapshot.get("token",-1)!=_presentation_display_pending.token:return _presentation_error("A stale request cannot release a newer native display")
		_native_presentation_model_changed()
		return {"ok":true,"released":true,"reason":reason,"display_canceled":true}
	if snapshot.get("token",-1)!=_presentation_pending.token:return _presentation_error("A stale request cannot release a newer native presentation")
	_presentation_pending.clear()
	return {"ok":true,"released":true,"reason":reason}

func capture_native_presentation()->Dictionary:
	if native_presentation_is_pending():return _presentation_error("Complete or explicitly release the outstanding native presentation before capturing another")
	if _presentation_configuration.is_empty():return _presentation_error("Native presentation has no verified startup/runtime configuration")
	if _presentation_configuration.host_control_identity!=[running,paused]:return _presentation_error("Reattach observed native control globals after Run/pause changes")
	if _presentation_configuration.apparatus_identity!=_presentation_identity():return _presentation_error("Reattach a verified presentation profile after apparatus allocation/order changes")
	var snapshot:Dictionary={"vessels":native_apparatus().duplicate(true),"connectors":native_connectors.duplicate(true),"catalog":_species.duplicate(true)}
	for key in ["scene","rng","context","bitmaps"]:snapshot[key]=_presentation_configuration[key].duplicate(true)
	_presentation_token+=1
	snapshot.revision=presentation_revision;snapshot.token=_presentation_token;snapshot.identity=_presentation_identity();snapshot.fingerprint=_presentation_fingerprint()
	# Keep an internal immutable comparison copy: caller-modified tokens/input
	# cannot authorize feedback from an unrelated presentation.
	_presentation_pending={"token":snapshot.token,"revision":snapshot.revision,"identity":snapshot.identity.duplicate(true),"fingerprint":snapshot.fingerprint,"input_hash":_presentation_hash(snapshot),"references":native_apparatus().duplicate()}
	return {"ok":true,"snapshot":snapshot,"providers":_presentation_configuration.providers,"profile":_presentation_configuration.profile.duplicate(true)}

func adopt_native_presentation(snapshot:Dictionary,result:Dictionary)->Dictionary:
	if _presentation_pending.is_empty() or snapshot.get("token",-1)!=_presentation_pending.token:return _presentation_error("Native presentation request is absent, superseded or already adopted")
	if presentation_revision!=_presentation_pending.revision or _presentation_fingerprint()!=_presentation_pending.fingerprint or _presentation_identity()!=_presentation_pending.identity:return _presentation_error("Model changed while native presentation was pending")
	var current_references:=native_apparatus()
	for index in current_references.size():
		if not is_same(current_references[index],_presentation_pending.references[index]):return _presentation_error("Original live vessel reference changed while presentation was pending")
	if _presentation_hash(snapshot)!=_presentation_pending.input_hash:return _presentation_error("Native presentation input changed after capture")
	if not result.get("ok",false) or result.get("probe_only",true) or not result.get("native_vcl_verified",false):return _presentation_error("Unverified/probe native presentation cannot be adopted")
	var state=result.get("state",null)
	if not state is Dictionary:return _presentation_error("Native presentation feedback is incomplete")
	for field in ["vessels","connectors"]:
		if not state.get(field,null) is Array or state[field].size()!=snapshot[field].size():return _presentation_error("Native feedback changed source array order/count")
	for field in ["scene","rng","context"]:
		if not state.get(field,null) is Dictionary:return _presentation_error("Native feedback state is incomplete: "+field)
	var validation:=_validate_presentation_runtime(state.scene,state.rng,snapshot.vessels.size())
	if not validation.ok:return validation
	if state.context!=snapshot.context:return _presentation_error("Presentation cannot change observed control globals")
	var allowed:={"solid_3cd8":true,"solid_3ff8":true,"native_particle_3cc8":true,"native_liquid_height_fresh":true,"native_liquid_color":true,"native_ph":true,"native_liquid_pen_color":true,"native_liquid_height":true,"native_liquid_volume":true,"native_liquid_rectangle":true}
	var working:=vessels.duplicate(true);var apparatus:=native_apparatus(working)
	for index in apparatus.size():
		var returned=state.vessels[index]
		if not returned is Dictionary:return _presentation_error("Native apparatus feedback is invalid")
		var before:Dictionary=snapshot.vessels[index]
		for key in returned:
			if not allowed.has(key) and (not before.has(key) or _presentation_hash(returned[key])!=_presentation_hash(before[key])):return _presentation_error("Presentation altered a nonpresentation apparatus field: "+str(key))
		for key in before:
			if not returned.has(key):return _presentation_error("Presentation removed an apparatus field")
		for key in allowed:
			if returned.has(key):apparatus[index][key]=returned[key].duplicate(true) if returned[key] is Dictionary or returned[key] is Array else returned[key]
		var committed:=Slots.commit(apparatus[index])
		if not committed.ok:return committed
	for index in state.connectors.size():
		if not state.connectors[index] is Dictionary:return _presentation_error("Native connector feedback is invalid")
		for key in snapshot.connectors[index]:
			if not state.connectors[index].has(key):return _presentation_error("Presentation removed an observed connector field")
			if key not in ["native_state_0x70","native_state_0x78"] and state.connectors[index].get(key)!=snapshot.connectors[index][key]:return _presentation_error("Presentation changed connector identity/geometry")
		for key in state.connectors[index]:
			if not snapshot.connectors[index].has(key):return _presentation_error("Presentation added an unobserved connector field")
	if not result.get("frames",null) is Array or result.frames.size()!=apparatus.size():return _presentation_error("Native presentation frames are incomplete")
	for index in result.frames.size():
		var frame=result.frames[index]
		if not frame is Dictionary or int(frame.get("native_index",-1))!=index or frame.get("probe_only",true) or not frame.get("native_vcl_verified",false):return _presentation_error("Native frame identity/provenance is invalid")
		if frame.get("presentation_stage","")!="background_composited_srccopy" or frame.get("display_mode","")!="opaque" or not frame.get("canvas_background_verified",false) or int(frame.get("source_compositor",0))!=0x492560 or frame.get("source_weight_bits","")!="000000000000e03f":return _presentation_error("Native frame omits verified final background composition/SRCCOPY")
		var width:int=int(apparatus[index].get("native_bitmap_width",0));var height:int=int(apparatus[index].get("native_bitmap_height",0))
		var position:Array=apparatus[index].position
		var expected_top_left:=[int(position[0])-int(width/2),int(position[1])-int(height/2)]
		if frame.get("display_top_left",null)!=expected_top_left:return _presentation_error("Native frame destination differs from original centered integer coordinates")
		if int(frame.get("width",0))!=width or int(frame.get("height",0))!=height or not frame.get("words",null) is Array or frame.words.size()!=width*height:return _presentation_error("Native frame pixels/dimensions are incomplete")
		for word in frame.words:
			if not word is int or word<0 or word>0xffffffff:return _presentation_error("Native frame contains an invalid DWORD")
	# All checks completed before mutating stable live vessel dictionaries.
	_commit(working)
	for index in native_connectors.size():native_connectors[index].merge(state.connectors[index],true)
	_presentation_configuration.scene=state.scene.duplicate(true);_presentation_configuration.rng=state.rng.duplicate(true)
	_presentation_pending.clear();changed.emit()
	native_presentation_frames=result.frames.duplicate(true)
	_presentation_display_pending={"token":snapshot.token,"stamp":native_presentation_stamp()}
	native_presentation_committed.emit(result,presentation_revision)
	return {"ok":true,"revision":presentation_revision}
