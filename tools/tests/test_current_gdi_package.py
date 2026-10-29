"""Integrity and original-operation provenance checks, without pretending to run GDI."""
import base64
import hashlib
import json
from pathlib import Path
import unittest
import zipfile

ROOT = Path(__file__).resolve().parents[2]

class CurrentGdiPackageTests(unittest.TestCase):
    def test_archive_integrity_and_bounded_native_operations(self):
        with zipfile.ZipFile(ROOT / "build/windows-reference/current-gdi-probes.zip") as archive:
            manifest = json.loads(archive.read("manifest.json"))
            self.assertEqual(set(archive.namelist()), {"manifest.json", *(row["path"] for row in manifest["files"])})
            for row in manifest["files"]:
                raw = archive.read(row["path"])
                self.assertEqual(hashlib.sha256(raw).hexdigest(), row["sha256"])
                self.assertEqual(len(raw), row["bytes"])
            self.assertEqual(hashlib.sha256(archive.read("guti.bmp")).hexdigest(), "c4087e0532dfa5aa9e6a148c1da5a34f0845b03b0ef7af003b66a93b0fcb4f31")
            corpus = json.loads(archive.read("current-gdi-cases.json"))
            self.assertEqual(len(corpus["cases"]), 57)
            self.assertEqual(len({c["id"] for c in corpus["cases"]}), 57)
            source_cache = {}
            for fixture in corpus["source_fixtures"]:
                raw = (ROOT / fixture["path"]).read_bytes()
                self.assertEqual(hashlib.sha256(raw).hexdigest(), fixture["sha256"])
                source_cache[fixture["path"]] = json.loads(raw)
            for case in corpus["cases"]:
                self.assertLessEqual(case["width"], 256)
                self.assertLessEqual(case["height"], 256)
                self.assertLessEqual(len(case["operations"]), 16)
                self.assertIn(case["bitmap_format"], (0, 24, 32))
                if "initial_bgra" in case:
                    self.assertEqual(len(base64.b64decode(case["initial_bgra"])), case["width"] * case["height"] * 4)
                evidence = case["evidence"]
                if evidence["kind"] == "original_instruction_record":
                    fixture = source_cache[evidence["fixture"]]
                    if "case_index" in evidence:
                        original = fixture["cases"][evidence["case_index"]]
                        expected = original["native_operations"]
                    else:
                        original = next(c for c in fixture["cases"] if c["name"] == evidence["case"])
                        expected = []
                        for op in original["native_operations"]:
                            if op["op"] == "tint_nonwhite":
                                break
                            expected.append(op)
                    self.assertEqual(case["operations"], expected)
                    self.assertEqual((case["width"], case["height"]), (original["width"], original["height"]))
            runner = archive.read("run_current_gdi_probes.ps1").decode()
            self.assertNotIn("ExecutionPolicy", runner)
            self.assertNotIn("TcpListener", runner)
            self.assertIn("native_vcl_verified=$false", runner)
            self.assertIn("$case.PSObject.Properties['initial_bgra']", runner)
            self.assertNotIn("if($case.initial_bgra)", runner)
            self.assertIn("if($op.op -eq 'arc')", runner)
            self.assertNotIn("Set-StrictMode -Off", runner)
            host = archive.read("original_gdi_host.ps1").decode()
            self.assertIn("IsLoopback", host)

if __name__ == "__main__":
    unittest.main()
