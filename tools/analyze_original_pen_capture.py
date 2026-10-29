"""Strict read-only importer of the pinned Windows original pen-graph archive.
Produces isolated diagnostic VM memory, never a production VCL profile.
"""
import argparse,base64,copy,json,re,stat,struct,zipfile
from pathlib import Path
from import_current_gdi_result import decode,digest,require
from analyze_original_particle_capture import address,blob,IMAGE_SHA,CS_SHA,EXPECTED_POINTERS
ROOT=Path(__file__).resolve().parents[1]
PS_SHA='cea024c2ed7fac84f2d63d6a000bfea70e96df63db33e73376d5a0a49aa31546'
PRIOR=ROOT/'evidence/windows-runtime/particle-pool-results-2026-10-14/CodexParticleState.json'
PRIOR_SHA='d290a1db6a5d2e268da8d9e688464649bae47c7c4fd82b5838448a033fa72995'
PS=ROOT/'tools/windows/read_original_pen_graph.ps1'
CS=ROOT/'tools/windows/original_dib_read_probe.cs'
MEMBERS={'CodexVclPenState.json','read_original_pen_graph.ps1','original_dib_read_probe.cs'}
def read_archive(path,expected_sha):
 require(re.fullmatch('[0-9a-f]{64}',expected_sha) is not None,'Archive SHA256 encoding differs')
 require(path.stat().st_size<=10_000_000,'Archive exceeds transport bound')
 raw=path.read_bytes();require(digest(raw)==expected_sha,'Returned archive identity differs')
 with zipfile.ZipFile(path) as z:
  infos=z.infolist()
  require(len(infos)==3 and {i.filename for i in infos}==MEMBERS,'Archive members differ or duplicate')
  for i in infos:
   require(not i.is_dir() and not stat.S_ISLNK(i.external_attr>>16) and not (i.flag_bits&1),'Unsupported archive entry')
   require(i.compress_type in (zipfile.ZIP_STORED,zipfile.ZIP_DEFLATED) and i.file_size<=8_000_000,'Archive member exceeds bound or compression differs')
  files={i.filename:z.read(i) for i in infos}
 require(digest(files['read_original_pen_graph.ps1'])==PS_SHA,'Executed PowerShell source differs')
 require(digest(files['original_dib_read_probe.cs'])==CS_SHA,'Executed C# source differs')
 return decode(files['CodexVclPenState.json']),files

def pinned_spans():
 source=PS.read_bytes();require(digest(source)==PS_SHA,'Local reviewed pen reader differs')
 return [(int(a,16),int(n,16),h) for a,n,h in re.findall(r"@\((0x[0-9a-f]+), (0x[0-9a-f]+), '([0-9a-f]{64})'\)",source.decode())]

def validate(data,prior):
 require(set(data)=={'format','image_sha256','process_id','module_base','whole_graph_equal_two_passes','graph','provenance'},'Capture root fields differ')
 require(data['format']=='chemlab-original-vcl-pen-graph-readonly-v1' and data['image_sha256']==IMAGE_SHA and type(data['process_id']) is int and data['process_id']==9348 and data['module_base']=='0x00400000','Process/source identity differs')
 require(data['whole_graph_equal_two_passes'] is True,'Complete two-pass equality is absent')
 p=data['provenance']
 require(set(p)=={'reader_sha256','reader_cs_sha256','target_calls','target_writes','target_suspend','gdi_operations','gdi_flush','native_vcl_verified','rng_tls_status','scope'},'Provenance fields differ')
 require(p['reader_sha256']==PS_SHA and p['reader_cs_sha256']==CS_SHA,'Executed reader provenance differs')
 for key in ('target_calls','target_writes','target_suspend','gdi_operations','gdi_flush','native_vcl_verified'):require(p[key] is False,'Capture access/verification scope differs')
 require(p['rng_tls_status']=='unobserved' and isinstance(p['scope'],str),'Unknown TLS or capture scope was replaced')
 g=data['graph'];require(set(g)=={'before','after','bitmaps','registry','registry_record_size','registry_nodes','blobs'},'Graph fields differ')
 state=g['before'];require(state==g['after'],'Checkpoint changed')
 require(all(type(state.get(k)) is int for k in ('run','pause','vessel_count')),'Checkpoint integer encoding differs')
 require(set(state)=={'main_form','run','pause','elapsed_hex','vessel_count'} and state['run']==2 and state['pause']==0 and state['vessel_count']==6 and state['elapsed_hex']=='6cbc749318445240','Pinned paused checkpoint differs')
 require(state['main_form']==prior['before']['main_form'] and prior['before']==prior['after'] and prior['image_sha256']==IMAGE_SHA and prior['process_id']==9348,'Prior checkpoint identity differs')
 for key in ('run','pause','elapsed_hex'):require(state[key]==prior['before'][key],'Prior checkpoint scalar differs')
 require(isinstance(g['blobs'],list) and 0<len(g['blobs'])<=2048,'Blob count exceeds graph bound')
 memory={};total=0
 for b in g['blobs']:
  require(set(b)=={'address','bytes','role','base64','sha256'} and isinstance(b['role'],str),'Raw blob fields differ')
  a=address(b['address']);n=b['bytes']
  require(type(n) is int and 0<n<=1_048_576 and a>=0x10000 and a+n<=0x100000000,'Blob address/length out of bounds')
  require((a,n) not in memory,'Duplicate raw blob')
  raw=base64.b64decode(b['base64'],validate=True)
  require(len(raw)==n and digest(raw)==b['sha256'],'Raw byte length/digest differs')
  memory[a,n]=raw;total+=n
 require(total<=4_000_000,'Complete graph byte bound exceeded')
 ordered=sorted(memory)
 for i,(a,n) in enumerate(ordered):
  for c,m in ordered[i+1:]:
   if c>=a+n:break
   end=min(a+n,c+m)
   require(memory[a,n][c-a:end-a]==memory[c,m][:end-c],'Overlapping raw observations disagree')
 used=set()
 def get(a,n):
  require((a,n) in memory,f'Required raw span missing {a:#x}/{n:#x}')
  used.add((a,n));return memory[a,n]
 def u(a,n=4):return struct.unpack('<I',get(a,n)[:4])[0]
 for a,n,h in pinned_spans():require(digest(get(a,n))==h,'Original in-memory code/VMT differs')
 require(u(0x57a6f8)==2 and u(0x5799c4)==address(state['main_form']) and u(address(state['main_form'])+0x5bc)==0 and get(0x5636cc,8).hex()==state['elapsed_hex'] and u(0x58779c)==6,'Raw checkpoint differs from reported state')
 vessels=struct.unpack('<6I',get(0x585850,24));solids=struct.unpack('<6I',get(0x595214,24))
 require(vessels==EXPECTED_POINTERS and len(prior['objects'])==6,'Raw apparatus order differs')
 expected_links=[];prior_bytes_compared=0
 for i,v in enumerate(vessels):
  old=prior['objects'][i];vr=get(v,0x4348)
  require(vr==blob(old['vessel'],0x4348,v),'Vessel bytes changed since particle checkpoint')
  require(solids[i]==address(old['solid_pointer']),'Solid-pool pointer differs from checkpoint')
  prior_bytes_compared+=len(vr)
  expected_links.extend((v,f,'vessel-%d-%x'%(i,f)) for f in (0xfc,0xf8,0xf4))
  kind=struct.unpack_from('<i',vr,8)[0]
  if 100<kind<200 and solids[i]:
   sr=get(solids[i],0x3468c)
   require(sr==blob(old['solid'],0x3468c,solids[i]),'Solid pool bytes changed since particle checkpoint')
   prior_bytes_compared+=len(sr)
   expected_links.extend((solids[i],f,'solid-%d-%s'%(i,name)) for f,name in ((0x34678,'primary'),(0x3467c,'retained')))
 require(len(g['bitmaps'])==len(expected_links),'Bitmap graph coverage differs')
 pen_records=[];available=0;unavailable=[]
 for link,(owner,offset,role) in zip(g['bitmaps'],expected_links):
  require(link['role']==role and address(link['owner'])==owner and link['offset']==f'0x{offset:x}','Bitmap graph role/order/crosslink differs')
  b=u(owner+offset);require(address(link['bitmap'])==b,'Bitmap pointer disagrees with raw source')
  if not b:
   require(link['canvas_status']=='unavailable' and link.get('reason')=='Null existing TBitmap; no constructor called','Missing bitmap state was replaced')
   require(set(link)=={'role','owner','offset','bitmap','canvas_status','reason'},'Null bitmap link fields differ')
   unavailable.append(copy.deepcopy(link));continue
  br=get(b,0x34);require(struct.unpack_from('<I',br)[0]==0x4e2af4,'TBitmap VMT differs')
  shared,canvas=struct.unpack_from('<II',br,0x20)
  require(shared!=0 and address(link['shared_image'])==shared and address(link['canvas'])==canvas,'Bitmap/shared/Canvas crosslink differs');get(shared,0x74)
  if not canvas:
   require(link['canvas_status']=='unavailable' and link.get('reason')=='Canvas has not been constructed; read-only capture cannot obtain it','Missing Canvas was constructed or obscured')
   require(set(link)=={'role','owner','offset','bitmap','canvas_status','reason','shared_image','canvas'},'Missing Canvas link fields differ')
   unavailable.append(copy.deepcopy(link));continue
  require(set(link)=={'role','owner','offset','bitmap','canvas_status','shared_image','canvas','pen','shared_pen_record','event_code','event_owner','lock','dc_handle','canvas_flags'} and link['canvas_status']=='read','Existing Canvas link fields differ')
  cr=get(canvas,0x64);require(struct.unpack_from('<I',cr)[0]==0x4e80d0 and struct.unpack_from('<I',cr,0x58)[0]==b,'Canvas VMT/owner differs')
  pen=struct.unpack_from('<I',cr,0x10)[0];pr=get(pen,0x1c);require(struct.unpack_from('<I',pr)[0]==0x4e2420,'Pen VMT differs')
  event,owner2,record,lock=struct.unpack_from('<IIII',pr,8)
  require(event==0x4e4dec and owner2==canvas and lock==canvas+0x38 and record!=0,'Pen source event/lock/record binding differs')
  for name,value in [('pen',pen),('shared_pen_record',record),('event_code',event),('event_owner',owner2),('lock',lock),('dc_handle',struct.unpack_from('<I',cr,4)[0])]:require(address(link[name])==value,'Pen/Canvas reported crosslink differs: '+name)
  require(type(link['canvas_flags']) is int and link['canvas_flags']==cr[8],'Canvas flags differ');get(lock,24)
  pen_records.append(record);available+=1
 registry=u(0x59a9e4);require(address(g['registry'])==registry and registry!=0,'Registry pointer differs')
 header=get(registry,0x24);require(struct.unpack_from('<I',header)[0]==0x4e2d1c and struct.unpack_from('<H',header,0x20)[0]==16 and type(g['registry_record_size']) is int and g['registry_record_size']==16,'Registry class/record size differs')
 get(registry+8,24);u(0x59a9a0)
 node=struct.unpack_from('<I',header,4)[0];seen=[]
 while node:
  require(node not in seen and len(seen)<512,'Registry cycle/excess')
  seen.append(node);raw=get(node,32);node=struct.unpack_from('<I',raw)[0]
 require([address(s) for s in g['registry_nodes']]==seen,'Registry ordered list is incomplete or fabricated')
 require(all(p in seen for p in pen_records),'Pen record is not in complete registry')
 require(used==set(memory),'Unrelated or unverified extra raw spans supplied')
 return dict(format='chemlab-isolated-observed-pen-graph-v1',image_sha256=IMAGE_SHA,process_id=9348,module_base='0x00400000',checkpoint=copy.deepcopy(state),native_vcl_verified=False,production_startup_profile_verified=False,gdi_queue_drain_verified=False,rng_tls_status='unobserved',target_handles_usable=False,scope='Diagnostic read-only graph from a pinned paused checkpoint. Absolute raw addresses are retained, not promoted to local handles or production providers.',graph=copy.deepcopy(g),memory_blobs=copy.deepcopy(g['blobs']),available_canvas_links=available,unavailable_canvas_links=unavailable,registry_node_count=len(seen),prior_raw_bytes_compared=prior_bytes_compared)

def import_archive(path,expected_sha,output):
 require(not output.exists(),'Output exists; preserve prior evidence')
 data,files=read_archive(path,expected_sha)
 prior_raw=PRIOR.read_bytes();require(digest(prior_raw)==PRIOR_SHA,'Pinned particle checkpoint file differs')
 report=validate(data,decode(prior_raw));report.update(archive_sha256=expected_sha,capture_sha256=digest(files['CodexVclPenState.json']),prior_particle_capture_sha256=PRIOR_SHA)
 output.mkdir(parents=True,exist_ok=False)
 for name,raw in files.items():(output/name).write_bytes(raw)
 (output/'isolated-pen-graph.json').write_text(json.dumps(report,indent=2)+'\n')
 return report

def main():
 p=argparse.ArgumentParser(description=__doc__);p.add_argument('archive',type=Path);p.add_argument('--sha256',required=True);p.add_argument('--output-directory',required=True,type=Path);a=p.parse_args()
 report=import_archive(a.archive,a.sha256,a.output_directory)
 print(json.dumps({k:report[k] for k in ('available_canvas_links','registry_node_count','prior_raw_bytes_compared','native_vcl_verified','rng_tls_status')}))
if __name__=='__main__':main()
