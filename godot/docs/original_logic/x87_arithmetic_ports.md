# x87 arithmetic compatibility and subnormal values

`original_x87.gd` keeps a binary64 high/low expansion rounded to the original x87 PC64 significand after each arithmetic operation. Ordinary results retain the existing two-element representation. When a binary64 expansion would lose significand bits in the subnormal range, an internal third element records an exact power-of-two scale: `[high, low, exponent]` means `(high + low) * 2^exponent`. Arithmetic normalizes these operands before multiplying/dividing. QWORD stores round the scaled value once to binary64, including nearest-even subnormal rounding. This avoids prematurely rounding intermediate x87 values to zero.

Callers must use `stored_double()` at actual native QWORD stores and public arithmetic operations for scaled values. They must not discard an expansion's third element. Existing geometry helpers which directly negate two components operate on ordinary coordinate values; these are not a generalized scaled-value API.

The combined original-frame fixture included explicitly observed uninitialized stack bytes `0000000001000000` in `46F704`. Supporting their finite numerical value does **not** establish that these bytes are an original default. Production still requires an explicit runtime memory profile where this native local is unresolved.

`tools/original_x87_arithmetic_oracle.py` executes 209 bounded x87 instruction microkernels under Unicorn CW `0x037f`. They cover finite subnormal operands, intermediate values below the binary64 range that later divide back into it, positive/negative QWORD stores, and division/product cancellation. They are arithmetic references, not observations of a Windows thread's hardware control word. `test_original_x87_arithmetic.gd` compares exact IEEE bytes and exits unsuccessfully for missing/unsupported results or mismatches.

Validation after this change: all 209 arithmetic microfixtures, 357 existing original CRT math cases, 140 combined native physics frames, quantities/thermal native fixtures, 69 solubility cases, and 445 heat geometry cases passed. Full opening workflow equivalence remains a separate test and had further source-order mismatches at the time of this document; these arithmetic checks do not claim that workflow complete.

## Transfer ratio store found by arithmetic audit

The sequential second drop of NaOH initially appeared to be a division-rounding error. Exact rational PC64 comparison showed the existing extended quotient and product were correct. Raw original disassembly instead establishes an omitted QWORD boundary:

- `00476F0F`: `FLD qword [ebp-64]` (requested liquid amount);
- `00476F12`: `FDIV qword [ebp-5c]` (liquid volume);
- `00476F15`: `FSTP qword [ebp-6c]` (ratio becomes binary64);
- `00477138`: `FLD qword [ecx+eax*8+8d8]` (source moles);
- `0047713F`: `FMUL qword [ebp-6c]` (stored ratio);
- `00477142`: `FSTP qword [ebp-74]` (moved moles);
- `00477145` / `00477155`: reload moved moles and reverse-subtract from source.

The solid helper has the equivalent ratio store at `00477466` after its division at `00477463`, then reads the stored ratio at `00477522`. The transfer module's owner corrected these boundaries. Altering PC64 division itself to force a particular dosing output would have violated the native instruction sequence.
# Signed-zero addition regression

Direct stores preserve a source negative zero. Under the traced nearest-even
mode, FADD of opposite signed zeros yields positive zero, while two negative
zeros yield negative zero. The previous zero-operand shortcut returned the
other operand without implementing the both-zero rule; preserving direct
negative-zero stores exposed 55 negative-zero/positive-zero mismatches in
the 140-frame source corpus. `test_original_x87_signed_zero.gd` verifies all
four zero addition sign combinations and the direct-store rule. Correcting
this arithmetic rule restores all 140 frame comparisons without altering
species names, slot bytes, fixture values or simulation branches.

