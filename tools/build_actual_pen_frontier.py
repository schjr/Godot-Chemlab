"""Compare an actual captured pen graph up to the first unprovided primitive.

Runs original PE bytes only in an isolated emulator. Foreign handles remain
identities. No target calls, successful primitive stubs, or live thread claims.
"""
import argparse, base64, hashlib, json, struct
from pathlib import Path
from analyze_original_pen_capture import validate, decode, PRIOR, PRIOR_SHA
from original_x86_oracle import OriginalOracle, ROOT, EXPECTED
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EDX, UC_X86_REG_ESP, UC_X86_REG_EBP, UC_X86_REG_EIP

CAPTURE_SHA='55efb5a1c8cba1556689dee25ca6bcc984b3740e80e47866fd100e9ef5ce7787'
ARCHIVE_SHA='c74791baf575cb1880abf5d318525aad63c07e258c639d51921fb424f72ba24b'
def digest(raw):return hashlib.sha256(raw).hexdigest()
def require(ok,message):
 if not ok:raise ValueError(message)
def integer(value):return int(value,16) if isinstance(value,str) else int(value)
class Frontier(Exception):pass
class ObservedOracle(OriginalOracle):
 def __init__(self,segments):
  super().__init__();self.attempts=[]
  pages={p for lo,hi,_ in self.uc.mem_regions() for p in range(lo&~4095,(hi+4096)&~4095,4096)}
  for segment in segments:
   at=segment['address'];raw=bytes.fromhex(segment['hex'])
   for page in range(at&~4095,(at+len(raw)+4095)&~4095,4096):
    if page not in pages:self.uc.mem_map(page,4096);pages.add(page)
   self.uc.mem_write(at,raw)
  self.hooks={0x554ec4:lambda:self.stop('EnterCriticalSection',address=self.args(1)[0]),0x555020:lambda:self.stop('LeaveCriticalSection',address=self.args(1)[0]),
   0x530c70:lambda:self.stop('GetMem',size=self.uc.reg_read(UC_X86_REG_EAX)),0x530c88:lambda:self.stop('FreeMem',address=self.uc.reg_read(UC_X86_REG_EAX)),
   0x5552d8:lambda:self.stop('DeleteObject',handle=self.args(1)[0]),0x5553f8:lambda:self.stop('SelectObject',hdc=self.args(2)[0],handle=self.args(2)[1]),
   0x5552b4:lambda:self.stop('CreatePenIndirect',logpen_hex=bytes(self.uc.mem_read(self.args(1)[0],12)).hex()),0x555678:lambda:self.stop('GetSysColor',index=self.args(1)[0])}
 def args(self,n):return struct.unpack('<'+'I'*n,self.uc.mem_read(self.uc.reg_read(UC_X86_REG_ESP)+4,n*4))
 def stop(self,api,**kwargs):
  self.attempts.append(dict(api=api,source_pc=self.uc.reg_read(UC_X86_REG_EIP),**kwargs));raise Frontier(api)
 def prefix(self,pen,color):
  self.uc.mem_write(0x90ffe00,struct.pack('<I',self.stop_address));self.uc.reg_write(UC_X86_REG_ESP,0x90ffe00);self.uc.reg_write(UC_X86_REG_EBP,0)
  self.uc.reg_write(UC_X86_REG_EAX,pen);self.uc.reg_write(UC_X86_REG_EDX,color);self.u32(0,0xffffffff)
  try:self.uc.emu_start(0x4e3e50,self.stop_address,count=200000)
  except Frontier:pass
  require(len(self.attempts)==1,'First setter did not reach exactly one explicit primitive frontier')
  return self.attempts[0]
def build(directory,output):
 capture=(directory/'CodexVclPenState.json').read_bytes();require(digest(capture)==CAPTURE_SHA,'Actual capture SHA differs')
 prior=PRIOR.read_bytes();require(digest(prior)==PRIOR_SHA,'Prior particle capture SHA differs')
 expected=validate(decode(capture),decode(prior))
 graph=json.loads((directory/'isolated-pen-graph.json').read_text())
 for field,value in expected.items():require(graph.get(field)==value,'Validated isolated graph differs: '+field)
 require(graph.get('archive_sha256')==ARCHIVE_SHA and graph.get('capture_sha256')==CAPTURE_SHA,'Archive/capture provenance missing')
 segments=[dict(address=integer(b['address']),hex=base64.b64decode(b['base64'],validate=True).hex()) for b in graph['memory_blobs']]
 def read(at,size):
  result=bytearray()
  for offset in range(size):
   values=[bytes.fromhex(s['hex'])[at+offset-s['address']] for s in segments if s['address']<=at+offset<s['address']+len(s['hex'])//2]
   require(values and len(set(values))==1,'Missing/conflicting captured bytes');result.append(values[0])
  return bytes(result)
 def u32(at):return struct.unpack('<I',read(at,4))[0]
 link=next(b for b in graph['graph']['bitmaps'] if b['role']=='solid-0-primary')
 require(link['canvas_status']=='read','Actual first solid Canvas unavailable')
 pen=integer(link['pen']);owner=integer(link['owner']);color=u32(owner+0x32d50);record=u32(pen+0x10)
 world=dict(source_sha256=EXPECTED,scope='Actual PID9348 paused pen graph; isolated diagnostic fresh FS/stack, no live thread or usable handle attestation',segments=segments,
  globals={'0x59a9e4':u32(0x59a9e4),'0x59a9a0':u32(0x59a9a0)},thread=dict(fs_base=0,exception_head=0xffffffff,stack_base=0x9000000,stack_size=0x100000,stack_pointer=0x90ffe00,stack_origin='fresh_committed_pages'))
 oracle=ObservedOracle(segments);frontier=oracle.prefix(pen,color)
 result=dict(format='chemlab-actual-pen-frontier-v1',source_sha256=EXPECTED,capture_sha256=CAPTURE_SHA,archive_sha256=ARCHIVE_SHA,isolated_graph_sha256=digest((directory/'isolated-pen-graph.json').read_bytes()),world=world,
  operation=dict(pen=pen,color=color,old_color=u32(record+0x14),same_color=color==u32(record+0x14)),frontier=frontier,
  after_segments=[dict(address=s['address'],hex=bytes(oracle.uc.mem_read(s['address'],len(s['hex'])//2)).hex()) for s in segments],completed_setter=False,native_vcl_verified=False,target_handles_usable=False)
 require(frontier['api']=='EnterCriticalSection' and frontier['address']==integer(link['lock']),'Unexpected actual first source boundary')
 output.parent.mkdir(parents=True,exist_ok=True);require(not output.exists(),'Preserve existing fixture; output already exists');output.write_text(json.dumps(result,indent=2)+'\n')
 return result
if __name__=='__main__':
 p=argparse.ArgumentParser(description=__doc__);p.add_argument('capture_directory',type=Path);p.add_argument('--output',type=Path,default=ROOT/'godot/tests/fixtures/actual_pen_frontier.json');a=p.parse_args();r=build(a.capture_directory,a.output)
 print(json.dumps({k:r[k] for k in ('operation','frontier','completed_setter','native_vcl_verified')}))
