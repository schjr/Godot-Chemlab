# ChemLab for Godot

This project ports the recovered 仿真化学实验室 executable, original resources, and all 28 CEM examples to Godot 4.7.1. The laboratory is being corrected to follow the original code. The earlier substitute simulation has been removed from the active model.

## Run the source

Open `project.godot` in Godot 4.7.1 and run the main scene. The Compatibility renderer is selected. Python utilities use the repository’s uv-managed environment:

```sh
uv run --no-project tools/godot_task.py import
uv run --no-project tools/godot_task.py run
uv run --no-project tools/godot_task.py test
```

Godot needs a writable user-data directory. The runner checks access before launching and treats script errors as failures even when the engine returns zero.

The old October13 `ChemLab-Godot.zip` and `build/macOS/` exports predate the
original-logic corrections. The current macOS development build is
`ChemLab-original-port-WIP-macOS.zip`, version0.1.3, with the version in its
window title.

Version0.1.3 preserves original BMP RGB through Godot texture import, including pixels whose display alpha is zero. This fixes dark dropper rectangles and corrupted beaker edges without changing the original mask, blend or chemistry routines. All107 original apparatus bitmaps are checked against300,769 original BMP pixels.

Version0.1.2 supplies live numeric storage from the retained original allocator,
preserves reused cells and an owned thread stack, seeds the original RNG from
the live clock, and connects the source particle feedback and drawing recipes.
It no longer requires captured or test allocation profiles to run the opening
experiment. Normal viewport gestures cover NaOH withdrawal, both precipitates,
acid dissolution, continuous pouring and Stop/Run withdrawal again. All28
documents also start and advance ordinary model frames without injected cache
values. These checks do not certify every complete example workflow or all
Windows GDI curve pixels.

To reveal the original dropper controls, run the experiment and click its
exposed rubber bulb. The corrected context menu opens beside the pointer.
See [`live_workflow_2026_10_18.md`](docs/original_logic/live_workflow_2026_10_18.md)
for the changes and verification boundaries.

## Original laboratory behavior

The opening document is the original copper/iron hydroxide experiment. Its droppers withdraw the original two-mL amount and dispense the original 0.2-mL drops. Pouring changes the original apparatus orientation and uses the continuous native transfer routine. There is no percentage-transfer dialog.

The active model calls source-transcribed quantity, heating geometry, thermal, transfer, dissolution, reaction and gas routines in the original order. It preserves ordered species and reaction rows, raw apparatus fields, zero-amount rows, source precision/stores and original phase/condition rules. An unresolved native state produces an explicit error rather than switching to the earlier simulator.

## Verified scope

The 2026-10-15 source milestone passes95 selected Godot checks. Their exact
source/log hashes and unchanged-runtime check are recorded in
`evidence/godot/source-package-validation-vcl-state-2026-10-15.json` in the workspace
and `verification/` in the source archive. The checks retain the boundaries below.

- All 28 original examples import. Original document and molecule round trips are covered separately.
- First Run now follows the original counter-clear, stopped refresh, reaction preparation and air initialization order. A fresh native reference matches all 28 examples at Run return: 84,500 physical numeric cells, 1,183 scalar values and 49 connector resets. Unwritten cells retain explicit test input bytes. This does not establish complete graphics or allocator startup behavior.
- All 140 recorded physics frames match the original executable’s tested stored state under the explicitly recorded fixture memory/stack profile.
- The opening seven-action workflow and 63 physics ticks match the original executable: NaOH withdrawal, both precipitates, acid dissolution, bottle rotation and pouring. The same exact comparison now passes through actual canvas helper releases and main pouring context actions, with a paused-release no-op and resume check.
- 486 original helper-release dispatch cases and 1,014 original pouring-menu profiles match the active interface.
- Independent native oracles cover manual controls, transfer, reactions, dissolution, heat, gas routing, constructor choices, liquid/gas/solid drawing recipes, surface outlines, pixel composition, program expressions and chart calculations.
- The macOS x87 helper executes the original trigonometric instructions through Rosetta. Its 1,014 sine/cosine references and 180 tangent references match exactly. Extended-value conversion preserves signed zero and subnormal rounding. The software compatibility experiment is not a production fallback.
- The actual Windows opening capture attaches with all 3,000 raw numeric cells, ordered species names and 18 captured scalars preserved. This verifies the observed allocation, including unused stale bytes.
- A second Windows session recorded a successful NaOH withdrawal. Replaying the original withdrawal from its observed input matches all 12 captured water/NaOH amount, mass and volume values and the source/recipient species order exactly. Later gas evolution and elapsed ticks are outside this isolated action comparison.
- All 57 recorded Windows GDI requests replay with their exact captured pixel bytes. These bounded requests do not establish complete vessel-frame or VCL parity.
- The six opening vessel bitmaps match all 11,548 captured 32-bit words after original fill and canvas-background composition, using the original document positions as an explicit hypothesis. The comparison verifies this paused checkpoint; it does not certify moving particles, rotated vessels or all examples. See `docs/original_logic/vcl_bitmap_comparison_2026_10_14.md`.
- A later read-only particle capture preserves the complete six apparatus objects and both beakers' solid/bubble objects. All 3,000 material cells remain unchanged; observed vessel centers corroborate the bitmap comparison's positions. Four retained 32-bit particle DIBs and their scanline caches agree. Missing TLS random state remains unobserved, and these objects are not universal startup defaults.
- The original Application.OnIdle registration and message pump are traced. Separate polling and physics clocks, MouseUp/pause timing, modal property ownership and Confirm/Cancel caller continuation match their native references. Delivered input is retained in order through presentation, including typed dialog input; closed-window records cannot deadlock or target a replacement window. Complete native drawing and Run/Pause profile rebinding remain explicit dependencies. See `docs/original_logic/ui_event_order.md`.
- The source-specific bitmap scaling helper matches 126 native cases and 12,237 full pixel words under their explicit reserved-byte profiles. Tilted drawing recipes and retained shared-bitmap dependencies are recorded separately; these checks do not enable an approximate rotation.
- Property quantity/mass edits, confirmation, cancellation and run locking follow the recovered transactions. The live property grid follows the original program→grid→chart ordering in all 28 imported examples under the explicit verification profile.
- Native reference checks cover the shared heap kernel and original startup time/RNG routine. Their production startup integration is still pending.
- The isolated original pen registry, reference counts, dynamic change callback and lazy handle creation match 25 native operations and 693 comparisons. Locks, allocation, graphics and exception unwinding remain explicit integration boundaries; this module does not yet complete the live particle frame.
- The returned pen capture validates 16 existing Canvas links and the complete ten-node pen registry against the earlier raw objects. A separate reconstructed setter uses genuine Godot recursive locks and matches the original instruction trace and 538,808 non-lock bytes. Captured Windows lock internals and foreign graphics handles are not reused.
- The recovered brush setters, shared registry, notifications and lazy handle creation match 23 native cases, 47 operations and 1,344 checks. Fresh Canvas construction also follows the original zeroing, Font/Pen/Brush initialization, shared lock bindings and list registration: 5 native cases, 20 steps and 1,670 checks. These isolated components are still being joined to the live renderer.
- Original memory-manager selection matches 36 native cases and 540 global values, including missing DLL exports and fatal branches. Only the source-selected compatible System manager is accepted by the existing heap. Complete production allocation history remains pending.
- Fresh TBitmap construction matches 20 native cases and 4,260 object/guard bytes, including source-defined initialization and shared-image references. A combined VCL world now executes the allocator and Canvas/Pen/Brush/Bitmap constructors in one byte memory and stack with real recursive locks; its 12 reference steps and failure/lifetime guards pass 1,523 checks. This establishes that isolated shared world, while live-frame integration remains unfinished.
- Lazy BitmapCanvas creation matches five source-prepared graphs and 10,528 object/list/registry bytes; repeated access preserves the same object. Rectangle required-state and pen/brush selection match 12 native operations and 1,324 checks. Native DC creation, image copying and raster results remain explicit dependencies.
- Failed or malformed drawing/scanline responses preserve the native call stack and reject pixel feedback. The captured particle-prefix check now retains the unresolved helper's original return address rather than treating that call as completed.
- CEM saving preserves complete ordered reaction edits, additions, deletions and swaps, plus independently stored native reagent masses. All 28 unchanged examples round-trip byte-exactly from both recovered JSON and parsed CEM.

These checks execute the original PE’s routines or declared x87 instruction references. They do not by themselves certify the complete Windows UI or every possible interaction. The evidence and each boundary are recorded in `docs/original_logic/`.

## Remaining integration

The current evidence and ordered remaining work are listed in
[`integration_status_2026_10_15.md`](docs/original_logic/integration_status_2026_10_15.md).

The original allocator leaves some numeric cells unwritten, and some gas paths read unwritten stack values. Production now reads their physical bytes from this reconstructed process's retained allocator and owned stack, including prior writes and reuse. It does not import fixtures as defaults or claim to reproduce the historical Windows GUI heap/stack history. Live Windows captures remain scoped observations. Six one-ULP inert-gas differences under the Windows ARM emulator remain a separate numerical investigation. See `docs/original_logic/production_runtime_allocation.md`, `docs/original_logic/gasflow_trace.md`, `windows_capture_validation_2026_10_14.md` and `live_controlword_audit.md`.

Particle updates now run in the normal canvas with persistent source pools,
live original RNG calls, bitmap surfaces and chemical cache feedback. Normal
rendering uses original material/tilted recipes, resource masks and blend
arithmetic with portable non-antialiased raster primitives. Portable curve edge
coverage has not been certified against every Windows GDI result. The separate
verified native presentation API still retains its attestation and atomic
display checks. See `docs/original_logic/production_source_renderer.md` and
`particle_pixel_loop_ports.md`.

Native chart initialization, fixed 240px grids and accepted-tick sampling are integrated. The original selection priority and body/attachment dragging are integrated and verified against 4,509 native selection decisions and 169 native movement cases. Actual-scene checks cover 28 imports, four charts and 28 accepted program ticks under an explicitly supplied verification profile. Chart/annotation/label edits preserve original CEM records. Bitmap/wood/button resize and release associations now execute retained original instructions; 75 geometry and 84 association references cover those branches. Native raster presentation, remaining dialog transactions and library editing still require completion. The project is not yet a completed release in which all 28 examples have been verified end to end. The old prototype tests must not be represented as fidelity acceptance tests. External runtime comparisons without their captured input are reported as PENDING separately from completed local checks; they are not counted as passing.

The molecule and encyclopedia modules retain the original recovered content. Complete parity for all three historical programs, printing, AVI capture, courseware compilation and network features has not been established.

## Sources

`scripts/original_model_host.gd` hosts the native laboratory state. `scripts/original/` contains source-bound ports. `scripts/main.gd`, `lab_canvas.gd` and `lab_dialogs.gd` connect those ports to Godot. `experiment_adapter.gd` and `legacy_formats.gd` preserve the original documents.

The original executable SHA-256 is `7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c`. The recovered binaries and decompiler exports remain in the repository’s recovery folders. Numerical reports identify observed, inferred and unresolved behavior rather than calling an approximation original logic.
