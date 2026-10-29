# Recovered declarations and method mappings

This directory contains evidence-based declaration skeletons and published method address mappings; it is not a complete buildable project.

Each `.hpp` skeleton preserves an observed root form class and the named component classes in its recovered DFM graph. Event bindings appear as comments. Original unit filenames, inheritance, method signatures, constructors, private state, field layout, and executable implementations are not recoverable from DFM resources alone, so no handler bodies or guessed event signatures are supplied. Component declarations are an inventory for reconstruction, not a claim about the original C++ class layout. C++ headers reflect the parent task's C++Builder evidence for the main applications; using a header as a declaration inventory does not establish the original language for every auxiliary binary.

`method_maps/*.tsv` provides corroborated executable addresses and published method names for the decompiler. The prefix `Published_` is synthetic. Adjacent JSON files preserve entry offsets, code offsets, binary hashes, and the form resources referencing each name. Name matches alone do not assign a method to a particular root class.

The exact original form payloads are in `../forms`; see that directory's manifest and README for verification and decoding limitations.
