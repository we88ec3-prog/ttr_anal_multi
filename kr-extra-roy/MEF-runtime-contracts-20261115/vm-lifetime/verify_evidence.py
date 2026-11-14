#!/usr/bin/env python3
"""Read-only identity, instruction-boundary, finite-set and ownership verifier."""
import argparse
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
GIT_ENV = dict(os.environ, GIT_NO_LAZY_FETCH="1", GIT_OPTIONAL_LOCKS="0", GIT_TERMINAL_PROMPT="0")


def check(condition, message):
    if not condition:
        raise AssertionError(message)


def sha(data):
    return hashlib.sha256(data).hexdigest()


def read_json(name):
    return json.loads((HERE / name).read_text(encoding="utf-8"))


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--bin", required=True, type=Path)
    ap.add_argument("--repo", required=True, type=Path)
    args = ap.parse_args()
    manifest = read_json("source-manifest.json")
    helper = args.repo / manifest["helper"]["path"]
    check(sha(helper.read_bytes()) == manifest["helper"]["sha256"], "PE helper identity")
    spec = importlib.util.spec_from_file_location("pinned_read_only_pe", helper)
    lib = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(lib)
    pe = lib.PE(args.bin, manifest["original"])
    bundle = read_json("native-windows.json")
    records = bundle["records"]
    recs = {r["id"]: r for r in records}
    check(len(recs) == len(records), "unique record ids")
    asm = (HERE / "native-windows.asm").read_text(encoding="utf-8")
    instructions = {}
    total_ins = 0
    for r in records:
        start, end = int(r["va"], 16), int(r["end_exclusive"], 16)
        data = pe.at(start, end - start)
        check(end - start == r["length"], "window length: " + r["id"])
        check(pe.raw_of(start, len(data)) == int(r["raw"], 16), "raw offset: " + r["id"])
        check(data.hex() == r["hex"] and sha(data) == r["sha256"], "window bytes: " + r["id"])
        check("[" + r["id"] + "]" in asm, "asm record missing: " + r["id"])
        if r["kind"] != "code":
            continue
        output = subprocess.check_output([
            "objdump", "-d", "-M", "intel", "--insn-width=16",
            "--start-address=" + hex(start), "--stop-address=" + hex(end + 15), str(args.bin)
        ], text=True)
        cursor, decoded, rows = start, bytearray(), []
        for line in output.splitlines():
            m = re.match(r"^\s*([0-9a-f]+):\s*((?:[0-9a-f]{2}\s+)+)\s*(.*)$", line)
            if not m:
                continue
            va = int(m[1], 16)
            if va >= end:
                break
            code = bytes.fromhex(m[2])
            check(va == cursor and "(bad)" not in m[3] and not m[3].startswith(".byte"),
                  "instruction decoding: " + r["id"])
            expected_line = f"{va:08x}  {code.hex():32s}  {m[3]}"
            check(expected_line in asm, "published disassembly: " + r["id"])
            cursor += len(code)
            decoded.extend(code)
            rows.append((va, code, m[3]))
        check(cursor == end and decoded == data, "complete instruction endpoint: " + r["id"])
        check(len(rows) == r["instruction_count"], "instruction count: " + r["id"])
        instructions[r["id"]] = rows
        total_ins += len(rows)

    census = read_json("candidate-sets.json")
    function_targets = {int(x, 16) for x in census["function_targets"]}
    actual = {k: {"literals": [], "calls": [], "tails": []} for k in census["targets"]}
    for s in pe.sections:
        if s["name"] not in (".text", ".rdata", ".data"):
            continue
        data = pe.data[s["raw"]:s["raw"] + s["raw_size"]]
        for key in actual:
            pos, needle = 0, struct.pack("<I", int(key, 16))
            while True:
                pos = data.find(needle, pos)
                if pos < 0:
                    break
                actual[key]["literals"].append({"va": hex(s["va"] + pos),
                    "raw": hex(s["raw"] + pos), "section": s["name"]})
                pos += 1
        if s["name"] == ".text":
            for i in range(len(data) - 4):
                if data[i] not in (0xE8, 0xE9):
                    continue
                dest = (s["va"] + i + 5 + struct.unpack_from("<i", data, i + 1)[0]) & 0xffffffff
                if dest in function_targets:
                    actual[hex(dest)]["calls" if data[i] == 0xE8 else "tails"].append({
                        "va": hex(s["va"] + i), "raw": hex(s["raw"] + i), "hex": data[i:i + 5].hex()})
    for key, expected in census["targets"].items():
        check(actual[key]["literals"] == expected["literals"], "literal census: " + key)
        for kind in ("calls", "tails"):
            without_nav = [{k: v for k, v in x.items() if k != "owner"} for x in expected[kind]]
            check(actual[key][kind] == without_nav, kind + " census: " + key)

    relation = read_json("lifetime-relations.json")

    def call_target(va):
        check(pe.at(va, 1) == b"\xe8", "expected E8: " + hex(va))
        return (va + 5 + struct.unpack("<i", pe.at(va + 1, 4))[0]) & 0xffffffff

    for row in relation["guarded_constructions"]:
        va = int(row["callsite"], 16)
        check(call_target(va) == int(row["constructor"], 16), "constructor target")
        check(pe.at(va + 5, 5) == b"\x68" + struct.pack("<I", int(row["destructor"], 16)), "atexit target push")
        check(call_target(va + 10) == 0x89231A, "CRT registration target")
        code = instructions[row["record"]]
        guard_ops = [text for addr, _, text in code if addr < va and row["guard"] in text]
        check(any(x.startswith("test") for x in guard_ops) and any(x.startswith("or") for x in guard_ops),
              "guard test and set: " + row["callsite"])
    for target in ("0x6f4380", "0x55c610"):
        check({x["callsite"] for x in relation["guarded_constructions"] if x["constructor"] == target} ==
              {x["va"] for x in actual[target]["calls"]}, "all constructor candidates connected")

    guard_entries = 0
    for row in relation["exception_guard_clears"]:
        info, table = int(row["function_info"], 16), int(row["unwind_map"], 16)
        words = struct.unpack("<9I", pe.at(info, 36))
        check((words[0] & 0xfffffff0) == 0x19930520, "C++ FuncInfo magic")
        check(words[1] == row["max_state"] and words[2] == table, "unwind map identity")
        handler_bytes = bytes.fromhex(recs[row["record"]]["hex"])
        check(b"\xb8" + struct.pack("<I", info) in handler_bytes, "handler -> FuncInfo")
        prologue = bytes.fromhex(recs[row["record"] + "P"]["hex"])
        check(b"\x68" + struct.pack("<I", int(row["handler"], 16)) in prologue, "caller -> EH handler")
        for c in row["guard_clear"]:
            entry, action, guard = int(c["entry"], 16), int(c["action"], 16), int(c["guard"], 16)
            check(table <= entry < table + words[1] * 8 and (entry - table) % 8 == 0, "entry inside map")
            check(struct.unpack("<iI", pe.at(entry, 8)) == (c["prior_state"], action), "unwind -> action")
            signature = b"\xa1" + struct.pack("<I", guard) + b"\x83\xe0\xfe\xa3" + struct.pack("<I", guard) + b"\xc3"
            check(pe.at(action, len(signature)) == signature, "clear initialization bit")
            guard_entries += 1

    for key, entries in relation["global_literal_uses"].items():
        check([{k: row[k] for k in ("va", "raw", "section")} for row in entries] == actual[key]["literals"],
              "all selected global literals classified: " + key)
        for row in entries:
            ins = instructions[row["record"]]
            check(len(ins) == 1 and ins[0][0] == int(row["instruction_va"], 16) and ins[0][2] == row["instruction"],
                  "global literal instruction")
            check(ins[0][0] <= int(row["va"], 16) < ins[0][0] + len(ins[0][1]), "literal inside instruction")

    for row in relation["borrowed_wrapper_families"]:
        cleanup, handler = int(row["cleanup"], 16), int(row["handler"], 16)
        check(pe.at(cleanup, 4) == b"\x8d\x45\xe8\xe9", "stack wrapper cleanup")
        jump = cleanup + 3
        check(jump + 5 + struct.unpack("<i", pe.at(jump + 1, 4))[0] == 0x6F4410, "wrapper destructor tail")
        info, table = int(row["function_info"], 16), int(row["unwind_map"], 16)
        words = struct.unpack("<9I", pe.at(info, 36))
        check(words[1] == row["max_state"] and words[2] == table, "borrowed wrapper map")
        check(b"\xb8" + struct.pack("<I", info) in pe.at(handler, 27), "borrowed handler -> FuncInfo")
        for item in row["matching_entries"]:
            check(struct.unpack("<iI", pe.at(int(item["entry"], 16), 8)) == (item["prior_state"], cleanup), "borrowed EH cleanup entry")
        rep = next(r for r in records if int(r["va"], 16) == int(row["representative"], 16))
        code = bytes.fromhex(rep["hex"])
        check(b"\x68" + struct.pack("<I", handler) in code, "representative installs handler")
        # XOR EAX,EAX remains live through intervening stores into the wrapper.
        zero_sequence = ("33c08975e88945ec8945f0" if int(row["representative"], 16) == 0x4AC270
                         else "33c08945ec8945f0")
        check(bytes.fromhex(zero_sequence) in code, "borrowed wrapper initial owns=0")

    anchors = {
        0x6F4396: "a3c8f3fd00", 0x6F439B: "c705ccf3fd0000000000",
        0x6F43A5: "c705d0f3fd0001000000", 0x55C6B3: "a3ec1efe00",
        0x55C636: "33db", 0x55C6CA: "8910895804895808",
        0x6F4410: "8378080074078b00", 0x6F75F7: "8b4810",
        0x6F75FB: "8b7970", 0x6F7532: "897070",
        0x6F7528: "c7400c70716f00", 0x6F737B: "6a0068780100005750ffd1",
    }
    for va, raw in anchors.items():
        check(pe.at(va, len(bytes.fromhex(raw))).hex() == raw, "ownership/state anchor: " + hex(va))
    check(call_target(0x55D7C2) == 0x6F4A50, "prepass uses existing wrapper loader")
    prepass_calls = [int(text.split()[-1], 16) for _, _, text in instructions["P04"]
                     if re.fullmatch(r"call\s+0x[0-9a-f]+", text)]
    check(0x6F74B0 not in prepass_calls and 0x6F4380 not in prepass_calls, "prepass does not call state constructors")

    for source in manifest["sources"]:
        result = subprocess.check_output(["git", "ls-tree", source["commit"], "--", source["path"]],
                                         cwd=args.repo, text=True, env=GIT_ENV).strip()
        check(result.split("\t", 1)[0].split()[-1] == source["git_blob"], "source tree pin: " + source["path"])
        local = args.repo / source["path"]
        if local.is_file() and source.get("sha256"):
            check(sha(local.read_bytes()) == source["sha256"], "local pinned source bytes: " + source["path"])

    print(json.dumps({"status": "PASS", "scope": "read-only original bytes, complete instruction windows, named finite sets and explicit lifetime anchors",
        "original_sha256": manifest["original"]["sha256"], "records": len(records),
        "code_windows": len(instructions), "instruction_records_with_overlap": total_ins,
        "window_bytes_with_overlap": sum(r["length"] for r in records),
        "finite_function_targets": len(function_targets), "literal_targets": len(actual),
        "guarded_constructor_calls": len(relation["guarded_constructions"]),
        "exception_owner_functions": len(relation["exception_guard_clears"]),
        "guard_clear_entries": guard_entries, "borrowed_wrapper_families": len(relation["borrowed_wrapper_families"]),
        "source_tree_pins": len(manifest["sources"]),
        "limitation": "No Client or Lua execution; not a proof of arbitrary dynamic aliases, first MEF caller or gameplay completion."},
        ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
