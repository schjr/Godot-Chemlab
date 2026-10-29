"""Replay actual native material geometry/color instructions from observed slots.

VCL primitive calls are recorded boundaries. No particle/pixel approximation.
"""
import hashlib
import json
import struct
from pathlib import Path
from original_visual_oracle import SolidVisualOracle
from original_x86_oracle import EXPECTED, ROOT
from original_actions_oracle import bits

CAPTURE = ROOT / 'evidence/windows-runtime/precision-and-graphics-2026-10-14/full80-naoh.json'

def sha(path): return hashlib.sha256(path.read_bytes()).hexdigest()

def main():
    observed=json.loads(CAPTURE.read_text(encoding='utf-8-sig'))
    assert observed['provenance']['image_sha256']==EXPECTED
    snapshot=observed['snapshots'][0]
    assert snapshot['apparatus_identity_stable_during_read'] and len(snapshot['vessels'])==6
    assert snapshot['run_state_before']['simulation_advancing'] is False and snapshot['run_state_after']['simulation_advancing'] is False
    docs=ROOT/'godot/data/examples.json'
    doc=next(d for d in json.loads(docs.read_text()) if d['name']=='氢氧化铜与氢氧化铁')
    sprites=ROOT/'godot/data/sprites.json'; sprite_data=json.loads(sprites.read_text())
    oracle=SolidVisualOracle()
    oracle.u32(0x57a748,oracle.species['H2O(液体)']['color_integer'])
    cases=[]
    for index,(record,apparatus,kind) in enumerate(zip(snapshot['vessels'],doc['apparatus'],['sb200','xkp','jtdg_2','sb200','xkp','jtdg_2'])):
        assert record['status']=='read' and record['species_identity_stable_during_read']
        assert record['native_index']==index and record['label']['text']==apparatus['name']
        assert record['type_id']==apparatus['type_id'] and str(record['native_type_parameter'])==apparatus['native_fields']['0x0c']
        assert apparatus['native_fields']['0x18']=='0'
        species=[r['text'] for r in record['species']]
        moles_raw=bytes.fromhex(record['arrays']['moles_0x8d8']['raw_hex'])
        assert len(moles_raw)==800 and len(species)==record['species_count_0x104']
        contents={name:struct.unpack_from('<d',moles_raw,slot*8)[0] for slot,name in enumerate(species)}
        capacity=float(apparatus['native_fields']['0x28'])
        vessel_index=oracle.add_vessel(contents,capacity=capacity)
        pointer=oracle.vessels[vessel_index]
        oracle.u32(pointer+8,record['type_id']);oracle.u32(pointer+0xc,record['native_type_parameter'])
        input_arrays={}
        for field,offset in [('moles_0x8d8',0x8d8),('mass_0x298',0x298),('volume_0x5b8',0x5b8),('solid_0x3cd8',0x3cd8),('solid_0x3ff8',0x3ff8)]:
            raw=bytes.fromhex(record['arrays'][field]['raw_hex']);assert len(raw)==800
            oracle.uc.mem_write(pointer+offset,raw);input_arrays[field]=raw.hex()
        for field in ['solid_0x3cd8','solid_0x3ff8']:
            assert all(value==0 for value in struct.unpack('<100d',bytes.fromhex(input_arrays[field]))[:len(species)])
        for field in ['0x4318','0x3cc8','0x4338']:
            raw=bytes.fromhex(record['scalars'][field]['ieee754_le_hex']);assert struct.unpack('<d',raw)[0]==0
            oracle.uc.mem_write(pointer+int(field,16),raw)
        source=ROOT/sprite_data[kind]['source'];raw=source.read_bytes()
        width,height=struct.unpack_from('<ii',raw,18);height=abs(height)
        assert [width,height]==sprite_data[kind]['size']
        bitmap=oracle.bitmap(width,height);oracle.u32(pointer+0xfc,bitmap)
        oracle.f64(pointer+0x30,0)
        oracle.operations.clear();oracle.boundary_calls.clear()
        oracle.pen_color=oracle.brush_color=0xffffff;oracle.brush_style=0
        stages=[dict(stage='clear_white',native_function='0040A4B8',operations=[dict(op='rectangle',left=0,top=0,right=width,bottom=height,pen_color=0xffffff,brush_color=0xffffff,brush_style=0)])]
        for label,entry in [('liquid',0x471650),('gas',0x47692c)]:
            before=len(oracle.operations);oracle.call(entry,struct.pack('<II',bitmap,vessel_index))
            stages.append(dict(stage=label,native_function=f'{entry:08X}',operations=oracle.operations[before:].copy()))
        height_now=oracle.f64(pointer+0x30)
        stages.append(dict(stage='suspended_particles',operations=[],status='not_replayed',reason='Retained particle layers not captured; pool gas delta+3CC0=0 is an explicit unobserved hypothesis, not a captured field'))
        before=len(oracle.operations)
        if height_now>1:oracle.call(0x473e6c,struct.pack('<II',bitmap,vessel_index))
        stages.append(dict(stage='surface_outline',native_function='00473E6C',operations=oracle.operations[before:].copy(),enabled=height_now>1))
        before=len(oracle.operations);oracle.call(0x4744dc,struct.pack('<II',bitmap,vessel_index))
        settled=oracle.operations[before:].copy()
        assert not settled, 'Observed zero settled-solid rows unexpectedly draw; do not omit this stage'
        stages.append(dict(stage='settled_solid',native_function='004744DC',operations=settled,status='native_zero_no_operations'))
        ops=[op for stage in stages for op in stage['operations']]
        assert all(op['op']=='rectangle' for op in ops)
        cases.append(dict(id=f'current-vessel-{index}',native_index=index,observed_pointer=record['pointer'],label=record['label']['text'],type_id=record['type_id'],native_type_parameter=record['native_type_parameter'],width=width,height=height,bitmap_format=32,initial_stretch_mode=1,operations=ops,stages=stages,inputs=dict(ordered_species=species,arrays=input_arrays,capacity_bits=bits(capacity),orientation=0,settled_scalar_bits=record['scalars']['0x4318']['ieee754_le_hex'],pool_gas_delta=dict(offset='0x3cc0',status='unobserved_explicit_zero_hypothesis',hypothesis_bits='0000000000000000')),outputs=dict(liquid_height_bits=bits(height_now),liquid_volume_bits=bits(oracle.f64(pointer+0x4320)),liquid_color_integer=oracle.u32(pointer+0x3cd0)),bitmap_asset=dict(path=str(source.relative_to(ROOT)),sha256=sha(source)),native_boundaries=sorted(set(oracle.boundary_calls))))
    output=ROOT/'evidence/original_logic/current-material-gdi-cases.json'
    result=dict(format='chemlab-current-material-gdi-cases-v1',original_binary_sha256=EXPECTED,input_capture=dict(path=str(CAPTURE.relative_to(ROOT)),sha256=sha(CAPTURE),process_id=observed['provenance']['process_id'],snapshot_label=snapshot['label']),source_inputs=[dict(path=str(p.relative_to(ROOT)),sha256=sha(p)) for p in [docs,sprites,ROOT/'godot/data/reagents.json']],source_plan='0040A4B8: clear,471650 liquid,47692C gas,particles(unresolved),473E6C surface,4744DC settled(empty),overlays/FC+F8+F4 composition(excluded)',scope='Uncomposed native32 material rectangle references only. No retained particles, overlays, apparatus SRCPAINT, fill blend or original VCL profile attestation.',cases=cases)
    output.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n')
    print(json.dumps(dict(output=str(output),sha256=sha(output),cases=len(cases))))

if __name__=='__main__':main()
