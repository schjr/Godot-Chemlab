"""Read-only disassembly retention of ChemLab's vessel/reaction constructors."""
from pathlib import Path
import struct,json,hashlib
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
root=Path(__file__).resolve().parents[1]
blob=(root/'artifacts/ChemLab/_main.exe').read_bytes()
p=struct.unpack_from('<I',blob,60)[0];opt=struct.unpack_from('<H',blob,p+20)[0]
base=struct.unpack_from('<I',blob,p+52)[0];sections=[]
for i in range(struct.unpack_from('<H',blob,p+6)[0]):
 o=p+24+opt+i*40;size,rva,raw_size,offset=struct.unpack_from('<IIII',blob,o+8)
 sections.append((rva,max(size,raw_size),offset))
def read(va,n):
 for rva,size,offset in sections:
  if rva<=va-base<rva+size:return blob[offset+va-base-rva:offset+va-base-rva+n]
 raise ValueError(hex(va))
m=Cs(CS_ARCH_X86,CS_MODE_32)
blocks={}
for name,start,end in [('image_factory',0x41bcd6,0x41be55),('cem_factory',0x43281b,0x4329b3),('empty_string_ctor',0x4016e8,0x40171c),('reaction_ctor',0x416b30,0x416c0c),('vector_ctor',0x533f34,0x5340f0),('operator_new',0x533ad8,0x533b22),('allocator_dispatch',0x534330,0x534340)]:
 raw=read(start,end-start)
 blocks[name]={'start':f'{start:08x}','end_exclusive':f'{end:08x}','bytes':raw.hex(),'instructions':[f'{i.address:08x} {i.mnemonic} {i.op_str}' for i in m.disasm(raw,start)]}
result={'source':'artifacts/ChemLab/_main.exe','source_sha256':hashlib.sha256(blob).hexdigest(),'allocation_bytes':0x4348,'reaction_count':50,'reaction_stride':0xe8,'reaction_ctor':'00416b30','explicit_zero_string_offsets':[4,0xb8,0xd0,0xd4,0xd8,0xdc,0xe0],'blocks':blocks}
out=root/'godot/docs/original_logic/constructor_evidence.json';out.write_text(json.dumps(result,indent=2)+'\n')
print(out.relative_to(root))
