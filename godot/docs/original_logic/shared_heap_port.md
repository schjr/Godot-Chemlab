# Original shared byte-heap port

`OriginalSharedHeap` executes retained original x86 allocator instructions;
it does not transcribe splitting, free-list ordering or reuse into a new
allocation policy. The original image SHA256 is
`7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c`.
`tools/compile_original_heap_ir.py` retains1,870 instructions from52F950
through530D58, original MemMove530DFC and exception cleanup531BE0. The
mapped original PE image includes loader-defined BSS; its separately
verified image hash is in `original_heap_ir.json`.

## API and bootstrap

Create a new `OriginalSharedHeap` and call
`initialize_fresh(boundary, observed_manager, thread_context)`. The manager
input must explicitly identify fallback dispatch534428 and raw System
GetMem5306B0, FreeMem530838, ReallocMem530BAC. The exported process9348
observation matches this identity; it does not justify assuming another
process selected it. See `observed_allocator_identity.json`.

The thread context must supply FS base, exception head, stack base/size,
stack pointer and provenance scope. Stack bytes require either an explicit
fresh committed-page origin or complete observed bytes. Win32 callbacks
must return actual/chosen API results for VirtualAlloc, VirtualFree,
LocalAlloc and critical-section operations. Reservation placement is a
boundary input. Failed results are passed back to original instructions;
unresolved callbacks fail explicitly.

`get_mem(size)`, `free_mem(pointer)` and `realloc_mem(pointer,size)` execute
the raw System methods with their original register ABI. These are not the
higher-level530C70/530C88/530CA0 wrappers: callers must not assume those
wrappers' null/zero conventions. `read_bytes` and `write_bytes` operate on
original32-bit virtual addresses. `to_state` records byte pages, validity,
reservation/commit state and observations; importing a complete live heap
checkpoint into the shared heap is not implemented. `close()` releases
callback references.

`OriginalHeapVm` adds only required integer/memory instructions to the
existing numeric interpreter: OR, XCHG, signed JS, direction flag and
original forward/backward MOVS. Allocation headers, tables, node pools,
coalescing, copying and commit decisions execute original retained code.

## Byte origin rules

LocalAlloc flags0 does not request zero initialization. If its provider
omits payload bytes, accessible cells remain unknown; original writes mark
only the cells they actually define. Unknown reads stop with an explicit
error. Known zero is distinct from unknown. Decommitting removes payload;
committing an already committed page retains its bytes. A newly committed
page receives zero according to the [Win32 VirtualAlloc contract](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualalloc).
Raw apparatus4348 blocks are not automatically initialized like original
class instances whose InitInstance531414 zeros the class body.

## Actual native validation

`tools/original_heap_oracle.py` executes the original PE in Unicorn with
explicit hosted Win32 boundaries. Four cases contain74 operations:
guarded4348-byte reuse, arena-start decommit, realloc grow/move/shrink and
mixed original client sizes. `test_original_shared_heap.gd` passes5,655
checks of return/pointer addresses, exact globals/list/table bytes, every
committed-page hash, reservation state and API calls. The diagnostic
LocalAlloc payload is A5, not a proposed Windows default. Mixed operation
selection uses a deterministic test seed, not the application's RNG.

`test_original_heap_boundaries.gd` separately passes with LocalAlloc payload
omitted. The original allocator initializes its needed list cells while
unused bytes remain unknown. It also verifies unknown-read failure,
byte-validity state restoration and decommit/fresh-page origin behavior.
The MEM_RELEASE reference probe was corrected to log its actual API size0
rather than the internally released reservation size; no allocator source
behavior was altered to satisfy that logging correction.

## Integration prerequisite

This is a fresh allocator kernel world, not the original GUI startup heap.
Production needs either a scoped complete native heap checkpoint or the
original shared allocation/free/write history, including VCL objects,
managed strings, bitmap storage, temporary clients and apparatus blocks.
Replaying apparatus requests alone does not establish the preceding free
lists or their retained payloads. No universal zero slots, assumed process
seed or per-example fabricated profile was added, and no production model,
canvas or arithmetic code was changed by this module.

Packaging must retain `godot/data/original_heap_image.bin` and
`godot/data/original_heap_ir.json`; absence/hash mismatch is an explicit
bootstrap failure. A future checkpoint importer must validate manager and
source identity, original globals59B170..59B1E8, table/node-pool allocations,
reserved/committed ranges, and byte validity before exposing typed vessel
views. Full shared-client startup replay remains the production prerequisite.
