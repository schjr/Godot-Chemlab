"""Retain original TBrush setter/registry/dynamic-event/lazy-handle instructions."""
from pathlib import Path
import json,hashlib,struct
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
from capstone.x86 import X86_OP_REG,X86_OP_IMM,X86_OP_MEM
ROOT=Path(__file__).resolve().parents[1]
SOURCE='7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c'
image=(ROOT/'godot/data/original_heap_image.bin').read_bytes()
base=0x400000
raw=(ROOT/'artifacts/ChemLab/_main.exe').read_bytes();assert hashlib.sha256(raw).hexdigest()==SOURCE
nt=struct.unpack_from('<I',raw,0x3c)[0];opt=struct.unpack_from('<H',raw,nt+20)[0]
assert struct.unpack_from('<I',raw,nt+52)[0]==base
mapped=bytearray(struct.unpack_from('<I',raw,nt+80)[0]);headers=struct.unpack_from('<I',raw,nt+84)[0];mapped[:headers]=raw[:headers]
for index in range(struct.unpack_from('<H',raw,nt+6)[0]):
 offset=nt+24+opt+index*40;_,rva,size,file_at=struct.unpack_from('<4I',raw,offset+8)
 mapped[rva:rva+size]=raw[file_at:file_at+size]
assert bytes(mapped)==image,'Mapped image differs from exact source PE reconstruction' 
ranges=[(0x4e2d30,0x4e2d44),(0x4e2da4,0x4e2fc8),(0x4e34a4,0x4e34b4),(0x4e34d4,0x4e3508),(0x4e40bc,0x4e42a8),(0x4e4e0c,0x4e4e2c),(0x52b774,0x52b794),(0x530dfc,0x530e3c),(0x5315b4,0x5315fc)]
decoder=Cs(CS_ARCH_X86,CS_MODE_32);decoder.detail=True;instructions=[]
for start,end in ranges:
 for ins in decoder.disasm(image[start-base:end-base],start):
  ops=[]
  for operand in ins.operands:
   item={'size':operand.size}
   if operand.type==X86_OP_REG:item.update(kind='reg',reg=ins.reg_name(operand.reg))
   elif operand.type==X86_OP_IMM:item.update(kind='imm',value=operand.imm)
   elif operand.type==X86_OP_MEM:item.update(kind='mem',base=ins.reg_name(operand.mem.base) or '',index=ins.reg_name(operand.mem.index) or '',scale=operand.mem.scale,disp=operand.mem.disp,segment=ins.reg_name(operand.mem.segment) or '')
   else:raise ValueError(ins.op_str)
   ops.append(item)
  instructions.append({'address':ins.address,'next':ins.address+ins.size,'mnemonic':ins.mnemonic,'operands':ops,'text':ins.op_str,'bytes':ins.bytes.hex()})
result={'source_sha256':SOURCE,'image_file':'res://data/original_heap_image.bin','image_sha256':hashlib.sha256(image).hexdigest(),'image_base':base,'image_size':len(image),'ranges':ranges,'instructions':instructions,'scope':'Original normal TBrush setter/registry/dynamic event and lazy handle paths; API failures returned normally, exception unwinding is an explicit boundary','vmt_evidence':{'brush':0x4e2520,'parent':0x4e21d0,'dynamic_table':0x4e21dc,'dynamic_method_id':0xfffd,'dynamic_target':0x4e34d4,'brush_size':0x18}}
(ROOT/'godot/data/original_brush_ir.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({'instructions':len(instructions),'mnemonics':sorted({i['mnemonic'] for i in instructions})}))
