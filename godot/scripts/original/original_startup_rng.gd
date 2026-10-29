class_name OriginalStartupRng
extends RefCounted
## 00413698 -> 0053D198 -> 0053CE18/0053CD04 -> 00539C0C/00539C38.
## Windows GetLocalTime and initialized CRT globals are explicit inputs.
const MONTH_LENGTHS := [31,28,31,30,31,30,31,31,30,31,30,31]
const MONTH_STARTS := [0,31,59,90,120,151,181,212,243,273,304,334]
static func _error(message: String) -> Dictionary:
	return {"ok":false,"error":message,"boundary":"Original Windows startup time/CRT profile"}
static func _signed32(value: int) -> int:
	value &= 0xFFFFFFFF
	return value - 0x100000000 if value >= 0x80000000 else value
static func _dst(hour: int, day_zero: int, month_one: int, year_since_1970: int) -> bool:
	# 0053CD04: this legacy CRT uses its own fixed April/October rule,
	# not the current Windows dynamic timezone transition dates.
	var yday := day_zero + int(MONTH_STARTS[month_one - 1])
	var leap := ((year_since_1970 + 70) & 3) == 0
	if month_one > 2 and leap: yday += 1
	if month_one < 4 or month_one > 10: return false
	if month_one > 4 and month_one < 10: return true
	var sunday: int
	if year_since_1970 > 16 and month_one == 4:
		sunday = int(MONTH_STARTS[month_one - 1]) + 7
	else:
		sunday = int(MONTH_STARTS[month_one])
	if not leap: sunday -= 1
	var weekday := (year_since_1970 * 365 + ((year_since_1970 + 1) >> 2) + sunday + 4) % 7
	sunday -= weekday
	if month_one == 4:
		return yday > sunday or (yday == sunday and hour >= 2)
	return yday < sunday or (yday == sunday and hour <= 1)
static func seed(system_time: Dictionary, crt_timezone_seconds: int, crt_daylight_enabled: bool) -> Dictionary:
	# Read SYSTEMTIME WORDs, not local Unix-time approximations. Milliseconds and
	# day_of_week do not participate in the original conversion.
	for field in ["year","month","day","hour","minute","second","millisecond","day_of_week"]:
		if not system_time.has(field) or not system_time[field] is int or system_time[field] < 0 or system_time[field] > 65535:
			return _error("Explicit Windows SYSTEMTIME WORD missing/invalid: " + field)
	if crt_timezone_seconds < -0x80000000 or crt_timezone_seconds > 0x7FFFFFFF: return _error("CRT timezone global must be a signed DWORD")
	var year: int = system_time.year
	var month: int = system_time.month
	var day: int = system_time.day
	var hour: int = system_time.hour
	if year < 1 or month < 1 or month > 12 or hour > 23 or system_time.minute > 59 or system_time.second > 59 or system_time.millisecond > 999 or system_time.day_of_week > 6:
		return _error("Input is not a valid Windows local-time profile")
	var days_in_month := int(MONTH_LENGTHS[month - 1])
	if month == 2 and year % 4 == 0 and (year % 100 != 0 or year % 400 == 0): days_in_month += 1
	if day < 1 or day > days_in_month: return _error("Input is not a valid Windows calendar date")
	var raw_time := 0xFFFFFFFF
	var daylight_applied := false
	# 0053CE28 checks tm_year [70,138] before normalization.
	if year >= 1970 and year <= 2038:
		var offset := year - 1970
		var leap_days := (offset + 2) >> 2
		if ((year - 1900) & 3) == 0 and month < 3: leap_days -= 1
		var elapsed_days := offset * 365 + leap_days + int(MONTH_STARTS[month - 1]) + day - 1
		var seconds := _signed32(elapsed_days * 86400 + hour * 3600 + int(system_time.minute) * 60 + int(system_time.second) + crt_timezone_seconds)
		if crt_daylight_enabled and _dst(hour, day - 1, month, offset):
			seconds = _signed32(seconds - 3600)
			daylight_applied = true
		# 0053CF94 rejects signed seconds <=0, including the epoch itself.
		if seconds > 0: raw_time = seconds
	# 00539C0C writes low=raw_time, high=0, then consumes one 00539C38.
	var low := (raw_time * 0x15A4E35 + 1) & 0xFFFFFFFF
	return {"ok":true,"ctime_raw":raw_time,"ctime_signed":_signed32(raw_time),"daylight_applied":daylight_applied,"state":{"low":low,"high":0},"discarded_rand":(low >> 16) & 0x7FFF,"profile":{"system_time":system_time.duplicate(true),"crt_timezone_seconds":crt_timezone_seconds,"crt_daylight_enabled":crt_daylight_enabled}}
