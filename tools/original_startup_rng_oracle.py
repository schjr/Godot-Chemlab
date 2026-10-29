"""Actual original startup/time/DST/RNG instructions; explicit Win32/TLS boundary."""
import calendar
import hashlib
import json
import random
import struct
from pathlib import Path
from original_x86_oracle import OriginalOracle, EXPECTED
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP, UC_X86_REG_EIP

ROOT = Path(__file__).resolve().parents[1]

class StartupOracle(OriginalOracle):
    def __init__(self):
        super().__init__()
        self.tls = self.alloc(0x100)
        self.system_time = None
        self.hooks[0x53ca64] = lambda: self.ret(self.tls)
        self.hooks[0x554f54] = self.get_local_time

    def get_local_time(self):
        sp = self.uc.reg_read(UC_X86_REG_ESP)
        fields = self.system_time
        raw = struct.pack('<8H', *(fields[k] for k in ('year','month','day_of_week','day','hour','minute','second','millisecond')))
        self.uc.mem_write(self.u32(sp + 4), raw)
        self.uc.reg_write(UC_X86_REG_ESP, sp + 8)  # GetLocalTime stdcall, one arg.
        self.uc.reg_write(UC_X86_REG_EIP, self.u32(sp))

def fields(year, month, day, hour=0, minute=0, second=0, millisecond=0):
    return dict(year=year, month=month, day=day, hour=hour, minute=minute, second=second, millisecond=millisecond, day_of_week=0)

def main():
    oracle = StartupOracle()
    profiles = []
    for year in (1969,1970,1972,1986,1987,2000,2024,2026,2038,2039,2100):
        for month, day in ((1,1),(2,28),(4,1),(4,7),(4,30),(6,15),(10,25),(10,31),(12,31)):
            for hour in (0,1,2,23):
                profiles.append((fields(year,month,day,hour,59,59,999),0,True))
    # All modern and pre-1987 April/October transition dates and hour boundaries.
    for year in (1972,1986,1987,2024,2026,2038):
        for month in (4,10):
            for day in range(1, calendar.monthrange(year,month)[1]+1):
                for hour in (1,2): profiles.append((fields(year,month,day,hour),18000,True))
    for second in (0,1,2):
        profiles.append((fields(1970,1,1,second=second),0,False))
    for second in (6,7,8,9):
        profiles.append((fields(2038,1,19,3,14,second),0,False))
    rng = random.Random(0x413698)  # Fixture input selection only; not app RNG.
    for _ in range(240):
        year=rng.randrange(1970,2039);month=rng.randrange(1,13);day=rng.randrange(1,calendar.monthrange(year,month)[1]+1)
        profiles.append((fields(year,month,day,rng.randrange(24),rng.randrange(60),rng.randrange(60),rng.randrange(1000)),rng.choice([-43200,-28800,-19800,0,18000,20700,43200,2147483647,-2147483648]),bool(rng.randrange(2))))
    cases=[]
    for index,(clock,zone,daylight) in enumerate(profiles):
        oracle.system_time=clock
        oracle.u32(0x577974,zone);oracle.u32(0x577978,int(daylight))
        raw_time=oracle.call(0x53d198,struct.pack('<I',0))
        oracle.u32(oracle.tls+0x44,0xDEADBEEF);oracle.u32(oracle.tls+0x48,0xCAFEBABE)
        discarded=oracle.call(0x413698,b'')
        low=oracle.u32(oracle.tls+0x44);high=oracle.u32(oracle.tls+0x48)
        next_values=[]
        for _ in range(3):
            value=oracle.call(0x539c60,b'');next_values.append(dict(value=value,low=oracle.u32(oracle.tls+0x44),high=oracle.u32(oracle.tls+0x48)))
        cases.append(dict(id=index,system_time=clock,crt_timezone_seconds=zone,crt_daylight_enabled=daylight,native_ctime_raw=raw_time,native_discarded_rand=discarded,native_state=dict(low=low,high=high),native_next=next_values))
    output=ROOT/'evidence/original_logic/native-startup-rng-oracle.json'
    output.write_text(json.dumps(dict(binary_sha256=EXPECTED,functions=['00413698','0053D198','0053CE18','0053CD04','00539C0C','00539C38','00539C60'],contract='Actual original instructions. GetLocalTime fills explicit SYSTEMTIME; CRT globals577974/577978 are supplied; TLS accessor53CA64 returns isolated per-thread storage. No Win32 timezone initialization, actual current clock, GUI or full process equivalence.',boundary_calls=sorted(set(oracle.boundary_calls)),source_dossiers=[dict(path=str(p.relative_to(ROOT)),sha256=hashlib.sha256(p.read_bytes()).hexdigest()) for p in (ROOT/'evidence/original_logic/startup_rng_time_dossier.json',ROOT/'evidence/original_logic/startup_rng_epoch_dossier.json')],cases=cases),indent=2)+'\n')
    print(f'Executed {len(cases)} original startup profiles and {len(cases)*3} subsequent RNG calls -> {output}')

if __name__=='__main__': main()
