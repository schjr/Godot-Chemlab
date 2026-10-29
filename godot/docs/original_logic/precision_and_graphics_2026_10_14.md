# Second actual Windows session: withdrawal and drawing references

The user transferred `precision-and-graphics.zip` into `build/windows-reference`.
Its SHA256 is `401a48ec4d5981fcdb2d738acfdbaaa4f0c37074fb11e211e97f894f0666791c`.
The six original members are retained unchanged in
`evidence/windows-runtime/precision-and-graphics-2026-10-14/`.
The original process is 9348, executable SHA256
`7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c`.
Each state capture has six stable allocation identities and five complete
100-QWORD arrays per allocation. The reader used query/read access only;
snapshots are not atomic and each records its stopped state before/after.

The app was restarted after the user-authorized Windows ARM compatibility
settings were applied. The cold capture is a manual load of the opening
`氢氧化铜与氢氧化铁.cem`, rather than the app's automatic startup path.
Do not infer equivalence between those allocation histories.

| Original member | SHA256 | Observed elapsed seconds |
| --- | --- | --- |
| full80-cold.json | e58df62ccfe663ff48492ced3b7f0759af3b9b00cd438274a2b4a286d8e1ba8a | 0 |
| full80-run.json | bc77afab8ba5ea08ff7c8af19d5daddc422ea63057e7157ca1b01430e7d9f782 | 45.390999999999991 |
| full80-naoh.json | 9f6793c5f8729e0dc99ae35de1446230c07f45c7c6c7e1b35c154c3b99b99887 | 73.064000000000021 |
| current-gdi-result.json | baa5e6ac5e8d074b047525029ab58949ce0247130450a85c6f8e87bd695ff3e5 | separate probe |
| naoh-running-click.json | d6f0ac398ed45d7b6fe1e688820bf445e47fa9c02de0dcda0e2b078de9bf122c | separate observation |
| allocator-globals.txt | a424ade43fcc94d6f49f675670a674b836fda78aed65d8895fdf71d9426c104a | same session |

## Successful withdrawal

The first NaOH bottle loses exactly the recovered two-mL dose. Its water
moles change from 2.2202486678508 to 2.10923623445826, and its NaOH from
0.1 to 0.095. The recipient dropper receives water
0.11101243339253997 mol and NaOH 0.004999999999999998 mol; species order
is inert gas, water, NaOH. Water masses are 38.000000000000007 g in the
bottle and 1.9999999999999998 g in the dropper.

`test_original_windows_withdrawal.gd` installs the exact observed pre-action
arrays in an isolated source action context, executes the native withdrawal
port, and compares all 12 reagent-row moles/mass/volume values bit for bit
against the actual post-action observation. All pass, including original
source/recipient indices and species order. The evidence is
`evidence/godot/actual-windows-withdrawal-2026-10-14.console.log`.
This does not replay the later timer history or certify inert-gas equivalence.
The earlier process8928 attempted withdrawal remains a separate no-op
observation; it was not relabelled a successful action.

## Arithmetic boundary remains open

The new empty-dropper inert-mole observation remains
`b1a934e4dc67273f`, and its inert volume remains exactly4.0. The PC64 port
retains the previously documented one-ULP difference. Thus the new setting
did not resolve the observed discrepancy. The stored5755E8 control word is
still memory evidence, not a sampled live x87 register. No precision change,
intermediate store, epsilon or captured-value substitution was introduced.

## Actual GDI requests

The returned57-case GDI result passes package/provenance/payload validation.
Imported SHA256 is `8d1a8be837781fea222af5f64aa8aae9cfea0a33414a25ba0cec06c87dc46e2e`.
All57 complete requests replay exactly through the existing capture provider.
The console and full local suite show no engine errors. An empty initial
pixel payload is handled directly instead of calling Godot's empty-buffer
Base64 conversion, which previously emitted an error despite returning0.

These are bounded native Windows GDI references, not captures of complete
original vessel frames. `native_vcl_verified` remains false. The additional
six-vessel material corpus and eighteen existing-DIB reader are prepared
separately; they must resolve the omitted particle/overlay/composition stages
and previously unobserved+3CC0 scalar before any complete-frame claim.
