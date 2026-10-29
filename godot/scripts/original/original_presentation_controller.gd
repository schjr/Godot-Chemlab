class_name OriginalPresentationController
extends Node
const Orchestrator = preload("res://scripts/original/original_presentation_orchestrator.gd")
const Frames = preload("res://scripts/original/original_canvas_frames.gd")
var _host: RefCounted
var _canvas: Control
var _renderer := Orchestrator.new()
var _pending := false
var _pending_snapshot: Dictionary = {}
var _cancel_requested := false
var _display_snapshot: Dictionary = {}
func attach(host: RefCounted, canvas: Control)->Dictionary:
	if _pending:return {"ok":false,"error":"Cannot replace a pending native presentation host"}
	for name in ["capture_native_presentation","adopt_native_presentation","native_presentation_stamp","release_native_presentation"]:
		if not host.has_method(name):return {"ok":false,"error":"Native host lacks "+name}
	if not canvas.has_method("commit_native_frames") or canvas.get("model")!=host:return {"ok":false,"error":"Canvas must already be configured for this exact native host"}
	_host=host;_canvas=canvas
	return {"ok":true}
func _release(snapshot: Dictionary, reason: String)->Dictionary:
	var released: Dictionary=_host.release_native_presentation(snapshot,reason)
	_pending=false;_pending_snapshot.clear();_cancel_requested=false
	return released
func display_submitted(stamp: Dictionary)->void:
	if _host!=null and _host.native_presentation_stamp()==stamp:
		_display_snapshot.clear()

func cancel_pending()->Dictionary:
	if not _pending:
		if not _display_snapshot.is_empty():
			var released: Dictionary=_host.release_native_presentation(_display_snapshot,"Undisplayed presentation cancelled")
			_display_snapshot.clear()
			return released
		return {"ok":true,"released":false}
	# Keep the source physics gate until an already-dispatched provider returns.
	# A second frame must not overlap that provider's mutable GDI/DC state.
	_cancel_requested=true
	return {"ok":true,"cancel_requested":true,"release_after_provider_returns":true}
func _exit_tree()->void:
	if not _display_snapshot.is_empty() and _host!=null:
		_host.release_native_presentation(_display_snapshot,"Display controller detached")
		_display_snapshot.clear()
	if _pending and _host!=null and not _pending_snapshot.is_empty():
		_host.release_native_presentation(_pending_snapshot,"Presentation controller detached")
	_pending=false;_pending_snapshot.clear()
func render_once()->Dictionary:
	if _pending:return {"ok":false,"error":"Native presentation request is already pending"}
	if _host==null or not is_instance_valid(_canvas):return {"ok":false,"error":"Native presentation controller is not attached"}
	var capture: Dictionary=_host.capture_native_presentation()
	if not capture.get("ok",false):return capture
	_pending=true
	_pending_snapshot=capture.snapshot.duplicate(true);_cancel_requested=false
	var result: Dictionary=await _renderer.render(capture.snapshot,capture.providers,capture.profile,false)
	if _cancel_requested:
		_release(capture.snapshot,"Presentation cancelled after provider completed")
		return {"ok":false,"error":"Native presentation was cancelled before adoption"}
	if not result.get("ok",false):
		_release(capture.snapshot,str(result.get("error","Native rendering failed")));return result
	# Validate display transport before any numeric feedback is adopted.
	var validation:=Frames.prepare(result,capture.snapshot.vessels)
	if not validation.ok:_release(capture.snapshot,str(validation.error));return validation
	var adopted: Dictionary=_host.adopt_native_presentation(capture.snapshot,result)
	if not adopted.get("ok",false):_release(capture.snapshot,str(adopted.error));return adopted
	_pending=false;_pending_snapshot.clear();_cancel_requested=false
	# Host's committed signal synchronously delivers the new revision to Canvas.
	if _canvas.native_frame_revision()!=int(adopted.revision):
		_release(capture.snapshot,"Canvas rejected the adopted display frame")
		return {"ok":false,"error":"Native feedback adopted but Canvas did not accept the final display frame"}
	_display_snapshot=capture.snapshot.duplicate(true)
	return {"ok":true,"revision":adopted.revision,"frames":result.frames.size()}
