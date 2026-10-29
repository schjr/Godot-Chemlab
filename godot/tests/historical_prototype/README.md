# Historical prototype tests

These three scripts tested the removed prototype engine. They assert percentage transfer, invented pH/heating/equilibrium behavior and the Godot Expression fallback. Their source is preserved for history; they are not executable acceptance tests for the original-code port.

Current source-bound numerical acceptance is in `../test_original_*.gd`, including 140 all-example physical frames and the opening seven-action/63-tick workflow. These fixtures have explicit memory/host boundary profiles. They do not claim every end-to-end UI action is complete. UI/import/persistence tests must be maintained separately as the actual native modules are integrated.
