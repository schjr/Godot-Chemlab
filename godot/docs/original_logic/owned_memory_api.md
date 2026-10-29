# Owned memory API for a fresh reconstructed process

`OriginalOwnedMemoryApi` supplies the original allocator's narrow API contract
without pretending to allocate inside the original application. Logical DWORD
addresses come from explicit caller-supplied virtual/local domains using an
ordered first-fit policy. They are not OS pointers or target observations.
Every response/state marks `fresh_reconstructed=true` and
`native_vcl_verified=false`. No process access or native GUI attestation occurs.

Initialize with `scope`, `virtual_domains`, `local_domains`, `exclusions`,
`lock_domains`, page_size4096, allocation_granularity65536, and an explicit
power-of-two local_alignment≥8. Each range is `{address:int,size:int}`. Allocation
domains must not overlap. `bind_memory(heap.vm.byte_memory)` must occur before
allocations; existing image/stack/other mapped pages intersecting an allocation
domain require explicit exclusions. `dispatch(request)` is directly usable as
an OriginalSharedHeap boundary callback. Dynamic addresses remain inside owned
metadata; they are never passed as raw host pointers.

## Supported memory contract

VirtualAlloc supports reserve2000 with source protection1(NOACCESS) or4(RW),
and commit1000 with protection4. Source52FB19/52FB23 requests reserve protection1;
52FB69/52FB76 and52FB92/52FB9B request reserve protection4. Commit at52FCEA/52FCF5
uses protection4. Unsupported flags/protections, including combined3000, return
an explicit unsupported-boundary error. Ordinary domain exhaustion, overlap,
unreserved commits and invalid address/size outcomes return the API's zero
failure carrier, rather than a fabricated successful block.

Hints round down at allocation granularity for reservation and page size for
commit; all touched pages are included. Repeated commit is legal. A reservation
only owns logical address space; the OriginalSharedHeap callback establishes
page-byte origins. Fresh commits are defined zeros, whereas a repeated commit
preserves existing bytes. These follow the documented
[VirtualAlloc contract](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualalloc).

VirtualFree supports decommit4000 and release8000. Release requires the exact
reservation base and size0; it invalidates that complete reservation.
Decommit keeps the reservation and permits already uncommitted pages. The
metadata provider also normalizes base+size0 into the full reservation span.
Invalid ranges fail without partial metadata mutation. See
[VirtualFree](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualfree).

LocalAlloc supports flags0 only. Its returned pointer has no invented payload
or ZEROINIT claim; unwritten bytes remain unknown in the original byte heap.
Local domain exhaustion returns0. LocalFree, movable blocks and other flags are
outside this source subset. This distinguishes fixed allocation from the
separate zero-initialization flag in
[LocalAlloc](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-localalloc).

The standalone provider owns logical range/page metadata; OriginalSharedHeap
owns physical byte-page effects. Its existing callback driver applies the
original aligned reservation and nonzero decommit shapes. General Win32
unaligned reservation hints or size0 decommit need the driver to consume the
provider's normalized reserved/decommit spans before use in that byte world;
this module does not patch or silently extend the existing driver. Direct
metadata contract tests cover those normalized responses separately. No original
allocator path tested here requires those extra driver shapes.

## Real locks, opaque storage and source audit

InitializeCriticalSection creates an actual `OriginalOwnedRecursiveLocks`
mutex with an explicit new source identity/lifetime scope. Enter/Leave execute
real blocking recursive mutex operations; wrong-owner/unbalanced release fails.
Delete requires balanced ownership; reinitialization after deletion creates a
new lifetime, while duplicate initialization of a live identity fails.
Identities must lie in explicit static lock domains, active local allocations,
or committed owned virtual pages. Live-lock allocation release/decommit is an
explicit unresolved-lifetime boundary until source deletion, not an invented
successful cleanup.

The24-byte native CRITICAL_SECTION storage becomes unknown after initialization.
No synthetic struct words are produced from Godot mutex state. `map_unknown`
alone does not invalidate previously known PE bytes; this provider explicitly
clears the known mask too. The static audit
`tools/audit_original_heap_lock_reads.py` checks every retained instruction's
bytes against the mapped original image and records12 uses of source identity
59B184, all direct arguments to Init/Enter/Leave/Delete APIs, with no absolute
interior load/store. The retained allocator also passes actual exercised paths
with all24 interior bytes unknown. This bounded audit does not claim that
arbitrary application/API code never reads those internals.

## Verification and limits

The focused test uses the retained original allocator for a fresh4348-byte
allocation, real recursive source locking, byte fill/free/next allocation and
unknown LocalAlloc tables. A guarded reuse sequence independently compares
source-selected pointers and every complete committed-page hash against the
existing actual-PE `original_shared_heap.json` fixture. It also exercises the
SharedHeap callback byte layer's repeated commit, decommit, recommit-to-zero
and complete release. Domain exclusions, overlap, exhaustion, unsupported flags,
opaque lock storage, duplicate initialization, deletion/reuse and unbalanced
unlock have focused checks.

The source instruction reference and ordinary memory-contract checks are
separate evidence: this test does not execute actual Win32 VirtualAlloc on
macOS, does not claim native Windows address placement, and does not treat
fresh-page zeros as proof of an old heap's unused cells. No active frame or
production module was edited. The shared VCL-world owner can consume this
provider using the same byte memory and one common lock-owner path.

Final focused result:125 checks pass, zero failures. No Windows GetLastError
value is fabricated; supported ordinary failure responses carry only0.
