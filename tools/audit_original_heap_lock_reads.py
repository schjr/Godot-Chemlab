"""Bounded source audit: opaque critical-section identity is not app payload."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
x=json.loads((ROOT/'godot/data/original_heap_ir.json').read_text());image=(ROOT/'godot/data/original_heap_image.bin').read_bytes()
uses=[];absolute=[];ins=x['instructions'];names={0x555008:'InitializeCriticalSection',0x554ec4:'EnterCriticalSection',0x555020:'LeaveCriticalSection',0x554eb2:'DeleteCriticalSection'}
for i,a in enumerate(ins):
 assert image[a['address']-0x400000:a['address']-0x400000+len(bytes.fromhex(a['bytes']))].hex()==a['bytes']
 for operand in a['operands']:
  if operand['kind']=='mem' and not operand['base'] and not operand['index'] and 0x59b184<=operand['disp']<0x59b19c:absolute.append(a)
  if operand['kind']=='imm' and 0x59b184<=operand['value']<0x59b19c:
   assert a['mnemonic']=='push' and operand['value']==0x59b184
   following=ins[i+1];assert following['mnemonic']=='call'
   target=following['operands'][0]['value'];assert target in names
   uses.append({'pc':a['address'],'call_pc':following['address'],'api':names[target]})
assert not absolute and len(uses)==12
out={'source_sha256':x['source_sha256'],'ir_sha256':hashlib.sha256((ROOT/'godot/data/original_heap_ir.json').read_bytes()).hexdigest(),'critical_section_address':0x59b184,'size':24,'identity_uses':uses,'absolute_interior_memory_operands':absolute,'scope':'Static retained heap instruction inventory only: all immediate identities are direct API arguments; no absolute interior loads/stores. No claim about API implementations or arbitrary application code. Source allocator accepted paths additionally tested with all24 interior bytes unknown.'}
(ROOT/'godot/tests/fixtures/original_heap_lock_reads.json').write_text(json.dumps(out,indent=2)+'\n');print(len(uses),'source identities, no absolute interior app accesses')
