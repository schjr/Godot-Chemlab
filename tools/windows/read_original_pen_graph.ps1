# Pinned, read-only original VCL pen graph. No target calls, writes, suspension,
# GDI operations, privilege changes, process input or networking.
Set-StrictMode -Version Latest
$ErrorActionPreference='Stop'
$ProcessId=9348
$ExpectedVessels=@(0x0d960000,0x0d964380,0x0d968700,0x0d96ca80,0x0d970e00,0x0d97c000)
$expectedSha='7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c'
$expectedReaderSha='f366f56e3a842384cb26395e14ce14361aab0bfb70f34121d3ae80331e263839'
$Output=Join-Path $env:TEMP 'CodexVclPenState.json'
$zip=Join-Path ([Environment]::GetFolderPath('Desktop')) 'vcl-pen-results.zip'
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
  if($script:blobs.Count -ge 2048){throw 'Graph blob bound exceeded; no truncated capture emitted'}
  $script:blobs.Add($key,[ordered]@{address=(Address $a);bytes=$n;role=$role;base64=[Convert]::ToBase64String($b);sha256=(Hash $b)})
 }
 return ,$b
}
function RequireVmt([byte[]]$bytes,[UInt64]$expected,[string]$role){
 if([BitConverter]::ToUInt32($bytes,0) -ne $expected){throw "$role original VMT identity differs"}
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
function CaptureLock([UInt64]$pointer,[string]$role){
 if($pointer -ne 0){[void](Capture $pointer 24 $role)}
}
function Bitmap([UInt64]$owner,[int]$offset,[string]$role){
 [byte[]]$pointerBytes=Capture ($owner+[UInt64]$offset) 4 "$role-pointer"
 $bitmap=[BitConverter]::ToUInt32($pointerBytes,0)
 $link=[ordered]@{role=$role;owner=(Address $owner);offset=('0x{0:x}' -f $offset);bitmap=(Address $bitmap);canvas_status='unavailable'}
 if($bitmap -eq 0){$link.reason='Null existing TBitmap; no constructor called';return $link}
 [byte[]]$object=Capture $bitmap 0x34 "$role-TBitmap"
 RequireVmt $object 0x4e2af4 'TBitmap'
 $shared=[BitConverter]::ToUInt32($object,0x20)
 $canvas=[BitConverter]::ToUInt32($object,0x24)
 $link.shared_image=Address $shared;$link.canvas=Address $canvas
 if($shared -eq 0){throw 'Existing bitmap shared image unavailable'}
 [void](Capture $shared 0x74 "$role-shared-image")
 if($canvas -eq 0){$link.reason='Canvas has not been constructed; read-only capture cannot obtain it';return $link}
 [byte[]]$cb=Capture $canvas 0x64 "$role-TBitmapCanvas"
 RequireVmt $cb 0x4e80d0 'TBitmapCanvas'
 if([BitConverter]::ToUInt32($cb,0x58) -ne $bitmap){throw 'TBitmapCanvas owner identity differs'}
 $pen=[BitConverter]::ToUInt32($cb,0x10)
 if($pen -eq 0){throw 'Existing Canvas has a null TPen'}
 [byte[]]$pb=Capture $pen 0x1c "$role-TPen"
 RequireVmt $pb 0x4e2420 'TPen'
 $event=[BitConverter]::ToUInt32($pb,8);$eventOwner=[BitConverter]::ToUInt32($pb,12)
 if($event -ne 0x4e4dec -or $eventOwner -ne $canvas){throw 'TPen event differs from source TBitmapCanvas binding'}
 $lock=[BitConverter]::ToUInt32($pb,0x14)
 if($lock -ne ([UInt64]$canvas+0x38)){throw 'TPen critical section differs from source Canvas binding'}
 CaptureLock $lock "$role-Canvas-critical-section"
 $record=[BitConverter]::ToUInt32($pb,0x10)
 if($record -eq 0){throw 'TPen shared record unavailable'}
 $link.canvas_status='read';$link.pen=Address $pen;$link.shared_pen_record=Address $record
 $link.event_code=Address $event;$link.event_owner=Address $eventOwner;$link.lock=Address $lock
 $link.dc_handle=Address ([BitConverter]::ToUInt32($cb,4));$link.canvas_flags=[int]$cb[8]
 return $link
}
function Graph {
 $script:blobs=[ordered]@{}
 $before=State
 [byte[]]$vp=Capture 0x585850 24 'vessel-pointer-table'
 [byte[]]$sp=Capture 0x595214 24 'solid-pool-pointer-table'
 $links=@()
 for($i=0;$i -lt 6;$i++){
  $v=[BitConverter]::ToUInt32($vp,$i*4)
  if($v -ne $ExpectedVessels[$i]){throw 'Pinned six-vessel pointer identity differs'}
  [byte[]]$vb=Capture $v 0x4348 "vessel-$i"
  foreach($offset in @(0xfc,0xf8,0xf4)){$links+=Bitmap $v $offset ("vessel-{0}-{1:x}" -f $i,$offset)}
  $s=[BitConverter]::ToUInt32($sp,$i*4)
  $type=[BitConverter]::ToInt32($vb,8)
  if($type -gt 100 -and $type -lt 200 -and $s -ne 0){
   [void](Capture $s 0x3468c "solid-pool-$i")
   $links+=Bitmap $s 0x34678 "solid-$i-primary"
   $links+=Bitmap $s 0x3467c "solid-$i-retained"
  }
 }
 [byte[]]$rp=Capture 0x59a9e4 4 'pen-registry-pointer'
 $registry=[BitConverter]::ToUInt32($rp,0)
 if($registry -eq 0){throw 'Original pen registry is null'}
 [byte[]]$header=Capture $registry 0x24 'pen-registry-header'
 RequireVmt $header 0x4e2d1c 'TResourceManager'
 $recordSize=[BitConverter]::ToUInt16($header,0x20)
 if($recordSize -ne 16){throw 'Original pen registry record size differs from source initialization4EB3AD'}
 CaptureLock ([UInt64]$registry+8) 'pen-registry-critical-section'
 $node=[BitConverter]::ToUInt32($header,4);$seen=@{};$nodes=@()
 while($node -ne 0){
  $key=Address $node
  if($seen.ContainsKey($key)){throw 'Registry cycle encountered; capture is incomplete'}
  if($nodes.Count -ge 512){throw 'Registry node bound exceeded; no truncated graph emitted'}
  $seen[$key]=$true
  [byte[]]$raw=Capture $node (16+$recordSize) 'pen-registry-node'
  $nodes+=$key
  $node=[BitConverter]::ToUInt32($raw,0)
 }
 foreach($link in $links){
  if($link.canvas_status -eq 'read' -and -not $seen.ContainsKey($link.shared_pen_record)){throw 'Captured TPen shared record is absent from complete registry'}
 }
 [void](Capture 0x59a9a0 4 'stock-pen-handle')
 # These immutable original bytes establish class sizes, inherited dynamic
 # method FFFD->4E34D4, and the actual pen event/registry code identities.
 $identitySpans=@(
  ,@(0x4e2acc, 0x4, '77f906b94309dc84a1d71649eeac2d708182919f62d74580340943d6d8014bf9')
  ,@(0x4e80a0, 0x48, 'ad6b82c722a1d09c18507dcd18a8ba70185a83a0061da22d8844ba8439b5518a')
  ,@(0x4e23f0, 0x3c, 'fc82c70cf0c86e8fc1bdcea91befb7051a1a944ca2f639ee9757552b415d9f10')
  ,@(0x4e21a0, 0x30, 'da35911a84986ea36fa997b958211ccb008c0a49a5719b27bf3195aadac246d0')
  ,@(0x4e21dc, 0x8, '69875e8a538b0f4c79199594ac384cad3f78a43c85e52ce40a1d7701abd61c10')
  ,@(0x4e2cf4, 0x4, 'de6d696c194fb883fd153e435f68d0283ebcf1a28c46cba524df6a8c0807084a')
  ,@(0x4e34d4, 0x14, '7c8351a502cd8babea4af7ccdd9bebc63f5eb747cc9a5e879bab95c918e48336')
  ,@(0x4e4dec, 0x20, '5c7910c64eab05f7a1e9c943f3cbc5be33801baa13fe022f75e9294f204923a3')
  ,@(0x4e2d30, 0x14, '901c24162d469e5299bcdde733b8fddafd3b910d3085a6e6a87131a45949f6db')
 )
 foreach($span in $identitySpans){
  [byte[]]$identity=Capture ([UInt64]$span[0]) ([int]$span[1]) 'original-code-or-VMT'
  if((Hash $identity) -ne $span[2]){throw 'Original in-memory class/code bytes differ from pinned PE'}
 }
 $after=State
 return [ordered]@{before=$before;after=$after;bitmaps=$links;registry=(Address $registry);registry_record_size=$recordSize;registry_nodes=$nodes;blobs=@($script:blobs.Values)}
}
$handle=[ChemLabOriginalDibReadProbe]::Open([uint32]$ProcessId)
try{
 $image=[ChemLabOriginalDibReadProbe]::ImagePath($handle)
 if((Get-FileHash -Algorithm SHA256 $image).Hash.ToLowerInvariant() -ne $expectedSha){throw 'Original image SHA256 differs'}
 $modules=@([ChemLabOriginalDibReadProbe]::Modules($ProcessId)|Where-Object {$_.szExePath -eq $image}|Sort-Object modBaseAddr,modBaseSize,szExePath -Unique)
 if($modules.Count -ne 1 -or [UInt64]$modules[0].modBaseAddr.ToInt64() -ne 0x400000){throw 'Original module base/identity differs'}
 $first=Graph;$firstJson=$first|ConvertTo-Json -Depth 20 -Compress
 $second=Graph;$secondJson=$second|ConvertTo-Json -Depth 20 -Compress
 if($firstJson -cne $secondJson){throw 'Complete graph differs across read-only passes; no evidence output emitted'}
 $result=[ordered]@{format='chemlab-original-vcl-pen-graph-readonly-v1';image_sha256=$expectedSha;process_id=$ProcessId;module_base='0x00400000';whole_graph_equal_two_passes=$true;graph=$first;provenance=[ordered]@{reader_sha256=(Get-FileHash -Algorithm SHA256 $PSCommandPath).Hash.ToLowerInvariant();reader_cs_sha256=$expectedReaderSha;target_calls=$false;target_writes=$false;target_suspend=$false;gdi_operations=$false;gdi_flush=$false;native_vcl_verified=$false;rng_tls_status='unobserved';scope='Existing original object/registry bytes only. No DC queries or operations on target handles; two-pass equality does not establish a drained GDI queue or atomic snapshot.'}}
 [IO.File]::WriteAllText($Output,($result|ConvertTo-Json -Depth 24),[Text.UTF8Encoding]::new($false))
 Compress-Archive -Path @($Output,$PSCommandPath,$readerSource) -DestinationPath $zip
 Get-FileHash -Algorithm SHA256 $Output
 Get-FileHash -Algorithm SHA256 $zip
}finally{[ChemLabOriginalDibReadProbe]::Close($handle)}
