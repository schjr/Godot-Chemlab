#!/usr/bin/env -S uv run --no-project --script
"""Export CHEMS.CSB read-only, then create a portable SQLite reconstruction.

UV_CACHE_DIR=/private/tmp/chemlab-uv-cache uv run --no-project tools/database_recover.py
Use --fetch-dependencies on a clean machine (Java 11+ and uv required).
The supplied password is read only by the Java reader, never logged or exported.
"""
from __future__ import annotations

import argparse
import base64
import hashlib
import json
import sqlite3
import subprocess
import urllib.request
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
LIBRARIES = [
    ("com/healthmarketscience/jackcess/jackcess/4.0.8/jackcess-4.0.8.jar", "bb84e5c7367dedf3a5cea7ad2d37e6874bb688f9003edb92749ef032be25671e"),
    ("com/healthmarketscience/jackcess/jackcess-encrypt/4.0.3/jackcess-encrypt-4.0.3.jar", "d40a7871ac1dc6343cd2e433c3ee484eb59cdff728b7a1e22dcfc8b3f400a18a"),
    ("org/apache/commons/commons-lang3/3.10/commons-lang3-3.10.jar", "28968ae55fff465494083aeba856f8824c34902329882bf61e77246a91e25aa9"),
    ("commons-logging/commons-logging/1.2/commons-logging-1.2.jar", "daddea1ea0be0f56978ab3006b8ac92834afeefbd9b7e4e6316fca57df0fa636"),
    ("org/bouncycastle/bcprov-jdk18on/1.78/bcprov-jdk18on-1.78.jar", "1bf721b09758b3f55f2a5c875b6178ec6c41dddad854b0dead4b27a236f1943a"),
]


def digest(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def quote(value: str) -> str:
    return '"' + value.replace('"', '""') + '"'


def sqlite_type(access_type: str) -> str:
    if access_type in {"BYTE", "INT", "LONG", "BIG_INT", "BOOLEAN"}:
        return "INTEGER"
    if access_type in {"FLOAT", "DOUBLE", "MONEY", "NUMERIC"}:
        return "REAL"
    if access_type in {"BINARY", "OLE"}:
        return "BLOB"
    return "TEXT"


def convert(value):
    if isinstance(value, dict) and "$binary_base64" in value:
        return base64.b64decode(value["$binary_base64"])
    return value


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--source", type=Path, default=ROOT / "artifacts/ChemLab/CHEMS.CSB")
    parser.add_argument("--password-note", type=Path, default=ROOT / "artifacts/ChemLab/逆向说明.txt")
    parser.add_argument("--output", type=Path, default=ROOT / "recovered/database")
    parser.add_argument("--library-cache", type=Path, default=Path("/private/tmp/chemlab-db-libs"))
    parser.add_argument("--fetch-dependencies", action="store_true")
    args = parser.parse_args()
    before = digest(args.source)
    args.library_cache.mkdir(parents=True, exist_ok=True)
    for url_path, expected in LIBRARIES:
        path = args.library_cache / Path(url_path).name
        if not path.exists():
            if not args.fetch_dependencies:
                parser.error(f"Missing {path.name}; rerun with --fetch-dependencies")
            with urllib.request.urlopen("https://repo.maven.apache.org/maven2/" + url_path) as response:
                path.write_bytes(response.read())
        if digest(path) != expected:
            raise RuntimeError(f"Dependency checksum mismatch: {path.name}")
    args.output.mkdir(parents=True, exist_ok=True)
    subprocess.run([
        "java", "-cp", str(args.library_cache / "*"), str(ROOT / "tools/DatabaseRecover.java"),
        str(args.source), str(args.password_note), str(args.output),
    ], check=True)
    if digest(args.source) != before:
        raise RuntimeError("Source database changed during recovery")
    schema_file = args.output / "schema.json"
    schema = json.loads(schema_file.read_text())
    schema_file.write_text(json.dumps(schema, ensure_ascii=False, indent=2) + "\n")
    db_path = args.output / "chemlab.sqlite3"
    temporary = args.output / "chemlab.sqlite3.tmp"
    temporary.unlink(missing_ok=True)
    sql = []
    total = 0
    with sqlite3.connect(temporary) as db:
        for table in schema["tables"]:
            name = table["name"]
            columns = table["columns"]
            parts = [f'{quote(c["name"])} {sqlite_type(c["type"])}' for c in columns]
            primary = next((i for i in table["indexes"] if i["primary_key"]), None)
            if primary:
                parts.append("PRIMARY KEY (" + ", ".join(quote(c["name"]) for c in primary["columns"]) + ")")
            statement = f"CREATE TABLE {quote(name)} (" + ", ".join(parts) + ");"
            sql.append(statement)
            db.execute(statement)
            rows = json.loads((args.output / table["data_file"]).read_text())
            if len(rows) != table["declared_rows"]:
                raise RuntimeError(f"Row count mismatch: {name}")
            db.executemany(f"INSERT INTO {quote(name)} VALUES (" + ",".join("?" for _ in columns) + ")",
                           [[convert(row[c["name"]]) for c in columns] for row in rows])
            for index in table["indexes"]:
                if index["primary_key"]:
                    continue
                statement = "CREATE " + ("UNIQUE " if index["unique"] else "") + "INDEX "
                statement += quote(name + "__" + index["name"]) + " ON " + quote(name)
                statement += " (" + ", ".join(quote(c["name"]) + (" ASC" if c["ascending"] else " DESC") for c in index["columns"]) + ");"
                db.execute(statement)
                sql.append(statement)
            fetched = db.execute(f"SELECT * FROM {quote(name)}").fetchall()
            expected_rows = [tuple(convert(row[c["name"]]) for c in columns) for row in rows]
            if fetched != expected_rows:
                raise RuntimeError(f"Round-trip value mismatch: {name}")
            total += len(rows)
        if db.execute("PRAGMA integrity_check").fetchone()[0] != "ok":
            raise RuntimeError("SQLite integrity check failed")
    temporary.replace(db_path)
    (args.output / "schema.sqlite.sql").write_text("\n".join(sql) + "\n")
    manifest = {
        "source_sha256": before, "source_size": args.source.stat().st_size,
        "original_source_unchanged": True, "reader": "Jackcess 4.0.8 + Jackcess Encrypt 4.0.3",
        "tables": len(schema["tables"]), "rows": total,
        "sqlite_values_match_json": True, "sqlite_integrity_check": "ok",
        "artifacts": {str(p.relative_to(args.output)): digest(p)
                      for p in sorted(args.output.rglob("*")) if p.is_file() and p.name != "manifest.json" and p.suffix != ".md"},
    }
    (args.output / "manifest.json").write_text(json.dumps(manifest, indent=2) + "\n")
    print(f"Validated {total} records in {len(schema['tables'])} tables; source unchanged.")


if __name__ == "__main__":
    main()
