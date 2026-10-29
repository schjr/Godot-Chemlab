"""Original opening experiment manual callbacks and full native physics workflow."""
import json,struct
from original_frame_oracle import FrameOracle
from original_x86_oracle import ROOT,EXPECTED
from original_actions_oracle import bits

def tick(o):
 o.f64(0x5636d4,0.02)
 for entry in [0x470060,0x48e418,0x4849fc]:o.call(entry,b'')
 for i,p in enumerate(o.vessels):
  if o.u32(p+0x18)==0:o.call(0x46c84c,struct.pack('<I',i))
 for entry in [0x4624d8,0x46ec50,0x46d414,0x46f704,0x4624d8]:o.call(entry,b'')
 o.render()

def main():
 doc=next(d for d in json.loads((ROOT/'godot/data/examples.json').read_text()) if d['name']=='氢氧化铜与氢氧化铁')
 o=FrameOracle();o.setup(doc);o.enable_manual_presentation()
 actions=[dict(name='aspirate original NaOH bottle',selected=2,command=1,position=[429,206]),dict(name='drop onto CuSO4 beaker',selected=2,command=2,position=[179,190],ticks=15),dict(name='drop onto FeCl3 beaker',selected=2,command=2,position=[306,190],ticks=15),dict(name='aspirate original HCl bottle',selected=5,command=1,position=[510,206]),dict(name='drop HCl onto copper hydroxide',selected=5,command=2,position=[179,190],ticks=15),dict(name='drop HCl onto iron hydroxide',selected=5,command=2,position=[306,190],ticks=15),dict(name='rotate and pour original HCl bottle',selected=4,position=[203,175],ticks=3,orientation_toggle=True)]
 states=[]
 try:
  for a in actions:
   p=o.vessels[a['selected']];o.u32(p+0x10,a['position'][0]);o.u32(p+0x14,a['position'][1]);o.u32(0x57a734,a['selected']);o.u32(0x57a730,204);o.u32(0x57a738,a.get('command',0))
   if a.get('orientation_toggle'):
    o.enable_orientation_presentation();o.toggle_orientation(a['selected'])
   else:o.call(0x477708,b'')
   o.render()
   for _ in range(a.get('ticks',0)):tick(o)
   if a.get('orientation_toggle'):o.toggle_orientation(a['selected']);o.render()
   states.append(o.capture_frame());print(a['name'],flush=True)
  result={'status':'executed','states':states}
 except Exception as e:result={'status':'unresolved','error':str(e),'completed':len(states)}
 output={'binary_sha256':EXPECTED,'name':doc['name'],'fixture_path':doc['fixture'],'profile':'Explicit zero numerical heap inputs, exact original RUN stages','scope':'Original477708 manual callbacks with VCLCopyRect/Ellipse/Repaint presentation hosted; full native physics; programs excluded','delta_bits':bits(0.02),'actions':actions,**result}
 (ROOT/'godot/tests/fixtures/original_workflow.json').write_text(json.dumps(output,ensure_ascii=False,indent=2)+'\n');print(result['status'],result.get('error'))
if __name__=='__main__':main()
