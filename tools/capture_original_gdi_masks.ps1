param(
 [Parameter(Mandatory=$true)][string]$Fixture,
 [Parameter(Mandatory=$true)][string]$Guti,
 [Parameter(Mandatory=$true)][string]$Output
)
# Windows-only direct GDI probe. Parent controls the VM. This is NOT an assertion
# that stock DC palette defaults match the legacy VCL bitmap implementation.
$ErrorActionPreference = 'Stop'
$sha = (Get-FileHash -Algorithm SHA256 $Guti).Hash.ToLowerInvariant()
if ($sha -ne 'c4087e0532dfa5aa9e6a148c1da5a34f0845b03b0ef7af003b66a93b0fcb4f31') { throw 'Original guti.bmp SHA256 mismatch' }
Add-Type -TypeDefinition (Get-Content -Raw -Encoding UTF8 (Join-Path $PSScriptRoot 'windows/original_gdi_host.cs'))
$fixtureData = Get-Content -Raw -Encoding UTF8 $Fixture | ConvertFrom-Json
$entries = @{}
foreach ($case in $fixtureData.cases) {
 $width=[int]$case.width; $height=[int]$case.height
 $parts = [System.Collections.Generic.List[string]]::new()
 $parts.Add([string]$width);$parts.Add([string]$height)
 foreach ($op in $case.native_operations) {
  if ($op.op -in @('rectangle','ellipse','arc')) {
   $parts.Add([string]$op.op)
   foreach ($field in @('left','top','right','bottom')) {$parts.Add([string][int]$op.$field)}
   if($op.op -eq 'arc'){foreach($field in @('start_x','start_y','end_x','end_y')){$parts.Add([string][int]$op.$field)}}
  }
 }
 if($case.native_operations.Count -eq 0){continue}
 $key=[string]::Join(';',$parts)
 if($entries.ContainsKey($key)){continue}
 $colorStencil=[OriginalGdiBitmap]::new($width,$height,0)
 $arc=[OriginalGdiBitmap]::new($width,$height,32)
 try {
  foreach($op in $case.native_operations) {
   if($op.op -in @('rectangle','ellipse')) {
    # Source trace uses white clear and black stencil, each pen=brush.
    $color=[uint32]$op.brush_color
    $colorStencil.Shape([string]$op.op,[int]$op.left,[int]$op.top,[int]$op.right,[int]$op.bottom,[uint32]$op.pen_color,[uint32]$op.brush_color,[int]$op.brush_style,0,0,0,0)
   } elseif($op.op -eq 'texture') {$colorStencil.Texture($Guti)}
   elseif($op.op -eq 'arc') {$arc.Shape('arc',[int]$op.left,[int]$op.top,[int]$op.right,[int]$op.bottom,0,0,0,[int]$op.start_x,[int]$op.start_y,[int]$op.end_x,[int]$op.end_y)}
  }
  $entries[$key]=@{width=$width;height=$height;stencil_texture_bgra=$colorStencil.ConvertedWords();arc_coverage=$arc.Coverage();probe_case=$case.name}
 } finally {$colorStencil.Dispose();$arc.Dispose()}
}
$atlas=@{format='chemlab-gdi-mask-atlas-v2';guti_sha256=$sha;native_vcl_verified=$false;
 boundary='Direct Win32 GDI probe; source-traced device-compatible stencil then native GetDIBits32; DIB32 Arc, R2_COPYPEN/one-pixel solid pen, source brush/font state, texture StretchBlt color mode. Compare original VCL outputs before enabling.';
 entries=$entries}
$json=$atlas|ConvertTo-Json -Depth 20 -Compress
[System.IO.File]::WriteAllText($Output,$json,[System.Text.UTF8Encoding]::new($false))
Write-Output ('Captured {0} unique geometry probes. Native VCL verification remains required.' -f $entries.Count)
