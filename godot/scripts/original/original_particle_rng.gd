class_name OriginalParticleRng
extends RefCounted
## Native 00539C60 per-thread two-DWORD random state and 004028EC bound.
## State must come from an explicit original startup/runtime profile.
static func next(state: Dictionary) -> int:
	var low := int(state.low) & 0xffffffff
	var high := int(state.high) & 0xffffffff
	var product := low * 0x4e35
	var next_low := (product + 1) & 0xffffffff
	var next_high := ((product >> 32) + low * 0x15a + high * 0x4e35 + (1 if (product & 0xffffffff) == 0xffffffff else 0)) & 0xffffffff
	state.low = next_low
	state.high = next_high
	return next_high & 0x7fffffff
static func bounded(state: Dictionary, bound: int) -> int:
	if bound == 0: return 0 # Native helper does not consume RNG when bound==0.
	return next(state) % bound
