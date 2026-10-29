# Read-only original Windows cache probe

`tools/windows_read_original.ps1` reads the running original x86 application. It uses only standard Windows/.NET facilities and needs no installed package. It does not launch, change, pause, suspend, inject into, attach a debugger to, or send inputs to the application.

The target file SHA-256 must be `7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c`. The probe verifies the executable path, loaded module base, remote PE32/x86 header and preferred image base. Native global addresses are adjusted by the actual loaded module base. Process access is limited to `PROCESS_VM_READ | PROCESS_QUERY_LIMITED_INFORMATION`; no administration or elevation is requested. If access fails, the probe reports failure rather than changing privileges.

## Guest workflow

Transfer the script into the Windows guest using the parent's existing shared-folder or temporary-file-transfer workflow. The script itself makes no network requests and does not control the VM. Open the desired original experiment manually or through the parent-controlled original UI.

In an ordinary Windows PowerShell terminal, identify the actual original process:

```powershell
Get-Process -Name _main,main -ErrorAction SilentlyContinue | Select-Object Id,ProcessName
```

Use its ID, replacing `1234` below. Capture a cold or manually paused state:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\windows_read_original.ps1 -ProcessId 1234 -Label cold-opening -RequireNotAdvancing -OutputPath .\cold-opening.json
```

`-ExecutionPolicy Bypass` applies only to this script process; it does not persistently change execution policy. The probe can also discover `_main`, `main`, or the Chinese launcher-name candidate when exactly one candidate's executable hash matches the original. Explicit `-ProcessId` avoids ambiguity.

The parent can later run the original app, manually pause it, and capture its state again:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\windows_read_original.ps1 -ProcessId 1234 -Label after-run-paused -RequireNotAdvancing -IncludeAmounts -OutputPath .\after-run-paused.json
```

For read-only observations while it is running, omit `-RequireNotAdvancing` and optionally request a bounded series:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\windows_read_original.ps1 -ProcessId 1234 -Label running -RepeatCount 3 -IntervalMilliseconds 100 -OutputPath .\running.json
```

Running observations are not stable snapshots. The probe never stops the app to make them stable. `-RequireNotAdvancing` checks the original tick gate before and after each capture and refuses output if either check is advancing or unknown; it cannot rule out a start/stop between those checks.

## Captured data

The original apparatus count comes from **0x0058779C**, and the pointer array from **0x00585850**. Each record includes its native index/address, label/type, active species count at `+0x104`, and the corresponding ordered names from `+0x108`.

For every vessel, all **100 double slots** are captured at:

- `+0x5b8`: species volume cache;
- `+0x3cd8`: first particle/solid counter array;
- `+0x3ff8`: second particle/solid counter array.

Scalar doubles at `+0x4318`, `+0x3cc8`, and `+0x4338` are also captured. `-IncludeAmounts` additionally captures all 100 mole (`+0x8d8`) and mass (`+0x298`) slots, so the parent can correlate observed caches with current runtime chemistry.

Each value retains its exact little-endian IEEE-754 hex. This is authoritative for the Godot host: decode those eight bytes rather than roundtripping decimal JSON. `value_text` is only an invariant-culture human-readable representation; NaNs and infinities are explicitly classified. Original GBK-compatible names retain raw bytes and GB18030 decoded text.

The snapshot records the original run global **0x0057A6F8**, main-form pointer at **0x005799C4**, pause field `+0x5bc`, and elapsed-time global **0x005636CC** before/after reading. It checks vessel pointer/count identity and per-vessel species identity across the read. These checks detect some changes, but do not make sequential reads atomic or rule out every race.

Unused slot bytes are observations of the particular live allocation. They are not generalized to zero or claimed to be constructor defaults. Compare cold and paused-after-run profiles independently and retain the process/module identity with each profile.

## x87 control-word boundary

The live hardware x87 control word cannot be obtained through `ReadProcessMemory` alone. The script explicitly reports it as not captured. It contains no thread-context or suspension API and does not assume `0x037f` because that was an emulator setting.

If original-code tracing establishes a stored startup/control-word global, the parent can supply `-KnownControlWordGlobalVa 0x...`. The probe will read that exact two-byte memory location after image-base adjustment and label it as a caller-specified stored global, **not** an observed hardware register. No speculative memory scan is performed.

## Validation status

The script was written on the macOS workspace and encoded as UTF-8 with a BOM for Windows PowerShell 5.1 string compatibility. Windows guest reads succeeded on 2026-10-14 for three stable stopped/paused snapshots of the verified original process. The exported archive hash and all 3,000 QWORD cells per snapshot were checked on macOS. See [capture validation](windows_capture_validation_2026_10_14.md) for observations and remaining live arithmetic differences. The Windows ARM module enumeration returned duplicate identical mappings; exact base/size/path duplicates are deduplicated before enforcing one unique original image. Conflicting mappings still fail. The expected executable hash was checked against `evidence/native-inputs/main.exe`. Tick-gate addresses were checked against `recovered/native/main/decompiled.cpp:456`. The reads remain sequential and non-atomic; they do not prove live register state, RNG state, or full-frame rendering.
