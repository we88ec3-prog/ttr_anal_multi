#!/usr/bin/env python3
"""Read-only selected-range identity check; no target execution or semantic verdict."""
import argparse
import hashlib
import json
import pathlib
import struct

ORIGINAL = "9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
WORKING_COPY = "6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c"
RANGES = [(0x440790, 0xA0), (0x4A31B0, 0x190), (0x4A3360, 0x1D0),
          (0x47F540, 0x130), (0x733C30, 0x190), (0x733DD0, 0x100),
          (0x8098E0, 0x100), (0x809A10, 0x60), (0x809A70, 0x130), (0x809BA0, 0xA00)]


def mapped(path):
    data = path.read_bytes()
    if data[:2] != b"MZ":
        raise ValueError("Expected PE32 executable")
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    if data[pe:pe + 4] != b"PE\0\0":
        raise ValueError("Invalid PE header")
    count = struct.unpack_from("<H", data, pe + 6)[0]
    optional_size = struct.unpack_from("<H", data, pe + 20)[0]
    optional = pe + 24
    if struct.unpack_from("<H", data, optional)[0] != 0x10B:
        raise ValueError("Expected PE32 optional header")
    base = struct.unpack_from("<I", data, optional + 28)[0]
    sections = []
    for i in range(count):
        entry = optional + optional_size + i * 40
        _, va, raw_size, raw_offset = struct.unpack_from("<IIII", data, entry + 8)
        sections.append((base + va, raw_size, raw_offset))

    def read(va, size):
        for start, raw_size, offset in sections:
            if start <= va and va + size <= start + raw_size:
                first = offset + va - start
                result = data[first:first + size]
                if len(result) == size:
                    return result
        raise ValueError("Selected range is not fully file-backed")
    return hashlib.sha256(data).hexdigest(), read


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=pathlib.Path)
    parser.add_argument("working_copy", type=pathlib.Path)
    args = parser.parse_args()
    original_sha, original = mapped(args.original)
    copy_sha, copy = mapped(args.working_copy)
    if original_sha != ORIGINAL or copy_sha != WORKING_COPY:
        raise ValueError("Exact original/working-copy SHA mismatch")
    rows = [{"va": hex(va), "size": size, "identical": original(va, size) == copy(va, size),
             "original_range_sha256": hashlib.sha256(original(va, size)).hexdigest()}
            for va, size in RANGES]
    print(json.dumps({"original_sha256": original_sha, "working_copy_sha256": copy_sha,
        "scope": "Selected byte ranges only; not whole functions, provenance, native semantic review or runtime proof",
        "ranges": rows}, indent=2))
    return 0 if all(row["identical"] for row in rows) else 1


if __name__ == "__main__":
    raise SystemExit(main())
