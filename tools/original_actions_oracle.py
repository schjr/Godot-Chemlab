"""Bounded original 0x00477708 selection/dose oracle.

Execute original x86 instructions. Host only declared VCL bitmap properties,
initial canvas Rectangle presentation, existing AnsiString boundaries, and
capture the original transfer CALL arguments without executing transfer.
No Win32 process or replacement selection algorithm is run.
"""
from pathlib import Path
import json
import struct
import sys

from original_x86_oracle import OriginalOracle, EXPECTED
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EDX, UC_X86_REG_ESP, UC_X86_REG_EIP

ROOT = Path(__file__).resolve().parents[1]


def bits(value):
    return struct.pack('<d', float(value)).hex()


class ActionsOracle(OriginalOracle):
    def __init__(self):
        super().__init__()
        self.bitmaps = {}
        self.transfers = []
        self.graphics_boundaries = []
        self.bitmap_vtable = self.alloc(0x60)
        self.canvas = self.alloc(0x80)
        self.u32(self.canvas + 0x10, self.alloc(0x40))
        self.u32(self.canvas + 0x14, self.alloc(0x40))
        for offset, address, handler in [
            (0x20, 0x8000100, self.get_height),
            (0x2c, 0x8000110, self.get_width),
            (0x34, 0x8000120, self.set_height),
            (0x40, 0x8000130, self.set_width),
        ]:
            self.u32(self.bitmap_vtable + offset, address)
            self.hooks[address] = handler
        self.hooks.update({
            0x4e8edc: self.construct_bitmap,
            0x4e9448: self.get_canvas,
            0x4e4744: self.initial_rectangle,
            0x476ddc: self.capture_transfer,
        })

    def bitmap(self, width, height):
        pointer = self.alloc(0x80)
        self.u32(pointer, self.bitmap_vtable)
        self.bitmaps[pointer] = {'width': int(width), 'height': int(height)}
        return pointer

    def construct_bitmap(self):
        # Original routine calls TBitmap constructor and then sets both dimensions.
        self.graphics_boundaries.append('TBitmap constructor, initially 0 x 0')
        self.ret(self.bitmap(0, 0))

    def get_height(self):
        pointer = self.uc.reg_read(UC_X86_REG_EAX)
        self.ret(self.bitmaps[pointer]['height'])

    def get_width(self):
        pointer = self.uc.reg_read(UC_X86_REG_EAX)
        self.ret(self.bitmaps[pointer]['width'])

    def set_height(self):
        pointer = self.uc.reg_read(UC_X86_REG_EAX)
        self.bitmaps[pointer]['height'] = self.uc.reg_read(UC_X86_REG_EDX)
        self.ret(pointer)

    def set_width(self):
        pointer = self.uc.reg_read(UC_X86_REG_EAX)
        self.bitmaps[pointer]['width'] = self.uc.reg_read(UC_X86_REG_EDX)
        self.ret(pointer)

    def get_canvas(self):
        self.graphics_boundaries.append('TBitmap.GetCanvas')
        self.ret(self.canvas)

    def initial_rectangle(self):
        # Borland fastcall Rectangle passes bottom/right on stack (callee removes 8).
        # This is presentation only; no geometry or scalar arithmetic is substituted.
        self.graphics_boundaries.append('TCanvas.Rectangle presentation')
        sp = self.uc.reg_read(UC_X86_REG_ESP)
        address = self.u32(sp)
        self.uc.reg_write(UC_X86_REG_ESP, sp + 12)
        self.uc.reg_write(UC_X86_REG_EIP, address)

    def capture_transfer(self):
        sp = self.uc.reg_read(UC_X86_REG_ESP)
        self.transfers.append({
            'source_index': self.u32(sp + 4),
            'target_index': self.u32(sp + 8),
            'requested_bits': bytes(self.uc.mem_read(sp + 12, 8)).hex(),
        })
        self.ret()

    def execute_case(self, case):
        self.vessels.clear()
        self.transfers.clear()
        self.graphics_boundaries.clear()
        self.boundary_calls.clear()
        for vessel in case['vessels']:
            volume = vessel.get('liquid_volume', 0.0)
            # One actual library liquid species stores the explicitly supplied slot volume.
            contents = {'H2O(液体)': volume / self.species['H2O(液体)']['molar_mass']} if volume else {}
            index = self.add_vessel(contents, capacity=100.0)
            pointer = self.vessels[index]
            self.u32(pointer + 8, vessel['type'])
            self.u32(pointer + 0xc, vessel.get('size', 0))
            self.u32(pointer + 0x10, vessel['x'])
            self.u32(pointer + 0x14, vessel['y'])
            self.u32(pointer + 0xfc, self.bitmap(vessel['width'], vessel['height']))
            self.f64(pointer + 0x30, vessel['liquid_height'])
            self.u32(pointer + 0x68, vessel.get('state', 7))
            if volume:
                self.f64(pointer + 0x5b8, volume)
            # This explicit native input cache suppresses VCL falling-drop animation;
            # selection and CALL arguments still execute in the original routine.
            self.f64(pointer + 0x4320, 0.0)
        self.u32(0x58779c, len(self.vessels))
        self.u32(0x57a734, case['selected'])
        self.u32(0x57a730, case['vessels'][case['selected']]['type'])
        self.u32(0x57a738, case['command'])
        self.f64(0x5636c0, case['scale'])
        self.call(0x477708, b'')
        return {'name': case['name'], 'selected': case['selected'], 'command': case['command'],
                'scale_bits': bits(case['scale']),
                'vessels': [{**v, 'liquid_height_bits': bits(v['liquid_height']),
                             'liquid_volume_bits': bits(v.get('liquid_volume', 0.0))} for v in case['vessels']],
                'native_transfers': self.transfers.copy(),
                'native_states': [self.u32(p + 0x68) for p in self.vessels],
                'native_boundaries': sorted(set(self.boundary_calls)),
                'presentation_boundaries': sorted(set(self.graphics_boundaries))}


def vessel(type_id, x=100, y=50, width=31, height=101, liquid_height=60.0, size=0, liquid_volume=0.0):
    return {'type': type_id, 'x': x, 'y': y, 'width': width, 'height': height,
            'liquid_height': liquid_height, 'size': size, 'liquid_volume': liquid_volume}


def cases():
    cases = []
    for selected_type in [204, 207, 208, 211]:
        for command in [1, 2, 3, 0, 4]:
            for candidate_type in [101, 102, 103, 104, 105, 107, 201, 202, 106, 121]:
                for scale in [0.5, 1.0, 1.25]:
                    candidate = vessel(candidate_type, size=100 if candidate_type == 103 else 0)
                    selected = vessel(selected_type, y=0, width=9, height=100)
                    cases.append({'name': f'type{selected_type}-cmd{command}-target{candidate_type}-s{scale}',
                                  'vessels': [candidate, selected], 'selected': 1, 'command': command, 'scale': scale})
    # Tests exact source-order behavior, including a valid empty first source.
    for used in [0.0, 0.25, 1.75, 2.0, 3.0]:
        cases.append({'name': f'aspirate-first-empty-used{used}', 'selected': 2, 'command': 1, 'scale': 1.0,
                      'vessels': [vessel(202, liquid_volume=0.0), vessel(202, liquid_volume=40.0),
                                  vessel(204, y=0, width=9, height=100, liquid_volume=used)]})
    # Strict mouth/surface/bottom boundaries are actual original branch comparisons.
    for x in [95, 96, 100, 104, 105]:
        for y in [-100, -61, -60, -59, -3, -2, 0, 46, 47, 48]:
            cases.append({'name': f'204-strict-x{x}-y{y}', 'selected': 1, 'command': 2, 'scale': 1.0,
                          'vessels': [vessel(202, height=100), vessel(204, x=x, y=y, width=9, height=100)]})
    for selected_type in [204, 207, 208, 211]:
        for y in [0, 1, 2, 3]:
            cases.append({'name': f'overlap-truncated-score-{selected_type}-{y}', 'selected': 2, 'command': 2 if selected_type == 204 else 3,
                          'scale': 1.0, 'vessels': [vessel(201, y=50, height=101), vessel(202, y=50, height=100),
                                                  vessel(selected_type, y=y, width=9, height=100)]})
    for selected_type in [101, 102, 203, 206, 212, 311]:
        for command in [1, 2, 3]:
            cases.append({'name': f'unsupported-selected-{selected_type}-{command}', 'selected': 1,
                          'command': command, 'scale': 1.0,
                          'vessels': [vessel(202), vessel(selected_type, y=0, width=9, height=100)]})
    for selected_type in [204, 207, 208, 211]:
        for height in [99, 101]:
            for scale in [0.75, 1.3]:
                cases.append({'name': f'odd-outlet-{selected_type}-h{height}-s{scale}', 'selected': 1,
                              'command': 2 if selected_type == 204 else 3, 'scale': scale,
                              'vessels': [vessel(201), vessel(selected_type, x=103, y=-1, width=9, height=height)]})
    for x in [95, 96, 104, 105]:
        for y in [-11, -10, -9, 46, 47, 48]:
            cases.append({'name': f'aspirate-strict-x{x}-y{y}', 'selected': 1, 'command': 1, 'scale': 1.0,
                          'vessels': [vessel(202, height=100), vessel(204, x=x, y=y, width=9, height=100)]})
    return cases


def main():
    oracle = ActionsOracle()
    output = {'binary_sha256': EXPECTED, 'function': '0x00477708',
              'contract': 'Original x86 selection/state/dose instructions; explicit bitmap getters/initial draw boundaries; transfer CALL arguments captured; selected native liquid-total cache explicitly 0 to bypass falling-drop drawing.',
              'cases': []}
    for case in cases():
        output['cases'].append(oracle.execute_case(case))
    destination = ROOT / 'evidence/original_logic/native-actions-oracle.json'
    destination.write_text(json.dumps(output, ensure_ascii=False, indent=2) + '\n')
    print(f'Executed {len(output["cases"])} original manual-action frames -> {destination}')


if __name__ == '__main__':
    main()
