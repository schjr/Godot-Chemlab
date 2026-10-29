# Original continuous pouring and open-outlet flow

Target: `artifacts/ChemLab/_main.exe`, SHA-256
`7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c`.
The retained native bodies are `evidence/original_logic/004849fc.cpp` and
`004433b4.cpp`. Their instructions and original resource paths establish this
port; no textbook rate, recipient proximity rule or capacity policy is added.

Implementation: `godot/scripts/original/original_flow.gd`, `OriginalFlow`.

## Native order and public methods

`advance(vessels, delta, scale, reagent_map)` modifies the supplied ordered
native apparatus array. The original caller supplies delta seconds and its
canvas scale; the flow function itself does not check the run flag. It returns
ordered transfer calls, their results and any requested native stop/error.

`plan_frame(...)` is a capture-only comparison mode. It copies the apparatus
array, records calls instead of executing material transfers and still performs
the native intermediate quantity pass. It matches the corresponding oracle
boundary; production simulation must use `advance`, not `plan_frame`.

`toggle_pour(vessel)` transcribes `N18Click` at `0x004433B4`. It changes native
orientation 0 to 2, or 2 to 0; orientation 1 is untouched. It returns the exact
native bitmap and mask filenames and menu check state. The host must load
those resources, copy the plain bitmap to the active bitmap and refresh its
actual dimensions before calling flow. Applying a generic visual rotation to
an upright image does not establish the original outlet geometry.

The display scalar feedback also follows the original branch. In `40A4B8`,
orientation2 with an open mouth (`+18=2`, `+38=0`) uses fixed tilted material
polygons and bypasses `471650`. Consequently this branch keeps the preceding
`+30` liquid height and the quantity pass's `+4320` liquid volume; it does not
apply the common upright liquid-height calculation or its capacity clamp to
the tilted bitmap. A closed tilted vessel still takes common material, as
does an upright vessel. `original_model_host.gd:refresh_render_state` preserves
this predicate. The normal-import regression
`test_native_tilted_liquid_feedback.gd` checks the opening reagent bottle's
actual upright/tilted asset dimensions and both sides of this scalar boundary,
including a source-permitted over-capacity quantity.

Native `0x004849FC` runs:

1. Its type-311 conduit/control-region pass.
2. Pouring for apparatus whose `+0x18` orientation equals **2**.
3. `0x004624D8`, recalculating quantities for all types 101–299.
4. Open-outlet transfer for types 204, 207, 208, 209, 210, 211 and 311,
   excluding orientations 1/2 and requiring `+0x68 != 1`.

The implemented profile includes the ordinary-vessel branches in steps 2–4.
Type 311 has native GDI polygon-region and custom-conduit endpoint logic;
its geometry remains unresolved. If any type 311 exists in the array, the
port fails explicitly before mutation. It does not silently skip that pass
or substitute rectangle/nearest-target behavior. None of the 28 supplied
original experiments contains type 311.

## Required original fields

Each record retains `native_fields` including `0x18` orientation. Depending
on the branch, `0x0c` subtype/size, `0x68` outlet state and `0x6c` solid mode
are required. Centers are original integer coordinates in `position`.
`native_bitmap_width` and `native_bitmap_height` describe the **current
active** bitmap, including the bitmap loaded by the orientation toggle.
Species remain in native order in `contents`, with original reagent metadata
and quantity caches supplied by `OriginalQuantities`.

Missing fields or dimensions produce explicit unresolved-input errors. The
module does not derive bitmap dimensions from a guessed apparatus rectangle.

## Original pouring geometry and rate

Orientation-2 outlets use the current tilted bitmap dimensions `(W,H)`:

```text
outlet_x = truncate(x - W*0.5*scale + dx*scale)
outlet_y = truncate(y + H*0.5*scale - dy*scale)
```

| Type / subtype | dx | dy |
| --- | --- | --- |
| 101 | 0 | 0 |
| 102 | 1 | 1 |
| 103, size 100 | 12 | 14 |
| 103, size 250 | 16 | 18 |
| 104 | 12 | 15 |
| 105 | 9 | 14 |
| 106 | 1 | 1 |
| 121 | 0 | 0 |
| 201 / 202 | 2 | 7 |

The native source has no assigned outlet for other tilted type/subtype
combinations. Such native stale-local situations are reported as unsupported;
the port does not invent an endpoint.

Recipient orientations 1/2 are excluded. Eligible recipient types are
101, 102, 103, 104, 105, 107, 121, 201, 202, 209 and 210. The native code
uses explicit strict mouth bands above the current recipient bitmap, with
an integer-truncated best score as in manual dosing. The profile preserves
the type-101 size-45 offset mouth, beaker edge insets, wide/narrow vessel
radii, and funnel/separator mouth bands.

At instruction `0x00488E6E`, liquid transfer calls `0x00476DDC` with request:

```text
float[0x0048C3F0] * delta * extended[0x0048C3F4]
```

The float is exactly 0.25. The extended value is stored as
`D4 FE FF FF FF FF FF C7 05 40` and is approximately 100. The request is
approximately `25 * delta` physical-volume units, with its original x87
operation order retained through `OriginalX87`.

After the liquid helper returns, the original checks the source's updated
`+0x4320` liquid volume. Only if it is below `1e-10` does it call the solid
helper `0x00477330`, with the **same** request at `0x00488EB1`. Thus solids
can start moving in the same frame that its last liquid is depleted. A
precomputed plan based on the old quantity would change this behavior;
`advance` checks after the actual helper mutation.

## Original open-outlet geometry and rate

Types 204, 207, 208, 209, 210 and 211 use
`truncate(y + H*0.5*scale)` as outlet y. Type 207 additionally moves outlet x
by `-4*scale`; other supported types use their center x.

The incoming bands differ from tilted pouring: ordinary beakers/vessels use
the internal bottom limit rather than an upper-rim-only band; types 121,
209 and 210 retain their upper-mouth bands. Types 107, 201 and 202 use
integer-halved bitmap height in this branch, preserving odd-height behavior.

At `0x0048C2F4` the regular liquid request is:

```text
double[0x0048C420] * delta * extended[0x0048C3F4]
```

The double is exactly the stored binary64 0.2. This is approximately
`20 * delta`, not a manual “点滴” dose. Type 209 additionally transfers
solids at the approximately `25 * delta` rate when its updated liquid
volume is below `1e-10` and native field `+0x6c == 0`.

No destination-capacity cap is inserted. Material selection, proportional
movement, merge order, temperature mixing and quantity recalculation use
the original `OriginalTransfer` helpers, documented in `dropper_trace.md`.

## Exact original bitmap switching

`N18Click` loads native `+0xF4` plain and `+0xF8` mask resources, resets the
active `+0xFC` bitmap, then assigns the plain bitmap to it. It changes the
menu check alongside the orientation. If paused, it calls the original
redraw routine; that caller/UI redraw remains the host's responsibility.

The implementation retains the observed filenames, including both original
size-1000 bottle quirks: wide bottle uses `dgkp_z.bmp` with `_dgkp.bmp`,
and narrow bottle uses `dxkp_z.bmp` with `_dxkp.bmp`; their upright counterparts
also retain the small masks. This is not corrected to a guessed `_z` mask.
Unsupported bitmap type/size branches still retain the original orientation
write but do not invent a resource load.

## Original-instruction verification

`tools/original_flow_oracle.py` executes actual original x86 instructions in
the bounded emulator; no Windows process is launched.

- **678 flow caller frames** execute `0x004849FC`, including original
  `0x004624D8/0x00461E54` calculations. Transfer entry points capture the
  original stack indices, phase helper and raw request bytes rather than
  executing material mutations. Tests compare ordered calls and every dose
  bit. Coverage includes all ordinary outlet types, candidate/subtype bands,
  open/closed/other state values, orientation exclusions, odd dimensions,
  fractional scales, overlaps and zero/negative delta request semantics.
- **54 orientation frames** execute the original `0x004433B4`. Native bitmap
  loading is hosted as a declared VCL boundary that reads SHA-verified original
  BMP files and their actual dimensions from the recovered inventory. Tests
  compare orientation, menu check, plain/mask path selection, including
  unsupported type/size branches and both size-1000 mask quirks.
- **Nine full material-flow frames** execute `0x004849FC`, liquid transfer,
  solid transfer and derived-quantity arithmetic without numeric hooks. They
  use the original `dxkp` and `sb200` bitmap dimensions and a source containing
  liquid water, dissolved NaOH, solid Zn and gaseous CO2. Cases span initial
  liquid volumes 0.01, 1 and 40, and delta values 0.017, 0.1 and 0.3. Tests
  compare source/target ordering and all recorded mass, volume, mole,
  temperature and aggregate binary64 results. Liquid depletion and same-frame
  solid fallback match the executed original instructions.

All comparisons in `tests/test_original_flow.gd` pass. Floating operands and
outputs are encoded as byte strings to avoid Godot JSON decimal conversion
differences. The fixture files are `native-flow-oracle.json`,
`native-orientation-oracle.json` and `native-flow-material-oracle.json` in
`evidence/original_logic`.

This establishes the recorded ordinary-vessel numeric/state profile.
Type-311 GDI region behavior, full bitmap pixels/animation, paused redraw,
whole-application event routing and arbitrary legacy floating-point inputs
remain outside these bounded comparisons and must not be claimed as verified.
