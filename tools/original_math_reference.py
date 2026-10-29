"""Generate separate x87 instruction reference fixtures; not whole-app evidence."""
from pathlib import Path
import json, random, struct, subprocess
ROOT=Path(__file__).resolve().parents[1]
def bits(x):return struct.pack('<d',x).hex()
def main():
    rng=random.Random(471650)
    cases=[]
    for value in [2.0**n for n in range(-100,101,5)]+[10.0**(-p) for p in [2,3.2,4.5,5,7,8,9,10,12]]+[10**rng.uniform(-25,5) for _ in range(100)]:
        cases.append(('log10',value,0.0))
    for base in [0.001,0.01,0.1,0.5,0.9,0.99,1.0]+[rng.uniform(0.001,1.0) for _ in range(100)]:
        cases.append(('pow',base,1/3))
    for _ in range(100):cases.append(('pow',10**rng.uniform(-5,5),rng.uniform(0.01,2)))
    out=[]
    for kind,x,y in cases:
        args=['/private/tmp/chemlab-x87-reference',kind,format(x,'.17g')]
        if kind=='pow':args.append(format(y,'.17g'))
        double,extended=subprocess.check_output(args,text=True).split()
        out.append({'kind':kind,'x_bits':bits(x),'y_bits':bits(y),'double_bits':double,'extended_bits':extended})
    (ROOT/'godot/tests/fixtures/original_math.json').write_text(json.dumps({'reference':'Original CRT operation sequence using x87 instructions through Rosetta; separate from PE emulator','cases':out},indent=2)+'\n')
    print(f'x87 instruction reference: {len(out)} cases')
if __name__=='__main__':main()
