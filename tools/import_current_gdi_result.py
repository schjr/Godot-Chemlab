"""Validate a real Windows capture against its exact reviewed local package.

No capture generation, GDI emulation, production attestation or network access.
"""
import argparse
import base64
import hashlib
import json
import re
from pathlib import Path

MAX_BYTES = 32 * 1024 * 1024
SHA = re.compile(r"[0-9a-f]{64}\Z")
FORMAT = "chemlab-exact-gdi-capture-v1"

def digest(raw):
    return hashlib.sha256(raw).hexdigest()

def pairs(rows):
    result = {}
    for key, value in rows:
        if key in result:
            raise ValueError("Duplicate JSON key: " + key)
        result[key] = value
    return result

def decode(raw):
    if len(raw) > MAX_BYTES:
        raise ValueError("Capture exceeds size bound")
    return json.loads(raw.decode("utf-8"), object_pairs_hook=pairs,
                      parse_constant=lambda value: (_ for _ in ()).throw(ValueError("Nonfinite JSON")))

def require(condition, message):
    if not condition:
        raise ValueError(message)

def hash_value(value):
    return isinstance(value, str) and SHA.fullmatch(value) is not None

def integer(value):
    return type(value) is int

def validate(raw, package):
    """Return normalized exact lookup data only after all capture checks pass."""
    manifest_raw = (package / "manifest.json").read_bytes()
    manifest = decode(manifest_raw)
    require(manifest.get("format") == "chemlab-current-gdi-package-v1", "Package format differs")
    files = manifest["files"]
    required_names = {"README.md", "current-gdi-cases.json", "guti.bmp", "original_gdi_host.cs",
                      "original_gdi_host.ps1", "run_current_gdi_probes.ps1", "vcl_bitmap_profile.md"}
    require(len(files) == len(required_names) and {r["path"] for r in files} == required_names, "Package file identity differs")
    for row in files:
        content = (package / row["path"]).read_bytes()
        require(hash_value(row["sha256"]) and digest(content) == row["sha256"] and len(content) == row["bytes"], "Package file hash/size differs: " + row["path"])
    corpus_raw = (package / "current-gdi-cases.json").read_bytes()
    corpus = decode(corpus_raw)
    require(corpus.get("format") == "chemlab-current-gdi-cases-v1" and len(corpus["cases"]) == 57, "Reviewed corpus differs")
    result = decode(raw)
    require(result.get("format") == "chemlab-current-gdi-result-v1", "Windows result format differs")
    require(result.get("native_vcl_verified") is False, "Capture cannot assert original VCL verification")
    require(result.get("corpus_sha256") == digest(corpus_raw), "Windows corpus hash differs")
    require(result.get("manifest_sha256") == digest(manifest_raw), "Windows package manifest hash differs")
    require(result.get("package_files") == files, "Windows package file identities differ")
    require(result.get("original_binary_sha256") == corpus["original_binary_sha256"] and hash_value(result["original_binary_sha256"]), "Original executable identity differs")
    require(isinstance(result.get("created_utc"), str) and isinstance(result.get("boundary"), str), "Capture provenance text missing")
    runtime = result.get("runtime")
    require(isinstance(runtime, dict), "Runtime provenance missing")
    for field in ("os_version", "framework", "powershell", "culture"):
        require(isinstance(runtime.get(field), str) and runtime[field], "Runtime provenance missing: " + field)
    require(type(runtime.get("process_64bit")) is bool and type(runtime.get("os_64bit")) is bool, "Runtime architecture missing")
    depth = runtime.get("desktop_bits")
    require(integer(depth) and 1 <= depth <= 128, "Desktop depth invalid")
    dlls = runtime.get("system_dlls")
    require(isinstance(dlls, list) and 2 <= len(dlls) <= 4, "Native DLL provenance missing")
    names = [r["name"] for r in dlls]
    require(len(set(names)) == len(names) and {"gdi32.dll", "user32.dll"}.issubset(names), "Native GDI DLL identity missing")
    require(set(names).issubset({"gdi32.dll", "gdi32full.dll", "win32u.dll", "user32.dll"}), "Unexpected native DLL identity")
    for row in dlls:
        require(hash_value(row.get("sha256")) and isinstance(row.get("version"), str) and row["version"] and isinstance(row.get("path"), str) and row["path"], "Native DLL hash/version/path missing")
    reference = result.get("comparison_reference_sha256")
    require(reference is None or hash_value(reference), "Comparison reference identity malformed")
    rows = result.get("cases")
    require(isinstance(rows, list) and len(rows) == 57, "Incomplete or excessive case set")
    mapped = {}
    for row in rows:
        require(isinstance(row, dict) and isinstance(row.get("id"), str) and row["id"] not in mapped, "Duplicate/malformed case identity")
        mapped[row["id"]] = row
    require(set(mapped) == {c["id"] for c in corpus["cases"]}, "Case identities differ from exact corpus")
    entries = []
    request_pixels = {}
    for case in corpus["cases"]:
        row = mapped[case["id"]]
        for field in ("width", "height", "bitmap_format"):
            require(integer(row.get(field)) and row[field] == case[field], "Case geometry/format differs: " + case["id"])
        require(integer(row.get("returned_pixel_format")) and row["returned_pixel_format"] == 32, "Captured pixel format differs")
        try:
            pixels = base64.b64decode(row["bgra"], validate=True)
        except (KeyError, ValueError, TypeError) as exc:
            raise ValueError("Malformed BGRA payload: " + case["id"]) from exc
        require(len(pixels) == case["width"] * case["height"] * 4, "BGRA dimensions differ")
        require(digest(pixels) == row.get("pixel_sha256"), "BGRA pixel hash differs")
        expected_mode = case["initial_stretch_mode"]
        if any(op["op"] == "texture" for op in case["operations"]):
            expected_mode = 4 if depth < 9 else 3
        require(integer(row.get("stretch_mode")) and row["stretch_mode"] == expected_mode, "Final native stretch state differs")
        counts = [row.get(field) for field in ("comparison_byte_differences", "comparison_rgb_byte_differences", "comparison_reserved_byte_differences")]
        if reference is None:
            require(counts == [None, None, None], "Unexpected comparison counters")
        else:
            require(all(integer(n) and 0 <= n <= len(pixels) for n in counts) and counts[0] == counts[1] + counts[2], "Comparison counters malformed")
        request = {field: case[field] for field in ("width", "height", "bitmap_format", "initial_stretch_mode", "operations")}
        request["initial_bgra"] = case.get("initial_bgra", "")
        key = json.dumps(request, sort_keys=True, separators=(",", ":"))
        require(key not in request_pixels or request_pixels[key] == pixels, "Identical requests produced conflicting native pixels; profile is not stable")
        request_pixels[key] = pixels
        entries.append(dict(id=case["id"], request=request, bgra=row["bgra"], pixel_sha256=row["pixel_sha256"], stretch_mode=row["stretch_mode"], evidence=case["evidence"]))
    return dict(format=FORMAT, native_vcl_verified=False, capture_sha256=digest(raw),
                corpus_sha256=digest(corpus_raw), manifest_sha256=digest(manifest_raw),
                original_binary_sha256=result["original_binary_sha256"], guti_sha256=digest((package / "guti.bmp").read_bytes()),
                provenance=result, entries=entries)

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("result", type=Path)
    parser.add_argument("--package", type=Path, default=Path(__file__).resolve().parents[1] / "build/windows-reference/current-gdi-probes")
    parser.add_argument("--output", required=True, type=Path)
    args = parser.parse_args()
    require(not args.output.exists(), "Output already exists; retain capture history or choose another path")
    imported = validate(args.result.read_bytes(), args.package)
    output = (json.dumps(imported, ensure_ascii=False, separators=(",", ":")) + "\n").encode()
    with args.output.open("xb") as stream:
        stream.write(output)
    print(json.dumps(dict(output=str(args.output.resolve()), imported_sha256=digest(output), cases=len(imported["entries"]), native_vcl_verified=False)))

if __name__ == "__main__":
    main()
