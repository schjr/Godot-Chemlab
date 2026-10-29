"""Bind retained frame inputs to exact paused PID9348 capture; no defaults."""
import base64,hashlib,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
SOURCE='7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c'
CAPTURE='d290a1db6a5d2e268da8d9e688464649bae47c7c4fd82b5838448a033fa72995'
VALIDATION='ac8ff5ccc81c81bb3489214fc143800eccc2314bef141b55e5ee5db41c316132'
DIB='13774e051e92a19010ff937a7abf5d20dfe360b20fbd74782aa81ea2ee1ac0c7'
BASELINE='6b868d27c2e1ecf2af7d1d521823a97650b26457960f5db55edf29597fa1c0ea'
def sha(raw):return hashlib.sha256(raw).hexdigest()
def load(path,digest):
 raw=(ROOT/path).read_bytes();assert sha(raw)==digest,path;return json.loads(raw)
def main():
 capture=load('evidence/windows-runtime/particle-pool-results-2026-10-14/CodexParticleState.json',CAPTURE)
 validation=load('evidence/windows-runtime/particle-pool-results-2026-10-14/validation.json',VALIDATION)
 baseline=load('evidence/windows-runtime/vcl-pixel-results-2026-10-14/dib-material-state.json',BASELINE)
 assert capture['image_sha256']==SOURCE and capture['before']==capture['after']==validation['checkpoint']
 assert capture['before']['run']==2 and capture['before']['pause']==0 and capture['provenance']['rng_tls_status']=='unobserved'
 dib=load('evidence/windows-runtime/vcl-pixel-results-2026-10-14/original-dib-pixels.json',DIB)
 assert dib['run_before']==dib['run_after']==capture['before']
 vessels=[];pools=[];material_words={}
 for item,obs,prior in zip(capture['objects'],validation['objects'],baseline['snapshots'][0]['vessels']):
  raw=base64.b64decode(item['vessel']['base64']);assert len(raw)==0x4348 and sha(raw)==item['vessel']['sha256']
  u32=lambda at:struct.unpack_from('<I',raw,at)[0]
  i32=lambda at:struct.unpack_from('<i',raw,at)[0]
  f64=lambda at:struct.unpack_from('<d',raw,at)[0]
  assert u32(4)==int(prior['label']['pointer'],16)
  names=[s['text'] for s in prior['species']]
  assert i32(0x104)==len(names) and all(u32(0x108+i*4)==int(s['pointer'],16) for i,s in enumerate(prior['species']))
  image=next(b for b in dib['vessels'][item['native_index']]['bitmaps'] if b['vessel_field']=='0xfc')
  assert image['status']=='read' and image['bit_count']==32 and int(image['bitmap_pointer'],16)==u32(0xfc)
  pixels=base64.b64decode(image['visual_topdown_base64']);assert sha(pixels)==image['visual_topdown_sha256']
  material_words[str(item['native_index'])]=list(struct.unpack('<'+'I'*(len(pixels)//4),pixels))
  v={'label':prior['label']['text'],'type_id':i32(8),'position':[i32(0x10),i32(0x14)],'native_fields':{'0x18':str(i32(0x18))},'native_bitmap_width':image['width'],'native_bitmap_height':image['height'],'native_liquid_height':f64(0x30),'native_liquid_color':u32(0x3cd0),'contents':{name:f64(0x8d8+i*8) for i,name in enumerate(names)},'solid_3cd8':{name:f64(0x3cd8+i*8) for i,name in enumerate(names)},'solid_3ff8':{name:f64(0x3ff8+i*8) for i,name in enumerate(names)},'solid_4318':f64(0x4318),'gas_3cc0':f64(0x3cc0),'native_particle_3cc8':f64(0x3cc8),'capture_vessel_sha256':item['vessel']['sha256']}
  assert v['native_bitmap_width']>0 and v['native_bitmap_height']>0
  vessels.append(v);pool={}
  for name,size,count_at,records_at in [('solid',0x3468c,0x34684,4),('bubbles',0xfc20,0x5150,0x10)]:
   if name not in item:continue
   blob=item[name];body=base64.b64decode(blob['base64']);assert len(body)==size and sha(body)==blob['sha256']
   bindings={}
   if name=='solid':
    for image in item['solid_bitmaps']:
     field=image['vessel_field'];proof=obs['pools']['solid']['bitmaps'][field]
     assert image['status']=='read' and image['bit_count']==32 and proof['mismatched_current_rows']==[]
     pixels=base64.b64decode(image['visual_topdown_base64']);assert sha(pixels)==image['visual_topdown_sha256']
     bindings[field]={'source_sha256':SOURCE,'scope':'Actual PID9348 observed32-bit DIB and source-derived row addresses; no GDI drain attestation','original_pointer':int(image['bitmap_pointer'],16),'bitmap_format':32,'width':image['width'],'height':image['height'],'words':list(struct.unpack('<'+'I'*(len(pixels)//4),pixels)),'pixels_sha256':sha(pixels),'row_addresses':proof['current_dib_visual_row_addresses']}
   count=struct.unpack_from('<i',body,count_at)[0];rect_at=0x32d58 if name=='solid' else 0x515c
   rect=list(struct.unpack_from('<4i',body,rect_at))
   pool[name]={'count':count,'slots':[list(struct.unpack_from('<13I',body,records_at+i*52)) for i in range(count)],'rect':rect,'width':abs(rect[2]-rect[0]),'height':abs(rect[3]-rect[1]),'native_raw_object':{'source_sha256':SOURCE,'scope':'Actual paused PID9348 checkpoint; RNG/VCL attestation unavailable','original_address':int(blob['address'],16),'byte_size':size,'raw_hex':body.hex(),'sha256':blob['sha256'],'bitmap_bindings':bindings}}
  pools.append(pool)
 reagent_path=ROOT/'godot/data/reagents.json'
 result={'format':'actual-paused-particle-checkpoint-regression-v1','source_sha256':SOURCE,'capture_sha256':CAPTURE,'validation_sha256':VALIDATION,'baseline_sha256':BASELINE,'main_dib_sha256':DIB,'catalog_sha256':sha(reagent_path.read_bytes()),'scope':'Bounded original frame execution on real raw checkpoint. No fabricated TLS/GDI/pause substitution; not production profile.','context':{'run_flag':2,'pause_flag':0,'native_material_words':material_words},'rng':{},'vessels':vessels,'connectors':[],'scene':{'pools':pools},'input_claims':{'rng_tls_status':'unobserved','native_vcl_verified':False,'gdi_provider_supplied':False}}
 path=ROOT/'godot/tests/fixtures/actual_paused_particle_checkpoint.json';path.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({'fixture':str(path),'vessels':len(vessels),'observed_pools':sum(bool(p) for p in pools),'bytes':path.stat().st_size}))
if __name__=='__main__':main()
