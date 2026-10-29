class_name LabCanvas
extends Control
const Interaction = preload("res://scripts/original/original_interaction.gd")
const NativeFrames = preload("res://scripts/original/original_canvas_frames.gd")
const NativeController = preload("res://scripts/original/original_presentation_controller.gd")
const SourceRenderer = preload("res://scripts/original/original_source_renderer.gd")
## Canvas coordinates preserve the original .cem apparatus centers.
signal apparatus_selected(id: int)
signal properties_requested(id: int)
signal context_requested(id: int, location: Vector2)
signal apparatus_created(kind: String, location: Vector2)
signal decoration_requested(kind: String, location: Vector2)
signal button_activated(id: int)
signal status(text: String)
## CPU draw submission does not attest GPU visibility.
signal native_frame_draw_submitted(revision: int)

var ui_dispatch:Callable
var model: LabModel
var program
var selected_id: int = -1
var active_tool: String = "select"
var zoom: float = 1.5
var pan: Vector2 = Vector2.ZERO
var background: Color = Color.WHITE
var annotations: Array = []
var legacy_connectors: Array = []
var graph_history: Dictionary = {} # Compatibility only; native graphs store drawn segments.
var _chart_views: Dictionary = {}
var _textures: Dictionary = {}
var _fonts: Dictionary = {}
var _drag_id: int = -1
var _drag_offset: Vector2 = Vector2.ZERO
var _panning: bool = false
var _pour_source: int = -1
var _animation_time: float = 0.0
var _selection: Dictionary = {}
var _dragging_native := false
const Selection = preload("res://scripts/original/original_selection.gd")
const Controls = preload("res://scripts/original/original_controls.gd")
var _control_down := 0
var _controls_running := false
var _native_frames: Dictionary = {}
var _native_owned_ids: Dictionary = {}
var _native_stamp: Dictionary = {}
var _native_revision := -1
var _native_controller: Node = null
var native_presentation_mode := true
var native_presentation_status := "原始绘图资料未齐备"
var _native_render_pending := false
var _native_failed_stamp: Dictionary = {}
var _native_configuration_ready := false
var _native_draw_submitted: Dictionary = {}
var _native_acknowledged_stamp: Dictionary = {}
var _source_renderer=SourceRenderer.new()
var _source_frames:Array=[]
var _source_textures:Dictionary={}
var source_render_errors:Dictionary={}

func _ready() -> void:
	mouse_filter = Control.MOUSE_FILTER_STOP
	focus_mode = Control.FOCUS_ALL
	texture_filter = CanvasItem.TEXTURE_FILTER_LINEAR
	set_process(true)

func configure(lab: LabModel, evaluator = null) -> void:
	if model!=null:
		if model.changed.is_connected(_on_model_changed):model.changed.disconnect(_on_model_changed)
		if model.has_signal("native_presentation_committed") and model.is_connected("native_presentation_committed",_on_native_presentation_committed):model.disconnect("native_presentation_committed",_on_native_presentation_committed)
	model = lab
	program = evaluator
	_native_frames.clear();_native_owned_ids.clear();_native_stamp.clear();_native_revision=-1
	_source_renderer=SourceRenderer.new();_source_frames.clear();_source_textures.clear();source_render_errors.clear()
	native_presentation_mode=true;native_presentation_status="原始绘图资料未齐备";_native_failed_stamp.clear();_native_configuration_ready=false
	model.changed.connect(_on_model_changed)
	if model.has_signal("native_presentation_committed"):model.connect("native_presentation_committed",_on_native_presentation_committed)
	if _native_controller!=null:_native_controller.queue_free()
	_native_controller=NativeController.new();add_child(_native_controller)
	_native_controller.attach(model,self)
	queue_redraw()

func configure_native_presentation(configuration: Dictionary)->Dictionary:
	# Missing original runtime/profile inputs never select a substitute renderer.
	native_presentation_mode=true
	invalidate_native_frames();_native_failed_stamp.clear()
	if model==null:return NativeFrames.error("Native host is missing")
	var result: Dictionary=model.configure_native_presentation(configuration)
	_native_configuration_ready=bool(result.ok)
	if not result.ok:
		native_presentation_status="原始绘图资料未齐备"
		status.emit(str(result.error))
	else:
		native_presentation_status="原始绘图等待生成"
		call_deferred("_render_native_if_needed")
	queue_redraw()
	return result

func _render_native_if_needed()->void:
	if not native_presentation_mode or not _native_configuration_ready or _native_render_pending or model==null or _native_stamp_current():return
	if model.has_method("native_presentation_is_configured") and not model.native_presentation_is_configured():return
	var stamp: Dictionary=model.native_presentation_stamp()
	if stamp==_native_failed_stamp:return
	_native_render_pending=true
	var result: Dictionary=await render_native_presentation()
	_native_render_pending=false
	if not result.ok:_native_failed_stamp=stamp

func _on_model_changed()->void:
	invalidate_native_frames()
	queue_redraw()

func invalidate_native_frames()->void:
	_native_frames.clear();_native_stamp.clear();_native_revision=-1;_native_acknowledged_stamp.clear()
	if native_presentation_mode:native_presentation_status="原始绘图等待重新生成" if _native_configuration_ready else "原始绘图资料未齐备"
	# Already source-managed vessels never fall back to guessed tinted material.
	queue_redraw()

func _native_stamp_current()->bool:
	if _native_frames.is_empty():return false
	if model==null or not model.has_method("native_presentation_stamp") or model.native_presentation_stamp()!=_native_stamp:
		invalidate_native_frames();return false
	return true

func native_frame_revision()->int:
	return _native_revision if _native_stamp_current() else -1

func _on_native_presentation_committed(result: Dictionary, revision: int)->void:
	var accepted:=commit_native_frames(result,revision)
	if not accepted.ok:status.emit(str(accepted.error))

func commit_native_frames(result: Dictionary, revision: int)->Dictionary:
	if model==null or not model.has_method("native_presentation_stamp"):return NativeFrames.error("Native host revision/identity boundary is missing")
	var stamp: Dictionary=model.native_presentation_stamp()
	if int(stamp.get("revision",-1))!=revision:return NativeFrames.error("Native display result is stale")
	if model.get("native_presentation_frames")!=result.get("frames",null):return NativeFrames.error("Native frames must already be atomically adopted by this host")
	var prepared:=NativeFrames.prepare(result,model.native_apparatus())
	if not prepared.ok:return prepared
	var committed: Dictionary=prepared.entries
	for id in committed:
		committed[id].texture=ImageTexture.create_from_image(committed[id].image)
		_native_owned_ids[id]=true
	_native_frames=committed;_native_stamp=stamp.duplicate(true);_native_revision=revision
	native_presentation_mode=true;native_presentation_status="";_native_failed_stamp.clear()
	texture_filter=CanvasItem.TEXTURE_FILTER_NEAREST
	queue_redraw()
	return {"ok":true,"revision":revision,"frames":committed.size()}

func render_native_presentation()->Dictionary:
	native_presentation_mode=true
	if _native_controller==null:return NativeFrames.error("Native presentation controller is not configured")
	var already_pending:=_native_render_pending
	_native_render_pending=true
	var result: Dictionary=await _native_controller.render_once()
	_native_render_pending=already_pending
	if result.get("ok",false):_native_configuration_ready=true
	if not result.get("ok",false):native_presentation_status="原始绘图资料未齐备";status.emit(str(result.get("error","原始绘图条件尚未齐备")))
	return result

func cancel_native_presentation()->Dictionary:
	if _native_controller==null:return {"ok":true,"released":false}
	return _native_controller.cancel_pending()

func _process(dt: float) -> void:
	_animation_time += dt
	if not _native_frames.is_empty():_native_stamp_current()
	if native_presentation_mode and not _native_render_pending:_render_native_if_needed()
	if model != null:
		# Pause/fidelity-stop can change the run flag without a changed signal.
		# Repaint once on that edge so inactive helper buttons do not linger.
		if model.running or _controls_running!=model.running:queue_redraw()
		_controls_running=model.running

func set_tool(kind: String) -> void:
	active_tool = kind
	_pour_source = -1
	mouse_default_cursor_shape = Control.CURSOR_ARROW if kind == "select" else Control.CURSOR_CROSS

func to_world(point: Vector2) -> Vector2:
	return (point - pan) / zoom

func _position(v: Dictionary) -> Vector2:
	return Vector2(float(v.position[0]), float(v.position[1]))

func _texture(kind: String) -> Texture2D:
	if _textures.has(kind): return _textures[kind]
	var path: String = "res://assets/apparatus/" + kind + ".png"
	if ResourceLoader.exists(path):
		_textures[kind] = load(path)
		return _textures[kind]
	return null

func vessel_size(v: Dictionary) -> Vector2:
	if v.has("native_bitmap_width") and v.has("native_bitmap_height"): return Vector2(float(v.native_bitmap_width),float(v.native_bitmap_height))
	if v.kind == "annotation": return Vector2(240, 50)
	if v.kind == "chart":
		var dimensions = [240,240]
		return Vector2(float(dimensions[0]), float(dimensions[1]))
	if v.kind == "button": return Vector2(82, 30)
	if v.kind == "image": return Vector2(160, 110)
	if v.kind == "conduit": return Vector2(90, 15)
	var tex = _texture(str(v.get("native_bitmap_plain",v.kind)))
	return tex.get_size() if tex != null else Vector2(45, 65)

func vessel_rect(v: Dictionary) -> Rect2:
	return Rect2(_position(v) - vessel_size(v) * 0.5, vessel_size(v))

func reset_native_selection() -> void:
	_selection={};_dragging_native=false;_drag_id=-1;_control_down=0

func selection_scene() -> Dictionary:
	var charts: Array = []
	for v in model.vessels:
		if v.kind=="chart": charts.append(v)
	return {"vessels":model.native_apparatus(),"connectors":model.native_connectors,"annotations":annotations,"charts":charts,"buttons":model.native_buttons,"scale":model.native_scale}

func _decision_id(result: Dictionary) -> int:
	if not result.get("ok",false): return -1
	if int(result.type)>100 and int(result.type)<400:
		var vessels: Array=model.native_apparatus()
		return int(vessels[int(result.index)].id) if int(result.index)<vessels.size() else -1
	if int(result.type)==3000:
		var charts: Array=selection_scene().charts
		return int(charts[int(result.index)].id) if int(result.index)<charts.size() else -1
	return -1

func hit_test(point: Vector2) -> int:
	if model==null:return -1
	return _decision_id(Selection.press(selection_scene(),point,_selection))


func _gui_input(event: InputEvent) -> void:
	if ui_dispatch.is_valid():
		ui_dispatch.call(Callable(self,"_dispatch_gui_input"),[event]);accept_event();return
	_dispatch_gui_input(event)

func _dispatch_gui_input(event:InputEvent)->void:
	if model == null: return
	if event is InputEventMouseButton:
		var p: Vector2 = to_world(event.position)
		if event.button_index == MOUSE_BUTTON_WHEEL_UP and event.pressed:
			_zoom_at(event.position, 1.12); accept_event(); return
		if event.button_index == MOUSE_BUTTON_WHEEL_DOWN and event.pressed:
			_zoom_at(event.position, 1.0 / 1.12); accept_event(); return
		if event.button_index == MOUSE_BUTTON_MIDDLE:
			_panning = event.pressed; accept_event(); return
		if event.button_index == MOUSE_BUTTON_RIGHT and event.pressed:
			_selection = Selection.press(selection_scene(),p,_selection)
			if not _selection.ok: status.emit(str(_selection.error)); accept_event(); return
			selected_id = _decision_id(_selection)
			_dragging_native = false
			apparatus_selected.emit(selected_id)
			if selected_id >= 0: context_requested.emit(selected_id, get_global_transform_with_canvas()*event.position)
			queue_redraw(); accept_event(); return
		if event.button_index == MOUSE_BUTTON_LEFT:
			if not event.pressed:
				model.end_pointer()
				if model.running and selected_id >= 0:
					var command := Controls.command_at(model.get_vessel(selected_id),p)
					if command > 0:
						model.manual_action(selected_id,command)
						_drag_id=-1;_dragging_native=false;_control_down=0;accept_event();return
				if active_tool == "select" and not _selection.is_empty():
					var released:=Interaction.release(selection_scene(),_selection)
					if not released.ok:status.emit(str(released.error))
					else:model.refresh_render_state();model.changed.emit()
				_drag_id = -1; _dragging_native = false; _control_down = 0; accept_event(); return
			model.begin_pointer()
			grab_focus()
			if selected_id >= 0 and active_tool == "select":
				_control_down = Controls.command_at(model.get_vessel(selected_id),p)
				if _control_down > 0: queue_redraw(); accept_event(); return
			if active_tool != "select":
				if active_tool in ["annotation", "chart", "image", "button"]: decoration_requested.emit(active_tool, p)
				else: apparatus_created.emit(active_tool, p)
				set_tool("select"); return
			_selection = Selection.press(selection_scene(),p,_selection)
			if not _selection.ok: status.emit(str(_selection.error)); accept_event(); return
			Interaction.begin(selection_scene(),_selection)
			selected_id = _decision_id(_selection)
			_dragging_native = int(_selection.type)!=-1
			apparatus_selected.emit(selected_id)
			if selected_id >= 0:
				var v: Dictionary = model.get_vessel(selected_id)
				if event.double_click:
					properties_requested.emit(selected_id)
				elif v.kind == "button" and not event.alt_pressed:
					button_activated.emit(selected_id)
				else:
					_drag_id = selected_id
					_drag_offset = _position(v) - p
			queue_redraw(); accept_event()
	elif event is InputEventMouseMotion:
		if _panning:
			pan += event.relative; queue_redraw()
		elif _dragging_native:
			var moved := Selection.drag(selection_scene(),_selection,to_world(event.position))
			if not moved.ok: status.emit(str(moved.error)); _dragging_native=false
			else:
				for c in model.native_connectors: c.start=[int(c.metadata[2]),int(c.metadata[3])]; c.end=[int(c.metadata[4]),int(c.metadata[5])]
				model.refresh_render_state(); model.changed.emit()
			queue_redraw()
		else:
			# Original425ED0 changes the cursor over the selected helper rectangles;
			# hover never changes the source apparatus selection.
			if selected_id >= 0:
				var command:=Controls.command_at(model.get_vessel(selected_id),to_world(event.position))
				if command > 0:
					mouse_default_cursor_shape=Control.CURSOR_POINTING_HAND
					tooltip_text=""
					return
			mouse_default_cursor_shape=Control.CURSOR_ARROW if active_tool=="select" else Control.CURSOR_CROSS
			var id: int = hit_test(to_world(event.position))
			if id >= 0:
				var v: Dictionary = model.get_vessel(id)
				if int(v.type_id)==204:
					tooltip_text="运行实验后，单击滴管露出的胶头，显示“吸取”和“点滴”。\n双击查看属性；右键打开菜单。"
				else:tooltip_text = "%s · %.1f°C\n双击查看属性；右键添加药品 / 倾倒" % [str(v.label), float(v.temperature)]
			else: tooltip_text = "选择器件后点击实验区放置；滚轮缩放，中键平移"
	elif event is InputEventKey and event.pressed:
		if event.keycode == KEY_ESCAPE: _drag_id = -1; set_tool("select")
		elif event.keycode == KEY_DELETE and selected_id >= 0: model.remove_apparatus(selected_id); selected_id = -1

func _zoom_at(p: Vector2, factor: float) -> void:
	var world: Vector2 = to_world(p)
	zoom = clampf(zoom * factor, 0.35, 4.0)
	pan = p - world * zoom
	queue_redraw()

func fit_document() -> void:
	if model == null or model.vessels.is_empty(): zoom = 1.5; pan = Vector2.ZERO; return
	var bounds: Rect2 = vessel_rect(model.vessels[0])
	for v in model.vessels: bounds = bounds.merge(vessel_rect(v))
	for annotation in annotations:
		var p = annotation.get("position", [0, 0])
		var dimensions = annotation.get("size", [300, 40])
		bounds = bounds.merge(Rect2(Vector2(float(p[0]), float(p[1])), Vector2(float(dimensions[0]), float(dimensions[1]))))
	if size.x < 10 or size.y < 10: return
	zoom = clampf(minf((size.x - 100) / maxf(580.0, bounds.size.x), (size.y - 100) / maxf(340.0, bounds.size.y)), 0.5, 1.7)
	pan = (size - bounds.size * zoom) * 0.5 - bounds.position * zoom
	queue_redraw()

func _draw() -> void:
	_native_draw_submitted.clear()
	_source_frames.clear();source_render_errors.clear()
	if not _native_frames.is_empty():_native_stamp_current()
	draw_rect(Rect2(Vector2.ZERO, size), background)
	if _native_configuration_ready and not native_presentation_status.is_empty():draw_string(get_theme_default_font(),Vector2(10,18),native_presentation_status,HORIZONTAL_ALIGNMENT_LEFT,-1,12,Color(0.45,0.35,0.20))
	for id in _chart_views.keys():
		if model.get_vessel(int(id)).is_empty():_chart_views[id].clip.queue_free();_chart_views.erase(id)
		else: _chart_views[id].clip.visible = false
	if model == null: return
	draw_set_transform(pan, 0.0, Vector2(zoom, zoom))
	for c in legacy_connectors:
		var a = c.get("start", [0, 0]); var b = c.get("end", [0, 0])
		draw_line(Vector2(float(a[0]), float(a[1])), Vector2(float(b[0]), float(b[1])), Color(0.42, 0.45, 0.45), 3, true)
	for c in model.connections:
		if c.has("legacy_index"): continue
		var a: Dictionary = model.get_vessel(int(c.source))
		var b: Dictionary = model.get_vessel(int(c.target))
		if a.is_empty() or b.is_empty(): continue
		draw_dashed_line(_position(a), _position(b), Color(0.1, 0.38, 0.38, 0.6), 1.0, 4.0)
	var chart_index := 0
	var chart_stopped := false
	for v in model.vessels:
		if v.kind == "chart":
			if chart_stopped: continue
			if chart_index >= 9 or (v.has("native_chart_record") and int(v.native_chart_record[0]) == 0):
				chart_stopped = true; continue
			chart_index += 1
		_draw_vessel(v)
	if model.running and selected_id >= 0:
		for r in Controls.rectangles(model.get_vessel(selected_id)):
			var rect := Rect2(Vector2(r.left,r.top),Vector2(r.right-r.left,r.bottom-r.top))
			draw_rect(rect,Color(0.75,0.75,0.75)); draw_rect(rect,Color.BLACK,false)
			draw_string(get_theme_default_font(),rect.position+Vector2(3,14),r.caption,HORIZONTAL_ALIGNMENT_CENTER,rect.size.x-6,12,Color.BLACK)
	var font: Font = get_theme_default_font()
	for a in annotations:
		var p = a.get("position", [0, 0])
		var color: Color = _bgr(int(a.get("color_integer", 128)))
		var text: String = str(a.get("text", ""))
		if program != null: text = program.expand(text)
		var fs: int = clampi(int(a.get("font_size", 15)), 10, 42)
		var family: String = str(a.get("font", "宋体"))
		if not _fonts.has(family):
			var original_font = SystemFont.new()
			original_font.font_names = PackedStringArray([family, "SimSun", "Songti SC", "STSong", "Noto Serif CJK SC"])
			_fonts[family] = original_font
		var annotation_font: Font = _fonts[family]
		var y: float = float(p[1]) + fs
		for line in text.split("\n"):
			draw_string(annotation_font, Vector2(float(p[0]), y), line, HORIZONTAL_ALIGNMENT_LEFT, -1, fs, color); y += fs * 1.3
	draw_set_transform(Vector2.ZERO, 0.0, Vector2.ONE)
	_acknowledge_native_draw()

func _acknowledge_native_draw()->void:
	if not _native_stamp_current() or _native_stamp==_native_acknowledged_stamp:return
	if _native_draw_submitted.size()!=_native_frames.size():return
	for id in _native_frames:
		if not _native_draw_submitted.has(id):return
	var stamp:=_native_stamp.duplicate(true)
	var acknowledgement: Dictionary=model.acknowledge_native_presentation_display(stamp)
	if acknowledgement.get("ok",false) and acknowledgement.get("acknowledged",false):
		_native_acknowledged_stamp=stamp
		if _native_controller!=null:_native_controller.display_submitted(stamp)
		native_frame_draw_submitted.emit(_native_revision)

func _draw_vessel(v: Dictionary) -> void:
	var rect: Rect2 = vessel_rect(v)
	var p: Vector2 = _position(v)
	var font: Font = get_theme_default_font()
	if v.kind == "annotation":
		var text: String = str(v.get("text", "文字注释"))
		if program != null: text = program.expand(text)
		var y: float = rect.position.y + 16
		for line in text.split("\n"):
			draw_string(font, Vector2(rect.position.x, y), line, HORIZONTAL_ALIGNMENT_LEFT, -1, 16, _bgr(int(v.get("color_integer", 8388608)))); y += 21
	elif v.kind == "chart": _draw_chart(v, rect)
	elif v.kind == "button":
		draw_rect(rect, Color(0.75, 0.75, 0.75)); draw_rect(rect, Color.DIM_GRAY, false)
		draw_string(font, rect.position + Vector2(10, 20), str(v.get("text", "运行")), HORIZONTAL_ALIGNMENT_CENTER, rect.size.x - 20, 13, Color.BLACK)
	elif v.kind == "image":
		var path: String = str(v.get("image_path", ""))
		if not path.is_empty() and not _textures.has(path):
			var img = Image.load_from_file(path)
			if img != null and not img.is_empty(): _textures[path] = ImageTexture.create_from_image(img)
		if _textures.has(path): draw_texture_rect(_textures[path], rect, false)
		else:
			draw_rect(rect, Color(0.96, 0.96, 0.96)); draw_rect(rect, Color.GRAY, false); draw_string(font, p, "图片", HORIZONTAL_ALIGNMENT_CENTER, -1, 13, Color.GRAY)
	elif v.kind == "conduit":
		draw_line(rect.position + Vector2(0, 7), rect.end - Vector2(0, 7), Color(0.5, 0.5, 0.5), 3)
	else:
		var native_id:=int(v.id)
		var native_display := _native_frames.has(native_id)
		var tex = _texture(str(v.get("native_bitmap_plain",v.kind)))
		if native_display:
			# Native40FE60 is SRCCOPY of an already background-composited +FC.
			# Image alpha is opaque; native reserved bytes remain only in words.
			var frame: Dictionary=_native_frames[native_id]
			if frame.get("texture") is Texture2D and frame.get("image") is Image and not frame.image.is_empty():
				draw_texture(frame.texture,frame.top_left)
				_native_draw_submitted[native_id]=true
		elif int(v.get("type_id",0))>100 and int(v.get("type_id",0))<300:
			var particle_stage:=Callable()
			if model.has_method("advance_source_particles"):
				var apparatus:Array=model.native_apparatus();var particle_index:int=apparatus.find(v)
				particle_stage=func(words:Array,presentation:Callable,phase:String)->Dictionary:return model.advance_source_particles(particle_index,words,presentation,phase)
			var source_frame:Dictionary=_source_renderer.render(v,model._species,_source_frames,background.to_rgba32()>>8,particle_stage)
			if source_frame.ok:
				_source_frames.append(source_frame)
				var fingerprint:=hash(source_frame.words)
				if not _source_textures.has(native_id) or _source_textures[native_id].fingerprint!=fingerprint:
					_source_textures[native_id]={"fingerprint":fingerprint,"texture":ImageTexture.create_from_image(source_frame.image)}
				draw_texture(_source_textures[native_id].texture,Vector2(source_frame.top_left[0],source_frame.top_left[1]))
			else:
				source_render_errors[native_id]=source_frame.error
				if tex!=null:draw_texture_rect(tex,rect,false)
		elif tex != null: draw_texture_rect(tex, rect, false)
		else: draw_rect(rect, Color(0.5, 0.5, 0.5), false, 1.0)
		if not v.get("hide_label", false):
			draw_string(font, Vector2(p.x - 65, rect.end.y + 14), str(v.label), HORIZONTAL_ALIGNMENT_CENTER, 130, 12, Color(0.55, 0.05, 0.05))
	if selected_id == int(v.id): draw_rect(rect.grow(4), Color(0.0, 0.2, 0.55), false, 0.75)

func source_render_snapshot()->Array:
	# Read-only visible production-frame evidence for interaction integration QA.
	return _source_frames.duplicate(true)

func _draw_chart(v: Dictionary, rect: Rect2) -> void:
	var id:=int(v.id)
	if not _chart_views.has(id):
		var clip:=Control.new();clip.mouse_filter=Control.MOUSE_FILTER_IGNORE;clip.clip_contents=true;clip.size=Vector2(240,240);add_child(clip)
		var painter:=Control.new();painter.set_script(preload("res://scripts/original/original_chart_view.gd"));painter.size=Vector2(240,240);clip.add_child(painter)
		_chart_views[id]={"clip":clip,"painter":painter}
	var view:Dictionary=_chart_views[id]
	view.clip.visible = true
	view.clip.position=pan+rect.position*zoom;view.clip.scale=Vector2(zoom,zoom)
	view.painter.chart=v;view.painter.queue_redraw()

func _bgr(value: int) -> Color:
	return Color(float(value & 255) / 255, float((value >> 8) & 255) / 255, float((value >> 16) & 255) / 255)
