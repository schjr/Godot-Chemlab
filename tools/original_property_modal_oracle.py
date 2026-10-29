"""Actual417750 modal caller ordering with declared VCL ownership boundaries."""
import json
from original_program_oracle import ProgramOracle
from original_x86_oracle import ROOT,EXPECTED
from unicorn.x86_const import UC_X86_REG_EAX
class ModalOracle(ProgramOracle):
 def __init__(self):
  super().__init__();self.events=[];self.property=self.alloc(0x400);vt=self.alloc(0xe0)+4;self.u32(self.property,vt);self.u32(vt+0xd8,0x8000200);self.u32(vt-4,0x8000210);holder=self.alloc(4);self.u32(0x5799cc,holder)
  self.hooks.update({0x49d310:self.create,0x8000200:lambda:self.record('modal'),0x8000210:lambda:self.record('destroy'),0x43f7bc:lambda:self.record('caller43F7BC'),0x515d0c:lambda:self.ret()})
 def create(self):self.events.append('create');self.ret(self.property)
 def record(self,event):self.events.append(event);self.ret()
 def case(self,run,typ):
  self.events=[];self.u32(0x57a6f8,run);self.u32(0x57a730,typ);self.u32(0x57a738,0);self.uc.reg_write(UC_X86_REG_EAX,self.form);self.call(0x417750,b'');return dict(run=run,type=typ,events=self.events.copy())
def main():
 o=ModalOracle();cases=[o.case(run,typ) for run in [0,1,2] for typ in [100,101,102,204,299]]
 (ROOT/'godot/tests/fixtures/original_property_modal.json').write_text(json.dumps(dict(source_sha256=EXPECTED,entry='00417750',boundaries='VCL constructor/ShowModal/destructor recorded, stopped caller43F7BC recorded; original dispatcher branch/order executes',cases=cases),indent=2)+'\n');print(len(cases),'native modal caller cases')
if __name__=='__main__':main()
