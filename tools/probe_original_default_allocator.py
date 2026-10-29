"""Execute original System allocator bytes with explicit Win32 page boundaries.
No original app process is launched. This is a kernel feasibility probe, not
a reconstruction of the GUI's allocation history or a universal slot profile.
"""
import hashlib,json,struct,re
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP
from original_x86_oracle import OriginalOracle,ROOT,EXPECTED

class AllocatorProbe(OriginalOracle):
 def __init__(self):
  super().__init__();self.reservations={};self.committed=set();self.virtual_next=0x4000000;self.events=[]
  self.function_entries=set(int(a,16) for a in re.findall(r'// Entry ([0-9a-fA-F]{8})',(ROOT/'recovered/native/main/decompiled.cpp').read_text()))
  self.visited_functions=set();self.native_instruction_count=0
  self.local_base=0x6000000;self.local_next=self.local_base;self.uc.mem_map(self.local_base,0x10000)
  self.hooks.update({0x5550c2:self.virtual_alloc,0x5550c8:self.virtual_free,0x555038:self.local_alloc,
                    0x555008:lambda:self.stdcall(0,4),0x554ec4:lambda:self.stdcall(0,4),0x555020:lambda:self.stdcall(0,4)})
 def on_instruction(self,uc,address,size,unused):
  if address not in self.hooks:
   self.native_instruction_count+=1
   if address in self.function_entries:self.visited_functions.add(address)
  super().on_instruction(uc,address,size,unused)
 def arguments(self,count):
  sp=self.uc.reg_read(UC_X86_REG_ESP)
  return list(struct.unpack('<'+'I'*count,self.uc.mem_read(sp+4,count*4)))
 def stdcall(self,result,pop):
  self.ret(result);self.uc.reg_write(UC_X86_REG_ESP,self.uc.reg_read(UC_X86_REG_ESP)+pop)
 def local_alloc(self):
  flags,size=self.arguments(2)
  if flags!=0 or self.local_next+size>self.local_base+0x10000:raise RuntimeError('Unexpected allocator LocalAlloc boundary '+repr((flags,size)))
  # LPTR/LMEM_ZEROINIT was NOT requested. Deliberately nonzero table bytes
  # establish that original52FFDC really writes its own table cells.
  address=self.local_next;self.local_next=(address+size+15)&~15
  self.uc.mem_write(address,b'\xa5'*size)
  self.events.append({'api':'LocalAlloc','flags':flags,'size':size,'address':hex(address),'boundary':'explicit nonzero diagnostic table payload'})
  self.stdcall(address,8)
 def virtual_alloc(self):
  address,size,flags,protect=self.arguments(4)
  if flags==0x2000:
   address=address or self.virtual_next;size=(size+0xffff)&~0xffff
   if address in self.reservations:raise RuntimeError('Unexpected overlapping reserve')
   self.uc.mem_map(address,size);self.reservations[address]=size;self.virtual_next=max(self.virtual_next,address+size)
  elif flags==0x1000:
   if not any(a<=address and address+size<=a+n for a,n in self.reservations.items()):raise RuntimeError('Commit without reservation')
   for page in range(address&~4095,(address+size+4095)&~4095,4096):
    if page not in self.committed:self.uc.mem_write(page,b'\0'*4096);self.committed.add(page)
  else:raise RuntimeError('Unimplemented VirtualAlloc flags '+hex(flags))
  self.events.append({'api':'VirtualAlloc','address':hex(address),'size':size,'flags':hex(flags),'protect':hex(protect),'boundary':'fresh committed pages zero by Win32 contract; existing committed pages preserved'})
  self.stdcall(address,16)
 def virtual_free(self):
  address,size,flags=self.arguments(3)
  requested_size=size
  if flags==0x4000:
   for page in range(address&~4095,(address+size+4095)&~4095,4096):self.committed.discard(page)
  elif flags==0x8000:
   if address not in self.reservations:raise RuntimeError('Unexpected VirtualFree release')
   size=self.reservations.pop(address);self.uc.mem_unmap(address,size)
   for page in range(address,address+size,4096):self.committed.discard(page)
  else:raise RuntimeError('Unexpected VirtualFree flags')
  self.events.append({'api':'VirtualFree','address':hex(address),'size':requested_size,'flags':hex(flags)})
  self.stdcall(1,12)
 def get(self,size):
  self.uc.reg_write(UC_X86_REG_EAX,size)
  return self.call(0x5306b0,b'')
 def free(self,pointer):
  self.uc.reg_write(UC_X86_REG_EAX,pointer)
  return self.call(0x530838,b'')

def main():
 probe=AllocatorProbe();guard=probe.get(0x1000);first=probe.get(0x4348)
 if not first:raise RuntimeError('Original GetMem failed')
 fresh=bytes(probe.uc.mem_read(first,0x4348))
 barrier=probe.get(0x4348)
 probe.uc.mem_write(first,b'\xa5'*0x4348)
 freed=probe.free(first);attempts=[];reused=0
 for _ in range(16):
  reused=probe.get(0x4348);attempts.append(hex(reused))
  if reused==first:break
 payload=bytes(probe.uc.mem_read(reused,0x4348))
 fields={hex(offset):payload[offset:offset+800].hex() for offset in (0x298,0x5b8,0x8d8,0x3cd8,0x3ff8)}
 report={'source_sha256':EXPECTED,'status':'executed','scope':'Actual default System5306B0/530838 allocation/free routines and their actual helpers; Win32 virtual-memory/critical-section and nonzero LocalAlloc table boundaries hosted. No GUI startup allocation history replayed.',
         'sequence':[{'op':'GetMem alignment guard','size':'0x1000','pointer':hex(guard)},{'op':'GetMem','size':'0x4348','pointer':hex(first)},{'op':'GetMem barrier','size':'0x4348','pointer':hex(barrier)},{'op':'diagnostic fill','value':'a5','size':'0x4348'},{'op':'FreeMem','pointer':hex(first),'return':freed},{'op':'GetMem until source selects recycled block','size':'0x4348','attempt_pointers':attempts}],
         'same_pointer_reused':first==reused,'fresh_payload_nonzero_bytes':sum(b!=0 for b in fresh),'fresh_nonzero_offsets':[i for i,b in enumerate(fresh) if b!=0],'reused_payload_a5_bytes':sum(b==0xa5 for b in payload),'reused_payload_sha256':hashlib.sha256(payload).hexdigest(),'slot_arrays_hex':fields,'api_events':probe.events,'native_function_entries':[hex(a) for a in sorted(probe.visited_functions)],'native_instruction_count':probe.native_instruction_count,
         'limitations':['Chosen virtual-address/OS API boundary, not the captured process layout','Runtime-selected external borlndmm path not executed','Whole application allocation/write history absent','Allocator choice depends on full shared client history; this sequence is not a factory default']}
 # Separate source alignment branch: freeing the arena-start block causes
 # actual RTL page decommit. Do not treat all freed blocks as retained bytes.
 alternate=AllocatorProbe();a=alternate.get(0x4348);b=alternate.get(0x4348)
 alternate.uc.mem_write(a,b'\xa5'*0x4348);alternate.free(a);c=alternate.get(0x4348)
 alt_payload=bytes(alternate.uc.mem_read(c,0x4348))
 report['decommit_variant']={'alignment_guard':False,'first':hex(a),'barrier':hex(b),'next_allocation':hex(c),'same_pointer':a==c,
                             'new_payload_a5_bytes':sum(x==0xa5 for x in alt_payload),'api_events':alternate.events,'native_function_entries':[hex(a) for a in sorted(alternate.visited_functions)],'native_instruction_count':alternate.native_instruction_count}
 destination=ROOT/'godot/docs/original_logic/default_allocator_probe.json';destination.write_text(json.dumps(report,indent=2)+'\n')
 print(json.dumps({k:report[k] for k in ('status','same_pointer_reused','fresh_payload_nonzero_bytes','reused_payload_a5_bytes')}))

if __name__=='__main__':main()
