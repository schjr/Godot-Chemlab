# Native per-vessel bitmap order and final composition

`OriginalVesselBitmapRenderer.plan(vessel, reagents)` isolates the upright
0040A4B8 material branch. It calls `OriginalLiquid.refresh` first, preserving
its actual liquid-height/cache writes; it then obtains original gas and solid
recipes. It returns the complete native stage order, including unresolved
particle/overlay stages. It does not silently omit those stages.

`compose_native_words(vessel, material, plain, fill, capture)` finishes an
already verified native material raster. Inputs must be equal-size native
32-bit DIB B/G/R/reserved words in visual row order. `material` represents
+0xFC **after** all material/particle/overlay stages, `plain` is +0xF8 and
`fill` is +0xF4. These are the actual original bitmaps selected by loading
or N18Click, not generated geometric masks. Caller must provide
`native_material_verified` and `native_srcpaint_word_format_verified`.
Missing provenance is an error. This deliberately does not claim that
RGB images decoded through a different bitmap format reproduce every
native reserved byte before conversion.

The final result retains native words and gives an opaque RGB Godot Image.
White-key background/canvas compositing, rotation/scaling, selection and
other main-canvas display operations are separate. Native DIB reserved
bytes are preserved in words and are not used as Godot opacity.

## Native addresses and order

For the upright material branch in `evidence/original_logic/0040a4b8.cpp`:

1. Enable +FC bitmap transparency; white pen/brush Rectangle clears it.
2. Set +30 liquid height to zero, then call liquid 00471650 at **0040E8C1**.
3. Gas 0047692C at **0040E8DC**.
4. Original particle bitmap/object branch (including 0049BF44,0049C298,
   0049C620, and the alternative bitmap Draw when particle display is active).
5. If liquid height >1, outline 00473E6C at **0040F32F**.
6. Settled solid 004744DC at **0040F34A**.
7. Running display/particle overlays and type108 special 00492560 composition.
8. Set +FC canvas CopyMode **00EE0086 SRCPAINT**; CopyRect the +F8 plain
   apparatus into +FC at full bitmap bounds; restore **00CC0020 SRCCOPY**.
9. Fill/mask 004926E0 at **0040FB72** (201/202 size1000 weight0.3) or
   **0040FBA7** (all others weight1.0). Source pointer is +F4; destination
   is +FC. The corresponding separate tilted branch uses0040D823/0040D858.
10. Main-canvas capture/rotation/background composition and final SRCCOPY
    BitBlt follow; these are outside this per-vessel material module.

The bitmap virtual call +0x3C(1) is **SetTransparent(true)**, not pf1bit.
Original global004E2AA8 holds VMT004E2AF4; slot+3C resolves004E6420 and stores
a boolean at bitmap+19. Actual pixel format setter is004EA36C, with7 meaning
pf32bit. Previous captured call labels have been corrected. There is no
justification for converting the solid stencil to monochrome in this path.

## Original 004926E0 pixel formula

This is distinct from tint004928A0 and ordinary composite00492560.
The original routine selects pf32bit for both bitmaps. If destination RGB
is white, it copies the entire fill word, including reserved byte.
Otherwise it computes:

- `product = storedDouble(fill.red * 0.00392)` (literal49288C).
- `factor = min(1, storedDouble((1-product)+0.65))` (literal492898).
- Each byte becomes `TRUNC(fill.byte*(1-weight*factor) +
  destination.byte*weight*factor) &255`, preserving native x87 order.
- The reserved byte is cleared for this nonwhite branch.

Constants are the original binary64 bit patterns, not an inferred1/255
or a generic opacity setting. Mask factor depends specifically on **red**.
The SRCPAINT-before-fill order is significant: apparatus white pixels can
force the white-copy branch even when the preceding material was colored.

`tools/original_vessel_pixels_oracle.py` executes actual004926E0 instructions
with declared dimensions/scanline and 32-to-32 format boundaries. Its1098
frames include two original caller weights, arbitrary BGR/reserved words,
white/high-byte cases and seeded random colors. All bit-for-bit comparisons
pass in `tests/test_original_vessel_bitmap_renderer.gd`.

## Remaining boundaries

The plan is not a whole renderer parity claim. Rotated branch geometry,
actual native GDI Rectangle/Ellipse/Arc rasterization, particle state/RNG,
mode-specific particle bitmap source,
running overlays, type108 special composition and main-canvas transforms
still need exact implementations or captures. Settled-solid GDI mask
atlases are accepted only after original VCL verification; uncaptured
geometry fails explicitly. No replacement bubbles, flames, sprites or
surface effects are inserted.

The surface outline is now ported in `original_surface_outline.gd` and
validated against156 original instruction frames. Its live Rectangle raster
can be sent to `OriginalGDIHost`; see `native_gdi_host.md`.
