# Original numeric allocation slots

`OriginalSlots` preserves 100 physical QWORD cells for each of apparatus
`+298` (mass), `+5B8` (volume), `+8D8` (moles), `+3CD8` and `+3FF8`
(particle feedback). Cells are little-endian hex strings; `null` means not
observed. Observed inactive cells, negative zero and NaN payloads survive
serialization. A nonfinite/unknown cell is retained without being evaluated;
an attempted unsupported read fails explicitly. No fresh-heap zero assumption
or universal allocation profile is introduced.

Species names at `+108`, with count `+104`, provide an ordered view of those
cells. Numeric cells do not belong to names. A deleted/reordered name must
not carry a particle/volume cell to a different physical index automatically.

## Source lifecycle evidence

Evidence is in `recovered/native/main/decompiled.cpp`; original instruction
bytes and the existing oracle fixture tooling are retained in this workspace.

| Native routine | Relevant writes |
| --- | --- |
| `453A28` factory, lines 24219 onward | Count zero; no initialization of these five 100-cell numeric arrays. See allocator audit for reused heap. |
| `43240C` reader, lines 12431–12460 | Reads count, ordered names, mass and moles into active indices. Does not initialize particle arrays or inactive cells. |
| `461E54` quantities, lines 29175 onward | Updates active mass; updates volume only for original physical phase branches. Nonphysical volume cells remain untouched. |
| `462660` selected reaction insertion, lines 29442–29528; `46C894` cycle preparation, lines 33605–33688 | A new reaction species writes zero moles, mass, volume and both particle cells, then increases count. Existing species is not zeroed. |
| `476DDC` / `477330` liquid/solid transfer | Appended target species writes its name and moved moles. Particle cells and nonphysical volume cells are not initialized by this append. Subsequent quantity refresh writes physical volumes. |
| Run callback, lines 15945–15960 | Clears `3CC8` and `4318`; clears both particle arrays **only for the current active count**, before air insertion. |
| `48E9B4` air initialization, lines 44154–44193 | Appends/finds inert gas; writes mass, moles and volume zero before calculating inert mass/moles. Does not write either particle cell. |
| `4A62DC` Form5 dosing, lines 53475–53490 and equivalent later branches | New name writes mass, moles and volume; neither particle array is written. |
| `49D418` Form4 staging, lines 50141 onward | Copies all 100 cells of each numeric array to temporary globals, not only the active count. |
| `4A0A98` chemical delete, lines 50920 onward | Compacts visible chemical name/mole/mass grid rows and binding rows. It does not shift apparatus particle/volume cells. |
| `49F0C8` Form4 confirmation, lines 50595–50638 and 50772 onward | Clears former active temporary mass/mole rows, rebuilds them from visible rows, then copies full 100-cell numeric arrays back. Volume/particle arrays remain indexed by their original slots. |

The source callback's full-array copy includes stale tail cells. The Godot
property commit helper rewrites only the source mass/mole cells and explicit
nested Form5 volume writes; it retains those untouched tail cells.

## Integration

`OriginalModelHost.attach_profile(profile, snapshot_index)` is explicit. It
validates original executable SHA, stable stopped/paused observation, vessel
count/order/type/parameter/label, ordered species and captured active mole
bits when available. It does not apply a process's allocation to a different
example or future new vessel. Full native records retain pointers, amounts,
scalars and capture metadata as evidence, not constructor defaults.

`OriginalRuntimeProfile` carries all raw arrays and keeps allocation evidence
on each vessel. First attachment copies all observed cells, then current
proved native writes win. A later call cannot resurrect stale snapshot bytes
over a subsequent slot write. Missing finite active values are projections
from the backing; unknown or nonfinite cells remain absent from the numeric
view until the source tries to read them.

The host commits active dictionary writes and projects by index at quantity,
manual transfer, dissolution/reaction and gas stage boundaries. Run uses the
active-only clear helper. Render feedback dictionaries are committed before
the following physics step. The explicit backing is included in saved vessel
state; imported state validates its shape and cells.

## Validation scope

`test_original_slots.gd` checks storage/lifecycle semantics using declared
sentinel cells, including stale inert append, active-only Run clearing,
editor index preservation, explicit reaction zero writes, unknown reads,
nonfinite payload preservation and rejection of implicit compaction.
`test_original_runtime_profile.gd` checks transport/identity guards, raw
mass/mole retention and prevents reapplication from overwriting later writes.
These tests are synthetic storage regressions, not live Windows captures.

`test_original_particle_frames.gd` retains the original PE's **declared zero
numeric allocation test profile** as full indexed observations, rather than
prefilling every possible species name. The complete opening workflow still
matches 60 physics ticks and 66 persistent particle feedback passes. This
does not establish a zero heap policy in the original GUI. An actual stable
Windows allocation capture is needed for a live-profile first-frame test.
