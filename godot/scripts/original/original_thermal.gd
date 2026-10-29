class_name OriginalThermal
extends RefCounted
## Direct branch port of main.exe 0x0048E418, confirmed by its machine instructions.
## Heater geometry 0x00470060 is intentionally not replaced or approximated here.

const X87 = preload("res://scripts/original/original_x87.gd")

const NATIVE_OFFSETS := {"type_id": 0x08, "temperature": 0x88,
	"native_heating": 0xa0, "native_rate_slider": 0x3c78,
	"native_liquid_volume": 0x4320}

static func slider_multiplier(slider: int) -> float:
	# 0x48E43B..0x48E4D2; fabs wrapper 0x5394D4 resolved at instruction level.
	var value: float = float(clampi(slider, 1, 19))
	if absf(value - 10.0) < 0.1: return 1.0
	if value > 10.0: return value - 9.0
	# Native .1 is an 80-bit constant. Integer/10 reproduces its qword store for
	# each possible integer slider 1..9; a binary64 .1*integer does not always do so.
	if value < 10.0: return value / 10.0
	return value

static func advance(vessel: Dictionary, delta_seconds: float, multiplier: float) -> Dictionary:
	for field in ["type_id", "temperature", "native_heating", "native_liquid_volume"]:
		if not vessel.has(field): return {"ok": false, "error": "原始热计算缺少字段：" + field, "native_function": "0x0048E418"}
	if not is_finite(delta_seconds) or not is_finite(multiplier) or not is_finite(float(vessel.temperature)) or not is_finite(float(vessel.native_liquid_volume)):
		return {"ok": false, "error": "原始热计算包含非有限数值。", "native_function": "0x0048E418"}
	var type_id: int = int(vessel.type_id)
	# Native unsigned range test plus exact comparisons for IDs 108 and 121.
	if not ((type_id >= 101 and type_id <= 106) or type_id == 108 or type_id == 121):
		return {"ok": true, "native_function": "0x0048E418"}
	if int(vessel.native_heating) == 1:
		if float(vessel.native_liquid_volume) <= 0.001:
			var native_value: Array = X87.thermal_store(50.0, delta_seconds, multiplier, float(vessel.temperature), false)
			if native_value.is_empty(): return {"ok": false, "error": "原始 x87 热计算数值超出已实现范围。"}
			vessel.temperature = native_value[0]
			if float(vessel.temperature) > 800.0: vessel.temperature = 800.0
		else:
			var native_value: Array = X87.thermal_store(5.0, delta_seconds, multiplier, float(vessel.temperature), false)
			if native_value.is_empty(): return {"ok": false, "error": "原始 x87 热计算数值超出已实现范围。"}
			vessel.temperature = native_value[0]
			if float(vessel.temperature) > 100.0: vessel.temperature = 100.0
	if int(vessel.native_heating) == 0:
		var native_value: Array = X87.thermal_store(5.0, delta_seconds, multiplier, float(vessel.temperature), true)
		if native_value.is_empty(): return {"ok": false, "error": "原始 x87 热计算数值超出已实现范围。"}
		vessel.temperature = native_value[0]
		if float(vessel.temperature) < 20.0: vessel.temperature = 20.0
	# Other heater flag values do neither branch; there is no implicit conversion to bool.
	return {"ok": true, "native_function": "0x0048E418"}
