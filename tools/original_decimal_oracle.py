"""Original extended decimal parser and its distinct qword-store wrapper.

Use the uv-managed workspace environment. The original PE is not launched;
AnsiString ownership/exception bookkeeping remain declared oracle boundaries.
"""
import json
import struct
from original_program_oracle import ProgramOracle, ROOT, EXPECTED
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_FP0, UC_X86_REG_FPSW

VALUES = ["9007199254740993", "123456789012345678", "1.23456789012345678",
          "0.009007199254740993", "999999999999999999", "-99999999999999999",
          "3.14159265358979323", "123456789012345675"]

def result_bytes(oracle):
    top = (oracle.uc.reg_read(UC_X86_REG_FPSW) >> 11) & 7
    significand, exponent = oracle.uc.reg_read(UC_X86_REG_FP0 + top)
    return struct.pack("<QH", significand, exponent).hex()

def main():
    cases = []
    for text in VALUES:
        wrapper = ProgramOracle()
        holder = wrapper.alloc(4)
        wrapper.u32(holder, wrapper.string(text))
        wrapper.uc.reg_write(UC_X86_REG_EAX, holder)
        wrapper.call(0x541348, b"")
        extended = ProgramOracle()
        extended.uc.reg_write(UC_X86_REG_EAX, extended.string(text))
        extended.call(0x52C700, b"")
        cases.append({"text": text, "extended_bits": result_bytes(wrapper),
                      "operand_extended_bits": result_bytes(extended)})
    output = {"binary_sha256": EXPECTED, "entry": "00541348",
              "extended_parser_entry": "0052C700", "cases": cases,
              "boundary": "Original parser instructions execute; AnsiString ownership is hosted. Wrapper541348 performs the original qword store before returning."}
    path = ROOT / "godot/tests/fixtures/original_decimal.json"
    path.write_text(json.dumps(output, indent=2) + "\n")
    print(f"Captured {len(cases)} original decimal operands and qword wrappers")

if __name__ == "__main__":
    main()
