# Native dropper / pouring trace

This is a static trace of the shipped Windows executable and recovered native
pseudocode. It records observed native operations and unresolved arguments;
it does not specify a replacement chemistry model or invent droplet volumes.
The prior proposed Godot `aspirate/drop` action API is not used as evidence.
No interaction test or simulation implementation was added during this audit.

Target: `artifacts/ChemLab/_main.exe`, SHA-256
`7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c`.
Native source references below use `recovered/native/main/decompiled.cpp`.
Read-only PE disassembly was obtained with macOS `/usr/bin/objdump -d`.
The active shared REA session was not changed.

## 1. User-visible original operation

`recovered/chemistry/help_text/help/yongysl.txt:46` establishes the workflow:
run the experiment, position the rubber dropper's mouth below the source
liquid surface, then click the adjacent “吸取”; “点滴” delivers its liquid
into another vessel. The example transfers NaOH solution from a narrow-mouth
bottle to CuSO4 and FeCl3 beakers. This help text establishes interaction
order, not dose size or transfer formulas.

The prepared original example “氢氧化铜与氢氧化铁” has, in stored order:

| Original apparatus | Type | Center | Capacity | Initial relevant content |
| --- | --- | --- | --- | --- |
| 容器3 | 102 | (179,222) | 200 | CuSO4 solution |
| 容器4 | 202 | (429,224) | 100 | NaOH solution |
| 容器5 | 204 | (429,206) | 4 | Empty dropper |
| 容器6 | 102 | (306,222) | 200 | FeCl3 solution |
| 容器7 | 202 | (510,224) | 100 | HCl solution |
| 容器8 | 204 | (510,206) | 4 | Empty dropper |

Stored apparatus IDs can repeat; native array positions and display names
must not be conflated with a new Godot ID.

## 2. Adjacent controls are drawn, not DFM helper-window buttons

Observed in `FUN_0040A4B8` (27,666 bytes; source starts line 4557), specifically
the source branch starting at line 6796. The button rectangles and labels are
drawn directly to the main canvas via `FUN_004E4744` and
`thunk_FUN_004E484C`. Searches across all `_main` recovered DFM forms find no
“吸取” or “点滴” buttons. `TFORM_BUTTON.dfm` is a user-authored button-object
settings dialog, not the dropper helper panel.

The native renderer enters this helper-control branch only when:

```text
DAT_0057A6F8 == 1
100 < DAT_0057A730 < 300
DAT_0057A734 == current apparatus array index
```

The first global is the run flag in the timer path; the latter two identify
the selected apparatus type and index. Those interpretations are corroborated
by the conditions and callers; original symbol names are absent.

Native label strings:

| VA | Label | Apparatus render branch |
| --- | --- | --- |
| 0x00556744 | 吸取 | Type 204 |
| 0x00556749 | 点滴 | Type 204 |
| 0x0055674E | 打开 | Types 207 / 208 |
| 0x00556753 | 关闭 | Types 207 / 208 |
| 0x00556758 | 点滴 | Types 207 / 208 |
| 0x0055675D | 打开 | Type 211 |
| 0x00556762 | 关闭 | Type 211 |
| 0x00556767 | 点滴 | Type 211 |

For type 204, let `(x,y)` be the apparatus center and `(W,H)` its active
bitmap dimensions. The observed drawn rectangles are:

```text
吸取: [x + W/2 + 10, y - H/2,      x + W/2 + 45, y - H/2 + 20]
点滴: [x + W/2 + 10, y - H/2 + 23, x + W/2 + 45, y - H/2 + 43]
```

Caption origins are `x + W/2 + 14`, with y offsets `+3` and `+26`.
Native code explicitly adjusts negative integer halves toward zero before
using them. Renderer calls here use stored coordinates and bitmap dimensions;
the global scale must not be assumed to multiply these constants indiscriminately.
Mouse activation rectangles, overlap priority and actual dosing remain the
separate primary mouse-handler trace; drawing a rectangle alone does not
prove its callback behavior.

Types 207/208 draw three controls at the right of the bitmap, near its bottom,
at vertical offsets `H/2-70..H/2-50`, `H/2-47..H/2-27`, and
`H/2-24..H/2-4`. Type 211 uses offsets `-H/2+0..20`,
`-H/2+23..43`, and `-H/2+46..66`. Open-state fill styling checks the
apparatus field at `+0x68`.

## 3. Native scheduler and transport chain

`FUN_004018B0` (4,139 bytes; source line 385) checks the runtime tick value,
requires more than five ticks since the form's stored tick field, and runs
the experiment branch only if `DAT_0057A6F8 == 1` and form field `+0x5BC == 0`.
Within it:

```text
delta = extended_constant_at_004028DC * (current_tick - DAT_0057A74C)
DAT_005636D4 = delta
DAT_005636CC += delta
DAT_0057A74C = current_tick
FUN_00470060()
FUN_0048E418()
FUN_004849FC()
... native reaction and condition passes ...
FUN_004624D8()
```

The extended constant at `0x004028DC` decodes to 0.001. Thus the observed
delta is milliseconds converted to seconds. Timer event identity is not
asserted from an unresolved original class symbol alone.

`FUN_004849FC` (31,032 bytes; source line 40404) contains the continuous
transport scan and recipient geometry. It calls the liquid transfer helper
`FUN_00476DDC` and solid helper `FUN_00477330`. The geometry is native
type-specific, not a nearest-vessel or generic bounding-box operation.

The unrotated output scan admits types 204, 207, 208, 209, 210, 211 and 311,
excludes orientation fields `+0x18 == 1 or 2`, and requires field `+0x68 != 1`.
For type 204 its outlet begins at `(x, y + H/2 * scale)`; type 207 shifts
x by `-4 * scale`. Recipient scanning uses strict inequalities, type-specific
mouth bands and polygon regions for special conduit/type-311 paths. It
stores the candidate with the greatest positive vertical score, rather than
unconditionally selecting the last hit item.

For type 102, a directly visible recipient-band branch is:

```text
xr - W/2*scale + 7*scale < outlet_x < xr + W/2*scale - 1*scale
yr - H/2*scale - 50*scale < outlet_y < yr + H/2*scale - 3*scale
score = outlet_y - (yr - H/2*scale - 50*scale)
candidate changes only if score > current_score
```

This band establishes eligibility for continuous outlet transfer. It must not
be substituted for the separate “吸取” below-liquid-surface predicate.

## 4. Exact secondary call-site amounts

Ghidra pseudocode incorrectly renders several native calls as argumentless.
The recovered callee reads stack slots. PE disassembly resolves these
secondary call sites without altering a REA session:

| Call VA | Helper | Stack arguments established by assembly |
| --- | --- | --- |
| 0x0048C29A | 0x00476DDC | source index, recipient index, double 100.0; special type 311 |
| 0x0048C2CA | 0x00477330 | same indices, double 100.0 if type-311 liquid is depleted |
| 0x0048C2F4 | 0x00476DDC | source index, recipient index, `double[0048C420] * delta * extended[0048C3F4]` |
| 0x0048C35A | 0x00477330 | same indices, `float[0048C3F0] * delta * extended[0048C3F4]`, type 209 with depleted liquid and `+0x6C == 0` |

Constants decode to `double[0048C420] = 0.2`,
`float[0048C3F0] = 0.25`, and `extended[0048C3F4] ≈ 100`.
Its exact stored extended bytes are `D4 FE FF FF FF FF FF C7 05 40`.
The regular continuous liquid request is therefore approximately `20 * delta`
in native physical-volume units, while the type-209 solid request is
approximately `25 * delta`. The depletion threshold at `0x0048C400` is
double `1e-10`. These are continuous-run transport calls; they do **not**
establish the single “点滴” button dose or the “吸取” filling amount.

## 5. Exact native liquid transfer algorithm

`FUN_00476DDC` (1,348 bytes; source line 37990) reads:

```text
stack +4: source native array index
stack +8: recipient native array index
stack +12/+16: requested physical volume as a double
```

Observed algorithm:

1. Sum source per-species `+0x5B8 + 8*i` only for phase `(液体)` into `L`.
2. If `L < 1e-20`, return without transfer.
3. Set `q = min(requested, L)`.
4. Iterate source species, accepting phases `(液体)`, `(溶解)`, `(离子)`,
   and `(指示剂)`. For each, compute `moved_moles = source_moles * q/L`
   using per-species moles at `+0x8D8 + 8*i`; subtract from source.
5. Find the identical recipient species name with `FUN_00461DB4`; add
   moved moles, or append name and moles to the recipient's species arrays.
6. If the recipient species count exceeds 99, clear the run flag and display
   the error string at `0x00563E19`.
7. Let recipient pre-recalculation occupied volume be
   `V = recipient[+0x4320] + recipient[+0x4338]`. If `V+q > 1e-10`, update
   temperature at `+0x88` to `(source_temperature*q + target_temperature*V)/(V+q)`.
8. Call `FUN_00461E54` for source and recipient to recalculate derived values.

The phase string references are `0x00563DF4/DFB` for liquid,
`0x00563E02` dissolved, `0x00563E09` ion and `0x00563E10` indicator.
Gases and solids are not included in this liquid transfer loop. This is not
an all-species total-mole fraction transfer.

`FUN_00477330` (967 bytes; source line 38164) repeats the same structure with
only phase `(固体)` in the denominator and moved-species loop. Its phase
strings are `0x00563E31` and `0x00563E38`; its error string is `0x00563E3F`.
It performs the corresponding volume-weighted thermal update and derived
state recalculation.

## 6. Derived physical volumes, not guessed water volumes

`FUN_00461E54` (1,617 bytes; source line 29132) establishes these fields:

| Apparatus offset | Native meaning / observed formula |
| --- | --- |
| +0x104 | Number of species |
| +0x108 + 4*i | Species name |
| +0x298 + 8*i | Mass: reagent molar mass at +0x10 multiplied by moles |
| +0x5B8 + 8*i | Physical volume: mass / reagent density at +0x30 for nongas physical phases; gas volume `moles*22.4*1000` |
| +0x8D8 + 8*i | Moles |
| +0x4320 | Sum of liquid-phase physical volumes |
| +0x4328 | Sum of gas-phase moles |
| +0x4330 | Total gas volume `gas_moles*22.4*1000` |
| +0x4338 | Sum of solid-phase physical volumes |
| +0x88 | Temperature |
| +0x28 | Apparatus capacity |

This routine stops the experiment for moles below `-1e-10`. Per-species mass
and physical-volume conversion use original reagent fields. The native
standard-gas conversion is retained as an observed original rule, not replaced
by a textbook temperature/pressure law.

`FUN_004624D8` loops all apparatus of type 101–299 and calls this recalculation.
The dropper fill renderer `FUN_00471650` additionally caps its displayed
height calculation at 53.7 after calculating `liquid_volume/capacity * H + 0.5`.
That is a rendering limit, not proof of a new physical dropper capacity.

## 7. Separate visual stream path and unresolved primary actions

`FUN_004126DC` (528 bytes; source line 7722) calls `FUN_0047E714` when running
and form field `+0x5BC == 0`, then calls `FUN_0040A4B8`. The former draws
streams/drops and advances animation field `+0x4340` modulo eight; it should
not be mistaken for a user action callback or itself be used as chemistry.

Still requiring the primary mouse-handler/native instruction trace:

- exact press/release mode and overlap selection priority;
- the type-204 aspiration recipient predicate and below-surface check;
- aspiration capacity/remainder and phase movement formulas at its click site;
- exact one-drop dose and whether it is latched or immediate;
- open/close field transitions and their click rectangles;
- rotated-pouring amount and source/target argument identities.

No replacement value should be assigned to these unknowns. In particular,
the observed 4-unit dropper capacity in an example does not establish a
0.05-unit droplet, and the continuous `~20*delta` outflow does not establish
the adjacent “点滴” command's dose. Follow-up tests must derive from the
resolved native action trace rather than from the earlier proposed UI API.

## 8. Transcribed transfer helpers

`godot/scripts/original/original_transfer.gd` now provides `OriginalTransfer`:

```gdscript
OriginalTransfer.configure_reagents(original_reagent_map)
var result := OriginalTransfer.move_liquid(vessels, source_array_index,
    recipient_array_index, requested_physical_volume)
# move_solid(...) uses native 0x00477330 instead.
```

An optional fifth argument supplies a reagent map per call. The catalog map
keys are exact source species names. The transfer helpers require the
precomputed `native_species_volume`, `native_liquid_volume` and
`native_solid_volume` values supplied by `OriginalQuantities.recalc`, with
`contents` dictionaries retaining native species order. The request amount
is supplied by the resolved native caller; these helpers do not invent an
aspiration dose or dropdown interaction.

The port retains the native source-volume and thermal thresholds, phase
membership, source subtraction before target lookup, ordered append/merge,
zero-mole species appends, and source-then-recipient recalculation. Same-source
calls and negative/zero finite requests are not given new physical-policy
guards. No target-capacity cap or total-mole fraction is added.

Result fields include `ok`, `performed`, `requested_volume`, `actual_volume`,
`source_phase_volume`, `moved_moles`, `appended_species`, `stop_requested`,
`native_entry`, `native_messages` and `errors`. The native 100-species message
is preserved exactly as stored, including its original spelling:
“容器中的药品已有100钟！”. Appending the 100th species sets `stop_requested`
and emits the original message, matching the native count check. Attempting
an additional new species would exceed the native arrays and corrupt other
fields; that undefined memory operation is explicitly unsupported and
reported with preceding writes retained.

The native append routine writes only name and moles, not the destination
slot's old volume cache. If a caller provides `native_species_volume_slots`,
the prior unused slot is preserved under the new species name. Otherwise a
nonphysical phase's unobserved volume remains unknown/absent; the helper and
native derived-quantity routine never use that volume in this transfer.

Host adapter checks reject malformed indices, missing requisite caches,
missing original reagent metadata and nonfinite requests. Such inputs do
not describe valid native call frames, so no fallback physics is supplied.
Arithmetic now follows the native operation order through `OriginalX87`,
retaining precision-control=64 significand intermediates for division,
multiplication, addition and thermal mixing before each native qword store.
`tests/test_original_transfer.gd` compares the original executed x86 oracle's
source and target species ordering and every recorded binary64 field.
`evidence/original_logic/transfer-rawbits-from-native.json` packs the original
oracle output into little-endian double bytes through Python's round-trip
JSON reader; Godot decodes those bytes rather than reparsing decimal numbers.
The original NaOH/bottle fixture passes every recorded bit comparison.
That bounded fixture establishes agreement for its original call frame;
it is not a claim that every possible legacy floating-point input is covered.

## 9. Newly discovered manual callback 0x00477708

The prior exported function collection omitted `0x00477708`. A focused
recovery now retains its 2,182-line body and native instructions at
`evidence/original_logic/selected/00477708.cpp` and `.asm`. Thus the earlier
recovery was incomplete at this function; the new evidence supersedes the
manual-dose unknowns in section 7. This callback is invoked by the original
MouseUp path when running, after MouseDown latches command 1, 2 or 3 in
`DAT_0057A738`.

| Selected type | Command | Native state / transfer |
| --- | --- | --- |
| 204 | 1 / 吸取 | First submerged source in native stored order; request `2.0 - sum(current dropper liquid physical volumes)` |
| 204 | 2 / 点滴 | Chosen recipient; request double 0.2 |
| 207 / 208 | 1 / 打开 | Set field +0x68 to 0 |
| 207 / 208 | 2 / 关闭 | Set field +0x68 to 1 |
| 207 / 208 | 3 / 点滴 | Set +0x68 to 1, then chosen recipient; request double 0.25 |
| 211 | 1 / 打开 | Set +0x68 to 0 |
| 211 | 2 / 关闭 | Set +0x68 to 1 |
| 211 | 3 / 点滴 | Set +0x68 to 1, then chosen recipient; request double 1.0 |

Aspiration request instructions occur before all eight calls at
`0x00477A61`, `0x00477CE4`, `0x00477F80`, `0x0047819F`, `0x004783BE`,
`0x004785DD`, `0x004787FC`, `0x00478A1B`: load float constant
`0x0047E6D4 = 2.0`, subtract the dropper's double liquid-volume sum, store
double argument, push selected dropper index as target, then candidate
index as source. The saved example's 4-unit capacity is not used as this
aspiration limit. Overfilled dropper inputs produce a negative request;
the native callback does not impose a positive clamp here.

Single-drop argument pushes at `0x0047A0BF`, `0x0047B80F`,
`0x0047CF52` and `0x0047E6B2` resolve respectively to 0.2, 0.25,
0.25 and 1.0. These fixed manual doses are distinct from the secondary
continuous `~20 * delta` route.

### Manual numeric geometry

This callback contains no polygon-region creation or bitmap-pixel-mask
lookup. Its chemistry target selection uses explicit native strict bands.
GDI/VCL calls in this callback draw the falling-drop animation; main canvas
object hit-testing and the MouseDown helper-control hit rectangles remain
separate caller responsibilities.

The selected outlet uses x=center x and
`y=truncate(center y + H*0.5*scale)` for types 204 and 208.
Type 207 additionally uses `x=truncate(center x - 4*scale)`.
Type 211 uses integer-truncated `H/2` before scaling its outlet y.
The conversion routine `0x005394FC` temporarily sets x87 rounding control
to truncate, executes `FISTP` int64 and restores the control word
(`0x00539503`–`0x00539520`). It does not round to nearest.

Eligible manual source/recipient types are 101, 102, 103, 104, 105, 107,
201 and 202. Type 101 requires field +0x0C==0. Type 103 requires
+0x0C==100 or 250 and uses x radius 5 or 7 respectively. Other narrow
bands use x radius 5 for 104/105/202, and 7 for 101/107/201, scaled by
the native scale. Type 102 uses `x-W/2*scale+7*scale` as its left bound;
its right inset is 2 for aspiration and type-211 drops, 1 for other drops.

Aspiration requires the outlet strictly below the **current** source liquid
surface `y + H/2*scale - native_liquid_height*scale`, and strictly above
the bottom inset `y + H/2*scale - 3*scale`. It returns on the first eligible
source even if that source contains no transferable liquid; it does not
continue looking for a nonempty alternative.

Manual drop bands run from `y-H/2*scale-50*scale` to
`y+H/2*scale-3*scale`. The candidate score is outlet y minus the upper
bound. A candidate changes only if its extended score exceeds the current
stored **integer** score, after which the score is truncated toward zero.
Consequently this is not a true floating-point maximum: a later score 51.3
can replace 51.5 because the earlier stored score was 51. Type-211 bands
use integer halves. Type-208/type-201 uses floating-half bounds but an
integer-half height in its score; type-208/type-202 uses integer-half bounds
and score. Those branch differences are retained rather than generalized.

### Fresh liquid height is a native rendering dependency

`FUN_0040A4B8` clears the apparatus double +0x30 before its draw pass,
then invokes `0x00471650` and `0x0047692C` (source lines 6172–6177).
`0x00471650` writes the current liquid height +0x30 and also writes its
capacity-clamped liquid total into +0x4320 (source lines 36448–36452).
`0x0047692C` colors gaseous headspace and does not overwrite that height.
Previously saved `.cem` height fields can be stale and are not a substitute
for the current rendering pass.

`OriginalApparatusActions` in
`godot/scripts/original/original_apparatus_actions.gd` transcribes this
manual numeric/state branch. Its `plan_manual_action(vessels, selected_index,
command, scale)` returns native field writes and the resolved source, target
and request amount. `execute_manual_action(..., reagent_map)` applies those
writes and invokes `OriginalTransfer`.

The input contract requires original active `native_bitmap_width` and
`native_bitmap_height`, native integer center coordinates, type/subtype
fields, and a freshly computed `native_liquid_height` marked
`native_liquid_height_fresh=true` for aspiration candidates. Missing live
height/dimensions produce an explicit unresolved-data error. No estimated
`volume/capacity * height * arbitrary factor` is supplied. The falling-drop
VCL animation is identified by an `animation_boundary` result rather than
silently replaced with another geometry algorithm. The native liquid-renderer
transcription, the main MouseDown/MouseUp routing, object hit masks and
falling-drop drawing remain separate dependencies before claiming complete
manual-interaction equivalence.

### Original-instruction callback verification

`tools/original_actions_oracle.py` subclasses the existing bounded x86 oracle
and executes the actual `0x00477708` instruction body. It hosts only the
declared VCL bitmap constructor, dimension setters/getters, `GetCanvas`,
initial `Rectangle` presentation, and existing AnsiString/lookup boundaries.
There is no hosted recipient-selection predicate, comparison, dose formula
or command-state handler. At the original `0x00476DDC` entry it captures
stack source/target indices and the request's raw eight bytes, then returns;
liquid-transfer arithmetic is independently verified by the transfer oracle.

Every callback frame explicitly supplies its native bitmap dimensions,
integer coordinates, subtype/size, +0x30 height and dropper slot volumes.
It sets the selected +0x4320 total cache to zero as a declared input to skip
the purely visual falling-drop animation. That choice does not skip recipient
selection or the eventual manual transfer call; it does not establish that
the current renderer produced those height values in the actual application.

`evidence/original_logic/native-actions-oracle.json` records 729 executed
native frames. `tests/test_original_apparatus_actions.gd` passes all recorded
source/target identities, requested-dose binary64 bits and +0x68 state
writes. Coverage includes all four supported selected types, commands 0–4,
three scales, eight eligible and two ineligible recipient types, unsupported
selected types, empty-first-source aspiration, existing dropper volumes
0–3, strict mouth/surface/bottom boundaries, overlapping recipients with
integer-truncated scores, odd bitmap heights and fractional scales. Floating
input heights/scales/volumes and native output doses are decoded from byte
strings, avoiding Godot JSON decimal conversion differences.

This is a bounded scalar/state callback comparison with explicit VCL property
boundaries. It is not execution of the whole Windows app or verification of
native bitmap pixels, event hit-testing, current liquid-height rendering,
animation, or every possible floating-point edge case.
