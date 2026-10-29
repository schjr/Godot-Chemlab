"""Read-only strict import of observed gas operands; no precision inference."""
import argparse,base64,copy,json,re,stat,struct,zipfile
from pathlib import Path
from import_current_gdi_result import decode,digest,require
from analyze_original_particle_capture import address,blob,IMAGE_SHA,CS_SHA,EXPECTED_POINTERS
from analyze_original_pen_capture import PRIOR,PRIOR_SHA
ROOT=Path(__file__).resolve().parents[1]
PS=ROOT/'tools/windows/read_original_gas_operands.ps1'
CS=ROOT/'tools/windows/original_dib_read_probe.cs'
PS_SHA='1a9d1203adf0d19f8f21f42d3c36ddf04c94f0ebfd5605436ba1a8f333f80dbc'
CODE_SHA='79ecf0a1d428ae541775b3923f0e731fd33e72afe1efb22e947be94f2e2e7c59'
NAME_HEX='b6e8d0d4c6f8cce528c6f8cce529'
MEMBERS={'CodexGasOperands.json','read_original_gas_operands.ps1','original_dib_read_probe.cs'}
def read_archive(path,expected_sha):
 require(re.fullmatch('[0-9a-f]{64}',expected_sha) is not None,'Archive SHA encoding differs')
 require(path.stat().st_size<=12_000_000,'Archive exceeds bound')
 require(digest(path.read_bytes())==expected_sha,'Returned archive identity differs')
 with zipfile.ZipFile(path) as z:
  infos=z.infolist();require(len(infos)==3 and {i.filename for i in infos}==MEMBERS,'Archive members differ/duplicate')
  for i in infos:require(not i.is_dir() and not stat.S_ISLNK(i.external_attr>>16) and not(i.flag_bits&1) and i.file_size<=10_000_000 and i.compress_type in (0,8),'Unsafe/bounded archive entry differs')
  files={i.filename:z.read(i) for i in infos}
 require(digest(files['read_original_gas_operands.ps1'])==PS_SHA and digest(files['original_dib_read_probe.cs'])==CS_SHA,'Executed source identity differs')
 return decode(files['CodexGasOperands.json']),files

def spans():
 raw=PS.read_bytes();require(digest(raw)==PS_SHA,'Reviewed local reader differs')
 rows=re.findall(r"^  ,@\((0x[0-9a-f]+),(\d+),'([0-9a-f]+)','([^']+)'\)$",raw.decode(),re.M)
 require(len(rows)==10,'Reviewed constant corpus differs')
 return [(int(a,16),int(n),h,r) for a,n,h,r in rows]

def validate(data,prior):
 require(set(data)=={'format','image_sha256','process_id','module_base','whole_graph_equal_two_passes','graph','provenance'},'Root fields differ')
 require(data['format']=='chemlab-original-gas-operands-readonly-v1' and data['image_sha256']==IMAGE_SHA and type(data['process_id']) is int and data['process_id']==9348 and data['module_base']=='0x00400000','Pinned source/process differs')
 require(data['whole_graph_equal_two_passes'] is True,'Whole graph equality absent')
 p=data['provenance'];require(set(p)=={'reader_sha256','reader_cs_sha256','target_calls','target_writes','target_suspend','gdi_operations','gdi_flush','native_vcl_verified','rng_tls_status','floating_execution_context','scope'},'Provenance fields differ')
 require(p['reader_sha256']==PS_SHA and p['reader_cs_sha256']==CS_SHA,'Reader hashes differ')
 for k in ('target_calls','target_writes','target_suspend','gdi_operations','gdi_flush','native_vcl_verified'):require(p[k] is False,'Access/verification scope differs')
 require(p['rng_tls_status']==p['floating_execution_context']=='unobserved' and isinstance(p['scope'],str),'Unknown runtime context was invented')
 g=data['graph'];require(set(g)=={'before','after','constants','reagent_count','reagents','inert','blobs'},'Graph fields differ')
 state=g['before'];require(state==g['after'] and set(state)=={'main_form','run','pause','elapsed_hex','vessel_count'},'Checkpoint changed/fields differ')
 require(all(type(state[k]) is int for k in ('run','pause','vessel_count')) and state['run']==2 and state['pause']==0 and state['vessel_count']==6 and state['elapsed_hex']=='6cbc749318445240','Paused checkpoint differs')
 require(prior['image_sha256']==IMAGE_SHA and prior['process_id']==9348 and prior['before']==prior['after'],'Prior identity differs')
 for k in ('main_form','run','pause','elapsed_hex'):require(state[k]==prior['before'][k],'Prior checkpoint differs')
 require(isinstance(g['blobs'],list) and 0<len(g['blobs'])<=8192,'Blob count bound exceeded')
 memory={};total=0
 for b in g['blobs']:
  require(set(b)=={'address','bytes','role','base64','sha256'} and isinstance(b['role'],str),'Blob schema differs')
  a=address(b['address']);n=b['bytes'];require(type(n) is int and 0<n<=1_048_576 and a>=0x10000 and a+n<=0x100000000 and (a,n) not in memory,'Blob length/address/duplicate differs')
  raw=base64.b64decode(b['base64'],validate=True);require(len(raw)==n and digest(raw)==b['sha256'],'Blob digest/length differs');memory[a,n]=raw;total+=n
 require(total<=4_000_000,'Raw graph byte bound exceeded')
 ordered=sorted(memory)
 for i,(a,n) in enumerate(ordered):
  for c,m in ordered[i+1:]:
   if c>=a+n:break
   e=min(a+n,c+m);require(memory[a,n][c-a:e-a]==memory[c,m][:e-c],'Overlapping observations contradict')
 used=set()
 def get(a,n):
  require((a,n) in memory,f'Required span absent {a:#x}/{n:#x}');used.add((a,n));return memory[a,n]
 def u(a):return struct.unpack('<I',get(a,4))[0]
 require(u(0x57a6f8)==2 and u(0x5799c4)==address(state['main_form']) and u(address(state['main_form'])+0x5bc)==0 and get(0x5636cc,8).hex()==state['elapsed_hex'] and u(0x58779c)==6,'Raw checkpoint differs')
 require(struct.unpack('<6I',get(0x585850,24))==EXPECTED_POINTERS and len(prior['objects'])==6,'Six-vessel table differs')
 for i,v in enumerate(EXPECTED_POINTERS):require(get(v,0x4348)==blob(prior['objects'][i]['vessel'],0x4348,v),'Prior vessel bytes changed')
 require(digest(get(0x452d9c,0x8c))==CODE_SHA,'Original lookup code changed')
 expected=spans();require(len(g['constants'])==10,'Constant coverage differs');changed=[]
 for row,(a,n,h,role) in zip(g['constants'],expected):
  require(set(row)=={'address','bytes','role','observed_hex','image_hex','matches_original_image'},'Constant row fields differ')
  raw=get(a,n);matches=raw.hex()==h
  require(address(row['address'])==a and type(row['bytes']) is int and row['bytes']==n and row['role']==role and row['observed_hex']==raw.hex() and row['image_hex']==h and row['matches_original_image'] is matches,'Constant raw/projection/source differs')
  if not matches:changed.append(role)
 count=struct.unpack('<i',get(0x580a28,4))[0]
 require(0<count<=1024 and type(g['reagent_count']) is int and g['reagent_count']==count and len(g['reagents'])==count,'Catalog count/coverage differs')
 table=struct.unpack('<'+'I'*count,get(0x57bc08,count*4));matching=[]
 for i,(r,a) in enumerate(zip(g['reagents'],table)):
  require(set(r)=={'index','record','name_pointer','name_length','name_hex','ansi_header_hex','molar_mass_qword_hex'},'Reagent row fields differ')
  require(type(r['index']) is int and r['index']==i and address(r['record'])==a and a!=0,'Catalog order/pointer differs')
  raw=get(a,0x18);name=struct.unpack_from('<I',raw,8)[0];require(address(r['name_pointer'])==name,'Name pointer differs')
  if name:
   require(name>=65544,'Name pointer cannot supply header');header=get(name-8,8);length=struct.unpack_from('<i',header,4)[0];require(0<=length<=1024,'Name length exceeds bound')
   string=get(name-8,8+length+1);require(string[:8]==header and string[-1]==0,'Name header/terminator differs');name_hex=string[8:-1].hex();header_hex=header.hex()
  else:length=0;name_hex=header_hex=''
  require(type(r['name_length']) is int and r['name_length']==length and r['name_hex']==name_hex and r['ansi_header_hex']==header_hex and r['molar_mass_qword_hex']==raw[0x10:0x18].hex(),'Name/molar operand projection differs')
  if name_hex==NAME_HEX:matching.append(i)
 require(matching,'Exact recovered INERT byte name absent')
 inert=g['inert'];require(set(inert)=={'expected_name_hex','matching_indices','selected_index','selected_record','original_molar_mass_qword_hex','molar_mass_matches_original','selection'},'INERT fields differ')
 require(inert['expected_name_hex']==NAME_HEX and inert['matching_indices']==matching and all(type(i) is int for i in inert['matching_indices']) and type(inert['selected_index']) is int and inert['selected_index']==matching[0] and inert['selected_record']==g['reagents'][matching[0]] and inert['original_molar_mass_qword_hex']=='0000000000003d40' and inert['molar_mass_matches_original'] is (inert['selected_record']['molar_mass_qword_hex']=='0000000000003d40') and inert['selection']=='Original452D9C ascending first exact byte-name match','INERT selection/source/projection differs')
 require(used==set(memory),'Extra/unverified raw spans supplied')
 return dict(format='chemlab-observed-gas-operands-validation-v1',image_sha256=IMAGE_SHA,process_id=9348,native_vcl_verified=False,gdi_queue_drain_verified=False,rng_tls_status='unobserved',floating_execution_context='unobserved',precision_mode_inferred=False,arithmetic_rule_changed=False,scope='Observed raw gas operands only; stable changed values preserved, not substituted or interpreted as a floating execution context.',graph=copy.deepcopy(g),changed_constant_roles=changed,inert_molar_mass_matches_original=inert['molar_mass_matches_original'],prior_vessel_bytes_compared=6*0x4348)

def import_archive(path,expected_sha,output):
 require(not output.exists(),'Output already exists; preserve evidence')
 data,files=read_archive(path,expected_sha);raw=PRIOR.read_bytes();require(digest(raw)==PRIOR_SHA,'Pinned prior particle capture differs')
 report=validate(data,decode(raw));report.update(archive_sha256=expected_sha,capture_sha256=digest(files['CodexGasOperands.json']),prior_particle_capture_sha256=PRIOR_SHA)
 output.mkdir(parents=True,exist_ok=False)
 for name,raw in files.items():(output/name).write_bytes(raw)
 (output/'validation.json').write_text(json.dumps(report,indent=2)+'\n');return report

def main():
 p=argparse.ArgumentParser(description=__doc__);p.add_argument('archive',type=Path);p.add_argument('--sha256',required=True);p.add_argument('--output-directory',type=Path,required=True);a=p.parse_args();r=import_archive(a.archive,a.sha256,a.output_directory)
 print(json.dumps({k:r[k] for k in ('changed_constant_roles','inert_molar_mass_matches_original','native_vcl_verified','floating_execution_context')}))
if __name__=='__main__':main()
