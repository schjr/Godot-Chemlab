"""Record native 0x00461E54 quantities using the parent's bounded PE oracle."""
from pathlib import Path
import json
import random
import struct

from original_x86_oracle import OriginalOracle, EXPECTED, ROOT


def bit_values(values):
    if isinstance(values, dict):
        return {key: bit_values(value) for key, value in values.items()}
    return struct.pack("<d", values).hex()


def main():
    records = json.loads((ROOT / "godot/data/reagents.json").read_text())
    specifications = [
        {"contents": {}, "volume_ml": 100.0, "native_species_volume": {}},
        {"contents": {"H2O(液体)": 2.2202486678508, "NaOH(溶解)": 0.1, "Zn(固体)": 0.01, "CO2(气体)": 0.001}, "volume_ml": 100.0, "native_species_volume": {"NaOH(溶解)": 17.0}},
        {"contents": {"H2O(液体)": 8.3259325044405, "H+(离子)": 0.003, "OH-(离子)": 0.001, "甲基橙(指示剂)": 0.001, "O2(气体)": 1.0}, "volume_ml": 90.0, "native_species_volume": {"H+(离子)": 11.0, "OH-(离子)": 13.0, "甲基橙(指示剂)": 19.0}},
    ]
    specifications.extend({"contents": {record["species"]: 0.017}, "volume_ml": 100.0, "native_species_volume": {record["species"]: 23.0}} for record in records)
    generator = random.Random(0x461E54)
    for _ in range(200):
        chosen = generator.sample(records, 8)
        specifications.append({"contents": {record["species"]: generator.uniform(0.0, 0.17) for record in chosen}, "volume_ml": generator.uniform(1.0, 500.0), "native_species_volume": {record["species"]: generator.uniform(0.0, 30.0) for record in chosen}})
    oracle = None
    cases = []
    for index, specification in enumerate(specifications):
        if index % 30 == 0:
            oracle = OriginalOracle()
        vessel = oracle.add_vessel(specification["contents"], capacity=specification["volume_ml"], volume_cache=specification["native_species_volume"])
        snapshot = oracle.snapshot(vessel)
        snapshot.pop("temperature")
        cases.append({"input": specification, "input_bits": bit_values(specification), "expected": snapshot, "expected_bits": bit_values(snapshot)})
    output = {
        "provenance": {"binary_sha256": EXPECTED, "entry": "0x00461E54", "method": "Actual original PE arithmetic instructions executed by OriginalOracle/Unicorn 2.1.4; original x87 PC=64; explicitly initialized species-volume cache inputs.", "hosted_boundaries": ["AnsiString lifetime/copy/equality", "phase suffix extraction 0x00452ACC", "species/reagent lookup", "message presentation"], "limits": "No whole-application equivalence; the binary arithmetic is executed while listed non-arithmetic boundaries are hosted according to static instruction traces."},
        "reagent_operand_bits": {record["species"]: {"molar_mass": struct.pack("<d", float(record["molar_mass"])).hex(), "density_or_render_parameter": struct.pack("<d", float(record["raw_fields"][7])).hex()} for record in records},
        "cases": cases,
    }
    destination = ROOT / "godot/tests/fixtures/original_quantities.json"
    destination.parent.mkdir(parents=True, exist_ok=True)
    destination.write_text(json.dumps(output, ensure_ascii=False, indent=2) + "\n")
    print(f"Recorded {len(cases)} native quantities fixtures: {destination}")


if __name__ == "__main__":
    main()
