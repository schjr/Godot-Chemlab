"""Retain raw-PE TBitmap constructor and shared-image initialization instructions, without heap edits."""
import hashlib,json,struct
from pathlib import Path
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
from capstone.x86 import X86_OP_REG,X86_OP_IMM,X86_OP_MEM
ROOT=Path(__file__).resolve().parents[1]
raw=(ROOT/'artifacts/ChemLab/_main.exe').read_bytes();sha=hashlib.sha256(raw).hexdigest()
assert sha=='7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c'
image=(ROOT/'godot/data/original_heap_image.bin').read_bytes();base=0x400000
nt=struct.unpack_from('<I',raw,60)[0];opt=struct.unpack_from('<H',raw,nt+20)[0]
mapped=bytearray(struct.unpack_from('<I',raw,nt+80)[0]);headers=struct.unpack_from('<I',raw,nt+84)[0];mapped[:headers]=raw[:headers]
for i in range(struct.unpack_from('<H',raw,nt+6)[0]):
 at=nt+24+opt+i*40;_,rva,n,offset=struct.unpack_from('<4I',raw,at+8);mapped[rva:rva+n]=raw[offset:offset+n]
assert bytes(mapped)==image,'Mapped bitmap source differs from pinned PE reconstruction' 
ranges=[(0x4e8edc,0x4e8f44),(0x4e60fc,0x4e6134),(0x4e843c,0x4e8440),(0x4e94ac,0x4e94fc),(0x4ea08c,0x4ea1c4),(0x530c70,0x530c88),(0x53139c,0x5313b0),(0x5313d8,0x5313f8),(0x531414,0x53146c),(0x531634,0x53163c),(0x531708,0x531731),(0x531760,0x531768)]
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
ir=dict(source_sha256=sha,mapped_image_sha256=hashlib.sha256(image).hexdigest(),image_file='res://data/original_heap_image.bin',image_size=len(image),image_base=base,instructions=instructions,ranges=ranges,scope='Original TBitmap constructor, InitInstance and initial shared-image AddRef; raw selected manager allocation and runtime errors are explicit boundaries')
(ROOT/'godot/data/original_bitmap_constructor_ir.json').write_text(json.dumps(ir,indent=2)+'\n');print(len(instructions),'bitmap constructor instructions')
