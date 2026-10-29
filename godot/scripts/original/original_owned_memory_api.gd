class_name OriginalOwnedMemoryApi
extends RefCounted
## Logical address placement for an explicitly fresh reconstructed process.
## No returned address is a native host pointer or captured VCL observation.
const Locks=preload("res://scripts/original/original_owned_recursive_locks.gd")
const Memory=preload("res://scripts/original/original_heap_memory.gd")
var locks=Locks.new()
var memory
var scope:=""
var virtual_domains:Array=[]
var local_domains:Array=[]
var exclusions:Array=[]
var lock_domains:Array=[]
var reservations:Dictionary={}
var committed:Dictionary={}
var local_blocks:Dictionary={}
var lock_lifetimes:Dictionary={}
var events:Array=[]
var generation:=0
var initialized:=false
var local_alignment:=16
func _error(message:String)->Dictionary:return {"ok":false,"error":message,"fresh_reconstructed":true,"native_vcl_verified":false}
func _range(value)->bool:
	return value is Dictionary and value.get("address") is int and value.get("size") is int and value.address>0 and value.size>0 and value.address+value.size<=0x100000000
func _overlap(a:int,n:int,b:int,m:int)->bool:return a<b+m and b<a+n
func _align(value:int,alignment:int)->int:return (value+alignment-1)&~(alignment-1)
func initialize(config:Dictionary)->Dictionary:
	if initialized:return _error("Use a fresh owned memory API for a new process scope")
	if str(config.get("scope","")).strip_edges().is_empty():return _error("Explicit fresh reconstructed process scope is required")
	for field in ["virtual_domains","local_domains","exclusions","lock_domains"]:
		if not config.get(field) is Array:return _error("Explicit address domains/exclusions required: "+field)
		for region in config[field]:
			if not _range(region):return _error("Invalid DWORD address range: "+field)
	if int(config.get("page_size",0))!=4096 or int(config.get("allocation_granularity",0))!=65536:return _error("This original process subset requires declared4096-byte pages and65536-byte allocation granularity")
	local_alignment=int(config.get("local_alignment",0))
	if local_alignment<8 or local_alignment>65536 or (local_alignment&(local_alignment-1))!=0:return _error("Explicit power-of-two local address alignment is required")
	var all:Array=config.virtual_domains+config.local_domains
	for i in all.size():
		if i<config.virtual_domains.size() and (int(all[i].address)&65535)!=0:return _error("Virtual domain must start on allocation granularity")
		for j in range(i):
			if _overlap(all[i].address,all[i].size,all[j].address,all[j].size):return _error("Allocation domains overlap")
	if str(config.scope).length()>200:return _error("Reconstructed lifetime scope is too long")
	scope=config.scope;virtual_domains=config.virtual_domains.duplicate(true);local_domains=config.local_domains.duplicate(true);exclusions=config.exclusions.duplicate(true);lock_domains=config.lock_domains.duplicate(true)
	initialized=true;return {"ok":true,"scope":scope,"fresh_reconstructed":true,"native_vcl_verified":false}
func bind_memory(known_byte_memory)->Dictionary:
	if not known_byte_memory is Memory:return _error("Original known-byte memory object is required")
	if memory!=null:return _error("Owned API memory is already bound")
	if not reservations.is_empty() or not local_blocks.is_empty():return _error("Bind the byte world before owned allocations")
	for base in known_byte_memory.pages:
		for domain in virtual_domains+local_domains:
			var first:int=maxi(int(base),int(domain.address));var end:int=mini(int(base)+4096,int(domain.address)+int(domain.size))
			if first>=end:continue
			var covered:=false
			for excluded in exclusions:
				if excluded.address<=first and end<=excluded.address+excluded.size:covered=true
			if not covered:return _error("Allocation domain overlaps existing byte-world pages without an explicit exclusion")
	memory=known_byte_memory;return {"ok":true}
func _contained(address:int,size:int,domains:Array)->bool:
	for region in domains:
		if region.address<=address and address+size<=region.address+region.size:return true
	return false
func _free_range(address:int,size:int)->bool:
	for region in exclusions:
		if _overlap(address,size,region.address,region.size):return false
	for table in [reservations,local_blocks]:
		for base in table:
			if _overlap(address,size,int(base),int(table[base])):return false
	return true
func _place(size:int,alignment:int,domains:Array)->int:
	for region in domains:
		var address:=_align(int(region.address),alignment)
		while address+size<=int(region.address)+int(region.size):
			var advance:=address
			for item in exclusions:
				if _overlap(address,size,item.address,item.size):advance=maxi(advance,int(item.address)+int(item.size))
			for table in [reservations,local_blocks]:
				for base in table:
					if _overlap(address,size,int(base),int(table[base])):advance=maxi(advance,int(base)+int(table[base]))
			if advance==address:return address
			address=_align(advance,alignment)
	return 0
func _reservation(address:int,size:int)->int:
	for base in reservations:
		if int(base)<=address and address+size<=int(base)+int(reservations[base]):return int(base)
	return 0
func _allocation_failure(_diagnostic:int=0)->Dictionary:return {"ok":true,"address":0}
func _virtual_alloc(request:Dictionary)->Dictionary:
	var address:int=request.address;var size:int=request.size;var flags:int=request.flags
	if flags not in [0x2000,0x1000] or (int(request.protect) not in [1,4] if flags==0x2000 else int(request.protect)!=4):return _error("Unsupported original VirtualAlloc flags/protection 0x%x/0x%x"%[flags,int(request.protect)])
	if address<0 or size<=0 or address+size>0x100000000:return _allocation_failure(87)
	if flags==0x2000:
		var base:int=address&~65535 if address!=0 else 0
		var length:int=_align(address+size,4096)-base if address!=0 else _align(size,4096)
		if address==0:base=_place(length,65536,virtual_domains)
		if base==0 or not _contained(base,length,virtual_domains) or not _free_range(base,length):return _allocation_failure(8)
		reservations[base]=length
		return {"ok":true,"address":base,"reserved_size":length}
	var first:int=address&~4095;var end:=_align(address+size,4096)
	if address==0 or _reservation(first,end-first)==0:return _allocation_failure()
	for page in range(first,end,4096):committed[page]=true
	return {"ok":true,"address":first}
func _virtual_free(request:Dictionary)->Dictionary:
	var address:int=request.address;var size:int=request.size;var flags:int=request.flags
	if flags not in [0x4000,0x8000]:return _error("Unsupported original VirtualFree flags")
	if address<=0 or size<0 or address+size>0x100000000:return {"ok":true,"result":0}
	if flags==0x8000:
		if size!=0 or not reservations.has(address):return {"ok":true,"result":0}
		if _active_lock_in(address,int(reservations[address])):return _error("Source allocation contains a live lock; its DeleteCriticalSection lifetime is unresolved")
		for page in range(address,address+int(reservations[address]),4096):committed.erase(page)
		reservations.erase(address);return {"ok":true,"result":1}
	var first:int=address&~4095;var end:=_align(address+size,4096)
	if size==0:
		if not reservations.has(address):return {"ok":true,"result":0}
		end=address+int(reservations[address])
	if _reservation(first,end-first)==0:return {"ok":true,"result":0}
	if _active_lock_in(first,end-first):return _error("Source decommit contains a live lock lifetime")
	for page in range(first,end,4096):committed.erase(page)
	return {"ok":true,"result":1,"decommit_address":first,"decommit_size":end-first}
func _lock_address(address:int)->bool:
	if _contained(address,24,lock_domains) or _contained(address,24,_locals()):return true
	if _reservation(address,24)==0:return false
	for page in range(address&~4095,_align(address+24,4096),4096):
		if not committed.has(page):return false
	return true
func _active_lock_in(address:int,size:int)->bool:
	for identity in lock_lifetimes:
		if _overlap(address,size,int(identity),24):return true
	return false
func _locals()->Array:
	var result:Array=[]
	for base in local_blocks:result.append({"address":int(base),"size":int(local_blocks[base])})
	return result
func _lock(request:Dictionary)->Dictionary:
	var address:int=request.address;var name:String=request.api
	if not _lock_address(address):return _error("Source lock identity is outside the explicit owned world")
	if name=="InitializeCriticalSection":
		if memory==null:return _error("Known-byte memory binding is required for opaque lock storage")
		if lock_lifetimes.has(address):return _error("Source lock already initialized in this allocation lifetime")
		generation+=1;var lifetime:="%s/lock%d"%[scope,generation]
		var result:Dictionary=locks.create(lifetime,address)
		if not result.ok:return result
		lock_lifetimes[address]=lifetime;memory.map_unknown(address,24)
		for offset in 24:
			var at:int=address+offset;memory.pages[at&~4095].known[at&4095]=0
		return {"ok":true,"primitive_executed":true,"opaque_address":address,"opaque_size":24,"memory_writes":[],"native_vcl_verified":false}
	if not lock_lifetimes.has(address):return _error("Unknown/deleted source lock lifetime")
	var lifetime:String=lock_lifetimes[address]
	if name=="DeleteCriticalSection":
		var result:Dictionary=locks.destroy(lifetime,address)
		if result.ok:lock_lifetimes.erase(address)
		return result
	return locks.dispatch(request,lifetime)
func dispatch(request:Dictionary)->Dictionary:
	if not initialized:return _error("Owned process memory API is not initialized")
	for field in (["address","size","flags","protect"] if request.get("api")=="VirtualAlloc" else ["address","size","flags"] if request.get("api")=="VirtualFree" else ["flags","size"] if request.get("api")=="LocalAlloc" else ["address"]):
		if not request.get(field) is int:return _error("Original API request requires integer "+field)
	var result:Dictionary
	match str(request.get("api","")):
		"VirtualAlloc":result=_virtual_alloc(request)
		"VirtualFree":result=_virtual_free(request)
		"LocalAlloc":
			if int(request.flags)!=0:return _error("Unsupported original LocalAlloc flags; payload must remain unknown")
			var size:int=request.size
			var address:int=_place(size,local_alignment,local_domains) if size>0 and size<=0xffffffff else 0
			if address!=0:local_blocks[address]=size
			result={"ok":true,"address":address} # No invented bytes/ZEROINIT.
		"InitializeCriticalSection","EnterCriticalSection","LeaveCriticalSection","DeleteCriticalSection":result=_lock(request)
		_:return _error("Unsupported original owned memory API")
	result.fresh_reconstructed=true;result.native_vcl_verified=false
	events.append({"request":request.duplicate(true),"response":result.duplicate(true)})
	return result
func to_state()->Dictionary:
	return {"scope":scope,"fresh_reconstructed":true,"native_vcl_verified":false,"placement_policy":"ordered-domain first-fit logical addresses","reservations":reservations.duplicate(),"committed":committed.keys(),"local_blocks":local_blocks.duplicate(),"locks":lock_lifetimes.duplicate(),"events":events.duplicate(true)}
