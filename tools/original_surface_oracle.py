"""Original 00473E6C arithmetic/call operands; primitive GDI is a boundary."""
import struct,json
from pathlib import Path
from original_visual_oracle import VisualOracle,bits,EXPECTED
ROOT=Path(__file__).resolve().parents[1]
def main():
 oracle=VisualOracle();cases=[]
 for kind in [100,101,102,103,104,105,106,107,108,109,120,121,201,202,203,204,205,206,207,208,209,210,211,212,213,300]:
  for color,height in [(0,0),(0xFFFFFF,.999),(0x123456,1.001),(0xFEDCBA,21.7),(0x808080,101.3),(0x112233,-3.5)]:
   oracle.allocation=oracle.fixture_origin;oracle.vessels.clear();oracle.bitmaps.clear();oracle.operations.clear()
   index=oracle.add_vessel({},capacity=100);pointer=oracle.vessels[index];bitmap=oracle.bitmap(43,101)
   oracle.u32(pointer+8,kind);oracle.u32(pointer+0x3cd0,color);oracle.u32(pointer+0xfc,bitmap);oracle.f64(pointer+0x30,height)
   oracle.pen_color=0;oracle.brush_color=0x556677;oracle.brush_style=0
   oracle.call(0x473e6c,struct.pack('<II',bitmap,index))
   cases.append({'type':kind,'color':color,'height_bits':bits(height),'width':43,'height':101,'native_pen_color':oracle.pen_color,'native_brush_style':oracle.brush_style,'native_operations':oracle.operations.copy()})
 out=ROOT/'evidence/original_logic/native-surface-oracle.json';out.write_text(json.dumps({'binary_sha256':EXPECTED,'function':'0x00473E6C','contract':'Original numeric instructions execute; GDI pen/brush changes and Rectangle operands captured, no raster-edge claim. Helper is directly called including values caller normally suppresses.','cases':cases},indent=2)+'\n');print(f'Executed {len(cases)} original surface-outline frames -> {out}')
if __name__=='__main__':main()
