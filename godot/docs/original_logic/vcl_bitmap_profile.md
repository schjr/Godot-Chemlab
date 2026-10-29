# Original VCL bitmap and DC construction profile

This is a static trace of the original PE and its recovered VCL code.
`evidence/original_logic/vcl-bitmap-profile.json` retains binary identity,
actual VMT slots, raw default-resource/ROP bytes and original BMP headers.
It establishes construction/state semantics; it is not a live GDI frame or
an assertion of rendered edge-pixel equality.

## TBitmap and storage

- Global004E2AA8 points at TBitmap VMT004E2AF4. Its virtual+3C is004E6420,
  the transparency BOOLEAN setter at bitmap+19. It calls Changed+10 when
  the boolean changes. It does not select pf1bit.
- Constructor004E8EDC calls TGraphic004E60FC, sets TransparentColor+2C to
  `20000000` (clDefault), allocates a shared image and increments its refcount
  via004E843C. Object allocation0053139C calls InitInstance00531414, which
  zeros fields; initial transparency is therefore false, canvas+24 is null,
  and image handles/bits/dimensions start zero.
- The constructor additionally requests handle type1 only when flag574B54
  is nonzero. The original PE byte is0; the traced direct references are
  its constructor and bitmap-load branches. Runtime mutation of this flag
  is not assumed without runtime evidence.
- A fresh/resized device-format bitmap follows004E9070/004E8610. With no DIB
  info header it uses screen GetDC and CreateCompatibleBitmap, not an
  explicitly monochrome bitmap. The bit-depth1 branch is selected only when
  original bitmap metadata actually requests1 plane/1 bit.
- Loader004E9A44 reads the BMP's actual info header. BI_RGB/BI_BITFIELDS with
  flag574B54=0 use CreateDIBSection and read the real bytes. The checked
  guti, sb100/_sb100, gkp_z/_gkp and tilted equivalents are all24-bit BI_RGB
  with no color table. All recovered res BMP headers are recorded separately.
- Assign004E8F80 shares the image storage; cloning/handle-needed routines
  preserve bitmap metadata. Thus a material bitmap assigned from the original
  fill BMP is initially its color format, not universally device format.
- SetPixelFormat004EA36C is separate and nonvirtual.7 requests32-bit BI_RGB
  with plane1/bit-count32. It calls004E9070, whose allocator004E8610 uses
  CreateDIBSection/native GDI conversion (including GetDIBits/copy paths).
  Tint004928A0, composites00492560/004926E0 explicitly select7.
- GetScanLine004E95B0 calls GdiFlush, computes native aligned row stride and
  reverses the requested row when stored height is positive. Its exposed
  row0 is therefore visual top despite a bottom-up DIB backing store.

## Canvas, pen and brush

Bitmap.GetCanvas004E9448 creates004E8248/004E42A8 on demand. Its handle
creation004E8350 uses CreateCompatibleDC(NULL), selects the bitmap handle,
and selects/realizes an image palette only when present. Canvas constructor
004E42A8 explicitly sets CopyMode+20 to00CC0020 SRCCOPY.

Pen constructor004E3CBC uses default resource574D38, whose raw data establish
black color, width1 and solid style. Its Mode+18 is4, and the original
WORD table574D68 maps index4 to13 (`R2_COPYPEN`).004E3E78 creates the LOGPEN
using the original style table574D48;004E4D20 selects it and calls SetROP2.
Color changes alone do not change width, style or mode.

Brush constructor004E3FAC uses resource574D58: white color, solid style and
no bitmap pattern.004E418C creates the mapped Win32 brush.004E4D50 selects
it: solid style0 sets BkColor to the brush color and BkMode2 OPAQUE; hollow
style1 sets BkColor to its bitwise complement and BkMode1 TRANSPARENT. The
style color is retained when the surface helper only changes style to1.

Font constructor004E3790 explicitly sets color80000008 (`clWindowText`).
Color resolution004E34A4 uses the native system-color lookup for that value;
its current RGB is a Windows runtime property, not universally literal black.
Primitive RequiredState004E4C58 mask0D prepares Handle/Pen/Brush. The actual
Rectangle/Ellipse/Arc wrappers call Win32 directly and ignore BOOL results.

## Texture Draw and CopyRect state

Canvas.Draw004E44A8 sets destination BkColor from its current logical brush
color and TextColor from the font color, constructs the full source graphic
rectangle and invokes the source graphic's Draw virtual. For guti, the
source is a newly constructed bitmap loaded from the real24-bit BMP. No
source SetTransparent call appears in its initialization at main/decompiled
lines8105–8112, so its inherited transparency=false selects the opaque path.

TBitmap.Draw004E917C prepares both canvases/palettes. If device depth is low
(<9) and less than source depth, it uses HALFTONE4 with brush-origin handling.
Otherwise a non-monochrome source selects COLORONCOLOR3. The opaque branch
calls **StretchBlt** with the destination Canvas.CopyMode. The solid helper
sets that mode to00EE0086 SRCPAINT before drawing guti. Source/destination
sizes are90x90 at origin and destination clipping applies.

Canvas.CopyRect004E4420 also uses **StretchBlt**, but it does NOT choose a
new stretch mode. It inherits the current DC state. CopyMode is read from
Canvas+20. Thus a prior Draw can change a later CopyRect's scaling semantics,
and DC state cannot be universally reset to BLACKONWHITE or COLORONCOLOR
for every new logical operation. Caller must track the actual ordered history.

## Native host corrections

`tools/windows/original_gdi_host.cs` now supports three explicit profiles:
0=device-compatible DDB,24=color DIB24,32=color DIB32.32 remains the generic
protocol default; the settled-solid stencil explicitly requests0, matching
its fresh temporary bitmap. Output conversion of24/device profiles uses
native GetDIBits into32-bit visual top-down rows. Input conversion uses
native SetDIBits. These are actual Windows operations, not color formulas
substituted for VCL conversion.

The host explicitly prepares R2_COPYPEN and brush BkMode/color, resolves
clWindowText through GetSysColor(8), and texture Draw uses native StretchBlt
with the source-traced color stretch mode. Request fields `bitmap_format`
and `initial_stretch_mode` specify actual prior state; replies expose final
`stretch_mode`, `desktop_bits` and returned pixel format32. The Godot client
adds these as optional `render_ops` arguments. CopyRect inherits requested
state. A renderer split across requests must preserve this state explicitly.

Source24 and target24/32 ordinary solid/hollow color primitives use direct
RGB colors and no palette/monochrome conversion. System text/background colors
have no color-to-monochrome role in that supported color path. This removes
the earlier supposed pf1bit uncertainty. It does not prove every reserved
byte or edge pixel across DDB/DIB conversion or Windows/device versions.
The native host construction profile still defaults to unverified until its
Windows outputs can be compared; no full-render parity claim is made here.

The underlying API contracts are documented by Microsoft for
[CreateDIBSection](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-createdibsection),
[Arc](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-arc), and
[BitBlt](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-bitblt).
The source-specific state and constants above come from the recovered PE,
not assumptions about an arbitrary stock DC.

## Actual bitmap resource roles

Actual six-vessel runtime DIB comparison (2026-10-14) additionally identifies
the resource roles: +F8 contains underscore masks (_sb200,_xkp,_jtdg_2),
while+F4 contains nonunderscore body images (sb200,xkp,jtdg_2). Twelve images,
23,096 pixel pairs match after that mapping. +F8 is24-bit and+F4/+FC are32-bit
in the observed state. The existing UI `native_bitmap_plain` body-asset name
is not an authoritative native+F8 binding. Native providers must bind actual
captured fields/resources rather than extrapolate from legacy UI aliases.
This source-asset match does not grant general VCL/DC conversion verification.

## Form4 variable cleanup handoff

004A0F50 scans the temporary Form4 variable table's active count and compares
exact names at row field13, stopping at the first empty-name sentinel.
004A1050 accepts its lookup result; -1 is a no-op. Otherwise it shifts all17
fields through physical slot298, decrements count, and does NOT clear299.
The physical table has300 rows of0x44 bytes. Chemical delete004A0A98 and
clear-all004A2194 invoke these helpers independently for the stored mole
and mass binding names (grid-associated arrays596F3C and596DAC), even if both
names match. It does not search by an inferred species/vessel convention.

Those operations affect the TEMPORARY table at Form4+3D0/+3D4. Confirm49F0C8
copies it to main+E20/+E24; Cancel does not. New
`OriginalVariableCleanup` implements the raw table API and source-regression
tests. Model/main/program integration is handed to the formats coordinator;
no active-table mapping or synthetic unused slots are invented here.
