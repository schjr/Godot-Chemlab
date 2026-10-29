"""Execute original 0x00470060 heater geometry, hosting bitmap dimensions/name lookup."""
import json
import random
import struct
from original_x86_oracle import OriginalOracle, EXPECTED, ROOT
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP


class GeometryOracle(OriginalOracle):
    def __init__(self):
        super().__init__()
        self.hooks[0x453F98] = self.find_vessel
        self.hooks[0x8000010] = self.bitmap_height
        self.hooks[0x8000020] = self.bitmap_width

    def find_vessel(self):
        sp = self.uc.reg_read(UC_X86_REG_ESP)
        name = self.bytes_at(self.u32(sp + 4))
        found = next((index for index, p in enumerate(self.vessels) if self.bytes_at(self.u32(p + 4)) == name), -1)
        self.ret(found)

    def bitmap_height(self):
        self.ret(self.u32(self.uc.reg_read(UC_X86_REG_EAX) + 4))

    def bitmap_width(self):
        self.ret(self.u32(self.uc.reg_read(UC_X86_REG_EAX) + 8))

    def run_geometry(self, vessels, scale):
        mapping = {"type_id": 8, "native_type_parameter": 0xC, "native_cap_flag": 0x38, "native_flame_style": 0x50, "native_flame_width": 0x5C, "native_flame_height": 0x60, "native_platform_mode": 0x6C, "native_platform_offset": 0x7C, "native_ignition": 0x9C, "native_heating": 0xA0}
        for v in vessels:
            index = self.add_vessel({}, capacity=100.0)
            p = self.vessels[index]
            self.u32(p + 4, self.string(v["label"]))
            self.u32(p + 0x10, int(v["position"][0]))
            self.u32(p + 0x14, int(v["position"][1]))
            self.u32(p + 0x80, self.string(v["native_attachment"]))
            for name, offset in mapping.items(): self.u32(p + offset, v[name])
            bitmap = self.alloc(16)
            table = self.alloc(0x40)
            self.u32(bitmap, table)
            self.u32(bitmap + 4, v["native_sprite_height"])
            self.u32(bitmap + 8, v["native_sprite_width"])
            self.u32(table + 0x20, 0x8000010)
            self.u32(table + 0x2C, 0x8000020)
            self.u32(p + 0xFC, bitmap)
        self.u32(0x58779C, len(vessels))
        self.f64(0x5636C0, scale)
        self.call(0x470060, b"")
        return [{name: self.u32(p + mapping[name]) for name in ["native_heating", "native_ignition", "native_flame_style", "native_flame_width", "native_flame_height"]} for p in self.vessels]


def make_vessel(label, type_id, position, size, **updates):
    result = {"label": label, "type_id": type_id, "position": position, "native_sprite_width": size[0], "native_sprite_height": size[1], "native_type_parameter": 0, "native_cap_flag": 0, "native_flame_style": 0, "native_flame_width": 0, "native_flame_height": 0, "native_platform_mode": 0, "native_platform_offset": 0, "native_attachment": "", "native_ignition": 0, "native_heating": 1}
    result.update(updates)
    return result


def main():
    examples = json.loads((ROOT / "godot/data/examples.json").read_text())
    sprites = json.loads((ROOT / "godot/data/sprites.json").read_text())
    kinds = {101: "sg0", 102: "sb100", 103: "zxp100", 104: "ydsp100", 105: "pdsp100", 106: "blg", 108: "uxg", 121: "zfm_50", 301: "tiejt0", 302: "jjd"}
    specifications = []
    for example in examples:
        if not any(v["type_id"] == 302 for v in example["apparatus"]): continue
        vessels = []
        for v in example["apparatus"]:
            m = v["metadata"]
            kind = kinds.get(v["type_id"], "jjd")
            if v["type_id"] == 101: kind = "sg97" if int(m[3]) == 97 else "sg45" if int(m[3]) == 45 else "sg0"
            if v["type_id"] == 102: kind = "sb500" if int(m[3]) >= 500 else "sb200" if int(m[3]) >= 200 else "sb100"
            if v["type_id"] == 103 and int(m[3]) >= 250: kind = "zxp250"
            size = sprites[kind]["size"]
            vessels.append(make_vessel(v["name"], v["type_id"], [int(v["x"]), int(v["y"])], size, native_type_parameter=int(m[3]), native_cap_flag=0 if v["type_id"] == 302 else int(m[10]), native_flame_style=int(m[16]), native_flame_width=int(m[19]), native_flame_height=int(m[20]), native_platform_mode=int(m[23]), native_platform_offset=int(m[27]), native_attachment=m[28], native_ignition=int(m[34]), native_heating=int(m[35])))
        specifications.append({"name": example["name"] + ":lamp_flags_active", "vessels": vessels, "scale": 1.0})
    for type_id, parameter, size in [(101, 0, [18, 88]), (101, 45, [71, 72]), (101, 97, [90, 23]), (102, 100, [45, 47]), (103, 100, [43, 52]), (104, 100, [44, 82]), (105, 100, [43, 79]), (106, 0, [38, 86]), (108, 0, [48, 79]), (121, 50, [44, 17]), (301, 0, [88, 206])]:
        for scale in [0.5, 1.0, 1.5]:
            for x_shift, gap in [(0, 5), (0, 6), (0, 7), (0, 24), (0, 25), (0, 28), (40, 15), (-int(29 * scale), 7), (-int(29 * scale), 24), (-int(15 * scale), 15)]:
                target = make_vessel("target", type_id, [200, 200], size, native_type_parameter=parameter, native_platform_mode=2 if type_id == 301 else 0, native_platform_offset=72 if type_id == 301 else 0)
                bottom = 200 + size[1] * 0.5 * scale - (72 * scale if type_id == 301 else 0)
                lamp = make_vessel("lamp", 302, [200 + x_shift, int(bottom + (12 + gap) * scale)], [43, 48])
                specifications.append({"name": f"boundary_type{type_id}_angle{parameter}_scale{scale}_dx{x_shift}_gap{gap}", "vessels": [target, lamp], "scale": scale})
    closed_target = make_vessel("target", 102, [200, 200], [45, 47])
    specifications.append({"name": "closed_lamp", "vessels": [closed_target, make_vessel("lamp", 302, [200, 248], [43, 48], native_cap_flag=1)], "scale": 1.0})
    stand = make_vessel("stand", 301, [400, 200], [88, 206], native_platform_mode=2, native_ignition=1)
    target = make_vessel("attached", 102, [10, 10], [45, 47], native_attachment="stand")
    specifications.append({"name": "stand_ignition_attachment", "vessels": [stand, target], "scale": 1.0})
    generator = random.Random(0x470060)
    target_shapes = [(101, 0, [18, 88]), (101, 45, [71, 72]), (101, 97, [90, 23]), (102, 100, [45, 47]), (103, 100, [43, 52]), (104, 100, [44, 82]), (105, 100, [43, 79]), (106, 0, [38, 86]), (121, 50, [44, 17]), (301, 0, [88, 206])]
    for index in range(100):
        scale = generator.choice([0.37, 0.7, 1.23, 1.73])
        vessels = []
        for target_index in range(4):
            type_id, parameter, size = generator.choice(target_shapes)
            vessels.append(make_vessel("receiver" + str(target_index), type_id, [generator.randrange(160, 241), generator.randrange(160, 241)], size, native_type_parameter=parameter, native_platform_mode=2 if type_id == 301 else 0, native_platform_offset=72 if type_id == 301 else 0, native_ignition=generator.randrange(2), native_attachment="receiver0" if target_index > 0 else ""))
        for lamp_index in range(2):
            vessels.append(make_vessel("lamp" + str(lamp_index), 302, [generator.randrange(160, 241), generator.randrange(210, 321)], [43, 48], native_cap_flag=generator.choice([0, 0, 1])))
        specifications.append({"name": "mixed_ordered_scene_" + str(index), "vessels": vessels, "scale": scale})
    cases = []
    for specification in specifications:
        after = GeometryOracle().run_geometry(specification["vessels"], specification["scale"])
        cases.append({**specification, "scale_bits": struct.pack("<d", specification["scale"]).hex(), "after": after})
    output = {"provenance": {"binary_sha256": EXPECTED, "entry": "0x00470060", "method": "Actual PE geometry instructions, actual fabs and integer-truncation helpers; bitmap height/width virtual access and name lookup are declared hosted boundaries. Original example coordinates/metadata and recovered bitmap dimensions are inputs; lamp cap flags explicitly set active in example fixtures."}, "cases": cases}
    destination = ROOT / "godot/tests/fixtures/original_heat_geometry.json"
    destination.write_text(json.dumps(output, ensure_ascii=False, indent=2) + "\n")
    print(f"Recorded {len(cases)} original heater geometry cases: {destination}")


if __name__ == "__main__": main()
