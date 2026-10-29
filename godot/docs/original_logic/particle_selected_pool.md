# Pool ownership in a selected-vessel particle phase

`step_vessel(index,...)` now constructs and adopts the selected vessel's solid
and bubble objects only. It retains all apparatus metadata and conduit geometry.
Unselected persistent pool dictionaries, bitmaps and scanline tables are left
unchanged and their global pool-table cells are not mapped. Ordinary
`step(...,selected_vessel=-1)` retains the existing complete traversal.

The retained `original_particle_ir.json`, identified by original executable SHA
`7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c`,
contains20 pool-table references:11 to `595214` in `frame_solid` and9 to `5940B0`
in `frame_gas`. In every case the immediately preceding instruction loads the
lookup index register from `[EBP-60]`, the current vessel index. No retained
helper instruction references either table. Helpers receive the current pool
object through their source call arguments. The frame's observed-pointer-domain
reservations still consider the whole scene, preventing an unselected captured
pointer from accidentally aliasing a selected hosted allocation.

`test_original_particle_selected_pool.gd` audits every table reference and
compares selected first-phase state with the same prefix of a complete traversal.
Continuing with the next selected phase matches full persistent scene, vessel
and RNG results. It verifies unchanged unselected state, missing unselected
table/bitmap mappings, retained other-vessel metadata and callback cleanup. The
small bitmap provider in this focused transport test is explicit reference
input; the audit does not make a new native raster equivalence claim.
