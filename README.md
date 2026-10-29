# ChemLab for Godot

A Godot reconstruction of the historical 仿真化学实验室, retaining the original
laboratory resources, 28 experiment examples, molecule models, recovered code,
and native-reference verification evidence. The current port is a work in
progress; complete parity with the historical Windows applications has not yet
been established.

## Run the Godot project

Open [`godot/project.godot`](godot/project.godot) in **Godot 4.7.1** and run the
main scene. The project uses the Compatibility renderer. The macOS numerical
helper is retained in `godot/bin/`; Apple Silicon uses Rosetta to execute its
original x87 instructions.

Python utilities use **uv** to manage their local environment. From the
repository root:

```sh
uv run --no-project tools/godot_task.py import
uv run --no-project tools/godot_task.py run
uv run --no-project tools/godot_task.py test
```

Set `CHEMLAB_GODOT` to the Godot executable when it is not installed at
`/Applications/Godot.app/Contents/MacOS/Godot` or available as `godot`/`godot4`.
Godot requires access to its user-data folder. See the
[`Godot project README`](godot/README.md) for the verified behavior, limitations,
and current integration status.

## Repository contents

| Directory | Contents |
|---|---|
| `godot/` | Runnable project, assets, data, source ports, and tests |
| `tools/` | Recovery utilities, native-reference tools, and packaging scripts |
| `docs/`, `godot/docs/` | Format notes, source analysis, and integration evidence |
| `recovered/` | Recovered forms, chemistry data, database exports, and decompilation |
| `artifacts/` | Historical application inputs and resources used by recovery and verification |
| `evidence/` | Recorded native results and validation reports |

Generated application exports, Windows reference packages under `build/`,
duplicate source archives, Godot caches, and local Python environments are
excluded from version control.

## Historical source recovery

Recovered from `ChemLab.zip`, SHA-256 `3b2943c926f2c637fc28f3705ff454fe146570dbfcc55cfa6c112af6df7c1144`.

The archive contains compiled Windows software, resources and data; no original C++/Delphi source project was found. This recovery provides the code and original resources that can be recovered from those artifacts. **It is not the exact original source, a buildable project, or a behaviorally verified replacement.** The binaries contain Borland C++Builder and Delphi/VCL runtime evidence. The recovery did not execute the packaged applications.

## Start here

| Material | Location | Recovery status |
|---|---|---|
| Main laboratory event code | `recovered/native/main/published_handlers.cpp` | Pseudocode for all 296 preserved published methods |
| Main laboratory complete static export | `recovered/native/main/decompiled.cpp` | Default analysis export, including runtime/library routines |
| Molecule viewer event code | `recovered/native/molecule/published_handlers.cpp` | Pseudocode for all 197 preserved published methods |
| Encyclopedia event code | `recovered/native/encyclopedia/published_handlers.cpp` | Pseudocode for all 180 preserved published methods |
| AVI, GIF and two PE resource modules | `recovered/native/avi`, `gif`, `resource_6b1e97cc`, `resource_cb7e19b8` | Complete discovered-function exports plus published methods |
| Original forms | `recovered/forms/` | 69 exact binary DFM payloads, readable DFM and structured metadata |
| Component declarations and method addresses | `recovered/project/` | Incomplete declaration inventories; address mappings preserve published names |
| Original chemistry data | `recovered/chemistry/` | 599 reactions, 499 reagents, 28 experiments, 46 molecular models and help |
| Access database | `recovered/database/` | Seven tables, all 475 records, schema/indexes, JSON and verified SQLite copy |
| Coverage and verification | `recovered/coverage.json` | Per-binary identity and explicit counts/limits |
| Reproducible recovery tools | `tools/` | Newly written recovery code, separate from recovered application code |

Seven distinct PE artifacts were analyzed, with duplicate executable filenames recorded in `evidence/native-inputs.json`. Static analysis exported 26,698 of 26,699 discovered functions. A metadata-guided pass added 103 function entries, giving **26,801 distinct entries with pseudocode** and pseudocode for **all 786 preserved published-method addresses**. These totals include substantial Borland/VCL library code and are not counts of original author-written functions.

Each native directory contains `functions.tsv`, `symbols.tsv`, `coverage.json`, and `decompiled.cpp`. `published_recovered.cpp` contains the separate metadata-guided export; `published_recovery.tsv` records whether entries were already known or seeded from published metadata. `published_handlers.cpp` is a convenient index selecting those method bodies. Original published method names are preserved with synthetic prefixes/address suffixes. Their original class ownership, parameter types and calling conventions remain unresolved.

One 321,611-byte molecule-viewer routine at `0x0043d7d0` exceeded the 60-second decompiler limit. Its analyzed instructions are preserved in `recovered/native/molecule/fallback.asm`; no replacement implementation was invented. Unidentified machine code, indirect calls, uncertain function boundaries and compiler-generated structures may also remain unresolved. A successful decompilation does not prove that the recovered body is complete or equivalent to the original behavior.

## Verification

- All 69 original form resources match their exact binary slices and SHA-256 hashes, and parsed with zero trailing bytes.
- Exported code counts, published-method counts and binary identities were checked across all seven artifacts.
- All chemistry text was losslessly round-tripped to its original encoded bytes. Reaction species resolve to the supplied reagent library.
- All 475 database records were exported; every SQLite value was compared against its JSON source and SQLite integrity checking passed. The original database hash was unchanged. The password was read from the packaged note and was not copied into recovery code or reports.
- The original applications were not run, and the pseudocode and declaration inventories have not been compiled with the original Windows toolchain.

## Reproduce locally

Keep the extracted original package in `artifacts/ChemLab`. Python environments are managed with uv. These tools use the standard library; database extraction also requires Java and pinned Jackcess libraries.

```sh
UV_CACHE_DIR=/private/tmp/chemlab-uv-cache uv venv .venv
.venv/bin/python tools/forms_recover.py
.venv/bin/python tools/chemistry_recover.py --check
.venv/bin/python tools/database_recover.py --fetch-dependencies
.venv/bin/python tools/recover_native.py
.venv/bin/python tools/recover_native.py --published
.venv/bin/python tools/recover_native.py --published --select gif --force --seed-published
.venv/bin/python tools/index_recovery.py
.venv/bin/python tools/package_recovery.py
```

Native export used the existing Ghidra 12.1.4 and JDK 21 installations. Set `CHEMLAB_GHIDRA` and `CHEMLAB_JAVA_HOME` to their local paths on another machine. Ghidra configuration, caches and temporary projects are isolated under `/private/tmp`; the original binaries are never rewritten. Default function discovery and metadata-guided analysis are separately preserved. The GIF module required seeding published entries before automatic analysis to recover its `FormCreate` entry.

REA archive evidence is retained in `evidence/archive.json`: inspection `ev_680d1dabb337077a8c8948ce9094c8acee87e482fab2845ef318f1ac2cb394f2`, extraction `ev_822b920502827caa2e14e84cd199542e092840c72619bf6bda2d4ce5d6c99844`. Main-function inventory and sample decompilation evidence are retained in `evidence/main-rea.json`. Complete bulk exports were produced by the included Ghidra scripts and their corresponding logs; they are not represented as REA observations.

Exact original source comments, most identifiers, original project files, build options and complete high-level type definitions cannot be recovered from these compiled artifacts. Turning this material into a runnable replacement requires a separate implementation and validation effort.
