"""Actual original TBrush setters, shared registry, events and lazy GDI handle."""
import json,struct
from original_pen_oracle import PenOracle,REG,PEN,CANVAS
from original_x86_oracle import ROOT,EXPECTED
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX
class BrushOracle(PenOracle):
 def __init__(self):
  super().__init__();self.hooks[0x555272]=self.create_brush
 def create_brush(self):
  pointer=self.args(1)[0];self.events.append({'api':'CreateBrushIndirect','logbrush_hex':bytes(self.uc.mem_read(pointer,12)).hex()});self.stdcall(self.create_result,4)
 def operation(self,op):
  self.uc.reg_write(UC_X86_REG_EAX,PEN);self.uc.reg_write(UC_X86_REG_EDX,op.get('value',0))
  return self.call({'color':0x4e4158,'style':0x4e4274,'handle':0x4e418c}[op['op']],b'')
def record(color,style=0,pattern=0,padding=b'\0\0\0'):return struct.pack('<III',0,color,pattern)+bytes([style])+padding
def case(name,operations,refs=1,existing=False,middle=False,event=0,selected=False,old_handle=0x44440001,brush_lock=False,collision=False,create=0x77770001,delete=1,color=0x112233,style=0,pattern=0,padding=b'\0\0\0'):
 o=BrushOracle();o.create_result=create;o.delete_result=delete;old=0x2001000;match=0x2001100;head=match if middle or existing or collision else old
 segments=[]
 def put(a,b):o.uc.mem_write(a,bytes(b));segments.append({'address':a,'hex':b.hex()})
 # Setters copy descriptor and erase native handle/pattern, then transform style/color.
 desired_color=operations[0].get('value',0) if operations[0]['op']=='color' else color
 desired_style=(0 if style==1 else style) if operations[0]['op']=='color' else operations[0].get('value',style) if operations[0]['op']=='style' else style
 if operations[0]['op']=='style' and desired_style==1:desired_color=0xffffff
 target=record(desired_color,desired_style,padding=padding)
 for a in [old]+([match] if head!=old else []):
  data=record(color,style,pattern,padding) if a==old else record(desired_color^1,desired_style,padding=b'\x10\0\0') if collision else target
  if collision and a==match:
   # Retain an actual distinct equal-checksum descriptor, found using native checksum.
   desired=o.checksum(target);candidate=None
   for value in range(65536):
    probe=record(desired_color^1,desired_style,padding=struct.pack('<H',value)+b'\0')
    if o.checksum(probe)==desired:candidate=probe;break
   assert candidate is not None;data=candidate
  node=bytearray(b'\xa5'*32);struct.pack_into('<IIIH',node,0,0 if a==old else old,refs if a==old else 2,old_handle if a==old else 0,o.checksum(data));node[16:]=data;put(a,node)
 reg=bytearray(0x24);struct.pack_into('<II',reg,0,0x4e2d1c,head);struct.pack_into('<H',reg,0x20,16);put(REG,reg)
 brush=bytearray(0x18);struct.pack_into('<I',brush,0,0x4e2520);struct.pack_into('<II',brush,8,event,CANVAS);struct.pack_into('<II',brush,16,old,0x2000300 if brush_lock else 0);put(PEN,brush)
 canvas=bytearray(0x64);struct.pack_into('<II',canvas,0,0x4e80d0,0x11110042);canvas[8]=0x88 if selected else 0x80;put(CANVAS,canvas)
 o.u32(0x59a9e8,REG);o.u32(0x59a9a4,0x55550002)
 world={'source_sha256':EXPECTED,'scope':'Explicit diagnostic native graph and declared API outcomes, not captured/live VCL state','globals':{'0x59a9e8':REG,'0x59a9a4':0x55550002},'thread':{'fs_base':0,'exception_head':0xffffffff,'stack_base':0x9000000,'stack_size':0x100000,'stack_pointer':0x90ffe00,'stack_origin':'fresh_committed_pages'},'segments':segments,'external_events':[0x7000000] if event==0x7000000 else []}
 steps=[]
 for op in operations:
  value=o.operation(op);steps.append({'operation':op,'value':value,'state':o.state(segments)})
 return {'name':name,'world':world,'api_outcomes':{'create':create,'delete':delete},'steps':steps}
def c(value):return {'op':'color','value':value}
def s(value):return {'op':'style','value':value}
def h():return {'op':'handle'}
def main():
 cases=[case('same descriptor retains handle',[c(0x112233),h(),h()]),case('new color selected canvas lock finally',[c(0xabcdef),h()],event=0x4e4e0c,selected=True,brush_lock=True),case('matching registry node preserves old shared record',[c(0x445566),h()],existing=True,refs=2,event=0x4e4e0c),case('unlink old middle node',[c(0x778899),h()],middle=True,event=0x4e4e0c,selected=True),case('equal hash distinct descriptor',[c(0x765432),h()],collision=True),case('external change event',[c(0x220044),h()],event=0x7000000),case('delete failure still frees',[c(0x331155),h()],delete=0,event=0x4e4e0c,selected=True),case('system color lookup',[c(0x8000000f),h()]),case('creation failure retried',[c(0x559911),h(),h()],create=0),case('cached handle no allocation',[h()]),case('uncached handle lazy and cached',[h(),h()],old_handle=0),case('hollow style forces white',[s(1),h()]),case('hollow color assignment becomes solid',[c(0x101010),h()],style=1,color=0xffffff),case('setting same hollow style retains record',[s(1),h()],style=1,color=0xffffff),case('nonzero descriptor padding preserved',[c(0x505050),h()],padding=b'\x19\x28\x37'),case('color removes bitmap descriptor',[c(0x112233),h()],pattern=0x2005000),case('style removes bitmap descriptor',[s(0),h()],pattern=0x2005000)]
 for style in range(2,8):cases.append(case('hatch style'+str(style),[s(style),h()]))
 output={'source_sha256':EXPECTED,'scope':'Actual PE brush/registry/dynamic-event instructions; isolated locks, allocation, GDI and external events have declared outcomes. No target handles used. Bitmap virtual lazy-create branch remains unknown.','cases':cases}
 (ROOT/'godot/tests/fixtures/original_brush.json').write_text(json.dumps(output,indent=2)+'\n');print(json.dumps({'cases':len(cases),'steps':sum(len(c['steps']) for c in cases)}))
if __name__=='__main__':main()
