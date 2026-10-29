"""Trace native numeric slot reads/writes with an explicit validity shadow.

Unicorn's physical mapping is zero here only to explore the fixture branch.
Those bytes are NOT considered initialized. Native instructions, explicit
loader amounts, and source-proved Run writes alone set shadow validity.
This is bounded path evidence, not a production heap profile.
"""
import json
import struct
import bisect
from unicorn import UC_HOOK_MEM_READ,UC_HOOK_MEM_WRITE
from unicorn.x86_const import UC_X86_REG_EIP
from original_particle_frames_oracle import ParticleFramesOracle
from original_workflow_oracle import tick
from original_x86_oracle import ROOT,EXPECTED

FIELDS={0x298:("mass",800),0x5b8:("volume",800),0x8d8:("moles",800),0x3cd8:("reserved_solid",800),0x3ff8:("solid_delta",800),
        0x3cc0:("gas_last_delta",8),0x3cc8:("bubble_accumulator",8),0x4318:("reserved_solid_total",8),0x4338:("solid_volume_total",8)}

class ReadAudit(ParticleFramesOracle):
 def __init__(self):
  self.defined=set();self.reads={};self.stage="construct boundary";self.region_count=-1;self.regions=[];self.region_starts=[]
  super().__init__()
  self.uc.hook_add(UC_HOOK_MEM_READ,self.memory_read)
  self.uc.hook_add(UC_HOOK_MEM_WRITE,self.memory_write)
 def tracked(self,address,size):
  if self.region_count!=len(self.vessels):
   self.regions=sorted((p+offset,p+offset+length,index,p,offset,field) for index,p in enumerate(self.vessels) for offset,(field,length) in FIELDS.items())
   self.region_starts=[x[0] for x in self.regions];self.region_count=len(self.vessels)
  index=bisect.bisect_right(self.region_starts,address)-1
  if index>=0:
   start,end,vessel,p,offset,field=self.regions[index]
   if start<=address<end:return vessel,p,offset,field,address,min(address+size,end)
  return None
 def memory_write(self,uc,access,address,size,value,unused):
  match=self.tracked(address,size)
  if match:self.defined.update(range(match[4],match[5]))
 def memory_read(self,uc,access,address,size,value,unused):
  match=self.tracked(address,size)
  if not match:return
  index,p,offset,field,start,end=match
  missing=[a for a in range(start,end) if a not in self.defined]
  if not missing:return
  slot=(start-p-offset)//8
  pc=uc.reg_read(UC_X86_REG_EIP)
  key=(index,field,slot,pc)
  if key not in self.reads:
   count=self.u32(p+0x104)
   name=self.text_at(self.u32(p+0x108+slot*4)) if FIELDS[offset][1]==800 and slot<count else None
   self.reads[key]={"vessel":index,"field":field,"slot":slot,"species":name,"pc":hex(pc),"stage":self.stage,"unwritten_bytes":len(missing)}
 def f64(self,address,value=None):
  if value is not None:
   match=self.tracked(address,8)
   if match:self.defined.update(range(match[4],match[5]))
  return super().f64(address,value)
 def add_vessel(self,contents,temperature=20.0,capacity=100.0,volume_cache=None):
  # Source CEM loader writes names/moles; no artificial nonphysical volume write.
  p=self.alloc(0x5000);index=len(self.vessels);self.vessels.append(p);self.u32(0x585850+index*4,p)
  self.u32(p+0x104,len(contents));self.f64(p+0x88,temperature);self.f64(p+0x28,capacity)
  for slot,(species,amount) in enumerate(contents.items()):
   self.u32(p+0x108+4*slot,self.string(species));self.f64(p+0x8d8+8*slot,float(amount))
  self.call(0x461e54,struct.pack("<I",index))
  return index
 def call(self,address,args):
  previous=self.stage;self.stage=hex(address)
  try:return super().call(address,args)
  finally:self.stage=previous
 def render_particles(self,*args,**kwargs):
  previous=self.stage;self.stage="40A4B8 particle slices"
  try:return super().render_particles(*args,**kwargs)
  finally:self.stage=previous

def main():
 docs=json.loads((ROOT/"godot/data/examples.json").read_text());cases=[]
 for doc in docs:
  oracle=ReadAudit();status="executed";error=None
  try:
   oracle.setup(doc);oracle.create_pools();oracle.render_particles()
   for _ in range(2):tick(oracle)
  except Exception as exc:status="unresolved";error=str(exc)
  cases.append({"name":doc["name"],"status":status,"error":error,"reads_before_write":list(oracle.reads.values())})
  print(doc["name"],status,len(oracle.reads),flush=True)
 report={"source_sha256":EXPECTED,"scope":"All28 CEM native setup and two physics+particle frames; five numeric arrays plus gasdelta/bubbleaccumulator/reservedsolidtotal/solidvolume scalars. Loader/Run explicit writers hosted according to retained source; classes/presentation/TLS hosted as existing oracle. Unknown physical bytes zero solely for bounded branch exploration, never marked valid.","limitations":["No original allocator executed","Branches dependent on unwritten values can differ under another heap","No live RNG/bitmap profile claim","No complete interaction/program/UI path coverage"],"cases":cases}
 out=ROOT/"godot/docs/original_logic/allocation_startup_reads.json"
 out.write_text(json.dumps(report,ensure_ascii=False,indent=2)+"\n")
 print("Evidence",out)

if __name__=="__main__":main()
