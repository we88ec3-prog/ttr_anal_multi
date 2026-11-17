#!/usr/bin/env python3
"""Reproduce the bounded Server-content comparison from pinned Git blobs.

This reads published JSON and schemas. It does not execute Server code, Lua,
Client code, or commands taken from those files. --write only writes the two
fixed derived JSON files next to this program.
"""
from pathlib import Path
import argparse
import hashlib
import json
import subprocess
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent


def require(value, message):
    if not value:
        raise ValueError(message)


def digest(raw):
    return hashlib.sha256(raw).hexdigest()


def encode(value):
    return (json.dumps(value, ensure_ascii=False, indent=2) + "\n").encode()


def load_sources(repo):
    manifest = json.loads((HERE / "source-manifest.json").read_text())
    loaded = {}
    for row in manifest["git_sources"]:
        commit = row["commit"]
        blob = subprocess.check_output(
            ["git", "rev-parse", f"{commit}:{row['path']}"], cwd=repo
        ).decode().strip()
        require(blob == row["git_blob"], "Source blob mismatch: " + row["path"])
        raw = subprocess.check_output(["git", "cat-file", "blob", blob], cwd=repo)
        require(len(raw) == row["bytes"] and digest(raw) == row["sha256"],
                "Source bytes mismatch: " + row["path"])
        loaded[row["id"]] = json.loads(raw)
    return manifest, loaded


def build_context(manifest, sources):
    story = sources["story"]
    external = sources["external"]
    schema = sources["schema"]
    requirements = sources["requirements"]
    quests = [q for q in story["quests"] if q["quest"] == 119]
    require(len(quests) == 1, "Exactly one Q119 in pinned story candidate")
    quest = quests[0]
    definitions = [d for d in external["definitions"] if d["id"] == "story-quest-119"]
    require(len(definitions) == 1, "Exactly one external Q119 definition")
    definition = definitions[0]
    require(external["nativeMef"] is False, "External content is NOT_NATIVE_MEF")
    require(len(quest["scenario"]["nodes"]) == len(definition["nodes"]) == 4,
            "Four nodes in the selected source pair")
    story_pin = next(r for r in manifest["git_sources"] if r["id"] == "story")
    require(any(s["sha256"] == story_pin["sha256"] for s in definition["sources"]),
            "External definition must pin the exact story source")
    nodes = []
    for ordinal, (a, b) in enumerate(zip(quest["scenario"]["nodes"], definition["nodes"]), 1):
        require(b["node"] == ordinal and a["map"] == b["map"], "Node order and map identity")
        require(a["encounterModels"] == [r["model"] for r in b["encounters"]],
                "The external file retains the selected finite encounter order")
        nodes.append({
            "server_node": b["node"], "original_chart_source_node": a["sourceNode"],
            "map_id": a["map"], "server_candidate_cluster": a["selectedCluster"],
            "server_candidate_encounter_models": a["encounterModels"],
            "enter_scenes": a["enterScenes"], "clear_scenes": a["clearScenes"],
            "external_portal_pre_registered_closed": b["portal"]["preRegisterClosed"],
            "scene_phase_authority": "EXPLICIT_SERVER_CANDIDATE_POLICY_NOT_NATIVE_TRIGGER_ORDER",
            "coordinates_reexported": False,
        })
    require(nodes[-1]["enter_scenes"] == [3] and nodes[-1]["clear_scenes"] == [4],
            "Q119/3 entry and Q119/4 clear must remain distinct")
    require(nodes[-1]["server_node"] == 4 and nodes[-1]["original_chart_source_node"] == 1,
            "Server ordinal is not the original Chart sourceNode")
    require(quest["returnScenes"] == [5], "Q119/5 return scene")
    levels = {"root": schema, **{k: schema["$defs"][k] for k in ["definition", "node", "rule"]}}
    require(all(v.get("additionalProperties") is False for v in levels.values()),
            "Pinned schema rejects unannounced fields at all inspected levels")
    rule = schema["$defs"]["rule"]["properties"]
    require(rule["event"]["enum"] == ["Entry", "GroupCleared", "InteractZ"], "Rule event set")
    require(rule["action"]["enum"] == ["SpawnGroup", "UnlockPortal", "NextNode", "Result"],
            "Rule action set: no new PlayScene or Lua command is implied")
    req_rows = requirements if isinstance(requirements, list) else requirements.get("requirements", requirements.get("items", []))
    reqs = [r for r in req_rows if r.get("id") in {"REQ-0019", "REQ-0021"}]
    require(len(reqs) == 2 and all(r["status"] == "CANDIDATE" for r in reqs),
            "Existing requirement identity and status")
    context = {
        "schema": "MEF_P0_SERVER_CONTEXT_REVIEW_V1_NOT_NATIVE_MEF",
        "governance_commit": manifest["governance_commit"],
        "research_only": True, "server_code_executed": False,
        "server_schema_modified": False, "deployment_ready": False,
        "story_identity": {"schema": story["schema"], "version": story["version"],
                           "sha256": story_pin["sha256"], "source_kind": story["sourceKind"]},
        "selected_quest": {"quest_id": 119, "field_id": quest["scenario"]["field"],
                           "case_id": quest["scenario"]["case"], "intro_scenes": quest["introScenes"],
                           "return_scenes": quest["returnScenes"], "nodes": nodes},
        "original_source_limits_preserved": story["limits"],
        "schema_boundary": {
            "schema_id": schema["$id"],
            "additional_properties_allowed": {k: v["additionalProperties"] for k, v in levels.items()},
            "rule_events": rule["event"]["enum"], "rule_actions": rule["action"]["enum"],
            "scene_selection_in_external_node_schema": False,
            "p0_review_is_existing_schema_input": False,
            "new_fields_require_versioned_server_integration": True,
        },
        "requirements": [{k: r[k] for k in ["id", "status", "client_version", "spec_ids", "gap_ids"]}
                         for r in reqs],
        "identity_non_equivalences": [
            "Q actor slot != world EntityId != Server encounter index",
            "Q model1086 presentation != Server candidate model1022 boss",
            "Original Chart sourceNode1 != Server ordinal node1; the selected map635 is ordinal4",
            "Server candidate selectedCluster4 != all original Cluster variants or runtime-selected Cluster19",
            "Q119/3 enter-scene candidate != Q119/4 clear scene or Q119/5 return scene",
            "External scenario SHA != story SHA != Event member SHA != effective runtime resource identity",
        ],
    }
    return context


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--repo", required=True, type=Path)
    parser.add_argument("--write", action="store_true", help="Write the fixed derived context and receipt files")
    args = parser.parse_args()
    manifest, sources = load_sources(args.repo.resolve())
    context = build_context(manifest, sources)
    raw = encode(context)
    if args.write:
        (HERE / "server-context.json").write_bytes(raw)
    else:
        require((HERE / "server-context.json").read_bytes() == raw, "Recomputed Server context differs")
    result = {
        "schema": "MEF_P0_SERVER_CONTEXT_VERIFICATION_V1", "status": "PASS",
        "pinned_git_sources": len(manifest["git_sources"]), "q119_nodes": 4,
        "compared_schema_levels": 4, "existing_requirements": 2,
        "context_sha256": digest(raw), "server_executed": False, "client_executed": False,
        "lua_executed": False, "deployment_ready": False, "formal_status_changed": False,
    }
    if args.write:
        (HERE / "verification-result.json").write_bytes(encode(result))
    print(encode(result).decode(), end="")


if __name__ == "__main__":
    main()
