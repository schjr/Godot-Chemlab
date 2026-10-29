"""Execute real TPen/registry instructions on explicit diagnostic graphs."""
import json,struct
from original_x86_oracle import OriginalOracle,ROOT,EXPECTED
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX,UC_X86_REG_ESP
REG=0x2000000;PEN=0x2000100;CANVAS=0x2000200;NEW=0x2010000
class PenOracle(OriginalOracle):
 def __init__(self):
  super().__init__();self.events=[];self.blocks={};self.next_block=NEW;self.create_result=0x77770001;self.delete_result=1
  self.hooks.update({0x554ec4:lambda:self.critical('EnterCriticalSection'),0x555020:lambda:self.critical('LeaveCriticalSection'),0x530c70:self.get_mem,0x530c88:self.free_mem,0x5552d8:self.delete_object,0x5553f8:self.select_object,0x5552b4:self.create_pen,0x555678:self.system_color})
  self.uc.mem_map(0x7000000,4096);self.uc.mem_write(0x7000000,b'\xc3');self.hooks[0x7000000]=self.external_event
 def args(self,n):return list(struct.unpack('<'+'I'*n,self.uc.mem_read(self.uc.reg_read(UC_X86_REG_ESP)+4,n*4)))
 def stdcall(self,result,pop):self.ret(result);self.uc.reg_write(UC_X86_REG_ESP,self.uc.reg_read(UC_X86_REG_ESP)+pop)
 def critical(self,name):self.events.append({'api':name,'address':self.args(1)[0]});self.stdcall(None,4)
 def get_mem(self):
  size=self.uc.reg_read(UC_X86_REG_EAX);address=self.next_block;self.next_block=(address+size+15)&~15
  self.uc.mem_write(address,b'\xa5'*size);self.blocks[address]=size;self.events.append({'api':'GetMem','size':size});self.ret(address)
 def free_mem(self):self.events.append({'api':'FreeMem','address':self.uc.reg_read(UC_X86_REG_EAX)});self.ret()
 def delete_object(self):self.events.append({'api':'DeleteObject','handle':self.args(1)[0]});self.stdcall(self.delete_result,4)
 def select_object(self):
  hdc,handle=self.args(2);self.events.append({'api':'SelectObject','hdc':hdc,'handle':handle});self.stdcall(0x11220000,8)
 def create_pen(self):
  pointer=self.args(1)[0];self.events.append({'api':'CreatePenIndirect','logpen_hex':bytes(self.uc.mem_read(pointer,12)).hex()});self.stdcall(self.create_result,4)
 def system_color(self):self.events.append({'api':'GetSysColor','index':self.args(1)[0]});self.stdcall(0x224466,4)
 def external_event(self):self.events.append({'api':'event','target':0x7000000,'owner':self.uc.reg_read(UC_X86_REG_EAX),'sender':self.uc.reg_read(UC_X86_REG_EDX)});self.ret()
 def checksum(self,data):
  p=self.alloc(len(data));self.uc.mem_write(p,data);self.uc.reg_write(UC_X86_REG_EAX,p);self.uc.reg_write(UC_X86_REG_EDX,len(data));return self.call(0x4e2d30,b'')&0xffff
 def operation(self,op):
  self.uc.reg_write(UC_X86_REG_EAX,PEN);self.uc.reg_write(UC_X86_REG_EDX,op.get('color',0))
  value=self.call(0x4e3e50 if op['op']=='color' else 0x4e3e78,b'')
  return value
 def state(self,segments):
  addresses={s['address']:len(bytes.fromhex(s['hex'])) for s in segments};addresses.update(self.blocks)
  result={'segments':[{'address':a,'hex':bytes(self.uc.mem_read(a,n)).hex()} for a,n in sorted(addresses.items())],'events':self.events.copy(),'fs_head':self.u32(0),'ordered_nodes':[]}
  p=self.u32(REG+4)
  while p:
   if len(result['ordered_nodes'])>100:raise RuntimeError('Unexpected cycle')
   result['ordered_nodes'].append(p);p=self.u32(p)
  return result

def record(color,width=2,style=0):return struct.pack('<IIII',0,color,width,style)
def case(name,target,refs=1,existing=False,middle=False,event=0,selected=False,old_handle=0x44440001,pen_lock=False,collision=False,create=0x77770001,delete=1,get_only=False,repeat=False):
 o=PenOracle();o.create_result=create;o.delete_result=delete;old=0x2001000;match=0x2001100;head=match if middle or existing or collision else old
 segments=[]
 def put(a,b):o.uc.mem_write(a,bytes(b));segments.append({'address':a,'hex':b.hex()})
 nodes=[old]+([match] if head!=old else [])
 for a in nodes:
  data=record(0x112233) if a==old else record(target^1,18) if collision else record(target)
  node=bytearray(b'\xa5'*32);struct.pack_into('<IIIH',node,0,0 if a==old else old,refs if a==old else 2,old_handle if a==old else 0,o.checksum(data));node[16:]=data
  if collision and a==match:assert o.checksum(data)==o.checksum(record(target)) and data!=record(target)
  put(a,node)
 reg=bytearray(0x24);struct.pack_into('<II',reg,0,0x4e2d1c,head);struct.pack_into('<H',reg,0x20,16);put(REG,reg)
 pen=bytearray(0x1c);struct.pack_into('<I',pen,0,0x4e2420);struct.pack_into('<II',pen,8,event,CANVAS);struct.pack_into('<II',pen,16,old,0x2000300 if pen_lock else 0);pen[24]=4;put(PEN,pen)
 canvas=bytearray(0x64);struct.pack_into('<II',canvas,0,0x4e80d0,0x11110042);canvas[8]=0x84 if selected else 0x80;put(CANVAS,canvas)
 o.u32(0x59a9e4,REG);o.u32(0x59a9a0,0x55550002)
 world={'source_sha256':EXPECTED,'scope':'Explicit diagnostic native graph and API outcomes; not captured/live VCL state','globals':{'0x59a9e4':REG,'0x59a9a0':0x55550002},'thread':{'fs_base':0,'exception_head':0xffffffff,'stack_base':0x9000000,'stack_size':0x100000,'stack_pointer':0x90ffe00,'stack_origin':'fresh_committed_pages'},'segments':segments,'external_events':[0x7000000] if event==0x7000000 else []}
 operations=[{'op':'handle'}] if get_only else [{'op':'color','color':target}]
 if create is not None and not get_only:operations.append({'op':'handle'})
 if repeat:operations.append(operations[-1].copy())
 steps=[]
 for op in operations:
  value=o.operation(op);steps.append({'operation':op,'value':value,'state':o.state(segments)})
 return {'name':name,'world':world,'api_outcomes':{'create':create,'delete':delete},'steps':steps}
def main():
 cases=[case('same record retains shared handle',0x112233,repeat=True),
 case('new key frees old handle selected Canvas notification',0xabcdef,event=0x4e4dec,selected=True,pen_lock=True),
 case('existing different key keeps old shared reference',0x445566,refs=2,existing=True,event=0x4e4dec),
 case('middle old node unlink',0x778899,middle=True,event=0x4e4dec,selected=True),
 case('same hash distinct key comparison',0x765432,collision=True,event=0x4e4dec),
 case('no old native handle still frees record',0x991133,old_handle=0),
 case('external OnChange ordering',0x220044,event=0x7000000),
 case('DeleteObject failure does not skip FreeMem',0x331155,delete=0,event=0x4e4dec,selected=True),
 case('lazy system color native lookup',0x8000000f,event=0x4e4dec),
 case('lazy CreatePen failure retried',0x559911,create=0,repeat=True),
 case('already cached native handle no allocation or locks',0x112233,get_only=True),
 case('lazy original handle from old shared zero',0x112233,old_handle=0,get_only=True,repeat=True)]
 output={'source_sha256':EXPECTED,'scope':'Actual native instructions with declared locks/memory/Win32 callback outcomes; no target handles used','cases':cases}
 p=ROOT/'godot/tests/fixtures/original_pen.json';p.write_text(json.dumps(output,indent=2)+'\n');print(json.dumps({'cases':len(cases),'steps':sum(len(c['steps']) for c in cases)}))
if __name__=='__main__':main()
