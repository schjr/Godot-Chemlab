# Native material pixel boundary

`OriginalMaterialRasterizer` consumes `OriginalSolidVisual.compute()` recipes,
not replacement geometric shapes. Its public entry point is
`render_solid_words(destination_words, width, height, recipe, atlas)`. Words
are native unsigned 32-bit DIB B/G/R/reserved bytes, arranged in visual
row order from top to bottom. The result retains these words and supplies an
opaque RGB Godot `Image`; a DIB reserved byte is not an alpha channel.

The native routines 004928A0 and 00492560 establish the tint and final
composition formulas. These are applied by the previously native-validated
`OriginalSolidVisual.tint_pixel()` and `composite_pixel()`. Arc pixels use
the original COLORREF pen, converted to DIB BGR. Native white pixels remain
white-key transparency; there is no invented particle or opacity layer.

## Required GDI evidence

The native solid helper 004744DC enables bitmap transparency through virtual
slot +0x3C, draws its white/black stencil, uses `TCanvas.Draw` with
`SRCPAINT` (`00EE0086`) and original 90x90 **24-bit** `guti.bmp`, then
004928A0 explicitly selects `pf32bit` through 004EA36C for tint.

An earlier label incorrectly described virtual +0x3C(1) as `pf1bit`.
Actual VMT evidence proves otherwise: global 004E2AA8 points at TBitmap
VMT 004E2AF4; +0x3C resolves to 004E6420, which stores a boolean at object
+0x19 and invokes its Changed virtual. Pixel format is a different setter,
004EA36C. The recipe/oracle labels and this probe have been corrected.
There is no source evidence for a monochrome conversion in this path.

The original bitmap's initial device format, GDI primitive edge pixels,
source transparency handling and reserved-byte writes remain native
presentation boundaries. The probe now uses the source-traced device-compatible stencil, native
GetDIBits32 conversion, and a separate DIB32 Arc pass; it must
be compared against the original VCL bitmap before declaring equivalence.

`tools/capture_original_gdi_masks.ps1` is a Windows-only direct GDI probe:

```powershell
.\capture_original_gdi_masks.ps1 `
  -Fixture .\native-solid-visual-oracle.json `
  -Guti .\guti.bmp `
  -Output .\original-gdi-mask-atlas.json
```

The fixture is `evidence/original_logic/native-solid-visual-oracle.json`;
the texture is `artifacts/ChemLab/res/guti.bmp`. The script checks its SHA256.
It uses Win32 Rectangle/Ellipse/Arc, one-pixel solid pens, real source BMP
loading and native BitBlt. It outputs each unique fixture geometry's
post-SRCPAINT color bitmap plus its separate Arc coverage. It does not
use System.Drawing's GDI+ primitives. Default counterclockwise Arc direction,
the source-traced color/device profile, current brush state and
clWindowText are explicit
probe conditions. Whether these match the original VCL implementation must
be checked against original output before accepting the atlas.

The probe intentionally writes `native_vcl_verified: false`. After original
VCL comparison, the caller must retain the comparison evidence and enable
this marker. An unverified marker or a geometry not present in the atlas
returns an explicit error. This is an evidence boundary, not a completed
cross-platform implementation of GDI's rasterization algorithm. Currently
there is no verified shipped atlas, so the opening settled-solid image is
not yet established as pixel-identical by this module alone.

An atlas has format `chemlab-gdi-mask-atlas-v2`, original `guti_sha256`, a
verification marker and an `entries` dictionary. Keys encode dimensions,
ordered integer rectangle/ellipse bounds and Arc endpoints; color is
excluded because it is applied by the native pixel formulas later. Each
entry contains `stencil_texture_bgra` (base64, four bytes per pixel,
post-conversion), `arc_coverage` (base64, one byte per pixel) and dimensions.
No-Arc geometries have all-zero coverage. Additional live scene geometries
need corresponding captures, rather than choosing a nearby atlas shape.

To establish full rendering parity, compare at least the opening experiment's
actual bitmap size and integer solid geometry, all 73 recorded solid profiles,
odd dimensions/negative clipped bounds, original device-format texture conversion, and Arc
writes to the reserved DIB byte. The native draw fixture already records
exact coordinates and color-independent shape recipes. Native suspended
particles remain a separate renderer outside this settled-solid helper.

## Verification

`tests/test_original_material_rasterizer.gd` passes 21 original executable
pixel fixtures through the full rasterizer composition route, checks DIB
reserved-byte preservation and RGB channel presentation, and tests synthetic
mask routing plus rejection of changed/unverified/absent captures. Synthetic
masks test plumbing only; they are explicitly not native GDI pixel goldens.
The Windows generator has not been executed in this macOS environment.
Its implementation now shares `tools/windows/original_gdi_host.cs`; copy
that relative supporting path as well. See `vcl_bitmap_profile.md`.
