# Current six-vessel material comparison references

`current-material-gdi-cases.json` is generated from the observed six vessels in
`evidence/windows-runtime/precision-and-graphics-2026-10-14/full80-naoh.json`.
Its input SHA256 is9f6793c5f8729e0dc99ae35de1446230c07f45c7c6c7e1b35c154c3b99b99887.
The case generator executes retained original471650(liquid),47692C(gas),
473E6C(surface when liquid height>1) and4744DC(settled solid) instructions.
Only VCL dimensions/properties/primitive calls are recorded boundaries.
It installs the exact observed100-cell moles,mass,volume,+3CD8,+3FF8 arrays,
including inactive cells, **after** setup so a recalculation does not replace
the observed caches. Native case outputs preserve raw double height/volume
bits and full ordered primitive colors and coordinates.

All observed active settled/suspended-pending rows and+4318,+3CC8,+4338
are zero. The actual settled helper produces no draw operations in all six
cases. The prior scalar reader did not capture+3CC0: pool-gas delta0 is
explicitly labelled an unobserved hypothesis, not a measurement. Retained
particle objects/layers are also absent. These references therefore omit
particle layers, running overlays, plain apparatus SRCPAINT and fill blending.
They are **uncomposed material references**, not full vessel+FC pixel claims.

Capacity/orientation are derived from the original opening CEM's native
fields; dimensions are read from original BMP headers and checked against
the recovered sprite catalog: sb20053x58,xkp30x52,jtdg_2 15x76, repeated for
the second chemistry group. Those identities and source hashes are recorded
in each case. The current Cu live DIB53x58 agrees; the new live DIB/scalar
capture must verify remaining formats/dimensions/capacity/orientation and
the omitted-state conditions before comparing complete original output.

Place these together in the parent's reviewed transfer package:

- `current-material-gdi-cases.json`
- `run_current_material_probes.ps1`
- the current `original_gdi_host.cs`
- `read_original_dib_pixels.ps1` and`original_dib_read_probe.cs`
- the parent's updated scalar reader

Run each script in a fresh ordinary PowerShell process using existing
execution policy/privileges. The material runner makes no process access,
target calls/writes, network connection, GUI input, policy change or elevation.
It pins the reviewed corpus and C# hashes and accepts only the six bounded
color32 Rectangle recipes (solid/hollow brush). Example:

```powershell
powershell -NoProfile -File .\run_current_material_probes.ps1 -ExpectedCorpusSha256 7b88f23ceef19829e576326d804a87b31f9eec2ddf32962cb8774ba1cc64dd8b -ExpectedGdiSourceSha256 621b369d85290f10ee0b0333709f10c8e651593dd7a04194232886dedefde466 -Output .\current-material-gdi-result.json
```

The result contains exact native top-down B/G/R/reserved32 words, SHA256s,
the original ordered recipes/stages, input capture identity, executable
identity, source/runner hashes and Windows GDI DLL/runtime provenance.
`native_vcl_verified` remainsfalse. No Windows execution occurred while
preparing this corpus; its numeric original-instruction replay did execute.

On return, verify both scalar/DIB capture identities and state against these
case inputs. Original+FC is already apparatus-composed; direct comparison
against these uncomposed references is invalid. Use observed+F8/+F4 pixels,
original same-size native CopyRect semantics and verified4926E0 arithmetic
to build a separately labelled final candidate, with any particle/overlay
boundary resolved first. Report RGB and reserved-byte differences separately;
do not promote a partial match to complete VCL/DC or frame fidelity.

Reproduce the six original numeric/color/geometry recipes in the uv-managed
venv (bounded native JIT requires its authorized sandbox override):

```sh
.venv/bin/python tools/build_current_material_corpus.py
```
