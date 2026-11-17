#!/usr/bin/env python3
"""Read-only integration verification for the P0/P1/P2 continuation package.

Replays new native evidence against supplied original bytes. Existing unchanged
ABI/lifecycle/journey/world results are pinned, not relabeled as new research.
Only --result writes a receipt. No Client, Lua, Server or target DLL is executed.
--require-ready returns 2 when the evidence is valid but readiness is blocked.
"""
import argparse
from concurrent.futures import ThreadPoolExecutor
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
BASE = "15d9501c203c6f656461b64f578a50c96e38a5ff"
EXCLUDED = {"artifact-manifest.json", "verification-result.json"}
PRIOR = HERE.parent / "MEF-P0-P1-master-continuation-20261117"


def require(ok, message):
    if not ok:
        raise ValueError(message)


def sha(data):
    return hashlib.sha256(data).hexdigest()


def load(path):
    return json.loads(Path(path).read_text(encoding="utf-8"))


def artifact_check():
    manifest = load(HERE / "artifact-manifest.json")
    require(set(manifest["excluded"]) == EXCLUDED, "artifact exclusions differ")
    rows = manifest["files"]
    expected = {r["path"] for r in rows}
    require(len(expected) == len(rows), "duplicate manifest paths")
    actual = set()
    for path in HERE.rglob("*"):
        require(not path.is_symlink(), "artifact symlink rejected")
        if path.is_file():
            rel = path.relative_to(HERE).as_posix()
            require(path.suffix in {".py", ".json", ".md", ".asm"}, "unexpected artifact type: " + rel)
            if rel not in EXCLUDED:
                actual.add(rel)
    require(actual == expected, "artifact file set differs")
    size = 0
    for row in rows:
        path = (HERE / row["path"]).resolve()
        require(path.is_relative_to(HERE), "artifact path escapes package")
        data = path.read_bytes()
        require(len(data) == row["bytes"] and sha(data) == row["sha256"], "artifact differs: " + row["path"])
        data.decode("utf-8")
        if path.suffix == ".json":
            load(path)
        size += len(data)
    require(manifest["files_count"] == len(rows) and manifest["bytes"] == size, "artifact totals differ")
    return {"files": len(rows), "bytes": size, "manifest_sha256": sha((HERE / "artifact-manifest.json").read_bytes())}


def source_check(args):
    manifest = load(HERE / "source-manifest.json")
    require(manifest["base_commit"] == BASE and manifest["branch"] == "extra/roy1", "wrong source baseline")
    env = dict(os.environ, GIT_NO_LAZY_FETCH="1", GIT_OPTIONAL_LOCKS="0")
    for pin in manifest["published_pins"]:
        ref = pin["source_commit"] + ":" + pin["path"]
        data = subprocess.check_output(["git", "show", ref], cwd=args.repo, env=env)
        blob = subprocess.check_output(["git", "rev-parse", ref], cwd=args.repo, env=env, text=True).strip()
        require(blob == pin["git_blob"] and len(data) == pin["bytes"] and sha(data) == pin["sha256"],
                "Git source identity differs: " + pin["path"])
        require((args.repo / pin["path"]).read_bytes() == data, "referenced worktree source differs: " + pin["path"])
    for original in manifest["originals"]:
        root = args.supplemental if original["group"] == "supplemental" else args.sources
        data = (root / original["file"]).read_bytes()
        require(len(data) == original["bytes"] and sha(data) == original["sha256"], "original differs: " + original["file"])
    instruction = manifest["shared_instructions"]
    data = (args.sources / instruction["file"]).read_bytes()
    require(sha(data) == instruction["sha256"] and len(data) == instruction["bytes"], "shared instructions differ")
    availability = load(HERE / "source-availability.json")
    require(availability["master_available"] and availability["finite_title_lookup"]["new_carriers_obtained"] == 0,
            "source availability changed without review")
    for row in availability["project_source_files"]:
        require((args.sources / row["file"]).stat().st_size == row["bytes"], "supplied inventory differs")
    return {"published_pins": len(manifest["published_pins"]), "originals": len(manifest["originals"]),
            "shared_instructions": "PASS", "master_available": True, "new_carriers_obtained": 0}


def links_check(repo):
    count = 0
    for path in HERE.rglob("*.md"):
        for target in re.findall(r"\[[^\]]*\]\(([^)\s]+)\)", path.read_text(encoding="utf-8")):
            if target.startswith(("https://", "http://", "mailto:", "#")):
                continue
            resolved = (path.parent / target.split("#", 1)[0]).resolve()
            require(resolved.is_relative_to(repo) and resolved.exists(),
                    "broken/outside Markdown link: " + str(path.relative_to(HERE)) + " -> " + target)
            count += 1
    return count


def claims_check():
    status = load(HERE / "status.json")
    old = load(PRIOR / "status.json")
    p0 = load(HERE / "p0-selection/contracts.json")
    p1 = load(HERE / "p1-entry/candidate-contracts.json")
    p2 = load(HERE / "p2-format/format-capability.json")
    require(status["base_commit"] == BASE and status["branch"] == "extra/roy1", "status baseline differs")
    require(status["planned_work_packages"] == {"P0": 3, "P1": 4, "P2": 1}, "original plan coverage differs")
    items = status["work_packages"]
    require(len(items) == status["work_packages_addressed"] == 8 and len({i["id"] for i in items}) == 8,
            "eight work packages must be individually addressed")
    require({key: sum(i["priority"] == key for i in items) for key in ["P0", "P1", "P2"]} == status["planned_work_packages"],
            "priority counts differ")
    require(all(i["remaining"] and i["evidence"] for i in items), "missing evidence or remaining condition")
    for field in ["all_native_goals_closed", "all_p0_readiness_gates_closed", "resource_ready",
                  "official_mef_grammar_proven", "official_mef_executor_proven", "deployment_ready",
                  "gameplay_verified", "server_changes_implemented"]:
        require(status[field] is False, "unsupported promotion: " + field)
    require(all(value is False for value in status["effects"].values()), "unexpected target/source/status mutation")
    require(p0["status"]["static_policy_questions_closed"], "P0 bounded contract not complete")
    for field in ["actual_cha_abf_winner_observed", "actual_map_fld_winner_observed", "resource_payload_ready", "full_p0_ready"]:
        require(p0["status"][field] is False, "P0 selected-content gate promoted")
    require(p0["status"]["native_selected_paths"] is None, "invented native selected path")
    require(p1["status"]["ordinary_B"] == status["ordinary_entry_B"] == "NOT_CLOSED", "B falsely closed")
    require(p1["selected_resource"]["path"] == "UI/Component/TalkBox_Scenario_Panel.FTC" and
            p1["selected_resource"]["id"] == 212, "P1 concrete source differs")
    require(not p1["status"]["script_owner_cancel_and_reentry_proven"], "UI lifecycle promoted to script lifecycle")
    world = load(PRIOR / "world-lua/contracts.json")
    require(status["ordinary_world_to_same_run_generation_lua"] ==
            world["classification"]["ordinary_world_to_same_run_generation_lua"] == "NOT_CLOSED_NO_PROVEN_ENDPOINT",
            "world-Lua endpoint falsely closed")
    require(p2["p2_overall"] == "BLOCKED" and p2["official_mef"]["verified_payload_count"] == 0 and
            not p2["official_mef"]["native_format_complete"] and not p2["full_program_absence_proved"], "P2 format gate differs")
    for key in ["header", "version", "record_grammar", "parser_address", "executor_address", "first_normal_entry", "server_delivery_opcode"]:
        require(p2["official_mef"][key] is None, "invented official MEF field: " + key)
    require(status["master_source_gate"] == old["master_source_gate"] == "CLOSED_DECLARED_MOUNT_TREE", "Master gate regressed")
    for key in ["dependency_nodes", "remaining_original_frontier_entries", "missing_descriptor_payloads"]:
        require(status["prior_selected_scenes"][key] == old["prior_selected_scenes"][key], "prior frontier changed: " + key)
    q = status["q119_scope"]
    for key in ["body_calls_by_scene", "body_calls_total", "distinct_models", "available_descriptor_models",
                "missing_descriptor_models", "journey_steps", "functional_families", "server_nodes", "portal_pre_register_closed"]:
        require(q[key] == old["new_q119_scope"][key], "Q119 scope differs: " + key)
    require(q["portal_pre_register_closed"] == [False, False, False, True], "portal policies conflated")
    journey_data = load(PRIOR / "journey-families/data-evidence.json")
    require(q["node_policy_authority"] == "SERVER_RECONSTRUCTION_NOT_NATIVE_MEF" and
            all(node["authority"] == q["node_policy_authority"] for node in journey_data["server_journey"]["nodes"]),
            "Server reconstruction promoted to native MEF")
    require(status["server_development"]["can_proceed_without_unknown_B_or_world_lua_bridge"] and
            status["server_development"]["can_proceed_without_official_mef_grammar"] and
            not status["server_development"]["formal_registry_changed"], "Server responsibility boundary differs")
    return {"work_packages_addressed": 8, "P0": 3, "P1": 4, "P2": 1,
            "p0_static_selection_contract": "PROVEN_BOUNDED", "p0_actual_content_ready": False,
            "ordinary_entry_B": "NOT_CLOSED", "world_Lua_endpoint": "NOT_CLOSED",
            "official_MEF": "BLOCKED", "gameplay_verified": False, "server_development_can_proceed": True}


def replay_one(name, command, expected_exit, repo):
    result = subprocess.run(command, cwd=repo, capture_output=True, text=True, timeout=300)
    require(result.returncode == expected_exit,
            name + " unexpected exit " + str(result.returncode) + ": " + result.stderr[-1800:])
    receipt = json.loads(result.stdout)
    require(receipt.get("status", receipt.get("result", "")).startswith("PASS"), name + " did not report evidence PASS")
    return {"id": name, "observed_exit": result.returncode, "expected_exit": expected_exit,
            "stdout_sha256": sha(result.stdout.encode("utf-8")), "result": receipt}


def replay(args):
    common = ["--repo", str(args.repo)]
    jobs = [
        ("p0-selection", [sys.executable, "-B", str(HERE / "p0-selection/verify_evidence.py")]
         + common + ["--binary", str(args.sources / "02-Tartaros.bin")], 0),
        ("p1-entry", [sys.executable, "-B", str(HERE / "p1-entry/verify_evidence.py")]
         + common + ["--sources", str(args.sources)], 0),
        ("p2-format-require-native-mef", [sys.executable, "-B", str(HERE / "p2-format/verify_evidence.py")]
         + common + ["--bin", str(args.sources / "02-Tartaros.bin"), "--master", str(args.sources / "11-Master.stp"),
                     "--require-native-mef"], 2),
    ]
    with ThreadPoolExecutor(max_workers=3) as pool:
        futures = [pool.submit(replay_one, name, command, expected, args.repo) for name, command, expected in jobs]
        results = [future.result() for future in futures]
    p2 = results[2]["result"]
    require(p2["native_mef_gate"] == "BLOCKED" and p2["requested_native_mef_gate"] and
            p2["official_mef_verified_samples"] == 0, "P2 negative readiness gate failed")
    return results


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--repo", type=Path, required=True)
    parser.add_argument("--sources", type=Path, required=True)
    parser.add_argument("--supplemental", type=Path, required=True)
    parser.add_argument("--require-ready", action="store_true")
    parser.add_argument("--result", type=Path)
    args = parser.parse_args()
    require(not sys.flags.optimize, "python -O is not supported")
    args.repo, args.sources, args.supplemental = [p.resolve() for p in [args.repo, args.sources, args.supplemental]]
    require(HERE.is_relative_to(args.repo), "package must be within supplied repo")
    before = artifact_check()
    sources = source_check(args)
    claims = claims_check()
    links = links_check(args.repo)
    results = replay(args)
    require(artifact_check() == before, "artifacts changed during replay")
    exit_code = 2 if args.require_ready else 0
    receipt = {"schema": "MEF_P0_P1_P2_ROOT_VERIFICATION_V1", "status": "PASS_BOUNDED_EVIDENCE_AND_INTEGRATION",
               "verified_at_utc": datetime.now(timezone.utc).isoformat(), "base_commit": BASE, "branch": "extra/roy1",
               "artifacts": before, "sources": sources, "claims": claims, "local_markdown_links_checked": links,
               "replays": results, "readiness_gate": "BLOCKED", "require_ready": args.require_ready,
               "expected_exit": exit_code, "target_execution": {"client": False, "lua": False, "server": False, "DLL": False},
               "complete_original_members_exported": False, "formal_status_changed": False,
               "meaning": "Evidence consistency PASS; actual content, B, world-Lua, official MEF and gameplay gates remain unclosed."}
    if args.result:
        args.result.write_text(json.dumps(receipt, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(receipt, ensure_ascii=False, indent=2))
    return exit_code


if __name__ == "__main__":
    raise SystemExit(main())
