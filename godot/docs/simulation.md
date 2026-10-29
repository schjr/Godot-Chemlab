# Original simulation port

The earlier educational substitute engine has been removed. `LabModel` now extends `OriginalModelHost`, which calls the source-bound modules in `scripts/original/`. No generic reaction solver, illustrative pH formula, percentage pouring, invented gas-transfer rate or substep integrator is used by this host.

The original callback order is heater geometry, thermal update, continuous apparatus transfer, per-vessel dissolve/reaction/dissolve, quantity refresh, open gas, conduit graph, remaining gas, quantity refresh, original bindings/programs and graph update. Mouse holds suppress accepted ticks; release resets the original time baseline. Run clears its original active caches and elapsed time. Native drawing/cache feedback has its own persistent state and must run in its original order as integration completes.

Native arithmetic retains x87 intermediate precision and the source’s double/float32 stores. The original transfer quotient’s double store is significant. Source quirks, zero-quantity rows, reaction order, phase-specific density, concentration colors, apparatus temperature behavior and native recipient selection are preserved rather than replaced by chemically preferable rules.

## Evidence

`original_logic/frame_verification.md` records the 28-example, 140-frame physics corpus and the seven-action opening protocol. The corpus explicitly supplies its known allocation bytes and observed stack inputs. It does not establish a universal heap initializer or certify particle presentation, UI timing and programs outside its stated scope.

`original_logic/allocator_startup_particle_audit.md` demonstrates that the apparatus allocator does not zero the full payload. The managed particle classes do zero their payload through their original instance initializer. These distinct facts must not be collapsed into one default-zero rule.

`original_logic/vessel_bitmap_renderer.md` and `native_gdi_host.md` document original material order, GDI operations and pixel composition. Full VCL construction and live rendered-frame comparison remain required. The native x87 host avoids substituting a platform trigonometric library for the original FSIN/FCOS instructions on this Mac.

## Current limit

Independent routine checks pass their recorded cases, including the full opening chemistry/transfer protocol. The production application still has unresolved startup memory and native rendering integration. Therefore this source tree is work in progress; all 28 examples have not yet been certified end to end. It deliberately reports an unresolved source boundary instead of simulating a simplified replacement.
