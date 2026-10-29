"""Retained Rectangle/required-state on source-constructed shared Canvas graph."""
import json,struct
from original_shared_vcl_oracle import SharedVclOracle
from original_x86_oracle import ROOT,EXPECTED
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX,UC_X86_REG_ECX,UC_X86_REG_ESP,UC_X86_REG_EIP
class DrawingOracle(SharedVclOracle):
 def __init__(self):
  super().__init__();self.canvas=0;self.graphics=[];self.next_handle=0x71000001;self.creation_failure=False;self.rectangle_result=1
  self.uc.mem_map(0x7000000,4096)
  for address,name,count in [(0x5553e0,'Rectangle',5),(0x55547c,'UnrealizeObject',1),(0x55540a,'SetBkColor',2),(0x555410,'SetBkMode',2),(0x555434,'SetROP2',2),(0x555678,'GetSysColor',1),(0x5552b4,'CreatePenIndirect',1),(0x555272,'CreateBrushIndirect',1),(0x5553f8,'SelectObject',2),(0x5552d8,'DeleteObject',1)]:self.hooks[address]=lambda n=name,c=count:self.graphics_api(n,c)
  for address in [0x7000100,0x7000200]:self.hooks[address]=lambda a=address:self.event(a)
  self.hooks[0x52d038]=lambda:self.exception_frontier()
 def exception_frontier(self):raise RuntimeError('Original missing-HDC exception constructor52D038; exceptional unwinding outside scope')
 def graphics_api(self,name,count):
  args=self.arguments(count);request=dict(api=name)
  if name=='Rectangle':
   def signed(v):return v-0x100000000 if v&0x80000000 else v
   request.update(hdc=args[0],**dict(zip(['left','top','right','bottom'],map(signed,args[1:]))))
  elif name in ['CreatePenIndirect','CreateBrushIndirect']:request['logpen_hex' if name=='CreatePenIndirect' else 'logbrush_hex']=bytes(self.uc.mem_read(args[0],12)).hex()
  elif name in ['UnrealizeObject','DeleteObject']:request['handle']=args[0]
  elif name=='GetSysColor':request['index']=args[0]
  elif name=='SelectObject':request.update(hdc=args[0],handle=args[1])
  else:request.update(hdc=args[0],**{'color' if name=='SetBkColor' else 'mode':args[1]})
  self.capture(request)
  result={'Rectangle':self.rectangle_result,'UnrealizeObject':1,'SelectObject':0x11220000 if args[-1]!=0 else 0,'DeleteObject':1,'GetSysColor':0x224466,'SetBkColor':0x334455,'SetBkMode':2,'SetROP2':13}.get(name)
  if name.startswith('Create'):
   result=0 if self.creation_failure else self.next_handle
   if not self.creation_failure:self.next_handle+=1
  self.stdcall(result,count*4)
 def capture(self,request):
  self.graphics.append({'request':request,'canvas_state':bytes(self.uc.mem_read(self.canvas+8,1)).hex() if self.canvas else '', 'pen_record':self.u32(self.u32(self.canvas+16)+16) if self.canvas else 0,'brush_record':self.u32(self.u32(self.canvas+20)+16) if self.canvas else 0})
 def event(self,target):
  self.capture(dict(api='event',target=target,owner=self.uc.reg_read(UC_X86_REG_EAX),sender=self.uc.reg_read(UC_X86_REG_EDX)));self.ret()
 def rectangle(self,coords):
  left,top,right,bottom=coords
  self.uc.reg_write(UC_X86_REG_EAX,self.canvas);self.uc.reg_write(UC_X86_REG_EDX,left&0xffffffff);self.uc.reg_write(UC_X86_REG_ECX,top&0xffffffff)
  return self.call(0x4e4744,struct.pack('<II',bottom&0xffffffff,right&0xffffffff))
def case(name,hdc=0x11110042):
 seed=json.loads((ROOT/'godot/tests/fixtures/original_canvas_constructor.json').read_text())['cases'][0]
 world=seed['world'];world['scope']='Actual normal Canvas and source allocator; explicit input HDC/event bindings and declared primitive GDI results, no native Win32 raster claim';world['manager']=dict(allocation_dispatch=0x534428,system_get=0x5306b0,system_free=0x530838,system_realloc=0x530bac)
 world['segments'].append(dict(address=0x574b54,hex='00'));world['globals'].update({'0x59a9a0':0xa1110001,'0x59a9a4':0xa1110002})
 o=DrawingOracle()
 for segment in world['segments']:o.uc.mem_write(segment['address'],bytes.fromhex(segment['hex']))
 for address,value in world['globals'].items():o.u32(int(address,16),value)
 setup=[]
 for entry,end,eax,edx in [(0x4eb398,0x4eb3d7,0,0),(0x4eb3e8,0x4eb40a,0,0),(0x4e42a8,None,0x4e25e4,1)]:setup.append(dict(entry=entry,endpoint=end if end else -1,eax=eax,edx=edx,value=o.run(entry,eax,edx,end=end)))
 o.canvas=setup[-1]['value'];pen=o.u32(o.canvas+16);brush=o.u32(o.canvas+20)
 writes=[dict(address=o.canvas+4,hex=struct.pack('<I',hdc).hex()),dict(address=o.canvas+0x30,hex=struct.pack('<II',0x7000100,0xb1110001).hex()),dict(address=o.canvas+0x28,hex=struct.pack('<II',0x7000200,0xb1110002).hex())]
 for w in writes:o.uc.mem_write(w['address'],bytes.fromhex(w['hex']))
 operations=[dict(op='rectangle',coords=[-4,-2,60,70])]
 if hdc:
  operations += [dict(op='rectangle',coords=[0,0,10,10]),dict(op='pen_color',value=0x112233),dict(op='rectangle',coords=[1,2,10,20]),dict(op='brush_style',value=1),dict(op='rectangle',coords=[10,9,-8,-7]),dict(op='brush_color',value=0x8000000f),dict(op='rectangle',coords=[0,0,10,10]),dict(op='pen_color',value=0x8899aa),dict(op='brush_color',value=0xaabbcc),dict(op='rectangle',coords=[1,1,2,2],creation_failure=True,rectangle_result=0),dict(op='rectangle',coords=[1,1,2,2],creation_failure=True,rectangle_result=0)]
 steps=[]
 for operation in operations:
  o.creation_failure=operation.get('creation_failure',False);o.rectangle_result=operation.get('rectangle_result',1)
  try:
   if operation['op']=='rectangle':value=o.rectangle(operation['coords'])
   else:value=o.run({'pen_color':0x4e3e50,'brush_color':0x4e4158,'brush_style':0x4e4274}[operation['op']],pen if operation['op']=='pen_color' else brush,operation['value'])
   steps.append(dict(operation=operation,status='executed',value=value,state=o.state(),graphics=o.graphics.copy(),canvas_state=bytes(o.uc.mem_read(o.canvas+8,1)).hex()))
  except Exception as e:steps.append(dict(operation=operation,status='boundary',error=str(e),pc=o.uc.reg_read(UC_X86_REG_EIP),graphics=o.graphics.copy(),canvas_state=bytes(o.uc.mem_read(o.canvas+8,1)).hex()));break
 return dict(name=name,world=world,setup=setup,canvas=o.canvas,pen=pen,brush=brush,input_writes=writes,event_targets=[0x7000100,0x7000200],steps=steps)
def main():
 cases=[case('constructed Canvas selection, dirty state, events and GDI failures'),case('missing native HDC exception frontier',0)]
 (ROOT/'godot/tests/fixtures/original_canvas_drawing.json').write_text(json.dumps(dict(source_sha256=EXPECTED,scope='Actual source constructor/heap/Rectangle/PenBrush state with real host RLocks; declared GDI results and input HDC/event bindings; no raster/Win32 execution claim',cases=cases),indent=2)+'\n')
 print(len(cases),'cases',sum(len(c['steps'])for c in cases),'steps')
if __name__=='__main__':main()
