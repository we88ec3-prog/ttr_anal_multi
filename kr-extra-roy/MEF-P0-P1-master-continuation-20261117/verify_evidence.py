#!/usr/bin/env python3
"""Read-only integration replay for the Master/P0/P1 research package.

Checks the sealed artifact set and original/source identities, then actually
executes four bounded evidence verifiers and the negative readiness gate.
Only --result writes a receipt; target Client/Lua/Server/DLLs are never run.
"""
import argparse
from concurrent.futures import ThreadPoolExecutor
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import re
import subprocess
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
BASE = "5ed4833b805949fabe260aea77e3fe0fd8e86bfa"
EXCLUDED = {"artifact-manifest.json", "verification-result.json"}


def require(ok, message):
    if not ok:
        raise ValueError(message)


def sha(b):
    return hashlib.sha256(b).hexdigest()


def load(path):
    return json.loads(Path(path).read_text(encoding="utf-8"))


def artifact_check():
    manifest = load(HERE/"artifact-manifest.json")
    require(set(manifest["excluded"]) == EXCLUDED, "unexpected artifact exclusions")
    rows = manifest["files"]
    expected = {r["path"] for r in rows}
    require(len(rows) == len(expected), "duplicate artifact names")
    actual = set()
    for path in HERE.rglob("*"):
        require(not path.is_symlink(), "artifact symlink rejected")
        if path.is_file():
            rel = path.relative_to(HERE).as_posix()
            require(path.suffix in {".py", ".json", ".md", ".asm"}, "unexpected deliverable type: "+rel)
            if rel not in EXCLUDED:
                actual.add(rel)
    require(actual == expected, "artifact file set differs from manifest")
    total = 0
    for r in rows:
        path = HERE/r["path"]
        require(path.resolve().is_relative_to(HERE), "artifact path escapes package")
        b = path.read_bytes()
        require(len(b) == r["bytes"] and sha(b) == r["sha256"], "artifact differs: "+r["path"])
        b.decode("utf-8")
        if path.suffix == ".json":
            load(path)
        total += len(b)
    require(manifest["files_count"] == len(rows) and manifest["bytes"] == total, "manifest totals differ")
    return {"files": len(rows), "bytes": total, "manifest_sha256": sha((HERE/"artifact-manifest.json").read_bytes())}


def source_check(args):
    manifest = load(HERE/"source-manifest.json")
    require(manifest["base_commit"] == BASE and manifest["branch"] == "extra/roy1", "analysis baseline/branch")
    for pin in manifest["published_pins"]:
        ref = pin["source_commit"]+":"+pin["path"]
        b = subprocess.check_output(["git", "show", ref], cwd=args.repo)
        blob = subprocess.check_output(["git", "rev-parse", ref], cwd=args.repo, text=True).strip()
        require(blob == pin["git_blob"] and sha(b) == pin["sha256"] and len(b) == pin["bytes"],
                "root Git pin differs: "+pin["path"])
        require((args.repo/pin["path"]).read_bytes() == b, "root referenced working source differs: "+pin["path"])
    for original in manifest["originals"]:
        root = args.supplemental if original["group"] == "supplemental" else args.sources
        b = (root/original["file"]).read_bytes()
        require(sha(b) == original["sha256"] and len(b) == original["bytes"], "original differs: "+original["file"])
    instruction = manifest["shared_instructions"]
    b = (args.sources/instruction["file"]).read_bytes()
    require(sha(b) == instruction["sha256"] and len(b) == instruction["bytes"], "shared instructions differ")
    return {"root_git_pins": len(manifest["published_pins"]), "original_carriers": len(manifest["originals"]),
            "shared_instructions": "PASS", "source_manifest_sha256": sha((HERE/"source-manifest.json").read_bytes())}


def links_check(repo):
    count = 0
    for path in HERE.rglob("*.md"):
        for target in re.findall(r"\[[^\]]*\]\(([^)\s]+)\)", path.read_text(encoding="utf-8")):
            if target.startswith(("https://", "http://", "mailto:", "#")):
                continue
            filename = target.split("#", 1)[0]
            resolved = (path.parent/filename).resolve()
            require(resolved.is_relative_to(repo) and resolved.exists(),
                    "broken/outside local Markdown link: "+str(path.relative_to(HERE))+" -> "+target)
            count += 1
    return count


def claims_check():
    s = load(HERE/"status.json")
    m = load(HERE/"master-resource-closure/master-summary.json")
    d = load(HERE/"master-resource-closure/p0-frontier-delta.json")
    j = load(HERE/"journey-families/contracts.json")
    b = load(HERE/"entry-b/candidate-contracts.json")
    w = load(HERE/"world-lua/contracts.json")
    require(s["base_commit"] == BASE and len(s["p0"]) == 3 and len(s["p1"]) == 4, "original work package coverage")
    require(s["p0_analysis_packages_completed"] == 3 and s["p1_analysis_packages_completed"] == 4,
            "analysis package counts differ")
    for k in ["all_p0_readiness_gates_closed", "resource_ready", "official_mef_grammar_proven",
              "deployment_ready", "gameplay_verified", "server_changes_implemented"]:
        require(s[k] is False, "unsupported completion promotion: "+k)
    require(all(v is False for v in s["effects"].values()), "unexpected target/source/formal-state mutation claim")
    require(s["master_source_gate"] == "CLOSED_DECLARED_MOUNT_TREE", "Master declaration gate")
    for k in ["file_members", "directories_excluding_root", "index_nodes", "attached_packages"]:
        require(s["master"][k] == m[k], "Master count differs: "+k)
    require(s["master"]["packing_rule_joins"] == m["packing_rules"]["binding_joins"] == 897, "Master joins")
    require(s["prior_selected_scenes"]["remaining_original_frontier_entries"] == d["remaining_blocked_entries"] == 108,
            "original frontier silently closed")
    require(s["prior_selected_scenes"]["missing_descriptor_payloads"] == d["missing_model_descriptor_payloads"] == 13,
            "old and new descriptor scopes confused")
    require(s["ordinary_entry_B"] == b["status"]["ordinary_entry_B"] == "NOT_CLOSED", "B falsely closed")
    require(s["ordinary_world_to_same_run_generation_lua"] ==
            w["classification"]["ordinary_world_to_same_run_generation_lua"] == "NOT_CLOSED_NO_PROVEN_ENDPOINT",
            "world/Lua falsely closed")
    require(j["status"]["function_family_analysis"] == "ANALYZED_7_OF_7" and len(j["families"]) == 7 and
            len(j["journey"]) == 10 and not j["status"]["deployable_ready"], "P1 family/journey scope")
    require([p["preRegisterClosed"] for p in j["portal_policy_by_node"]] ==
            s["new_q119_scope"]["portal_pre_register_closed"] == [False, False, False, True], "portal policies conflated")
    require(s["new_q119_scope"]["body_calls_by_scene"] == [16, 33, 46, 48, 33] and
            sum(s["new_q119_scope"]["body_calls_by_scene"]) == 176, "body/Register count convention")
    require(s["server_development"]["can_proceed_without_unknown_B_or_world_lua_bridge"] and
            not s["server_development"]["formal_registry_changed"], "Server responsibility boundary")
    old = {name: load(HERE/"baseline-replay"/(name+".json")) for name in ["abi", "lifecycle", "server-context"]}
    require(old["abi"]["status"] == "PASS_REPRODUCIBLE_BOUNDED_RESEARCH" and
            old["abi"]["source_pins_checked"] == 40 and old["abi"]["published_errata_adopted"] == 15, "ABI replay receipt")
    require(old["lifecycle"]["all_matched"] and old["lifecycle"]["owners"] == 22 and
            old["lifecycle"]["cleanup_edges"] == 20 and old["lifecycle"]["run_profiles"] == 3, "lifecycle replay receipt")
    require(old["server-context"]["status"] == "PASS" and old["server-context"]["q119_nodes"] == 4, "Server context receipt")
    return {"P0_work_packages": 3, "P1_work_packages": 4, "family_examples": 7, "journey_steps": 10,
            "existing_baseline_replay_receipts": 3, "remaining_original_frontier_entries": 108,
            "Master_declaration_closed": True, "all_P0_ready": False, "B_closed": False, "world_Lua_closed": False}


def run_verifier(name, argv, args, expected_exit=0):
    completed = subprocess.run(argv, cwd=args.repo, capture_output=True, text=True, timeout=300)
    require(completed.returncode == expected_exit,
            name+" returned "+str(completed.returncode)+": "+completed.stderr[-1500:])
    result = json.loads(completed.stdout)
    require(result.get("status", result.get("result", "")).startswith("PASS"), name+" did not report PASS")
    return {"id": name, "expected_exit": expected_exit, "observed_exit": completed.returncode,
            "stdout_sha256": sha(completed.stdout.encode("utf-8")), "result": result}


def replay(args):
    common = ["--repo", str(args.repo)]
    sources = ["--sources", str(args.sources), "--supplemental", str(args.supplemental)]
    master = [sys.executable, "-B", str(HERE/"master-resource-closure/verify_evidence.py")]+common+sources
    jobs = [
        ("master-resource-closure", master),
        ("journey-families", [sys.executable, "-B", str(HERE/"journey-families/verify_evidence.py")]+common+sources),
        ("entry-b", [sys.executable, "-B", str(HERE/"entry-b/verify_evidence.py")]+common+
         ["--binary", str(args.sources/"02-Tartaros.bin"), "--master", str(args.sources/"11-Master.stp")]),
        ("world-lua", [sys.executable, "-B", str(HERE/"world-lua/verify_evidence.py")]+common+
         ["--bin", str(args.sources/"02-Tartaros.bin"), "--shared-instructions",
          str(args.sources/"09-02-PROJECT-SHARED-INSTRUCTIONS.md")]),
    ]
    with ThreadPoolExecutor(max_workers=4) as pool:
        futures = [pool.submit(run_verifier, name, argv, args) for name, argv in jobs]
        results = [f.result() for f in futures]
    by_id = {r["id"]: r["result"] for r in results}
    require(by_id["master-resource-closure"]["new_native_windows"] == 23 and
            by_id["master-resource-closure"]["new_native_bytes"] == 10275 and
            by_id["master-resource-closure"]["selected_native_imports"] == 2, "Master replay scope")
    require(by_id["journey-families"]["whole_scene_body_calls"] == 176 and
            by_id["journey-families"]["family_contracts"] == 7 and
            by_id["journey-families"]["bound_position_checks"] == 21, "journey replay scope")
    require(by_id["entry-b"]["conclusion"]["ordinary_entry_B"] == "NOT_CLOSED", "entry replay conclusion")
    require(not by_id["world-lua"]["claims"]["same_run_generation_event_endpoint_closed"], "world replay conclusion")
    gate = run_verifier("master-require-ready", master+["--require-ready"], args, expected_exit=2)
    require(not gate["result"]["resource_ready"], "ready gate silently passed")
    results.append(gate)
    return results


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--repo", type=Path, required=True)
    ap.add_argument("--sources", type=Path, required=True)
    ap.add_argument("--supplemental", type=Path, required=True)
    ap.add_argument("--result", type=Path)
    args = ap.parse_args()
    require(not sys.flags.optimize, "Python -O is not supported")
    args.repo, args.sources, args.supplemental = [p.resolve() for p in [args.repo, args.sources, args.supplemental]]
    require(HERE.is_relative_to(args.repo), "package must be within supplied repository")
    artifacts = artifact_check()
    sources = source_check(args)
    claims = claims_check()
    links = links_check(args.repo)
    results = replay(args)
    require(artifact_check() == artifacts, "artifacts changed during verification")
    receipt = {"schema": "MEF_MASTER_P0_P1_VERIFICATION_V1", "status": "PASS_REPRODUCIBLE_BOUNDED_ANALYSIS",
               "verified_at_utc": datetime.now(timezone.utc).isoformat(), "baseline_commit": BASE,
               "branch_target": "extra/roy1", "artifacts": artifacts, "sources": sources,
               "local_markdown_links_checked": links, "claims": claims, "replays": results,
               "target_execution": {"client": False, "lua": False, "server": False, "DLL": False},
               "complete_original_members_exported": False, "formal_status_changed": False,
               "meaning": "Bounded evidence and integration consistency. Resource ready, B, world-Lua, official MEF grammar and gameplay are not promoted."}
    if args.result:
        require(not args.result.is_symlink(), "receipt symlink rejected")
        target = args.result.resolve()
        require(target.name == "verification-result.json", "receipt filename must be verification-result.json")
        require(target == HERE/"verification-result.json" or not target.is_relative_to(args.repo),
                "receipt may not overwrite another repository file")
        for source in [args.sources, args.supplemental]:
            require(not target.is_relative_to(source), "receipt overlaps original source tree")
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_text(json.dumps(receipt, ensure_ascii=False, indent=2)+"\n", encoding="utf-8")
    print(json.dumps(receipt, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    try:
        main()
    except (ValueError, OSError, KeyError, subprocess.SubprocessError) as exc:
        print(json.dumps({"status": "FAIL", "error": str(exc)}, ensure_ascii=False), file=sys.stderr)
        sys.exit(1)
