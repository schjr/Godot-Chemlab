# Original fresh memory-manager selection

`OriginalHeapSelection.select_fresh(boundary, stack_context, initial_globals,
argument=1)` executes retained original534368→53418C and dependencies. It
returns `manager`, exact selected global DWORDs, ordered API events, source mode,
fatal status and `compatible_with_existing_system_heap`. Callers must require
`ok:true`; an unsupported external/custom manager must not be converted to the
System fallback. Successful compatible output.manager has exactly the shape
accepted by existing `OriginalSharedHeap.initialize_fresh`. Neither existing
heap nor production startup/host/frame modules are changed here.

This module resolves selection only. PE initial57598C is5343C8. That wrapper
calls534368(1), then allocates through the selected dispatch. The isolated
selector stops after534368 and does not invent the allocation return or execute
external allocation code. The335 retained instructions include original5340F0,
534110,53418C,534368 and wrappers, plus534500 and530CF0/530D0C/530D28. Compiler
`tools/compile_original_heap_selection_ir.py` creates separate selection IR;
it does not rewrite the shared allocator IR or mapped image. The existing
mapped PE is verified by source/mapped-image SHA and size before execution.

Explicit host callbacks supply `GetModuleHandleA`, `LoadLibraryA` and
`GetProcAddress` results. API names and decorated export-name bytes are read
from original mapped memory. Original LoadLibrary thunk is555026; DLL names
are the actual original `borlndmm` strings, not a substituted path. A selected
HeapAddRef call also needs an explicit host result. Missing callbacks/results
stop without guessing zero, success, or a selected manager. Source fatal53B954
stops with recorded original message bytes and partial global writes; no stub
returns success from that fatal path. This is not execution of original fatal
message/termination OS behavior.

Source facts:

- No module:534368 selects System dispatches534444/534428/534468/5344B8,
  source mode4; the raw System manager slots575604/608/60C remain unchanged.
- Module present:5340F0 loads it and requires the returned handle equal the
  first observed module handle; mismatch reaches original fatal53B954.
- 534110 obtains all three SysGetMem/SysFreeMem/SysReallocMem exports,
  writing each observed result. 53418C then obtains HeapAddRef/HeapRelease.
- Missing either reference export selects the System-dispatch fallback,
  source mode3, even when some allocation exports are missing. This branch
  does not install those DLL allocation exports into System slots.
- Both reference exports require all three allocation exports and zero prior
  startup marker/mode. It selects Borland dispatches5342C0/5342D4/5342EC/534328,
  source mode2;534500 installs exports into System slots only when530D28 says
  those slots still contain the original default manager. It then calls the
  observed HeapAddRef. A previously replaced System manager stays unchanged.
- 534368 stores its explicit argument to575980 after successful selection.

The stack context needs explicit base/size/pointer, `stack_origin` equal
`fresh_committed_pages`, and scope. This declares a new isolated committed-page
stack; it does not infer bytes from a live thread. Optional initial_globals
can supply observed DWORDs only at the listed selection globals. All other
initial bytes come from the verified freshly mapped original PE/BSS. Unknown
live checkpoints, thread history, loaded DLLs or GUI startup ordering are not
inferred. No TLS, OS precision or GDI state is supplied. Use a new selector
instance for each fresh world, then `close()` to release callback references.

`tools/original_heap_selection_oracle.py` executes the actual original PE with
explicit hosted Win32/export/AddRef outcomes. Its36 cases cover module absent,
load-handle mismatch, all32 export-presence masks, already replaced System
slots and an invalid prior startup marker. `test_original_heap_selection.gd`
matches540 selected/global DWORDs plus all callback operands/order, fatal state
and compatibility flags. Missing module-result tests preserve original lazy
5343C8 and fail explicitly. These are bounded source-selection tests, not a
capture of actual process startup or proof that an external allocator works.
