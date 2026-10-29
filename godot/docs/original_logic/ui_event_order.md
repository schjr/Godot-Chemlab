# Original UI message ordering and Godot continuation barrier

## Original evidence

Physics callback `4018B0` is **Application.OnIdle**, not WM_TIMER. Retained
instructions `40164C..40166D` register method pair `[4018B0,self]` at the
Application object (`579A10`) offsets`D8/DC`. `4F6E44` uses PeekMessageA,
TranslateMessage and DispatchMessageA. `4F6EF4` calls `4F7688` only when that
message read returns false; `4F7688` invokes `D8(dataDC,Application,&Done)` and
calls WaitMessage when Done remains true. `4018B0` writes Done=true at return.
Sources: `recovered/native/main/decompiled.cpp` entries4018B0,4F6E44,4F6EF4,
4F7688; actual registration bytes read directly from the original hash-bound PE.
The main DFM contains no TTimer; the molecular executable has separate timers.

The callback has two timestamps. Form`+5A8` admits the outer callback only when
signed32(now-poll)>5; it updates after that outer branch even when paused,
stopped or pointer-held. Global`57A74C` changes only for accepted Run1 physics,
where the delta uses the actual extended80 constant4028DC. MouseUp42AA18 resets
that physics timestamp only in Run1. Pause43DDD8 changes1→2 without resetting;
resume2→1 samples the clock. Startup43DE5C resets elapsed and samples57A74C.
`original_ui_clock_oracle.py` executes actual4018B0 with declared clock and
physics/presentation call boundaries:24 cases match both timestamps and delta
QWORDs. The host retains separate clocks and an injectable test clock; production
uses its monotonic clock and does not invent a replay delta.

Menu_property417750 creates Form4, calls ShowModal at VMT`+D8`, destroys it,
and calls43F7BC when run=0 regardless of Confirm or Cancel. Native ShowModal
4F4094 disables task windows via4EE270 and runs the nested4F6EF4 message pump
until ModalResult becomes nonzero. Therefore the owner cannot accept input,
but the same original idle callback still runs while Form4 is open.43F7BC is
4624D8→48C428→48DB24→454E44→459F1C→presentation.

## Integrated behavior

Form4 is exclusive. Nested Form5, reaction selection and variable dialogs are
owned by that Form4 window and remain exclusive to it. Confirm writes its
staged rows/scalars first; Cancel writes none. Both close paths (including OS
close requests) leave the window tree before resuming the stopped caller. Main
then aggregates quantities, updates bindings, initializes charts, runs the
retained apparatus/conduit associations, refreshes presentation state and starts
configured native drawing. A short close-continuation gate prevents idle from
interleaving between modal result and that caller; it does not pause physics
while the modal window is open.

OriginalUiDispatch preserves delivered callbacks in FIFO order. Its snapshots
copy InputEvents and argument containers. Main/root and dialog viewports install
OriginalWindowInputGate at `_input`, before Control GUI processing. A raw event
is marked handled and later replayed through the same viewport. Thus queued
text input precedes the queued Modify/Confirm action; the implementation does
not sample future text fields or substitute a later selected apparatus. Nested
GUI callbacks generated during replay stay within the same source message.
Canvas events also retain their raw coordinates and select targets at dispatch.
Godot input accumulation is explicitly disabled. No delivered motion events
are compressed, dropped, or used to cancel an in-flight presentation.

The dispatcher waits for the existing host presentation and final CPU draw
acknowledgement. After each callback it synchronously starts any required,
verified native presentation before admitting the next callback. Missing or
changed providers are not replaced. Invalid callback ownership retains the
message and reports an error. Source idle is polled only when the delivered
input FIFO is empty and the presentation/close barriers are free. Godot process
frames are polling opportunities, **not queued source timer messages**: there
is no accumulated backlog of idle polls. Time is sampled when the admitted
idle callback or source timestamp-reset callback executes.

## Checks and limits

- 24 actual native idle-clock cases plus six original MouseUp/pause/resume
 callback comparisons pass.
- 15 actual417750 caller cases verify modal→destructor→stopped continuation.
- Real modal tests cover Confirm/Cancel after-close chart reset, nested Form5
 ownership and accepted physics while Form4 remains open.
- 18 quantity UI cases compare the two distinct native stages: committed grid
 mass before close and original aggregation after close; all match.
- Raw viewport tests retain three text keys, Tab, Space press/release and replay
 the resulting button action with exact preceding text. Immediate replay is
 once-only. FIFO tests preserve100 delivered motions and dispatch-time clocks.
- The existing28 imports/four charts/28 explicit-profile ticks and actual native
 canvas drag/wood-resize/release/CEM-save regression pass after these changes.

These are bounded control-flow/GUI-state checks, not a claim of matching every
Windows message arrival time or platform mouse delivery. In particular,
Application.WaitMessage wake conditions and OS message cadence are external
runtime boundaries; a Godot frame opportunity is not evidence of a particular
Windows wake. The live native drawing/particle profile and exact GDI provider
remain required. The existing presentation configuration binds its observed
Run/Pause identity and rejects other modes: a paused-only capture is not
silently reused after Run/resume. Without a verified mode-specific rebind,
complete native drawing continuation is still unavailable and reported by the
existing explicit presentation status. Direct programmatic calls outside the
UI dispatcher are test/API boundaries, not proof of native user-message order.
CPU draw submission acknowledgement also does not attest GPU visibility.

### Destruction and queued window input

The retained VCL destruction path `4EE684` retrieves the HWND's WNDPROC,
calls DestroyWindow, then frees the non-default procedure trampoline via4EE5AC.
The pump `4F6E44` dispatches window messages through the HWND/Windows API;
it does not retain and call a destroyed Form4 C++ object callback. Ordinary
keyboard routing4F6CF0 searches control/parent handles rather than transferring
messages to an arbitrarily new Form4. [Microsoft's DestroyWindow contract](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-destroywindow)
confirms child/owned-window destruction and focus removal. [DispatchMessage](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-dispatchmessagew)
is a window-procedure dispatch boundary, not a retained object closure.

The Godot input lease therefore retains a weak reference to the **original
viewport allocation**, plus its gate and lifecycle flag. The lease itself stays
alive in queued arguments after its Node is destroyed. A message whose original
window has closed is consumed with a recorded `closed_target` disposition; it
never dereferences a freed Node, blocks future live messages, or targets a newly
created window. This is targeted closed-window handling, not a blanket discard
of live events. Missing gates on still-live windows remain explicit errors,
with the message retained. Generic invalid non-window callbacks also remain
errors. Window close requests use the same lease where applicable.

`test_native_closed_window_dispatch.gd` queues Form4 Close, two delivered raw
keys for that Form4, then a live message. It verifies the modal caller runs
before the keys are classified, exactly two closed-target dispositions retain
the old allocation ID, the live message executes, and a new Form4 is not a
replacement target. PASS. HWND generation/reuse behavior beyond this explicit
allocation scope remains an OS/runtime boundary; the implementation does not
claim to simulate Windows handle reuse or shortcut translation for an unknown
window class.
