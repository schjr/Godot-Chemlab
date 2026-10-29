"""Execute retained 53958C general-g formatter used at401E5A/401EE7."""
import sys,json,struct,random,math
from original_program_oracle import ProgramOracle
from original_x86_oracle import ROOT,EXPECTED

def main():
 o=ProgramOracle();o.call(0x539f98,b'');rng=random.Random(0x401e5a)
 values=[0.,-0.,1.,-1.,1.2345,1.2355,9.9995,9999.5,0.000099995,0.00001,1e-9,12345.6789,1.7976931348623157e308,5e-324]
 for exponent in range(-320,309,7):
  for sign in [1,-1]:
   v=sign*rng.uniform(1,9.9)*10.**exponent
   if math.isfinite(v):values.append(v)
 cases=[]
 for v in values:
  dst=o.alloc(512);o.call(0x53958c,struct.pack('<dII',v,4,dst));text=bytes(o.uc.mem_read(dst,512)).split(b'\0')[0].decode('ascii');cases.append(dict(bits=struct.pack('<d',v).hex(),text=text))
 (ROOT/'godot/tests/fixtures/original_live_property.json').write_text(json.dumps(dict(source_sha256=EXPECTED,entry='0053958C',call_sites=['00401E5A','00401EE7'],precision=4,cases=cases),indent=2)+'\n');print(len(cases),'native formats')
if __name__=='__main__':main()
