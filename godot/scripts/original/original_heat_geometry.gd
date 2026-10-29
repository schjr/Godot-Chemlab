class_name OriginalHeatGeometry
extends RefCounted
## Original main.exe 0x00470060: ordered lamp/apparatus geometry and raw field writes.
## Bitmap dimensions are caller-supplied native virtual GetWidth/GetHeight values.
const X87 = preload("res://scripts/original/original_x87.gd")

static func _error(text: String) -> Dictionary:
	return {"ok": false, "error": text, "native_function": "0x00470060"}

static func _neg(value: Array) -> Array:
	return [] if value.is_empty() else [-float(value[0]), -float(value[1])]

static func _compare(a: Array, b: Array) -> int:
	if float(a[0]) < float(b[0]): return -1
	if float(a[0]) > float(b[0]): return 1
	if float(a[1]) < float(b[1]): return -1
	if float(a[1]) > float(b[1]): return 1
	return 0

static func _truncate(value: Array) -> int:
	# Actual helper 0x005394FC switches x87 RC to toward-zero before FISTP.
	var high: float = float(value[0])
	var result: int = int(high)
	if high == float(result):
		if high > 0.0 and float(value[1]) < 0.0: result -= 1
		if high < 0.0 and float(value[1]) > 0.0: result += 1
	return result

static func _scaled(value: float, scale: float) -> Array:
	return X87.multiply([value, 0.0], scale)

static func _gap(lamp: Dictionary, target: Dictionary, scale: float, offset: float) -> Array:
	var bottom: Array = X87.multiply(X87.multiply([float(target.native_sprite_height), 0.0], 0.5), scale)
	bottom = X87.add(bottom, float(int(target.position[1])))
	if offset != 0.0: bottom = X87.add_pair(bottom, _neg(_scaled(offset, scale)))
	var top: Array = X87.add(_neg(_scaled(12.0, scale)), float(int(lamp.position[1])))
	return X87.add_pair(top, _neg(bottom))

static func _i32(value: int) -> int:
	var unsigned: int = value & 0xffffffff
	return unsigned - 0x100000000 if unsigned >= 0x80000000 else unsigned

static func _flame(lamp: Dictionary, gap: Array, scale: float, constant: float, style: int, adjustment: float, stand: bool = false) -> Dictionary:
	var length: Array = X87.add_pair(_scaled(constant, scale), X87.multiply(gap, 2.0))
	if length.is_empty(): return _error("原始火焰长度 x87 数值未解析。")
	var pixels: int = _truncate(length)
	var should_update: bool = int(lamp.native_flame_style) == 1
	if stand:
		var previous: Array = _scaled(float(int(lamp.native_flame_height)), scale)
		if previous.is_empty(): return _error("原始火焰高度比较 x87 数值未解析。")
		should_update = should_update or X87.compare_to_double(previous, float(pixels)) > 0
	else:
		should_update = should_update or pixels < int(lamp.native_flame_height)
	if should_update:
		var height: Array = X87.add(X87.divide([float(pixels), 0.0], scale), adjustment)
		if height.is_empty(): return _error("原始火焰比例换算 x87 数值未解析。")
		lamp.native_flame_height = _truncate(height)
	lamp.native_flame_style = style
	lamp.native_flame_width = 36
	return {"ok": true}

static func derive(vessels: Array, native_scale: float) -> Dictionary:
	if not is_finite(native_scale): return _error("原始显示比例不是有限数值。")
	for v in vessels:
		if not v is Dictionary or not v.has("type_id"): return _error("器件缺少原始类型字段 +0x08。")
		var type_id: int = int(v.type_id)
		if type_id == 301 or (type_id > 100 and type_id < 300): v.native_heating = 0
	for lamp_index in vessels.size():
		var lamp: Dictionary = vessels[lamp_index]
		if int(lamp.type_id) != 302: continue
		if not lamp.has("native_cap_flag"): return _error("酒精灯缺少原始盖状态 +0x38。")
		if int(lamp.native_cap_flag) == 1: continue
		if not lamp.get("position", null) is Array or lamp.position.size() != 2: return _error("酒精灯缺少原始整数坐标。")
		lamp.native_flame_style = 1
		lamp.native_flame_width = 36
		lamp.native_flame_height = 36
		for target_index in vessels.size():
			if target_index == lamp_index: continue
			var target: Dictionary = vessels[target_index]
			var type_id: int = int(target.type_id)
			if not type_id in [101, 102, 103, 104, 105, 106, 121, 301]: continue
			if not target.get("position", null) is Array or target.position.size() != 2: return _error("受热器件缺少原始整数坐标。")
			if type_id == 301:
				if not target.has("native_platform_mode"): return _error("铁架台缺少原始平台状态 +0x6C。")
				if int(target.native_platform_mode) != 2: continue
			if not target.has("native_sprite_width") or not target.has("native_sprite_height"): return _error("受热器件原始位图尺寸尚未提供。")
			var horizontal: float = absf(float(_i32(int(target.position[0]) - int(lamp.position[0]))))
			var radius: Array
			var bottom_offset: float = 0.0
			var maximum_gap: float = 28.0
			var minimum_gap: float = 6.0
			var style: int = 0
			var adjustment: float = -3.0
			var discard_length: bool = false
			if type_id == 301:
				if not target.has("native_platform_offset"): return _error("铁架台缺少原始平台偏移 +0x7C。")
				radius = _scaled(25.0, native_scale)
				bottom_offset = float(int(target.native_platform_offset))
				maximum_gap = 38.0
				minimum_gap = 12.0
			elif type_id == 101:
				if not target.has("native_type_parameter"): return _error("试管缺少原始角度字段 +0x0C。")
				var angle: int = int(target.native_type_parameter)
				maximum_gap = 25.0
				if angle == 0:
					radius = X87.add_pair(X87.multiply(X87.multiply([float(target.native_sprite_width), 0.0], 0.5), native_scale), _neg(_scaled(2.0, native_scale)))
					style = 1
					discard_length = true
				elif angle == 45:
					# 0x470600 uses target.x - 29*scale - lamp.x before fabs.
					var shifted_x: Array = X87.add(_neg(_scaled(29.0, native_scale)), float(int(target.position[0])))
					shifted_x = X87.add(shifted_x, -float(int(lamp.position[0])))
					if shifted_x.is_empty(): return _error("原始斜置试管坐标 x87 数值未解析。")
					horizontal = absf(X87.stored_double(shifted_x))
					radius = _scaled(10.0, native_scale)
					style = 3
					adjustment = 5.0
				elif angle == 97:
					var shifted_x: Array = X87.add(_neg(_scaled(15.0, native_scale)), float(int(target.position[0])))
					shifted_x = X87.add(shifted_x, -float(int(lamp.position[0])))
					if shifted_x.is_empty(): return _error("原始横置试管坐标 x87 数值未解析。")
					horizontal = absf(X87.stored_double(shifted_x))
					radius = _scaled(25.0, native_scale)
					style = 2
					adjustment = -6.0
				else: continue
			else:
				radius = X87.add_pair(X87.multiply(X87.multiply([float(target.native_sprite_width), 0.0], 0.5), native_scale), _neg(_scaled(10.0, native_scale)))
				if type_id in [104, 105]: maximum_gap = 29.0
				if type_id == 106: bottom_offset = 1.0
				if type_id == 121: bottom_offset = 6.0; maximum_gap = 32.0
			if radius.is_empty(): return _error("原始受热水平范围 x87 数值未解析。")
			if X87.compare_to_double(radius, horizontal) <= 0: continue
			var gap: Array = _gap(lamp, target, native_scale, bottom_offset)
			if gap.is_empty(): return _error("原始受热垂直范围 x87 数值未解析。")
			var maximum: Array = _scaled(maximum_gap, native_scale)
			var minimum: Array = _scaled(minimum_gap, native_scale)
			if maximum.is_empty() or minimum.is_empty(): return _error("原始受热阈值 x87 数值未解析。")
			if _compare(gap, maximum) >= 0 or _compare(gap, minimum) <= 0: continue
			if type_id in [104, 105]:
				# Final native branch marks these flasks heated without changing lamp artwork fields.
				target.native_heating = 1
				continue
			if discard_length:
				# Native 0x4705xx computes/truncates a length but discards the result.
				lamp.native_flame_style = 1
				lamp.native_flame_width = 36
			else:
				var flame_gap: Array = _gap(lamp, target, native_scale, 8.0) if type_id == 101 and int(target.native_type_parameter) == 97 else gap
				var changed: Dictionary = _flame(lamp, flame_gap, native_scale, -22.0 if type_id == 301 else -2.0, style, adjustment, type_id == 301)
				if not changed.ok: return changed
			target.native_heating = 1
	# Original final pass propagates ignition (0x9C), not heater-active (0xA0), via a stand attachment.
	for v in vessels:
		if not (int(v.type_id) > 100 and int(v.type_id) < 300): continue
		if not v.has("native_attachment"): return _error("器件缺少原始连接名称 +0x80。")
		for attached in vessels:
			if not attached.has("label"): return _error("原始器件名称查找字段 +0x04 缺失。")
			if str(attached.label) != str(v.native_attachment): continue
			if int(attached.type_id) == 301:
				if not attached.has("native_platform_mode") or not attached.has("native_ignition"): return _error("原始铁架台连接状态尚未提供。")
				if int(attached.native_platform_mode) == 2 and int(attached.native_ignition) == 1: v.native_ignition = 1
			break
	return {"ok": true, "native_function": "0x00470060"}
