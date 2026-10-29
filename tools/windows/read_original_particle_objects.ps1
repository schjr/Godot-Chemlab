$ProcessId=9348;$ExpectedVessels=@(0x0d960000,0x0d964380,0x0d968700,0x0d96ca80,0x0d970e00,0x0d97c000);$Output=join-path $env:temp CodexParticleState.json;
# Read-only original-process snapshot. No target GDI calls, write, injection,
# suspension, input, elevation or networking. Existing DIB storage only.
Set-StrictMode -Version Latest
$ErrorActionPreference='Stop'
$expectedSha='7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c'
if($ExpectedVessels.Count -ne 6){throw 'This bounded capture requires the explicitly identified six vessels'}
if(Test-Path $Output){throw 'Choose a new output filename to preserve evidence'}
if('ChemLabOriginalDibReadProbe' -as [type]){throw 'Use a fresh PowerShell process; do not reuse an unknown compiled reader'}
$readerSource=Join-Path $PSScriptRoot 'original_dib_read_probe.cs'
Add-Type -TypeDefinition (Get-Content -Raw -Encoding UTF8 $readerSource)
function Hex([byte[]]$raw){return [BitConverter]::ToString($raw).Replace('-','').ToLowerInvariant()}
function Hash([byte[]]$raw){$ctx=[Security.Cryptography.SHA256]::Create();try{return Hex ($ctx.ComputeHash($raw))}finally{$ctx.Dispose()}}
function Read([UInt64]$address,[int]$length){return ,([ChemLabOriginalDibReadProbe]::Read($handle,$address,$length))}
function U32([UInt64]$address){return [BitConverter]::ToUInt32((Read $address 4),0)}
function I32([UInt64]$address){return [BitConverter]::ToInt32((Read $address 4),0)}
function Va([UInt64]$preferred){return $moduleBase+($preferred-0x400000)}
function Address([UInt64]$value){return ('0x{0:x8}' -f $value)}
function RunState {
 $run=I32 (Va 0x57a6f8);$form=U32 (Va 0x5799c4)
 if($form -eq 0){throw 'Original main form is unavailable; pause state unknown'}
 $pause=I32 ([UInt64]$form+0x5bc)
 if($run -eq 1 -and $pause -eq 0){throw 'Original simulation is advancing; this reader will not pause it'}
 return @{run=$run;main_form=(Address $form);pause=$pause;elapsed_hex=(Hex (Read (Va 0x5636cc) 8))}
}
function CaptureBitmap([UInt64]$vessel,[int]$offset){
 $bitmap=U32 ($vessel+$offset)
 $record=@{vessel_field=('0x{0:x}' -f $offset);bitmap_pointer=(Address $bitmap);status='unavailable'}
 if($bitmap -eq 0){$record.reason='Null TBitmap';return $record}
 [byte[]]$object=Read $bitmap 0x30
 if([BitConverter]::ToUInt32($object,0) -ne (Va 0x4e2af4)){throw 'TBitmap VMT identity differs'}
 $shared=[BitConverter]::ToUInt32($object,0x20)
 if($shared -eq 0){throw 'Shared image pointer is null'}
 [byte[]]$metadata=Read $shared 0x74
 $record.shared_pointer=Address $shared;$record.bitmap_object_hex=Hex $object;$record.shared_image_hex=Hex $metadata
 $bits=[BitConverter]::ToUInt32($metadata,0x2c)
 $headerSize=[BitConverter]::ToUInt32($metadata,0x30)
 $width=[BitConverter]::ToInt32($metadata,0x34);$signedHeight=[BitConverter]::ToInt32($metadata,0x38)
 $planes=[BitConverter]::ToUInt16($metadata,0x3c);$bpp=[BitConverter]::ToUInt16($metadata,0x3e);$compression=[BitConverter]::ToUInt32($metadata,0x40)
 $record.bits_pointer=Address $bits;$record.header_size=$headerSize;$record.width=$width;$record.signed_height=$signedHeight;$record.planes=$planes;$record.bit_count=$bpp;$record.compression=$compression
 if($bits -eq 0){$record.reason='No existing CPU-readable DIB bits; DDB conversion or target GetScanLine is forbidden';return $record}
 if($headerSize -ne 40 -or $planes -ne 1 -or $compression -ne 0 -or $bpp -notin @(24,32)){throw 'Existing DIB format is unsupported; no guessed interpretation'}
 if($width -le 0 -or $width -gt 1024 -or $signedHeight -eq 0 -or $signedHeight -lt -1024 -or $signedHeight -gt 1024){throw 'Existing DIB dimensions exceed the read-only safety bound'}
 $height=[Math]::Abs($signedHeight);$stride=[int](([Math]::Floor(($width*$bpp+31)/32))*4);$size=$stride*$height
 if([BitConverter]::ToInt32($metadata,0x1c) -ne $width -or [BitConverter]::ToInt32($metadata,0x20) -ne $height -or [BitConverter]::ToInt32($metadata,0x24) -ne $stride -or [BitConverter]::ToUInt16($metadata,0x28) -ne 1 -or [BitConverter]::ToUInt16($metadata,0x2a) -ne $bpp){throw 'BITMAP and DIB header metadata disagree'}
 if($size -gt 1048576){throw 'Existing DIB storage exceeds the per-image safety bound'}
 # Compare metadata and entire backing store twice. No GdiFlush is called in
 # the original process; unchanged reads do not prove all pending GDI drained.
 [byte[]]$raw=Read $bits $size
 [byte[]]$again=Read $bits $size
 if((Hex $raw) -ne (Hex $again) -or (Hex $metadata) -ne (Hex (Read $shared 0x74)) -or (Hex $object) -ne (Hex (Read $bitmap 0x30)) -or $bitmap -ne (U32 ($vessel+$offset))){throw 'Bitmap pixels or metadata changed during read'}
 [byte[]]$topdown=New-Object byte[] $size
 for($y=0;$y -lt $height;$y++){$storedY=$y;if($signedHeight -gt 0){$storedY=$height-1-$y};[Array]::Copy($raw,$storedY*$stride,$topdown,$y*$stride,$stride)}
 $record.status='read';$record.height=$height;$record.row_stride=$stride;$record.storage_bytes=$size
 $record.raw_storage_base64=[Convert]::ToBase64String($raw);$record.raw_storage_sha256=Hash $raw
 $record.visual_topdown_base64=[Convert]::ToBase64String($topdown);$record.visual_topdown_sha256=Hash $topdown
 $record.metadata_and_pixels_stable_during_read=$true;$record.gdi_flush_in_target=$false
 return $record
}
function Blob([UInt64]$a,[int]$n){[byte[]]$b=Read $a $n;if((Hash $b) -ne (Hash (Read $a $n))){throw 'Changing raw object'};return @{address=(Address $a);bytes=$n;base64=[Convert]::ToBase64String($b);sha256=(Hash $b)}}
$handle=[ChemLabOriginalDibReadProbe]::Open([uint32]$ProcessId)
try{
$image=[ChemLabOriginalDibReadProbe]::ImagePath($handle);if((Get-FileHash -Algorithm SHA256 $image).Hash.ToLowerInvariant() -ne $expectedSha){throw 'Image differs'}
$modules=@([ChemLabOriginalDibReadProbe]::Modules($ProcessId)|Where-Object {$_.szExePath -eq $image}|Sort-Object modBaseAddr,modBaseSize,szExePath -Unique)
if($modules.Count -ne 1){throw 'Module identity differs'};$moduleBase=[UInt64]$modules[0].modBaseAddr.ToInt64();if($moduleBase -ne 0x400000){throw 'Reviewed image base differs'}
$before=RunState;if($before.elapsed_hex -ne '6cbc749318445240' -or (I32 (Va 0x58779c)) -ne 6){throw 'Checkpoint differs'}
[byte[]]$vp=Read (Va 0x585850) 24;[byte[]]$sp=Read (Va 0x595214) 24;[byte[]]$bp=Read (Va 0x5940b0) 24;$rows=@()
for($i=0;$i -lt 6;$i++){
$v=[BitConverter]::ToUInt32($vp,$i*4);if($v -ne $ExpectedVessels[$i]){throw 'Vessel identity differs'};$s=[BitConverter]::ToUInt32($sp,$i*4);$b=[BitConverter]::ToUInt32($bp,$i*4)
$type=I32 ($v+8);$row=@{native_index=$i;type_id=$type;vessel=(Blob $v 0x4348);solid_pointer=(Address $s);bubble_pointer=(Address $b)}
if($type -gt 100 -and $type -lt 200 -and $s -ne 0){$row.solid=(Blob $s 0x3468c);$row.solid_bitmaps=@((CaptureBitmap $s 0x34678),(CaptureBitmap $s 0x3467c))}
if($type -gt 100 -and $type -lt 200 -and $b -ne 0){$row.bubbles=(Blob $b 0xfc20)};$rows+=$row
}
$after=RunState;foreach($k in @('run','main_form','pause','elapsed_hex')){if($before[$k] -ne $after[$k]){throw 'Run state changed'}}
foreach($pair in @(@(0x585850,$vp),@(0x595214,$sp),@(0x5940b0,$bp))){if((Hash $pair[1]) -ne (Hash (Read (Va $pair[0]) 24))){throw 'Pointer table changed'}}
$result=@{format='chemlab-original-particle-objects-readonly-v1';image_sha256=$expectedSha;process_id=$ProcessId;module_base=(Address $moduleBase);before=$before;after=$after;objects=$rows}
$result.globals=@{crt_timezone=(Hex (Read (Va 0x577974) 4));crt_daylight=(Hex (Read (Va 0x577978) 4));stored_fpu_policy=(Hex (Read (Va 0x5755e8) 2))}
$result.provenance=@{reader_sha256=(Get-FileHash $PSCommandPath).Hash.ToLowerInvariant();reader_cs_sha256=(Get-FileHash $readerSource).Hash.ToLowerInvariant();target_calls=$false;target_writes=$false;target_suspend=$false;gdi_flush=$false;rng_tls_status='unobserved';native_vcl_verified=$false}
[IO.File]::WriteAllText($Output,($result|ConvertTo-Json -Depth 20),[Text.UTF8Encoding]::new($false))
$zip=join-path $env:userprofile desktop/particle-pool-results.zip;if(Test-Path $zip){throw 'Preserve existing archive'};Compress-Archive -Path @($Output,$PSCommandPath) -DestinationPath $zip;Get-FileHash $zip
}finally{[ChemLabOriginalDibReadProbe]::Close($handle)}
