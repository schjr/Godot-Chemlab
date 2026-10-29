"""Package recovered material with a deterministic file inventory and checksums."""
from pathlib import Path
import hashlib
import json
import zipfile

ROOT = Path(__file__).resolve().parents[1]
DEST = ROOT/'ChemLab-recovered-source.zip'

def main():
    files = [ROOT/'README.md']
    for directory in ('recovered','tools','evidence'):
        for path in (ROOT/directory).rglob('*'):
            if not path.is_file() or '__pycache__' in path.parts or 'native-inputs' in path.parts:
                continue
            if path.suffix in {'.pyc','.class'} or path.name=='package-manifest.json':
                continue
            files.append(path)
    files.sort(key=lambda p:str(p.relative_to(ROOT)))
    manifest = [{'path':str(p.relative_to(ROOT)),'bytes':p.stat().st_size,
                 'sha256':hashlib.sha256(p.read_bytes()).hexdigest()} for p in files]
    manifest_path = ROOT/'recovered/package-manifest.json'
    manifest_path.write_text(json.dumps(manifest,ensure_ascii=False,indent=2)+'\n')
    files.append(manifest_path)
    with zipfile.ZipFile(DEST,'w',zipfile.ZIP_DEFLATED,compresslevel=9) as archive:
        for path in files:
            info=zipfile.ZipInfo(str(path.relative_to(ROOT)),date_time=(2026,10,13,0,0,0))
            info.compress_type=zipfile.ZIP_DEFLATED
            info.external_attr=0o100644 << 16
            archive.writestr(info,path.read_bytes())
    with zipfile.ZipFile(DEST) as archive:
        if archive.testzip() is not None:
            raise RuntimeError('ZIP CRC verification failed')
        for row in manifest:
            data=archive.read(row['path'])
            if len(data)!=row['bytes'] or hashlib.sha256(data).hexdigest()!=row['sha256']:
                raise RuntimeError('Packaged file identity mismatch')
    print(json.dumps({'archive':str(DEST),'files':len(files),'bytes':DEST.stat().st_size,
                     'sha256':hashlib.sha256(DEST.read_bytes()).hexdigest(),'verified':True}))

if __name__=='__main__':main()
