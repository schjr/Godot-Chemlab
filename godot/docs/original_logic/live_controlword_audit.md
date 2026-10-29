# Live x87 precision-context audit

`tools/trace_original_live_controlword.py` reads the recovered original PE,
decodes instructions from retained function boundaries and records aligned
control-word instructions, callers, raw bytes and global references in
`live_controlword_evidence.json`. Source SHA remains the verified original.
A raw D9 opcode search produces numerous false positives in instruction
operands; those are not counted as executed control-word instructions.

The aligned main-image inventory has 21 control/environment instructions:
19 FNSTCW/FLDCW instructions and two FNINIT instructions. No aligned FLDENV,
FRSTOR, FXRSTOR, XRSTOR or LDMXCSR instruction was found in the retained
main-function inventory. This scope does not inspect external Windows DLL
implementation or observe the live hardware/emulated control register.

## Source effects

| Function / instruction | Proven effect |
| --- | --- |
| `531344`, FNINIT then FLDCW at `531347` | Resets and loads word5755E8, image value1332: PC bits11 (64-significand precision), nearest rounding. Startup caller533A19; exception reset callers531874/53199A. |
| `5394E4`, FNINIT then control87 caller5394F1 | Applies DWORD5772E0, image1332, mask1FFF. Startup53C7E3 and exception53E81D callers. |
| `539278`, FNSTCW53927F / FLDCW5392A0 | Generic masked setter. Every direct caller and its pushed operands is retained. No direct main-image caller sets PC bits to10 (53-bit precision). |
| `539664`, callers5396D2/5396E7/539713 | Reads current CW using mask0, temporarily changes rounding via maskC00, then restores those rounding bits. PC bits are outside this mask and remain unchanged. |
| `53C2D8`, caller53C489 | Exception handler applies stored5772E0 with mask1F3F; no literal PC53 setting. |
| `52AA40`, FNSTCW52AA50 / FLDCW52AA56 / restore52AAE0 | Numeric parser temporarily loads constant52A296=133F (PC64, nearest, masked exceptions) and restores entry CW on its normal success/failure exit. |
| `530F28`, save530F2C / load530F30 / restore530F3B | Integer conversion temporarily uses575610=1F32 (PC64, truncation rounding), then restores entry CW. |
| `5394FC`, save539503 / load53950E / restore539517 | FTOL ORs high-byte0C, changing rounding to truncation. It restores that byte afterwards; it does not select PC53. |
| `5393C9`, save539436 / loads539441/53944C | Large exp branch ORs high-byte0F for integer rounding, then ANDsF3. This sets PC64 and returns to nearest rounding; it does not select PC53. |
| `4FE494`, save4FE4D9 / restore4FE507 | VCL wrapper saves entry CW around an indirect callback and restores it, including exception cleanup. It does not impose a new precision. |
| `52E1CC`, save52E1EC / restore52E21C | LoadLibrary wrapper restores entry CW around external initialization, including cleanup. |

Delphi's registry `FPUMaskValue` path at531280 changes only the low six
exception-mask bits of5755E8; it does not change precision bits. Main-image
global references and writes to5755E8/5772E0 are retained in the JSON audit.

The original Run, transfer/action and quantity paths contain no direct
FLDCW instruction. Their FTOL/parser helper calls use the temporary and
restored modes above. The gas-volume sequence at46216E/462174 is consecutive
FMUL of binary64 22.4 and binary32 1000, then its later QWORD store. There is
no hidden intermediate QWORD store to add to the production port.

No source evidence here establishes an app-owned PC53 precision change
around Run or withdrawal. This is a negative finding within the retained
main-image scope, not proof that an external component never changes CW.
The read-only capture of5755E8=1332 is still a stored memory value, not the
live control register.

## Primary Windows on Arm documentation

Microsoft's [Adjust emulation settings on Arm](https://learn.microsoft.com/en-us/windows/arm/apps-on-arm-program-compat-troubleshooter)
documents that Prism normally approximates x87 using a 64-bit format, and
that the per-application **Disable floating point optimization** option
selects full 80-bit precision instead. This concerns the emulator's execution
semantics; the saved x87 control word can still contain PC64 bits.

That documented behavior is a plausible explanation for the two droppers'
captured mole/volume combination, which matches binary64 rounding between
multiplies while the PC64 original-source port does not. It is an inference,
not a verified setting on the captured guest process. No VM setting, source
store boundary, simulation operation or production arithmetic mode was
changed during this audit.

A controlled repeat under verified full-80-bit emulator settings, or an
original-process arithmetic/context observation, would distinguish the
emulator explanation from another live context change. The new successful
withdrawal capture must also be compared from its actual pre-action state,
without treating the earlier ineffective click as a completed action.
