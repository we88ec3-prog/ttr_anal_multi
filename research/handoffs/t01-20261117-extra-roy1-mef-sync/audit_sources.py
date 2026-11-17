#!/usr/bin/env python3
"""Read-only R0 audit of the exact extra/roy1 delta; not a native semantic verdict.

No Client/Lua/Server execution, extraction, network, Git mutation or source writes.
Prints JSON to stdout; the caller may redirect it to a separate review receipt.
"""
from __future__ import annotations

import argparse
import ast
from collections import Counter
from hashlib import sha1, sha256
import io
import json
import os
from pathlib import Path, PurePosixPath
import re
import struct
import subprocess
import tarfile

BASE = "03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc"
SOURCE = "534746f194a889ebb34dda7471c2ae62d30a1dd1"
TARGET = "9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
ORIGINALS = {
    "02-Tartaros.bin": (12472320, TARGET),
    "01-Tartaros.exe": (2594816, "03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f"),
    "06-Event.stp": (11241597, "2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b"),
    "07-Table.stp": (5248784, "09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442"),
    "10-BoundMap.stp": (20772373, "07d8f3a20aa4a396312c60927431a53a89dce6370ef8bb8192bd8d8eca1dd6b8"),
}


def git(repo: Path, *args: str) -> bytes:
    return subprocess.check_output(["git", "-C", str(repo), *args],
                                   env={**os.environ, "GIT_NO_LAZY_FETCH": "1"})


def strict_json(data: bytes):
    def object_pairs(pairs):
        out = {}
        for key, value in pairs:
            if key in out:
                raise ValueError(f"duplicate key: {key}")
            out[key] = value
        return out

    def reject_constant(value):
        raise ValueError(f"non-JSON constant: {value}")

    return json.loads(data.decode("utf-8-sig"), object_pairs_hook=object_pairs,
                      parse_constant=reject_constant)


def file_identity(path: Path, display_name: str):
    data = path.read_bytes()
    return {"name": display_name, "bytes": len(data), "sha256": sha256(data).hexdigest()}


def pe_sections(data: bytes):
    if data[:2] != b"MZ":
        raise ValueError("not MZ")
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    if data[pe:pe + 4] != b"PE\0\0":
        raise ValueError("not PE")
    machine, count = struct.unpack_from("<HH", data, pe + 4)
    optional_size = struct.unpack_from("<H", data, pe + 20)[0]
    optional = pe + 24
    magic = struct.unpack_from("<H", data, optional)[0]
    image_base = struct.unpack_from("<I", data, optional + 28)[0]
    if machine != 0x14C or magic != 0x10B or image_base != 0x400000:
        raise ValueError("unexpected target PE identity")
    sections = []
    for index in range(count):
        start = optional + optional_size + index * 40
        name = data[start:start + 8].split(b"\0", 1)[0].decode("ascii")
        virtual_size, rva, raw_size, raw = struct.unpack_from("<IIII", data, start + 8)
        if raw + raw_size > len(data):
            raise ValueError("section raw bytes outside file")
        sections.append({"name": name, "va": hex(image_base + rva), "rva": hex(rva),
                         "virtual_size": virtual_size, "raw_offset": hex(raw),
                         "raw_size": raw_size,
                         "mapping": "raw = VA - section.va + section.raw_offset (raw-backed range only)"})
    return {"machine": hex(machine), "optional_magic": hex(magic),
            "image_base": hex(image_base), "sections": sections}


def audit(repo: Path, sources: Path):
    ancestor = subprocess.run(["git", "-C", str(repo), "merge-base", "--is-ancestor",
                               BASE, SOURCE], check=False,
                              env={**os.environ, "GIT_NO_LAZY_FETCH": "1"}).returncode == 0
    records = git(repo, "diff", "--name-status", "-z", BASE, SOURCE).split(b"\0")
    changes = [(records[i].decode(), records[i + 1].decode())
               for i in range(0, len(records) - 1, 2)]
    tree = {}
    for record in git(repo, "ls-tree", "-r", "-z", SOURCE, "--", "kr-extra-roy").split(b"\0"):
        if record:
            info, path = record.split(b"\t", 1)
            mode, kind, blob = info.split()
            tree[path.decode()] = (mode.decode(), kind.decode(), blob.decode())
    entries, failures, json_files, python_files = [], [], 0, 0
    expected_suffixes = {".md", ".py", ".json", ".asm", ".txt", ".tsv", ".patch"}
    for status, path in changes:
        row = {"path": path, "change": status, "source_commit": SOURCE}
        if status != "A" or not path.startswith("kr-extra-roy/"):
            failures.append({"path": path, "reason": "unexpected change type/scope"})
            continue
        data = (repo / path).read_bytes()
        mode, kind, blob = tree[path]
        actual_blob = sha1(b"blob " + str(len(data)).encode() + b"\0" + data).hexdigest()
        row.update({"git_blob_sha": blob, "sha256": sha256(data).hexdigest(),
                    "bytes": len(data), "mode": mode, "worktree_matches_blob": actual_blob == blob})
        if actual_blob != blob or kind != "blob" or mode not in {"100644", "100755"}:
            failures.append({"path": path, "reason": "Git identity/mode mismatch"})
        suffix = Path(path).suffix
        if suffix not in expected_suffixes and not re.fullmatch(r"\.part\d{2}", suffix):
            failures.append({"path": path, "reason": "unexpected publication file type"})
        try:
            if suffix == ".json":
                strict_json(data)
                json_files += 1
            elif suffix == ".py":
                ast.parse(data.decode("utf-8-sig"), filename=path)
                python_files += 1
            elif suffix in expected_suffixes:
                data.decode("utf-8-sig")
        except (ValueError, SyntaxError, UnicodeError) as exc:
            failures.append({"path": path, "reason": str(exc)})
        if data.startswith((b"MZ", b"STPD", b"STPI", b"\x1bLua")):
            failures.append({"path": path, "reason": "raw executable/archive/resource signature"})
        entries.append(row)

    part_paths = sorted(path for _, path in changes if re.search(r"\.part\d{2}$", path))
    packed = b"".join((repo / path).read_bytes() for path in part_paths)
    archive_rows = []
    with tarfile.open(fileobj=io.BytesIO(packed), mode="r:xz") as archive:
        for member in archive.getmembers():
            posix = PurePosixPath(member.name)
            if posix.is_absolute() or ".." in posix.parts or not member.isfile():
                failures.append({"path": member.name, "reason": "unsafe/nonregular research archive member"})
                continue
            stream = archive.extractfile(member)
            if stream is None:
                raise ValueError("regular tar member has no stream")
            data = stream.read()
            row = {"path": member.name, "bytes": len(data), "sha256": sha256(data).hexdigest()}
            archive_rows.append(row)
            suffix = posix.suffix
            if suffix not in expected_suffixes or data.startswith((b"MZ", b"STPD", b"STPI", b"\x1bLua")):
                failures.append({"path": member.name, "reason": "unexpected archive publication content"})
            if suffix == ".json":
                strict_json(data)
            elif suffix == ".py":
                ast.parse(data.decode("utf-8-sig"), filename=member.name)
            else:
                data.decode("utf-8-sig")

    identities = [file_identity(sources / filename, filename) for filename in ORIGINALS]
    for identity in identities:
        size, digest = ORIGINALS[identity["name"]]
        identity["matches_expected"] = (identity["bytes"] == size and identity["sha256"] == digest)
        if not identity["matches_expected"]:
            failures.append({"path": identity["name"], "reason": "original identity mismatch"})
    original = (sources / "02-Tartaros.bin").read_bytes()
    if sha256(original).hexdigest() != TARGET:
        failures.append({"path": "02-Tartaros.bin", "reason": "target identity mismatch"})
    if len(changes) != 608 or not ancestor:
        failures.append({"path": "Git delta", "reason": "unexpected scope/ancestry"})
    return {
        "schema": "t01-mef-source-audit-v1", "review": "R0 source integrity only",
        "main_base": BASE, "source_branch": "extra/roy1", "source_commit": SOURCE,
        "main_is_source_ancestor": ancestor,
        "source_commit_count": int(git(repo, "rev-list", "--count", f"{BASE}..{SOURCE}")),
        "source_file_count": len(entries), "source_bytes": sum(x["bytes"] for x in entries),
        "suffix_counts": dict(sorted(Counter(Path(x["path"]).suffix for x in entries).items())),
        "strict_json_checked": json_files, "python_ast_checked": python_files,
        "research_archive": {"parts": part_paths, "packed_bytes": len(packed),
                             "packed_sha256": sha256(packed).hexdigest(),
                             "members": archive_rows, "extracted_to_disk": False},
        "original_source_identities": identities, "pe": pe_sections(original),
        "failures": failures, "status": "PASS_R0_ONLY" if not failures else "FAIL_R0",
        "native_semantic_full_pass": False, "client_executed": False,
        "lua_executed": False, "server_executed": False, "sources": entries,
    }


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--repo", type=Path, required=True)
    parser.add_argument("--sources", type=Path, required=True)
    args = parser.parse_args()
    result = audit(args.repo.resolve(), args.sources.resolve())
    print(json.dumps(result, ensure_ascii=False, indent=2))
    raise SystemExit(0 if not result["failures"] else 1)


if __name__ == "__main__":
    main()
