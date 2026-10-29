# Atomic native presentation model boundary

The host now exposes a production presentation boundary without supplying
startup state itself. This does not certify the outstanding Windows pixel
captures, reproduce the shared heap, or wire a guessed renderer into the UI.

## Configuration and capture

`configure_native_presentation(configuration)` requires:

- `profile`: exact original `source_sha256`, nonempty scoped provenance,
  an evidence SHA256, and explicit `native_vcl_verified` plus
  `runtime_state_verified`. Existing probe-only graphics are not sufficient.
- `apparatus_identity`: exact native ordered identity from the host,
  including IDs, type/parameter, label and bitmap dimensions.
- `scene`, `rng`, `context`: observed persistent solid/bubble objects,
  their13-DWORD records and retained bitmap words; original TLS low/high
  DWORDs; native run/pause globals. Missing inputs fail explicitly.
- `bitmaps`: full ordered original plain/fill pixels, material bitmap
  format/dimensions/DC stretch state, source/destination CopyRect rectangles
  and verified bitmap provenance.
- `providers`: exact GDI object methods, per-vessel `particles`, `overlays`
  and final `canvas_composite` callables. Non32-bit original plain sources
  require an exact `plain_copy` boundary.

Verification flags are an explicit trusted boundary declaration accompanied
by provenance, not an automatic verification of pixels or authenticity of a
Windows process. The host cannot turn an unverified capture into a verified
one. DWORDs and pixel words must be typed integer observations; input parsers
must losslessly decode their observed bytes rather than invent missing data.

`capture_native_presentation()` returns `{ok,snapshot,providers,profile}`.
The snapshot directly supplies the orchestrator's complete ordered vessels,
connectors, scene, RNG, context, catalog and bitmaps, plus revision, request
token, identity and input fingerprint. Deep copies isolate numeric state.
Captured provider objects/callables remain the explicit native boundaries.
The host retains an immutable input hash and actual live vessel references.
A newer capture supersedes the earlier token.

Successful native Run, load and reset invalidate the attached lifecycle
profile. A changed Run/pause control state requires explicitly updated
observed globals. Apparatus creation/order changes require reattachment.
Regular presentation adoption persists source scene/RNG updates; the host
never creates default particle pools, zeros heap slots or seeds its own RNG.

## Adoption and display

`adopt_native_presentation(snapshot,result)` checks the original request,
current revision, complete model fingerprint, native ordered identity and
`is_same` live vessel references. It rejects modified snapshots, replaced
allocations, direct dictionary mutations and duplicate adoption. Probe or
unverified output fails. All returned dimensions, unsigned32 words, scene
records, control state and allowed feedback fields are validated before any
live dictionary is mutated.

Only source presentation writes can update particle caches and liquid
presentation fields. Chemistry, apparatus identity and connector geometry
cannot be changed by rendering. Source connector feedback is retained.
Existing live vessel dictionaries remain stable; their actual indexed slot
backing receives source cache writes. Scene/RNG updates and frames become
visible only after every check succeeds.

Frames must represent final source background composition followed by
SRCCOPY: `presentation_stage=background_composited_srccopy`, `display_mode=opaque`,
verified main-background input, compositor492560, half-weight IEEE bytes
`000000000000e03f`, and original centered integer destination. A prebackground
fill result cannot be promoted to a final frame or converted to guessed
white transparency.

`presentation_revision` advances on model `changed`; frames are cleared.
`native_presentation_stamp()` additionally returns a full content fingerprint
and native identity so the canvas detects direct mutation that emits no
signal. On successful atomic adoption, the host emits `changed`, stores
`native_presentation_frames`, then emits
`native_presentation_committed(result,new_revision)`. The canvas/controller
owns actual display and asynchronous scheduling. If physics continues while
a frame is pending, the stale frame is rejected; this guard does not itself
reorder or pause original simulation events.

## Focused evidence

`test_original_presentation_adoption.gd` executes source40A4B8 particle
feedback using the actual opening fixture and exact Rosetta x87 boundary.
It validates stable-reference adoption, raw particle feedback, notification
ordering, revision/content/input guards, missing RNG/pixels, probe rejection,
nonpresentation field rejection and final-composition metadata.
Its final pixel arrays and verification declarations are explicitly synthetic
contract fixtures; no Windows pixel equivalence or production profile
verification is claimed by this test. Actual pixel/provider acceptance remains
with native capture validation and the presentation orchestrator.

## Liquid-cache ordering during configured production

When a verified native presentation configuration is attached,
`refresh_render_state()` binds bitmap dimensions/assets but defers the
all-apparatus Liquid.refresh prepass. The orchestrator instead performs
liquid refresh immediately before that vessel's particle stage. Thus later
vessels still expose their previous liquid caches to earlier vessels and
connector logic; an asynchronous request works entirely on its captured
ordered copy until atomic adoption. Explicit working-array load diagnostics
and the unconfigured legacy numeric acceptance path retain their existing
refresh contract. Neither is advertised as configured full presentation.

The focused adoption test now rejects each absent particle/overlay/final
compositor provider without indexing a missing Dictionary key, and checks
that configured refresh retains two distinct previous liquid heights. An
actual source Liquid.refresh on the first captured vessel leaves the next
vessel's cache untouched. This checks ordering, not an invented native pixel
fixture. Particle adapters must seed any `native_material_words` helper input
in a temporary copied context; observed run/pause/context globals must not
be changed merely to transport destination bitmap pixels.

## Native timer/presentation serialization

An accepted capture now owns a single pending source event. Another capture
cannot supersede it. While it is outstanding, `tick` and `step` do not accept
physics, matching the single-thread native40A4B8 boundary before the next
accepted timer. `tick` leaves `_last_tick_ms` unchanged, so its next accepted
interval includes the entire render duration rather than discarding that
time. An explicit `step(dt)` during the pending event is rejected, not queued
as an extra independent native timer; elapsed-time accumulation belongs to
the host's timestamped `tick` entry.

Successful adoption clears the pending event. On renderer, transport,
validation, stale-input or cancellation failure, the controller must call
`release_native_presentation(snapshot,reason)`. A matching token explicitly
unlocks physics; a stale token cannot release a newer event. A missing pending
event is a harmless no-op. `native_presentation_is_pending()` exposes this
gate; `native_presentation_is_configured()` reports readiness only when the
configured native allocation/control identity remains valid.

The focused test verifies pending-frame physics rejection, unchanged timer
stamp, stale-release protection, explicit failed-frame release and that the
next real native physics tick includes the accumulated20ms interval. It does
not claim a complete native event queue: mouse/keyboard/property actions,
Run/reset during an awaited request, and asynchronous provider side effects
are still explicit UI-event boundaries. Existing user actions invalidate
stale output through revisions/identity; they are not replayed later in an
invented event order. Full original UI-thread serialization requires the
controller/main event dispatcher to queue or defer those source events too.

## Draw-submission acknowledgement

Successful numeric adoption releases the capture token but now establishes
an adopted-frame display gate. This prevents an asynchronous coroutine from
adopting during process-frame handling and the next timer invalidating that
frame before Canvas._draw submits it. `tick`, `step` and further capture
remain blocked until actual native-frame draw submission acknowledges the
exact stored current revision/fingerprint/identity via
`acknowledge_native_presentation_display(stamp)`.

An earlier frame's acknowledgement cannot release a later pending frame.
Explicit model/profile/lifecycle changes invalidate the old display gate;
a direct dictionary mutation is detected by the pending-state fingerprint
check rather than leaving a permanently unacknowledgeable frame. If Canvas
rejects or cancels the adopted frame, matching-token
`release_native_presentation(snapshot,reason)` cancels its display gate,
clears cached frames and advances the invalidation revision. The next tick
still retains all time since its last accepted timestamp.

The focused test now accepts two frames and verifies adoption-before-draw
physics rejection, stale/current acknowledgement behavior and cancellation
without a locked timer. Acknowledgement means that Godot drawing commands
were submitted. It does not attest that a render thread/GPU has presented
those pixels or that Windows BitBlt completion has been reproduced. The
remaining original UI event queue and native provider side effects remain
explicit boundaries; no undocumented input ordering was introduced.
