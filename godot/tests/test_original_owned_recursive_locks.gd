extends SceneTree
const Locks=preload("res://scripts/original/original_owned_recursive_locks.gd")
const ADDRESS:=0x0a71b01c
var locks=Locks.new()
var failures:Array=[]
var scope:="explicit-test-lifetime-1"
var thread_gate:=Mutex.new()
var worker_done:=false
var worker_result:Dictionary={}
func check(ok:bool,label:String)->void:
	if not ok:failures.append(label)
func contender()->Dictionary:
	var wrong:=locks.leave(scope,ADDRESS)
	var result:=locks.enter(scope,ADDRESS)
	var released:=locks.leave(scope,ADDRESS) if result.ok else {"ok":false}
	thread_gate.lock();worker_result={"wrong":wrong,"entered":result,"released":released};worker_done=true;thread_gate.unlock()
	return worker_result
func done()->bool:
	thread_gate.lock();var value:=worker_done;thread_gate.unlock();return value
func wait_pending(timeout_ms:int)->bool:
	var limit:=Time.get_ticks_msec()+timeout_ms
	while Time.get_ticks_msec()<limit:
		if int(locks.state(scope,ADDRESS).pending)>0:return true
		OS.delay_msec(1)
	return false
func _initialize()->void:
	check(not locks.enter(scope,ADDRESS).ok,"No default mutex for absent identity")
	check(not locks.create("",ADDRESS).ok and not locks.create(scope,0).ok,"Explicit nonnull lifetime identity required")
	check(locks.create(scope,ADDRESS).ok,"Fresh owned mutex created")
	check(not locks.create(scope,ADDRESS).ok,"Aliases cannot silently allocate another mutex")
	check(locks.enter(scope,ADDRESS).ok,"Actual first lock")
	check(locks.enter(scope,ADDRESS).ok and locks.state(scope,ADDRESS).depth==2,"Actual recursive lock")
	var worker:=Thread.new()
	var started:int=worker.start(Callable(self,"contender"))
	check(started==OK,"Separate actual Godot Thread started")
	if started==OK:
		check(wait_pending(2000),"Contender has entered the blocking lock path")
		check(not done(),"Actual separate thread remains blocked")
	check(not locks.destroy(scope,ADDRESS).ok,"Cannot delete held/waiting object")
	check(locks.leave(scope,ADDRESS).ok and locks.state(scope,ADDRESS).depth==1,"One leave retains recursive debt")
	OS.delay_msec(20)
	if started==OK:check(not done(),"Contender cannot pass after only one leave")
	# Always release main-thread debt before any join, including failed checks.
	while int(locks.state(scope,ADDRESS).depth)>0 and int(locks.state(scope,ADDRESS).owner)==OS.get_thread_caller_id():
		check(locks.leave(scope,ADDRESS).ok,"Failure-safe main-thread release")
	if started==OK:
		var limit:=Time.get_ticks_msec()+2000
		while not done() and Time.get_ticks_msec()<limit:OS.delay_msec(1)
		if not done():
			# No unsafe forced release or destruction: terminate this failed test
			# process rather than block indefinitely in wait_to_finish.
			printerr("Contender failed bounded completion after final unlock")
			OS.kill(OS.get_process_id());return
		var result:Dictionary=worker.wait_to_finish()
		check(not result.wrong.ok,"Wrong-owner leave rejected")
		check(result.entered.ok and result.released.ok,"Last unlock releases real contender and it balances release")
		check(int(result.entered.owner)!=OS.get_thread_caller_id(),"Ownership is actual separate OS thread")
	check(not locks.leave(scope,ADDRESS).ok,"Unbalanced leave rejected")
	check(locks.destroy(scope,ADDRESS).ok,"Unlocked object can be deleted")
	check(not locks.create(scope,ADDRESS).ok and not locks.enter(scope,ADDRESS).ok,"Stale lifetime cannot rebind or reacquire")
	check(locks.create("explicit-test-lifetime-2",ADDRESS).ok,"Explicit address reuse with new lifetime")
	check(locks.destroy("explicit-test-lifetime-2",ADDRESS).ok,"Fresh reused identity cleanup")
	print(JSON.stringify({"failures":failures,"native_win32_attestation":false}))
	if failures.is_empty():print("PASS actual Godot recursive mutex ownership contention lifetime and balanced cleanup")
	quit(0 if failures.is_empty() else 1)
