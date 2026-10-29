# Original-code integration status, 2026-10-15

The requested result remains a functioning laboratory using the original logic
and interaction rules, with all28 examples checked end to end. It is unfinished.
Isolated source checks and captured checkpoints below do not certify that result.

| Area | Established evidence | Remaining work |
| --- | --- | --- |
| Chemistry and Run order | All28 Run-return numeric references; recorded physics frames; source-ordered opening withdrawal/drop/pour workflow | Complete startup allocation history and uninitialized-cell inputs for arbitrary live documents |
| NaOH withdrawal | All12 values and species order match a real Windows action capture | Full interactive frame and later source render feedback |
| Gas operands | All10 constant spans and all499 reagent records captured and strictly validated; selected inert mass29 unchanged | Six diagnostic one-ULP differences and live/emulated floating execution context remain unresolved |
| Drawing objects | Source Canvas, Font, Pen, Brush and Bitmap construction, registries, reference counts and notifications; one shared memory/stack/allocator world; genuine recursive mutexes | Live renderer binding, lazy drawing-surface/DC and complete source bitmap operations |
| Pixels | Exact57 recorded GDI request replays;11,548 final vessel words at one paused checkpoint | Complete moving, rotated and arbitrary-example frames; persistent source GDI state |
| Particle state | Full observed raw objects retained; numerical source routines, RNG calls and cache feedback verified under explicit fixture inputs | Fresh startup RNG/clock/CRT binding, original object allocation/presentation integration |
| Interaction | Source MouseUp dispatch, menu states, drag/selection, modal ownership, FIFO and two-clock rules | Complete native presentation timing and remaining dialog transactions |
| Documents | All28 CEM imports and unchanged round trips; ordered edits retained | Full user workflows through the completed runtime |

The two returned captures are recorded separately in
`evidence/windows-runtime/pen-capture-transfer-2026-10-14.json` and
`gas-operand-transfer-2026-10-15.json`. Both raw imports passed. Neither capture
supplies a live thread's TLS random state or a usable foreign graphics handle.

Next integration order:

1. Finish the source lazy BitmapCanvas/DC and drawing-state paths at their true
   Win32 primitive boundaries, using the shared byte world and real lock backend.
2. Connect original bitmap sizing/loading, persistent particle surfaces and frame
   execution to those constructed objects, preserving source call order and
   failure state. A failed provider must never release the call or adopt pixels.
3. Supply actual source startup allocation and clock/CRT inputs rather than
   turning captured bytes, test poison or a fixed random seed into defaults.
4. Run all28 complete workflows through that runtime, including their rendered
   output and interactions; compare with the original where required.
5. Build and smoke-test release artifacts only after those dependencies pass.

The current ZIP remains a buildable work-in-progress source project. Existing
older desktop binaries are not an acceptance result for the current port.
