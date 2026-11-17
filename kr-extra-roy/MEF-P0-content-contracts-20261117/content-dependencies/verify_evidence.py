#!/usr/bin/env python3
"""Verify complete bounded scene analysis without executing target content.

Default operation is read-only and prints a deterministic JSON receipt. The
optional --result writes only a new/current verification-result.json in this
package or an unrelated scratch directory. --require-ready deliberately exits
2 while real payload/selection evidence is blocked.
"""
import argparse
from collections import Counter
import importlib.util
import json
from pathlib import Path
import re
import struct
import subprocess
import sys

HERE = Path(__file__).resolve().parent
sys.dont_write_bytecode = True
import content_audit as audit


def require(condition, detail):
    if not condition:
        raise ValueError(detail)


def pe_sections(data):
    require(data[:2] == b"MZ", "PE MZ header")
    nt = struct.unpack_from("<I", data, 0x3c)[0]
    require(data[nt:nt+4] == b"PE\0\0", "PE signature")
    machine, count = struct.unpack_from("<HH", data, nt+4)
    opt = nt+24
    opt_size = struct.unpack_from("<H", data, nt+20)[0]
    require(machine == 0x14c and struct.unpack_from("<H", data, opt)[0] == 0x10b, "PE32 x86 required")
    base = struct.unpack_from("<I", data, opt+28)[0]
    sections = []
    for i in range(count):
        at = opt+opt_size+40*i
        _, rva, raw_size, raw = struct.unpack_from("<IIII", data, at+8)
        sections.append((rva, raw_size, raw))
    return base, sections


def raw_offset(va, base, sections):
    rva = va-base
    for start, size, raw in sections:
        if start <= rva < start+size:
            return raw+rva-start
    raise ValueError(f"VA has no file-backed section: {va:#x}")


def disassemble(binary, anchor, end):
    out = subprocess.check_output(["objdump", "-d", "-Mintel", "--insn-width=16",
        "--start-address="+hex(anchor), "--stop-address="+hex(end), str(binary)], text=True)
    rows = []
    for line in out.splitlines():
        m = re.match(r"\s*([0-9a-f]+):\s*\t([0-9a-f ]+)\t(.+)$", line)
        if m:
            rows.append({"va": "0x"+m[1], "bytes": bytes.fromhex(m[2]).hex(), "asm": m[3].strip()})
    return rows


def verify(args):
    # Reused parsers contain assertions; prohibit optimization even though this
    # verifier and all source gates use explicit errors.
    require(not sys.flags.optimize, "run without -O/PYTHONOPTIMIZE; reused parser checks must remain enabled")
    manifest = json.loads((HERE/"source-manifest.json").read_text())
    for pin in manifest["published_pins"]:
        object_name = pin["source_commit"]+":"+pin["path"]
        data = subprocess.check_output(["git", "show", object_name], cwd=args.repo)
        blob = subprocess.check_output(["git", "rev-parse", object_name], cwd=args.repo, text=True).strip()
        require(blob == pin["git_blob"], "Git blob mismatch: "+pin["path"])
        require(len(data) == pin["bytes"] and audit.sha(data) == pin["sha256"], "published SHA/length mismatch: "+pin["path"])
    for pin in manifest["originals"]:
        root = args.supplemental if pin["group"] == "supplemental" else args.sources
        data = (root/pin["file"]).read_bytes()
        require(len(data) == pin["bytes"] and audit.sha(data) == pin["sha256"], "original mismatch: "+pin["file"])
    binary = args.sources/"02-Tartaros.bin"
    data = binary.read_bytes()
    base, sections = pe_sections(data)
    native = json.loads((HERE/"native-evidence.json").read_text())
    require(native["binary_sha256"] == audit.sha(data), "native source mismatch")
    total = 0
    for row in native["windows"]:
        start, end, anchor = (int(row[k], 16) for k in ("va", "end", "function_anchor"))
        off = raw_offset(start, base, sections)
        raw = data[off:off+end-start]
        require(off == int(row["raw_offset"], 16) and len(raw) == row["length"] and audit.sha(raw) == row["sha256"], "native byte window "+row["id"])
        decoded = [r for r in disassemble(binary, anchor, end) if start <= int(r["va"], 16) < end]
        require(decoded == row["instructions"], "native disassembly "+row["id"])
        require(decoded and int(decoded[0]["va"], 16) == start, "native start boundary")
        require(int(decoded[-1]["va"], 16)+len(bytes.fromhex(decoded[-1]["bytes"])) == end, "native end boundary")
        require(b"".join(bytes.fromhex(r["bytes"]) for r in decoded) == raw, "native full byte coverage")
        require(not any("(bad)" in r["asm"] or ".byte" in r["asm"] for r in decoded), "invalid instruction")
        total += len(raw)
    for row in native["strings"]:
        off = raw_offset(int(row["va"], 16), base, sections)
        raw = row["value"].encode("ascii")+b"\0"
        require(off == int(row["raw_offset"], 16) and data[off:off+len(raw)] == raw and audit.sha(raw) == row["sha256"], "native string")
    for row in native["data_records"]+native["reused_windows"]:
        off = raw_offset(int(row["va"], 16), base, sections)
        raw = data[off:off+row["length"]]
        require(off == int(row["raw_offset"], 16) and audit.sha(raw) == row["sha256"], "native data/reuse bytes")
        if "hex" in row:
            require(raw.hex() == row["hex"], "native data hex")
    vt = next(r for r in native["data_records"] if r["id"] == "fld_parser_vtable")
    require(struct.unpack("<II", bytes.fromhex(vt["hex"])) == (0x7ea080, 0x7ed180), "FLD vtable targets")
    regenerated = audit.audit(args.repo, args.sources, args.supplemental)
    for name, value in regenerated.items():
        require(value == json.loads((HERE/name).read_text()), "regenerated content differs: "+name)
    graph = regenerated["scene-dependencies.json"]
    scenes = graph["scenes"]
    require([s["static_parse"]["function_body_call_count"] for s in scenes] == [46, 62], "whole-scene coverage changed")
    require([len(s["slots"]) for s in scenes] == [3, 14], "Create count changed")
    require([len(s["models"]) for s in scenes] == [1, 14], "model count changed")
    require(len(scenes[1]["prologs"][0]["dialogs"]) == 10 and len(scenes[1]["prologs"][0]["unique_pictures"]) == 7, "Prolog picture closure")
    require(all(s["ready"] is False and not s["full_transitive_payload_enumeration_complete"] for s in scenes), "blocked frontier must not become ready")
    require(graph["inventory_scope"]["parsed_base_descriptor_count"] == 2, "Base index is not full parsing")
    require(all(n["inventory"]["native_selected_path"] is None for n in graph["dependency_nodes"]), "inventory is not runtime selection")
    receipt = {"schema": "MEF_P0_CONTENT_VERIFICATION_V1", "status": "PASS_REPRODUCIBLE_BOUNDED_ANALYSIS",
        "original_count": len(manifest["originals"]), "published_pin_count": len(manifest["published_pins"]),
        "new_native_window_count": len(native["windows"]), "new_native_window_bytes": total,
        "native_string_count": len(native["strings"]), "native_data_records": len(native["data_records"]),
        "reused_native_window_count": len(native["reused_windows"]), "reused_native_bytes": sum(x["length"] for x in native["reused_windows"]),
        "complete_scene_functions": 2, "scene_body_calls": [46, 62], "Create_calls": 17, "unique_model_ids": 15,
        "actual_base_descriptors_parsed": 2, "missing_selected_model_descriptors": 13,
        "explicit_attachment_attempts": 9, "default_attachment_attempts_per_unique_model": 15,
        "camera_members_parsed": 8, "talk_rows_resolved": 12, "unique_direct_and_prolog_images": 8,
        "prolog_rows": 10, "prolog_text_lines": sum(d["line_count"] for d in scenes[1]["prologs"][0]["dialogs"]),
        "dependency_nodes": len(graph["dependency_nodes"]), "dependency_roles": dict(sorted(Counter(n["role"] for n in graph["dependency_nodes"]).items())),
        "frontier_entries": regenerated["dependency-frontier.json"]["entry_count"],
        "stp_members_read": len(regenerated["member-evidence.json"]["stp_members_read"]),
        "parser_checks": graph["parser_checks"], "ready": False, "deployment_artifact": False,
        "exact_runtime_selection": "BLOCKED_MISSING_ORIGINAL_SOURCE", "full_transitive_payload_enumeration_complete": False,
        "require_ready_exit_status": 2, "target_lua_client_server_execution": False,
        "formal_T01_RR_S00_status_changed": False}
    return receipt


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--repo", type=Path, required=True)
    ap.add_argument("--sources", type=Path, required=True)
    ap.add_argument("--supplemental", type=Path, required=True)
    ap.add_argument("--result", type=Path)
    ap.add_argument("--require-ready", action="store_true")
    args = ap.parse_args()
    receipt = verify(args)
    if args.result:
        require(args.result.name == "verification-result.json", "receipt filename must be verification-result.json")
        audit.check_output_directory(args.result.parent, args.repo, args.sources, args.supplemental)
        require(not args.result.is_symlink(), "receipt must not overwrite a symlink target")
        args.result.parent.mkdir(parents=True, exist_ok=True)
        audit.dump(args.result, receipt)
    print(json.dumps(receipt, ensure_ascii=False, sort_keys=True))
    return 2 if args.require_ready else 0


if __name__ == "__main__":
    try:
        sys.exit(main())
    except (ValueError, OSError, subprocess.CalledProcessError) as error:
        print(json.dumps({"status": "FAIL", "error": str(error)}, ensure_ascii=False), file=sys.stderr)
        sys.exit(1)
