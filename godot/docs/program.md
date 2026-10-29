# Reconstructed variables and event programs

`LabProgram extends RefCounted` reconnects the recovered experiment's live
variables, annotation placeholders, arithmetic assignments and event-program
control vocabulary to `LabModel`. It is a new interpreter, not the recovered
native interpreter compiled unchanged.

## API and frame order

```gdscript
var program := LabProgram.new()
program.configure(model)
program.bind_variable("water_g", vessel_id, "H2O(液体)", "mass")
program.bind_variable("h_mol", vessel_id, "H+(离子)", "moles")
program.code = "ph1=-log10(1000*h_mol/water_g)"
var errors := program.evaluate_frame()
var annotation := program.expand("PH = {ph1}")
```

Call `evaluate_frame()` after each simulation step and before drawing live
labels or recording chart samples. Bindings are read first; then program lines
execute in order. The public `variables` dictionary contains resulting scalar
values. `t` is refreshed from model elapsed seconds. Each binding is
`{name, vessel_id, species, metric}`. Metrics are `moles`, `mass` (grams via
recovered molar mass), `temperature`, `pH` and `time`. Temperature and pH use
the vessel state and reconstructed model's pH calculation.

`set_variable(name, value)` sets a finite scalar. `bind_variable(name,
vessel_id, species="", metric="moles")` adds or replaces a live binding.
`expand(text)` interpolates exact brace names, including source names such
as `{Ca(HCO3)2}`. Unknown placeholders remain visible and add an error.
`to_state()` and `from_state()` persist variables, bindings and program text.
The caller saves this dictionary alongside the model state. Program bindings
read model state; assignments update variables rather than modifying vessel
chemistry.

## Supported language

Assignments use `name=expression`; optional trailing semicolons are accepted.
All numeric literals and variable values use floating-point arithmetic.
The original editor's entire mathematical list is supported: `cos`, `arccos`,
`sin`, `arcsin`, `tan`, `arctan`, `exp`, `fabs`, `log`, `log10`, `sqrt`,
`pow` and `signum`. Trigonometric arguments are radians; `log` is natural
logarithm. `acos/asin/atan`, `abs/sign`, and `min/max` are additional aliases.
Arithmetic, comparisons and `and/or/not` are supported. A single equality
sign in a condition means equality; original `<>` means inequality.

The recovered editor's exact control templates are supported, including
nested blocks and matching numeric IDs:

```text
i=0
sum=0
循环1:当(i<5)成立
判断2:如果(i<>2)则执行
sum=sum+i
结束判断2
i=i+1
结束循环1
```

Additional convenient aliases are `if expression [then]`, `while expression`,
`endif`, `endwhile`, and `end`. These aliases are new compatibility choices,
not a claim that the old app accepted English keywords. Lines starting with
`//` or `#` are comments. `else`, `for`, external code, object access and
arbitrary method calls are unsupported and produce visible errors.

Original internal command names are recognized: `简单发声`, `播放声音(path)`,
`打开(path-or-url)`, `重新运行`, `暂停`, `停止`, and `退出`. All emit
`command_requested(command, arguments)` for the application's host to handle.
Pause and stop additionally clear `model.running`. Pause, stop, restart and
exit end the current program evaluation. File/URL opening, sound, reset and
app exit must be connected by the host; the interpreter itself does not open
arbitrary files or execute system commands.

`evaluate_frame()` returns an array of readable errors. Syntax and block
structure are checked before any statement runs. Execution stops on the first
expression failure. Unknown commands, missing variables/vessels/species,
nonfinite results, unclosed/mismatched blocks and loops exceeding 1,024
instructions per frame are reported. Expressions accept only scalar tokens
and the listed mathematical functions before reaching Godot's Expression
engine; no object instance is exposed to evaluated expressions.

## Original evidence and import mapping

The original `forms/_main/TGCFORM.dfm` declares the event editor, judgment and
loop insertion buttons, the 13 mathematical function names and seven internal
commands. `native/main/published_recovered.cpp` handlers at `0x004B0E8C`
and `0x004B0F48` insert three-line control templates; math and command insertion
handlers are at `0x004B1098` and `0x004B1154`.

The template strings occur directly in the shipped `artifacts/ChemLab/_main.exe`:
`判断1:如果(    )则执行` at VA `0x0056E3E8` (file `0x16D3E8`),
`结束判断1` at VA `0x0056E416`,
`循环1:当(     )成立` at VA `0x0056E420`, and
`结束循环1` at VA `0x0056E448`. These are static resource observations.

Prepared `.cem` examples preserve the original arithmetic programs:
“强酸与弱酸的电离” contains `ph1=-log10(1000*h1/a1)` and equivalent
ph2/ph3 assignments; “酸碱中和滴定” uses
`ph1=-log10(1000.0*b1/a1)`; “硬水的软化” contains `a_all=a+a1`.
Original dynamic labels include `PH = {ph1}`, `{fe_mol}` and
`Ca(HCO3)2:{Ca(HCO3)2} mol`.

The observed `.cem` variable section begins at `trailing_lines[0]` with its
record count; line 1 is a preserved global/reserved field. Each seven-line
record begins at `2 + 7 * index` and contains type, another flag, name,
description, current value, initial value, and another flag. The first record
is normally `0,0,t,时间变量,0,0,0`. The exact meanings of both additional flags
remain unresolved. Preserve them rather than guessing their behavior.

Chemical records already contain explicit `moles_variable` and
`mass_variable` names. Bind those names to their containing imported vessel
and chemical species. Use the app's newly assigned unique vessel ID rather
than original `.cem` apparatus IDs, which can repeat. App import should map
the original apparatus name to the imported vessel label. Numeric program
variables can retain their saved current/initial values until changed by the
program. Original event serialization contains additional fields and event
types; the host owns selection and timing of each event program.

## Verification and limitations

`tests/test_program.gd` passes under Godot 4.7.1. It verifies recovered pH
formulas, live mass/moles/time bindings, floating-point literal division, math
functions, nested original Chinese control syntax, chemical-formula names,
annotation interpolation, bounded infinite loops, visible unknown commands,
rejected object expressions, invalid numerical domains, pause and persistence.

```sh
Godot --headless --path godot --log-file /private/tmp/chemlab-program-test.log --script res://tests/test_program.gd
```

The native parser's full edge-case grammar, original event scheduling,
variable flag semantics and numerical-domain policies have not been recovered
completely. Infinite loops and invalid numeric domains are explicitly bounded
or rejected by this port. Exact original interpreter equivalence is not claimed.
