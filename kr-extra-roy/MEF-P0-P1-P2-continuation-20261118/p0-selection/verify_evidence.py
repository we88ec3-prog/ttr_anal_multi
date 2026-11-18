#!/usr/bin/env python3
"""Replay pinned P0 evidence and strict local-cache profile checks, read-only.

Writes only JSON to stdout.  Does not execute the target, any archive member,
Lua, DLL, Server, or a filesystem path supplied inside cache records.
"""
from __future__ import annotations

import argparse
import datetime
import json
import struct
import sys
import zipfile
from pathlib import Path

sys.dont_write_bytecode = True

from cache_inspect import CacheProfileError, ENTRY_SIZE, GROUP_SIZE, inspect_bytes
from evidence_io import BASE, BIN_SHA256, DEFAULT_BIN, PE, disassemble, git_blob_id, git_bytes, require, sha256

HERE = Path(__file__).resolve().parent
REPO = HERE.parents[2]


def read_json(name: str) -> dict:
    return json.loads((HERE / name).read_text())


def synthetic_profile_checks() -> list[dict]:
    """Construct in-memory analyzer vectors; never a native fcs original."""
    def cslot(value: str, size: int) -> bytes:
        encoded = value.encode("ascii")
        require(len(encoded) < size, "test construction exceeds slot")
        return encoded + bytes(size - len(encoded))

    def group(name: str, directory: str, pattern: str = "*.abf", recursive: int = 1) -> bytes:
        return cslot(name, 16) + cslot(pattern, 64) + cslot(directory, 260) + struct.pack("<I", recursive)

    def entry(name: str, directory: str, filename: str) -> bytes:
        return cslot(name, 16) + cslot(directory, 260) + cslot(filename, 260)

    def cache(groups: list[bytes], entries: list[bytes]) -> bytes:
        return struct.pack("<II", len(groups), len(entries)) + b"".join(groups + entries)

    results = []

    def passed(name: str, condition: bool) -> None:
        require(condition, f"synthetic profile check failed: {name}")
        results.append({"id": name, "pass": True, "evidence_class": "SYNTHETIC_ANALYZER_ONLY"})

    def rejects(name: str, data: bytes) -> None:
        try:
            inspect_bytes(data)
        except CacheProfileError:
            passed(name, True)
        else:
            raise ValueError(f"profile accepted rejected case: {name}")

    empty = inspect_bytes(bytes(8), [("CHA_ABF", "example.abf")])
    passed("zero_counts_is_structural_only_not_target_coverage", empty["structural_profile_pass"] and not empty["queries"][0]["group_present"] and not empty["native_payload_ready"])
    good = cache([group("CHA_ABF", "Declared/")], [entry("CHA_ABF", "Actual/", "Example.abf")])
    result = inspect_bytes(good, [("CHA_ABF", "example.ABF")])
    passed("entry_directory_is_literal_not_group_prefix", result["queries"][0]["candidate_literal_path"] == "Actual/Example.abf")
    passed("selected_path_stays_unobserved", result["queries"][0]["native_selected_path"] is None and not result["queries"][0]["native_open_verified"])
    duplicated = cache([group("CHA_ABF", "First/"), group("CHA_ABF", "Second/", "*.different", 0)],
                       [entry("CHA_ABF", "Winner/", "Example.abf"), entry("CHA_ABF", "Loser/", "EXAMPLE.ABF")])
    result = inspect_bytes(duplicated, [("CHA_ABF", "example.abf")])
    passed("first_group_definition_retained", result["groups"][0]["directory"] == "First/" and result["groups"][0]["pattern"] == "*.abf" and result["groups"][0]["recursive"] == 1 and len(result["duplicate_groups"]) == 1)
    passed("first_normalized_entry_retained", result["queries"][0]["candidate_literal_path"] == "Winner/Example.abf" and len(result["duplicate_entries"]) == 1)
    separate = cache([group("CHA_ABF", "A/"), group("cha_abf", "B/")],
                     [entry("CHA_ABF", "A/", "Example.abf"), entry("cha_abf", "B/", "example.abf")])
    result = inspect_bytes(separate, [("CHA_ABF", "example.abf"), ("cha_abf", "Example.abf")])
    passed("exact_group_names_do_not_casefold", result["retained_group_count"] == 2 and [q["candidate_directory"] for q in result["queries"]] == ["A/", "B/"])
    query = inspect_bytes(good, [("MISSING", "example.abf"), ("CHA_ABF", "missing.abf")])
    passed("missing_group_and_missing_key_distinct", not query["queries"][0]["group_present"] and query["queries"][1]["group_present"] and all(q["candidate_record"] is None for q in query["queries"]))
    no_separator = inspect_bytes(cache([group("G", "")], [entry("G", "Literal", "f.abf")]), [("G", "f.abf")])
    passed("no_path_normalization_or_separator_insertion", no_separator["queries"][0]["candidate_literal_path"] == "Literalf.abf")
    non_boolean = inspect_bytes(cache([group("G", "", recursive=2)], []))
    passed("recursive_field_is_not_forced_to_boolean", non_boolean["groups"][0]["recursive"] == 2)
    name_63 = "a" * 59 + ".abf"
    boundary = inspect_bytes(cache([group("G", "A/")], [entry("G", "A/", name_63)]), [("G", name_63)])
    passed("key_63_bytes_fits_profile_with_nul", boundary["queries"][0]["candidate_filename"] == name_63)
    rejects("truncated_header", b"\0" * 7)
    rejects("truncated_record", good[:-1])
    rejects("trailing_bytes_rejected_by_offline_policy", good + b"X")
    rejects("oversized_count_rejected_by_offline_policy", struct.pack("<II", 0xFFFFFFFF, 0))
    rejects("undeclared_entry_group_rejected", cache([], [entry("UNKNOWN", "A/", "e.abf")]))
    rejects("entry_group_case_mismatch_rejected", cache([group("CHA_ABF", "A/")], [entry("cha_abf", "A/", "e.abf")]))
    altered = bytearray(good); altered[8:24] = b"A" * 16
    rejects("group_slot_without_nul_rejected", bytes(altered))
    altered = bytearray(good); altered[8 + GROUP_SIZE + 0x114:8 + GROUP_SIZE + ENTRY_SIZE] = b"A" * 260
    rejects("filename_slot_without_nul_rejected", bytes(altered))
    altered = bytearray(good); altered[8 + GROUP_SIZE + 0x114] = 0xE9
    rejects("non_ascii_name_not_guessed", bytes(altered))
    rejects("cache_key_64_bytes_rejected", cache([group("G", "A/")], [entry("G", "A/", "A" * 64)]))
    return results


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--binary", type=Path, default=DEFAULT_BIN)
    parser.add_argument("--repo", type=Path, default=REPO)
    args = parser.parse_args()
    manifest = read_json("source-manifest.json")
    evidence = read_json("native-evidence.json")
    contract = read_json("contracts.json")
    census = read_json("caller-census.json")
    availability = read_json("source-availability.json")
    pe = PE(args.binary)
    require(sha256(pe.data) == BIN_SHA256 == manifest["binary"]["sha256"], "wrong original BIN")
    require(len(pe.data) == manifest["binary"]["bytes"], "BIN length changed")
    require(pe.image_base == 0x400000, "wrong image base")
    require(manifest["repository_baseline"] == BASE == contract["baseline"], "baseline changed")
    shared = Path(manifest["shared_instructions"]["path"])
    require(sha256(shared.read_bytes()) == manifest["shared_instructions"]["sha256"], "shared instruction identity changed")

    pinned = {}
    for pin in manifest["git_sources"]:
        data = git_bytes(args.repo, pin["path"])
        require(pin["commit"] == BASE and pin["loaded_by_verifier"], "unpinned source")
        require(len(data) == pin["bytes"] and sha256(data) == pin["sha256"] and git_blob_id(data) == pin["git_blob_sha1"], f"source mismatch: {pin['path']}")
        pinned[pin["path"]] = data

    all_windows = list(evidence["windows"])
    for reference in evidence["reused_windows"]:
        source = json.loads(pinned[reference["source_path"]])
        window = next(w for w in source["windows"] if w["id"] == reference["source_window_id"])
        for key in ("va", "end", "sha256"):
            require(window[key] == reference[key], f"reused window changed: {key}")
        all_windows.append(window)
    instruction_map = {}
    checked_instructions = 0
    for window in all_windows:
        start, end = int(window["va"], 16), int(window["end"], 16)
        raw = pe.read(start, end - start)
        require(sha256(raw) == window["sha256"], f"window bytes: {window['id']}")
        require(pe.offset(start, end - start) == int(window["raw_offset"], 16), "PE mapping changed")
        # Decode from the documented function anchor to establish start boundary.
        decoded = disassemble(args.binary, int(window["function_anchor"], 16), end)
        selected = [row for row in decoded if start <= int(row["va"], 16) < end]
        require(selected and selected[0]["va"] == window["va"], f"start is not instruction boundary: {window['id']}")
        expected = [{"va": row["va"], "bytes": row["bytes"], "asm": " ".join(row["asm"].split())} for row in window["instructions"]]
        require(selected == expected, f"instruction replay mismatch: {window['id']}")
        require(b"".join(bytes.fromhex(row["bytes"]) for row in selected) == raw, "instruction bytes do not cover window")
        instruction_map.update({row["va"]: row for row in selected})
        checked_instructions += len(selected)
    for literal in evidence["strings"]:
        raw = bytes.fromhex(literal["bytes"])
        require(pe.read(int(literal["va"], 16), len(raw)) == raw, "literal changed")
        require(raw == literal["ascii"].encode("ascii") + b"\0", "literal decoding changed")
    imports = pe.imports()
    for record in evidence["native_imports"]:
        require(imports[int(record["iat_va"], 16)] == {"dll": record["dll"], "name": record["name"]}, "native import identity changed")

    # Explicit native decision/dataflow anchors, with the complete functions above.
    anchors = {
        "0x716498": "jne 0x7164a1", "0x71649a": "xor eax,eax",
        "0x7164b3": "call 0x891c3f", "0x716562": "call 0x891c3f", "0x716577": "call 0x891c3f",
        "0x7164b8": "mov eax,DWORD PTR [esp+0x20]", "0x71657c": "xor edi,edi",
        "0x716585": "jle 0x7165b5", "0x7165a3": "call 0x716040",
        "0x716615": "je 0x716679", "0x716679": "mov eax,DWORD PTR [ebx+0x4]",
        "0x716684": "mov esi,DWORD PTR [eax]", "0x7166b7": "mov eax,DWORD PTR [esi+0x28]",
        "0x7166c7": "call 0x7198f0", "0x71670c": "mov eax,0x1",
        "0x716118": "jne 0x716220", "0x716172": "lea ecx,[edi+0x1c]",
        "0x7161ae": "mov DWORD PTR [edi+0x38],ecx", "0x7162ac": "call 0x718ee0",
        "0x7163fc": "call 0x718fb0", "0x719010": "je 0x7191ba",
        "0x7190a6": "test al,0x10", "0x7190ae": "test al,0x2",
        "0x719249": "jne 0x7193e0", "0x719302": "call 0x718fb0",
        "0x7193e0": "test BYTE PTR [ebp-0x30c],0x12", "0x7197c5": "jmp 0x719256",
        "0x719337": "mov eax,DWORD PTR [edx+0xc]",
        "0x7167fa": "xor eax,eax", "0x716808": "call 0x7197e0",
        "0x71980f": "push 0x40", "0x719887": "xor eax,eax",
        "0x799170": "call 0x716440", "0x799177": "jne 0x799456",
        "0x799184": "mov DWORD PTR ds:0xfb79a8,ebx",
        "0x79944f": "call 0x716240", "0x799456": "mov DWORD PTR ds:0xfb79a8,edi",
        "0x7f6c18": "lea esi,[esp+0x14]", "0x7f6c3d": "call 0x718fb0",
        "0x7f6d3f": "lea ecx,[esp+0x14]", "0x7f6d43": "call 0x718dd0",
    }
    for va, assembly in anchors.items():
        require(instruction_map[va]["asm"] == assembly, f"semantic anchor changed: {va}")
    expected_census = pe.rel32_candidates([int(target, 16) for target in census["targets"]])
    require(expected_census == census["targets"], "finite census changed")
    for target, callers in census["targets"].items():
        for caller in callers:
            require(instruction_map[caller]["asm"] in (f"call {target}", f"jmp {target}"), "raw xref not a decoded instruction")

    require(len(contract["fallback_default_groups"]) == 10, "wrong fallback list")
    for row in contract["fallback_default_groups"]:
        call = int(row["call_va"], 16)
        require(instruction_map[row["call_va"]]["asm"] == "call 0x716040", "group registration target changed")
        # push recursive; push pattern; push group; mov ecx,directory; mov edx,manager.
        signature = b"\x57\x68" + struct.pack("<I", int(row["pattern_va"], 16)) + b"\x68" + struct.pack("<I", int(row["group_va"], 16)) + b"\xb9" + struct.pack("<I", int(row["directory_va"], 16)) + b"\xba" + struct.pack("<I", int(row["manager_va"], 16))
        require(pe.read(call - len(signature), len(signature)) == signature, "fallback ABI changed")
        for key in ("group", "pattern", "directory"):
            require(pe.cstring(int(row[key + "_va"], 16)).decode("ascii") == row[key], "fallback string changed")
        require(row["recursive"] == 1, "fallback recursion changed")
    require(contract["cache_reader"]["group_record"]["stride"] == GROUP_SIZE and contract["cache_reader"]["entry_record"]["stride"] == ENTRY_SIZE, "reader/layout mismatch")
    require(not contract["status"]["full_p0_ready"] and contract["status"]["native_selected_paths"] is None, "unknown gate was improperly promoted")
    require(not contract["status"]["resource_payload_ready"] and not contract["status"]["playable_verified"] and not contract["status"]["t01_full_pass"], "unproved completion flag")

    for root in availability["roots"]:
        path = Path(root["path"])
        files = [p for p in path.rglob("*") if p.is_file()] if path.exists() else []
        require(len(files) == root["file_count"], "supplied source inventory changed: refresh availability")
        observed = sorted(str(p.relative_to(path)) for p in files if p.name.lower() == "fcs.flu")
        require(observed == root["matching_cache_paths"], "new cache source detected: rerun analysis")
    for archive in availability["archives"]:
        path = Path(archive["path"])
        require(sha256(path.read_bytes()) == archive["sha256"], "archive identity changed")
        with zipfile.ZipFile(path) as handle:
            names = handle.namelist()
            matches = [n for n in names if n.replace("\\", "/").rsplit("/", 1)[-1].lower() == "fcs.flu"]
        require(len(names) == archive["member_count"] and matches == archive["matching_cache_members"], "archive availability changed")
    require(availability["actual_cache_observed"] is False, "actual cache requires a separate actual-source analysis")

    synthetic = synthetic_profile_checks()
    artifacts = read_json("artifact-manifest.json")
    for record in artifacts["files"]:
        data = (HERE / record["path"]).read_bytes()
        require(len(data) == record["bytes"] and sha256(data) == record["sha256"], f"artifact changed: {record['path']}")
    receipt = {
        "schema": "MEF_P0_SELECTION_VERIFICATION_V1",
        "checked_at_utc": datetime.datetime.now(datetime.timezone.utc).isoformat(),
        "result": "PASS_EVIDENCE_REPLAY_AND_OFFLINE_PROFILE",
        "original_bin_sha256": BIN_SHA256, "immutable_baseline": BASE,
        "git_source_pins_checked": len(pinned), "new_full_windows_checked": len(evidence["windows"]),
        "reused_windows_checked": len(evidence["reused_windows"]),
        "window_instructions_checked_including_overlaps": checked_instructions,
        "native_semantic_anchors_checked": len(anchors),
        "decoded_direct_call_candidates_checked": sum(map(len, census["targets"].values())),
        "fallback_group_definitions_checked": 10, "native_import_identities_checked": len(evidence["native_imports"]),
        "literal_records_checked": len(evidence["strings"]), "artifact_hashes_checked": len(artifacts["files"]),
        "synthetic_profile_cases": synthetic,
        "actual_fcs_input_analyzed": False, "native_execution": False, "server_execution": False,
        "native_selected_path": None, "resource_payload_ready": False, "full_p0_ready": False,
        "t01_full_pass": False,
        "meaning": "Exact evidence/data/tool replay only; human semantic claims remain bounded by report, originals and unresolved inputs. Synthetic vectors are not actual cache or Client success.",
    }
    print(json.dumps(receipt, ensure_ascii=False, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
