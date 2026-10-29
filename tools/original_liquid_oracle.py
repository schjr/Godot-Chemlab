"""Run original 0x471650 liquid rendering arithmetic, hosting VCL presentation.

Dimensions and chemical slot values are explicit inputs. Original x86 color,
indicator, volume clamp, and height instructions run unmodified.
"""
from pathlib import Path
import json
import struct
from original_actions_oracle import ActionsOracle, bits
from original_x86_oracle import EXPECTED
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EDX, UC_X86_REG_ECX, UC_X86_REG_ESP

ROOT = Path(__file__).resolve().parents[1]

class LiquidOracle(ActionsOracle):
    def __init__(self):
        super().__init__()
        self.rectangles = []
        self.hooks.update({0x4e4158:self.presentation_property, 0x4e3e50:self.presentation_property,
                           0x4e4274:self.presentation_property, 0x4e4744:self.rectangle})
        for i, record in enumerate(self.catalog):
            p = self.u32(0x57bc08 + i*4)
            self.u32(p + 0x28, record['color_integer'])
        self.u32(0x57a748, self.species['H2O(液体)']['color_integer'])

    def presentation_property(self):
        self.graphics_boundaries.append('VCL pen/brush presentation property')
        self.ret()

    def rectangle(self):
        sp = self.uc.reg_read(UC_X86_REG_ESP)
        def signed(v):return v if v < 0x80000000 else v-0x100000000
        self.rectangles.append([signed(self.uc.reg_read(UC_X86_REG_EDX)), signed(self.uc.reg_read(UC_X86_REG_ECX)),
                                signed(self.u32(sp+4)), signed(self.u32(sp+8))])
        self.initial_rectangle()

    def execute_case(self, case):
        self.vessels.clear(); self.rectangles.clear(); self.boundary_calls.clear()
        index = self.add_vessel(case['contents'], capacity=case['capacity'], volume_cache=case.get('volumes'))
        p = self.vessels[index]
        self.u32(p + 8, case['type']); self.u32(p + 0xfc, self.bitmap(case['width'],case['height']))
        # FUN_0040A4B8 resets this before calling the liquid and gas routines.
        self.f64(p + 0x30, 0.0)
        self.call(0x471650, struct.pack('<II', self.bitmap(case['width'],case['height']), index))
        return {**case, 'capacity_bits':bits(case['capacity']),
                'contents_bits':{k:bits(v) for k,v in case['contents'].items()},
                'volumes_bits':{self.text_at(self.u32(p+0x108+i*4)):bits(self.f64(p+0x5b8+i*8)) for i in range(self.u32(p+0x104))},
                'height_bits':bits(self.f64(p+0x30)),
                'liquid_volume_bits':bits(self.f64(p+0x4320)), 'color':self.u32(p+0x3cd0),
                'rectangles':self.rectangles.copy(), 'boundaries':sorted(set(self.boundary_calls))}

def main():
    oracle=LiquidOracle()
    cases=[]
    for typ,cap,w,h in [(101,20,20,90),(102,100,42,46),(103,100,55,65),(104,100,53,78),
                       (105,100,52,78),(106,40,110,16),(107,150,50,82),(108,30,40,90),
                       (121,50,45,19),(201,100,36,53),(202,100,34,52),(204,4,10,76),
                       (207,50,20,250),(208,50,20,250),(209,100,53,94),(210,100,30,104),
                       (211,100,35,167),(212,100,50,44)]:
        for fraction in [0.0,0.01,0.1,0.5,0.99,1.0,1.2]:
            for solute in [None,'CuSO4(溶解)','FeCl3(溶解)']:
                content={'H2O(液体)':cap*fraction/18.016}
                if solute:content[solute]=0.0004
                cases.append({'name':f'type{typ}-v{fraction}-{solute}', 'type':typ,'capacity':cap,
                              'width':w,'height':h,'contents':content})
    # Exact original names from the library, and original thresholds around pH bands.
    indicators=[r['species'] for r in oracle.catalog if '(指示剂)' in r['species']]
    for indicator in indicators:
        for ph in [2.0,3.2,4.5,5.0,7.0,8.0,9.0,10.0,12.0]:
            cases.append({'name':f'{indicator}-ph{ph}','type':102,'capacity':100,'width':42,'height':46,
                          'contents':{'H2O(液体)':40/18.016,'H+(离子)':40/1000*10**(-ph),indicator:1e-8}})
    result={'binary_sha256':EXPECTED,'entry':'0x00471650','cases':[oracle.execute_case(c) for c in cases],
            'constants':{hex(a):bytes(oracle.uc.mem_read(a,10)).hex() for a in [0x472cf4,0x472d20,0x472d4c]},
            'limitations':['VCL bitmap dimensions and pen/brush/rectangle presentation are hosted.',
                           'Original CRT pow/log10 and x87 instructions execute in the original PE.']}
    output=ROOT/'godot/tests/fixtures/original_liquid.json'
    output.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n')
    print(f"Original liquid renderer: {len(result['cases'])} frames; constants {result['constants']}")

if __name__=='__main__':main()
