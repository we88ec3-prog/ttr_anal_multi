#!/usr/bin/env python3
"""Replay only the pinned offline authored-content analysis. No target execution."""
from __future__ import annotations

import argparse
from datetime import datetime, timezone
import hashlib
import importlib.metadata
import json
from pathlib import Path
import platform
import subprocess
import sys

sys.dont_write_bytecode = True
from analyze_content import BASE, SCHEMA_PATH, all_paths, analyze


def require(condition, detail):
    if not condition:
        raise ValueError(detail)


def digest(raw):
    return hashlib.sha256(raw).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--repo", type=Path, required=True)
    parser.add_argument("--write-receipt", action="store_true")
    args = parser.parse_args()
    repo = args.repo.resolve()
    here = Path(__file__).resolve().parent
    manifest = json.loads((here / "source-manifest.json").read_text())
    require(manifest["baseline"] == BASE, "baseline mismatch")
    pinned = manifest["sources"]
    source_paths = [p["path"] for p in pinned]
    require(len(set(source_paths)) == len(source_paths) == manifest["source_count"], "source identities/count")
    documentation_count = 0
    for row in pinned:
        raw = subprocess.check_output(["git", "show", BASE + ":" + row["path"]], cwd=repo)
        blob = subprocess.check_output(["git", "rev-parse", BASE + ":" + row["path"]], cwd=repo, text=True).strip()
        require((len(raw), digest(raw), blob) == (row["bytes"], row["sha256"], row["git_blob"]), "source receipt mismatch: " + row["path"])
        if Path(row["path"]).suffix.lower() == ".md":
            # Documentary claims are pinned to the immutable Git object, not to
            # mutable navigation/current-direction pages in the later worktree.
            documentation_count += 1
        else:
            # Never relax real analysis inputs or a source Python helper.
            require((repo / row["path"]).read_bytes() == raw, "worktree source drift: " + row["path"])
    scenario_paths = sorted(row["path"] for row in pinned if row["role"] == "authored_scenario_occurrence")
    require(scenario_paths == all_paths(repo), "scenario source set mismatch")
    require(len(scenario_paths) == manifest["scenario_file_count"], "scenario source count")

    audit = json.loads((here / "content-audit.json").read_text())
    replay = analyze(repo)
    require(audit == replay, "saved analysis differs from replay")
    require(not audit["schema_errors"], "schema errors")
    require(not audit["structural_dependency_issues"], "structural/dependency issues")
    require(all(d["all_nodes_reachable"] and d["acyclic"] and d["result_exit_count"] > 0 for d in audit["definitions"]), "finite graph result")

    schema = json.loads((repo / SCHEMA_PATH).read_text())
    rules = json.loads((here / "rule-contracts.json").read_text())
    opt = json.loads((here / "optimization-contracts.json").read_text())
    status = json.loads((here / "analysis-status.json").read_text())
    for obj in (rules, opt, status):
        require(obj["baseline"] == BASE, "artifact baseline drift")
    require(rules["rule_events"] == schema["$defs"]["rule"]["properties"]["event"]["enum"], "rule event coverage")
    require(rules["rule_actions"] == schema["$defs"]["rule"]["properties"]["action"]["enum"], "rule action coverage")
    require(rules["signal_events"] == schema["$defs"]["signal"]["properties"]["event"]["enum"], "signal coverage")
    require(len(rules["features"]) == status["semantic_features_closed"] == 18, "feature coverage count")
    by_id = {f["id"]: f for f in rules["features"]}
    require(len(by_id) == len(rules["features"]), "duplicate semantic feature")
    event_counts = {s["event"]: s["occurrences"] for s in audit["signal_coverage"]}
    for feature in rules["features"]:
        require(all(s in source_paths for s in feature["sources"]), "unpinned feature source: " + feature["id"])
        for pointer in feature["schema_pointers"]:
            node = schema
            for part in pointer.split("/")[1:]:
                node = node[part.replace("~1", "/").replace("~0", "~")]
        coverage = feature["configured_coverage"]
        if "signal_event" in coverage:
            require(coverage["occurrences"] == event_counts[coverage["signal_event"]], "feature event count: " + feature["id"])

    counts, coverage = audit["counts"], audit["feature_coverage"]
    expected = {
        "RULE-01": {"nodes": counts["nodes"], "initial_actor_occurrences": counts["initial_actors"]},
        "RULE-02": {"waves": counts["reinforcements"]},
        "RULE-03": {"waves": counts["timedReinforcements"]},
        "RULE-04": {"flag_gated_waves": counts["flag_gated_waves"], "region_gated_waves": counts["region_gated_waves"]},
        "RULE-05": {"empty_initial_nodes": counts["initial_empty_nodes"], "named_wave_required_boss_nodes": coverage["required_boss_named_wave_nodes"]},
        "RULE-08": {"required_boss_nodes": coverage["required_boss_nodes"]},
        "RULE-09": {"default_unlock_rules": coverage["default_action_UnlockPortal"]},
        "RULE-14": {"require_group_clear": coverage["manual_requires_group_clear"], "no_group_clear_requirement": coverage["manual_pre_clear"], "with_flag_prerequisites": coverage["manual_with_flag_prerequisites"]},
        "RULE-15": {"default_exit_conditions": coverage["default_exit_conditions"], "alternative_exit_conditions": coverage["alternative_exit_conditions"]},
        "RULE-16": {"branch_nodes": coverage["branch_nodes"], "alternative_exits": counts["alternativeExits"], "next_node_edges": coverage["default_action_NextNode"] + coverage["alternative_action_NextNode"], "result_exits": sum(d["result_exit_count"] for d in audit["definitions"])},
        "RULE-17": {"signal_occurrences": counts["signals"], "nodes_with_incoming_guaranteed_flags": sum(bool(n["guaranteed_flags_on_entry"]) for d in audit["definitions"] for n in d["nodes"])},
        "RULE-18": {"pre_registered_default_exits": coverage["pre_registered_default_exits"]},
    }
    for feature_id, expected_values in expected.items():
        for key, value in expected_values.items():
            require(by_id[feature_id]["configured_coverage"][key] == value, "configured count drift: " + feature_id + "/" + key)
    limits = rules["limits"]
    require(limits["nodes_per_definition"] == schema["$defs"]["definition"]["properties"]["nodes"]["maxItems"], "node limit")
    require(limits["extra_waves_combined_per_node"] == 31 and limits["actors_total_per_node"] == 255, "typed combined capacities")
    require(limits["exits_per_node"] == 1 + schema["$defs"]["node"]["properties"]["alternativeExits"]["maxItems"], "exit limit")
    require(limits["flags_per_requirement"] == schema["$defs"]["wave"]["properties"]["requiredFlags"]["maxItems"], "flag requirement limit")
    require(limits["unique_flags_per_definition"] == 64 and limits["manual_interactions_per_node"] == 8, "typed flags/interactions bound")
    require(status["schema_validation"] == {"status": "PASS", "files": counts["files"], "errors": 0}, "status schema counts")
    require(status["graph_and_dependency_analysis"]["definition_occurrences"] == counts["definitions"], "status definitions")
    require(status["graph_and_dependency_analysis"]["node_occurrences"] == counts["nodes"], "status nodes")
    require(len(opt["proposals"]) == status["new_optimization"]["proposal_count"] == 7, "optimization count")
    require(len({p["id"] for p in opt["proposals"]}) == len(opt["proposals"]), "optimization identity")
    require(status["analysis_status"] == "COMPLETE_FOR_PINNED_SCOPE", "analysis status")
    require(status["spatial_reachability"]["status"] == "SEPARATE_AUDIT_WITH_KNOWN_CONTENT_BLOCKERS", "spatial scope must be separate")
    for obj in (audit, opt, status):
        require(not obj["target_executed"] and not obj["server_executed"] and not obj["lua_executed"], "execution boundary")
    require(not rules["runtime_test_performed"] and not rules["human_play_verified"] and not status["human_play_verified"], "runtime/human boundary")

    names = ["analyze_content.py", "verify_evidence.py", "source-manifest.json", "content-audit.json", "rule-contracts.json", "optimization-contracts.json", "analysis-status.json", "report.md"]
    artifact_pins = []
    for name in names:
        raw = (here / name).read_bytes()
        artifact_pins.append({"file": name, "bytes": len(raw), "sha256": digest(raw)})
    summary = {
        "schema": "MEF_LEVEL_RULES_VERIFICATION_RECEIPT_V1", "baseline": BASE,
        "result": "PASS_STATIC_SOURCES_SCHEMA_GRAPH_DEPENDENCIES_CONTRACT_COVERAGE",
        "source_files_verified": len(pinned), "scenario_files_verified": len(scenario_paths),
        "source_verification_policy": {
            "documentation_git_objects_verified": documentation_count,
            "non_documentation_git_and_worktree_inputs_verified": len(pinned) - documentation_count,
            "executed_helpers_covered_by_artifact_hashes": ["analyze_content.py", "verify_evidence.py"],
        },
        "definition_occurrences": counts["definitions"], "node_occurrences": counts["nodes"],
        "schema_errors": 0, "structural_dependency_issues": 0,
        "semantic_features": len(rules["features"]), "signal_semantics": len(event_counts),
        "optimization_contracts": len(opt["proposals"]),
        "target_executed": False, "server_executed": False, "lua_executed": False,
        "human_play_verified": False, "spatial_validation_performed_here": False,
        "artifacts": artifact_pins,
    }
    receipt_path = here / "verification-receipt.json"
    if args.write_receipt:
        receipt = dict(summary, verified_utc=datetime.now(timezone.utc).isoformat(),
                       environment={"python": platform.python_version(), "jsonschema": importlib.metadata.version("jsonschema")})
        receipt_path.write_text(json.dumps(receipt, ensure_ascii=False, indent=2) + "\n")
    else:
        receipt = json.loads(receipt_path.read_text())
        require(all(receipt[k] == v for k, v in summary.items()), "receipt/artifact drift; rerun --write-receipt only after reviewing changes")
    print(json.dumps({k: v for k, v in summary.items() if k != "artifacts"}, ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
