#!/usr/bin/env python3
"""Read-only, bounded adapter/vtable/import evidence from the pinned PE32 image.

Writes JSON only to stdout. Does not execute target code, load a target DLL,
write source bytes, or change Git state. Git C files are navigation pins only.
"""
from __future__ import annotations
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct
import subprocess

BASELINE = "5ed4833b805949fabe260aea77e3fe0fd8e86bfa"
BINARY_SHA = "9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
FUNCTION_DIR = "kr-bulk-roy/" + BINARY_SHA + "/functions/"


def require(ok, message):
    if not ok:
        raise ValueError(message)


def sha(b):
    return hashlib.sha256(b).hexdigest()


class PE:
    def __init__(self, data):
        self.data = data
        require(len(data) == 12472320 and sha(data) == BINARY_SHA, "original BIN identity")
        require(data[:2] == b"MZ", "DOS signature")
        nt = struct.unpack_from("<I", data, 0x3c)[0]
        require(data[nt:nt+4] == b"PE\0\0", "PE signature")
        machine, count = struct.unpack_from("<HH", data, nt+4)
        opt, opt_size = nt+24, struct.unpack_from("<H", data, nt+20)[0]
        require(machine == 0x14c and struct.unpack_from("<H", data, opt)[0] == 0x10b, "PE32 i386")
        self.base = struct.unpack_from("<I", data, opt+28)[0]
        require(self.base == 0x400000, "image base")
        self.sections = []
        for i in range(count):
            start = opt+opt_size+i*40
            virtual_size, rva, n, raw = struct.unpack_from("<IIII", data, start+8)
            require(raw+n <= len(data), "section file bounds")
            self.sections.append((rva, n, raw))
        self.import_rva, self.import_size = struct.unpack_from("<II", data, opt+96+8)
        self.off(self.import_rva, self.import_size)

    def off(self, rva, n=1):
        require(n >= 0, "negative read size")
        for start, length, raw in self.sections:
            if start <= rva and rva+n <= start+length:
                return raw+rva-start
        raise ValueError("RVA outside one file-backed section: " + hex(rva))

    def at(self, rva, n):
        p = self.off(rva, n)
        return self.data[p:p+n]

    def z(self, rva, max_bytes=4096):
        result = bytearray()
        for i in range(max_bytes):
            byte = self.at(rva+i, 1)[0]
            if byte == 0:
                return bytes(result)
            result.append(byte)
        raise ValueError("unterminated bounded import string")

    def record(self, rva, n):
        raw = self.at(rva, n)
        return {"rva": hex(rva), "va": hex(self.base+rva), "raw_offset": hex(self.off(rva, n)),
                "length": n, "sha256": sha(raw), "hex": raw.hex()}


def import_walk(pe):
    """Walk every import descriptor/thunk; retain only two specified IAT slots."""
    targets = {0xbd2624: ("texture_create_memory_import", "D3DXCreateTextureFromFileInMemoryEx"),
               0xbd2628: ("image_info_memory_import", "D3DXGetImageInfoFromFileInMemory")}
    selected, descriptors, thunk_count = {}, 0, 0
    terminated = False
    for index in range(pe.import_size//20):
        descriptor_rva = pe.import_rva+index*20
        values = struct.unpack("<IIIII", pe.at(descriptor_rva, 20))
        if not any(values):
            terminated = True
            break
        ilt, timestamp, forwarder, name_rva, iat = values
        dll_bytes = pe.z(name_rva, 512)
        dll = dll_bytes.decode("ascii")
        descriptors += 1
        thunk_terminated = False
        for ordinal in range(65536):
            lookup_rva = (ilt or iat)+ordinal*4
            hint_name_rva = struct.unpack("<I", pe.at(lookup_rva, 4))[0]
            if hint_name_rva == 0:
                thunk_terminated = True
                break
            thunk_count += 1
            iat_rva = iat+ordinal*4
            iat_va = pe.base+iat_rva
            if iat_va not in targets:
                continue
            require(not hint_name_rva & 0x80000000, "selected import is by name")
            hint = struct.unpack("<H", pe.at(hint_name_rva, 2))[0]
            name_bytes = pe.z(hint_name_rva+2)
            name = name_bytes.decode("ascii")
            expected_id, expected_name = targets[iat_va]
            require(dll == "d3dx9_32.dll" and name == expected_name, "selected native import identity")
            require(iat_va not in selected, "duplicate selected IAT slot")
            selected[iat_va] = {
                "id": expected_id, "iat_va": hex(iat_va), "dll": dll, "symbol": name,
                "descriptor_index": index, "thunk_index": ordinal, "hint": hint,
                "descriptor_fields": {"original_first_thunk_rva": hex(ilt), "time_date_stamp": timestamp,
                                      "forwarder_chain": forwarder, "dll_name_rva": hex(name_rva),
                                      "first_thunk_rva": hex(iat)},
                "descriptor": pe.record(descriptor_rva, 20),
                "lookup_thunk": pe.record(lookup_rva, 4), "iat_thunk": pe.record(iat_rva, 4),
                "dll_name": pe.record(name_rva, len(dll_bytes)+1),
                "hint_name": pe.record(hint_name_rva, len(name_bytes)+3),
            }
        require(thunk_terminated, "unterminated import thunk array")
    require(terminated and set(selected) == set(targets), "complete descriptor walk and selected imports")
    return {"directory_rva": hex(pe.import_rva), "directory_size": pe.import_size,
            "descriptors_walked": descriptors, "nonzero_thunks_walked": thunk_count,
            "descriptor_terminator_seen": True, "selected": [selected[k] for k in sorted(selected)]}


def code_window(pe, binary, ident, start, end, claim):
    output = subprocess.check_output(["objdump", "-d", "-Mintel", "--insn-width=16",
                                      f"--start-address={start:#x}", f"--stop-address={end:#x}", str(binary)], text=True)
    rows = []
    for line in output.splitlines():
        m = re.match(r"\s*([0-9a-f]+):\s*\t([0-9a-f ]+)\t(.+)$", line)
        if m:
            rows.append({"va": "0x"+m[1], "bytes": bytes.fromhex(m[2]).hex(), "asm": m[3].strip()})
    raw = pe.at(start-pe.base, end-start)
    require(rows and int(rows[0]["va"], 16) == start, "function start boundary")
    require(b"".join(bytes.fromhex(r["bytes"]) for r in rows) == raw, "complete instruction bytes")
    require(not any("(bad)" in r["asm"] or ".byte" in r["asm"] for r in rows), "valid instructions")
    return {"id": ident, "function_anchor": hex(start), "va": hex(start), "end": hex(end),
            "raw_offset": hex(pe.off(start-pe.base, end-start)), "length": end-start,
            "sha256": sha(raw), "claim": claim, "instructions": rows}


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--binary", type=Path, required=True)
    ap.add_argument("--repo", type=Path, required=True)
    args = ap.parse_args()
    pe = PE(args.binary.read_bytes())
    tables = []
    for ident, va, values in [
            ("model_texture_adapter_vtable", 0xc455f8, (0x737ee0, 0x737f00)),
            ("image_texture_create_adapter_vtable", 0xc45604, (0x737fb0, 0x738000)),
            ("image_info_adapter_vtable", 0xc45610, (0x738050, 0x738070))]:
        row = pe.record(va-pe.base, 8)
        require(struct.unpack("<II", bytes.fromhex(row["hex"])) == values, "typed adapter slots")
        row.update(id=ident, u32=[hex(v) for v in values])
        tables.append(row)
    windows = [code_window(pe, args.binary, *spec) for spec in [
        ("model_texture_memory_adapter", 0x737f00, 0x737f37, "C455F8+4; adapter device/output fields and input buffer/length -> IAT BD2624 texture creation"),
        ("image_texture_memory_adapter", 0x738000, 0x738049, "C45604+4; adapter fields and input buffer/length -> IAT BD2624 texture creation"),
        ("image_info_memory_adapter", 0x738070, 0x738089, "C45610+4; input buffer/length/output image-info -> IAT BD2628 image information"),
    ]]
    instructions = {r["va"]: r for w in windows for r in w["instructions"]}
    for va, iat in [(0x737f2d, 0xbd2624), (0x73803f, 0xbd2624), (0x73807f, 0xbd2628)]:
        require(instructions[hex(va)]["bytes"] == (b"\xff\x15"+struct.pack("<I", iat)).hex(), "selected IAT call operand")
    pins = []
    for va in [0x737f00, 0x738000, 0x738070]:
        path = FUNCTION_DIR+hex(va)+".c"
        ref = BASELINE+":"+path
        b = subprocess.check_output(["git", "show", ref], cwd=args.repo)
        blob = subprocess.check_output(["git", "rev-parse", ref], cwd=args.repo, text=True).strip()
        pins.append({"source_commit": BASELINE, "path": path, "git_blob": blob,
                     "bytes": len(b), "sha256": sha(b), "loaded_by_analyzer": False,
                     "role": "navigation only; claims checked against pinned original BIN"})
    result = {"schema": "MEF_ADAPTER_PEER_EVIDENCE_V1", "status": "PASS_BOUNDED_ORIGINAL_BYTES",
              "baseline_commit": BASELINE, "binary_sha256": BINARY_SHA, "image_base": hex(pe.base),
              "data_records": tables, "windows": windows, "native_imports": import_walk(pe),
              "published_pins": pins,
              "support": ["Model worker C455F8 and image-create C45604 are distinct adapters ending in the same texture-create import.",
                          "Image-info C45610 ends in a distinct GetImageInfo import; it is not itself texture creation."],
              "limits": ["Names and original IAT/ILT records do not prove runtime DLL binding or successful graphics calls.",
                         "Caller identities, path policy, payload bytes and device lifecycle remain separate parent-package evidence."],
              "target_execution": False, "source_writes": False, "git_writes": False}
    print(json.dumps(result, ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
