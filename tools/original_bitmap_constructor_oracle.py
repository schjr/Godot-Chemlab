"""Actual original TBitmap/InitInstance writes; raw manager allocation explicit.
Guard/poison bytes are diagnostic inputs, never assumed original heap defaults.
"""
import json,struct
from original_x86_oracle import OriginalOracle,ROOT,EXPECTED
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX,UC_X86_REG_EIP
class BitmapOracle(OriginalOracle):
 def __init__(self,case):
  super().__init__();self.case=case;self.blocks=[];self.events=[];self.failed=False;self.next=0x2000010
  self.hooks.update({0x5306b0:self.allocate,0x530d64:self.runtime_error})
  self.uc.mem_write(0x574b54,bytes([case['monochrome']]))
 def allocate(self):
  n=self.uc.reg_read(UC_X86_REG_EAX);index=len(self.blocks)
  if index==self.case.get('fail_allocation',-1):self.events.append(dict(api='MemoryManager.GetMem',address=0x5306b0,size=n,result=0));self.ret(0);return
  a=self.next;self.next+=0x200;raw=bytes([self.case['poison']])*n;guard=bytes([0xcc])*16
  self.uc.mem_write(a-16,guard+raw+guard);self.blocks.append(dict(address=a,size=n,initial_hex=raw.hex()));self.events.append(dict(api='MemoryManager.GetMem',address=0x5306b0,size=n,result=a));self.ret(a)
 def runtime_error(self):
  self.failed=True;self.events.append(dict(api='OriginalRuntimeError',code=self.uc.reg_read(UC_X86_REG_EAX)&255));self.uc.reg_write(UC_X86_REG_EIP,self.stop_address)
 def run(self):
  initial=[];pointer=0x4e2af4
  if self.case['flag'] in (0,129):
   pointer=0x2100010;raw=bytearray([self.case['poison']]*0x34);struct.pack_into('<I',raw,0,0x4e2af4)
   self.uc.mem_write(pointer-16,b'\xcc'*16+raw+b'\xcc'*16);initial.append(dict(address=pointer,size=0x34,initial_hex=raw.hex()))
  self.uc.reg_write(UC_X86_REG_EAX,pointer);self.uc.reg_write(UC_X86_REG_EDX,self.case['flag']);value=self.call(0x4e8edc,b'')
  for b in initial+self.blocks:b.update(final_hex=bytes(self.uc.mem_read(b['address'],b['size'])).hex(),prefix_hex=bytes(self.uc.mem_read(b['address']-16,16)).hex(),suffix_hex=bytes(self.uc.mem_read(b['address']+b['size'],16)).hex())
  alias=None
  if not self.failed:
   shared=self.u32(value+0x20);before=bytes(self.uc.mem_read(shared,0x74)).hex();self.uc.reg_write(UC_X86_REG_EAX,shared);self.call(0x4e843c,b'');alias=dict(shared=shared,before_hex=before,after_hex=bytes(self.uc.mem_read(shared,0x74)).hex())
  return dict(input=self.case,constructor_return=value,failed=self.failed,events=self.events,blocks=initial+self.blocks,allocations=self.blocks,fs_after=self.u32(0),alias_addref=alias)
def main():
 cases=[]
 for flag in [1,0,129]:
  for mono in [0,1]:
   for poison in [0,0xa5,0xff]:cases.append(BitmapOracle(dict(flag=flag,monochrome=mono,poison=poison)).run())
 for fail in [0,1]:cases.append(BitmapOracle(dict(flag=1,monochrome=0,poison=0xa5,fail_allocation=fail)).run())
 out=ROOT/'godot/tests/fixtures/original_bitmap_constructor.json';out.write_text(json.dumps(dict(source_sha256=EXPECTED,scope=__doc__,cases=cases),indent=2)+'\n');print('Executed',len(cases),'native TBitmap constructors')
if __name__=='__main__':main()
