class_name OriginalRuntimeRng
extends RefCounted
## The original startup seed/CRT/RNG arithmetic with this process's live clock.
## The portable OS boundary declares a fixed-offset zone at startup. It does
## not infer Windows transition rules from a timezone abbreviation or isdst.
const Startup=preload("res://scripts/original/original_startup_rng.gd")
static var _startup:Dictionary={}
static func _error(message:String)->Dictionary:return {"ok":false,"error":message}
static func from_windows_clock(system_time:Dictionary,timezone_information:Dictionary)->Dictionary:
	# 53CFB0 Windows branch: (Bias+StandardBias)*60, with daylight enabled
	# only when both transition SYSTEMTIMEs contain a nonzero month.
	for field in ["bias_minutes","standard_bias_minutes","standard_month","daylight_month"]:
		if not timezone_information.get(field,null) is int:return _error("Original timezone boundary is missing integer "+field)
	var bias:int=timezone_information.bias_minutes
	var standard_bias:int=timezone_information.standard_bias_minutes
	var standard_month:int=timezone_information.standard_month
	var daylight_month:int=timezone_information.daylight_month
	if bias < -0x80000000 or bias > 0x7fffffff or standard_bias < -0x80000000 or standard_bias > 0x7fffffff or standard_month<0 or standard_month>12 or daylight_month<0 or daylight_month>12:
		return _error("Original timezone boundary contains invalid Win32 fields")
	# Both addition and multiply are original signed-DWORD operations.
	var zone:int=Startup._signed32(Startup._signed32(bias+standard_bias)*60)
	var result:=Startup.seed(system_time,zone,standard_month!=0 and daylight_month!=0)
	if result.ok:result.timezone_information=timezone_information.duplicate(true)
	return result
static func from_host_clock(calendar:Dictionary,zone:Dictionary,millisecond:int)->Dictionary:
	for field in ["year","month","day","hour","minute","second","weekday"]:
		if not calendar.get(field,null) is int:return _error("Host local clock is missing integer "+field)
	if not zone.get("bias",null) is int:return _error("Host current timezone offset is unavailable")
	var offset:int=zone.bias
	if offset < -1440 or offset > 1440:return _error("Host current timezone offset is outside one day")
	var clock:Dictionary={"year":int(calendar.year),"month":int(calendar.month),"day":int(calendar.day),"hour":int(calendar.hour),"minute":int(calendar.minute),"second":int(calendar.second),"millisecond":millisecond,"day_of_week":int(calendar.weekday)}
	# Godot bias is current minutes east of UTC; Win32 Bias is minutes west.
	# Explicit zero transition months describe this reconstructed fixed zone.
	# This is an OS-boundary policy, not a claim that the host has no DST rules.
	var info:Dictionary={"bias_minutes":-offset,"standard_bias_minutes":0,"standard_month":0,"daylight_month":0}
	var result:=from_windows_clock(clock,info)
	if not result.ok:return result
	result.provenance={"clock":"live Godot host local calendar at process startup","timezone_boundary":"reconstructed OS fixed-offset timezone at startup; no transition dates","host_current_offset_minutes_east":offset,"host_current_timezone_name":str(zone.get("name","")),"host_current_dst":calendar.get("dst",null),"source_startup_entry":0x413698,"scope":"This reconstructed process and UI-thread RNG; not an observed Windows timezone/TLS profile","millisecond_role":"read from the same host-clock second; source seeding ignores milliseconds and weekday"}
	return result
static func start()->Dictionary:
	# 413698 executes once at application startup, never at Run/document load.
	# Return the same Dictionary/state so all consumers share its RNG sequence.
	if not _startup.is_empty():return _startup
	for _attempt in 4:
		var before:float=Time.get_unix_time_from_system()
		var zone:Dictionary=Time.get_time_zone_from_system()
		var calendar:Dictionary=Time.get_datetime_dict_from_system(false)
		var zone_after:Dictionary=Time.get_time_zone_from_system()
		var after:float=Time.get_unix_time_from_system()
		if floor(before)!=floor(after) or zone.get("bias",null)!=zone_after.get("bias",null):continue
		var result:=from_host_clock(calendar,zone,clampi(int(floor((before-floor(before))*1000.0)),0,999))
		if not result.ok:return result
		_startup=result
		return _startup
	return _error("Host clock/timezone changed while reading the original startup clock boundary")
