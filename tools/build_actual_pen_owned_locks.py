"""Original PE setter with genuine fresh host RLocks, not target/Win32 locks.

Cross-platform reconstructed primitive scope only. All non-lock captured bytes
and source call order are retained for the separate Godot Mutex diagnostic.
"""
import hashlib,json,threading
from pathlib import Path
from unicorn import UC_HOOK_MEM_READ
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX
from build_actual_pen_frontier import ObservedOracle,require,CAPTURE_SHA,ARCHIVE_SHA
from original_x86_oracle import ROOT
FIXTURE_SHA='a90c7f6013967d13e84f9188a9e36a3b62893989d6b672d71c61a4a7182cf334'
class OwnedLockOracle(ObservedOracle):
 def __init__(self,world,identities,ranges):
  super().__init__(world['segments']);self.locks={a:threading.RLock() for a in identities};self.depth={a:0 for a in identities};self.trace=[];self.lock_reads=[]
  self.hooks[0x554ec4]=lambda:self.operation('EnterCriticalSection')
  self.hooks[0x555020]=lambda:self.operation('LeaveCriticalSection')
  self.uc.hook_add(UC_HOOK_MEM_READ,lambda uc,kind,a,size,value,data:self.read_guard(a,size,ranges))
 def read_guard(self,address,size,ranges):
  if any(address<r['address']+r['size'] and r['address']<address+size for r in ranges):
   self.lock_reads.append([address,size]);raise ValueError('Original application unexpectedly reads a historical lock interior')
 def operation(self,api):
  address=self.args(1)[0];require(address in self.locks,'Unprovided fresh lock identity')
  if api=='EnterCriticalSection':self.locks[address].acquire();self.depth[address]+=1
  else:
   require(self.depth[address]>0,'Original source unbalanced release');self.locks[address].release();self.depth[address]-=1
  self.trace.append(dict(api=api,address=address,source_pc=0x554ec4 if api=='EnterCriticalSection' else 0x555020))
  self.stdcall_void()
 def stdcall_void(self):
  from unicorn.x86_const import UC_X86_REG_ESP
  self.ret();self.uc.reg_write(UC_X86_REG_ESP,self.uc.reg_read(UC_X86_REG_ESP)+4)
def build():
 path=ROOT/'godot/tests/fixtures/actual_pen_frontier.json';raw=path.read_bytes();require(hashlib.sha256(raw).hexdigest()==FIXTURE_SHA,'Actual bounded fixture identity changed');base=json.loads(raw)
 graph=json.loads((ROOT/'evidence/windows-runtime/vcl-pen-results-2026-10-14/isolated-pen-graph.json').read_text())
 require(graph['capture_sha256']==CAPTURE_SHA and graph['archive_sha256']==ARCHIVE_SHA,'Actual capture provenance differs')
 ranges=[dict(address=int(b['address'],16),size=b['bytes']) for b in graph['memory_blobs'] if 'critical-section' in b['role']]
 pen=base['operation']['pen'];canvas=base['frontier']['address'];registry=base['world']['globals']['0x59a9e4']+8;ids=[canvas,registry]
 oracle=OwnedLockOracle(base['world'],ids,ranges)
 oracle.uc.reg_write(UC_X86_REG_EAX,pen);oracle.uc.reg_write(UC_X86_REG_EDX,base['operation']['color']);oracle.call(0x4e3e50,b'')
 require(not any(oracle.depth.values()) and not oracle.lock_reads,'Source must balance fresh locks without inspecting historical interiors')
 require(len(oracle.trace)==8,'Unexpected original setter primitive sequence')
 # Compare each observed span with historical lock bytes removed, including lock
 # interiors duplicated inside larger Canvas/resource-manager capture spans.
 segments=[]
 for s in base['world']['segments']:
  at=s['address'];size=len(s['hex'])//2;start=None
  for p in range(at,at+size+1):
   keep=p<at+size and not any(r['address']<=p<r['address']+r['size'] for r in ranges)
   if keep and start is None:start=p
   if not keep and start is not None:
    segments.append(dict(address=start,hex=bytes(oracle.uc.mem_read(start,p-start)).hex()));start=None
 result=dict(format='chemlab-actual-pen-fresh-owned-locks-v1',capture_sha256=CAPTURE_SHA,source_sha256=base['source_sha256'],world=base['world'],operation=base['operation'],lock_identities=ids,historical_lock_ranges=ranges,trace=oracle.trace,after_nonlock_segments=segments,
  completed_reconstructed_setter=True,native_win32_verified=False,native_vcl_verified=False,target_handles_usable=False,
  primitive_provider='Genuine fresh Python threading.RLock on emulator caller OS thread, keyed by source identity; no Windows or captured ownership attestation')
 out=ROOT/'godot/tests/fixtures/actual_pen_owned_locks.json';require(not out.exists(),'Preserve existing fixture');out.write_text(json.dumps(result,indent=2)+'\n')
 print(json.dumps(dict(fixture_sha256=hashlib.sha256(out.read_bytes()).hexdigest(),trace=oracle.trace,nonlock_spans=len(segments),nonlock_bytes=sum(len(s['hex'])//2 for s in segments),native_win32_verified=False)))
if __name__=='__main__':build()
