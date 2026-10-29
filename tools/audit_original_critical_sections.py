"""Pin the bounded native lock-pointer wrappers used by the new own-object host."""
import hashlib, json, struct
from pathlib import Path
from capstone import Cs, CS_ARCH_X86, CS_MODE_32
ROOT=Path(__file__).resolve().parents[1]
SHA='7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c'
def audit():
 raw=(ROOT/'artifacts/ChemLab/_main.exe').read_bytes()
 if hashlib.sha256(raw).hexdigest()!=SHA:raise ValueError('Original binary identity differs')
 pe=struct.unpack_from('<I',raw,0x3c)[0];sections=struct.unpack_from('<H',raw,pe+6)[0];optional=struct.unpack_from('<H',raw,pe+20)[0];base=struct.unpack_from('<I',raw,pe+24+28)[0]
 def get(address,size):
  rva=address-base
  for i in range(sections):
   vs,va,n,offset=struct.unpack_from('<4I',raw,pe+24+optional+40*i+8)
   if va<=rva and rva+size<=va+n:return raw[offset+rva-va:offset+rva-va+size]
  raise ValueError('Requested instruction span outside raw PE section')
 md=Cs(CS_ARCH_X86,CS_MODE_32)
 spans=[]
 patterns=[(0x4e2da4,0x4e2dae,[('add','eax, 8'),('push','eax'),('call','0x554ec4'),('ret','')]),
  (0x4e2db0,0x4e2dba,[('add','eax, 8'),('push','eax'),('call','0x555020'),('ret','')]),
  (0x4e34e8,0x4e34f6,[('mov','edx, dword ptr [eax + 0x14]'),('test','edx, edx'),('je','0x4e34f5'),('push','edx'),('call','0x554ec4'),('ret','')]),
  (0x4e34f8,0x4e3506,[('mov','edx, dword ptr [eax + 0x14]'),('test','edx, edx'),('je','0x4e3505'),('push','edx'),('call','0x555020'),('ret','')])]
 for start,end,expected in patterns:
  data=get(start,end-start);instructions=list(md.disasm(data,start));actual=[(i.mnemonic,i.op_str) for i in instructions]
  if actual!=expected:raise ValueError('Source lock wrapper changed at '+hex(start))
  spans.append(dict(address=hex(start),bytes=len(data),sha256=hashlib.sha256(data).hexdigest(),instructions=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str) for i in instructions]))
 for call,callee in [(0x4e2d5e,0x555008),(0x4e2d8f,0x554eb2)]:
  i=next(md.disasm(get(call,5),call))
  if i.mnemonic!='call' or i.op_str!=hex(callee):raise ValueError('Source constructor/destructor import changed')
 return dict(format='chemlab-original-critical-wrapper-audit-v1',source_sha256=SHA,spans=spans,
  constructor_initialize_call='0x4e2d5e',destructor_delete_call='0x4e2d8f',
  finding='These exact wrappers pass registry+8 or Pen+0x14 to Win32 without inspecting pointed-to CRITICAL_SECTION fields.',
  scope='Bounded static original-code evidence only; not Windows backend execution or global absence of other lock uses',native_backend_executed=False,native_vcl_verified=False)
if __name__=='__main__':
 result=audit();out=ROOT/'evidence/original-critical-wrapper-audit.json';out.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(dict(validated_wrappers=len(result['spans']),source_sha256=SHA,native_backend_executed=False)))
