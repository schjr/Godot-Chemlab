# Normal dropper and pouring workflow, 2026-10-18

The active application now uses the retained original allocator for physical
apparatus numeric arrays and scalar storage. New committed pages have their
owned API-defined contents; freeing and allocating blocks preserves the source
allocator's actual reuse. Loader and source-function stores override only their
specified cells. No test cache arrays, captured startup snapshots, or universal
particle-zero defaults are installed by normal startup.

The gas routine's read-before-write local now refers to an owned stack QWORD
at the original4018B0→46F704 ABI offset. The same reconstructed thread stack
retains particle-frame writes between UI messages. This supplies actual memory
for source reads without claiming that every historical Windows native stack
temporary has been replayed. Explicit capture/oracle inputs remain scoped and
override this runtime boundary only when explicitly attached.

The original startup time conversion and RNG seed execute once from the live
host clock, using a declared fixed-offset OS timezone boundary. The source RNG
sequence continues across documents and Run/Stop. Source particle constructors,
bitmap clears and scanline bindings now exist in production. Stopped painting
initializes the liquid-sized surfaces; Run retains them. Live rendering executes
solid particles, liquid outlines, sediment, then bubbles in the retained order,
and adopts the reserved-solid feedback consumed by the next reaction step.

Open tilted vessels preserve the old liquid-height feedback as the source
branch requires. All16 original pourable factory choices use their source
polygons and matching resource geometry. When liquid height changes, bitmap
resizing follows the raw-source FillRect and old-overlap SRCCOPY path; the
decompiler's apparent early return was misleading and caused black material.

Two expensive particle pixel loops have source-equivalent direct ports. The
original drawing prefix and final pixel/suffix still execute retained IR. The
direct loops match22 cases of complete VM memory, registers, flags and x87 state
and the66-frame native particle corpus. This removes interpretation overhead
without changing the blur, fade, particle emission or chemical model.

`test_opening_live_workflow.gd` creates the ordinary main scene, presses the Run
button and drives actual viewport down/motion/up events. It does not set the
running flag, inject numeric observations, call manual chemistry actions, or
teleport apparatus dictionaries. Its checks cover:

- NaOH leaving its bottle and entering the dropper up to the original2mL limit.
- Moving the dropper and adding a drop to both beakers, producing their actual
  copper and iron hydroxide species.
- Withdrawing HCl and dissolving both precipitates.
- Moving the acid bottle, selecting the real pouring menu, and observing liquid
  leave the bottle and enter the beaker over running ticks.
- Restoring the upright orientation and repeating withdrawal after Stop/Run.
- Source particle instructions running with live material surfaces and no
  render errors.

The normal-display version saves withdrawal, precipitation and pouring PNGs.
The source-level native seven-action/63-tick comparison remains separately
exact, and all28 documents pass normal import/Run/model-frame checks without
injected allocation profiles. These are bounded evidence, not a claim that all
28 complete user workflows and every possible apparatus combination have been
verified end to end. Portable curve edges remain distinct from certified
Windows GDI pixels. Older dated integration reports describe earlier states.

Final validation:107 regression scripts pass across the fresh suite and its
documented reruns. The normal graphical workflow, exported PCK replay with the
test-capable Godot engine, and clean extracted project workflow all pass without
fixture profiles. The release executable separately starts and exits cleanly.
Release templates ignore external test scripts; the PCK replay is not described
as an external harness running inside the release executable. The synthetic
presentation-adoption provider was corrected to supply resized bitmap pixels;
its44 guards still reject incomplete pixel state. Full records and frozen
runtime hashes are in `verification/live-workflow-validation-2026-10-18.json`
in the source archive.
