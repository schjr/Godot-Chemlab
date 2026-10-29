"""Execute original mainMouseDown decision path through common4256BD boundary."""
import json,struct
from original_frame_oracle import FrameOracle
from original_x86_oracle import ROOT,EXPECTED
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX,UC_X86_REG_ECX
class SelectionOracle(FrameOracle):
 def __init__(self):
  super().__init__();self.form=self.alloc(0x1000);self.hooks[0x505524]=lambda:self.ret();self.hooks[0x527f18]=lambda:self.ret()
 def setup_scene(self,doc):
  self.setup(doc)
  lines=doc['trailing_lines'];pos=1+7*int(lines[0]);chart_count=int(lines[pos]);chart_records=[lines[pos+1+55*i:pos+56+55*i] for i in range(chart_count)];pos+=1+55*chart_count
  annotation_count=int(lines[pos]);pos+=1
  annotations=[]
  for i in range(annotation_count):
   r=lines[pos:pos+16];pos+=16+int(r[15]);annotations.append(dict(metadata=r,position=[int(r[1]),int(r[2])],size=[int(r[3]),int(r[4])]))
  group_count=int(lines[pos]);pos+=1
  for i in range(group_count):r=lines[pos:pos+4];pos+=4+int(r[0])
  scale=float(lines[pos]);pos+=1;button_count=int(lines[pos]);pos+=1;button_records=[lines[pos+26*i:pos+26*i+26] for i in range(button_count)];pos+=26*button_count
  label_records=[]
  for i in range(len(self.vessels)):
   r=lines[pos:pos+16];pos+=16+int(r[15]);label_records.append(r)
   for j,off in [(0,0xc0),(1,0xc4),(2,0xc8),(3,0xcc),(4,0xd0)]:self.u32(self.vessels[i]+off,int(r[j]))
  self.f64(0x5636c0,scale)
  self.uc.mem_write(0x57a750,b'\0'*(100*0x34));self.uc.mem_write(0x58ef64,b'\0'*(10*0x148));self.uc.mem_write(0x58ca94,b'\0'*(100*0x5c))
  for i,a in enumerate(annotations):
   p=0x57a750+0x34*i
   for j in range(5):self.u32(p+4*j,int(a['metadata'][j]))
  for i,r in enumerate(chart_records):
   for j in range(3):self.u32(0x58ef64+0x148*i+4*j,int(r[j]))
  buttons=[]
  for i,r in enumerate(button_records):
   p=0x58ca94+0x5c*i
   for j,off in [(0,0),(1,4),(2,8),(16,0x34),(17,0x38)]:self.u32(p+off,int(r[j]))
   buttons.append(dict(metadata=r,active=int(r[0]),position=[int(r[1]),int(r[2])],size=[int(r[16]),int(r[17])]))
  vessels=[]
  for i,a in enumerate(doc['apparatus']):
   b=self.bitmaps[self.u32(self.vessels[i]+0xfc)]
   vessels.append(dict(id=i+1,type_id=a['type_id'],position=[int(a['x']),int(a['y'])],native_fields=a['native_fields'],native_bitmap_width=b['width'],native_bitmap_height=b['height'],native_label_rect=[int(x) for x in label_records[i][1:5]]))
  return dict(vessels=vessels,connectors=doc['connectors'],annotations=annotations,charts=[dict(metadata=r,position=[int(r[1]),int(r[2])]) for r in chart_records],buttons=buttons,scale=scale)
 def selection(self,x,y,selected=-1):
  self.u32(0x57a724,0);self.u32(0x57a728,0);self.u32(0x57a730,0 if selected<0 else self.u32(self.vessels[selected]+8));self.u32(0x57a734,max(0,selected));self.u32(0x57a738,0)
  self.u32(self.form+0x588,0);self.u32(self.form+0x5ac,0);self.u32(self.form+0x5b0,0);self.uc.reg_write(UC_X86_REG_EAX,self.form);self.uc.reg_write(UC_X86_REG_EDX,0);self.uc.reg_write(UC_X86_REG_ECX,0)
  saved=self.stop_address;self.stop_address=0x4256bd
  try:self.call(0x417ee0,struct.pack('<ii',y,x))
  finally:self.stop_address=saved
  def signed(v):return v if v<0x80000000 else v-0x100000000
  return {'type':signed(self.u32(0x57a730)),'index':self.u32(0x57a734),'command':self.u32(0x57a738),'dx':signed(self.u32(self.form+0x5ac)),'dy':signed(self.u32(self.form+0x5b0))}
def main():
 docs=json.loads((ROOT/'godot/data/examples.json').read_text());cases=[];failures=[]
 for d in docs:
  o=SelectionOracle();scene=o.setup_scene(d);points=set()
  for v in scene['vessels']:
   x,y=v['position'];w,h=v['native_bitmap_width'],v['native_bitmap_height']
   points.update((x+dx,y+dy) for dx in [0,-w//2,w//2,-w//2-4,w//2+4] for dy in [0,-h//2,h//2,-h//2-4,h//2+4])
  for a in scene['annotations']:points.add((a['position'][0]+1,a['position'][1]+1))
  for c in scene['charts']:points.add(tuple(c['position']))
  for c in scene['connectors']:points.add((int(c['metadata'][2]),int(c['metadata'][3])));points.add((int(c['metadata'][4]),int(c['metadata'][5])))
  samples=[]
  for x,y in sorted(points):
   try:samples.append(dict(point=[x,y],expected=o.selection(x,y)))
   except Exception as e:failures.append([d['name'],[x,y],str(e)])
  cases.append(dict(name=d['name'],scene=scene,samples=samples));print(d['name'],len(samples),flush=True)
 out=dict(binary_sha256=EXPECTED,entry='00417EE0',stop='004256BD decision common boundary; postselection attachment/UI changes excluded',scope='Leftbutton,selecttool; actualnativeVCLwidth/heightqueries underdeclaredbitmapdata,actualfont-labelboxfields fromCEMfooter',cases=cases,failures=failures)
 (ROOT/'godot/tests/fixtures/original_selection.json').write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n');print('selectioncases',sum(len(c['samples']) for c in cases),'failures',len(failures))
if __name__=='__main__':main()
