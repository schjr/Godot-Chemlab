# One reconstructed VCL and RTL memory world

`OriginalVclMemoryWorld` is an isolated composition of the retained original
heap, Pen, Brush, Canvas-constructor and Bitmap-constructor instruction IR.
It uses **one VM, one known-byte memory, one actor stack and one FS chain**.
The embedded `OriginalSharedHeap.vm` refers to this same VM; it is not a second
allocator execution context. Original `530C70`/`530C88`/`530CA0` dispatch and
selected allocator functions execute inline. There is no VCL GetMem callback
that resets another interpreter or returns an independently maintained object.

All merged IR files must agree on original source SHA, image base/size/file and
mapped-image SHA. The existing heap initialization verifies the actual image
bytes. Conflicting instructions at a shared address are rejected. The chosen
original memory-manager addresses are explicit `world.manager` inputs and must
match the supported original default manager; they are not a silent fallback.

## Inputs and API

`initialize_fresh(world, graphics_boundary, owned_primitives=null)` accepts the
same explicit `source_sha256/scope/thread` context used by the isolated ports,
plus `manager`. The supported actor context is explicitly flat FS0, a declared
fresh or observed page-aligned stack, and a stack pointer inside that stack.
Stack mapping cannot overlap the original PE. Reinitialization is rejected.

Initial segments may supply only the complete **44-byte runtime font descriptor
at574B28** or the **one-byte bitmap policy at574B54**. Runtime global inputs are
restricted to the VCL registry/list/stock-object slots and bitmap policy. Exact
integral JSON DWORDs are accepted without truncation; invalid lengths, hex,
fractions, code/manager writes and invalid BYTE policy values are rejected.
The image font descriptor, bitmap policy and relevant runtime VCL globals are
masked unknown before these explicit inputs are applied. Missing but unused
inputs can remain unknown; an actual read fails. No font or bitmap runtime value
is silently supplied by the mapped PE's initial bytes.

The actual source bootstrap then writes complete registry and list objects:

- `construct_registries()`: actual4EB398..4EB3D7.
- `construct_canvas_list()`: actual4EB3E8..4EB40A.
- `construct_canvas(vmt_or_instance,allocation_flag=1)`: actual4E42A8.
- `execute_entry(entry,eax=0,edx=0,ecx=0,endpoint=-1)`: top-level entry into the
  same retained instruction world. `Object.call` is reserved by Godot, hence the
  distinct name. The original normal operation must restore FS before the next
  top-level operation is accepted.
- `.vm/.heap/.program/.context`, `read_bytes`, and `close` expose this isolated
  execution context for further source-bound composition.

When supplied, `OriginalOwnedMemoryApi` binds directly to the same memory and
handles the memory/critical-section primitive requests. It declares logical
address-placement domains and exact supported Win32 memory subset semantics;
LocalAlloc0 payload remains **unknown**. Source initialization and table writes
make only the bytes they really write known. Actual fresh committed pages have
their explicit zero origin. The source allocator performs all client allocation,
free/reuse and metadata manipulation itself. The API's genuine Godot recursive
mutexes provide synchronization; their24-byte historical Win32 representations
remain unknown rather than being fabricated. No second lock owner is created.

The external graphics boundary is separate and must return validated explicit
primitive results. The current shared test rejects every graphics/other request.
There is no stock-HDC or handle stand-in. API replies use `OriginalApiReply` so a
missing/nonboolean result or an empty failure message cannot continue execution.

## Original-instruction comparison

`tools/original_shared_vcl_oracle.py` executes the original PE with the same
explicit reconstructed memory-manager selection, font descriptor, bitmap policy
and address domains. Host `threading.RLock` calls are genuine recursive locks;
this is a reconstructed host primitive scope, **not native Win32 attestation**.
The OS memory-page boundaries are explicit diagnostic counterparts to the owned
logical-address API. No GetMem/FreeMem/constructor is stubbed. Graphics refuse.

The new fixture SHA is
`56e4abb5d568a8f860728256ea7bd7b8b6c9d2d19e9cb0c6d2869b82ed0748ff`.
`test_original_shared_vcl_world.gd` passes **1523 checks across12 source steps**:

1. Three actual VCL resource-manager constructors.
2. Actual Canvas ThreadLists and underlying lists.
3. A complete source TCanvas, with full Font, Pen and Brush objects and real
   shared registry records. Constructor result Canvas040000F4,
   Pen040001B8, Brush040001FC; these are diagnostic logical addresses.
4. Interleaved Pen/Brush new-color allocation, same-key reuse, old-key return,
   source-node free/reallocation, and hollow Brush style.
5. Actual TBitmap construction through the same RTL heap and shared-image AddRef.
   Its lazy Canvas pointer remains zero; existing Canvas/registry globals persist.

The comparison checks every known non-lock byte of four committed heap pages,
all allocator global metadata outside opaque locks, source-written LocalAlloc
segments, registry globals, FS restoration and **71 source-ordered genuine lock
calls**. It verifies the actual constructor associations and shared Canvas+38
lock alias. Unwritten LocalAlloc bytes remain unknown in Godot; the oracle tracks
actual native stores, so diagnostic A5 bytes from its host buffer cannot become
required defaults. No successful no-op primitive is used in the Godot test.

The first harness run read an unwritten registry global before its bootstrap
write; its explicit unknown-byte error also poisoned subsequent inspections.
The fixture/check was corrected to compare source-written globals only. Earlier
experimental Brush pointer/entry mistakes were corrected against the retained
source before generating the passing fixture (Brush is Canvas+14, not Font+C;
Brush.SetColor is4E4158). Neither source logic nor expected data was weakened.

## Remaining boundary

This establishes a usable isolated shared object graph, not complete original
GUI startup or live production attachment. The original capture's process-
specific handles, allocator placement, thread ownership, pending messages and
actual startup state are not inherited by this fresh reconstruction.

Lazy TBitmap.GetCanvas/derived BitmapCanvas association and source HDC creation,
selection, palette/brush/pen/font state, bitmap creation and GDI drawing remain
separate source-bound work. The not-yet-handed-off lazy-Canvas IR has deliberately
not been included. Current graphics failures preserve the explicit unsupported
boundary; Delphi exceptional unwind/cancellation and destruction after a failed
operation holding locks are not implemented. Callers must not pretend a refused
primitive was successful, reset FS or force-release another owner's mutex.
There are no production/frame/model/main edits in this isolated composition.


## Final lifecycle and primitive guards

The bound DeleteCriticalSection import helper now calls the common `_os` path:
it records one ordered event and routes deletion through OwnedMemoryApi's actual
per-generation lifetime, rather than attempting the world's broader scope.
The focused check exercises that stdcall helper with a real constructed Canvas
lock, verifies the owned Mutex lifetime is deleted/tombstoned, rejects subsequent
entry and preserves unknown opaque bytes. This is a direct source-import-boundary
test, not a claim that the complete Canvas destructor is implemented.

Missing graphics results, empty-error successful replies and non-DWORD values
(strings, fractions, negatives, overflow and booleans) now produce an explicit
nonempty stop before helper return. A preexisting source operand error returns
before ledger append or provider invocation. No retry, fabricated zero result or
source continuation occurs. The final focused run passes1523 checks; the
separate original Canvas drawing regression passes1324 checks/12 native steps
with its one explicit exception frontier. The12-step shared-world fixture hash
above is unchanged. Lazy Canvas IR has not been merged in this milestone.
