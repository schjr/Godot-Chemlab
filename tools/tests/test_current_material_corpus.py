"""Source-input and bounded-recipe checks, not Windows pixel execution."""
import hashlib
import json
from pathlib import Path
import struct
import unittest

ROOT=Path(__file__).resolve().parents[2]

class CurrentMaterialCorpusTests(unittest.TestCase):
    def test_six_observed_exact_slot_recipes(self):
        corpus=json.loads((ROOT/'evidence/original_logic/current-material-gdi-cases.json').read_text())
        raw=(ROOT/corpus['input_capture']['path']).read_bytes()
        self.assertEqual(hashlib.sha256(raw).hexdigest(),corpus['input_capture']['sha256'])
        observed=json.loads(raw.decode('utf-8-sig'))['snapshots'][0]['vessels']
        self.assertEqual(len(corpus['cases']),6)
        self.assertEqual([c['native_index'] for c in corpus['cases']],list(range(6)))
        for case,record in zip(corpus['cases'],observed):
            self.assertEqual(case['observed_pointer'],record['pointer'])
            self.assertEqual(case['inputs']['ordered_species'],[r['text'] for r in record['species']])
            for name,raw_hex in case['inputs']['arrays'].items():
                self.assertEqual(raw_hex,record['arrays'][name]['raw_hex'])
                self.assertEqual(len(bytes.fromhex(raw_hex)),800)
            self.assertEqual(case['bitmap_format'],32)
            self.assertLessEqual(len(case['operations']),16)
            self.assertEqual([s['stage'] for s in case['stages']],['clear_white','liquid','gas','suspended_particles','surface_outline','settled_solid'])
            self.assertEqual(case['stages'][-1]['status'],'native_zero_no_operations')
            self.assertEqual(case['stages'][-1]['operations'],[])
            self.assertEqual(case['inputs']['pool_gas_delta']['status'],'unobserved_explicit_zero_hypothesis')
            self.assertEqual(case['stages'][3]['status'],'not_replayed')
            bitmap=(ROOT/case['bitmap_asset']['path']).read_bytes()
            self.assertEqual(hashlib.sha256(bitmap).hexdigest(),case['bitmap_asset']['sha256'])
            width,height=struct.unpack_from('<ii',bitmap,18)
            self.assertEqual((case['width'],case['height']),(width,abs(height)))
            self.assertEqual(case['operations'],[op for stage in case['stages'] for op in stage['operations']])
            self.assertTrue(all(op['op']=='rectangle' and op['brush_style'] in (0,1) for op in case['operations']))

if __name__=='__main__':unittest.main()
