# Read-only gas operand capture

`tools/windows/read_original_gas_operands.ps1` uses unchanged reviewed C#
readerSHA256 f366f56e3a842384cb26395e14ce14361aab0bfb70f34121d3ae80331e263839.
Run it in a fresh PowerShell process with that C# file beside it. Output is
`%TEMP%/CodexGasOperands.json` and Desktop `gas-operand-results.zip`, containing
JSON and exact executed PS/CS sources. Existing outputs are refused.

It pins original image/PID9348/base400000, six vessel addresses, count6,
run2/pause0 and elapsed6cbc749318445240. Full vessel bytes and every captured
operand are read in two complete graph traversals; exact equality is required.
The lookup implementation452D9C's live code span is checked against original
PE SHA25679ecf0a1d428ae541775b3923f0e731fd33e72afe1efb22e947be94f2e2e7c59.

The ten constant spans come directly from the existing gas operand audit:
4624B0/8,4624B8/4,48EC70/8,48EC78/4,46F6D0/8,46F6D8/4,
48EC7C/10,46F6EC/10,48EC88/10,46F6F8/10. Both observed and original-image bytes
are recorded. A stable changed constant is **reported**, not rejected merely
because it differs, replaced with original bytes or numerically reinterpreted.

Reagent count580A28 and ordered pointer table57BC08 are captured in full. Each
record's first18 hex bytes preserve AnsiString pointer+8 and mass QWORD+10.
Non-null strings preserve their preceding8-byte headers, declared-length raw
name bytes and terminator, including embedded NULs; no CString truncation or
locale decoder is used. Null strings remain exact empty names. INERT selection
uses recovered byte name b6e8d0d4c6f8cce528c6f8cce529 and the ascending first
exact match, as452D9C does. All matching indices are recorded; no fixed reagent
index is guessed. Observed molar mass and its comparison with original29.0
bytes are separate fields. Changed operands remain observed evidence.

Probe safety bounds are1024 reagents,1024 declared name bytes and8192 raw
blobs; exceeding them fails without a truncated output. Bounds are not claimed
native catalog limits. PowerShell5-specific guards use positive decimal
4294967295 and unary-comma nested constant rows. Five local static tests verify
all ten literal spans and lookup code against the pinned PE, exact byte-name
selection, numeric/array guards, read-only C# imports/access and output scope.
Actual Windows execution remains pending.

No target calls/writes/suspension, privilege or policy changes, GDI operations,
GetThreadContext or precision inference occur. Equal raw reads do not establish
an atomic snapshot or drained GDI queue. Output explicitly retains full VCL,
TLS and floating execution context as unverified/unobserved. This probe can
clarify changed live operands; it does not itself explain the remaining4/2mL
arithmetic discrepancy or authorize a changed arithmetic rule.


## Returned archive importer

Use `tools/analyze_original_gas_operands.py returned.zip --sha256 ACTUAL_SHA
--output-directory NEW_DIRECTORY`. It pins the exact reviewed PS/CS source
hashes, original image/PID/base/checkpoint, all10 constant projections and lookup
code452D9C hash. It validates complete raw spans and digest lengths, overlapping
observations, table/record/string/header/terminator crosslinks, source-ordered
first exact name selection and all matching indices. Existing six full vessel
blocks must still match the pinned actual particle checkpoint byte-for-byte.
Every supplied raw span must participate in the reviewed graph. Unexpected
archive members, duplication, traversal names, encryption, symlinks, excessive
sizes and existing output directories are rejected.

Stable live constants and molar mass that differ from original image literals
are retained and reported separately; the importer does not reject or replace
these findings. It preserves null names, zero-length names and embedded NUL
bytes. Output `validation.json` retains the full graph and marks floating
execution context/TLS as unobserved, precision inference/arithmetic-rule changes
false and native VCL/queue drain unverified. Original JSON/PS/CS are preserved
alongside it. Eight synthetic transport/graph tests plus five source tests pass;
actual returned Windows evidence is still pending.
