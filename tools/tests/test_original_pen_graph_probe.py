"""Source/identity checks only; this does not execute a Windows capture."""
import hashlib,re,struct,unittest
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
class PenGraphProbeSource(unittest.TestCase):
 def setUp(self):
  self.source=(ROOT/'tools/windows/read_original_pen_graph.ps1').read_text()
  self.pe=(ROOT/'artifacts/ChemLab/_main.exe').read_bytes()
 def read(self,address,length):
  nt=struct.unpack_from('<I',self.pe,60)[0];n=struct.unpack_from('<H',self.pe,nt+6)[0];start=nt+24+struct.unpack_from('<H',self.pe,nt+20)[0]
  for i in range(n):
   _,rva,size,offset=struct.unpack_from('<4I',self.pe,start+i*40+8)
   if rva<=address-0x400000<rva+size:
    return self.pe[offset+address-0x400000-rva:offset+address-0x400000-rva+length]
  self.fail('Address not backed by original PE')
 def test_all_pinned_code_spans_match_original(self):
  spans=re.findall(r"@\((0x[0-9a-f]+), (0x[0-9a-f]+), '([0-9a-f]{64})'\)",self.source)
  self.assertGreaterEqual(len(spans),9)
  for a,n,h in spans:self.assertEqual(hashlib.sha256(self.read(int(a,16),int(n,16))).hexdigest(),h)
 def test_exact_source_class_sizes_and_dynamic_pen_event(self):
  for v,size in [(0x4e2af4,0x34),(0x4e80d0,0x64),(0x4e2420,0x1c),(0x4e2d1c,0x24)]:
   self.assertEqual(struct.unpack('<I',self.read(v-0x28,4))[0],size)
  self.assertEqual(self.read(0x4e21dc,8),struct.pack('<HHI',1,0xfffd,0x4e34d4))
 def test_existing_reader_identity_and_no_target_mutation_apis(self):
  cs=(ROOT/'tools/windows/original_dib_read_probe.cs').read_bytes()
  self.assertIn(hashlib.sha256(cs).hexdigest(),self.source)
  imports=re.findall(r'private static extern \w+ (\w+)\(',cs.decode())
  self.assertEqual(set(imports),{'OpenProcess','ReadProcessMemory','CloseHandle','QueryFullProcessImageNameW','CreateToolhelp32Snapshot','Module32FirstW','Module32NextW'})
  self.assertIn('OpenProcess(0x0010 | 0x1000, false, processId)',cs.decode())
  for forbidden in ['WriteProcessMemory','VirtualAllocEx','CreateRemoteThread','SuspendThread','GdiFlush(', 'SelectObject(', 'DeleteObject(']:self.assertNotIn(forbidden,self.source)
 def test_powershell5_unsigned_address_limit_literal(self):
  guard=self.source[self.source.index('function Read('):self.source.index('function U32(')]
  self.assertIn('$address -gt 4294967295',guard)
  self.assertNotIn('0xffffffff',guard.lower())
  # WinPS5 treats hexFFFFFFFF as Int32(-1); decimal4294967295 promotes
  # to positive Int64, preserving valid original DWORD addresses.
  self.assertGreater(4294967295,0x0d960000)
 def test_powershell_identity_spans_preserve_nested_arrays(self):
  table=self.source[self.source.index(' $identitySpans=@('):self.source.index(' foreach($span in $identitySpans)')]
  rows=[line for line in table.splitlines() if '0x' in line]
  self.assertEqual(len(rows),9)
  self.assertTrue(all(line.startswith('  ,@(') for line in rows))
 def test_whole_graph_and_failure_guards(self):
  for required in ['$first=Graph','$second=Graph','$firstJson -cne $secondJson','Registry cycle encountered','Registry node bound exceeded','source Canvas binding','Canvas has not been constructed','native_vcl_verified=$false','6cbc749318445240','0xfc,0xf8,0xf4','0x34678','0x3467c','0x59a9e4','0x59a9a0']:
   self.assertIn(required,self.source)
  self.assertIn('Compress-Archive -Path @($Output,$PSCommandPath,$readerSource)',self.source)
if __name__=='__main__':unittest.main()
