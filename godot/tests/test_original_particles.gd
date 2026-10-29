extends SceneTree
const Particles = preload("res://scripts/original/original_live_particles.gd")
const X = preload("res://scripts/original/original_x87.gd")
const Rng = preload("res://scripts/original/original_particle_rng.gd")
func _initialize() -> void:
	var fixture: Dictionary = JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_particles.json"))
	var failures: Array = []
	var checks := 0
	for c in fixture.rng_cases:
		var state: Dictionary = c.initial.duplicate()
		for step in c.steps:
			var actual := Rng.next(state)
			if actual != int(step.result) or int(state.low) != int(step.state.low) or int(state.high) != int(step.state.high): failures.append(["rng",checks])
			checks += 1
	for c in fixture.cases:
		var pool := Particles.create_solid([0,0,40,50])
		var rng: Dictionary = c.rng.duplicate()
		for action in c.actions:
			var amounts: Array = []
			for hex in action.amount_bits: amounts.append(str(hex).hex_decode().decode_float(0))
			var result := Particles.emit_solid(pool,action.colors,amounts,int(action.y),int(action.x),rng)
			if not result.ok: failures.append(["emission",result]); continue
			if int(pool.count) != int(action.expected.count): failures.append(["count",pool.count,action.expected.count])
			for index in mini(pool.count,action.expected.count):
				for word in range(13):
					if int(pool.slots[index][word]) != int(action.expected.slots[index][word]): failures.append(["word",checks,index,word,pool.slots[index][word],action.expected.slots[index][word]])
			if int(rng.low) != int(action.expected.rng.low) or int(rng.high) != int(action.expected.rng.high): failures.append(["emission_rng",checks])
			checks += 1
	for c in fixture.bubble_cases:
		var pool := Particles.create_bubbles([0,0,40,50],20,0xaaaabb,0)
		var rng: Dictionary = c.rng.duplicate()
		for action in c.actions:
			var result: Dictionary = Particles.emit_bubbles.callv([pool]+action.args+[rng])
			if not result.ok: failures.append(["bubble_emit",checks,result]); continue
			for key in ["count","call_count","center_x","center_y"]:
				if int(pool[key]) != int(action.expected[key]): failures.append(["bubble_field",checks,key])
			for index in mini(pool.count,action.expected.count):
				for word in range(13):
					if int(pool.slots[index][word]) != int(action.expected.slots[index][word]): failures.append(["bubble_word",checks,index,word,pool.slots[index][word],action.expected.slots[index][word]])
			if int(rng.low) != int(action.expected.rng.low) or int(rng.high) != int(action.expected.rng.high): failures.append(["bubble_rng",checks])
			checks += 1
	for c in fixture.bubble_updates:
		var pool := Particles.create_bubbles([0,0,40,50],20,0xaaaabb,0)
		pool.slots=c.initial.slots.duplicate(true);pool.count=int(c.initial.count)
		var rng: Dictionary=c.initial.rng.duplicate()
		for frame in c.frames:
			var calls: Dictionary={"index":0,"trig":frame.trig}
			var provider:=func(angle:float,kind:String)->Array:
				if int(calls.index)>=calls.trig.size():failures.append(["bubble_extra_trig",checks]);return []
				var record: Dictionary=calls.trig[int(calls.index)];calls.index=int(calls.index)+1
				if kind!=record.kind or PackedFloat64Array([angle]).to_byte_array().hex_encode()!=record.input_bits:failures.append(["bubble_trig_input",checks,angle,record]);return []
				return X.from_extended80_hex(str(record.extended_bits))
			var result:=Particles.update_bubbles(pool,rng,provider)
			if not result.ok:failures.append(["bubble_update",checks,result]);break
			if int(pool.count)!=int(frame.expected.count):failures.append(["bubble_update_count",checks,pool.count,frame.expected.count])
			for index in mini(pool.count,frame.expected.count):
				for word in range(13):
					if int(pool.slots[index][word])!=int(frame.expected.slots[index][word]):failures.append(["bubble_update_word",checks,index,word,pool.slots[index][word],frame.expected.slots[index][word]])
			if int(rng.low)!=int(frame.expected.rng.low) or int(rng.high)!=int(frame.expected.rng.high):failures.append(["bubble_update_rng",checks])
			checks+=1
	for c in fixture.update_cases:
		var pool := Particles.create_solid([0,0,40,50])
		pool.slots = c.initial.slots.duplicate(true); pool.count = int(c.initial.count); pool.background = int(c.background)
		var rng: Dictionary = c.initial.rng.duplicate()
		for frame in c.frames:
			var calls := {"index":0,"trig":frame.trig}
			var provider := func(angle:float,kind:String)->Array:
				if int(calls.index)>=calls.trig.size(): failures.append(["extra_trig",checks]); return []
				var record: Dictionary = calls.trig[int(calls.index)]; calls.index = int(calls.index)+1
				if kind != record.kind or PackedFloat64Array([angle]).to_byte_array().hex_encode() != record.input_bits:
					failures.append(["trig_input",checks,kind,angle,record]); return []
				return X.from_extended80_hex(str(record.extended_bits))
			var result := Particles.update_solid(pool,rng,provider)
			if not result.ok: failures.append(["update",checks,result]); continue
			if int(pool.count) != int(frame.expected.count): failures.append(["update_count",checks])
			for index in mini(pool.count,frame.expected.count):
				for word in range(13):
					if int(pool.slots[index][word]) != int(frame.expected.slots[index][word]): failures.append(["update_word",checks,index,word,pool.slots[index][word],frame.expected.slots[index][word]])
			if int(rng.low) != int(frame.expected.rng.low) or int(rng.high) != int(frame.expected.rng.high): failures.append(["update_rng",checks])
			checks += 1
	print(JSON.stringify({"particle_checks":checks,"failures":failures}))
	if failures.is_empty():print("PASS original persistent particle/RNG source ports")
	quit(0 if failures.is_empty() else 1)
