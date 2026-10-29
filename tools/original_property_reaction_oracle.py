"""Execute original Form4 five-field reaction Modify4A14E4."""
import json,struct
from original_property_quantity_oracle import PropertyOracle
from original_x86_oracle import ROOT,EXPECTED
from unicorn.x86_const import UC_X86_REG_EAX

def main():
 o=PropertyOracle();grid=o.alloc(0x220);o.u32(o.form+0x318,grid);cases=[]
 values=[['0.003','水溶液','-1.2345678901234567','1E-20','可逆'],['-2.5','任意 原文','-100','-0.5','未知模式'],['1E99','','1.2345E-90','1.2345678901234567','单向'],['0','0','0','0',''],['+2.5E-12',' 加热 ','-0','1000000001',' 反向 ']]
 for row in [1,2,50]:
  for texts in values:
   o.u32(grid+0x214,row)
   for off,text in zip([0x330,0x338,0x340,0x348,0x350],texts):p=o.alloc(4);o.u32(o.form+off,p);o.edits[p]=text
   o.uc.reg_write(UC_X86_REG_EAX,o.form);o.call(0x4a14e4,b'')
   cases.append(dict(row=row,texts=texts,rate_bits=bytes(o.uc.mem_read(0x5970a0+row*0xe8,8)).hex(),condition=o.text_at(o.u32(0x5970a8+row*0xe8)),heat_bits=bytes(o.uc.mem_read(0x5970b0+row*0xe8,8)).hex(),equilibrium_bits=bytes(o.uc.mem_read(0x5970b8+row*0xe8,8)).hex(),mode=o.text_at(o.u32(0x5970c0+row*0xe8))))
 (ROOT/'godot/tests/fixtures/original_property_reaction.json').write_text(json.dumps(dict(source_sha256=EXPECTED,entry='004A14E4',boundaries='VCL GetText and managed string ownership; retained parser and ordered callback stores execute',cases=cases),ensure_ascii=False,indent=2)+'\n');print(len(cases),'native cases')
if __name__=='__main__':main()
