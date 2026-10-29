# Original TBitmap lazy Canvas and Handle prefix

`OriginalBitmapCanvas.initialize(world,boundary)` reuses the existing standalone
Canvas constructor boundary and adds536 retained original instructions.
`get_canvas(bitmap)` executes4E9448. It requires an existing source-proven
TBitmap graph, shared image and initial registry/list/thread state, rather than
creating a minimal synthetic bitmap or returning a dummy Canvas pointer.

When bitmap+24 is zero, source4E96EC copies shared-image+14 into+8 only when
+8 is zero. It does not invent an HBITMAP, convert pixels or detach shared image
ownership. Original4E8248 constructs class4E80D0, whose original64-byte
InitInstance and full inherited4E42A8 create its Font/Pen/Brush and register it
in the source TThreadList using actual retained allocation/list-growth code.
4E8248 writes Canvas+58=bitmap. Getter4E9448 then stores bitmap+24=Canvas,
Canvas+2C=bitmap, Canvas+28=bitmapVMT[+10], Canvas+34=bitmap and
Canvas+30=4E9130. A later getter returns that same pointer without executing
construction or changing any graph bytes. No DC is created by GetCanvas.

`handle_prefix(canvas)` executes actual4E4B84. It first invokes the source
change callback4E4CCC, which dispatches Canvas+30/34 to4E9130. That calls
4E93CC, clears shared-image+50/+54 and FreeAndNil52E1BC on saved object+6C.
Fresh empty shared images have no object there, so retained531408 nil behavior
executes. RequiredState4E4C58 sees invalid bit1 and dispatches class CreateHandle
4E8350. Original canvas/global lock acquisition, shared-handle promotion,
bitmap-list guards4E81CC and palette guards4E975C execute. An empty image then
reaches **real Win32 CreateCompatibleDC(0), thunk55527E**.

The module deliberately stops before that import: no handle/result is
fabricated. It records the actual arguments and an explicit unresolved
frontier. This is a prefix, not successful Handle creation; pending source
exception frames and lock state at the stopping point remain as observed in
the native prefix and are not silently unwound. A shared reference count>1
instead reaches4E9070's copy-on-write path from4E93CC; that separate unresolved
frontier is recorded before fabricating a detached bitmap or copied pixels.
Nonempty bitmap/palette/DC creation, stock objects and downstream RequiredState
Font/Pen/Brush selection are outside this completed standalone prefix.

`tools/original_bitmap_canvas_oracle.py` prepares complete diagnostic graphs by
executing original registry/TThreadList/TBitmap constructors, with explicitly
hosted poisoned allocations/lock byte effects. It executes real4E9448 twice,
then where applicable4E4B84, stopping before Win32 creation or native copy.
`test_original_bitmap_canvas.gd` matches five native graphs, five repeated
aliases, four explicit Handle frontiers and10,528 object/list/registry bytes.
It checks class VMT, source owner/method fields, shared-handle promotion,
unchanged alias calls, API ordering and FS prefix state. Inputs cover00/A5/FF
allocation payload, retained-handle promotion and shared ownership. No actual
process graph or native VCL/GDI raster attestation follows from these tests.

Own `OriginalBitmapCanvasVm` adds source NOT byte instruction support without
changing condition flags and inherits explicit FS-base translation. For future
shared-world integration, union this IR with existing constructor/bitmap/heap
IR on the same VM/ESP/FS; compare identical overlapping instruction records.
Do not replace4E8248/4E42A8 with whole-constructor callbacks or reset a nested
heap interpreter. The standalone high-level GetMem/lock boundary follows the
existing diagnostic Canvas constructor module; a shared-world integration must
retain its actual inline selected allocator and owned lock provider instead.
No production/shared-world/frame/host/main files were changed here.
