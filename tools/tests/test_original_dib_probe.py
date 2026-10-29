"""Source and read-only API preflight; does not claim Windows pixels captured."""
import hashlib
from pathlib import Path
import re
import struct
import unittest

ROOT = Path(__file__).resolve().parents[2]

def pe_bytes(address, length):
    raw = (ROOT / "artifacts/ChemLab/_main.exe").read_bytes()
    assert hashlib.sha256(raw).hexdigest() == "7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c"
    nt = struct.unpack_from("<I", raw, 60)[0]
    sections = struct.unpack_from("<H", raw, nt + 6)[0]
    opt = struct.unpack_from("<H", raw, nt + 20)[0]
    for i in range(sections):
        _, rva, size, offset = struct.unpack_from("<4I", raw, nt + 24 + opt + i * 40 + 8)
        if 0x400000 + rva <= address < 0x400000 + rva + size:
            return raw[offset + address - 0x400000 - rva:offset + address - 0x400000 - rva + length]
    raise ValueError("Address outside original image")

class OriginalDibProbePreflight(unittest.TestCase):
    def test_exact_native_metadata_reads(self):
        # 4E95C1 MOV EAX,[EBX+20]; ADD EAX,18; EBP=EAX; ESI=EAX+18.
        self.assertEqual(pe_bytes(0x4E95C1, 11).hex(), "8b432083c0188be88d7018")
        # Height=[ESI+8]; bpp=WORD[ESI+E]; width=[ESI+4]; pointer=[EBP+14].
        self.assertEqual(pe_bytes(0x4E95EB, 3).hex(), "8b4608")
        self.assertEqual(pe_bytes(0x4E95F7, 4).hex(), "0fb7560e")
        self.assertEqual(pe_bytes(0x4E9600, 3).hex(), "8b4604")
        self.assertEqual(pe_bytes(0x4E960A, 3).hex(), "034514")

    def test_reader_has_only_read_query_apis(self):
        code = (ROOT / "tools/windows/original_dib_read_probe.cs").read_text()
        calls = set(re.findall(r"extern\s+\w+\s+(\w+)\(", code))
        self.assertEqual(calls, {"OpenProcess", "ReadProcessMemory", "CloseHandle", "QueryFullProcessImageNameW", "CreateToolhelp32Snapshot", "Module32FirstW", "Module32NextW"})
        self.assertIn("OpenProcess(0x0010 | 0x1000, false", code)
        script = (ROOT / "tools/windows/read_original_dib_pixels.ps1").read_text()
        for forbidden in ("WriteProcessMemory", "CreateRemoteThread", "SuspendThread", "VirtualAllocEx", "Set-ExecutionPolicy", "GdiFlush(", "GetDIBits(", "TcpClient"):
            self.assertNotIn(forbidden, script)
        self.assertIn("$bits=[BitConverter]::ToUInt32($metadata,0x2c)", script)
        self.assertIn("$record.gdi_flush_in_target=$false", script)
        self.assertIn("'Original simulation is advancing; this reader will not pause it'", script)
        self.assertIn("Sort-Object modBaseAddr,modBaseSize,szExePath -Unique", script)
        self.assertIn("$modules.Count -ne 1", script)

if __name__ == "__main__":
    unittest.main()
