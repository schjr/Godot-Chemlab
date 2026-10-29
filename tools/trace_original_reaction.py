"""Retain static PE constants used by the original reaction pass."""
from pathlib import Path
import struct,json,hashlib,re
root=Path(__file__).resolve().parents[1]
b=(root/'artifacts/ChemLab/_main.exe').read_bytes()
pe=struct.unpack_from('<I',b,0x3c)[0]
num=struct.unpack_from('<H',b,pe+6)[0];opt=struct.unpack_from('<H',b,pe+20)[0]
base=struct.unpack_from('<I',b,pe+52)[0]
sections=[]
for i in range(num):
 o=pe+24+opt+40*i
 size,rva,raw_size,offset=struct.unpack_from('<IIII',b,o+8)
 sections.append((rva,max(size,raw_size),offset))
def read(va,n):
 for rva,size,offset in sections:
  if rva<=va-base<rva+size:return b[offset+va-base-rva:offset+va-base-rva+n]
 raise ValueError(hex(va))
src=(root/'recovered/native/main/decompiled.cpp').read_text()
chunk=src[src.index('// Entry 00462c18'):src.index('// Entry 0046b858')]
strings={}
for address in sorted(set(int(x,16) for x in re.findall(r'DAT_(00563[0-9a-f]+)',chunk))):
 if address==0x5636d4:continue
 raw=read(address,256).split(b'\0')[0]
 strings[f'{address:08x}']={'bytes':raw.hex(),'gb18030':raw.decode('gb18030')}
result={'source_sha256':hashlib.sha256(b).hexdigest(),'function':'00462c18','string_constants':strings,'extended_constants':{'0046b820':{'bytes':read(0x46b820,10).hex(),'decimal':'0.1'},'0046b848':{'bytes':read(0x46b848,10).hex(),'decimal':'0.0001'}}}
out=root/'godot/docs/original_logic/reaction_constants.json'
out.parent.mkdir(parents=True,exist_ok=True)
out.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n')
print(out.relative_to(root))
