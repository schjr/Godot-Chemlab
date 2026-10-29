"""Actual 0x0046B858 arithmetic with explicit original string/lookup boundaries."""
import json
import struct

from original_x86_oracle import OriginalOracle, EXPECTED, ROOT
from original_oneway_oracle import ReactionOracle
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EDX, UC_X86_REG_ECX, UC_X86_REG_ESP


class SolubilityOracle(OriginalOracle):
    def __init__(self):
        super().__init__()
        for index, record in enumerate(self.catalog):
            self.f64(self.u32(0x57BC08 + index * 4) + 0x50, float(record["raw_fields"][11]))
        self.hooks[0x452C3C] = self.base_species
        self.hooks[0x541040] = self.concatenate
        self.hooks[0x452D9C] = self.find_reagent

    def base_species(self):
        sp = self.uc.reg_read(UC_X86_REG_ESP)
        destination = self.u32(sp + 4)
        name = self.bytes_at(self.u32(sp + 8))
        opening = name.rfind(b"(")
        self.u32(destination, self.string(name[:opening] if opening > 0 else b""))
        self.ret(destination)

    def concatenate(self):
        left = self.u32(self.uc.reg_read(UC_X86_REG_EAX))
        right = self.u32(self.uc.reg_read(UC_X86_REG_EDX))
        destination = self.uc.reg_read(UC_X86_REG_ECX)
        self.u32(destination, self.string(self.bytes_at(left) + self.bytes_at(right)))
        self.ret(destination)

    def find_reagent(self):
        sp = self.uc.reg_read(UC_X86_REG_ESP)
        name = self.text_at(self.u32(sp + 4))
        self.ret(self.reagent_indices.get(name, -1))

    def solubility_snapshot(self, index):
        result = self.snapshot(index)
        pointer = self.vessels[index]
        for label, offset in [("solid_3cd8", 0x3CD8), ("solid_3ff8", 0x3FF8)]:
            result[label] = {self.text_at(self.u32(pointer + 0x108 + slot * 4)): self.f64(pointer + offset + slot * 8) for slot in range(self.u32(pointer + 0x104))}
        return result

class DriverOracle(SolubilityOracle, ReactionOracle):
    pass


def encode_bits(value):
    if isinstance(value, dict):
        return {key: encode_bits(item) for key, item in value.items()}
    return struct.pack("<d", value).hex()


def main():
    records = json.loads((ROOT / "godot/data/reagents.json").read_text())
    by_name = {record["species"]: record for record in records}
    bases = ["NaCl", "KCl", "KNO3", "NaNO3", "AgCl", "AgBr", "AgI", "Ag2SO4", "Ca(OH)2", "Ba(OH)2", "CuSO4", "FeCl3", "NaOH", "KOH", "Na2CO3", "NaHCO3", "NH4Cl", "NH4NO3", "CaCl2", "HCl", "HBr"]
    specifications = []
    for base in bases:
        dissolved = base + "(溶解)"
        physical = base + "(固体)" if base + "(固体)" in by_name else base + "(气体)"
        if dissolved not in by_name or physical not in by_name: continue
        for kind in ["dissolve_new_slot", "precipitate_new_slot", "paired_slots"]:
            contents = {"H2O(液体)": 5.550621669627}
            if kind == "dissolve_new_slot": contents[physical] = 1.0
            elif kind == "precipitate_new_slot": contents[dissolved] = 2.0
            else:
                contents[physical] = 0.2
                contents[dissolved] = 0.3
            specifications.append({"name": base + ":" + kind, "contents": contents, "delta_seconds": 0.1, "temperature": 20.0, "volume_ml": 100.0})
    specifications.extend([
        {"name": "no_water_solute", "contents": {"NaCl(溶解)": 1.0}, "delta_seconds": 0.1, "temperature": 20.0, "volume_ml": 100.0},
        {"name": "insoluble_hydroxides", "contents": {"H2O(液体)": 5.550621669627, "Cu(OH)2(固体)": 0.01, "Fe(OH)3(固体)": 0.01}, "delta_seconds": 0.1, "temperature": 20.0, "volume_ml": 100.0},
        {"name": "cold_expression_is_not_used", "contents": {"H2O(液体)": 5.550621669627, "NaCl(固体)": 1.0}, "delta_seconds": 0.1, "temperature": 20.0, "volume_ml": 100.0},
        {"name": "hot_expression_is_not_used", "contents": {"H2O(液体)": 5.550621669627, "NaCl(固体)": 1.0}, "delta_seconds": 0.1, "temperature": 100.0, "volume_ml": 100.0},
        {"name": "zero_delta_new_slot", "contents": {"H2O(液体)": 5.550621669627, "NaCl(固体)": 1.0}, "delta_seconds": 0.0, "temperature": 20.0, "volume_ml": 100.0},
        {"name": "dissolve_all_available", "contents": {"H2O(液体)": 5.550621669627, "NaCl(固体)": 0.0001}, "delta_seconds": 0.1, "temperature": 20.0, "volume_ml": 100.0},
    ])
    oracle = None
    cases = []
    for case_index, specification in enumerate(specifications):
        if case_index % 10 == 0: oracle = SolubilityOracle()
        vessel = oracle.add_vessel(specification["contents"], temperature=specification["temperature"], capacity=specification["volume_ml"])
        before = oracle.solubility_snapshot(vessel)
        oracle.f64(0x5636D4, specification["delta_seconds"])
        oracle.call(0x46B858, struct.pack("<I", vessel))
        after = oracle.solubility_snapshot(vessel)
        cases.append({"name": specification["name"], "delta_bits": struct.pack("<d", specification["delta_seconds"]).hex(), "before": before, "before_bits": encode_bits(before), "after": after, "after_bits": encode_bits(after)})
    driver_cases = []
    examples = json.loads((ROOT / "godot/data/examples.json").read_text())
    opening = next(example for example in examples if example["name"] == "氢氧化铜与氢氧化铁")
    neutralization = next(reaction for reaction in opening["apparatus"][0]["reactions"] if reaction["name"] == "方程式171")
    for flag in [0, 1, 2]:
        oracle = DriverOracle()
        contents = {"H2O(液体)": 5.550621669627, "NaOH(固体)": 0.02, "NaOH(溶解)": 0.0, "HCl(溶解)": 0.001, "NaCl(溶解)": 0.0}
        vessel = oracle.add_vessel(contents, capacity=100.0)
        pointer = oracle.vessels[vessel]
        oracle.u32(pointer + 0xA4, 0)
        oracle.u32(pointer + 0x3C74, flag)
        oracle.u32(pointer + 0x3C78, 10)
        oracle.f64(pointer + 0x30, 20.0)
        oracle.f64(0x5636D4, 0.1)
        oracle.add_reaction(vessel, neutralization)
        before = oracle.solubility_snapshot(vessel)
        oracle.call(0x46C84C, struct.pack("<I", vessel))
        after = oracle.solubility_snapshot(vessel)
        driver_cases.append({"name": "original_driver_solubility_flag_" + str(flag), "flag": flag, "reaction": neutralization, "delta_bits": struct.pack("<d", 0.1).hex(), "before_bits": encode_bits(before), "after_bits": encode_bits(after), "gas_3cc0_bits": struct.pack("<d", oracle.f64(pointer + 0x3CC0)).hex()})
    output = {"provenance": {"binary_sha256": EXPECTED, "entry": "0x0046B858", "driver_entry": "0x0046C84C", "method": "Actual original PE solubility arithmetic and control flow, x87 PC=64; hosted AnsiString helpers, exact phase/base name extraction, concatenation and original species/reagent lookup boundaries.", "scalar_input": "Reagent +0x50 initialized from original positional field12. Original +0x48 temperature expression is not accessed by this routine."}, "reagent_operand_bits": {record["species"]: {"molar_mass": struct.pack("<d", float(record["molar_mass"])).hex(), "solubility_at_20_C": struct.pack("<d", float(record["raw_fields"][11])).hex()} for record in records}, "cases": cases, "driver_cases": driver_cases}
    destination = ROOT / "godot/tests/fixtures/original_solubility.json"
    destination.write_text(json.dumps(output, ensure_ascii=False, indent=2) + "\n")
    print(f"Recorded {len(cases)} native solubility cases: {destination}")


if __name__ == "__main__": main()
