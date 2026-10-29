# Original quantities and thermal modules

These modules port the identified native operations; they do not use the earlier replacement simulation model. They are separate from `lab_model.gd` until the original simulation driver and remaining operations are recovered.

## `OriginalQuantities.recalc(vessel, reagent_map)`

Source: original **0x00461E54**, saved decompilation lines 29128–29314 and disassembled machine instructions ending at **0x004624A4**. Reagent loader **0x00460D84**, lines 28826–28829, establishes original positional field eight as reagent double `+0x30`, used by the quantity routine as the mass-to-volume divisor. Field three is molar mass at reagent `+0x10`.

Inputs are ordered `vessel.contents` (species to moles), `vessel.volume_ml` (native capacity `+0x28`), and the original reagent map. Records supply `molar_mass` and `density_or_render_parameter`; a numerical density value is accepted directly so decoded native double values do not need a lossy string roundtrip. Existing `native_species_volume` values are retained for phases the original routine does not write.

The routine mutates these caches and returns `{ok: true}` on successful computation:

| Godot field | Native field | Meaning established by calculation |
|---|---|---|
| `native_species_mass` | `+0x298 + 8*i` | Species molar mass × moles, stored as double |
| `native_species_volume` | `+0x5b8 + 8*i` | Solid/liquid mass divided by native density; gas moles × 22.4 × 1000 |
| `native_liquid_volume` | `+0x4320` | Sum of exact `(液体)` suffix species volumes |
| `native_gas_moles` | `+0x4328` | Sum of exact `(气体)` suffix species moles |
| `native_gas_volume` | `+0x4330` | Aggregate gas moles × 22.4 × 1000 |
| `native_solid_volume` | `+0x4338` | Sum of exact `(固体)` suffix species volumes |
| `native_pressure` | `+0xa8` | Native excess-gas scalar; no SI unit is assigned |

Optional `native_species_mass_slots` / `native_species_volume_slots` arrays represent the underlying ordered native buffers. When supplied, mass slots and physical-phase volume slots are updated by index. Other volume slots remain unchanged. Missing volume values for dissolved/ionic/indicator species remain absent: the original routine neither reads nor writes those cells. Constructor evidence does not establish that these numeric cells start at zero, so this module does not invent zero values for them.

The phase helper follows original **0x00452ACC**: find the final ASCII `(` and copy the suffix until its first ASCII space. Exact suffix equality governs branches; category fields and arbitrary phase substring searches are not used.

Pressure calculation stores headspace (`capacity - liquid volume`) and gas excess (`gas volume - headspace`) as native doubles, then multiplies by original 80-bit constants at **0x004624BC** (`1fba6ddbb66ddbb6fa3f`) and **0x004624C8** (`3bdf4f8d976e1283f53f`) in the actual instruction order. Negative pressure is set to zero. There is no liquid-capacity clipping, temperature-dependent gas law, or substituted density.

For moles below `-1e-10`, the routine preserves the original ordering (write mass first, then stop), returns `stop: true` and `stop_requested: true`, and provides the original error text at **0x0056379E**: `容器中的药品mol量<0`. The model driver must apply the stop request. Missing native operands, invalid lookup results, zero physical density, and unsupported floating-point ranges fail explicitly instead of receiving guessed values. All recovered solid/liquid records have nonzero field-eight divisors.

## `OriginalThermal.advance(vessel, delta_seconds, multiplier)`

Source: original **0x0048E418**, machine instructions **0x0048E418–0x0048E667**. Required fields are `type_id` (`+0x08`), `temperature` (`+0x88`), integer `native_heating` (`+0xa0`), and `native_liquid_volume` (`+0x4320`). `delta_seconds` is the already computed original tick delta. The helper does not derive lamp geometry or change heater flags.

`slider_multiplier(native_rate_slider)` ports the integer `+0x3c78` setting: clamp to 1..19; the original `fabs(setting - 10) < 0.1` branch gives one at setting ten; values below ten give setting/10; values above ten give setting minus nine. The quotient expression reproduces the native qword stores for the complete integer domain while avoiding binary64 multiplication by an already rounded `0.1` constant.

Only type IDs 101..106, 108, and 121 change temperature. Heater flag one increases temperature by native `50 * delta * multiplier` when liquid volume is at most `0.001`, capped at `800`; otherwise it increases by `5 * delta * multiplier`, capped at `100`. Flag zero decreases temperature by `5 * delta * multiplier`, floored at `20`. Other integer flag values do neither branch. There are no altered temperature thresholds, exponential cooling, or additional apparatus types.

## Native precision and validation

The original executes x87 extended intermediates and qword stores. The saved decompiler's apparent single-precision casts are incorrect: disassembly uses `FMUL qword`, `FADD qword`, and `FSTP qword`. `OriginalX87` retains the extra significand bits using high/low binary64 arithmetic with rounding to the original 64-bit significand, then rounds at native double stores. Overflow/underflow ranges not supported by this helper return an explicit failure. This is floating-point compatibility for original operations, not a substitute chemistry or heat algorithm.

`tools/original_thermal_oracle.py` executes the actual PE temperature function and its actual `fabs` helper in Unicorn, with no hosted function boundaries. `tools/original_quantities_oracle.py` uses `OriginalOracle` to execute the actual quantity arithmetic while hosting declared string-lifetime/copy/equality, phase extraction, lookup, and message boundaries. Both record the binary identity and exact operand/output bits. The quantity oracle's initial nonphysical volume slots are explicit test inputs, not a claim about native cold-load initialization.

The fixtures include **1,109 thermal cases** and **702 quantity cases**, including every recovered reagent and 200 mixed-species cases. `tests/test_original_quantities_thermal.gd` compares every recorded output double bit for bit; all cases pass. Exact input bits are necessary because Godot's decimal JSON conversion can differ by one ULP. The reagent numeric loading in these fixtures is an explicit hosted input boundary; the complete native text-to-number loader is not claimed to have been executed.

This validates these finite arithmetic cases and identified branches. It does not validate lamp geometry, discovery, reactions, equilibrium, solubility, transport, the original driver ordering as a whole, or all possible x87 operands. Earlier educational scenarios and `lab_model.gd` tests are not evidence of original-code equivalence.
