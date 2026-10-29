# Dropper controls and context menu, 2026-10-18

The running desktop process was the old October13 export in `build/macOS/`,
not the current original-logic source project. Its context menu appeared far
left of the pointer with almost white text on a gray panel. These are real
presentation defects; the earlier callback-only tests did not cover them.

The current source now uses the delivered right-click event coordinates rather
than sampling the mouse again. Embedded popups use viewport coordinates; native
popups convert those through the viewport screen transform. PopupMenu receives
the same explicit dark text theme as other classic controls. A physical desktop
right click opened the menu beside the NaOH dropper, and clicking its properties
item opened the selected dropper's property dialog.

Original40A4B8 draws the adjacent dropper controls only for the selected type204
while global57A6F8 is1. Main MouseMove4284B4 calls425ED0 to change the cursor;
425ED0 reads the current selection rather than changing it. Hovering an
unselected dropper therefore must not invent a new selection. The existing
original hit rectangles and selected-apparatus rules are retained. Hover now
explains that the exposed bulb must be clicked after Run, and selected helper
rectangles show the original actionable cursor. The second caption is restored
to the recovered `点滴` string, also for types207/208/211. Pause or a fidelity
stop now repaints the helper controls even without a model changed signal.

`test_canvas_pointer_ui.gd` drives root viewport mouse events, including the
window input gate, exposed-bulb selection, helper hover, right click and an
actual popup Copy click. It checks menu coordinates and text contrast. The
normal display run also writes the two review screenshots. Its running flag is
set explicitly to isolate visibility from unknown numerical allocation inputs;
these screenshots do not prove production startup or successful aspiration.

`test_native_action_workflow.gd` now sends helper down/up events through the
viewport and clicks the actual pouring popup. It no longer invokes the canvas
release or context action directly. All seven actions and63 physics ticks still
match the original bits under its declared numerical allocation fixture.

The normal desktop source run still stops on an uninitialized inert-gas
particle cell at+3CD8. Its missing rendering configuration is also visible.
Neither problem is resolved by these interface corrections. A separate WIP
export uses bundle identifier `org.chemlab.originalport.wip`, version0.1.1,
and an explicit development title so it can be distinguished from the old app.
It is an interaction review build, not a completed laboratory release.
