# Deferred original particle RNG access

Source4028EC compares its bound at4028EF, branches to XOR EAX,EAX at402902
when it is zero, and calls539C60 at4028F5 only otherwise. Actual original PE
execution confirms bound0 returns0 with no TLS access and unchanged
explicit diagnostic state; bound5 makes four TLS accessor calls and updates
that state. Exact instructions and references are retained in
`rng_lazy_access_evidence.json`. The diagnostic bytes are not a startup seed.

OriginalParticleFrame passes its supplied RNG Dictionary to the instruction
VM without an eager state check. Existing VM semantics therefore already
allow `{}` through a source frame branch that makes no random request. The
only correction made here is at the actual nonzero4028EC access boundary:
present-but-unobserved/null or malformed DWORDs now fail explicitly instead
of converting to zero. Losslessly decoded integral DWORD-valued JSON numbers
are accepted; no missing state is generated. Production host configuration
attestation and original startup-seed policy are unchanged.

`test_original_rng_lazy_access.gd` passes zero-bound/missing/null/malformed
checks, actual native positive-bound state/output, and a complete retained
frame with run_flag2, no emissions and no random access. Its pools/pixels are
explicit bounded test inputs, not the pending Windows checkpoint.
Higher-level OriginalLiveParticles convenience functions still have eager
RNG checks; this conclusion applies to retained source instruction execution
through OriginalParticleFrame/OriginalParticleVm, not every helper API.

## Raw object capture interpretation

The requested capture sizes match the source class allocations: solid3468C
and bubbleFC20. Frame.create_scene constructs pools only when100<type_id<200.
That is a constructor/fresh-object helper, not a decoder for an existing
process allocation. The PowerShell reader instead captures all nonnull
observed pointers from native tables595214 and5940B0 and retains full blobs;
null pointers must remain absent, even if an inferred constructor branch
would normally create an object.

Existing Frame._pool reconstructs a zeroed class and selected fields. That
is insufficient by itself to import arbitrary raw live objects: untouched
record tails and source pointer caches must retain their observed values,
with explicit pointer relocation for hosted bitmap/scanline objects. Source
solid pixel code uses32D68/339E8 and subsequent indexed cells (49C9B5,
49CA78,49CC6E), beyond the current reduced pool dictionary. Bubble collision
branches read7EF8, region/geometry cells7F08/7F0C andDCC8/FC0C; frame code
currently rejects a nonempty region profile rather than guessing its layout.
The full raw block preserves those bytes but does not independently supply
Windows region contents or make an original pointer valid in hosted memory.

A parser must retain raw bytes/source pointers, validate blob length/hash and
VMT identity, decode only established fields, and explicitly relocate each
actually used original pointer to observed backing. It must not fill omitted
region/palette/scanline-cache cells from create_scene defaults. Source-path
no-operation may leave unknown cells unaccessed, just as deferred RNG does;
required pointer/region/pixel accesses must fail when their backing remains
unobserved. The pending reader is read-only and does not call GetScanLine or
GdiFlush in the target; stable reads do not establish VCL/GDI completion.

## Direct source helpers corrected

The direct OriginalLiveParticles APIs now match lazy access as well. Actual
native49BF44,49C298,49A61C and49AA88 execution in
`particle_noop_rng_evidence.json` confirms nine no-op branches make no TLS
access: capped/empty/subunit solid emission, empty/frozen/delete-only solid
update, bubble throttle/zero request and empty bubble update.

Solid RNG validation moved to the first emission call49C08B, after source
coordinate stores, and the drift call49C3C8, after deletion and deterministic
trigonometric movement. Trig availability is checked only when a surviving
particle actually reaches FCOS. Bubble emission validates on its actual
source-point/position/angle random access; a zero-bound position selection
still requires no state. Bubble updates delegate actual access validation
to the retained VM. Malformed/null/out-of-DWORD observations fail only when
consumed; no-op branches preserve them unchanged rather than assigning a
seed. Missing region/primitive inputs retain their independent unresolved
boundaries.

`test_original_direct_particle_rng.gd` verifies those no-ops with missing,
null and malformed state, plus the original pre-access writes on eligible
emission/update failures. No production attestation or startup-seed behavior
was changed. The earlier note about eager convenience checks is superseded
by these source-proven direct-helper corrections.
