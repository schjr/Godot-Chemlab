"""Actual 40A4B8 particle feedback slices, with explicit VCL presentation boundary.
Original chemistry/manual callbacks run before persistent renderer-cache slices.
No host/Godot/source replacement calculates the cache mutations.
"""
import json,struct
from original_frame_oracle import FrameOracle
from original_actions_oracle import bits
from original_x86_oracle import ROOT,EXPECTED
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EDX,UC_X86_REG_ESP,UC_X86_REG_EBP,UC_X86_REG_EIP
class ParticleFramesOracle(FrameOracle):
 def __init__(self):
  super().__init__();self.pools=[];self.bitmap_rows={};self.presentation_events=[]
  self.tls=self.alloc(0x100);self.u32(self.tls+0x44,1);self.u32(self.tls+0x48,0)
  self.hooks[0x53ca64]=lambda:self.ret(self.tls)
  self.hooks[0x4e95b0]=self.get_row
  self.hooks[0x4e4b84]=lambda:self.ret(self.canvas)
  self.hooks[0x5552de]=lambda:self.record_presentation(0x5552de,20)
  self.hooks[0x5553e0]=lambda:self.record_presentation(0x5553e0,20)
  self.hooks[0x55542e]=lambda:self.record_presentation(0x55542e,16)
  self.hooks[0x4e44a8]=lambda:self.record_presentation(0x4e44a8,4)
  self.form_state=self.alloc(0x5c0);self.u32(self.form_state+0x5bc,0)
 def get_row(self):
  bmp=self.uc.reg_read(UC_X86_REG_EAX);row=self.uc.reg_read(UC_X86_REG_EDX);key=(bmp,row)
  if key not in self.bitmap_rows:self.bitmap_rows[key]=self.alloc(max(4,self.bitmaps[bmp]['width']*4))
  self.ret(self.bitmap_rows[key])
 def record_presentation(self,address,pop):
  self.presentation_events.append(dict(address=hex(address),eax=self.uc.reg_read(UC_X86_REG_EAX),edx=self.uc.reg_read(UC_X86_REG_EDX),ecx=self.uc.reg_read(UC_X86_REG_ECX)))
  self.ret();self.uc.reg_write(UC_X86_REG_ESP,self.uc.reg_read(UC_X86_REG_ESP)+pop)
 def create_pools(self):
  for index,p in enumerate(self.vessels):
   if not 100<self.u32(p+8)<200:self.pools.append(None);continue
   shape=self.bitmaps[self.u32(p+0xfc)];w=shape['width'];h=shape['height']
   solid=self.alloc(0x3468c);bubble=self.alloc(0xfc20)
   # InitInstance531414 has independently been executed against A5 sentinel.
   self.u32(solid+0x34678,self.bitmap(w,h));self.u32(solid+0x3467c,self.bitmap(w,h));self.u32(solid+0x32d4c,1)
   self.u32(solid+0x32d60,w);self.u32(solid+0x32d64,h)
   self.u32(bubble+0x5164,w);self.u32(bubble+0x5168,h);self.u32(bubble+0x7ef4,1);self.u32(bubble+0x5158,0xffffff)
   self.u32(0x595214+index*4,solid);self.u32(0x5940b0+index*4,bubble)
   self.pools.append((solid,bubble))
 def render_particles(self,pause=0,run=1):
  self.u32(0x57a6f8,run);self.u32(self.form_state+0x5bc,pause)
  for index,p in enumerate(self.vessels):
   if not 100<self.u32(p+8)<300:continue
   for entry,end in [(0x40e8e4,0x40f304),(0x40f352,0x40f9ff)]:
    ebp=0x90ff000;sp=ebp-0x2000
    self.u32(ebp-0x58,self.form_state);self.u32(ebp-0x60,index);self.u32(ebp-0x38,0)
    self.uc.reg_write(UC_X86_REG_EBP,ebp);self.uc.reg_write(UC_X86_REG_ESP,sp)
    self.uc.emu_start(entry,end,count=5000000)
    if self.uc.reg_read(UC_X86_REG_EIP)!=end:raise RuntimeError('Original particle slice instruction bound exceeded')
 def rng(self):return dict(low=self.u32(self.tls+0x44),high=self.u32(self.tls+0x48))
 def capture_pools(self):
  out=[]
  for pair in self.pools:
   if pair is None:out.append({});continue
   solid,bubble=pair;sc=self.u32(solid+0x34684);bc=self.u32(bubble+0x5150)
   primary=self.bitmaps[self.u32(solid+0x34678)]
   out.append(dict(solid=dict(count=sc,slots=[list(struct.unpack('<13I',self.uc.mem_read(solid+4+i*52,52))) for i in range(sc)],rect=[self.u32(solid+0x32d58+i*4) for i in range(4)],width=primary['width'],height=primary['height'],background=self.u32(solid+0x32d50),previous_background=self.u32(solid+0x32d54)),bubbles=dict(count=bc,call_count=self.u32(bubble+0xfc10),surface=self.u32(bubble+0x7f00),center_x=self.u32(bubble+0xfc18),center_y=self.u32(bubble+0xfc1c),slots=[list(struct.unpack('<13I',self.uc.mem_read(bubble+0x10+i*52,52))) for i in range(bc)])))
  return out
 def capture(self):
  values=self.capture_frame()
  for p,v in zip(self.vessels,values):v['particle_accumulator_bits']=bits(self.f64(p+0x3cc8))
  return dict(vessels=values,pools=self.capture_pools(),rng=self.rng())
 def render(self):
  super().render()
  if self.pools:self.render_particles()
def main():
 doc=next(d for d in json.loads((ROOT/'godot/data/examples.json').read_text()) if d['name']=='氢氧化铜与氢氧化铁')
 o=ParticleFramesOracle();o.setup(doc);o.create_pools();o.enable_manual_presentation()
 start=o.capture();frames=[]
 actions=[dict(selected=2,command=1,position=[429,206],ticks=0),dict(selected=2,command=2,position=[179,190],ticks=15),dict(selected=2,command=2,position=[306,190],ticks=15),dict(selected=5,command=1,position=[510,206],ticks=0),dict(selected=5,command=2,position=[179,190],ticks=15),dict(selected=5,command=2,position=[306,190],ticks=15)]
 from original_workflow_oracle import tick
 for action in actions:
  p=o.vessels[action['selected']];o.u32(p+0x10,action['position'][0]);o.u32(p+0x14,action['position'][1]);o.u32(0x57a734,action['selected']);o.u32(0x57a730,204);o.u32(0x57a738,action['command'])
  o.call(0x477708,b'');o.render()
  for _ in range(action['ticks']):tick(o)
  frames.append(o.capture())
  print('action',action,flush=True)
 result=dict(source_sha256=EXPECTED,profile='Explicit zero original apparatus fixture; particle classes InitInstance zeroing; TLS random state low1 high0; zero-filled DIB scanline input profile; actual49C620/49CDD8/49B3A8 numeric/draw logic; only VCL/GDI primitives recorded without rasterization',fixture_path=doc['fixture'],start=start,actions=actions,frames=frames,delta_bits=bits(.02),status='executed')
 (ROOT/'godot/tests/fixtures/original_particle_frames.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n')
 print('Captured native persistent particle chemistry workflow',sum(a['ticks'] for a in actions),'ticks')
if __name__=='__main__':main()
