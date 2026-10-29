"""Execute shipped FUN_00462c18 with explicit reaction records and smart=false.
Hosted boundaries are copied from the verified original string helper signatures;
no chemistry arithmetic is substituted. Failure is recorded, not approximated.
"""
from original_x86_oracle import OriginalOracle,ROOT,EXPECTED
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX,UC_X86_REG_ESP,UC_X86_REG_ST0
import json,struct

class ReactionOracle(OriginalOracle):
 def __init__(self):
  super().__init__()
  self.hooks[0x5410e4]=self.unequal_string
  self.hooks[0x402908]=self.string_ptr
 def unequal_string(self):
  a=self.u32(self.uc.reg_read(UC_X86_REG_EAX));b=self.u32(self.uc.reg_read(UC_X86_REG_EDX))
  self.ret(int(self.bytes_at(a)!=self.bytes_at(b)))
 def string_ptr(self):
  p=self.u32(self.uc.reg_read(UC_X86_REG_EAX))
  self.ret(p or self.string(b''))
 def add_reaction(self,index,reaction):
  p=self.vessels[index];n=self.u32(p+0xf18);r=p+0xf20+n*0xe8
  self.u32(p+0xf18,n+1);self.populate_record(r,reaction)
 def populate_record(self,r,reaction):
  self.u32(r+4,self.string(reaction['name']))
  self.u32(r+8,len(reaction['reactants']));self.u32(r+12,len(reaction['products']))
  for side,base,coeff in [('reactants',0x10,0x60),('products',0x38,0x88)]:
   for i,item in enumerate(reaction[side]):
    self.u32(r+base+4*i,self.string(item['name']));self.u32(r+coeff+4*i,item['coefficient'])
  params=reaction['parameters']
  self.f64(r+0xb0,float(params[0]));self.u32(r+0xb8,self.string(params[1]));self.f64(r+0xc0,float(params[2]));self.f64(r+0xc8,float(params[3]));self.u32(r+0xd0,self.string(params[4]))
  for off in [0xd4,0xd8,0xdc,0xe0]:self.u32(r+off,0)
  if reaction.get('equation_type'):self.u32(r+0xd4,self.string(reaction['equation_type']))
  if reaction.get('native_note'):self.u32(r+0xe0,self.string(reaction['native_note']))
 def add_library(self,library):
  self.u32(0x58584c,len(library))
  for i,reaction in enumerate(library):
   r=self.alloc(0xe8);self.u32(0x580a2c+4*i,r);self.populate_record(r,reaction)
 def run(self,fixture):
  reaction=fixture['reaction'];contents=fixture['contents'].copy()
  for side in ['reactants','products']:
   for item in reaction.get(side,[]):contents.setdefault(item['name'],0.0)
  index=self.add_vessel(contents,fixture.get('temperature',20.0),100.0,fixture.get('volume_cache',{}))
  p=self.vessels[index];self.u32(p+0xa4,int(fixture.get('smart_flag',0)));self.u32(p+0x3c70,int(fixture.get('ion_flag',0)));self.u32(p+0xa0,fixture.get('heating_flag',0));self.u32(p+0x3c78,fixture.get('speed_setting',10));self.f64(p+0x30,fixture.get('liquid_height',20));self.f64(0x5636d4,fixture.get('delta_seconds',0.1))
  if reaction:self.add_reaction(index,reaction)
  self.add_library(fixture.get('library',[]))
  before=self.snapshot(index)
  before_counters={'solid_3cd8':{s:struct.pack('<d',self.f64(p+0x3cd8+8*i)).hex() for i,s in enumerate(before['contents'])},'solid_3ff8':{s:struct.pack('<d',self.f64(p+0x3ff8+8*i)).hex() for i,s in enumerate(before['contents'])}}
  try:
   self.call(0x462c18,struct.pack('<I',index))
   return {**fixture,'status':'executed','before':before,'before_counter_bits':before_counters,'before_bits':{table:{key:struct.pack('<d',value).hex() for key,value in before[table].items()} for table in ['contents','volumes']},'after':self.snapshot(index),'after_bits':{key:struct.pack('<d',value).hex() for key,value in self.snapshot(index)['contents'].items()},'gas_3cc0':self.f64(p+0x3cc0),'solid_3cd8':{s:self.f64(p+0x3cd8+8*i) for i,s in enumerate(self.snapshot(index)['contents'])},'solid_3ff8':{s:self.f64(p+0x3ff8+8*i) for i,s in enumerate(self.snapshot(index)['contents'])},'after_reactions':[self.text_at(self.u32(p+0xf24+i*0xe8)) for i in range(self.u32(p+0xf18))],'counter_bits':{'gas_3cc0':struct.pack('<d',self.f64(p+0x3cc0)).hex(),'solid_4318':struct.pack('<d',self.f64(p+0x4318)).hex(),'solid_3cd8':{s:struct.pack('<d',self.f64(p+0x3cd8+8*i)).hex() for i,s in enumerate(self.snapshot(index)['contents'])},'solid_3ff8':{s:struct.pack('<d',self.f64(p+0x3ff8+8*i)).hex() for i,s in enumerate(self.snapshot(index)['contents'])}},'boundaries':sorted(set(self.boundary_calls))}
  except Exception as error:
   return {**fixture,'status':'unresolved','error':str(error),'boundaries':sorted(set(self.boundary_calls))}

def main():
 examples=json.loads((ROOT/'godot/data/examples.json').read_text())
 names=['氢氧化铜与氢氧化铁','铁和盐酸的反应','加热碳酸氢钠','实验室制氧气','强酸与弱酸的电离','水的电离','酸碱中和滴定']
 cases=[]
 for name in names:
  doc=next(e for e in examples if e['name']==name)
  for apparatus in doc['apparatus']:
   for reaction in apparatus['reactions'][:3]:
    fixture={'example':name,'vessel':apparatus['name'],'reaction':reaction,'contents':{c['name']:c['moles'] for c in apparatus['chemicals']},'temperature':apparatus['temperature'],'heating_flag':int(apparatus['metadata'][35]),'speed_setting':int(apparatus['simulation_fields'][2]),'liquid_height':float(apparatus['metadata'][9]),'delta_seconds':0.1,'volume_cache':{c['name']:0.0 for c in apparatus['chemicals']}}
    cases.append(ReactionOracle().run(fixture))
 # Meaningful operands from the original precipitation/dissolution instructions.
 doc=next(e for e in examples if e['name']=='氢氧化铜与氢氧化铁')
 for apparatus in [doc['apparatus'][0],doc['apparatus'][3]]:
  for reaction in apparatus['reactions']:
   contents={c['name']:c['moles'] for c in apparatus['chemicals']}
   for item in reaction['reactants']:
    if item['name'] not in contents or contents[item['name']]==0:
     contents[item['name']]=0.01*int(item['coefficient'])
   fixture={'example':doc['name']+' / explicit native reaction operands','vessel':apparatus['name'],'reaction':reaction,'contents':contents,'temperature':20.0,'heating_flag':0,'speed_setting':10,'liquid_height':float(apparatus['metadata'][9]),'delta_seconds':0.1,'volume_cache':{s:0.0 for s in contents}}
   cases.append(ReactionOracle().run(fixture))
 water=next(e for e in examples if e['name']=='水的电离')['apparatus'][0]
 reaction=water['reactions'][0].copy();reaction['native_note']='水的电离'
 fixture={'example':'水的电离 / explicit copied library note','vessel':water['name'],'reaction':reaction,'contents':{c['name']:c['moles'] for c in water['chemicals']},'temperature':20.0,'heating_flag':0,'speed_setting':10,'liquid_height':float(water['metadata'][9]),'delta_seconds':0.1,'volume_cache':{c['name']:0.0 for c in water['chemicals']}}
 cases.append(ReactionOracle().run(fixture))
 native_library=json.loads((ROOT/'godot/data/reactions.json').read_text())
 def native_record(key):
  original=next(r for r in native_library if r['id']==key)
  return dict(name=key,reactants=[dict(name=x['species'],coefficient=int(x['coefficient'])) for x in original['reactants']],products=[dict(name=x['species'],coefficient=int(x['coefficient'])) for x in original['products']],parameters=[original['reaction_heat'],original['condition'],original['reaction_rate'],original['equilibrium_degree_or_constant'],original['equilibrium_mode']],equation_type=original['equation_type'],native_note=original['optional_note_lines'][2])
 for name,contents,keys,ions in [('smart HCl / ionic flag enabled',{'H2O(液体)':2.2202486678508,'HCl(溶解)':0.02},['方程式197','方程式233'],1),('smart HCl / ionic flag disabled',{'H2O(液体)':2.2202486678508,'HCl(溶解)':0.02},['方程式197','方程式233'],0),('smart copper precipitation',{'H2O(液体)':4.9955595026643,'CuSO4(溶解)':0.02,'NaOH(溶解)':0.005},['方程式19'],0)]:
  fixture={'example':name,'vessel':'explicit native slots','reaction':{},'library':[native_record(key) for key in keys],'contents':contents,'smart_flag':1,'ion_flag':ions,'temperature':20.0,'heating_flag':0,'speed_setting':10,'liquid_height':20.0,'delta_seconds':0.1,'volume_cache':{s:0.0 for s in contents}}
  cases.append(ReactionOracle().run(fixture))
 for name,contents,ions in [('full library / copper dose',{'H2O(液体)':4.9955595026643,'CuSO4(溶解)':0.02,'NaOH(溶解)':0.005},0),('full library / acetic acid',{'H2O(液体)':11.101243321492,'CH3COOH(溶解)':0.02},1)]:
  fixture={'example':name,'vessel':'explicit native slots','reaction':{},'library':[native_record(r['id']) for r in native_library],'contents':contents,'smart_flag':1,'ion_flag':ions,'temperature':20.0,'heating_flag':0,'speed_setting':10,'liquid_height':20.0,'delta_seconds':0.1,'volume_cache':{s:0.0 for s in contents}}
  cases.append(ReactionOracle().run(fixture))
 output={'library_count':len(native_library),'binary_sha256':EXPECTED,'function':'00462c18','smart':False,'constructor_notes':'empty by explicit native416b30/4016e8 construction','volume_seed':'Explicit fixture zero cache; not a universal native allocator claim','cases':cases}
 path=ROOT/'godot/tests/fixtures/original_reactions.json';path.write_text(json.dumps(output,ensure_ascii=False,indent=2)+'\n')
 print(json.dumps({'cases':len(cases),'executed':sum(c['status']=='executed' for c in cases),'failures':[(c['example'],c['reaction'].get('name','smart'),c.get('error')) for c in cases if c['status']!='executed']},ensure_ascii=False))
if __name__=='__main__':main()
