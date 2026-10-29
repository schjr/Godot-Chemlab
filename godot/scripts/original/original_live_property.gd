class_name OriginalLiveProperty
extends RefCounted
## 401E5A/401EE7 ->538D8C ->53958C: general g, precision4.
## Exact finite binary64 decimal expansion avoids host printf/log rounding.
static func _multiply(text:String, multiplier:int)->String:
	var carry:=0
	var out:=""
	for index in range(text.length()-1,-1,-1):
		var value:=int(text[index])*multiplier+carry
		out=str(value%10)+out;carry=value/10
	while carry>0:out=str(carry%10)+out;carry=carry/10
	return out

static func format_number(value:float)->String:
	if not is_finite(value):return "" # Nonfinite CRT strings not part of this bounded path.
	var raw:=PackedByteArray();raw.resize(8);raw.encode_double(0,value)
	var low:=int(raw.decode_u32(0));var high:=int(raw.decode_u32(4))
	var negative:bool=(high & 0x80000000)!=0
	var exponent_bits:=(high>>20)&2047
	var significand:=(high&0xfffff)*4294967296+low
	var binary_exponent:=-1074
	if exponent_bits!=0:significand+=4503599627370496;binary_exponent=exponent_bits-1075
	if significand==0:return "-0" if negative else "0"
	var digits:=str(significand)
	var places:=0
	if binary_exponent<0:
		places=-binary_exponent
		for i in places:digits=_multiply(digits,5)
	else:
		for i in binary_exponent:digits=_multiply(digits,2)
	var exponent:=digits.length()-places-1
	var leading:=digits.left(4)
	if leading.length()<4:leading+="0".repeat(4-leading.length())
	var rounded:=int(leading)
	if digits.length()>4 and int(digits[4])>=5:rounded+=1
	if rounded==10000:rounded=1000;exponent+=1
	leading=str(rounded)
	while leading.length()>1 and leading.ends_with("0"):leading=leading.left(leading.length()-1)
	var text:String
	if exponent>=-4 and exponent<4:
		var point:=exponent+1
		if point<=0:text="0."+"0".repeat(-point)+leading
		elif point>=leading.length():text=leading+"0".repeat(point-leading.length())
		else:text=leading.left(point)+"."+leading.substr(point)
	else:
		text=leading.left(1)
		if leading.length()>1:text+="."+leading.substr(1)
		var power:=str(absi(exponent));if power.length()<2:power="0"+power
		text+="e"+("-" if exponent<0 else "+")+power
	return "-"+text if negative else text

static func rows(vessel:Dictionary)->Dictionary:
	var result:Array=[]
	for species in vessel.get("contents",{}):
		if not vessel.get("native_species_mass",{}).has(species):return {"ok":false,"error":"原始药品质量槽位未知："+str(species)}
		var amount:=format_number(float(vessel.contents[species]))
		var mass:=format_number(float(vessel.native_species_mass[species]))
		if amount.is_empty() or mass.is_empty():return {"ok":false,"error":"原始实时格式化的非有限数分支尚未恢复。"}
		result.append([str(species),amount,mass])
	return {"ok":true,"rows":result}
