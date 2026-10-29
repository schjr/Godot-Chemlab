"""Execute original 004926E0; bitmap scanline/dimensions are declared boundaries."""
from pathlib import Path
import json, struct, random
from original_visual_oracle import PixelOracle, EXPECTED, bits
ROOT = Path(__file__).resolve().parents[1]
def main():
    oracle=PixelOracle();cases=[]
    words=[0,0xFFFFFF,0xFFFFFFFF,0x123456,0xAABBCCDD,0xFEFDFB,0x77FFFFFF]
    rng=random.Random(0x4926E0)
    pairs=[(a,b,w) for a in words for b in words for w in [0.3,1.0]]
    pairs += [(rng.getrandbits(32),rng.getrandbits(32),w) for _ in range(500) for w in [0.3,1.0]]
    for destination,mask,weight in pairs:
        oracle.u32(oracle.first_pixels,destination);oracle.u32(oracle.second_pixels,mask)
        oracle.call(0x4926e0,struct.pack('<IIIId',0,0,oracle.second,oracle.first,weight))
        cases.append({'destination':destination,'mask':mask,'weight_bits':bits(weight),'native_result':oracle.u32(oracle.first_pixels)})
    out=ROOT/'evidence/original_logic/native-vessel-pixels-oracle.json'
    out.write_text(json.dumps({'binary_sha256':EXPECTED,'function':'0x004926E0','contract':'Original native pixel instructions; dimensions, scanline and 32-to-32 format property are declared VCL boundaries. No GDI primitive or preconversion pixel claim.','cases':cases},indent=2)+'\n')
    print(f'Executed {len(cases)} original vessel fill-mask pixel frames -> {out}')
if __name__=='__main__':main()
