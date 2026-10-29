"""Retain original TCanvas constructor prefix and original graphic-object construction instructions."""
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
ranges=[(0x4e2d30,0x4e2d80),(0x4e2da4,0x4e2ea0),(0x4e3790,0x4e37e4),(0x4e3cbc,0x4e3d00),(0x4e3fac,0x4e3fec),(0x4e42a8,0x4e4366),(0x4eb398,0x4eb3d7),(0x4eb3e8,0x4eb40a),(0x51f89c,0x51f8d0),(0x51fa20,0x51fa74),(0x51fbb0,0x51fbec),(0x51fc5c,0x51fc60),(0x51fc60,0x51fcb4),(0x51fd30,0x51fdcc),(0x51fe1c,0x51fe28),(0x52b774,0x52b794),(0x530dfc,0x530e3c),(0x53139c,0x5313b0),(0x5313d8,0x5313f8),(0x531414,0x53146c),(0x531634,0x53163c),(0x531708,0x531731),(0x531760,0x531768)]
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
result={'source_sha256':SOURCE,'image_file':'res://data/original_heap_image.bin','image_sha256':hashlib.sha256(image).hexdigest(),'image_base':base,'image_size':len(image),'ranges':ranges,'instructions':instructions,'scope':'Original startup shared-registry and TThreadList construction, complete normal Canvas constructor including native list growth/registration; allocator, lock primitives and exceptions remain explicit boundaries','vmt_evidence':{'canvas':0x4e25e4,'canvas_size':0x58,'bitmap_canvas':0x4e80d0,'bitmap_canvas_size':0x64,'font':0x4e22a4,'pen':0x4e2420,'brush':0x4e2520,'init_instance':0x531414}}
(ROOT/'godot/data/original_canvas_constructor_ir.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({'instructions':len(instructions),'mnemonics':sorted({i['mnemonic'] for i in instructions})}))
