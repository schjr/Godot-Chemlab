"""Execute original ChemLab arithmetic instructions for bounded reference cases.

The PE is never launched as a process. Unicorn executes selected original x86
functions; hosted AnsiString operations and message presentation are explicit
boundaries. This does not establish equivalence of the whole Windows app.
Use uv's workspace environment with unicorn==2.1.4 and capstone==5.0.9.
"""
from pathlib import Path
import struct
import json
import hashlib
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX,UC_X86_REG_ECX,UC_X86_REG_EIP,UC_X86_REG_ESP,UC_X86_REG_EBP,UC_X86_REG_EFLAGS,UC_X86_REG_FPCW

ROOT=Path(__file__).resolve().parents[1]
BINARY=ROOT/'artifacts/ChemLab/_main.exe'
EXPECTED='7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c'

class OriginalOracle:
    def __init__(self):
        raw=BINARY.read_bytes()
        if hashlib.sha256(raw).hexdigest()!=EXPECTED:raise ValueError('Original binary identity mismatch')
        nt=struct.unpack_from('<I',raw,0x3c)[0]
        count=struct.unpack_from('<H',raw,nt+6)[0];optsize=struct.unpack_from('<H',raw,nt+20)[0]
        self.base=struct.unpack_from('<I',raw,nt+24+28)[0]
        image_size=struct.unpack_from('<I',raw,nt+24+56)[0]
        self.uc=Uc(UC_ARCH_X86,UC_MODE_32)
        self.uc.mem_map(self.base,(image_size+4095)&~4095)
        self.uc.mem_write(self.base,raw[:struct.unpack_from('<I',raw,nt+24+60)[0]])
        for i in range(count):
            offset=nt+24+optsize+i*40
            _,rva,size,ptr=struct.unpack_from('<4I',raw,offset+8)
            if size:self.uc.mem_write(self.base+rva,raw[ptr:ptr+size])
        # A flat zero-based FS segment supplies the structured-exception frame.
        # No Windows exceptions are swallowed or dispatched by this oracle.
        self.uc.mem_map(0,4096);self.u32(0,0xffffffff)
        self.uc.mem_map(0x1000000,0x2000000)
        self.uc.mem_map(0x9000000,0x100000)
        self.uc.mem_map(0x8000000,4096)
        self.stop_address=0x8000000
        self.uc.reg_write(UC_X86_REG_FPCW,0x037f)
        self.allocation=0x1000000
        self.vessels=[];self.messages=[];self.boundary_calls=[]
        self.catalog=json.loads((ROOT/'godot/data/reagents.json').read_text())
        self.species={r['species']:r for r in self.catalog}
        self.reagent_indices={r['species']:i for i,r in enumerate(self.catalog)}
        for i,r in enumerate(self.catalog):
            p=self.alloc(0xc0);self.u32(0x57bc08+i*4,p)
            self.u32(p+4,self.string(r['species']))
            self.f64(p+0x10,float(r['molar_mass']))
            self.f64(p+0x30,float(r['raw_fields'][7]))
        self.hooks={0x4016e8:self.construct_empty,0x540ec4:self.construct_cstr,
                    0x540efc:self.copy_string,0x541018:self.copy_string,
                    0x540fe8:self.destroy_string,0x5410cc:self.equal_string,
                    0x452acc:self.phase_string,0x461db4:self.find_species,
                    0x452d9c:self.find_reagent,0x500350:self.show_message}
        self.uc.hook_add(UC_HOOK_CODE,self.on_instruction)
    def alloc(self,size):
        p=self.allocation;self.allocation=(p+size+15)&~15
        if self.allocation>=0x3000000:raise MemoryError('Oracle allocation budget exceeded')
        return p
    def u32(self,addr,value=None):
        if value is None:return struct.unpack('<I',self.uc.mem_read(addr,4))[0]
        self.uc.mem_write(addr,struct.pack('<I',int(value)&0xffffffff))
    def f64(self,addr,value=None):
        if value is None:return struct.unpack('<d',self.uc.mem_read(addr,8))[0]
        self.uc.mem_write(addr,struct.pack('<d',value))
    def string(self,text):
        b=text.encode('gb18030') if isinstance(text,str) else text
        p=self.alloc(len(b)+9);self.u32(p,1);self.u32(p+4,len(b));self.uc.mem_write(p+8,b+b'\0')
        return p+8
    def bytes_at(self,p):
        if p==0:return b''
        out=bytearray()
        for i in range(20000):
            v=self.uc.mem_read(p+i,1)[0]
            if v==0:return bytes(out)
            out.append(v)
        raise ValueError('Unbounded oracle string')
    def text_at(self,p):return self.bytes_at(p).decode('gb18030')
    def ret(self,result=None):
        if result is not None:self.uc.reg_write(UC_X86_REG_EAX,int(result)&0xffffffff)
        sp=self.uc.reg_read(UC_X86_REG_ESP);address=self.u32(sp)
        self.uc.reg_write(UC_X86_REG_ESP,sp+4);self.uc.reg_write(UC_X86_REG_EIP,address)
    def construct_empty(self):
        dst=self.uc.reg_read(UC_X86_REG_EAX);self.u32(dst,0);self.ret(dst)
    def construct_cstr(self):
        dst=self.uc.reg_read(UC_X86_REG_EAX);src=self.uc.reg_read(UC_X86_REG_EDX)
        self.u32(dst,self.string(self.bytes_at(src)));self.ret(dst)
    def copy_string(self):
        dst=self.uc.reg_read(UC_X86_REG_EAX);src=self.uc.reg_read(UC_X86_REG_EDX)
        self.u32(dst,self.u32(src));self.ret(dst)
    def destroy_string(self):
        dst=self.uc.reg_read(UC_X86_REG_EAX);self.u32(dst,0);self.ret(dst)
    def equal_string(self):
        a=self.u32(self.uc.reg_read(UC_X86_REG_EAX));b=self.u32(self.uc.reg_read(UC_X86_REG_EDX))
        result=int(self.bytes_at(a)==self.bytes_at(b))
        flags=self.uc.reg_read(UC_X86_REG_EFLAGS)&~(0x1|0x4|0x40|0x80|0x800)
        if result==0:flags|=0x40|0x4
        self.uc.reg_write(UC_X86_REG_EFLAGS,flags);self.ret(result)
    def phase_string(self):
        sp=self.uc.reg_read(UC_X86_REG_ESP);dst=self.u32(sp+4);src=self.u32(sp+8)
        name=self.bytes_at(src);i=name.rfind(b'(')
        phase=name[i:].split(b' ',1)[0] if i>=0 else b''
        self.u32(dst,self.string(phase));self.ret(dst)
    def find_species(self):
        sp=self.uc.reg_read(UC_X86_REG_ESP);idx=self.u32(sp+4);name=self.bytes_at(self.u32(sp+8))
        p=self.vessels[idx]
        found=next((i for i in range(self.u32(p+0x104)) if self.bytes_at(self.u32(p+0x108+4*i))==name),-1)
        self.ret(found)
    def find_reagent(self):
        sp=self.uc.reg_read(UC_X86_REG_ESP);name=self.text_at(self.u32(sp+4))
        if name not in self.reagent_indices:raise ValueError('Original reagent lookup unresolved: '+name)
        self.ret(self.reagent_indices[name])
    def show_message(self):
        self.messages.append(self.text_at(self.uc.reg_read(UC_X86_REG_EAX)));self.ret(1)
    def on_instruction(self,uc,address,size,unused):
        if address==self.stop_address:uc.emu_stop();return
        if address in self.hooks:
            self.boundary_calls.append(hex(address));self.hooks[address]();return
        if not self.base<=address<self.base+0x200000:raise RuntimeError(f'Unresolved native boundary {address:#x}')
    def add_vessel(self,contents,temperature=20.0,capacity=100.0,volume_cache=None):
        p=self.alloc(0x5000);idx=len(self.vessels);self.vessels.append(p);self.u32(0x585850+4*idx,p)
        self.u32(p+0x104,len(contents));self.f64(p+0x88,temperature);self.f64(p+0x28,capacity)
        for i,(species,n) in enumerate(contents.items()):
            self.u32(p+0x108+4*i,self.string(species));self.f64(p+0x8d8+8*i,float(n))
            self.f64(p+0x5b8+8*i,float((volume_cache or {}).get(species,0)))
        self.call(0x461e54,struct.pack('<I',idx))
        return idx
    def call(self,address,args):
        sp=0x90ffe00
        self.uc.mem_write(sp,struct.pack('<I',self.stop_address)+args)
        self.uc.reg_write(UC_X86_REG_ESP,sp);self.uc.reg_write(UC_X86_REG_EBP,0)
        self.u32(0,0xffffffff)
        try:self.uc.emu_start(address,self.stop_address,count=2000000)
        except Exception as error:
            pc=self.uc.reg_read(UC_X86_REG_EIP)
            raise RuntimeError(f'Native oracle failed at {pc:#x}: {error}') from error
        if self.uc.reg_read(UC_X86_REG_EIP)!=self.stop_address:raise RuntimeError('Native oracle instruction budget exceeded')
        return self.uc.reg_read(UC_X86_REG_EAX)
    def snapshot(self,index):
        p=self.vessels[index];count=self.u32(p+0x104)
        return {'contents':{self.text_at(self.u32(p+0x108+4*i)):self.f64(p+0x8d8+8*i) for i in range(count)},
                'masses':{self.text_at(self.u32(p+0x108+4*i)):self.f64(p+0x298+8*i) for i in range(count)},
                'volumes':{self.text_at(self.u32(p+0x108+4*i)):self.f64(p+0x5b8+8*i) for i in range(count)},
                'temperature':self.f64(p+0x88),'liquid_volume':self.f64(p+0x4320),'solid_volume':self.f64(p+0x4338),'gas_moles':self.f64(p+0x4328),'gas_volume':self.f64(p+0x4330),'pressure':self.f64(p+0xa8)}

def main():
    oracle=OriginalOracle()
    a=oracle.add_vessel({'H2O(液体)':2.2202486678508,'NaOH(溶解)':0.1,'Zn(固体)':0.01,'CO2(气体)':0.001},40)
    b=oracle.add_vessel({'H2O(液体)':0.5},20)
    before=[oracle.snapshot(a),oracle.snapshot(b)]
    oracle.call(0x476ddc,struct.pack('<IId',a,b,2.0))
    result={'binary_sha256':EXPECTED,'function':'0x00476ddc','requested_volume':2.0,'before':before,'after':[oracle.snapshot(a),oracle.snapshot(b)],
            'boundary_calls':sorted(set(oracle.boundary_calls)),'messages':oracle.messages,
            'limitations':['Original arithmetic is executed; AnsiString operations and lookup/message boundaries are hosted.',
                           'Oracle starts with explicitly zero-initialized volume slots and x87 control word 0x037f.',
                           'No whole-application or Win32 UI equivalence is claimed.']}
    output=ROOT/'evidence/original_logic/native-transfer-oracle.json';output.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n')
    print(json.dumps(result,ensure_ascii=False,indent=2))

if __name__=='__main__':main()
