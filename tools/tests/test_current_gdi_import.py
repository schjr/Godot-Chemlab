"""Negative import preflight only; these tests do not invent Windows pixels."""
import importlib.util
import json
from pathlib import Path
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[2]
spec = importlib.util.spec_from_file_location("gdi_import", ROOT / "tools/import_current_gdi_result.py")
module = importlib.util.module_from_spec(spec)
spec.loader.exec_module(module)
PACKAGE = ROOT / "build/windows-reference/current-gdi-probes"

class ImportGuards(unittest.TestCase):
    def test_duplicate_and_nonfinite_json_rejected(self):
        for raw in (b'{"format":1,"format":2}', b'{"value":NaN}'):
            with self.assertRaises(ValueError):
                module.decode(raw)

    def test_missing_result_cannot_be_imported(self):
        with self.assertRaisesRegex(ValueError, "result format"):
            module.validate(b'{}', PACKAGE)

    def test_false_vcl_attestation_rejected(self):
        with self.assertRaisesRegex(ValueError, "VCL verification"):
            module.validate(b'{"format":"chemlab-current-gdi-result-v1","native_vcl_verified":true}', PACKAGE)

    def test_wrong_corpus_rejected_before_pixels(self):
        with self.assertRaisesRegex(ValueError, "corpus hash"):
            module.validate(b'{"format":"chemlab-current-gdi-result-v1","native_vcl_verified":false,"corpus_sha256":"incorrect"}', PACKAGE)

    def test_local_package_tampering_rejected(self):
        with tempfile.TemporaryDirectory() as temporary:
            dest = Path(temporary)
            for path in PACKAGE.iterdir():
                if path.is_file():
                    (dest / path.name).write_bytes(path.read_bytes())
            with (dest / "original_gdi_host.cs").open("ab") as stream:
                stream.write(b"changed")
            with self.assertRaisesRegex(ValueError, "Package file hash"):
                module.validate(b'{}', dest)

if __name__ == "__main__":
    unittest.main()
