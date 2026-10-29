# Retained Canvas Rectangle and selection path

`OriginalCanvasDrawing` is an isolated extension of the existing shared VCL
memory world. It executes Rectangle `4E4744`, required-state `4E4C58`, pen
selection `4E4D20`, brush selection `4E4D50` and the Canvas method-event helpers
on the same source-constructed object/allocator graph. No active frame, host,
canvas UI or shared-world file is edited. The compiler retains171 exact PE
instructions and checks the mapped image against the hash-pinned source.

## Source control and API order

Rectangle invokes Canvas VMT+10 (Changing, `4E4CCC`), requests original state
mask0D, calls actual Rectangle import thunk5553E0, then invokes VMT+0C (Changed,
`4E4CE0`). Coordinates preserve original signed DWORD values and the two Delphi
stack arguments; no geometry conversion, clipping or replacement rectangle
algorithm is introduced. `4E4CCC` invokes event code/owner+30/+34 and `4E4CE0`
uses+28/+2C, only when the original method pointer's high word is nonzero.

Required-state computes missing bits from the current Canvas+08 byte. Bit1
calls virtual CreateHandle at VMT+14 and checks Canvas+04 afterward. With no
HDC, the original path reaches exception constructor52D038; this remains an
explicit exceptional frontier rather than successful drawing. Base CreateHandle
`4E4C00` is retained as its actual source RET. Bitmap-Canvas CreateHandle/DC
construction is owned by the separate bitmap/DC port, not replaced here with
a dummy HDC callback.

Bit4 calls native Pen.Handle `4E3E78`, SelectObject5553F8 and SetROP2555434.
The ROP2 value comes from the original table574D68 indexed by the actual pen
mode byte+18; the fixture exercises constructor mode4. Bit8 calls native
Brush.Handle `4E418C`, UnrealizeObject55547C, the handle getter again,
SelectObject, then source color/background handling. Style0 sets its color and
OPAQUE mode2; other styles use the complemented color and TRANSPARENT mode1.
System colors still invoke original4E34A4/GetSysColor. Only after successful
source control flow through these helpers are missing bits ORed into+08.

The full required-state function retains bit2's FontSelect call4E4CF4, but
Font.Handle4E3978 and its GDI creation dependencies are not supplied by this
module. Rectangle's native0D mask excludes that font bit. A general required
font-state request remains explicit until its source module is available.

The shared world already retains source pen/brush setters and invalidation
callbacks4E4DEC/4E4E0C. Tests change those original objects between Rectangles,
so the next draw selects only the dirty object and preserves the cached state
of the other. No hand-built four-byte Canvas/Pen/Brush records are used.

## Primitive and event boundaries

`initialize_fresh(world,boundary,owned_memory_api)` builds the same retained
allocator/Canvas world as before and merges the drawing IR, rejecting conflicting
source instructions. `rectangle(canvas,left,top,right,bottom)` and
`required_state(canvas,mask)` execute source entries. All allocator operations
continue inline through the actual retained heap. Real recursive lock operations
come from the same OwnedMemoryApi, and opaque lock bytes remain unknown.

GDI thunks require explicit DWORD results from the supplied boundary:
Rectangle, UnrealizeObject, SelectObject, SetROP2, SetBkColor, SetBkMode,
CreatePenIndirect, CreateBrushIndirect, DeleteObject and GetSysColor. Pen/brush
lazy constructors execute source instructions, including shared-record locking
and handle caching; a callback cannot replace a whole selection helper.
No pixel/raster output, native GDI handle or visible successful drawing is
fabricated. A zero primitive result remains zero; original source may ignore it
and continue notifications/cache writes, which is a control-flow result only.

External event targets may be explicitly registered with
`register_external_event(target)`. They cannot replace retained code or another
bound helper. Event request includes actual owner/sender and requires an explicit
caller callback. The test's source method bindings and HDC word are declared
external inputs applied to the real constructed Canvas; the constructor does
not synthesize them. Native BitmapCanvas/TBitmap event bodies are independent
source dependencies and are not represented by these diagnostic external events.

## Native reference and checks

`original_canvas_drawing_oracle.py` executes actual PE constructors, original
heap, pen/brush setters, Rectangle and selection code with real host RLocks.
The primitive GDI results and HDC/event bindings are explicit diagnostic inputs;
this does not execute Windows GDI on macOS or attest a captured GUI process.
`original_canvas_drawing.json` preserves complete non-lock heap-page hashes,
allocator globals, source-written LocalAlloc ranges, real-lock call order,
returns, transient Canvas state, record identities and every GDI/event argument
in sequence. Unwritten LocalAlloc and opaque lock bytes are not forced toA5/zero.

The normal sequence covers first selection, cached redraw, dirty pen-only and
brush-only selection, hollow style, system color, signed/reversed coordinates,
zero handle creation and zero Rectangle results. A repeated draw after those
failures preserves the original selection-bit behavior rather than adding a
retry rule. The second case has no HDC and reaches the original exception
constructor after Changing; the port stops at exactly the same source address
without claiming exceptional unwind or returning success.

Acceptance covers12 normal native operations and one exception frontier.
Integer API traces are converted losslessly from Godot JSON Float tokens to
exact DWORD/signed-coordinate integers before comparison; nonintegral reference
values are rejected, and no numeric tolerance is applied. The active modules
remain isolated pending source DC/GDI integration. These tests prove byte/control/
argument order within their declared boundaries, not complete application pixels.

Final focused result:1,324 checks pass with zero failures. Files are quiescent
for the complete suite/package milestone; no additional drawing scope was added.
