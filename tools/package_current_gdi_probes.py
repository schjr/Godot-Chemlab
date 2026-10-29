"""Reproducible, offline packaging only; run with uv run --no-project python."""
import base64
import hashlib
import json
from pathlib import Path
import shutil
import zipfile

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / "build/windows-reference/current-gdi-probes"
OUT.mkdir(parents=True, exist_ok=True)

def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()

solid_path = ROOT / "evidence/original_logic/native-solid-visual-oracle.json"
surface_path = ROOT / "evidence/original_logic/native-surface-oracle.json"
solid = json.loads(solid_path.read_text())
surface = json.loads(surface_path.read_text())
assert solid["binary_sha256"] == surface["binary_sha256"]
cases = []

def add(name, width, height, fmt, ops, evidence, initial=None, mode=1):
    row = dict(id=name, width=width, height=height, bitmap_format=fmt,
               initial_stretch_mode=mode, operations=ops, evidence=evidence)
    if initial is not None:
        row["initial_bgra"] = base64.b64encode(initial).decode()
    cases.append(row)

groups = {}
for row in solid["cases"]:
    groups.setdefault((row["type"], row["subtype"], row["width"], row["height"]), []).append(row)
for key, rows in groups.items():
    for which, row in (("first", rows[0]), ("last", rows[-1])):
        # Exact recorded native operations preceding arithmetic tint/composition.
        ops = []
        for op in row["native_operations"]:
            if op["op"] == "tint_nonwhite":
                break
            assert op["op"] in ("transparent", "rectangle", "ellipse", "texture")
            ops.append(op)
        add(f"solid-{key[0]}-{key[1]}-{key[2]}x{key[3]}-{which}", row["width"], row["height"], 0, ops,
            {"kind": "original_instruction_record", "function": "004744DC", "fixture": str(solid_path.relative_to(ROOT)), "case": row["name"], "stage": "stencil and texture only; tint/composition excluded"})
# Arc primitives use exact captured bounds/color, but a declared synthetic background.
for row in solid["cases"]:
    arcs = [op for op in row["native_operations"] if op["op"] == "arc"]
    if not arcs:
        continue
    if len([c for c in cases if c["id"].startswith("arc-")]) >= 4:
        break
    op = dict(arcs[0], brush_color=0, brush_style=0)
    initial = bytes([0x31, 0x72, 0xB4, 0xA5]) * (row["width"] * row["height"])
    add("arc-" + row["name"], row["width"], row["height"], 32, [op],
        {"kind": "original_primitive_synthetic_initial_pixels", "function": "004744DC", "fixture": str(solid_path.relative_to(ROOT)), "case": row["name"], "stage": "Arc only; background is not native tint output"}, initial)
seen = set()
for index, row in enumerate(surface["cases"]):
    if not row["native_operations"]:
        continue
    op = row["native_operations"][0]
    key = (op["top"], op["pen_color"])
    if key in seen:
        continue
    seen.add(key)
    add(f"surface-{index}", row["width"], row["height"], 24, row["native_operations"],
        {"kind": "original_instruction_record", "function": "00473E6C", "fixture": str(surface_path.relative_to(ROOT)), "case_index": index})
    if len(seen) == 8:
        break
for fmt in (0, 24, 32):
    evidence = {"kind": "synthetic_boundary_case", "source_contract": "004E8610/004EA36C bitmap conversion;004E43C8/4588 primitives", "purpose": "format conversion and reserved-byte observation"}
    add(f"format-{fmt}-empty", 13, 11, fmt, [], evidence)
    add(f"format-{fmt}-initial", 13, 11, fmt, [], evidence, bytes([0x31, 0x72, 0xB4, 0xA5]) * 143)
    ops = [dict(op="rectangle", left=-2, top=2, right=9, bottom=14, pen_color=0x183957, brush_color=0x7FA3C9, brush_style=0),
           dict(op="ellipse", left=5, top=-3, right=16, bottom=8, pen_color=0xABCDEF, brush_color=0x224466, brush_style=1),
           dict(op="rectangle", left=4, top=4, right=4, bottom=7, pen_color=0, brush_color=0, brush_style=0)]
    add(f"format-{fmt}-clipped-empty-hollow", 13, 11, fmt, ops, evidence)
src = bytes(sum(([x * 31, y * 47, (x + y) * 19, 0xA5] for y in range(4) for x in range(5)), []))
for mode in (1, 3):
    for rop in (0xCC0020, 0xEE0086):
        op = dict(op="copy_rect", source_width=5, source_height=4, source_bgra=base64.b64encode(src).decode(),
                  left=-1, top=1, right=12, bottom=10, source_left=0, source_top=0, source_right=5, source_bottom=4, copy_mode=rop)
        add(f"copy-{mode}-{rop:x}", 13, 11, 32, [op],
            {"kind": "synthetic_boundary_case", "source_contract": "004E4420 inherits DC stretch mode; StretchBlt SRCCOPY/SRCPAINT", "purpose": "scaled/clipped pixel references, not original app coordinates"}, bytes([0x10, 0x20, 0x40, 0x5A]) * 143, mode)
assert len(cases) <= 96
corpus = dict(format="chemlab-current-gdi-cases-v1", original_binary_sha256=solid["binary_sha256"],
              source_fixtures=[dict(path=str(p.relative_to(ROOT)), sha256=sha(p)) for p in (solid_path, surface_path)], cases=cases)
(OUT / "current-gdi-cases.json").write_text(json.dumps(corpus, ensure_ascii=False, indent=2) + "\n")
for filename in ("original_gdi_host.cs", "original_gdi_host.ps1", "run_current_gdi_probes.ps1"):
    shutil.copyfile(ROOT / "tools/windows" / filename, OUT / filename)
shutil.copyfile(ROOT / "artifacts/ChemLab/res/guti.bmp", OUT / "guti.bmp")
shutil.copyfile(ROOT / "godot/docs/original_logic/current_gdi_probes.md", OUT / "README.md")
shutil.copyfile(ROOT / "godot/docs/original_logic/vcl_bitmap_profile.md", OUT / "vcl_bitmap_profile.md")
bundle_names = ("README.md", "current-gdi-cases.json", "guti.bmp", "original_gdi_host.cs",
                "original_gdi_host.ps1", "run_current_gdi_probes.ps1", "vcl_bitmap_profile.md")
files = [dict(path=name, sha256=sha(OUT / name), bytes=(OUT / name).stat().st_size) for name in bundle_names]
(OUT / "manifest.json").write_text(json.dumps(dict(format="chemlab-current-gdi-package-v1", files=files), indent=2) + "\n")
archive = OUT.with_suffix(".zip")
with zipfile.ZipFile(archive, "w", zipfile.ZIP_DEFLATED) as z:
    for name in sorted((*bundle_names, "manifest.json")):
        info = zipfile.ZipInfo(name, (2026, 1, 1, 0, 0, 0))
        info.compress_type = zipfile.ZIP_DEFLATED
        z.writestr(info, (OUT / name).read_bytes())
print(json.dumps(dict(archive=str(archive), cases=len(cases), bytes=archive.stat().st_size, sha256=sha(archive))))
