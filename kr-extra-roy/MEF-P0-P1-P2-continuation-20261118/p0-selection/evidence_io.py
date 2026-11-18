"""Read-only PE/Git/objdump helpers for the bounded P0 evidence replay.

No target code, resource script, DLL, archive member or Server is executed.
Only Python's standard library, git show and GNU objdump are used.
"""
from __future__ import annotations

import hashlib
import re
import struct
import subprocess
from pathlib import Path

BASE = "15d9501c203c6f656461b64f578a50c96e38a5ff"
BIN_SHA256 = "9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
DEFAULT_BIN = Path("/workspace/scratch/3e083e35831f/project_sources/02-Tartaros.bin")


def require(condition: bool, message: str) -> None:
    if not condition:
        raise ValueError(message)


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def git_bytes(repo: Path, path: str) -> bytes:
    return subprocess.run(
        ["git", "show", f"{BASE}:{path}"], cwd=repo, check=True,
        stdout=subprocess.PIPE, stderr=subprocess.PIPE,
    ).stdout


def git_blob_id(data: bytes) -> str:
    return hashlib.sha1(b"blob " + str(len(data)).encode("ascii") + b"\0" + data).hexdigest()


class PE:
    def __init__(self, path: Path):
        self.path = path
        self.data = path.read_bytes()
        require(self.data[:2] == b"MZ", "not MZ")
        pe = self.u32(0x3C)
        require(self.data[pe:pe + 4] == b"PE\0\0", "not PE")
        require(self.u16(pe + 4) == 0x14C, "not i386")
        self.optional = pe + 24
        require(self.u16(self.optional) == 0x10B, "not PE32")
        self.image_base = self.u32(self.optional + 28)
        table = self.optional + self.u16(pe + 20)
        self.sections = []
        for i in range(self.u16(pe + 6)):
            name, virtual_size, rva, raw_size, raw_offset = struct.unpack_from(
                "<8sIIII", self.data, table + 40 * i
            )
            self.sections.append({"name": name.rstrip(b"\0").decode("ascii"),
                                  "virtual_size": virtual_size, "rva": rva,
                                  "raw_size": raw_size, "raw_offset": raw_offset})

    def u16(self, offset: int) -> int:
        return struct.unpack_from("<H", self.data, offset)[0]

    def u32(self, offset: int) -> int:
        return struct.unpack_from("<I", self.data, offset)[0]

    def offset(self, va: int, size: int = 1) -> int:
        rva = va - self.image_base
        for section in self.sections:
            relative = rva - section["rva"]
            if 0 <= relative and relative + size <= section["raw_size"]:
                return section["raw_offset"] + relative
        raise ValueError(f"not fully file-backed: {va:#x}+{size:#x}")

    def read(self, va: int, size: int) -> bytes:
        offset = self.offset(va, size)
        return self.data[offset:offset + size]

    def cstring(self, va: int) -> bytes:
        offset = self.offset(va)
        end = self.data.index(b"\0", offset)
        self.offset(va, end - offset + 1)
        return self.data[offset:end]

    def imports(self) -> dict[int, dict]:
        rva = self.u32(self.optional + 104)
        descriptor = self.offset(self.image_base + rva, 20)
        result = {}
        while True:
            original, stamp, chain, name, thunk = struct.unpack_from("<IIIII", self.data, descriptor)
            if not any((original, stamp, chain, name, thunk)):
                return result
            dll = self.cstring(self.image_base + name).decode("ascii")
            index = 0
            while True:
                value = struct.unpack("<I", self.read(self.image_base + (original or thunk) + index * 4, 4))[0]
                if not value:
                    break
                symbol = f"ordinal:{value & 0xffff}" if value & 0x80000000 else self.cstring(self.image_base + value + 2).decode("ascii")
                result[self.image_base + thunk + index * 4] = {"dll": dll, "name": symbol}
                index += 1
            descriptor += 20

    def rel32_candidates(self, targets: list[int]) -> dict[str, list[str]]:
        """Finite raw E8/E9 census; NOT a decoded all-call proof."""
        section = next(s for s in self.sections if s["name"] == ".text")
        data = self.data[section["raw_offset"]:section["raw_offset"] + section["raw_size"]]
        va = self.image_base + section["rva"]
        result = {hex(target): [] for target in targets}
        for i in range(len(data) - 4):
            if data[i] in (0xE8, 0xE9):
                target = va + i + 5 + struct.unpack_from("<i", data, i + 1)[0]
                if target in targets:
                    result[hex(target)].append(hex(va + i))
        return result


def disassemble(path: Path, start: int, end: int) -> list[dict]:
    output = subprocess.run(
        ["objdump", "-d", "-Mintel", "--insn-width=16", f"--start-address={start:#x}",
         f"--stop-address={end:#x}", str(path)],
        check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True,
    ).stdout
    result = []
    for line in output.splitlines():
        match = re.match(r"^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*(\S.*)$", line)
        if match:
            result.append({"va": hex(int(match.group(1), 16)),
                           "bytes": "".join(match.group(2).split()),
                           "asm": " ".join(match.group(3).split())})
    require(bool(result), f"no disassembly at {start:#x}")
    cursor = start
    for instruction in result:
        require(int(instruction["va"], 16) == cursor, "instruction gap")
        require("(bad)" not in instruction["asm"] and ".byte" not in instruction["asm"], "invalid instruction")
        cursor += len(bytes.fromhex(instruction["bytes"]))
    require(cursor == end, f"window does not end at instruction boundary: {cursor:#x} != {end:#x}")
    return result
