"""Execute original ordinary-vessel continuous-flow and N18Click instructions.

Numeric selection/rate code executes in x86. Transfer entry points capture
arguments, so fixtures explicitly test caller selection and dose semantics.
Native derived-quantity calculations execute normally. Type311 region paths
are excluded and are an explicit unsupported profile, never approximated.
"""
from pathlib import Path
import json
import struct
import hashlib
from original_actions_oracle import ActionsOracle, vessel, bits
from original_x86_oracle import EXPECTED
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EDX, UC_X86_REG_ECX, UC_X86_REG_ESP

ROOT = Path(__file__).resolve().parents[1]


class FlowOracle(ActionsOracle):
    def __init__(self):
        super().__init__()
        self.hooks[0x477330] = self.capture_solid
        self.fixture_origin = self.allocation

    def capture_transfer(self):
        self.capture(False)

    def capture_solid(self):
        self.capture(True)

    def capture(self, solid):
        sp = self.uc.reg_read(UC_X86_REG_ESP)
        self.transfers.append({'source_index': self.u32(sp + 4), 'target_index': self.u32(sp + 8),
                              'requested_bits': bytes(self.uc.mem_read(sp + 12, 8)).hex(), 'solid': solid})
        self.ret()

    def execute_flow(self, case):
        self.allocation = self.fixture_origin
        self.vessels.clear()
        self.bitmaps.clear()
        self.transfers.clear()
        self.boundary_calls.clear()
        before = []
        for item in case['vessels']:
            volume = item.get('liquid_volume', 0.0)
            contents = {'H2O(液体)': volume / self.species['H2O(液体)']['molar_mass']} if volume else {}
            index = self.add_vessel(contents, capacity=100.0)
            pointer = self.vessels[index]
            self.u32(pointer + 8, item['type'])
            self.u32(pointer + 0xc, item.get('size', 0))
            self.u32(pointer + 0x10, item['x'])
            self.u32(pointer + 0x14, item['y'])
            self.u32(pointer + 0x18, item.get('orientation', 0))
            self.u32(pointer + 0x68, item.get('state', 1))
            self.u32(pointer + 0x6c, item.get('solid_mode', 0))
            self.u32(pointer + 0xfc, self.bitmap(item['width'], item['height']))
            self.f64(pointer + 0x30, item['liquid_height'])
            snapshot = self.snapshot(index)
            before.append({'contents': {n: bits(q) for n, q in snapshot['contents'].items()},
                           'volumes': {n: bits(q) for n, q in snapshot['volumes'].items()},
                           'native_liquid_volume_bits': bits(snapshot['liquid_volume']),
                           'native_solid_volume_bits': bits(snapshot['solid_volume']),
                           'temperature_bits': bits(snapshot['temperature']),
                           'capacity_bits': bits(100.0)})
        self.u32(0x58779c, len(self.vessels))
        self.f64(0x5636c0, case['scale'])
        self.f64(0x5636d4, case['delta'])
        self.call(0x4849fc, b'')
        return {'name': case['name'], 'scale_bits': bits(case['scale']), 'delta_bits': bits(case['delta']),
                'vessels': case['vessels'], 'before': before, 'native_calls': self.transfers.copy(),
                'boundaries': sorted(set(self.boundary_calls))}


class OrientationOracle(FlowOracle):
    def __init__(self):
        super().__init__()
        self.sprite_catalog = json.loads((ROOT / 'godot/data/sprites.json').read_text())
        self.loaded = []
        self.menu_checked = None
        self.form = self.alloc(0x700)
        self.u32(self.form + 0x448, self.alloc(0x80))
        self.u32(0x57a6ec, self.string('resources'))
        self.u32(self.bitmap_vtable + 8, 0x8000140)
        self.u32(self.bitmap_vtable + 0x48, 0x8000150)
        self.hooks.update({0x8000140: self.assign_bitmap, 0x8000150: self.load_bitmap,
                           0x541040: self.concatenate, 0x4d3864: self.set_checked,
                           0x4e9160: self.reset_bitmap})
        self.fixture_origin = self.allocation

    def concatenate(self):
        a = self.uc.reg_read(UC_X86_REG_EAX)
        b = self.uc.reg_read(UC_X86_REG_EDX)
        destination = self.uc.reg_read(UC_X86_REG_ECX)
        self.u32(destination, self.string(self.bytes_at(self.u32(a)) + self.bytes_at(self.u32(b))))
        self.ret(destination)

    def load_bitmap(self):
        pointer = self.uc.reg_read(UC_X86_REG_EAX)
        filename = self.text_at(self.uc.reg_read(UC_X86_REG_EDX)).split('\\')[-1]
        key = filename.rsplit('.', 1)[0]
        if key not in self.sprite_catalog:
            raise RuntimeError('Original bitmap resource unresolved: ' + filename)
        record = self.sprite_catalog[key]
        raw = (ROOT / record['source']).read_bytes()
        if hashlib.sha256(raw).hexdigest() != record['sha256']:
            raise RuntimeError('Original bitmap identity differs: ' + filename)
        if raw[:2] != b'BM': raise RuntimeError('Original bitmap format is not BMP')
        width, height = struct.unpack_from('<ii', raw, 18)
        self.bitmaps[pointer] = {'width': width, 'height': abs(height), 'filename': filename}
        self.loaded.append(filename)
        self.ret(pointer)

    def assign_bitmap(self):
        target = self.uc.reg_read(UC_X86_REG_EAX)
        source = self.uc.reg_read(UC_X86_REG_EDX)
        self.bitmaps[target] = self.bitmaps[source].copy()
        self.ret(target)

    def reset_bitmap(self):
        # Native resets the active bitmap immediately before assigning the loaded +F4.
        pointer = self.uc.reg_read(UC_X86_REG_EAX)
        self.bitmaps[pointer] = {'width': 0, 'height': 0}
        self.ret(pointer)

    def set_checked(self):
        self.menu_checked = self.uc.reg_read(UC_X86_REG_EDX) & 255
        self.ret()

    def execute_toggle(self, type_id, subtype, orientation):
        self.allocation = self.fixture_origin
        self.vessels.clear()
        self.bitmaps.clear()
        self.boundary_calls.clear()
        self.loaded.clear()
        self.menu_checked = None
        index = self.add_vessel({})
        pointer = self.vessels[index]
        self.u32(pointer + 8, type_id)
        self.u32(pointer + 0xc, subtype)
        self.u32(pointer + 0x18, orientation)
        for offset in [0xf4, 0xf8, 0xfc]:
            self.u32(pointer + offset, self.bitmap(7, 9))
        self.u32(0x57a734, 0)
        self.u32(0x57a6f8, 1) # Native paused redraw boundary is outside this callback profile.
        self.uc.reg_write(UC_X86_REG_EAX, self.form)
        self.uc.reg_write(UC_X86_REG_EDX, 0)
        self.uc.reg_write(UC_X86_REG_ECX, 0)
        self.call(0x4433b4, b'')
        active = self.bitmaps[self.u32(pointer + 0xfc)]
        return {'type': type_id, 'subtype': subtype, 'orientation_before': orientation,
                'orientation_after': self.u32(pointer + 0x18), 'menu_checked': self.menu_checked,
                'loaded_paths': self.loaded.copy(), 'active_bitmap': active.copy(),
                'boundaries': sorted(set(self.boundary_calls))}


class MaterialFlowOracle(FlowOracle):
    def __init__(self):
        super().__init__()
        self.hooks.pop(0x476ddc)
        self.hooks.pop(0x477330)

    def on_instruction(self, uc, address, size, unused):
        if address in [0x476ddc, 0x477330]:
            sp = self.uc.reg_read(UC_X86_REG_ESP)
            self.transfers.append({'source_index': self.u32(sp + 4), 'target_index': self.u32(sp + 8),
                                  'requested_bits': bytes(self.uc.mem_read(sp + 12, 8)).hex(),
                                  'solid': address == 0x477330})
        super().on_instruction(uc, address, size, unused)

    def execute_material(self, liquid_volume, delta):
        self.allocation = self.fixture_origin
        # Each frame uses explicitly fresh, zero-initialized slot storage.
        self.uc.mem_write(self.fixture_origin, b'\0' * 0x100000)
        self.vessels.clear()
        self.bitmaps.clear()
        self.transfers.clear()
        self.boundary_calls.clear()
        sprites = json.loads((ROOT / 'godot/data/sprites.json').read_text())
        sw, sh = sprites['dxkp']['size']
        tw, th = sprites['sb200']['size']
        px = int(200 - sw * .5 + 2)
        py = int(100 + sh * .5 - 7)
        recipient = self.add_vessel({'H2O(液体)': .5}, temperature=20)
        source = self.add_vessel({'H2O(液体)': liquid_volume / self.species['H2O(液体)']['molar_mass'],
                                  'NaOH(溶解)': .1, 'Zn(固体)': .01, 'CO2(气体)': .001}, temperature=40)
        records = [dict(type=102, size=200, x=px, y=int(py + th * .5 + 10), width=tw, height=th,
                        orientation=0, state=1),
                   dict(type=202, size=100, x=200, y=100, width=sw, height=sh, orientation=2, state=1)]
        for i, item in enumerate(records):
            pointer = self.vessels[i]
            for offset, key in [(8, 'type'), (0xc, 'size'), (0x10, 'x'), (0x14, 'y'),
                                (0x18, 'orientation'), (0x68, 'state')]:
                self.u32(pointer + offset, item[key])
            self.u32(pointer + 0xfc, self.bitmap(item['width'], item['height']))
        before = [raw_snapshot(self, i) for i in range(2)]
        self.u32(0x58779c, 2)
        self.f64(0x5636c0, 1.0)
        self.f64(0x5636d4, delta)
        self.call(0x4849fc, b'')
        return {'name': f'liquid{liquid_volume}-delta{delta}', 'records': records, 'before': before,
                'after': [raw_snapshot(self, i) for i in range(2)], 'calls': self.transfers.copy(),
                'scale_bits': bits(1), 'delta_bits': bits(delta),
                'boundary_calls': sorted(set(self.boundary_calls)), 'messages': self.messages.copy()}


def raw_snapshot(oracle, index):
    source = oracle.snapshot(index)
    result = {name: {species: bits(value) for species, value in source[name].items()}
              for name in ['contents', 'masses', 'volumes']}
    for name in ['temperature', 'liquid_volume', 'solid_volume', 'gas_moles', 'gas_volume', 'pressure']:
        result[name] = bits(source[name])
    result['capacity'] = bits(oracle.f64(oracle.vessels[index] + 0x28))
    return result


def candidates(type_id):
    return [0, 45] if type_id == 101 else ([100, 250] if type_id == 103 else [0])


def frames():
    result = []
    outlets = {101: (0, 0), 102: (1, 1), 103: (12, 14), 104: (12, 15), 105: (9, 14),
               106: (1, 1), 121: (0, 0), 201: (2, 7), 202: (2, 7)}
    for source_type in [101, 102, 103, 104, 105, 106, 121, 201, 202, 204, 207, 208, 209, 210, 211]:
        pouring = source_type in outlets
        for target_type in [101, 102, 103, 104, 105, 107, 121, 201, 202, 209, 210, 106]:
            for size in candidates(target_type):
                for scale in [0.5, 1.0, 1.3]:
                    source = vessel(source_type, x=200, y=100, width=41, height=101,
                                    size=100 if source_type == 103 else 0)
                    source['orientation'] = 2 if pouring else 0
                    source['state'] = 0
                    source['liquid_volume'] = 0.0 if source_type == 209 else 10.0
                    if pouring:
                        dx, dy = outlets[source_type]
                        px = int(200 - 41 * .5 * scale + dx * scale)
                        py = int(100 + 101 * .5 * scale - dy * scale)
                    else:
                        px = int(200 - 4 * scale) if source_type == 207 else 200
                        py = int(100 + 101 * .5 * scale)
                    target = vessel(target_type, x=int(px - (30 * scale if target_type == 101 and size == 45 else 0)),
                                    y=int(py + 101 * .5 * scale + 10 * scale), width=41, height=101, size=size)
                    target['orientation'] = 0
                    target['state'] = 1
                    result.append({'name': f'source{source_type}-target{target_type}-size{size}-scale{scale}',
                                   'vessels': [target, source], 'scale': scale, 'delta': .017})
    for source_type in [204, 207, 208, 209, 210, 211]:
        for state in [0, 1, 2]:
            for orientation in [0, 1, 2]:
                if orientation == 2: continue  # Unassigned tilted outlets are explicit unsupported data.
                source = vessel(source_type, x=100, y=0, width=9, height=100)
                source.update(state=state, orientation=orientation)
                target = vessel(202, x=96 if source_type == 207 else 100, y=50, height=101)
                result.append({'name': f'open-flags-{source_type}-{state}-{orientation}',
                               'vessels': [target, source], 'scale': 1.0, 'delta': .1})
    for delta in [0.0, 0.01, 0.1, 0.3, 1.0, -0.01]:
        for scale in [.75, 1.25]:
            source = vessel(202, x=150, y=0, width=41, height=101)
            source.update(orientation=2, liquid_volume=0.0, state=1)
            first = vessel(201, x=int(150 - 18.5 * scale), y=100, width=41, height=101)
            second = vessel(202, x=int(150 - 18.5 * scale), y=100, width=41, height=100)
            result.append({'name': f'overlap-delta{delta}-scale{scale}',
                           'vessels': [first, second, source], 'scale': scale, 'delta': delta})
    return result


def main():
    oracle = FlowOracle()
    output = {'binary_sha256': EXPECTED, 'function': '0x004849FC',
              'contract': 'Original ordinary-vessel geometry and x87 rate instructions; original 624D8/461E54 executes; transfer entry captures arguments without material side effects; type311 GDI regions excluded and explicitly unsupported by this profile.',
              'cases': [oracle.execute_flow(case) for case in frames()]}
    water = oracle.species['H2O(液体)']
    output['reagent_bits'] = {'H2O(液体)': {'molar_mass': bits(water['molar_mass']),
                                            'density': bits(float(water['raw_fields'][7]))}}
    destination = ROOT / 'evidence/original_logic/native-flow-oracle.json'
    destination.write_text(json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(f'Executed {len(output["cases"])} original flow frames -> {destination}')
    orientation = OrientationOracle()
    types = [(101, 0), (101, 45), (101, 20), (102, 100), (102, 200), (102, 500),
             (102, 999), (103, 100), (103, 250), (104, 100), (105, 100), (106, 0),
             (121, 50), (201, 100), (201, 1000), (202, 100), (202, 1000), (207, 50)]
    toggles = [orientation.execute_toggle(typ, subtype, state)
               for typ, subtype in types for state in [0, 1, 2]]
    output = {'binary_sha256': EXPECTED, 'function': '0x004433B4',
              'contract': 'Original N18Click instructions; hosted AnsiString concatenation and VCL bitmap loading reads SHA-verified original BMP dimensions; checkbox/reset/assign are explicit VCL property boundaries; run flag=1 excludes paused redraw.',
              'cases': toggles}
    destination = ROOT / 'evidence/original_logic/native-orientation-oracle.json'
    destination.write_text(json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(f'Executed {len(toggles)} original N18 frames -> {destination}')
    material = MaterialFlowOracle()
    material_cases = [material.execute_material(volume, delta)
                      for volume in [.01, 1.0, 40.0] for delta in [.017, .1, .3]]
    names = ['H2O(液体)', 'NaOH(溶解)', 'Zn(固体)', 'CO2(气体)']
    reagent_bits = {name: {'molar_mass': bits(material.species[name]['molar_mass']),
                           'density': bits(float(material.species[name]['raw_fields'][7]))} for name in names}
    output = {'binary_sha256': EXPECTED, 'function': '0x004849FC + 0x00476DDC + 0x00477330 + 0x00461E54',
              'contract': 'Original x86 flow, liquid/solid transfer and quantity arithmetic executes; only existing AnsiString/lookup and bitmap measurement boundaries hosted. Actual original dxkp/sb200 bitmap dimensions from recovered sprite inventory. Fresh explicitly zeroed slot storage each frame.',
              'reagent_bits': reagent_bits, 'cases': material_cases}
    destination = ROOT / 'evidence/original_logic/native-flow-material-oracle.json'
    destination.write_text(json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(f'Executed {len(material_cases)} original full material-flow frames -> {destination}')


if __name__ == '__main__':
    main()
