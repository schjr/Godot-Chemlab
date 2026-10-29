"""Original MouseMove geometry and MouseUp association references with VCL dimension ABI boundary."""
import copy,json,struct
from original_selection_oracle import SelectionOracle
from original_x86_oracle import ROOT,EXPECTED
from unicorn.x86_const import UC_X86_REG_EBP,UC_X86_REG_ESP,UC_X86_REG_EIP
class InteractionOracle(SelectionOracle):
 def setup_scene(self,doc):
  scene=copy.deepcopy(super().setup_scene(doc));holder=self.alloc(4);self.u32(holder,self.form);self.u32(0x5799c4,holder)
  return scene
 def signed(self,x):return x if x<0x80000000 else x-0x100000000
 def snapshot(self,scene):
  out=copy.deepcopy(scene)
  for i,v in enumerate(out['vessels']):
   p=self.vessels[i];v['position']=[self.signed(self.u32(p+0x10)),self.signed(self.u32(p+0x14))];v['parent_type']=self.u32(p+0x84);v['parent_name']=self.text_at(self.u32(p+0x80));v['width']=self.bitmaps[self.u32(p+0xfc)]['width'];v['height']=self.bitmaps[self.u32(p+0xfc)]['height']
  for i,c in enumerate(out['connectors']):
   p=self.connectors[i]
   for j in range(2,19):c['metadata'][j]=self.text_at(self.u32(p+j*4)) if j in [11,14] else str(self.signed(self.u32(p+j*4)))
  for i,b in enumerate(out['buttons']):
   p=0x58ca94+i*0x5c;b['position']=[self.signed(self.u32(p+4)),self.signed(self.u32(p+8))];b['size']=[self.signed(self.u32(p+0x34)),self.signed(self.u32(p+0x38))]
  return out
 def resize(self,scene,d,point):
  for a,val in [(0x57a730,d['type']),(0x57a734,d['index']),(0x57a738,d['command'])]:self.u32(a,val)
  for off,key in [(0x5ac,'dx'),(0x5b0,'dy'),(0x504,'start_width'),(0x508,'start_height'),(0x50c,'start_x'),(0x510,'start_y')]:self.u32(self.form+off,d[key])
  bp=0x90ff000;self.u32(bp-4,self.form);self.u32(bp+8,point[1]);self.u32(bp+12,point[0]);self.uc.reg_write(UC_X86_REG_EBP,bp);self.uc.reg_write(UC_X86_REG_ESP,bp-0x400)
  old=self.stop_address;self.stop_address=0x42a881
  try:self.uc.emu_start(0x42873c,self.stop_address,count=2000000)
  finally:self.stop_address=old
  if self.uc.reg_read(UC_X86_REG_EIP)!=0x42a881:raise ValueError('Geometry did not reach original presentation boundary')
  return dict(scene=self.snapshot(scene),dx=self.signed(self.u32(self.form+0x5ac)),dy=self.signed(self.u32(self.form+0x5b0)))
 def release(self,scene):
  self.call(0x454e44,b'');self.call(0x459f1c,b'');return self.snapshot(scene)
def main():
 docs=json.loads((ROOT/'godot/data/examples.json').read_text());releases=[];resizes=[];failures=[]
 for doc in docs:
  for profile in ['stored','move_first','connector_boundary']:
   o=InteractionOracle();scene=o.setup_scene(doc)
   if profile=='move_first' and scene['vessels']:
    v=scene['vessels'][0];v['position'][0]+=13;v['position'][1]+=17
    o.u32(o.vessels[0]+0x10,v['position'][0]);o.u32(o.vessels[0]+0x14,v['position'][1])
   if profile=='connector_boundary' and scene['connectors']:
    c=scene['connectors'][0];c['metadata'][2]=str(int(c['metadata'][2])+5);c['metadata'][3]=str(int(c['metadata'][3])-5)
    o.u32(o.connectors[0]+8,int(c['metadata'][2]));o.u32(o.connectors[0]+12,int(c['metadata'][3]))
   try:releases.append(dict(name=doc['name']+'/'+profile,scene=scene,expected=o.release(scene)))
   except Exception as e:failures.append(dict(name=doc['name'],profile=profile,phase='release',error=str(e)))
 template=next(d for d in docs if any(a['type_id']==316 for a in d['apparatus']))
 index=next(i for i,a in enumerate(template['apparatus']) if a['type_id']==316)
 for typ in [316,318,2000]:
  for cmd in range(5):
   for delta in [(7,9),(-11,-13),(0,0),(40,35),(-40,-35)]:
    o=InteractionOracle();scene=o.setup_scene(template)
    if typ==2000:
     scene['buttons']=[dict(metadata=['0']*26,active=1,position=[223,117],size=[35,30])];b=scene['buttons'][0];b['metadata'][0]='1';b['metadata'][1]='223';b['metadata'][2]='117';b['metadata'][16]='35';b['metadata'][17]='30'
     for off,val in [(0,1),(4,223),(8,117),(0x34,35),(0x38,30)]:o.u32(0x58ca94+off,val)
     selected=0;x,y=b['position'];w,h=b['size']
    else:
     selected=index;v=scene['vessels'][index];v['type_id']=typ;v['native_fields']['0x08']=str(typ);o.u32(o.vessels[index]+8,typ);x,y=v['position'];w,h=v['native_bitmap_width'],v['native_bitmap_height']
    dx=0 if cmd==0 else (-w//2 if cmd in [1,3] else w//2);dy=0 if cmd==0 else (-h//2 if cmd in [1,2] else h//2)
    d=dict(type=typ,index=selected,command=cmd,dx=dx,dy=dy,start_width=w,start_height=h,start_x=x,start_y=y);point=[x+dx+delta[0],y+dy+delta[1]]
    try:resizes.append(dict(scene=scene,decision=d,point=point,expected=o.resize(scene,d,point)))
    except Exception as e:failures.append(dict(type=typ,command=cmd,delta=delta,error=str(e)))
 out=dict(source_sha256=EXPECTED,release_entries=['00454E44','00459F1C'],resize_entry='0042873C..0042A881',boundary='Original VCL dimension getters/setters hosted; geometry before raster redraw; exception registration declared',release_cases=releases,resize_cases=resizes,failures=failures)
 (ROOT/'godot/tests/fixtures/original_interaction.json').write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n');print('release',len(releases),'resize',len(resizes),'failures',failures)
if __name__=='__main__':main()
