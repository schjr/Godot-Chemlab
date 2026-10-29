# Reconstructed encyclopedia

`scripts/encyclopedia_view.gd` provides `EncyclopediaView extends Control`.
Add it to a parent layout and assign full anchors. It loads
`res://data/encyclopedia.json` automatically, or accepts an alternate prepared
table array through `set_tables(data)`.
If a validated local catalog exists at `user://encyclopedia.json`, it is
loaded at startup. The packaged `res://data/encyclopedia.json` remains the
source baseline and is never overwritten by the editor.

The reader contains all seven recovered database tables and all 475 records:
83 chemicals, 22 chemists, 153 concepts, 103 detailed element articles,
112 periodic-element entries, one library index and one DIY resource root.
The category tree includes the two administrative records so nothing is
silently discarded. Article rendering includes every nonempty field with
Chinese field labels. Element articles join their matching detailed history
by `elenum`; original database spelling, historical names and scientific
values remain unchanged.

The periodic table positions the recovered 112 elements in seven periods,
with separate lanthanide and actinide rows. It preserves historical symbols
such as Uub and does not add newer elements absent from the source. Clicking
an element opens its properties and available detailed article. The table
scrolls horizontally if the application window is narrow.

Toolbar categories follow recovered `forms/_ency/TMAINFORM.dfm`: periodic
elements, chemicals, concepts, chemists and user DIY. Gray Godot controls
inherit the host application's classic theme. A left category tree and
right reading panel provide the original application's lookup and document
reading workflow. Full-text Unicode search covers every field, including
names, formulas, biographies and descriptive text; Latin matching ignores
case. Search results honor the selected toolbar category. Choose
“全部资料” to search across all tables. “上一条” and “下一条” navigate the
current results. Articles support selection, copying, and UTF-8 text export.

“编辑资料”, “新增资料”, “删除资料”, and “保存资料库” restore local catalog
editing. A scrollable dialog exposes every original database column under
its Chinese field label. Longer descriptions use taller plain-text fields.
New records use the selected toolbar category, or default to user DIY when
“全部资料” is selected. DIY creation generates a unique eight-digit resource
ID and attaches the new note to the root resource. Deletion requires a
confirmation. Saving preserves the modified catalog between launches.

Every mutation validates the original seven table names and column schemas,
text field types, nonempty unique primary names/IDs and valid element numbers.
Rejected mutations leave the catalog untouched. Element properties can be
edited; adding/deleting periodic-table elements is disabled to preserve all
112 original grid entries. Detailed element articles can be added or deleted
independently. Other table records support creation, editing and deletion.

## Public API

| API | Description |
| --- | --- |
| `set_tables(Array)` | Replace the prepared data and rebuild search/periodic indices |
| `search_records(query, category="")` | Return matching entry dictionaries; does not alter UI |
| `select_category(name)` | Filter by prepared table name; empty means all tables |
| `refresh_search(query)` | Rebuild visible category tree and match count |
| `open_record(table_index, record_index)` | Show one record; returns false for invalid indices |
| `article_text(table_index, record_index)` | Return full readable text, including joined element details |
| `get_current_article()` | Return title plus the current article's full text |
| `periodic_position(atomic_number)` | Return the periodic grid coordinates |
| `create_record(table_index, record)` | Add a validated complete record |
| `update_record(table_index, record_index, record)` | Replace a validated record |
| `delete_record(table_index, record_index)` | Remove a record, excluding fixed periodic entries |
| `validate_catalog(Array)` | Check original schemas, text fields, unique primary keys and element range |
| `save_catalog(path="user://encyclopedia.json")` | Save the modified JSON catalog; reject packaged resource paths |
| `load_catalog(path="user://encyclopedia.json")` | Load a validated catalog without mutating data on failure |
| `request_status(message)` | Signal for the application's status bar |

`tables`, `entries`, `filtered_entries`, `current_entry` and
`periodic_buttons` are inspectable. An entry identifies its source through
`table_index`, `record_index`, `table`, and `title`. Periodic grid columns
are groups 1–18; rows 1–7 are periods, rows 9–10 are f-block series.

## Verification and boundaries

`tests/test_encyclopedia.gd` reads every one of the 475 records, verifies that
all nonempty source fields occur in its readable article, checks category
counts, Unicode/formula/full-text matching, Latin case folding, all 112
unique periodic positions, detailed-element joins, navigation and invalid
indices. CRUD tests exercise new concepts and DIY notes, edits, deletion,
duplicate/schema rejection, periodic entry preservation, packaged-source
protection and a catalog save/load roundtrip in a temporary file. Tests do
not write or overwrite the real saved user catalog. They pass under Godot 4.7.1.

```sh
Godot --headless --path godot --log-file /private/tmp/chemlab-encyclopedia-test.log --script res://tests/test_encyclopedia.gd
```

This reader uses recovered database content and DFM feature structure. It
does not reproduce the original HTML browser's precise formatting. HTML was
stripped during data preparation; this view renders and edits native text.
That conversion affects presentation, not retention of the recovered original
database files and raw artifacts elsewhere in the recovery package. Editing
creates a separate JSON catalog, rather than rewriting the legacy MDB files.
Remote-server login, printer setup and browser integration are not implemented
by this view. Source entries are historical content, retained without silently
updating their facts until the user explicitly edits them.
