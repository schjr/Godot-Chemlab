# Exact native format and importer trace

This ledger concerns static recovered code and original stored records. It does not establish runtime equivalence for the new chemistry engine. No textbook-derived outcome has been substituted for the native code.

## Investigation state after interruption

The earlier requested educational scenarios were not written: no `example_scenarios.json`, acceptance-scenario test, or scenario outcome report was created. Existing preparer/catalogs, exact encoding tests, adapter tests, original annotation/chart/program extraction, and explicit export fallbacks remain. The temperature correction below is now applied. The prior importer used metadata field 9 as temperature; this was wrong. The native reader maps field 9 to offset `0x30`, whereas thermal integration reads temperature at `0x88` (metadata field 30). All 28 original example files store 20°C in field 30. Geometric values such as 222 in titration burets are no longer treated as temperature.

## Entry points and ownership

- Main Save button `Published_SpeedButton_saveClick_0042d600` calls `FUN_0042dc3c`, the text writer. [Published entry point](/Users/schjr/Programs/ChemLab_REA/recovered/native/main/published_recovered.cpp:10950), [writer](/Users/schjr/Programs/ChemLab_REA/recovered/native/main/decompiled.cpp:10670).
- Main Open button `Published_SpeedButton_openClick_0043220c` calls `FUN_0043240c`, the text reader. [Published entry point](/Users/schjr/Programs/ChemLab_REA/recovered/native/main/published_recovered.cpp:11095), [reader](/Users/schjr/Programs/ChemLab_REA/recovered/native/main/decompiled.cpp:11821).
- The file reader identifies three legacy signature versions. This parser supports the shipped V3 layout; older compatibility branches remain unported.
- Header fields 1 and 3 are vessel and connector counts. Header fields 2 and 4 are separate counters preserved verbatim, not rewritten as counts of the new Godot objects.

## Vessel record: exact 40 metadata fields

Offsets are relative to each native vessel allocation in pointer table `DAT_00585850`. Every raw text value remains in `metadata`, and the adapter exposes that array as `native_metadata`. Typed interpretations are used only where established below. The reader covers these assignments at [lines 12176–12433](/Users/schjr/Programs/ChemLab_REA/recovered/native/main/decompiled.cpp:12176).

| Zero-based field | Native offset | Stored type | Established use / boundary |
|---:|---:|---|---|
| 0 | 0x00 | int32 | Object record integer; repeatedly 1, not a unique identity |
| 1 | 0x04 | managed string | Object name, used for lookup/attachments |
| 2 | 0x08 | int32 | Apparatus type |
| 3 | 0x0c | int32 | Type-dependent size/subtype; includes tube angles and jar orientation |
| 4 | 0x10 | int32 | Diagram X |
| 5 | 0x14 | int32 | Diagram Y |
| 6 | 0x18 | int32 | Preserved; no semantic alias |
| 7 | 0x20 | double | Preserved; no semantic alias |
| 8 | 0x28 | double | Vessel volume/capacity used as free-space bound in transport |
| 9 | 0x30 | double | Liquid-column/draw height in submerged endpoint tests; **not temperature** |
| 10 | 0x38 | int32 | Mouth/cap state; connector solver tests ==0, heater checks !=1 |
| 11 | 0x3c | int32 | Relative control/attachment geometry, retained |
| 12 | 0x40 | int32 | Relative control/attachment geometry, retained |
| 13 | 0x44 | int32 | Relative control/attachment geometry, retained |
| 14 | 0x48 | int32 | Relative control/attachment geometry, retained |
| 15 | 0x4c | int32 | Control color/state raw value |
| 16 | 0x50 | int32 | Second control state, retained |
| 17 | 0x54 | int32 | Relative control/attachment geometry, retained |
| 18 | 0x58 | int32 | Relative control/attachment geometry, retained |
| 19 | 0x5c | int32 | Relative control/attachment geometry, retained |
| 20 | 0x60 | int32 | Relative control/attachment geometry, retained |
| 21 | 0x64 | int32 | Second control color/state raw value |
| 22 | 0x68 | int32 | Additional control state; exact valve UI interpretation requires callback trace |
| 23 | 0x6c | int32 | Type-dependent control subtype (stand checks value 2) |
| 24 | 0x70 | int32 | Retained without new semantic alias |
| 25 | 0x74 | int32 | Retained without new semantic alias |
| 26 | 0x78 | int32 | Retained without new semantic alias |
| 27 | 0x7c | int32 | Retained without new semantic alias |
| 28 | 0x80 | managed string | Attached parent object name, resolved by `FUN_00453f98` |
| 29 | 0x84 | int32 | Attached parent type/subtype |
| 30 | 0x88 | double | Actual temperature; thermal integrator reads/writes this |
| 31 | 0x90 | managed string | Preserved string |
| 32 | 0x94 | managed string | Preserved string |
| 33 | 0x98 | managed string | Preserved string |
| 34 | 0x9c | int32 | State propagated through a type-301 parent with subtype 2; no inferred electrolysis/light alias |
| 35 | 0xa0 | int32 | Heating flag, thermal integrator tests ==1 |
| 36 | 0xa4 | int32 | Smart-reaction checkbox |
| 37 | 0xa8 | double | Preserved |
| 38 | 0xb0 | double | Preserved |
| 39 | 0xb8 | double | Preserved |

The exact native model has additional transient fields that are not serialized in this prefix. The Godot importer does not reconstruct them by guessed geometry.

Heating evidence: `FUN_00470060` resets container offset `0xa0` before deriving heat attachment state. Its type-302 branch activates when lamp `0x38 != 1`. [Heat attachment logic](/Users/schjr/Programs/ChemLab_REA/recovered/native/main/decompiled.cpp:35146). Native thermal integration tests `0xa0 == 1`, changes `0x88`, and chooses different increments/caps for wet/dry contents. [Temperature integration](/Users/schjr/Programs/ChemLab_REA/recovered/native/main/decompiled.cpp:43999). The adapter now imports the stored heating flag and exposes the lamp branch as `native_heater_enabled`. Its existing `burning` field is only an integration alias for that proven lamp activation condition; it does not establish a chemistry combustion model. Native recomputation must supersede stored heating once original-mode execution is ported.

The smart checkbox assignment is `DAT_0059625c = (checked == 1)` and is written to vessel word `0x29`, offset `0xa4`. [Checkbox read](/Users/schjr/Programs/ChemLab_REA/recovered/native/main/decompiled.cpp:50642), [property write](/Users/schjr/Programs/ChemLab_REA/recovered/native/main/decompiled.cpp:50761). Field 34 is not this checkbox.

## Reagents, reactions and simulator values

After metadata comes an integer reagent count at native offset `0x104`. Each triplet contains name (`0x108 + 4*i`), mass (`0x298 + 8*i`) and amount (`0x8d8 + 8*i`). The writer/reader preserve both mass and amount; a renderer should not discard either or assume all volume comes from capacity.

Reaction count is at `0xf18`. Each reaction occupies native stride `0xe8` and serializes: integer at `0xf20`, name at `0xf24`, reactant/product counts at `0xf28/0xf2c`, reagent/coefficient pairs, then five parameters (`0xfd0` double, `0xfd8` string, `0xfe0` double, `0xfe8` double, `0xff0` string). The record name is a stable `方程式...` identifier; the leading integer is not a stable reaction identity. Full definitions are retained in `reaction_overrides` rather than assuming the library's same-numbered entry has identical contents. [Reaction reader](/Users/schjr/Programs/ChemLab_REA/recovered/native/main/decompiled.cpp:12465).

Twenty integers follow, at native offsets `0x3c70 + 4*i`, fields 0–19. The property form stores ion consideration (`CheckBox2`) and dissolution/precipitation consideration (`CheckBox3`) in the first two fields, then copies all twenty words. Field 2 is read as a bounded 1–19 thermal adjustment in the native integrator; the importer retains it, and does not interpret it as a new arbitrary rate. Fields 3–19 remain raw. [Property controls](/Users/schjr/Programs/ChemLab_REA/recovered/native/main/decompiled.cpp:50644), [20-word copy](/Users/schjr/Programs/ChemLab_REA/recovered/native/main/decompiled.cpp:50794), [thermal adjustment](/Users/schjr/Programs/ChemLab_REA/recovered/native/main/decompiled.cpp:43975).

## Connectors: exact 25 fields

Connector allocations are in `DAT_0058baec`. File fields map to offsets:

`[0x00,0x04,0x08,0x0c,0x10,0x14,0x18,0x1c,0x20,0x24,0x28,0x2c,0x30,0x34,0x38,0x3c,0x40,0x44,0x48,0x4c,0x50,0x54,0x58,0x60,0x68]`.

Field 1 is the connector's own name. Fields 2–5 are the two diagram endpoints. Fields 11/14 are attached endpoint names, fields 12/15 their types, and fields 13/16 their endpoint selectors. A connector can reference another connector with type 1001/1002. The native chain resolver `FUN_0046cee0` follows a connector's opposite endpoint according to these types and stops at vessels with type 101–299 or unconnected endpoints; cycle/visited state is stored at connector `0x4c`. [Resolver](/Users/schjr/Programs/ChemLab_REA/recovered/native/main/decompiled.cpp:33733).

`FUN_0046d414` clears connector visitation state, traverses the graph, and tests whether endpoints are submerged using vessel Y + half image height − field-9 liquid height. It also tests native mouth states. [Graph and endpoint solver](/Users/schjr/Programs/ChemLab_REA/recovered/native/main/decompiled.cpp:33863). `FUN_0046f704` applies subsequent transfer and volume-space logic. [Transfer continuation](/Users/schjr/Programs/ChemLab_REA/recovered/native/main/decompiled.cpp:34811).

The previous adapter's generic `gas_only=true, rate=0.2` connections were new approximation fields, not a port of this solver. These invented flow fields have now been removed from the adapter; state connections identify `native_route` plus their retained connector index, and `native_connectors` carries the original 25 fields. They must not serve as the authority for original-mode transport. Original records remain available as document connectors, raw metadata and native endpoint selectors. Type-211 funnel attachment via vessel metadata 28/29 is not represented by those gas connectors and must be handled by the original liquid-control callback, not an invented gas link.

## Trailer and event groups

After connectors come two variable-label strings per reagent. Then:

1. Custom variable count; seven fields per variable (three integers then name, description, initial/current string values).
2. Chart count; 55 fields per chart: ten chart fields and five nine-field series. Series fields 7/8 are exact X/Y variable names. Chart native position is preserved. The old 360×180 display size was a documented new view default, not native recovered geometry.
3. Annotation count; sixteen fields (enable/style, XY, size, font/color etc.) followed by field-15 text-line count and those exact lines.
4. Program group count; four integers per group followed by first integer's number of source lines. Native storage is form offset `0x5dd8 + group*0x7e0`: line count, fields `0x5ddc/0x5de0/0x5de4`, then managed source strings at `0x5de8 + line*4`. [Program reader](/Users/schjr/Programs/ChemLab_REA/recovered/native/main/decompiled.cpp:13129), [writer](/Users/schjr/Programs/ChemLab_REA/recovered/native/main/decompiled.cpp:11578).

`program_groups` retains all four integers and exact source strings. The former combined `program` string is an inspection convenience; running every combined line on every frame would not establish original event scheduling. The stored group integers' scheduling semantics have not been verified here, and no names such as “trigger” or “interval” have been invented for them. Group editor reads/writes the same line arrays. [Code editor read](/Users/schjr/Programs/ChemLab_REA/recovered/native/main/decompiled.cpp:57665), [editor write](/Users/schjr/Programs/ChemLab_REA/recovered/native/main/decompiled.cpp:57706).

## Verification boundary

Native field correction/regeneration passes all 133 GB18030 byte round trips and all 28 unchanged experiment adapter round trips. These are format-preservation checks, not educational/chemistry acceptance tests. They do not prove frame timing, reaction behavior, original dropper interaction, or original transport correctness. No such broader claim is made by this ledger.

The later constructor trace in `godot/docs/original_logic/constructor_trace.md` proves cold per-reaction note strings are explicitly null despite their omission from `.cem`, while numeric per-reagent volume slots are not universally zero-initialized. This evidence is stronger than any inference from a fresh allocator block.
