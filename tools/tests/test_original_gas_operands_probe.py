"""Static PE/source checks only. Does not claim Windows probe execution."""
import hashlib,json,re,struct,unittest
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
class GasProbeSource(unittest.TestCase):
 def setUp(self):
  self.source=(ROOT/'tools/windows/read_original_gas_operands.ps1').read_text();self.pe=(ROOT/'artifacts/ChemLab/_main.exe').read_bytes()
 def image_bytes(self,a,n):
  nt=struct.unpack_from('<I',self.pe,60)[0];start=nt+24+struct.unpack_from('<H',self.pe,nt+20)[0];count=struct.unpack_from('<H',self.pe,nt+6)[0]
  for i in range(count):
   _,r,z,t=struct.unpack_from('<4I',self.pe,start+40*i+8)
   if r<=a-0x400000<r+z:return self.pe[t+a-0x400000-r:t+a-0x400000-r+n]
  self.fail('Missing PE address')
 def test_ten_exact_operands_and_protected_nested_rows(self):
  rows=re.findall(r"^  ,@\((0x[0-9a-f]+),(\d+),'([0-9a-f]+)','([^']+)'\)$",self.source,re.M)
  self.assertEqual(len(rows),10)
  for a,n,b,_role in rows:self.assertEqual(self.image_bytes(int(a,16),int(n)).hex(),b)
  table=self.source[self.source.index(' $constantSpans=@('):self.source.index(' $constants=@()')]
  self.assertEqual(table.count('  ,@('),10);self.assertNotIn('\n  @(',table)
 def test_lookup_code_and_byte_name_selection(self):
  self.assertIn(hashlib.sha256(self.image_bytes(0x452d9c,0x8c)).hexdigest(),self.source)
  for required in ['Capture 0x580a28 4','Capture 0x57bc08 ($count*4)','ToUInt32($object,8)','$nameHex -ceq $expectedInertNameHex','$records[[int]$matchingIndices[0]]']:
   self.assertIn(required,self.source)
  inert=next(r for r in json.loads((ROOT/'godot/data/reagents.json').read_text()) if r['species']=='惰性气体(气体)')
  name=inert['raw_fields'][1].encode('gbk');self.assertIn(name.hex(),self.source);self.assertIn(name,self.pe)
  self.assertNotIn('GetEncoding',self.source);self.assertNotIn('CStringBytes(',self.source)
 def test_ps5_unsigned_bounds_and_two_pass_guards(self):
  guard=self.source[self.source.index('function Read('):self.source.index('function U32(')]
  self.assertIn('$address -gt 4294967295',guard);self.assertNotIn('0xffffffff',guard.lower())
  for required in ['$first=Graph','$second=Graph','$firstJson -cne $secondJson','6cbc749318445240','$count -gt 1024','$nameLength -gt 1024','No guessed reagent index'.lower()]:
   self.assertIn(required.lower(),self.source.lower())
  self.assertIn('(Hex $header) -ne (Hex $fullHeader)',self.source)
 def test_read_only_existing_reader_and_output_provenance(self):
  cs=(ROOT/'tools/windows/original_dib_read_probe.cs').read_bytes();self.assertIn(hashlib.sha256(cs).hexdigest(),self.source)
  self.assertIn('OpenProcess(0x0010 | 0x1000, false, processId)',cs.decode())
  imports=set(re.findall(r'private static extern \w+ (\w+)\(',cs.decode()))
  self.assertEqual(imports,{'OpenProcess','ReadProcessMemory','CloseHandle','QueryFullProcessImageNameW','CreateToolhelp32Snapshot','Module32FirstW','Module32NextW'})
  for forbidden in ['GetThreadContext(', 'WriteProcessMemory(', 'SuspendThread(', 'SelectObject(', 'GdiFlush(', 'SetExecutionPolicy']:
   self.assertNotIn(forbidden,self.source)
  for required in ['CodexGasOperands.json','gas-operand-results.zip','floating_execution_context=\'unobserved\'','native_vcl_verified=$false','Compress-Archive -Path @($Output,$PSCommandPath,$readerSource)']:
   self.assertIn(required,self.source)
 def test_live_changed_operands_are_not_replaced_or_rejected(self):
  self.assertIn('matches_original_image=((Hex $raw) -eq $span[2])',self.source)
  self.assertNotIn('if((Hex $raw) -ne $span[2])',self.source)
  self.assertIn("molar_mass_matches_original=($selected.molar_mass_qword_hex -eq '0000000000003d40')",self.source)
if __name__=='__main__':unittest.main()
