param([switch]$Verify,[string]$Output)
# Own-object Win32 verifier or newline JSON protocol; no target process is opened.
$ErrorActionPreference='Stop'
if($env:OS -ne 'Windows_NT'){throw 'Actual Win32 critical sections require Windows; no substitute backend'}
$source=Join-Path $PSScriptRoot 'original_owned_critical_sections.cs'
Add-Type -TypeDefinition (Get-Content -Raw -Encoding UTF8 $source)
$sourceHash=(Get-FileHash -Algorithm SHA256 $source).Hash.ToLowerInvariant()
if($Verify){
 $report=[OriginalOwnedCriticalSections]::Verify()
 $report['backend_source_sha256']=$sourceHash
 $report['windows_version']=[Environment]::OSVersion.VersionString
 $report['process_pointer_size']=[IntPtr]::Size
 $json=$report|ConvertTo-Json -Depth 20
 if($Output){if(Test-Path -LiteralPath $Output){throw 'Preserve existing verification result; output exists'};[IO.File]::WriteAllText($Output,$json,[Text.UTF8Encoding]::new($false))}
 $json
 exit
}
$hostState=[OriginalOwnedCriticalSections]::new()
try {
 while(($line=[Console]::ReadLine()) -ne $null){
  try {
   if($line.Length -gt 16384){throw 'Own-lock request exceeds bounded protocol'}
   $request=$line|ConvertFrom-Json
   if($request.protocol -ne 'chemlab-owned-win32-critical-sections-v1'){throw 'Unknown own-lock protocol'}
   $reply=$null
   switch([string]$request.op){
    'create' {$reply=$hostState.Create([string]$request.scope,[string]$request.source_identity)}
    'begin' {$reply=@{ok=$true;ticket=$hostState.Begin([string]$request.key,[string]$request.actor,[string]$request.api);complete=$false}}
    'poll' {$reply=$hostState.Poll([long]$request.ticket,[int]$request.wait_ms)}
    'delete' {$reply=$hostState.Delete([string]$request.key)}
    default {throw 'Unported own-lock protocol operation'}
   }
   $reply['protocol']='chemlab-owned-win32-critical-sections-v1'
   $reply['backend_source_sha256']=$sourceHash
   $reply['native_vcl_verified']=$false
   $reply['target_calls']=$false
  }catch{$reply=@{ok=$false;protocol='chemlab-owned-win32-critical-sections-v1';error=$_.Exception.Message;native_vcl_verified=$false}}
  [Console]::WriteLine(($reply|ConvertTo-Json -Depth 12 -Compress))
 }
}finally {
 # Held/queued locks deliberately refuse disposal: no cross-thread forced Leave.
 $hostState.Dispose()
}
