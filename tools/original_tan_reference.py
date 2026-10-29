"""Retain original 53AD24 instruction bytes and bounded Rosetta FPTAN returns."""
import hashlib
import json
import math
import random
import struct
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

def main():
    from original_x86_oracle import OriginalOracle, EXPECTED
    from capstone import Cs, CS_ARCH_X86, CS_MODE_32
    original = OriginalOracle()
    code = bytes(original.uc.mem_read(0x53ad24, 32))
    assembly = [{"address":hex(i.address), "bytes":i.bytes.hex(), "mnemonic":i.mnemonic, "operands":i.op_str} for i in Cs(CS_ARCH_X86, CS_MODE_32).disasm(code, 0x53ad24)]
    assert any(i["mnemonic"] == "fptan" for i in assembly)
    reference = Path("/private/tmp/chemlab-math-reference")
    rng = random.Random(0x53ad24)
    values = [0.0, -0.0, .1, -.1, math.pi/4, -math.pi/4, 1e-100, -1e-100, math.ulp(0.0), -math.ulp(0.0), math.nextafter(2.0**53, 0.0)]
    for pole in [math.pi/2, -math.pi/2, 3*math.pi/2]:
        values += [math.nextafter(pole, -math.inf), pole, math.nextafter(pole, math.inf)]
    values += [rng.uniform(-1000, 1000) for _ in range(160)]
    cases = []
    for value in values:
        stored, extended = subprocess.check_output([str(reference), "tan", repr(value)], text=True).strip().split()
        cases.append({"input_bits":struct.pack("<d", value).hex(), "stored_bits":stored, "extended_bits":extended})
    result = {"binary_sha256":EXPECTED, "entry":"0053AD24", "assembly":assembly,
        "reference":"Rosetta executes FPTAN; pop pushed 1.0; retain 80-bit result; PC64 nearest. Finite abs(input)<2^53 only.",
        "reference_sha256":hashlib.sha256(reference.read_bytes()).hexdigest(), "cases":cases}
    (ROOT/"godot/tests/fixtures/original_tan.json").write_text(json.dumps(result, indent=2)+"\n")
    print("Retained", len(cases), "FPTAN references")

if __name__ == "__main__":
    main()
