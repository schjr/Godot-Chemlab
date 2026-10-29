"""Synthetic transport/graph tests; does not fabricate actual gas evidence."""
import base64,copy,json,struct,sys,tempfile,unittest,zipfile
from pathlib import Path
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
from analyze_original_gas_operands import *
def fixture(changed=False):
 prior=decode(PRIOR.read_bytes());memory={}
 def put(a,raw):memory[a,len(raw)]=bytes(raw)
 state=dict(prior['before'],vessel_count=6)
 for a,value in [(0x57a6f8,2),(0x5799c4,address(state['main_form'])),(address(state['main_form'])+0x5bc,0),(0x58779c,6)]:put(a,struct.pack('<I',value))
 put(0x5636cc,bytes.fromhex(state['elapsed_hex']));put(0x585850,struct.pack('<6I',*EXPECTED_POINTERS))
 for i,v in enumerate(EXPECTED_POINTERS):put(v,blob(prior['objects'][i]['vessel'],0x4348,v))
 constants=[]
 for i,(a,n,h,role) in enumerate(spans()):
  raw=bytearray.fromhex(h)
  if changed and i==0:raw[0]^=1
  put(a,raw);constants.append(dict(address=f'0x{a:08x}',bytes=n,role=role,observed_hex=raw.hex(),image_hex=h,matches_original_image=raw.hex()==h))
 pe=(ROOT/'artifacts/ChemLab/_main.exe').read_bytes();nt=struct.unpack_from('<I',pe,60)[0];count=struct.unpack_from('<H',pe,nt+6)[0];off=nt+24+struct.unpack_from('<H',pe,nt+20)[0]
 for i in range(count):
  _,r,z,t=struct.unpack_from('<4I',pe,off+i*40+8)
  if r<=0x452d9c-0x400000<r+z:put(0x452d9c,pe[t+0x452d9c-0x400000-r:t+0x452d9c-0x400000-r+0x8c]);break
 names=[b'embedded\x00name',bytes.fromhex(NAME_HEX),bytes.fromhex(NAME_HEX),b'']
 records=[];pointers=[]
 for i,name in enumerate(names):
  p=0x23000000+i*0x100;namep=0x24000008+i*0x100;pointers.append(p)
  header=struct.pack('<ii',1,len(name));put(namep-8,header);put(namep-8,header+name+b'\x00')
  raw=bytearray(0x18);struct.pack_into('<I',raw,8,namep);mass=struct.pack('<d',30 if changed and i==1 else 29);raw[0x10:0x18]=mass;put(p,raw)
  records.append(dict(index=i,record=f'0x{p:08x}',name_pointer=f'0x{namep:08x}',name_length=len(name),name_hex=name.hex(),ansi_header_hex=header.hex(),molar_mass_qword_hex=mass.hex()))
 put(0x580a28,struct.pack('<i',len(records)));put(0x57bc08,struct.pack('<4I',*pointers))
 inert=dict(expected_name_hex=NAME_HEX,matching_indices=[1,2],selected_index=1,selected_record=copy.deepcopy(records[1]),original_molar_mass_qword_hex='0000000000003d40',molar_mass_matches_original=not changed,selection='Original452D9C ascending first exact byte-name match')
 blobs=[dict(address=f'0x{a:08x}',bytes=n,role='Synthetic transport only',base64=base64.b64encode(b).decode(),sha256=digest(b)) for (a,n),b in memory.items()]
 graph=dict(before=state,after=copy.deepcopy(state),constants=constants,reagent_count=len(records),reagents=records,inert=inert,blobs=blobs)
 provenance=dict(reader_sha256=PS_SHA,reader_cs_sha256=CS_SHA,target_calls=False,target_writes=False,target_suspend=False,gdi_operations=False,gdi_flush=False,native_vcl_verified=False,rng_tls_status='unobserved',floating_execution_context='unobserved',scope='Synthetic transport fixture only')
 return dict(format='chemlab-original-gas-operands-readonly-v1',image_sha256=IMAGE_SHA,process_id=9348,module_base='0x00400000',whole_graph_equal_two_passes=True,graph=graph,provenance=provenance),prior

def mutate(data,a,n,offset,value):
 b=next(b for b in data['graph']['blobs'] if address(b['address'])==a and b['bytes']==n);raw=bytearray(base64.b64decode(b['base64']));raw[offset]=value;b.update(base64=base64.b64encode(raw).decode(),sha256=digest(raw))
class GasOperandCapture(unittest.TestCase):
 def test_exact_full_bytes_first_match_and_unknown_context(self):
  d,p=fixture();original=copy.deepcopy(d);r=validate(d,p)
  self.assertEqual(d,original);self.assertEqual(r['graph'],d['graph']);self.assertEqual(r['graph']['inert']['selected_index'],1);self.assertEqual(r['changed_constant_roles'],[])
  self.assertFalse(r['native_vcl_verified']);self.assertFalse(r['precision_mode_inferred']);self.assertEqual(r['floating_execution_context'],'unobserved')
  self.assertEqual(r['graph']['reagents'][0]['name_hex'],b'embedded\x00name'.hex())
 def test_changed_live_constants_and_molar_mass_are_preserved(self):
  d,p=fixture(True);r=validate(d,p);self.assertEqual(r['changed_constant_roles'],['quantity22.4']);self.assertFalse(r['inert_molar_mass_matches_original']);self.assertEqual(r['graph'],d['graph'])
 def test_null_name_remains_empty_without_constructed_string(self):
  d,p=fixture();r=d['graph']['reagents'][3]
  r.update(name_pointer='0x00000000',name_hex='',name_length=0,ansi_header_hex='')
  mutate(d,0x23000300,0x18,8,0)
  mutate(d,0x23000300,0x18,9,0)
  mutate(d,0x23000300,0x18,10,0)
  mutate(d,0x23000300,0x18,11,0)
  d['graph']['blobs']=[b for b in d['graph']['blobs'] if address(b['address'])!=0x24000300]
  report=validate(d,p)
  self.assertEqual(report['graph']['reagents'][3]['name_pointer'],'0x00000000')
 def test_guessed_later_match_or_index_rejected(self):
  d,p=fixture();d['graph']['inert']['selected_index']=2;d['graph']['inert']['selected_record']=d['graph']['reagents'][2]
  with self.assertRaises(ValueError):validate(d,p)
  d,p=fixture();d['graph']['inert']['matching_indices']=[1]
  with self.assertRaises(ValueError):validate(d,p)
 def test_checkpoint_context_and_scope_rejected(self):
  for k,v in [('process_id',1),('whole_graph_equal_two_passes',False),('rng',{'low':1})]:
   d,p=fixture();d[k]=v
   with self.assertRaises(ValueError):validate(d,p)
  for k,v in [('floating_execution_context','PC64'),('native_vcl_verified',True),('target_calls',True)]:
   d,p=fixture();d['provenance'][k]=v
   with self.assertRaises(ValueError):validate(d,p)
 def test_rehashed_code_vessel_and_string_corruption_rejected(self):
  for a,n,off in [(0x452d9c,0x8c,0),(EXPECTED_POINTERS[0],0x4348,0),(0x24000100,8,4),(0x24000100,8+len(bytes.fromhex(NAME_HEX))+1,8+len(bytes.fromhex(NAME_HEX)))]:
   d,p=fixture();mutate(d,a,n,off,123)
   with self.assertRaises(ValueError):validate(d,p)
 def test_digest_table_crosslinks_duplicates_and_missing_blobs_rejected(self):
  d,p=fixture();d['graph']['blobs'][0]['sha256']='0'*64
  with self.assertRaises(ValueError):validate(d,p)
  d,p=fixture();d['graph']['reagents'][0]['name_pointer']='0x24000208'
  with self.assertRaises(ValueError):validate(d,p)
  d,p=fixture();d['graph']['blobs'].append(copy.deepcopy(d['graph']['blobs'][0]))
  with self.assertRaises(ValueError):validate(d,p)
  d,p=fixture();d['graph']['blobs'].pop()
  with self.assertRaises(ValueError):validate(d,p)
 def test_archive_source_member_hash_and_preserve_output(self):
  d,p=fixture(True)
  with tempfile.TemporaryDirectory() as tmp:
   zpath=Path(tmp)/'synthetic.zip'
   def write(extra=False,wrong=False):
    with zipfile.ZipFile(zpath,'w') as z:
     z.writestr('CodexGasOperands.json',json.dumps(d));z.writestr('read_original_gas_operands.ps1',b'changed' if wrong else PS.read_bytes());z.writestr('original_dib_read_probe.cs',CS.read_bytes())
     if extra:z.writestr('../bad','x')
   write();output=Path(tmp)/'fresh';r=import_archive(zpath,digest(zpath.read_bytes()),output);self.assertFalse(r['inert_molar_mass_matches_original'])
   with self.assertRaises(ValueError):import_archive(zpath,digest(zpath.read_bytes()),output)
   write(extra=True)
   with self.assertRaises(ValueError):read_archive(zpath,digest(zpath.read_bytes()))
   write(wrong=True)
   with self.assertRaises(ValueError):read_archive(zpath,digest(zpath.read_bytes()))
   write()
   with self.assertRaises(ValueError):read_archive(zpath,'0'*64)
if __name__=='__main__':unittest.main()
