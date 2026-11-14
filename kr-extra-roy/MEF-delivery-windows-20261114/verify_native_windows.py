#!/usr/bin/env python3
"""Verify bounded evidence against immutable KR originals; never execute them.

Uses only Python's standard library. An optional assembly export invokes objdump
on temporary byte slices, never on an executable process. This checks provenance
and exact bytes, not runtime behavior, full-program completeness, or T01 approval.
"""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import tempfile


EXPECTED = {
    "game": "9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91",
    "launcher": "03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f",
}


def number(value):
    return int(value, 0) if isinstance(value, str) else int(value)


def digest(data):
    return hashlib.sha256(data).hexdigest()


def read_pe(path, expected):
    data = path.read_bytes()
    actual = digest(data)
    if actual != expected:
        raise ValueError(f"Source SHA-256 mismatch: {path.name}: {actual}")
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    if data[:2] != b"MZ" or data[pe:pe + 4] != b"PE\0\0":
        raise ValueError("Invalid PE signatures")
    machine, count = struct.unpack_from("<HH", data, pe + 4)
    optional_size = struct.unpack_from("<H", data, pe + 20)[0]
    optional = pe + 24
    if machine != 0x14C or struct.unpack_from("<H", data, optional)[0] != 0x10B:
        raise ValueError("Expected PE32 i386")
    base = struct.unpack_from("<I", data, optional + 28)[0]
    sections = []
    for index in range(count):
        entry = optional + optional_size + 40 * index
        name = data[entry:entry + 8].split(b"\0")[0].decode("ascii")
        vsize, rva, raw_size, raw = struct.unpack_from("<IIII", data, entry + 8)
        sections.append({"name": name, "va": base + rva,
                         "virtual_size": vsize, "raw": raw, "raw_size": raw_size})
    return {"data": data, "path": path, "sha256": actual,
            "image_base": base, "sections": sections}


def map_va(source, va, length):
    if length <= 0:
        raise ValueError("Empty or reversed evidence window")
    for section in source["sections"]:
        delta = va - section["va"]
        if 0 <= delta and delta + length <= section["raw_size"]:
            raw = section["raw"] + delta
            if raw + length <= len(source["data"]):
                return raw
    raise ValueError(f"Unmapped or cross-section window: {hex(va)}, length {length}")


def check_window(source, record):
    start = number(record["start_va"])
    length = number(record["end_exclusive_va"]) - start
    raw = map_va(source, start, length)
    if raw != number(record["file_offset"]) or length != record["length"]:
        raise ValueError(f"PE mapping/length mismatch: {record['tag']}")
    wanted = bytes.fromhex(record["bytes_hex"])
    actual = source["data"][raw:raw + length]
    if actual != wanted or len(wanted) != length or digest(actual) != record["sha256"]:
        raise ValueError(f"Native byte/hash mismatch: {record['tag']}")
    return actual


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--bin", type=Path, required=True)
    parser.add_argument("--exe", type=Path, required=True)
    parser.add_argument("--manifest", type=Path,
                        default=Path(__file__).with_name("native-windows.json"))
    parser.add_argument("--out", type=Path, required=True, help="Verification result JSON")
    parser.add_argument("--asm", type=Path, help="Optional objdump assembly export")
    args = parser.parse_args()
    protected = {args.bin.resolve(), args.exe.resolve(), args.manifest.resolve(),
                 Path(__file__).resolve()}
    outputs = [args.out] + ([args.asm] if args.asm else [])
    if any(path.resolve() in protected for path in outputs):
        raise ValueError("Output must not overwrite an original, manifest, or verifier")
    if len({path.resolve() for path in outputs}) != len(outputs):
        raise ValueError("Output paths must be different")
    manifest = json.loads(args.manifest.read_text())
    sources = {"game": read_pe(args.bin, EXPECTED["game"]),
               "launcher": read_pe(args.exe, EXPECTED["launcher"])}
    counts = {key: 0 for key in sources}
    seen = set()
    assembly = []
    for record in manifest["windows"]:
        key = record["source"]
        identity = (key, record["tag"])
        if identity in seen:
            raise ValueError(f"Duplicate evidence identity: {identity}")
        seen.add(identity)
        actual = check_window(sources[key], record)
        counts[key] += 1
        if args.asm:
            assembly.append(f"\n; {key}: {record['tag']} {record['start_va']}.."
                            f"{record['end_exclusive_va']} (end exclusive)\n")
            if record.get("kind", "code") == "data":
                assembly.append("; data: " + actual.hex(" ") + "\n")
            else:
                with tempfile.NamedTemporaryFile(prefix="ttr-evidence-", suffix=".raw") as handle:
                    handle.write(actual)
                    handle.flush()
                    rendered = subprocess.check_output([
                        "objdump", "-D", "-b", "binary", "-m", "i386", "-M", "intel",
                        "--adjust-vma=" + record["start_va"], handle.name], text=True)
                    assembly.append(rendered.replace(handle.name, "<verified-byte-window>"))
    for anchor in manifest["anchors"]:
        source = sources[anchor["source"]]
        wanted = bytes.fromhex(anchor["bytes_hex"])
        raw = map_va(source, number(anchor["va"]), len(wanted))
        if source["data"][raw:raw + len(wanted)] != wanted:
            raise ValueError(f"Anchor mismatch: {anchor['tag']}")
    result = {
        "schema": "ttr-mef-delivery-window-verification-v1",
        "manifest_sha256": digest(args.manifest.read_bytes()),
        "targets": [{"source": key, "filename": source["path"].name,
                     "bytes": len(source["data"]), "sha256": source["sha256"],
                     "image_base": hex(source["image_base"]),
                     "sections": source["sections"]} for key, source in sources.items()],
        "windows_matched": counts, "total_windows": sum(counts.values()),
        "anchors_matched": len(manifest["anchors"]), "all_matched": True,
        "scope": "Static source identity and bounded bytes only. No target execution, "
                 "runtime timing proof, MEF parser certification, or T01 FULL-PASS."
    }
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n")
    if args.asm:
        args.asm.parent.mkdir(parents=True, exist_ok=True)
        args.asm.write_text("".join(assembly))
    print(json.dumps({"all_matched": True, "windows": counts,
                      "anchors": len(manifest["anchors"]), "result": str(args.out)},
                     ensure_ascii=False))


if __name__ == "__main__":
    main()
