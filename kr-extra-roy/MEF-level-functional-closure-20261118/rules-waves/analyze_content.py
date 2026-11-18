#!/usr/bin/env python3
"""Static authored-content analysis; never executes MEF, Client, Lua or Server.

The dependency pass checks structural possibility under named assumptions. It is
not a replacement for the external Server typed loader, BND geometry, or play.
"""
from __future__ import annotations

import argparse
from collections import Counter, defaultdict, deque
import hashlib
import json
from pathlib import Path
import subprocess

from jsonschema import Draft202012Validator

BASE = "09799b117f01e577be56dee3e909e1cde25b855f"
SCHEMA_PATH = "design/scenario-content/local-scenario-definition.schema.json"


def source(repo, path):
    data = subprocess.check_output(["git", "show", BASE + ":" + path], cwd=repo)
    if (repo / path).read_bytes() != data:
        raise ValueError("worktree differs from pinned source: " + path)
    return data


def all_paths(repo):
    names = subprocess.check_output(["git", "ls-tree", "-r", "--name-only", BASE,
                                     "design/scenario-content"], cwd=repo, text=True).splitlines()
    return sorted(p for p in names if p.endswith(".scenario.json"))


def flags_of(obj):
    return set((obj or {}).get("requiredFlags", []))


def analyze_definition(definition, file_path):
    issues = []
    nodes = definition["nodes"]
    by_id = {n["node"]: n for n in nodes}

    def issue(code, node, detail):
        issues.append({"code": code, "node": node, "detail": detail})

    if len(by_id) != len(nodes):
        issue("DUPLICATE_NODE", None, "node identities must be unique")
    groups = [n["encounterGroup"] for n in nodes]
    if len(groups) != len(set(groups)):
        issue("DUPLICATE_ENCOUNTER_GROUP", None, groups)
    graph = defaultdict(list)
    edges = {}
    producer = {}
    for n in nodes:
        nid = n["node"]
        kinds = Counter(r["event"] for r in n["rules"])
        if kinds != Counter({"Entry": 1, "GroupCleared": 1, "InteractZ": 1}):
            issue("RULE_EVENT_IDENTITIES", nid, dict(kinds))
        exit_rule = next((r for r in n["rules"] if r["event"] == "InteractZ"), {})
        exits = [{"portal": n["portal"], "action": exit_rule.get("action"),
                  "targetNode": exit_rule.get("targetNode"), "default": True}]
        exits += [dict(x, default=False) for x in n.get("alternativeExits", [])]
        edges[nid] = exits
        for e in exits:
            if e["action"] == "NextNode":
                target = e.get("targetNode")
                graph[nid].append(target)
                if target not in by_id:
                    issue("MISSING_TARGET", nid, target)
        cat0 = [e["portal"]["key"] for e in exits]
        interactions = [s["interaction"] for s in n.get("signals", []) if s["event"] == "CheckpointInteracted"]
        cat0 += [i["markerKey"] for i in interactions if i.get("markerKey") is not None]
        cat0 += [b["marker"]["key"] for b in n.get("barriers") or [] if b.get("marker")]
        if len(cat0) != len(set(cat0)):
            issue("DUPLICATE_CATEGORY0_POINT", nid, cat0)
        cat1 = [i["key"] for i in interactions]
        if len(cat1) > 8 or len(cat1) != len(set(cat1)):
            issue("INTERACTION_KEY_OR_COUNT", nid, cat1)
        wave_rows = n.get("reinforcements", []) + n.get("timedReinforcements", [])
        ids = [w["id"] for w in wave_rows]
        if len(ids) != len(set(ids)):
            issue("DUPLICATE_WAVE", nid, ids)
        total_actors = len(n["encounters"]) + sum(len(w["encounters"]) for w in wave_rows)
        if len(wave_rows) > 31 or total_actors > 255:
            issue("WAVE_OR_ACTOR_CAPACITY", nid, {"waves": len(wave_rows), "actors": total_actors})
        for s in n.get("signals", []):
            if s["flag"] in producer:
                issue("DUPLICATE_FLAG", nid, s["flag"])
            producer[s["flag"]] = (nid, s)
            if s["event"] in ("WaveCleared", "WaveHealthReached") and s.get("waveId") not in [None] + ids:
                issue("MISSING_SIGNAL_WAVE", nid, s.get("waveId"))
    if len(producer) > 64:
        issue("FLAG_CAPACITY", None, len(producer))
    entry = definition["entryNode"]
    if entry not in by_id:
        issue("MISSING_ENTRY_NODE", None, entry)
    reachable = set()
    stack = [entry]
    while stack:
        nid = stack.pop()
        if nid in reachable or nid not in by_id:
            continue
        reachable.add(nid)
        stack.extend(graph[nid])
    if reachable != set(by_id):
        issue("UNREACHABLE_NODES", None, sorted(set(by_id) - reachable))
    incoming_edges = defaultdict(list)
    indegree = {nid: 0 for nid in by_id}
    for nid, outs in edges.items():
        for e in outs:
            if e["action"] == "NextNode" and e["targetNode"] in by_id:
                target = e["targetNode"]
                indegree[target] += 1
                incoming_edges[target].append((nid, e))
    queue = deque(sorted(nid for nid, degree in indegree.items() if degree == 0))
    order = []
    while queue:
        nid = queue.popleft()
        order.append(nid)
        for target in graph[nid]:
            if target in indegree:
                indegree[target] -= 1
                if indegree[target] == 0:
                    queue.append(target)
    if len(order) != len(by_id):
        issue("CYCLIC_GRAPH", None, sorted(set(by_id) - set(order)))

    outgoing_guarantees = {}
    node_results = []

    def antecedents(flags):
        result = set(flags)
        old_size = -1
        while len(result) != old_size:
            old_size = len(result)
            for flag in list(result):
                record = producer.get(flag)
                if record and record[1]["event"] == "CheckpointInteracted":
                    result |= flags_of(record[1]["interaction"])
        return result

    for nid in order:
        n = by_id[nid]
        parent_sets = [outgoing_guarantees[(parent, e["portal"]["key"])]
                       for parent, e in incoming_edges[nid]]
        must = set.intersection(*parent_sets) if parent_sets else set()
        signals = n.get("signals", [])
        seq = n.get("reinforcements", [])
        timed = n.get("timedReinforcements", [])
        possible = set(must)
        spawned = {None} if n["encounters"] else set()
        rounds = []

        def signal_possible(s, whole_clear):
            event = s["event"]
            if event in ("GroupCleared", "ClearDelayElapsed"):
                return whole_clear
            if event in ("RegionEntered", "RegionHeld", "NodeDelayElapsed"):
                return True
            if event in ("WaveCleared", "WaveHealthReached"):
                return s.get("waveId") in spawned
            if event == "CheckpointInteracted":
                i = s["interaction"]
                return (whole_clear or not i.get("requireGroupCleared", False)) and flags_of(i) <= possible
            if event == "BossDefeated":
                boss = n.get("requiredBoss")
                if not boss:
                    return False
                return boss.get("waveId") in spawned
            return False

        # This is existence of a feasible dependency schedule, not a simulated Poll.
        while True:
            before_flags, before_waves = set(possible), set(spawned)
            for s in signals:
                if signal_possible(s, False):
                    possible.add(s["flag"])
            for w in timed:
                if flags_of(w) <= possible:
                    spawned.add(w["id"])
            for index, w in enumerate(seq):
                if all(previous["id"] in spawned for previous in seq[:index]) and flags_of(w) <= possible:
                    spawned.add(w["id"])
            if before_flags == possible and before_waves == spawned:
                break
            rounds.append({"new_flags": sorted(possible - before_flags),
                           "new_waves": sorted(x for x in spawned - before_waves if x is not None)})
        waiting = [w["id"] for w in seq + timed if w["id"] not in spawned]
        if waiting:
            issue("PRE_CLEAR_WAVE_DEPENDENCY_BLOCK", nid, waiting)
        preclear = set(possible)
        if not waiting:
            while True:
                before = set(possible)
                for s in signals:
                    if signal_possible(s, True):
                        possible.add(s["flag"])
                if possible == before:
                    break
        for s in signals:
            if s["flag"] not in possible:
                issue("SIGNAL_DEPENDENCY_UNREACHABLE", nid, s["flag"])
        required_by = []
        for e in edges[nid]:
            required_by.append(("exit:" + str(e["portal"]["key"]), flags_of(e["portal"].get("condition"))))
        for w in seq + timed:
            required_by.append(("wave:" + w["id"], flags_of(w)))
        for s in signals:
            if s["event"] == "CheckpointInteracted":
                required_by.append(("interaction:" + str(s["interaction"]["key"]), flags_of(s["interaction"])))
        for b in n.get("barriers") or []:
            required_by.append(("barrier", {b["opensWithFlag"]}))
        for h in n.get("hazards") or []:
            if h.get("disabledByFlag"):
                required_by.append(("hazard:" + h["id"], {h["disabledByFlag"]}))
        for consumer, needed in required_by:
            for f in needed:
                if f not in producer:
                    issue("UNDEFINED_FLAG", nid, {"consumer": consumer, "flag": f})
                elif f not in possible:
                    issue("FLAG_NOT_AVAILABLE_ON_ALL_ENTRY_PATHS", nid, {"consumer": consumer, "flag": f})
        guaranteed_clear = {s["flag"] for s in signals if s["event"] == "GroupCleared"}
        for e in edges[nid]:
            outgoing_guarantees[(nid, e["portal"]["key"])] = antecedents(must | guaranteed_clear | flags_of(e["portal"].get("condition")))
        node_results.append({"node": nid, "map": n["map"], "guaranteed_flags_on_entry": sorted(must),
                             "pre_clear_possible_flags": sorted(preclear), "post_clear_possible_flags": sorted(possible),
                             "additional_waves_possible": sorted(x for x in spawned if x is not None),
                             "blocked_waves": waiting, "dependency_rounds": rounds,
                             "flag_consumers": [{"consumer": consumer, "required_flags": sorted(needed)}
                                                for consumer, needed in required_by if needed],
                             "reverse_flag_index": {flag: sorted(consumer for consumer, needed in required_by if flag in needed)
                                                    for flag in sorted(set().union(*(needed for _, needed in required_by)))},
                             "exits": [{"key": e["portal"]["key"], "action": e["action"], "target": e.get("targetNode"),
                                        "required_flags": sorted(flags_of(e["portal"].get("condition"))),
                                        "guaranteed_after_exit": sorted(outgoing_guarantees[(nid, e["portal"]["key"])])} for e in edges[nid]]})
    return {"file": file_path, "definition": definition["id"], "entry": entry,
            "node_count": len(nodes), "topological_order": order, "reachable_nodes": sorted(reachable),
            "all_nodes_reachable": reachable == set(by_id), "acyclic": len(order) == len(by_id),
            "result_exit_count": sum(e["action"] == "Result" for outs in edges.values() for e in outs),
            "unique_flag_count": len(producer), "nodes": node_results, "issues": issues}


def analyze(repo):
    schema_data = source(repo, SCHEMA_PATH)
    schema = json.loads(schema_data)
    Draft202012Validator.check_schema(schema)
    validator = Draft202012Validator(schema)
    counts = Counter()
    coverage = Counter()
    maxima = Counter()
    signals = Counter()
    event_files = defaultdict(set)
    event_definitions = defaultdict(set)
    files = []
    analyses = []
    schema_errors = []
    for path in all_paths(repo):
        raw = source(repo, path)
        obj = json.loads(raw)
        for error in validator.iter_errors(obj):
            schema_errors.append({"file": path, "path": list(error.path), "message": error.message})
        file_counts = Counter({"definitions": len(obj["definitions"])})
        definition_ids = [d["id"] for d in obj["definitions"]]
        if len(definition_ids) != len(set(definition_ids)):
            schema_errors.append({"file": path, "path": ["definitions"], "message": "duplicate definition identity"})
        for d in obj["definitions"]:
            analyses.append(analyze_definition(d, path))
            maxima["nodes_per_definition"] = max(maxima["nodes_per_definition"], len(d["nodes"]))
            for n in d["nodes"]:
                file_counts["nodes"] += 1
                file_counts["initial_actors"] += len(n["encounters"])
                file_counts["initial_empty_nodes"] += not n["encounters"]
                for key in ["reinforcements", "timedReinforcements", "alternativeExits", "signals", "barriers", "hazards"]:
                    file_counts[key] += len(n.get(key) or [])
                for w in n.get("reinforcements", []) + n.get("timedReinforcements", []):
                    file_counts["additional_actors"] += len(w["encounters"])
                    file_counts["flag_gated_waves"] += bool(w.get("requiredFlags"))
                    file_counts["region_gated_waves"] += bool(w.get("activationRegion"))
                waves = n.get("reinforcements", []) + n.get("timedReinforcements", [])
                maxima["additional_waves_per_node"] = max(maxima["additional_waves_per_node"], len(waves))
                maxima["actors_per_node"] = max(maxima["actors_per_node"], len(n["encounters"]) + sum(len(w["encounters"]) for w in waves))
                maxima["exits_per_node"] = max(maxima["exits_per_node"], 1 + len(n.get("alternativeExits", [])))
                for rule in n["rules"]:
                    coverage["default_action_" + rule["action"]] += 1
                coverage["required_boss_nodes"] += bool(n.get("requiredBoss"))
                coverage["required_boss_named_wave_nodes"] += bool((n.get("requiredBoss") or {}).get("waveId"))
                coverage["default_exit_conditions"] += bool(n["portal"].get("condition"))
                coverage["pre_registered_default_exits"] += n["portal"].get("preRegisterClosed", False)
                coverage["branch_nodes"] += bool(n.get("alternativeExits"))
                coverage["signal_nodes"] += bool(n.get("signals"))
                for e in n.get("alternativeExits", []):
                    coverage["alternative_action_" + e["action"]] += 1
                    coverage["alternative_exit_conditions"] += bool(e["portal"].get("condition"))
                for s in n.get("signals", []):
                    signals[s["event"]] += 1
                    event_files[s["event"]].add(path)
                    event_definitions[s["event"]].add(path + "#" + d["id"])
                    if s["event"] == "CheckpointInteracted":
                        coverage["manual_pre_clear"] += not s["interaction"].get("requireGroupCleared", False)
                        coverage["manual_requires_group_clear"] += s["interaction"].get("requireGroupCleared", False)
                        coverage["manual_with_flag_prerequisites"] += bool(s["interaction"].get("requiredFlags"))
        counts.update(file_counts)
        files.append({"path": path, "bytes": len(raw), "sha256": hashlib.sha256(raw).hexdigest(),
                      "definition_ids": definition_ids, "counts": dict(sorted(file_counts.items()))})
    issues = [{"file": row["file"], "definition": row["definition"], **issue}
              for row in analyses for issue in row["issues"]]
    supported = schema["$defs"]["signal"]["properties"]["event"]["enum"]
    return {"schema": "MEF_LEVEL_RULES_STATIC_CONTENT_AUDIT_V1", "baseline": BASE,
            "source_schema": {"path": SCHEMA_PATH, "sha256": hashlib.sha256(schema_data).hexdigest()},
            "scope": "All committed design/scenario-content/*.scenario.json at baseline; versions/candidates counted as occurrences, not unique playable stages.",
            "counts": {"files": len(files), **dict(sorted(counts.items()))},
            "feature_coverage": dict(sorted(coverage.items())),
            "observed_maxima": dict(sorted(maxima.items())),
            "signal_coverage": [{"event": e, "occurrences": signals[e], "files": sorted(event_files[e]),
                                 "definition_occurrences": len(event_definitions[e])} for e in supported],
            "schema_errors": schema_errors, "structural_dependency_issues": issues,
            "assumptions": ["This is a static existence/availability analysis, not a runtime or exact Server-loader implementation.",
                            "Finite timers may progress, configured combatants can eventually be defeated, and referenced regions/interactions are geometrically reachable; these assumptions are not verified here.",
                            "Incoming guaranteed flags use intersection; exit requirements and their manual-interaction prerequisites are propagated, together with documented GroupCleared flags.",
                            "Only declared fixed graph/rules are checked; no random routes, inventory predicates, loop semantics, or unknown callbacks are invented."],
            "files": files, "definitions": analyses,
            "target_executed": False, "server_executed": False, "lua_executed": False,
            "deployment_or_play_verification": False}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--repo", type=Path, required=True)
    parser.add_argument("--output", type=Path)
    args = parser.parse_args()
    result = analyze(args.repo.resolve())
    encoded = json.dumps(result, ensure_ascii=False, indent=2) + "\n"
    if args.output:
        args.output.write_text(encoded, encoding="utf-8")
        print(json.dumps({"counts": result["counts"], "schema_errors": result["schema_errors"],
                          "structural_dependency_issues": result["structural_dependency_issues"]}, ensure_ascii=False, indent=2))
    else:
        print(encoded, end="")
