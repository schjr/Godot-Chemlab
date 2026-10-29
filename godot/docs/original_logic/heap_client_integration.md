# Smallest exact shared-heap integration step

Update2026-10-18: the bounded view below is now used by the production
`OriginalRuntimeAllocation` owner. See
[production runtime allocation](production_runtime_allocation.md) for the fresh
reconstructed process contract, lifecycle and distinction from historical
Windows GUI heap replay. The description below records the earlier integration
boundary and the evidence still required for a claim of historical heap identity.

The current host's `add_apparatus` calls OriginalFactory.create, obtains a
Dictionary, binds simulation fields, and appends it to the host list. It
never calls original GetMem or the original string/font/bitmap constructors.
Factory templates faithfully represent a finite metadata-writing branch,
but cannot establish an allocation address or the previous bytes of its
4348-byte apparatus block. The current host must not treat a fresh isolated
allocator's returned bytes as the original GUI's initial heap history.

## Exact constructor/load boundary

Retained `constructor_evidence.json` records source43281B..4329B3:

1. Push4348 at43281B; operator-new533AD8 at432820.
2. Empty CString4016E8 at apparatus+04,+80,+90,+94,+98.
3. Font constructor416D28 at+E8; CString4016E8 at+EC.
4. Array constructor533F34 creates100 CString4016E8 elements of stride4
   at+108,+BF8,+D88. Cleanup callback540FE8 is recorded, not executed on
   successful construction.
5. Array constructor533F34 creates50 reaction records of strideE8 at+F20
   using416B30 (destructor416C0C).
6. Publish pointer into585850[index] at4329A0; invoke453A28 at4329AD.
7. Source43240C then creates the VCL object at+F0 through403BD4 and reads
   persisted CEM fields; bitmap/list creation and string parsing proceed.

Empty CString4016E8 zeros its pointer member, not the apparatus block.
Reaction416B30 zeros selected managed-string members. Font416D28 and VCL
calls are allocation clients: omitting them changes the shared heap before
later vessels are allocated. A successful constructor slice therefore cannot
be advertised merely by writing its obvious zero members or by replacing
these clients with no-ops. CEM string reads and temporaries also allocate and
release shared blocks. The source precedes apparatus loading with original
file/dialog/form activity; this is not represented by current host state.

## Implemented bounded adapter

`OriginalHeapVesselView.bind(heap,pointer,provenance)` attaches a read-only
view to an explicit4348-byte allocation. Provenance requires original image
SHA, matching pointer, request size and scope. This is a caller's declared
allocation identity, not an automatic validation of an entire live process.
It deliberately does not allocate or execute a constructor.

`snapshot(ordered_names)` returns the existing OriginalSlots backing shape
for all five100-cell numeric arrays and raw QWORD scalars3CC0,3CC8,4318,
4338. These use exactly the existing RuntimeProfile keys:3CC0=`gas_3cc0`,
3CC8=`native_particle_3cc8`,4318=`solid_4318`,4338=`native_solid_volume`.
3CC8 and4318 are particle/counter fields, not physical gas/liquid volumes.
OriginalQuantities physical liquid/gas volumes are4320 and4330 respectively;
this four-scalar observation adapter does not alias or capture those fields.
Known bytes are preserved exactly, including inactive subnormal or
nonfinite bit patterns. Unmapped/unobserved cells remain null. The view
checks validity masks before reading, so observing an unknown cell never
turns it into zero or poisons the interpreter. Names come from explicit
source row order; no species-to-slot guess or numeric normalization occurs.

`test_original_heap_vessel_view.gd` passes scoped-identity rejection,
physical-index retention, inactive negative-subnormal preservation and
unknown-cell behavior. This tests the adapter contract; it does not claim
GUI startup equivalence. No host/main/canvas integration was performed.

## Next integration input

The smallest production connection is an explicitly scoped initialized
shared heap plus the real apparatus pointer and source-ordered names. The
view can then expose its bytes without changing chemistry or inventing
constructor writes. To obtain such a heap, capture or execute:

- selected manager pointers and source module identity;
- original globals59B170..59B1E8 and all linked LocalAlloc tables/node pools;
- every reserved/committed arena range and its bytes;
- allocation provenance identifying apparatus pointers at that checkpoint;
- thread/exception context and source client event ordering after checkpoint.

The exported five numeric arrays per vessel are not a complete heap
checkpoint: they do not determine free lists, node pools, object/string
blocks, original bitmaps or preceding allocations. Manager identity alone
selects the kernel but supplies none of that history. Capturing a checkpoint
immediately before the first relevant new/reload allocation permits a
bounded next-operation test without replaying all GUI startup. Afterward,
source constructor and managed/VCL allocation calls must execute original
code or use a fully recorded allocation/write/free transcript; their output
pointer values cannot be replaced with unrelated Godot object identities.
