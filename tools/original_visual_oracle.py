"""Execute original gas/solid numeric visual routines; capture VCL draw records.

No scalar color/volume/geometry instruction is replaced. Canvas property and
primitive presentation calls are explicit boundaries, not rendered-pixel claims.
"""
from pathlib import Path
import json
import struct
from original_flow_oracle import FlowOracle
from original_x86_oracle import EXPECTED
from original_actions_oracle import bits
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EDX, UC_X86_REG_ECX, UC_X86_REG_ESP, UC_X86_REG_EIP

ROOT = Path(__file__).resolve().parents[1]


def signed(value):
    return value if value < 0x80000000 else value - 0x100000000


class VisualOracle(FlowOracle):
    def __init__(self):
        super().__init__()
        for index, record in enumerate(self.catalog):
            self.u32(self.u32(0x57bc08 + index * 4) + 0x28, int(record['color_integer']))
        self.pen_color = 0
        self.brush_color = 0
        self.brush_style = 0
        self.operations = []
        self.hooks.update({0x4e3e50: self.set_pen_color, 0x4e4158: self.set_brush_color,
                           0x4e4274: self.set_brush_style, 0x4e4744: self.rectangle})
        self.fixture_origin = self.allocation

    def set_pen_color(self):
        self.pen_color = self.uc.reg_read(UC_X86_REG_EDX)
        self.ret()

    def set_brush_color(self):
        self.brush_color = self.uc.reg_read(UC_X86_REG_EDX)
        self.ret()

    def set_brush_style(self):
        self.brush_style = self.uc.reg_read(UC_X86_REG_EDX) & 255
        self.ret()

    def rectangle(self):
        sp = self.uc.reg_read(UC_X86_REG_ESP)
        self.operations.append({'op': 'rectangle', 'left': signed(self.uc.reg_read(UC_X86_REG_EDX)),
                                'top': signed(self.uc.reg_read(UC_X86_REG_ECX)),
                                'right': signed(self.u32(sp + 8)), 'bottom': signed(self.u32(sp + 4)),
                                'pen_color': self.pen_color, 'brush_color': self.brush_color,
                                'brush_style': self.brush_style})
        destination = self.u32(sp)
        self.uc.reg_write(UC_X86_REG_ESP, sp + 12)
        self.uc.reg_write(UC_X86_REG_EIP, destination)

    def gas_frame(self, name, contents, capacity, liquid_volume, liquid_height, width, height):
        self.allocation = self.fixture_origin
        self.vessels.clear(); self.bitmaps.clear(); self.boundary_calls.clear(); self.operations.clear()
        self.pen_color = self.brush_color = self.brush_style = 0
        index = self.add_vessel(contents, capacity=capacity)
        pointer = self.vessels[index]
        bitmap = self.bitmap(width, height)
        self.u32(pointer + 0xfc, bitmap)
        self.f64(pointer + 0x4320, liquid_volume)
        self.f64(pointer + 0x30, liquid_height)
        self.call(0x47692c, struct.pack('<II', bitmap, index))
        return {'name': name, 'contents_bits': {species: bits(value) for species, value in contents.items()},
                'capacity_bits': bits(capacity), 'liquid_volume_bits': bits(liquid_volume),
                'liquid_height_bits': bits(liquid_height), 'width': width, 'height': height,
                'native_operations': self.operations.copy(), 'boundaries': sorted(set(self.boundary_calls))}


class SolidVisualOracle(VisualOracle):
    def __init__(self):
        super().__init__()
        self.u32(self.bitmap_vtable - 4, 0x8000160)
        self.u32(self.bitmap_vtable + 0x3c, 0x8000170)
        self.hooks.update({0x8000160: lambda: self.ret(), 0x8000170: self.set_transparent,
                           0x4e4588: self.ellipse, 0x4e43c8: self.arc,
                           0x4e4150: lambda: self.ret(self.brush_color),
                           0x4e44a8: self.texture_draw, 0x4928a0: self.tint,
                           0x492560: self.composite})
        texture = self.bitmap(1, 1)
        self.u32(0x57a720, texture)
        self.fixture_origin = self.allocation

    def set_transparent(self):
        self.operations.append({'op': 'transparent', 'value': self.uc.reg_read(UC_X86_REG_EDX) & 255})
        self.ret()

    def ellipse(self):
        count = len(self.operations)
        self.rectangle()
        self.operations[count]['op'] = 'ellipse'

    def arc(self):
        sp = self.uc.reg_read(UC_X86_REG_ESP)
        # Delphi register convention pushes remaining arguments left-to-right.
        coordinates = [signed(self.uc.reg_read(UC_X86_REG_EDX)), signed(self.uc.reg_read(UC_X86_REG_ECX))]
        coordinates += [signed(self.u32(sp + offset)) for offset in [24, 20, 16, 12, 8, 4]]
        names = ['left', 'top', 'right', 'bottom', 'start_x', 'start_y', 'end_x', 'end_y']
        self.operations.append({'op': 'arc', **dict(zip(names, coordinates)), 'pen_color': self.pen_color})
        address = self.u32(sp)
        self.uc.reg_write(UC_X86_REG_ESP, sp + 28)
        self.uc.reg_write(UC_X86_REG_EIP, address)

    def texture_draw(self):
        sp = self.uc.reg_read(UC_X86_REG_ESP)
        graphic = self.u32(sp + 4)
        if graphic != self.u32(0x57a720): raise RuntimeError('Unexpected native solid texture operand')
        self.operations.append({'op': 'texture', 'source': 'guti.bmp',
                                'left': signed(self.uc.reg_read(UC_X86_REG_EDX)),
                                'top': signed(self.uc.reg_read(UC_X86_REG_ECX)),
                                'copy_mode': self.u32(self.canvas + 0x20)})
        address = self.u32(sp)
        self.uc.reg_write(UC_X86_REG_ESP, sp + 8)
        self.uc.reg_write(UC_X86_REG_EIP, address)

    def tint(self):
        sp = self.uc.reg_read(UC_X86_REG_ESP)
        self.operations.append({'op': 'tint_nonwhite', 'color_integer': self.u32(sp + 8),
                                'weight_bits': bytes(self.uc.mem_read(sp + 12, 8)).hex()})
        self.ret()

    def composite(self):
        sp = self.uc.reg_read(UC_X86_REG_ESP)
        self.operations.append({'op': 'composite_white_key', 'left': signed(self.u32(sp + 4)),
                                'top': signed(self.u32(sp + 8)),
                                'weight_bits': bytes(self.uc.mem_read(sp + 20, 8)).hex()})
        self.ret()

    def solid_frame(self, name, contents, precipitated, type_id, subtype, capacity, liquid_volume, width, height):
        self.allocation = self.fixture_origin
        self.vessels.clear(); self.bitmaps.clear(); self.boundary_calls.clear(); self.operations.clear()
        self.pen_color = self.brush_color = self.brush_style = 0
        index = self.add_vessel(contents, capacity=capacity)
        pointer = self.vessels[index]
        bitmap = self.bitmap(width, height)
        self.u32(pointer + 8, type_id); self.u32(pointer + 0xc, subtype)
        self.u32(pointer + 0xfc, bitmap); self.f64(pointer + 0x4320, liquid_volume)
        for slot, species in enumerate(contents): self.f64(pointer + 0x3cd8 + slot * 8, precipitated.get(species, 0.0))
        snapshot = self.snapshot(index)
        self.call(0x4744dc, struct.pack('<II', bitmap, index))
        return {'name': name, 'contents_bits': {species: bits(value) for species, value in contents.items()},
                'volumes_bits': {species: bits(value) for species, value in snapshot['volumes'].items()},
                'precipitated_bits': {species: bits(precipitated.get(species, 0.0)) for species in contents},
                'type': type_id, 'subtype': subtype, 'capacity_bits': bits(capacity), 'liquid_volume_bits': bits(liquid_volume),
                'width': width, 'height': height, 'native_operations': self.operations.copy(),
                'boundaries': sorted(set(self.boundary_calls))}


class PixelOracle(VisualOracle):
    def __init__(self):
        super().__init__()
        self.hooks.update({0x4ea36c: lambda: self.ret(), 0x4e95b0: self.scanline})
        self.first = self.bitmap(1, 1)
        self.second = self.bitmap(1, 1)
        self.first_pixels = self.alloc(4)
        self.second_pixels = self.alloc(4)
        self.bitmaps[self.first]['pixels'] = self.first_pixels
        self.bitmaps[self.second]['pixels'] = self.second_pixels

    def scanline(self):
        bitmap = self.uc.reg_read(UC_X86_REG_EAX)
        row = self.uc.reg_read(UC_X86_REG_EDX)
        if row != 0: raise RuntimeError('Pixel oracle only hosts an explicit 1-row bitmap')
        self.ret(self.bitmaps[bitmap]['pixels'])

    def tint_frame(self, pixel, color, weight):
        self.u32(self.first_pixels, pixel)
        self.call(0x4928a0, struct.pack('<IId', self.first, color, weight))
        return {'op': 'tint', 'pixel': pixel, 'color': color, 'weight_bits': bits(weight),
                'native_result': self.u32(self.first_pixels)}

    def composite_frame(self, destination, source, weight):
        self.u32(self.first_pixels, destination)
        self.u32(self.second_pixels, source)
        self.call(0x492560, struct.pack('<IIIId', 0, 0, self.second, self.first, weight))
        return {'op': 'composite', 'destination': destination, 'source': source, 'weight_bits': bits(weight),
                'native_result': self.u32(self.first_pixels)}


def gas_cases():
    for volume in [0.0, .05, .0999999999, .1, .1000000001, 1.0, 10.0, 100.0, 200.0]:
        for liquid in [0.0, 50.0, 100.0, 120.0]:
            for liquid_height in [0.0, 11.5, 100.2]:
                yield (f'Cl2-volume{volume}-liquid{liquid}-height{liquid_height}',
                       {'Cl2(气体)': volume / 22.4 / 1000}, 100.0, liquid, liquid_height, 41, 101)
    for n in [.00001, .001, .1]:
        for liquid in [0.0, 37.3]:
            yield (f'mixed-n{n}-liquid{liquid}', {'Cl2(气体)': n, 'CO2(气体)': n * 2, 'NO2(气体)': n * 3},
                   100, liquid, 21.3, 53, 58)
    yield ('non-gas-excluded', {'H2O(液体)': 1.0, 'Zn(固体)': .1}, 100, 18.016, 10, 53, 58)


def main():
    oracle = VisualOracle()
    cases = [oracle.gas_frame(*case) for case in gas_cases()]
    names = {species for case in cases for species in case['contents_bits']}
    records = {species: {'molar_mass_bits': bits(oracle.species[species]['molar_mass']),
                         'color_integer': oracle.species[species]['color_integer']} for species in names}
    output = {'binary_sha256': EXPECTED, 'function': '0x0047692C',
              'contract': 'Original gas color, volume, headspace and rectangle-bound instructions execute; only VCL property/primitive presentation and established AnsiString/lookup boundaries hosted. Captured operations do not establish GDI pixels.',
              'reagent_fields': records, 'cases': cases}
    destination = ROOT / 'evidence/original_logic/native-gas-visual-oracle.json'
    destination.write_text(json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(f'Executed {len(cases)} original gas visual frames -> {destination}')
    solid = SolidVisualOracle()
    cases = []
    for type_id, subtype in [(101, 0), (101, 45), (101, 97), (102, 100), (103, 100),
                             (104, 100), (105, 100), (106, 0), (107, 100), (108, 0),
                             (121, 50), (201, 100), (202, 100), (209, 50), (210, 100), (211, 100)]:
        for solid_volume in [.01, 5.0, 20.0, 120.0]:
            moles = solid_volume * float(solid.species['Zn(固体)']['raw_fields'][7]) / solid.species['Zn(固体)']['molar_mass']
            cases.append(solid.solid_frame(f'type{type_id}-sub{subtype}-vol{solid_volume}',
                         {'Zn(固体)': moles}, {}, type_id, subtype, 100, 0, 41, 101))
    for liquid in [0.0, 1.0, 20.0]:
        for precipitated in [0.0, .025, .1]:
            cases.append(solid.solid_frame(f'mixed-liquid{liquid}-precip{precipitated}',
                         {'Zn(固体)': .1, 'Cu(OH)2(固体)': .02, 'H2O(液体)': 1},
                         {'Zn(固体)': precipitated}, 102, 200, 100, liquid, 53, 58))
    names = {species for case in cases for species in case['contents_bits']}
    fields = {species: {'molar_mass_bits': bits(solid.species[species]['molar_mass']),
                        'density_bits': bits(float(solid.species[species]['raw_fields'][7])),
                        'color_integer': solid.species[species]['color_integer']} for species in names}
    output = {'binary_sha256': EXPECTED, 'function': '0x004744DC',
              'contract': 'Original solid volume/color/shape arithmetic executes; VCL primitive, texture draw, pixel tint and white-key composition are recorded presentation boundaries; no random particle algorithm or GDI pixel claim.',
              'reagent_fields': fields, 'cases': cases}
    destination = ROOT / 'evidence/original_logic/native-solid-visual-oracle.json'
    destination.write_text(json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(f'Executed {len(cases)} original solid visual frames -> {destination}')
    pixels = PixelOracle()
    words = [0, 0xFFFFFF, 0xFFFFFFFF, 0x00EEEEEE, 0x00123456, 0x00ABCDEF, 0x00FEFDFB]
    cases = [pixels.tint_frame(pixel, color, weight)
             for pixel in words for color in words[:6] for weight in [.15, .0, .5, 1.0]]
    cases += [pixels.composite_frame(destination, source, weight)
              for destination in words for source in words for weight in [.15, .0, .5, 1.0]]
    destination = ROOT / 'evidence/original_logic/native-solid-pixels-oracle.json'
    destination.write_text(json.dumps({'binary_sha256': EXPECTED, 'functions': ['0x004928A0', '0x00492560'],
                         'contract': 'Original per-pixel instructions execute against explicit native 32-bit 1x1 DIB words; bitmap size/scanline and no-op 32->32 format property are declared VCL boundaries. No ellipse/GDI rasterization claim.',
                         'cases': cases}, ensure_ascii=False, indent=2) + '\n')
    print(f'Executed {len(cases)} original solid pixel frames -> {destination}')


if __name__ == '__main__':
    main()
