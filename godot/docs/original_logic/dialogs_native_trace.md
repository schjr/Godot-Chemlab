# Form4 numeric fields and temporary-row semantics

Recovered `TFORM4.dfm` has chemical name/mole/mass edits, reaction rate/
condition/heat/equilibrium edits and a separate memo label. It does **not**
have temperature or capacity input controls. Source callback49F0C8 commits
prepared temporary globals/ordered rows; it does not impose the former
Godot temperature range[-273,2000], step0.1, or capacity range[.001,1e6].
Those SpinBoxes were reconstruction additions and changed native zero-capacity
stands merely by opening and confirming the dialog.

The temperature/capacity settings are now readonly labels. Their native
scalar double bits and raw native field text are preserved on confirmation;
factory choice and thermal logic own their values. The commit restores the
preserved capacity scalar after `_bind_native` reparses metadata, so a second
Godot decimal conversion cannot alter an unchanged binary64 value. No new
editable controls, range clamp, step or numeric-parser fallback is exposed.

The regression uses original `sb100` and `tiejt0` factory keys, verifies the
stand's zero capacity, and preserves existing zero/sub-.001/full-precision/
outside-old-range scalar states bit-for-bit. These are input-state preservation
checks, not claims that the original Form4 offered an editor for such values.

Chemical edits49FE58/delete4A0A98/clear4A2194 update temporary form rows.
Reaction edits4A14E4/delete4A169C/clear4A2440 update full ordered temporary
records. RowMoved4A253C swaps full records. Confirm49F0C8 copies these back;
Cancel discards them. The Godot property dialog follows this staged behavior,
retains zero-mole named slots and synchronizes native reaction records with
UI IDs/overrides. Nested Form5 additions also affect the temporary snapshot.

The existing `cleanup_deleted_chemical_bindings(original,draft)` coordinator
call remains in the commit path. Its raw helpers are documented in
`vcl_bitmap_profile.md` and `OriginalVariableCleanup`; source-bound mapping
and any inactive table slots remain the coordinator's responsibility.

## Stopped Form4 quantity/mass transaction (2026-10-14)

The original Modify callback49FE58 reads species Edit1, then the checked RadioButton1/RadioButton2. DFM confirms raw TEdit controls Edit2/Edit3 with no OnChange coupling; callbacks4A1444/4A1494 switch which amount field is enabled. Godot's former SpinBoxes clamped to1e6 and continuously converted the opposite quantity. These are now replaced by mutually exclusive radio controls and raw LineEdit text. Conversion occurs only on Modify. Existing grid mass comes from the independent native mass cache, not a recomputed substitute. Missing original mass is an explicit failure.

Native541348 parses the selected text, then49FF6A stores QWORD before the negative check and conversion. The other unit is calculated with the original stored molar mass and x87 arithmetic. Both numbers pass native540F7C (15 significant digits) into grid cells; the callback reparses all grid rows into temporary moles596A90 and mass596450. Confirmation49F0C8 reparses the grid again. The dialog retains those grid strings and copies their parsed doubles only into the draft until confirmation; cancel leaves the live vessel unchanged. Nested additions now carry their explicit dose mass into the temporary mass rows instead of discarding it; their full numeric-input/selector UI parity remains a separate scope.

`tools/original_property_quantity_oracle.py` executes49FE58 with explicit VCL text/grid/radio/focus/message boundaries. Original parser/formatter and arithmetic execute in the PE. All54 cases pass: quantity/mass modes, zero, negative rejection, scientific notation, high precision, tiny1E-20 and large1E99 values, and three valid library species. The reference also records native461E54 mass aggregation after copying the modified rows. `test_original_property_quantity.gd` compares exact grid text and both stored double arrays. `test_native_property_quantity_ui.gd` runs18 existing-HCl cases through real windows, radio buttons, Modify/Confirm/Cancel and compares the stopped caller's mass aggregation bit-for-bit. The broader dialog regression remains passing.

The caller is417750: after closing/destroying Form4 it calls43F7BC only when running global57A6F8=0.43F7BC begins4624D8, then48C428 bindings,48DB24 chart initialization,454E44/459F1C association and presentation. Stopped confirmation's mass recalculation therefore follows original code; a running confirmation is not a supported original user action. FormShow49D418 explicitly disables11 buttons for running or paused states. Retained TForm4 VMT568AE4 field metadata maps+2D0=Confirm, +310=DefineVariable and the nine substance/reaction mutation buttons. The active dialog now disables all11 in both states and keeps Cancel available.

This is a bounded same-species stopped-dialog transaction port. The editable original species-renaming/binding migration path remains unported in the UI. While running, source4018B0 updates the open Form4 grids using CRT53958C; the subsequent section documents its completed exact live display port. Full modal ownership/input behavior, other reaction/settings controls and invalid-format/native exception presentation still require separate ports. This evidence does not certify the complete Form4 or library editor.

## Running Form4 grid (2026-10-14)

The accepted-idle source block is `401D9C..40261D` inside `4018B0`
(`recovered/native/main/decompiled.cpp`, lines581–760). It runs only when
`57A6F4==1` and `100<57A730<300`. The enclosing idle callback accepts physics only in Run state;
Pause does not refresh this grid. Source order is physics/quantity aggregation,
first binding pass, original program `402928`, presentation `48C758`, **Form4
refresh**, second binding `48C428`, graph sampling `48D6E0`.

Chemical rows read ordered names at `+108`, independent moles at `+8D8`, and
stored mass at `+298`. The calls `401E5A` and `401EE7` pass `(double,4,buffer)`
to `538D8C→53958C`. This is the CRT general-`g` conversion wrapper (not the
usual variadic printf ABI): `53958C` passes type `0x67`, precision4, and flags6
to `5392A8`. Its observed output uses four significant digits, lowercase `e`,
an explicit exponent sign, at least two exponent digits, and preserves negative
zero. This differs from stopped Form4's `540F7C`/15-digit FloatToStr.

`OriginalLiveProperty` expands the finite input binary64 exactly in decimal and
rounds to four significant digits, eliminating an intermediate host log/power
or float-to-string conversion. `original_live_property_oracle.py` executes the
original formatter instructions: **194 native references** include both signs,
rounding boundaries, the minimum subnormal, maximum finite double, and exponents
across -320..308. Every output string matches. Nonfinite formatting explicitly
returns unsupported; Windows locale/exception presentation is outside this scope.

The active dialog listens to the model's `native_property_refresh` hook, emitted
after the original program/quantity pass and before chart sampling. It displays
the supplied staged apparatus state, not the previous committed frame. As in
native grid SetCell calls, updating cells does not invoke selection callbacks or
rewrite the chemical name/quantity/mass edits, nor replace stopped-dialog draft
buffers. Reaction rows retain source order and explicitly print every integer
coefficient (including1), with the native ` + ` and ` == ` separators. The
selected reaction's rate/heat/equilibrium details still use source `540F7C`.
The live rate gets a raw read-only text field so a SpinBox cannot truncate it.
Closing the window disconnects its hook.

`test_native_live_property_ui.gd`: **28 actual imports/accepted ticks PASS**,
including all shipped program-bearing examples. It verifies program→grid→chart
ordering, exact chemical strings, unchanged selection edits, paused-state skip,
and hook cleanup. These tests explicitly declare the oracle's observed zero
100-cell numerical backing profile and `46F704` stack boundary. They do not
establish production heap defaults or provide the pending native GDI renderer.
Existing18 native quantity editor cases and stopped dialog regressions still pass.

## Five-field reaction transaction and label/name correction (2026-10-14)

`4A14E4` (`recovered/native/main/decompiled.cpp`, lines51165–51213) reads
Form4 edits at `+330,+338,+340,+348,+350` in that order. It stores parsed
rate, literal condition, parsed heat, parsed equilibrium, and literal mode into
the selected1-based temporary reaction row. Numeric parser `541348` writes each
result to QWORD; there is **no** negative/range clamp and **no** condition/mode
whitelist. The source table addresses are `5970A0/A8/B0/B8/C0 + row*E8`;
these correspond to native record fields `B0/B8/C0/C8/D0`.

The stopped UI now has five raw text fields (Edit4/heat remains hidden, as
in the shipped DFM) and Modify writes the selected
complete draft record. Neither field typing nor Modify affects the live vessel;
Confirm copies the draft and Cancel discards it. Negative rates/equilibrium,
arbitrary condition/mode strings, empty strings, original whitespace and
negative-zero heat survive. Existing coefficient lists, name, note, and other
record fields are retained. Imported `parameters` mirrors are updated in their
actual order `[heat,condition,rate,equilibrium,mode]`. CEM export serialization
now consumes the complete ordered native records. `ExperimentAdapter` retains
each original source-row index independently of names/IDs, saves all five fields
and direction, and preserves swaps, deletion, clear-all and added complete rows.
The adapter checks cover save/reopen with duplicate IDs and stale UI mirrors;
all28 shipped examples round-trip byte-exactly from both JSON and parsed CEM.
Chemical mass is exported from the independently stored native mass field when
known, instead of recomputing it from a mole value and an old mass ratio.

`original_property_reaction_oracle.py` executes the actual callback with hosted
GetText/string ownership only: **15 native comparisons PASS**, covering physical
selected rows1,2,50 and five input sets. All numeric QWORD bits and exact strings
match. `test_native_property_reaction_ui.gd` adds **10 real UI transactions PASS**
(Modify then Confirm/Cancel), testing live-state isolation and exact committed
values. The local port rejects unsupported/invalid/nonfinite numeric input
before committing; original invalid-format exceptions may leave earlier draft
writes and their precise presentation/partial-state behavior remain unported.
This is a finite-valid-input port, not a replacement native exception handler.

A separate audit found the former "容器标签" LineEdit incorrectly mutated the
apparatus identifier at `+04`. Source49D418 copies that string into temporary
`5961BC`;49F0C8 simply restores it, with no Form4 apparatus-name control. The
actual label control is Memo1 at Form4`+3C0`, populated from the separate
TStringList at vessel`+F0`. Source49F0C8 commits its memo/font then computes
`+CC` as maximum absolute original GDI TextWidth through
`4E49C0/5394D4/5394FC`. Exact assembly `49F5C0..49F5DF` computes `+D0`
as the native integer conversion of `abs(double(linecount * font-field596294
*1.1))`, retaining x87 multiply order and QWORD store before5394D4/5394FC.
The1.1 constant is the actual binary64 at49FE50.596294 comes from native
font getter4E3B44, which reads `[font+10]+14`; no Godot font estimate is used.

The active properties dialog now shows an informational apparatus name and
separate memo label draft, preserves `+04` on every confirmation, and **rejects
changed memo commits** with an explicit metrics-required message until an exact
native font provider is available. Cancel works without modifying either label
or identifier. Existing native label metadata is retained on unchanged commits;
this does not claim to rerun missing GDI font measurements. Edit9 atForm4`+388`
is the hidden shipped hint control (`+94`, temporary59624C), not a label/name
control; its value now comes from and returns to that exact field. Font editing,
label geometry recalculation, complete modal ownership, and original exception
presentation remain bounded gaps. No guessed dimensions or multiplier were introduced. The label guard/name preservation regression passes.
