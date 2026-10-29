# Original allocation and startup replay path

This audit uses the reverse-engineer-anything skill, retained REA/Ghidra
decompilation and exact recovered PE bytes. The current REA evidence ledger
has no retained allocator dossier; no duplicate analysis session was opened
and no other agent's target/session was replaced. New address/byte evidence
is retained in `allocation_startup_evidence.json`, with original image SHA256
`7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c`.

No production model, arithmetic primitive, VM setting or UI was changed.

## What must be reproduced

The source can reproduce allocation behavior. A constructor-only default
table cannot reproduce its unwritten values: those values come from the
original **shared allocator and prior byte writes**. Replaying only a list
of apparatus allocations omits other clients that determine block choice,
alignment, splitting, coalescing and page reuse.

The five 100-cell apparatus arrays are mass298, volume5B8, moles8D8,
reserved-solid3CD8 and solid-delta3FF8. CEM construction reserves4348 bytes
but does not zero these arrays. Its string and reaction constructors
initialize specific members; the reader writes active mass/mole rows;
quantities overwrites active mass and physical volumes. Run clears current
active particle cells before appending air. Air insertion and transport
append names/moles without initializing the new particle cells.

The live cold capture proves stale bytes occur in a real allocation:
the HCl bottle has many nonzero/subnormal inactive cells, including
3CD8[63]. Its allocation is evidence for that instance, not a default.

## Exact allocation machinery

| Source address | Role |
| --- | --- |
| 533AD8 -> 534330 | C++ operator-new retry/dispatch, requested byte size unchanged |
| pointer57598C | Runtime-selected allocation dispatch |
| 5343C8 -> 534368 | First-call manager selection; fallback routes to534428 |
| 53418C / 534110 | Can select external borlndmm exports using module/export lookup |
| 534428 -> 530CF0 | Fallback bridge obtains System allocator triple |
| pointers575604/575608/57560C | Default images point to5306B0/530838/530BAC; 530D0C can replace them |
| 5306B0 | System GetMem: size=(request+7)&~3, minimum12;4348 requests become434C including header |
| 5305BC | Large block selection, splitting and arena growth |
| 530838 | System FreeMem: validates headers, coalesces, may reclaim pages, otherwise retains free block payload |
| 530BAC -> 5309DC | Reallocation, with original copy/free fallback when in-place growth fails |
| 52FFDC | Initializes lists, free-table storage and heap state |
| 52F950 | LocalAlloc644 node pools and explicit node-link initialization |
| 52FAF4 / 52FB58 | VirtualAlloc reserve paths, generally one-megabyte reservations |
| 52FC88 | Commits page-aligned portions of reservations |
| 52FD1C and related reclaim helpers | VirtualFree decommit/release bookkeeping |

`probe_original_default_allocator.py` executes the actual GetMem/FreeMem
instructions and their RTL helper tree. It hosts only explicit Win32
virtual-memory, LocalAlloc bookkeeping and critical-section boundaries.
LocalAlloc tables deliberately start with A5 bytes; original RTL code
initializes the table/link fields it needs. No source allocator routine is
replaced with a bump allocator in this probe.

Fresh **committed pages** are zero because that is the documented
[VirtualAlloc contract](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualalloc).
Already committed pages retain their contents. A decommitted page gets fresh
zero contents when committed again. This is an OS API boundary, not a
whole-apparatus calloc policy. The original allocator can write bookkeeping
inside bytes that later become returned payload, so even a fresh-page
allocation need not return all-zero payload.

The completed `default_allocator_probe.json` establishes two actual source
branches:

1. A1000 alignment guard,4348 apparatus block,4348 barrier, A5 diagnostic
   fill, free and reallocation cause the source to select the **same address**.
   All800 bytes in each of the five numeric arrays retain A5. Only12 bytes
   elsewhere in the17224-byte payload change as allocator bookkeeping.
2. Without the alignment guard, freeing the arena-start block invokes an
   actual16KB page-decommit path. The next source allocation uses a different
   address and does not contain the previous A5 payload.

The first fresh apparatus allocation in the guarded sequence already contains
nine nonzero allocator-written payload bytes; exact offsets are recorded.
These are controlled sequences, not claims about the GUI's allocation order.
Chosen virtual addresses, OS boundaries and external-manager exclusions are
explicit in the evidence.

## Startup clients and ordering

`trace_original_startup_allocations.py` finds36 aligned direct application
operator-new sites below4C0000, retaining the preceding argument instructions.
Important clients include:

| Client | Source size/order evidence |
| --- | --- |
| CEM vessel loader43240C | Push4348 at43281B; call533AD8 at432820; construct standalone strings/font helper; three100-element string arrays; fifty E8 reaction records; publish pointer; call453A28 at4329AD; then read persisted data |
| CEM connectors | Push80 at43449F; call4344A4; then initialize/read connector fields |
| Palette apparatus | Many conditional4348 branches inside retained417CC0 region, including41BCD6/41BCDB; connection branch41B92F/41B934 requests80 |
| Clipboard duplicate415008 |4348 allocation at415047/41504C, followed by source record copies |
| Reagent-library loading460D84 |58 record allocation at460EFB/460EFD, plus managed strings |
| Reaction-library loading4613B8 |E8 record allocation at4615C5/4615CA, plus managed strings |
| Run/stop reaction checkpoints |2D60 per-container allocations at43DFE4/43DFE9 and43E901/43E906, plus label/reaction copies |
| Particle classes | NewInstance53139C -> InitInstance531414; sizes3468C for solids andFC20 for bubbles; source InitInstance explicitly zeroes these class objects |
| VCL objects, bitmap objects and managed strings | Use shared System allocation through their constructors/string helpers; their allocations and frees affect the same pool even though their outputs are presented by Godot |

The last two categories cannot be replaced with arbitrary object handles or
Godot-only strings **if those replacements omit observable shared-heap
side effects**. Existing numerical oracles intentionally host string and
presentation operations; they certify the traced numerical functions, not
the full GUI heap history. Their zero/bump fixture allocation is not a
production allocator implementation.

## Actual read-before-write dependencies

`audit_original_startup_reads.py` executes original setup plus two
physics/particle frames for all28 recovered examples, using a byte validity
shadow. Only explicit loader/Run writes and guest instructions mark bytes
initialized. Mapped zero bytes used to explore a path are **not** marked
initialized. Fields include all five arrays and startup gas/particle scalars.
Results and scope limits are in `allocation_startup_reads.json`.

The original core at46B715 sums reserved-solid3CD8 across **every active
species**, with no solid-phase filter (`decompiled.cpp`32045 onward).
The renderer at40ECBB tests negative solid-delta3FF8 across every active
species (`decompiled.cpp`6265 onward). Newly appended gas names can therefore
expose old cells in both routines. Giving only solid species a valid cache
would not reproduce the original reads.

On the array paths examined, there are171 reserved-solid and71 solid-delta
read-before-write dependencies. Most are the new inert row (163 and58);
the remainder are new transported CO/O2/H2/H2O(gas)/CH4 rows. No unwritten
mass, mole or volume read appeared in these bounded paths. This narrows the
startup array dependency to two actual particle cells per relevant new row,
without weakening full-array byte preservation.

For the opening example, inert indices after Run are[8,2,0,6,2,0] in native
vessel order. Its core reads the corresponding six3CD8 cells; the Cu and Fe
beaker render paths read3FF8[8] and3FF8[6]. Existing Run-cleared rows and
reaction insertion zeros are genuine writes, not unknown allocator inputs.

The gas-delta scalar3CC0 requires separate attention: factory453A28 does not
zero it, and Run explicitly clears3CC8/4318 but not3CC0. A particle draw before
the first reaction-core clear can read this old cell. The current snapshots
capture3CC8/4318/4338 but not3CC0. Actual event ordering and a3CC0 observation
are needed for that startup path; a prior run's value must not be replaced
with a new-load zero by assumption.

The completed scalar-inclusive trace records58 such first reads at40F46C.
The opening's Cu and Fe beakers each read3CC0 on that pre-core render path,
bringing its bounded startup dependencies to ten cells. All28 traces executed
successfully. No unwritten3CC8,4318 or4338 read appeared after their identified
source writers on these paths. In total the report retains300 distinct
field/index/read-site dependencies (171 reserved-solid,71 solid-delta,
58 gas-delta), rather than treating every missing numeric cache as an
unconditional production read.

Coverage is bounded to the explored inputs/branches. An unwritten value can
change a branch, producing further reads not reached under the exploratory
zero-valued physical backing. This is not proof of all memory accesses,
all interactions, complete first-message ordering, or live RNG/bitmap state.

## Concrete production implementation path

The allocator kernel has been demonstrated, so the next step is a shared
native byte heap with source execution, not another chemistry approximation.

1. **Identify the manager.** Read57598C and System triple575604/575608/57560C
   in the target process. If the selected path is external borlndmm, bind that
   original module/implementation or keep the unsupported branch explicit;
   do not force the proven fallback merely because it is available.
2. **Provide an initial allocation world.** Either execute original startup
   with source-faithful allocation clients, or attach one validated full heap
   checkpoint. A checkpoint needs allocator globals59B170..59B1E8, free-table
   storage at59B1DC, LocalAlloc node pools linked through59B19C/59B1A0,
   reservation/committed/free-list nodes, committed arena bytes and manager
   pointers. It is scoped to that process/layout/startup point, not defaults
   for another example or run.
3. **Execute original allocation/free/reallocation code.** Preserve32-bit
   virtual addresses, headers, source list order, splitting/coalescing,
   page commit/decommit and untouched payloads. Packed page buffers provide
   practical storage; do not materialize one Godot Dictionary entry per
   byte or return fresh zeros on every GetMem. The native probe supplies
   exact regression sequences for both retained and reclaimed payloads.
4. **Replay shared clients.** Drive CEM/palette/duplicate/checkpoint paths and
   managed-string/class constructors in their original call order. Source
   InitInstance zeroing applies only to those classes; raw vessel4348 blocks
   retain payload. String/temp/VCL allocations that affect this same manager
   must be executed or recorded/replayed with their actual writes/frees.
   A snapshot of the current vessel arrays alone cannot supply this history.
5. **Connect the byte heap to the port.** Factory obtains the original block;
   constructors and source helpers write exact spans; slots/scalars become
   typed views by physical index. The existing OriginalSlots layer can retain
   those views and runtime observations. Unknown bytes remain unknown until
   a source writer or validated allocation-world input defines them.
6. **Validate event sequences.** Begin with opening load -> Run -> first
   paint/tick -> successful withdrawal -> restart -> delete/new/reload.
   Compare full block bytes, selected pointers, old/new slot values and
   source read/write order, then extend to the28 examples. A per-scene native
   process backend can provide this faithfully before a standalone bootstrap
   replay is complete; it must mirror actual source operations, not inject a
   fabricated allocation profile for each scene.

This path removes the need for universal slot defaults. The remaining gap
is the selected original **shared allocation world/client history**, not an
unknown GetMem algorithm. The current captured opening's observed cells can
already be attached faithfully; future unseen allocations need that lifecycle
or their own validated native observation. Apparatus-only heap replay cannot
be advertised as full startup equivalence.

Numeric context remains a separate investigation. Parent reports that a
full80 emulator-checkbox change and process restart9348 still showed the
same inert-mole difference; that contrary observation does not support
declaring emulator optimization the established cause. No arithmetic fix
or allocator-derived numeric value substitution was made here.

## Authoritative observed manager export

The exported `evidence/windows-runtime/precision-and-graphics-2026-10-14/allocator-globals.txt`
(SHA256 `a424ade43fcc94d6f49f675670a674b836fda78aed65d8895fdf71d9426c104a`)
contains UTF-16LE lines `B0-06-53-00-38-08-53-00-AC-0B-53-00` and
`28-44-53-00`. At the documented capture addresses575604 and57598C these
decode to System GetMem5306B0, FreeMem530838, ReallocMem530BAC and fallback
dispatch534428. Parent identifies this capture as process9348; the text file
itself does not embed PID/address headers. Machine-readable source provenance
is retained in `observed_allocator_identity.json`. This selects the supported
fallback for that observed process, without asserting selection for another
startup.

The isolated `OriginalSharedHeap` now executes the retained allocator
instructions over byte-addressed pages. Its74 actual-native operation
references pass5,655 address, return, byte, page-hash, list/global and API
checks. See `shared_heap_port.md` for its explicit bootstrap and integration
boundary. No GUI/client startup replay was added.
