"""Execute4018B0 clocks; physics/presentation callbacks are recorded boundaries."""
import json,struct
from original_program_oracle import ProgramOracle
from original_x86_oracle import ROOT,EXPECTED
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX
from original_controls_dispatch_oracle import DispatchOracle
class ClockOracle(ProgramOracle):
 def __init__(self):
  super().__init__();self.now=0;self.calls=[]
  self.hooks[0x53d180]=lambda:self.ret(self.now)
  for a in [0x470060,0x48e418,0x4849fc,0x4624d8,0x46ec50,0x46d414,0x46f704,0x48c428,0x48d6e0,0x48c758,0x4126dc]:self.hooks[a]=lambda a=a:self.record(a)
  self.hooks[0x4028ec]=lambda:self.ret(0);self.hooks[0x402928]=lambda:self.ret(1)
 def record(self,a):self.calls.append(hex(a));self.ret()
 def tick(self,run,held,poll,physics,now):
  self.now=now;self.calls=[];self.u32(0x57a6f8,run);self.u32(0x57a6f4,0);self.u32(self.form+0x5bc,held);self.u32(self.form+0x5a8,poll);self.u32(0x57a74c,physics);self.f64(0x5636cc,0)
  handled=self.alloc(4);self.uc.reg_write(UC_X86_REG_EAX,self.form);self.uc.reg_write(UC_X86_REG_ECX,handled);self.call(0x4018b0,b'')
  return dict(run=run,held=held,poll=poll,physics=physics,now=now,after_poll=self.u32(self.form+0x5a8),after_physics=self.u32(0x57a74c),elapsed_bits=bytes(self.uc.mem_read(0x5636cc,8)).hex(),accepted=bool(self.calls),calls=self.calls)
def main():
 o=ClockOracle();cases=[o.tick(run,held,100,80,now) for run in [0,1,2] for held in [0,1] for now in [100,105,106,140]]
 mouse=[];pause=[]
 doc=next(d for d in json.loads((ROOT/'godot/data/examples.json').read_text()) if any(a['type_id']==204 for a in d['apparatus']))
 for run in [0,1,2]:
  up=DispatchOracle();scene=up.setup_scene(doc);index=next(i for i,v in enumerate(scene['vessels']) if v['type_id']==204);up.u32(0x57a74c,80);up.dispatch(index,[-1000,-1000],run);mouse.append(dict(run=run,after_physics=up.u32(0x57a74c)))
  o.u32(0x57a6f8,run);o.u32(0x57a74c,80);o.now=140;o.hooks[0x527f18]=lambda:o.ret();o.hooks[0x505524]=lambda:o.ret();o.uc.reg_write(UC_X86_REG_EAX,o.form);o.call(0x43ddd8,b'');pause.append(dict(run=run,after_run=o.u32(0x57a6f8),after_physics=o.u32(0x57a74c)))
 (ROOT/'godot/tests/fixtures/original_ui_clock.json').write_text(json.dumps(dict(source_sha256=EXPECTED,entry='004018B0',mouse_up_cases=mouse,pause_cases=pause,boundaries='Declared monotonic clock; physics, program and GDI callbacks captured without side effects; original cadence/physics clocks, delta arithmetic and timer control flow execute',cases=cases),indent=2)+'\n');print(len(cases),'clock cases')
if __name__=='__main__':main()
