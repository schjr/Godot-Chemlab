param([ValidateRange(1,2147483647)][int]$ProcessId=9348)
# Reviewed local captures only. Uses existing process privileges and policy.
Set-StrictMode -Version Latest
$ErrorActionPreference='Stop'
$manifest=Get-Content -Raw -Encoding UTF8 (Join-Path $PSScriptRoot 'manifest.json')|ConvertFrom-Json
foreach($entry in $manifest.files){
 $path=Join-Path $PSScriptRoot $entry.path
 if((Get-FileHash -Algorithm SHA256 $path).Hash.ToLowerInvariant() -ne $entry.sha256){throw ('Reviewed package file differs: '+$entry.path)}
}
$output=Join-Path $env:TEMP 'CodexVclPixelResults'
$archive=Join-Path ([Environment]::GetFolderPath('Desktop')) 'vcl-pixel-results.zip'
if((Test-Path $output) -or (Test-Path $archive)){throw 'Previous evidence exists; choose a fresh output before rerunning'}
[void](New-Item -ItemType Directory -Path $output)
$shell=Join-Path $PSHOME 'powershell.exe'
function Child([string]$script,[string[]]$arguments){
 & $shell -NoProfile -File (Join-Path $PSScriptRoot $script) @arguments
 if($LASTEXITCODE -ne 0){throw ('Capture failed: '+$script+'; partial evidence preserved at '+$output)}
}
Child 'read_original_dib_pixels.ps1' @('-ProcessId',"$ProcessId",'-Output',(Join-Path $output 'original-dib-pixels.json'))
Child 'windows_read_original.ps1' @('-ProcessId',"$ProcessId",'-IncludeAmounts','-RequireNotAdvancing','-KnownControlWordGlobalVa','0x5755e8','-Label','dib-material-state','-OutputPath',(Join-Path $output 'dib-material-state.json'))
Child 'run_current_material_probes.ps1' @('-Corpus',(Join-Path $PSScriptRoot 'current-material-gdi-cases.json'),'-ExpectedCorpusSha256','7b88f23ceef19829e576326d804a87b31f9eec2ddf32962cb8774ba1cc64dd8b','-ExpectedGdiSourceSha256','621b369d85290f10ee0b0333709f10c8e651593dd7a04194232886dedefde466','-Output',(Join-Path $output 'current-material-gdi-result.json'))
# No target state is changed. Cross-capture validation continues on the Mac.
Copy-Item (Join-Path $PSScriptRoot 'manifest.json') (Join-Path $output 'input-manifest.json')
$files=@(Get-ChildItem -File $output)
$rows=@($files|ForEach-Object {@{path=$_.Name;bytes=$_.Length;sha256=(Get-FileHash -Algorithm SHA256 $_.FullName).Hash.ToLowerInvariant()}})
[IO.File]::WriteAllText((Join-Path $output 'result-manifest.json'),(@{files=$rows;process_id=$ProcessId;no_policy_or_privilege_change=$true}|ConvertTo-Json -Depth 10),[Text.UTF8Encoding]::new($false))
Compress-Archive -Path (Join-Path $output '*.json') -DestinationPath $archive
Write-Output ('Results saved to '+$archive)
Get-FileHash -Algorithm SHA256 $archive
