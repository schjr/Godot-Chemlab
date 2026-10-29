"""Retain exact original resize/association instructions; no generated geometry rules."""
import json,sys
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
from capstone.x86 import X86_OP_REG,X86_OP_IMM,X86_OP_MEM
from original_x86_oracle import OriginalOracle,ROOT,EXPECTED
oracle=OriginalOracle();c=Cs(CS_ARCH_X86,CS_MODE_32);c.detail=True
functions={};constants={}
for name,a,b in [('drag_geometry',0x42873c,0x42a881),('apparatus_association',0x454e44,0x4596f3),('conduit_association',0x459f1c,0x460d47),('connector_helpers',0x454024,0x454e44),('exception_registration',0x534be0,0x534c19)]:
 instructions=[]
 for i in c.disasm(bytes(oracle.uc.mem_read(a,b-a)),a):
  ops=[]
  for op in i.operands:
   item={'size':op.size}
   if op.type==X86_OP_REG:item.update(kind='reg',reg=i.reg_name(op.reg))
   elif op.type==X86_OP_IMM:item.update(kind='imm',value=op.imm)
   elif op.type==X86_OP_MEM:
    item.update(kind='mem',base=i.reg_name(op.mem.base) or '',index=i.reg_name(op.mem.index) or '',scale=op.mem.scale,disp=op.mem.disp)
    if not op.mem.base and not op.mem.index and 0x400000<=op.mem.disp<0x580000:constants[hex(op.mem.disp)]=bytes(oracle.uc.mem_read(op.mem.disp,16)).hex()
   else:raise ValueError(i.op_str)
   ops.append(item)
  instructions.append(dict(address=i.address,next=i.address+i.size,mnemonic=i.mnemonic,operands=ops,text=i.op_str))
 functions[name]=dict(entry=a,end=b,instructions=instructions)
for function in functions.values():
 for index,ins in enumerate(function['instructions'][:-1]):
  if ins['mnemonic']=='mov' and ins['operands'][0].get('reg')=='eax' and ins['operands'][1]['kind']=='imm' and function['instructions'][index+1]['mnemonic']=='call' and function['instructions'][index+1]['operands'][0].get('value')==0x534be0:
   a=ins['operands'][1]['value'];constants[hex(a)]=bytes(oracle.uc.mem_read(a,32)).hex()
for a in [0x56377b,0x56377c,0x56377d]:constants[hex(a)]=bytes(oracle.uc.mem_read(a,16)).hex()
(ROOT/'godot/data/original_interaction_ir.json').write_text(json.dumps(dict(source_sha256=EXPECTED,functions=functions,constants=constants),indent=2)+'\n')
print({k:len(v['instructions']) for k,v in functions.items()})
print(sorted(set(i['mnemonic'] for v in functions.values() for i in v['instructions'])))
