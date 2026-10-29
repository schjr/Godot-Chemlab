"""Execute original main MouseUp dispatch for helper releases under run/pause states."""
import json,struct
from original_selection_oracle import SelectionOracle
from original_x86_oracle import ROOT,EXPECTED
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX,UC_X86_REG_ECX
class DispatchOracle(SelectionOracle):
 def dispatch(self,selected,point,run):
  calls=[]
  def action():calls.append(dict(index=self.u32(0x57a734),type=self.u32(0x57a730),command=self.u32(0x57a738)));self.ret()
  self.hooks[0x477708]=action
  self.hooks[0x53d180]=lambda:self.ret(1234) # Declared clock presentation boundary; dispatch predicates do not use its value.
  # Independently verified geometry association; callback presentation boundary.
  for a in [0x454e44,0x459f1c,0x4126dc,0x505524]:self.hooks[a]=lambda:self.ret()
  self.u32(0x57a6f8,run);self.u32(0x57a730,self.u32(self.vessels[selected]+8));self.u32(0x57a734,selected);self.u32(0x57a738,0);self.u32(self.form+0x588,0);self.u32(self.form+0x5bc,1)
  self.uc.reg_write(UC_X86_REG_EAX,self.form);self.uc.reg_write(UC_X86_REG_EDX,0);self.uc.reg_write(UC_X86_REG_ECX,0)
  self.call(0x42aa18,struct.pack('<ii',point[1],point[0]));return calls
def main():
 cases=[];errors=[]
 for doc in json.loads((ROOT/'godot/data/examples.json').read_text()):
  for index,a in enumerate(doc['apparatus']):
   typ=a['type_id']
   if typ not in [204,207,208,211]:continue
   o=DispatchOracle();scene=o.setup_scene(doc);v=scene['vessels'][index];x,y=v['position'];w,h=v['native_bitmap_width'],v['native_bitmap_height'];hw=w//2;hh=h//2
   spans=[(1,y-hh,y-hh+20),(2,y-hh+23,y-hh+43)] if typ==204 else [(1,y+hh-70,y+hh-50),(2,y+hh-47,y+hh-27),(3,y+hh-24,y+hh-4)] if typ in [207,208] else [(1,y-hh,y-hh+20),(2,y-hh+23,y-hh+43),(3,y-hh+46,y-hh+66)]
   for cmd,top,bottom in spans:
    for run in [0,1,2]:
     for profile,point in [('inside',[x+hw+20,top+10]),('left_edge',[x+hw+10,top+10]),('top_edge',[x+hw+20,top])]:
      try:cases.append(dict(name=doc['name'],index=index,vessel=v,point=point,run=run,profile=profile,nominal_command=cmd,expected=o.dispatch(index,point,run)))
      except Exception as e:errors.append(dict(name=doc['name'],error=str(e)))
 (ROOT/'godot/tests/fixtures/original_controls_dispatch.json').write_text(json.dumps(dict(source_sha256=EXPECTED,entry='0042AA18',scope='Left MouseUp; selected original helper; no matching MouseDown latch required;477708 intercepted for dispatch observation; association/presentation separately verified',cases=cases,errors=errors),ensure_ascii=False,indent=2)+'\n')
 print(len(cases),'dispatchcases; failures',len(errors),errors[:2])
if __name__=='__main__':main()
