"""Retain decoded source-instruction IR for the original particle routines."""
import runpy,json
from capstone.x86 import X86_OP_REG,X86_OP_IMM,X86_OP_MEM
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
from original_x86_oracle import ROOT,EXPECTED
x=runpy.run_path(str(ROOT/'tools/trace_original_allocator_controlword.py'));read=x['read']
c=Cs(CS_ARCH_X86,CS_MODE_32);c.detail=True
functions={};constants={};dynamic_globals=[]
for name,a,b in [('bubble_update',0x49aa88,0x49b367),('solid_emit',0x49bf44,0x49c23f),('solid_update',0x49c298,0x49c5e5),('bubble_emit',0x49a61c,0x49aa5c),('solid_fade',0x49cdd8,0x49cf54),('frame_solid',0x40e8e4,0x40f304),('frame_gas',0x40f352,0x40f9ff),('solid_color_setup',0x49b698,0x49b7a4),('solid_resize',0x49b7a4,0x49ba04),('solid_clear',0x49bac8,0x49bb20),('rect',0x51ef38,0x51ef52),('solid_resume',0x49b678,0x49b698),('bubble_surface',0x49930c,0x499328),('solid_pixels',0x49c620,0x49cdd8),('pixel_color_mix',0x49ba04,0x49bac8),('bubble_draw',0x49b3a8,0x49b678)]:
 instructions=[]
 for i in c.disasm(read(a,b-a),a):
  ops=[]
  for op in i.operands:
   item={'size':op.size}
   if op.type==X86_OP_REG:item.update(kind='reg',reg=i.reg_name(op.reg))
   elif op.type==X86_OP_IMM:item.update(kind='imm',value=op.imm)
   elif op.type==X86_OP_MEM:
    item.update(kind='mem',base=i.reg_name(op.mem.base) or '',index=i.reg_name(op.mem.index) or '',scale=op.mem.scale,disp=op.mem.disp)
    if not op.mem.base and not op.mem.index:
     addr=op.mem.disp&0xffffffff
     if 0x400000<=addr<0x580000:
      try:constants[hex(addr)]=read(addr,16).hex()
      except ValueError:dynamic_globals.append(hex(addr))
   else:raise ValueError(i.op_str)
   ops.append(item)
  instructions.append(dict(address=i.address,next=i.address+i.size,mnemonic=i.mnemonic,operands=ops,text=i.op_str))
 functions[name]=dict(entry=a,end=b,instructions=instructions)
result=dict(source_sha256=EXPECTED,functions=functions,constants=constants,dynamic_globals=sorted(set(dynamic_globals)))
(ROOT/'godot/data/original_particle_ir.json').write_text(json.dumps(result,indent=2)+'\n')
print({k:len(v['instructions']) for k,v in functions.items()})
print(sorted(set(i['mnemonic'] for v in functions.values() for i in v['instructions'])))
