# Active native Canvas connection

Canvas uses native mode from initialization. The prototype chemical tint,
fill-mask overlay and artificial sealed cap have been removed from its drawing
code. `LabCanvas.configure_native_presentation(configuration)` delegates the
complete verified configuration to the source host.
No particles, RNG, bitmap bytes or VCL verification flags are invented.
Unconfigured presentation explicitly reports missing original drawing inputs.
Native mode with missing inputs displays the known apparatus asset
and an unfinished-state message, never substitutes the old material tint.

After successful configuration Canvas automatically schedules the actual
pipeline when its model stamp changes. `render_native_presentation()` also
offers an explicit awaitable request. `OriginalPresentationController` calls
host.capture_native_presentation, the source-ordered orchestrator, validates
final pixel/Image transport, and calls host.adopt_native_presentation.
Host revision/fingerprint/reference checks reject stale asynchronous results.
After atomic adoption, the host emits native_presentation_committed with its
new revision; Canvas commits only that host-owned result and checks the current
stamp. Direct dictionary mutation without changed.emit also invalidates cached
frames. Missing profiles/stages do not enable a substitute renderer.

Each committed frame must include exact uint32 words, matching opaque-RGB
Image bytes, original dimensions and the actual final-display metadata:
presentation_stage=background_composited_srccopy,display_mode=opaque,
canvas_background_verified=true,source_compositor=492560,
source_weight_bits=000000000000e03f,probe_only=false and a verified VCL scope.
Canvas displays the returned native-sized Image at native integer center minus
TRUNC(size/2), with nearest texture sampling. It skips the old sprite/material
mask/sealed-cap path for committed frames. UI labels/selection and the existing
user view pan/zoom are separate presentation; this is not a claim that the entire
Godot screen is a native GDI frame. Rotated/scaled/nonchemical source branches
remain explicit orchestrator boundaries.

## Why white alpha is incorrect

The actual upright scale1 source captures the preceding main canvas region
into local88 at40FD5C, calls492560 at40FD82 with background as source,+FC
as destination and weight0.5, sets TransparentColorFFFFFF at40FD9F, then
uses **BitBlt SRCCOPY** at40FE60. It does not display post-fill+FC with a
transparent TBitmap.Draw. Source-background RGB white preserves the whole
foreground word; foreground RGB white copies the whole background word;
both nonwhite average each byte with native truncation and clear the reserved
byte. Therefore a dropper over a bottle includes or blends that already-drawn
bottle. A generic white-key RGBA texture would preserve overlap incorrectly.

`OriginalCanvasPresentation.compose(foreground,background,width,height,
native_position,proof,probe=false)` reuses the native-verified492560 word
kernel with the correct argument order and half weight. It requires exact
scale1 proof and complete original background words. Production requires
background and VCL provenance. It returns opaque Image bytes plus the full
native words; the reserved byte is never used as opacity. Probe mode can
compare bounded evidence without granting production attestation.

The orchestrator now requires `providers.canvas_composite` for production.
This per-vessel provider must capture/reconstruct the correct preceding canvas
pixels using the original CopyRect geometry/DC profile and prior draw order;
it can call the helper above. Probe runs without it remain tagged
post_fill_pre_canvas and cannot be adopted/displayed as complete native frames.
Do not treat an initial white background or original CEM coordinates as a
general runtime observation. Native particle presentation remains a synchronous
VM callback boundary, whereas the TCP GDI bridge is asynchronous. Complete
providers and original runtime histories are still required.

## Actual bounded evidence

The report `evidence/windows-runtime/vcl-pixel-results-2026-10-14/word-overlap-comparison/comparison.json`
compares all11,548 final32-bit words in six observed+FC bitmaps with candidate
words using the original material recipes,4926E0 fill and492560 half-weight
preceding-canvas composition. Every RGB,reserved-byte and full-word difference
count is zero. Its source document positions and white prior canvas are
explicit hypotheses; preceding apparatus use captured+FC pixels, and prior
connectors/labels/decorators are not replayed. The report retains
native_vcl_verified=false andruntime_canvas_coordinates_verified=false.

The actual six+F8 images are24-bit; +FC/+F4 are32-bit. Parent comparison shows
that choosing either00 orFF for the otherwise unobserved plain high byte gives
identical final fill words:4926E0 copies the fill32 word for white RGB and
clears the reserved byte otherwise. This proves an output dependency for the
bounded same-size candidate, not every intermediate native24-to32 conversion
or all possible source DC/palette/geometry branches. The production plain_copy
boundary is therefore retained.

Focused tests validate49 actual native half-weight compositor fixture cases,
then use clearly labelled synthetic transport providers to exercise the **active**
Canvas configure→automatic render→capture→adopt→commit path, native-sized
opaque textures, stale/probe rejection, direct-mutation invalidation and native
mode tint suppression. These synthetic flags/pixels are only guard tests;
they never populate production evidence or certify missing runtime providers.

## Timer and pending-frame ownership

The source40A4B8 completes synchronously before another timer advances physics.
The native host therefore gates both tick and step while a captured presentation
token is outstanding. Tick retains its previous timestamp; the next accepted
tick includes time spent waiting for rendering. Controller releases its exact
token on renderer failure, malformed frame transport or rejected/stale adoption;
successful adoption releases it itself. Stale tokens cannot release a newer
request. Capture refuses overlapping requests instead of superseding a frame
whose GDI/particle provider still owns mutable state.

`Canvas.cancel_native_presentation()` requests cancellation. An already-issued
native provider is allowed to settle before the controller releases its token
and rejects adoption; this prevents a new frame from concurrently changing
the same provider's DC/layer state. Controller detachment releases its matching
pending token as cleanup. Cancellation is a transport boundary, not a claim that
the original native renderer supported interrupted partial draws.

UI events are **not yet queued** to reproduce the original single-thread message
order. Edits while a provider is pending change the revision/fingerprint and
reject its stale output; their original event-order equivalence remains unresolved.
Do not claim this timer gate alone verifies complete running-frame/UI semantics.
Focused delayed-provider tests verify physics/timestamp gating and token release
after failure/cancellation using synthetic boundaries, without generating native
pixel evidence.

## Native bitmap resource roles

The actual twelve source DIBs establish the allocation roles for this bounded
six-vessel case: +F8 is the **underscore mask** (_sb200,_xkp,_jtdg_2), while
+F4 is the **nonunderscore body** (sb200,xkp,jtdg_2). All23,096 source-image
pixel pairs match those resources. `native_bitmap_plain` is the existing UI
body-asset alias; it must not be used to infer the native+F8 file. Likewise a
legacy UI fill-mask alias is not the native+F4 body buffer. Provider `plain`
must bind the observed+F8 mask bytes, and provider `fill` the observed+F4 body
bytes; preserve their actual24/32-bit metadata and capture provenance. No broad
UI alias remapping was performed. Actual source asset identity does not by
itself verify every subsequent DC conversion or runtime draw history.


The source timer gate now continues after feedback adoption until actual Canvas
`_draw` submits every committed native image. Canvas acknowledges the exact
stored host stamp only at the end of that callback, after every native
`draw_texture` command. Texture creation and commit signals do not acknowledge
display. Hidden canvases, missing textures, missing apparatus, and stale stamps
cannot release that gate. Controller cancellation or detachment can release its
own adopted-but-undisplayed token; a stale token cannot release a newer frame.

The focused running integration test uses a real headless viewport and synthetic
transport providers. It verifies hidden/missing-image rejection, blocked physics
inside the commit callback, acknowledgement from the actual draw callback before
resumed physics, and continued subsequent frames. This establishes CPU
CanvasItem draw-command submission ordering. It does not establish GPU display,
pixel readback, an original VCL profile, or original UI-event queue semantics.
The original UI-event queue and production runtime/provider attestations remain
explicit unresolved boundaries.
