# Read-only allocator, startup cache, and particle-render audit

This audit changes no production model, UI, or VM state. `tools/trace_original_allocator_controlword.py` retains exact original bytes and disassembly in `allocator_controlword_evidence.json`, from the original SHA-256 `7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c`.

## Apparatus allocation is not a whole-block zero constructor

The `.cem` and palette factories request `0x4348` bytes through `533AD8` as recorded in `constructor_trace.md`. The allocator chain is:

1. `533AD8` retries `534330` until successful (allocation failure handler only).
2. `534330` calls the function pointer at `57598C`.
3. The image initially contains pointer `5343C8` there. Its first-call bridge invokes manager selection `534368`, then calls the newly selected pointer with the original requested size.
4. `53418C` can choose Borland shared memory-manager exports when `borlndmm` is already loaded. These external exports are not proven by the current static binary evidence.
5. The fallback at `534368` selects `534428`. That routine gets the System memory manager through `530CF0` and calls its allocation member.
6. The System allocation pointer at `575604` initially targets `5306B0`. It is mutable through `530D0C`; the original runtime pointer must be recorded to identify the manager actually used.

`5306B0` rounds the requested block size and returns an arena/free-list allocation. A `0x4348` request becomes `0x434C` including its header. The arena-return path subtracts the size from free space, moves the arena pointer, writes the block-size header and returns the address immediately after that header. It does not zero the payload. The large free-list path through `5305BC` unlinks or splits a free block, writes the size/header, and returns its payload; again it does not zero its old contents. Small free-list paths do not apply to this apparatus size, and likewise do not establish a whole-block zero guarantee.

Fresh committed Windows pages may contain zeros, but recycled blocks are not thereby zeroed. The original member constructors zero specific managed-string members and `453A28` writes specified scalar fields; neither initializes the whole `0x4348` apparatus block. The numeric unused slots remain allocator-dependent unless another explicitly identified writer touches them. A live profile records an allocation's actual bytes, not a universal constructor default.

## Source-defined stored x87 policy globals

Two exact stored words are established, suitable for **read-only memory observation**:

- `5755E8`: initial image bytes `3213` (`0x1332`). `531344` executes `FNINIT`; `531347` executes `FLDCW word [5755E8]`. The System initialization path calls this reset at `533A19`. `531280` can read the `FPUMaskValue` registry value under `SOFTWARE\\Borland\\Delphi\\RTL` and updates the low six mask bits of this global; it is not an immutable constant.
- `5772E0`: initial DWORD bytes `32130000` (`0x1332`). The C++ startup reset `5394E4` executes `FNINIT`, then `5394EB` passes this value with mask `0x1FFF` to `539278`. That routine reads the current control word into a stack slot, merges the requested masked bits, updates the policy global when a nonzero mask is passed, and executes `FLDCW` at `5392A0`. Startup calls the reset at `53C7E3`.

The PC bits in initial `0x1332` select 64-bit significand precision and the RC bits select nearest-even. `575610`, initial bytes `321f`, is a separate conversion word read by `530F30` during truncating integer conversion, followed by restoring the saved stack word. It is not the startup policy.

The process probe can read `5755E8` or `5772E0` using its caller-specified global parameter. Neither stored value proves a thread's **current hardware register**. Other routines temporarily save/modify/restore the word on the stack. This audit does not use thread context APIs, debugging, or VM inputs.

## Production host cache/start review

`original_model_host.gd:start()` explicitly resets `native_particle_3cc8`, `solid_4318`, and the active species' `solid_3cd8`/`solid_3ff8` entries. These are justified by the actual original Run callback (`decompiled.cpp:15945` onward), which clears both 32-bit halves of `+3CC8` and `+4318`, then both halves of each **active** `+3CD8/+3FF8` double. It does not clear every inactive slot.

`from_state()` retains unknown dissolved/ion volume-cache entries as absent; physical quantities recalculate through `461E54`. The three initial aggregate zeros `4320/4328/4330` are explicit `453A28` writes. There is no corresponding proved constructor zero at `4338`; its physical recalculation is a separate operation.

A startup discrepancy was reported to the parent: the native Run callback explicitly clears elapsed time at `5636CC/5636D0` (`decompiled.cpp:15973` onward), while the reviewed host `start()` did not reset `elapsed`. No host change was made by this read-only audit.

## Live suspended-particle rendering remains a separate stateful stage

The existing settled-solid and gas-color modules transcribe `4744DC` and `47692C`. The live particle stage inside renderer `40A4B8` is separate. It changes native caches during rendering, so the pure-physics frame corpus does not certify its behavior.

At `decompiled.cpp:6225` onward, positive solid `3FF8` deltas scaled by 20000 trigger emission into the vessel's particle-system object (`595214` pointer array) through `49BF44`; that delta is then cleared. Negative deltas lead to particle-layer removal/recolor operations through `49CDD8` and other helpers. The layer uses the separate `3CD8` reserved-solid cells and `4318` total. At lines6417–6444, gas `3CC0 * 200000` is added into `3CC8`, capped at ten, converted into bubble emission through `49A61C`, then the accumulator is reset when emission occurs. These updates obey the original run/pause/liquid-height/type gates; they are not equivalent to drawing decorative particles from current total moles.

`49BF44` manages a persistent particle array with stride `0x34` and count at object `+34684`, capped by its entry condition at 2000. It uses float32 stores for particle coordinates, angle, speed, lifespan and related values, plus original random calls through `4028EC` -> CRT `539C60` modulo the requested bound. `49C298` updates/deletes particles, applies native trigonometric helpers, consumes further RNG values, and maintains persistent pixel layers. `49CDD8` mutates retained pixel rows using native color arithmetic. The original vessel cache bytes alone do not capture these particle objects or their RNG state.

A source-faithful port is viable as an explicitly owned persistent particle subsystem, but needs the full `49BF44`/`49C298`/bubble helper argument contracts, original RNG state/order, float32 store boundaries and bitmap-layer calls. Those dependencies are not yet all verified here. This audit does not invent a particle implementation or claim that an isolated numeric particle snippet is the complete live renderer.
