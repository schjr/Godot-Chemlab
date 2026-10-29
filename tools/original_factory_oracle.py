"""Record original scalar initializer and palette creation kernels.

The actual scalar creation branch is executed from its first native type write
until the live-array count increments. VCL bitmap/list/region object services
are explicitly hosted; this does not execute the entire Win32 mouse handler.
"""
import json
import struct
from pathlib import Path
import capstone
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EDX, UC_X86_REG_ECX, UC_X86_REG_EBP, UC_X86_REG_ESP
from original_x86_oracle import OriginalOracle, ROOT, EXPECTED

OFFSETS = [0, 4, 8, 12, 16, 20, 24, 32, 40, 48, 56, 60, 64, 68, 72, 76, 80, 84, 88, 92, 96, 100, 104, 108, 112, 116, 120, 124, 128, 132, 136, 144, 148, 152, 156, 160, 164, 168, 176, 184]
STRINGS = {4, 128, 144, 148, 152}
DOUBLES = {32, 40, 48, 136, 168, 176, 184}


class FactoryOracle(OriginalOracle):
    def __init__(self):
        super().__init__()
        self.started = False
        self.completed = False
        self.loaded_bitmaps = []
        self.hooks.update({0x4E8EDC: self.bitmap_constructor, 0x541040: self.concatenate, 0x499328: self.region_constructor, 0x49BBF8: self.region_constructor, 0x4EA4D4: self.noop, 0x4E9448: self.canvas_get, 0x4E4420: self.canvas_copy})
        for offset, callback in [(8, self.bitmap_copy), (0x20, self.bitmap_height), (0x2C, self.bitmap_width), (0x34, self.bitmap_set_height), (0x40, self.bitmap_set_width), (0x48, self.bitmap_load), (0x3C, self.noop)]:
            self.hooks[0x8000100 + offset] = callback
        self.uc.hook_add(UC_HOOK_CODE, self.stop_after_creation)
        self.bitmap_sizes = {}
        for path in (ROOT / "artifacts/ChemLab/res").iterdir():
            if path.suffix.lower() == ".bmp":
                raw = path.read_bytes()
                self.bitmap_sizes[path.name.lower()] = [abs(struct.unpack_from("<i", raw, 18)[0]), abs(struct.unpack_from("<i", raw, 22)[0])]

    def stop_after_creation(self, uc, address, size, unused):
        if self.started and self.u32(0x58779C) == 1:
            self.completed = True
            uc.emu_stop()

    def noop(self): self.ret(1)

    def canvas_get(self): self.ret(self.alloc(0x100))

    def canvas_copy(self):
        # Actual TCanvas.CopyRect has one 16-byte by-value destination rectangle.
        sp = self.uc.reg_read(UC_X86_REG_ESP)
        self.ret()
        self.uc.reg_write(UC_X86_REG_ESP, sp + 20)

    def concatenate(self):
        left = self.u32(self.uc.reg_read(UC_X86_REG_EAX))
        right = self.u32(self.uc.reg_read(UC_X86_REG_EDX))
        destination = self.uc.reg_read(UC_X86_REG_ECX)
        self.u32(destination, self.string(self.bytes_at(left) + self.bytes_at(right)))
        self.ret(destination)

    def bitmap_constructor(self):
        p = self.alloc(0x100)
        table = self.alloc(0x80)
        self.u32(p, table)
        for offset in [8, 0x20, 0x2C, 0x34, 0x40, 0x48, 0x3C]: self.u32(table + offset, 0x8000100 + offset)
        self.ret(p)

    def bitmap_height(self): self.ret(self.u32(self.uc.reg_read(UC_X86_REG_EAX) + 4))
    def bitmap_width(self): self.ret(self.u32(self.uc.reg_read(UC_X86_REG_EAX) + 8))

    def bitmap_set_height(self):
        p = self.uc.reg_read(UC_X86_REG_EAX)
        self.u32(p + 4, self.uc.reg_read(UC_X86_REG_EDX))
        self.ret()

    def bitmap_set_width(self):
        p = self.uc.reg_read(UC_X86_REG_EAX)
        self.u32(p + 8, self.uc.reg_read(UC_X86_REG_EDX))
        self.ret()

    def bitmap_load(self):
        p = self.uc.reg_read(UC_X86_REG_EAX)
        path = self.text_at(self.uc.reg_read(UC_X86_REG_EDX))
        name = path.replace("\\", "/").split("/")[-1].lower()
        if name not in self.bitmap_sizes: raise ValueError("Unresolved original bitmap: " + path)
        width, height = self.bitmap_sizes[name]
        self.u32(p + 4, height)
        self.u32(p + 8, width)
        self.loaded_bitmaps.append(name)
        self.ret()

    def bitmap_copy(self):
        target = self.uc.reg_read(UC_X86_REG_EAX)
        source = self.uc.reg_read(UC_X86_REG_EDX)
        self.u32(target + 4, self.u32(source + 4))
        self.u32(target + 8, self.u32(source + 8))
        self.ret()

    def region_constructor(self):
        # Windows region construction has no writes to the vessel metadata.
        # Its two by-value rectangle arguments are 16 bytes on this call path.
        sp = self.uc.reg_read(UC_X86_REG_ESP)
        self.ret(self.alloc(0x100))
        self.uc.reg_write(UC_X86_REG_ESP, sp + 20) # Actual 0x0049A4CB RET 0x10.

    def fields(self, pointer):
        result = {}
        for offset in OFFSETS:
            if offset in STRINGS: value = self.text_at(self.u32(pointer + offset))
            elif offset in DOUBLES: value = self.f64(pointer + offset)
            else:
                value = self.u32(pointer + offset)
                if value >= 0x80000000: value -= 0x100000000
            result[f"0x{offset:02x}"] = value
        return result

    def initialize(self):
        pointer = self.alloc(0x5000)
        self.uc.mem_write(pointer, bytes([0xA5]) * 0x4348)
        self.vessels = [pointer]
        self.u32(0x585850, pointer)
        for offset in STRINGS: self.u32(pointer + offset, 0)
        for array_offset in [0x108, 0xBF8, 0xD88]:
            for slot in range(100): self.u32(pointer + array_offset + slot * 4, 0)
        self.call(0x453A28, struct.pack("<I", 0))
        return pointer

    def create_kernel(self, address, type_id, parameter):
        pointer = self.initialize()
        self.u32(pointer, 1)
        self.u32(pointer + 4, self.string("容器0"))
        self.u32(0x58779C, 0)
        self.u32(0x57A724, type_id)
        self.u32(0x57A728, parameter)
        self.u32(0x57A6EC, self.string(""))
        self.u32(0x57A740, self.string(""))
        frame = 0x90FE800
        controller = self.alloc(0x7000)
        self.u32(frame + 8, 222)
        self.u32(frame + 12, 333)
        self.u32(frame - 0x3C8, controller)
        self.u32(frame - 0x3A8, 0)
        self.uc.reg_write(UC_X86_REG_EBP, frame)
        self.uc.reg_write(UC_X86_REG_ESP, frame - 0x980)
        self.started = True
        try: self.uc.emu_start(address, self.stop_address, count=2000000)
        except Exception as error:
            from unicorn.x86_const import UC_X86_REG_EIP
            raise RuntimeError(f"Creation kernel failed at {self.uc.reg_read(UC_X86_REG_EIP):#x}: {error}") from error
        if not self.completed: raise RuntimeError("Original creation kernel did not reach live-count increment")
        return {"native_fields": self.fields(pointer), "native_simulation_fields": [self.u32(pointer + 0x3C70 + 4 * i) for i in range(20)], "uninitialized_solid_volume_bytes": bytes(self.uc.mem_read(pointer + 0x4338, 8)).hex(), "bitmap_files": self.loaded_bitmaps, "sprite_size": [self.u32(self.u32(pointer + 0xFC) + 8), self.u32(self.u32(pointer + 0xFC) + 4)]}


def main():
    raw = (ROOT / "evidence/native-inputs/main.exe").read_bytes()
    pe = struct.unpack_from("<I", raw, 60)[0]
    optional = pe + 24
    headers = optional + struct.unpack_from("<H", raw, pe + 20)[0]
    code = None
    for index in range(struct.unpack_from("<H", raw, pe + 6)[0]):
        _, virtual_size, rva, size, pointer = struct.unpack_from("<8sIIII", raw, headers + 40 * index)
        if rva <= 0x17EE0 < rva + max(virtual_size, size): code = raw[pointer + 0x17EE0 - rva : pointer + 0x284B4 - rva]
    instructions = list(capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32).disasm(code, 0x417EE0))
    starts = {}
    for index, instruction in enumerate(instructions):
        if instruction.mnemonic == "mov" and "+ 8]," in instruction.op_str:
            try: typ = int(instruction.op_str.split(",")[-1].strip(), 0)
            except ValueError: continue
            if typ in [101, 102, 103, 104, 105, 106, 107, 108, 121, 201, 202, 204, 207, 208, 209, 210, 211, 212, 301, 302, 303, 311, 316]: starts[typ] = instructions[index - 2].address
    choices = [("sg0", 101, 0), ("sg45", 101, 45), ("sg97", 101, 97), ("sb100", 102, 100), ("sb200", 102, 200), ("sb500", 102, 500), ("zxp100", 103, 100), ("zxp250", 103, 250), ("ydsp100", 104, 100), ("pdsp100", 105, 100), ("blg", 106, 100), ("jqp", 107, 100), ("djqp", 107, -100), ("uxg", 108, 100), ("zfm_50", 121, 50), ("gkp", 201, 100), ("gkp1000", 201, 1000), ("xkp", 202, 100), ("xkp1000", 202, 1000), ("jtdg_2", 204, 4), ("ssddg", 207, 50), ("jsddg", 208, 50), ("ld", 209, 50), ("cjld", 210, 50), ("fyld", 211, 50), ("shuic", 212, 1000), ("tiejt0", 301, 0), ("tiejt1", 301, 1), ("jjd", 302, 0), ("wendj", 303, 100), ("bolb", 311, 1), ("bolb_x", 311, 2), ("wood", 316, 1)]
    results = []
    for kind, typ, parameter in choices:
        try: result = FactoryOracle().create_kernel(starts[typ], typ, parameter)
        except Exception as error: result = {"error": str(error)}
        results.append({"kind": kind, "type_id": typ, "parameter": parameter, "entry": hex(starts[typ]), **result})
    output = {"provenance": {"binary_sha256": EXPECTED, "constructor": "0x00453A28", "handler": "0x00417EE0", "scope": "Actual metadata-writing creation kernels; fixed reference position (333,222), explicit original label container counter zero. Hosted VCL bitmap/list/region graphics object boundaries. Not the complete mouse handler or Windows UI."}, "cases": results}
    destination = ROOT / "godot/tests/fixtures/original_factory.json"
    destination.write_text(json.dumps(output, ensure_ascii=False, indent=2) + "\n")
    print(json.dumps({"cases": len(results), "executed": sum("error" not in r for r in results), "failures": [{"kind": r["kind"], "error": r["error"]} for r in results if "error" in r]}, ensure_ascii=False))


if __name__ == "__main__": main()
