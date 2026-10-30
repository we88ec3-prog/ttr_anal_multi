#!/usr/bin/env python3
"""Recheck T08-129..152 author's replacement sources against native KR Tartaros.bin.

This is an exact byte/VA/crosswalk audit, NOT an independent full-CFG, semantic,
FULL-PASS, release, or runtime validation. Uses only Python standard library.
Usage: python verify_legacy_corrected_sources.py --repo /path/to/ttr_anal_multi --bin /path/to/Tartaros.bin
"""
import argparse
import hashlib
import json
import re
from pathlib import Path

TARGET_SHA = "9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
NUMBERS = list(range(129, 153))
TEXT_VA = 0x401000
TEXT_RAW = 0x400
TEXT_SIZE = 0x7d0600 - 0x400
HEX_CHECKS = {
    131: [(0x7B8A50, "55 8b ec 6a ff 68 c6 8b 91 00")],
    132: [(0x7BB240, "55 8b ec 6a ff 68 9e b7 92 00")],
    148: [(0x7A4C50, "55 8b ec 6a ff 68 63 79 90 00"), (0x4CA460, "55 8b ec 6a ff 68 20 89 90 00")],
    149: [(0x7A63C0, "55 8b ec 6a ff 68 76 bd 92 00"), (0x7A8E10, "55 8b ec 83 ec 0c")],
    150: [(0x4CA460, "55 8b ec 6a ff 68 20 89 90 00"), (0x4E0F60, "55 8b ec 83 ec 0c")],
    151: [(0x4CA660, "8b 49 0c 85 c9 74 08 8b 01 8b 10 6a 01 ff d2 c3"), (0x7A3920, "85 c9 74 09 8b 01 8b 50 08 6a 01 ff d2 c3")],
}

def exact_at(binary, va, bs):
    off = va - TEXT_VA + TEXT_RAW
    if not (TEXT_RAW <= off and off + len(bs) <= TEXT_RAW + TEXT_SIZE):
        return False
    return binary[off:off + len(bs)] == bs

def rel_target(va, bs):
    if len(bs) == 5 and bs[0] in (0xE8, 0xE9):
        return (va + 5 + int.from_bytes(bs[1:5], "little", signed=True)) & 0xFFFFFFFF
    return None

def audit(repo, target):
    bin_bytes = target.read_bytes()
    assert len(bin_bytes) == 12472320, "target length"
    assert hashlib.sha256(bin_bytes).hexdigest() == TARGET_SHA, "target SHA256"
    root = repo / "kr-temp-roy" / "T01-legacy-pe-crosswalk"
    mapping_path = repo / "shared/integrations/T01-20261029-semantic-review/t08-early/mapping-findings.json"
    reviews_path = repo / "shared/integrations/T01-20261029-semantic-review/t08-early/mapping-reviews.json"
    mapping = json.loads(mapping_path.read_text("utf-8"))
    reviews = json.loads(reviews_path.read_text("utf-8"))
    assert mapping["target_sha256"] == TARGET_SHA, "mapping provenance"
    by_n = {int(r["number"]): r for r in mapping["reports"]}
    reviews_by_n = {int(re.search(r"T08-(\\d+)-", r["source"]).group(1)): r for r in reviews["reviews"]}
    assert len(reviews_by_n) == 24 and len(by_n) == 18, "expected review/map counts"
    covered = 0
    summary = []
    for n in NUMBERS:
        rev = reviews_by_n[n]
        srcs = sorted((root / "corrected-sources").glob(f"*-T08-{n}-corrected-source-v3.md"))
        assert len(srcs) == 1, f"T08-{n}: expected one v3 source, got {srcs}"
        report = srcs[0].read_text("utf-8").lower()
        assert rev["git_blob_sha"] in report, f"T08-{n}: original SHA absent"
        assert rev["source"] in report, f"T08-{n}: original path absent"
        assert TARGET_SHA in report, f"T08-{n}: target identity absent"
        rows = by_n.get(n, {}).get("rows", [])
        for row in rows:
            assert row.get("affine_candidate_equal"), f"T08-{n}: unchecked T01 mapping {row['va']}"
            va = int(row["affine_candidate_va"], 16)
            raw = bytes.fromhex(row["expected"])
            assert raw == bytes.fromhex(row["affine_candidate_bytes"]), f"T08-{n}: T01 mapped wrong"
            assert exact_at(bin_bytes, va, raw), f"T08-{n}: BIN byte mismatch at {va:08X}"
            needle = f"|{row['va']}|{row['affine_candidate_va']}|`{row['affine_candidate_bytes']}`|".lower()
            # Some v3 docs render the corrected VA in uppercase.
            assert needle in report, f"T08-{n}: row absent {va:08X}"
            computed = rel_target(va, raw)
            if computed is not None:
                assert f"0x{computed:x}" in report, f"T08-{n}: bad relative target at {va:08X}"
            covered += 1
        for va, hexbytes in HEX_CHECKS.get(n, []):
            assert exact_at(bin_bytes, va, bytes.fromhex(hexbytes)), f"T08-{n}: independent entry mismatch {va:08X}"
        summary.append({"source": n, "rows": len(rows), "entry_checks": len(HEX_CHECKS.get(n, [])), "result": "BYTE_PASS"})
        print(f"T08-{n:03d}: BYTE_PASS, mapped_rows={len(rows)}, entry_checks={len(HEX_CHECKS.get(n, []))}")
    assert covered == 1263, f"expected 1263 native mapped rows, got {covered}"
    print("NATIVE_ROW_AUDIT_PASS: 24 new sources, 18 T01 mapped reports, 1263/1263 original BIN byte locations")
    print("IMPORTANT: this does NOT certify whole-source CFG, ABI, runtime safety, T01 FULL-PASS or reviewer RESOLVED")
    return summary

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--repo", type=Path, required=True)
    parser.add_argument("--bin", type=Path, required=True)
    args = parser.parse_args()
    audit(args.repo, args.bin)
