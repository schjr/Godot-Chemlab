"""Synthetic pen transport/graph rejection tests; no runtime attestation."""
import base64,copy,json,struct,sys,tempfile,unittest,zipfile
from pathlib import Path
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
from analyze_original_pen_capture import *

def fixture(available=True):
 prior=decode(PRIOR.read_bytes());memory={};links=[]
 def put(a,raw,role='Synthetic transport only'):
  key=a,len(raw)
  if key in memory:assert memory[key]==bytes(raw)
  memory[key]=bytes(raw)
 def raw_owner(a,n):return memory[a,n]
 def ptr(owner,offset,n):
  p=struct.unpack_from('<I',raw_owner(owner,n),offset)[0];put(owner+offset,struct.pack('<I',p));return p
 state=dict(prior['before'],vessel_count=6)
 put(0x57a6f8,struct.pack('<I',2));put(0x5799c4,struct.pack('<I',address(state['main_form'])));put(address(state['main_form'])+0x5bc,bytes(4));put(0x5636cc,bytes.fromhex(state['elapsed_hex']));put(0x58779c,struct.pack('<I',6))
 vp=[];sp=[];owners=[]
 for i,old in enumerate(prior['objects']):
  v=EXPECTED_POINTERS[i];vr=blob(old['vessel'],0x4348,v);put(v,vr);vp.append(v);s=address(old['solid_pointer']);sp.append(s)
  owners.extend((v,f,'vessel-%d-%x'%(i,f),0x4348) for f in (0xfc,0xf8,0xf4))
  if 'solid' in old:
   put(s,blob(old['solid'],0x3468c,s));owners.extend((s,f,'solid-%d-%s'%(i,name),0x3468c) for f,name in ((0x34678,'primary'),(0x3467c,'retained')))
 put(0x585850,struct.pack('<6I',*vp));put(0x595214,struct.pack('<6I',*sp))
 registry=0x21000000;node=registry+0x100;pen=node+0x100;canvas=pen+0x100
 for i,(owner,f,role,n) in enumerate(owners):
  b=ptr(owner,f,n);shared=0x22000000+i*0x100
  link=dict(role=role,owner=f'0x{owner:08x}',offset=f'0x{f:x}',bitmap=f'0x{b:08x}',canvas_status='unavailable')
  if not b:link['reason']='Null existing TBitmap; no constructor called';links.append(link);continue
  br=bytearray(0x34);struct.pack_into('<I',br,0,0x4e2af4);struct.pack_into('<II',br,0x20,shared,canvas if i==0 and available else 0);put(b,br);put(shared,bytes(0x74))
  link.update(shared_image=f'0x{shared:08x}',canvas=f'0x{canvas:08x}' if i==0 and available else '0x00000000')
  if i==0 and available:
   cr=bytearray(0x64);struct.pack_into('<I',cr,0,0x4e80d0);struct.pack_into('<I',cr,4,0x123);cr[8]=4;struct.pack_into('<I',cr,0x10,pen);struct.pack_into('<I',cr,0x58,b);put(canvas,cr);put(canvas+0x38,bytes(24))
   pr=bytearray(0x1c);struct.pack_into('<I',pr,0,0x4e2420);struct.pack_into('<IIII',pr,8,0x4e4dec,canvas,node,canvas+0x38);put(pen,pr)
   link.update(canvas_status='read',pen=f'0x{pen:08x}',shared_pen_record=f'0x{node:08x}',event_code='0x004e4dec',event_owner=f'0x{canvas:08x}',lock=f'0x{canvas+0x38:08x}',dc_handle='0x00000123',canvas_flags=4)
  else:link['reason']='Canvas has not been constructed; read-only capture cannot obtain it'
  links.append(link)
 put(0x59a9e4,struct.pack('<I',registry));h=bytearray(0x24);struct.pack_into('<II',h,0,0x4e2d1c,node);struct.pack_into('<H',h,0x20,16);put(registry,h);put(registry+8,bytes(24));nr=bytearray(32);struct.pack_into('<I',nr,4,1);put(node,nr);put(0x59a9a0,struct.pack('<I',0xabcdef))
 pe=(ROOT/'artifacts/ChemLab/_main.exe').read_bytes();nt=struct.unpack_from('<I',pe,60)[0];cnt=struct.unpack_from('<H',pe,nt+6)[0];off=nt+24+struct.unpack_from('<H',pe,nt+20)[0]
 for a,n,_hash in pinned_spans():
  for i in range(cnt):
   _,r,z,t=struct.unpack_from('<4I',pe,off+i*40+8)
   if r<=a-0x400000<r+z:put(a,pe[t+a-0x400000-r:t+a-0x400000-r+n]);break
 blobs=[dict(address=f'0x{a:08x}',bytes=n,role='Synthetic transport only',base64=base64.b64encode(raw).decode(),sha256=digest(raw)) for (a,n),raw in memory.items()]
 graph=dict(before=state,after=copy.deepcopy(state),bitmaps=links,registry=f'0x{registry:08x}',registry_record_size=16,registry_nodes=[f'0x{node:08x}'],blobs=blobs)
 prov=dict(reader_sha256=PS_SHA,reader_cs_sha256=CS_SHA,target_calls=False,target_writes=False,target_suspend=False,gdi_operations=False,gdi_flush=False,native_vcl_verified=False,rng_tls_status='unobserved',scope='Synthetic transport test only')
 return dict(format='chemlab-original-vcl-pen-graph-readonly-v1',image_sha256=IMAGE_SHA,process_id=9348,module_base='0x00400000',whole_graph_equal_two_passes=True,graph=graph,provenance=prov),prior

def change_blob(data,a,offset,value,fmt='<I'):
 b=next(b for b in data['graph']['blobs'] if address(b['address'])==a)
 raw=bytearray(base64.b64decode(b['base64']));struct.pack_into(fmt,raw,offset,value);b.update(base64=base64.b64encode(raw).decode(),sha256=digest(raw))

class PenCapture(unittest.TestCase):
 def test_full_graph_keeps_unknown_state_and_all_raw_bytes(self):
  data,prior=fixture();old=copy.deepcopy(data);report=validate(data,prior)
  self.assertEqual(data,old);self.assertEqual(report['available_canvas_links'],1);self.assertEqual(report['registry_node_count'],1)
  self.assertEqual(report['memory_blobs'],data['graph']['blobs']);self.assertFalse(report['native_vcl_verified']);self.assertFalse(report['target_handles_usable']);self.assertEqual(report['rng_tls_status'],'unobserved')
  self.assertGreater(report['prior_raw_bytes_compared'],400000)
 def test_missing_canvas_is_preserved_not_constructed(self):
  data,prior=fixture(False);report=validate(data,prior)
  self.assertEqual(report['available_canvas_links'],0);self.assertEqual(len(report['unavailable_canvas_links']),len(data['graph']['bitmaps']))
 def test_checkpoint_scope_and_provenance_rejected(self):
  for key,value in [('process_id',1),('whole_graph_equal_two_passes',False),('module_base','0x00500000'),('rng',{'low':1})]:
   d,p=fixture();d[key]=value
   with self.assertRaises(ValueError):validate(d,p)
  d,p=fixture();d['provenance']['native_vcl_verified']=True
  with self.assertRaises(ValueError):validate(d,p)
 def test_registry_cycle_omission_and_extra_node_rejected(self):
  d,p=fixture();change_blob(d,0x21000100,0,0x21000100)
  with self.assertRaises(ValueError):validate(d,p)
  for nodes in [[],['0x21000100','0x21000200']]:
   d,p=fixture();d['graph']['registry_nodes']=nodes
   with self.assertRaises(ValueError):validate(d,p)
 def test_rehashed_wrong_event_lock_and_shared_record_rejected(self):
  for offset,value in [(8,0x4e4e0c),(12,0x21000304),(16,0x12340000),(20,0)]:
   d,p=fixture();change_blob(d,0x21000200,offset,value)
   with self.assertRaises(ValueError):validate(d,p)
 def test_raw_overlap_and_prior_pool_changes_rejected(self):
  d,p=fixture();change_blob(d,EXPECTED_POINTERS[0]+0xfc,0,0x12340000)
  with self.assertRaises(ValueError):validate(d,p)
  d,p=fixture();pool=address(p['objects'][0]['solid_pointer']);change_blob(d,pool,0,42)
  with self.assertRaises(ValueError):validate(d,p)
 def test_rehashed_wrong_code_and_duplicate_blob_rejected(self):
  d,p=fixture();a=pinned_spans()[0][0];change_blob(d,a,0,0)
  with self.assertRaises(ValueError):validate(d,p)
  d,p=fixture();d['graph']['blobs'].append(copy.deepcopy(d['graph']['blobs'][0]))
  with self.assertRaises(ValueError):validate(d,p)
 def test_transport_members_sources_and_no_overwrite(self):
  d,_p=fixture()
  with tempfile.TemporaryDirectory() as tmp:
   path=Path(tmp)/'return.zip'
   def write(extra=False,wrong=False):
    with zipfile.ZipFile(path,'w') as z:
     z.writestr('CodexVclPenState.json',json.dumps(d));z.writestr('read_original_pen_graph.ps1',b'changed' if wrong else PS.read_bytes());z.writestr('original_dib_read_probe.cs',CS.read_bytes())
     if extra:z.writestr('../extra','x')
   write();data,files=read_archive(path,digest(path.read_bytes()));self.assertEqual(data,d);self.assertEqual(len(files),3)
   output=Path(tmp)/'imported';report=import_archive(path,digest(path.read_bytes()),output);self.assertFalse(report['native_vcl_verified'])
   with self.assertRaises(ValueError):import_archive(path,digest(path.read_bytes()),output)
   write(extra=True)
   with self.assertRaises(ValueError):read_archive(path,digest(path.read_bytes()))
   write(wrong=True)
   with self.assertRaises(ValueError):read_archive(path,digest(path.read_bytes()))
   write()
   with self.assertRaises(ValueError):read_archive(path,'0'*64)
if __name__=='__main__':unittest.main()
