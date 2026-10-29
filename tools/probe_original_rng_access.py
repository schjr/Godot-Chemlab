"""Bounded original4028EC RNG access evidence; no startup seed inference."""
import json,struct
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
from original_x86_oracle import OriginalOracle,ROOT,EXPECTED
class RngAccessOracle(OriginalOracle):
 def __init__(self):
  super().__init__();self.tls=self.alloc(0x100);self.tls_calls=0
  self.u32(self.tls+0x44,0x12345678);self.u32(self.tls+0x48,0x9abcdef0)
  self.hooks[0x53ca64]=self.get_tls
 def get_tls(self):self.tls_calls+=1;self.ret(self.tls)
 def state(self):return bytes(self.uc.mem_read(self.tls+0x44,8)).hex()
def main():
 cases=[]
 for bound in [0,5]:
  oracle=RngAccessOracle();before=oracle.state();value=oracle.call(0x4028ec,struct.pack('<i',bound))
  cases.append({'bound':bound,'return':value,'before_rng_hex':before,'after_rng_hex':oracle.state(),'tls_access_count':oracle.tls_calls})
 oracle=RngAccessOracle()
 instructions=[{'address':hex(i.address),'bytes':i.bytes.hex(),'mnemonic':i.mnemonic,'operands':i.op_str} for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(bytes(oracle.uc.mem_read(0x4028ec,26)),0x4028ec)]
 result={'source_sha256':EXPECTED,'scope':'Actual original4028EC execution with explicit diagnostic TLS bytes, not real startup/process seed','cases':cases,'instructions':instructions}
 (ROOT/'godot/docs/original_logic/rng_lazy_access_evidence.json').write_text(json.dumps(result,indent=2)+'\n')
 assert cases[0]['tls_access_count']==0 and cases[0]['before_rng_hex']==cases[0]['after_rng_hex']
 assert cases[1]['tls_access_count']>0 and cases[1]['before_rng_hex']!=cases[1]['after_rng_hex']
 print(json.dumps(cases))
if __name__=='__main__':main()
