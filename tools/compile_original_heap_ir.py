"""Retain exact original default heap instruction IR and mapped PE image bytes."""
from pathlib import Path
import hashlib,json,re,struct
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
from capstone.x86 import X86_OP_REG,X86_OP_IMM,X86_OP_MEM
ROOT=Path(__file__).resolve().parents[1]
raw=(ROOT/'evidence/native-inputs/main.exe').read_bytes()
sha=hashlib.sha256(raw).hexdigest()
assert sha=='7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c'
nt=struct.unpack_from('<I',raw,60)[0];opt=struct.unpack_from('<H',raw,nt+20)[0]
base=struct.unpack_from('<I',raw,nt+52)[0];size=struct.unpack_from('<I',raw,nt+80)[0]
mapped=bytearray(size);header=struct.unpack_from('<I',raw,nt+84)[0];mapped[:header]=raw[:header]
for index in range(struct.unpack_from('<H',raw,nt+6)[0]):
 offset=nt+24+opt+index*40;_,rva,n,position=struct.unpack_from('<4I',raw,offset+8)
 mapped[rva:rva+n]=raw[position:position+n]
starts=sorted(set(int(a,16) for a in re.findall(r'// Entry ([0-9a-fA-F]{8})',(ROOT/'recovered/native/main/decompiled.cpp').read_text())))
decoder=Cs(CS_ARCH_X86,CS_MODE_32);decoder.detail=True
instructions=[];functions=[]
for index,start in enumerate(starts[:-1]):
 if not (0x52f950<=start<0x530d58 or start==0x530dfc or start==0x531be0):continue
 end=starts[index+1];functions.append({'entry':start,'end':end})
 for ins in decoder.disasm(mapped[start-base:end-base],start):
  ops=[]
  for operand in ins.operands:
   item={'size':operand.size}
   if operand.type==X86_OP_REG:item.update(kind='reg',reg=ins.reg_name(operand.reg))
   elif operand.type==X86_OP_IMM:item.update(kind='imm',value=operand.imm)
   elif operand.type==X86_OP_MEM:item.update(kind='mem',base=ins.reg_name(operand.mem.base) or '',index=ins.reg_name(operand.mem.index) or '',scale=operand.mem.scale,disp=operand.mem.disp,segment=ins.reg_name(operand.mem.segment) or '')
   else:raise ValueError(ins.op_str)
   ops.append(item)
  instructions.append({'address':ins.address,'next':ins.address+ins.size,'mnemonic':ins.mnemonic,'operands':ops,'text':ins.op_str,'bytes':ins.bytes.hex()})
image=ROOT/'godot/data/original_heap_image.bin';image.write_bytes(mapped)
ir={'source_sha256':sha,'mapped_image_sha256':hashlib.sha256(mapped).hexdigest(),'image_base':base,'image_size':size,'image_file':'res://data/original_heap_image.bin',
    'functions':functions,'instructions':instructions,'entries':{'get':0x5306b0,'free':0x530838,'realloc':0x530bac},'scope':'Original default System allocator and its retained helper functions; no startup client ordering implied'}
(ROOT/'godot/data/original_heap_ir.json').write_text(json.dumps(ir,indent=2)+'\n')
print(json.dumps({'instructions':len(instructions),'mnemonics':sorted(set(i['mnemonic'] for i in instructions)),'image_bytes':size}))
