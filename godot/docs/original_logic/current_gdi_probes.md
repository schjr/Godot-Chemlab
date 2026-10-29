# Current Windows GDI pixel probes

This package uses the current color/device renderer. Do not use the guest's
old `reference-probes` monochrome renderer. The original bitmap virtual
slot +3C is SetTransparent, not SetPixelFormat(1).

Extract `current-gdi-probes.zip` into a new local working folder. In an ordinary
Windows PowerShell session, using the existing execution policy, run:

```powershell
.\run_current_gdi_probes.ps1 -Output .\current-gdi-result.json
```

If the existing policy disallows local scripts, retain that policy and report
the restriction. This package does not request elevation, change policy,
install anything, launch the target application, or write its files. The
offline probe makes no network connection and creates only the requested
result file. Add-Type compiles the included local C# using the host's normal
temporary compilation facilities. The optional persistent host is included
for review; the probe does not start it, and it permits loopback binding only.
The offline runner supports inherited StrictMode: absent initial pixel data
is checked through PSObject.Properties, and Arc-only endpoint fields are read
only for Arc. Mandatory fields remain errors when missing; StrictMode is not
disabled. Runtime provenance fields are required framework/PowerShell members;
optional system DLLs are checked for existence before reading their metadata.

To compare a later run with an earlier result from this identical corpus:

```powershell
.\run_current_gdi_probes.ps1 -Output .\repeat-result.json -Compare .\current-gdi-result.json
```

Each result contains complete visual-top-down B/G/R/reserved bytes as base64,
their SHA256, bitmap format, final stretch mode, and separate RGB/reserved
byte difference counts when comparing. Provenance includes every package
file hash, original executable and instruction-fixture hashes, OS/process
architecture, PowerShell/CLR versions, desktop color depth, and system GDI
DLL hashes/versions. A failed case aborts before writing a successful result.
Read all comparison counts; the script deliberately does not label a capture
or repeatability match as original VCL verification.

The corpus contains exact recorded solid-stencil/texture operations from
004744DC, exact surface Rectangle operations from 00473E6C, four recorded Arc
geometries on explicitly synthetic initial pixels, and labelled synthetic
format/clipping/hollow/empty/scaled-copy boundary cases. Coordinates from
the native instruction oracle are not altered. Arithmetic tint and white-key
composition are excluded from these GDI primitive probes; their separate
native arithmetic tests already exist. The selected cases are bounded by
96 images, 256x256 pixels/image and 16 operations/image. This is a finite
review corpus, not an exhaustive geometry atlas.

Source audit: 004E8610 uses a screen-compatible device bitmap for the fresh
solid stencil; 004EA36C converts to color32; original fill BMPs are color24.
004E43C8/004E4588/004E4744 call Rectangle/Ellipse/Arc and ignore BOOL.
The pen is PS_SOLID,width1,R2_COPYPEN; solid/hollow brush selection updates
native background mode/color. Original guti is the hashed 90x90 color24 BMP,
opaque native StretchBlt SRCPAINT. 004E917C sets the color stretch mode;
004E4420 CopyRect inherits it. See `vcl_bitmap_profile.md` for addresses and
the exact source construction trace. The C# source uses actual GDI calls
rather than an ellipse approximation or a monochrome stand-in.

What these results establish: actual Windows GDI pixel references for the
declared construction/operation profile, and byte-level repeatability or
differences against another run of this same corpus. They do **not** prove
the original process's live allocations/DC state match this profile, reserved
bytes survive every VCL conversion identically, all particle geometries are
covered, or a complete experiment frame matches. `native_vcl_verified`
remains false. Original application memory/frame captures are still needed
before enabling the production verification flag. No Windows execution was
performed while preparing the package on macOS.

Rebuild locally from the source workspace with:

```sh
UV_CACHE_DIR=/private/tmp/chemlab-uv-cache uv run --no-project python tools/package_current_gdi_probes.py
```

The zip is reproducible; its manifest checks all bundled inputs before a
probe runs. No obsolete guest probe files are included.
