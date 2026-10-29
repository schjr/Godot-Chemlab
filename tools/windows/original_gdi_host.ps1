param([Parameter(Mandatory=$true)][string]$Guti,[int]$Port=17708,[string]$BindAddress='127.0.0.1')
# Persistent arbitrary-geometry native Windows GDI host. No legacy app launch.
# Bind to loopback by default; the parent manages VM forwarding and lifetime.
$ErrorActionPreference='Stop'
$bindIP=[System.Net.IPAddress]::Parse($BindAddress)
if(-not [System.Net.IPAddress]::IsLoopback($bindIP)){throw 'This reference host permits loopback binding only'}
$sha=(Get-FileHash -Algorithm SHA256 $Guti).Hash.ToLowerInvariant()
if($sha -ne 'c4087e0532dfa5aa9e6a148c1da5a34f0845b03b0ef7af003b66a93b0fcb4f31'){throw 'Original guti.bmp hash differs'}
Add-Type -TypeDefinition (Get-Content -Raw -Encoding UTF8 (Join-Path $PSScriptRoot 'original_gdi_host.cs'))
$listener=[System.Net.Sockets.TcpListener]::new($bindIP,$Port)
$listener.Start()
try {
 while($true){
  $client=$listener.AcceptTcpClient()
  try {
   $stream=$client.GetStream()
   $reader=[System.IO.StreamReader]::new($stream,[System.Text.UTF8Encoding]::new($false))
   $writer=[System.IO.StreamWriter]::new($stream,[System.Text.UTF8Encoding]::new($false));$writer.AutoFlush=$true
   while(($line=$reader.ReadLine()) -ne $null){
    $bitmap=$null
    try {
     if($line.Length -gt 24*1024*1024){throw 'Request too large'}
     $request=$line|ConvertFrom-Json
     if($request.protocol -ne 'chemlab-native-gdi-v1'){throw 'Unknown GDI protocol'}
     $w=[int]$request.width;$h=[int]$request.height
     if($w -le 0 -or $h -le 0 -or $w*$h -gt 4*1024*1024){throw 'Bitmap geometry outside bounded native host contract'}
     $format=32
     if($request.PSObject.Properties.Name -contains "bitmap_format"){$format=[int]$request.bitmap_format}
     if($format -notin @(0,24,32)){throw "Unsupported original color bitmap format"}
     $bitmap=[OriginalGdiBitmap]::new($w,$h,$format)
     if($request.PSObject.Properties.Name -contains "initial_stretch_mode"){$bitmap.StretchMode=[int]$request.initial_stretch_mode}
     if($request.initial_bgra){$bitmap.LoadWords([string]$request.initial_bgra)}
     foreach($op in $request.operations){
      if($op.op -in @('rectangle','ellipse','arc')){
       $style=[int]$op.brush_style
       if($style -notin @(0,1)){throw 'Unported brush style'}
       $bitmap.Shape([string]$op.op,[int]$op.left,[int]$op.top,[int]$op.right,[int]$op.bottom,
        [uint32]$op.pen_color,[uint32]$op.brush_color,$style,[int]$op.start_x,[int]$op.start_y,[int]$op.end_x,[int]$op.end_y)
      }elseif($op.op -eq 'copy_rect'){
       $sw=[int]$op.source_width;$sh=[int]$op.source_height
       if($sw -le 0 -or $sh -le 0 -or $sw*$sh -gt 4*1024*1024){throw 'Source bitmap outside bounded native host contract'}
       $rop=[uint32]$op.copy_mode
       if($rop -notin @(0xEE0086,0xCC0020)){throw 'Unported original CopyRect raster operation'}
       $bitmap.CopyRectWords([string]$op.source_bgra,$sw,$sh,[int]$op.left,[int]$op.top,[int]$op.right,[int]$op.bottom,
        [int]$op.source_left,[int]$op.source_top,[int]$op.source_right,[int]$op.source_bottom,$rop)
      }elseif($op.op -eq 'texture'){
       if($op.source -ne 'guti.bmp' -or [int]$op.copy_mode -ne 0xEE0086 -or [int]$op.left -ne 0 -or [int]$op.top -ne 0){throw 'Unsupported original texture operation'}
       $bitmap.Texture($Guti)
      }elseif($op.op -eq 'transparent'){
       # Object transparency governs drawing this bitmap as a source later;
       # it does not modify raster pixels inside its own memory DC.
       if([int]$op.value -ne 1){throw 'Unexpected original transparency state'}
      }else{throw ('Unported GDI operation '+$op.op)}
     }
     $response=@{ok=$true;protocol='chemlab-native-gdi-v1';width=$w;height=$h;bgra=$bitmap.ConvertedWords();guti_sha256=$sha;
      bitmap_format=$format;returned_pixel_format=32;desktop_bits=[OriginalGdiBitmap]::DesktopBits;stretch_mode=$bitmap.StretchMode;
      construction_profile='Source-traced Windows GDI color/device bitmap, R2_COPYPEN, PS_SOLID width1, solid/hollow brush, clWindowText; real DIB24 guti native StretchBlt SRCPAINT';
      native_vcl_verified=$false}
    }catch{$response=@{ok=$false;protocol='chemlab-native-gdi-v1';error=$_.Exception.Message}}
    finally{if($bitmap){$bitmap.Dispose()}}
    $writer.WriteLine(($response|ConvertTo-Json -Depth 10 -Compress))
   }
  }finally{$client.Dispose()}
 }
}finally{$listener.Stop()}
