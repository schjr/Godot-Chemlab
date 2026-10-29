"""Execute original assignment/evaluator and CRT numeric formatting instructions."""
from pathlib import Path
import json,struct,random,subprocess
from original_x86_oracle import OriginalOracle,EXPECTED
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX,UC_X86_REG_ECX,UC_X86_REG_ESP
ROOT=Path(__file__).resolve().parents[1]
class ProgramOracle(OriginalOracle):
    def __init__(self):
        super().__init__()
        self.hooks.update({0x402908:self.c_str,0x531f60:self.set_string_length})
        self.form=self.alloc(0x80000)
        # Explicit '.' locale fixture. Native formatter/parser read this byte;
        # VCL normally initializes it from the Windows locale at startup.
        self.uc.mem_write(0x59ac33,b'.')
        self.track=False;self.formatted=[];self.log_inputs=[]
        self.hooks[0x540f7c]=self.record_format
        self.hooks[0x5397ec]=self.record_log
    def record_log(self):
        if self.track:self.log_inputs.append(self.f64(self.uc.reg_read(UC_X86_REG_ESP)+4))
    def record_format(self):
        if self.track:
            sp=self.uc.reg_read(UC_X86_REG_ESP)
            self.formatted.append(self.f64(sp+4))
        # Read-only observation; the original instructions still execute.
    def c_str(self):
        self.ret(self.u32(self.uc.reg_read(UC_X86_REG_EAX)))
    def set_string_length(self):
        dst=self.uc.reg_read(UC_X86_REG_EAX);src=self.uc.reg_read(UC_X86_REG_EDX);size=self.uc.reg_read(UC_X86_REG_ECX)
        self.u32(dst,self.string(bytes(self.uc.mem_read(src,size))));self.ret(dst)
    def format_number(self,value):
        dst=self.alloc(4);self.uc.reg_write(UC_X86_REG_EAX,dst)
        self.call(0x540f7c,struct.pack('<d',value))
        return self.text_at(self.u32(dst))
    def assignment(self,text,variables):
        self.track=False
        self.u32(self.form+0xe20,len(variables))
        for i,(name,value) in enumerate(variables.items()):
            self.u32(self.form+0xe60+i*0x44,self.string(self.format_number(value)))
            self.u32(self.form+0xe60+i*0x44+4,self.string(self.format_number(value)))
            self.u32(self.form+0xe60+i*0x44-8,self.string(name))
        self.track=True;self.formatted=[];self.log_inputs=[]
        result=self.call(0x44dacc,struct.pack('<II',self.form,self.string(text)))
        self.track=False
        return result,{name:self.text_at(self.u32(self.form+0xe60+i*0x44)) for i,name in enumerate(variables)}
def main():
    oracle=ProgramOracle()
    def bits(x):return struct.pack('<d',x).hex()
    rng=random.Random(0x44dacc)
    values=[0.0,0.12345678901234567,1e-8,1e-20,1e25,18.016]
    values += [rng.uniform(-1,1)*10**rng.uniform(-25,25) for _ in range(200)]
    formats=[{'bits':bits(v),'text':oracle.format_number(v)} for v in values]
    cases=[]
    for i in range(100):
        expression='ph1=-log10(1000*h1/a1)' if i%2 else 'ph1=-log10(1000.0*h1/a1)'
        inputs={'ph1':0.0,'h1':10**rng.uniform(-12,-3),'a1':rng.uniform(1,100)}
        result,outputs=oracle.assignment(expression,inputs)
        ref={}
        for value in oracle.log_inputs:
            encoded=subprocess.check_output(['/private/tmp/chemlab-x87-reference','log10',format(value,'.17g')],text=True).split()[0]
            hardware=struct.unpack('<d',bytes.fromhex(encoded))[0]
            ref['ph1']=oracle.format_number(-hardware)
        cases.append({'expression':expression,'inputs_bits':{k:bits(v) for k,v in inputs.items()},'ok':bool(result&255),'outputs':outputs,'format_values':[bits(v) for v in oracle.formatted],'x87_reference_outputs':ref})
    for expression,inputs in [('a_all=a+a1',{'a_all':0.0,'a':0.04,'a1':0.002}),('v=1+2*3/4',{'v':0.0}),('v=-(1+2)',{'v':0.0}),('v=a+b+c',{'v':0.0,'a':0.1234567890123456,'b':0.00123,'c':0.007})]:
        result,outputs=oracle.assignment(expression,inputs)
        cases.append({'expression':expression,'inputs_bits':{k:bits(v) for k,v in inputs.items()},'ok':bool(result&255),'outputs':outputs,'format_values':[bits(v) for v in oracle.formatted]})
    output={'binary_sha256':EXPECTED,'entry':'0x0044DACC','locale_decimal_separator':'.',
            'format_entry':'0x00540F7C','formats':formats,'cases':cases,
            'boundaries':['Managed AnsiString ownership and C-string/length construction only; original formatter/parser/evaluator instructions execute.']}
    (ROOT/'godot/tests/fixtures/original_program.json').write_text(json.dumps(output,ensure_ascii=False,indent=2)+'\n')
    print(f"Original assignment evaluator: {len(cases)} cases; formatting {len(formats)} values")
if __name__=='__main__':main()
