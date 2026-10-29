"""Bounded actual PE4A0F50/4A1050 reference; declared AnsiString boundaries."""
import json,struct
from pathlib import Path
from original_x86_oracle import OriginalOracle,EXPECTED
from unicorn.x86_const import UC_X86_REG_EAX
ROOT=Path(__file__).resolve().parents[1]
def rows(overrides):
 out=[]
 for i in range(300):out.append([i*100+j for j in range(13)]+[overrides.get(str(i),'v'+str(i)),'aux'+str(i),'expr'+str(i),'note'+str(i)])
 return out
def main():
 oracle=OriginalOracle();origin=oracle.allocation;cases=[]
 profiles=[('match',4,{},'v2',False),('case-sensitive',4,{},'V2',False),('empty-sentinel',4,{'1':''},'v2',False),('missing',4,{},'missing',True),('shift-tail',4,{},'v1',True),('delete-last-active',4,{},'v3',True),('full-table-last',300,{},'v299',True),('empty-count',0,{},'v0',True)]
 for name,count,overrides,query,delete in profiles:
  oracle.allocation=origin;table=oracle.alloc(4+300*68);oracle.u32(table,count)
  for i,row in enumerate(rows(overrides)):
   for j,value in enumerate(row):oracle.u32(table+4+i*68+j*4,value if j<13 else oracle.string(value))
  oracle.call(0x4a0f50,struct.pack('<II',table,oracle.string(query)))
  found=oracle.uc.reg_read(UC_X86_REG_EAX);found=found if found<0x80000000 else found-0x100000000
  if delete:oracle.call(0x4a1050,struct.pack('<Ii',table,found))
  result=[]
  for i in range(300):
   row=[]
   for j in range(17):
    v=oracle.u32(table+4+i*68+j*4);row.append(v if j<13 else oracle.text_at(v))
   result.append(row)
  cases.append({'name':name,'count':count,'overrides':overrides,'query':query,'delete':delete,'native_index':found,'native_count':oracle.u32(table),'native_rows':result})
 out=ROOT/'evidence/original_logic/native-variable-cleanup-oracle.json';out.write_text(json.dumps({'binary_sha256':EXPECTED,'functions':['0x004A0F50','0x004A1050'],'contract':'Actual helper instructions and physical300x17 slot shifts; existing AnsiString assignment/compare constructors are declared hosted boundaries, no VCL form or rendering execution.','cases':cases},ensure_ascii=False,indent=2)+'\n');print(f'Executed {len(cases)} original variable-table helper frames -> {out}')
if __name__=='__main__':main()
