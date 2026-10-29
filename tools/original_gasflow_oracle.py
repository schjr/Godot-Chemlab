"""Execute original air/open-gas instructions with declared VCL bitmap dimensions."""
from original_oneway_oracle import ReactionOracle
from original_actions_oracle import ActionsOracle,bits
from original_x86_oracle import ROOT,EXPECTED
import json,struct

class GasOracle(ReactionOracle,ActionsOracle):
 def __init__(self):
  super().__init__();self.recent=[];self.transport_excess_written=False;self.transport_stack_reads=[]
  self.hooks[0x540f38]=self.selector_to_string
  self.hooks[0x5412f8]=self.selector_from_string
 def on_instruction(self,uc,address,size,unused):
  if address==0x46f704:self.transport_excess_written=False;self.transport_stack_reads=[]
  if address==0x46fada:self.transport_excess_written=True
  if address==0x46fb18 and not self.transport_excess_written:
   from unicorn.x86_const import UC_X86_REG_EBP
   self.transport_stack_reads.append(bits(self.f64(uc.reg_read(UC_X86_REG_EBP)-0x7c)))
  self.recent.append((hex(address),bytes(uc.mem_read(address,size)).hex()))
  self.recent=self.recent[-30:]
  super().on_instruction(uc,address,size,unused)
 def selector_to_string(self):
  from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX
  dst=self.uc.reg_read(UC_X86_REG_EAX);value=self.uc.reg_read(UC_X86_REG_EDX)
  if value not in [0,1,2]:raise RuntimeError('Unverified selector formatting boundary')
  self.u32(dst,self.string(str(value)));self.ret(dst)
 def selector_from_string(self):
  from unicorn.x86_const import UC_X86_REG_EAX
  text=self.text_at(self.u32(self.uc.reg_read(UC_X86_REG_EAX)))
  if text not in ['0','1','2']:raise RuntimeError('Unverified selector parsing boundary')
  self.ret(int(text))
 def get_width(self):
  from unicorn.x86_const import UC_X86_REG_EAX
  p=self.uc.reg_read(UC_X86_REG_EAX)
  if not self.bitmaps[p].get('geometry_known',True):raise RuntimeError('Original bitmap width unresolved; no placeholder substitution')
  super().get_width()
 def get_height(self):
  from unicorn.x86_const import UC_X86_REG_EAX
  p=self.uc.reg_read(UC_X86_REG_EAX)
  if not self.bitmaps[p].get('geometry_known',True):raise RuntimeError('Original bitmap height unresolved; no placeholder substitution')
  super().get_height()
 def case(self,case):
  self.vessels.clear();self.boundary_calls.clear();self.transfers.clear()
  for v in case['vessels']:
   index=self.add_vessel(v['contents'],v.get('temperature',20),v['capacity'],v.get('volume_cache',{}));p=self.vessels[index]
   self.u32(p+4,self.string(v.get('name','v'+str(index))));self.u32(p+8,v['type']);self.u32(p+0x18,v.get('orientation',0));self.u32(p+0x38,v.get('mouth',0));self.u32(p+0x10,v.get('x',0));self.u32(p+0x14,v.get('y',0));self.f64(p+0x30,v.get('liquid_height',0));bitmap=self.bitmap(v.get('width',40),v.get('height',60));self.bitmaps[bitmap]['geometry_known']=not v.get('declared_bitmap_source','').startswith('unresolved');self.u32(p+0xfc,bitmap)
  self.u32(0x58779c,len(self.vessels))
  self.connectors=[]
  offsets=[0,4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,64,68,72,76,80,84,88,96,104]
  self.u32(0x58ca8c,len(case.get('connectors',[])))
  for i,c in enumerate(case.get('connectors',[])):
   p=self.alloc(0x80);self.connectors.append(p);self.u32(0x58baec+4*i,p)
   for field,(offset,value) in enumerate(zip(offsets,c['metadata'])):
    if field in [1,11,14]:self.u32(p+offset,self.string(value))
    elif field>=22:self.f64(p+offset,float(value))
    else:self.u32(p+offset,int(value))
  def snapshot():
   return [{**self.snapshot(i),'bits':{table:{s:bits(value) for s,value in self.snapshot(i)[table].items()} for table in ['contents','masses','volumes']},'scalar_bits':{s:bits(self.snapshot(i)[s]) for s in ['liquid_volume','solid_volume','gas_moles','gas_volume','pressure']}} for i in range(len(self.vessels))]
  before=snapshot()
  try:
   self.call(0x48e9b4,b'');after_air=snapshot()
   self.call(0x6ec50+0x400000,b'');after=snapshot()
   self.call(0x4624d8,b'')
   self.call(0x46d414,b'')
   network=[]
   for i in range(self.u32(0x590ef4)):
    p=0x58fc34+i*0x30
    network.append(dict(mode=struct.unpack('<i',self.uc.mem_read(p,4))[0],source_name=self.text_at(self.u32(p+4)),target_name=self.text_at(self.u32(p+8)),source_connector=self.text_at(self.u32(p+12)),target_connector=self.text_at(self.u32(p+16)),source_selector=self.u32(p+20),target_selector=self.u32(p+24),amount_bits=bits(self.f64(p+32))))
   before_remaining=snapshot()
   self.call(0x46f704,b'')
   after_remaining=snapshot()
   connector_states=[{'amount_bits':bits(self.f64(p+0x70)),'direction':self.u32(p+0x78)} for p in self.connectors]
   return {**case,'status':'executed','before':before,'after_air':after_air,'after':after,'before_remaining':before_remaining,'after_remaining':after_remaining,'connector_states':connector_states,'uninitialized_transport_stack_reads':self.transport_stack_reads,'network':network,'visited':[self.u32(p+0x4c) for p in self.connectors],'boundaries':sorted(set(self.boundary_calls))}
  except Exception as e:return {**case,'status':'unresolved','error':str(e),'recent':self.recent,'boundaries':sorted(set(self.boundary_calls))}

def main():
 examples=json.loads((ROOT/'godot/data/examples.json').read_text());sprites=json.loads((ROOT/'godot/data/sprites.json').read_text())
 kinds={101:'sg0',102:'sb100',103:'zxp100',104:'ydsp100',105:'pdsp100',106:'blg',107:'jqp',108:'uxg',121:'zfm_50',201:'gkp',202:'xkp',204:'jtdg_2',207:'ssddg',208:'jsddg',209:'ld',210:'cjld',211:'fyld',212:'shuic',301:'tiejt0',302:'jjd',303:'wendj'}
 def vessel(a):
  k=kinds.get(a['type_id']);size=abs(float(a['metadata'][3]))
  if a['type_id']==102:k='sb500' if size>=500 else 'sb200' if size>=200 else 'sb100'
  if a['type_id']==103:k='zxp250' if size>=250 else 'zxp100'
  if a['type_id']==101:k='sg97' if size>=90 else 'sg45' if size>=40 else 'sg0'
  w,h=sprites[k]['size'] if k in sprites else [1,1]
  return dict(name=a['name'],type=a['type_id'],capacity=a['capacity'],temperature=a['temperature'],orientation=int(a['metadata'][6]),mouth=int(a['metadata'][10]),x=int(a['x']),y=int(a['y']),width=w,height=h,liquid_height=float(a['metadata'][9]),contents={c['name']:c['moles'] for c in a['chemicals']},volume_cache={c['name']:0.0 for c in a['chemicals']},declared_bitmap_source=sprites.get(k,{}).get('source','unresolved-not-used-in-open-branch'))
 cases=[]
 for e in examples:cases.append(GasOracle().case({'name':e['name'],'vessels':[vessel(a) for a in e['apparatus']],'connectors':e.get('connectors',[])}))
 # Explicit original gas-operand variations, not authored expected chemistry.
 for gas in ['H2(气体)','CO2(气体)','Cl2(气体)','O2(气体)']:
  for orientation in [0,1]:
   v=dict(type=107,capacity=100.0,temperature=20,orientation=orientation,mouth=0,x=100,y=100,width=50,height=82,liquid_height=0.0,contents={'H2O(液体)':0.5,gas:0.005},volume_cache={})
   cases.append(GasOracle().case({'name':gas+f' / orientation{orientation}','vessels':[v]}))
 # Real inverted-jar/trough geometry branch from stored hydrogen example.
 source=next(e for e in examples if e['name']=='制取与收集氢气');vs=[vessel(a) for a in source['apparatus']]
 vs[-1]['contents']['H2(气体)']=0.003
 cases.append(GasOracle().case({'name':'制取与收集氢气 / explicit gas operand','vessels':vs}))
 # Closed source has pressure; direct connection produces two native rows.
 def direct_record(name,source,target,typ1,typ2,y1,y2):
  metadata=['1',name,'100',str(y1),'200',str(y2),'0','0','0','0','0',source,str(typ1),'0',target,str(typ2),'0','0','0','0','0','0','0','0','0']
  return {'metadata':metadata}
 source=dict(name='source',type=103,capacity=100.0,temperature=20,orientation=0,mouth=1,x=100,y=100,width=50,height=80,liquid_height=0.0,contents={'H2(气体)':0.008},volume_cache={})
 target=dict(name='target',type=107,capacity=100.0,temperature=20,orientation=0,mouth=0,x=200,y=100,width=50,height=80,liquid_height=0.0,contents={},volume_cache={})
 cases.append(GasOracle().case({'name':'direct closed gas source / native row sharing','vessels':[source,target],'connectors':[direct_record('tube','source','target',103,107,80,80)]}))
 # Native submerged outlet bubble counter and empty-outlet overcapacity paths.
 target_wet={**target,'mouth':1,'liquid_height':30.0,'contents':{'H2O(液体)':0.5}}
 cases.append(GasOracle().case({'name':'direct submerged outlet / native bubble counter','vessels':[source,target_wet],'connectors':[direct_record('tube','source','target',103,107,80,130)]}))
 cases.append(GasOracle().case({'name':'closed excess gas / empty outlet','vessels':[source],'connectors':[direct_record('tube','source','',103,0,80,80)]}))
 result={'binary_sha256':EXPECTED,'entries':['0048E9B4','0046EC50','0046D414','0046F704'],'fixture_volume_seed':'Explicit zero input caches; not a constructor-zero claim','bitmap_boundary':'Declared BMP pixel dimensions; unresolved wood dimensions are 1x1 carrier placeholders and are not established original geometry','constants':{hex(a):bytes(GasOracle().uc.mem_read(a,10)).hex() for a in [0x48ec7c,0x48ec88,0x46f6ec,0x46f6f8]},'cases':cases}
 path=ROOT/'godot/tests/fixtures/original_gasflow.json';path.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n')
 print(json.dumps({'cases':len(cases),'executed':sum(c['status']=='executed' for c in cases),'failures':[(c['name'],c.get('error')) for c in cases if c['status']!='executed']},ensure_ascii=False))
if __name__=='__main__':main()
