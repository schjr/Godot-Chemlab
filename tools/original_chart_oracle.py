"""Actual48D6E0 graph sampler/coordinate kernel; VCL pen/line calls captured."""
import json,struct
from original_program_oracle import ProgramOracle
from original_liquid_oracle import LiquidOracle
from original_x86_oracle import ROOT,EXPECTED
from unicorn.x86_const import UC_X86_REG_EDX,UC_X86_REG_ECX
class ChartOracle(ProgramOracle,LiquidOracle):
 def __init__(self):
  super().__init__();self.call(0x539f98,b'');holder=self.alloc(4);self.u32(holder,self.form);self.u32(0x5799c4,holder)
  self.hooks.update({0x4e3f80:self.presentation_property,0x4e46a8:self.move,0x4e4648:self.line,0x4e4a80:self.presentation_property,0x4e3964:self.presentation_property,0x4e484c:self.textout})
  self.u32(self.canvas+0xc,self.alloc(0x80));label=self.alloc(0x80);self.u32(self.form+0x4b0,label);self.u32(label+0x58,self.alloc(0x80))
  self.moves=[];self.lines=[];self.texts=[];self.recent=[]
 def on_instruction(self,uc,address,size,unused):
  if hasattr(self,'recent'):
   self.recent.append((hex(address),bytes(uc.mem_read(address,size)).hex()));self.recent=self.recent[-20:]
  super().on_instruction(uc,address,size,unused)
 def xy(self):
  def signed(x):return x if x<0x80000000 else x-0x100000000
  return [signed(self.uc.reg_read(UC_X86_REG_EDX)),signed(self.uc.reg_read(UC_X86_REG_ECX))]
 def move(self):self.moves.append(self.xy());self.ret()
 def line(self):self.lines.append([self.moves[-1],self.xy()]);self.ret()
 def textout(self):
  from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP
  sp=self.uc.reg_read(UC_X86_REG_ESP);self.texts.append([*self.xy(),self.text_at(self.u32(sp+4))]);pc=self.u32(sp)
  self.uc.reg_write(UC_X86_REG_ESP,sp+8);self.uc.reg_write(UC_X86_REG_EIP,pc)
 def run_initialize(self,record,variables):
  self.run_sample(record,variables,False);self.moves=[];self.lines=[];self.texts=[];self.rectangles=[]
  try:self.call(0x48db24,b'')
  except Exception as e:raise RuntimeError(str(e)+' '+str(self.recent)) from e
  return dict(record=record,variables=variables,lines=self.lines,texts=self.texts,rectangles=self.rectangles,after_names=[[self.text_at(self.u32(0x58f084+4*i)),self.text_at(self.u32(0x58f098+4*i))] for i in range(5)],after_previous_bits=[[bytes(self.uc.mem_read(0x58efcc+8*i,8)).hex(),bytes(self.uc.mem_read(0x58f034+8*i,8)).hex()] for i in range(5)])
 def run_sample(self,record,variables,execute=True):
  self.uc.mem_write(0x58ef64,b'\0'*(8*0x148));self.moves=[];self.lines=[]
  p=0x58ef64;self.u32(p,int(record[0]));self.u32(0x58ef3c,self.bitmap(240,240))
  for j,off in [(3,0x10),(4,0x18),(5,0x20),(6,0x28)]:self.f64(p+off,float(record[j]))
  for j,off in [(7,0x30),(8,0x34),(9,0x38)]:self.u32(p+off,int(record[j]))
  for i in range(5):
   fields=record[10+9*i:19+9*i]
   for j,base in [(0,0x3c),(1,0x50),(4,0xb8)]:self.u32(p+base+4*i,int(fields[j]))
   for j,base in [(2,0x68),(3,0x90),(5,0xd0),(6,0xf8)]:self.f64(p+base+8*i,float(fields[j]))
   self.u32(p+0x120+4*i,self.string(fields[7]));self.u32(p+0x134+4*i,self.string(fields[8]))
  self.u32(self.form+0xe20,len(variables))
  for i,(name,text) in enumerate(variables.items()):self.u32(self.form+0xe58+0x44*i,self.string(name));self.u32(self.form+0xe60+0x44*i,self.string(text))
  if execute:self.call(0x48d6e0,b'')
  return dict(record=record,variables=variables,lines=self.lines,after_previous_bits=[[bytes(self.uc.mem_read(p+0x68+8*i,8)).hex(),bytes(self.uc.mem_read(p+0xd0+8*i,8)).hex()] for i in range(5)])
def main():
 cases=[]
 for e in json.loads((ROOT/'godot/data/examples.json').read_text()):
  lines=e['trailing_lines'];p=1+7*int(lines[0]);count=int(lines[p])
  for i in range(count):
   r=lines[p+1+55*i:p+56+55*i];variables={name:'0.02' if name=='t' else '0.0004' for slot in range(5) for name in [r[17+9*slot],r[18+9*slot]] if name!='数值0'}
   cases.append({'name':e['name'],**ChartOracle().run_sample(r,variables),'initialize':ChartOracle().run_initialize(r,variables)})
 r=['1','0','0','1','1','0','0','16777215','0','0']+sum(([str(128+i),'0','0','0','0','0','0','x'+str(i),'y'+str(i)] for i in range(5)),[])
 for k,(x,y) in enumerate([(0,0),(.5,.5),(-.5,-.5),(1.0,1.0),(8.25,-2.25),(-8.25,2.25)]):cases.append({'name':'boundary'+str(k),**ChartOracle().run_sample(r,{name:format(x if name[0]=='x' else y,'.17g') for i in range(5) for name in ['x'+str(i),'y'+str(i)]}),'initialize':ChartOracle().run_initialize(r,{name:format(x if name[0]=='x' else y,'.17g') for i in range(5) for name in ['x'+str(i),'y'+str(i)]})})
 for k,(ox,oy) in enumerate([(17.5,13.25),(13.0000000001,13.0000000001),(-31.125,270.5),(245.5,-5.125)]):
  varied=r.copy();varied[3]='0.3333333333333333';varied[4]='0.0001234567890123';varied[5]=str(ox);varied[6]=str(oy);varied[7]='10197915';varied[8]='302641'
  values={name:'0.123456789012345' for i in range(5) for name in ['x'+str(i),'y'+str(i)]}
  cases.append({'name':'fractional grid'+str(k),**ChartOracle().run_sample(varied,values),'initialize':ChartOracle().run_initialize(varied,values)})
 unknown=r.copy();unknown[17]='missing_x';unknown[18]='y0'
 cases.append({'name':'initialize unknown variable sanitation','initialize_only':True,'record':unknown,'variables':{'y0':'0.125'},'initialize':ChartOracle().run_initialize(unknown,{'y0':'0.125'})})
 out={'binary_sha256':EXPECTED,'entry':'0048D6E0','scope':'Actual variablelookup417424, ANSI numberparse541348 andx87coordinates; VCLstyle/MoveTo/LineTo presentation captured','cases':cases}
 (ROOT/'godot/tests/fixtures/original_chart.json').write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n');print('captured',len(cases),'native chart updates')
if __name__=='__main__':main()
