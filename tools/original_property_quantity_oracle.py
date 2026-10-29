"""Execute original Form4 Modify49FE58 with text/grid/radio ABI boundaries."""
import json,struct,copy
from original_program_oracle import ProgramOracle
from original_x86_oracle import ROOT,EXPECTED
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX,UC_X86_REG_ECX,UC_X86_REG_ESP,UC_X86_REG_EIP
class PropertyOracle(ProgramOracle):
 def __init__(self):
  super().__init__();self.edits={};self.radios={};self.rows=[]
  self.hooks.update({0x5053e0:self.get_text,0x505410:self.set_text,0x4e1c8c:self.get_cell,0x4e1cfc:self.set_cell,0x4f25c8:lambda:self.ret(0),0x8000200:self.get_checked})
 def ret4(self):
  sp=self.uc.reg_read(UC_X86_REG_ESP);pc=self.u32(sp);self.uc.reg_write(UC_X86_REG_ESP,sp+8);self.uc.reg_write(UC_X86_REG_EIP,pc)
 def get_text(self):self.u32(self.uc.reg_read(UC_X86_REG_EDX),self.string(self.edits[self.uc.reg_read(UC_X86_REG_EAX)]));self.ret()
 def set_text(self):self.edits[self.uc.reg_read(UC_X86_REG_EAX)]=self.text_at(self.uc.reg_read(UC_X86_REG_EDX));self.ret()
 def get_checked(self):self.ret(int(self.radios[self.uc.reg_read(UC_X86_REG_EAX)]))
 def get_cell(self):
  row=self.uc.reg_read(UC_X86_REG_ECX);col=self.uc.reg_read(UC_X86_REG_EDX);dst=self.u32(self.uc.reg_read(UC_X86_REG_ESP)+4)
  self.u32(dst,self.string(self.rows[row-1][col-1] if 1<=row<=len(self.rows) and col>0 else ''));self.ret4()
 def set_cell(self):
  row=self.uc.reg_read(UC_X86_REG_ECX);col=self.uc.reg_read(UC_X86_REG_EDX);text=self.text_at(self.u32(self.uc.reg_read(UC_X86_REG_ESP)+4));self.rows[row-1][col-1]=text;self.ret4()
 def case(self,species,mode,text):
  self.rows=[['H2O(液体)','0.123456789012345','2.224197'],'HCl(溶解) 0.02 0.7292'.split()];self.messages=[]
  grid=self.alloc(0x220);self.u32(grid+0x214,2);self.u32(self.form+0x2e4,grid)
  vt=self.alloc(0xc0);self.u32(vt+0xb4,0x8000200)
  for off,value in [(0x2ec,species),(0x2f4,text if mode=='moles' else '0.02'),(0x300,text if mode=='mass' else '0.7292')]:p=self.alloc(4);self.edits[p]=value;self.u32(self.form+off,p)
  for off,value in [(0x2f0,mode=='moles'),(0x2fc,mode=='mass')]:p=self.alloc(4);self.u32(p,vt);self.radios[p]=value;self.u32(self.form+off,p)
  self.u32(0x5962bc,len(self.rows));self.uc.reg_write(UC_X86_REG_EAX,self.form);self.call(0x49fe58,b'')
  result=dict(species=species,mode=mode,text=text,rows=self.rows,messages=self.messages)
  if not self.messages:
   result['stored_bits']=[dict(species=self.text_at(self.u32(0x5962c0+4*i)),moles=bytes(self.uc.mem_read(0x596a90+8*i,8)).hex(),mass=bytes(self.uc.mem_read(0x596450+8*i,8)).hex()) for i in range(self.u32(0x5962bc))]
  if not self.messages:
   contents={row['species']:struct.unpack('<d',bytes.fromhex(row['moles']))[0] for row in result['stored_bits']}
   idx=self.add_vessel(contents);pointer=self.vessels[idx]
   result['recalculated_mass_bits']={row['species']:bytes(self.uc.mem_read(pointer+0x298+8*i,8)).hex() for i,row in enumerate(result['stored_bits'])}
  return copy.deepcopy(result)
def main():
 o=PropertyOracle();cases=[];errors=[]
 for species in ['HCl(溶解)','NaOH(溶解)','CuSO4(溶解)']:
  for mode in ['moles','mass']:
   for text in ['0','0.04','1.2345678901234567','1E-20','10000001','1.23456789012345E99','-1',' -0.25 ','+2.5E-12']:
    try:cases.append(o.case(species,mode,text))
    except Exception as e:errors.append(dict(species=species,mode=mode,text=text,error=str(e)))
 out=dict(source_sha256=EXPECTED,entry='0049FE58',scope='Original Modify callback, native parsing/formatting/arithmetic; grid/edit/radio/focus/message ABI boundaries; invalid-format exceptions not hosted',cases=cases,errors=errors)
 (ROOT/'godot/tests/fixtures/original_property_quantity.json').write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n');print(len(cases),'cases',len(errors),errors[:2])
if __name__=='__main__':main()
