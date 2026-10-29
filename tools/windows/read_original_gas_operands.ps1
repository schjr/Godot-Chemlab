# Pinned, read-only original gas operand graph. No target calls, writes, suspension,
# GDI operations, privilege changes, process input or networking.
Set-StrictMode -Version Latest
$ErrorActionPreference='Stop'
$ProcessId=9348
$ExpectedVessels=@(0x0d960000,0x0d964380,0x0d968700,0x0d96ca80,0x0d970e00,0x0d97c000)
$expectedSha='7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c'
$expectedReaderSha='f366f56e3a842384cb26395e14ce14361aab0bfb70f34121d3ae80331e263839'
$Output=Join-Path $env:TEMP 'CodexGasOperands.json'
$zip=Join-Path ([Environment]::GetFolderPath('Desktop')) 'gas-operand-results.zip'
if((Test-Path $Output) -or (Test-Path $zip)){throw 'Preserve existing evidence; output JSON/archive already exists'}
if('ChemLabOriginalDibReadProbe' -as [type]){throw 'Use a fresh PowerShell process; reader type already exists'}
$readerSource=Join-Path $PSScriptRoot 'original_dib_read_probe.cs'
if((Get-FileHash -Algorithm SHA256 $readerSource).Hash.ToLowerInvariant() -ne $expectedReaderSha){throw 'Reviewed C# reader identity differs'}
Add-Type -TypeDefinition (Get-Content -Raw -Encoding UTF8 $readerSource)
function Hex([byte[]]$raw){return [BitConverter]::ToString($raw).Replace('-','').ToLowerInvariant()}
function Hash([byte[]]$raw){$ctx=[Security.Cryptography.SHA256]::Create();try{return Hex ($ctx.ComputeHash($raw))}finally{$ctx.Dispose()}}
function Read([UInt64]$address,[int]$length){
 if($address -lt 0x10000 -or $address -gt 4294967295 -or $length -le 0 -or ($address+[UInt64]$length) -gt 0x100000000){throw 'Address/length exceeds bounded original32 read domain'}
 return ,([ChemLabOriginalDibReadProbe]::Read($handle,$address,$length))
}
function U32([UInt64]$address){return [BitConverter]::ToUInt32((Read $address 4),0)}
function Address([UInt64]$value){return ('0x{0:x8}' -f $value)}
function Capture([UInt64]$a,[int]$n,[string]$role){
 [byte[]]$b=Read $a $n
 $key=('{0:x8}:{1:x}' -f $a,$n)
 if($script:blobs.Contains($key)){
  if($script:blobs[$key].sha256 -ne (Hash $b)){throw 'A shared graph object changed within traversal'}
 }else{
  if($script:blobs.Count -ge 8192){throw 'Graph blob bound exceeded; no truncated capture emitted'}
  $script:blobs.Add($key,[ordered]@{address=(Address $a);bytes=$n;role=$role;base64=[Convert]::ToBase64String($b);sha256=(Hash $b)})
 }
 return ,$b
}
function State {
 [byte[]]$run=Capture 0x57a6f8 4 'run-global'
 [byte[]]$fp=Capture 0x5799c4 4 'main-form-pointer'
 $form=[BitConverter]::ToUInt32($fp,0)
 if($form -eq 0){throw 'Original main form is unavailable'}
 [byte[]]$pause=Capture ([UInt64]$form+0x5bc) 4 'pause-field'
 [byte[]]$elapsed=Capture 0x5636cc 8 'elapsed-global'
 [byte[]]$count=Capture 0x58779c 4 'vessel-count'
 if([BitConverter]::ToInt32($run,0) -ne 2 -or [BitConverter]::ToInt32($pause,0) -ne 0 -or (Hex $elapsed) -ne '6cbc749318445240' -or [BitConverter]::ToInt32($count,0) -ne 6){throw 'Pinned paused checkpoint differs; target will not be paused or modified'}
 return [ordered]@{main_form=(Address $form);run=2;pause=0;elapsed_hex=(Hex $elapsed);vessel_count=6}
}
function Graph {
 $script:blobs=[ordered]@{}
 $before=State
 [byte[]]$vp=Capture 0x585850 24 'vessel-pointer-table'
 for($i=0;$i -lt 6;$i++){
  $v=[BitConverter]::ToUInt32($vp,$i*4)
  if($v -ne $ExpectedVessels[$i]){throw 'Pinned six-vessel identity differs'}
  [void](Capture $v 0x4348 "vessel-$i")
 }
 # Each row is unary-comma protected against PowerShell5 pipeline flattening.
 # These are observed operands: differences are reported, not overwritten or
 # rejected merely because the live constant differs from the image file.
 $constantSpans=@(
  ,@(0x4624b0,8,'6666666666663640','quantity22.4')
  ,@(0x4624b8,4,'00007a44','quantity1000')
  ,@(0x48ec70,8,'6666666666663640','initializer22.4')
  ,@(0x48ec78,4,'00007a44','initializer1000')
  ,@(0x46f6d0,8,'6666666666663640','open22.4')
  ,@(0x46f6d8,4,'00007a44','open1000')
  ,@(0x48ec7c,10,'3bdf4f8d976e1283f53f','initializerA')
  ,@(0x46f6ec,10,'3bdf4f8d976e1283f53f','openA')
  ,@(0x48ec88,10,'1fba6ddbb66ddbb6fa3f','initializerB')
  ,@(0x46f6f8,10,'1fba6ddbb66ddbb6fa3f','openB')
 )
 $constants=@()
 foreach($span in $constantSpans){
  [byte[]]$raw=Capture ([UInt64]$span[0]) ([int]$span[1]) ([string]$span[3])
  $constants+=[ordered]@{address=(Address ([UInt64]$span[0]));bytes=[int]$span[1];role=[string]$span[3];observed_hex=(Hex $raw);image_hex=[string]$span[2];matches_original_image=((Hex $raw) -eq $span[2])}
 }
 [byte[]]$code=Capture 0x452d9c 0x8c 'original-reagent-lookup-code'
 if((Hash $code) -ne '79ecf0a1d428ae541775b3923f0e731fd33e72afe1efb22e947be94f2e2e7c59'){throw 'Original in-memory452D9C lookup source differs'}
 [byte[]]$countBytes=Capture 0x580a28 4 'reagent-count'
 $count=[BitConverter]::ToInt32($countBytes,0)
 if($count -le 0 -or $count -gt 1024){throw 'Reagent count exceeds the probe bound; no truncated table emitted'}
 [byte[]]$table=Capture 0x57bc08 ($count*4) 'reagent-pointer-table'
 $expectedInertNameHex='b6e8d0d4c6f8cce528c6f8cce529'
 $records=@();$matchingIndices=@()
 for($i=0;$i -lt $count;$i++){
  $record=[BitConverter]::ToUInt32($table,$i*4)
  if($record -eq 0){throw 'Original lookup table has a null record; original452D9C dereference would be unresolved'}
  [byte[]]$object=Capture $record 0x18 "reagent-record-$i"
  $name=[BitConverter]::ToUInt32($object,8)
  $nameHex='';$nameLength=0;$headerHex=''
  if($name -ne 0){
   if($name -lt 65544){throw 'AnsiString pointer cannot supply the original preceding header'}
   [byte[]]$header=Capture ([UInt64]$name-8) 8 "reagent-string-header-$i"
   $nameLength=[BitConverter]::ToInt32($header,4)
   if($nameLength -lt 0 -or $nameLength -gt 1024){throw 'AnsiString length exceeds the probe bound; no name truncation'}
   [byte[]]$string=Capture ([UInt64]$name-8) (8+$nameLength+1) "reagent-string-$i"
   if($string[8+$nameLength] -ne 0){throw 'Original AnsiString terminator differs'}
   [byte[]]$fullHeader=$string[0..7]
   if((Hex $header) -ne (Hex $fullHeader)){throw 'AnsiString header changed during observed byte read'}
   # Length-based exact bytes preserve embedded NULs and source comparison
   # semantics; no guessed locale decoder or CString truncation is used.
   if($nameLength -eq 0){$nameHex=''}else{
    [byte[]]$nameBytes=New-Object byte[] $nameLength
    [Array]::Copy($string,8,$nameBytes,0,$nameLength)
    $nameHex=Hex $nameBytes
   }
   $headerHex=Hex $header
  }
  [byte[]]$mass=New-Object byte[] 8
  [Array]::Copy($object,0x10,$mass,0,8)
  $row=[ordered]@{index=$i;record=(Address $record);name_pointer=(Address $name);name_length=$nameLength;name_hex=$nameHex;ansi_header_hex=$headerHex;molar_mass_qword_hex=(Hex $mass)}
  $records+=$row
  if($nameHex -ceq $expectedInertNameHex){$matchingIndices+=$i}
 }
 if($matchingIndices.Count -eq 0){throw 'Exact recovered inert species bytes are absent; no guessed reagent index'}
 # Original452D9C scans ascending and stops at the FIRST exact string match.
 $selected=$records[[int]$matchingIndices[0]]
 $inert=[ordered]@{expected_name_hex=$expectedInertNameHex;matching_indices=$matchingIndices;selected_index=[int]$matchingIndices[0];selected_record=$selected;original_molar_mass_qword_hex='0000000000003d40';molar_mass_matches_original=($selected.molar_mass_qword_hex -eq '0000000000003d40');selection='Original452D9C ascending first exact byte-name match'}
 $after=State
 return [ordered]@{before=$before;after=$after;constants=$constants;reagent_count=$count;reagents=$records;inert=$inert;blobs=@($script:blobs.Values)}
}
$handle=[ChemLabOriginalDibReadProbe]::Open([uint32]$ProcessId)
try{
 $image=[ChemLabOriginalDibReadProbe]::ImagePath($handle)
 if((Get-FileHash -Algorithm SHA256 $image).Hash.ToLowerInvariant() -ne $expectedSha){throw 'Original image SHA256 differs'}
 $modules=@([ChemLabOriginalDibReadProbe]::Modules($ProcessId)|Where-Object {$_.szExePath -eq $image}|Sort-Object modBaseAddr,modBaseSize,szExePath -Unique)
 if($modules.Count -ne 1 -or [UInt64]$modules[0].modBaseAddr.ToInt64() -ne 0x400000){throw 'Original module base/identity differs'}
 $first=Graph;$firstJson=$first|ConvertTo-Json -Depth 20 -Compress
 $second=Graph;$secondJson=$second|ConvertTo-Json -Depth 20 -Compress
 if($firstJson -cne $secondJson){throw 'Complete operand graph differs across read-only passes; no evidence output emitted'}
 $result=[ordered]@{format='chemlab-original-gas-operands-readonly-v1';image_sha256=$expectedSha;process_id=$ProcessId;module_base='0x00400000';whole_graph_equal_two_passes=$true;graph=$first;provenance=[ordered]@{reader_sha256=(Get-FileHash -Algorithm SHA256 $PSCommandPath).Hash.ToLowerInvariant();reader_cs_sha256=$expectedReaderSha;target_calls=$false;target_writes=$false;target_suspend=$false;gdi_operations=$false;gdi_flush=$false;native_vcl_verified=$false;rng_tls_status='unobserved';floating_execution_context='unobserved';scope='Read-only observed gas constant/reagent bytes. No GetThreadContext, precision-mode inference, operand replacement, target calls or GDI operations.'}}
 [IO.File]::WriteAllText($Output,($result|ConvertTo-Json -Depth 24),[Text.UTF8Encoding]::new($false))
 Compress-Archive -Path @($Output,$PSCommandPath,$readerSource) -DestinationPath $zip
 Get-FileHash -Algorithm SHA256 $Output
 Get-FileHash -Algorithm SHA256 $zip
}finally{[ChemLabOriginalDibReadProbe]::Close($handle)}
