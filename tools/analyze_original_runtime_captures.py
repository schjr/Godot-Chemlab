"""Read-only validation and byte deltas for the user-exported original captures."""
import hashlib
import argparse
import json
import math
from pathlib import Path
import struct

ROOT = Path(__file__).resolve().parents[1]
CAPTURES = ROOT / "evidence/windows-runtime/original-captures-2026-10-14"
EXPECTED_IMAGE = "7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c"
ARRAYS = ("volume_0x5b8", "solid_0x3cd8", "solid_0x3ff8", "moles_0x8d8", "mass_0x298")
SCALARS = ("0x4318", "0x3cc8", "0x4338", "0x3cc0")


def inspect(path):
    raw = path.read_bytes()
    data = json.loads(raw.decode("utf-8-sig"))
    assert data["format"] == "ChemLab-original-read-only-memory-profile"
    assert data["version"] == 1
    assert data["provenance"]["image_sha256"] == EXPECTED_IMAGE
    assert data["provenance"]["process_pointer_bits"] == 32
    assert data["provenance"]["runtime_module_base"] == "0x00400000"
    snapshots = []
    for source in data["snapshots"]:
        assert source["apparatus_identity_stable_during_read"]
        assert not source["run_state_before"]["simulation_advancing"]
        assert not source["run_state_after"]["simulation_advancing"]
        vessels = []
        for record in source["vessels"]:
            assert record["status"] == "read" and record["species_identity_stable_during_read"]
            assert record["species_count_0x104"] == len(record["species"])
            assert all(entry["status"] == "read" for entry in record["species"])
            names = [species["text"] for species in record["species"]]
            assert len(names) <= 100
            arrays = {}
            for field in ARRAYS:
                original = record["arrays"][field]
                cells = bytes.fromhex(original["raw_hex"])
                assert original["count"] == 100 and len(cells) == 800
                assert len(original["slots"]) == 100
                values = struct.unpack("<100d", cells)
                for i, entry in enumerate(original["slots"]):
                    assert entry["slot"] == i
                    assert entry["ieee754_le_hex"] == cells[i*8:i*8+8].hex()
                arrays[field] = {
                    "nonzero_indices": [i for i in range(100) if cells[i*8:i*8+8] != bytes(8)],
                    "nonfinite_indices": [i for i,n in enumerate(values) if not math.isfinite(n)],
                    "subnormal_indices": [i for i,n in enumerate(values) if n != 0 and abs(n) < 2**-1022],
                }
            moles = struct.unpack("<100d", bytes.fromhex(record["arrays"]["moles_0x8d8"]["raw_hex"]))
            for field in SCALARS:
                if field not in record["scalars"]:
                    continue  # Older captures omit +3CC0; never infer a value.
                scalar_hex = record["scalars"][field]["ieee754_le_hex"]
                assert len(scalar_hex) == 16 and len(bytes.fromhex(scalar_hex)) == 8
            vessels.append({"index": record["native_index"], "pointer": record["pointer"],
                            "label": record["label"]["text"], "active_moles": dict(zip(names,moles)),
                            "arrays": arrays, "scalars": record["scalars"]})
        snapshots.append({"label":source["label"],"elapsed":source["run_state_before"]["elapsed_005636cc"],"vessels":vessels})
    return data, {"file":str(path.resolve()),"sha256":hashlib.sha256(raw).hexdigest(),"status":"validated","snapshots":snapshots}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--directory", type=Path, default=CAPTURES)
    parser.add_argument("--cold", default="cold-opening")
    parser.add_argument("--running", default="after-run-paused")
    parser.add_argument("--after", default="after-naoh")
    args = parser.parse_args()
    actual = {}; report = {"captures":{},"post_run_to_after_naoh":[]}
    for name in (args.cold, args.running, args.after):
        actual[name], report["captures"][name] = inspect(args.directory / (name+".json"))
    assert actual[args.running]["provenance"]["process_id"] == actual[args.after]["provenance"]["process_id"], "Cannot compare allocation deltas across different processes"
    before = actual[args.running]["snapshots"][0]
    after = actual[args.after]["snapshots"][0]
    assert len(before["vessels"]) == len(after["vessels"]), "Apparatus count changed"
    for a,b in zip(before["vessels"],after["vessels"]):
        deltas = {}
        for field in ARRAYS:
            va=struct.unpack("<100d",bytes.fromhex(a["arrays"][field]["raw_hex"]))
            vb=struct.unpack("<100d",bytes.fromhex(b["arrays"][field]["raw_hex"]))
            deltas[field] = {"changed_indices":[i for i in range(100) if a["arrays"][field]["slots"][i]["ieee754_le_hex"] != b["arrays"][field]["slots"][i]["ieee754_le_hex"]],
                             "active_delta":[vb[i]-va[i] for i in range(len(a["species"]))]}
        report["post_run_to_after_naoh"].append({"index":a["native_index"],"same_pointer":a["pointer"]==b["pointer"],
                                                "same_species":a["species"]==b["species"],"same_scalars":a["scalars"]==b["scalars"],"deltas":deltas})
    report["elapsed_changed_after_click"] = before["run_state_before"]["elapsed_005636cc"] != after["run_state_before"]["elapsed_005636cc"]
    print(json.dumps(report,ensure_ascii=False,indent=2))


if __name__ == "__main__":
    main()
