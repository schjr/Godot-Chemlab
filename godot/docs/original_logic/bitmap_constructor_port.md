# Original TBitmap construction and initial shared image

`OriginalBitmapConstructor` executes327 retained original x86 instructions.
`initialize(world,boundary)` requires the original source identity/scope,
explicit selected manager575604, constructor policy byte574B54, object segments
and complete stack/FS inputs. `construct(vmt_or_instance=4E2AF4,flag=1)` executes
4E8EDC. `add_reference(shared)` executes original4E843C. `read_bytes` exposes
known backing; `close` releases callback references. This is an isolated module,
not a replacement implementation of bitmap objects in production.

Concrete source path:

- TBitmap4E8EDC calls531708 when allocation flag is nonzero. Its ordinary
  flag1 NewInstance dispatches53139C→530C70→the explicitly selected raw GetMem.
- Actual531414 writes the class VMT and clears exactly its instance body using
  STOS instructions. This establishes zero from original writes, not a guessed
  allocator payload. TBitmap VMT4E2AF4 declares instance size34 hex.
- Inherited TGraphic4E60FC/TObject5313D8 constructors and AfterConstruction
 531760→531638 execute. Source531708 installs and restores its real FS exception
  frame; the isolated VM adds explicit FS-base translation. No SEH node is
  replaced with a success callback.
- 4E8EF8 sets bitmap+2C to20000000. 4E8F01 loads shared-image VMT4E2A94
  from4E2A48 and constructs it via5313D8/531414. Its size is74 hex. 4E8F0D
  stores the pointer at bitmap+20;4E843C increments shared+4 from0 to1.
- Bitmap+24 remains0 after ordinary InitInstance: this constructor does not
  create a Canvas or allocate DIB pixels, an HBITMAP, palette or DC.
- If explicit574B54 is nonzero, virtual+68 invokes4EA08C with true. Its actual
  getter4E94AC sees the newly initialized empty shared image and returns true,
  so the setter exits unchanged. Both policy paths complete without Win32 GDI
  calls. The unrelated nonempty-image conversion branches remain unresolved.

The standalone raw allocation boundary is `MemoryManager.GetMem`, with exact
selected function address and EAX size. A successful callback supplies its
address and may supply raw payload bytes and explicit allocator backing writes.
Absent payload is unknown, not zero: actual InitInstance must establish every
subsequently read byte. Zero allocation return flows through retained530C70 to
original RTL error530D64. This is an explicit failed error/exception frontier;
full RTL exception allocation, unwind and termination behavior is not faked.

For inherited/direct construction, flag0 and negative DL81 use an explicitly
supplied existing TBitmap instance. Original constructor body overwrites+20 and
+2C while preserving other bytes. It does not zero that existing object or
release an old image pointer as a fabricated convenience. Such a flag is not a
new uninitialized-object allocation rule. Unknown subclasses or conventions
fail explicitly. AddRef aliases change only the shared reference-count DWORD.
Image load/resize/Assign/draw/destruction are not exposed as fabricated APIs.

Validation: `tools/original_bitmap_constructor_oracle.py` executes actual PE
instructions with explicit raw manager allocations and guard/poison bytes.
Twenty cases cover flag1/0/81, policy0/1, poison00/A5/FF and failure of the first
or second allocation. `test_original_bitmap_constructor.gd` matches4,260 exact
object and guard bytes, VMTs, returned pointers, refcounts, API events and FS
restoration/failed-frame state; separate checks cover source-defined writes
from unknown payload and a nonzero FS base. No native GDI raster or complete GUI
startup attestation follows from these constructor tests.

Shared-world integration must union this IR with the actual selected allocator
IR on the same VM/ESP/FS and use original530C70 dispatch. It must omit the
standalone raw GetMem callback when that selected allocator is already executed
inline. Merely synchronizing independent VM stores, resetting a nested heap's
registers or remapping a live graph as a fresh PE would be incorrect. Existing
shared heap, Canvas, particle, main and host files are unchanged by this port.
