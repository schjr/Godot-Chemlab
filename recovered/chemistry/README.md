# ChemLab chemistry and experiment data recovery

This directory contains recovered **original data** and a newly written, evidence-based Python reader. It is not the lost original C++/Delphi implementation and does not implement the application's simulation engine.

## Contents

- `original/`: exact copies of the chemistry libraries, explanatory file, HTML help, 28 experiments, 46 molecular models, and DEFAULT.ETS.
- `utf8/`: complete, losslessly decoded UTF-8 text with original CRLF and blank lines preserved. Original Chinese text is not translated or normalized.
- `reactions.json`: 599 records, IDs 方程式0–方程式598; decoded raw text, original line numbers, and documented fields.
- `reagents.json`: 499 records; all twelve positional strings and separately labelled inferred names. Do not treat the guessed serialized order as an established original source schema.
- `models/`: all 28 `.cem` and 46 `.cl3` files as numbered lines, headers, and source hashes. These are faithful text exports, not guessed deserializations into apparatus or molecule objects.
- `help_text/`: readable Chinese text extracted from 20 HTML documents. The UTF-8 HTML and original bytes are also preserved separately.
- `DEFAULT.embedded.bmp`: the complete 610 × 410, 16-bit BMP extracted exactly from offset 28 in DEFAULT.ETS. Seven preceding little-endian DWORDs are `[28,34,41,15,16,10,10]`; their meanings remain unresolved.
- `manifest.json`: byte counts, encoding choices, source SHA-256, and export paths.
- `summary.json`: record counts and category distributions.

## Reader and verification

Run from the workspace root using the shared uv-managed environment:

```sh
uv run python tools/chemistry_recover.py --check
```

The standalone reader uses only Python's standard library. `read_reactions(path)` and `read_reagents(path)` are importable. It validates record delimiters and reaction coefficient counts without changing original numeric spelling. `raw_text` and exact originals remain available alongside parsed values.

Verification passed for all 599/499 library records, continuous reaction IDs, a known silver/fluorine record, the water-ionization record and note, exact library delimiter/blank-line reconstruction, SHA-256 of every original copy, re-encoding of every UTF-8 export to its exact source bytes, and extraction of the entire BMP tail.

## Evidence and limits

`res/allfcs说明.txt` describes reaction ID, reactant and product counts, the combined species list, the matching coefficient list, heat, condition, rate, equilibrium degree/constant, equilibrium mode, equation type, and optional note. It is UTF-8; the libraries, legacy HTML, `.cem`, and `.cl3` files decode losslessly as GB18030. The recovered directory retains the explanation exactly as supplied; its authorship/date is not established.

There are 461 普通, 136 离子, and 2 扩展 reaction records; 575 单向 and 24 可逆 records. All species referenced by reaction records exist in reagent position 2. Equation 197 stores its note 水的电离 after two empty trailing lines. All trailing lines are preserved, since the explanatory text does not explain the meaning of each trailing slot.

`help/fcs_edit.htm` documents reaction rate as moles per second for a species with coefficient 1; coefficients scale that rate. It also says reaction heat has not yet been included in calculations. This is a historical documentation statement, not independent verification of machine-code behavior. It documents conditions 加热, 加强热, 温度>X, and 温度<X, single-direction/reversible modes, and ordinary/ionic/extended types. The recovered reader does not infer numerical equilibrium rules or temperature conversion from these descriptions.

`help/fanying.htm` describes evaluation of existing container equations and, when smart processing is selected, the addition of equations found from current chemicals and conditions. The exact search, integration, ordering, transport, and equilibrium algorithms are not supplied by the text and are not reimplemented here.

`help/yp_edit.htm` documents names, valence, solubility at 20 °C, and colors as editable properties, but gives no serialized field order. Reagent names such as molar mass, charge/valence, category, color, and solubility are therefore explicitly inferred. Positions 9 and 10 are always `100` and `1000`; their meanings are unknown. Position 8 appears to combine density-like values for gases/liquids and small integer values for solids; it is not claimed to be a uniform density field. One indicator category contains a trailing space, and three indicator records exist despite the help's five-class description. No trimming or silent correction is performed.

Every `.cem` begins `仿真化学实验室 金华科 V3.0`. Every `.cl3` begins the three lines `2107`, `1`, and `南京金华科软件有限公司仿真化学实验室-三维结构`. Those repeated prefixes are observed signatures; `2107` and `1` are not assigned invented version or count meanings. The line exports preserve the evidence needed for later machine-code-assisted format recovery.
