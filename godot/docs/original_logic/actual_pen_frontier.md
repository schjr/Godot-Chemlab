# Actual paused pen graph: isolated first-setter comparison

The new `tools/build_actual_pen_frontier.py` consumes an extracted, validated
`isolated-pen-graph.json` and its original `CodexVclPenState.json`. The captured
JSON must hash to `55efb5a1c8cba1556689dee25ca6bcc984b3740e80e47866fd100e9ef5ce7787`;
the validated return archive is
`c74791baf575cb1880abf5d318525aad63c07e258c639d51921fb424f72ba24b`.
The complete graph is revalidated against the prior particle checkpoint, not
accepted solely because it carries those hash strings.

The builder reads the source-used solid-0 primary bitmap's existing Canvas and
Pen pointers from the actual graph, and requests the solid object's actual
background color at offset `0x32D50`. It preserves every supplied byte span at
its absolute observed address. Process-specific HDC/HPEN values remain foreign
identities; no operation is performed with them.

The reference executes original PE instructions beginning at `0x4E3E50`.
Every lock, allocation, release, system-color and graphics primitive is refused
at its first actual call. Explicit fresh isolated FS and stack pages are used
only to execute this diagnostic prefix. They are not observations of the live
Windows thread. No successful lock or graphics callback is fabricated.

Source `0x4E3DE0` copies the shared key, then `0x4E3DF8` enters the Pen's optional
critical section before reaching the registry lookup at `0x4E2F50`. The capture
analyzer establishes that each available Pen has that lock bound to
`Canvas + 0x38`. Consequently even an equal stored color cannot make this actual
setter a primitive-free operation. The generated fixture records the exact
color-equality result, first primitive arguments and all captured bytes after
the native prefix. Actual values are not asserted before the returned graph is
available and the builder runs.

Run the builder in the workspace uv environment and execute the diagnostic:

```
uv run python tools/build_actual_pen_frontier.py <validated-capture-directory>
Godot --headless --path godot --script res://tests/actual_pen_frontier_check.gd
```

The Godot check refuses the same primitive and compares the request and every
captured byte span with the original PE prefix. `VALIDATION` means that bounded
comparison passed; it does not mean the setter or frame completed. Adding
`-- --require-complete-setter` requires completion and fails while that boundary
remains unresolved. The script stays outside automatic `test_*` discovery until
the actual fixture has been produced. Production configuration, VCL attestation,
queue draining, live exception/stack state and TLS RNG remain unchanged.

## Returned capture: measured result

The returned directory is
`evidence/windows-runtime/vcl-pen-results-2026-10-14`. The builder has now run
against that validated graph. Generated fixture SHA256:
`a90c7f6013967d13e84f9188a9e36a3b62893989d6b672d71c61a4a7182cf334`.
Original PE prefix and Godot diagnostic agree on all **152 observed spans,
539624 bytes**, with no successful primitive callback and no captured graph
mutation before the frontier.

| Actual observed/verified value | Result |
| --- | --- |
| Solid-0 pool | `0x0D9911B4` |
| Primary bitmap / Canvas | `0x0D9C5844` / `0x0A71AFE4` |
| Pen | `0x0D91F2AC` |
| Requested and already stored color | `0x00FCADA1` |
| Original first primitive | `EnterCriticalSection` import `0x00554EC4` |
| Passed lock identity | `0x0A71B01C` (Canvas + `0x38`) |
| Captured registry / embedded lock | `0x0A63178C` / `0x0A631794` |
| Old shared record | `0x0A6EB93C`, reference count 2 |
| Requested 16-byte key | `00000000a1adfc000100000000000000` |
| Key checksum | 53795 (`0xD223`) |
| First matching ordered registry node | The same old shared record |

The last four facts are direct inspection plus source-algorithm projection over
the complete captured registry list. They are **not execution beyond the refused
lock**. If an appropriately reconstructed fresh lock world completes its actual
Enter/Leave operations and this record graph remains unchanged by other actors,
the source lookup selects the same node, increments then releases its reference,
and skips change notification. That path would need no allocation or GDI call
for this setter. The required nested lock sequence still consists of Canvas
Enter, registry Enter, nested registry Enter/Leave for lookup, nested registry
Enter/Leave for release, outer registry Leave, and Canvas Leave.

This makes the new owned-lock backend a concrete next diagnostic candidate,
subject to its Windows verifier and an explicit fresh-object/lifetime/thread
scope. It does **not** authorize replacing the captured process's current locks
with fresh unlocked ones or attesting the original live graph's ownership state.
The captured Pen Canvas has HDC zero and flags zero; those observations do not
supply a future lazy-HDC creation provider. Completion of the paused frame, its
other VCL boundaries and production integration remain unclaimed.

The first Godot run exposed two diagnostic-harness issues, corrected in the new
check only: JSON numeric fields needed integer normalization for dictionary
comparison, and the intentionally refused VM error had to be preserved then
cleared solely for post-stop byte inspection. No instructions resume afterward.
The rerun reports `VALIDATION` with zero failures and `completed_setter:false`.
