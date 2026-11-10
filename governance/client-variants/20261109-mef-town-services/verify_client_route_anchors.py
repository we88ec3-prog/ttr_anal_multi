"""Read-only bounded PE anchors. No Client execution, attachment or native calls."""
import argparse
import hashlib
from pathlib import Path
import struct

SOURCE_SHA256 = "9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
ANCHORS = {
    0xC0C9FC: bytes.fromhex("e01a4d00"),  # CMonster v+20 -> update thunk
    0x4D1AE0: bytes.fromhex("e99b6affff"),  # jmp 4C8580
    0x4C85AD: bytes.fromhex("e8de220000"),  # call 4CA890
    0xC0CA30: bytes.fromhex("e0ab4c00"),  # CMonster v+54 -> collision move
    0x82CDF0: bytes.fromhex(
        "558bec83ec1453568bf18b5e245785db750e395e28750933c05f5e5b8be55dc3"
    ),  # Only the null-grid early-return block, not the complete function.
}
COMPARISON_WINDOWS = {
    0x4B2730: 0x1A0, 0x4CA890: 0x268, 0x4CABE0: 0xDA,
    0x4DF1A0: 0x2E2, 0x4DF510: 0x510, 0x82CDF0: 0x82, 0xC0CEB0: 32,
}


def image_reader(path, expected_sha256):
    data = path.read_bytes()
    if hashlib.sha256(data).hexdigest() != expected_sha256.lower():
        raise ValueError("Source identity mismatch.")
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    if data[pe:pe+4] != b"PE\0\0":
        raise ValueError("Missing PE signature.")
    count = struct.unpack_from("<H", data, pe+6)[0]
    opt_size = struct.unpack_from("<H", data, pe+20)[0]
    opt = pe+24
    if struct.unpack_from("<H", data, opt)[0] != 0x10B:
        raise ValueError("PE32 required.")
    base = struct.unpack_from("<I", data, opt+28)[0]
    def read(address, length):
        rva = address-base
        offsets = []
        for index in range(count):
            at = opt+opt_size+index*40+8
            virtual_size, start, raw_size, raw_offset = struct.unpack_from("<IIII", data, at)
            if start <= rva and rva+length <= start+min(virtual_size, raw_size):
                offsets.append(raw_offset+rva-start)
        if len(offsets) != 1:
            raise ValueError("Ambiguous or absent file-backed anchor.")
        offset = offsets[0]
        return data[offset:offset+length]
    return read


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--binary", type=Path, required=True)
    parser.add_argument("--comparison-binary", type=Path)
    parser.add_argument("--comparison-sha256")
    args = parser.parse_args()
    if bool(args.comparison_binary) != bool(args.comparison_sha256):
        raise ValueError("Comparison path and independently identified hash are required together.")
    original = image_reader(args.binary, SOURCE_SHA256)
    for address, expected in ANCHORS.items():
        if original(address, len(expected)) != expected:
            raise ValueError(f"Anchor mismatch at {address:#x}.")
    print(f"Verified {len(ANCHORS)} bounded KR anchors; source {SOURCE_SHA256}.")
    if args.comparison_binary:
        comparison = image_reader(args.comparison_binary, args.comparison_sha256)
        for address, length in COMPARISON_WINDOWS.items():
            if original(address, length) != comparison(address, length):
                raise ValueError(f"Comparison differs in bounded window {address:#x}/{length}.")
        print(f"Compared {len(COMPARISON_WINDOWS)} exact windows; comparison {args.comparison_sha256.lower()}.")
    print("Not full-function review, runtime grid observation, route acceptance or native MEF support.")


if __name__ == "__main__":
    main()
