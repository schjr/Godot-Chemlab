# Optional owned process stack for particle frames

`OriginalParticleFrame.step` and `step_vessel` accept optional
`context.owned_stack_bytes`: exactly65536 bytes in a `PackedByteArray`, bound at
the fixed source VM stack address `09000000..0900FFFF`. Other types and lengths
are rejected before VM setup. The caller supplies a complete known byte span;
the frame does not infer values from missing locals or import a test profile.

The intended production caller reads this span from its own source heap's
explicit fresh/reused stack pages. Source instructions then read and write these
prior bytes normally, including emission locals that the old program sometimes
reads before writing. The result contains `owned_stack_bytes` with the complete
post-execution span. It is returned on successful execution and after a source
or presentation failure once the stack was mapped, so completed source stores
can be preserved instead of resurrecting the input bytes. The caller owns its
process lifecycle and writes the result back into the same owned stack domain.

When the context field is omitted, the existing sparse unknown-stack contract
is unchanged; no stack buffer or zero fallback is manufactured. Supplying a
stack also does not initialize unrelated apparatus or bitmap state. The owned
addresses are reconstructed process storage, not native host pointers or a
claim about a historical Windows GUI thread's bytes.

`test_original_particle_owned_stack.gd` covers strict transport, unchanged input
buffers, retained untouched bytes, source local writes, reuse of returned stack,
exact address bounds, omitted unknown state and preservation across a source
failure. The retained particle IR is now parsed and helper instructions flattened
once per process; each frame treats these shared structures as immutable.
