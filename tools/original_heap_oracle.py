"""Native allocator address/byte/list-state reference sequences."""
import hashlib,json,struct,random
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX
from probe_original_default_allocator import AllocatorProbe
from original_x86_oracle import ROOT,EXPECTED

def snapshot(probe):
 return {'globals_59b170':bytes(probe.uc.mem_read(0x59b170,0x78)).hex(),
         'local_blocks':[{'address':e['address'],'size':e['size'],'bytes':bytes(probe.uc.mem_read(int(e['address'],16),e['size'])).hex()} for e in probe.events if e['api']=='LocalAlloc'],
         'pages':[{'address':hex(page),'sha256':hashlib.sha256(bytes(probe.uc.mem_read(page,4096))).hexdigest()} for page in sorted(probe.committed)],
         'reservations':{hex(a):size for a,size in probe.reservations.items()},'api_events':probe.events.copy()}

def run(name,operations):
 probe=AllocatorProbe();pointers={};steps=[]
 for operation in operations:
  op=operation['op'];value=None
  if op=='get':value=probe.get(operation['size']);pointers[operation['id']]=value
  elif op=='free':value=probe.free(pointers[operation['id']])
  elif op=='fill':
   p=pointers[operation['id']];probe.uc.mem_write(p,bytes.fromhex(operation['hex']))
  elif op=='realloc':
   probe.uc.reg_write(UC_X86_REG_EAX,pointers[operation['id']]);probe.uc.reg_write(UC_X86_REG_EDX,operation['size'])
   value=probe.call(0x530bac,b'');pointers[operation['id']]=value
  else:raise ValueError(op)
  steps.append({'operation':operation,'value':value,'pointers':pointers.copy(),'state':snapshot(probe)})
 return {'name':name,'status':'executed','steps':steps}

def main():
 cases=[]
 cases.append(run('guarded apparatus reuse',[{'op':'get','id':'guard','size':0x1000},{'op':'get','id':'a','size':0x4348},{'op':'get','id':'barrier','size':0x4348},{'op':'fill','id':'a','hex':('a5'*0x4348)},{'op':'free','id':'a'},{'op':'get','id':'a2','size':0x4348}]))
 cases.append(run('arena-start apparatus decommit',[{'op':'get','id':'a','size':0x4348},{'op':'get','id':'barrier','size':0x4348},{'op':'fill','id':'a','hex':('a5'*0x4348)},{'op':'free','id':'a'},{'op':'get','id':'a2','size':0x4348}]))
 cases.append(run('source realloc grow move shrink',[{'op':'get','id':'a','size':17},{'op':'get','id':'barrier','size':32},{'op':'fill','id':'a','hex':bytes(range(17)).hex()},{'op':'realloc','id':'a','size':150},{'op':'realloc','id':'a','size':9},{'op':'free','id':'a'},{'op':'free','id':'barrier'}]))
 rng=random.Random(9348);operations=[];live=[];next_id=0
 for _ in range(48):
  if live and rng.random()<0.38:
   chosen=live.pop(rng.randrange(len(live)));operations.append({'op':'free','id':chosen})
  else:
   identifier='a'+str(next_id);next_id+=1;size=rng.choice([1,4,11,12,17,31,88,232,4095,4096,0x2d60,0x4348,65536])
   operations.append({'op':'get','id':identifier,'size':size});live.append(identifier)
 for identifier in reversed(live):operations.append({'op':'free','id':identifier})
 cases.append(run('deterministic mixed original client sizes',operations))
 report={'source_sha256':EXPECTED,'status':'executed','profile':'Original default System allocator bytes; explicit chosen virtual addresses, nonzero LocalAlloc bookkeeping payload, fresh VirtualAlloc commit semantics. No GUI bootstrap or universal allocation defaults. Random9348 selects test operations only, not app RNG.',
         'cases':cases}
 destination=ROOT/'godot/tests/fixtures/original_shared_heap.json';destination.write_text(json.dumps(report,indent=2)+'\n')
 print(json.dumps({'cases':len(cases),'steps':sum(len(c['steps']) for c in cases),'bytes':destination.stat().st_size}))

if __name__=='__main__':main()
