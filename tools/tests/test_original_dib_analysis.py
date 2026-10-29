"""Synthetic transport guards only; no actual Windows/VCL pixel claim."""
import base64
from pathlib import Path
import struct
import sys
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from analyze_original_dib_capture import bitmap
from import_current_gdi_result import digest

def fixture(bpp=32, signed_height=2):
    width, height = 3, abs(signed_height)
    stride = ((width*bpp+31)//32)*4
    obj = bytearray(0x30)
    metadata = bytearray(0x74)
    struct.pack_into('<I', obj, 0, 0x4e2af4)
    struct.pack_into('<I', obj, 0x20, 0x1000)
    struct.pack_into('<iiiHHI', metadata, 0x1c, width,height,stride,1,bpp,0x2000)
    struct.pack_into('<IiiHHI', metadata, 0x30, 40,width,signed_height,1,bpp,0)
    raw = bytes(range(stride*height))
    rows = [raw[y*stride:(y+1)*stride] for y in range(height)]
    visual = b''.join(rows[::-1] if signed_height > 0 else rows)
    return dict(status='read', width=width,height=height,bit_count=bpp,planes=1,compression=0,header_size=40,
                metadata_and_pixels_stable_during_read=True,gdi_flush_in_target=False,signed_height=signed_height,
                row_stride=stride,storage_bytes=len(raw),bitmap_object_hex=obj.hex(),shared_image_hex=metadata.hex(),
                shared_pointer='0x00001000',bits_pointer='0x00002000',
                raw_storage_base64=base64.b64encode(raw).decode(),raw_storage_sha256=digest(raw),
                visual_topdown_base64=base64.b64encode(visual).decode(),visual_topdown_sha256=digest(visual))

class DibTransportGuards(unittest.TestCase):
    def test_both_row_orders_and24_bit_padding_remain_explicit(self):
        for bpp in (24,32):
            for signed in (-2,2):
                source=fixture(bpp,signed)
                result=bitmap(source)
                self.assertEqual(result['topdown_base64'],source['visual_topdown_base64'])
                self.assertEqual(result['bitmap_format'],bpp)
                self.assertEqual(result['row_stride'],12)

    def test_conflicting_or_unavailable_evidence_is_rejected(self):
        for field,value in [('row_stride',16),('status','unavailable'),('signed_height',3),('bit_count',8),
                            ('gdi_flush_in_target',True),('visual_topdown_sha256','0'*64),('shared_pointer','0x00003000')]:
            source=fixture();source[field]=value
            with self.assertRaises(ValueError,msg=field): bitmap(source)

if __name__=='__main__': unittest.main()
