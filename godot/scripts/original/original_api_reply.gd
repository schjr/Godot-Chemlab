class_name OriginalApiReply
extends RefCounted
## Validate host primitive replies before retained instructions can continue.
static func validate(reply:Variant,fallback:String)->Dictionary:
	if reply is Dictionary and reply.get("ok",false) is bool and reply.get("ok",false):return reply
	var message:=str(reply.get("error",fallback)) if reply is Dictionary else fallback
	if message.is_empty():message=fallback
	if message.is_empty():message="Original primitive result is unresolved"
	return {"ok":false,"error":message}
