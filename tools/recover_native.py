"""Export discovered functions of every unique packaged PE without target execution."""
from pathlib import Path
import concurrent.futures
import hashlib
import json
import os
import shutil
import subprocess
import argparse

ROOT = Path(__file__).resolve().parents[1]
GHIDRA = Path(os.environ.get('CHEMLAB_GHIDRA', '/Users/schjr/Applications/ghidra_12.1.4_PUBLIC'))
JDK = os.environ.get('CHEMLAB_JAVA_HOME', '/Users/schjr/Library/Java/JavaVirtualMachines/jdk-21.0.12.1+1/Contents/Home')

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--published', action='store_true', help='Supplement default discovery with preserved method entry points')
    parser.add_argument('--select', help='Recover a single canonical binary name')
    parser.add_argument('--force', action='store_true', help='Regenerate completed exports')
    parser.add_argument('--seed-published', action='store_true', help='Seed metadata entry points before automatic analysis')
    args = parser.parse_args()
    source = ROOT / 'artifacts/ChemLab'
    staging = ROOT / 'evidence/native-inputs'
    staging.mkdir(parents=True, exist_ok=True)
    groups = {}
    for p in sorted(source.rglob('*')):
        if p.is_file() and p.suffix.lower() in {'.exe', '.obj'} and p.read_bytes()[:2] == b'MZ':
            digest = hashlib.sha256(p.read_bytes()).hexdigest()
            groups.setdefault(digest, []).append(p)
    labels = {'_main.exe':'main', '_mol.exe':'molecule', '_ency.exe':'encyclopedia', 'avi.exe':'avi', 'gif.exe':'gif'}
    jobs = []
    manifest = []
    for digest, paths in groups.items():
        label = next((labels[p.name] for p in paths if p.name in labels), 'resource_' + digest[:8])
        staged = staging / (label + '.exe')
        shutil.copyfile(paths[0], staged)
        row = {'name':label, 'sha256':digest, 'paths':[str(p.relative_to(source)) for p in paths]}
        manifest.append(row)
        jobs.append((row, staged))
    if args.select:
        jobs = [job for job in jobs if job[0]['name']==args.select]
        if not jobs:
            parser.error('Unknown binary name')
    (ROOT/'evidence/native-inputs.json').write_text(json.dumps(manifest, ensure_ascii=False, indent=2))
    with concurrent.futures.ThreadPoolExecutor(max_workers=2) as pool:
        results = list(pool.map(lambda job: run(job,args.published,args.force,args.seed_published), jobs))
    suffix = ('-'+args.select if args.select else '')+('-seeded' if args.seed_published else '')
    (ROOT/'evidence'/(('published-runs' if args.published else 'native-runs')+suffix+'.json')).write_text(json.dumps(results, indent=2))
    return 0 if all(r['exit_code']==0 for r in results) else 1

def run(job,published=False,force=False,seed=False):
    row, staged = job
    label = row['name']
    out = ROOT/'recovered/native'/label
    if not force and (out/('published_coverage.json' if published else 'coverage.json')).exists():
        return {'name':label, 'exit_code':0, 'reused':True}
    project_dir = Path('/private/tmp/chemlab-ghidra-project')/(label+('-published' if published else ''))
    project_dir.mkdir(parents=True, exist_ok=True)
    env = dict(os.environ, JAVA_HOME=JDK, XDG_CONFIG_HOME='/private/tmp/chemlab-ghidra-config', XDG_CACHE_HOME='/private/tmp/chemlab-ghidra-cache', GHIDRA_HEADLESS_MAXMEM='2G')
    script_args = ['RecoverPublished.java',str(ROOT/'recovered/project/method_maps'/f'{label}.tsv'),str(out)] if published else ['RecoverSource.java',str(out)]
    cmd = [str(GHIDRA/'support/analyzeHeadless'),str(project_dir),'recovery','-import',str(staged),'-scriptPath',str(ROOT/'tools/ghidra'),'-postScript',*script_args,'-deleteProject']
    if seed:
        cmd += ['-preScript','SeedPublished.java',str(ROOT/'recovered/project/method_maps'/f'{label}.tsv')]
    log_name = f'{label}'+('-published' if published else '')+'-ghidra.log'
    with (ROOT/'evidence'/log_name).open('w') as log:
        result = subprocess.run(cmd, env=env, stdout=log, stderr=subprocess.STDOUT)
    print(label, 'finished', result.returncode, flush=True)
    return {'name':label, 'exit_code':result.returncode, 'log':f'evidence/{log_name}'}

if __name__ == '__main__':
    raise SystemExit(main())
