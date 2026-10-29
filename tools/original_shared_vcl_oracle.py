"""Actual constructors/Pen/Brush/default allocator in one original PE world.
Fresh host RLocks are real; Win32 memory page outcomes are explicit diagnostics.
No graphics success stubs, no target process, no disconnected GetMem heap.
"""
import hashlib,json,threading,struct
from pathlib import Path
from probe_original_default_allocator import AllocatorProbe
from original_x86_oracle import ROOT,EXPECTED
from unicorn import UC_HOOK_MEM_WRITE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX,UC_X86_REG_ECX,UC_X86_REG_ESP,UC_X86_REG_EBP,UC_X86_REG_EIP
class SharedVclOracle(AllocatorProbe):
 def __init__(self):
  super().__init__();self.owned={};self.depth={};self.lock_events=[];self.local_written=set()
  self.uc.hook_add(UC_HOOK_MEM_WRITE,lambda uc,kind,a,n,v,data:self.local_written.update(range(a,a+n)) if 0x6000000<=a<0x6010000 else None)
  self.hooks[0x555008]=lambda:self.lock_api('InitializeCriticalSection')
  self.hooks[0x554ec4]=lambda:self.lock_api('EnterCriticalSection')
  self.hooks[0x555020]=lambda:self.lock_api('LeaveCriticalSection')
  for address,name in [(0x5553f8,'SelectObject'),(0x5552d8,'DeleteObject'),(0x555272,'CreateBrushIndirect'),(0x5552b4,'CreatePenIndirect')]:self.hooks[address]=lambda n=name:self.refuse(n)
  for address,value in [(0x57598c,0x534428),(0x575604,0x5306b0),(0x575608,0x530838),(0x57560c,0x530bac)]:self.u32(address,value)
 def refuse(self,name):raise RuntimeError('Explicit graphics boundary: '+name)
 def lock_api(self,name):
  address=self.arguments(1)[0]
  if name=='InitializeCriticalSection':
   if address in self.owned:raise ValueError('Duplicate lifetime')
   self.owned[address]=threading.RLock();self.depth[address]=0
  elif name=='EnterCriticalSection':self.owned[address].acquire();self.depth[address]+=1
  else:self.owned[address].release();self.depth[address]-=1
  self.lock_events.append(dict(api=name,address=address));self.stdcall(None,4)
 def run(self,entry,eax=0,edx=0,ecx=0,end=None):
  self.uc.reg_write(UC_X86_REG_EAX,eax);self.uc.reg_write(UC_X86_REG_EDX,edx);self.uc.reg_write(UC_X86_REG_ECX,ecx)
  if end is None:return self.call(entry,b'')
  sp=0x90ffe00;self.uc.mem_write(sp,struct.pack('<I',self.stop_address));self.uc.reg_write(UC_X86_REG_ESP,sp);self.uc.reg_write(UC_X86_REG_EBP,0);self.u32(0,0xffffffff)
  self.uc.emu_start(entry,end,count=2000000)
  if self.uc.reg_read(UC_X86_REG_EIP)!=end:raise ValueError('Source bootstrap endpoint not reached')
  return self.uc.reg_read(UC_X86_REG_EAX)
 def known_bytes(self,address,size):
  raw=bytes(self.uc.mem_read(address,size));return bytes(v for i,v in enumerate(raw) if not any(a<=address+i<a+24 for a in self.owned))
 def local_segments(self):
  result=[]
  for event in self.events:
   if event['api']!='LocalAlloc':continue
   address=int(event['address'],16);end=address+event['size'];start=None
   for at in range(address,end+1):
    keep=at<end and at in self.local_written
    if keep and start is None:start=at
    if not keep and start is not None:result.append(dict(address=start,hex=bytes(self.uc.mem_read(start,at-start)).hex()));start=None
  return result
 def state(self):
  return dict(heap_globals_sha256=hashlib.sha256(self.known_bytes(0x59b170,0x78)).hexdigest(),registry_globals={hex(a):self.u32(a) for a in [0x59a9e0,0x59a9e4,0x59a9e8,0x59a9ec] if self.u32(a)!=0},
   local_known_segments=self.local_segments(),
   pages=[dict(address=a,sha256=hashlib.sha256(self.known_bytes(a,4096)).hexdigest()) for a in sorted(self.committed)],opaque_locks=list(self.owned),locks=self.lock_events.copy(),events=self.events.copy(),fs_head=self.u32(0))

def build():
 seed=json.loads((ROOT/'godot/tests/fixtures/original_canvas_constructor.json').read_text())['cases'][0]
 world=seed['world'];world['scope']='Explicit fresh reconstructed shared VCL/RTL heap, source constructors, genuine host recursive locks, declared memory page outcomes; not live startup'
 world['manager']=dict(allocation_dispatch=0x534428,system_get=0x5306b0,system_free=0x530838,system_realloc=0x530bac)
 world['segments'].append(dict(address=0x574b54,hex='00'))
 o=SharedVclOracle()
 for s in world['segments']:o.uc.mem_write(s['address'],bytes.fromhex(s['hex']))
 for a,v in world['globals'].items():o.u32(int(a,16),v)
 steps=[]
 def record(operation,entry,eax=0,edx=0,ecx=0,end=None):
  
  try:value=o.run(entry,eax,edx,ecx,end)
  except Exception as e:raise RuntimeError(operation) from e
  steps.append(dict(operation=operation,entry=entry,eax=eax,edx=edx,ecx=ecx,endpoint=end if end is not None else -1,value=value,state=o.state()));return value
 record('source registry constructors',0x4eb398,end=0x4eb3d7)
 record('source canvas lists',0x4eb3e8,end=0x4eb40a)
 vmt=seed['steps'][-1]['input'];canvas=record('source complete Canvas constructor',0x4e42a8,vmt,1);pen=o.u32(canvas+16);brush=o.u32(canvas+20)
 for name,entry,ptr,value in [('Pen new color',0x4e3e50,pen,0x112233),('Brush new color',0x4e4158,brush,0x445566),('Pen same key reuse',0x4e3e50,pen,0x112233),('Brush original key frees allocator node',0x4e4158,brush,0xffffff),('Pen original key frees allocator node',0x4e3e50,pen,0),('Pen repeated allocation',0x4e3e50,pen,0x778899),('Brush hollow style',0x4e4274,brush,1)]:record(name,entry,ptr,value)
 bitmap=record('source complete TBitmap constructor lazy Canvas absent',0x4e8edc,0x4e2af4,1)
 record('source bitmap shared image AddRef',0x4e843c,o.u32(bitmap+0x20))
 if o.u32(bitmap+0x24)!=0:raise ValueError('Bitmap constructor synthesized a lazy Canvas')
 if any(o.depth.values()):raise ValueError('Unbalanced real host locks')
 result=dict(source_sha256=EXPECTED,scope=world['scope'],world=world,canvas=canvas,pen=pen,brush=brush,bitmap=bitmap,steps=steps,native_win32_verified=False,native_vcl_verified=False)
 out=ROOT/'godot/tests/fixtures/original_shared_vcl_world.json';out.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(dict(steps=len(steps),canvas=hex(canvas),pen=hex(pen),brush=hex(brush),pages=len(o.committed),locks=len(o.lock_events),sha256=hashlib.sha256(out.read_bytes()).hexdigest())))
if __name__=='__main__':build()
