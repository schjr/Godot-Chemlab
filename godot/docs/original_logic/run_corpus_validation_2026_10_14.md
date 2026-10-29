# Original Run numeric corpus, 2026-10-14

The corrected current host matches a fresh actual-PE first-Run corpus for all
28 supplied CEM examples. `tools/original_run_corpus_oracle.py` executes retained
`0043DE5C` instructions and writes `tests/fixtures/original_run_corpus.json`.
`tests/test_original_run_corpus.gd` imports the original CEM fixtures and compares
`OriginalModelHost.start()` at Run return. No earlier frame fixture was replaced.

The test passes 84,500 physical QWORD comparisons across 169 apparatus records:
100 cells in each of five arrays, including inactive allocation cells. It also
checks 1,183 scalar QWORDs, exact active species and selected-reaction order,
connector counter clearing, Run flag and elapsed-time reset. Comparisons use
raw eight-byte values without tolerances. Of the array cells, native instructions
write 789 originally active and 1,596 originally inactive cells; 82,115 unwritten
cells retain their exact input bytes. Counts refer to distinct physical cells,
not the number of individual instruction stores.

## Executed source order and fields

The actual first-Run callback clears apparatus `+3CC8` and `+4318`, and clears
`+3CD8/+3FF8` only through the original pre-Run active count. Connector `+70/+78`
are reset. It then calls `43F7BC` while stopped, resets elapsed time, saves the
before-Run document through `42DC3C`, prepares selected reactions with `46C894`,
initializes air with `48E9B4`, and sets the Run flag. There is no quantity
recalculation after air initialization in this callback.

Inside the declared stopped-refresh boundary, the oracle executes real
`4624D8` quantity instructions and `471650` liquid-display numeric instructions
before preparation/air. The latter must be included: six original inputs have
liquid volume slightly above capacity after recalculation; original drawing
clamps their scalar volume to capacity before air initialization. Initially
omitting that display mutation produced six scalar discrepancies even though
all physical array cells matched. The revised fixture executes that mutation
instead of copying or rounding expected outputs.

| Recorded field | Original apparatus offset |
| --- | --- |
| contents | `+08D8`, 100 QWORDs |
| native_species_mass | `+0298`, 100 QWORDs |
| native_species_volume | `+05B8`, 100 QWORDs |
| solid_3cd8 | `+3CD8`, 100 QWORDs |
| solid_3ff8 | `+3FF8`, 100 QWORDs |
| native_liquid_volume | `+4320` |
| native_gas_moles | `+4328` |
| native_gas_volume | `+4330` |
| native_solid_volume | `+4338` |
| native_particle_3cc8 | `+3CC8` |
| solid_4318 | `+4318` |
| native_pressure | `+00A8` |

The reference records actual native memory-write addresses in these array
ranges. Reaction names and species names are read from the actual resulting
native record order. The fixture includes the executable SHA256 and the
prepared example dataset SHA256.

## Explicit boundaries and limits

This is a bounded numeric callback reference, not a complete VCL Run execution.
The original PE is the hash-pinned retained executable; ordinary finite
arithmetic is evaluated by the native oracle under its declared PC64 policy.
The source UI enabled/repaint calls, chart/association portions of `43F7BC`, GDI
pen/brush/raster calls, and `42DC3C` file saving remain hosted boundaries. Original
bitmap dimensions are supplied from recovered sprite metadata; no fake bitmap
pixels or renderer output are introduced. The backup flag is explicitly zero
(first Run); the prior-backup save branch is not covered.

All 100 numerical cells are explicit isolated test inputs. Originally active
moles and masses retain their CEM inputs; remaining amount/mass cells and all
volume/particle cells receive nonzero exactly representable dyadic sentinels.
Counter seeds are 13.25/17.5 and connector seeds 19.75/2. This reveals unwanted
clearing or writes to inactive cells. It does not infer that the real allocator
uses these values or initializes unknown cells. The production host receives
this profile only inside the acceptance test through `OriginalSlots.observe`;
there is no runtime default or allocation-policy change.

`test_original_gas_operand_order.gd` now compares the current production helper
and first-Run cache state by default; all six conversions and the isolated Run
case pass. The six previously observed Windows inert-gas ULP differences remain
a separate unresolved execution-context/live-operand question. Neither this
corpus nor the multiplication-order correction claims to resolve them. No
accepted idle tick, full particle frame, save-file side effect, OS message
behavior or complete bitmap image is proved by these Run-return checks.
