#!/usr/bin/env python3
"""Verify this resource study against pinned original data and published proofs.
PASS means reproducible bounded research. It never means a ready/playable scene.
"""
from __future__ import annotations
import argparse
import hashlib
import importlib.util
import json
from pathlib import Path
import struct
import subprocess
import sys
import tempfile


def sha(data):
    return hashlib.sha256(data).hexdigest()


def require(condition, label):
    if not condition:
        raise RuntimeError(label)


def pe_sections(data):
    require(data[:2] == b"MZ", "PE DOS header")
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    require(data[pe:pe + 4] == b"PE\0\0", "PE signature")
    n = struct.unpack_from("<H", data, pe + 6)[0]
    optional_size = struct.unpack_from("<H", data, pe + 20)[0]
    optional = pe + 24
    require(struct.unpack_from("<H", data, optional)[0] == 0x10B, "PE32")
    imagebase = struct.unpack_from("<I", data, optional + 28)[0]
    sections = []
    for i in range(n):
        off = optional + optional_size + 40 * i
        virtual_size, rva, raw_size, raw = struct.unpack_from("<4I", data, off + 8)
        sections.append({"rva": rva, "raw_size": raw_size, "raw": raw, "virtual_size": virtual_size})
    return imagebase, sections


def mapped_raw(va, size, imagebase, sections):
    rva = va - imagebase
    for s in sections:
        if s["rva"] <= rva and rva + size <= s["rva"] + s["raw_size"]:
            return s["raw"] + rva - s["rva"]
    raise ValueError("window not fully backed by raw PE bytes")


def lexer_counterexamples(audit):
    # SYN lexical fixtures only: they are not game scenes or gameplay tests.
    cases = [
        ('-- PlayCamera("comment.cam",0,0,0,0)\nPlayCamera("real.cam",0,0,0,0) -- trailing\n', ["real.cam"], 0),
        ('--[=[\nPlayCamera("comment.cam",0,0,0,0)\n]=]\nPlayCameraNoWait("r.cam",0,0,0,0)', ["r.cam"], 0),
        ('x = \'PlayCamera("example.cam",0,0,0,0)\'\ny = [==[PlayCamera("example2.cam")]==]', [], 0),
        ('PlayCamera("a\\\"b.cam",0,0,0,0)', ['a"b.cam'], 0),
        ('PlayCamera("a\\046cam",0,0,0,0)', ['a.cam'], 0),
        ('function PlayCamera(name) return name end\nQ.PlayCamera("namespaced.cam",0)', [], 0),
        ('PlayCamera(prefix .. suffix,0,0,0,0)', [None], 0),
        ('PlayCamera "unsupported.cam"', [], 1),
    ]
    for index, (source, expected, unsupported_count) in enumerate(cases):
        calls, unsupported = audit.direct_calls(source)
        actual = [c["args"][0] if isinstance(c["args"][0], str) else None for c in calls]
        require(actual == expected and len(unsupported) == unsupported_count, f"SYN lexer counterexample {index}")
    return len(cases)


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--sources", type=Path, required=True)
    p.add_argument("--repo", type=Path, required=True)
    p.add_argument("--supplemental", type=Path, required=True, help="pinned Base.stp and W1/W2/W3 ZIP directory")
    p.add_argument("--result", type=Path)
    a = p.parse_args()
    here = Path(__file__).resolve().parent
    manifest = json.loads((here / "source-manifest.json").read_text())
    native = json.loads((here / "native-reuse-evidence.json").read_text())
    gov = json.loads((here / "governance-readset.json").read_text())
    for original in manifest["originals"]:
        directory = a.supplemental if original.get("source_group") == "supplemental" else a.sources
        raw = (directory / original["file"]).read_bytes()
        require(len(raw) == original["size"] and sha(raw) == original["sha256"], "original source " + original["file"])

    cache = {}
    for pin in manifest["published_pins"]:
        identity = f"{pin['commit']}:{pin['path']}"
        blob = subprocess.check_output(["git", "rev-parse", identity], cwd=a.repo, text=True).strip()
        require(blob == pin["blob_sha"], "published tree identity " + pin["path"])
        raw = subprocess.check_output(["git", "cat-file", "blob", blob], cwd=a.repo)
        require(len(raw) == pin["bytes"] and sha(raw) == pin["sha256"], "published content " + pin["path"])
        cache[pin["path"]] = raw
    for pin in gov["pins"]:
        blob = subprocess.check_output(["git", "rev-parse", f"{gov['main']}:{pin['path']}"], cwd=a.repo, text=True).strip()
        require(blob == pin["blob_sha"], "governance tree identity " + pin["path"])
        raw = subprocess.check_output(["git", "cat-file", "blob", blob], cwd=a.repo)
        require(len(raw) == pin["bytes"], "governance bytes " + pin["path"])
        if "sha256" in pin:
            require(sha(raw) == pin["sha256"], "governance digest " + pin["path"])

    binary = (a.sources / "02-Tartaros.bin").read_bytes()
    imagebase, sections = pe_sections(binary)
    native_bytes = 0
    for ref in native["records"]:
        old = json.loads(cache[ref["path"]])
        rows = old.get("records", old.get("windows"))
        window = next(w for w in rows if w.get("id", w.get("tag")) == ref["record_id"])
        raw_offset = mapped_raw(int(ref["va"], 16), ref["length"], imagebase, sections)
        require(raw_offset == int(ref["raw"], 16), "native PE mapping " + ref["record_id"])
        actual = binary[raw_offset:raw_offset + ref["length"]]
        expected = bytes.fromhex(window.get("hex", window.get("bytes_hex")))
        require(actual == expected and sha(actual) == ref["sha256"], "reused original window " + ref["record_id"])
        native_bytes += len(actual)

    spec = importlib.util.spec_from_file_location("resource_audit", here / "resource_audit.py")
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    fixtures = lexer_counterexamples(module)
    # One complete regeneration also checks the actual CLI refuses READY.
    with tempfile.TemporaryDirectory(prefix="mef-resource-verify-") as temp:
        run = subprocess.run([sys.executable, str(here / "resource_audit.py"), "--sources", str(a.sources),
                              "--repo", str(a.repo), "--supplemental", str(a.supplemental), "--output-dir", temp, "--require-ready"],
                             capture_output=True, text=True, check=False)
        require(run.returncode == 2, "preflight must refuse readiness for missing dependencies: " + run.stderr)
        summary = json.loads(run.stdout)
        require(summary["audit_completed"] is True and summary["ready"] is False, "audit success is not readiness")
        for filename in summary["files"]:
            actual = json.loads((Path(temp) / filename).read_text())
            saved = json.loads((here / filename).read_text())
            require(actual == saved, "full data regeneration " + filename)
    selected = json.loads((here / "selected-dependencies.json").read_text())["selected_scene"]
    camera = json.loads((here / "camera-audit.json").read_text())
    supplemental = json.loads((here / "supplemental-audit.json").read_text())
    require(len(selected["dialogue"]["text_matches"]) == 5, "bounded dialogue keys 1287..1291")
    require(len(camera["case_variant_candidates"]) == 1 and len(camera["absent_even_after_audit_casefold"]) == 42, "camera inventory findings")
    require(not camera["lexer_errors"] and not camera["unsupported_call_syntax"], "declared text scan coverage")
    require(supplemental["descriptor"]["selected_required_action_ids"] == [1, 4, 8, 11, 101, 103], "original descriptor selected action declarations")
    require(supplemental["zip_inventory"]["manifest_entries_verified"] == 130, "ZIP declaration integrity")
    require(len(supplemental["zip_inventory"]["original_table_byte_comparisons"]) == 9 and
            all(r["exact_bytes_equal"] for r in supplemental["zip_inventory"]["original_table_byte_comparisons"]), "ZIP Table bytes independently match original carrier")
    require(supplemental["current_dependency_state"]["native_model_descriptor_selection_proven"] is False and
            supplemental["ready"] is False, "descriptor availability must not become readiness")
    report = {
        "result": "PASS_REPRODUCIBLE_RESEARCH", "ready": False, "deployment_artifact": False,
        "source_originals_checked": len(manifest["originals"]), "published_source_pins_checked": len(manifest["published_pins"]),
        "main_governance_pins_checked": len(gov["pins"]), "previously_published_native_windows_rechecked": len(native["records"]),
        "native_bytes_rechecked": native_bytes, "synthetic_lexer_counterexamples": fixtures,
        "complete_data_outputs_regenerated": summary["files"], "require_ready_exit_status": run.returncode,
        "camera": {k: camera[k] for k in ("text_sequence_members", "literal_camera_call_occurrences", "literal_camera_unique_paths", "exact_path_miss_occurrences", "shape_summary_counts")},
        "supplemental": {"base_index_members": supplemental["base_inventory"]["member_count"],
                         "selected_action_declarations": len(supplemental["descriptor"]["selected_action_declarations"]),
                         "zip_entries": supplemental["zip_inventory"]["entries"], "zip_manifest_records_verified": 130,
                         "zip_table_members_equal_original": 9},
        "tool_sha256": {name: sha((here / name).read_bytes()) for name in ("resource_audit.py", "verify_evidence.py")},
        "limits": ["No Client, Lua, Server or original resource executed or modified", "No native format or loader validity claim from Python XML/filename checks",
                   "No T01, RR, REQ, gameplay or full MEF completion status changed", "Missing assets and unresolved transforms intentionally remain NOT_READY"],
    }
    if a.result:
        if any(directory.resolve() == a.result.resolve() or directory.resolve() in a.result.resolve().parents for directory in (a.sources, a.supplemental)):
            p.error("verification output must not overwrite original source tree")
        a.result.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n")
    print(json.dumps(report, ensure_ascii=False, indent=2))
    return 0


if __name__ == "__main__":
    sys.exit(main())
