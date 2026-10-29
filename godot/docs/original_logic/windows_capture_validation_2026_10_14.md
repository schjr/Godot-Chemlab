# Actual original-process capture validation

The user exported archive SHA256
`c2a109776bdf35d89f7799ebed9c725bbe91b779b95ca12b6bf2a520bc1e5b5b`.
Parent verified the archive before extraction. The exact files are under
`evidence/windows-runtime/original-captures-2026-10-14/`.
`tools/analyze_original_runtime_captures.py` validates their format, original
executable hash, 32-bit process/image base, stable stopped/paused apparatus
and species identities, and each complete 100-cell raw numeric array.
Its byte-delta report is `analysis.json` in that evidence directory.

All three captures identify process 8928 and the recovered original image
SHA256 `7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c`.
They contain six apparatus allocations and five complete 800-byte arrays
per allocation: 3,000 observed QWORD cells per snapshot. No array is truncated.
Each raw cell agrees with the reader's independently recorded per-slot hex.
All observed values are finite, but some inactive cells are subnormal/stale.

## The attempted NaOH action

`after-run-paused.json` and `after-naoh.json` have identical species order,
allocation pointers, all 3,000 QWORD cells and all 18 captured scalar values.
Elapsed remains exactly `3bb4c876bedf2940` = 12.937000000000003 seconds.
All active amount deltas are exactly zero.

| Apparatus | Observed liquid/reagent amounts in both snapshots |
| --- | --- |
| NaOH bottle (index 1, 容器4) | Water 2.2202486678508 mol = 40 g; NaOH 0.1 mol |
| First dropper (index 2, 容器5) | Only inert gas 0.00017857142857142857 mol; no water or NaOH |
| HCl bottle (index 4, 容器7) | Water 2.2202486678508 mol = 40 g; HCl 0.1 mol |
| Second dropper (index 5, 容器8) | Only inert gas 0.00017857142857142857 mol; no water or HCl |

The copper and iron beakers retain respectively 0.02 mol CuSO4 and 0.03 mol
FeCl3, zero NaOH and zero hydroxide precipitate. The capture label does not
establish a successful button action. These observations establish **no
withdrawal or dosing occurred between the two captured stopped states**.
They do not establish why the attempted interaction did not execute.

## Real allocator evidence

The cold HCl bottle has 96 nonzero volume cells, 95 nonzero mole cells,
92 nonzero mass cells, and a nonzero `+3CD8` particle cell at inactive index
63 (`-1.4853970537e-313`). Most are subnormals. Its nonphysical active HCl
volume cell also contains a preserved subnormal. Run leaves that inactive
particle cell untouched. This is direct evidence against treating the whole
apparatus allocation as zero-initialized. These bytes belong to the observed
allocation and are not defaults for another allocation or example.

## Godot comparison

`test_original_windows_capture.gd` (default acceptance) imports the original
opening CEM and calls `model.attach_profile(cold)`. It passes **3,024 checks**:
all 3,000 QWORD cells, six ordered name sets and 18 captured scalar values
match the actual cold observation. Full raw evidence, including inactive
subnormal cells, is retained in `native_slot_backing`.

The opt-in `-- --compare-live` diagnostic proceeds through Run and source-driven ticks. It
reports **six mismatches**, each one ULP and confined to the two empty
droppers' inert gas:

| Stage | Port | Actual later paused capture |
| --- | --- | --- |
| Immediately after Run, inert volume | `ffffffffffff0f40` (3.9999999999999996) | `0000000000001040` (4.0) |
| After a tick, inert moles | `b2a934e4dc67273f` | `b1a934e4dc67273f` |
| After a tick, inert mass | `c9b9cf2e2036753f` | `c8b9cf2e2036753f` |

Each row occurs in both droppers. All other compared active and inactive
slots, names and scalars match. The amount difference remains after four
source-driven ticks. The later native capture is not a recorded first-tick
clock/history; its elapsed time cannot be replayed as one invented delta.

The captured mole/volume combination is consistent with binary64 rounding
after each multiplication of `moles * 22.4 * 1000`. That is an **inference
about the live arithmetic context**, not a proven cause. Source assembly
at 46216E and 462174 has consecutive FMUL QWORD22.4 / FMUL DWORD1000 without
an intervening QWORD store. The current PC64 arithmetic port matches the
retained original-PE oracle fixtures. No precision switch, inserted store,
epsilon adjustment or value substitution was added to force this capture
to match.

The captured `5755E8` memory word is `0x1332`, as the source startup trace
predicts. It is a stored global, **not an observed live x87 control register**.
The actual runtime arithmetic context/source call sequence still needs
evidence before changing the production primitive. Exact live particle
pixels and RNG startup state are also not included in these memory captures.
Consequently this evidence establishes cold allocation attachment, but not
complete live tick/render equivalence or a successful NaOH interaction.
