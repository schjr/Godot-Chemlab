"""Actual GetCanvas + actual TBitmapCanvas constructor and empty handle prefix.
Allocator/locks explicit; stops BEFORE real CreateCompatibleDC, never fake DC.
"""
import json,struct
from original_canvas_constructor_oracle import CanvasOracle
from original_x86_oracle import ROOT,EXPECTED
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EIP
class LazyOracle(CanvasOracle):
 def __init__(self,poison):
  super().__init__(poison);self.frontier=None
  self.hooks[0x55527e]=self.dc
  self.hooks[0x4e9070]=self.copy_frontier
 def dc(self):
  self.frontier=dict(api='CreateCompatibleDC',address=0x55527e,hdc=self.args(1)[0]);self.events.append(self.frontier.copy());self.uc.reg_write(UC_X86_REG_EIP,self.stop_address)
 def copy_frontier(self):
  self.frontier=dict(api='unported_native_bitmap_copy',address=0x4e9070);self.events.append(self.frontier.copy());self.uc.reg_write(UC_X86_REG_EIP,self.stop_address)
def case(poison,retained=0,shared_alias=False):
 o=LazyOracle(poison);o.u32(0x59a99c,0x11110022);o.uc.mem_write(0x574b54,b'\0')
 descriptor=bytearray(o.uc.mem_read(0x574b28,44));struct.pack_into('<I',descriptor,0,0xdeadbeef);o.uc.mem_write(0x574b28,bytes(descriptor))
 segments=[dict(address=0x574b28,hex=descriptor.hex())]
 o.run(0x4eb398,end=0x4eb3d7);o.run(0x4eb3e8,end=0x4eb40a)
 bitmap=o.run(0x4e8edc,0x4e2af4,1);shared=o.u32(bitmap+0x20);o.u32(shared+0x14,retained)
 if shared_alias:o.u32(shared+4,2)
 snapshot=o.snapshot(segments)
 world=dict(source_sha256=EXPECTED,scope='Actual source-prepared diagnostic graph, original constructors and explicit poisoned allocation/lock inputs; not actual process capture',segments=snapshot['segments']+[dict(address=0x574d90,hex=struct.pack('<I',o.u32(0x574d90)).hex())],globals={**snapshot['globals'],'0x59a99c':0x11110022},thread=dict(fs_base=0,exception_head=0xffffffff,stack_base=0x9000000,stack_size=0x100000,stack_pointer=0x90ffe00,stack_origin='fresh_committed_pages'))
 world['globals'].pop('0x574d90',None)
 o.events.clear();next_block=o.next_block;steps=[]
 for _i in range(2):
  canvas=o.run(0x4e9448,bitmap);steps.append(dict(op='get_canvas',value=canvas,state=o.snapshot(segments)))
 if retained==0:
  o.run(0x4e4b84,canvas);steps.append(dict(op='handle_prefix',frontier=o.frontier,state=o.snapshot(segments)))
 return dict(poison=poison,retained=retained,shared_alias=shared_alias,bitmap=bitmap,shared=shared,initial_next_block=next_block,world=world,steps=steps)
def main():
 cases=[case(p) for p in [0,0xa5,0xff]]+[case(0xa5,0x12340042),case(0xa5,shared_alias=True)]
 out=ROOT/'godot/tests/fixtures/original_bitmap_canvas.json';out.write_text(json.dumps(dict(source_sha256=EXPECTED,scope=__doc__,cases=cases),indent=2)+'\n');print('Executed',len(cases),'native lazyCanvas graphs')
if __name__=='__main__':main()
