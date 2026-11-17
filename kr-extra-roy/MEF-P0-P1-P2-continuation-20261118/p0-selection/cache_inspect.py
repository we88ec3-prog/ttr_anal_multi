#!/usr/bin/env python3
"""Strict, read-only inspection of local fcs.flu bytes, NOT a native emulator.

The layout is inferred from this pinned BIN's reader.  NUL/length/count/ASCII
checks are offline acceptance policy; the native routine does not provide them.
No filesystem paths stored inside a cache are opened or resolved.  The model
assumes an initially empty group manager and the CRT default ASCII uppercase
branch.  Its result is a candidate path, never proof of a native open/render.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import struct
from dataclasses import dataclass
from pathlib import Path

GROUP_SIZE = 0x158
ENTRY_SIZE = 0x218
MAX_BYTES = 256 * 1024 * 1024  # Offline policy, not a native-format maximum.


class CacheProfileError(ValueError):
    pass


def check(value: bool, message: str) -> None:
    if not value:
        raise CacheProfileError(message)


def slot(data: bytes, start: int, width: int, label: str, *, empty: bool = False) -> str:
    raw = data[start:start + width]
    check(len(raw) == width, f"{label}: truncated physical slot")
    end = raw.find(b"\0")
    check(end >= 0, f"{label}: no in-slot NUL; native unbounded string access is not emulated")
    raw = raw[:end]
    check(bool(raw) or empty, f"{label}: empty string outside strict profile")
    check(all(0x20 <= byte < 0x7F for byte in raw), f"{label}: outside printable ASCII profile")
    return raw.decode("ascii")


def ascii_default_key(name: str) -> str:
    check(bool(name), "empty filename outside strict profile")
    check(all(0x20 <= ord(char) < 0x7F for char in name), "query outside printable ASCII profile")
    check(len(name) < 0x40, "filename/query exceeds native 64-byte copy-buffer profile")
    return name.upper()


@dataclass(frozen=True)
class Group:
    record: int
    name: str
    pattern: str
    directory: str
    recursive: int


@dataclass(frozen=True)
class Entry:
    record: int
    group: str
    directory: str
    filename: str


def inspect_bytes(data: bytes, queries: list[tuple[str, str]] | None = None) -> dict:
    check(8 <= len(data) <= MAX_BYTES, "input outside offline size policy")
    group_count, entry_count = struct.unpack_from("<II", data)
    check(group_count <= 65536 and entry_count <= 1000000, "counts outside offline budget")
    expected = 8 + group_count * GROUP_SIZE + entry_count * ENTRY_SIZE
    check(len(data) == expected, f"strict exact length mismatch: expected {expected}, observed {len(data)}")
    groups: dict[str, Group] = {}
    group_duplicates = []
    for index in range(group_count):
        start = 8 + index * GROUP_SIZE
        name = slot(data, start, 0x10, f"group[{index}].name")
        pattern = slot(data, start + 0x10, 0x40, f"group[{index}].pattern")
        directory = slot(data, start + 0x50, 0x104, f"group[{index}].directory", empty=True)
        recursive = struct.unpack_from("<I", data, start + 0x154)[0]
        group = Group(index, name, pattern, directory, recursive)
        if name in groups:
            group_duplicates.append({"retained_record": groups[name].record, "discarded_record": index, "group": name})
        else:
            groups[name] = group
    entries: dict[tuple[str, str], Entry] = {}
    entry_duplicates = []
    entry_start = 8 + group_count * GROUP_SIZE
    for index in range(entry_count):
        start = entry_start + index * ENTRY_SIZE
        group = slot(data, start, 0x10, f"entry[{index}].group")
        directory = slot(data, start + 0x10, 0x104, f"entry[{index}].directory", empty=True)
        filename = slot(data, start + 0x114, 0x104, f"entry[{index}].filename")
        check(group in groups, f"entry[{index}]: undeclared exact group; native reader's missing-group dereference is not emulated")
        key = (group, ascii_default_key(filename))
        entry = Entry(index, group, directory, filename)
        if key in entries:
            entry_duplicates.append({"retained_record": entries[key].record, "discarded_record": index,
                                     "group": group, "ascii_default_key": key[1]})
        else:
            entries[key] = entry
    selected = []
    for group, filename in queries or []:
        key = ascii_default_key(filename)
        winner = entries.get((group, key))
        selected.append({
            "group": group, "filename": filename, "ascii_default_key": key,
            "group_present": group in groups,
            "candidate_record": winner.record if winner else None,
            "candidate_directory": winner.directory if winner else None,
            "candidate_filename": winner.filename if winner else None,
            "candidate_literal_path": winner.directory + winner.filename if winner else None,
            "status": "CANDIDATE_UNDER_STATED_PROFILE" if winner else "NO_CANDIDATE_UNDER_STATED_PROFILE",
            "native_selected_path": None, "native_open_verified": False,
        })
    return {
        "schema": "FCS_LOCAL_ASCII_INSPECTION_V1", "input_sha256": hashlib.sha256(data).hexdigest(),
        "input_bytes": len(data), "structural_profile_pass": True,
        "native_execution": False, "initial_manager_assumption": "EMPTY",
        "normalization_assumption": "CRT_DEFAULT_ASCII_BRANCH_ONLY",
        "native_cache_loaded": None, "native_payload_ready": False,
        "group_record_count": group_count, "entry_record_count": entry_count,
        "retained_group_count": len(groups), "retained_entry_count": len(entries),
        "groups": [vars(group) for group in groups.values()],
        "duplicate_groups": group_duplicates, "duplicate_entries": entry_duplicates,
        "queries": selected,
        "limitations": [
            "Strict length, bounded counts, in-slot NUL and ASCII are analyzer policy, not native checks.",
            "Candidate records do not prove that this cache was opened by the Client.",
            "Stored paths are concatenated literally, never normalized or opened.",
            "Native locale, preexisting manager entries, cwd, mounted provider and payload success remain unobserved.",
        ],
    }


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("cache", type=Path)
    parser.add_argument("--query", nargs=2, metavar=("GROUP", "FILENAME"), action="append", default=[])
    args = parser.parse_args()
    try:
        check(args.cache.stat().st_size <= MAX_BYTES, "file exceeds offline budget")
        result = inspect_bytes(args.cache.read_bytes(), args.query)
    except (CacheProfileError, OSError) as error:
        print(json.dumps({"structural_profile_pass": False, "error": str(error),
                          "native_execution": False, "native_payload_ready": False}, ensure_ascii=False, indent=2))
        return 2
    print(json.dumps(result, ensure_ascii=False, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
