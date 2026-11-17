#!/usr/bin/env python3
"""Verify P0 research artifacts and optionally rerun their offline evidence tools.

PASS means that the preserved research is internally consistent and reproducible.
It never means that missing original files exist, Server adoption is deployed,
or the Client has passed gameplay validation.
"""
from pathlib import Path
import argparse
import ast
import hashlib
import json
import os
import re
import subprocess
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent


def require(condition, message):
    if not condition:
        raise ValueError(message)


def digest(raw):
    return hashlib.sha256(raw).hexdigest()


def read_json(path):
    def pairs(values):
        result = {}
        for key, value in values:
            require(key not in result, "Duplicate JSON key: " + str(path) + ":" + key)
            result[key] = value
        return result

    def invalid(value):
        raise ValueError("Non-finite JSON constant: " + str(path) + ":" + value)

    return json.loads(path.read_text(encoding="utf-8"), object_pairs_hook=pairs, parse_constant=invalid)


def within(path, directory):
    result = path.resolve()
    require(result.is_relative_to(directory.resolve()), "Path escaped allowed directory: " + str(path))
    return result


def git(repo, *args):
    env = dict(os.environ, GIT_NO_LAZY_FETCH="1", GIT_OPTIONAL_LOCKS="0",
               GIT_TERMINAL_PROMPT="0", GIT_NO_REPLACE_OBJECTS="1")
    return subprocess.check_output(["git", "-c", "remote.origin.promisor=false", *args], cwd=repo, env=env)


def artifacts():
    root = read_json(HERE / "artifact-manifest.json")
    expected = {row["path"]: row for row in root["files"]}
    require(len(expected) == len(root["files"]), "Unique artifact paths")
    excluded = set(root["excluded_paths"])
    require(excluded == {"artifact-manifest.json", "verification-result.json"}, "Only two derived root exclusions")
    actual = {str(path.relative_to(HERE)) for path in HERE.rglob("*") if path.is_file()} - excluded
    require(actual == set(expected), "Root artifact inventory differs")
    for name, row in expected.items():
        path = within(HERE / name, HERE)
        require(path.suffix in {".md", ".json", ".py", ".asm"}, "Unexpected deliverable type: " + name)
        raw = path.read_bytes()
        require(len(raw) == row["bytes"] and digest(raw) == row["sha256"], "Artifact identity: " + name)
    return len(expected)


def sources(repo):
    cache, checked, same_batch = {}, set(), set()

    def walk(value, directory, inherited_commit=None):
        if isinstance(value, list):
            for item in value:
                walk(item, directory, inherited_commit)
            return
        if not isinstance(value, dict):
            return
        commit = value.get("commit", value.get("source_commit", value.get("base_commit", inherited_commit)))
        path = value.get("path")
        blob = value.get("git_blob", value.get("blob_sha"))
        raw = None
        if path and blob:
            require(isinstance(commit, str) and re.fullmatch(r"[0-9a-f]{40}", commit), "A Git pin needs an immutable commit")
            key = (commit, path)
            if key not in cache:
                actual_blob = git(repo, "rev-parse", f"{commit}:{path}").decode().strip()
                cache[key] = (actual_blob, git(repo, "cat-file", "blob", actual_blob))
            actual_blob, raw = cache[key]
            require(actual_blob == blob, "Git source blob differs: " + path)
            checked.add(key)
        elif value.get("kind") == "same_batch_file":
            require(isinstance(path, str), "Same-batch source needs a path")
            target = within(directory / path, HERE)
            raw = target.read_bytes()
            same_batch.add(str(target.relative_to(HERE)))
        if raw is not None:
            require(isinstance(value.get("sha256"), str) and
                    re.fullmatch(r"[0-9a-f]{64}", value["sha256"]) and
                    type(value.get("bytes", value.get("size"))) is int,
                    "Source pin needs SHA-256 and byte length: " + str(path))
            require(digest(raw) == value["sha256"] and len(raw) == value.get("bytes", value.get("size")),
                    "Source pin bytes differ: " + str(path))
        for child in value.values():
            if isinstance(child, (list, dict)):
                walk(child, directory, commit)

    for path in sorted(HERE.rglob("source-manifest.json")):
        value = read_json(path)
        walk(value, path.parent, value.get("baseline_head"))
    return len(checked), len(same_batch)


def syntax_and_links(repo, base, creating_own_receipt=False):
    json_count = python_count = 0
    links = set()
    for path in sorted(HERE.rglob("*")):
        if not path.is_file():
            continue
        if path.suffix == ".json":
            read_json(path)
            if path != HERE / "verification-result.json":
                json_count += 1
        elif path.suffix == ".py":
            ast.parse(path.read_text(encoding="utf-8"), filename=str(path))
            python_count += 1
        elif path.suffix == ".md":
            for target in re.findall(r"\]\(([^)]+)\)", path.read_text(encoding="utf-8")):
                if re.match(r"[a-zA-Z][a-zA-Z0-9+.-]*:", target) or target.startswith("#"):
                    continue
                target = target.split("#", 1)[0]
                resolved = within(path.parent / target, repo)
                name = str(resolved.relative_to(repo))
                if not resolved.exists():
                    # The first successful complete invocation creates its own
                    # receipt only after all checks. No other missing target is
                    # exempt, and read-only invocations require it to exist.
                    if not (creating_own_receipt and resolved == HERE / "verification-result.json"):
                        git(repo, "cat-file", "-e", f"{base}:{name}")
                links.add(name)
    return json_count, python_count, len(links)


def status_contract():
    status = read_json(HERE / "p0-status.json")
    rows = status["items"]
    require(len(rows) == 3 and {r["id"] for r in rows} == {"P0-ABI", "P0-RESOURCES", "P0-LIFECYCLE"},
            "Exactly the three P0 packages from the published plan")
    for row in rows:
        require(row["reviewed_in_this_batch"] is True and row["deployment_ready"] is False,
                "P0 research review does not imply deployment")
        require(set(row["remaining_layers"]) == {"client_reverse", "server_development", "integration", "play_validation"},
                "Four separate remaining layers")
        require(row["evidence_files"] and row["acceptance_checks"], "P0 item needs concrete evidence and checks")
        for ref in row["evidence_files"]:
            within(HERE / ref, HERE).read_bytes()
        for check in row["acceptance_checks"]:
            require(check["state"] in {"COMPLETE_BOUNDED", "BLOCKED_MISSING_ORIGINAL_SOURCE", "SERVER_DEVELOPMENT", "INTEGRATION_REQUIRED", "PLAY_VALIDATION_REQUIRED"},
                    "Explicit check state")
            require(check["evidence"] and check["boundary"], "A check needs evidence and boundary")
    require(status["all_release_gates_closed"] is False and status["formal_status_changed"] is False,
            "No readiness or formal-state promotion")
    return {r["id"]: r["analysis_status"] for r in rows}


def source_availability(repo):
    note = read_json(HERE / "source-availability.json")
    lookup = note["pinned_original_source_map_lookup"]
    mapping = json.loads(git(repo, "show", f"{lookup['commit']}:{lookup['path']}"))
    rows = mapping["sources"]
    require(len(rows) == lookup["source_records"], "Original source-map record count")
    require(lookup["regex_flags"] == "IGNORECASE", "Source-map lookup flags")
    hits = [row["original_path"] for row in rows
            if re.search(lookup["original_path_regex"], row["original_path"], re.IGNORECASE)]
    require(hits == lookup["matching_original_paths"], "Recomputed bounded source-map lookup")
    for source in note["recovered_original_lua_from_existing_git"]:
        candidates = [r for r in rows if r.get("version") == "kr" and r["sha256"] == source["sha256"]]
        require(candidates, "Recovered source lacks a KR mapping: " + source["name"])
        for path in {r["portable_path"] for r in candidates}:
            raw = git(repo, "show", f"{lookup['commit']}:{path}")
            require(len(raw) == source["bytes"] and digest(raw) == source["sha256"],
                    "Recovered original Lua identity: " + source["name"])
    return {"mapped_source_records": len(rows), "matching_resource_paths": len(hits),
            "recovered_original_lua_files": len(note["recovered_original_lua_from_existing_git"]),
            "remote_title_searches_repeated_this_invocation": False}


def cross_contracts(repo):
    base_commit = read_json(HERE / "source-manifest.json")["base_commit"]
    original_abi = json.loads(git(repo, "show", base_commit +
        ":kr-extra-roy/MEF-comprehensive-contracts-20261117/abi/abi-contracts.json"))["bindings"]
    adoption = read_json(HERE / "abi-adoption/adoption-catalog.json")
    original = {row["name"]: row for row in original_abi}
    adopted = {row["name"]: row for row in adoption["records"]}
    require(len(original_abi) == len(original) == len(adoption["records"]) == len(adopted) == 121,
            "All 121 bindings are unique in both contracts")
    require(set(original) == set(adopted), "Adoption binding coverage")
    for name, row in original.items():
        other = adopted[name]
        for field in ["native", "marshaller", "argument_count", "argument_kinds", "binding_status", "produces_new_lua_value"]:
            require(row[field] == other[field], "Adoption changed pinned ABI: " + name + "." + field)
        require(other["implementation_or_playability_certified"] is False, "A binding row cannot certify gameplay")
    require(sum(r["adoption_class"] == "DISABLED_STUB" for r in adopted.values()) == 4,
            "Four disabled stubs remain explicit")
    require(adopted["lb.GetObjectCount"]["adoption_class"] == "DISABLED_NOT_A_COUNT",
            "GetObjectCount is not a new numeric producer")
    require(adoption["deployment_ready"] is False, "Adoption review is not deployment")

    abi_scenes = read_json(HERE / "abi-adoption/original-call-review.json")["scenes"]
    resource_data = read_json(HERE / "content-dependencies/scene-dependencies.json")
    resource_scenes = resource_data["scenes"]
    life_scenes = read_json(HERE / "execution-lifecycle/selected-scene-lifecycle.json")["scenes"]
    a = {s["selector_label"]: s for s in abi_scenes}
    r = {s["key"]: s for s in resource_scenes}
    l = {f"Q{s['quest']}/{s['scene']}": s for s in life_scenes}
    expected = {"Q119/3", "Q2440/5"}
    require(len(abi_scenes) == len(resource_scenes) == len(life_scenes) == 2 and set(a) == set(r) == set(l) == expected,
            "Three work packages review the same two unique real selectors")
    full_calls = 0
    for key in sorted(expected):
        require(a[key]["source_member"]["decoded_sha256"] == r[key]["sequence_source"]["decoded_sha256"] ==
                l[key]["member"]["decoded_sha256"], "Exact original SEQ bytes agree: " + key)
        require(a[key]["source_member"]["path"] == r[key]["sequence_source"]["member"] ==
                l[key]["member"]["virtual_path"], "SEQ member paths agree: " + key)
        acalls = [(c["line"], c["name"], c["argument_count"]) for c in a[key]["calls"] if c["name"] != "Register"]
        rcalls = [(c["line"], c["function"], c["arity"]) for c in r[key]["call_inventory"]]
        require(acalls == rcalls and len(rcalls) == r[key]["static_parse"]["function_body_call_count"],
                "Independent parsers agree on every ordered body call and arity: " + key)
        require(r[key]["static_parse"]["unconsumed_tokens"] == 0 and r[key]["static_parse"]["executed"] is False,
                "Complete bounded syntax audit without execution")
        require(sum(c[1] == "CreateObject" for c in rcalls) == l[key]["direct_create_calls"],
                "Lifecycle CreateObject scope agrees: " + key)
        for statement in l[key]["lifecycle_statements"]:
            name = statement["text"].split("(", 1)[0]
            require(any(c[0] == statement["line"] and c[1] == name for c in rcalls),
                    "Lifecycle statement belongs to the same scene: " + key)
        require(r[key]["ready"] is False and r[key]["full_transitive_payload_enumeration_complete"] is False and
                r[key]["exact_runtime_selection_status"] == "BLOCKED_MISSING_ORIGINAL_SOURCE",
                "Missing resource frontiers cannot become ready")
        full_calls += len(rcalls)

    boot = read_json(HERE / "abi-adoption/bootstrap-global-contract.json")
    boot_records = [s for s in boot["sources"] if s["id"] == "BOOT_CHUNK"]
    require(len(boot_records) == 1 and boot_records[0]["assignment_contract"] == {
        "TRUE": {"lua_type": "number", "value": 1}, "FALSE": {"lua_type": "number", "value": 0}},
        "Pinned Boot supplies numeric constants")
    for scene in resource_scenes:
        for slot in scene["slots"]:
            require(slot["baseline_FALSE_value"]["lua_type"] == "number" and
                    slot["baseline_FALSE_value"]["value"] == 0 and
                    slot["baseline_FALSE_value"]["qbase_helper_isVisible_number"] == 1 and
                    slot["baseline_FALSE_value"]["native_integer32_result"] == 1,
                    "Resource interpretation follows Boot number0 through the helper's numeric comparison and native integer32")
    owners = read_json(HERE / "execution-lifecycle/owner-ledger.json")["owners"]
    require(len(owners) == len({row["id"] for row in owners}) == 22, "22 distinct owner records")
    profiles = read_json(HERE / "execution-lifecycle/run-contracts.json")
    require(len(profiles["profiles"]) == 3 and {p["id"] for p in profiles["profiles"]} ==
            {"finite_native_effect", "same_run_multiphase", "independent_runs"}, "Three explicit run strategies")
    require(profiles["all_profiles_deployment_ready"] is False and profiles["global_queue_drain_proved"] is False,
            "A strategy contract does not manufacture deployment or a drain ACK")
    return {"normal_bindings": len(adopted), "original_scene_count": len(expected),
            "ordered_body_calls_cross_checked": full_calls, "owner_records": len(owners),
            "run_strategies": len(profiles["profiles"]), "resource_dependency_nodes": len(resource_data["dependency_nodes"])}


def validate_runs(document):
    require(document["schema"] == "MEF_P0_EVIDENCE_RUNS_V1", "Evidence run schema")
    expected = {
        "abi": {
            "cwd": "abi-adoption", "receipt": "abi-adoption/verification-result.json",
            "argv": ["{python}", "-B", "verify_evidence.py", "--repo", "{repo}", "--sources", "{sources}"],
            "required_fields": {"status": "PASS_REPRODUCIBLE_BOUNDED_RESEARCH", "deployment_ready": False,
                                "client_executed": False, "lua_executed": False, "server_executed": False,
                                "formal_status_changed": False},
        },
        "resources": {
            "cwd": "content-dependencies", "receipt": "content-dependencies/verification-result.json",
            "argv": ["{python}", "-B", "verify_evidence.py", "--repo", "{repo}", "--sources", "{sources}",
                     "--supplemental", "{supplemental}"],
            "required_fields": {"status": "PASS_REPRODUCIBLE_BOUNDED_ANALYSIS", "ready": False,
                                "full_transitive_payload_enumeration_complete": False,
                                "exact_runtime_selection": "BLOCKED_MISSING_ORIGINAL_SOURCE",
                                "target_lua_client_server_execution": False, "formal_T01_RR_S00_status_changed": False},
        },
        "lifecycle": {
            "cwd": "execution-lifecycle", "receipt": "execution-lifecycle/verification-result.json",
            "argv": ["{python}", "-B", "verify_evidence.py", "--repo", "{repo}",
                     "--bin", "{sources}/02-Tartaros.bin", "--event", "{sources}/06-Event.stp"],
            "required_fields": {"all_matched": True, "deployment_ready": False,
                                "selected_original_image_zero_fadeout_branch_closed": True,
                                "client_executed": False, "lua_executed": False, "server_executed": False,
                                "formal_status_changed": False},
        },
        "integration": {
            "cwd": "integration", "receipt": "integration/verification-result.json",
            "argv": ["{python}", "-B", "verify_context.py", "--repo", "{repo}"],
            "required_fields": {"status": "PASS", "deployment_ready": False,
                                "client_executed": False, "lua_executed": False, "server_executed": False,
                                "formal_status_changed": False},
        },
    }
    rows = document["runs"]
    require(isinstance(rows, list) and len(rows) == 4, "Exactly four evidence verifiers are required")
    require({row["name"] for row in rows} == set(expected), "All four unique evidence run names are required")
    for row in rows:
        want = dict(expected[row["name"]], name=row["name"], stdout_format="json")
        require(row == want, "Fixed command, receipt, success criteria and boundaries: " + row["name"])
    return rows


def receipts(runs):
    saved = []
    for run in runs:
        require(run["stdout_format"] == "json", "Evidence receipts use machine-readable JSON")
        target = within(HERE / run["receipt"], HERE)
        result = read_json(target)
        for key, value in run["required_fields"].items():
            require(result.get(key) == value, "Evidence receipt mismatch: " + run["name"] + "." + key)
        saved.append({"name": run["name"], "receipt": run["receipt"], "sha256": digest(target.read_bytes())})
    return saved


def rerun(args, runs):
    require(args.sources is not None and args.supplemental is not None, "--run-evidence requires both source directories")
    substitutions = {"python": sys.executable, "repo": str(args.repo),
                     "sources": str(args.sources.resolve()), "supplemental": str(args.supplemental.resolve())}
    env = dict(os.environ, PYTHONDONTWRITEBYTECODE="1")
    executed = []
    allowed = {"verify_evidence.py", "verify_context.py"}
    for run in runs:
        cwd = within(HERE / run["cwd"], HERE)
        argv = [part.format(**substitutions) for part in run["argv"]]
        require(argv[:2] == [sys.executable, "-B"] and argv[2] in allowed,
                "Only the declared offline evidence verifiers may be run")
        expected = read_json(HERE / run["receipt"])
        result = subprocess.run(argv, cwd=cwd, env=env, capture_output=True, text=True, timeout=300, check=False)
        require(result.returncode == 0, "Evidence verifier failed: " + run["name"] + "\n" +
                (result.stderr or result.stdout)[-6000:])
        actual = json.loads(result.stdout)
        require(actual == expected, "Recomputed receipt differs: " + run["name"])
        executed.append(run["name"])
    return executed


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--repo", type=Path, required=True)
    parser.add_argument("--sources", type=Path)
    parser.add_argument("--supplemental", type=Path)
    parser.add_argument("--run-evidence", action="store_true")
    parser.add_argument("--result", type=Path)
    args = parser.parse_args()
    args.repo = args.repo.resolve()
    within(HERE, args.repo)
    if args.result:
        args.result = args.result.resolve()
        require(args.result.suffix == ".json", "Result must be JSON")
        require(not args.result.is_relative_to(HERE) or args.result == HERE / "verification-result.json",
                "Result cannot overwrite package evidence")
        require(not args.result.is_relative_to(args.repo) or args.result == HERE / "verification-result.json",
                "Result cannot overwrite repository source files")
        for directory in [args.sources, args.supplemental]:
            if directory:
                require(not args.result.is_relative_to(directory.resolve()), "Result cannot overwrite a source directory")
    manifest = read_json(HERE / "source-manifest.json")
    count = artifacts()
    pins, same = sources(args.repo)
    json_count, python_count, links = syntax_and_links(
        args.repo, manifest["base_commit"], args.result == HERE / "verification-result.json")
    statuses = status_contract()
    availability = source_availability(args.repo)
    cross = cross_contracts(args.repo)
    runs = validate_runs(read_json(HERE / "evidence-runs.json"))
    saved = receipts(runs)
    executed = rerun(args, runs) if args.run_evidence else []
    if args.run_evidence:
        require(len(executed) == 4 and set(executed) == {r["name"] for r in runs},
                "All four declared evidence tools must have actually run")
        raw = (args.sources / "09-02-PROJECT-SHARED-INSTRUCTIONS.md").read_bytes()
        pin = manifest["shared_instructions"]
        require(len(raw) == pin["bytes"] and digest(raw) == pin["sha256"], "Shared instructions identity")
        artifacts()
    result = {
        "schema": "MEF_P0_PACKAGE_VERIFICATION_V1", "status": "PASS",
        "scope": "Research artifact identity, pinned sources, explicit P0 states, saved evidence receipts and optional offline reexecution",
        "base_commit": manifest["base_commit"], "artifact_files_hashed": count,
        "distinct_pinned_git_sources": pins, "same_batch_source_files": same,
        "json_files_parsed_excluding_own_receipt": json_count, "python_files_syntax_checked": python_count,
        "document_targets_checked": links, "p0_analysis_statuses": statuses,
        "source_availability_checks": availability,
        "cross_contracts": cross,
        "saved_receipts": saved, "evidence_rerun_this_invocation": bool(args.run_evidence),
        "executed_evidence_runs": executed,
        "client_executed": False, "lua_executed": False, "server_executed": False,
        "deployment_ready": False, "all_release_gates_closed": False,
        "official_mef_grammar_proved": False, "gameplay_verified": False,
        "formal_status_changed": False,
    }
    raw = json.dumps(result, ensure_ascii=False, indent=2, allow_nan=False) + "\n"
    if args.result:
        args.result.write_text(raw, encoding="utf-8")
    print(raw, end="")


if __name__ == "__main__":
    main()
