# Actual PID9348 paused particle-checkpoint regression

Input archiveSHA256:
`c870df7ea34d8e37f54768a0aebef1a54fc1ca4ccf1ccee94b6781ced07feb60`.
Exact raw captureSHA256:
`d290a1db6a5d2e268da8d9e688464649bae47c7c4fd82b5838448a033fa72995`.
ValidationSHA256:
`ac8ff5ccc81c81bb3489214fc143800eccc2314bef141b55e5ee5db41c316132`.
Material baselineSHA256:
`6b868d27c2e1ecf2af7d1d521823a97650b26457960f5db55edf29597fa1c0ea`.
Main DIB captureSHA256:
`13774e051e92a19010ff937a7abf5d20dfe360b20fbd74782aa81ea2ee1ac0c7`.

`tools/build_actual_particle_checkpoint_fixture.py` verifies those files and
builds the pinned Godot fixture. It decodes actual vessel fields and active
numeric cells from the full raw4348 blocks. Species/label text comes from the
same paused checkpoint's prior material reader; every current raw CString
pointer and count matches that earlier observation. Bitmap dimensions and
+FC pixels come from observed TBitmap metadata/pixels, not guessed apparatus
fields. Only native indices0 and3 have observed source-used particle pools.

Complete3468C/FC20 descriptors retain all raw object bytes. Original32-bit
primary/retained pixels and their source-derived visual row addresses are
supplied from validation, with populated cached rows checked against them.
No constructor creates missing pools; no region/palette defaults are filled.
TLS remains `{}` because the capture did not observe it. Run/pause remains
exactly`2/0`; it is not replaced with the previously tested`2/1` branch.
Native VCL verification remains false. No GDI callback or trig provider is
supplied to force completion.

## Observed source frontier

`test_actual_paused_particle_checkpoint.gd` imports and validates all those
objects, then executes the retained frame on the recorded control state.
The actual checkpoint reaches solid_color_setup49B698. It writes the already
observed color to32D50, obtains the known primary bitmap canvas through
4E9448, and calls4E3E50 at49B6CA. Execution stops at the unresolved helper
4E3E50, with return address49B6CF still on the original stack, with:

`Original VCL particle presentation boundary is unresolved at 0x4e3e50`.

TLS is still unobserved/untouched, and all four complete raw particle objects
remain byte-identical before that unresolved callback, after restoring only
the explicitly hosted bitmap pointer identities. This is a real required
VCL boundary, not a random-state failure or missing raw numeric bytes.

4E3E50 is TPen color-setting behavior. It copies the shared pen record via
4E3DE0, replaces its color and invokes4E3DF8/4E2F50 with global graphics
registry59A9E4. Source4E9448 reads existing TBitmap.Canvas at object+24 or
constructs it if absent. Actual TCanvas/TPen/shared-record/event/registry
state was not captured by the current reader. Pen color/handle state cannot
be inferred merely from uniform bitmap pixels or the solid background value.
The regression therefore supplies no stub-success setter and does not claim
that a complete paused frame rendered.

## Test meaning

The default test reports `VALIDATION`, with `completed_frame:false`, for the
pinned capture-bound source prefix and its exact unresolved frontier. It is
an input/prefix/boundary regression, not end-to-end presentation acceptance.
`--require-complete-frame` exits nonzero at that documented unresolved helper.
Production state/configuration and startup attestation are untouched. A future
exact VCL state/provider can move the frontier only with new source/runtime
evidence; the fixture expectation must then be deliberately revised.
