"""Bounded x87 PC64 arithmetic oracle (no application execution).
The instruction forms are native FLD/FMUL/FDIV/FADD/FSTP qword forms.  These
arithmetic microfixtures prove arithmetic behavior, not Windows process state.
"""
from pathlib import Path
import json, struct, random
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32
from unicorn.x86_const import UC_X86_REG_FPCW
ROOT = Path(__file__).resolve().parents[1]
def number(hexstr): return struct.unpack('<d',bytes.fromhex(hexstr))[0]
def bits(value): return struct.pack('<d',value).hex()
def run(a,b,c,kind):
    u=Uc(UC_ARCH_X86,UC_MODE_32);u.mem_map(0x100000,0x1000)
    u.reg_write(UC_X86_REG_FPCW,0x037f)
    addr=lambda x:struct.pack('<I',x)
    code=b'\xdd\x05'+addr(0x100200)
    if kind=='multiply_divide':
        code+=b'\xdc\x0d'+addr(0x100208)+b'\xdc\x35'+addr(0x100210)
    elif kind=='divide_multiply_subtract':
        code+=b'\xdc\x35'+addr(0x100208)+b'\xdc\x0d'+addr(0x100210)
        code+=b'\xdc\x2d'+addr(0x100210) # reverse subtract c minus extended product
    else: raise ValueError(kind)
    code+=b'\xdd\x1d'+addr(0x100218)
    u.mem_write(0x100000,code);u.mem_write(0x100200,struct.pack('<ddd',a,b,c))
    u.emu_start(0x100000,0x100000+len(code),count=20)
    return bytes(u.mem_read(0x100218,8)).hex()
def main():
    cases=[]
    samples=[number('0000000001000000'),number('0100000000000000'),number('ffffffffffff0f00'),number('0000000000001000')]
    rng=random.Random(4634)
    samples += [struct.unpack('<d', struct.pack('<Q',rng.randrange(1,1<<52)))[0] for _ in range(64)]
    for value in samples:
        for multiplier, divisor in [(0.001,22.4),(.125,1e-310),(-.2,1.8)]:
            cases.append(dict(kind='multiply_divide', a_bits=bits(value),b_bits=bits(multiplier),c_bits=bits(divisor),expected_bits=run(value,multiplier,divisor,'multiply_divide')))
    for a,b,c in [(0.2,1.8,.0045),(1.,3.,3.),(1.,7.,7.),(1.,9.,9.),(.2,2.,.005)]:
        cases.append(dict(kind='divide_multiply_subtract',a_bits=bits(a),b_bits=bits(b),c_bits=bits(c),expected_bits=run(a,b,c,'divide_multiply_subtract')))
    out=ROOT/'godot/tests/fixtures/original_x87_arithmetic.json'
    out.write_text(json.dumps(dict(provenance='Unicorn x86 x87 instruction microkernels; PC64 nearest-even CW037f; not guest hardware profile',cases=cases),indent=2)+'\n')
    print('Captured',len(cases),'x87 arithmetic microfixtures')
if __name__=='__main__':main()
