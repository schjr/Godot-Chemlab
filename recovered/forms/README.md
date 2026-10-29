# Recovered form resources

69 binary Delphi/VCL form resources were extracted from seven distinct PE binaries, including two files disguised as `data.obj`. Three translated executable filenames are exact duplicates of the corresponding underscore-prefixed executable. `manifest.json` records the aliases and SHA-256 digests.

Each form has three outputs:

- `.dfm.bin`: original resource bytes, unchanged.
- `.dfm`: decoded Delphi textual form description, retaining component names, classes, properties, nested components, graphic data, and event bindings.
- `.json`: structured decoded form plus original resource path, file offset, byte size, digest, published method candidates, and declaration skeleton path.

All 69 decoded forms consumed their resources exactly, with no trailing bytes or parse errors. Every saved binary was compared with its corresponding original executable slice and verified by SHA-256. There are 854 event bindings.

The source bytes are authoritative. Text DFM conversion interprets legacy narrow strings using GBK, with CP1252 fallback; this fits the Chinese interfaces, but an original code page cannot be proven from the stream alone. Wide and UTF-8 strings use their explicit encodings. Readable Unicode strings are expressed using Delphi character-code escapes. Floating-point textual values are decoded numeric equivalents; 80-bit extended values also retain their exact original hex encoding in JSON. The textual representation is intended for inspection and reconstruction and has not been validated by an original-era C++Builder/Delphi compiler.

Packed published-method entries validate method name, entry size, and code address in an executable PE section. These yield 786 distinct method addresses across seven binaries. Multiple classes can use the same handler name; the supplied candidates do not prove class ownership. `recovered/project/method_maps` provides TSV address/name mappings and separate JSON evidence. `Published_` prefixes are synthetic; the remaining identifier is the observed original published method name.

Reproduce with the existing uv-managed environment:

```sh
.venv/bin/python tools/forms_recover.py
```

The parser uses Python's standard library and does not require external packages.
