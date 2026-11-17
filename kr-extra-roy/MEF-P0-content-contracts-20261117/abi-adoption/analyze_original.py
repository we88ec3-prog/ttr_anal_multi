#!/usr/bin/env python3
"""Inspect original SEQ text and Lua-5.1 prototype data, never execute Lua.

Produces call-level metadata and bounded excerpts, not unpacked resources.
Call resolution uses a finite name-only CFG reaching-definition analysis.
No code generation, constant execution, arbitrary alias or runtime claim.
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

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
EVENT_SHA = "2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b"
OPS = "MOVE LOADK LOADBOOL LOADNIL GETUPVAL GETGLOBAL GETTABLE SETGLOBAL SETUPVAL SETTABLE NEWTABLE SELF ADD SUB MUL DIV MOD POW UNM UNOT LEN CONCAT JMP EQ LT LE TEST TESTSET CALL TAILCALL RETURN FORLOOP FORPREP TFORLOOP SETLIST CLOSE CLOSURE VARARG".split()
SCENES = {"Q119/3": "Event/Sequences/Phindous_YuriandRazed_Boss.seq",
          "Q2440/5": "Event/Sequences/Aisen_01_After.seq"}


def sha(data):
    return hashlib.sha256(data).hexdigest()


def load_sources(repo):
    manifest = json.loads((HERE / "source-manifest.json").read_text())
    sources = {}
    for row in manifest["repository_sources"]:
        if row.get("analysis_input"):
            path = repo / row["path"]
            raw = path.read_bytes() if path.exists() else subprocess.check_output(
                ["git", "-c", "remote.origin.promisor=false", "cat-file", "blob", row["git_blob"]], cwd=repo)
            if len(raw) != row["bytes"] or sha(raw) != row["sha256"]:
                raise ValueError("pinned analysis source differs: " + row["path"])
            if row.get("content_kind") == "lua51_chunk":
                sources[row["id"]] = raw
            elif path.suffix == ".py":
                spec = importlib.util.spec_from_file_location("p0_pinned_" + row["id"], path)
                module = importlib.util.module_from_spec(spec)
                spec.loader.exec_module(module)
                sources[row["id"]] = module
            else:
                sources[row["id"]] = json.loads(raw)
    return sources


def decode(proto):
    rows = []
    for pc, word in enumerate(proto["words"]):
        opcode = word & 63
        if opcode >= len(OPS):
            raise ValueError("unsupported prototype opcode")
        a, b, c, bx = (word >> 6) & 255, (word >> 23) & 511, (word >> 14) & 511, word >> 14
        row = {"pc": pc, "raw_offset": proto["code_offset"] + 4 * pc,
               "word": hex(word), "op": OPS[opcode], "A": a, "B": b, "C": c}
        if opcode in (1, 5, 7):
            row["constant"] = proto["constants"][bx]
        if opcode in (6, 9, 11, 23, 24, 25):
            row["RK_C"] = {"constant": proto["constants"][c - 256]} if c >= 256 else {"register": c}
        if opcode in (23, 24, 25):
            row["RK_B"] = {"constant": proto["constants"][b - 256]} if b >= 256 else {"register": b}
        if opcode in (22, 31, 32):
            row["target"] = pc + 1 + bx - 131071
        rows.append(row)
    return rows


def cfg(rows):
    count = len(rows)
    edges = {}
    for row in rows:
        pc, op = row["pc"], row["op"]
        if op in ("RETURN", "TAILCALL"):
            targets = []
        elif op in ("JMP", "FORPREP"):
            targets = [row["target"]]
        elif op == "FORLOOP":
            targets = [pc + 1, row["target"]]
        elif op in ("EQ", "LT", "LE", "TEST", "TESTSET", "TFORLOOP"):
            targets = [pc + 1, pc + 2]
        elif op == "LOADBOOL" and row["C"]:
            targets = [pc + 2]
        else:
            targets = [pc + 1]
        if any(target < 0 or target >= count for target in targets):
            raise ValueError("prototype control flow escapes its instruction array")
        edges[pc] = targets
    reachable, todo = set(), [0]
    while todo:
        pc = todo.pop()
        if pc in reachable:
            continue
        reachable.add(pc)
        todo.extend(edges[pc])
    predecessors = {pc: set() for pc in reachable}
    for pc in reachable:
        for target in edges[pc]:
            predecessors[target].add(pc)
    dominators = {pc: ({0} if pc == 0 else set(reachable)) for pc in reachable}
    changed = True
    while changed:
        changed = False
        for pc in sorted(reachable - {0}):
            updated = {pc} | set.intersection(*(dominators[parent] for parent in predecessors[pc]))
            if updated != dominators[pc]:
                dominators[pc] = updated
                changed = True
    return edges, reachable, dominators


def audit_proto(proto, export, native):
    rows = decode(proto)
    edges, reachable, _ = cfg(rows)
    # A finite forward dataflow lattice. None means an unknown reaching value.
    # Values are names only: no numeric evaluation or Lua calls are executed.
    unknown = (frozenset({None}), frozenset())
    stack = proto["stack"]
    before = {0: tuple(unknown for _ in range(stack))}
    todo = [0]
    covered = {}
    for row in rows:
        covered[row["op"]] = covered.get(row["op"], 0) + 1
        if row["op"] == "CLOSURE":
            # No selected qbase helper has nested CLOSURE data words. Explicitly
            # fail closed if a changed source requires child-upvalue decoding.
            raise ValueError("nested CLOSURE requires a dedicated CFG contract")
        if row["op"] == "SETLIST" and row["C"] == 0:
            raise ValueError("SETLIST extension word requires a dedicated CFG contract")

    def transfer(state, row):
        out = list(state)
        pc, op, a, b, c = (row[key] for key in ("pc", "op", "A", "B", "C"))
        def get(register):
            if not 0 <= register < stack:
                raise ValueError("register outside original prototype stack")
            return state[register]
        def put(register, value=unknown):
            if not 0 <= register < stack:
                raise ValueError("destination outside original prototype stack")
            out[register] = value
        def member(base, operand):
            names, provenance = base
            key = operand.get("constant")
            if not isinstance(key, str):
                return unknown
            derived = {None if name is None or name.count(".") >= 2 else name + "." + key for name in names}
            return frozenset(derived), provenance | {pc}
        if op == "GETGLOBAL":
            put(a, (frozenset({row["constant"]}), frozenset({pc})))
        elif op == "GETTABLE":
            put(a, member(get(b), row["RK_C"]))
        elif op == "SELF":
            put(a + 1, get(b))
            put(a, member(get(b), row["RK_C"]))
        elif op == "MOVE":
            names, provenance = get(b)
            put(a, (names, provenance | {pc}))
        elif op == "LOADNIL":
            for register in range(a, b + 1):
                put(register)
        elif op in ("CALL", "TAILCALL"):
            if c != 1:
                for register in range(a, stack if c == 0 else a + c - 1):
                    put(register)
        elif op == "VARARG":
            for register in range(a, stack if b == 0 else a + b - 1):
                put(register)
        elif op == "TFORLOOP":
            for register in range(a + 2, a + 3 + c):
                put(register)
        elif op == "FORLOOP":
            put(a)
            put(a + 3)
        elif op == "FORPREP":
            put(a)
        elif op in ("LOADK", "LOADBOOL", "GETUPVAL", "NEWTABLE", "ADD", "SUB", "MUL", "DIV", "MOD", "POW", "UNM", "UNOT", "LEN", "CONCAT", "TESTSET"):
            # TESTSET is conservatively unknown for both successor edges.
            put(a)
        elif op not in ("SETGLOBAL", "SETUPVAL", "SETTABLE", "JMP", "EQ", "LT", "LE", "TEST", "RETURN", "SETLIST", "CLOSE"):
            raise ValueError("unhandled opcode transfer: " + op)
        return tuple(out)

    while todo:
        pc = todo.pop()
        outgoing = transfer(before[pc], rows[pc])
        for target in edges[pc]:
            if target not in before:
                before[target] = outgoing
                todo.append(target)
                continue
            merged = tuple((left[0] | right[0], left[1] | right[1]) for left, right in zip(before[target], outgoing))
            if merged != before[target]:
                before[target] = merged
                todo.append(target)
    calls = []
    for row in rows:
        pc, op, a, b, c = (row[key] for key in ("pc", "op", "A", "B", "C"))
        if pc not in reachable or op not in ("CALL", "TAILCALL"):
            continue
        names, provenance = before[pc][a]
        accepted = len(names) == 1 and None not in names
        name = next(iter(names)) if accepted else None
        item = {"pc": pc, "opcode": op, "callee": name,
                "callee_proof": "UNIQUE_REACHING_GLOBAL_MEMBER_NAME_ON_ALL_CFG_PREDECESSORS" if accepted else "UNRESOLVED",
                "definition_pcs": sorted(provenance) if accepted else [],
                "argument_count": b - 1 if b else None,
                "result_count": c - 1 if c else None,
                "normal_binding": name in native}
        if name in native:
            item["expected_native_argument_count"] = native[name]["argument_count"]
            item["exact_arity_matches"] = b != 0 and b - 1 == native[name]["argument_count"]
            item["binding_status"] = native[name]["binding_status"]
        if export["name"] == "RevPhase1" and proto["index"] == 74 and pc == 38 and name == "Q.EndSepia" and b == 1:
            item["bounded_original_compatibility"] = {
                "contract": "zeroarg-endsepia-contract.json#ORIGINAL-REVPHASE1-ENDSEPIA-ZERO",
                "derived_native_integer": 0,
                "condition": "Original C binding, ordinary valid frame/allocator, no debug hook mutating frame; separate native proof required",
                "new_authoring_policy": "REQUIRE_ONE_EXPLICIT_INTEGER"}
        calls.append(item)
    return {"name": export["name"], "prototype": proto["index"], "parameters": proto["params"],
            "code_sha256": sha(struct.pack("<" + "I" * len(proto["words"]), *proto["words"])),
            "instruction_words": len(proto["words"]), "opcode_coverage": covered,
            "dataflow_scope": "Finite name-only CFG reaching-definition join; unknown values block positive resolution; globals remain runtime mutable",
            "calls": calls}


def text_calls(text, lexer):
    tokens = lexer.lua_tokens(text)
    result = []
    for index, token in enumerate(tokens):
        if token["kind"] != "name" or token["raw"] in ("function", "if", "while", "for", "return", "local", "repeat", "until") or (index and tokens[index - 1]["raw"] in (".", ":", "function")):
            continue
        end_name, name = index + 1, token["raw"]
        while end_name + 1 < len(tokens) and tokens[end_name]["raw"] == "." and tokens[end_name + 1]["kind"] == "name":
            name += "." + tokens[end_name + 1]["raw"]
            end_name += 2
        if end_name >= len(tokens) or tokens[end_name]["raw"] != "(":
            continue
        args, depth, begin = [], 0, end_name + 1
        for stop in range(begin, len(tokens)):
            raw = tokens[stop]["raw"] if tokens[stop]["kind"] == "symbol" else None
            if raw == ")" and depth == 0:
                if stop > begin:
                    args.append(tokens[begin:stop])
                result.append({"name": name, "line": token["line"], "args": args,
                               "start": token["start"], "end": tokens[stop]["end"]})
                break
            if raw == "," and depth == 0:
                args.append(tokens[begin:stop])
                begin = stop + 1
            elif raw in ("(", "{", "["):
                depth += 1
            elif raw in (")", "}", "]"):
                depth -= 1
        else:
            raise ValueError("unclosed call")
    return result


def analyze(repo, event):
    sources = load_sources(repo)
    if sha(event.read_bytes()) != EVENT_SHA:
        raise ValueError("Event source identity differs")
    archive = sources["STP_READER"].STP(event)
    parser, lexer = sources["LUA_PARSER"], sources["LEXER"]
    native = {row["name"]: row for row in sources["ABI"]["bindings"]}
    export_index = sources["HELPERS"]
    exports = {row["name"]: row for row in export_index["exports"]}
    chunk, qmeta = archive.get("Event/qbase.lua")
    protos = parser.read_lua51_prototypes(chunk)
    if len(protos) != 76 or len(exports) != 75 or sha(chunk) != export_index["member"]["decoded_sha256"]:
        raise ValueError("original qbase identity/shape changed")
    helper_rows = []
    for export in export_index["exports"]:
        row = audit_proto(protos[export["prototype"]], export, native)
        if row["code_sha256"] != export["code_sha256"]:
            raise ValueError("helper code hash differs")
        helper_rows.append(row)
    helper_by_name = {row["name"]: row for row in helper_rows}
    manifest = json.loads((HERE / "source-manifest.json").read_text())
    bootstrap = []
    for source_id, filename in (("COROUTINE_CHUNK", "Coroutine.lua"), ("BOOT_CHUNK", "boot.lua"), ("LOGIC_CHUNK", "Logic.lua")):
        pin = next(row for row in manifest["repository_sources"] if row["id"] == source_id)
        source_path = "kr-temp-roy/T16-local-20261028/evidence/resources/kr/" + filename
        mapping = [row for row in sources["SOURCE_MAP"]["sources"] if row["original_path"] == source_path and row["version"] == "kr"]
        if len(mapping) != 1 or mapping[0]["portable_path"] != pin["path"] or mapping[0]["sha256"] != pin["sha256"]:
            raise ValueError("exact KR bootstrap source-map identity")
        raw = sources[source_id]
        ps = parser.read_lua51_prototypes(raw)
        record = {"id": source_id, "source_map_entry": mapping[0],
                  "git_source": {key: pin[key] for key in ("path", "git_blob", "sha256", "bytes")},
                  "prototype_count": len(ps), "instruction_words": sum(len(proto["words"]) for proto in ps),
                  "TRUE_FALSE_direct_SETGLOBAL": [{"prototype": proto["index"], "pc": row["pc"], "name": row["constant"]}
                                                   for proto in ps for row in decode(proto)
                                                   if row["op"] == "SETGLOBAL" and row["constant"] in ("TRUE", "FALSE")]}
        if source_id == "BOOT_CHUNK":
            root = ps[0]
            if root["words"][:4] != [0x4001, 0x7, 0xC001, 0x8007] or root["constants"][:4] != ["TRUE", 1.0, "FALSE", 0.0]:
                raise ValueError("original Boot numeric global assignment prefix changed")
            record["bounded_root_prefix"] = decode(root)[:4]
            record["assignment_contract"] = {"TRUE": {"lua_type": "number", "value": 1}, "FALSE": {"lua_type": "number", "value": 0}}
            record["prefix_condition"] = "These first four original instructions execute; later script/global mutations remain outside this initialization claim"
        bootstrap.append(record)
    scenes = []
    for selector, member in SCENES.items():
        raw, meta = archive.get(member)
        # Both selected original SEQs contain only ASCII bytes. Enforce this
        # bounded fact instead of guessing a general Client text codepage.
        text = raw.decode("ascii")
        calls = text_calls(text, lexer)
        reviewed = []
        for call in calls:
            name = call["name"]
            helper = exports.get(name)
            binding = native.get(name)
            expected = helper["parameters"] if helper else (binding["argument_count"] if binding else None)
            item = {"line": call["line"], "name": name, "argument_count": len(call["args"]),
                    "layer": "ORIGINAL_QBASE_HELPER" if helper else ("NORMAL_BINDING" if binding else "OTHER_GLOBAL"),
                    "expected_argument_count": expected,
                    "exact_arity_matches": None if expected is None else expected == len(call["args"]),
                    "symbolic_arguments": [{"argument": i + 1, "symbol": arg[0]["raw"]}
                                           for i, arg in enumerate(call["args"])
                                           if len(arg) == 1 and arg[0]["kind"] == "name"]}
            if helper:
                item["qbase_prototype"] = helper["prototype"]
            for symbolic in item["symbolic_arguments"]:
                if symbolic["symbol"] in ("TRUE", "FALSE"):
                    symbolic["baseline_boot_value"] = {"lua_type": "number", "value": 1 if symbolic["symbol"] == "TRUE" else 0}
                    symbolic["condition"] = "Original Boot prefix executed and global not subsequently changed; source call is preserved"
            if name == "Register":
                item["scope"] = "TOP_LEVEL_REGISTRATION_NOT_SCENE_BODY"
            if name in ("SetFinalMusic", "OpenTalkScene", "FlyingObject") or (name in ("CreateObject", "WalkObject") and not any(x["name"] == name for x in reviewed)):
                item["bounded_excerpt"] = text[call["start"]:call["end"]]
            reviewed.append(item)
        reached, todo = set(), [row["name"] for row in reviewed if row["name"] in helper_by_name]
        while todo:
            name = todo.pop()
            if name in reached:
                continue
            reached.add(name)
            todo.extend(row["callee"] for row in helper_by_name[name]["calls"] if row["callee"] in helper_by_name)
        problems = [{"helper": name, **call} for name in sorted(reached)
                    for call in helper_by_name[name]["calls"]
                    if call.get("normal_binding") and not call["exact_arity_matches"]]
        scenes.append({"selector_label": selector, "source_member": meta,
                       "selected_original_text_encoding": "ASCII_ONLY_BYTES_VERIFIED",
                       "source_never_modified": True, "review_status": "STATIC_REVIEW_COMPLETE_NOT_AUTHORING_PASS",
                       "calls": reviewed, "transitively_referenced_qbase_helpers": sorted(reached),
                       "reachable_native_arity_mismatches": problems,
                       "other_globals": sorted({row["name"] for row in reviewed if row["layer"] == "OTHER_GLOBAL"}),
                       "deployment_ready": False})

    global_records = []
    for member in ("Event/qbase.lua", "Event/TutorialBase.lua", "Event/TutorialMain.lua"):
        raw, meta = archive.get(member)
        ps = parser.read_lua51_prototypes(raw)
        globals_read, globals_written = [], []
        for proto in ps:
            for row in decode(proto):
                if row["op"] in ("GETGLOBAL", "SETGLOBAL") and row["constant"] in ("TRUE", "FALSE"):
                    (globals_read if row["op"] == "GETGLOBAL" else globals_written).append(
                        {"prototype": proto["index"], "pc": row["pc"], "name": row["constant"]})
        global_records.append({"member": meta, "prototype_count": len(ps),
                               "instruction_words": sum(len(p["words"]) for p in ps),
                               "TRUE_FALSE_direct_GETGLOBAL": globals_read,
                               "TRUE_FALSE_direct_SETGLOBAL": globals_written,
                               "scope": "Direct GETGLOBAL/SETGLOBAL in these original prototype arrays only; does not exclude computed table writes or earlier loaders"})

    mismatches = [{"helper": helper["name"], **call} for helper in helper_rows
                  for call in helper["calls"] if call.get("normal_binding") and not call["exact_arity_matches"]]
    selected = [17, 18, 21, 25, 26, 38, 62, 64]
    helper_evidence = {"schema": "ttr-mef-p0-helper-bridge-evidence-v1", "not_native_mef": True,
                       "member": qmeta, "scope": "Bounded original prototype excerpts; data decoding only",
                       "selected_prototypes": [{**protos[index], "decoded": decode(protos[index])} for index in selected],
                       "arity_mismatch_excerpt": {"prototype": 74, "helper": "RevPhase1",
                                                   "selected_instructions": decode(protos[74])[36:39]},
                       "source_global_inventory": global_records}
    return {
        "original-call-review.json": {"schema": "ttr-mef-p0-original-call-review-v1", "not_native_mef": True,
                                      "scope": "Two selected original scenes; call layers and static arity, not execution or a rewritten SEQ",
                                      "scenes": scenes, "deployment_ready": False, "lua_executed": False},
        "helper-call-audit.json": {"schema": "ttr-mef-p0-qbase-call-audit-v1", "not_native_mef": True,
                                   "scope": "All 75 root-exported original helpers; bounded name-only CFG reaching-definition analysis, not all dynamic Lua calls",
                                   "member": qmeta, "helpers": helper_rows, "native_arity_mismatches": mismatches,
                                   "normal_native_call_sites": sum(call["normal_binding"] for row in helper_rows for call in row["calls"]),
                                   "nonfunctional_native_call_sites": [{"helper": row["name"], **call} for row in helper_rows for call in row["calls"] if call.get("binding_status") in ("STUB", "NOT_COUNT_QUERY")],
                                   "unresolved_call_sites": [{"helper": row["name"], "pc": call["pc"]} for row in helper_rows for call in row["calls"] if call["callee"] is None],
                                   "deployment_ready": False, "lua_executed": False},
        "helper-bridge-evidence.json": helper_evidence,
        "bootstrap-global-contract.json": {"schema": "ttr-mef-p0-bootstrap-globals-v1", "not_native_mef": True,
                                           "scope": "Original KR Git-preserved Lua chunks, source-map provenance, and selected numeric initialization prefix",
                                           "source_commit": manifest["source_commit"], "sources": bootstrap,
                                           "native_load_order": [{"call_va": "0x560796", "name": "Coroutine.lua"}, {"call_va": "0x5607a2", "name": "Boot.lua"},
                                                                 {"call_va": "0x5607ae", "name": "Logic.lua"}, {"call_va": "0x5607ba", "name": "Event/qbase.lua"}],
                                           "native_order_source": "PARSER_NATIVE:parser:manager_four_script_loads",
                                           "availability": "Recovered exact original bytes from existing pinned Git evidence; no new raw resource copied into this package",
                                           "runtime_selection_or_success_certified": False, "lua_executed": False},
    }


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--repo", type=Path, default=HERE.parents[2])
    parser.add_argument("--event", type=Path, required=True)
    parser.add_argument("--output-dir", type=Path, required=True)
    args = parser.parse_args()
    destination = args.output_dir.absolute()
    if any(part.is_symlink() for part in (destination, *destination.parents)):
        raise ValueError("Derived-output path must not contain symlinks")
    destination = destination.resolve()
    if destination.is_relative_to(args.event.resolve().parent):
        raise ValueError("Never write derived output inside the original resource directory")
    if destination.is_relative_to(args.repo.resolve()) and not destination.is_relative_to(HERE):
        raise ValueError("Repository outputs are limited to this ABI adoption directory")
    outputs = analyze(args.repo, args.event)
    destination.mkdir(parents=True, exist_ok=True)
    for name, value in outputs.items():
        target = destination / name
        if target.is_symlink() or (target.exists() and (not target.is_file() or target.stat().st_nlink != 1)):
            raise ValueError("Derived output must not overwrite symlink or shared/nonregular file")
        target.write_text(json.dumps(value, ensure_ascii=False, indent=2) + "\n")
    print(json.dumps({"static_analysis_completed": True, "files": list(outputs), "deployment_ready": False,
                      "lua_executed": False}, indent=2))


if __name__ == "__main__":
    main()
