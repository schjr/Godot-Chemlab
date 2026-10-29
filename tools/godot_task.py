"""Run Godot tasks with a writable-data preflight to avoid its startup crash.

Use: uv run --no-project tools/godot_task.py import|run|test|export
"""
from pathlib import Path
import argparse
import json
import os
import re
import shutil
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[1]
PROJECT=ROOT/'godot'
EXTERNAL_TEST_INPUTS={
    'test_original_gdi_capture_actual.gd': ('CHEMLAB_GDI_IMPORT_PATH','CHEMLAB_GDI_IMPORT_SHA256'),
    'test_original_dib_capture_actual.gd': ('CHEMLAB_DIB_INPUT_PATH','CHEMLAB_DIB_INPUT_SHA256'),
}
RECORDED_GDI_PATH=ROOT/'evidence/windows-runtime/precision-and-graphics-2026-10-14/exact-gdi-capture.json'
RECORDED_GDI_SHA256='8d1a8be837781fea222af5f64aa8aae9cfea0a33414a25ba0cec06c87dc46e2e'
RECORDED_DIB_PATH=ROOT/'evidence/windows-runtime/vcl-pixel-results-2026-10-14/comparison-input.json'
RECORDED_DIB_SHA256='581645423211d700eaedee8d9311b2af56fb478fdd3dafad68d21cd3d725b58a'

def configure_recorded_test_inputs():
    """Use this verified capture when no explicit external profile was supplied."""
    keys=EXTERNAL_TEST_INPUTS['test_original_gdi_capture_actual.gd']
    if not any(os.environ.get(key) for key in keys) and RECORDED_GDI_PATH.is_file():
        os.environ[keys[0]]=str(RECORDED_GDI_PATH)
        os.environ[keys[1]]=RECORDED_GDI_SHA256
    keys=EXTERNAL_TEST_INPUTS['test_original_dib_capture_actual.gd']
    if not any(os.environ.get(key) for key in keys) and RECORDED_DIB_PATH.is_file():
        os.environ[keys[0]]=str(RECORDED_DIB_PATH)
        os.environ[keys[1]]=RECORDED_DIB_SHA256

def selected_tests():
    """Separate missing runtime evidence from completed local checks."""
    selected=[]
    for path in sorted((PROJECT/'tests').glob('*test*.gd')):
        if path.name=='test_ui.gd':continue
        requirements=EXTERNAL_TEST_INPUTS.get(path.name,())
        supplied=[bool(os.environ.get(key)) for key in requirements]
        if requirements and not any(supplied):
            print(f'PENDING external runtime comparison: {path.name} (requires {", ".join(requirements)})')
            continue
        # A partial configuration executes the check and reports its input
        # error. It must not silently become a successful skipped check.
        selected.append(path)
    return selected

def native_summary(output):
    """Accept explicit oracle results, never a successful process exit alone."""
    for line in output.splitlines():
        try: result=json.loads(line)
        except (ValueError,TypeError): continue
        if not isinstance(result,dict): continue
        error_keys=[key for key in result if any(token in key for token in ('mismatches','failures','unresolved'))]
        counts={key:value for key,value in result.items() if isinstance(value,int) and not isinstance(value,bool) and value>0 and any(token in key for token in ('cases','checks','frames','tested','actions'))}
        if error_keys and counts and all(result[key]==[] for key in error_keys):
            return ', '.join(f'{key}={value}' for key,value in counts.items())
    return None

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('task',choices=['import','run','test','export'])
    parser.add_argument('--engine',default=os.environ.get('CHEMLAB_GODOT','/Applications/Godot.app/Contents/MacOS/Godot'))
    args=parser.parse_args()
    if args.task=='test':configure_recorded_test_inputs()
    engine=Path(args.engine)
    if not engine.exists():
        located=shutil.which(args.engine) or shutil.which('godot') or shutil.which('godot4')
        if not located:parser.error('Godot 4 is required; set CHEMLAB_GODOT to its executable.')
        engine=Path(located)
    project_text=(PROJECT/'project.godot').read_text()
    project_name=re.search(r'^config/name="(.*)"$',project_text,re.M).group(1)
    if sys.platform=='darwin': base=Path.home()/'Library/Application Support'
    elif sys.platform=='win32':base=Path(os.environ.get('APPDATA',str(Path.home()/'AppData/Roaming')))
    else:base=Path(os.environ.get('XDG_DATA_HOME',str(Path.home()/'.local/share')))
    data=base/'Godot/app_userdata'/project_name
    try:
        data.mkdir(parents=True,exist_ok=True)
        probe=data/'.chemlab-write-check'
        probe.write_text('preflight');probe.unlink()
    except OSError as error:
        print('Godot was not started: its user-data folder is not writable.',file=sys.stderr)
        print(f'Folder: {data}\nRun this task from a normal terminal or grant the runner access to this folder. ({error})',file=sys.stderr)
        return 75
    (ROOT/'evidence/godot').mkdir(parents=True,exist_ok=True)
    base_cmd=[str(engine),'--path',str(PROJECT),'--log-file',str(ROOT/'evidence/godot'/f'{args.task}.log')]
    if args.task=='import':commands=[base_cmd+['--headless','--editor','--import']]
    elif args.task=='run':commands=[base_cmd]
    elif args.task=='test':commands=[base_cmd+['--headless','--script','res://tests/'+p.name,'--quit-after','1200','--','--testing'] for p in selected_tests()]
    else:
        (ROOT/'build').mkdir(exist_ok=True)
        commands=[base_cmd+['--headless','--export-release',preset] for preset in ['macOS','Windows Desktop']]
    for command in commands:
        result=subprocess.run(command,cwd=ROOT,text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
        log_path=ROOT/'evidence/godot'/(args.task+'-'+str(commands.index(command))+'.console.log')
        log_path.write_text(result.stdout)
        if result.returncode or any(marker in result.stdout for marker in ['SCRIPT ERROR:', 'Parse Error:', 'Compile Error:', 'ERROR:']):
            print(result.stdout)
            return result.returncode or 1
        oracle_result=native_summary(result.stdout)
        if args.task=='test' and 'PASS' not in result.stdout and 'VALIDATION:' not in result.stdout and oracle_result is None:
            print(result.stdout)
            print('Validation did not reach its success marker.',file=sys.stderr)
            return 1
        concise=[line for line in result.stdout.splitlines() if 'PASS' in line or 'checks:' in line or 'VALIDATION:' in line]
        print('\n'.join(concise) if concise else f'PASS native oracle: {oracle_result}' if oracle_result else f'{args.task}: complete')
    return 0

if __name__=='__main__':raise SystemExit(main())
