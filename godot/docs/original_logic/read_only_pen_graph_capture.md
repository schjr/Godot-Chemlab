# Read-only original pen graph capture

Run `tools/windows/read_original_pen_graph.ps1` in a **fresh** PowerShell process
with the existing reviewed `original_dib_read_probe.cs` beside it. It writes
`%TEMP%/CodexVclPenState.json` and Desktop `vcl-pen-results.zip`; the archive
contains the JSON, exact PowerShell source and exact C# reader source. Existing
outputs are preserved by refusing a rerun that would overwrite them.

The probe requires PID9348, original imageSHA256
7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c,
module base400000, the six explicit vessel pointers, run2/pause0, count6 and
elapsed bytes6cbc749318445240. Its C# dependency is pinned toSHA256
f366f56e3a842384cb26395e14ce14361aab0bfb70f34121d3ae80331e263839.
The reader opens only PROCESS_VM_READ|PROCESS_QUERY_LIMITED_INFORMATION.
It neither suspends nor changes the target, calls target methods, accesses
GDI through captured target handles, elevates, changes policy nor uses network.

Each traversal records full4348 vessel bytes, existing FC/F8/F4 TBitmaps,
source-used complete solid pools and their primary/retained bitmaps. It captures
TBitmap34 bytes (original instance-sizeDWORD at4E2ACC is34), shared image74
bytes, existing TBitmapCanvas64 bytes and TPen1C bytes. A missing Canvas is
explicitly unavailable: no constructor or GetCanvas target invocation occurs.
Non-null objects must match exact source VMT4E2AF4/4E80D0/4E2420. Pen event
must be4E4DEC with the same Canvas owner, and pen lock must equal Canvas+38.

Registry global59A9E4 must reference original TResourceManager VMT4E2D1C.
Its full24-byte header includes list head+4, embedded24-byte critical section
at+8 and record-sizeWORD+20. Source initialization4EB3AD–4EB3BD establishes
record size16. The entire linked list is captured in traversal order, each node
32 bytes: next+0, refcount+4, handle+8, checksumWORD+C and16-byte payload+10.
Every observed TPen shared-record pointer must occur in that full list. Stock
pen global59A9A0 and critical-section raw bytes are captured without calling
OS functions on them. Immutable code/VMT spans are hashed against original PE
bytes, including inherited dynamic methodFFFD→4E34D4 and event4E4DEC.

The whole graph is traversed twice. Every raw blob, graph link, registry order,
checkpoint value and unavailable status must be exactly equal. Shared objects
are also checked on repeated references inside each traversal. Cycles,
unreadable bytes, differing source identities, more than512 registry nodes or
2048 blobs fail explicitly; these are probe safety limits, not claimed native
limits. No truncated graph is written.

The graph preserves source state required for an isolated exact registry/pen
setter port. Captured process-specific handles remain identities, not usable
handles for another process. No pixel-derived pen state is supplied. Equality
of two reads establishes an unchanged observed graph across those reads; it
cannot prove an atomic snapshot or that pending original GDI work was drained.
Output always retains `native_vcl_verified:false` and TLS unobserved.

Local validation: four Python source/identity tests compare the pinned spans,
class instance sizes and dynamic dispatch table against the actual original PE,
verify the reviewed C# import/access set, and check complete-graph rejection
and archive safeguards. PowerShell/Windows execution is pending until the
probe is actually run on the pinned original process; no successful capture is
claimed by these static checks.


## Returned archive validation

`tools/analyze_original_pen_capture.py returned.zip --sha256 ACTUAL_SHA256
--output-directory NEW_DIRECTORY` imports only the exact JSON/PS/CS member set.
It rejects duplicate/traversal/extra entries, encryption, symlinks, excessive
sizes, wrong source hashes, wrong source code/VMT bytes, incomplete or changed
checkpoints, digest corruption and contradictory overlapping raw observations.
It verifies every bitmap/Canvas/pen owner, event, lock, shared record and complete
ordered registry crosslink, preserving missing Canvas states. All full vessel
and source-used solid pool bytes must still equal the pinned prior actual
particle checkpoint. Bitmap/Canvas object bytes newly observed by this probe
are not falsely compared to an earlier unobserved pen graph.

The new directory preserves the original JSON and both source files, plus
`isolated-pen-graph.json`: full raw blobs and graph links suitable for isolated
VM loading, with absolute addresses preserved. It explicitly denies production
VCL/startup verification, drained GDI state, usable target handles and inferred
TLS. Existing output directories are refused before import. Eight local tests
use explicitly synthetic graph/transport fixtures to test successful preservation
and reject cycles, omitted nodes, corrupt/rehashed source/event/lock/crosslink
bytes, changed checkpoint/pool bytes, duplicate blobs, wrong archive members,
wrong source/ZIP identity and overwriting prior evidence. Actual returned archive
validation remains pending; these tests do not manufacture capture evidence.


The reviewed reader was corrected before any target graph bytes were captured:
Windows PowerShell5 interprets literal `0xffffffff` as signed Int32−1. The
address maximum now uses decimal4294967295. Current readerSHA256 is
4a1d7c2b11470b1fe6c7d734b1d4978e01765a0fbc021e8219027291f627d4f8;
the importer pins only this corrected source. The old package remains preserved.
A source regression checks the decimal DWORD bound explicitly. The failed old
attempt produced no capture output and is not evidence of successful reading.
The original return archive must still contain `read_original_pen_graph.ps1`;
the executed basename controls the PowerShell archive member name.


The next Windows run traversed the graph but stopped before source identity
validation: PowerShell pipeline output flattened the nine identity-span arrays.
Each row now uses unary comma `,@(...)` to retain its nested array. Current
reviewed readerSHA256 is
cea024c2ed7fac84f2d63d6a000bfea70e96df63db33e73376d5a0a49aa31546.
The importer pins this version; another regression verifies all nine nested
rows. This interrupted run also emitted no completed capture.
