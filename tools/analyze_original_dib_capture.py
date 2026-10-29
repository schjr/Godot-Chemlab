"""Validate returned read-only bitmap evidence and prepare a bounded comparison.

No pixel emulation or VCL attestation. Original raw files remain unchanged.
"""
import argparse
import base64
import json
from pathlib import Path
import struct
import zipfile

from import_current_gdi_result import decode, digest, require
from analyze_original_runtime_captures import inspect, ARRAYS

ROOT = Path(__file__).resolve().parents[1]
IMAGE_SHA = '7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c'
PACKAGE_SHA = 'b6e0167f7ff66c41720e47f2a03ac9e898513e5bd1aed46116f4e08b7f6a492f'
BASELINE = ROOT / 'evidence/windows-runtime/precision-and-graphics-2026-10-14/full80-naoh.json'
BASELINE_SHA = '9f6793c5f8729e0dc99ae35de1446230c07f45c7c6c7e1b35c154c3b99b99887'
AMENDED_READER_SHA = '4a4d476366c523d8efe96d85c7d864e5dba1f923b8eafe7f53e281a86a00e138'

def payload(record, field):
    raw = base64.b64decode(record[field + '_base64'], validate=True)
    require(digest(raw) == record[field + '_sha256'], 'Bitmap pixel hash differs')
    return raw

def bitmap(record):
    require(record['status'] == 'read', 'Existing DIB is unavailable; comparison stays unresolved')
    width, height, bpp = record['width'], record['height'], record['bit_count']
    require(type(width) is int and type(height) is int and 0 < width <= 1024 and 0 < height <= 1024, 'DIB dimensions invalid')
    require(bpp in (24, 32) and record['planes'] == 1 and record['compression'] == 0 and record['header_size'] == 40, 'DIB format differs')
    require(record['metadata_and_pixels_stable_during_read'] is True and record['gdi_flush_in_target'] is False, 'Read-only DIB scope differs')
    signed = record['signed_height']
    stride = ((width*bpp + 31)//32)*4
    require(abs(signed) == height and record['row_stride'] == stride and record['storage_bytes'] == stride*height, 'DIB stride differs')
    obj = bytes.fromhex(record['bitmap_object_hex'])
    metadata = bytes.fromhex(record['shared_image_hex'])
    require(len(obj) == 0x30 and len(metadata) == 0x74 and struct.unpack_from('<I', obj)[0] == 0x4e2af4, 'Original bitmap class differs')
    require(struct.unpack_from('<I', obj, 0x20)[0] == int(record['shared_pointer'], 16), 'Shared DIB identity differs')
    require(struct.unpack_from('<I', metadata, 0x2c)[0] == int(record['bits_pointer'], 16), 'Existing bits pointer differs')
    require(struct.unpack_from('<IiiHHI', metadata, 0x30) == (40,width,signed,1,bpp,0), 'Original DIB header differs')
    require(struct.unpack_from('<iiiHH', metadata, 0x1c) == (width,height,stride,1,bpp), 'Original BITMAP metadata differs')
    raw = payload(record, 'raw_storage')
    visual = payload(record, 'visual_topdown')
    require(len(raw) == len(visual) == stride*height, 'DIB backing size differs')
    rows = [raw[y*stride:(y+1)*stride] for y in range(height)]
    require(b''.join(rows[::-1] if signed > 0 else rows) == visual, 'DIB row orientation differs')
    # Keep24-bit input explicit. A32-bit conversion requires native GDI evidence.
    return dict(width=width,height=height,bitmap_format=bpp,row_stride=stride,
                topdown_base64=base64.b64encode(visual).decode(),pixel_sha256=digest(visual))

def validate(directory, package):
    package_raw = package.read_bytes()
    require(digest(package_raw) == PACKAGE_SHA, 'Reviewed transfer archive identity differs')
    with zipfile.ZipFile(package) as archive:
        expected_manifest = archive.read('manifest.json')
        manifest = decode(expected_manifest)
        for entry in manifest['files']:
            content = archive.read(entry['path'])
            require(len(content) == entry['bytes'] and digest(content) == entry['sha256'], 'Reviewed package member differs')
        corpus_raw = archive.read('current-material-gdi-cases.json')
    returned_manifest = decode((directory/'input-manifest.json').read_bytes())
    amended_manifest = decode(expected_manifest)
    for entry in amended_manifest['files']:
        if entry['path'] == 'read_original_dib_pixels.ps1':
            entry['sha256'] = AMENDED_READER_SHA
            entry['bytes'] = 8405
    require(returned_manifest == manifest or returned_manifest == amended_manifest, 'Windows input manifest differs from both reviewed reader revisions')
    outputs = decode((directory/'result-manifest.json').read_bytes())
    expected_names = {'original-dib-pixels.json','dib-material-state.json','current-material-gdi-result.json','input-manifest.json'}
    require(len(outputs['files']) == 4 and {r['path'] for r in outputs['files']} == expected_names, 'Returned member identity differs')
    require(outputs['process_id'] == 9348 and outputs['no_policy_or_privilege_change'] is True, 'Capture process/scope differs')
    for entry in outputs['files']:
        raw = (directory/entry['path']).read_bytes()
        require(len(raw) == entry['bytes'] and digest(raw) == entry['sha256'], 'Returned file hash/size differs')
        decode(raw)  # Reject duplicate keys/nonfinite JSON before other validators.
    dib = decode((directory/'original-dib-pixels.json').read_bytes())
    require(dib['format'] == 'chemlab-original-existing-dib-readonly-v1' and dib['native_vcl_verified'] is False, 'DIB evidence format differs')
    provenance = dib['provenance']
    require(provenance['process_id'] == 9348 and provenance['image_sha256'] == IMAGE_SHA and provenance['runtime_module_base'] == '0x00400000' and provenance['process_pointer_bits'] == 32, 'Original DIB process identity differs')
    hashes = {r['path']: r['sha256'] for r in returned_manifest['files']}
    require(provenance['reader_cs_sha256'] == hashes['original_dib_read_probe.cs'] and provenance['reader_ps_sha256'] == hashes['read_original_dib_pixels.ps1'], 'Reader source identity differs')
    require(provenance['process_access'] == 'PROCESS_VM_READ | PROCESS_QUERY_LIMITED_INFORMATION', 'Reader access differs')
    for key in ('target_calls','target_writes','target_pause_or_suspend','gdi_flush_in_target'):
        require(provenance[key] is False, 'Reader expanded target access')
    require(dib['vessel_identity_stable'] is True and dib['run_before'] == dib['run_after'], 'DIB run state changed')
    run = dib['run_before']
    require(not (run['run'] == 1 and run['pause'] == 0), 'DIB captured an advancing simulation')
    state, state_report = inspect(directory/'dib-material-state.json')
    require(state['provenance']['process_id'] == 9348 and len(state['snapshots']) == 1, 'Scalar process identity differs')
    baseline_raw = BASELINE.read_bytes()
    require(digest(baseline_raw) == BASELINE_SHA, 'Original material input capture differs')
    baseline = decode(baseline_raw)['snapshots'][0]
    current = state['snapshots'][0]
    elapsed = baseline['run_state_before']['elapsed_005636cc']['ieee754_le_hex']
    for observed in (current['run_state_before'], current['run_state_after']):
        require(observed['elapsed_005636cc']['ieee754_le_hex'] == elapsed, 'Material input timer history changed')
        require(observed['running_global_0057a6f8'] == run['run'] and observed['pause_field_0x5bc'] == run['pause'], 'DIB/scalar run state differs')
    require(run['elapsed_hex'] == elapsed, 'DIB/material timer history differs')
    corpus = decode(corpus_raw)
    material = decode((directory/'current-material-gdi-result.json').read_bytes())
    require(material['format'] == 'chemlab-current-material-gdi-result-v1' and material['native_vcl_verified'] is False, 'Material evidence format differs')
    require(material['original_binary_sha256'] == IMAGE_SHA and material['corpus_sha256'] == digest(corpus_raw) and material['gdi_source_sha256'] == hashes['original_gdi_host.cs'] and material['runner_sha256'] == hashes['run_current_material_probes.ps1'], 'Material source identity differs')
    require(material['input_capture'] == corpus['input_capture'] and material['source_plan'] == corpus['source_plan'] and material['scope'] == corpus['scope'], 'Material reference scope differs')
    require(len(dib['vessels']) == len(current['vessels']) == len(baseline['vessels']) == len(material['cases']) == 6, 'Six-vessel comparison identity differs')
    inputs = []
    for index, (old, now, image, case, reference) in enumerate(zip(baseline['vessels'], current['vessels'], dib['vessels'], corpus['cases'], material['cases'])):
        require(old['native_index'] == now['native_index'] == image['native_index'] == case['native_index'] == reference['native_index'] == index, 'Vessel order differs')
        require(old['pointer'] == now['pointer'] == image['pointer'] == case['observed_pointer'] == reference['observed_pointer'], 'Vessel pointer differs')
        require(old['species'] == now['species'] and old['type_id'] == now['type_id'] == image['native_type_field_0x8'], 'Material species/type identity differs')
        for field in ARRAYS:
            require(old['arrays'][field]['raw_hex'] == now['arrays'][field]['raw_hex'], 'Material array changed: '+field)
        for field in old['scalars']:
            require(old['scalars'][field]['ieee754_le_hex'] == now['scalars'][field]['ieee754_le_hex'], 'Previously observed material scalar changed')
        require('0x3cc0' in now['scalars'], 'Gas delta remains unobserved')
        require(reference['operations'] == case['operations'] and reference['stages'] == case['stages'] and reference['id'] == case['id'], 'Material operations differ')
        require(reference['width'] == case['width'] and reference['height'] == case['height'] and reference['bitmap_format'] == reference['returned_pixel_format'] == 32 and reference['stretch_mode'] == case['initial_stretch_mode'], 'Material geometry/DC state differs')
        raw = base64.b64decode(reference['bgra'], validate=True)
        require(len(raw) == case['width']*case['height']*4 and digest(raw) == reference['pixel_sha256'], 'Material pixel hash/size differs')
        images = {r['vessel_field']: r for r in image['bitmaps']}
        require(len(images) == 3 and set(images) == {'0xfc','0xf8','0xf4'}, 'Original bitmap fields differ')
        native = {field: bitmap(record) for field,record in images.items()}
        require(all(r['width'] == case['width'] and r['height'] == case['height'] for r in native.values()), 'Source bitmap dimensions differ')
        inputs.append(dict(native_index=index,type_id=now['type_id'],native_type_parameter=now['native_type_parameter'],width=case['width'],height=case['height'],material_bgra=reference['bgra'],bitmaps=native,gas_delta_hex=now['scalars']['0x3cc0']['ieee754_le_hex']))
    return dict(format='chemlab-original-dib-comparison-input-v1',native_vcl_verified=False,
                scope='Six observed source bitmaps and uncomposed native GDI materials. Retained particle/overlay stages remain excluded; any candidate is a bounded comparison hypothesis.',
                package_sha256=PACKAGE_SHA,baseline_sha256=BASELINE_SHA,
                reader_ps_sha256=hashes['read_original_dib_pixels.ps1'],
                returned_input_manifest_sha256=digest((directory/'input-manifest.json').read_bytes()),
                state_report=state_report,inputs=inputs)

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('directory', type=Path)
    parser.add_argument('--package', type=Path, default=ROOT/'build/windows-reference/vcl-pixel-probes.zip')
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    require(not args.output.exists(), 'Output exists; preserve comparison history')
    result = validate(args.directory, args.package)
    raw = (json.dumps(result,ensure_ascii=False,separators=(',',':'))+'\n').encode()
    with args.output.open('xb') as stream:
        stream.write(raw)
    print(json.dumps(dict(output=str(args.output.resolve()),sha256=digest(raw),vessels=len(result['inputs']),native_vcl_verified=False)))

if __name__ == '__main__':
    main()
