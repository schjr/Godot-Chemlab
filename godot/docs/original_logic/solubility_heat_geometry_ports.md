# Original solubility and heater geometry

Both modules are separate ports of identified original functions. They do not edit or fall back to the earlier replacement model.

## Solubility

`OriginalSolubility.advance(vessel, reagent_map, delta_seconds)` ports **0x0046B858**. The driver **0x0046C84C** calls it before and after the reaction core only when native `+0x3c74` equals one. Caller state uses ordered `contents`, `native_species_mass`, `native_species_volume`, `solid_3cd8` and `solid_3ff8` dictionaries. Optional native slot arrays are updated only on proven native insertion paths.

The original computes water mass once on entry from exact species `H2O(液体)` and its original molar mass. Each species' saturation mass uses water mass multiplied by reagent `+0x50`, then original extended constant **0x0046C838** (`0ad7a3703d0ad7a3f83f`, 0.01). The reagent scalar at `+0x50` comes from original positional field twelve. The raw temperature expression at `+0x48` (field eleven) and container temperature are not read by this function. Bounded searches identify direct scalar writes in the library loader and reagent editors, not in the identified main tick. No interpolation has been introduced.

Excess dissolved material moves immediately into its paired `(固体)` species, falling back to `(气体)` only when the solid species is absent from both the container and original catalogue. Solid and gas species can move into paired `(溶解)` species. That dissolution is capped at original **0x0046C844** qword `0.1 * delta_seconds`, and at the available source amount and saturation deficit. Missing paired catalogue species are skipped according to original branches. The native maximum of 100 species slots is preserved.

Species names are handled by exact original phase/base operations. The phase extractor **0x00452ACC** takes the final parenthesized suffix up to the first ASCII space; base extractor **0x00452C3C** takes the prefix before the final `(`. Native insertion initializes the new mole, mass, volume, particle counters and variable-name fields to their original zero/empty values. Existing counters and quantity caches are not recomputed by this stage; the outer native driver performs aggregation later. The loop also visits newly appended slots in their original order.

Instruction-level analysis establishes qword stores of the saturation mass, excess/deficit numerator, transferred amount, and each mole update. `OriginalX87` preserves those stores and the extended comparisons. No phase-conservation shortcut, capacity clip, density substitution, or changed rate has been added.

`tools/original_solubility_oracle.py` executes actual **0x0046B858** bytes with explicitly hosted string construction/copy/comparison/concatenation, exact base/phase extraction and lookup boundaries. **69 cases** cover 21 original paired species, gas fallback, dissolution into new/existing slots, precipitation, insoluble hydroxides, absence of water, zero delta, all-available dissolution, and differing temperatures with identical scalar input. Three additional cases execute actual **0x0046C84C** with an original neutralization equation and flags zero/one/two. The source port reproduces all recorded ordered slots and double stores bit for bit, including solubility-before/reaction/solubility-after behavior.

## Heater geometry

`OriginalHeatGeometry.derive(vessels, native_scale)` ports **0x00470060**. It derives original `+0xa0` heater flags from active lamp cap state, apparatus positions, native bitmap dimensions, apparatus subtype and stand fields. It does not use a radius guessed from chemistry or a generic heating checkbox.

The routine first resets stand and type-101..299 heater flags, then traverses lamps and candidate targets in their original array order. Lamp type 302 is active when its native `+0x38` value is unequal to one. Active lamps initialize their original artwork fields before target-specific adjustments.

Required fields correspond directly to the native record:

| Godot field | Native location |
|---|---|
| `label`, `type_id`, `native_type_parameter` | `+0x04`, `+0x08`, `+0x0c` |
| `position` | Integer `+0x10`, `+0x14` |
| `native_cap_flag` | `+0x38` |
| `native_flame_style`, `native_flame_width`, `native_flame_height` | `+0x50`, `+0x5c`, `+0x60` |
| `native_platform_mode`, `native_platform_offset` | `+0x6c`, `+0x7c` |
| `native_attachment`, `native_ignition`, `native_heating` | `+0x80`, `+0x9c`, `+0xa0` |
| `native_sprite_height`, `native_sprite_width` | Bitmap object `+0xfc` virtual getters `+0x20`, `+0x2c` |

The caller must provide actual native bitmap dimensions. Missing fields or unsupported numeric ranges fail explicitly. Unknown numeric caches are not supplied invented defaults.

The port preserves separate stand, vertical tube, 45-degree tube, horizontal tube, beaker, flask, conduit and evaporating-dish branches, their original strict horizontal/vertical comparisons, and their differing side effects. In particular, slanted tubes use original horizontal offset `29 * scale`, horizontal tubes use `15 * scale`; ordinary tube and flask branches differ in whether they change lamp artwork. Types 104 and 105 mark heating without changing lamp artwork fields. The original integer helper **0x005394FC** truncates toward zero; it does not round to nearest.

The final attachment pass propagates stand `+0x9c` ignition when its platform mode is two. This is a distinct field from `+0xa0` heating and is not replaced with a generic Boolean relationship.

`tools/original_heat_geometry_oracle.py` executes actual original geometry instructions and actual `fabs` / integer conversion helpers. Bitmap dimension access and name lookup are declared hosted boundaries. **445 cases** include original experiment coordinates and metadata with explicitly active lamps, supported type/subtype boundaries at multiple scales, a closed lamp, stand attachment propagation, and 100 ordered multi-lamp layouts with nonbinary scales. All output heater, ignition and artwork fields match the source port exactly. The fixtures' declared bitmap inputs establish the arithmetic comparison; they do not by themselves validate the complete original bitmap-construction pipeline.

Run `tests/test_original_solubility.gd` and `tests/test_original_heat_geometry.gd` through Godot. These results validate the stated stages and fixtures, not the complete application, unported overflow/connector stages, or all possible floating-point inputs.
