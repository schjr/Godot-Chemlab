# Inert-gas operand/store audit, 2026-10-14

This audit read the existing original Windows captures and retained PE without
changing the guest or production arithmetic policy. Original executable SHA256:
`7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c`.
Reviewable reproduction is `tools/original_gas_operand_order_oracle.py`, output
`tests/fixtures/original_gas_operand_order.json`, and Godot comparison
`tests/test_original_gas_operand_order.gd`. The default test validates source reference arithmetic and compares production
conversion and Run caches strictly, with no tolerance or substituted captured
output.

## Concrete discrepancies found

### Conversion order and difference store

Initializer48E9B4 stores free capacity minus liquid volume to QWORD at48EAE6.
It sums other gas moles into a QWORD accumulator, multiplies by QWORD22.4 and
DWORD1000 at48EBA5/48EBAB, and stores that gas volume at48EBB1. The fill path is:

| Instruction | Original effect |
| --- | --- |
|48EBC3/48EBC6|Load stored free volume; subtract stored gas volume.|
|48EBC9|Store difference to QWORD `[ebp-5C]`.|
|48EBCC/48EBD2|Load extended80 A; multiply **stored difference**.|
|48EBD5/48EBDB|Load extended80 B; multiply previous product.|
|48EBEA|Store final amount to the INERT mole slot as QWORD.|
|48EC16/48EC26/48EC3A|Load looked-up reagent molar mass, multiply stored mole amount, store mass QWORD.|

Open-gas46EC50 uses the same conversion order at46F418/46F41E/46F424/46F42A,
after its difference QWORD store at **46F3E5**;46F42C then adds the existing
stored INERT moles before final QWORD46F433. An earlier preliminary message
named46F3D1; the aligned retained instructions establish46F3E5 instead.

The previous `_inert_amount` implementation multiplied `(A*B)*extendedDifference`.
It both reassociated the multiplies and omitted the difference's QWORD boundary.
Two independent native counterexamples establish the consequences:

| Input | Actual original48E9B4 | Previous helper |
| --- | --- | --- |
|Empty headspace27.34703538773724 mL (`d9e2a84fd7583b40`)|`c90d187c9d00543f`|`ca0d187c9d00543f`|
|Capacity30.694220260404236 mL (`24a8426bb8b13e40`), O2 amount0.00027610799525626384 mol|`df3596c347ed513f`|`de3596c347ed513f`|

For the second case, stored other-gas volume is`f9296d3741bd1840`, and the
native stored difference is`a65d671d68823840`. Correct multiplication order
**without** the difference store still produces the wrong`de...` result. An
independent exact-rational,64-significand nearest/even calculation matches the
actual retained PE in both counterexamples. The six-case native fixture also
includes2,4 and110 mL and a tiny existing O2 amount.

Parent applied the narrow production correction: QWORD-store input, then
`(A*storedDifference)*B`. All six native conversion cases now match. This does
not alter x87 precision or claim to fix the captured empty-dropper difference.

### Run initializer sequence

Actual first-Run43DE5C with backup flag`Form+E1B=0` records:
`43F7BC→4624D8→42DC3C(save boundary)→46C894→48E9B4→run=1`.
The source calls43F7BC **before** selected-reaction preparation and air
initialization. There is no quantity recalculation after48E9B4 in this callback.

The isolated actual-PE Run fixture therefore leaves a4 mL empty dropper with
INERT moles`b1a934e4dc67273f`, mass`c8b9cf2e2036753f`, **species volume0**,
and gas-mole/gas-volume aggregate caches0 immediately at Run return.48E9B4
explicitly resets the INERT species volume slot to0 and fills only moles/mass.
The following accepted idle callback recalculates quantities later.

The prior host instead recalculated and refreshed after air initialization.
The opt-in regression initially reported immediate species volume
`ffffffffffff0f40` instead of the original0. The earlier FrameOracle startup
also used ensure→air→recalc→render, so an unchanged fixture from that setup is
not independent proof of43DE5C's Run-return cache state. Parent has corrected the host startup order; the default regression now passes
against production. The new all-28-example reference in
`run_corpus_validation_2026_10_14.md` preserves older frame artifacts and tests
the actual Run order with explicit nonzero numeric allocation inputs.

The Run oracle uses declared UI enabled/repaint, save, and stopped-graphics
boundaries. It executes actual4624D8 inside that stopped boundary, plus actual
43DE5C/46C894/48E9B4 instructions. The first-run backup flag is explicitly0;
backup flag1 and complete VCL/bitmap behavior are outside this fixture. Numeric
heap bytes are the isolated harness's explicit zero allocation input, not a
claim about real allocator initialization.

## Why these corrections do not explain the captured six differences

The reported six diagnostic differences concern two empty droppers: a volume
comparison at "Run", then a mole and mass difference after an idle. That "Run"
comparison uses a later paused capture (45.391 seconds in the second session),
not an actual immediate-return Run capture. Its volume4.0 is therefore not
proof of the cache value at43DE5C return; the native fixture establishes0.

For the actual empty4 mL case, subtraction is exact and multiplication by4
is an exponent shift. Both conversion associations produce the same initial
mole bits`b1a934e4dc67273f`. For the withdrawn2 mL case the same holds.
Thus the newly corrected conversion helper cannot explain the remaining
captured4/2 mL mole-volume combination.

The initializer's molar record is original `惰性气体(气体)`, JSON/raw-library
mass29 and density/render parameter0.00129. Only mass29 is used here; density,
temperature, timezone and DST do not enter the hardcoded gas-volume multiply.
Given observed initial mole bits`b1...`, native-style64-significand consecutive
FMULs produce gas-volume QWORD`ffffffffffff0f40`, while the capture records4.0.
Observed mass`c8...` is exactly the64-significand29*moles QWORD; it is a dependent
consequence, not an independent mass-law discrepancy. With source volume below
free4 mL, the original open-gas fill condition admits a correction; the current
PC64 model then advances to mole bits`b2...` and corresponding mass`c9...`.
No unknown stack operand is read along this ordinary empty-dropper branch:
48E9B4's free/gas/difference locals and46EC50's gas sums/free/difference are all
initialized before use.46F704's separate known stack boundary is not a substitute
explanation for this scalar conversion.

## Missing observable input

The new full vessel bytes corroborate all3,000 previously captured numeric
cells. Relevant raw fields match the original opening configuration: type204,
subtype4, capacity4.0, upright0, mouth0; empty dropper liquid volume0. The
withdrawn dropper has the observed nearly2 mL liquid volume, INERT amount
`b1a934e4dc67173f` and gas volume2.0. Stored FPU policy bytes`3213`, timezone
`808fffff` (-28800) and daylight0 do not reveal the live/emulated x87 execution
context. No precision mode was inferred or selected by this audit.

To distinguish a live operand change from execution-context behavior, the
missing read-only observations are the actual process's constant bytes and
reagent operand, and its actual live/emulated floating execution context at
these operations. The image file hash does not separately attest these live
memory reads:

| Live address / size | Original image bytes |
| --- | --- |
|4624B0/8 (quantity22.4)|`6666666666663640`|
|4624B8/4 (quantity1000)|`00007a44`|
|48EC70/8,48EC78/4 (initializer)|Same22.4/1000 bytes.|
|46F6D0/8,46F6D8/4 (open-gas)|Same22.4/1000 bytes.|
|48EC7C/10,46F6EC/10 (A)|`3bdf4f8d976e1283f53f`|
|48EC88/10,46F6F8/10 (B)|`1fba6ddbb66ddbb6fa3f`|
|Lookup result from table57BC08, record+10/8|Original inert molar mass29.0 (`0000000000003d40`).|

An intermediate binary64 rounding diagnostic yields the captured4.0, but there
is no corresponding source QWORD store between46216E and462174. That diagnostic
is not a port rule or proof of its cause. Full-80 compatibility being requested
and stored policy1332 also do not constitute a sampled live arithmetic context.
The six observed one-ULP diagnostic differences remain unaccounted for by the
available runtime evidence. No epsilon, guessed precision, heap-zero default,
inserted gas-volume store or forced captured output was used.

## Read-only operand capture received, 2026-10-15

The subsequent capture from the same pinned PID9348 checkpoint is now saved in
`evidence/windows-runtime/gas-operand-results-2026-10-15`. Archive SHA256 is
`36fb3abe36a300c6e119b42fcf586fc84bf3cdd2e95b83db0f514f6658e7ed28`;
raw JSON SHA256 is
`06c888b34ae64781a55d1222190b70cc82a37e9de0b0fa1dcd617d2ecc83d872`.
The reviewed reader completed two identical full graph passes. The strict
importer validates source identity, raw digests and overlapping spans, the
complete ordered499-record table and all ANSIString bytes/header/terminators.
All103,344 vessel bytes match the prior particle checkpoint.

All ten observed constant spans match their original image bytes. Actual452D9C
first-exact-byte-name selection reaches index491 and its molar mass is still
29.0 (`0000000000003d40`). No changed constant or molar operand explains the
empty-dropper discrepancy at this checkpoint. This capture observes operands
after the earlier arithmetic; it does not observe a prior operation's operands
or live/emulated x87 execution context. No precision mode is inferred and no
production arithmetic rule changes. The remaining six diagnostic one-ULP
differences are still unresolved.
