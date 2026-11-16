#!/usr/bin/env python3
"""Independent, offline acceptance checks for the supplied W3 normal input.

This runs only the new converter, twice.  It does not import the converter,
execute historical evidence scripts, contact a service, or exercise gameplay.
The fixed route checks document the supplied 2026-11-04 ten-Quest work package;
they are not a validator for every future story package.
"""

from __future__ import annotations

import argparse
import ast
from collections import Counter
import csv
import hashlib
import json
from pathlib import Path
import re
import subprocess
import sys
import tempfile
from typing import Any
from xml.etree import ElementTree as ET


T16 = "git-evidence/research/handoffs/kr-quest-runtime-20261103-v0.1.0"
BASELINE = (
    "git-evidence/governance/s00-iterations/evidence/"
    "S00-20261104-ALSMEER-RESOURCE-BASELINE.json"
)
QUESTS = (117, 118, 119, 120, 121, 122, 123, 124, 131, 132)
OUTPUTS = ("story-catalog.json", "source-map.csv", "validation-report.json")
BOUNDARY = (
    "Offline normal-input format, provenance and data-preservation checks only; "
    "not T01 FULL-PASS, native MEF validation, Server activation or gameplay acceptance."
)
STDLIB_ROOTS_PY39 = {
    "__future__", "argparse", "codecs", "collections", "csv", "hashlib", "io",
    "json", "os", "pathlib", "re", "sys", "tempfile", "xml",
}


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def unique_object(pairs: list[tuple[str, Any]]) -> dict[str, Any]:
    out: dict[str, Any] = {}
    for key, value in pairs:
        if key in out:
            raise ValueError("Duplicate JSON member: " + key)
        out[key] = value
    return out


def load_json(path: Path) -> Any:
    return json.loads(path.read_text(encoding="utf-8-sig"), object_pairs_hook=unique_object)


def snapshot(root: Path) -> dict[str, str]:
    return {
        p.relative_to(root).as_posix(): sha256(p.read_bytes())
        for p in sorted(root.rglob("*"))
        if p.is_file()
    }


def pointer_value(document: Any, pointer: str) -> Any:
    """Resolve an RFC 6901 pointer; null is a valid, resolved value."""
    if pointer.startswith("#"):
        pointer = pointer[1:]
    if not pointer:
        return document
    if not pointer.startswith("/"):
        raise ValueError("Not a JSON pointer: " + pointer)
    current = document
    for token in pointer[1:].split("/"):
        token = token.replace("~1", "/").replace("~0", "~")
        if isinstance(current, list):
            index = int(token)
            if str(index) != token or index < 0:
                raise ValueError("Invalid list index: " + token)
            current = current[index]
        else:
            current = current[token]
    return current


class Checks:
    def __init__(self) -> None:
        self.count = 0
        self.failures: list[str] = []
        self.groups: list[str] = []

    def require(self, condition: bool, description: str) -> None:
        self.count += 1
        if not condition:
            self.failures.append(description)

    def equal(self, actual: Any, expected: Any, description: str) -> None:
        self.require(actual == expected, description)

    def group(self, description: str) -> None:
        self.groups.append(description)


def parsed_csv(root: Path, name: str, contracts: dict[str, Any]) -> list[dict[str, Any]]:
    contract = next(t for t in contracts["tables"] if t["file"] == name)
    with (root / T16 / name).open(encoding="utf-8-sig", newline="") as stream:
        rows = list(csv.DictReader(stream))
    result = []
    for row in rows:
        parsed = {}
        for column in contract["columns"]:
            key = column["name"]
            value = row[key]
            kind = column["cell_type"]
            if value == "":
                parsed[key] = None
            elif kind == "integer":
                parsed[key] = int(value)
            elif kind == "boolean":
                if value.casefold() not in {"true", "false"}:
                    raise ValueError("Unexpected boolean CSV cell: " + value)
                parsed[key] = value.casefold() == "true"
            elif kind == "json":
                parsed[key] = json.loads(value, object_pairs_hook=unique_object)
            else:
                parsed[key] = value
        result.append(parsed)
    return result


def verify_catalog(root: Path, catalog: dict[str, Any], checks: Checks) -> dict[str, int]:
    """Compare actual output to input objects, not to the converter's PASS label."""
    baseline = load_json(root / BASELINE)
    source_definitions = load_json(root / T16 / "quest-definitions.json")["definitions"]
    definitions = {d["id"]["value"]: d for d in source_definitions}
    source_flows = load_json(root / T16 / "quest-flows.json")["flows"]
    source_scenarios = load_json(root / T16 / "scenario-entries.json")["entries"]
    contracts = load_json(root / T16 / "csv-contracts.json")
    source_catalog = parsed_csv(root, "quest-catalog.csv", contracts)
    source_scenes = parsed_csv(root, "quest-scenes.csv", contracts)
    source_npc_scenes = parsed_csv(root, "quest-npc-scenes.csv", contracts)
    source_objectives = parsed_csv(root, "quest-objectives.csv", contracts)
    source_rewards = parsed_csv(root, "quest-rewards.csv", contracts)
    rows_by_id = {x["quest_id"]: x for x in source_catalog}
    quest_ids = [q["quest_id"] for q in catalog["quests"]]
    checks.equal(tuple(q["quest"] for q in baseline["quests"]), QUESTS,
                 "Supplied S00 baseline must name the expected ten Quest IDs")
    checks.equal(tuple(quest_ids), QUESTS, "Output order and membership must match ten-Quest scope")
    checks.equal(len(set(quest_ids)), 10, "Output Quest IDs must be unique")
    checks.equal(len(source_definitions), 20, "T16 source has 20 canonical definitions")
    checks.equal(catalog["activation"], "DRAFT_BLOCKED", "Conversion must not activate content")
    actual = {q["quest_id"]: q for q in catalog["quests"]}
    scene_count = 0
    for quest_id in QUESTS:
        quest = actual[quest_id]
        definition = definitions[quest_id]
        checks.equal(quest["id"], {"domain": "quest", "value": quest_id},
                     f"Quest {quest_id} typed identity")
        checks.equal(quest["definition"], definition,
                     f"Quest {quest_id} canonical definition, nulls, provenance and blockers preserved")
        checks.equal(quest["predecessors"], definition["source_data"]["demand_ids"],
                     f"Quest {quest_id} predecessors follow source Demands")
        checks.equal(quest["successors"], definition["unlock_candidates"],
                     f"Quest {quest_id} successors follow documented links")
        for key, value in rows_by_id[quest_id].items():
            checks.require(key in quest["catalog_projection"], f"Quest {quest_id} retains CSV column {key}")
            checks.equal(quest["catalog_projection"].get(key), value,
                         f"Quest {quest_id} CSV column {key} preserved with declared type")
        expected_scenes = [x for x in source_scenes if x["quest_id"] == quest_id]
        expected_npc = [x for x in source_npc_scenes if x["quest_id"] == quest_id]
        checks.equal(len(quest["scene_bindings"]), len(expected_scenes),
                     f"Quest {quest_id} scene count")
        for row, expected in zip(quest["scene_bindings"], expected_scenes):
            for key, value in expected.items():
                checks.require(key in row, f"Quest {quest_id} retains scene column {key}")
                checks.equal(row.get(key), value, f"Quest {quest_id} scene column {key}")
        checks.equal(len(quest["npc_scene_associations"]), len(expected_npc),
                     f"Quest {quest_id} NPC association count")
        for row, expected in zip(quest["npc_scene_associations"], expected_npc):
            for key, value in expected.items():
                checks.require(key in row, f"Quest {quest_id} retains NPC association column {key}")
                checks.equal(row.get(key), value, f"Quest {quest_id} NPC association column {key}")
        checks.equal(quest["objective_projection"],
                     [r for r in source_objectives if r["quest_id"] == quest_id],
                     f"Quest {quest_id} objective CSV preserves all unbound conditions")
        checks.equal(quest["reward_projection"],
                     [r for r in source_rewards if r["quest_id"] == quest_id],
                     f"Quest {quest_id} reward CSV preserves unknown policy placeholders")
        scene_count += len(quest["scene_bindings"])
    checks.equal(scene_count, 30, "Ten selected Quests must preserve 30 composite scene keys")
    checks.group("Canonical definitions, typed IDs, dependency edges and CSV projections preserved")

    # S00 explicitly schedules four scenarios; Field metadata alone is insufficient.
    expected_cases = {119: 107, 122: 108, 124: 101, 132: 109}
    expected_maps = {
        119: [632, 633, 634, 635],
        122: [636, 637, 638, 639],
        124: [184, 185, 186, 187],
        132: [640, 641, 642, 643],
    }
    for quest_id in QUESTS:
        route = actual[quest_id]["s00_route"]
        checks.equal(route["status"], "DRAFT_CANDIDATE", f"Quest {quest_id} S00 route is candidate")
        checks.equal(route["scenario_scheduled"], quest_id in expected_cases,
                     f"Quest {quest_id} scenario schedule follows explicit S00 route")
        checks.equal(route["ordered_maps"],
                     [{"domain": "map", "value": m} for m in expected_maps.get(quest_id, [])],
                     f"Quest {quest_id} ordered and typed Map IDs")
        checks.equal(route["field_metadata"], definitions[quest_id]["source_data"]["field"],
                     f"Quest {quest_id} Field metadata preserved separately from scheduling")
        # This is the S00 schedule's Case.  Q118's distinct T16 Case109
        # candidate remains in its canonical Scenario and catalog projection.
        case = expected_cases.get(quest_id)
        checks.equal(route["case_metadata"], {"domain": "case", "value": case} if case is not None else None,
                     f"Quest {quest_id} scheduled Case stays distinct from T16 metadata")
        narrative = [1, 2, 3] if quest_id == 120 else [1]
        checks.equal(route["narrative_scene_sequence"],
                     [{"domain": "scene", "quest": {"domain": "quest", "value": quest_id}, "scene_index": s}
                      for s in narrative], f"Quest {quest_id} narrative order follows the explicit S00 description")
    checks.equal(actual[118]["s00_route"]["field_metadata"], {"domain": "field", "value": 28},
                 "Q118 preserves Field28 while remaining a narrative route")
    for quest_id in (131, 132):
        source = actual[quest_id]["definition"]["source_data"]
        checks.equal(source["town"], {"domain": "town", "value": 1}, f"Q{quest_id} Quest town remains 1")
        checks.equal(source["chapters"][0]["chapter_town"], {"domain": "town", "value": 2},
                     f"Q{quest_id} Chapter town remains 2")
    checks.equal(actual[117]["predecessors"], [{"domain": "quest", "value": 15}],
                 "External prerequisite Q15 preserved")
    checks.equal(actual[132]["successors"], [{"domain": "quest", "value": 133}],
                 "External successor Q133 preserved without including it in the route")
    cues = actual[132]["s00_route"]["scene_cues"]
    cue2 = [c for c in cues if c["scene"]["scene_index"] == 2]
    checks.equal(len(cue2), 1, "Q132 scene2 has one explicit cue")
    if cue2:
        checks.equal(cue2[0]["presentation_maps"], [{"domain": "map", "value": 642}],
                     "Q132 scene2 binds to Map642, the third route map")
    cue5 = [c for c in cues if c["scene"]["scene_index"] == 5]
    checks.equal(len(cue5), 1, "Q132 scene5 has one return cue")
    if cue5:
        checks.equal(cue5[0]["presentation_maps"], [{"domain": "map", "value": 183}],
                     "Q132 scene5 preserves the explicit endpoint Map183 association")
    checks.equal(actual[132]["s00_route"]["result_and_return"]["destination_map"],
                 {"domain": "map", "value": 183}, "Q132 explicit destination is Map183")
    checks.equal(actual[132]["s00_route"]["result_and_return"]["destination_town"],
                 {"domain": "town", "value": 2}, "Q132 explicit destination is Town2")
    external = catalog["external_quest_references"]
    checks.equal([e["id"] for e in external],
                 [{"domain": "quest", "value": 15}, {"domain": "quest", "value": 133}],
                 "External boundary registry contains exact typed Q15 and Q133")
    checks.group("S00 route differences preserved: Q118, Chapter town, Q132 Map642, external Q15/Q133")

    shared = catalog["shared"]
    used_flow_ids = {definitions[q]["flow_ref"] for q in QUESTS} - {None}
    expected_flows = {f["flow_id"]: f for f in source_flows if f["flow_id"] in used_flow_ids}
    actual_flows = {f["flow_id"]: f for f in shared["flows"]}
    checks.equal(actual_flows, expected_flows, "Relevant canonical flows retained exactly, including blocked stages")
    used_scenario_ids = {definitions[q]["scenario_entry_ref"] for q in QUESTS} - {None}
    expected_scenarios = {s["entry_id"]: s for s in source_scenarios if s["entry_id"] in used_scenario_ids}
    actual_scenarios = {s["entry_id"]: s for s in shared["scenario_entries"]}
    checks.equal(actual_scenarios, expected_scenarios,
                 "Relevant canonical scenarios retain original blocked status and null graph")
    checks.require(all(s["map_graph"] is None for s in actual_scenarios.values()),
                   "New Case resources must not overwrite original T16 null map_graph")
    case_resources = shared["case_resources"]
    checks.equal([c["case"]["value"] for c in case_resources],
                 [s["case"] for s in baseline["scenarios"]], "Four new Case resources retain baseline order")
    for case, source in zip(case_resources, baseline["scenarios"]):
        checks.equal(case["s00_candidate_selection"], source,
                     f"Case {source['case']} preserves source node order and all source clusters")
        checks.equal(case["status"], "DRAFT_BLOCKED", f"Case {source['case']} remains blocked")
    checks.equal([m["s00_baseline"] for m in shared["map_resources"]], baseline["maps"],
                 "All 18 map metadata/positions remain attributed S00 baseline projections")
    checks.group("Original flow/Scenario activation and legal settlement gates unchanged")
    return {"quests": len(quest_ids), "scenes": scene_count,
            "canonical_flows_preserved": len(actual_flows),
            "canonical_scenarios_preserved": len(actual_scenarios)}


def verify_source_map(root: Path, out: Path, checks: Checks) -> dict[str, Any]:
    """Source-map contract is verified against actual files and location targets."""
    with (out / "source-map.csv").open(encoding="utf-8-sig", newline="") as stream:
        rows = list(csv.DictReader(stream))
    checks.require(bool(rows), "Source-map must contain field-level provenance")
    contracts = load_json(root / T16 / "csv-contracts.json")
    snapshot_commit = load_json(root / "MANIFEST.json")["source_analysis_commit"]
    source_json: dict[str, Any] = {}
    output_json: dict[str, Any] = {}
    source_hash: dict[str, str] = {}
    csv_values: dict[str, list[dict[str, Any]]] = {}
    csv_lines: dict[str, list[tuple[int, int]]] = {}
    text_lines: dict[str, list[str]] = {}
    xml_roots: dict[str, ET.Element] = {}
    formats: Counter[str] = Counter()
    failed_locations = []
    for number, row in enumerate(rows, 1):
        try:
            relative = row["input_path"]
            path = (root / relative).resolve()
            checks.require(path != root and root in path.parents,
                           f"Source-map row {number} input is inside the package")
            if path == root or root not in path.parents:
                continue
            if relative not in source_hash:
                source_hash[relative] = sha256(path.read_bytes())
            checks.equal(row["input_sha256"], source_hash[relative],
                         f"Source-map row {number} input content hash")
            checks.equal(row["package_snapshot_commit"], snapshot_commit,
                         f"Source-map row {number} snapshot commit")
            output_file = row["output_file"]
            checks.require(output_file in OUTPUTS and output_file.endswith(".json"),
                           f"Source-map row {number} names a known JSON output")
            if output_file not in output_json:
                output_json[output_file] = load_json(out / output_file)
            produced_value = pointer_value(output_json[output_file], row["output_pointer"])
            kind = row["input_format"]
            formats[kind] += 1
            if kind == "JSON_POINTER":
                if relative not in source_json:
                    source_json[relative] = load_json(path)
                source_value = pointer_value(source_json[relative], row["input_pointer"])
                if row["transformation"] == "COPY_PRESERVING_SOURCE_STATUS":
                    checks.equal(produced_value, source_value,
                                 f"Source-map row {number} JSON copy value")
            elif kind == "CSV_CELL":
                if relative not in csv_values:
                    csv_values[relative] = parsed_csv(root, Path(relative).name, contracts)
                    with path.open(encoding="utf-8-sig", newline="") as stream:
                        reader = csv.DictReader(stream)
                        _ = reader.fieldnames
                        previous_line = reader.line_num
                        positions = []
                        for source_row in reader:
                            positions.append((previous_line + 1, reader.line_num))
                            previous_line = reader.line_num
                    csv_lines[relative] = positions
                ordinal = int(row["csv_record"])
                if ordinal < 1:
                    raise ValueError("CSV data record must be 1-based")
                source_value = csv_values[relative][ordinal - 1][row["column"]]
                start, end = csv_lines[relative][ordinal - 1]
                checks.equal((int(row["csv_line_start"]), int(row["csv_line_end"])), (start, end),
                             f"Source-map row {number} physical CSV lines")
                checks.equal(produced_value, source_value,
                             f"Source-map row {number} CSV value after declared type conversion")
            elif kind == "MARKDOWN_TABLE_ROW":
                match = re.fullmatch(r"line:(\d+)", row["input_pointer"])
                if match is None:
                    raise ValueError("Markdown location is not line:N")
                if relative not in text_lines:
                    text_lines[relative] = path.read_text(encoding="utf-8-sig").splitlines()
                line = text_lines[relative][int(match[1]) - 1]
                cells = [cell.strip() for cell in line.strip().strip("|").split("|")]
                checks.require(len(cells) == 3 and cells[0].isdigit(),
                               f"Source-map row {number} resolves to a Quest route table row")
                target = re.match(r"/quests/(\d+)/s00_route(?:/|$)", row["output_pointer"])
                if target and cells[0].isdigit():
                    qid = output_json[output_file]["quests"][int(target[1])]["quest_id"]
                    checks.equal(int(cells[0]), qid, f"Source-map row {number} Markdown Quest identity")
            elif kind == "XML_XPATH":
                if relative not in xml_roots:
                    raw = path.read_bytes()
                    declared = re.search(br"encoding\s*=\s*['\"]([^'\"]+)['\"]", raw[:256], re.I)
                    encoding = "utf-8-sig" if raw.startswith(b"\xef\xbb\xbf") else (
                        declared[1].decode("ascii") if declared else "utf-8"
                    )
                    xml_roots[relative] = ET.fromstring(raw.decode(encoding))
                document = xml_roots[relative]
                xpath = row["input_pointer"]
                root_xpath = "/" + document.tag
                if xpath == root_xpath:
                    selected = [document]
                elif xpath.startswith(root_xpath + "/"):
                    selected = document.findall("." + xpath[len(root_xpath):])
                else:
                    selected = []
                checks.require(bool(selected), f"Source-map row {number} XML location exists")
            else:
                checks.require(False, f"Source-map row {number} unsupported location kind {kind}")
            if row["source_sha256"]:
                checks.require(bool(re.fullmatch(r"[0-9a-f]{64}", row["source_sha256"])),
                               f"Source-map row {number} source SHA256 remains distinct from blob SHA1")
            for key in ("source_commit", "source_git_blob_sha1"):
                if row[key]:
                    checks.require(bool(re.fullmatch(r"[0-9a-f]{40}", row[key])),
                                   f"Source-map row {number} {key} has Git SHA1 shape")
        except (OSError, ValueError, KeyError, IndexError, TypeError, ET.ParseError) as exc:
            failed_locations.append(f"row {number}: {type(exc).__name__}: {exc}")
    checks.require(not failed_locations,
                   "All source-map input/output locations resolve: " + "; ".join(failed_locations[:10]))
    checks.group("Every source-map hash, JSON pointer, CSV record/column/physical line and XML/Markdown location checked")
    return {"source_map_rows": len(rows), "source_map_input_files": len(source_hash),
            "source_map_location_errors": len(failed_locations), "source_map_formats": dict(sorted(formats.items()))}


def verify_hash_report(root: Path, report: dict[str, Any], checks: Checks) -> dict[str, int]:
    manifest = load_json(root / "MANIFEST.json")
    expected = {row["path"]: row for row in manifest["files"]}
    actual = {row["path"]: row for row in report["manifest_audit"]}
    checks.equal(set(actual), set(expected), "Manifest audit covers every supplied member/file")
    for name, row in expected.items():
        data = (root / name).read_bytes()
        digest = sha256(data)
        checks.equal(digest, row["sha256"], f"Independent manifest SHA check: {name}")
        checks.equal(len(data), row["bytes"], f"Independent manifest size check: {name}")
        if name in actual:
            checks.equal(actual[name]["actual_sha256"], digest, f"Report contains measured hash: {name}")
            checks.equal(actual[name]["original_member_sha_match"], row.get("original_member_sha_match"),
                         f"Original-member declaration preserved separately: {name}")
    originals_unknown = {
        row["member"] for row in expected.values()
        if row.get("member", "").startswith("Table/") and row.get("original_member_sha_match") is not True
    }
    reported_unknowns = {
        u["member"] for u in report["unknowns"] if u["code"] == "TABLE_ORIGINAL_MEMBER_UNVERIFIED"
    }
    checks.equal(reported_unknowns, originals_unknown,
                 "Four Table members with unknown original identity remain individually reported")
    old_manifest = load_json(root / T16 / "content-manifest.json")
    old_audit = {r["path"]: r for r in report["content_manifest_audit"]}
    absent = []
    matched = 0
    for row in old_manifest["files"]:
        relative = T16 + "/" + row["path"]
        checks.require(relative in old_audit, "Historical manifest entry reported: " + relative)
        path = root / relative
        if path.is_file():
            digest = sha256(path.read_bytes())
            checks.equal(digest, row["sha256"], "Historical file hash: " + relative)
            checks.equal(old_audit[relative]["actual_sha256"], digest, "Historical measured hash: " + relative)
            checks.equal(old_audit[relative]["status"], "MATCH", "Historical available file status: " + relative)
            matched += 1
        else:
            absent.append(row["path"])
            checks.equal(old_audit[relative]["status"], "NOT_IN_PACKAGE", "Historical absent file status: " + relative)
    checks.equal(sorted(absent), ["requirements.txt", "validate_content.py"],
                 "Historical T16 missing files are recorded as exact names")
    source_index = load_json(root / T16 / "source-index.json")
    sources = {r["source_ref"]: r for r in source_index["sources"]}
    source_audit = {r["source_ref"]: r for r in report["source_index_audit"]}
    checks.equal(set(source_audit), set(sources), "All 133 source-index identities audited")
    for name, row in source_audit.items():
        checks.equal(row["expected_sha256"], sources[name]["source_sha"], "Source-index expected hash: " + name)
        if row["status"].startswith("CONTENT_SHA_MATCH"):
            measured = sha256((root / row["available_path"]).read_bytes())
            checks.equal(measured, sources[name]["source_sha"], "Rehashed available source identity: " + name)
    checks.equal(report["structural"]["errors"], 0, "Normal package has no conversion structure errors")
    checks.equal(report["activation"]["status"], "DRAFT_BLOCKED", "Report preserves activation block")
    checks.equal(report["activation"]["runtime_enabled"], False, "Report does not enable runtime")
    checks.group("Independent package/source hashes and exact missing-file/original-member boundaries checked")
    return {"manifest_files_verified": len(expected), "historical_files_verified": matched,
            "historical_files_not_provided": len(absent), "original_table_members_unverified": len(originals_unknown)}


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--input", required=True, type=Path,
                        help="Read-only extracted W1/W2/W3 input package")
    parser.add_argument("--converter", type=Path,
                        default=Path(__file__).with_name("convert_story_data.py"))
    parser.add_argument("--report", type=Path, help="Optional report outside the input package")
    args = parser.parse_args()
    root = args.input.resolve()
    converter = args.converter.resolve()
    if args.report and (args.report.resolve() == root or root in args.report.resolve().parents):
        parser.error("The verification report must be outside the input package")
    checks = Checks()
    report: dict[str, Any] = {"schema": "W3_NORMAL_INPUT_VERIFICATION_V1", "boundary": BOUNDARY}
    try:
        before = snapshot(root)
        report["input_manifest_sha256"] = before["MANIFEST.json"]
        report["converter_sha256"] = sha256(converter.read_bytes())
        syntax = ast.parse(converter.read_text(encoding="utf-8"))
        imports = set()
        for node in ast.walk(syntax):
            if isinstance(node, ast.Import):
                imports.update(a.name.split(".")[0] for a in node.names)
            elif isinstance(node, ast.ImportFrom) and node.module:
                imports.add(node.module.split(".")[0])
        stdlib = set(getattr(sys, "stdlib_module_names", STDLIB_ROOTS_PY39))
        checks.require(imports <= stdlib, "Converter has only standard-library imports")
        with tempfile.TemporaryDirectory(prefix="w3-normal-verification-") as temp:
            outputs = [Path(temp) / "first", Path(temp) / "second"]
            for output in outputs:
                completed = subprocess.run(
                    [sys.executable, "-B", str(converter), "--input", str(root), "--output", str(output)],
                    capture_output=True, encoding="utf-8", errors="replace", timeout=60,
                )
                if completed.returncode != 0:
                    raise RuntimeError(
                        f"Converter exited {completed.returncode}: {completed.stdout} {completed.stderr}"
                    )
            checks.equal(snapshot(root), before, "Every input file and filename is unchanged after both conversions")
            report["input_files_unchanged"] = len(before)
            report["output_sha256"] = {}
            for name in OUTPUTS:
                first = (outputs[0] / name).read_bytes()
                second = (outputs[1] / name).read_bytes()
                checks.equal(first, second, f"{name} is byte-identical across independent output directories")
                report["output_sha256"][name] = sha256(first)
            checks.group("Two independent CLI conversions are deterministic and input remains byte-identical")
            report.update(verify_catalog(root, load_json(outputs[0] / "story-catalog.json"), checks))
            report.update(verify_source_map(root, outputs[0], checks))
            report.update(verify_hash_report(root, load_json(outputs[0] / "validation-report.json"), checks))
    except Exception as exc:
        checks.require(False, f"Verification exception: {type(exc).__name__}: {exc}")
    report["status"] = "PASS" if not checks.failures else "FAIL"
    report["checks"] = checks.count
    report["check_groups"] = checks.groups
    report["failures"] = checks.failures
    rendered = json.dumps(report, ensure_ascii=False, sort_keys=True, indent=2) + "\n"
    if args.report:
        args.report.parent.mkdir(parents=True, exist_ok=True)
        with args.report.open("w", encoding="utf-8", newline="\n") as stream:
            stream.write(rendered)
    print(rendered, end="")
    return 0 if not checks.failures else 1


if __name__ == "__main__":
    raise SystemExit(main())
