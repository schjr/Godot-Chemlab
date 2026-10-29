# Original startup particle RNG seed

`OriginalStartupRng.seed(system_time, crt_timezone_seconds,
crt_daylight_enabled)` supplies the exact startup two-DWORD state for the
existing `OriginalParticleRng.next`. It does not modify model/main/canvas.

`system_time` contains explicit integer Windows SYSTEMTIME fields `year`,
`month`, `day`, `hour`, `minute`, `second`, `millisecond`, `day_of_week`.
The latter two fields are validated as a clock profile but do not affect
the original seed. `crt_timezone_seconds` is the initialized signed DWORD
at00577974 (seconds added to local calendar seconds, normally seconds west
of UTC); `crt_daylight_enabled` is00577978!=0. A current Unix timestamp,
Godot randomize, OS timezone library, or fixed0/1 seed is not substituted.
Missing inputs return an explicit error. Valid local calendar fields are
required; this entry point does not expose the CRT's general malformed-date
normalization interface.

Native call sequence and operation addresses:

-00413698 calls0053D198 with null output pointer, then passes returned EAX
 to00539C0C.
-0053D198 calls GetLocalTime at00554F54, ignores milliseconds/weekday,
 passes year-1900,month-1,day-1,hour,minute,second,isdst=-1 to0053CE18.
-0053CE28–33 accepts tm_year70..138. For the valid SYSTEMTIME input domain,
 the remaining normalization divisions leave clock fields unchanged.
0053CEE3–CF4D computes native 32-bit seconds from the retained month table
0057785C and timezone global00577974. Leap logic is divisible-by-four over
1970..2038.0053CF56–79 consults0053CD04 when00577978!=0 and subtracts3600.
0053CF94–9F returnsFFFFFFFF if the signed result<=0, including epoch0
and2038 signed overflow. This raw failure word is still seeded by the caller.
-0053CD04 uses its own legacy DST rule: May–September active; before1987
last Sunday of April, from1987 first Sunday of April, ending last Sunday of
October. Start-day hour>=2 activates; end-day hour<=1 remains active.
These are the actual retained instructions, not modern Windows transition
rules, Southern Hemisphere rules, or the current US March/November policy.
-00539C0C writes TLS+44=raw_time, TLS+48=0, then calls00539C38 once.
00539C3E–4B writes low=(seed*015A4E35+1) mod2^32; high remains0. Its return
is(low>>16)&7FFF. Startup discards this result. The module returns it as
`discarded_rand` for audit, and returns the **post-consumption** `state`.
-Subsequent particles use00539C60, already represented byOriginalParticleRng.

The initialized CRT globals are deliberately explicit. CRT timezone setup
0053CFB0 can use a TZ environment path or Windows GetTimeZoneInformation;
its Windows branch adds Bias and StandardBias then multiplies by60, and
sets the daylight flag from the retained timezone structure. This module
does not infer those globals from a macOS timezone name or current DST
status. The actual Windows startup profile must be captured or supplied
by a separately evidenced runtime adapter. It does not automatically choose
a fresh seed when that profile is unavailable.

`tools/original_startup_rng_oracle.py` executes the retained PE instructions
for00413698,0053D198,0053CE18,0053CD04,00539C0C,00539C38 and00539C60.
Only GetLocalTime's16-byte output and TLS accessor0053CA64 are hosted;
initialized CRT globals are explicit inputs. No date conversion, DST decision
or random arithmetic is replaced inside the oracle. The executable SHA256
is7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c.
Retained REA dossiers are `startup_rng_time_dossier.json` and
`startup_rng_epoch_dossier.json`; full bounded original instruction bytes
and addresses are recorded in `startup_rng_native.asm`.

The fixture `native-startup-rng-oracle.json` contains1,375 actual startup
profiles and4,125 actual subsequent particle calls. Tests cover April/October
transition days/hours,1986/1987 rule change, leap dates,1970 epoch rejection,
2038 overflow, rejected outside-year range, signed timezone extremes,
non-hour timezone values, disabled DST, ignored milliseconds, stale incoming
TLS reset, and continuation of both DWORDs. All comparisons pass on Godot4.7.1.
The Python input-selector seed only selects fixture cases; it is never used
as the application's RNG state. This validates the explicit boundary contract,
not Windows timezone initialization or a whole running process snapshot.

## Live reconstructed-process clock boundary

`OriginalRuntimeRng.start()` now supplies the production boundary. It reads
Godot's actual local calendar and current timezone offset, constructs the
original SYSTEMTIME fields and invokes the unchanged source startup chain.
The Unix clock is used only to keep the calendar read within one second and
supply the ignored millisecond field; its epoch value is not the RNG seed.
The original CRT still computes that value, rejects its original year/epoch
limits, performs the first discarded random call and returns both state words.

The portable timezone API boundary explicitly declares a fixed-offset zone
for this process at startup. Its Bias is the negative of Godot's current
minutes-east-of-UTC offset, StandardBias is zero, and both transition months
are zero. Applying the source `53CFB0` Windows branch therefore establishes
`timezone=(Bias+StandardBias)*60` and disables the source legacy DST rule.
This is a valid declared reconstructed OS timezone, with provenance retained
in the result. It does not assert that the host lacks DST rules or that a
Windows VM's timezone structure has been observed. Godot's current `dst` flag
alone cannot establish those transition rules; the adapter does not infer
them from that flag or a timezone abbreviation. For the current Shanghai
host, the observed current offset480 minutes gives CRT timezone-28800.

The module also exposes `from_windows_clock` for an explicit complete boundary:
Bias and StandardBias are signed-DWORD minute fields, while the source
daylight flag requires both StandardDate.month and DaylightDate.month to be
nonzero. The source's own April/October rule still decides whether daylight
applies after that flag is enabled. It does not use modern host transition dates.

Startup is cached once for the process and returns the same state Dictionary.
Consumers must retain that shared reference; loading a document, pressing Run
or asking for the startup result again does not reseed a consumed sequence.
The live-boundary regression `test_original_runtime_rng.gd` covers positive,
negative and fractional-hour offsets, StandardBias, both transition-month
conditions, actual host-clock replay and continuation across repeated access.

Godot host API semantics were checked against its
[Time documentation](https://docs.godotengine.org/en/stable/classes/class_time.html)
and the [4.7 Unix implementation](https://github.com/godotengine/godot/blob/4.7/drivers/unix/os_unix.cpp).

To reproduce the bounded native reference in the uv-managed workspace venv:

```sh
.venv/bin/python tools/original_startup_rng_oracle.py
```

Unicorn execution requires the already authorized native-JIT sandbox override.
Godot comparison:

```sh
/Applications/Godot.app/Contents/MacOS/Godot --headless --path godot --log-file /private/tmp/chemlab-startup-rng.log --script res://tests/test_original_startup_rng.gd
```
