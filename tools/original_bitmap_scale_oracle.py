"""Original48F1E0 bounded raw-PE numeric oracle. VCL bitmap callbacks hosted.
SetPixelFormat7 is an explicit identity precondition: supplied 32-bit words.
No native VCL conversion or GDI rasterization equivalence is claimed.
"""
import json,struct,random
from pathlib import Path
from original_visual_oracle import PixelOracle,EXPECTED
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX
ROOT=Path(__file__).resolve().parents[1]
class ScaleOracle(PixelOracle):
 def __init__(self):
  super().__init__();self.hooks[0x4e95b0]=self.scanline
 def scanline(self):
  p=self.uc.reg_read(UC_X86_REG_EAX);r=self.uc.reg_read(UC_X86_REG_EDX);b=self.bitmaps[p]
  if not 0<=r<b['height']:raise ValueError('Native scanline out of bounds')
  self.ret(b['pixels']+4*r*b['width'])
 def frame(self,w,h,s,words,high):
  self.bitmaps[self.first].update(width=w,height=h,pixels=self.alloc(w*h*4))
  self.bitmaps[self.second]['pixels']=self.alloc(max(1,w*h*16)*4)
  self.uc.mem_write(self.bitmaps[self.first]['pixels'],struct.pack('<'+'I'*len(words),*words))
  #48F1E0 pushes EBP; untouched local [EBP-11] must remain an explicit input.
  self.uc.mem_write(0x90ffe00-4-0x11,bytes([high]))
  result=self.call(0x48f1e0,struct.pack('<IIf',self.first,self.second,s))
  dst=self.bitmaps[self.second];out=[]
  if result==0:out=list(struct.unpack('<'+'I'*(dst['width']*dst['height']),self.uc.mem_read(dst['pixels'],4*dst['width']*dst['height'])))
  return {'width':w,'height':h,'scale32_bits':struct.pack('<f',s).hex(),'source_words':words,'reserved_byte':high,'native_return':result,'destination_width':dst['width'],'destination_height':dst['height'],'native_words':out}
def main():
 o=ScaleOracle();rng=random.Random(0x48f1e0);cases=[]
 for w,h in [(1,1),(3,2),(7,5),(2,300)]:
  for s in [0.1,0.10001,0.3,0.5,0.99,1.0,1.01,1.5,2.3,4.0,4.01]:
   if h*s>600 and s<=4:continue
   for high in [0,165,255]:cases.append(o.frame(w,h,s,[rng.getrandbits(32) for _ in range(w*h)],high))
 p=ROOT/'evidence/original_logic/native-bitmap-scale-oracle.json'
 p.write_text(json.dumps({'binary_sha256':EXPECTED,'function':'0x0048F1E0','contract':__doc__,'cases':cases},indent=2)+'\n');print(f'Executed {len(cases)} original scaling cases -> {p}')
if __name__=='__main__':main()
