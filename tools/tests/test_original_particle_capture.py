"""Synthetic transport rejection tests; no original particle-state attestation."""
import base64
import copy
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest
import zipfile

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from analyze_original_particle_capture import (BASELINE, CS_SHA, EXPECTED_POINTERS,
                                             IMAGE_SHA, READER_SHA, ARRAY_OFFSETS,
                                             read_archive, scanline_observation, validate)
from import_current_gdi_result import decode, digest
from tools.tests.test_original_dib_analysis import fixture as bitmap_fixture


def raw_record(raw, pointer):
    return dict(bytes=len(raw), address=f'0x{pointer:08x}',
                base64=base64.b64encode(raw).decode(), sha256=digest(raw))


def fixture():
    baseline = decode(BASELINE.read_bytes())
    rows = []
    for index, old in enumerate(baseline['snapshots'][0]['vessels']):
        raw = bytearray(0x4348)
        struct.pack_into('<i', raw, 8, old['type_id'])
        struct.pack_into('<ii', raw, 0x10, 179 + index, 222)
        struct.pack_into('<i', raw, 0x104, len(old['species']))
        for name, offset in ARRAY_OFFSETS.items():
            raw[offset:offset + 800] = bytes.fromhex(old['arrays'][name]['raw_hex'])
        for field, scalar in old['scalars'].items():
            offset = int(field, 16)
            raw[offset:offset + 8] = bytes.fromhex(scalar['ieee754_le_hex'])
        row = dict(native_index=index, type_id=old['type_id'],
                   vessel=raw_record(raw, EXPECTED_POINTERS[index]),
                   solid_pointer='0x00000000', bubble_pointer='0x00000000')
        if 100 < old['type_id'] < 200:
            for name, size, pointer in (('solid', 0x3468c, 0x20000000 + index * 0x100000),
                                        ('bubbles', 0xfc20, 0x30000000 + index * 0x100000)):
                row[name] = raw_record(bytes(size), pointer)
                row['solid_pointer' if name == 'solid' else 'bubble_pointer'] = f'0x{pointer:08x}'
            row['solid_bitmaps'] = [dict(vessel_field=field, bitmap_pointer='0x00000000',
                                        status='unavailable', reason='Synthetic null bitmap')
                                    for field in ('0x34678', '0x3467c')]
        rows.append(row)
    state = dict(run=2, pause=0, elapsed_hex='6cbc749318445240', main_form='0x12340000')
    data = dict(format='chemlab-original-particle-objects-readonly-v1', image_sha256=IMAGE_SHA,
                process_id=9348, module_base='0x00400000', before=state, after=copy.deepcopy(state), objects=rows,
                globals=dict(crt_timezone='00000000', crt_daylight='00000000', stored_fpu_policy='3413'),
                provenance=dict(reader_sha256=READER_SHA, reader_cs_sha256=CS_SHA, target_calls=False,
                                target_writes=False, target_suspend=False, gdi_flush=False,
                                rng_tls_status='unobserved', native_vcl_verified=False))
    return data, baseline


class ParticleCaptureTransport(unittest.TestCase):
    def test_unknown_rng_and_unavailable_bitmaps_remain_explicit(self):
        data, baseline = fixture()
        original = copy.deepcopy(data)
        report = validate(data, baseline)
        self.assertEqual(data, original)
        self.assertEqual(report['unchanged_material_cells'], 3000)
        self.assertEqual(report['rng_tls_status'], 'unobserved')
        self.assertFalse(report['production_startup_profile_verified'])
        self.assertFalse(report['native_vcl_verified'])
        self.assertEqual(report['objects'][0]['native_position'], [179, 222])
        self.assertEqual(report['objects'][0]['pools']['solid']['bitmaps']['0x34678']['status'], 'unavailable')

    def test_changed_or_invented_checkpoint_rejected(self):
        for field, value in (('process_id', 9999), ('rng', {'low': 0, 'high': 1}),
                              ('module_base', '0x00500000')):
            data, baseline = fixture(); data[field] = value
            with self.assertRaises(ValueError, msg=field): validate(data, baseline)
        data, baseline = fixture(); data['after']['elapsed_hex'] = '0' * 16
        with self.assertRaises(ValueError): validate(data, baseline)
        data, baseline = fixture(); data['provenance']['target_writes'] = True
        with self.assertRaises(ValueError): validate(data, baseline)

    def test_corruption_and_rehashed_material_changes_rejected(self):
        data, baseline = fixture(); data['objects'][0]['solid']['sha256'] = '0' * 64
        with self.assertRaises(ValueError): validate(data, baseline)
        data, baseline = fixture()
        row = data['objects'][0]
        raw = bytearray(base64.b64decode(row['vessel']['base64'])); raw[0x8d8] ^= 1
        row['vessel'] = raw_record(raw, EXPECTED_POINTERS[0])
        with self.assertRaisesRegex(ValueError, 'Material cells changed'): validate(data, baseline)
        data, baseline = fixture(); data['objects'][0]['solid_pointer'] = '0x20000001'
        with self.assertRaises(ValueError): validate(data, baseline)

    def test_archive_path_escape_or_wrong_reader_rejected_before_extract(self):
        for filename in ('../CodexParticleState.json', 'CodexParticleState.json'):
            with tempfile.TemporaryDirectory() as directory:
                path = Path(directory) / 'capture.zip'
                with zipfile.ZipFile(path, 'w') as archive:
                    archive.writestr(filename, json.dumps({}))
                    archive.writestr('read_original_particle_objects.ps1', 'wrong reader')
                with self.assertRaises(ValueError): read_archive(path, digest(path.read_bytes()))

    def test_stale_cache_targets_stay_unresolved_and24_bit_words_not_invented(self):
        for bpp in (24, 32):
            image = bitmap_fixture(bpp)
            pool = bytearray(0x3468c)
            struct.pack_into('<II', pool, 0x32d68, 0x2010, 0x2000)
            original = bytes(pool)
            report = scanline_observation(pool, image, 0x32d68)
            self.assertEqual(pool, original)
            self.assertEqual(report['current_dib_visual_row_addresses'], [0x200c, 0x2000])
            self.assertEqual(report['mismatched_current_rows'], [0])
            self.assertEqual(report['cached_row_addresses'], [0x2010, 0x2000])
            self.assertEqual('current_dib_words' in report, bpp == 32)
            self.assertFalse(report['native_vcl_verified'])


if __name__ == '__main__':
    unittest.main()
