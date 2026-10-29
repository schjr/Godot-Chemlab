"""Fresh actual43DE5C numeric Run corpus; no complete VCL/allocator claim."""
import hashlib,json,struct
from unicorn import UC_HOOK_MEM_WRITE
from unicorn.x86_const import UC_X86_REG_EAX
from original_gas_operand_order_oracle import RunOracle
from original_liquid_oracle import LiquidOracle
from original_x86_oracle import ROOT,EXPECTED
ARRAYS={'contents':0x8d8,'native_species_mass':0x298,'native_species_volume':0x5b8,'solid_3cd8':0x3cd8,'solid_3ff8':0x3ff8}
SCALARS={'native_liquid_volume':0x4320,'native_gas_moles':0x4328,'native_gas_volume':0x4330,'native_solid_volume':0x4338,'native_particle_3cc8':0x3cc8,'solid_4318':0x4318,'native_pressure':0xa8}
class CorpusOracle(RunOracle):
 def __init__(self):
  super().__init__();self.record_writes=False;self.writes=[];self.stage='input';self.uc.hook_add(UC_HOOK_MEM_WRITE,self.write)
  self.rectangles=[]
  self.hooks.update({0x4e4158:self.presentation_property,0x4e3e50:self.presentation_property,0x4e4274:self.presentation_property,0x4e4744:self.rectangle})
  for i,record in enumerate(self.catalog):self.u32(self.u32(0x57bc08+i*4)+0x28,record['color_integer'])
  self.u32(0x57a748,self.species['H2O(液体)']['color_integer'])
 def presentation_property(self):LiquidOracle.presentation_property(self)
 def rectangle(self):LiquidOracle.rectangle(self)
 def refresh_boundary(self):
  self.events.append('43F7BC stopped refresh-boundary');context=self.uc.context_save();stack=bytes(self.uc.mem_read(0x90f0000,0x10000))
  self.call(0x4624d8,b'')
  for index,p in enumerate(self.vessels):
   if 100<self.u32(p+8)<300:
    self.f64(p+0x30,0);self.call(0x471650,struct.pack('<II',self.u32(p+0xfc),index))
  self.uc.mem_write(0x90f0000,stack);self.uc.context_restore(context);self.ret()
 def on_instruction(self,uc,address,size,unused):
  if self.record_writes and address in [0x43de5c,0x43f7bc,0x4624d8,0x46c894,0x48e9b4]:self.stage=f'{address:08X}'
  super().on_instruction(uc,address,size,unused)
 def write(self,uc,access,address,size,value,unused):
  if not self.record_writes:return
  for index,p in enumerate(self.vessels):
   for field,offset in ARRAYS.items():
    if p+offset<=address and address+size<=p+offset+800:self.writes.append([self.stage,index,field,(address-p-offset)//8,size]);return
 def setup_inputs(self,doc):
  self.vessels.clear();self.connectors=[]
  sprites=json.loads((ROOT/'godot/data/sprites.json').read_text())
  kinds={101:'sg0',102:'sb100',103:'zxp100',104:'ydsp100',105:'pdsp100',106:'blg',107:'jqp',108:'uxg',121:'zfm_50',201:'gkp',202:'xkp',204:'jtdg_2',207:'ssddg',208:'jsddg',209:'ld',210:'cjld',211:'fyld',212:'shuic'}
  for a in doc['apparatus']:
   index=self.add_vessel({c['name']:c['moles'] for c in a['chemicals']},a['temperature'],a['capacity']);p=self.vessels[index]
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
   if 100<a['type_id']<300:
    assert k in sprites,(a['type_id'],k)
    self.u32(p+0xfc,self.bitmap(*sprites[k]['size']))
   for r in a['reactions']:self.add_reaction(index,r)
   count=len(a['chemicals'])
   for slot in range(100):
    # Exactly representable nonzero dyadic cells, explicit isolated input.
    for field,off in ARRAYS.items():
     value={'contents':0.125+slot/1024,'native_species_mass':0.25+slot/512,'native_species_volume':0.375+slot/256,'solid_3cd8':0.5+slot/128,'solid_3ff8':0.625+slot/64}[field]
     if slot<count and field=='contents':value=a['chemicals'][slot]['moles']
     if slot<count and field=='native_species_mass':value=a['chemicals'][slot]['mass']
     self.f64(p+off+slot*8,value)
   self.f64(p+0x3cc8,13.25);self.f64(p+0x4318,17.5)
  self.u32(0x58779c,len(self.vessels));self.f64(0x5636c0,1)
  offsets=[0,4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,64,68,72,76,80,84,88,96,104]
  for index,c in enumerate(doc['connectors']):
   p=self.alloc(0x80);self.connectors.append(p);self.u32(0x58baec+index*4,p)
   for field,(off,value) in enumerate(zip(offsets,c['metadata'])):
    if field in [1,11,14]:self.u32(p+off,self.string(value))
    elif field>=22:self.f64(p+off,float(value))
    else:self.u32(p+off,int(value))
   self.f64(p+0x70,19.75);self.u32(p+0x78,2)
  self.u32(0x58ca8c,len(self.connectors))
  library=json.loads((ROOT/'godot/data/reactions.json').read_text())
  self.add_library([dict(name=r['id'],reactants=[dict(name=t['species'],coefficient=t['coefficient']) for t in r['reactants']],products=[dict(name=t['species'],coefficient=t['coefficient']) for t in r['products']],parameters=[r['reaction_heat'],r['condition'],r['reaction_rate'],r['equilibrium_degree_or_constant'],r['equilibrium_mode']],equation_type=r['equation_type'],native_note=r['optional_note_lines'][2]) for r in library])
  self.uc.mem_write(self.form+0xe1b,b'\0');self.u32(0x57a730,0);self.events=[];self.operands=[]
 def snapshot_numeric(self):
  result=[]
  for p in self.vessels:
   count=self.u32(p+0x104)
   result.append(dict(names=[self.text_at(self.u32(p+0x108+slot*4)) for slot in range(count)],arrays={field:bytes(self.uc.mem_read(p+off,800)).hex() for field,off in ARRAYS.items()},scalars={field:bytes(self.uc.mem_read(p+off,8)).hex() for field,off in SCALARS.items()},reaction_names=[self.text_at(self.u32(p+0xf24+slot*0xe8)) for slot in range(self.u32(p+0xf18))]))
  return result
 def case(self,doc):
  try:
   self.setup_inputs(doc);before=self.snapshot_numeric();self.writes=[];self.record_writes=True
   self.uc.reg_write(UC_X86_REG_EAX,self.form);self.call(0x43de5c,b'');self.record_writes=False;after=self.snapshot_numeric()
   written={}
   for stage,index,field,slot,size in self.writes:written.setdefault(f'{stage}:{index}:{field}',set()).add(slot)
   return dict(name=doc['name'],fixture_path=doc['fixture'],status='executed',before=before,after=after,events=self.events,run_flag=self.u32(0x57a6f8),writes={key:sorted(slots) for key,slots in written.items()},connector_after=[dict(amount_bits=bytes(self.uc.mem_read(p+0x70,8)).hex(),direction=self.u32(p+0x78)) for p in self.connectors])
  except Exception as e:return dict(name=doc['name'],fixture_path=doc['fixture'],status='unresolved',stage=self.stage,error=str(e),recent=self.recent)
def main():
 docs=json.loads((ROOT/'godot/data/examples.json').read_text());cases=[]
 for doc in docs:
  result=CorpusOracle().case(doc);cases.append(result);print(doc['name'],result['status'],result.get('error',''),flush=True)
 out=dict(source_sha256=EXPECTED,entry='0043DE5C',scope='First Run flag0; original numeric writes,4624D8,471650,46C894,48E9B4 execute; original bitmap dimensions are explicit inputs; VCL enabled/repaint,43F7BC chart/association/raster and42DC3C save are declared boundaries. NOT a complete VCL or live allocation reference.',allocation_profile='All100 cells explicitly defined with nonzero exactly representable dyadic sentinel values; original active CEM amount/mass inputs preserved. No universal heap initialization inference.',dataset_sha256=hashlib.sha256((ROOT/'godot/data/examples.json').read_bytes()).hexdigest(),cases=cases)
 (ROOT/'godot/tests/fixtures/original_run_corpus.json').write_text(json.dumps(out,ensure_ascii=False,separators=(',',':'))+'\n')
 print('Original Run corpus:',sum(c['status']=='executed' for c in cases),'/',len(cases))
if __name__=='__main__':main()
