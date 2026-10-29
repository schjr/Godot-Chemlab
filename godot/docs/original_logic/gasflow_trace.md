# Original gas initialization and transport

`OriginalGasflow` ports original entries48E9B4,46EC50,46D414 and46F704. Source evidence is `recovered/native/main/decompiled.cpp`; raw PE is `artifacts/ChemLab/_main.exe`, whose SHA256 is retained in `tests/fixtures/original_gasflow.json`. No time-scaled transport rate or inferred density rule is added.

| Entry | Decompiled source lines | Port |
|---|---:|---|
|48E9B4|44123–44204|`initialize_air`|
|46EC50|34542–34810|`advance_open`|
|46EABC|34469–34541|first original submerged receiver lookup|
|46CEE0|33733–33862|ordered connector-chain resolver|
|46D414|33863–34468|`advance_conduits`|
|46F704|34811–35145|`advance_remaining`|

The source species is `惰性气体(气体)`. Air initialization resets/appends that species and fills the original headspace remainder. Native qword stores and the two original80bit conversion constants are preserved. Open-vessel behavior uses the original mass mean and orientation comparisons, inverted gas-jar bounding-box lookup, original liquid displacement fractions, and original quantity recalculation order.

Connector graph traversal consumes the original25-field records. It preserves stored order, native chain types1001/1002, visited markers, empty/closed sentinels, direct connection duplicate rows, name swaps, and pressure-sharing counts. The source endpoint2 branch reads endpoint1 Y at record+0x0c; this original behavior is retained. Graph output is returned as `native_network`, and the same ordered rows drive remaining transport. Shared static graph state matches the original single active experiment; callers must rebuild it for the active document before transport.

Remaining transport divides each route amount by the source cached gas total. That cached total stays unchanged for the entire phase even as species amounts change. Transfer is bounded by the current source amount. Destination append writes species name and amount only; mass/volume/particle arrays are not silently initialized. The original outer quantity phase subsequently updates physical gas caches. Submerged outlet bubble state uses connector+0x70 and direction+0x78, with original endpoint geometry and factor200000. No delta or acceleration multiplier applies to46F704.

The empty-outlet source path has an original read-before-write: `fstp [ebp-0x7c]` at46FADA executes only when current gas volume exceeds free volume; `fmul [ebp-0x7c]` at46FB18 can execute without that store. The decompiler names this local `local_80`. An excess from an earlier species/route remains live. `advance_remaining` accepts optional `native_context.observed_stack_excess` only for an explicit diagnostic original memory input; without that observation or an owned physical stack boundary, it refuses a read-before-write. The captured cold states for `一氧化碳还原氧化铁` and `一氧化碳还原氧化铜` exercise this input; machine fixtures retain the observed stack bytes separately.

`OriginalRuntimeGasFrame` provides the production physical boundary. Source
4018B0 establishes EBP and reservesF4 bytes; CALL46F704 at4019E5 pushes
return4019EA, and the callee pushes EBP before using its7C local. Thus the
physical QWORD is at idle-frame EBP-178. `gas_stack_abi.asm` retains these
original instruction fragments. The runtime binds that address inside the
existing owned source-allocator thread stack. The active model connects this
boundary in `step()` with its declared idle-frame EBP900F000, giving cell
900EE88; particle execution preserves its writes in the same owned64KiB stack
area between UI callbacks. Run and document loading do not fabricate an
excess value or clear that cell. Fresh committed pages establish
known initial bytes, and subsequently connected native VM/host stores remain
in the same byte world. Each source46FADA assignment writes its QWORD there;
each reached46FB18 reads it lazily. There is no fixed excess scalar, capture
input or per-call zeroing. Missing/nonfinite actually accessed bytes fail
explicitly; unused branches do not inspect them.

This is the reconstructed process's declared ABI frame and byte history.
It does not establish the historical Windows address or all prior Windows
stack writes: only routines connected to this owned byte world contribute
their retained stack effects. In particular, the high-level physics ports do
not replay every native temporary store of their original functions. The
scope distinction remains explicit rather than treating a captured stack
QWORD as a universal startup value. Diagnostic `observed_stack_excess` still
overrides the owned boundary for native-reference comparisons.

`tools/original_gas_stack_oracle.py` executes retained46F704 with explicit
physical initial QWORD12.5 and-4.25 in the two CO examples and the closed-excess
outlet case. `test_original_runtime_gas_frame.gd` compares every remaining
species amount, ten reached source read/store operands and the final physical
cell across six native cases, plus frame bounds, stale-value retention,
nonfinite refusal and lazy access. These diagnostic nonzero operands belong
only to the regression and are never used to initialize production.

RUN43DE5C (source lines15962–15967) explicitly resets all connector+0x70/+0x74 double bubble caches and+0x78 direction to zero before species initialization and air filling. Thus a faithful RUN caller supplies established zeros here; later ticks preserve them. CEM serialization itself does not contain these fields. Unsupported bitmap dimensions likewise remain unresolved when actually queried.

`tools/original_gasflow_oracle.py` executes actual original instructions and hosts only verified string/selector/VCL bitmap boundaries. All28 stored experiments and12 explicit native operand/geometry variations are captured,40 cases total. `tests/test_original_gasflow.gd` verifies air/open amounts, masses and volumes, graph order/types/pressure-share bytes, final transported amounts and connector bubble bytes/direction. All40 cases match stored doubles exactly under Godot4.7.1. Explicit fixture volume/bubble zeros and observed stack bytes are verification inputs, not production defaults or application-wide allocator guarantees.
