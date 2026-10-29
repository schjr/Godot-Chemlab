# Combined original physics verification

`tools/original_frame_oracle.py` executes original PE code in the same physics order as the running branch of4018B0 (main/decompiled.cpp:450 onward):470060 heater geometry,48E418 thermal,4849FC continuous apparatus flow,46C84C for every upright object,624D8 quantities,46EC50 open gas,46D414 connector graph,46F704 remaining transport, then624D8 quantities. It executes471650 scalar liquid/color refresh between ticks. It does not replace chemistry/transfer formulas, and does not apply a100–300 type filter to46C84C.

All28 original examples have five captured20ms physics ticks:140 native outputs. Tests load original raw CEM fixture bytes through the project importer, configure the strict host, run original startup preparation, and compare ordered chemical names, selected reaction names, amounts/masses/volumes, temperature, pressure, gas and solid counters, heating and liquid color. IEEE754 input/output carriers avoid JSON numeric conversion loss.

This is an explicitly declared fixture memory profile, not an allocator claim: all100 numeric slot buffers start at zero before loading/RUN, and absent arrays remain mapped as latent zero fixture slots. Native constructors only guarantee the states separately established in `constructor_trace.md`. Native RUN explicitly clears active particle buffers and connector bubble caches. The tests supply unknown appended INERT particle slots and unwritten dissolved/ion volume slots from that fixture profile; the production importer does not adopt those values.

Original46F704 can read uninitialized stack bytes. The oracle captures each tick's actual reads at46FB18 and passes only the observed value through an optional verification context. Original stack reuse can yield subnormal operands, so these values are not a safe production default. All140 captured original physics frames now match every tested stored numeric byte and ordered species/reaction list after extending `OriginalX87` scaled subnormal arithmetic. The port also preserves the observed nonzero stack input in the hydrogen/iron case; it is never silently changed to zero. Production without an externally established stack input still refuses the original read-before-write.

The native reaction instruction limit is10million per46C84C invocation for combined-frame capture; the older2million bound rejected the cold strong/weak acid case despite eventual native completion. Bitmap dimensions come from original resource pixels or proven dynamic factory/stored fields. In particular type316 wood is35×30 from factory424513 and the original CEM0x3c/0x40 fields. A1×1 placeholder is never accepted when its geometry is queried.

Bindings48C428, program group callbacks, user pointer timing and Win32 presentation are outside this physics fixture's scope. Their independent original tests must not be represented as whole application execution. The strict host callback is left unset in this corpus, so it matches that scope.

`tools/original_workflow_oracle.py` adds the opening original experiment protocol using actual477708 callbacks, original two-mL aspiration and0.2mL drops, original reaction rates, and full20ms physics ticks. VCLCopyRectRET4, EllipseRET8, canvas lookup and repaint are declared presentation boundaries. Positions are explicit user drag inputs; no new target-selection rule is inserted. The saved protocol applies NaOH to CuSO4 and FeCl3, then original HCl to each precipitate, with15 original ticks after each drop, followed by the original4433B4 orientation callback and three pouring ticks from the HCl bottle before restoring upright orientation. Seven native actions and63 physics ticks execute. Its original `original_workflow.json` outputs are retained as historical evidence with the earlier FrameOracle startup scope. The active workflow tests now use the fresh source-ordered reference described below.

The seven-action workflow now passes with zero stored-double mismatches across all species, mass/volume, temperature, pressure and particle caches. Sequential dosing exposed an omitted original transfer QWORD quotient store; its source owner corrected that boundary. It also exposed reaction comparisons that read only the mantissa of the newly scaled x87 representation; those comparisons now include the exponent through the x87 comparison API. Both changes preserve original arithmetic/control flow rather than adding clamps or chemistry rules.

The pouring oracle initially aliased bitmap fieldsF4/F8/FC. That invalid fixture pointer ownership meant the native reset ofFC also clearedF4 and suppressed pouring. The corrected fixture creates separate objects as the original factory/asset initialization does (main/decompiled.cpp:9158–9174 and13897–13902). The original4433B4 callback now loads and swaps actual resource dimensions, and all three pouring ticks match the Godot host. Production Flow needed no change for that discrepancy.

## Source-ordered Run workflow reference

`tools/original_workflow_run_order_oracle.py` constructs the same explicit input
allocation and recovered bitmap objects, suppresses the old harness startup,
and executes actual first-Run `43DE5C`. Its stopped-refresh boundary executes
real `4624D8` and `471650` before `46C894`/`48E9B4`; there is no extra
after-air recalculation. UI enabled/repaint, stopped chart/association/raster,
and `42DC3C` saving are explicitly hosted boundaries. Actual Run numeric
instructions, manual `477708`, orientation `4433B4`, and subsequent original
physics are executed, rather than deriving expected outputs from the port.

The fresh `tests/fixtures/original_workflow_run_order.json` preserves the same
seven source-defined actions and 63 physics ticks. Both `test_original_workflow.gd`
and `test_native_action_workflow.gd` compare Run return, every one of the 63
frames, and each action's final state against that fresh reference. The latter
also preserves the paused helper no-op and resumed live helper dispatch test.
The previous workflow fixture is not overwritten. All allocation inputs remain
explicit test observations; none are production defaults. This reference does
not prove complete VCL/raster execution or resolve the separately recorded
Windows inert-gas execution-context discrepancy.

Fresh source-ordered validation passes in both focused tests: seven action
endpoints, all 63 individual physics frames, and immediate Run return have zero
bit mismatches in the tested fields and species/reaction order. The GUI-path
regression also passes the original paused helper no-op, resume, withdrawals,
drops and context-menu pouring. This replaces the earlier startup reference in
active tests without changing runtime logic or weakening any comparison.
