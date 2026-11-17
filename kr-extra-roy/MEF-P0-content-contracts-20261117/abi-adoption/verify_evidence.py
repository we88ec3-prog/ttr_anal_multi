#!/usr/bin/env python3
"""Reproduce P0 ABI adoption research without Client/Lua/Server execution."""
from __future__ import annotations

import argparse
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import shutil
import struct
import subprocess
import sys
import tempfile

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent


def require(condition, label):
    if not condition:
        raise ValueError(label)


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def load_module(path, name):
    spec = importlib.util.spec_from_file_location(name, path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def json_at(path):
    return json.loads(path.read_text(encoding="utf-8"))


def checked_result_destination(path, repo, sources):
    absolute = path.absolute()
    require(not any(part.is_symlink() for part in (absolute, *absolute.parents)), "result path must not contain symlinks")
    resolved = absolute.resolve()
    require(not resolved.is_relative_to(sources.resolve()), "result must not be written inside original source directory")
    if resolved.is_relative_to(repo.resolve()):
        require(resolved == HERE / "verification-result.json", "only the fixed ABI verification receipt may be written inside repository")
    if resolved.exists():
        require(resolved.is_file() and resolved.stat().st_nlink == 1, "result must be a regular unshared file")
    return resolved


def run_fixtures(preflight, original, repo):
    fixtures = json_at(HERE / "fixtures.json")
    outcomes = []
    for case in fixtures["cases"]:
        result = preflight.validate(case["plan"], repo)
        codes = [row["code"] for row in result["errors"]]
        effects = [row["effect"] for row in result["declared_native_effects"]]
        require(result["status"] == case["expected_status"], "fixture status " + case["name"])
        require(set(case["required_error_codes"]) <= set(codes), "fixture rejection " + case["name"])
        require(not case["required_effects"] or effects == case["required_effects"], "fixture effect " + case["name"])
        require(not any(result[key] for key in ("deployment_ready", "gameplay_verified", "client_executed", "lua_executed", "server_executed")), "no promotion")
        outcomes.append({"name": case["name"], "status": result["status"], "error_codes": codes,
                         "warning_codes": [row["code"] for row in result["warnings"]], "effects": effects})
    for case in fixtures["json_rejections"]:
        try:
            preflight.strict_loads(case["text"])
        except ValueError:
            pass
        else:
            raise ValueError("JSON parser accepted " + case["name"])
    json_shape_cases = []
    for label, argument_text in (("overflowed_json_exponent", "1e309"), ("unknown_numeric_argument_shape", '{"value":1}')):
        plan = json.loads(json.dumps(fixtures["cases"][0]["plan"]))
        plan["calls"][0]["args"][0] = "REPLACE_ARG"
        raw = json.dumps(plan).replace('"REPLACE_ARG"', argument_text)
        result = preflight.validate(preflight.strict_loads(raw), repo)
        require(result["status"] == "REJECTED" and "NUMERIC_ABI" in {row["code"] for row in result["errors"]}, "JSON numeric shape fail closed")
        json_shape_cases.append({"name": label, "status": result["status"]})

    # Meaningful source-identity rejection: mutate an analysis copy, never the
    # original definitions or a Client asset. The validator must refuse it.
    manifest = json_at(HERE / "source-manifest.json")
    with tempfile.TemporaryDirectory(prefix="mef-p0-abi-pin-") as temporary:
        destination = Path(temporary)
        for pin in manifest["repository_sources"]:
            if pin.get("runtime_input"):
                target = destination / pin["path"]
                target.parent.mkdir(parents=True, exist_ok=True)
                shutil.copyfile(repo / pin["path"], target)
                if pin["id"] == "ABI":
                    target.write_bytes(target.read_bytes() + b" ")
        try:
            preflight.validate(fixtures["cases"][0]["plan"], destination)
        except ValueError as error:
            require("pinned definition differs" in str(error), "source-mismatch reason")
        else:
            raise ValueError("changed source was accepted")

    # Synthetic instruction metadata, not compiled/executed Lua. These cases
    # guard the reaching-definition joins and multi-register kills that could
    # otherwise turn an ambiguous call into a false positive native edge.
    def abc(op, a=0, b=0, c=0):
        return original.OPS.index(op) | a << 6 | c << 14 | b << 23
    def abx(op, a, bx):
        return original.OPS.index(op) | a << 6 | bx << 14
    def jump(pc, target, op="JMP", a=0):
        return abx(op, a, target - pc - 1 + 131071)
    def check_flow(name, words, constants, call_pc, expected):
        proto = {"index": 1, "params": 0, "stack": 8, "code_offset": 0,
                 "words": words, "constants": constants, "children": []}
        result = original.audit_proto(proto, {"name": name}, {})
        call = next(row for row in result["calls"] if row["pc"] == call_pc)
        require(call["callee"] == expected, "SYN static dataflow " + name)
        return {"name": name, "callee": call["callee"]}
    static_cases = []
    static_cases.append(check_flow("different_names_merge_to_unknown", [
        abx("GETGLOBAL", 0, 0), abc("EQ", 0, 0, 256), jump(2, 5),
        abx("GETGLOBAL", 0, 1), jump(4, 5), abc("GETTABLE", 0, 0, 258),
        abc("CALL", 0, 1, 1), abc("RETURN", 0, 1)], ["Q", "Tutorial", "EndSepia"], 6, None))
    static_cases.append(check_flow("same_name_all_predecessors_resolves", [
        abx("GETGLOBAL", 0, 0), abc("EQ", 0, 0, 256), jump(2, 5),
        abx("GETGLOBAL", 0, 0), jump(4, 5), abc("GETTABLE", 0, 0, 257),
        abc("CALL", 0, 1, 1), abc("RETURN", 0, 1)], ["Q", "EndSepia"], 6, "Q.EndSepia"))
    static_cases.append(check_flow("one_predecessor_kills_name_to_unknown", [
        abx("GETGLOBAL", 0, 0), abc("EQ", 0, 0, 256), jump(2, 5),
        abc("LOADNIL", 0, 0), jump(4, 5), abc("GETTABLE", 0, 0, 257),
        abc("CALL", 0, 1, 1), abc("RETURN", 0, 1)], ["Q", "EndSepia"], 6, None))
    static_cases.append(check_flow("self_overwrites_receiver_slot", [
        abx("GETGLOBAL", 1, 0), abc("GETTABLE", 1, 1, 257), abx("GETGLOBAL", 0, 2),
        abc("SELF", 0, 0, 259), abc("CALL", 1, 1, 1), abc("RETURN", 0, 1)],
        ["Q", "EndSepia", "coroutine", "yield"], 4, "coroutine"))
    static_cases.append(check_flow("vararg_kills_every_result_slot", [
        abx("GETGLOBAL", 1, 0), abc("GETTABLE", 1, 1, 257), abc("VARARG", 0, 3),
        abc("CALL", 1, 1, 1), abc("RETURN", 0, 1)], ["Q", "EndSepia"], 3, None))
    static_cases.append(check_flow("numeric_for_kills_external_index_register", [
        abx("GETGLOBAL", 3, 0), abc("GETTABLE", 3, 3, 257), jump(2, 2, "FORLOOP", 0),
        abc("CALL", 3, 1, 1), abc("RETURN", 0, 1)], ["Q", "EndSepia"], 3, None))
    static_cases.append(check_flow("generic_for_kills_iterator_results", [
        abx("GETGLOBAL", 3, 0), abc("GETTABLE", 3, 3, 257), abc("TFORLOOP", 0, 0, 1),
        abc("CALL", 3, 1, 1), abc("RETURN", 0, 1)], ["Q", "EndSepia"], 3, None))
    for opcode, word in (("nested_closure", abx("CLOSURE", 0, 0)), ("setlist_extension", abc("SETLIST", 0, 1, 0))):
        try:
            original.audit_proto({"index": 1, "params": 0, "stack": 2, "code_offset": 0,
                                  "words": [word, abc("RETURN", 0, 1)], "constants": [], "children": []}, {"name": opcode}, {})
        except ValueError:
            static_cases.append({"name": opcode, "status": "REJECTED_UNSUPPORTED_CFG_CONSTRUCT"})
        else:
            raise ValueError("unknown CFG construct accepted")
    lexer = original.load_sources(repo)["LEXER"]
    lexical = original.text_calls("Register(function() Q.EndCutScene() end)", lexer)
    require([row["name"] for row in lexical] == ["Register", "Q.EndCutScene"], "anonymous function keyword not a call")
    return {"status": "PASS", "scope": "Synthetic authoring-policy/dataflow checks only; no target execution",
            "authoring_cases": len(outcomes), "json_rejection_cases": len(fixtures["json_rejections"]),
            "source_mutation_rejections": 1, "static_dataflow_cases": static_cases,
            "json_numeric_shape_cases": json_shape_cases,
            "anonymous_function_lexical_case": "PASS", "outcomes": outcomes}


def verify_zeroarg_and_bridges(pe, outputs, by_name):
    evidence = json_at(HERE / "native-evidence.json")
    require(evidence["source_bin_sha256"] == sha(pe.b), "supplemental BIN identity")
    for row in evidence["windows"]:
        require(pe.function(int(row["va"], 16)) == row, "supplemental original native function " + row["id"])
    require({row["va"] for row in evidence["windows"]} ==
            {"0x565600", "0x6fdcb0", "0x6fdd90", "0x6fdc30", "0x6fdd10", "0x700880", "0x6f74b0", "0x6f7170", "0x897a66"}, "exact supplemental scope")
    asm = ["; Original KR BIN bounded supplemental evidence. Never executed.", "; SHA256 " + sha(pe.b), ""]
    for row in evidence["windows"]:
        asm.append("; " + row["id"] + " VA " + row["va"] + " RAW " + row["raw"] + " SHA256 " + row["sha256"])
        asm.extend(i["va"] + "  " + i["hex"].ljust(32) + "  " + i["asm"] for i in row["instructions"])
        asm.append("")
    require((HERE / "native-evidence.asm").read_text() == "\n".join(asm) + "\n", "supplemental ASM reproduction")
    imported = evidence["allocator_import"]
    descriptor = pe.at(int(imported["descriptor_va"], 16), 20)
    require(descriptor.hex() == imported["descriptor_hex"], "heap import descriptor")
    ilt, _, _, name_rva, iat = struct.unpack("<IIIII", descriptor)
    require(pe.at(pe.base + name_rva, 13) == b"KERNEL32.dll\0", "heap import module")
    import_index = (int(imported["iat_va"], 16) - pe.base - iat) // 4
    lookup = pe.base + ilt + 4 * import_index
    require(lookup == int(imported["lookup_thunk_va"], 16), "heap import matching lookup slot")
    thunk = pe.at(lookup, 4)
    require(thunk.hex() == imported["lookup_thunk_hex"], "heap import lookup value")
    name_address = pe.base + int.from_bytes(thunk, "little")
    require(name_address == int(imported["import_by_name_va"], 16), "heap import name address")
    require(pe.at(name_address + 2, 12) == b"HeapReAlloc\0", "exact heap import name")
    require(pe.at(int(imported["iat_va"], 16), 4).hex() == imported["iat_disk_hex"], "heap import IAT disk contents")
    contract = json_at(HERE / "zeroarg-endsepia-contract.json")
    excerpt = outputs["helper-bridge-evidence.json"]["arity_mismatch_excerpt"]
    require(contract["original_call"] == excerpt, "exact original compatibility call")
    require([(r["pc"], r["op"], r["A"], r["B"], r["C"]) for r in excerpt["selected_instructions"]][-1] == (38, "CALL", 0, 1, 1), "zero user args original CALL")
    for key in ("registrar", "closure", "marshaller", "native"):
        require(contract["binding"][key] == by_name["Q.EndSepia"][key], "zeroarg exact ABI binding")
    require(contract["derived_native_argument"] == {"kind": "integer32", "value": 0, "source_lua_value_kind": "function", "source_is_explicit_nil": False}, "bounded compatibility conclusion")
    # Exact decision bytes reused from the pinned original windows above.
    for address, expected in ((0x6FD036, "894708"), (0x6FE1C6, "83780806"),
                              (0x6F510F, "c1e004"), (0x6F5112, "034108"),
                              (0x56A44A, "83f903"), (0x56A44F, "83f904"),
                              (0x56A494, "33c0"), (0x56A496, "50")):
        require(pe.at(address, len(expected) // 2).hex() == expected, "zeroarg proof decision " + hex(address))
    require(not contract["deployment_ready"] and not contract["lua_executed"], "compatibility boundary")
    helper_rules = json_at(HERE / "helper-adoption-rules.json")
    create = next(row for row in helper_rules["rules"] if row["id"] == "HELPER-CREATE")
    selected = {row["index"]: row for row in outputs["helper-bridge-evidence.json"]["selected_prototypes"]}
    require(selected[62]["words"][3:10] == [0x3400057, 0x80008016, 0x241, 0x8247, 0x80004016, 0x4241, 0x8247], "Create original typed EQ and 0/1 writer")
    require(by_name["Q.CreateObject"]["argument_kinds"][6] == create["native_argument_7_kind"] == "integer32", "Create seventh ABI type")
    for case in create["counterexamples"]:
        typed = case["input"]
        equals_zero = typed["lua_type"] == "number" and typed["value"] == 0
        require(equals_zero == case["equals_number_zero"] and int(equals_zero) == case["native_argument_7"], "typed Create counterexample")
    require(len(create["counterexamples"]) == 4, "typed Create counterexample coverage")
    return {"new_native_windows": len(evidence["windows"]), "new_native_bytes": sum(row["size"] for row in evidence["windows"]),
            "allocator_import": "KERNEL32.HeapReAlloc", "zeroarg_original_native_integer": 0,
            "zeroarg_generalized_to_missing_nil": False, "helper_create_typed_counterexamples": 4}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--repo", type=Path, default=HERE.parents[2])
    parser.add_argument("--sources", required=True, type=Path)
    parser.add_argument("--result", type=Path)
    args = parser.parse_args()
    require(not sys.flags.optimize, "Run without -O")
    result_path = checked_result_destination(args.result, args.repo, args.sources) if args.result else None
    manifest = json_at(HERE / "source-manifest.json")
    cache = {}
    env = dict(os.environ, GIT_NO_LAZY_FETCH="1", GIT_OPTIONAL_LOCKS="0", GIT_TERMINAL_PROMPT="0", GIT_NO_REPLACE_OBJECTS="1")
    for row in manifest["repository_sources"]:
        blob = subprocess.check_output(["git", "-c", "remote.origin.promisor=false", "rev-parse", manifest["source_commit"] + ":" + row["path"]], cwd=args.repo, env=env, text=True).strip()
        require(blob == row["git_blob"], "source tree pin " + row["id"])
        raw = subprocess.check_output(["git", "-c", "remote.origin.promisor=false", "cat-file", "blob", blob], cwd=args.repo, env=env)
        require(len(raw) == row["bytes"] and sha(raw) == row["sha256"], "source byte pin " + row["id"])
        require(hashlib.sha1(b"blob " + str(len(raw)).encode() + b"\0" + raw).hexdigest() == blob, "Git blob content identity")
        cache[row["id"]] = raw
        local = args.repo / row["path"]
        if local.exists():
            require(local.read_bytes() == raw, "local source agrees with pinned Git source " + row["id"])
    for row in manifest["originals"]:
        raw = (args.sources / row["file"]).read_bytes()
        require(len(raw) == row["bytes"] and sha(raw) == row["sha256"], "original " + row["file"])
    for source_id in ("ABI_SUPPORT", "ABI_VERIFY"):
        row = next(item for item in manifest["repository_sources"] if item["id"] == source_id)
        require((args.repo / row["path"]).read_bytes() == cache[source_id], "executed offline verifier source " + source_id)
    abi_directory = args.repo / next(row["path"] for row in manifest["repository_sources"] if row["id"] == "ABI_VERIFY")
    sys.path.insert(0, str(abi_directory.parent))
    native_support = load_module(abi_directory.with_name("native_support.py"), "p0_abi_pe")
    old_verifier = load_module(abi_directory, "p0_pinned_abi_verifier")
    abi_result = old_verifier.run(args.sources / "02-Tartaros.bin")
    require(abi_result["status"] == "PASS", "published ABI evidence rerun")
    pe = native_support.PE(args.sources / "02-Tartaros.bin")
    extra_windows = []
    for source_id, selected in (("EVENTS_NATIVE", None), ("REUSE_NATIVE", {"q_flying_create", "q_flying_cancel"}),
                                ("REUSE_FOLLOWUP_NATIVE", None),
                                ("AV_NATIVE", {"M24", "M25"}),
                                ("PARSER_NATIVE", {"parser:manager_four_script_loads", "parser:core_script_names", "parser:qbase_script_name"}),
                                ("SUPERVISOR_NATIVE", {"vm_call", "precall"})):
        evidence = json.loads(cache[source_id])
        rows = evidence.get("windows", evidence.get("records", []))
        for row in rows:
            identity = row.get("id", row.get("tag"))
            if selected is not None and identity not in selected:
                continue
            length = row.get("length", row.get("size", row.get("bytes")))
            address = row.get("va", row.get("start"))
            raw = pe.at(int(address, 16), length)
            require(raw.hex() == row["hex"] and sha(raw) == row["sha256"], "supporting original window " + identity)
            require(pe.raw(int(address, 16), length) == int(row.get("raw", row.get("raw_offset")), 16), "supporting PE raw mapping")
            extra_windows.append({"source": source_id, "record": identity, "va": address, "bytes": length, "sha256": row["sha256"]})
        if selected is not None:
            require(selected <= {row["record"] for row in extra_windows if row["source"] == source_id}, "all requested support windows present")
    # Check the precise original load instructions and literal script names.
    for site, name_va, name in ((0x560796, 0xC055C8, b"Coroutine.lua"), (0x5607A2, 0xC055B0, b"Boot.lua"),
                                (0x5607AE, 0xC055BC, b"Logic.lua"), (0x5607BA, 0xC10658, b"Event/qbase.lua")):
        call = pe.at(site, 5)
        require(call[0] == 0xE8 and site + 5 + int.from_bytes(call[1:], "little", signed=True) == 0x6F4A50, "bootstrap loader call")
        require(pe.at(name_va, len(name) + 1) == name + b"\0", "bootstrap exact name")

    catalog = json_at(HERE / "adoption-catalog.json")
    abi = json.loads(cache["ABI"])
    observations = {row["name"]: row for row in json.loads(cache["OBSERVATIONS"])["records"]}
    functions = {row["name"]: row for row in json.loads(cache["FUNCTIONS"])["records"]}
    rows = catalog["records"]
    require(len(rows) == len({row["name"] for row in rows}) == 121, "one record for every normal name")
    require({row["name"] for row in rows} == {row["name"] for row in abi["bindings"]}, "catalog name equality")
    by_name = {row["name"]: row for row in rows}
    for definition in abi["bindings"]:
        record = by_name[definition["name"]]
        for key in ("native", "registrar", "closure", "marshaller", "argument_count", "argument_kinds", "relative_stack_indices", "binding_status", "produces_new_lua_value", "lua_value_kind", "evidence_records"):
            require(record[key] == definition[key], "catalog ABI " + definition["name"] + ":" + key)
        functional = functions[definition["name"]]
        require(record["domain"] == functional["domain"] and record["capability"] == functional["capability"] and record["constraints"] == functional["constraints"], "catalog functional contract")
        if definition["name"] in observations:
            require(record["observation"] == {key: observations[definition["name"]][key] for key in record["observation"]}, "catalog observation source")
        require(not record["implementation_or_playability_certified"], "catalog scope")
    require(catalog["counts"] == {"bindings": 121, "domains": 15, "new_numeric_producers": 17, "observations": 16, "stubs": 4, "no_new_value": 104}, "coverage partitions")
    require(not catalog["deployment_ready"], "catalog not deployment")
    adoption = json_at(HERE / "errata-adoption.json")
    entries = json.loads(cache["REUSE_ERRATA"])["entries"]
    require([row["published_entry"] for row in adoption["records"]] == entries, "all published errata adopted in order")
    require(all(row["adoption_status"] == "ADOPTED_WITH_ORIGINAL_BOUNDARIES" for row in adoption["records"]), "errata boundary status")
    followup = json.loads(cache["REUSE_FOLLOWUP_ERRATA"])["entries"]
    require(all(row in entries for row in followup), "followup errata subset reconciled")

    original = load_module(HERE / "analyze_original.py", "p0_original_analysis")
    outputs = original.analyze(args.repo, args.sources / "06-Event.stp")
    for name, value in outputs.items():
        require(value == json_at(HERE / name), "regenerated original evidence " + name)
    helper_audit = outputs["helper-call-audit.json"]
    require(len(helper_audit["helpers"]) == 75 and helper_audit["normal_native_call_sites"] == 76, "complete selected helper audit")
    require([(row["helper"], row["pc"], row["callee"], row["argument_count"], row["expected_native_argument_count"]) for row in helper_audit["native_arity_mismatches"]] == [("RevPhase1", 38, "Q.EndSepia", 0, 1)], "original arity mismatch preserved")
    bounded_native_result = verify_zeroarg_and_bridges(pe, outputs, by_name)
    preflight = load_module(HERE / "preflight.py", "p0_preflight")
    fixture_result = run_fixtures(preflight, original, args.repo)
    require(fixture_result == json_at(HERE / "fixture-results.json"), "fixture receipt reproducibility")
    artifact_manifest = json_at(HERE / "artifact-manifest.json")
    for row in artifact_manifest["files"]:
        raw = (HERE / row["name"]).read_bytes()
        require(len(raw) == row["bytes"] and sha(raw) == row["sha256"], "artifact integrity " + row["name"])
    result = {"schema": "ttr-mef-p0-abi-verification-v1", "status": "PASS_REPRODUCIBLE_BOUNDED_RESEARCH",
              "source_commit": manifest["source_commit"], "source_pins_checked": len(manifest["repository_sources"]),
              "original_files_checked": len(manifest["originals"]), "published_abi_verifier_rerun": abi_result,
              "published_errata_adopted": len(adoption["records"]),
              "supporting_native_byte_windows_rechecked": len(extra_windows),
              "supporting_native_bytes_rechecked": sum(row["bytes"] for row in extra_windows),
              "supporting_windows_scope": "Exact original bytes and PE mapping reuse; not a new whole-function/full-program certification",
              "bootstrap_original_chunks": 3, "bootstrap_prototypes": 15, "bootstrap_instruction_words": 199,
              "bootstrap_numeric_assignments": {"TRUE": 1, "FALSE": 0},
              "original_data_outputs_regenerated": list(outputs), "original_qbase_helpers": 75,
              "original_qbase_normal_native_call_sites": 76, "original_qbase_native_arity_mismatches": 1,
              "original_scene_call_counts": {row["selector_label"]: len(row["calls"]) for row in outputs["original-call-review.json"]["scenes"]},
              "authoring_fixture_cases": fixture_result["authoring_cases"], "json_rejection_cases": fixture_result["json_rejection_cases"],
              "source_mutation_rejections": 1, "static_dataflow_cases": len(fixture_result["static_dataflow_cases"]),
              "json_numeric_shape_cases": len(fixture_result["json_numeric_shape_cases"]),
              "bounded_native_compatibility": bounded_native_result,
              "anonymous_function_lexical_cases": 1, "artifact_integrity_files": len(artifact_manifest["files"]),
              "client_executed": False, "lua_executed": False, "server_executed": False,
              "deployment_ready": False, "gameplay_verified": False, "official_mef_grammar_proved": False,
              "formal_status_changed": False}
    if result_path:
        result_path.parent.mkdir(parents=True, exist_ok=True)
        result_path.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n")
    print(json.dumps(result, ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
