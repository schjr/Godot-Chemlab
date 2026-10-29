"""Preparation guards only; these tests are not the actual captured graph."""
import json, sys, tempfile, unittest
from pathlib import Path
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
from build_actual_pen_frontier import ObservedOracle, build
from original_x86_oracle import ROOT
class FrontierPreparation(unittest.TestCase):
 def test_native_optional_lock_is_refused_before_mutation(self):
  fixture=json.loads((ROOT/'godot/tests/fixtures/original_pen.json').read_text())
  case=fixture['cases'][1];segments=case['world']['segments']
  oracle=ObservedOracle(segments)
  request=oracle.prefix(0x2000100,0xabcdef)
  self.assertEqual(request,dict(api='EnterCriticalSection',address=0x2000300,source_pc=0x554ec4))
  for segment in segments:
   self.assertEqual(bytes(oracle.uc.mem_read(segment['address'],len(segment['hex'])//2)).hex(),segment['hex'])
 def test_builder_rejects_nonactual_capture_without_output(self):
  with tempfile.TemporaryDirectory() as d:
   directory=Path(d);(directory/'CodexVclPenState.json').write_text('{}')
   output=directory/'fixture.json'
   with self.assertRaisesRegex(ValueError,'Actual capture SHA differs'):build(directory,output)
   self.assertFalse(output.exists())
if __name__=='__main__':unittest.main()
