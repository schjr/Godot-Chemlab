# Reconstructed molecular viewer

`scripts/molecule_view.gd` defines `MoleculeView`, a Godot 4 `Control` with an
owned 3D subviewport. It can be added to any Godot UI layout and fills its
assigned rectangle. Coordinates and bond topology come from the converted
original molecular models; rendering uses new Godot meshes, materials and
lights, rather than the recovered OpenGL implementation.

## Data and public methods

`set_molecule(data)` accepts a dictionary containing:

```json
{"atoms":[{"element":"O","position":[0,0,0]},{"element":"H","position":[0.96,0,0]}],
 "bonds":[{"a":0,"b":1,"order":1}]}
```

Indices are zero-based. Positions may also be Godot `Vector3` values, `pos`
values, or separate `x`, `y`, `z` fields. Atom dictionaries may retain any
additional source metadata. Input is copied; edits are available in the public
`molecule` dictionary. Coordinates are expected in angstroms. Prepared original
editor models convert their graphics coordinate units by dividing by ten;
original coordinates remain in their source metadata.

| Method | Purpose |
| --- | --- |
| `set_display_mode(mode)` | `ball-stick`, `space-fill`, `wireframe`, `labels`, or `labels-3d` |
| `set_auto_rotate(enabled, axis=Vector3.UP)` | Continuous rotation about any axis |
| `set_rotation_axis("X"/"Y"/"Z")` | Start the original toolbar's axis rotation |
| `reset_view()` | Stop rotation and restore orientation and framing |
| `zoom(factor)` | Values below one enlarge the molecule |
| `select_atom(index)` | Select and highlight an atom; `-1` clears selection |
| `set_background_color(color)` | Set background color |
| `set_lighting(ambient, light_color, direction)` | Set ambient and directional light colors; direction is Euler degrees |
| `set_element_color(symbol, color)` | Change a chemical element's appearance |
| `set_labels_visible(enabled)` | Show element symbols in other modes |
| `set_line_width(radius)` | Change framework bond thickness |
| `get_image()` | Read the current viewport image for PNG export |
| `add_atom(atom)` | Append an atom and return its index |
| `set_atom_position(index, Vector3)` | Change its coordinates |
| `delete_atom(index)` | Remove atom and attached bonds; remap remaining bond indices |
| `add_bond(a, b, order=1)` | Add a bond; refuse invalid indices, loops and duplicates |
| `delete_bond(index)` | Remove a bond |
| `rotate_bond(index, angle_degrees)` | Rotate the component on the B side of a single bond; refuse rings and multiple bonds |

`atom_selected(index, atom)` and `bond_selected(index, bond)` signals connect
selection to property panels and editing tools. These are graph operations;
chemical valence rules and the original functional-group templates belong to
the app's editor layer. The renderer itself does not invent bonds or atoms.

## Interaction

Drag the left mouse button to orbit. Click an atom or bond to select it;
selection turns white. The mouse wheel or A/S keys zoom. Arrow keys rotate,
Space stops automatic rotation and Home restores the initial view. Multiple
bond orders display parallel cylinders. Proportion/space-fill mode uses common
van der Waals radii; framework and symbol modes preserve the explicit bond
graph.

## Evidence and boundaries

Recovered `forms/_mol/TFORM1.dfm` declares mouse drag, wheel, key and toolbar
handlers, the display-mode menus and X/Y/Z rotation controls. The original
`chemistry/help_text/帮助/菜单及功能介绍.txt`, `工具栏.txt` and
`有机分子的搭建.txt` explain sphere/cylinder, proportional, wireframe and
flat/3D symbol modes, element/background/light colors, selection, and single
bond conformation rotation. Those resources establish the feature mapping.

The initial black background, element palette, modern sphere tessellation,
lighting intensities and camera framing are reconstruction choices. This is
not a pixel-identical recreation or execution of the recovered renderer.
The 3D symbol mode uses Godot's planar `Label3D` with fixed orientation; it does
not recreate extruded legacy font geometry. AVI/GIF recording, VRML export,
legacy printing and executable generation are outside this renderer.

## Verification

`tests/test_molecule.gd` exercises preserved distances, all five modes,
rendered atom and bond counts, selection, rotation/zoom/reset, atom deletion
and bond index remapping, valid conformation rotation, ring rejection,
invalid indices and an empty model. It passes with installed Godot 4.7.1.

```sh
Godot --headless --path godot --log-file /private/tmp/chemlab-molecule-test.log --script res://tests/test_molecule.gd
```

Use the actual Godot executable path on your system. The explicit log path
allows headless execution in a filesystem sandbox whose default Godot
application-data folder is not writable.
