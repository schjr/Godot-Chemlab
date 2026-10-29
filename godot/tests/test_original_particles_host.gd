extends SceneTree
const Particles=preload("res://scripts/original/original_live_particles.gd")
const Host=preload("res://scripts/original/original_x87_host.gd")
func _initialize()->void:
	var fixture:Dictionary=JSON.parse_string(FileAccess.get_file_as_string("res://tests/fixtures/original_particles.json"))
	var host=Host.new();var failures:Array=[];var checks:=0
	if not host.start():print("FAIL original particle host: ",host.last_error);quit(1);return
	for pair in [["update_cases",true],["bubble_updates",false]]:
		for c in fixture[pair[0]]:
			var solid:bool=pair[1]
			var pool:=Particles.create_solid([0,0,40,50]) if solid else Particles.create_bubbles([0,0,40,50],20,0xaaaabb,0)
			pool.slots=c.initial.slots.duplicate(true);pool.count=int(c.initial.count)
			if solid:pool.background=int(c.background)
			var rng:Dictionary=c.initial.rng.duplicate()
			for frame in c.frames:
				var result:=Particles.update_solid(pool,rng,Callable(host,"evaluate")) if solid else Particles.update_bubbles(pool,rng,Callable(host,"evaluate"))
				if not result.ok:failures.append([checks,result]);break
				if int(pool.count)!=int(frame.expected.count):failures.append([checks,"count"])
				for index in mini(pool.count,frame.expected.count):
					for word in 13:
						if int(pool.slots[index][word])!=int(frame.expected.slots[index][word]):failures.append([checks,index,word,pool.slots[index][word],frame.expected.slots[index][word]])
				if int(rng.low)!=int(frame.expected.rng.low) or int(rng.high)!=int(frame.expected.rng.high):failures.append([checks,"rng"])
				checks+=1
	host.stop();print(JSON.stringify({"native_host_particle_frames":checks,"failures":failures}))
	if failures.is_empty() and checks==128:print("PASS exact x87 host with all persistent solid/bubble frames")
	quit(0 if failures.is_empty() and checks==128 else 1)
