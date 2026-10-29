# Original Canvas and graphic-object construction

The isolated `OriginalCanvasConstructor` retains the complete normal
`4E42A8` TCanvas constructor, including its inherited constructor, Font/Pen/Brush
construction, object aliases/events, thread-list registration and normal
AfterConstruction/finally path. It does not report a no-op registration as a
successful constructor. `compile_original_canvas_constructor_ir.py` retains
631 exact PE instructions; its mapped-image identity is checked against the
hash-pinned original executable and `original_heap_image.bin`.

## Source construction and memory ownership

| Source | Retained effect |
| --- | --- |
| `531708` | Actual constructor allocation/exception frame, including virtual NewInstance. |
| `53139C` | Loads instance size from VMT-28, GetMem, then jumps to InitInstance. |
| `531414` | Writes VMT, executes original STOS zeroing of payload, walks inherited interface-initialization metadata. |
| `5313D8` | Actual inherited TObject constructor. |
| `531760`, virtual `531638` | Normal AfterConstruction path; the inherited method is an actual source RET. |
| `4EB398..4EB3D7` | Constructs real shared-resource registries and writes globals59A9E0/E4/E8 with descriptor lengths44/16/16. |
| `4EB3E8..4EB40A` | Constructs real TThreadLists/TLists and writes574D90 and59A9EC; the unrelated preceding4EAF84 object is outside this bounded startup block. |
| `4E3790` | Original TFont: zeros descriptor handle574B28, interns44-byte descriptor, sets object+18=80000008 and copies stock/global59A99C to+1C. |
| `4E3CBC` | Original TPen: interns original16-byte default descriptor and sets+18 byte4. |
| `4E3FAC` | Original TBrush: interns original16-byte default descriptor. |
| `4E42A8` | Canvas initializes its+38 critical section, constructs/binds graphic objects, sets copy mode+20=CC0020 and source state byte+8. |
| `51FC60` | Original TThreadList constructs a TList through normal allocation/InitInstance and initializes its own critical section. |
| `51FD30`, `51FDB8`, `51FE1C` | Actual locked Canvas-list registration and normal finally unlock. |
| `51FA54`, `51F89C` | Original ordered search and append. |
| `51FA20`, `51FBB0` | Source capacity growth and ReallocMem call; no substitute collection algorithm. |

Base TCanvas VMT is4E25E4, instance size58. TFont/Pen/Brush VMTs are
4E22A4/4E2420/4E2520, sizes24/1C/18. Canvas+0C/+10/+14 store the three
source-created objects. Every graphic object's+0C is the same Canvas owner;
its+14 is the exact same Canvas+38 lock address. Event code fields+08 are
4E4DCC/4E4DEC/4E4E0C respectively. These are direct source writes and verified
aliases, not reconstructed minimal records.

The constructor honors allocation flag0: a supplied instance does not execute
InitInstance again. Its untouched payload bytes remain unchanged. With flag1,
poisoned GetMem bytes become defined zeros only through the actual source STOS
instructions. Registry allocation header padding that source does not write
remains unknown unless the allocator boundary supplies it. No allocator-wide
zero policy is inferred.

## Module and boundaries

`initialize(world,boundary)` uses the same explicit segment/global/thread
schema as the isolated pen/brush modules. Runtime font descriptor574B28..574B53
and stock/global59A99C are explicit inputs; mapped file defaults are not
accepted as runtime observations. Fresh diagnostic tests declare the descriptor
bytes, including a nonzero incoming descriptor handle that the font constructor
then resets itself. Registry globals and59A9EC stay unknown until observed or
written by the retained startup instructions.

`construct_registries()` runs the first bounded startup block;
`construct_canvas_list()` runs the second. `construct(vmt_or_instance,flag=1)`
executes the complete normal Canvas constructor and returns its actual pointer.
The startup endpoints are instruction checkpoints, not fabricated RETs in the
Godot module. The native oracle supplies a normal-return harness at each
startup-block endpoint because these source blocks are not standalone functions.

GetMem/FreeMem/ReallocMem backing and effects, InitializeCriticalSection and
Enter/LeaveCriticalSection are explicit primitive boundaries. Reallocation
receives the original pointer slot, old pointer and size, and must supply
complete new backing and other memory effects. Lock initialization must supply
its backing writes. Native wrapper/default-allocator execution and real locks
can replace these diagnostic primitives in the shared-world integration.
Allocation failures, exceptional unwinding and duplicate-error mode2 in a
preexisting thread list remain unsupported source branches. No graphics API
or whole constructor is silently hosted.

## Native comparison

`original_canvas_constructor_oracle.py` executes actual PE instructions;
`tests/fixtures/original_canvas_constructor.json` records complete allocated
backing, runtime globals, return values, FS restoration and primitive call
order/arguments. Five cases cover A5-poisoned and zero allocator backing,
flag0 caller-supplied poisoned bytes, six Canvases sharing real interned records
with list growth0→4→8, and a parent TCanvas constructor allocating the original
64-byte bitmap-Canvas VMT. The latter does not claim to execute the distinct
4E80E4 derived bitmap-Canvas constructor or establish its bitmap attachment.

`test_original_canvas_constructor.gd` passes20 native steps and1,670 checks,
including explicit missing-Canvas-list, unknown allocation-padding and missing
runtime-font-descriptor guards. The checks compare every recorded object/node/
list allocation byte, source VMTs/owner/event/lock aliases, registry/global
writes, primitive order and normal FS restoration. Uninitialized globals are
not compared to the PE file's BSS zero values.

No active frame/main/host or existing pen/brush/lock file was edited. Production
integration needs one shared original known-byte world and actor stack/FS,
source allocator and real lock providers. Bitmap-Canvas construction, bitmap
ownership, lazy GDI handles and rendering remain separate dependencies.
