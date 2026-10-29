# Original state-specific and scaled drawing audit

Retained source `evidence/original_logic/0040a4b8.cpp:295` selects its special
material branch only when vessel DWORD +18 equals2 **and** DWORD +38 equals0.
This branch draws apparatus/subtype-specific polygons and line endpoints from
native liquid +4320 and solid +4338 caches; it is not a general rotated texture.
The common `else` starts at line1404. Its +38==1 path draws direct canvas
geometry before common material processing. Nonzero +18 alone does not select
the special material branch, but does not establish the identity of that state's
+F4/+F8/+FC resources either. `OriginalVesselDisplayBranch.classify` reproduces
this selection; `plan` demands explicit verified state/resource bindings for
nonzero orientation and exposes unresolved polygon/direct-canvas dependencies.
The existing production orchestrator's orientation rejection remains intact.

Raw original instructions40FBAF–40FBE0 load global5636C0, subtract literal1,
store the difference as double, take absolute value through5394D4 and compare
to0.01. Outside the near-one branch,40FE6A–40FE8E stores scale to float32 and
calls48F1E0(+FC, shared5867F0, scale32). The resampled shared bitmap then becomes
the destination of background compositor492560 and the source of final SRCCOPY.
Scaling occurs **after** F8 SRCPAINT and4926E0 fill and **before** background
composition. The near-one branch uses +FC directly. `placement` records the
source FTOL background rectangle and distinct scaled/unscaled display offsets;
negative centers can make background extraction and unscaled IDIV2 placement
differ, so clipping or a white canvas cannot be inferred.

`OriginalBitmapScale.resample` ports48F1E0 from retained decompiled source
`recovered/native/main/decompiled.cpp:44336` and raw PE disassembly saved in
`evidence/original_logic/0048f1e0.asm`. It preserves float32 scale and coordinate
stores, double-stored interpolation weights, sequential x87 sums and FTOL
truncation. Boundary pixels copy a full original source word. Interpolated
pixels write only B,G,R into stack local[EBP-14..EBP-12] and copy the untouched
[EBP-11] byte too (48F4F2,48F550,48F5AE,48F5BE). That byte must be explicitly
supplied; it is never invented as opacity. Unlike the preceding fill stage,
resampling can reintroduce this unknown reserved byte after fill has completed.
RGB output does not depend on it, but native final word comparisons do.

Native returns1 without changing the shared destination for scale32<=0.1,
scale32>4, or source height>300. The caller ignores that return; reconstructing
this case requires prior shared5867F0 contents and dimensions. The port reports
`changed:false` and does not fabricate them. Native source and destination
scanline pointer arrays have300 and600 slots. A destination above600 rows would
overwrite original stack locals; the port explicitly rejects that unsafe domain
instead of pretending to reproduce corruption. The normal fixed native
apparatus sizes fall within the bounded domain.

Validation: `tools/original_bitmap_scale_oracle.py` executes raw original PE
48F1E0 with hosted bitmap dimension/scanline and pf32-identity callbacks. It
sets the untouched stack byte explicitly to0,A5,FF. The126 fixtures contain
12,237 output words, all matched bit-for-bit by `test_original_bitmap_scale.gd`.
These validate original numeric resampling, acceptance boundaries, dimension
stores and full-word edge copies. They do not validate native TBitmap format
conversion, allocation, scanline orientation, clipping, GDI edge pixels,
state-specific polygons or complete original frame drawing. The helper and
recipe do not promote any VCL or production-profile gate.
