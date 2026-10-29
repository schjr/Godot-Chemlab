"""Retained46F704 physical-stack reads/stores for explicit boundary cases."""
import json
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
from original_gasflow_oracle import GasOracle
from original_x86_oracle import ROOT,EXPECTED
from original_actions_oracle import bits
from unicorn.x86_const import UC_X86_REG_EBP

class StackOracle(GasOracle):
    def __init__(self,operand):
        super().__init__();self.operand=operand;self.stack_events=[];self.initial_hex='';self.final_hex=''
    def call(self,address,args):
        if address==0x46f704:
            # OriginalOracle.call enters with ESP90FFE00; PUSH EBP therefore
            # establishes gas EBP90FFDFC, and [EBP-7C] is90FFD80.
            self.f64(0x90ffd80,self.operand);self.initial_hex=bits(self.operand)
        result=super().call(address,args)
        if address==0x46f704:self.final_hex=bytes(self.uc.mem_read(0x90ffd80,8)).hex()
        return result
    def on_instruction(self,uc,address,size,unused):
        if address==0x46fadd and self.recent and self.recent[-1][0]=='0x46fada':
            self.stack_events.append(dict(pc=0x46fada,operation='write',raw_hex=bytes(uc.mem_read(uc.reg_read(UC_X86_REG_EBP)-0x7c,8)).hex()))
        if address==0x46fb18:
            self.stack_events.append(dict(pc=address,operation='read',raw_hex=bytes(uc.mem_read(uc.reg_read(UC_X86_REG_EBP)-0x7c,8)).hex()))
        super().on_instruction(uc,address,size,unused)

def main():
    corpus=json.loads((ROOT/'godot/tests/fixtures/original_gasflow.json').read_text())
    cases=[]
    for name in ['一氧化碳还原氧化铁','一氧化碳还原氧化铜','closed excess gas / empty outlet']:
        source=next(c for c in corpus['cases'] if c['name']==name)
        for operand in [12.5,-4.25]:
            oracle=StackOracle(operand)
            case=oracle.case(dict(name=name,vessels=source['vessels'],connectors=source.get('connectors',[])))
            case.update(initial_stack_hex=oracle.initial_hex,final_stack_hex=oracle.final_hex,stack_events=oracle.stack_events)
            cases.append(case)
    result=dict(binary_sha256=EXPECTED,scope='Actual46F704 instructions with explicit initial physical stack QWORD; source strings/bitmap boundaries hosted as original gasflow oracle. Verification inputs only, never production stack initialization.',cases=cases)
    (ROOT/'godot/tests/fixtures/original_gas_stack_boundary.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n')
    lines=['; Original PE SHA256 '+EXPECTED,'; Source ABI fragments; omitted ranges are not represented as executed.']
    decoder=Cs(CS_ARCH_X86,CS_MODE_32)
    for address,size in [(0x4018b0,0x25),(0x4019d6,0x19),(0x46f704,0x14),(0x46fac9,0x72)]:
        lines.append('; Fragment '+hex(address))
        for instruction in decoder.disasm(bytes(oracle.uc.mem_read(address,size)),address):
            lines.append(f'{instruction.address:08x}: {instruction.bytes.hex():24s} {instruction.mnemonic} {instruction.op_str}')
    (ROOT/'godot/docs/original_logic/gas_stack_abi.asm').write_text('\n'.join(lines)+'\n')
    print(json.dumps(dict(cases=len(cases),statuses=[c['status'] for c in cases],events=sum(len(c['stack_events']) for c in cases))))

if __name__=='__main__':main()
