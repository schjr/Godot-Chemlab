"""Original48E9B4 conversion/store and43DE5C first-Run sequence evidence."""
import json,struct
from original_gasflow_oracle import GasOracle
from original_x86_oracle import ROOT,EXPECTED
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EBP

def bits(v):return struct.pack('<d',v).hex()
class OrderOracle(GasOracle):
 def __init__(self):super().__init__();self.operands=[]
 def on_instruction(self,uc,address,size,unused):
  if address==0x48ebcc:
   frame=uc.reg_read(UC_X86_REG_EBP);self.operands.append(dict(free_volume_bits=bits(self.f64(frame-0x54)),existing_gas_volume_bits=bits(self.f64(frame-0x4c)),stored_difference_bits=bits(self.f64(frame-0x5c))))
  super().on_instruction(uc,address,size,unused)
 def convert(self,capacity,contents):
  self.vessels.clear();self.operands=[];i=self.add_vessel(contents,20,capacity,{})
  p=self.vessels[i];self.u32(p+8,204);self.u32(p+0xc,4);self.u32(0x58779c,1)
  before=self.snapshot(i);self.call(0x48e9b4,b'');after=self.snapshot(i)
  return dict(capacity_bits=bits(capacity),contents_bits={s:bits(n) for s,n in contents.items()},operands=self.operands.copy(),after_bits={k:{s:bits(n) for s,n in after[k].items()} for k in ['contents','masses','volumes']},gas_aggregate_bits=bits(after['gas_volume']))
class RunOracle(OrderOracle):
 def __init__(self):
  super().__init__();self.events=[];self.form=self.alloc(0x50000)
  vt=self.alloc(0x60);self.u32(vt+0x5c,0x8000200)
  for off in [0x320,0x324,0x328,0x400,0x404]:p=self.alloc(4);self.u32(p,vt);self.u32(self.form+off,p)
  for a in [0x505524,0x4d38b8,0x527f18,0x8000200]:self.hooks[a]=lambda:self.ret()
  self.hooks[0x53d180]=lambda:self.ret(140)
  self.hooks[0x42dc3c]=lambda:self.save_boundary()
  self.hooks[0x43f7bc]=self.refresh_boundary
 def save_boundary(self):self.events.append('42DC3C save-boundary');self.ret()
 def refresh_boundary(self):
  self.events.append('43F7BC stopped refresh-boundary');context=self.uc.context_save();stack=bytes(self.uc.mem_read(0x90f0000,0x10000))
  self.call(0x4624d8,b'');self.uc.mem_write(0x90f0000,stack);self.uc.context_restore(context);self.ret()
 def on_instruction(self,uc,address,size,unused):
  if hasattr(self,'events') and address in [0x4624d8,0x6c894+0x400000,0x48e9b4]:self.events.append(f'{address:08X}')
  super().on_instruction(uc,address,size,unused)
 def run(self):
  self.vessels.clear();i=self.add_vessel({},20,4,{})
  self.u32(self.vessels[i]+8,204);self.u32(self.vessels[i]+0xc,4);self.u32(0x58779c,1)
  self.u32(0x58ca8c,0);self.uc.mem_write(self.form+0xe1b,b'\0');self.u32(0x57a730,0);self.events=[];self.operands=[]
  self.uc.reg_write(UC_X86_REG_EAX,self.form);self.call(0x43de5c,b'');after=self.snapshot(i)
  return dict(first_run_backup_flag=0,declared_clock=140,events=self.events.copy(),run_flag=self.u32(0x57a6f8),after_bits={k:{s:bits(n) for s,n in after[k].items()} for k in ['contents','masses','volumes']},aggregate_bits={k:bits(after[k]) for k in ['liquid_volume','gas_moles','gas_volume']})
def main():
 cases=[]
 for cap,contents in [(2.,{}),(4.,{}),(27.34703538773724,{}),(110.,{}),(30.694220260404236,{'O2(气体)':0.00027610799525626384}),(4.,{'O2(气体)':1e-20})]:cases.append(OrderOracle().convert(cap,contents))
 run=RunOracle().run();print('Run sequence',run)
 o=GasOracle();constants={f'{a:08X}':bytes(o.uc.mem_read(a,n)).hex() for a,n in [(0x4624b0,8),(0x4624b8,4),(0x48ec70,8),(0x48ec78,4),(0x48ec7c,10),(0x48ec88,10),(0x46f6d0,8),(0x46f6d8,4),(0x46f6ec,10),(0x46f6f8,10)]}
 out=dict(source_sha256=EXPECTED,scope='PC64 nearest; actual PE conversion/parser/arithmetic; managed strings, UI enabled/repaint, save and stopped graphics are explicit boundaries; stopped-boundary4624D8 executes original instructions; first-run backup flag0 only, no production heap assumption',constants=constants,cases=cases,run=run)
 (ROOT/'godot/tests/fixtures/original_gas_operand_order.json').write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n');print(len(cases),'native conversions + actual first-Run sequence')
if __name__=='__main__':main()
