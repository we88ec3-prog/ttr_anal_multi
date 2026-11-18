#!/usr/bin/env python3
"""Read-only evidence/package verification; never runs Client, target Lua, or Server."""
from __future__ import annotations

import argparse
from concurrent.futures import ThreadPoolExecutor
import datetime
import hashlib
import json
from pathlib import Path
import re
import subprocess
import sys

HERE = Path(__file__).resolve().parent
BASE = "60c1c1a5dc7a73902d9dbb50361d5148e8b30058"
PACKAGE = "kr-extra-roy/MEF-server-provided-capabilities-20261118"
EXTRA = ["kr-extra-roy/AGENTS.md", "kr-extra-roy/MEF-CURRENT-DIRECTION.md", "kr-extra-roy/README.md"]
EXCLUDED = {"artifact-manifest.json", "verification-result.json"}


def require(condition, message):
    if not condition:
        raise ValueError(message)


def sha(data):
    return hashlib.sha256(data).hexdigest()


def load(path):
    return json.loads(path.read_text(encoding="utf-8"))


def command(args, cwd):
    return subprocess.check_output(args, cwd=cwd)


def source_check(repo, sources):
    manifest = load(HERE / "source-manifest.json")
    require(manifest["base_commit"] == BASE, "unexpected analysis baseline")
    result = {}
    for row in manifest["published_pins"]:
        ref = row["source_commit"] + ":" + row["path"]
        data = command(["git", "show", ref], repo)
        blob = command(["git", "rev-parse", ref], repo).decode().strip()
        require(blob == row["git_blob"] and len(data) == row["bytes"] and sha(data) == row["sha256"],
                "pinned source differs: " + row["path"])
        require((repo / row["path"]).read_bytes() == data, "worktree source differs: " + row["path"])
        result[row["path"]] = data
    for row in manifest["originals"] + [manifest["shared_instructions"]]:
        data = (sources / row["source_file"]).read_bytes()
        require(len(data) == row["bytes"] and sha(data) == row["sha256"], "original/instructions identity differs: " + row["source_file"])
    for rel in manifest["subpackage_source_manifests"]:
        require((HERE / rel).is_file(), "missing subpackage sources: " + rel)
    return result, {"published_source_pins": len(result), "original_identities": len(manifest["originals"]),
                    "shared_instructions_identity": "MATCH", "source_files_changed": False}


def artifact_check(repo):
    manifest = load(HERE / "artifact-manifest.json")
    rows = manifest["files"]
    paths = [r["path"] for r in rows]
    require(len(paths) == len(set(paths)), "duplicate artifact paths")
    expected = {p.relative_to(repo).as_posix() for p in HERE.rglob("*")
                if p.is_file() and not (p.parent == HERE and p.name in EXCLUDED)} | set(EXTRA)
    require(set(paths) == expected, "artifact set differs from sealed package")
    for row in rows:
        rel = row["path"]
        require(rel.startswith(PACKAGE + "/") or rel in EXTRA, "unexpected artifact scope: " + rel)
        require(Path(rel).suffix in {".md", ".json", ".py", ".asm", ".txt"}, "unexpected artifact type: " + rel)
        data = (repo / rel).read_bytes()
        require(len(data) == row["bytes"] and sha(data) == row["sha256"], "artifact differs: " + rel)
        if rel.endswith(".json"):
            json.loads(data)
    return {"sealed_files": len(rows), "sha256_and_sizes": "MATCH", "package_and_direction_files_only": True}


def capability_check(source_bytes):
    catalog_path = "kr-extra-roy/MEF-comprehensive-contracts-20261117/function-map/function-coverage.json"
    abi_path = "kr-extra-roy/MEF-comprehensive-contracts-20261117/abi/abi-contracts.json"
    helpers_path = "kr-extra-roy/MEF-capabilities-20261116/control/helper-index.json"
    old = {r["name"]: r for r in json.loads(source_bytes[catalog_path])["records"]}
    abi = {r["name"]: r for r in json.loads(source_bytes[abi_path])["bindings"]}
    new = load(HERE / "binding-offload-map.json")
    rows = new["records"]
    by_name = {r["name"]: r for r in rows}
    require(len(rows) == len(by_name) == 121 and set(by_name) == set(old) == set(abi), "normal binding set differs")
    require(len({r["domain"] for r in rows}) == 15, "domain set differs")
    for name, row in by_name.items():
        require(row["native"] == old[name]["native"] == abi[name]["native"], "native target differs: " + name)
        for key in ["argument_kinds", "argument_count", "produces_new_lua_value", "lua_value_kind"]:
            require(row[key] == abi[name][key], "ABI changed: " + name + " / " + key)
        expected = "UNUSABLE_STUB" if old[name]["is_stub"] else (
            "NO_COUNT_RESULT" if name == "lb.GetObjectCount" else "BOUNDED_NATIVE_CAPABILITY_REUSABLE")
        require(row["classification"] == expected, "unsupported capability change: " + name)
        require(not {"required_context", "completion_boundary", "cleanup_boundary"}.intersection(row),
                "generic domain lifecycle was reintroduced as per-API requirement")
        require(row["evidence_refs"] == old[name]["evidence_refs"], "source references differ: " + name)
    helpers = json.loads(source_bytes[helpers_path])["exports"]
    require(len(helpers) == len({r["name"] for r in helpers}) == 75, "qbase helper coverage differs")
    plan = load(HERE / "capability-plan.json")
    require({r["id"] for r in plan["records"]} == {"spawn", "combat", "group_clear", "exit", "settlement", "rewards", "persistence"},
            "seven requested gameplay functions not covered")
    require(len(plan["records"]) == 7, "duplicate gameplay records")
    for row in plan["records"]:
        for key in ["client_mef", "server_mef", "existing_foundation", "minimum_adapter", "remaining", "evidence"]:
            require(bool(row[key]), "missing concrete split: " + row["id"] + " / " + key)
        require(row["scope"] == "MEF_AND_SERVER_DEVELOPMENT" and row["official_mef_required"] is False,
                "user scope was lost: " + row["id"])
        for path in row["evidence"]:
            require((HERE / path).is_file(), "missing gameplay evidence: " + path)
    dispatch = plan["finite_result_dispatch"]
    require(dispatch["generic_event_to_resident_lua_bridge_required"] is False and dispatch["new_wire_payload"] is False,
            "finite selector composition incorrectly requires a new event channel")
    require(dispatch["deployed"] is False, "finite composition is not a deployed release")
    profiles = {p["id"]: p for p in load(HERE / "delivery-profiles/contracts.json")["profiles"]}
    require(not profiles["Q_FINITE"]["ordinary_background_B_required"] and
            not profiles["TUTORIAL_INTERACTIVE"]["ordinary_background_B_required"], "B incorrectly blocks available profiles")
    require(profiles["ORDINARY_BACKGROUND_B"]["static_end_to_end_closed"] is False, "optional B evidence status inflated")
    status = load(HERE / "status.json")
    require(status["goal"]["mef_is_server_development"] and status["goal"]["server_executed_mef_rules_in_scope"], "MEF scope mismatch")
    require(not status["goal"]["official_format_recovery_required"] and not status["goal"]["official_samples_gate_custom_content"],
            "retired format gate reintroduced")
    require(all(value is False for value in status["effects"].values()), "unexpected execution/deployment/formal status assertion")
    require([r["id"] for r in status["priorities"]] == ["P0", "P1", "P2"], "priority list differs")
    return {"normal_bindings": len(rows), "domains": 15, "bounded_capability_names": 116, "stubs": 4,
            "not_a_count": 1, "new_value_producers": sum(r["produces_new_lua_value"] for r in rows),
            "reused_qbase_helpers": len(helpers), "gameplay_functions": len(plan["records"]),
            "native_targets_and_abi_equal_pinned_sources": True, "generic_lifecycle_fields_removed": True,
            "available_profiles_not_blocked_by_B": True, "official_format_not_a_gate": True}


def markdown_check(repo):
    checked = 0
    documents = list(HERE.rglob("*.md")) + [repo / p for p in EXTRA]
    for path in documents:
        data = path.read_text(encoding="utf-8")
        without_code = re.sub(r"```.*?```", "", data, flags=re.S)
        for target in re.findall(r"\[[^\]]*\]\(([^)]+)\)", without_code):
            if target.startswith(("http://", "https://", "sandbox:", "#", "mailto:")):
                continue
            target = target.split("#", 1)[0]
            if not target:
                continue
            require((path.parent / target).resolve().exists(), "missing Markdown target: " + str(path) + " -> " + target)
            checked += 1
    return {"documents": len(documents), "local_link_targets": checked}


def subpackage_check(repo, sources):
    tasks = [
        ("delivery-profiles", ["--repo", str(repo), "--sources", str(sources)]),
        ("world-offload", ["--repo", str(repo), "--bin", str(sources / "02-Tartaros.bin")]),
        ("npc-progression", ["--repo", str(repo), "--bin", str(sources / "02-Tartaros.bin"), "--table", str(sources / "07-Table.stp")]),
    ]

    def run(task):
        name, args = task
        completed = subprocess.run([sys.executable, "-B", str(HERE / name / "verify_evidence.py")] + args,
                                   cwd=repo, capture_output=True, text=True, check=False)
        require(completed.returncode == 0, name + " verification failed: " + completed.stdout[-3000:] + completed.stderr[-3000:])
        actual = json.loads(completed.stdout)
        require(str(actual.get("status", "")).startswith("PASS"), name + " did not report PASS")
        saved = load(HERE / name / "verification-result.json")
        comparable_actual, comparable_saved = dict(actual), dict(saved)
        if name == "world-offload":
            # This verifier timestamps each real rerun; all evidence/results must match.
            for receipt in [comparable_actual, comparable_saved]:
                timestamp = datetime.datetime.fromisoformat(receipt.pop("verified_at_utc"))
                require(timestamp.tzinfo is not None, "world receipt lacks a zoned timestamp")
        require(comparable_actual == comparable_saved, name + " saved evidence/result differs from rerun")
        return name, actual

    with ThreadPoolExecutor(max_workers=3) as pool:
        results = list(pool.map(run, tasks))
    return dict(results)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--repo", type=Path, required=True)
    parser.add_argument("--sources", type=Path, required=True)
    parser.add_argument("--receipt", type=Path)
    args = parser.parse_args()
    repo, sources = args.repo.resolve(), args.sources.resolve()
    require(HERE == repo / PACKAGE, "repository/package path mismatch")
    artifacts = artifact_check(repo)
    source_bytes, sources_result = source_check(repo, sources)
    capabilities = capability_check(source_bytes)
    links = markdown_check(repo)
    subpackages = subpackage_check(repo, sources)
    require(artifact_check(repo) == artifacts, "verification changed a sealed artifact")
    result = {"schema": "MEF_SERVER_PROVIDED_VERIFICATION_V1", "status": "PASS_BOUNDED_EVIDENCE_AND_CAPABILITY_CONTRACTS",
              "base_commit": BASE, "sources": sources_result, "artifacts": artifacts,
              "capability_coverage": capabilities, "markdown": links, "subpackages": subpackages,
              "scope": "固定來源、只讀原件有界證據、能力契約、交付一致性；不等於目標執行／部署／遊玩或正式全驗收。",
              "target_executed": False, "lua_executed": False, "server_executed": False,
              "deployed": False, "formal_status_changed": False}
    encoded = json.dumps(result, ensure_ascii=False, indent=2) + "\n"
    if args.receipt:
        args.receipt.write_text(encoded, encoding="utf-8")
    print(encoded, end="")


if __name__ == "__main__":
    main()
