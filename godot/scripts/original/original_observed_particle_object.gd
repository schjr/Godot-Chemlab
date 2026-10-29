class_name OriginalObservedParticleObject
extends RefCounted
## Complete scoped bytes from an existing native particle allocation.
## Uninterpreted fields stay raw; pointer targets require separate observation.
const SOURCE_SHA:="7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c"
static func hash_bytes(bytes:PackedByteArray)->String:
	var hash:=HashingContext.new();hash.start(HashingContext.HASH_SHA256);hash.update(bytes);return hash.finish().hex_encode()
static func validate(record:Dictionary,solid:bool)->Dictionary:
	var size:=0x3468c if solid else 0xfc20
	if record.get("source_sha256","")!=SOURCE_SHA or int(record.get("byte_size",0))!=size or str(record.get("scope","")).is_empty() or not record.get("original_address",null) is int:
		return {"ok":false,"error":"Scoped original particle allocation identity/size is required"}
	var address:int=int(record.original_address)
	if address<=0 or address>0xffffffff-size:return {"ok":false,"error":"Original particle allocation address is invalid"}
	var raw:=str(record.get("raw_hex","")).hex_decode()
	if raw.size()!=size or hash_bytes(raw)!=record.get("sha256",""):return {"ok":false,"error":"Original particle allocation bytes/hash differ"}
	var bindings=record.get("bitmap_bindings",{})
	if not bindings is Dictionary:return {"ok":false,"error":"Original particle bitmap bindings are invalid"}
	for key in bindings:
		var offset:int=str(key).trim_prefix("0x").hex_to_int()
		if offset not in ([0x34678,0x3467c] if solid else [4]):return {"ok":false,"error":"Unproven particle pointer-rebase field"}
		var bitmap=bindings[key]
		if not bitmap is Dictionary or bitmap.get("source_sha256","")!=SOURCE_SHA or str(bitmap.get("scope","")).is_empty() or not bitmap.get("original_pointer",null) is int or raw.decode_u32(offset)!=int(bitmap.original_pointer):return {"ok":false,"error":"Original particle bitmap pointer identity differs"}
		if int(bitmap.get("bitmap_format",0))!=32:return {"ok":false,"error":"Observed particle scanline backing requires original32-bit format; conversion is not inferred"}
		var width:int=int(bitmap.get("width",0));var height:int=int(bitmap.get("height",0))
		if width<=0 or height<=0 or width*height>4*1024*1024 or not bitmap.get("words",null) is Array or bitmap.words.size()!=width*height:return {"ok":false,"error":"Observed particle bitmap backing is incomplete"}
		for word in bitmap.words:
			if not word is int or word<0 or word>0xffffffff:return {"ok":false,"error":"Invalid observed particle pixel DWORD"}
		var pixels:=PackedByteArray();pixels.resize(width*height*4)
		for index in bitmap.words.size():pixels.encode_u32(index*4,int(bitmap.words[index]))
		if hash_bytes(pixels)!=bitmap.get("pixels_sha256",""):return {"ok":false,"error":"Observed particle pixel checksum differs"}
		if not bitmap.get("row_addresses",null) is Array or bitmap.row_addresses.size()!=height:return {"ok":false,"error":"Explicit original scanline addresses are required"}
		for row_address in bitmap.row_addresses:
			if not row_address is int or row_address<=0 or row_address>0xffffffff-width*4:return {"ok":false,"error":"Invalid observed original scanline address"}
	return {"ok":true,"bytes":raw,"bindings":bindings}
