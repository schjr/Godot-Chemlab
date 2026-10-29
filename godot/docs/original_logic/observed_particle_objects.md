# Scoped raw particle-object backing

Optional `pool.native_raw_object` now selects complete observed bytes instead
of synthetic whole-object initialization in Frame._pool. Its descriptor must
contain original image SHA, source scope, original allocation address,
byte_size3468C (solid) orFC20 (bubble), raw_hex and matching SHA256. The input
is not automatically attached, and it does not attest production VCL state,
seed RNG, allocate a collision polygon or reconstruct missing bitmap pixels.

Uninterpreted records, metadata, cache tables and region bytes remain exactly
in the supplied body. Bitmap rebasing is restricted to source-proven pointer
fields solid34678/3467C and bubble+04. An optional `bitmap_bindings` entry
for such a field must match the original raw pointer and provide complete
original32-bit words, pixel checksum, source provenance, dimensions and
explicit native visual-row addresses. Missing bindings are legal when the
executed source branch never needs them. Actual unbound reads/callbacks fail
explicitly, and adoption does not look up unavailable bitmap metadata merely
to format output.

## Exact scanline-table layout

| Physical range | Source meaning | Original bitmap |
| --- | --- | --- |
|32D68..339E7|800 DWORD scanline pointers|primary pointer34678|
|339E8..34667|800 DWORD scanline pointers|retained pointer3467C|

Source49B98F..49B9BE loops over the primary bitmap's height, calls4E95B0,
and stores returned rows at32D68+y*4. Source49B9CA..49B9F9 does the same
for the retained bitmap into339E8+y*4.49C996..49CB41 and49CC6E read these
cached pointers for pixel feedback. These are source-address tables, not
color palettes to be replaced with an empty list.

Native4E95B0 (decompiled.cpp94557) calls4E9130,4E9668 and GdiFlush, then
returns shared.bits(+2C)+stride*stored_y. Positive signed_height(+38)
selects stored_y=signed_height-y-1; otherwise stored_y=y.
Stride is4E510C(width(+34),bit_count(+3E),32). The existing capture's bits
pointer, signed height and row stride therefore establish row addresses for
an already available matching DIB. The parser must check populated cached
row entries against that actual evidence. It must not infer CPU pixels or
conversion results for an unavailable DDB/24-bit bitmap; this bounded binding
supports explicit32-bit backing only. Stable read-only captures also do not
prove the target's pending GDI has drained.

## Hosted pointer isolation and output

Original bitmap/scanline target domains are reserved before constructing the
hosted VM graph. Hosted addresses cannot be allocated at those original
pointer targets and make an unobserved pointer accidentally readable. Only
supplied known row addresses receive exact supplied pixel bytes. Missing
bitmap callbacks and ordinary unresolved VM reads report explicit boundary
errors rather than Dictionary indexing errors or fabricated pixel buffers.

On adoption the full updated object body is retained. Hosted bitmap pointer
values are restored to their original snapshot identities; source-updated
pixel words and raw-object checksums are updated. A dimensions change on an
observed bitmap requires new exact backing; no synthetic resize is performed.
Unknown region pointer targets remain unsupported on actual use. The
reduced convenience pool fields remain views; raw bytes are the complete
record of inactive/uninterpreted fields. Whole raw vessel4348 loading is not
implemented by this pool adapter.

`test_original_observed_particle_object.gd` passes malformed/hash/missing-row
rejection, inactive solid/bubble sentinel retention, source pointer restoration,
checksum update, unaccessed/unavailable DDB adoption and alias prevention.
It executes retained source frame instructions on explicit diagnostic blobs;
these are not the pending PID9348 Windows observations. Existing actual-native
opening66-render/60-tick acceptance also passes after the optional branch was
added. Production profile attestation/startup behavior remains unchanged.
