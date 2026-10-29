# Original apparatus factory metadata

`OriginalFactory` specializes the finite original palette choices using outputs of actual original creation instructions. It does not infer apparatus capacities or initialization from names, textbook glassware sizes, or the earlier replacement model.

## Interface

```gdscript
OriginalFactory.create(kind, position, bridge_id, native_label_counter)
```

The result is `{ok, vessel, next_native_label_counter, native_creation_entry}`. The bridge ID is separate from original naming. Original `DAT_005877A0` is the decimal label counter; `DAT_0058779C` is the live apparatus count. The callback increments both separately. The caller must supply the original label counter and persist its returned successor. It is not guessed from the bridge ID or current array length. The successor preserves signed 32-bit wrap.

The returned vessel contains forty original metadata fields, twenty simulation fields, the three original control records, empty ordered contents and reaction arrays, exact bitmap filenames/dimensions, and typed aliases needed by original quantity/thermal/geometry modules. Metadata coordinates are original integer mouse coordinates; invalid/out-of-range inputs fail explicitly.

`native_texture_kind` identifies the actual bitmap stem rather than assuming it equals the palette key. For example `gkp1000` uses `gkp_z`, and `djqp` uses `d_jqp`. The original bottle creation code can select stoppered artwork while leaving cap-state metadata zero. That discrepancy is preserved in the data rather than corrected by a guessed physical rule.

Separate connector/annotation/button/chart pools and the user-selected image-file workflow are not converted into fake chemical vessels. Unsupported kinds return an error until their actual builders are provided.

## Original source and evidence

The base initializer is **0x00453A28**, `recovered/native/main/decompiled.cpp:24114`. The creation handler is **0x00417EE0**, `recovered/native/main/published_recovered.cpp:2154`. Palette callbacks in the same file assign selected type at `DAT_0057A724` and subtype/size at `DAT_0057A728`; for example:

- **0x0043FBF4** selects dropper type 204 and parameter four.
- **0x0042D428** selects alcohol lamp type 302 and parameter zero.
- **0x0045239C / 0x004523C8 / 0x004523F4** select type 101 with angles zero, 45 and 97.
- **0x004524D0 / 0x004524FC** select narrow bottle type 202 with parameters 100 and 1000.
- **0x00452528 / 0x00452554** select wide bottle type 201 with parameters 100 and 1000.
- Conduit choices assign type **1001** in a separate pool. Type **311** is a glass rod.

The constructor initializes temperature 20, smart flag one, dissolution flag one, rate slider ten, empty counts and managed strings, and selected aggregate doubles. It does not zero unused per-species numeric cells or aggregate solid volume at `+0x4338`. The probe seeds uninitialized storage with `0xa5`; all 33 creation paths preserve those bytes at `+0x4338`. The factory therefore leaves those values absent/unknown rather than assigning zero.

Original capacities and oddities are retained:

| Original palette family | Native `+0x28` capacity |
|---|---|
| Test tubes, all three angles | 100 |
| Beakers | Selected 100, 200 or 500 |
| Conical flasks | Selected 100 or 250 |
| Round/flat flasks, horizontal glass vessel, U tube | Selected 100 |
| Ordinary/inverted gas jars | Absolute selected parameter, 100; inversion is recorded in native state |
| Wide/narrow bottles, including parameter 1000 | **100**; subtype and bitmap selection remain separate |
| Dropper | **4** |
| Evaporating dish and funnel/buret families | Selected 50 |
| Water trough | Selected 1000 |
| Stand variants | Selected zero or one |
| Lamp | Zero; native cap flag initially one |
| Glass rods and wood object | Zero |

The module supports 33 standard choices represented in `data/original_factory_templates.json`. Each template records its actual native kernel entry address and binary identity.

## Probe and validation boundary

`tools/original_factory_oracle.py` executes the actual base initializer and each actual metadata-writing creation branch from its first type-field write until the original live count increments. It hosts explicit VCL bitmap/list/region/raster services, using actual recovered BMP header dimensions. Rectangle construction, subtype conditions, scalar writes, coordinate writes, and geometry calculations inside these kernels execute original PE instructions.

Original managed strings are constructed as required; all unrelated numeric storage is seeded nonzero to distinguish initialized from uninitialized fields. The reference position `(333,222)`, alive field one and `容器0` label are explicit inputs corresponding to original preparatory writes preceding the kernel entry; the original palette counter/prefix logic is traced statically, not presented as executed by this bounded kernel probe.

`tests/test_original_factory.gd` verifies all forty metadata fields, original bitmap dimensions, empty chemical/reaction state, unknown numeric caches, and coordinate/counter specialization for all **33 completed native kernels**. The test returns failure on any mismatch. These results do not establish complete Win32 mouse-handler, GDI region, raster painting, file-picker, or whole-application equivalence.
