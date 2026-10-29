"""Actual complete normal Canvas constructor on declared allocator/lock inputs."""
import json,struct
from original_pen_oracle import PenOracle
from original_x86_oracle import ROOT,EXPECTED
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX
class CanvasOracle(PenOracle):
 def __init__(self,poison):
  super().__init__();self.poison=poison;self.list_initialized=False
  self.hooks[0x555008]=self.initialize_critical;self.hooks[0x530ca0]=self.realloc_mem
 def get_mem(self):
  size=self.uc.reg_read(UC_X86_REG_EAX);address=self.next_block;self.next_block=(address+size+15)&~15
  self.uc.mem_write(address,bytes([self.poison])*size);self.blocks[address]=size;self.events.append({'api':'GetMem','size':size});self.ret(address)
 def initialize_critical(self):
  address=self.args(1)[0];raw=b'\xc3'*24;self.uc.mem_write(address,raw)
  self.events.append({'api':'InitializeCriticalSection','address':address});self.stdcall(None,4)
 def realloc_mem(self):
  pointer=self.uc.reg_read(UC_X86_REG_EAX);size=self.uc.reg_read(UC_X86_REG_EDX);old=self.u32(pointer)
  raw=bytes(self.uc.mem_read(old,min(size,self.blocks[old]))) if old else b''
  address=self.next_block;self.next_block=(address+size+15)&~15;raw+=bytes([self.poison])*(size-len(raw))
  self.uc.mem_write(address,raw);self.u32(pointer,address);self.blocks[address]=size
  self.events.append({'api':'ReallocMem','pointer_address':pointer,'old_address':old,'size':size});self.ret()
 def run(self,entry,eax=0,edx=0,end=None):
  self.uc.reg_write(UC_X86_REG_EAX,eax);self.uc.reg_write(UC_X86_REG_EDX,edx)
  if end is not None:
   def boundary():self.uc.emu_stop()
   self.hooks[end]=boundary
  result=self.call(entry,b'') if end is None else self.call_bounded(entry,end)
  if end is not None:del self.hooks[end]
  if end==0x4eb40a:self.list_initialized=True
  return result
 def call_bounded(self,entry,end):
  # OriginalOracle.call expects STOP; intercept endpoint with a normal return
  # solely for these source startup blocks, which are not standalone functions.
  self.hooks[end]=lambda:self.ret()
  return self.call(entry,b'')
 def snapshot(self,segments):
  addresses={s['address']:len(bytes.fromhex(s['hex'])) for s in segments};addresses.update(self.blocks)
  return {'segments':[{'address':a,'hex':bytes(self.uc.mem_read(a,n)).hex()}for a,n in sorted(addresses.items())], 'globals':{f'0x{a:x}':self.u32(a)for a in [0x59a9e0,0x59a9e4,0x59a9e8]+([0x59a9ec,0x574d90] if self.list_initialized else [])},'events':self.events.copy(),'fs_head':self.u32(0)}
def case(name,poison=0xa5,count=1,existing=False,vmt=0x4e25e4):
 o=CanvasOracle(poison);descriptor=bytearray(o.uc.mem_read(0x574b28,44));struct.pack_into('<I',descriptor,0,0xdeadbeef);o.uc.mem_write(0x574b28,bytes(descriptor))
 segments=[{'address':0x574b28,'hex':descriptor.hex()}]
 if existing:
  data=bytearray([poison]*88);struct.pack_into('<I',data,0,vmt);o.uc.mem_write(0x2005000,bytes(data));segments.append({'address':0x2005000,'hex':data.hex()})
 o.u32(0x59a99c,0x11110022)
 world={'source_sha256':EXPECTED,'scope':'Explicit PE font descriptor input, diagnostic poisoned allocator and declared lock outcomes; constructor instructions execute; not live VCL allocation state','globals':{'0x59a99c':0x11110022},'thread':{'fs_base':0,'exception_head':0xffffffff,'stack_base':0x9000000,'stack_size':0x100000,'stack_pointer':0x90ffe00,'stack_origin':'fresh_committed_pages'},'segments':segments}
 steps=[]
 for op,entry,end in [('registries',0x4eb398,0x4eb3d7),('canvas_lists',0x4eb3e8,0x4eb40a)]:
  o.run(entry,end=end);steps.append({'operation':op,'state':o.snapshot(segments)})
 for i in range(count):
  value=o.run(0x4e42a8,0x2005000 if existing else vmt,0 if existing else 1)
  steps.append({'operation':'canvas','input':0x2005000 if existing else vmt,'allocation_flag':0 if existing else 1,'canvas':value,'state':o.snapshot(segments)})
 return {'name':name,'poison':poison,'world':world,'steps':steps}
def main():
 cases=[case('poisoned allocation normal TCanvas'),case('zero allocation normal TCanvas',0),case('caller instance no allocation or payload zeroing',existing=True),case('six Canvases shared records and native list growth',count=6),case('derived bitmap Canvas allocated at original64 size',vmt=0x4e80d0)]
 output={'source_sha256':EXPECTED,'scope':'Actual normal constructor, InitInstance and TThreadList registration/list growth; allocation and lock backing explicitly hosted; no complete application graphics/runtime claim','cases':cases}
 (ROOT/'godot/tests/fixtures/original_canvas_constructor.json').write_text(json.dumps(output,indent=2)+'\n');print(json.dumps({'cases':len(cases),'steps':sum(len(c['steps']) for c in cases)}))
if __name__=='__main__':main()
