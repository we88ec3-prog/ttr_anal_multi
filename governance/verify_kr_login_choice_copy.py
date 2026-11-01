"""Read-only bounded KR instruction check. Not a Client run or T01 semantic approval.

Requires capstone==5.0.6; optionally supply an isolated package directory.
"""
import argparse
import hashlib
import json
import pathlib
import struct
import sys


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("binary", type=pathlib.Path)
    parser.add_argument("--capstone-dir", type=pathlib.Path)
    parser.add_argument("--output", type=pathlib.Path)
    args = parser.parse_args()
    if args.capstone_dir:
        sys.path.insert(0, str(args.capstone_dir.resolve()))
    import capstone
    if capstone.__version__ != "5.0.6":
        raise ValueError("Reproduce with capstone==5.0.6")
    data = args.binary.read_bytes()
    digest = hashlib.sha256(data).hexdigest()
    if digest != "9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91":
        raise ValueError("Original KR identity mismatch")
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    if data[pe:pe + 4] != b"PE\0\0":
        raise ValueError("PE signature mismatch")
    machine, count = struct.unpack_from("<HH", data, pe + 4)
    optional_size = struct.unpack_from("<H", data, pe + 20)[0]
    optional = pe + 24
    if machine != 0x14C or struct.unpack_from("<H", data, optional)[0] != 0x10B:
        raise ValueError("Expected PE32 x86")
    base = struct.unpack_from("<I", data, optional + 28)[0]
    sections = []
    for index in range(count):
        offset = optional + optional_size + 40 * index
        virtual_size, rva, raw_size, raw = struct.unpack_from("<IIII", data, offset + 8)
        sections.append((rva, raw_size, raw, virtual_size))

    def read(va, size):
        rva = va - base
        matches = [(start, raw) for start, length, raw, _ in sections
                   if start <= rva and rva + size <= start + length]
        if len(matches) != 1:
            raise ValueError(f"Not one file-backed section: {va:x}")
        start, raw = matches[0]
        return data[raw + rva - start:raw + rva - start + size]

    ranges = [(0x4C3080, 0x4C316B), (0x507510, 0x507601),
              (0x507610, 0x507744), (0x507B10, 0x507BA0)]
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    instructions = {}
    spans = []
    for start, end in ranges:
        raw = read(start, end - start)
        decoded = list(decoder.disasm(raw, start))
        if sum(i.size for i in decoded) != len(raw):
            raise ValueError(f"Incomplete linear decode: {start:x}")
        rows = []
        for i in decoded:
            instructions[i.address] = i
            rows.append({"va": hex(i.address), "hex": i.bytes.hex(),
                         "mnemonic": i.mnemonic, "operands": i.op_str})
        spans.append({"start": hex(start), "end_exclusive": hex(end),
                      "sha256": hashlib.sha256(raw).hexdigest(), "instructions": rows})
    # Exact instruction bytes and starts, rather than substring matches.
    anchors = {
        0x4C30BE: "0fb70b", 0x4C30C4: "e847440400",
        0x4C3107: "0fb64e08", 0x4C3112: "0fb706",
        0x4C311A: "0fb65609", 0x4C312A: "e8e1440400",
        0x50753B: "8bf9", 0x50753F: "8bf2", 0x507552: "897da0",
        0x5075C0: "8b7e18", 0x5075CE: "e8cd050000", 0x5075E3: "8bc7",
        0x507651: "897d90", 0x507654: "894d94", 0x507657: "895598",
        0x50771E: "8d4590", 0x507721: "e8ea030000",
    }
    for va, expected in anchors.items():
        if va not in instructions or instructions[va].bytes.hex() != expected:
            raise ValueError(f"Instruction anchor mismatch: {va:x}")
    result = {"schema": "s00-bounded-login-choice-instructions-v1",
              "target_sha256": digest, "tool": f"Capstone {capstone.__version__}",
              "authority": "Direct original-file instruction bytes / bounded analyst interpretation",
              "checks": {"identity": "PASS", "pe_mapping": "PASS",
                         "linear_decode_ranges": len(spans), "exact_instruction_anchors": len(anchors)},
              "limitations": ["Not REA Evidence; live REA dossier timed out after 300 seconds",
                              "Linear decode is not complete CFG or semantic verification",
                              "No original Server packet, pairing, runtime, UI or T01 FULL-PASS verdict"],
              "ranges": spans}
    if args.output:
        args.output.write_bytes((json.dumps(result, indent=2) + "\n").encode("utf-8"))
    print(json.dumps({"target_sha256": digest, "checks": result["checks"]}))


if __name__ == "__main__":
    main()
