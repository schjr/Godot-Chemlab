"""Execute original534368 selection with explicit host module/export outcomes."""
import json,struct,itertools
from original_x86_oracle import OriginalOracle,ROOT,EXPECTED
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP
GLOBALS=[0x575980,0x575984,0x575988,0x57598c,0x575990,0x575994,0x575604,0x575608,0x57560c,0x59b224,0x59b228,0x59b22c,0x59b230,0x59b234,0x59b238]
class SelectionOracle(OriginalOracle):
 def __init__(self,case):
  super().__init__();self.case=case;self.events=[];self.fatal=False;self.uc.mem_map(0x71000000,0x10000)
  self.hooks.update({0x554f66:self.module,0x554f72:self.proc,0x53b954:self.abort})
  # Import thunk address is source-derived below, not a host guess.
  self.hooks[case['load_thunk']]=self.load
  for k,v in case.get('initial',{}).items():self.u32(int(k,16),v)
 def args(self,n):return struct.unpack('<'+'I'*n,self.uc.mem_read(self.uc.reg_read(UC_X86_REG_ESP)+4,n*4))
 def finish(self,value,pop):self.ret(value);self.uc.reg_write(UC_X86_REG_ESP,self.uc.reg_read(UC_X86_REG_ESP)+pop)
 def module(self):
  name=self.bytes_at(self.args(1)[0]).hex();value=self.case['module'];self.events.append(dict(api='GetModuleHandleA',name_hex=name,result=value));self.finish(value,4)
 def load(self):
  name=self.bytes_at(self.args(1)[0]).hex();value=self.case['load'];self.events.append(dict(api='LoadLibraryA',name_hex=name,result=value));self.finish(value,4)
 def proc(self):
  module,p=self.args(2);name=self.bytes_at(p).decode('ascii');value=self.case['exports'].get(name,0);self.events.append(dict(api='GetProcAddress',module=module,name_hex=name.encode().hex(),result=value))
  if 'HeapAddRef' in name and value:self.hooks[value]=self.addref
  self.finish(value,8)
 def addref(self):self.events.append(dict(api='HeapAddRef',address=self.uc.reg_read(UC_X86_REG_EIP),result=0));self.finish(0,0)
 def abort(self):
  self.fatal=True;self.events.append(dict(api='original_fatal',message_hex=self.bytes_at(self.args(1)[0]).hex()));self.uc.reg_write(UC_X86_REG_EIP,self.stop_address)

def main():
 # Raw original5340F0: PUSH module-name; CALL LoadLibrary thunk.
 from capstone import Cs,CS_ARCH_X86,CS_MODE_32
 image=(ROOT/'godot/data/original_heap_image.bin').read_bytes();ins=list(Cs(CS_ARCH_X86,CS_MODE_32).disasm(image[0x1340f0:0x134110],0x5340f0));thunk=next(int(i.op_str,16) for i in ins if i.mnemonic=='call')
 # Read names directly from mapped image, not guessed decoration.
 names=[]
 for a in [0x57585a,0x575873,0x57588e,0x5758b6,0x5758d0]:names.append(image[a-0x400000:].split(b'\0',1)[0].decode('ascii'))
 cases=[]
 configurations=[('absent',0,0,{},{}),('load mismatch',0x71000000,0,{}, {})]
 for mask in range(32):configurations.append((f'exports mask{mask:02x}',0x71000000,0x71000000,{name:0x71001000+i*0x100 for i,name in enumerate(names) if mask&(1<<i)},{}))
 configurations.append(('preselected System replacement',0x71000000,0x71000000,{name:0x71001000+i*0x100 for i,name in enumerate(names)},{'0x575604':0x72000100,'0x575608':0x72000200,'0x57560c':0x72000300}))
 configurations.append(('prior startup marker fatal',0x71000000,0x71000000,{name:0x71001000+i*0x100 for i,name in enumerate(names)},{'0x575980':7}))
 for label,module,load,exports,initial in configurations:
  case=dict(name=label,module=module,load=load,exports=exports,initial=initial,load_thunk=thunk,argument=1);o=SelectionOracle(case);before={hex(a):o.u32(a) for a in GLOBALS};o.call(0x534368,struct.pack('<I',1));cases.append(dict(input=case,fatal=o.fatal,events=o.events,initial_globals=before,final_globals={hex(a):o.u32(a) for a in GLOBALS}))
 out=ROOT/'godot/tests/fixtures/original_heap_selection.json';out.write_text(json.dumps(dict(source_sha256=EXPECTED,scope=__doc__,cases=cases),indent=2)+'\n');print('Executed',len(cases),'native selection cases; load thunk',hex(thunk))
if __name__=='__main__':main()
