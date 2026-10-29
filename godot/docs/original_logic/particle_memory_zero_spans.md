# Compact explicit particle zero storage

`OriginalParticleVm.map_zero(address,size)` records the exact byte effect of an
explicit source zero operation as sorted merged intervals. Source
`NewInstance53139C → InitInstance531414` clears the Delphi particle object;
`OriginalParticleFrame._alloc(size,true)` and the standalone bubble update now
use this representation. Previously each frame populated hundreds of thousands
of Dictionary entries before executing any particle instructions.

Sparse observed or instruction-written bytes override zero intervals. Repeating
an explicit zero operation removes older sparse writes only inside its requested
range, preserving bytes outside the range. Adjacent zero intervals merge without
making intervening unknown bytes readable. Invalid DWORD address extents are
rejected. No zero interval is added for the plain apparatus allocation or for an
observed particle object; their existing unknown/raw-byte contracts are retained.
The interval index also keeps a small per-page lookup cache: fully covered pages
use one marker, and boundary pages retain exact clipped intervals. Ordinary zero
reads therefore avoid searching every object interval.

`has_byte`, `contains_span` and `read` share this defined-byte contract. The
captured-scanline alias guard uses `overlaps_known_span`, so partially overlapping
known-zero storage is rejected just like observed sparse storage. The only other
production consumer that formerly inspected `vm.memory` directly, the native
interaction string reader, now uses these accessors. `OriginalHeapVm` continues
to override read/write/contains_span with its separate byte-mask memory backend.

`test_original_particle_zero_spans.gd` verifies compactness, exact zero extent,
unknown reads, sparse overrides, repeated-zero writes, adjacent and separate
intervals, partial aliases and address bounds. Existing captured particle-object
and checkpoint tests continue to use their unchanged raw bytes.
