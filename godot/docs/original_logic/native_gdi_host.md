# Live native Windows GDI rendering bridge

`OriginalGDIHost` removes the need to capture every possible integer ellipse
or Arc shape into a finite atlas. The bridge runs actual Windows GDI for each
requested geometry. There is no Godot ellipse approximation, hand-authored
scanline algorithm, neighboring-mask selection or synthesized particle layer.
The Windows host must be running; an unavailable host returns an explicit
error. This is a native host dependency, not a standalone macOS GDI port.

Parent-managed Windows launch:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\original_gdi_host.ps1 `
  -Guti C:\ChemLab\res\guti.bmp -Port 17708
```

Keep `tools/windows/original_gdi_host.ps1` and `original_gdi_host.cs` together.
The host checks the original texture's SHA256. It binds127.0.0.1 by default;
the caller owns VM port forwarding, process lifetime and any different bind
address. No VM control or legacy app launch is performed by this module.

Godot integration:

```gdscript
var gdi = preload("res://scripts/original/original_gdi_host.gd").new()
add_child(gdi)
gdi.configure("127.0.0.1", 17708, false)
var probe = await gdi.render_ops(width, height, original_operations, [], true)
# After independently comparing the original VCL construction profile:
gdi.configure("127.0.0.1", 17708, true)
var solid = await gdi.render_solid(destination_words, width, height, solid_recipe)
```

`render_ops` accepts Rectangle/Ellipse/Arc operation records, the original
guti texture operation and transparency metadata. Optional initial words
are exact unsigned32 DIB B/G/R/reserved values. Replies retain native words
and also supply an opaque RGB Godot Image. The persistent TCP protocol is
one UTF8 JSON object per line, format `chemlab-native-gdi-v1`, with base64
`initial_bgra`/`bgra`. Bitmap sizes, payload sizes, operation types, brush
styles and texture identity are bounded/validated; requests are serialized.

`render_solid` executes the original stencil/texture pass through the host,
uses native-verified004928A0 tint arithmetic locally, sends tinted native
words back for actual GDI Arc rendering, then applies00492560 white-key
composition locally. Thus live geometry and Arc writes do not require an
atlas, and reserved-byte writes are produced by GDI itself.

## Construction profile and verification boundary

The supplied host now offers device-compatible, color DIB24 and color
DIB32 profiles, with source-traced R2_COPYPEN/one-pixel solid pen, solid/hollow
brush state, clWindowText and default counterclockwise Arc. Texture uses
native StretchBlt SRCPAINT from the real24-bit guti BMP. Win32 primitives are actual native calls. These choices
are explicit, and **original VCL bitmap/DC construction parity still needs
comparison**: its initial device format, source transparency and pixel-format
conversion may affect reserved bytes. Both the host and Godot default to
unverified. Probe mode can collect evidence; production rendering requires
caller confirmation of the independently verified profile.

Bitmap virtual+3C(1) is SetTransparent(true), not pf1bit. Global004E2AA8 points
to TBitmap VMT004E2AF4; its+3C slot resolves004E6420 and stores boolean+19.
Actual SetPixelFormat is004EA36C. The earlier atlas probe was corrected to
color DIB32 and atlas formatv2. No monochrome conversion is assumed.

The Windows code has not been executed on this macOS host. The Godot bridge
compiles and its guard tests pass; native Windows raster pixels remain to
be verified on the parent-controlled VM. Consequently these files alone
do not yet establish the opening experiment's full rendered-frame parity.

## Surface outline00473E6C

`OriginalSurfaceOutline.compute(vessel)` ports this previously unresolved
stage. It reads liquid color+3CD0, multiplies each channel by exact80-bit
literal473FBC (`4992244992244992fc3f`) and single6 at473FC8, then truncates
and packs the shaded pen. Brush style1 is hollow. Supported types are
101–108,121,201,202,204,207–212. Unsupported types still update pen/brush
state but draw no Rectangle, matching the native helper.

Rectangle bounds are `(0, TRUNC(bitmapHeight-liquidHeight), bitmapWidth,
bitmapHeight)`. It is an outline of the liquid column, not an invented
meniscus ellipse or wave. The parent0040F31A caller invokes this helper
only when liquid height>1; direct helper tests include suppressed values
to verify its own branches. All156 original instruction frames pass for
shading, type filtering, hollow brush and exact signed coordinates.

Native VCL primitive wrappers004E43C8/004E4588/004E4744 call Win32 and
ignore its BOOL result. The host likewise keeps the actual bitmap for
empty/clipped geometry instead of inventing an error-triggered shape.
Microsoft documents the native Arc pen/direction semantics in
[Arc](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-arc),
the bitmap synchronization used here in
[CreateDIBSection](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-createdibsection),
and raster operations in
[BitBlt](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-bitblt).
These API contracts do not by themselves establish original VCL construction
parity; that remains a separate comparison.

`copy_rect(destination,W,H,source,sourceW,sourceH,destinationRect,sourceRect,
copyMode,probe)` additionally hosts original004E4420's **StretchBlt**.
Callers provide both original rectangles explicitly. This handles differing
apparatus/fill bitmap sizes through actual GDI; it does not resize with a
Godot filter or infer source bounds. Supported original copy modes are
SRCPAINT and SRCCOPY. The original wrapper ignores the BOOL result.

The optional final `render_ops` arguments are `bitmap_format`(0/24/32) and
`initial_stretch_mode`(1–4). The settled-solid stencil uses0; its native
output conversion to32 precedes the local tint. A subsequent Arc uses32.
See `vcl_bitmap_profile.md` for the exact constructor/DC source trace.
