#!/usr/bin/env python3
"""Check a few required offline data contracts using disposable package copies.

Only the new converter runs. No Client, Server, historical script, game failure,
concurrency or gameplay test is executed. Source files are never edited.
Fixture manifests are refreshed so semantic probes cannot pass merely because
the outer upload checksum changed. These fixtures are not native evidence.
"""
from __future__ import annotations

import argparse
import copy
import csv
import hashlib
import json
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile


T16 = "git-evidence/research/handoffs/kr-quest-runtime-20261103-v0.1.0"


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def load(path):
    return json.loads(path.read_text(encoding="utf-8-sig"))


def save(path, value):
    path.write_text(json.dumps(value, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")


def snapshot(root):
    return {p.relative_to(root).as_posix(): digest(p)
            for p in sorted(root.rglob("*")) if p.is_file()}


def edit_csv(root, name, edit):
    path = root / T16 / name
    with path.open(encoding="utf-8-sig", newline="") as stream:
        reader = csv.DictReader(stream)
        columns = reader.fieldnames
        rows = list(reader)
    rows = edit(rows)
    with path.open("w", encoding="utf-8-sig", newline="") as stream:
        writer = csv.DictWriter(stream, fieldnames=columns, lineterminator="\n")
        writer.writeheader()
        writer.writerows(rows)


def edit_json(root, name, edit):
    path = root / T16 / name
    value = load(path)
    edit(value)
    save(path, value)


def refresh_fixture_manifests(root):
    path = root / T16 / "content-manifest.json"
    manifest = load(path)
    for entry in manifest["files"]:
        source = root / T16 / entry["path"]
        if source.is_file():
            entry["sha256"] = digest(source)
            entry["size_bytes"] = source.stat().st_size
    save(path, manifest)
    path = root / "MANIFEST.json"
    manifest = load(path)
    for entry in manifest["files"]:
        source = root / entry["path"]
        if source.is_file():
            entry["sha256"] = digest(source)
            entry["bytes"] = source.stat().st_size
    save(path, manifest)


def duplicate_quest(root):
    def change(document):
        quest = next(x for x in document["definitions"] if x["id"]["value"] == 117)
        document["definitions"].append(copy.deepcopy(quest))
    edit_json(root, "quest-definitions.json", change)


def cross_quest_scene(root):
    def change(rows):
        row = next(x for x in rows if x["quest_id"] == "118")
        key = json.loads(row["scene_key"])
        key["quest"]["value"] = 119
        row["scene_key"] = json.dumps(key, separators=(",", ":"))
        return rows
    edit_csv(root, "quest-npc-scenes.csv", change)


def wrong_flow_domain(root):
    def change(document):
        flow = next(x for x in document["flows"] if x["flow_id"] == "q117.candidate")
        flow["quest_refs"][0]["domain"] = "npc"
    edit_json(root, "quest-flows.json", change)


def omitted_objective_row(root):
    edit_csv(root, "quest-objectives.csv",
             lambda rows: [x for x in rows if x["quest_id"] != "117"])


def jointly_wrong_town_projection(root):
    def change_json(document):
        quest = next(x for x in document["definitions"] if x["id"]["value"] == 117)
        quest["source_data"]["town"]["value"] = 2
    def change_csv(rows):
        next(x for x in rows if x["quest_id"] == "117")["town_id"] = "2"
        return rows
    edit_json(root, "quest-definitions.json", change_json)
    edit_csv(root, "quest-catalog.csv", change_csv)


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--input", required=True, type=Path)
    parser.add_argument("--converter", type=Path,
                        default=Path(__file__).with_name("convert_story_data.py"))
    parser.add_argument("--report", type=Path)
    args = parser.parse_args(argv)
    root, converter = args.input.resolve(), args.converter.resolve()
    if not (root / "MANIFEST.json").is_file() or not converter.is_file():
        parser.error("Supply the unpacked input package and the new converter")
    report_path = args.report.resolve() if args.report else None
    if report_path and (root == report_path or root in report_path.parents or report_path.exists()):
        parser.error("Report must be a new file outside the source package")
    before = snapshot(root)
    converter_sha = digest(converter)
    probes = (
        ("duplicate_quest_id", duplicate_quest, "DUPLICATE_ID", None),
        ("npc_scene_crosses_quest", cross_quest_scene, "SCENE_QUEST_MISMATCH", None),
        ("flow_quest_domain_mixup", wrong_flow_domain, "DOMAIN_MIXUP", None),
        ("missing_csv_objective_projection", omitted_objective_row, "PROJECTION_MISMATCH", None),
        ("canonical_and_csv_disagree_with_raw_town", jointly_wrong_town_projection,
         "PROJECTION_MISMATCH", T16 + "/quest-definitions.json"),
    )
    results = []
    for name, mutate, expected, required_source in probes:
        with tempfile.TemporaryDirectory(prefix="w3-format-") as temporary:
            temporary = Path(temporary)
            fixture, output = temporary / "input", temporary / "output"
            shutil.copytree(root, fixture)
            mutate(fixture)
            refresh_fixture_manifests(fixture)
            run = subprocess.run([sys.executable, str(converter), "--input", str(fixture),
                                  "--output", str(output)], capture_output=True, text=True,
                                 encoding="utf-8", errors="replace", timeout=60)
            report = load(output / "validation-report.json") if (output / "validation-report.json").is_file() else {}
            issues = report.get("issues", [])
            matching = [x for x in issues if x.get("code") == expected and
                        (required_source is None or (x.get("input_path") == required_source and
                         str(x.get("input_pointer", "")).endswith("/source_data/town")))]
            hash_errors = [x for x in issues if x.get("code") in
                           {"MANIFEST_INTEGRITY", "T16_CONTENT_HASH_MISMATCH"}]
            results.append({"probe": name, "expected_issue": expected,
                            "return_code": run.returncode,
                            "expected_diagnostic_found": bool(matching),
                            "fixture_manifest_errors": len(hash_errors),
                            "status": "PASS" if run.returncode == 1 and matching and not hash_errors else "FAIL",
                            "matching_diagnostics": matching,
                            "stdout": run.stdout.strip(),
                            "stderr_present": bool(run.stderr.strip())})
    unchanged = before == snapshot(root)
    code_unchanged = converter_sha == digest(converter)
    passed = unchanged and code_unchanged and all(x["status"] == "PASS" for x in results)
    result = {"schema_version": "1.0.0", "status": "PASS" if passed else "FAIL",
              "scope": "Five bounded offline data-contract probes on disposable copies; not game negative/fault/concurrency tests or native evidence.",
              "source_input_unchanged": unchanged, "converter_unchanged": code_unchanged,
              "converter_sha256": converter_sha, "input_manifest_sha256": before["MANIFEST.json"],
              "fixtures_are_native_evidence": False, "game_or_server_executed": False,
              "historical_scripts_executed": False, "probes": results}
    if report_path:
        report_path.parent.mkdir(parents=True, exist_ok=True)
        with report_path.open("x", encoding="utf-8") as stream:
            json.dump(result, stream, ensure_ascii=False, indent=2)
            stream.write("\n")
    print(json.dumps({"status": result["status"], "probes": len(results),
                      "source_input_unchanged": unchanged,
                      "failed": [x["probe"] for x in results if x["status"] != "PASS"]}))
    return 0 if passed else 1


if __name__ == "__main__":
    raise SystemExit(main())
