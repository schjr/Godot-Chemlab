# Native vessel factory and cold-load construction

This is a read-only static trace of the actual `_main.exe` bytes. `constructor_evidence.json` retains the executable SHA-256, exact instruction bytes and focused disassembly; `tools/trace_original_constructor.py` reproduces it. No engine initialization has been changed in this investigation.

## Proven: cold reaction strings are explicitly empty

The original `.cem` factory inside `FUN_0043240c` allocates exactly `0x4348` bytes through `FUN_00533ad8`, with the requested size pushed at `0x0043281b` and allocator call at `0x00432820`.

At `0x0043294e–0x00432972`, it calls vector constructor `FUN_00533f34` with these stack arguments, in call order:

```
buffer = vessel + 0xf20
stride = 0xe8
count = 0x32 (50)
constructor_call_flags = 1
constructor = 0x00416b30
destructor_call_flags = 1
destructor = 0x00416c0c
```

The vector helper's selected flag-1 branch at `0x00533ff8` pushes the current record pointer, calls the constructor, then cleans that argument. At `0x00534019` it advances the pointer by the provided stride, and at `0x0053401c–0x00534025` it decrements/tests the count and repeats. Thus this is not an inference from an apparently zeroed allocation: the constructor runs on all fifty records.

`FUN_00416b30` explicitly constructs managed strings at relative offsets:

- `+0x04`: name;
- `+0x10`: 10 reactant string pointers, stride 4;
- `+0x38`: 10 product string pointers, stride 4;
- `+0xb8`: condition;
- `+0xd0`: mode;
- `+0xd4`: equation type;
- `+0xd8`, `+0xdc`, `+0xe0`: optional notes 1–3.

For each managed-string slot, `FUN_004016e8` executes:

```
00401701 mov edx, dword ptr [ebp - 4]
00401704 xor ecx, ecx
00401706 mov dword ptr [edx], ecx
```

Consequently the per-vessel equation type and three note pointers at `0xff4`, `0xff8`, `0xffc`, and `0x1000` are guaranteed null/empty after construction, even if the allocated memory previously contained nonzero bytes. The V3 `.cem` reader overwrites the serialized fields only through mode at `0xff0`. It never populates the four later strings. A cold `.cem` load therefore has empty note 3 at `0x1000`; it does **not** acquire the library's `水的电离` annotation simply by sharing the equation name.

The corresponding `Image1MouseDown` apparatus creation branch at `0x0041bcd6–0x0041be55` uses the same allocation size, three 100-element managed-string arrays, and fifty-record constructor call. It explicitly pushes reaction constructor `0x00416b30` at `0x0041be10`, and calls the vector constructor at `0x0041be28`. This confirms the palette factory and file loader share the record construction scheme.

## Other explicit factory writes

The `.cem` factory also constructs standalone strings at `vessel+4`, `+0x80`, `+0x90`, `+0x94`, `+0x98`, and `+0xec`. Its `FUN_00416d28(vessel+0xe8)` call constructs the font-style helper at that subfield; it is unrelated to the reaction array despite the coincidental offset/stride value `0xe8`.

Three separate string arrays are constructed with count 100, stride 4, constructor `0x004016e8` and destructor `0x00540fe8`:

| Buffer | Role |
|---|---|
| vessel+0x108 | Reagent names |
| vessel+0xbf8 | Per-reagent variable-label strings |
| vessel+0xd88 | Per-reagent variable-label strings |

The vector helper does not zero the whole vessel or entire reaction record; it initializes only those constructed members. Reaction coefficient arrays and numeric doubles are not managed-string members.

`FUN_00453a28` then explicitly initializes the vessel scalar/control values, count fields and selected aggregate doubles. Temperature is set to 20 at `0x88`; smart selection is set to 1 at `0xa4`; dissolution is set to 1 at `0x3c74`; speed setting is set to 10 at `0x3c78`. The file reader overwrites the persisted values afterward.

## Not proven: all numeric volume slots start at zero

The factory's member construction does **not** write the 100-double reagent-volume array at `vessel+0x5b8`, or blanket-zero the numeric mass/amount arrays at `0x298`/`0x8d8`. The `.cem` reader writes mass and amount for the file's active reagent entries; it does not read/write their volume fields.

`FUN_00461e54` recomputes volumes for active slots whose phase matches liquid, gas or solid. It does not assign a volume in its dissolved/ionic branches. The supplied heap contents therefore cannot be replaced with a made-up calloc guarantee when reproducing the original memory layout. A fresh operating-system page or one observed allocator result containing zeros is not a constructor contract.

Explicit zero-volume writes occur when native helpers add a missing species slot (`FUN_00462660`, `FUN_0046c894`, and related dissolution insertion code), and when `FUN_0048e9b4` adds/resets the air species. They initialize the newly inserted slot, not every preexisting or unused slot. The run-start callback calls `FUN_0046c894` and `FUN_0048e9b4`; quantity recomputation is also invoked through `FUN_0043f7bc` and the normal update sequence. This still does not establish a universal all-slots-zero invariant.

For a strict factory oracle, prefill the allocation with a nonzero sentinel before running these original constructors. The note pointer slots must become zero. Untouched numeric volume slots should remain the sentinel until an explicitly identified writer handles them. Any original-mode calculation that reads such an untouched numeric value has an allocator-dependent or undefined initial state; it must be recorded as such rather than silently repaired.

## Coverage limits

The allocator call dispatches through a runtime memory-manager function pointer (`FUN_00534330`, call through `0x0057598c`); it can be selected dynamically. This investigation does not claim its fresh/reused blocks are zeroed. The retained vector-helper linear disassembly includes inline jump-table bytes; only the explicitly traced flag-1 and flag-3 branches above are treated as executed instructions. No original runtime execution was performed in this trace.
