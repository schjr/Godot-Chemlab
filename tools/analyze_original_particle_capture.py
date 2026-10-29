"""Validate a returned, read-only particle checkpoint without inventing state.

This imports evidence, not a production startup profile. Absolute pointers and
uninterpreted bytes stay intact; missing TLS random state remains unobserved.
"""
import argparse
import base64
from pathlib import Path
import struct
import zipfile
import json

from analyze_original_dib_capture import bitmap
from import_current_gdi_result import decode, digest, require

ROOT = Path(__file__).resolve().parents[1]
IMAGE_SHA = '7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c'
READER_SHA = 'b29746226740eee001fe670b022d2c525ac0500bd160219e96358003406b0f2d'
CS_SHA = 'f366f56e3a842384cb26395e14ce14361aab0bfb70f34121d3ae80331e263839'
BASELINE = ROOT / 'evidence/windows-runtime/vcl-pixel-results-2026-10-14/dib-material-state.json'
BASELINE_SHA = '6b868d27c2e1ecf2af7d1d521823a97650b26457960f5db55edf29597fa1c0ea'
EXPECTED_POINTERS = (0x0d960000, 0x0d964380, 0x0d968700, 0x0d96ca80, 0x0d970e00, 0x0d97c000)
ARRAY_OFFSETS = {'volume_0x5b8': 0x5b8, 'solid_0x3cd8': 0x3cd8,
                 'solid_0x3ff8': 0x3ff8, 'moles_0x8d8': 0x8d8, 'mass_0x298': 0x298}


def address(value):
    require(isinstance(value, str) and len(value) == 10 and value.startswith('0x'), 'Pointer encoding differs')
    number = int(value, 16)
    require(0 <= number <= 0xffffffff and value == f'0x{number:08x}', 'Pointer is not a canonical DWORD')
    return number


def blob(record, size, pointer):
    require(type(record['bytes']) is int and record['bytes'] == size, 'Object allocation length differs')
    require(address(record['address']) == pointer and pointer != 0, 'Object pointer differs')
    raw = base64.b64decode(record['base64'], validate=True)
    require(len(raw) == size and digest(raw) == record['sha256'], 'Object bytes or digest differ')
    return raw


def scanline_observation(pool_raw, record, cache_offset):
    """Describe current DIB addresses, without resolving stale cache targets."""
    image = bitmap(record)
    height, stride = record['height'], record['row_stride']
    require(height <= 800, 'Solid bitmap exceeds its source scanline-table allocation')
    bits = address(record['bits_pointer'])
    rows = [bits + stride * (height - 1 - y if record['signed_height'] > 0 else y)
            for y in range(height)]
    require(all(0 < value <= 0xffffffff - stride for value in rows), 'DIB row address overflow')
    cached = list(struct.unpack_from('<800I', pool_raw, cache_offset))
    result = dict(bitmap=image, current_dib_visual_row_addresses=rows,
                  cache_offset=f'0x{cache_offset:x}', cache_sha256=digest(pool_raw[cache_offset:cache_offset + 3200]),
                  cached_row_addresses=cached[:height],
                  mismatched_current_rows=[y for y in range(height) if cached[y] != rows[y]],
                  status='observed_current_dib_addresses', bitmap_format=record['bit_count'],
                  native_vcl_verified=False, gdi_flush_in_target=False)
    # Unknown/stale cache targets are never assigned these current pixels.
    # This metadata does not attest a later GetScanLine conversion or GDI drain.
    if record['bit_count'] == 32:
        visual = base64.b64decode(image['topdown_base64'], validate=True)
        result['current_dib_words'] = list(struct.unpack('<' + str(image['width'] * height) + 'I', visual))
    return result


def read_archive(path, expected_sha):
    raw = path.read_bytes()
    require(digest(raw) == expected_sha, 'Returned ZIP identity differs')
    with zipfile.ZipFile(path) as archive:
        infos = archive.infolist()
        require(len(infos) == 2 and {info.filename for info in infos} ==
                {'CodexParticleState.json', 'read_original_particle_objects.ps1'}, 'Archive members differ')
        require(all(not info.is_dir() and info.file_size <= 4_000_000 for info in infos), 'Archive member exceeds capture bound')
        reader = archive.read('read_original_particle_objects.ps1')
        require(len(reader) == 8148 and digest(reader) == READER_SHA, 'Executed reader source differs')
        capture = archive.read('CodexParticleState.json')
    return decode(capture), capture, reader


def validate(data, baseline):
    require(data['format'] == 'chemlab-original-particle-objects-readonly-v1', 'Particle capture format differs')
    require(data['image_sha256'] == IMAGE_SHA and data['process_id'] == 9348 and
            data['module_base'] == '0x00400000', 'Original process identity differs')
    provenance = data['provenance']
    require(provenance['reader_sha256'] == READER_SHA and provenance['reader_cs_sha256'] == CS_SHA, 'Reader identity differs')
    for field in ('target_calls', 'target_writes', 'target_suspend', 'gdi_flush', 'native_vcl_verified'):
        require(provenance[field] is False, 'Capture access or verification scope differs')
    require(provenance['rng_tls_status'] == 'unobserved' and 'rng' not in data, 'Unobserved TLS state was replaced')
    require(data['before'] == data['after'], 'Run state changed during capture')
    run = data['before']
    require(run['run'] == 2 and run['pause'] == 0 and run['elapsed_hex'] == '6cbc749318445240', 'Reviewed checkpoint differs')
    require(address(run['main_form']) != 0, 'Main form identity is missing')
    require(baseline['provenance']['image_sha256'] == IMAGE_SHA and baseline['provenance']['process_id'] == 9348,
            'Material baseline identity differs')
    require(len(baseline['snapshots']) == 1, 'Material baseline snapshot differs')
    prior = baseline['snapshots'][0]
    for state in (prior['run_state_before'], prior['run_state_after']):
        require(state['running_global_0057a6f8'] == run['run'] and state['pause_field_0x5bc'] == run['pause'] and
                state['elapsed_005636cc']['ieee754_le_hex'] == run['elapsed_hex'], 'Material checkpoint differs')
    require(len(data['objects']) == len(prior['vessels']) == 6, 'Six-vessel identity differs')
    objects = []
    for index, (row, old, pointer) in enumerate(zip(data['objects'], prior['vessels'], EXPECTED_POINTERS)):
        require(row['native_index'] == old['native_index'] == index and address(old['pointer']) == pointer, 'Vessel order differs')
        raw = blob(row['vessel'], 0x4348, pointer)
        type_id = struct.unpack_from('<i', raw, 8)[0]
        require(type_id == row['type_id'] == old['type_id'], 'Vessel class differs')
        require(struct.unpack_from('<i', raw, 0x104)[0] == len(old['species']), 'Species count changed')
        for name, offset in ARRAY_OFFSETS.items():
            require(raw[offset:offset + 800].hex() == old['arrays'][name]['raw_hex'], 'Material cells changed: ' + name)
        for field, scalar in old['scalars'].items():
            offset = int(field, 16)
            require(raw[offset:offset + 8].hex() == scalar['ieee754_le_hex'], 'Material scalar changed: ' + field)
        item = dict(native_index=index, type_id=type_id, vessel_pointer=row['vessel']['address'],
                    vessel_sha256=row['vessel']['sha256'], native_position=list(struct.unpack_from('<ii', raw, 0x10)),
                    native_orientation=struct.unpack_from('<i', raw, 0x18)[0],
                    solid_pointer=row['solid_pointer'], bubble_pointer=row['bubble_pointer'], pools={})
        for name, size, field in (('solid', 0x3468c, 'solid_pointer'), ('bubbles', 0xfc20, 'bubble_pointer')):
            pool_pointer = address(row[field])
            eligible = 100 < type_id < 200 and pool_pointer != 0
            require((name in row) == eligible, 'Pool read exceeds source constructor scope or is missing')
            if not eligible:
                item['pools'][name] = dict(status='not_dereferenced', reason='No source-used allocation for this type or pointer')
                continue
            pool_raw = blob(row[name], size, pool_pointer)
            # Preserve every byte; counts here are observations, not constructors.
            pool_info = dict(status='observed', address=row[name]['address'], bytes=size,
                             sha256=row[name]['sha256'], count=struct.unpack_from('<i', pool_raw, 0x34684 if name == 'solid' else 0x5150)[0])
            if name == 'solid':
                records = row.get('solid_bitmaps', [])
                require(len(records) == 2 and {r['vessel_field'] for r in records} == {'0x34678', '0x3467c'}, 'Solid bitmap fields differ')
                images = {}
                for record in records:
                    offset = int(record['vessel_field'], 16)
                    require(address(record['bitmap_pointer']) == struct.unpack_from('<I', pool_raw, offset)[0], 'Solid bitmap pointer differs')
                    if record['status'] == 'read':
                        images[record['vessel_field']] = scanline_observation(pool_raw, record, 0x32d68 if offset == 0x34678 else 0x339e8)
                    else:
                        require(record['status'] == 'unavailable' and isinstance(record.get('reason'), str), 'Unavailable bitmap reason missing')
                        images[record['vessel_field']] = dict(status='unavailable', reason=record['reason'])
                pool_info['bitmaps'] = images
            item['pools'][name] = pool_info
        require(('solid_bitmaps' in row) == ('solid' in row), 'Unexpected solid bitmap capture')
        objects.append(item)
    globals_raw = {}
    for name, size in (('crt_timezone', 4), ('crt_daylight', 4), ('stored_fpu_policy', 2)):
        raw = bytes.fromhex(data['globals'][name])
        require(len(raw) == size, 'Global byte length differs')
        globals_raw[name] = dict(raw_hex=raw.hex(), value=struct.unpack('<h' if size == 2 else '<i', raw)[0])
    return dict(format='chemlab-particle-capture-validation-v1', image_sha256=IMAGE_SHA,
                native_vcl_verified=False, production_startup_profile_verified=False,
                runtime_canvas_coordinates_verified=True, rng_tls_status='unobserved',
                scope='One paused observed checkpoint. Absolute pointers and all object bytes are retained; no pointer relocation, missing RNG, GDI drain or full VCL history is inferred.',
                checkpoint=run, globals=globals_raw, unchanged_material_cells=3000, objects=objects)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('archive', type=Path)
    parser.add_argument('--sha256', required=True)
    parser.add_argument('--output-directory', type=Path, required=True)
    args = parser.parse_args()
    data, capture, reader = read_archive(args.archive, args.sha256)
    baseline_raw = BASELINE.read_bytes()
    require(digest(baseline_raw) == BASELINE_SHA, 'Material baseline file differs')
    report = validate(data, decode(baseline_raw))
    report['archive_sha256'] = args.sha256
    report['capture_sha256'] = digest(capture)
    report['baseline_sha256'] = BASELINE_SHA
    require(not args.output_directory.exists(), 'Output directory exists; preserve evidence history')
    args.output_directory.mkdir(parents=True)
    (args.output_directory / 'CodexParticleState.json').write_bytes(capture)
    (args.output_directory / 'read_original_particle_objects.ps1').write_bytes(reader)
    (args.output_directory / 'validation.json').write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(dict(output=str(args.output_directory.resolve()), captured_objects=6,
                          material_cells=3000, rng_tls_status='unobserved', native_vcl_verified=False)))


if __name__ == '__main__':
    main()
