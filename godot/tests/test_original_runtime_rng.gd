extends SceneTree
const Runtime=preload("res://scripts/original/original_runtime_rng.gd")
const Startup=preload("res://scripts/original/original_startup_rng.gd")
const Particle=preload("res://scripts/original/original_particle_rng.gd")
var failures:Array=[]
func check(condition:bool,label:String)->void:
	if not condition:failures.append(label)
func _initialize()->void:
	var local:Dictionary={"year":2026,"month":10,"day":18,"hour":19,"minute":42,"second":17,"weekday":0,"dst":false}
	for east in [-720,-210,0,330,480,765]:
		var actual:=Runtime.from_host_clock(local,{"bias":east,"name":"explicit clock-boundary input"},421)
		var clock:Dictionary={"year":2026,"month":10,"day":18,"hour":19,"minute":42,"second":17,"day_of_week":0,"millisecond":421}
		var expected:=Startup.seed(clock,-east*60,false)
		check(actual.ok and actual.state==expected.state and actual.ctime_raw==expected.ctime_raw,"source CRT fixed-zone offset "+str(east))
	# Retain the actual Windows branch distinction between current DST and
	# transition capability. StandardBias participates even when it is nonzero.
	var clock:Dictionary={"year":2026,"month":10,"day":18,"hour":19,"minute":42,"second":17,"day_of_week":0,"millisecond":421}
	for months in [[0,0],[0,10],[4,0],[4,10]]:
		var actual:=Runtime.from_windows_clock(clock,{"bias_minutes":300,"standard_bias_minutes":30,"standard_month":months[0],"daylight_month":months[1]})
		var expected:=Startup.seed(clock,330*60,months[0]!=0 and months[1]!=0)
		check(actual.ok and actual.state==expected.state and actual.daylight_applied==expected.daylight_applied,"source Windows timezone initialization "+str(months))
	check(not Runtime.from_host_clock({}, {"bias":480},0).ok,"missing host calendar rejected")
	check(not Runtime.from_host_clock(local,{},0).ok,"missing host timezone rejected")
	var live:=Runtime.start()
	check(live.ok,"actual host startup boundary")
	if live.ok:
		var replay:=Startup.seed(live.profile.system_time,live.profile.crt_timezone_seconds,live.profile.crt_daylight_enabled)
		check(live.state==replay.state and live.ctime_raw==replay.ctime_raw,"actual live boundary feeds original source startup")
		check(live.provenance.timezone_boundary.contains("fixed-offset"),"runtime zone policy retained explicitly")
		var returned:=Runtime.start()
		check(is_same(live,returned) and is_same(live.state,returned.state),"startup calls share one original per-thread sequence")
		var next_value:=Particle.next(live.state)
		check(Runtime.start().state==live.state and Particle.next(replay.state)==next_value,"later startup access never reseeds consumed RNG")
	print(JSON.stringify({"failures":failures,"live_profile":live.get("profile",{}),"provenance":live.get("provenance",{})}))
	if failures.is_empty():print("PASS original runtime RNG live startup clock, source CRT timezone inputs and persistent shared sequence")
	quit(0 if failures.is_empty() else 1)
