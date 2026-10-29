class_name OriginalHeapMemory
extends RefCounted
## Byte-addressed native memory. Unknown LocalAlloc contents are not zeros.
const PAGE:=4096
var pages:Dictionary={}
var error:=""
func _page(address:int)->Dictionary:
	var base:int=address&~4095
	if not pages.has(base):
		var data:=PackedByteArray();data.resize(PAGE)
		var known:=PackedByteArray();known.resize(PAGE)
		var accessible:=PackedByteArray();accessible.resize(PAGE)
		pages[base]={"data":data,"known":known,"accessible":accessible}
	return pages[base]
func map_unknown(address:int,size:int)->void:
	for offset in size:
		var cell:=_page(address+offset)
		cell.accessible[(address+offset)&4095]=1
func commit_zero(base:int)->void:
	var data:=PackedByteArray();data.resize(PAGE)
	var flags:=PackedByteArray();flags.resize(PAGE);flags.fill(1)
	pages[base]={"data":data,"known":flags.duplicate(),"accessible":flags}
func decommit(base:int)->void:pages.erase(base)
func write(address:int,bytes:PackedByteArray)->void:
	var cursor:=0
	while cursor<bytes.size():
		var at:int=address+cursor;var base:int=at&~4095;var index:int=at&4095
		if not pages.has(base):error="Write outside mapped original memory at0x%x"%at;return
		var cell:Dictionary=pages[base];var count:int=mini(PAGE-index,bytes.size()-cursor)
		var data:PackedByteArray=cell.data;var known:PackedByteArray=cell.known
		for i in count:
			if cell.accessible[index+i]==0:error="Write outside mapped original memory at0x%x"%(at+i);return
			data[index+i]=bytes[cursor+i];known[index+i]=1
		cell.data=data;cell.known=known;cursor+=count
func map_known(address:int,bytes:PackedByteArray)->void:
	map_unknown(address,bytes.size());write(address,bytes)
func contains_span(address:int,size:int)->bool:
	for offset in size:
		var at:int=address+offset;var base:int=at&~4095
		if not pages.has(base) or pages[base].accessible[at&4095]==0 or pages[base].known[at&4095]==0:return false
	return true
func read(address:int,size:int)->PackedByteArray:
	var result:=PackedByteArray()
	var cursor:=0
	while cursor<size:
		var at:int=address+cursor;var base:int=at&~4095;var index:int=at&4095
		if not pages.has(base):error="Read outside mapped original memory at0x%x"%at;return []
		var cell:Dictionary=pages[base];var count:int=mini(PAGE-index,size-cursor)
		for i in count:
			if cell.accessible[index+i]==0:error="Read outside mapped original memory at0x%x"%(at+i);return []
			if cell.known[index+i]==0:error="Unobserved original allocation byte at0x%x"%(at+i);return []
		result.append_array(cell.data.slice(index,index+count));cursor+=count
	return result
func to_state()->Dictionary:
	var records:Array=[]
	var addresses:Array=pages.keys();addresses.sort()
	for address in addresses:
		var page:Dictionary=pages[address]
		records.append({"address":address,"data":page.data.hex_encode(),"known":page.known.hex_encode(),"accessible":page.accessible.hex_encode()})
	return {"version":1,"pages":records}
func from_state(state:Dictionary)->Dictionary:
	if int(state.get("version",0))!=1 or not state.get("pages",null) is Array:return {"ok":false,"error":"Invalid original heap byte state"}
	var restored:Dictionary={}
	for record in state.pages:
		var address:int=int(record.address)
		if address&4095!=0 or restored.has(address):return {"ok":false,"error":"Invalid original page address"}
		var cell:Dictionary={}
		for field in ["data","known","accessible"]:
			var bytes:=str(record.get(field,"")).hex_decode()
			if bytes.size()!=PAGE:return {"ok":false,"error":"Incomplete original memory page"}
			cell[field]=bytes
		for field in ["known","accessible"]:
			for value in cell[field]:
				if value not in [0,1]:return {"ok":false,"error":"Invalid original byte validity mask"}
		restored[address]=cell
	pages=restored;error="";return {"ok":true}
