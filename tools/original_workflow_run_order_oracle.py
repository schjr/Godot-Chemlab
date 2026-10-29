"""Fresh opening workflow reference with actual43DE5C startup; old fixture retained."""
import json,struct
from original_frame_oracle import FrameOracle
from original_workflow_oracle import tick
from original_x86_oracle import ROOT,EXPECTED
from original_actions_oracle import bits
from unicorn.x86_const import UC_X86_REG_EAX
class WorkflowRunOracle(FrameOracle):
 def __init__(self):
  super().__init__();self.loading=False;self.events=[]
  self.run_form=self.alloc(0x50000);vt=self.alloc(0x60);self.u32(vt+0x5c,0x8000200)
  for off in [0x320,0x324,0x328,0x400,0x404]:
   p=self.alloc(4);self.u32(p,vt);self.u32(self.run_form+off,p)
  for address in [0x505524,0x4d38b8,0x527f18,0x8000200]:self.hooks[address]=lambda:self.ret()
  self.hooks[0x53d180]=lambda:self.ret(140)
  self.hooks[0x42dc3c]=self.save_boundary
  self.hooks[0x43f7bc]=self.refresh_boundary
 def save_boundary(self):self.events.append('42DC3C save-boundary');self.ret()
 def refresh_boundary(self):
  self.events.append('43F7BC stopped refresh-boundary')
  context=self.uc.context_save();stack=bytes(self.uc.mem_read(0x90f0000,0x10000))
  self.call(0x4624d8,b'');self.render()
  self.uc.mem_write(0x90f0000,stack);self.uc.context_restore(context);self.ret()
 def on_instruction(self,uc,address,size,unused):
  if address in [0x4624d8,0x46c894,0x48e9b4]:self.events.append(f'{address:08X}')
  super().on_instruction(uc,address,size,unused)
 def call(self,address,args):
  # Reuse only the old harness's exact input-construction scope. Never execute
  # its obsolete ensure/air/recalc/render startup; actual43DE5C owns that order.
  if self.loading and address in [0x46c894,0x48e9b4,0x4624d8]:return 0
  return super().call(address,args)
 def render(self):
  if not self.loading:super().render()
 def setup(self,doc):
  self.loading=True;super().setup(doc);self.loading=False
  self.uc.mem_write(self.run_form+0xe1b,b'\0');self.u32(0x57a730,0);self.events=[]
  self.uc.reg_write(UC_X86_REG_EAX,self.run_form);self.call(0x43de5c,b'')
def main():
 doc=next(d for d in json.loads((ROOT/'godot/data/examples.json').read_text()) if d['name']=='氢氧化铜与氢氧化铁')
 old=json.loads((ROOT/'godot/tests/fixtures/original_workflow.json').read_text())
 o=WorkflowRunOracle();o.setup(doc);startup_events=o.events.copy();startup=o.capture_frame();o.enable_manual_presentation()
 actions=old['actions'];states=[];frames=[]
 try:
  for a in actions:
   p=o.vessels[a['selected']];o.u32(p+0x10,a['position'][0]);o.u32(p+0x14,a['position'][1]);o.u32(0x57a734,a['selected']);o.u32(0x57a730,204);o.u32(0x57a738,a.get('command',0))
   if a.get('orientation_toggle'):o.enable_orientation_presentation();o.toggle_orientation(a['selected'])
   else:o.call(0x477708,b'')
   o.render()
   for _ in range(a.get('ticks',0)):tick(o);frames.append(o.capture_frame())
   if a.get('orientation_toggle'):o.toggle_orientation(a['selected']);o.render()
   states.append(o.capture_frame());print(a['name'],flush=True)
  result={'status':'executed','states':states,'frames':frames}
 except Exception as e:result={'status':'unresolved','error':str(e),'completed':len(states)}
 output={'binary_sha256':EXPECTED,'name':doc['name'],'fixture_path':doc['fixture'],'profile':'Explicit zero numerical allocation input; original43DE5C first-Run callback; not production allocator semantics','scope':'Actual43DE5C numeric writes,4624D8 and471650 before46C894/48E9B4; stopped chart/association/raster and file-save boundaries hosted. Original477708 manual callbacks and4433B4 orientation; VCLCopyRect/Ellipse/Repaint presentation hosted; original physics and numeric liquid display; programs excluded. Earlier original_workflow.json retained with old startup scope.','startup_events':startup_events,'start':startup,'delta_bits':bits(0.02),'actions':actions,**result}
 (ROOT/'godot/tests/fixtures/original_workflow_run_order.json').write_text(json.dumps(output,ensure_ascii=False,separators=(',',':'))+'\n');print(result['status'],result.get('error'),len(frames),'frames')
if __name__=='__main__':main()
