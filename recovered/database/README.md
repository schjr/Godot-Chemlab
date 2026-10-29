# Recovered ChemLab database

`CHEMS.CSB` is a Microsoft Jet 4 / Access 2000 (`V2000`) database, despite its
custom extension. This recovery reads the original file without modifying it.
The password supplied in `artifacts/ChemLab/逆向说明.txt` matches the database
header. The credential is not embedded in recovered code or exported data.

## Observed contents

| Original table | Rows | Contents observed in its records |
| --- | ---: | --- |
| `chemicals` | 83 | Chemical names, formula HTML, popular names, descriptive HTML |
| `chemics` | 22 | Chemist names, foreign names, nationality, biography HTML |
| `concepts` | 153 | Chemistry concept names and descriptions |
| `eleinfo` | 103 | Discovery, naming, description, sources, uses, extended HTML by element number |
| `elements` | 112 | Element number/symbol/name, weight, type, English name, abundance, melting/boiling numeric values |
| `idlib` | 1 | A `diyid` counter value |
| `resdiy` | 1 | Root record for the user DIY resource hierarchy |

All 475 user-table records were exported. Each exported table's row count agrees
with its Jet table metadata. No saved queries or declared relationships were
found. That does not establish the absence of relationships maintained by
application code. System table names are preserved in `schema.json`; internal
Access system-table rows are outside this content export.

## Files

- `schema.json`: original Access types, lengths, auto-number flags, primary keys,
  indexes, row counts and table-to-file mapping.
- `tables/00.json` through `tables/06.json`: row data, preserving Unicode, HTML,
  nulls, empty strings, and numeric values.
- `chemlab.sqlite3`: portable reconstructed database, ready for read-only queries.
- `schema.sqlite.sql`: the SQLite schema used by the reconstruction.
- `manifest.json`: source fingerprint, artifact checksums, row counts and
  round-trip validation status.

The SQLite conversion uses ordinary SQLite collations. It does not reproduce
Jet's Chinese sort-order ID 2052, Access query semantics, or auto-number behavior.
The source reader warned that its Chinese text indexes are unsupported for
writes; recovery used sequential reads, so every row was still exported. Original
index definitions remain in `schema.json`. This is recovery of data and schema,
not recovery of the software author's original database-access source code.

## Reproduce

Requirements: Java 11 or newer and `uv`. From the repository root:

```sh
UV_CACHE_DIR=/private/tmp/chemlab-uv-cache uv run --no-project tools/database_recover.py --fetch-dependencies
```

The wrapper downloads only pinned, checksum-verified Maven reader libraries into
`/private/tmp/chemlab-db-libs`; omit `--fetch-dependencies` once they are cached.
It invokes `tools/DatabaseRecover.java` in read-only mode, checks the source hash
before and after export, validates all row counts, compares every SQLite value to
its JSON counterpart and runs SQLite's integrity check. Password parsing supports
the supplied UTF-8 note's `密码：...` line; it never logs the value. The original
ChemLab executable is not run.
