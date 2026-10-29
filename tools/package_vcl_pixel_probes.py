"""Package the bounded, reviewed Windows bitmap and scalar readers."""
from pathlib import Path
import hashlib
import json
import zipfile

ROOT = Path(__file__).resolve().parents[1]
DEST = ROOT / 'build/windows-reference/vcl-pixel-probes.zip'
INPUTS = {
    'run.ps1': ROOT / 'tools/windows/run_vcl_pixel_probes.ps1',
    'read_original_dib_pixels.ps1': ROOT / 'tools/windows/read_original_dib_pixels.ps1',
    'original_dib_read_probe.cs': ROOT / 'tools/windows/original_dib_read_probe.cs',
    'windows_read_original.ps1': ROOT / 'tools/windows_read_original.ps1',
    'run_current_material_probes.ps1': ROOT / 'tools/windows/run_current_material_probes.ps1',
    'original_gdi_host.cs': ROOT / 'tools/windows/original_gdi_host.cs',
    'current-material-gdi-cases.json': ROOT / 'evidence/original_logic/current-material-gdi-cases.json',
}

def main():
    files = {name: path.read_bytes() for name, path in INPUTS.items()}
    files['README.txt'] = (
        'ChemLab local bitmap comparison probes\r\n'
        'Run run.ps1 from an ordinary, already authorized PowerShell process.\r\n'
        'The original app must remain paused, process 9348, with the observed six vessels.\r\n'
        'Reads existing bitmap memory and raw state; renders separate bounded GDI references.\r\n'
        'No policy changes, elevation, target writes/calls, suspension, network or UI input.\r\n'
        'Results: Windows desktop/vcl-pixel-results.zip. Existing output is preserved.\r\n'
        'A bitmap match alone does not certify full VCL/frame parity.\r\n'
    ).encode('utf-8')
    rows = [{'path': name, 'bytes': len(raw), 'sha256': hashlib.sha256(raw).hexdigest()}
            for name, raw in sorted(files.items())]
    files['manifest.json'] = (json.dumps({'format': 'chemlab-vcl-pixel-probes-v1', 'files': rows}, indent=2) + '\n').encode()
    DEST.parent.mkdir(parents=True, exist_ok=True)
    with zipfile.ZipFile(DEST, 'w', zipfile.ZIP_DEFLATED, compresslevel=9) as archive:
        for name, raw in sorted(files.items()):
            info = zipfile.ZipInfo(name, date_time=(2026, 10, 14, 0, 0, 0))
            info.compress_type = zipfile.ZIP_DEFLATED
            archive.writestr(info, raw)
    with zipfile.ZipFile(DEST) as archive:
        assert archive.testzip() is None
        for name, raw in files.items():
            assert archive.read(name) == raw
    print(json.dumps({'archive': str(DEST), 'bytes': DEST.stat().st_size,
                      'sha256': hashlib.sha256(DEST.read_bytes()).hexdigest(), 'files': rows}))

if __name__ == '__main__':
    main()
