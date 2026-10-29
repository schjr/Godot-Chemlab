extends SceneTree
const VM=preload("res://scripts/original/original_particle_vm.gd")
func op(reg:String,size:int=4)->Dictionary:return {"kind":"reg","reg":reg,"size":size}
func _initialize()->void:
	var failures:Array=[]
	for reverse in [false,true]:
		var vm=VM.new();vm.fp=[[2.0,0.0],[7.0,0.0]]
		var result:Dictionary=vm.execute({"instructions":[{"address":1,"next":2,"mnemonic":"fsubrp" if reverse else "fsubp","operands":[op("st(1)")]},{"address":2,"next":3,"mnemonic":"nop","operands":[]}],"end":3},1)
		if not result.ok or vm.fp.size()!=1 or vm.fp[0][0]!=(-5.0 if reverse else 5.0):failures.append(["x87 subtraction/pop",result,vm.fp])
	for input in [0,1,0x80000000,0xffffffff]:
		var vm=VM.new();vm.registers.eax=input
		var result:Dictionary=vm.execute({"instructions":[{"address":1,"next":2,"mnemonic":"neg","operands":[op("eax")]},{"address":2,"next":3,"mnemonic":"setge","operands":[op("bl",1)]}],"end":3},1)
		var expected:int=(-input)&0xffffffff
		var ge:bool=(expected&0x80000000)==0 or input==0x80000000
		if not result.ok or vm.registers.eax!=expected or vm.carry!=(input!=0) or vm.overflow!=(input==0x80000000) or vm.registers.ebx!=(1 if ge else 0):failures.append(["NEG flags / SETGE",input,result,vm.registers])
	print(JSON.stringify({"failures":failures}))
	if failures.is_empty():print("PASS native VM FSUBP FSUBRP NEG SETGE NOP")
	quit(0 if failures.is_empty() else 1)
