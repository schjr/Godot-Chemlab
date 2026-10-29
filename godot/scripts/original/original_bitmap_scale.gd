class_name OriginalBitmapScale
extends RefCounted
## Exact bounded numeric resampling of original48F1E0; VCL format conversion
## and scanline allocation remain caller-supplied evidence boundaries.
const X87=preload("res://scripts/original/original_x87.gd")
const Actions=preload("res://scripts/original/original_apparatus_actions.gd")
static func fail(message:String)->Dictionary:return {"ok":false,"error":message,"native_function":0x48F1E0}
static func resample(words:Array,width:int,height:int,scale:float,reserved_byte:int=-1)->Dictionary:
	var s:=X87.stored_float32([scale,0.0]) # caller40FE75 FSTP dword
	if not is_finite(s) or s<=0.1 or s>4.0 or height>300:
		return {"ok":true,"native_return":1,"changed":false,"native_function":0x48F1E0}
	if width<=0 or height<=0 or words.size()!=width*height:return fail("Positive native source dimensions and complete uint32 scanlines required")
	for word in words:
		if not word is int or word<0 or word>0xFFFFFFFF:return fail("Source scanline contains a non-uint32 word")
	var dw:=Actions._trunc(X87.multiply([float(width),0.0],s))
	var dh:=Actions._trunc(X87.multiply([float(height),0.0],s))
	if dh>600:return fail("Original destination scanline array has 600 slots; native stack corruption is not fabricated")
	var output:Array=[];output.resize(dw*dh)
	for y in dh:
		var fy:=X87.stored_float32(X87.divide([float(y),0.0],s)) #48F362
		var y0:=int(fy);var y1:=Actions._trunc(X87.add([fy,0.0],1.0))
		for x in dw:
			var fx:=X87.stored_float32(X87.divide([float(x),0.0],s)) #48F359
			var x0:=int(fx);var x1:=Actions._trunc(X87.add([fx,0.0],1.0))
			if x0<0 or y0<0 or x0>=width or y0>=height:return fail("Native source index outside supplied scanlines")
			if y1>height-1 or x1>width-1:
				output[y*dw+x]=words[y0*width+x0] # native whole-word edge copy
				continue
			if reserved_byte<0 or reserved_byte>255:return fail("Interpolated high byte is original uninitialized stack byte [EBP-11]; explicit observed value required")
			var a:=float(y1)-fy;var b:=float(x1)-fx
			var c:=fx-float(x0);var d:=fy-float(y0)
			#48F3C7..3E2 store four products to QWORD before channel sums.
			var weights:=[X87.stored_double(X87.multiply([a,0.0],b)),X87.stored_double(X87.multiply([a,0.0],c)),X87.stored_double(X87.multiply([d,0.0],b)),X87.stored_double(X87.multiply([d,0.0],c))]
			var neighbors:=[words[y0*width+x0],words[y0*width+x1],words[y1*width+x0],words[y1*width+x1]]
			var result:=reserved_byte<<24
			for channel in 3:
				var total:Array=X87.multiply([float((neighbors[0]>>(channel*8))&255),0.0],weights[0])
				for i in range(1,4):total=X87.add_pair(total,X87.multiply([float((neighbors[i]>>(channel*8))&255),0.0],weights[i]))
				result|=(Actions._trunc(total)&255)<<(channel*8)
			output[y*dw+x]=result
	return {"ok":true,"changed":true,"native_return":0,"width":dw,"height":dh,"words":output,"native_function":0x48F1E0,"format_property":7,"reserved_byte_observed":reserved_byte}
