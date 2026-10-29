"""Package the current original-code work in progress, verifying every file."""
from pathlib import Path
import hashlib
import json
import zipfile

ROOT=Path(__file__).resolve().parents[1]
DEST=ROOT/'build/ChemLab-original-port-WIP-project.zip'
PREFIX='ChemLab-original-port-WIP/'

def main():
    files={}
    for p in (ROOT/'godot').rglob('*'):
        if p.is_file() and '.godot' not in p.parts:
            files[str(p.relative_to(ROOT))]=p
    for name in ['godot_task.py','package_godot.py','prepare_godot.py','build_original_bitmap_rgb_fixture.py','analyze_original_runtime_captures.py','import_current_gdi_result.py','analyze_original_dib_capture.py','analyze_original_particle_capture.py','analyze_original_pen_capture.py','analyze_original_gas_operands.py','build_actual_particle_checkpoint_fixture.py','build_actual_pen_frontier.py','build_actual_pen_owned_locks.py','original_x86_oracle.py','original_gas_stack_oracle.py','original_x87_host.c','windows_read_original.ps1']:
        files['tools/'+name]=ROOT/'tools'/name
    for p in sorted((ROOT/'tools/windows').glob('*')):
        if p.is_file():files[str(p.relative_to(ROOT))]=p
    files['tools/windows/guti.bmp']=ROOT/'artifacts/ChemLab/res/guti.bmp'
    # The bounded graph builders verify and emulate this exact original PE.
    files['artifacts/ChemLab/_main.exe']=ROOT/'artifacts/ChemLab/_main.exe'
    sprite_sources=json.loads((ROOT/'godot/data/sprites.json').read_text())
    for kind in sprite_sources:
        source=sprite_sources[kind]['source']
        files[source]=ROOT/source
    files['README.md']=ROOT/'godot/README.md'
    for p in sorted((ROOT/'evidence/godot').glob('test-*.console.log')):
        files['verification/'+p.name]=p
    for p in sorted((ROOT/'evidence/windows-runtime/original-captures-2026-10-14').glob('*.json')):
        files[str(p.relative_to(ROOT))]=p
    for p in sorted((ROOT/'evidence/windows-runtime/precision-and-graphics-2026-10-14').glob('*')):
        if p.is_file():files[str(p.relative_to(ROOT))]=p
    for p in sorted((ROOT/'evidence/windows-runtime/vcl-pixel-results-2026-10-14').rglob('*')):
        if p.is_file():files[str(p.relative_to(ROOT))]=p
    for p in sorted((ROOT/'evidence/windows-runtime/particle-pool-results-2026-10-14').rglob('*')):
        if p.is_file():files[str(p.relative_to(ROOT))]=p
    for name in ['vcl-pixel-probes.zip','vcl-pixel-results.zip','particle-pool-results.zip']:
        files['build/windows-reference/'+name]=ROOT/'build/windows-reference'/name
    files['evidence/windows-runtime/vcl-module-dedup-reader-revision.json']=ROOT/'evidence/windows-runtime/vcl-module-dedup-reader-revision.json'
    files['evidence/windows-runtime/particle-capture-transfer-2026-10-14.json']=ROOT/'evidence/windows-runtime/particle-capture-transfer-2026-10-14.json'
    files['evidence/windows-runtime/pen-capture-transfer-2026-10-14.json']=ROOT/'evidence/windows-runtime/pen-capture-transfer-2026-10-14.json'
    files['evidence/windows-runtime/gas-operand-transfer-2026-10-15.json']=ROOT/'evidence/windows-runtime/gas-operand-transfer-2026-10-15.json'
    for pattern in ['original-critical-*.json','original_heap_lock*.json','actual-pen-*.json','owned-critical-*.json']:
        for p in sorted((ROOT/'evidence').glob(pattern)):
            files[str(p.relative_to(ROOT))]=p
    # A still-pending returned archive is never silently represented as present.
    for directory in ['vcl-pen-results-2026-10-14','gas-operand-results-2026-10-15']:
        for p in sorted((ROOT/'evidence/windows-runtime'/directory).rglob('*')):
            if p.is_file():files[str(p.relative_to(ROOT))]=p
    for name in ['vcl-pen-results.zip','gas-operand-results.zip']:
        p=ROOT/'build/windows-reference'/name
        if p.is_file():files[str(p.relative_to(ROOT))]=p
    # Native-reference fixtures outside the Godot resource tree are required
    # by the shipped tests; retain their original relative paths.
    for p in sorted((ROOT/'evidence/original_logic').glob('*')):
        if p.is_file() and p.suffix in {'.json','.asm'}:files[str(p.relative_to(ROOT))]=p
    for p in sorted((ROOT/'evidence/godot').glob('actual-windows-*.log')):
        files['verification/'+p.name]=p
    for p in sorted((ROOT/'evidence/godot').glob('gas-run-order-*.log')):
        files['verification/'+p.name]=p
    for p in sorted((ROOT/'evidence/godot').glob('gas-run-pen-fresh-*.log')):
        files['verification/'+p.name]=p
    for p in sorted((ROOT/'evidence/godot').glob('vcl-state-*.log')):
        files['verification/'+p.name]=p
    for pattern in ['bitmap-*.log','bitmap-*.json','bitmap-*.png','opening-live-*.log','opening-live-*.png','runtime-allocation-production-*.log','opening-native-reference-*.log','final-runtime-*.log','live-runtime-suite-*.log','live-workflow-validation-*.json','pointer-ui-*.log','pointer-ui-validation-*.json','dropper-controls-2026-10-18.png','dropper-context-2026-10-18.png']:
        for p in sorted((ROOT/'evidence/godot').glob(pattern)):
            files['verification/'+p.name]=p
    for p in sorted((ROOT/'evidence/godot').glob('source-package-validation-*.json')):
        files['verification/'+p.name]=p
    rows=[{'path':name,'bytes':p.stat().st_size,'sha256':hashlib.sha256(p.read_bytes()).hexdigest()} for name,p in sorted(files.items())]
    data=json.dumps({'files':rows,'godot_version':'4.7.1','source_project':'godot/project.godot',
                    'status':'work_in_progress','version':'0.1.3',
                    'boundary':'Original bitmap RGB preserved through Godot import and export for107 source BMPs/300769 pixels; running canvas background/overlap and visible opening workflow verified. Original allocator-backed production storage and retained owned stack, live startup RNG and source particle instructions with numerical feedback. All28 documents pass normal import/Run/two-model-frame checks; opening experiment completes normal viewport dropper, chemistry, continuous pouring and Stop/Run workflow. Native seven-action/63-tick arithmetic comparison remains exact. All28 complete workflows and universal Windows GDI curve-edge equivalence remain unverified.'},ensure_ascii=False,indent=2)+'\n'
    with zipfile.ZipFile(DEST,'w',zipfile.ZIP_DEFLATED,compresslevel=9) as archive:
        for name,p in sorted(files.items()):
            info=zipfile.ZipInfo(PREFIX+name,date_time=(2026,10,19,0,0,0));info.compress_type=zipfile.ZIP_DEFLATED;info.external_attr=(0o100755 if p.stat().st_mode & 0o111 else 0o100644)<<16
            archive.writestr(info,p.read_bytes())
        archive.writestr(PREFIX+'manifest.json',data)
    with zipfile.ZipFile(DEST) as archive:
        if archive.testzip() is not None:raise RuntimeError('Corrupt project archive')
        for row in rows:
            if hashlib.sha256(archive.read(PREFIX+row['path'])).hexdigest()!=row['sha256']:raise RuntimeError('Packaged file mismatch')
    result={'archive':str(DEST),'files':len(files)+1,'bytes':DEST.stat().st_size,'sha256':hashlib.sha256(DEST.read_bytes()).hexdigest(),'verified':True}
    (ROOT/'build/original-port-WIP-source-package.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps(result))

if __name__=='__main__':main()
