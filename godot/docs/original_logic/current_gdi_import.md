# Exact Windows capture import and replay

The 57-case Windows output was transferred, validated and replayed on October 14, 2026. The retained imported file is `evidence/windows-runtime/precision-and-graphics-2026-10-14/exact-gdi-capture.json`, SHA256 `8d1a8be837781fea222af5f64aa8aae9cfea0a33414a25ba0cec06c87dc46e2e`. All 57 requests pass with exact recorded pixel bytes and without Godot script errors. The console evidence is `evidence/godot/actual-windows-gdi-2026-10-14.console.log`. `godot_task.py test` supplies this pinned capture when present and no external override is configured. VCL/full-frame validation remains pending.

Another returned output can be validated on macOS with:

```sh
UV_CACHE_DIR=/private/tmp/chemlab-uv-cache uv run --no-project python tools/import_current_gdi_result.py /path/current-gdi-result.json --output /path/exact-gdi-capture.json
```

The default expected package is `build/windows-reference/current-gdi-probes`.
If the guest's reviewed manifest was reserialized or its README changed,
retain that precise reviewed package in another directory and pass `--package`.
The importer rejects a mismatching manifest; do not change expected hashes
merely to make an unexplained result pass. Imported files never overwrite
existing files. The printed imported-file SHA256 must be retained with the
capture. The importer checks every package file, executable/corpus identity,
unique complete case set, geometry, formats, raw payload size/hash, final DC
stretch state, comparison counters and Windows/DLL provenance. Duplicate JSON
keys, NaN, changed package inputs and asserted VCL verification are errors.

Godot integration through the actual existing bridge:

```gdscript
var capture = preload("res://scripts/original/original_gdi_capture_provider.gd").new()
var loaded = capture.load_capture(capture_path, trusted_import_file_sha256)
if not loaded.ok: return loaded
gdi.use_capture_provider(capture)
var pixels = await gdi.render_ops(w, h, ops, initial_words, true, bitmap_format, stretch_mode)
```

This explicit capture-only route compares the **entire request**: operation
order and all fields/colors, geometry, initial BGRA words, bitmap format and
initial stretch mode. An unmatched request returns an error. No network,
approximation, color substitution, different initial background, neighboring
mask or automatic fallback is used. Exact output words retain the reserved
byte; the Godot Image presents opaque RGB separately. Production requests
remain rejected because the GDI capture alone does not verify original live
VCL allocations/DC state.

The solid pre-tint stencil/texture captures can serve identical recorded
requests through this route. The four Arc references have synthetic initial
pixels and **cannot** substitute for an Arc drawn on arbitrary tinted solid
pixels. Similarly a surface outline recorded on a white bitmap cannot be
replayed on a current liquid bitmap. Matching coordinates alone is insufficient.
Generic bridge `render_solid` therefore remains incomplete whenever its tinted
Arc request is absent. Complete production integration requires either actual
matching full-stage captures or a verified native GDI primitive provider and
separate original VCL profile evidence. No model/canvas wiring was changed.
The earlier material-mask atlas uses a geometry key and a separate VCL-verified
flag. This import does not populate or promote that atlas: a full BGRA primitive
capture is not automatically an initial-pixel-independent coverage mask, and
the probe result cannot satisfy its VCL verification gate.

Preflight guard tests exercise rejection only and do not claim pixel success.
After importing real data, run the dedicated actual replay test using the
printed SHA256:

```sh
CHEMLAB_GDI_IMPORT_PATH=/path/exact-gdi-capture.json CHEMLAB_GDI_IMPORT_SHA256=printed_sha256 /Applications/Godot.app/Contents/MacOS/Godot --headless --path godot --log-file /private/tmp/chemlab-gdi-capture-actual.log --script res://tests/test_original_gdi_capture_actual.gd
```

Without actual capture inputs it exits2 and prints PENDING, never PASS.
Matching replay verifies lookup and preservation of the recorded native pixels,
not a new independent renderer comparison or complete original-frame parity.
