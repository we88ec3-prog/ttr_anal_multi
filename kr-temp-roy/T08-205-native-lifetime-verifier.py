#!/usr/bin/env python3
"""Offline, read-only KR T08-205 code/VT evidence check. Never executes Client."""
import hashlib
import struct
import sys
from pathlib import Path

EXPECTED_SHA = "9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
EXPECTED_SIZE = 12472320
# Verified at real instruction boundaries against llvm-objdump of the KR PE32.
ANCHORS = {
    0x4B28FC: "8b 45 0c 83 f8 04 73 04",
    0x4B2915: "8b 4d 08 83 c1 04",
    0x4B29D9: "83 be 70 03 00 00 00",
    0x4B29E5: "e8 d6 52 2f 00",
    0x4B2A56: "8b 0d a4 a7 fb 00",
    0x4B2A82: "8b 01 8b 50 14 ff d2",
    0x4B2AC2: "e8 f9 d0 02 00",
    0x4B3730: "0f b7 06 0d 00 00 00 06",
    0x4B373E: "e8 4d c5 02 00",
    0x4DFBE4: "8b 0d a4 a7 fb 00",
    0x4DFBEC: "8b 42 1c 56 ff d0",
    0x4DFBF8: "8b 4f 10 8b 11 8b 42 14 ff d0",
    0x4DFC0D: "6a 01 ff d0",
    0x4DFC1E: "e8 6d 6c 2d 00",
    0x4DFCB6: "39 81 88 00 00 00",
    0x4DFCC0: "8b 42 14 ff d0",
    0x4DFCD2: "ff d0",
    0x4DFEA9: "8b 07 8b 50 14 8b cf ff d2",
    0x4DFEB6: "6a 01 8b cf ff d2",
    0x4DFF0A: "e8 41 39 34 00",
    0x4DFF0F: "8b 0d a4 a7 fb 00",
    0x4D18D0: "55 8b ec 56 8b f1",
    0x4D2280: "55 8b ec 6a ff",
    0x4D1F80: "e8 db 63 ff ff",
    0x4C8365: "8b 87 5c 01 00 00",
    0x4C7C19: "8b b3 60 01 00 00",
    0x4C7C21: "89 83 60 01 00 00",
    0x4C7C27: "89 83 5c 01 00 00",
    0x4C7C37: "f0 0f c1 08",
    0x4C7C43: "ff d0",
    0x4CA660: "8b 49 0c 85 c9 74 08",
    0x7A65D9: "8b 35 38 a8 fb 00",
    0x7A65E5: "83 c7 0c",
    0x7A664F: "89 38",
    0x7A6651: "83 86 b8 00 00 00 04",
    0x7BB264: "8b 86 b8 00 00 00",
    0x7BB2F0: "8b 8e b4 00 00 00",
    0x7BB2F6: "8b 0c b9 8b 11 8b 42 04 ff d0",
    0x7BB2FE: "ff d0",
    0x7BB330: "89 9e b8 00 00 00",
    0x7B8DCF: "8b 83 b4 00 00 00",
    0x7B8DDA: "e8 2d 84 0d 00",
    0x7B8DE2: "89 b3 b4 00 00 00",
    0x7B8DEE: "89 b3 bc 00 00 00",
    0x799F94: "e8 a7 12 02 00",
    0x7BA879: "e8 c2 09 00 00",
    0x7AAB41: "83 3d 38 a8 fb 00 00",
}
# Primary/secondary native tables; 4-byte slot values, not assumed type names.
VTABLES = {
    (0xC0C9DC, 0x00): 0x4D18D0,  # monster deleting destructor
    (0xC0C9DC, 0x14): 0x4D1F80,  # monster resource cleanup
    (0xC0CA9C, 0x00): 0x4D2280,  # NPC deleting destructor
    (0xC0CA9C, 0x14): 0x4D2860,  # NPC resource cleanup
    (0xC4F67C, 0x00): 0x7A4FF0,  # CDoll destructor
    (0xC4F67C, 0x08): 0x7A63C0,  # B-vector producer
    (0xC4F6B0, 0x08): 0x7A57C0,  # CDoll+8 cleanup interface
    (0xC4F6C0, 0x04): 0x7A8310,  # CDoll+0xC consumer
    (0xC0760C, 0x00): 0x4CA660,  # shared control callback
    (0xC4FC8C, 0x04): 0x7B8C80,  # manager deleting destructor
}
CALLS = {
    0x4B2AC2: 0x4DFBC0, 0x4B373E: 0x4DFC90,
    0x4D1F80: 0x4C8360, 0x4D18E6: 0x4C7B90,
    0x4D22E3: 0x4C7B90,
    0x799F94: 0x7BB240, 0x7BA879: 0x7BB240,
    0x7B8DDA: 0x89120C,
}


def main(path: str) -> None:
    b = Path(path).read_bytes()
    assert len(b) == EXPECTED_SIZE, f"file size changed: {len(b)}"
    assert hashlib.sha256(b).hexdigest() == EXPECTED_SHA, "KR BIN SHA mismatch"
    assert b[:2] == b"MZ"
    pe = struct.unpack_from("<I", b, 0x3c)[0]
    assert b[pe:pe + 4] == b"PE\0\0"
    machine, nsects = struct.unpack_from("<HH", b, pe + 4)
    assert machine == 0x14c, "not x86"
    opt_size = struct.unpack_from("<H", b, pe + 20)[0]
    sec = pe + 24 + opt_size
    sections = []
    for i in range(nsects):
        o = sec + i * 40
        name = b[o:o + 8].rstrip(b"\0").decode("ascii", "replace")
        virtual_size, rva, raw_size, raw_start = struct.unpack_from("<IIII", b, o + 8)
        sections.append((name, rva, max(virtual_size, raw_size), raw_start))
    image_base = struct.unpack_from("<I", b, pe + 24 + 28)[0]
    assert image_base == 0x400000

    def raw(va: int) -> int:
        rva = va - image_base
        for _name, srva, size, sraw in sections:
            if srva <= rva < srva + size:
                return sraw + (rva - srva)
        raise AssertionError(f"VA 0x{va:X} not mapped")

    assert raw(0x401000) == 0x400
    assert raw(0xBD2000) == 0x7D0600
    for va, hexstr in ANCHORS.items():
        expect = bytes.fromhex(hexstr)
        assert b[raw(va):raw(va) + len(expect)] == expect, f"code mismatch at 0x{va:X}"
    for (table, displacement), target in VTABLES.items():
        actual = struct.unpack_from("<I", b, raw(table + displacement))[0]
        assert actual == target, f"table mismatch at 0x{table:X}+0x{displacement:X}"
    for va, target in CALLS.items():
        off = raw(va)
        assert b[off] == 0xE8, f"not an E8 call at 0x{va:X}"
        disp = struct.unpack_from("<i", b, off + 1)[0]
        assert va + 5 + disp == target, f"call mismatch at 0x{va:X}"
    print(f"T08-205 KR BIN static evidence: PASS | {len(ANCHORS)} instruction anchors | "
          f"{len(VTABLES)} vtable slots | {len(CALLS)} E8 rel32 targets | "
          "size/SHA/PE headers/sections PASS")


if __name__ == "__main__":
    if len(sys.argv) != 2:
        raise SystemExit("usage: python -B T08-205-native-lifetime-verifier.py Tartaros.bin")
    main(sys.argv[1])
