# Original vessel bitmap comparison, 2026-10-14

The returned Windows archive `build/windows-reference/vcl-pixel-results.zip`
has SHA256 `9355cf55a460ea3543c52b503bb4b123fc6f3cbc8b72b2110c9f5a5978d71198`.
All five members and the four-member result manifest were verified before
extraction into `evidence/windows-runtime/vcl-pixel-results-2026-10-14/`.
The input manifest preserves the reviewed module-deduplication correction.
No original-process calls, writes, suspension, GDI flushing or new privilege
changes were used for these captures.

The original process was PID9348, PE32 at00400000, with the pinned executable
SHA2567744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c.
Run/pause identity and elapsed bytes remained stable. All3000 numeric array
cells and the18 previously captured scalars match the full80-naoh baseline.
The newly observed six+3CC0 values are all raw positive zero. This confirms
the earlier material corpus's explicit zero hypothesis for this checkpoint;
it does not turn that value into a startup default.

All18 existing DIBs were readable and stable during the repeated reads.
The six+FC material/final bitmaps and six+F4 fill bitmaps are32-bit BI_RGB.
All six+F8 apparatus bitmaps are24-bit BI_RGB, with padded row strides160,
92 and48 for widths53,30 and15. Treating those sources as32-bit words is
incorrect. Their raw storage and top-down row orientation are retained.

The live+F8 pixels match the underscore mask resources `_sb200`, `_xkp` and
`_jtdg_2`; +F4 visible pixels match the full shaded body resources `sb200`,
`xkp` and `jtdg_2`. All23096 pixel comparisons across these twelve images
match in `bitmap-asset-identity.json`. Existing UI asset terminology such as
`native_bitmap_plain` identifies the visible body asset; it must not be
interpreted as the original+F8 mask slot. Swapping those native roles changes
2691,1369 and334 pixels respectively. File padding and the unused conversion
byte are outside this resource-color identity check.

`tools/analyze_original_dib_capture.py` validated the source and returned
manifests, bitmap object/header/backing identities, material requests and
cross-capture state before creating `comparison-input.json` (SHA256
581645423211d700eaedee8d9311b2af56fb478fdd3dafad68d21cd3d725b58a).

The first bounded comparison unpacks24-bit BGR bytes without their padding,
applies the same-size RGB SRCPAINT hypothesis and the original4926E0 fill
arithmetic. Its visible colors match four vessels; the two droppers differ
at613 and615 pixels. The original40FD82 final stage explains the difference:
it applies492560 to the post-fill foreground and the previously drawn canvas
background at weight0.5, then40FE60 displays the complete bitmap with SRCCOPY.
Setting TransparentColor does not make this final BitBlt a white-alpha draw.

The second comparison uses the original CEM centers as an **explicit
hypothesis**, a white background outside earlier vessels, and actual captured
earlier+FC pixels in original order. It applies the already native-tested
`OriginalSolidVisual.composite_pixel(foreground, background, 0.5)` and source
unscaled placement. Runtime positions, prior decorators and canvas clipping
were not independently captured.

| Native index | Apparatus | Dimensions | First RGB differences | After background: full-word differences |
| --- | --- | --- | --- | --- |
|0|Beaker|53×58|0|0|
|1|NaOH bottle|30×52|0|0|
|2|NaOH dropper|15×76|613|0|
|3|Beaker|53×58|0|0|
|4|Acid bottle|30×52|0|0|
|5|Acid dropper|15×76|615|0|

All11548 final32-bit words match in `word-overlap-comparison/comparison.json`.
For every pixel, substituting00 versusFF in the projected plain source's
unobserved byte gives identical4926E0 output. The source checks only RGB and
then either copies the entire known32-bit fill word or clears the output
reserved byte. This eliminates that unknown from the final comparison; it
does **not** certify the intermediate native24-to32 conversion.

The original, first RGB comparison, RGB overlap comparison and final-word
overlap comparison remain separate evidence. PNG previews use opaque RGB;
native reserved bytes are compared in the numeric words, never treated as
opacity. No captured file or frozen probe package was rewritten.

This is an exact match at one paused, observed six-vessel checkpoint under
the declared overlap hypothesis. It does not establish the complete VCL
construction/DC history, pending GDI drainage, moving particles, arbitrary
overlays, rotated vessels, scale branches, or all28 examples end to end.
The native presentation coordinator must preserve the final background
composition stage and reject incomplete profiles before canvas adoption.
# Later particle-object capture

The returned `particle-pool-results.zip` (SHA256
`c870df7ea34d8e37f54768a0aebef1a54fc1ca4ccf1ccee94b6781ced07feb60`)
passed the reviewed reader, process, paused checkpoint, object digest and all
3000 material-cell checks. Raw vessel+10/+14 reads independently match the six
positions used in the earlier comparison. This is later checkpoint evidence;
the earlier report is retained unchanged, and no earlier canvas-position read
is retrospectively claimed.

Both source-used beakers have zero retained solid/bubble counts in this
observation. Their four solid-layer DIBs are32-bit53x27; every populated
primary/retained scanline-cache row matches the current captured DIB address.
Complete raw objects preserve inactive records and other bytes. These values
are observations of this allocation, never universal startup defaults.

See `evidence/windows-runtime/particle-pool-results-2026-10-14/validation.json`
and `coordinate-corroboration.json`. Initial white canvas, labels/connectors,
target GDI drain, TLS random state and complete VCL history remain unobserved;
`native_vcl_verified` remains false.
