"""Retain raw-PE startup allocator selection instructions, without heap edits."""
import hashlib,json,struct
from pathlib import Path
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
from capstone.x86 import X86_OP_REG,X86_OP_IMM,X86_OP_MEM
ROOT=Path(__file__).resolve().parents[1]
raw=(ROOT/'artifacts/ChemLab/_main.exe').read_bytes();sha=hashlib.sha256(raw).hexdigest()
assert sha=='7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c'
image=(ROOT/'godot/data/original_heap_image.bin').read_bytes();base=0x400000
ranges=[(0x5340f0,0x534420),(0x534500,0x534530),(0x530cf0,0x530d58)]
d=Cs(CS_ARCH_X86,CS_MODE_32);d.detail=True;instructions=[]
for a,b in ranges:
 for ins in d.disasm(image[a-base:b-base],a):
  ops=[]
  for o in ins.operands:
   item={'size':o.size}
   if o.type==X86_OP_REG:item.update(kind='reg',reg=ins.reg_name(o.reg))
   elif o.type==X86_OP_IMM:item.update(kind='imm',value=o.imm)
   elif o.type==X86_OP_MEM:item.update(kind='mem',base=ins.reg_name(o.mem.base) or '',index=ins.reg_name(o.mem.index) or '',scale=o.mem.scale,disp=o.mem.disp,segment=ins.reg_name(o.mem.segment) or '')
   else:raise ValueError(ins.op_str)
   ops.append(item)
  instructions.append({'address':ins.address,'next':ins.address+ins.size,'mnemonic':ins.mnemonic,'operands':ops,'text':ins.op_str,'bytes':ins.bytes.hex()})
ir=dict(source_sha256=sha,mapped_image_sha256=hashlib.sha256(image).hexdigest(),image_file='res://data/original_heap_image.bin',image_size=len(image),image_base=base,instructions=instructions,ranges=ranges,scope='Original manager selection only; host lookup/load/export results and AddRef are explicit boundaries; no allocation is executed')
(ROOT/'godot/data/original_heap_selection_ir.json').write_text(json.dumps(ir,indent=2)+'\n');print(len(instructions),'selection instructions')
