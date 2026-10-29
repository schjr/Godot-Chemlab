# Original persistent particles and render feedback

This port includes the live particle **state**, not decoration inferred from current chemical contents. `original_particle_rng.gd` transcribes native `539C60` and bound helper `4028EC`. `original_live_particles.gd` provides emission/update helpers. `original_particle_vm.gd` executes retained decoded source instructions for the complex collision, retained-pixel and main-render cache branches; `original_particle_frame.gd` binds native vessel/cell layouts to this execution. `tools/compile_original_particle_ir.py` generates `godot/data/original_particle_ir.json` directly from the original binary and preserves its SHA-256. The interpreter explicitly fails on an unsupported instruction, primitive, or undefined byte read.

## Integration contract

`OriginalParticleFrame.create_scene(native_apparatus)` creates portable pool dictionaries corresponding to native `43DCD8` Run construction. Only type IDs 101 through 199 have these pools. Native particle classes are zeroed through their actual Delphi `InitInstance` (`53139C` -> `531414`), independently verified against an A5-prefilled allocation. This is **different** from the plain apparatus allocation, whose untouched numeric slots are unknown.

Call an `OriginalParticleFrame` instance's method:

```
step(vessels, reagent_map, native_connectors, scene,
     {run_flag: original_integer, pause_flag: original_integer},
     {low: original_rng_low_dword, high: original_rng_high_dword},
     Callable(exact_x87_host, "evaluate"), native_presentation)
```

It returns `{ok, error?}`. The source branches are `40E8E4–40F304` (solid feedback) and `40F352–40F9FF` (gas/connector feedback), with their actual callees. The source caller has already refreshed liquid height/color and draws settled solids between these two blocks. They must be invoked in that original rendering order, including after manual actions when the original redraw occurs. They are not an extra physics approximation or a time-scaled particle animation.

The scene retains each pool's count, all thirteen DWORD cells per record, flags, rectangle, colors, bubble call count and surface, and `primary_words`/`retained_words` for solid layers. Cell values remain unsigned 32-bit integers, retaining exact float32 bit patterns without decimal conversion. Preserve these fields through save/load. The two-DWORD random state is shared across all source random callers and remains caller-owned; do not reset it when creating/restarting particle pools unless original code actually does so. Missing random state is rejected only when the original branch consumes a nonzero-bound random call; a zero bound does not advance the source RNG.

A transactional caller should pass working copies of vessels, connectors, scene and random state, then commit only a successful complete operation. A missing primitive can be discovered after earlier source writes, so it must not accidentally commit a partially evaluated host operation.

The current particle-frame module is isolated; it does not itself modify `original_model_host.gd`, `main.gd`, or `lab_canvas.gd`.

## Exact arithmetic boundary

Use `OriginalX87Host.evaluate(angle, kind)` for production. Its compiled x86_64 helper executes the original FSIN/FCOS instruction primitives through Rosetta. The particle's persisted float32 angle is widened to the original QWORD argument, and the returned extended pair participates in source-order arithmetic before the native float32 store. No Godot sin/cos substitution is made. Source-only tests also retain exact captured extended primitive results as an independent input reference.

`OriginalX87.stored_float32()` rounds extended expansions directly to binary32, avoiding an invented intermediate QWORD store. This matters independently of the quantity/thermal methods which store binary64.

## Native presentation callback

All retained-layer numerical instructions in `49C620`, `49CDD8`, and `49BA04` execute; these functions are **not** mocked as whole presentation calls. The remaining callback addresses are actual VCL/GDI operations: pen/brush/style setters, bitmap resizing/copy/draw, Rectangle, Ellipse, and SetPixel. A callback request includes the native address, register arguments, stack pointer, interpreter memory and bitmap metadata, so a provider can read the original arguments at the original call boundary. Native stack cleanup is preserved (Rectangle/Ellipse 20 bytes, SetPixel 16, VCL Rectangle 8, Canvas.Draw 4).

A callback returns `{ok: true, bitmap_words: {bitmap_name: array_of_u32_words}}` for surfaces it changes, or an explicit failure. It can use the supplied interpreter memory to obtain original call arguments. Before a source ScanLine is read, an `operation: "scanline_words"` request is made if the actual words are not available. Its reply must provide exactly `width * height` words. Pixel arrays are never silently initialized to zero in production. Unknown initial/resized DIB contents must be obtained from the verified native provider/profile.

The current callback contract is synchronous. An asynchronous Windows GDI host needs an adapter which obtains the exact primitive response before source execution continues; returning an asynchronous function state is not a completed pixel result. This adapter/verified raster provider remains a production integration dependency. The module does not silently substitute a software rasterizer or a nearby atlas entry.

The words are visual top-down DIB words. Native `4E95B0` proves this: it reverses positive `biHeight` rows before returning the scanline pointer and uses direct rows for negative height. Numeric code preserves the reserved high byte where the original does. Do not substitute a presumed alpha value or change pixel encoding. Each bitmap metadata entry contains its semantic name, dimensions, canvas/pen/brush handles and row pointers.

The exact Windows GDI host or an exhaustively verified finite mask atlas can supply primitive geometry. Such masks do not replace the persistent layers, pixel diffusion/color logic, random state or live cache feedback.

## Undefined original apparatus cells

The solid renderer's negative-delta sum reads `3FF8` for **all active species**, including a newly appended inert-gas cell. Run clears the arrays for the then-active count, before the air helper can append that cell. A missing inert cache therefore cannot be assumed zero merely because the other active entries were cleared. Supply observed runtime slot bytes or another proved original writer. Actual unknown reads fail explicitly; cells not read by a branch remain absent. Adoption does not synthesize values for unread cells.

Counts that exceed the physical object-array layouts are explicitly unresolved. The native emission guards do not establish a safe universal count cap after arbitrary large emissions; a native out-of-bounds overwrite is not converted into a new volume/particle clipping rule.

## Native reference evidence and acceptance

- `tools/original_particles_oracle.py`: actual original InitInstance, RNG, emission and update functions. The 300 checks cover 120 RNG steps, sixteen solid emissions, 64 solid updates, 36 bubble emissions and 64 bubble updates, preserving all active record DWORDs.
- `test_original_particles_host.gd`: all 128 persistent update frames pass with the production exact x87 host, including all record cells and final random state.
- `tools/original_particle_frames_oracle.py`: the actual opening copper/iron `.cem`, original manual callbacks and full original chemistry, followed by the actual main-render particle/cache blocks and retained-layer numerical functions. The profile declares initial numeric heap bytes, TLS low=1/high=0, and zero DIB input surfaces. Only VCL/GDI raster primitives are recorded rather than rasterized.
- `test_original_particle_frames.gd`: 60 physics ticks and 66 live render passes pass against that native reference. Comparisons include contents, `3CD8`/`3FF8` feedback, `3CC8`, all active particle DWORDs, rectangles, colors, counters and shared random state.
- `test_original_particle_unknowns.gd`: verifies that an actual unknown inert-cache read fails, while an unvisited bottle branch preserves its unread unknown slot.

These tests certify source state/numeric behavior under their explicitly declared presentation inputs. They do **not** claim that zero-filled DIB input is a native Windows constructor guarantee, or that recorded primitive calls prove their raster output. Production integration requires the verified primitive provider/pixel profile.

## Finite primitive geometry

For valid source-created solid particles, the minimum stored life decrement is float32 `0.008437500335276127`: the source's QWORD 0.01 plus its 80-bit `0.0015625` coefficient and four RNG bits, with the original intervening QWORD stores. Life starts at float32 0.35; the radius starts at six and grows by QWORD 0.2 at each update. There can be at most 41 drawable updates; the largest drawable stored radius is `14.199992179870605`. Neither term depends on physics dt.

`49C620`'s ellipse guards give `-7 < x < W+7` and `4 < y < H+4`; the native integer box is FTOL of `x ± radius` and `y ± radius/2`. Conservative exhaustive domains are x coordinates `[-22,W+22]`, y coordinates `[-4,H+12]`, width at most 30 and height at most 16. The subsequent rectangle uses FTOL `(x,y,x+1,y+2)` under its source guards.

Native-created bubbles have integer size 1–4. Their draw guard gives `-3 < x < W+3` and `-3 < y < H+3`. Size one uses SetPixel. Larger bubbles use FTOL of `(x-size/2,y-size/2,x+size+1,y+size)`; widths at most eight and heights at most seven are conservative bounds. Canonical native masks for every relevant integer geometry can be translated/clipped only after verifying the original pen/brush, mapping and clipping behavior; no sampled or nearby-mask substitute is permitted.

These bounds apply to valid native-created records, not corrupted memory after an oversized emission. They bound primitive masks, not the number of arbitrary persistent image states.
