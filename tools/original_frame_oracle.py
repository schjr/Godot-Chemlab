"""Original full physics sequence with declared zero-heap fixture, never production default."""
import json,struct
from original_gasflow_oracle import GasOracle
from original_liquid_oracle import LiquidOracle
from original_flow_oracle import MaterialFlowOracle
from original_solubility_oracle import SolubilityOracle
from original_x86_oracle import ROOT,EXPECTED,OriginalOracle
from original_actions_oracle import bits

class FrameOracle(GasOracle,LiquidOracle,MaterialFlowOracle,SolubilityOracle):
 def call(self,address,args):
  if address!=0x46c84c:return super().call(address,args)
  from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EBP,UC_X86_REG_EIP,UC_X86_REG_EAX
  sp=0x90ffe00;self.uc.mem_write(sp,struct.pack('<I',self.stop_address)+args)
  self.uc.reg_write(UC_X86_REG_ESP,sp);self.uc.reg_write(UC_X86_REG_EBP,0);self.u32(0,0xffffffff)
  try:self.uc.emu_start(address,self.stop_address,count=10000000)
  except Exception as e:raise RuntimeError(f'Native oracle failed at {self.uc.reg_read(UC_X86_REG_EIP):#x}: {e}') from e
  if self.uc.reg_read(UC_X86_REG_EIP)!=self.stop_address:raise RuntimeError('Native reaction10,000,000 instruction bound exceeded')
  return self.uc.reg_read(UC_X86_REG_EAX)
 def on_instruction(self,uc,address,size,unused):
  if address==0x46f704:self.transport_excess_written=False;self.transport_stack_reads=[]
  if address==0x46fada:self.transport_excess_written=True
  if address==0x46fb18 and not self.transport_excess_written:
   from unicorn.x86_const import UC_X86_REG_EBP
   self.transport_stack_reads.append(bits(self.f64(uc.reg_read(UC_X86_REG_EBP)-0x7c)))
  OriginalOracle.on_instruction(self,uc,address,size,unused)
 def enable_manual_presentation(self):
  from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP
  form=self.alloc(0x700);holder=self.alloc(4);self.u32(holder,form);self.u32(0x5799c4,holder)
  image=self.alloc(0x100);vtable=self.alloc(0x100);self.u32(image,vtable);self.u32(vtable+0x80,0x8000180);self.u32(form+0x4cc,image)
  def canvas():self.ret(self.canvas)
  def present(pop):
   sp=self.uc.reg_read(UC_X86_REG_ESP);pc=self.u32(sp);self.uc.reg_write(UC_X86_REG_ESP,sp+4+pop);self.uc.reg_write(UC_X86_REG_EIP,pc)
  # Verified x86 RET4 CopyRect and RET8 Ellipse; repaint virtual return is unused.
  self.hooks.update({0x4fb0ac:canvas,0x4e4420:lambda:present(4),0x4e4588:lambda:present(8),0x8000180:lambda:self.ret()})
 def enable_orientation_presentation(self):
  from original_flow_oracle import OrientationOracle
  from types import MethodType
  for name in ['concatenate','load_bitmap','assign_bitmap','reset_bitmap','set_checked']:
   setattr(self,name,MethodType(getattr(OrientationOracle,name),self))
  self.sprite_catalog=json.loads((ROOT/'godot/data/sprites.json').read_text());self.loaded=[];self.menu_checked=None
  self.form=self.alloc(0x700);self.u32(self.form+0x448,self.alloc(0x80));self.u32(0x57a6ec,self.string('resources'))
  self.u32(self.bitmap_vtable+8,0x8000140);self.u32(self.bitmap_vtable+0x48,0x8000150)
  self.hooks.update({0x8000140:self.assign_bitmap,0x8000150:self.load_bitmap,0x541040:self.concatenate,0x4d3864:self.set_checked,0x4e9160:self.reset_bitmap})
 def toggle_orientation(self,index):
  from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX,UC_X86_REG_ECX
  self.u32(0x57a734,index);self.u32(0x57a6f8,1)
  self.uc.reg_write(UC_X86_REG_EAX,self.form);self.uc.reg_write(UC_X86_REG_EDX,0);self.uc.reg_write(UC_X86_REG_ECX,0)
  self.call(0x4433b4,b'')
 def setup(self,doc):
  sprites=json.loads((ROOT/'godot/data/sprites.json').read_text())
  kinds={101:'sg0',102:'sb100',103:'zxp100',104:'ydsp100',105:'pdsp100',106:'blg',107:'jqp',108:'uxg',121:'zfm_50',201:'gkp',202:'xkp',204:'jtdg_2',207:'ssddg',208:'jsddg',209:'ld',210:'cjld',211:'fyld',212:'shuic',301:'tiejt0',302:'jjd',303:'wendj',316:'wood'}
  self.doc=doc;self.vessels.clear();self.connectors=[]
  for a in doc['apparatus']:
   i=self.add_vessel({c['name']:c['moles'] for c in a['chemicals']},a['temperature'],a['capacity']);p=self.vessels[i]
   for key,value in a['native_fields'].items():
    off=int(key,16)
    if off in [4,0x80,0x90,0x94,0x98]:self.u32(p+off,self.string(value))
    elif off in [0x20,0x28,0x30,0x88,0xa8,0xb0,0xb8]:self.f64(p+off,float(value))
    else:self.u32(p+off,int(value))
   for j,value in enumerate(a['simulation_fields'][:3]):self.u32(p+0x3c70+4*j,int(value))
   k=kinds.get(a['type_id']);size=abs(float(a['metadata'][3]))
   if a['type_id']==101:k='sg97' if size>=90 else 'sg45' if size>=40 else 'sg0'
   if a['type_id']==102:k='sb500' if size>=500 else 'sb200' if size>=200 else 'sb100'
   if a['type_id']==103:k='zxp250' if size>=250 else 'zxp100'
   if a['type_id']==107 and int(a['metadata'][6])==1:k='djqp'
   wh=sprites[k]['size'] if k in sprites else [int(a['native_fields']['0x3c']),int(a['native_fields']['0x40'])] if a['type_id']==316 else [1,1]
   for off in [0xf4,0xf8,0xfc]:
    bitmap=self.bitmap(*wh);self.bitmaps[bitmap]['geometry_known']=k in sprites or a['type_id']==316;self.u32(p+off,bitmap)
   for r in a['reactions']:self.add_reaction(i,r)
  self.u32(0x58779c,len(self.vessels));self.f64(0x5636c0,1.0)
  offsets=[0,4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,64,68,72,76,80,84,88,96,104]
  for i,c in enumerate(doc['connectors']):
   p=self.alloc(0x80);self.connectors.append(p);self.u32(0x58baec+4*i,p)
   for field,(offset,value) in enumerate(zip(offsets,c['metadata'])):
    if field in [1,11,14]:self.u32(p+offset,self.string(value))
    elif field>=22:self.f64(p+offset,float(value))
    else:self.u32(p+offset,int(value))
  self.u32(0x58ca8c,len(self.connectors))
  library=json.loads((ROOT/'godot/data/reactions.json').read_text())
  self.add_library([dict(name=r['id'],reactants=[dict(name=x['species'],coefficient=x['coefficient']) for x in r['reactants']],products=[dict(name=x['species'],coefficient=x['coefficient']) for x in r['products']],parameters=[r['reaction_heat'],r['condition'],r['reaction_rate'],r['equilibrium_degree_or_constant'],r['equilibrium_mode']],equation_type=r['equation_type'],native_note=r['optional_note_lines'][2]) for r in library])
  # Original RUN writes, separate from explicitly declared zero-heap profile.
  for p in self.vessels:
   self.f64(p+0x3cc8,0);self.f64(p+0x4318,0)
   for j in range(self.u32(p+0x104)):self.f64(p+0x3cd8+8*j,0);self.f64(p+0x3ff8+8*j,0)
  for p in self.connectors:self.f64(p+0x70,0);self.u32(p+0x78,0)
  self.call(0x46c894,b'');self.call(0x48e9b4,b'');self.call(0x4624d8,b'');self.render()
 def render(self):
  for i,p in enumerate(self.vessels):
   typ=self.u32(p+8)
   if 100<typ<300:
    self.f64(p+0x30,0)
    self.call(0x471650,struct.pack('<II',self.u32(p+0xfc),i))
 def capture_frame(self):
  result=[]
  for i,p in enumerate(self.vessels):
   s=self.snapshot(i);s['height']=self.f64(p+0x30);s['gas_3cc0']=self.f64(p+0x3cc0);s['solid_4318']=self.f64(p+0x4318)
   s['solid_3cd8']={name:self.f64(p+0x3cd8+8*j) for j,name in enumerate(s['contents'])}
   s['solid_3ff8']={name:self.f64(p+0x3ff8+8*j) for j,name in enumerate(s['contents'])}
   s['heating']=self.u32(p+0xa0);s['ignition']=self.u32(p+0x9c);s['liquid_color']=self.u32(p+0x3cd0)
   s['reaction_names']=[self.text_at(self.u32(p+0xf24+0xe8*j)) for j in range(self.u32(p+0xf18))]
   s['bits']={key:({n:bits(v) for n,v in value.items()} if isinstance(value,dict) else bits(value)) for key,value in s.items() if key not in ['heating','ignition','liquid_color','reaction_names']}
   result.append(s)
  return result
 def run_frames(self,doc):
  stage='setup'
  try:
   self.setup(doc);frames=[];stacks=[];start=self.capture_frame()
   self.f64(0x5636d4,0.02)
   for frame in range(5):
    for entry in [0x470060,0x48e418,0x4849fc]:stage=hex(entry);self.call(entry,b'')
    for i,p in enumerate(self.vessels):
     if self.u32(p+0x18)==0:stage='0046c84c';self.call(0x46c84c,struct.pack('<I',i))
    for entry in [0x4624d8,0x46ec50,0x46d414,0x46f704,0x4624d8]:stage=hex(entry);self.call(entry,b'')
    stacks.append(self.transport_stack_reads.copy());self.render();frames.append(self.capture_frame())
   return {'name':doc['name'],'fixture_path':doc['fixture'],'status':'executed','start':start,'frames':frames,'stack_reads':self.transport_stack_reads,'stack_reads_by_frame':stacks,'boundaries':sorted(set(self.boundary_calls))}
  except Exception as error:return {'name':doc['name'],'status':'unresolved','stage':stage,'error':str(error),'recent':self.recent}

def main():
 docs=json.loads((ROOT/'godot/data/examples.json').read_text());cases=[]
 for d in docs:
  case=FrameOracle().run_frames(d);cases.append(case);print(d['name'],case['status'],case.get('stage',''),case.get('error',''),flush=True)
 result={'binary_sha256':EXPECTED,'profile':'Explicit zero numeric heap slots before original cold loader/RUN; not production allocator semantics','scope':'Full original physics, native liquid scalar refresh; excludes program/binding/control callbacks','delta_bits':bits(0.02),'cases':cases}
 (ROOT/'godot/tests/fixtures/original_frames.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n')
 print(json.dumps({'cases':len(cases),'executed':sum(c['status']=='executed' for c in cases),'failures':[(c['name'],c.get('stage'),c.get('error')) for c in cases if c['status']!='executed']},ensure_ascii=False))
if __name__=='__main__':main()
