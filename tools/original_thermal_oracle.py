"""Bounded execution of shipped main.exe's temperature routine; no OS or import calls.

Run through uv with JIT memory permission on the Codex macOS sandbox. This maps the
user-provided PE and executes only 0x48E418 and its actual fabs helper at 0x5394D4.
It does not launch the Windows application or implement a replacement heat model.
"""
from __future__ import annotations

import hashlib
import json
from pathlib import Path
import random
import struct

from unicorn import Uc, UC_ARCH_X86, UC_MODE_32
from unicorn.x86_const import UC_X86_REG_ESP, UC_X86_REG_FPCW


class ThermalOracle:
    def __init__(self, binary: Path):
        self.binary = binary.read_bytes()
        pe = struct.unpack_from("<I", self.binary, 60)[0]
        optional = pe + 24
        base = struct.unpack_from("<I", self.binary, optional + 28)[0]
        size = struct.unpack_from("<I", self.binary, optional + 56)[0]
        section_headers = optional + struct.unpack_from("<H", self.binary, pe + 20)[0]
        self.uc = Uc(UC_ARCH_X86, UC_MODE_32)
        self.uc.mem_map(base, (size + 4095) & ~4095)
        for index in range(struct.unpack_from("<H", self.binary, pe + 6)[0]):
            _, _, virtual, raw_size, raw_pointer = struct.unpack_from(
                "<8sIIII", self.binary, section_headers + 40 * index
            )
            self.uc.mem_write(base + virtual, self.binary[raw_pointer : raw_pointer + raw_size])
        self.vessel = 0x10000000
        self.stack = 0x20000000
        self.halt = 0x30000000
        for address, length in [(self.vessel, 0x10000), (self.stack, 0x10000), (self.halt, 4096)]:
            self.uc.mem_map(address, length)
        self.integer(0x585850, self.vessel)
        self.integer(0x58779C, 1)

    def integer(self, address: int, value: int):
        self.uc.mem_write(address, struct.pack("<i", value))

    def number(self, address: int, value: float):
        self.uc.mem_write(address, struct.pack("<d", value))

    def run(self, fixture: dict) -> dict:
        self.integer(self.vessel + 8, fixture["type_id"])
        self.integer(self.vessel + 0xA0, fixture["native_heating"])
        self.integer(self.vessel + 0x3C78, fixture["native_rate_slider"])
        self.number(self.vessel + 0x88, fixture["temperature"])
        self.number(self.vessel + 0x4320, fixture["native_liquid_volume"])
        self.number(0x5636D4, fixture["delta_seconds"])
        self.uc.mem_write(self.stack + 0x8000, struct.pack("<I", self.halt))
        self.uc.reg_write(UC_X86_REG_ESP, self.stack + 0x8000)
        self.uc.reg_write(UC_X86_REG_FPCW, 0x37F)
        self.uc.emu_start(0x48E418, self.halt, count=100000)
        result = bytes(self.uc.mem_read(self.vessel + 0x88, 8))
        return {**fixture, "input_temperature_bits": struct.pack("<d", fixture["temperature"]).hex(), "input_liquid_volume_bits": struct.pack("<d", fixture["native_liquid_volume"]).hex(), "input_delta_bits": struct.pack("<d", fixture["delta_seconds"]).hex(), "expected_temperature": struct.unpack("<d", result)[0], "expected_temperature_bits": result.hex()}


def main():
    root = Path(__file__).resolve().parents[1]
    binary = root / "evidence/native-inputs/main.exe"
    oracle = ThermalOracle(binary)
    cases = []
    for slider in [-1, 0, *range(1, 20), 20]:
        for temperature, volume, heating, delta in [
            (20.0, 0.0, 1, 0.1),
            (20.0, 90.0, 1, 0.013),
            (50.0, 90.0, 0, 0.017),
            (20.0, 0.001, 1, 0.037),
        ]:
            cases.append({"type_id": 102, "temperature": temperature, "native_liquid_volume": volume, "native_heating": heating, "native_rate_slider": slider, "delta_seconds": delta})
    for type_id in [100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 120, 121, 122, 202, 302]:
        cases.append({"type_id": type_id, "temperature": 20.0, "native_liquid_volume": 0.0, "native_heating": 1, "native_rate_slider": 10, "delta_seconds": 0.1})
    for temperature, volume, heating in [(799.0, 0.0, 1), (99.0, 2.0, 1), (20.2, 2.0, 0), (30.0, 2.0, 2), (30.0, 2.0, -1), (100.0, 0.0010000000000001, 1)]:
        cases.append({"type_id": 102, "temperature": temperature, "native_liquid_volume": volume, "native_heating": heating, "native_rate_slider": 10, "delta_seconds": 0.1})
    # Deterministic finite operand coverage, independent of the Godot implementation.
    generator = random.Random(0x48E418)
    for _ in range(1000):
        cases.append({"type_id": generator.choice([101, 102, 103, 104, 105, 106, 108, 121]), "temperature": generator.uniform(20.0, 790.0), "native_liquid_volume": generator.choice([0.0, 0.001, 0.0010000000000001, 40.0]), "native_heating": generator.choice([0, 1, 2]), "native_rate_slider": generator.randrange(-3, 24), "delta_seconds": generator.randrange(6, 201) / 1000.0})
    output = {
        "provenance": {"binary": str(binary), "sha256": hashlib.sha256(oracle.binary).hexdigest(), "entry": "0x0048E418", "helper": "0x005394D4", "method": "Actual PE machine instructions executed in Unicorn 2.1.4 x86-32 with x87 control word 0x037F; single vessel; instruction bound 100000; no OS or imported function calls."},
        "cases": [oracle.run(case) for case in cases],
    }
    destination = root / "godot/tests/fixtures/original_thermal.json"
    destination.parent.mkdir(parents=True, exist_ok=True)
    destination.write_text(json.dumps(output, ensure_ascii=False, indent=2) + "\n")
    print(f"Recorded {len(output['cases'])} original thermal machine-code fixtures: {destination}")


if __name__ == "__main__":
    main()
