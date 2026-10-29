# Source-ordered chemical-vessel presentation

`OriginalPresentationOrchestrator.render(snapshot, providers, profile,
probe=false)` implements the upright chemical-vessel ordering of0040A4B8:
clear→471650liquid→47692Cgas→live particles→473E6Csurface→4744DCsettled
solid→running overlays→F8SRCPAINT→4926E0F4fill blend. A vessel completes
all these stages before the next vessel refreshes its liquid cache. No
all-vessel liquid prepass or all-vessel particle batch is substituted.
The frame result contains exact native words plus opaque-RGB presentation
Images, updated vessel/connector/pool/shared-RNG state, and an order trace.
No main/model/canvas wiring is changed by this helper.

The caller supplies a complete, owned snapshot containing:

- `vessels`: ordered native apparatus dictionaries, including exact chemical
slot caches, scalar observations, bitmap dimensions and original orientation.
- `connectors`: the complete original ordered connector graph and state.
- `scene`: persistent particle pools in full apparatus order. The orchestrator
does not create replacement pools or erase previous particle layers.
- `rng`: actual two-DWORD thread state from evidenced original startup/runtime.
No seed0/1 or Godot randomize fallback exists.
- `context`: explicit original run/pause flags and provider-specific profiles.
- `catalog`: original ordered reagent metadata/physical colors.
- `bitmaps`: one entry per vessel with explicit+FC`material` width/height,
bitmap_format32 and initial_stretch_mode; +F8`plain` and+F4`fill` words,
dimensions and bitmap_format; original `copy_rect` destination/source rectangles.
Production also requires `original_bitmap_profile_verified` on each entry.

The current helper explicitly rejects rotated vessels, nonchemical apparatus
branches, unknown bitmap formats, unverified production profiles and omitted
providers. These remain integration boundaries, not invented display branches.
The snapshot is deep-copied; only successful output state is offered for caller
adoption. The caller must own an input revision/event token and reject a stale
asynchronous result if its authoritative model changed while native GDI work
was pending. This transport boundary does not claim the original exception or
partial-failure side effects. One outstanding render per orchestrator is allowed.

Providers are explicit:

- `gdi` exposes the existingrender_ops/render_solid/copy_rect API. All stage
replies must contain complete unsigned32 words and current stretch_mode.
Production replies also require native_vcl_verified. Stage requests pass the
current DC mode; they do not reset it to a guessed default per rectangle.
- `particles` is a per-vessel Callable receiving native_index plus the **entire**
mutable working vessels/connector/pools/RNG graph, current material words,
canvas state and context. It executes actual emission/update/retained-layer
logic and returns complete words, stretch_mode and current canvas_state.
Missing pools, startup state, native trig, pixels or GDI semantics stay errors.
- `overlays` is a Callable receiving current vessel/context/material/canvas
state. Even a no-operation result must follow proven original branch guards;
the orchestrator does not assume heating/flame/other overlays are absent.
- Optional `plain_copy` handles actual source24/device bitmap CopyRect with
explicit raw source profile. Without it, the built-in hosted copy requires
source32. The bridge's existing source32 request is not silently applied to24.

473E6C retains the actual destination brush color after particles and sets
hollow style. Settled-solid arithmetic is computed **after** particle feedback;
it is not taken from the earlier`OriginalVesselBitmapRenderer.plan`. Its GDI
work occurs on a temporary bitmap and492560 changes destination scanline
pixels, so the destination stretch mode is preserved. Overlays can then change
that mode; F8CopyRect inherits the returned mode and uses exact native
StretchBlt SRCPAINT. F4 requires supplied native32 conversion and matching
dimensions; no Godot resize or color conversion is invented. Original4926E0
word arithmetic and fill_weight are reused unchanged.

`OriginalParticleFrame.step_vessel(index, vessels, catalog, connectors, scene,
context, rng, native_trig, native_presentation)` now restricts only the native
frame block execution to that global apparatus index. Full VM apparatus and
connector setup/adoption remains intact. Never pass a one-element subset,
which would change native indices and connector lookup semantics. Existing
`step` keeps its prior all-vessel default; its new optional selected_vessel=-1
parameter supplies the same selector when needed.

Before the single-vessel call, a provider can set
`context.native_material_words[index]` to the current exact pre-particle
words. The frame seeds only supplied bitmap words; unknown other-vessel
pixels remain unknown. Its result exports resolved`material_words` by native
index, including any scanline changes. Particle-presentation callbacks still
need actual GDI/native word responses; the numeric VM is synchronous, so a
callback cannot transparently await the asynchronous TCP bridge. Supply a
verified synchronous primitive provider or an exact matching capture. A
missing arbitrary-geometry particle renderer is an explicit unresolved boundary.
Track destination canvas state in that provider and return it to the orchestrator.

No current capture is promoted to production verification. The57-case GDI
capture proves actual GDI references for its own complete matching requests.
The current six material references omit retained particles/overlays and+3CC0
is still an unobserved zero hypothesis until the new scalar capture. Eighteen
original DIB records will help verify source formats/bytes and final candidates,
but do not alone establish previous particle/DC history or drain target GDI.
Both the profile and every production stage reply must retain independently
verified provenance before a production render can succeed.

Focused tests use labelled synthetic transport providers to verify ordering,
following-vessel cache history, snapshot isolation, explicit format/DC state,
missing-provider rejection, per-vessel index guards, and preservation of
supplied words without synthesizing another vessel's pixels. They are not
native pixel goldens. The established native particle-frame regression checks
the unchanged default against66 native render passes and60 physics ticks.
