"""Join preserved method names to decompiled entries; verify recovery provenance."""
import csv
import hashlib
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

def main():
    manifest = json.loads((ROOT/'evidence/native-inputs.json').read_text())
    summary = []
    for artifact in manifest:
        name = artifact['name']
        directory = ROOT/'recovered/native'/name
        coverage_path = directory/'coverage.json'
        if not coverage_path.exists():
            raise RuntimeError(f'Incomplete native export: {name}')
        coverage = json.loads(coverage_path.read_text())
        if coverage['sha256'] != artifact['sha256'] or coverage['cancelled']:
            raise RuntimeError(f'Native identity/completion mismatch: {name}')
        code = (directory/'decompiled.cpp').read_text()
        bodies = {}
        for part in re.split(r'(?m)^// Entry ',code)[1:]:
            address = part.split(',',1)[0]
            bodies[int(address,16)] = '// Entry '+part
        rows = list(csv.DictReader((directory/'functions.tsv').open(),delimiter='\t'))
        successful = [r for r in rows if r['status']=='decompiled']
        if len(successful)!=coverage['decompiled'] or len(bodies)!=coverage['decompiled'] or len(rows)!=coverage['functions']:
            raise RuntimeError(f'Native export count mismatch: {name}')
        published_coverage = json.loads((directory/'published_coverage.json').read_text())
        if published_coverage['sha256']!=artifact['sha256']:
            raise RuntimeError(f'Published export identity mismatch: {name}')
        published_code = (directory/'published_recovered.cpp').read_text()
        published_bodies = {}
        for part in re.split(r'(?m)^// Entry ',published_code)[1:]:
            address = part.split(',',1)[0]
            published_bodies[int(address,16)] = '// Entry '+part
        published_rows = list(csv.DictReader((directory/'published_recovery.tsv').open(),delimiter='\t'))
        if len(published_bodies)!=published_coverage['decompiled'] or len(published_rows)!=published_coverage['total']:
            raise RuntimeError(f'Published export count mismatch: {name}')
        additional_count = len(set(published_bodies)-set(bodies))
        bodies.update(published_bodies)
        method_map_path = ROOT/'recovered/project/method_maps'/f'{name}.json'
        mappings = []
        if method_map_path.exists():
            metadata = json.loads(method_map_path.read_text())
            if metadata['sha256'] != artifact['sha256']:
                raise RuntimeError(f'Method map identity mismatch: {name}')
            with (directory/'published_handlers.cpp').open('w') as handlers:
                handlers.write('/* Published event names recovered from executable metadata.\n'
                    '   Bodies are Ghidra pseudocode, not original/buildable source.\n'
                    '   Class ownership and original signatures are unresolved. */\n\n')
                for method in metadata['entries']:
                    address = int(method['address'],16)
                    found = address in bodies
                    mappings.append(dict(method_name=method['method_name'],address=method['address'],decompiled=found,evidence=method['evidence']))
                    if found:
                        handlers.write('// Preserved published name: '+method['method_name']+'\n')
                        handlers.write(bodies[address])
                    else:
                        handlers.write('// UNRESOLVED: '+method['method_name']+' at '+method['address']+' has no exported function body.\n\n')
            (directory/'published_methods.json').write_text(json.dumps(mappings,ensure_ascii=False,indent=2)+'\n')
        summary.append(dict(artifact,**coverage,additional_decompiled_method_entries=additional_count,published_methods=len(mappings),published_methods_with_bodies=sum(m['decompiled'] for m in mappings)))
    forms = json.loads((ROOT/'recovered/forms/manifest.json').read_text())
    form_count = 0
    for artifact in forms:
        binary = (ROOT/artifact['input']).read_bytes()
        if hashlib.sha256(binary).hexdigest()!=artifact['sha256']:
            raise RuntimeError('Source binary identity mismatch')
        for form in artifact.get('forms',[]):
            raw = (ROOT/form['binary']).read_bytes()
            start = form['file_offset']
            if raw != binary[start:start+form['resource_size']] or hashlib.sha256(raw).hexdigest()!=form['sha256']:
                raise RuntimeError('Form byte provenance mismatch')
            if form.get('trailing_bytes')!=0:
                raise RuntimeError('Form parse did not cover all bytes')
            form_count += 1
    report = {'native':summary,'forms_verified':form_count,'native_discovered_functions':sum(x['functions'] for x in summary),
              'decompiled_functions':sum(x['decompiled'] for x in summary),'decompilation_failures':sum(x['failed'] for x in summary),
              'additional_decompiled_method_entries':sum(x['additional_decompiled_method_entries'] for x in summary),
              'published_method_names':sum(x['published_methods'] for x in summary),
              'published_method_bodies':sum(x['published_methods_with_bodies'] for x in summary),
              'limitations':['Decompiler output is not original source or compilable code.',
                'Coverage is relative to statically discovered functions; unidentified code remains unknown.',
                'Default Ghidra analysis may infer incomplete boundaries/no-return behavior.',
                'Original comments, local names, C++ headers/project settings and behavioral equivalence are not recovered.']}
    report['unique_decompiled_entries']=report['decompiled_functions']+report['additional_decompiled_method_entries']
    (ROOT/'recovered/coverage.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
    print(json.dumps({k:v for k,v in report.items() if k not in ('native','limitations')}))

if __name__=='__main__': main()
