param(
 [string]$Output=(Join-Path $PSScriptRoot 'current-gdi-result.json'),
 [string]$Compare=''
)
# Bounded offline native GDI probe: no listener, target app, elevation or policy changes.
$ErrorActionPreference='Stop'
if($env:OS -ne 'Windows_NT'){throw 'Actual Windows GDI is required'}
$manifest=Get-Content -Raw -Encoding UTF8 (Join-Path $PSScriptRoot 'manifest.json')|ConvertFrom-Json
foreach($item in $manifest.files){
 $path=Join-Path $PSScriptRoot $item.path
 if((Get-FileHash -Algorithm SHA256 $path).Hash.ToLowerInvariant() -ne $item.sha256){throw ('Package hash mismatch: '+$item.path)}
}
$corpus=Get-Content -Raw -Encoding UTF8 (Join-Path $PSScriptRoot 'current-gdi-cases.json')|ConvertFrom-Json
if($corpus.format -ne 'chemlab-current-gdi-cases-v1' -or $corpus.cases.Count -gt 96){throw 'Invalid bounded corpus'}
$source=Join-Path $PSScriptRoot 'original_gdi_host.cs'
$guti=Join-Path $PSScriptRoot 'guti.bmp'
Add-Type -TypeDefinition (Get-Content -Raw -Encoding UTF8 $source)
function ByteHash([byte[]]$raw){
 $hasher=[System.Security.Cryptography.SHA256]::Create()
 try{return ([BitConverter]::ToString($hasher.ComputeHash($raw))).Replace('-','').ToLowerInvariant()}finally{$hasher.Dispose()}
}
$prior=@{}
if($Compare){
 $reference=Get-Content -Raw -Encoding UTF8 $Compare|ConvertFrom-Json
 if($reference.format -ne 'chemlab-current-gdi-result-v1' -or $reference.corpus_sha256 -ne (Get-FileHash -Algorithm SHA256 (Join-Path $PSScriptRoot 'current-gdi-cases.json')).Hash.ToLowerInvariant()){throw 'Comparison requires the identical corpus'}
 foreach($row in $reference.cases){$prior[$row.id]=$row}
}
$results=[System.Collections.Generic.List[object]]::new()
foreach($case in $corpus.cases){
 $w=[int]$case.width;$h=[int]$case.height
 if($w -le 0 -or $h -le 0 -or $w -gt 256 -or $h -gt 256 -or $case.operations.Count -gt 16){throw 'Case exceeds reviewed bounds'}
 $bitmap=$null
 try{
  $bitmap=[OriginalGdiBitmap]::new($w,$h,[int]$case.bitmap_format)
  $bitmap.StretchMode=[int]$case.initial_stretch_mode
  $initialProperty=$case.PSObject.Properties['initial_bgra']
  if($null -ne $initialProperty -and $initialProperty.Value){$bitmap.LoadWords([string]$initialProperty.Value)}
  foreach($op in $case.operations){
   switch([string]$op.op){
    {$_ -in @('rectangle','ellipse','arc')} {
     if([int]$op.brush_style -notin @(0,1)){throw 'Unreviewed brush style'}
     $sx=0;$sy=0;$ex=0;$ey=0
     # Arc endpoints are mandatory for Arc, unused by Rectangle/Ellipse.
     if($op.op -eq 'arc'){$sx=[int]$op.start_x;$sy=[int]$op.start_y;$ex=[int]$op.end_x;$ey=[int]$op.end_y}
     $bitmap.Shape([string]$op.op,[int]$op.left,[int]$op.top,[int]$op.right,[int]$op.bottom,[uint32]$op.pen_color,[uint32]$op.brush_color,[int]$op.brush_style,$sx,$sy,$ex,$ey)
    }
    'texture' {
     if($op.source -ne 'guti.bmp' -or [int]$op.copy_mode -ne 0xEE0086 -or [int]$op.left -ne 0 -or [int]$op.top -ne 0){throw 'Unreviewed texture operation'}
     $bitmap.Texture($guti)
    }
    'transparent' {if([int]$op.value -ne 1){throw 'Unreviewed transparency metadata'}}
    'copy_rect' {
     if([int]$op.source_width -gt 256 -or [int]$op.source_height -gt 256 -or [int]$op.source_width -le 0 -or [int]$op.source_height -le 0){throw 'Unbounded source'}
     if([uint32]$op.copy_mode -notin @(0xCC0020,0xEE0086)){throw 'Unreviewed ROP'}
     $bitmap.CopyRectWords([string]$op.source_bgra,[int]$op.source_width,[int]$op.source_height,[int]$op.left,[int]$op.top,[int]$op.right,[int]$op.bottom,[int]$op.source_left,[int]$op.source_top,[int]$op.source_right,[int]$op.source_bottom,[uint32]$op.copy_mode)
    }
    default {throw ('Unreviewed operation: '+$op.op)}
   }
  }
  $bgra=$bitmap.ConvertedWords();$raw=[Convert]::FromBase64String($bgra)
  if($raw.Length -ne $w*$h*4){throw 'Native output length mismatch'}
  $different=$null;$rgbDifferent=$null;$reservedDifferent=$null
  if($Compare){
   if(-not $prior.ContainsKey($case.id)){throw ('Missing reference case '+$case.id)}
   $expected=[Convert]::FromBase64String([string]$prior[$case.id].bgra)
   if($expected.Length -ne $raw.Length){throw 'Reference geometry mismatch'}
   $different=0;$rgbDifferent=0;$reservedDifferent=0
   for($i=0;$i -lt $raw.Length;$i++){if($raw[$i] -ne $expected[$i]){$different++;if($i%4 -eq 3){$reservedDifferent++}else{$rgbDifferent++}}}
  }
  $results.Add(@{id=$case.id;width=$w;height=$h;bitmap_format=[int]$case.bitmap_format;returned_pixel_format=32;bgra=$bgra;pixel_sha256=(ByteHash $raw);stretch_mode=$bitmap.StretchMode;comparison_byte_differences=$different;comparison_rgb_byte_differences=$rgbDifferent;comparison_reserved_byte_differences=$reservedDifferent})
 }finally{if($bitmap){$bitmap.Dispose()}}
}
$dlls=@()
foreach($name in @('gdi32.dll','gdi32full.dll','win32u.dll','user32.dll')){
 $path=Join-Path ([Environment]::SystemDirectory) $name
 if(Test-Path $path){$f=Get-Item $path;$dlls+=@{name=$name;path=$path;version=$f.VersionInfo.FileVersion;sha256=(Get-FileHash -Algorithm SHA256 $path).Hash.ToLowerInvariant()}}
}
$result=@{format='chemlab-current-gdi-result-v1';created_utc=[DateTime]::UtcNow.ToString('o');native_vcl_verified=$false;
 boundary='Actual Windows GDI pixels from the reviewed source-traced construction profile. No original VCL process or full-frame comparison was run.';
 corpus_sha256=(Get-FileHash -Algorithm SHA256 (Join-Path $PSScriptRoot 'current-gdi-cases.json')).Hash.ToLowerInvariant();
 manifest_sha256=(Get-FileHash -Algorithm SHA256 (Join-Path $PSScriptRoot 'manifest.json')).Hash.ToLowerInvariant();
 original_binary_sha256=$corpus.original_binary_sha256;package_files=$manifest.files;
 runtime=@{os_version=[Environment]::OSVersion.VersionString;process_64bit=[Environment]::Is64BitProcess;os_64bit=[Environment]::Is64BitOperatingSystem;framework=[Environment]::Version.ToString();powershell=$PSVersionTable.PSVersion.ToString();desktop_bits=[OriginalGdiBitmap]::DesktopBits;culture=[Globalization.CultureInfo]::CurrentCulture.Name;system_dlls=$dlls};
 comparison_reference_sha256=$(if($Compare){(Get-FileHash -Algorithm SHA256 $Compare).Hash.ToLowerInvariant()}else{$null});cases=$results.ToArray()}
[IO.File]::WriteAllText([IO.Path]::GetFullPath($Output),($result|ConvertTo-Json -Depth 30),[Text.UTF8Encoding]::new($false))
Write-Output ('Captured {0} bounded actual-GDI cases to {1}. Original VCL verification remains pending.' -f $results.Count,$Output)
