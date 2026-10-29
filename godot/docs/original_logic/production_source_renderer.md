# Production source rendering

The normal canvas now uses `OriginalSourceRenderer` without attaching capture
profiles. It reads the actual document and live chemistry values. The separate
strict verified-VCL presentation API remains available and retains its checks.

The production path executes the source liquid rectangle (`471650`), gas
rectangle (`47692C`), solid-particle stage (`40E8E4`), liquid outline
(`473E6C`), settled-solid recipe (`4744DC`), bubble stage (`40F352`), underscore-mask SRCPAINT, full
shaded-body `4926E0` blending, then preceding-vessel background composition
(`492560`, weight0.5). The original resource roles are important: +F8 is the
underscore mask and +F4 is the full shaded apparatus. PNG RGB is unchanged from
those BMP resources; their display alpha is ignored by this native-word path.
Godot apparatus imports keep `process/fix_alpha_border=false`. Alpha-border
color dilation changes transparent white sourceRGB to neighboring dark pixels;
reading those altered RGB values as native +F4/+F8 words produces opaque dropper
squares and spurious apparatus lines. Original whiteRGB must survive import.
The solid texture is the original90x90 `guti.bmp`, drawn at0,0 and clipped,
without stretching it to vessel size.
The original tilted250mL conical body is84x80 and its underscore mask84x79.
Same-coordinate CopyRect clips the absent source row, leaving that destination
row untouched; it does not rescale the shorter mask.

`OriginalPortableRaster` supplies non-antialiased rectangle, ellipse, arc,
line, polygon and SetPixel primitives on original-size pixel buffers. The
recovered numeric recipes and blend routines determine their colors, dimensions
and ordering. Curve edge coverage is portable rasterization and has not been
certified pixel-for-pixel against every Windows GDI geometry. This path reports
`portable_raster:true` and `native_vcl_verified:false`; it does not promote
native capture attestation or invent a replacement chemical simulation.

Open tilted vessels select the source fixed polygons, rather than rotating an
upright texture or filling their bounding box. The implemented polygon branches
cover all original pourable types101,102,103,104,105,106,121,201,202, including
source beaker/conical-size coefficients, the separate tube solid ellipse, and
the measuring-cylinder solid LineTo endpoint quirk.
They read +4320/+4338 while preserving the original tilted branch's old +30.
Unmatched native subtypes preserve the active body bitmap as the source does.

The particle stage uses the actual source instruction IR and persistent pools,
RNG, pixel surfaces, and numerical feedback through the model. In particular it
updates the reserved solid cells consumed by later reaction steps. Source49BBF8
constructs both solid bitmaps, clears them to its InitInstance-zero background,
sets +32D4C=1, and binds both row-pointer tables. These constructor effects now
exist in fresh production pools. TBitmap SetWidth/SetHeight with an unchanged
axis retains its backing. Raw4E894C/4E8969 shows that the changed-size pf32
branch of4E8610 continues into the common FillRect/current-brush and
4E8B4C BitBlt/SRCCOPY path after creating the new DIB. It fills new areas with
the actual canvas brush and copies the old overlap, then rebinds scanlines.
The decompiler's apparent early return at the cleanup boundary is incorrect.
Opaque particle TCanvas.Draw uses
SRCCOPY and includes white pixels. Direct particle VM scanline writes are read
before later bitmap draws; cached words cannot discard that feedback.

Stopped painting is part of initialization. In49B7A4, particle bitmaps are
resized to the liquid column and cleared to its current color only when
run_flag=0. Run must retain these objects and surfaces. Skipping stopped paint
or recreating their bitmaps at Run leaves fresh black DIB pixels beneath the
original opaque particle bitmap Draw and produces incorrect dark solutions.

`test_source_live_renderer.gd` uses the normal opening document and allocation,
without captured numerical profiles, and checks six visible source frames,
live particle execution, different empty/filled dropper pixels, and the original
52x30 pouring bitmap. `test_opening_live_workflow.gd` exercises viewport gestures
for withdrawal, precipitation, dissolution, and continuous pouring through the
same production renderer.
`test_source_background_passthrough.gd` runs the actual opening canvas on a
colored background after withdrawal. It checks2516 original white exterior
pixels, including936 overlapping earlier apparatus and1580 exposed background
pixels, against the original white-key/compositor behavior. This exercises the
imported textures through production composition rather than checking an
isolated transparency setting.
