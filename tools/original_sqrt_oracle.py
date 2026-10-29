"""Original53ACE8 FSQRT; a declared output-store trampoline captures its80bit return."""
import json,struct,random
from original_x86_oracle import OriginalOracle,ROOT,EXPECTED
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EBP,UC_X86_REG_FPTAG,UC_X86_REG_FPSW
class SqrtOracle(OriginalOracle):
 def sqrt(self,x):
  dst=self.alloc(16);trampoline=0x8000200
  self.uc.mem_write(trampoline,b'\xdb\x3d'+struct.pack('<I',dst)+b'\xe9'+struct.pack('<i',self.stop_address-(trampoline+11)))
  sp=0x90ffe00;self.uc.mem_write(sp,struct.pack('<Id',trampoline,x));self.uc.reg_write(UC_X86_REG_ESP,sp);self.uc.reg_write(UC_X86_REG_EBP,0);self.uc.reg_write(UC_X86_REG_FPTAG,0xffff);self.uc.reg_write(UC_X86_REG_FPSW,0)
  self.uc.emu_start(0x53ace8,self.stop_address,count=1000)
  return {'input_bits':struct.pack('<d',x).hex(),'extended80':bytes(self.uc.mem_read(dst,10)).hex()}
def main():
 rng=random.Random(0x53ace8);o=SqrtOracle();values=[0.0,1.0,2.0,3.0,4.0,.25,.5,1e-100,1e100]+[float(i) for i in range(1,1000)]+[rng.uniform(.1,1e8) for _ in range(1000)]
 result={'binary_sha256':EXPECTED,'entry':'0053ACE8','capture':'DeclaredFSTP_TBYTE+JMP outputtrampoline; originalFSQRT executes unchanged PC64','cases':[o.sqrt(x) for x in values]}
 (ROOT/'godot/tests/fixtures/original_sqrt.json').write_text(json.dumps(result,indent=2)+'\n');print('native sqrt',len(values))
if __name__=='__main__':main()
