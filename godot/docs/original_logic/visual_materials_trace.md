# Original gas and settled-solid drawing

Original PE SHA-256:
`7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c`.
The source functions are `0x0047692C` (gas) and `0x004744DC` (settled solid),
retained in `recovered/native/main/decompiled.cpp` at lines 37823 and 37139.
Native instructions, existing resource identity and bounded x86 execution
establish these modules; no bubbles, precipitation blobs or generic solid
rectangles are supplied as replacements.

## Gas: OriginalGasVisual

`original/original_gas_visual.gd` exposes `compute(vessel, reagent_map)`.
It returns `draw_operations`, packed native `color_integer`, total gas volume
and headspace when the relevant branch computes them.

The original algorithm:

1. Store headspace as capacity `+0x28` minus current liquid volume `+0x4320`.
   Return without drawing when it is not positive.
2. Sum only `(气体)` species as `moles * 22.4 * 1000`, preserving native
   x87 arithmetic and the original store after each accumulation.
3. Return without drawing below the stored double threshold 0.1.
4. Compute and separately store each gas's volume-weighted native reagent
   color channels, accumulate them in species order, truncate channels to
   bytes, then dilute those **truncated** channels with white when gas
   volume is below headspace.
5. If all three resulting bytes exceed 252, set the color to exactly white.
6. Set the original canvas pen/brush color and solid brush style. Draw the
   original rectangle from `(0,0)` to
   `(bitmap width, truncate(bitmap height - current liquid height +0x30))`.

`draw_operations` therefore contains the original rectangle bounds and
native pen/brush values, including negative or zero bounds when supplied
native inputs produce them. It does not apply a new clipping or alpha policy.
The renderer's current height and bitmap dimensions are required; no estimated
liquid fraction or default gas tint is used.

`tools/original_visual_oracle.py` executes the actual `0x0047692C` instructions
with declared VCL pen/brush/Rectangle and existing string/lookup boundaries.
`tests/test_original_gas_visual.gd` passes 115 original frames covering gas
thresholds, full/diluted headspace, overfilled vessels, mixed gas colors,
near-white normalization, nongas exclusion and exact rectangle bounds.
Inputs use encoded original binary64 words. The fixture is
`evidence/original_logic/native-gas-visual-oracle.json`.

## Settled solid: OriginalSolidVisual

`original/original_solid_visual.gd` exposes `compute(vessel, reagent_map)`.
Required fields include original per-species `native_species_volume`,
current liquid volume and preserved `solid_3cd8` mole cells; missing cells
fail explicitly rather than assuming zero. Type, subtype, capacity and
current active bitmap dimensions are required if the native drawing branch
is reached.

For each `(固体)` species, the original computes the equivalent volume of
its reserved `+0x3CD8` mole cell using original molar mass and density. Its
total settled volume counts the entire species volume when liquid volume is
at most that equivalent volume; otherwise it subtracts the equivalent volume.
The color numerator **always** subtracts it. This original branch distinction
is retained even when it differs from a conventional weighted-color model.

Colors accumulate and truncate in native order. The contour pen multiplies
each truncated byte by original float 0.25 and float 3.0. Capacity clipping
occurs only after color calculation, before shape height. The module retains
the separate linear, CRT cube-root, size-45 and size-97 shapes; integer
dimension halves/quarters, explicit offsets and repeated double stores follow
the native branches. Original inverted/out-of-frame primitive bounds are
returned unchanged.

The original drawing recipe is:

1. Create a temporary bitmap with the original dimensions and pixel format 1.
2. Clear it to white, then draw the native black ellipse/rectangle stencil.
3. Draw the original `guti.bmp` texture at `(0,0)` using copy mode `0xEE0086`
   (SRCPAINT). The global texture `DAT_0057A720` is loaded from `res/guti.bmp`
   in the main form initialization; it is not a new wood/noise texture.
4. Apply the original nonwhite pixel tint routine `0x004928A0` with the
   packed solid color and double weight 0.15
   (`33 33 33 33 33 33 C3 3F`).
5. Draw the original `Arc` contour using its native eight integer coordinates
   and shaded pen color.
6. Composite the temporary bitmap into the active image through
   `0x00492560` with the same weight 0.15, then destroy the temporary bitmap.

Each native presentation operation is returned in order as `draw_operations`.
This is a source-based stencil/texture/arc recipe, not a single approximated
solid fill. The host must apply the original texture, pixel-format behavior,
primitive geometry and masking; a generic colored rectangle or global alpha
blend would change it.

## Exact pixel arithmetic

`tint_pixel(pixel_word, colorref, weight=0.15)` ports `0x004928A0` for a native
32-bit DIB word. It leaves RGB-white pixels unchanged; other pixels blend
their original component with the solid color. It preserves the native
COLORREF-versus-DIB red/blue byte reversal and truncation.

`composite_pixel(destination_word, source_word, weight=0.15)` ports
`0x00492560`:

- RGB-white source preserves the destination word.
- RGB-white destination copies the source word fully.
- Otherwise each byte becomes the native truncation of
  `destination * weight + source * (1 - weight)`, with the stored output's
  high byte cleared as in the original routine.

The white-key branches preserve original whole words, including their high
byte. Consequently applying alpha 0.85 uniformly to every solid pixel is
incorrect: a white destination receives the full source color.

The pixel oracle executes these original routines against explicit native
32-bit 1x1 DIB words. Its only additional boundaries are the bitmap's
dimensions, scanline pointer and a 32-to-32 pixel-format property operation.
All 364 original tint/composition frames pass, including white/high-byte
cases, color channel order and several weights.

## Scope of verification and remaining particle renderer

`tests/test_original_solid_visual.gd` passes 73 original drawing frames for
the operation sequence, packed colors/shading, all integer ellipse/rectangle/
arc coordinates, exact texture copy mode and both weight arguments. Its
profiles include 16 type/subtype branches, tiny/partial/overfilled solid
volumes, mixed solid colors and several reserved-cell/liquid-volume states.
The fixtures are `native-solid-visual-oracle.json` and
`native-solid-pixels-oracle.json` in `evidence/original_logic`.

These comparisons establish original numeric geometry, operation operands
and pixel formulas. Native GDI primitive rasterization and pixel-format-1
texture conversion are presentation boundaries and are not claimed as
bit-identical rendered images by these tests.

The main renderer `0x0040A4B8` also maintains distinct suspended-particle
objects around `0x0049BF44`, `0x0049C298` and `0x0049C620`, with calls to
the original RNG `0x004028EC`. Those operations occur between the liquid/gas
pass and settled-solid rendering. They are separate from these two helpers;
their random state, lifecycle and geometry must be traced before any
particle replacement is implemented. Neither completed module invents a
random particle, bubble or flame algorithm.
