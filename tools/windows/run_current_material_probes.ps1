param(
 [string]$Corpus=(Join-Path $PSScriptRoot 'current-material-gdi-cases.json'),
 [Parameter(Mandatory=$true)][string]$ExpectedCorpusSha256,
 [Parameter(Mandatory=$true)][string]$ExpectedGdiSourceSha256,
 [string]$Output=(Join-Path $PSScriptRoot 'current-material-gdi-result.json')
)
# Offline bounded actual GDI, no process access, listener or target writes.
Set-StrictMode -Version Latest
$ErrorActionPreference='Stop'
if(Test-Path $Output){throw 'Choose a new evidence output filename'}
$source=Join-Path $PSScriptRoot 'original_gdi_host.cs'
if((Get-FileHash -Algorithm SHA256 $Corpus).Hash.ToLowerInvariant() -ne $ExpectedCorpusSha256){throw 'Reviewed material corpus hash differs'}
if((Get-FileHash -Algorithm SHA256 $source).Hash.ToLowerInvariant() -ne $ExpectedGdiSourceSha256){throw 'Reviewed GDI source hash differs'}
$data=Get-Content -Raw -Encoding UTF8 $Corpus|ConvertFrom-Json
if($data.format -ne 'chemlab-current-material-gdi-cases-v1' -or $data.original_binary_sha256 -ne '7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c' -or $data.cases.Count -ne 6){throw 'Original material corpus identity differs'}
if('OriginalGdiBitmap' -as [type]){throw 'Run in a fresh PowerShell process; do not reuse an unknown compiled GDI class'}
Add-Type -TypeDefinition (Get-Content -Raw -Encoding UTF8 $source)
function Hash([byte[]]$raw){$ctx=[Security.Cryptography.SHA256]::Create();try{return ([BitConverter]::ToString($ctx.ComputeHash($raw))).Replace('-','').ToLowerInvariant()}finally{$ctx.Dispose()}}
$results=@()
foreach($case in $data.cases){
 $w=[int]$case.width;$h=[int]$case.height
 if($w -le 0 -or $h -le 0 -or $w -gt 256 -or $h -gt 256 -or $case.operations.Count -gt 16 -or [int]$case.bitmap_format -ne 32){throw 'Material case exceeds reviewed native32 bounds'}
 $bitmap=$null
 try{
  $bitmap=[OriginalGdiBitmap]::new($w,$h,32);$bitmap.StretchMode=[int]$case.initial_stretch_mode
  foreach($op in $case.operations){
   if($op.op -ne 'rectangle' -or [int]$op.brush_style -notin @(0,1)){throw 'Unreviewed material primitive'}
   $bitmap.Shape('rectangle',[int]$op.left,[int]$op.top,[int]$op.right,[int]$op.bottom,[uint32]$op.pen_color,[uint32]$op.brush_color,[int]$op.brush_style,0,0,0,0)
  }
  $bgra=$bitmap.ConvertedWords();$raw=[Convert]::FromBase64String($bgra)
  $results+=@{id=$case.id;native_index=$case.native_index;observed_pointer=$case.observed_pointer;width=$w;height=$h;bitmap_format=32;returned_pixel_format=32;bgra=$bgra;pixel_sha256=(Hash $raw);stretch_mode=$bitmap.StretchMode;operations=$case.operations;stages=$case.stages}
 }finally{if($bitmap){$bitmap.Dispose()}}
}
$dlls=@()
foreach($name in @('gdi32.dll','gdi32full.dll','win32u.dll','user32.dll')){
 $path=Join-Path ([Environment]::SystemDirectory) $name
 if(Test-Path $path){$file=Get-Item $path;$dlls+=@{name=$name;path=$path;version=$file.VersionInfo.FileVersion;sha256=(Get-FileHash -Algorithm SHA256 $path).Hash.ToLowerInvariant()}}
}
$result=@{format='chemlab-current-material-gdi-result-v1';created_utc=[DateTime]::UtcNow.ToString('o');native_vcl_verified=$false;corpus_sha256=$ExpectedCorpusSha256;gdi_source_sha256=$ExpectedGdiSourceSha256;runner_sha256=(Get-FileHash -Algorithm SHA256 $PSCommandPath).Hash.ToLowerInvariant();input_capture=$data.input_capture;source_plan=$data.source_plan;scope=$data.scope;original_binary_sha256=$data.original_binary_sha256;runtime=@{os_version=[Environment]::OSVersion.VersionString;process_64bit=[Environment]::Is64BitProcess;powershell=$PSVersionTable.PSVersion.ToString();desktop_bits=[OriginalGdiBitmap]::DesktopBits;system_dlls=$dlls};cases=$results}
[IO.File]::WriteAllText([IO.Path]::GetFullPath($Output),($result|ConvertTo-Json -Depth 30),[Text.UTF8Encoding]::new($false))
Write-Output ('Captured six uncomposed material reference bitmaps. Original VCL/full-frame validation remains pending: '+$Output)
