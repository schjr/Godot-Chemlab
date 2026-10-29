# Original native simulation trace

This is a static trace of the shipped `main.exe`, SHA-256 `7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c`. It does **not** establish that the current Godot engine follows the original algorithms. The earlier Godot model contains replacement algorithms that fail the user's requirement for original code logic. No engine changes were made during this audit.

The primary source is [recovered/native/main/decompiled.cpp](/Users/schjr/Programs/ChemLab_REA/recovered/native/main/decompiled.cpp). Line numbers below refer to that saved file. Native strings and constants were additionally read from the matching PE at [evidence/native-inputs/main.exe](/Users/schjr/Programs/ChemLab_REA/evidence/native-inputs/main.exe). The exact virtual addresses, file offsets, bytes, and decoded values are retained in [native_simulation_constants.json](/Users/schjr/Programs/ChemLab_REA/godot/docs/original_logic/native_simulation_constants.json).

## Actual tick and ordering

`FUN_004018b0`, entry **0x004018B0**, starts at line 382. Its simulation block at lines 450–477 is gated by elapsed clock difference greater than five, global `DAT_0057a6f8 == 1`, and main-form field `+0x5bc == 0`. It obtains the clock through `FUN_0053d180` (**0x0053D180**, lines 166448–166460), which returns `GetTickCount() - DAT_0057798c`.

The tick assigns `DAT_005636d4 = 0.001 * (current_clock - DAT_0057a74c)`, adds that delta to `DAT_005636cc`, and updates `DAT_0057a74c`. The factor is the 80-bit constant at **0x004028DC**, decoded directly from the PE as `0.001`. There is no evidence here for the Godot engine's 0.1-second substeps or 60-second cap.

The original calls these functions in this order:

| Order | Native function | Saved source lines | Observation |
|---|---|---|---|
| 1 | `0x00470060` | 35146–35851 | Resets and derives heater flags using lamp/apparatus geometry and attachment references. |
| 2 | `0x0048E418` | 43955–44040 | Applies the temperature update described below. |
| 3 | `0x004849FC` | 40400–43096 | Large interaction/transport pass using apparatus states and geometry. Full branch meanings are not yet established. |
| 4 | `0x0046C84C` | 33537–33558 | Called once for each apparatus whose `+0x18 == 0`; conditionally dissolves/precipitates, executes chemistry, conditionally dissolves/precipitates again. |
| 5 | `0x004624D8` | 29319–29334 | Recomputes derived quantities for type IDs between 100 and 300. |
| 6 | `0x0046EC50` | 34542–34807 | Open-vessel gas volume / overflow handling; contains collection-by-water branches. |
| 7 | `0x0046D414` | 33863–34465 | Connector-network processing, including endpoint resolution and per-species changes. |
| 8 | `0x0046F704` | 34811–35142 | Further transport using apparatus references. Not fully translated. |
| 9 | `0x004624D8` | 29319–29334 | Recomputes derived quantities again after transport. |
| 10 | `0x0048C428` | 43100–43165 | Updates defined mole/mass variables from apparatus arrays. |

`FUN_004126dc` (**0x004126DC**, line 7717) also invokes `0x00470060` before drawing and invokes `0x0047E714` when running. Therefore interaction behavior cannot safely be reconstructed only from the main tick's call list. The latter function spans lines 38289–40396 and must be traced separately for exact geometry/transfer semantics.

## Apparatus and equation memory layout established by use

The apparatus pointer array is `DAT_00585850`; `DAT_0058779c` is its active count. The following uses are directly present in the saved code. Meaning labels requiring additional field-loader correlation remain marked as such.

| Apparatus offset | Native use / established interpretation | Source anchor |
|---|---|---|
| `+0x08` | Apparatus type ID. `0x12e` is 302 (lamp); `0x12d` is 301 (stand). | 35175, 35209 |
| `+0x10`, `+0x14` | Integer position coordinates used with sprite dimensions and scale. | 35228 onward |
| `+0x18` | Mode/state; chemistry tick runs only when this equals zero. Other geometry branches test one or two. Exact state enum is not assigned. | 468; 38417 |
| `+0x28` | Container capacity used in volume/headspace calculations. | 29183; 34603 |
| `+0x30` | Shape/size parameter, also tested in solid-render bookkeeping. It is **not** the temperature field. | 30749; 32851 |
| `+0x38` | Cap/open flag; gas-open pass requires zero, lamp active branch requires value unequal to one. Exact UI enum needs original handler correlation. | 34594; 35209 |
| `+0x80` | Apparatus attachment/reference name consulted through `FUN_00453f98`. | 35187 |
| `+0x88` | Double temperature, compared and written by heat integration. | 43999–44027 |
| `+0xa0` | Integer heater-active flag reset and derived by `0x00470060`, consumed by reaction conditions and temperature update. | 35175–35180; 43999 |
| `+0xa4` | Smart discovery flag. | 29892 |
| `+0x104` | Number of species slots. | 29178; 29427 |
| `+0x108 + 4*i` | Species name strings. | 29429; 29219 |
| `+0x298 + 8*i` | Species mass = library molar mass × species moles. | 29198–29201 |
| `+0x5b8 + 8*i` | Derived species volume. Gas volume is moles × 22.4 × 1000; other qualifying phases use mass / library field `+0x30`. | 29260–29269 |
| `+0x8d8 + 8*i` | Species moles. Values below `-1e-10` stop the original simulation and show an error. | 29199–29215 |
| `+0xf18` | Number of per-container equations. | 29902; 30432 |
| `+0x3c70` | Ionic discovery option; zero causes ionic library equations to be skipped. | 29922–29933 |
| `+0x3c74` | Dissolution/precipitation option; one enables passes both before and after reactions. | 33546–33556 |
| `+0x3c78` | Per-container rate/heat slider, clamped between 1 and 19. | 29868–29888; 43976–43994 |
| `+0x4320` | Derived sum of liquid species volumes (mL). | 29294–29300 |
| `+0x4328` | Derived sum of gas moles. | 29306–29311 |
| `+0x4330` | Derived gas volume = gas moles × 22.4 × 1000. | 29177–29180 |
| `+0x4338` | Derived sum of solid species volumes. | 29281–29284 |

The equation record stride is **0xe8 bytes**, beginning at apparatus `+0xf20` (deduced from the same fields in the library record and copied equation blocks). Observed fields relative to the apparatus for equation index `j`:

| Offset plus `j*0xe8` | Observed field |
|---|---|
| `0xf28`, `0xf2c` | Reactant and product counts |
| `0xf30 + 4*i`, `0xf58 + 4*i` | Reactant and product species names |
| `0xf80 + 4*i`, `0xfa8 + 4*i` | Integer reactant and product coefficients |
| `0xfd8` | Condition text |
| `0xfe0` | Double reaction rate |
| `0xfe8` | Double equilibrium value |
| `0xff0` | Direction/mode text |
| `0x1000` | Note text; the exact note `水的电离` selects a separate algorithm |

These offsets are established by arithmetic and string comparisons at lines 30432–33096. Reaction heat and unused/trailing note fields need reader/editor correlation before assigning every slot.

## Exact thermal arithmetic; geometry still incomplete

`FUN_0048e418` only updates apparatus types `101..106`, `108`, and `121` (line 43998). It obtains the slider from `+0x3c78`, clamps 1..19, applies the 80-bit multiplier at **0x0048E680** (decoded as `0.1`) for values below 10, and subtracts nine for values above 10. Subsequent disassembly resolves `FUN_005394d4` as a double-input `fabs` helper. The actual special test is `fabs(setting - 10) < 0.1`, yielding multiplier one at integer setting ten. This scalar arithmetic is now ported and validated separately; lamp geometry remains unresolved.

When `+0xa0 == 1`:

- If `+0x4320 <= 0.001`, temperature increases by native x87 `50 * dt * multiplier` and is capped at **800°C**.
- Otherwise it increases by native x87 `5 * dt * multiplier` and is capped at **100°C**.

When `+0xa0 == 0`, temperature decreases by `dt * 5 * multiplier` and is floored at **20°C**. Subsequent instruction-level analysis corrected the decompiler's apparent single-precision casts: the native routine uses x87 extended intermediates and qword inputs/stores. The previous Godot exponential cooling and +8/+30 heating do not match this code. See `quantities_thermal_ports.md` for the separately validated direct port.

`FUN_00470060` resets `+0xa0` for stands and type IDs 101..299, then identifies lamp type 302 with `+0x38 != 1`. It evaluates nearby stands/containers with apparatus-specific formulas using position, sprite width/height virtual methods (`+0xfc` object, virtual `+0x20` and `+0x2c`), scale `DAT_005636c0`, and stand offsets. At line 35294 and subsequent branches it sets candidate `+0xa0 = 1`. The formulas differ for horizontal/vertical tubes, beakers, flasks and stands; replacing them with one Euclidean-distance threshold would violate the source. Exact formulas and all sprite/attachment offsets are not fully lifted yet.

## Smart discovery and reaction evaluation

`FUN_0046c84c` calls `FUN_0046b858` before and after `FUN_00462c18` when `+0x3c74 == 1`. This establishes that original solubility conversion is a real part of simulation, rather than an optional display-only field.

`FUN_00462c18` (**0x00462C18**, lines 29583–33132) begins by resetting gas-generation bookkeeping `+0x3cc0`. Smart discovery (`+0xa4 == 1`) runs **before** the selected equation evaluation loops. It traverses the library array `DAT_00580a2c`, whose count is `DAT_0058584c`.

`FUN_00462b48` (**0x00462B48**, lines 29537–29579) compares reactant and product name sets/counts between an existing equation and the candidate. The duplicate search does not compare IDs. `FUN_00462520` (**0x00462520**, lines 29338–29370) verifies reactant-name presence among vessel slots; this presence check does not read mole amounts. `FUN_004625c0` does the corresponding product-presence check. Existing zero-mole species therefore matter to discovery. The Godot model's positive-mole-only discovery and ID-only deduplication are not code-equivalent.

When a candidate is accepted, it is copied into a per-vessel record (maximum 50 equations) and `FUN_00462660` ensures all reactant/product species have slots with zero quantities and reset bookkeeping (lines 29410–29533). The ionic option skips library equation type `离子` only during discovery; it is not a blanket veto of selected ionic equations.

The binary contains exact condition strings `加热`, `加强热`, `高温`, `点燃`, `温度>` and `温度<`, recorded with addresses/bytes in the JSON evidence file. `FUN_005410cc` is the string-equality wrapper (lines 169488–169498); `FUN_005410e4` is its inequality wrapper. These must not be mistaken for substring searches.

Observed condition behavior:

- Smart discovery splits the condition text into at most ten space-delimited tokens (lines 29940 onward).
- `加热`, `加强热` and `高温` candidates require the heater flag at `+0xa0` (line 30000).
- `加强热`/`高温` candidates require temperature at least **200°C** (line 30023).
- `点燃` candidates are skipped in the observed smart-discovery path (line 30029); other ignition handling belongs to interaction passes and cannot be replaced by a generic Boolean.
- Selected-equation processing compares exact condition strings; selected `加强热` requires **200°C** (line 30484). Numeric `温度>`/`温度<` parsing uses the original string conversion helpers and inclusive boundary behavior visible in branch comparisons. Equality at the threshold is not handled like Godot's strict `>` rejection.
- Aqueous, light, electrical, and arbitrary condition labels must be treated according to the complete native branches. The previous generic supported-condition whitelist is not established by this function and must not be retained as equivalent original behavior.

The selected equations are evaluated in three passes: one-way equations excluding the special water-ionization note (line 30432), reversible equations excluding that note (line 31004), then equations selected by the exact note `水的电离` (line 32084). The special note must remain in imported equation data. A single generic reversible solver cannot represent these paths.

The one-way path computes required amount `coefficient * rate * dt * multiplier`, subtracts it from reactant mole slots, adds it to product mole slots, and maintains phase-specific solid/gas bookkeeping (lines 30625–30809). The limiting-reagent path begins around line 30810 and must be lifted completely, including bookkeeping and thresholds. No physical balancing correction is authorized: per-container coefficients in original files govern computation, even when a recorded equation differs from modern textbook stoichiometry.

## Equilibrium and solubility: partially traced, not ready to implement

The reversible loops construct phase-specific concentration arrays. They sum liquid, gas and solid volumes from `+0x5b8` (lines 31239 onward). Dissolved and ionic species use `moles / liquid_volume * 1000`; gases use the gas-volume total; several solid/liquid branches have distinct handling. Power products are computed through `FUN_005399d8`, then product/reactant quotients are compared to the stored equilibrium value. The loops halve trial amounts, cap a step by `rate * dt * multiplier`, mutate species slots, and repeat. See lines 31558–31840 and 32651–32950.

The binary constant at **0x0046B848**, decoded as **0.0001**, participates in a relative convergence test. Its exact bytes/value are retained in the JSON evidence file. At present the decompiler loses x87 operand flow around `FUN_005394d4` and `FUN_005399d8`, so the exact powers, comparisons, stopping behavior, and special water path require assembly lifting. Treating the stored value as a universal thermodynamic equilibrium constant or treating every phase identically is not supported.

`FUN_0046b858` (**0x0046B858**, lines 33136–33533) determines water mass using reagent lookup and molar mass, then calculates a solubility mass limit proportional to `0.01 * water_mass * reagent(+0x50)` (constant **0x0046C838** decoded as `0.01`). It converts between phase-specific name variants through `FUN_00452acc` and `FUN_00452c3c`, inserting missing species slots as needed and transferring moles. Exact name-normalization rules, temperature interpolation, species lookup failures and solid bookkeeping must be lifted before implementing this pass.

## Gas transport and volume evidence

`FUN_00461e54` (**0x00461E54**, lines 29128–29314) derives mass, volume, liquid volume and gas quantity. It uses library field `+0x10` as molar mass and `+0x30` as density/volume divisor for qualifying phases; gases use **22.4 L/mol** converted to mL. The prior assumption that every liquid's mass equals mL is not equivalent.

`FUN_0046ec50` handles open container gas using remaining headspace `capacity - liquid_volume`, gas molar volume, cap flag, and inverted collection state. It also handles water displacement through a referenced apparatus (lines 34638 onward). The remaining branches include release/escape rather than unconditional permanent gas retention. `FUN_0046d414` resolves conduit records and alters several linked species arrays. The existing Godot per-link fraction-per-second transport has no native equivalence evidence.

## Remaining prerequisites and audit boundary

This pass identified original ordering, fields, several exact constants, and concrete differences from the replacement model. It did not execute the Windows binary and did not establish end-to-end equivalence for any experiment. Existing tests demonstrate only the behavior of the replacement model; they must not be described as original-code validation.

Before changing engine behavior, resolve the decompiler's missing x87 stack/flag effects with assembly, confirm all field mappings against original loaders/editors, lift all three reaction loops, lift solubility and every transfer/overflow branch, and compare differential traces against the original executable or a faithful emulator. Unrecognized branches remain unresolved rather than receiving substituted physics.

No pending command was interrupted while writing engine code: the proposed new `transfer_liquid`, capacity, lamp-distance and solution-volume APIs were never implemented before the user's constraint changed. This audit only added this document and the read-only binary evidence JSON.
