# Numeric allocation storage in the reconstructed process

The production host now uses `OriginalRuntimeAllocation` for its apparatus
numeric storage. This fixes the earlier production failure in which new species
rows appended by native air initialization exposed absent particle cells.
Previously only tests that attached an observed or declared numerical profile
could supply these cells.

Each host owns a fresh reconstructed process allocation world. It executes the
retained original System `5306B0`/`530838` allocator instructions over
`OriginalOwnedMemoryApi`: real recursive locks, source arena splitting/reuse and
the original byte-validity masks. Apparatus requests are the source `4348` bytes.
The five physical 100-QWORD arrays and four scalar offsets use
`OriginalHeapVesselView`; known bytes are projected at their physical indices.
Freshly committed pages have the operating-system zero origin already modeled
by the API boundary. A freed/reused block retains whatever the allocator leaves
there. No particle cell is assigned zero merely because it is missing from a
Dictionary, and no runtime capture or numerical test profile is loaded by the
production owner.

The host binds allocation storage before import/create recalculation, commits
source numerical writes back to its block, and invokes source FreeMem on object
removal, reset and document replacement. Working-array copies retain the same
live allocation token. Saves retain all known physical numeric cells but omit
the process token. Loading always creates a new owned identity and overlays the
explicit saved numeric bytes; foreign/serialized pointers are never trusted.
Imported observations can still replace explicit cells through their existing
validated diagnostic path. The host's explicit `attach_profile` operation treats
its validated observation as the authoritative checkpoint for the observed
arrays/scalars, replacing this runtime's projections and committing those bytes
to the owned block. The lower-level RuntimeProfile API retains its existing
preservation of explicit caller writes.

The owned address placement, fresh stack and selected default System manager are
declared runtime choices for this reconstructed process. They are not a replay
or claim about a historical Windows ChemLab heap. Godot's strings, forms and
graphics still do not replay every Windows GUI allocation client into this
numeric owner. Consequently this change establishes functioning source
numerical storage and retained allocator semantics, not identical stale bytes
to every possible original process history. Older documents describing a
complete captured GUI heap as the only production path predate this explicit
fresh reconstructed process integration.

`test_original_runtime_allocation.gd` drives normal import, Run and initial
frames for the 28 original documents without observing or injecting allocation
cells. Its separate guarded source allocation/free/reallocation sequence checks
that an inactive nonzero particle QWORD survives genuine chunk reuse.
