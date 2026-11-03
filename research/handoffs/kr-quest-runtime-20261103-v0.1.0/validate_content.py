#!/usr/bin/env python3
"""Validate this candidate content package locally; never run a game or fetch URLs.

Usage: python validate_content.py [--root DIRECTORY] [--strict-missing]
The default report is validation-report.json beside this script. Exit 0 means
structurally valid content with no attempted unsafe activation. Draft activation
blockers remain visible and do not turn a correctly blocked draft into a failure.
Missing optional integration files are DEFERRED unless --strict-missing is used.
"""

from __future__ import annotations

import argparse
import csv
import hashlib
import json
import re
import sys
from collections import Counter, defaultdict, deque
from datetime import datetime, timezone
from pathlib import Path

from jsonschema import Draft202012Validator
from jsonschema.exceptions import best_match
from referencing import Registry, Resource
from referencing.exceptions import NoSuchResource


VERSION = "0.1.0"
ENABLED = "ENABLED_AFTER_ACCEPTANCE"
SHA256 = re.compile(r"^[0-9a-f]{64}$")
COLLECTIONS = (
    ("quest-definitions.json", "definitions", "quest-definition.schema.json", "quest"),
    ("quest-flows.json", "flows", "quest-flow.schema.json", "flow"),
    ("scenario-entries.json", "entries", "scenario-entry.schema.json", "scenario"),
)
PRIMARY_CSVS = (
    "quest-catalog.csv", "quest-nodes.csv", "quest-objectives.csv",
    "quest-rewards.csv", "quest-wire-map.csv", "migration-matrix.csv",
    "exceptions.csv", "quest-scenes.csv", "quest-scenario-entries.csv",
    "id-dictionary.csv", "id-values.csv", "id-relations.csv", "quest-npc-scenes.csv",
)
WIRE_FIELDS = {
    "wire_adapter_id", "adapter_id", "publication_adapter_id",
    "intent_contract", "presentation_contract", "receipt_contract",
    "result_contract", "return_contract", "result_contract_ref", "return_contract_ref",
}
REQUIRED_NODE_BINDINGS = {
    "wait_npc_intent": ("intent_contract",),
    "show_npc_dialog": ("presentation_contract",),
    "accept_quest": ("policy_ref",),
    "close_npc_dialog": ("adapter_id",),
    "play_scene": ("schedule_policy_ref",),
    "wait_scene_receipt": ("receipt_contract",),
    "await_ui_cleanup": ("barrier_contract",),
    "offer_single_formation": ("selection_policy_ref",),
    "initialize_world": ("layout_ref",),
    "await_encounter_outcome": ("completion_policy_ref",),
    "open_manual_portal": ("portal_binding_ref",),
    "await_portal_intent": ("portal_binding_ref",),
    "show_result": ("result_contract",),
    "await_return_intent": ("return_contract",),
    "return_town": ("layout_ref",),
    "evaluate_objectives": ("completion_rule_ref",),
    "await_turnin_intent": ("intent_contract",),
    "settle_quest": ("reward_plan_ref",),
    "publish_quest_projection": ("projection_contract",),
    "wait_domain_event": ("event_policy_ref",),
    "branch": ("branch_policy_ref",),
    "tutorial_hook": ("contract_ref",),
}


def pointer(parts):
    return "/" + "/".join(str(x).replace("~", "~0").replace("/", "~1") for x in parts)


def walk(value, path=()):
    if isinstance(value, dict):
        yield path, value
        for key, child in value.items():
            yield from walk(child, path + (key,))
    elif isinstance(value, list):
        for index, child in enumerate(value):
            yield from walk(child, path + (index,))


def typed_value(value, domain):
    if isinstance(value, dict) and value.get("domain") == domain:
        result = value.get("value")
        if isinstance(result, int) and not isinstance(result, bool):
            return result
    return None


def nonempty(value):
    return value is not None and value != ""


def reachable(start, adjacency, forbidden=frozenset()):
    seen = set()
    queue = deque([start])
    while queue:
        node = queue.popleft()
        if node in seen or node in forbidden:
            continue
        seen.add(node)
        queue.extend(adjacency.get(node, ()))
    return seen


def deny_remote(uri):
    raise NoSuchResource(ref=uri)


class Validation:
    def __init__(self, root, strict_missing=False):
        self.root = root
        self.strict_missing = strict_missing
        self.errors = []
        self.warnings = []
        self.deferred = []
        self.checks = Counter()
        self.inputs = {}
        self.schemas = {}
        self.registry = Registry(retrieve=deny_remote)
        self.definitions = {}
        self.flows = {}
        self.scenarios = {}
        self.scene_rows = {}
        self.declared_scenes = set()
        self.wire = None
        self.activation = {}
        self.source_references = []

    def error(self, code, file, path, message):
        self.errors.append({"code": code, "file": file, "path": path, "message": message})

    def warning(self, code, file, path, message):
        self.warnings.append({"code": code, "file": file, "path": path, "message": message})

    def missing(self, file, purpose, required=False):
        if required or self.strict_missing:
            self.error("MISSING_FILE", file, "", purpose)
        else:
            self.deferred.append({"code": "MISSING_INTEGRATION_FILE", "file": file, "purpose": purpose})

    def read_json(self, name, required=False):
        path = self.root / name
        if not path.is_file():
            self.missing(name, "Required for the corresponding local static check.", required)
            return None
        try:
            raw = path.read_bytes()
            self.inputs[name] = {"sha256": hashlib.sha256(raw).hexdigest(), "bytes": len(raw)}
            return json.loads(raw)
        except (OSError, ValueError) as exc:
            self.error("JSON_READ", name, "", str(exc))
            return None

    def load_schemas(self):
        for _, _, filename, _ in COLLECTIONS:
            schema = self.read_json(filename, required=True)
            if schema is None:
                continue
            try:
                Draft202012Validator.check_schema(schema)
                self.schemas[filename] = schema
                self.registry = self.registry.with_resource(schema["$id"], Resource.from_contents(schema))
                self.checks["schemas_checked"] += 1
            except Exception as exc:
                self.error("INVALID_SCHEMA", filename, "", str(exc)[:600])

    def validate_schema(self, value, schema_name, filename, path=""):
        if schema_name not in self.schemas:
            return
        validator = Draft202012Validator(self.schemas[schema_name], registry=self.registry)
        try:
            for err in validator.iter_errors(value):
                detail = best_match(err.context) if err.context else err
                detail = detail or err
                self.error("SCHEMA", filename, path + pointer(detail.absolute_path), str(detail.message)[:600])
            self.checks["schema_instances_checked"] += 1
        except Exception as exc:
            self.error("SCHEMA_RESOLUTION", filename, path, "Local-only schema resolution failed: " + str(exc)[:500])

    def check_sources(self, value, filename, base=()):
        # Exact evidence keys only: supporting source arrays are not a scalar SHA.
        for path, record in walk(value, base):
            if "source_ref" not in record and "source_sha" not in record:
                continue
            self.checks["evidence_records_checked"] += 1
            for key in ("source_ref", "source_sha", "evidence_kind", "unknowns"):
                if key not in record:
                    self.error("EVIDENCE_FIELD", filename, pointer(path), "Missing evidence field: " + key)
            if not isinstance(record.get("source_ref"), str) or not record.get("source_ref", "").strip():
                self.error("SOURCE_REF", filename, pointer(path + ("source_ref",)), "A source reference must be a nonempty string.")
            if not isinstance(record.get("source_sha"), str) or not SHA256.fullmatch(record.get("source_sha", "")):
                self.error("SOURCE_SHA", filename, pointer(path + ("source_sha",)), "Primary source_sha must be one lowercase SHA-256 (64 hex characters).")
            elif isinstance(record.get("source_ref"), str):
                self.source_references.append((record["source_ref"], record["source_sha"], filename, pointer(path)))
            if not isinstance(record.get("evidence_kind"), str) or not record.get("evidence_kind", "").strip():
                self.error("EVIDENCE_KIND", filename, pointer(path), "evidence_kind must be nonempty.")
            if not isinstance(record.get("unknowns"), list):
                self.error("UNKNOWNS", filename, pointer(path + ("unknowns",)), "JSON evidence unknowns must be an array; [] explicitly means no listed unknowns.")

    def entity_key(self, kind, value):
        if kind == "quest":
            return typed_value(value.get("id"), "quest")
        return value.get("flow_id" if kind == "flow" else "entry_id")

    def load_collections(self):
        targets = {"quest": self.definitions, "flow": self.flows, "scenario": self.scenarios}
        for filename, collection_key, schema_name, kind in COLLECTIONS:
            collection = self.read_json(filename, required=True)
            if not isinstance(collection, dict):
                continue
            rows = collection.get(collection_key)
            if not isinstance(rows, list):
                self.error("COLLECTION_SHAPE", filename, "/" + collection_key, "Expected a JSON array.")
                continue
            if collection.get("schema_version") != VERSION or collection.get("classification") != "SERVER_CANDIDATE_NOT_NATIVE_MEF":
                self.error("COLLECTION_VERSION", filename, "", "Collection must declare version 0.1.0 and SERVER_CANDIDATE_NOT_NATIVE_MEF.")
            for index, row in enumerate(rows):
                where = pointer((collection_key, index))
                self.validate_schema(row, schema_name, filename, where)
                self.check_sources(row, filename, (collection_key, index))
                if not isinstance(row, dict):
                    continue
                key = self.entity_key(kind, row)
                if key is None:
                    self.error("MISSING_ID", filename, where, "Entity identifier is absent or incorrectly typed.")
                elif key in targets[kind]:
                    self.error("DUPLICATE_ID", filename, where, f"Duplicate {kind} identifier: {key!r}")
                else:
                    targets[kind][key] = row
            self.checks[kind + "_records_checked"] = len(rows)

    def check_examples(self):
        examples = self.root / "examples"
        if not examples.is_dir():
            self.missing("examples", "Examples must be schema checked and equal their collection entries.", True)
            return
        for path in sorted(examples.glob("*.json")):
            name = path.relative_to(self.root).as_posix()
            value = self.read_json(name, required=True)
            if not isinstance(value, dict):
                continue
            if "flow_id" in value:
                schema, kind, target = "quest-flow.schema.json", "flow", self.flows
            elif "entry_id" in value:
                schema, kind, target = "scenario-entry.schema.json", "scenario", self.scenarios
            elif "id" in value:
                schema, kind, target = "quest-definition.schema.json", "quest", self.definitions
            else:
                self.error("EXAMPLE_KIND", name, "", "Cannot select one of the three candidate schemas.")
                continue
            self.validate_schema(value, schema, name)
            self.check_sources(value, name)
            key = self.entity_key(kind, value)
            if key not in target:
                self.error("EXAMPLE_FK", name, "", "Example has no corresponding collection entry.")
            elif value != target[key]:
                self.error("EXAMPLE_DRIFT", name, "", "Example differs from its canonical collection entry; regenerate both together.")
            self.checks["examples_checked"] += 1

    def unique_values(self, values, filename, path, label):
        counts = Counter(values)
        for value, count in counts.items():
            if count > 1:
                self.error("DUPLICATE_ID", filename, path, f"Duplicate {label}: {value!r} ({count} occurrences).")

    def load_scene_evidence(self):
        data = self.read_json("evidence/scene-facts.json")
        if isinstance(data, dict):
            for index, scene in enumerate(data.get("scenes", [])):
                key = (scene.get("quest_id"), scene.get("scene_id"))
                if key in self.scene_rows:
                    self.error("DUPLICATE_SCENE_KEY", "evidence/scene-facts.json", pointer(("scenes", index)), str(key))
                self.scene_rows[key] = scene
        for qid, definition in self.definitions.items():
            seen = set()
            for chapter in definition.get("source_data", {}).get("chapters", []):
                for scene in chapter.get("source_order", []):
                    key = (typed_value(scene.get("quest"), "quest"), scene.get("scene_index"))
                    if key[0] != qid:
                        self.error("SCENE_QUEST_DOMAIN", "quest-definitions.json", f"quest:{qid}", f"Chapter scene {key} belongs to a different quest.")
                    if key in seen:
                        self.error("DUPLICATE_SCENE_KEY", "quest-definitions.json", f"quest:{qid}", f"Repeated chapter scene key {key}.")
                    seen.add(key)
                    self.declared_scenes.add(key)
                    if self.scene_rows and key not in self.scene_rows:
                        self.error("SCENE_SOURCE_FK", "quest-definitions.json", f"quest:{qid}", f"No Event scene evidence for {key}.")
                    elif key in self.scene_rows:
                        raw = self.scene_rows[key]
                        if (raw.get("chapter_id") != typed_value(chapter.get("chapter"), "chapter") or
                                raw.get("chapter_town_id") != typed_value(chapter.get("chapter_town"), "town")):
                            self.error("CHAPTER_SOURCE_MISMATCH", "quest-definitions.json", f"quest:{qid}", f"Chapter/town binding differs from scene evidence for {key}.")

    def check_foreign_keys(self):
        for qid, definition in self.definitions.items():
            filename, at = "quest-definitions.json", f"quest:{qid}"
            flow_ref = definition.get("flow_ref")
            if flow_ref is not None:
                if flow_ref not in self.flows:
                    self.error("FLOW_FK", filename, at, f"Missing flow {flow_ref!r}.")
                elif qid not in [typed_value(x, "quest") for x in self.flows[flow_ref].get("quest_refs", [])]:
                    self.error("FLOW_QUEST_FK", filename, at, "Referenced flow does not own this quest.")
            scenario_ref = definition.get("scenario_entry_ref")
            if scenario_ref is not None:
                if scenario_ref not in self.scenarios:
                    self.error("SCENARIO_FK", filename, at, f"Missing scenario entry {scenario_ref!r}.")
                elif typed_value(self.scenarios[scenario_ref].get("quest"), "quest") != qid:
                    self.error("SCENARIO_QUEST_FK", filename, at, "Scenario belongs to another quest.")
            self.unique_values([o.get("objective_key") for o in definition.get("objectives", [])], filename, at, "objective_key")
            self.unique_values([r.get("reward_key") for r in definition.get("rewards", [])], filename, at, "reward_key")
        for kind, entities, filename in (
                ("quest", self.definitions, "quest-definitions.json"),
                ("flow", self.flows, "quest-flows.json"),
                ("scenario", self.scenarios, "scenario-entries.json")):
            for identity, entity in entities.items():
                at = f"{kind}:{identity}"
                for path, record in walk(entity):
                    if record.get("domain") == "quest":
                        qid = typed_value(record, "quest")
                        if qid not in self.definitions:
                            self.error("QUEST_FK", filename, at + pointer(path), f"Unknown QuestId {qid!r}.")
                    if record.get("domain") == "scene":
                        key = (typed_value(record.get("quest"), "quest"), record.get("scene_index"))
                        if key not in self.declared_scenes:
                            self.error("SCENE_COMPOSITE_FK", filename, at + pointer(path), f"Unknown composite SceneKey {key}; numeric scene index alone is insufficient.")
                    reference = record.get("scenario_entry_ref")
                    if reference is not None and reference not in self.scenarios:
                        self.error("SCENARIO_FK", filename, at + pointer(path), f"Missing scenario entry {reference!r}.")

    def check_raw_fidelity(self):
        raw = self.read_json("evidence/quest-facts.json")
        if not isinstance(raw, dict):
            return
        facts = {row["quest_id"]: row for row in raw.get("quests", [])}
        for qid, definition in self.definitions.items():
            if qid not in facts:
                self.error("QUEST_SOURCE_FK", "quest-definitions.json", f"quest:{qid}", "Missing selected QuestInfo evidence row.")
                continue
            fact = facts[qid]
            attributes = fact.get("raw_attributes", {})
            actual = definition.get("source_data", {})
            differences = []
            if actual.get("raw_attributes") != attributes:
                differences.append("raw_attributes")
            for key in ("town", "field", "giver", "finisher"):
                expected = int(attributes[key]) if key in attributes else None
                domain = "npc" if key in ("giver", "finisher") else key
                if typed_value(actual.get(key), domain) != expected:
                    differences.append(key)
            for raw_key, normalized in (("type", "quest_type_raw"), ("subtype", "subtype_raw"), ("level", "level_raw")):
                expected = int(attributes[raw_key]) if raw_key in attributes else None
                if actual.get(normalized) != expected:
                    differences.append(normalized)
            demands = [int(row["id"]) for row in fact.get("demands", [])]
            if [typed_value(x, "quest") for x in actual.get("demand_ids", [])] != demands:
                differences.append("demand_ids")
            if actual.get("demand_operator_raw") != fact.get("demand_operator"):
                differences.append("demand_operator_raw")
            for source_key, target_key in (("contents", "contents_present"), ("rewards_etc", "reward_etc_present"), ("rewards_item", "reward_items_present"), ("quest_talk", "quest_talk_row_present")):
                if actual.get(target_key) != (fact.get(source_key) is not None):
                    differences.append(target_key)
            expected_rewards = [(int(r["type"]), int(r["value"])) for r in (fact.get("rewards_etc") or {}).get("rewards", [])]
            actual_rewards = [(typed_value(r.get("raw_type"), "quest_rewards_etc_type"), r.get("raw_value")) for r in definition.get("rewards", []) if r.get("raw_container") == "RewardsEtc"]
            if actual_rewards != expected_rewards:
                differences.append("RewardsEtc")
            if differences:
                self.error("RAW_FIDELITY", "quest-definitions.json", f"quest:{qid}", "Source literal/absence changed: " + ", ".join(differences))
            self.checks["raw_quest_rows_compared"] += 1

    def check_flow_graphs(self):
        for flow_id, flow in self.flows.items():
            filename, base = "quest-flows.json", f"flow:{flow_id}"
            nodes = flow.get("nodes", [])
            self.unique_values([n.get("node_id") for n in nodes], filename, base, "node_id")
            index = {n.get("node_id"): n for n in nodes}
            entry = flow.get("entry_node")
            if entry not in index:
                self.error("ENTRY_FK", filename, base, "entry_node is absent from nodes.")
                continue
            refs = [typed_value(q, "quest") for q in flow.get("quest_refs", [])]
            self.unique_values(refs, filename, base, "quest_ref")
            adjacency = {node_id: set() for node_id in index}
            edge_pairs = set()
            settles = defaultdict(set)
            for node_id, node in index.items():
                at = base + "/node:" + str(node_id)
                outgoing = node.get("next", [])
                for edge in outgoing:
                    target = edge.get("to")
                    if target not in index:
                        self.error("NEXT_FK", filename, at, f"Unknown next node {target!r}.")
                    else:
                        adjacency[node_id].add(target)
                        edge_pairs.add((node_id, target))
                self.unique_values([json.dumps(e, sort_keys=True) for e in outgoing], filename, at, "identical outgoing edge")
                for _, predicate in walk(node.get("preconditions")):
                    if predicate.get("name") == "flow_expected_node_and_authorized_scope" and predicate.get("args", {}).get("node") != node_id:
                        self.error("EXPECTED_NODE_MISMATCH", filename, at, "Expected-node predicate differs from node_id.")
                if node.get("primitive") == "wait_domain_event":
                    allowed = set(node.get("input", {}).get("allowed_events", []))
                    labels = {e.get("on") for e in outgoing}
                    for event in sorted(allowed - labels):
                        self.error("UNHANDLED_ALLOWED_EVENT", filename, at, f"Allowed event {event!r} has no outgoing edge.")
                    for event in sorted(labels - allowed):
                        self.error("UNDECLARED_DOMAIN_EVENT", filename, at, f"Outgoing event {event!r} is absent from allowed_events.")
                if node.get("primitive") == "end" and outgoing:
                    self.error("END_HAS_NEXT", filename, at, "An end node must be terminal.")
                if node.get("primitive") != "end" and not outgoing:
                    self.error("NONTERMINAL_DEAD_END", filename, at, "Use an explicit terminal outcome instead of an unlabelled dead end.")
                if node.get("primitive") == "settle_quest":
                    qid = typed_value(node.get("input", {}).get("quest"), "quest")
                    settles[qid].add(node_id)
                    receipt = node.get("wait") or {}
                    if (receipt.get("event") != "QuestSettlementCommitted" or receipt.get("proof") != "AUTHORITATIVE_COMMIT" or receipt.get("producer") != "SERVER"):
                        self.error("SETTLEMENT_COMMIT_WAIT", filename, at, "Settlement must wait for a Server authoritative QuestSettlementCommitted event.")
                    if not outgoing or any(e.get("on") != "QuestSettlementCommitted" for e in outgoing):
                        self.error("SETTLEMENT_COMMIT_EXIT", filename, at, "Every settlement exit must be gated by QuestSettlementCommitted.")
                    persistence = node.get("persistence", {})
                    if persistence.get("transaction") != node.get("input", {}).get("transaction_contract") or persistence.get("commit_before_effect") is not True:
                        self.error("SETTLEMENT_TRANSACTION", filename, at, "Settlement persistence must use the declared transaction and commit-before-effect boundary.")
                    if qid not in refs:
                        self.error("SETTLEMENT_QUEST_FK", filename, at, "Settlement is for a quest outside flow.quest_refs.")
                for path, record in walk(node):
                    if record.get("domain") == "scene" and typed_value(record.get("quest"), "quest") not in refs:
                        self.error("FLOW_SCENE_QUEST", filename, at + pointer(path), "Scene belongs to a quest outside flow.quest_refs.")
            reached = reachable(entry, adjacency)
            for node_id in sorted(set(index) - reached):
                self.error("UNREACHABLE_NODE", filename, base, f"Unreachable node {node_id!r}.")
            declared_loops = set()
            for loop in flow.get("explicit_event_loops", []):
                pair = (loop.get("from_node"), loop.get("to_node"))
                if pair in declared_loops:
                    self.error("DUPLICATE_LOOP", filename, base, str(pair))
                declared_loops.add(pair)
                if pair not in edge_pairs:
                    self.error("LOOP_EDGE_FK", filename, base, f"Declared loop {pair} is not an actual edge.")
                elif pair[0] not in reachable(pair[1], adjacency):
                    self.error("LOOP_NOT_CYCLIC", filename, base, f"Declared loop edge {pair} is not part of a cycle.")
            acyclic = {n: {v for v in targets if (n, v) not in declared_loops} for n, targets in adjacency.items()}
            indegree = Counter({n: 0 for n in index})
            for targets in acyclic.values():
                for target in targets:
                    indegree[target] += 1
            pending = deque(n for n in index if indegree[n] == 0)
            removed = set()
            while pending:
                n = pending.popleft()
                removed.add(n)
                for target in acyclic[n]:
                    indegree[target] -= 1
                    if indegree[target] == 0:
                        pending.append(target)
            if len(removed) != len(index):
                self.error("UNDECLARED_CYCLE", filename, base, "A cycle remains after removing declared event-loop edges: " + ", ".join(sorted(set(index) - removed)))
            all_settles = set().union(*settles.values()) if settles else set()
            listed = flow.get("legal_settlement_nodes", [])
            self.unique_values(listed, filename, base, "legal_settlement_node")
            if set(listed) != all_settles:
                self.error("SETTLEMENT_LIST_MISMATCH", filename, base, "legal_settlement_nodes must exactly identify the settle_quest nodes; author declaration is not completion proof.")
            has_settled_end = any(n.get("primitive") == "end" and n.get("input", {}).get("outcome") == "SETTLED" for n in nodes)
            if len(refs) > 1 or has_settled_end:
                for qid in refs:
                    if not settles.get(qid):
                        self.error("QUEST_SETTLEMENT_MISSING", filename, base, f"Quest {qid} has no own settle_quest node.")
            for node_id, node in index.items():
                if node.get("primitive") != "end" or node.get("input", {}).get("outcome") != "SETTLED":
                    continue
                qid = typed_value(node.get("input", {}).get("quest"), "quest")
                if qid not in refs:
                    self.error("END_QUEST_FK", filename, base + "/" + str(node_id), "SETTLED end must name a quest in flow.quest_refs.")
                # Removing all same-quest settlement nodes proves collective domination
                # and permits legitimate alternative settlement branches for one quest.
                if node_id in reachable(entry, adjacency, settles.get(qid, set())):
                    self.error("SETTLED_WITHOUT_COMMIT_PATH", filename, base + "/" + str(node_id), f"An entry-to-SETTLED path bypasses settlement of Quest {qid}.")
            self.checks["flow_graphs_checked"] += 1
            self.checks["flow_nodes_checked"] += len(nodes)

    def check_scenario_graphs(self):
        case_stages = {}
        facts = self.read_json("evidence/typed-domain-facts.json")
        if isinstance(facts, list):
            for row in facts:
                if row.get("domain") == "CASE" and row.get("raw_attributes", {}).get("STAGE") is not None:
                    case_stages[row.get("id")] = int(row["raw_attributes"]["STAGE"])
        scenario_node_maps = {}
        for entry_id, scenario in self.scenarios.items():
            filename, at = "scenario-entries.json", "scenario:" + entry_id
            qid = typed_value(scenario.get("quest"), "quest")
            definition = self.definitions.get(qid)
            if definition and scenario.get("field") != definition.get("source_data", {}).get("field"):
                self.error("SCENARIO_FIELD_MISMATCH", filename, at, "Scenario field differs from the quest's declared FieldId.")
            case_id = typed_value(scenario.get("case"), "case")
            if case_id in case_stages and typed_value(scenario.get("field"), "field") != case_stages[case_id]:
                self.error("CASE_FIELD_JOIN", filename, at, "Candidate Field-to-Case.STAGE join disagrees with the selected resource row.")
            graph = scenario.get("map_graph")
            if graph is None:
                continue
            nodes = graph.get("nodes", [])
            self.unique_values([n.get("node_key") for n in nodes], filename, at, "map node_key")
            keys = {n.get("node_key") for n in nodes}
            for node in nodes:
                node_key = node.get("node_key")
                choices = {typed_value(m.get("map"), "map") for m in node.get("map_choices", [])}
                scenario_node_maps[(qid, node_key)] = choices
            for edge in graph.get("edges", []):
                if edge.get("from_node") not in keys or edge.get("to_node") not in keys:
                    self.error("MAP_EDGE_FK", filename, at, "Map graph edge references a missing node.")
            # No map entry, traversal order, win condition or trigger is guessed here.
            self.checks["scenario_resource_graphs_checked"] += 1
        for flow_id, flow in self.flows.items():
            qids = [typed_value(q, "quest") for q in flow.get("quest_refs", [])]
            for node in flow.get("nodes", []):
                data = node.get("input", {})
                key = data.get("map_node_key")
                if not isinstance(key, str) or not key.startswith("case"):
                    continue
                matches = [scenario_node_maps[(qid, key)] for qid in qids if (qid, key) in scenario_node_maps]
                if not matches:
                    self.error("MAP_NODE_FK", "quest-flows.json", f"flow:{flow_id}/node:{node.get('node_id')}", f"No owned Scenario graph declares {key!r}.")
                elif "map" in data and typed_value(data["map"], "map") not in set().union(*matches):
                    self.error("MAP_NODE_DOMAIN_MISMATCH", "quest-flows.json", f"flow:{flow_id}/node:{node.get('node_id')}", "MapId is not one of this resource node's map choices.")

    def check_wire_adapters(self):
        data = self.read_json("quest-wire-evidence.json")
        if not isinstance(data, dict):
            return
        entries = data.get("wire_entries")
        if not isinstance(entries, list):
            self.error("WIRE_COLLECTION_SHAPE", "quest-wire-evidence.json", "/wire_entries", "Expected wire_entries array.")
            return
        self.wire = {}
        self.unique_values([x.get("id") for x in entries], "quest-wire-evidence.json", "/wire_entries", "wire entry id")
        for index, entry in enumerate(entries):
            adapter = entry.get("adapter_id")
            if not isinstance(adapter, str) or not adapter:
                self.error("WIRE_ADAPTER_ID", "quest-wire-evidence.json", pointer(("wire_entries", index)), "Missing adapter_id.")
            elif adapter in self.wire:
                self.error("DUPLICATE_ADAPTER_ID", "quest-wire-evidence.json", pointer(("wire_entries", index)), adapter)
            else:
                self.wire[adapter] = entry
        for filename, entities in (("quest-definitions.json", self.definitions), ("quest-flows.json", self.flows), ("scenario-entries.json", self.scenarios)):
            for identity, entity in entities.items():
                for path, record in walk(entity):
                    for field in WIRE_FIELDS:
                        value = record.get(field)
                        if value is None:
                            continue
                        self.checks["wire_adapter_references_checked"] += 1
                        if value not in self.wire:
                            self.error("WIRE_ADAPTER_FK", filename, str(identity) + pointer(path + (field,)), f"Adapter {value!r} is absent from quest-wire-evidence.json; no opcode-only alias is inferred.")

    def activation_record(self, kind, identity, entity):
        key = f"{kind}:{identity}"
        state = entity.get("status" if kind == "scenario" else "activation")
        record = {"entity": key, "requested_activation": state, "readiness": "BLOCKED", "blockers": []}
        self.activation[key] = record
        return record

    @staticmethod
    def block(record, code, path, detail):
        value = {"code": code, "path": path, "detail": detail}
        if value not in record["blockers"]:
            record["blockers"].append(value)

    def need(self, record, entity, paths):
        for dotted in paths:
            value = entity
            for key in dotted.split("."):
                value = value.get(key) if isinstance(value, dict) else None
            if value is None or value == "":
                self.block(record, "REQUIRED_BINDING_UNBOUND", dotted, "Unknown/null cannot be promoted to an executable default.")

    def assess_activation(self):
        for kind, entities in (("quest", self.definitions), ("flow", self.flows), ("scenario", self.scenarios)):
            for identity, entity in entities.items():
                record = self.activation_record(kind, identity, entity)
                for issue in entity.get("blocking_issues", []):
                    self.block(record, issue.get("code", "DECLARED_BLOCKER"), issue.get("field", ""), issue.get("reason", "Declared blocking issue."))
                if kind == "quest":
                    self.need(record, entity, (
                        "flow_ref", "policy.progress_scope", "policy.eligibility_rule", "policy.acceptance_rule",
                        "policy.npc_visibility_rule", "policy.character_restrictions", "policy.repeatability",
                        "policy.branch_policy_ref", "settlement.objective_rule", "settlement.turnin_rule", "settlement.reward_plan_ref",
                    ))
                    if entity.get("settlement", {}).get("status") != "BOUND":
                        self.block(record, "SETTLEMENT_UNBOUND", "settlement.status", "Legal objective, turn-in and reward transaction are not bound.")
                    if entity.get("reward_policy_status") != "BOUND":
                        self.block(record, "REWARD_POLICY_UNBOUND", "reward_policy_status", "An empty reward array is not approval of a zero-reward plan.")
                    for index, objective in enumerate(entity.get("objectives", [])):
                        if objective.get("status") != "BOUND":
                            self.block(record, "OBJECTIVE_UNBOUND", f"objectives.{index}.status", "Objective is not authoritative executable content.")
                        self.need(record, {"objective": objective}, tuple("objective." + key for key in ("kind", "target_ref", "required_count", "counter_scope", "event_contract")))
                    for index, reward in enumerate(entity.get("rewards", [])):
                        if reward.get("status") != "BOUND":
                            self.block(record, "REWARD_UNBOUND", f"rewards.{index}.status", "Raw resource reward has no approved grant contract.")
                        self.need(record, {"reward": reward}, tuple("reward." + key for key in ("grant_domain", "recipient_scope", "publication_adapter_id")))
                    if not entity.get("rewards") and (entity.get("reward_policy_status") != "BOUND" or not entity.get("settlement", {}).get("reward_plan_ref")):
                        self.block(record, "EMPTY_REWARDS_NEED_EXPLICIT_PLAN", "rewards", "Requires an explicit bound reward_plan_ref; absence is not zero.")
                elif kind == "flow":
                    for node in entity.get("nodes", []):
                        node_key = "nodes." + str(node.get("node_id"))
                        if node.get("status") == "BLOCKED":
                            self.block(record, "NODE_BLOCKED", node_key, "Blocked node cannot be executed.")
                        if node.get("preconditions") is None:
                            self.block(record, "NODE_PRECONDITION_UNBOUND", node_key, "Node has no bound authorization precondition.")
                        for field in REQUIRED_NODE_BINDINGS.get(node.get("primitive"), ()):
                            if not nonempty(node.get("input", {}).get(field)):
                                self.block(record, "NODE_CONTRACT_UNBOUND", node_key + ".input." + field, "Necessary primitive binding remains null.")
                else:
                    self.need(record, entity, ("case", "admission_policy_ref", "allowed_formation_policy_ref", "map_graph", "completion_rule_ref", "portal_policy.geometry_binding_ref"))
                    lifecycle = entity.get("lifecycle_profile")
                    if lifecycle == "TUTORIAL_CONTINUATION":
                        self.need(record, entity, ("tutorial_hook_contract_ref",))
                    elif lifecycle == "GENERAL_SCENARIO":
                        self.need(record, entity, ("result_contract_ref", "return_contract_ref"))
                    else:
                        self.block(record, "SCENARIO_LIFECYCLE_UNBOUND", "lifecycle_profile", "Bind an explicit tutorial continuation or general Scenario lifecycle; no QuestId-based default is inferred.")
                    for index, edge in enumerate((entity.get("map_graph") or {}).get("edges", [])):
                        if edge.get("trigger_policy_ref") is None:
                            self.block(record, "MAP_EDGE_TRIGGER_UNBOUND", f"map_graph.edges.{index}", "A source NodeLink is not a gameplay trigger.")
                if self.wire is not None:
                    for path, obj in walk(entity):
                        for field in WIRE_FIELDS:
                            adapter = obj.get(field)
                            if adapter in self.wire:
                                status = self.wire[adapter].get("status")
                                if status not in ("BOUND", "VERIFIED", "READY"):
                                    self.block(record, "WIRE_CONTRACT_NOT_BOUND", pointer(path + (field,)), f"{adapter}: evidence status is {status!r}; bounded source reuse alone does not activate content.")
                elif kind in ("quest", "flow", "scenario"):
                    self.block(record, "WIRE_REGISTRY_DEFERRED", "quest-wire-evidence.json", "Adapter registry has not yet been supplied.")
        # Cross-entity gates use a fixed point: a downstream blocker must reach
        # every dependent even when definitions/flows form a reference cycle.
        dependency_map = {}
        for key, record in self.activation.items():
            kind, identifier = key.split(":", 1)
            dependencies = []
            if kind == "quest":
                entity = self.definitions[int(identifier)]
                if entity.get("flow_ref"):
                    dependencies.append("flow:" + entity["flow_ref"])
                if entity.get("scenario_entry_ref"):
                    dependencies.append("scenario:" + entity["scenario_entry_ref"])
            elif kind == "flow":
                entity = self.flows[identifier]
                dependencies.extend("quest:" + str(typed_value(q, "quest")) for q in entity.get("quest_refs", []))
                dependencies.extend("scenario:" + r["scenario_entry_ref"] for _, r in walk(entity) if r.get("scenario_entry_ref"))
            else:
                entity = self.scenarios[identifier]
                dependencies.append("quest:" + str(typed_value(entity.get("quest"), "quest")))
            dependency_map[key] = sorted(set(dependencies))
            if record["requested_activation"] != ENABLED:
                self.block(record, "DECLARED_DISABLED", "activation", "Artifact is intentionally non-executable: " + str(record["requested_activation"]))
        changed = True
        while changed:
            changed = False
            for key, dependencies in dependency_map.items():
                record = self.activation[key]
                before = len(record["blockers"])
                for dependency in dependencies:
                    other = self.activation.get(dependency)
                    if other is None or other["requested_activation"] != ENABLED or other["blockers"]:
                        self.block(record, "DEPENDENCY_NOT_ENABLED", dependency, "All referenced definition, flow and Scenario versions must be ready and enabled together.")
                changed = changed or len(record["blockers"]) != before
        for record in self.activation.values():
            record["readiness"] = "BLOCKED" if record["blockers"] else "READY"

    def check_csvs(self):
        contract = self.read_json("csv-contracts.json")
        contracts = {}
        if isinstance(contract, dict):
            for table in contract.get("tables", []):
                name = table.get("file")
                if name in contracts:
                    self.error("DUPLICATE_CSV_CONTRACT", "csv-contracts.json", "/tables", str(name))
                contracts[name] = table
        for name in dict.fromkeys(list(PRIMARY_CSVS) + list(contracts)):
            path = self.root / name
            if not path.is_file():
                self.missing(name, "Primary CSV provenance and foreign-key checks run when this integration file is present.")
                continue
            try:
                raw = path.read_bytes()
                self.inputs[name] = {"sha256": hashlib.sha256(raw).hexdigest(), "bytes": len(raw)}
                with path.open(encoding="utf-8-sig", newline="") as handle:
                    reader = csv.DictReader(handle)
                    headers = reader.fieldnames or []
                    rows = list(reader)
            except (OSError, csv.Error, UnicodeError) as exc:
                self.error("CSV_READ", name, "", str(exc))
                continue
            required = {"source_ref", "source_sha", "evidence_kind", "unknowns"}
            for column in sorted(required - set(headers)):
                self.error("CSV_PROVENANCE_COLUMN", name, "", "Missing required column: " + column)
            columns = contracts.get(name, {}).get("columns", [])
            if columns and [column.get("name") for column in columns] != headers:
                self.error("CSV_CONTRACT_HEADERS", name, "", "CSV header/order differs from csv-contracts.json.")
            seen = set()
            for index, row in enumerate(rows, 2):
                at = f"row:{index}"
                if None in row:
                    self.error("CSV_COLUMN_COUNT", name, at, "Row has more cells than the header.")
                for field in ("source_ref", "evidence_kind", "unknowns"):
                    if not isinstance(row.get(field), str) or not row.get(field, "").strip():
                        self.error("CSV_PROVENANCE_VALUE", name, at, field + " must be nonempty; use [] for no listed unknowns.")
                if not isinstance(row.get("source_sha"), str) or not SHA256.fullmatch(row.get("source_sha", "")):
                    self.error("CSV_SOURCE_SHA", name, at, "Primary source_sha must be one 64-hex SHA-256; supporting arrays belong in separate columns.")
                elif isinstance(row.get("source_ref"), str):
                    self.source_references.append((row["source_ref"], row["source_sha"], name, at))
                for column in columns:
                    field, cell_type = column.get("name"), column.get("cell_type")
                    value = row.get(field)
                    if value is None or value == "":
                        if column.get("required_nonempty"):
                            self.error("CSV_REQUIRED_CELL", name, at, str(field) + " must be nonempty under its CSV contract.")
                        continue
                    if cell_type == "json":
                        try:
                            json.loads(value)
                        except ValueError:
                            self.error("CSV_CONTRACT_CELL_TYPE", name, at, str(field) + " is declared json but is not valid JSON.")
                    elif cell_type == "integer" and not re.fullmatch(r"-?[0-9]+", value):
                        self.error("CSV_CONTRACT_CELL_TYPE", name, at, str(field) + " is declared integer.")
                    elif cell_type == "boolean" and value.lower() not in ("true", "false"):
                        self.error("CSV_CONTRACT_CELL_TYPE", name, at, str(field) + " is declared boolean; no 0/1 coercion is assumed.")
                for field in ("row_sha256", "sequence_sha256"):
                    if row.get(field) and not SHA256.fullmatch(row[field]):
                        self.error("CSV_SECONDARY_SHA", name, at, field + " is not a SHA-256.")
                id_fields = {
                    "quest-catalog.csv": ("quest_id",), "quest-nodes.csv": ("flow_id", "node_id"),
                    "quest-objectives.csv": ("quest_id", "objective_key"), "quest-rewards.csv": ("quest_id", "reward_key"),
                    "quest-scenes.csv": ("quest_id", "scene_index"), "quest-scenario-entries.csv": ("entry_id",),
                    "id-dictionary.csv": ("id_domain",), "id-relations.csv": ("relation_id",),
                    "migration-matrix.csv": ("migration_id",), "quest-wire-map.csv": ("adapter_id",),
                    "exceptions.csv": ("exception_id",), "id-values.csv": ("value_key",),
                    "quest-npc-scenes.csv": ("association_id",),
                }.get(name, ())
                id_fields = tuple(contracts.get(name, {}).get("primary_key", id_fields))
                if id_fields and all(field in headers for field in id_fields):
                    key = tuple(row.get(field) for field in id_fields)
                    if key in seen:
                        self.error("CSV_DUPLICATE_ID", name, at, str(key))
                    seen.add(key)
                qid = None
                if row.get("quest_id"):
                    try:
                        qid = int(row["quest_id"])
                    except ValueError:
                        self.error("CSV_QUEST_ID", name, at, "quest_id must be an integer.")
                    if qid not in self.definitions:
                        self.error("CSV_QUEST_FK", name, at, f"Quest {qid!r} not in definitions.")
                if name == "quest-nodes.csv":
                    flow = self.flows.get(row.get("flow_id"))
                    node = next((n for n in (flow or {}).get("nodes", []) if n.get("node_id") == row.get("node_id")), None)
                    if node is None:
                        self.error("CSV_NODE_FK", name, at, "No corresponding flow node.")
                    else:
                        for field in ("input", "next", "persistence"):
                            try:
                                if json.loads(row.get(field, "")) != node.get(field):
                                    self.error("CSV_NODE_DRIFT", name, at, field + " differs from canonical flow JSON.")
                            except ValueError:
                                self.error("CSV_JSON_CELL", name, at, field + " is not valid JSON.")
                if name == "quest-scenes.csv":
                    try:
                        key = (qid, int(row.get("scene_index", "")))
                        if key not in self.declared_scenes:
                            self.error("CSV_SCENE_FK", name, at, f"Unknown composite key {key}.")
                        if row.get("scene_key") != f"scene:{key[0]}/{key[1]}":
                            self.error("CSV_SCENE_KEY", name, at, "scene_key disagrees with quest_id/scene_index.")
                    except ValueError:
                        self.error("CSV_SCENE_ID", name, at, "scene_index must be an integer.")
                if name == "quest-scenario-entries.csv" and row.get("entry_id") not in self.scenarios:
                    self.error("CSV_SCENARIO_FK", name, at, "Unknown scenario entry.")
                if name == "quest-wire-map.csv" and self.wire is not None and row.get("adapter_id") not in self.wire:
                    self.error("CSV_WIRE_FK", name, at, "adapter_id is not present in wire evidence.")
                if name == "quest-npc-scenes.csv":
                    try:
                        scene = json.loads(row.get("scene_key", ""))
                        key = (typed_value(scene.get("quest"), "quest"), scene.get("scene_index"))
                        if scene.get("domain") != "scene" or key not in self.declared_scenes or key[0] != qid:
                            self.error("NPC_SCENE_COMPOSITE_FK", name, at, "NPC association must reference this quest's composite SceneKey.")
                        role = row.get("npc_role")
                        if role in ("giver", "finisher") and qid in self.definitions:
                            expected = typed_value(self.definitions[qid]["source_data"].get(role), "npc")
                            if int(row.get("npc_id", "")) != expected:
                                self.error("NPC_ROLE_FK", name, at, "Giver/finisher ID differs from the Quest source row.")
                    except (ValueError, AttributeError):
                        self.error("NPC_SCENE_CELL", name, at, "Expected a composite scene object and integer NPC ID.")
                if name == "id-values.csv":
                    try:
                        typed_key = json.loads(row.get("typed_key", ""))
                        if not isinstance(typed_key, dict) or typed_key.get("domain") != row.get("domain"):
                            self.error("ID_VALUE_DOMAIN", name, at, "typed_key.domain differs from the dictionary row domain.")
                    except ValueError:
                        self.error("ID_VALUE_KEY", name, at, "typed_key must be a JSON object.")
                self.checks["primary_csv_rows_checked"] += 1
            self.checks["primary_csv_files_checked"] += 1

    def check_source_index(self):
        index = self.read_json("source-index.json")
        if not isinstance(index, dict):
            return
        registry = set()
        for position, source in enumerate(index.get("sources", [])):
            ref, digest = source.get("source_ref"), source.get("source_sha")
            if not isinstance(ref, str) or not ref.strip() or not isinstance(digest, str) or not SHA256.fullmatch(digest):
                self.error("SOURCE_INDEX_ENTRY", "source-index.json", pointer(("sources", position)), "Indexed source needs a nonempty reference and 64-hex content SHA-256.")
                continue
            key = (ref.split("#", 1)[0], digest)
            if key in registry:
                self.error("SOURCE_INDEX_DUPLICATE", "source-index.json", pointer(("sources", position)), "Duplicate source reference/content-hash pair.")
            registry.add(key)
        # A row locator after '#' narrows a source member; it does not change its
        # full-member hash. Git SHA-1s in supporting arrays are intentionally not
        # checked as primary SHA-256s by this pass.
        seen = set()
        for ref, digest, filename, at in self.source_references:
            key = (ref.split("#", 1)[0], digest)
            if key not in registry and key not in seen:
                self.error("SOURCE_INDEX_FK", filename, at, "Primary source reference/SHA pair is absent from source-index.json: " + ref)
                seen.add(key)
        self.checks["source_index_entries_checked"] = len(index.get("sources", []))
        self.checks["primary_source_references_indexed"] = len(self.source_references)

    def run(self):
        for phase in (
                self.load_schemas, self.load_collections, self.check_examples,
                self.load_scene_evidence, self.check_foreign_keys, self.check_raw_fidelity,
                self.check_flow_graphs, self.check_scenario_graphs, self.check_wire_adapters,
                self.check_csvs, self.check_source_index, self.assess_activation):
            try:
                phase()
            except Exception as exc:
                # Malformed data must produce a failing report instead of an
                # uncaught exception or a misleading partial PASS.
                self.error("VALIDATION_CHECK_FAILED", "validate_content.py", phase.__name__, type(exc).__name__ + ": " + str(exc)[:500])
        unsafe = [entry["entity"] for entry in self.activation.values() if entry["requested_activation"] == ENABLED and entry["blockers"]]
        return {
            "validator_version": VERSION,
            "generated_utc": datetime.now(timezone.utc).isoformat(),
            "scope": "LOCAL_STATIC_CONTENT_VALIDATION_ONLY",
            "runtime_tests_executed": False,
            "network_access_used": False,
            "structural": {"status": "PASS" if not self.errors else "FAIL", "error_count": len(self.errors), "errors": self.errors},
            "activation": {
                "status": "BLOCKED" if any(x["blockers"] for x in self.activation.values()) or self.errors else "READY",
                "unsafe_enabled_entities": unsafe,
                "entity_count": len(self.activation),
                "entities": list(self.activation.values()),
            },
            "coverage": {"status": "COMPLETE" if not self.deferred else "DEFERRED", "checks": dict(self.checks), "deferred": self.deferred},
            "warnings": self.warnings,
            "input_files": self.inputs,
            "interpretation": [
                "Structural PASS validates data/schema/graph consistency; it does not prove lawful objectives, rewards, original Server behavior or gameplay acceptance.",
                "BLOCKED drafts remain importable for review and non-executable. Unknown values are not supplied by this validator.",
                "Source SHA shape and selected local content comparisons are checked; remote source authenticity is not re-fetched.",
                "Scene membership/order and MapChart links do not establish gameplay triggers or completion rules.",
                "No Client, Server, replay, duplicate-settlement, disconnect or fault-injection test is performed.",
            ],
        }


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=Path(__file__).resolve().parent)
    parser.add_argument("--report", type=Path, default=None, help="Report path; default ROOT/validation-report.json")
    parser.add_argument("--strict-missing", action="store_true", help="Treat deferred integration files as structural errors.")
    args = parser.parse_args()
    root = args.root.resolve()
    report = Validation(root, args.strict_missing).run()
    output = args.report or root / "validation-report.json"
    output.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"structural": report["structural"]["status"], "activation": report["activation"]["status"], "errors": report["structural"]["error_count"], "deferred": len(report["coverage"]["deferred"]), "unsafe_enabled_entities": report["activation"]["unsafe_enabled_entities"], "report": str(output)}, ensure_ascii=False))
    return 1 if report["structural"]["errors"] or report["activation"]["unsafe_enabled_entities"] else 0


if __name__ == "__main__":
    sys.exit(main())
