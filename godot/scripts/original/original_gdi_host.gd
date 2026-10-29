class_name OriginalGDIHost
extends Node
## Persistent native Windows GDI bridge. This performs no software ellipse/arc
## approximation and no per-geometry atlas lookup. Parent owns host deployment.
const Solid = preload("res://scripts/original/original_solid_visual.gd")
const Raster = preload("res://scripts/original/original_material_rasterizer.gd")
var address := "127.0.0.1"
var port := 17708
var timeout_seconds := 5.0
var native_vcl_verified := false
var capture_provider: RefCounted = null
var _socket := StreamPeerTCP.new()
var _received := PackedByteArray()
var _busy := false
func configure(host_address: String, host_port: int, verified_vcl_profile: bool = false) -> void:
	_socket.disconnect_from_host()
	_received.clear()
	address = host_address
	port = host_port
	native_vcl_verified = verified_vcl_profile
func _error(message: String) -> Dictionary:
	return {"ok": false, "error": message, "boundary": "Native Windows GDI host"}
func use_capture_provider(provider: RefCounted) -> void:
	# Explicit capture-only route. A missing request returns its error, without
	# network access, nearest-mask selection or switching construction profiles.
	capture_provider = provider
func render_ops(width: int, height: int, operations: Array, initial_words: Array = [], probe: bool = false, bitmap_format: int = 32, initial_stretch_mode: int = 1) -> Dictionary:
	if capture_provider != null:
		if not capture_provider.has_method("render_ops"): return _error("Capture provider does not implement exact native requests")
		return capture_provider.render_ops(width,height,operations,initial_words,probe,bitmap_format,initial_stretch_mode)
	if not probe and not native_vcl_verified:
		return _error("Native VCL/GDI construction profile has not been verified; use explicit probe mode for evidence collection")
	if _busy: return _error("Native GDI host already has an outstanding request")
	if not is_inside_tree(): return _error("Native GDI bridge must be attached to the scene tree")
	if width <= 0 or height <= 0 or width * height > 4 * 1024 * 1024:
		return _error("Native bitmap dimensions exceed bounded host contract")
	if not initial_words.is_empty() and initial_words.size() != width * height:
		return _error("Initial native bitmap words differ from request dimensions")
	if bitmap_format not in [0,24,32] or initial_stretch_mode not in [1,2,3,4]: return _error("Native bitmap/DC format profile is unsupported")
	_busy = true
	var request := {"protocol": "chemlab-native-gdi-v1", "width": width, "height": height, "operations": operations, "bitmap_format": bitmap_format, "initial_stretch_mode": initial_stretch_mode}
	if not initial_words.is_empty():
		var raw := PackedByteArray()
		raw.resize(initial_words.size() * 4)
		for i in range(initial_words.size()): raw.encode_u32(i * 4, int(initial_words[i]))
		request["initial_bgra"] = Marshalls.raw_to_base64(raw)
	var response: Dictionary = await _request(request)
	_busy = false
	if not response.get("ok", false): return response
	if response.get("protocol", "") != "chemlab-native-gdi-v1" or response.get("guti_sha256", "") != Raster.GUTI_SHA256:
		return _error("Native GDI host identity or original texture hash differs")
	if int(response.get("width", 0)) != width or int(response.get("height", 0)) != height:
		return _error("Native host returned different bitmap dimensions")
	var bytes := Marshalls.base64_to_raw(str(response.get("bgra", "")))
	if bytes.size() != width * height * 4: return _error("Native GDI host returned malformed pixel data")
	var words: Array = []
	words.resize(width * height)
	for i in range(words.size()): words[i] = int(bytes.decode_u32(i * 4))
	response["words"] = words
	response["image"] = Raster.words_to_image(words, width, height)
	response["probe_only"] = probe
	response["native_vcl_verified"] = native_vcl_verified
	return response
func _request(request: Dictionary) -> Dictionary:
	var deadline := Time.get_ticks_msec() + int(timeout_seconds * 1000.0)
	_socket.poll()
	if _socket.get_status() != StreamPeerTCP.STATUS_CONNECTED:
		_socket.disconnect_from_host()
		_received.clear()
		var connect_error := _socket.connect_to_host(address, port)
		if connect_error != OK: return _error("Could not connect to native GDI host: " + str(connect_error))
		while _socket.get_status() == StreamPeerTCP.STATUS_CONNECTING:
			if Time.get_ticks_msec() >= deadline:
				_socket.disconnect_from_host()
				return _error("Native GDI host connection timed out")
			await get_tree().process_frame
			_socket.poll()
		if _socket.get_status() != StreamPeerTCP.STATUS_CONNECTED: return _error("Native GDI host is unavailable")
	var sent := _socket.put_data((JSON.stringify(request) + "\n").to_utf8_buffer())
	if sent != OK: return _error("Native GDI request write failed")
	while Time.get_ticks_msec() < deadline:
		_socket.poll()
		if _socket.get_status() != StreamPeerTCP.STATUS_CONNECTED: return _error("Native GDI host disconnected")
		var available := _socket.get_available_bytes()
		if available > 0:
			var received: Array = _socket.get_data(available)
			if int(received[0]) != OK: return _error("Native GDI response read failed")
			_received.append_array(received[1])
			if _received.size() > 24 * 1024 * 1024: return _error("Native GDI response exceeds bounded host contract")
			var end := _received.find(10)
			if end >= 0:
				var line := _received.slice(0, end).get_string_from_utf8()
				_received = _received.slice(end + 1)
				var decoded = JSON.parse_string(line)
				if not decoded is Dictionary: return _error("Native GDI response is not a JSON object")
				return decoded
		await get_tree().process_frame
	_socket.disconnect_from_host()
	_received.clear()
	return _error("Native GDI host rendering timed out")
func render_solid(destination: Array, width: int, height: int, recipe: Dictionary, probe: bool = false) -> Dictionary:
	if not recipe.get("ok", false): return _error(str(recipe.get("error", "Original solid recipe failed")))
	if destination.size() != width * height: return _error("Solid native destination dimensions differ")
	var operations: Array = recipe.get("draw_operations", [])
	if operations.is_empty(): return {"ok": true, "words": destination.duplicate(), "image": Raster.words_to_image(destination, width, height)}
	var before_tint: Array = []
	var arcs: Array = []
	var tint_color := -1
	for operation in operations:
		match str(operation.get("op", "")):
			"transparent", "rectangle", "ellipse", "texture": before_tint.append(operation)
			"tint_nonwhite":
				if operation.get("weight_bits", "") != Raster.WEIGHT_BITS: return _error("Unexpected original solid tint weight")
				tint_color = int(operation.get("color_integer", -1))
			"arc": arcs.append(operation)
			"composite_white_key":
				if operation.get("weight_bits", "") != Raster.WEIGHT_BITS or int(operation.get("left", -1)) != 0 or int(operation.get("top", -1)) != 0:
					return _error("Unexpected original solid final composition")
			_: return _error("Unported solid operation: " + str(operation.get("op", "")))
	if tint_color < 0: return _error("Original solid tint color missing")
	var stencil: Dictionary = await render_ops(width, height, before_tint, [], probe, 0)
	if not stencil.get("ok", false): return stencil
	var words: Array = stencil.words
	for i in range(words.size()): words[i] = Solid.tint_pixel(int(words[i]), tint_color)
	if not arcs.is_empty():
		var outlined: Dictionary = await render_ops(width, height, arcs, words, probe)
		if not outlined.get("ok", false): return outlined
		words = outlined.words
	for i in range(words.size()):
		words[i] = Solid.composite_pixel(int(destination[i]), int(words[i]))
		if int(words[i]) < 0: return _error("Original solid pixel arithmetic unsupported")
	return {"ok": true, "words": words, "image": Raster.words_to_image(words, width, height), "probe_only": probe, "native_vcl_verified": native_vcl_verified}
func copy_rect(destination: Array, destination_width: int, destination_height: int, source: Array, source_width: int, source_height: int, destination_rect: Array, source_rect: Array, copy_mode: int, probe: bool = false) -> Dictionary:
	if destination.size() != destination_width * destination_height or source.size() != source_width * source_height or destination_rect.size() != 4 or source_rect.size() != 4:
		return _error("Original CopyRect bitmap/rectangle dimensions are unresolved")
	if copy_mode not in [0xEE0086, 0xCC0020]: return _error("Unported original CopyRect raster operation")
	var raw := PackedByteArray()
	raw.resize(source.size() * 4)
	for i in range(source.size()): raw.encode_u32(i * 4, int(source[i]))
	var operation := {"op": "copy_rect", "source_bgra": Marshalls.raw_to_base64(raw),
		"source_width": source_width, "source_height": source_height, "copy_mode": copy_mode,
		"left": int(destination_rect[0]), "top": int(destination_rect[1]), "right": int(destination_rect[2]), "bottom": int(destination_rect[3]),
		"source_left": int(source_rect[0]), "source_top": int(source_rect[1]), "source_right": int(source_rect[2]), "source_bottom": int(source_rect[3])}
	return await render_ops(destination_width, destination_height, [operation], destination, probe)
