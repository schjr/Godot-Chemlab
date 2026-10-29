"""Instruction-aligned, read-only x87 control-word audit of recovered main.exe."""
from pathlib import Path
import bisect
import hashlib
import json
import re
import struct
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

ROOT=Path(__file__).resolve().parents[1]
image=(ROOT/"evidence/native-inputs/main.exe").read_bytes()
source=(ROOT/"recovered/native/main/decompiled.cpp").read_text()
nt=struct.unpack_from("<I",image,60)[0]
optional_size=struct.unpack_from("<H",image,nt+20)[0]
base=struct.unpack_from("<I",image,nt+52)[0]
sections=[]
for index in range(struct.unpack_from("<H",image,nt+6)[0]):
    header=nt+24+optional_size+index*40
    _,rva,size,offset=struct.unpack_from("<4I",image,header+8)
    sections.append((base+rva,size,offset))

def read(address,length):
    for start,size,offset in sections:
        if start<=address<start+size:
            return image[offset+address-start:offset+address-start+length]
    return b""

entries={int(m.group(1),16):source[:m.start()].count("\n")+1 for m in re.finditer(r"// Entry ([0-9a-fA-F]{8})",source)}
starts=sorted(entries)
decoder=Cs(CS_ARCH_X86,CS_MODE_32)
controls={"fldcw","fnstcw","fstcw","fninit","finit","fldenv","frstor","fxrstor","xrstor","ldmxcsr","fnsave","fsave","fnstenv"}
targets={0x539278,0x531344,0x5394e4}
found=[];calls=[];global_refs=[]

def instruction(i):
    return {"address":hex(i.address),"bytes":i.bytes.hex(),"mnemonic":i.mnemonic,"operands":i.op_str}

for index,start in enumerate(starts[:-1]):
    instructions=list(decoder.disasm(read(start,starts[index+1]-start),start))
    for position,i in enumerate(instructions):
        if i.mnemonic in controls:
            found.append({"function":hex(start),"source_line":entries[start],**instruction(i)})
        if i.mnemonic=="call" and i.op_str.startswith("0x") and int(i.op_str,16) in targets:
            calls.append({"function":hex(start),"source_line":entries[start],"target":i.op_str,
                          "context":[instruction(x) for x in instructions[max(0,position-7):position+2]]})
        if any(hex(address) in i.op_str for address in (0x5755e8,0x5772e0)):
            global_refs.append({"function":hex(start),"source_line":entries[start],**instruction(i)})

blocks={}
for start,end in [(0x4fe494,0x4fe558),(0x52aa40,0x52aaeb),(0x52e1cc,0x52e245),
                  (0x530f28,0x530f44),(0x531344,0x53134e),(0x539278,0x5392a8),
                  (0x5393c9,0x539490),(0x5394e4,0x5394fa),(0x5394fc,0x53952c)]:
    blocks[hex(start)]={"end_exclusive":hex(end),"bytes":read(start,end-start).hex(),
                       "instructions":[instruction(i) for i in decoder.disasm(read(start,end-start),start)]}
result={"image_sha256":hashlib.sha256(image).hexdigest(),"method":"Linear instruction decoding from every retained decompiler function entry to the next entry; no raw opcode substring matches accepted",
        "scope":"Recovered main-image functions and direct calls; external DLL/OS/emulator behavior and live control register not observed",
        "control_instructions":found,"direct_control_callers":calls,"global_references":global_refs,
        "stored_word_bytes":{hex(a):read(a,n).hex() for a,n in [(0x5755e8,2),(0x5772e0,4),(0x575610,2),(0x52a296,2)]},"blocks":blocks}
destination=ROOT/"godot/docs/original_logic/live_controlword_evidence.json"
destination.write_text(json.dumps(result,indent=2)+"\n")
print(json.dumps({"path":str(destination.relative_to(ROOT)),"control_instructions":len(found),"direct_control_callers":len(calls)}))
