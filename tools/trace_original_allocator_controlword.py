"""Read-only retained original allocator / control-word evidence."""
from pathlib import Path
import struct,json,hashlib
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
root=Path(__file__).resolve().parents[1]
raw=(root/'evidence/native-inputs/main.exe').read_bytes()
nt=struct.unpack_from('<I',raw,60)[0];opt=struct.unpack_from('<H',raw,nt+20)[0]
sections=[]
for i in range(struct.unpack_from('<H',raw,nt+6)[0]):
 offset=nt+24+opt+i*40;size,va,rs,fo=struct.unpack_from('<4I',raw,offset+8)
 sections.append((va,rs,fo))
def read(va,length):
 for start,size,off in sections:
  if start<=va-0x400000<start+size:
   return raw[off+va-0x400000-start:off+va-0x400000-start+length]
 raise ValueError(hex(va))
c=Cs(CS_ARCH_X86,CS_MODE_32)
blocks={}
for name,start,end in [
 ('allocator_initial_dispatch',0x5343c8,0x5343e0),('allocator_dispatch',0x534330,0x534340),
 ('allocator_manager_selection',0x53418c,0x5342c0),('allocator_fallback_selection',0x534368,0x5343b0),
 ('allocator_delphi_bridge',0x534428,0x534444),('delphi_getmemorymanager',0x530cf0,0x530d0c),
 ('default_getmem',0x5306b0,0x530838),('default_getmem_large_reuse',0x5305bc,0x5306b0),
 ('delphi_cw_reset',0x531344,0x53134e),('delphi_cw_registry',0x531280,0x531317),
 ('cpp_cw_reset',0x5394e4,0x5394fa),('cpp_cw_control',0x539278,0x5392a8),
 ('delphi_init_call',0x533980,0x533a23),('cpp_startup_call',0x53c7cc,0x53c7f0),
]:
 data=read(start,end-start)
 blocks[name]={'start':hex(start),'end_exclusive':hex(end),'bytes':data.hex(),
   'instructions':[f'{i.address:08x} {i.mnemonic} {i.op_str}' for i in c.disasm(data,start)]}
result={'source_sha256':hashlib.sha256(raw).hexdigest(),'globals':{hex(a):read(a,n).hex() for a,n in [(0x57598c,4),(0x575604,4),(0x5755e8,2),(0x575610,2),(0x5772e0,4)]},'blocks':blocks}
out=root/'godot/docs/original_logic/allocator_controlword_evidence.json'
out.write_text(json.dumps(result,indent=2)+'\n');print(out)
