extends SceneTree
const Seed = preload("res://scripts/original/original_startup_rng.gd")
const Rng = preload("res://scripts/original/original_particle_rng.gd")
func _initialize() -> void:
	var fixture_path := ProjectSettings.globalize_path("res://") + "../evidence/original_logic/native-startup-rng-oracle.json"
	var fixture: Dictionary = JSON.parse_string(FileAccess.get_file_as_string(fixture_path))
	assert(fixture.binary_sha256 == "7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c")
	for case in fixture.cases:
		var clock: Dictionary = {}
		for key in case.system_time: clock[key] = int(case.system_time[key])
		var result := Seed.seed(clock,int(case.crt_timezone_seconds),bool(case.crt_daylight_enabled))
		assert(result.ok, "Explicit original startup profile failed: " + str(case.id))
		assert(result.ctime_raw == int(case.native_ctime_raw), "Original CRT time differs: " + str(case.id))
		assert(result.discarded_rand == int(case.native_discarded_rand), "Initial discarded rand differs: " + str(case.id))
		assert(result.state.low == int(case.native_state.low) and result.state.high == int(case.native_state.high), "Startup TLS state differs: " + str(case.id))
		for expected in case.native_next:
			var value := Rng.next(result.state)
			assert(value == int(expected.value) and result.state.low == int(expected.low) and result.state.high == int(expected.high), "Particle RNG continuation differs: " + str(case.id))
		var milliseconds: Dictionary = clock.duplicate()
		milliseconds.millisecond = (int(clock.millisecond) + 1) % 1000
		assert(Seed.seed(milliseconds,int(case.crt_timezone_seconds),bool(case.crt_daylight_enabled)).state == Seed.seed(clock,int(case.crt_timezone_seconds),bool(case.crt_daylight_enabled)).state, "Milliseconds unexpectedly seed native RNG")
	assert(not Seed.seed({},0,false).ok)
	var invalid := {"year":2026,"month":2,"day":30,"hour":0,"minute":0,"second":0,"millisecond":0,"day_of_week":0}
	assert(not Seed.seed(invalid,0,false).ok)
	print("Original startup RNG: %d native time/TLS profiles and %d subsequent particle RNG calls PASS; explicit Windows clock/CRT globals, no current-time or fixed-seed substitution." % [fixture.cases.size(),fixture.cases.size()*3])
	quit()
