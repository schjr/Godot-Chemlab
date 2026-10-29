# Retained original TBrush and shared registry

`OriginalBrush` is an isolated source-instruction port. It does not replace a
setter with a callback. `compile_original_brush_ir.py` maps the hash-pinned PE,
checks its exact mapped bytes against `original_heap_image.bin`, and retains 545
instructions in `original_brush_ir.json`. `OriginalBrushVm` reuses the exact
integer instruction operations already retained for the common pen registry;
no pen or lock module is edited.

## Source entries and layout

| Address | Effect |
| --- | --- |
| `4E40BC` | Copies the complete 16-byte brush descriptor, then zeros its handle and bitmap fields. |
| `4E40DC` | Brush object lock, shared-registry replacement, normal finally unlock. |
| `4E4158` | Color setter; changes hollow style1 to solid0 before interning. |
| `4E4274` | Style setter; style1 also forces descriptor color to `00FFFFFF`. |
| `4E418C` | Lazy native handle getter, with locked second check and actual LOGBRUSH construction. |
| `4E2D30` | Native rotate/XOR 16-bit descriptor checksum. |
| `4E2DBC` | Registry search: checksum then full descriptor comparison; allocation/insertion and refcount increment. |
| `4E2EA0` | Refcount decrement, head/middle unlink, native-handle deletion and record freeing. |
| `4E2F50` | Intern/replace; dynamic OnChange before old-record release when pointer changes. |
| `5315B4/5315E4` | Actual inherited dynamic-method lookup/dispatch, method ID `FFFD`. |
| `4E34D4` | Actual OnChange method-pointer invocation with owner and sender. |
| `4E4E0C` | Canvas brush notification: clear selected-brush bit8, select observed stock brush into its HDC. |
| `4E34A4` | System color conversion, retaining actual `GetSysColor` dependency. |

TBrush VMT is `4E2520`, instance size `18`; its parent pointer slot is
`4E24FC→4E2184→4E21D0`. The parent dynamic table at `4E21DC` resolves the change
method to `4E34D4`. Object `+08/+0C` hold event code/owner, `+10` the shared
record, and `+14` its optional object critical-section pointer. Shared registry
pointer is live global `59A9E8`; Canvas stock brush is live global `59A9A4`.
Neither is accepted from PE BSS zero as live evidence.

A shared node is next pointer/refcount/HBRUSH/checksum at `+00/+04/+08/+0C`,
then a 16-byte descriptor at `+10`: descriptor-native-handle `+00`, color `+04`,
bitmap pointer `+08`, style byte `+0C`, and three preserved padding bytes.
The registry compares all16 bytes, including padding. Setter copying zeroes the
handle and bitmap fields, so a setter can remove a patterned descriptor even
when its apparent color or style is unchanged.

Lazy creation uses LOGBRUSH style0 for solid,1 for hollow, or2 with hatch
`(style & 7F)-2`; bitmap-backed records use3 after retained virtual calls at
`4E41DB/4E41E6`. It converts the color through the original helper, passes all12
LOGBRUSH bytes to `CreateBrushIndirect` at `555272`, and stores the returned
handle. Zero creation results remain zero, and the next getter retries.
Cached handles bypass allocation/locking. A failed `DeleteObject` result does
not suppress native record freeing.

## API and proof scope

Create a fresh `OriginalBrush`, call `initialize(world,boundary)`, then
`set_color(pointer,color)`, `set_style(pointer,style)` or `get_handle(pointer)`.
The world requires hash provenance, original graph segments, explicit registry
and optional stock-handle globals, and a declared thread stack/FS context.
`read_bytes` exposes retained graph state; `close` releases callback references.

The boundary must resolve critical-section operations, GetMem/FreeMem backing
and effects, DeleteObject, SelectObject, CreateBrushIndirect, GetSysColor and
explicit external OnChange handlers. Internal inherited dynamic dispatch and
Canvas notification execute retained instructions. An API callback is not a
substitute for an entire setter, registry operation or event dispatcher.
Allocation backing uses observed bytes or remains unknown. API failures that
return normally are covered; allocator exceptions and Delphi exceptional
unwinding remain explicit unsupported boundaries.

`original_brush_oracle.py` executes the actual PE instructions on independent
explicit diagnostic graphs. `test_original_brush.gd` compares full object,
registry, old/freed and new-node bytes, return values, exact registry order,
normal finally FS restoration and every API/event argument in order. Cases
include same/matching/new records, shared references, middle unlink, a genuine
same-hash distinct descriptor, nonzero descriptor padding, solid/hollow and six
hatch styles, bitmap removal by setters, selected Canvas notification, external
events, system colors, cached/retried handles, and deletion failure.

This does not provide live graph discovery, allocator semantics, native lock
execution or GDI rasterization. Bitmap lazy creation retains its original
virtual call sites, but a complete bitmap object/method provider is still
required; unknown bitmap bytes or nonretained callees fail explicitly. This
module is not connected to a production frame or the active canvas. Integration
requires a shared original memory world with the verified pen/bitmap/Canvas
objects, actual lock/allocator providers and actual GDI handle lifetimes. No
numeric, color or pixel approximation has been introduced.

Focused acceptance result: 23 actual-PE cases, 47 retained native operations,
1,344 checks, zero failures. This includes seven explicit dependency guard
checks (missing registry, bitmap object, stock handle and lock provider), in
addition to the complete native byte/event comparisons. No production file,
pen module or lock module was changed.
