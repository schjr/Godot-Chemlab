class_name OriginalOwnedRecursiveLocks
extends RefCounted
## Actual Godot recursive mutexes for explicit reconstructed source lifetimes.
## Historical pointers are identity keys; captured CRITICAL_SECTION bytes are unused.
var _gate:=Mutex.new()
var _entries:Dictionary={}
func _error(message:String)->Dictionary:return {"ok":false,"error":message,"native_vcl_verified":false}
func _key(scope:String,address:Variant)->String:
	if scope.strip_edges().is_empty() or scope.length()>256 or not address is int or address<=0 or address>0xffffffff:return ""
	return scope+":"+str(address)
func create(scope:String,address:Variant)->Dictionary:
	var key:=_key(scope,address)
	if key.is_empty():return _error("Explicit reconstructed lifetime scope and DWORD source lock identity required")
	_gate.lock()
	if _entries.has(key):
		_gate.unlock();return _error("Source identity already bound; deleted identity reuse requires an explicit new lifetime scope")
	_entries[key]={"mutex":Mutex.new(),"owner":-1,"depth":0,"pending":0,"deleted":false,"scope":scope,"address":address}
	_gate.unlock()
	return {"ok":true,"scope":scope,"address":address,"fresh_reconstructed":true,"native_vcl_verified":false}
func enter(scope:String,address:Variant)->Dictionary:
	var key:=_key(scope,address)
	_gate.lock()
	if key.is_empty() or not _entries.has(key) or _entries[key].deleted:
		_gate.unlock();return _error("Unknown/deleted reconstructed lock identity")
	var entry:Dictionary=_entries[key]
	entry.pending+=1 # Includes this caller before actual acquisition, preventing deletion.
	var actual:Mutex=entry.mutex
	_gate.unlock()
	actual.lock() # Real blocking/recursive operation, on this actual OS thread.
	_gate.lock()
	entry.pending-=1
	entry.owner=OS.get_thread_caller_id();entry.depth+=1
	var result:Dictionary={"ok":true,"api":"EnterCriticalSection","address":address,"depth":entry.depth,"owner":entry.owner,"primitive_executed":true,"native_vcl_verified":false}
	_gate.unlock()
	return result
func leave(scope:String,address:Variant)->Dictionary:
	var key:=_key(scope,address)
	_gate.lock()
	if key.is_empty() or not _entries.has(key) or _entries[key].deleted:
		_gate.unlock();return _error("Unknown/deleted reconstructed lock identity")
	var entry:Dictionary=_entries[key]
	if entry.depth<=0 or entry.owner!=OS.get_thread_caller_id():
		_gate.unlock();return _error("Wrong-owner or unbalanced Leave rejected before native mutex unlock")
	entry.depth-=1
	if entry.depth==0:entry.owner=-1
	var depth:int=entry.depth
	# Hold metadata gate until the actual release; a newly acquiring caller cannot
	# publish its ownership before this release's accounting is complete.
	var actual:Mutex=entry.mutex
	actual.unlock()
	_gate.unlock()
	return {"ok":true,"api":"LeaveCriticalSection","address":address,"depth":depth,"primitive_executed":true,"native_vcl_verified":false}
func destroy(scope:String,address:Variant)->Dictionary:
	var key:=_key(scope,address)
	_gate.lock()
	if key.is_empty() or not _entries.has(key) or _entries[key].deleted:
		_gate.unlock();return _error("Unknown/deleted reconstructed lock identity")
	var entry:Dictionary=_entries[key]
	if entry.depth!=0 or entry.pending!=0:
		_gate.unlock();return _error("Cannot delete a held or waiting reconstructed mutex")
	entry.deleted=true;entry.erase("mutex") # Last reference can die only after balanced release.
	_gate.unlock()
	return {"ok":true,"native_vcl_verified":false}
func state(scope:String,address:Variant)->Dictionary:
	var key:=_key(scope,address)
	_gate.lock()
	if key.is_empty() or not _entries.has(key):
		_gate.unlock();return _error("Unknown reconstructed lock identity")
	var entry:Dictionary=_entries[key]
	var result:Dictionary={"ok":true,"scope":scope,"address":address,"owner":entry.owner,"depth":entry.depth,"pending":entry.pending,"deleted":entry.deleted}
	_gate.unlock();return result
func dispatch(request:Dictionary,scope:String)->Dictionary:
	if not request.has("address"):return _error("Source lock request has no identity")
	match str(request.get("api","")):
		"EnterCriticalSection":return enter(scope,request.address)
		"LeaveCriticalSection":return leave(scope,request.address)
	return _error("Owned mutex backend cannot provide allocation, graphics or another primitive")
