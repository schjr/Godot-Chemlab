# Original TPen setter and shared-registry port

`OriginalPen` is a new isolated instruction-execution module. It does not
replace the current frame callback or attach a production profile. It uses
original imageSHA256
`7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c`.
`tools/compile_original_pen_ir.py` retains472 original instructions, including
the native registry hash/key comparison, normal finally epilogues, late
DeleteObject/FreeMem path omitted from decompilation, dynamic-method lookup,
Canvas pen-change callback and lazy native-handle creation.

## Exact source path

| Source address | Operation |
| --- | --- |
|4E3E50|Copy current16-byte pen key, replace color at key+4, call shared-key setter|
|4E3DE0|Copy shared record+10..+1F, then clear first key DWORD|
|4E3DF8|Optional pen lock; shared registry call; normal finally unlock|
|4E2D30|16-bit rotate-left5/XOR byte checksum|
|4E2DBC|Ordered linked-node search: checksum then full key; allocate on miss; insert at head; increment refcount|
|4E2F50|Registry lock; acquire new record; update pen+10; dispatch change only if pointer differs; release old record; normal finally unlock|
|4E2EA0|Decrement old refcount, unlink on zero; unlock; DeleteObject if handle nonzero; FreeMem|
|4E2F34..4E2F47|Exact late handle deletion/free instructions absent from the decompiled return path|
|5315B4/5315E4|Original dynamic-method inheritance/search and dispatch|
|4E34D4|Invoke pen event+8 with owner+0C if its high WORD is nonzero|
|4E4DEC|Canvas selected-pen bit4 clear, then SelectObject(HDC+4,stock handle59A9A0) when selected|
|4E3E78|Lazy handle: registry lock, style/width/system-color conversion, CreatePenIndirect, cache result, finally unlock|

TPen VMT4E2420 has size1C and no own dynamic table. Its parent-reference
4E2184 resolves to4E21D0; table4E21DC has count1, IDFFFD and target4E34D4.
The actual image's hierarchy/table bytes are used by the retained dynamic
lookup, not a hardcoded replacement callback.

The isolated `OriginalPenVm` extends byte memory execution only for needed
16-bit register views, MOVZX, SETE, ROL/SHR and REP comparison/scan
instructions. Original code controls registry traversal, copying, arithmetic,
notifications and cleanup. The allocator itself is an explicit boundary,
not replaced with a fabricated new allocation policy.

## API and input world

`initialize(world,boundary)` requires original source identity, nonempty
provenance scope, complete known graph byte segments, explicit runtime globals
and thread/stack origin. The source PE supplies literal VMTs/code/data.
Runtime globals59A9E4 and59A9A0 are marked unobserved before input attachment;
registry59A9E4 is mandatory. Missing stock handle may remain unknown until
an actual selected-Canvas event reads it. Graph segments preserve absolute
addresses and all record bytes; fields are not rebuilt from colors alone.

`set_color(pen_pointer,color)` executes4E3E50;
`get_handle(pen_pointer)` executes4E3E78.
`read_bytes` exposes known raw state; untouched bytes remain unknown when the
allocation provider did not observe them. `close()` breaks callback ownership.
Input normal stack memory must explicitly declare fresh committed pages or
complete observed raw bytes; no live thread context is assumed.

The callback sees the exact source API request/order and must return a scoped
outcome:

- EnterCriticalSection/LeaveCriticalSection: opaque original address;
  optional explicit EAX clobber. No target process lock is acquired here.
- GetMem: requested size; return original/chosen address and optional exact
  raw_hex. Missing payload remains unknown. Optional memory_writes can carry
  recorded backing effects.
- FreeMem: exact released pointer; memory_writes must be explicit, including
  an empty list only when the provider declares no backing changes. The
  diagnostic oracle deliberately retains freed bytes; this is not a claim
  that the original allocator never modifies free payload/header state.
- SelectObject/DeleteObject: source handles and explicit return value.
- CreatePenIndirect: exact12-byte LOGPEN and explicit returned handle.
- GetSysColor: exact masked system-color index and explicit result.
- External OnChange methods: declared target, owner and sender; no arbitrary
  process function or captured handle is invoked by the module.

Actual allocator integration must run its native primitive with the same
shared byte world and appropriate nested stack context, or supply complete
recorded backing effects. Calling an independent fresh heap with a reset
stack would not reproduce this shared allocation/client event.

## Native validation and scope

`tools/original_pen_oracle.py` executes the original PE functions in Unicorn
on declared diagnostic graphs; only lock/heap/Win32 primitive callbacks are
hosted. Twelve graphs contain25 source operations. The Godot differential
test passes693 return, complete node/pen/Canvas byte, ordered registry, normal
finally FS-restoration and API/event-order checks. Cases cover same-key reuse,
existing different shared key, new head insertion, predecessor unlink,
a genuine checksum collision with different valid key bytes, dynamic
notification, selected Canvas, absent native handle, DeleteObject failure,
external event order, system color, cached handle and CreatePen failure/retry.
API handles/addresses are explicit diagnostics and never used against the
original Windows process.

`test_original_pen_boundaries.gd` separately passes missing registry/stock
observation, missing native CreatePen, and unknown allocation-padding checks.
Required key bytes become known only through original writes; unused padding
is not made zero. The actual captured paused frame regression remains at
4E3E50 until the returned live graph is validated and an explicit primitive
provider is supplied.

Normal source finally cleanup is executed and verified. Delphi/Windows
exception unwinding, out-of-memory exceptions and provider-thrown exceptions
remain explicit unsupported boundaries; stopping with an unresolved primitive
is not represented as successfully executing those exception handlers.
No production VCL/heap/startup attestation, scene integration or GPU/pixel
completion claim is made by these isolated arithmetic/reference tests.
