"""Retain exact startup allocation clients and default allocator instructions."""
from pathlib import Path
import json,re,hashlib
ROOT=Path(__file__).resolve().parents[1]
# Reuse the read-only PE mapping definitions, without invoking that tool's
# unrelated control-word report writer as an import side effect.
exec((ROOT/"tools/trace_original_live_controlword.py").read_text().split("found=[];calls=[];global_refs=[]")[0])

calls=[]
for index,start in enumerate(starts[:-1]):
 if start>=0x4c0000:continue
 instructions=list(decoder.disasm(read(start,starts[index+1]-start),start))
 for position,i in enumerate(instructions):
  if i.mnemonic=="call" and i.op_str=="0x533ad8":
   calls.append({"function":hex(start),"source_line":entries[start],"address":hex(i.address),
                 "context":[f"{x.address:08x} {x.mnemonic} {x.op_str}" for x in instructions[max(0,position-8):position+2]]})
blocks={}
for start,end in [(0x52f950,0x5300a0),(0x5305bc,0x5306b0),(0x5306b0,0x530838),
                  (0x530838,0x5309dc),(0x530bac,0x530c70),(0x530cf0,0x530d58),
                  (0x53139c,0x53146c),(0x533ad8,0x533b22),(0x534110,0x5343c8)]:
 blocks[hex(start)]={"end_exclusive":hex(end),"raw_hex":read(start,end-start).hex(),
                     "instructions":[f"{x.address:08x} {x.mnemonic} {x.op_str}" for x in decoder.disasm(read(start,end-start),start)]}
report={"source_sha256":hashlib.sha256(image).hexdigest(),"scope":"Retained main image application functions below4C0000; direct operator-new sites and exact allocator/client blocks. Does not execute GUI allocation order or external borlndmm.","application_new_sites":calls,"blocks":blocks}
path=ROOT/"godot/docs/original_logic/allocation_startup_evidence.json"
path.write_text(json.dumps(report,indent=2)+"\n")
print(json.dumps({"path":str(path.relative_to(ROOT)),"direct_application_new_sites":len(calls)}))
