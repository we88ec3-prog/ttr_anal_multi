#!/usr/bin/env python3
"""Reproduce the level analysis package; never runs game, target Lua or Server."""
from __future__ import annotations
import argparse
from concurrent.futures import ThreadPoolExecutor
from collections import Counter
import datetime
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import re
import subprocess
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
BASE = "09799b117f01e577be56dee3e909e1cde25b855f"
PACKAGE = "kr-extra-roy/MEF-level-functional-closure-20261118"
EXTRA = ["kr-extra-roy/MEF-CURRENT-DIRECTION.md", "kr-extra-roy/README.md"]
EXCLUDED = {"artifact-manifest.json", "verification-result.json"}


def require(ok, message):
    if not ok:
        raise ValueError(message)


def sha(data):
    return hashlib.sha256(data).hexdigest()


def load(path):
    return json.loads(path.read_text(encoding="utf-8"))


def git(repo, *args):
    env = {**os.environ, "GIT_NO_LAZY_FETCH": "1", "GIT_OPTIONAL_LOCKS": "0", "GIT_TERMINAL_PROMPT": "0"}
    return subprocess.check_output(["git", "-C", str(repo), *args], env=env)


def sources_check(repo, sources):
    manifest = load(HERE/"source-manifest.json")
    require(manifest["base_commit"] == BASE, "baseline mismatch")
    for r in manifest["git_sources"]:
        ref = r["commit"]+":"+r["path"]
        data = git(repo, "show", ref)
        require(git(repo, "rev-parse", ref).decode().strip() == r["blob"] and
                len(data) == r["bytes"] and sha(data) == r["sha256"], "source differs: "+r["path"])
    for r in manifest["originals"]+[manifest["shared_instructions"]]:
        data = (sources/r["file"]).read_bytes()
        require(len(data) == r["bytes"] and sha(data) == r["sha256"], "original/instructions differs: "+r["file"])
    for r in manifest["subpackage_source_manifests"]:
        require((HERE/r).is_file(), "subpackage sources missing")
    fresh = load(HERE/"outcomes-continuity/latest-main-update.json")
    require(fresh["supplement_commit"] == manifest["latest_main_review"]["observed_head"] and
            fresh["original_50_source_pins_changed"] is False, "fresh-main scope")
    fresh_sources = {}
    for r in fresh["git_sources"]:
        ref = r["commit"]+":"+r["path"]
        data = git(repo,"show",ref)
        require(git(repo,"rev-parse",ref).decode().strip() == r["git_blob"] and
                len(data) == r["length"] and sha(data) == r["sha256"], "fresh source differs: "+r["path"])
        fresh_sources[r["id"]] = data
    require(sha(fresh_sources["U03"]) == fresh["verification"]["source_receipt_sha256"], "fresh receipt cross-hash")
    require(fresh["coverage_limits"]["tests_executed_by_this_agent"] is False and
            fresh["coverage_limits"]["client_executed"] is False and
            fresh["coverage_limits"]["deployed"] is False and
            fresh["coverage_limits"]["scenario_mode2_class26_direct_bag_entry_closed"] is False,
            "fresh source cannot inflate execution/native scope")
    return {"root_git_sources":len(manifest["git_sources"]),"original_identities":len(manifest["originals"]),
            "shared_instructions":"MATCH","subpackage_source_manifests":len(manifest["subpackage_source_manifests"]),
            "latest_main":fresh["supplement_commit"],"fresh_outcome_source_pins":len(fresh_sources)}


def artifacts_check(repo):
    manifest = load(HERE/"artifact-manifest.json")
    expected = {p.relative_to(repo).as_posix() for p in HERE.rglob("*") if p.is_file()
                and not (p.parent == HERE and p.name in EXCLUDED)} | set(EXTRA)
    rows = manifest["files"]
    paths = [r["path"] for r in rows]
    require(len(paths) == len(set(paths)) and set(paths) == expected, "sealed artifact set differs")
    for r in rows:
        path = repo/r["path"]
        require(r["path"].startswith(PACKAGE+"/") or r["path"] in EXTRA, "unexpected scope")
        require(path.suffix in {".md",".json",".py",".asm"}, "unexpected artifact type")
        data = path.read_bytes()
        require(len(data) == r["bytes"] and sha(data) == r["sha256"], "artifact differs: "+r["path"])
        if path.suffix == ".json": json.loads(data)
    return {"sealed_files":len(rows),"sha256_and_sizes":"MATCH","new_package_and_owned_indexes_only":True}


def links_check(repo):
    docs = list(HERE.rglob("*.md"))+[repo/p for p in EXTRA]
    count = 0
    for path in docs:
        body = re.sub(r"```.*?```", "", path.read_text(), flags=re.S)
        for target in re.findall(r"\[[^\]]*\]\(([^)]+)\)", body):
            if target.startswith(("https://","http://","sandbox:","#","mailto:")): continue
            target = target.split("#",1)[0]
            if target:
                require((path.parent/target).resolve().exists(), "broken link: "+str(path)+" -> "+target)
                count += 1
    return {"documents":len(docs),"local_link_targets":count}


def contracts_check():
    features = load(HERE/"feature-status.json")["features"]
    require(len(features) == 20 and {r["id"] for r in features} == {f"L{i:02}" for i in range(1,21)}, "feature coverage")
    require(Counter(r["priority"] for r in features) == {"P0":14,"P1":5,"P2":1}, "feature priorities")
    for r in features:
        require(r["analysis_status"] == "COMPLETE_FOR_PINNED_SCOPE" and not r["new_deployment_claimed"], "feature status")
        for key in ["player_feature","progress","confirmed","mef_execution_plan","remaining","evidence"]:
            require(bool(r[key]), "missing feature field: "+r["id"]+"/"+key)
        for rel in r["evidence"]: require((HERE/rel).is_file(), "feature evidence missing")
    opts = load(HERE/"optimization-plan.json")["items"]
    require(len(opts) == 9 and {r["id"] for r in opts} == {f"O{i:02}" for i in range(1,10)}, "optimization coverage")
    require(Counter(r["priority"] for r in opts) == {"P0":2,"P1":5,"P2":2}, "optimization priorities")
    for r in opts:
        require(not r["implemented_this_turn"] and bool(r["action"]) and bool(r["benefit"]), "optimization scope")
        for rel in r["evidence"]: require((HERE/rel).is_file(), "optimization evidence missing")
    status = load(HERE/"status.json")
    require(status["base_commit"] == BASE and status["feature_count"] == 20, "root status")
    require(status["goal"]["mef_is_server_development"] and status["goal"]["server_executed_mef_rules_in_scope"] and
            status["goal"]["existing_configuration_may_be_reused_without_new_format"] and
            not status["goal"]["official_mef_recovery_required"], "user scope")
    require(all(v is False for v in status["effects"].values()), "unexpected execution/deployment claim")
    require({r["id"]:r["feature_count"] for r in status["priorities"]} == {"P0":14,"P1":5,"P2":1}, "status counts")
    return {"features":len(features),"optimization_items":len(opts),"priority_feature_counts":dict(Counter(r["priority"] for r in features)),
            "existing_server_mef_retained":True,"official_recovery_not_required":True,"new_runtime_pass_claimed":False}


def review_check(repo, sources):
    review = load(HERE/"outcomes-continuity/root-handoff-review.json")
    require(review["result"] == "PASS_FOR_DECLARED_STATIC_SCOPE", "independent review status")
    for r in review["reviewed_artifacts"]:
        require(sha((repo/r["path"]).read_bytes()) == r["sha256"], "reviewed artifact changed: "+r["path"])
    spec = importlib.util.spec_from_file_location("level_review_pe", HERE/"outcomes-continuity/verify.py")
    verifier = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(verifier)
    binary = (sources/"02-Tartaros.bin").read_bytes()
    require(sha(binary) == review["original_bin_sha256"], "review binary identity")
    pe = verifier.PE(binary)
    for row in review["independent_instruction_checks"]:
        va = int(row["va"],16)
        if row["kind"] == "rel32": require(pe.rel32(va) == int(row["target"],16), "review call")
        else:
            data = bytes.fromhex(row["hex"])
            require(pe.read(va,len(data)) == data, "review instruction")
    return {"reviewed_versions":len(review["reviewed_artifacts"]),
            "independent_instruction_checks":len(review["independent_instruction_checks"]),"status":"MATCH"}


def subpackages_check(repo, sources):
    tasks = [
        ("rules-waves","verify_evidence.py",["--repo",str(repo)],"verification-receipt.json"),
        ("space-mechanisms","verify_evidence.py",["--originals",str(sources)],"verification-result.json"),
        ("outcomes-continuity","verify.py",["--repo",str(repo),"--original-bin",str(sources/"02-Tartaros.bin")],"verification.json"),
        ("finite-handoff","analyze_handoff.py",["--repo",str(repo),"--sources",str(sources)],"verification-result.json"),
    ]
    def run(task):
        name, script, args, receipt = task
        p = subprocess.run([sys.executable,"-B",str(HERE/name/script)]+args,cwd=repo,capture_output=True,text=True)
        require(p.returncode == 0, name+" verifier failed: "+p.stdout[-3000:]+p.stderr[-3000:])
        actual, saved = json.loads(p.stdout), load(HERE/name/receipt)
        require(str(actual.get("result",actual.get("status",""))).startswith("PASS"), name+" not PASS")
        comparable_a, comparable_s = dict(actual), dict(saved)
        if name == "rules-waves":
            # Its normal CLI emits the stable summary; it already verifies all
            # receipt artifact hashes internally. Timestamp/environment describe
            # the saved observation and are not present in normal CLI output.
            require(set(comparable_s) == set(comparable_a)|{"verified_utc","environment","artifacts"}, "rules receipt shape")
            require(datetime.datetime.fromisoformat(comparable_s.pop("verified_utc")).tzinfo is not None, "rules timestamp")
            environment = comparable_s.pop("environment")
            require(set(environment) == {"python","jsonschema"} and all(environment.values()), "rules environment metadata")
            require(len(comparable_s.pop("artifacts")) == 8, "rules verified artifact pins")
        require(comparable_a == comparable_s, name+" saved receipt differs")
        # Stable results only; each original timestamped observation stays in its subpackage receipt.
        return name, comparable_a
    with ThreadPoolExecutor(max_workers=4) as pool:
        return dict(pool.map(run,tasks))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--repo",type=Path,required=True)
    parser.add_argument("--sources",type=Path,required=True)
    parser.add_argument("--receipt",type=Path)
    args = parser.parse_args()
    require(not sys.flags.optimize, "run without -O; assertions verify evidence")
    repo, sources = args.repo.resolve(), args.sources.resolve()
    require(HERE == repo/PACKAGE, "repository/package mismatch")
    artifacts = artifacts_check(repo)
    source_result = sources_check(repo,sources)
    links = links_check(repo)
    contracts = contracts_check()
    review = review_check(repo,sources)
    results = subpackages_check(repo,sources)
    require(artifacts_check(repo) == artifacts, "analysis mutated sealed artifacts")
    require(results["rules-waves"]["scenario_files_verified"] == results["space-mechanisms"]["counts"]["scenario_files"] == 67, "corpus mismatch")
    require(results["rules-waves"]["node_occurrences"] == results["space-mechanisms"]["counts"]["node_occurrences"] == 399, "node mismatch")
    output = {"schema":"MEF_LEVEL_ROOT_VERIFICATION_V1","status":"PASS_BOUNDED_LEVEL_ANALYSIS_AND_PACKAGE",
              "base_commit":BASE,"sources":source_result,"artifacts":artifacts,"markdown":links,
              "coverage":contracts,"independent_review":review,"subpackages":results,
              "known_content_findings_retained":True,"target_executed":False,"server_executed":False,
              "target_lua_executed":False,"deployed":False,"formal_status_changed":False,
              "scope":"Reproduced source/native/static-content analyses and explicit known findings; not gameplay or deployment acceptance."}
    text = json.dumps(output,ensure_ascii=False,indent=2)+"\n"
    if args.receipt: args.receipt.write_text(text,encoding="utf-8")
    print(text,end="")


if __name__ == "__main__":
    main()
