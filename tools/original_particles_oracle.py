"""Execute original persistent-particle routines with explicit VCL boundaries."""
import struct,json,random
from original_x86_oracle import OriginalOracle,ROOT,EXPECTED
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX,UC_X86_REG_ECX,UC_X86_REG_ESP,UC_X86_REG_FPSW,UC_X86_REG_FP0
class ParticleOracle(OriginalOracle):
    def __init__(self,low,high):
        super().__init__();self.tls=self.alloc(0x100)
        self.u32(self.tls+0x44,low);self.u32(self.tls+0x48,high)
        self.hooks[0x53ca64]=lambda:self.ret(self.tls)
        self.trig_values=[];self.pending_trig=None
        self.hooks[0x539238]=lambda:self.trig_input('cos')
        self.hooks[0x53aca8]=lambda:self.trig_input('sin')
        self.hooks[0x49c342]=self.trig_output
        self.hooks[0x49c375]=self.trig_output
        ir=json.loads((ROOT/'godot/data/original_particle_ir.json').read_text())
        for ins in ir['functions']['bubble_update']['instructions']:
            if ins['mnemonic']=='call' and ins['operands'][0]['kind']=='imm' and ins['operands'][0]['value'] in [0x539238,0x53aca8]:self.hooks[ins['next']]=self.trig_output
        self.hooks[0x8000040]=lambda:self.ret(50)
        self.hooks[0x8000050]=lambda:self.ret(40)
        self.pool=self.alloc(0x3468c)
        self.uc.mem_write(self.pool,b'\xa5'*0x3468c)
        self.uc.reg_write(UC_X86_REG_EAX,0x5674e4);self.uc.reg_write(UC_X86_REG_EDX,self.pool)
        self.call(0x531414,b'')
        assert bytes(self.uc.mem_read(self.pool+4,0x34688))==b'\0'*0x34688
        bitmap=self.alloc(16);vmt=self.alloc(0x40);self.u32(bitmap,vmt)
        self.u32(vmt+0x20,0x8000040);self.u32(vmt+0x2c,0x8000050);self.u32(self.pool+0x34678,bitmap)
    def trig_input(self,kind):
        sp=self.uc.reg_read(UC_X86_REG_ESP)
        self.pending_trig=(kind,bytes(self.uc.mem_read(sp+4,8)).hex())
        # Capture only. Original CRT wrapper / FSIN/FCOS still executes.
    def trig_output(self):
        top=(self.uc.reg_read(UC_X86_REG_FPSW)>>11)&7
        significand,exponent=self.uc.reg_read(UC_X86_REG_FP0+top)
        self.trig_values.append(dict(kind=self.pending_trig[0],input_bits=self.pending_trig[1],extended_bits=struct.pack('<QH',significand,exponent).hex()))
    def update_solid(self):
        self.trig_values=[];self.uc.reg_write(UC_X86_REG_EAX,self.pool)
        self.call(0x49c298,b'')
        return dict(expected=self.snapshot(),trig=self.trig_values)
    def create_bubble(self):
        self.bubble=self.alloc(0xfc20)
        for offset,value in [(0x7ef4,1),(0x5164,40),(0x5168,50),(0x7f00,20),(0x5154,0xaaaabb)]:
            self.u32(self.bubble+offset,value)
    def bubble_snapshot(self):
        n=self.u32(self.bubble+0x5150)
        return dict(count=n,call_count=self.u32(self.bubble+0xfc10),center_x=self.u32(self.bubble+0xfc18),center_y=self.u32(self.bubble+0xfc1c),slots=[list(struct.unpack('<13I',self.uc.mem_read(self.bubble+0x10+i*52,52))) for i in range(n)],rng=self.rng())
    def emit_bubbles(self,args):
        self.uc.reg_write(UC_X86_REG_EAX,self.bubble);self.uc.reg_write(UC_X86_REG_EDX,args[0]);self.uc.reg_write(UC_X86_REG_ECX,args[1])
        self.call(0x49a61c,struct.pack('<7i',*args[2:]))
        return self.bubble_snapshot()
    def update_bubbles(self):
        self.trig_values=[];self.uc.reg_write(UC_X86_REG_EAX,self.bubble)
        self.call(0x49aa88,b'')
        return dict(expected=self.bubble_snapshot(),trig=self.trig_values)
    def rng(self):return {'low':self.u32(self.tls+0x44),'high':self.u32(self.tls+0x48)}
    def snapshot(self):
        n=self.u32(self.pool+0x34684)
        return dict(count=n,slots=[list(struct.unpack('<13I',self.uc.mem_read(self.pool+4+i*52,52))) for i in range(n)],rng=self.rng())
    def emit_solid(self,colors,amounts,y,x):
        cp=self.alloc(4*len(colors));ap=self.alloc(4*len(amounts))
        self.uc.mem_write(cp,struct.pack('<'+'I'*len(colors),*colors));self.uc.mem_write(ap,struct.pack('<'+'f'*len(amounts),*amounts))
        self.uc.reg_write(UC_X86_REG_EAX,self.pool);self.uc.reg_write(UC_X86_REG_EDX,cp);self.uc.reg_write(UC_X86_REG_ECX,ap)
        self.call(0x49bf44,struct.pack('<iii',y,x,len(colors)))
        return self.snapshot()
def main():
    cases=[]
    for seed in [dict(low=0,high=0),dict(low=1,high=0),dict(low=0xffffffff,high=0xffffffff),dict(low=0xdeadbeef,high=0x12345678)]:
        o=ParticleOracle(**seed);actions=[]
        for colors,amounts,y,x in [([0xaaaa22],[5.9],10,20),([0x336699],[.99],5,8),([0x779911],[3.0],100,10),([0x123456,0x789abc],[2.,2.],7,11)]:
            actions.append(dict(colors=colors,amount_bits=[struct.pack('<f',v).hex() for v in amounts],y=y,x=x,expected=o.emit_solid(colors,amounts,y,x)))
        cases.append(dict(rng=seed,actions=actions))
    rng_cases=[]
    for seed in [dict(low=0,high=0),dict(low=0xffffffff,high=0xffffffff),dict(low=0xfffffffe,high=2),dict(low=1,high=0)]:
        o=ParticleOracle(**seed);steps=[]
        for _ in range(30):steps.append(dict(result=o.call(0x539c60,b''),state=o.rng()))
        rng_cases.append(dict(initial=seed,steps=steps))
    update_cases=[]
    for seed in [dict(low=1,high=0),dict(low=0xdeadbeef,high=0x12345678)]:
        o=ParticleOracle(**seed);initial=o.emit_solid([0x336699],[7.],2,2);o.u32(o.pool+0x32d50,0x778822)
        frames=[o.update_solid() for _ in range(32)]
        update_cases.append(dict(initial=initial,background=0x778822,frames=frames))
    bubble_cases=[]
    for seed in [dict(low=1,high=0),dict(low=0xdeadbeef,high=0x12345678)]:
        o=ParticleOracle(**seed);o.create_bubble();actions=[]
        for j in range(18):
            args=[10,40,1 if j>8 else 0,12 if j>5 else 0,20 if j>5 else 0,4 if j>11 else 0 if j>8 else 3,8,3,-1 if j>14 else 5]
            actions.append(dict(args=args,expected=o.emit_bubbles(args)))
        bubble_cases.append(dict(rng=seed,actions=actions))
    bubble_updates=[]
    for seed in [dict(low=1,high=0),dict(low=0xdeadbeef,high=0x12345678)]:
        o=ParticleOracle(**seed);o.create_bubble()
        for _ in range(3):initial=o.emit_bubbles([10,40,0,0,0,3,1,8,5])
        frames=[o.update_bubbles() for _ in range(32)]
        bubble_updates.append(dict(initial=initial,frames=frames))
    result=dict(bubble_updates=bubble_updates,bubble_cases=bubble_cases,update_cases=update_cases,source_sha256=EXPECTED,constructor='actual531414 InitInstance sentinel test',state_scope='native solid emission49BF44 +thread RNG539C60; not full renderer',cases=cases,rng_cases=rng_cases)
    (ROOT/'godot/tests/fixtures/original_particles.json').write_text(json.dumps(result,indent=2)+'\n')
    print('Captured',len(cases),'persistent emission sequences and',sum(len(c['steps']) for c in rng_cases),'actual native RNG steps')
if __name__=='__main__':main()
