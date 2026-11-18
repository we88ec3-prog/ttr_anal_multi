#!/usr/bin/env python3
"""Verify this analysis package and rerun its read-only spatial evidence audit.

No game, Lua, Server, network, Git mutation or original-resource writes. PASS
means the audit and its known content findings are reproduced, not runtime PASS.
"""
import argparse
import hashlib
import importlib.util
import json
from pathlib import Path
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent


def require(ok, message):
    if not ok:
        raise ValueError(message)


def sha(data):
    return hashlib.sha256(data).hexdigest()


def load(name):
    return json.loads((HERE / name).read_text(encoding="utf-8"))


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--originals", type=Path, required=True)
    p.add_argument("--write-receipt", action="store_true", help="write only this package's derived verification-result.json")
    args = p.parse_args()
    artifacts = load("artifact-manifest.json")
    for row in artifacts["files"]:
        path = (HERE / row["path"]).resolve()
        require(path.parent == HERE, "artifact path scope")
        data = path.read_bytes()
        require(len(data) == row["length"] and sha(data) == row["sha256"], "artifact drift: " + row["path"])
    spec = importlib.util.spec_from_file_location("pinned_spatial_audit", HERE / "audit_spatial.py")
    audit = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(audit)
    result = audit.build(args.originals)
    require(result == load("spatial-evidence.json"), "derived spatial evidence mismatch")
    c = result["counts"]
    expected = {"scenario_files": 67, "definition_occurrences": 86, "node_occurrences": 399,
                "unique_map_ids": 118, "unique_map_ids_excluding_branch_example": 117,
                "unique_bound_members": 74, "point_exit": 444, "point_spawn": 399, "point_monster": 895,
                "point_status_reachable": 1753, "point_status_blocked_cell": 10,
                "nodes_with_nonreachable_points": 4, "potential_exit_circle_overlaps": 0}
    require(all(c[k] == v for k, v in expected.items()), "pinned corpus count mismatch")
    require({p["file"] for p in result["nonreachable_points"]} ==
            {"design/scenario-content/branch-example.scenario.json"}, "known content finding scope")
    barriers = [f["barriers"] for f in result["feature_geometry"] if f.get("barriers")]
    require(len(barriers) == 3 and all(b["overlay_cells"] == 12 and b["main_exit_reachable_while_closed"]
            and b["closed_barrier_route_witness"]["steps"] == 18
            and all(s["blocked_samples"] == 0 for s in b["closed_barrier_route_witness"]["segments"])
            for b in barriers), "known barrier bypass witness mismatch")
    require(len(result["revalidated_native_point_spans"]) == 13, "native evidence count")
    repair = result["branch_example_coordinate_remediation"]
    require(repair["status"] == "STATIC_CHECKED_NOT_APPLIED" and
            sum(len(n["points"]) for n in repair["nodes"]) == 13, "coordinate candidate scope")
    contracts = load("spatial-contracts.json")
    require(contracts["analysis_complete"] and not contracts["new_runtime_implementation_claimed"]
            and not contracts["official_mef_format_is_goal_or_gate"], "analysis status boundary")
    require(len(contracts["contracts"]) == 10 and len(contracts["consumer_separation"]) == 4
            and len(contracts["optimization_proposals"]) == 6, "contract coverage")
    manifest = load("source-manifest.json")
    receipt = {
        "schema": "MEF_LEVEL_SPATIAL_VERIFICATION_V1",
        "result": "PASS",
        "interpretation": "READ_ONLY_STATIC_AUDIT_REPRODUCED_WITH_KNOWN_CONTENT_FINDINGS; NOT_RUNTIME_OR_PLAYER_PASS",
        "baseline_commit": manifest["baseline_commit"],
        "artifact_manifest_sha256": sha((HERE / "artifact-manifest.json").read_bytes()),
        "source_manifest_sha256": sha((HERE / "source-manifest.json").read_bytes()),
        "spatial_evidence_sha256": sha((HERE / "spatial-evidence.json").read_bytes()),
        "verified_artifacts": len(artifacts["files"]),
        "verified_git_sources": len(manifest["git_sources"]),
        "source_access": {
            "baseline_git_objects": len(manifest["git_sources"]),
            "strict_worktree_inputs_and_helpers": sum(Path(s["path"]).suffix.lower() != ".md" for s in manifest["git_sources"]),
            "fixed_git_document_sources": sum(Path(s["path"]).suffix.lower() == ".md" for s in manifest["git_sources"]),
            "mutable_document_worktree_used_as_historical_evidence": False
        },
        "verified_original_carriers": len(manifest["originals"]),
        "verified_native_point_windows": 13,
        "counts": c,
        "known_findings": {"blocked_centers_in_legacy_branch_example": 10,
                           "q119_barrier_occurrences_with_closed_static_route": 3,
                           "proposed_repair_centers_checked_not_applied": 13},
        "checks": ["artifact SHA-256 and extent", "fixed baseline path/blob, SHA-256 and extent",
                   "strict worktree equality for actual data/evidence/Python-helper inputs",
                   "original BIN/Table/BoundMap identities", "selected BND header/layer/extent",
                   "all authored centers and four-neighbor connectivity", "bounded feature samples and route witnesses",
                   "native point spans and VA/raw mapping", "concrete coordinate-remediation geometry",
                   "MEF capability/consumer/status boundaries"],
        "game_lua_server_executed": False,
        "originals_or_existing_scenarios_modified": False,
        "formal_status_changed": False,
        "full_original_member_exported": False
    }
    payload = json.dumps(receipt, ensure_ascii=False, indent=2, sort_keys=True) + "\n"
    if args.write_receipt:
        (HERE / "verification-result.json").write_text(payload, encoding="utf-8")
    print(payload, end="")


if __name__ == "__main__":
    main()
