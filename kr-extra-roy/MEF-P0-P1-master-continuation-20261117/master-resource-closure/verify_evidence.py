#!/usr/bin/env python3
"""Replay original Master, previous selected members and bounded native bytes.

The default is read-only. --require-ready exits 2 while genuine original
payload/cache/context gaps remain; a passing analysis is never deployment.
"""
import argparse
import json
from pathlib import Path
import re
import struct
import subprocess
import sys

sys.dont_write_bytecode = True
import master_audit as a
from adapter_audit import PE, import_walk


def pe(data):
    a.require(data[:2] == b"MZ", "MZ header")
    nt = struct.unpack_from("<I", data, 0x3c)[0]
    a.require(data[nt:nt+4] == b"PE\0\0", "PE signature")
    machine, count = struct.unpack_from("<HH", data, nt+4)
    opt = nt+24
    size = struct.unpack_from("<H", data, nt+20)[0]
    a.require(machine == 0x14c and struct.unpack_from("<H", data, opt)[0] == 0x10b, "PE32 i386")
    base = struct.unpack_from("<I", data, opt+28)[0]
    sections = []
    for i in range(count):
        _, va, n, raw = struct.unpack_from("<IIII", data, opt+size+i*40+8)
        sections.append((va, n, raw))
    return base, sections


def offset(va, base, sections):
    for start, n, raw in sections:
        if start <= va-base < start+n:
            return raw+va-base-start
    raise ValueError("VA outside file-backed PE section")


def disassemble(path, start, end):
    result = subprocess.check_output(["objdump", "-d", "-Mintel", "--insn-width=16",
                                      f"--start-address={start:#x}", f"--stop-address={end:#x}", str(path)], text=True)
    rows = []
    for line in result.splitlines():
        m = re.match(r"\s*([0-9a-f]+):\s*\t([0-9a-f ]+)\t(.+)$", line)
        if m:
            rows.append({"va": "0x"+m[1], "bytes": bytes.fromhex(m[2]).hex(), "asm": m[3].strip()})
    return rows


def window_check(row, data, binary, base, sections):
    start, end = int(row["va"], 16), int(row["end"], 16)
    off = offset(start, base, sections)
    raw = data[off:off+end-start]
    a.require(off == int(row["raw_offset"], 16) and a.sha(raw) == row["sha256"] and len(raw) == row["length"], "native window bytes "+row["id"])
    anchor = int(row["function_anchor"], 16)
    instructions = [r for r in disassemble(binary, anchor, end) if start <= int(r["va"], 16) < end]
    a.require(instructions == row["instructions"], "native instructions differ: "+row["id"])
    a.require(b"".join(bytes.fromhex(r["bytes"]) for r in instructions) == raw, "instruction boundary or coverage")
    a.require(not any("(bad)" in r["asm"] or ".byte" in r["asm"] for r in instructions), "invalid native decode")
    return len(instructions)


def verify(args):
    generated = a.analyze(args.repo, args.sources, args.supplemental)
    for name, value in generated.items():
        a.require(value == a.load_json(a.HERE/name), "regenerated analysis differs: "+name)
    manifest = a.load_json(a.HERE/"source-manifest.json")
    native = a.load_json(a.HERE/"native-evidence.json")
    binary = args.sources/"02-Tartaros.bin"
    data = binary.read_bytes()
    base, sections = pe(data)
    a.require(base == 0x400000 and a.sha(data) == native["binary_sha256"], "native image identity")
    count = 0
    for row in native["windows"]:
        count += window_check(row, data, binary, base, sections)
    for row in native["reused_windows"]:
        old = a.load_json(args.repo/row["source"])
        full = next(r for r in old["windows"] if r["id"] == row["source_window_id"])
        if row.get("source_format") == "WORLD_NATIVE_WINDOWS":
            full = dict(full, function_anchor=full["va"], raw_offset=full["raw"],
                        instructions=[{"va": i["va"], "bytes": i["hex"], "asm": i["asm"]}
                                      for i in full["instructions"]])
        for k in ["va", "end", "raw_offset", "length", "sha256"]:
            a.require(full[k] == row[k], "reused native source differs")
        window_check(full, data, binary, base, sections)
    for row in native["strings"]:
        off = offset(int(row["va"], 16), base, sections)
        raw = row["value"].encode("ascii")+b"\0"
        a.require(off == int(row["raw_offset"], 16) and data[off:off+len(raw)] == raw and a.sha(raw) == row["sha256"], "native exact string")
    for row in native["data_records"]:
        off = offset(int(row["va"], 16), base, sections)
        raw = data[off:off+row["length"]]
        a.require(raw.hex() == row["hex"] and a.sha(raw) == row["sha256"], "typed vtable bytes")
    typed = next(r for r in native["data_records"] if r["id"] == "image_secondary_load_vtable")
    a.require(struct.unpack_from("<I", bytes.fromhex(typed["hex"]), 4)[0] == 0x73abe0, "image secondary receiver slot+4")
    for name, expected in {"model_texture_adapter_vtable": (0x737ee0, 0x737f00),
                           "image_texture_create_adapter_vtable": (0x737fb0, 0x738000),
                           "image_info_adapter_vtable": (0x738050, 0x738070)}.items():
        table = next(r for r in native["data_records"] if r["id"] == name)
        a.require(struct.unpack("<II", bytes.fromhex(table["hex"])) == expected,
                  "typed adapter methods differ: "+name)
    a.require(import_walk(PE(data)) == native["native_imports"], "selected original PE imports differ")
    all_instructions = {r["va"]: r for w in native["windows"] for r in w["instructions"]}
    for va, iat in {"0x737f2d": 0xbd2624, "0x73803f": 0xbd2624, "0x73807f": 0xbd2628}.items():
        a.require(all_instructions[va]["bytes"] == (b"\xff\x15"+struct.pack("<I", iat)).hex(),
                  "adapter indirect import call operand "+va)
    for va, target in {"0x7d0c76": "0x79bce0", "0x7d0c97": "0x7cbf70", "0x7d0caf": "0x7cbee0",
                       "0x73accb": "0x737d40", "0x73ace7": "0x737f40", "0x737d73": "0x714550",
                       "0x737dbe": "0x714aa0", "0x737dfc": "0x714770", "0x714aaf": "0x714970",
                       "0x734387": "0x7340c0", "0x73422b": "0x737d40", "0x7342b2": "0x737f40",
                       "0x7aae66": "0x7bb970", "0x7aae80": "0x7bbb90"}.items():
        a.require(all_instructions[va]["asm"] == "call   "+target, "native connected call edge "+va)
    for va, expected in {"0x7d0c6e": "push   0xfb76a8", "0x7aae7b": "push   0xfe1ac8",
                         "0x7bcdb7": "mov    DWORD PTR [esp+0x28],0xc455f8"}.items():
        a.require(all_instructions[va]["asm"] == expected, "same native manager argument "+va)
    expected_asm = "\n\n".join("; "+w["id"]+" | "+w["claim"]+"\n"+
                    "\n".join(i["va"]+" "+i["bytes"]+" "+i["asm"] for i in w["instructions"])
                    for w in native["windows"])+"\n"
    a.require((a.HERE/"native-evidence.asm").read_text(encoding="utf-8") == expected_asm,
              "human-readable native listing differs from checked evidence")
    contract = a.load_json(a.HERE/"resource-loader-contract.json")
    a.require(not contract["original_source_selection_observed"] and not contract["deployment_artifact"] and
              not contract["mef"]["native_grammar_proven"] and not contract["mef"]["native_entry_proven"],
              "loader contract overclaims readiness or MEF")
    a.require(contract["texture"]["direct_image_chain"][0] == "560030" and
              contract["texture"]["direct_image_info_result_gate"] is False and
              contract["texture"]["prolog_info_result_gate"] == "nonnegative",
              "distinct image caller success gates must be retained")
    summary = generated["master-summary.json"]
    delta = generated["p0-frontier-delta.json"]
    routes = generated["selected-resource-routes.json"]
    a.require(summary["root_encflag_u32"] == 5 and not summary["root_encsetting_present"] and summary["loader_encsetting_default"] == 1,
              "EncFlag is not EncSetting")
    a.require(summary["packing_rules"]["binding_joins"] == 897 and summary["file_members"] == 899, "whole Master coverage")
    a.require(delta["remaining_blocked_entries"] == 108 and delta["missing_model_descriptor_payloads"] == 13 and delta["native_payloads_added_by_master"] == 0,
              "Master metadata must not silently satisfy missing payloads")
    a.require(not summary["resource_ready"] and not summary["mef_evidence"]["native_grammar_or_entry_proven"], "unsupported readiness/grammar claim")
    # Focused analyzer negative controls using the real observed layout in
    # memory. These are neither native fixtures nor gameplay tests.
    STP, _ = a.sources_checked(args.repo, args.sources, args.supplemental)
    packing, _ = STP(args.sources/"11-Master.stp").get("Master0z/PackingRules")
    bad = [packing[:-1], packing+b"\0", struct.pack("<I", 898)+packing[4:]]
    for b in bad:
        try:
            a.packing_rules(b)
        except (ValueError, UnicodeError, struct.error):
            pass
        else:
            raise ValueError("incomplete/overlong PackingRules was silently accepted")
    candidates = [p for r in routes["dependencies"] for p in r["requests"]]
    packed = [p for p in candidates if p["variant"] != "original_reference"]
    return {"schema": "MEF_MASTER_VERIFICATION_V1", "status": "PASS_REPRODUCIBLE_BOUNDED_ANALYSIS",
            "originals_checked": len(manifest["originals"]), "published_git_pins": len(manifest["published_pins"]),
            "master_members_redecoded": 899, "independent_index_nodes": summary["index_nodes"],
            "master_packing_rows_joined": 897, "packing_rule_negative_controls": 3,
            "previous_selected_members_rechecked": len(routes["selected_source_members_rechecked"]),
            "new_native_windows": len(native["windows"]), "new_native_bytes": sum(r["length"] for r in native["windows"]),
            "new_native_instructions": count, "reused_native_windows": len(native["reused_windows"]),
            "native_strings": len(native["strings"]), "typed_vtable_records": len(native["data_records"]),
            "selected_native_imports": len(native["native_imports"]["selected"]),
            "prior_dependency_nodes_rejoined": len(routes["dependencies"]),
            "conditional_packed_requests": len(packed), "distinct_conditional_packed_requests": len({p["request"] for p in packed}),
            "master_source_gate": "CLOSED_DECLARED_MOUNT_TREE", "p0_payload_gate": "BLOCKED_MISSING_ORIGINAL_SOURCE_OR_SELECTED_CONTEXT",
            "remaining_original_frontier_entries": 108, "resource_ready": False, "native_mef_grammar_proven": False,
            "complete_original_members_exported": False, "target_execution": False, "deployment_artifact": False,
            "formal_T01_RR_S00_status_changed": False, "require_ready_exit_status": 2}


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--repo", type=Path, required=True)
    ap.add_argument("--sources", type=Path, required=True)
    ap.add_argument("--supplemental", type=Path, required=True)
    ap.add_argument("--result", type=Path)
    ap.add_argument("--require-ready", action="store_true")
    args = ap.parse_args()
    result = verify(args)
    if args.result:
        a.require(args.result.name == "verification-result.json", "only verification-result.json receipt allowed")
        a.check_output(args.result.parent, args.repo, args.sources, args.supplemental)
        args.result.parent.mkdir(parents=True, exist_ok=True)
        a.dump(args.result, result)
    print(json.dumps(result, ensure_ascii=False, sort_keys=True))
    return 2 if args.require_ready else 0


if __name__ == "__main__":
    try:
        sys.exit(main())
    except (ValueError, OSError, KeyError, subprocess.CalledProcessError) as e:
        print(json.dumps({"status": "FAIL", "error": str(e)}), file=sys.stderr)
        sys.exit(1)
