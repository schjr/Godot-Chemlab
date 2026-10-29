# Bitmap import correction, 2026-10-19

Version0.1.3 corrects the dark rectangular dropper backgrounds and corrupted
beaker edges visible in0.1.2. The recovered drawing order and pixel arithmetic
were correct; the texture bytes supplied to them were not.

Godot's default `process/fix_alpha_border=true` dilates RGB under transparent
pixels. For example, the original white top-left pixel of `sb200` became
RGB64,64,64; `_sb200` became black. Both pixels retained alpha0, so ordinary
sprite drawing concealed the changed colors. `OriginalSourceRenderer` reads
RGB as original DIB words, deliberately ignoring display alpha. Native F8
SRCPAINT, F4 blend4926E0 and background492560 therefore consumed changed data.

Every apparatus texture now retains `process/fix_alpha_border=false` in its
import settings. `prepare_godot.preserve_native_rgb` also preserves that option
for new and regenerated images. The alpha keys, source masks, apparatus shape,
compositing formulas and chemistry were not changed.

The RGB fixture is independently generated from all107 cataloged original BMP
resources, checking their source SHA256 and the prepared PNG bytes. The runtime
test compares every one of300,769 imported source-renderer words with those
references. Source, exported PCK and a clean extracted project all pass. The
same test rejects the old0.1.2 PCK, demonstrating that it detects this defect.

The normal running canvas test checks2516 original white exterior pixels:
936 over earlier apparatus and1580 over exposed colored background. The full
visible opening workflow still passes withdrawal, precipitation, acid
dissolution, continuous pouring and repeated withdrawal after Stop/Run. Its
three PNGs were reviewed for dropper silhouette, beaker marks and pouring.
The release executable also starts and exits normally; external UI harnesses
run against its PCK using the test-capable engine, not inside the release
executable. New/existing prepare-helper imports have separate fresh-project
positive and untreated negative controls.

See `verification/bitmap-validation-2026-10-19.json` and `bitmap-*.log` in the
source archive. Existing portable Windows curve-edge limits remain separate
from this import correction. Complete28-example workflows are not claimed.
