#!/usr/bin/env python3
"""Check this research bundle; optionally rerun its offline evidence verifiers.

No game, Lua chunk, Server or original resource is executed or modified.
Saved evidence receipts and fresh evidence execution are reported separately.
"""
from pathlib import Path
import argparse
import ast
import hashlib
import json
import os
import re
import subprocess
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent


def require(condition, message):
    if not condition:
        raise ValueError(message)


def digest(data):
    return hashlib.sha256(data).hexdigest()


def read_json(path):
    return json.loads(path.read_text(encoding="utf-8"))


def git(repo, *args):
    return subprocess.check_output(["git", *args], cwd=repo)


def check_artifacts():
    count = 0
    for path in sorted(HERE.rglob("artifact-manifest.json")):
        manifest = read_json(path)
        for record in manifest["files"]:
            target = (path.parent / record.get("name", record.get("path", ""))).resolve()
            require(target.is_relative_to(HERE), "Artifact escaped package")
            raw = target.read_bytes()
            require(len(raw) == record["bytes"] and digest(raw) == record["sha256"],
                    "Artifact identity: " + str(target.relative_to(HERE)))
            count += 1
    root = read_json(HERE / "artifact-manifest.json")
    excluded = set(root["excluded_paths"])
    expected = {x["name"] for x in root["files"]}
    actual = {str(x.relative_to(HERE)) for x in HERE.rglob("*")
              if x.is_file() and str(x.relative_to(HERE)) not in excluded}
    require(actual == expected, "Root artifact inventory differs")
    for name in actual:
        require(Path(name).suffix in {".md", ".json", ".py", ".asm"},
                "Unexpected deliverable type: " + name)
    return count, len(expected)


def check_sources(repo):
    checked = set()
    local = set()
    cache = {}

    def walk(value, directory, commit):
        if isinstance(value, list):
            for child in value:
                walk(child, directory, commit)
            return
        if not isinstance(value, dict):
            return
        commit = value.get("commit", value.get("source_commit",
                   value.get("base_commit", value.get("research_base_commit", commit))))
        path = value.get("path")
        blob = value.get("git_blob", value.get("blob_sha"))
        raw = None
        if path and blob:
            require(bool(commit), "Git source missing commit: " + path)
            key = (commit, path)
            if key not in cache:
                actual_blob = git(repo, "rev-parse", f"{commit}:{path}").decode().strip()
                cache[key] = actual_blob, git(repo, "cat-file", "blob", actual_blob)
            actual_blob, raw = cache[key]
            require(actual_blob == blob, "Pinned Git blob: " + path)
            checked.add(key)
        elif value.get("kind") == "same_batch_file":
            require(isinstance(value.get("sha256"), str) and
                    re.fullmatch(r"[0-9a-f]{64}", value["sha256"]) is not None and
                    isinstance(value.get("bytes", value.get("size")), int),
                    "Same-batch source requires SHA-256 and byte length: " + str(path))
            target = (directory / path).resolve()
            require(target.is_relative_to(HERE), "Same-batch source escaped package")
            raw = target.read_bytes()
            local.add(str(target.relative_to(HERE)))
        if raw is not None:
            size = value.get("bytes", value.get("size"))
            if size is not None:
                require(len(raw) == size, "Source bytes: " + path)
            if "sha256" in value:
                require(digest(raw) == value["sha256"], "Source SHA-256: " + path)
        if isinstance(value.get("result"), str) and "result_sha256" in value:
            target = (directory / value["result"]).resolve()
            require(target.is_relative_to(HERE), "Cross-package result escaped bundle")
            require(digest(target.read_bytes()) == value["result_sha256"],
                    "Cross-package result SHA-256: " + value["result"])
            local.add(str(target.relative_to(HERE)))
        for child in value.values():
            if isinstance(child, (dict, list)):
                walk(child, directory, commit)

    for path in sorted(HERE.rglob("source-manifest.json")):
        manifest = read_json(path)
        walk(manifest, path.parent, manifest.get("baseline_head"))
    return len(checked), len(local)


def check_links_and_syntax(repo, baseline):
    checked_links = set()
    json_count = 0
    python_count = 0
    for path in sorted(HERE.rglob("*")):
        if not path.is_file():
            continue
        if path.suffix == ".json":
            read_json(path)
            json_count += 1
        elif path.suffix == ".py":
            ast.parse(path.read_text(), filename=str(path))
            python_count += 1
        elif path.suffix == ".md":
            for target in re.findall(r"\]\(([^)]+)\)", path.read_text()):
                if re.match(r"[a-zA-Z][a-zA-Z0-9+.-]*:", target) or target.startswith("#"):
                    continue
                target = target.split("#", 1)[0]
                resolved = (path.parent / target).resolve()
                require(resolved.is_relative_to(repo), "Document link escaped repository")
                key = str(resolved.relative_to(repo))
                if not resolved.exists():
                    git(repo, "cat-file", "-e", f"{baseline}:{key}")
                checked_links.add(key)
    return len(checked_links), json_count, python_count


def check_cross_tables():
    abi = read_json(HERE / "abi/abi-contracts.json")["bindings"]
    queries = read_json(HERE / "events/observation-catalog.json")["records"]
    navigation = read_json(HERE / "function-map/function-coverage.json")
    a = {row["name"]: row for row in abi}
    q = {row["name"]: row for row in queries}
    n = {row["name"]: row for row in navigation["records"]}
    require(len(abi) == len(a) == len(n) == len(navigation["records"]) == 121,
            "121 unique normal names")
    require(set(a) == set(n), "ABI and function navigation name sets")
    numbers = {name for name, row in a.items() if row["produces_new_lua_value"]}
    require(len(numbers) == 17 and numbers - {"lb.DoFile"} == set(q) and len(queries) == len(q) == 16,
            "16 query producers plus loader")
    for name, row in a.items():
        require(int(row["native"], 16) == int(n[name]["native"], 16), "Native: " + name)
        require(row["argument_kinds"] == n[name]["argument_kinds"], "ABI: " + name)
        require(row["produces_new_lua_value"] == n[name]["produces_new_lua_value"],
                "Value producer: " + name)
        require(n[name]["is_stub"] == (row["binding_status"] == "STUB"),
                "Stub classification: " + name)
        require(n[name]["is_observation_query"] == (name in q),
                "Query classification: " + name)
        require(set(n[name]["layers"]) == {"client_reverse", "server_development",
                                           "integration", "play_validation"},
                "Four explicit completion layers: " + name)
        if name in q:
            require(int(row["native"], 16) == int(q[name]["native"], 16), "Query: " + name)
    require(len({row["domain"] for row in n.values()}) == 15, "15 functional domains")
    require(sum(row["is_stub"] for row in n.values()) == 4, "Four explicit stubs")
    review = (HERE / "events/review-note.md").read_text()
    matches = re.findall(r"\| `([^`]+)` \| `([0-9a-f]{64})` \|", review)
    require(len(matches) == 4, "ABI review hashes")
    for filename, expected in matches:
        require(digest((HERE / "abi" / filename).read_bytes()) == expected,
                "ABI cross-review version: " + filename)
    return {"normal_names": 121, "functional_domains": 15, "number_producers": 17,
            "observation_queries": 16, "no_new_binding_value": 104,
            "confirmed_stubs": 4, "cross_review_file_hashes": 4}


def check_receipts(runs):
    receipts = []
    for run in runs:
        require(run["stdout_format"] in {"json", "text"}, "Known verifier stdout format")
        result = read_json(HERE / run["receipt"])
        for field, expected in run["required_fields"].items():
            require(result.get(field) == expected, "Evidence receipt: " + run["name"] + "." + field)
        receipts.append({"name": run["name"], "receipt": run["receipt"],
                         "sha256": digest((HERE / run["receipt"]).read_bytes())})
    return receipts


def rerun_evidence(args, runs):
    require(args.sources and args.supplemental, "--run-evidence needs both source directories")
    substitutions = {"python": sys.executable, "repo": str(args.repo),
                     "sources": str(args.sources.resolve()),
                     "supplemental": str(args.supplemental.resolve())}
    env = dict(os.environ, PYTHONDONTWRITEBYTECODE="1")
    executed = []
    for run in runs:
        directory = (HERE / run["cwd"]).resolve()
        require(directory.is_relative_to(HERE), "Verifier cwd escaped package")
        argv = [part.format(**substitutions) for part in run["argv"]]
        require(argv[:2] == [sys.executable, "-B"] and
                argv[2] in {"verify_evidence.py", "check_validation.py"},
                "Only declared offline verifiers may execute")
        old = read_json(HERE / run["receipt"])
        completed = subprocess.run(argv, cwd=directory, env=env, capture_output=True,
                                   text=True, timeout=300, check=False)
        require(completed.returncode == 0, "Verifier failed: " + run["name"] + "\n" +
                (completed.stderr or completed.stdout)[-5000:])
        if run["stdout_format"] == "json":
            require(json.loads(completed.stdout) == old, "Recomputed receipt differs: " + run["name"])
        else:
            require(read_json(HERE / run["receipt"]) == old, "Recomputed fixture differs")
        executed.append(run["name"])
    return executed


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--repo", type=Path, required=True)
    parser.add_argument("--run-evidence", action="store_true")
    parser.add_argument("--sources", type=Path)
    parser.add_argument("--supplemental", type=Path)
    parser.add_argument("--result", type=Path)
    args = parser.parse_args()
    args.repo = args.repo.resolve()
    require(HERE.is_relative_to(args.repo), "Package must be within the research repository")
    if args.result:
        args.result = args.result.resolve()
        require(args.result.suffix == ".json", "Result must be a derived JSON file")
        require(not args.result.is_relative_to(HERE) or args.result == HERE / "verification-result.json",
                "Result must not overwrite package evidence or source files")
        for directory in (args.sources, args.supplemental):
            if directory:
                require(not args.result.is_relative_to(directory.resolve()),
                        "Result must not overwrite a source directory")
    sources = read_json(HERE / "source-manifest.json")
    runs = read_json(HERE / "evidence-runs.json")["runs"]
    artifact_checks, files = check_artifacts()
    git_pins, same_batch = check_sources(args.repo)
    links, json_files, python_files = check_links_and_syntax(args.repo, sources["base_commit"])
    cross = check_cross_tables()
    receipts = check_receipts(runs)
    executed = rerun_evidence(args, runs) if args.run_evidence else []
    # A verifier must not silently rewrite evidence or source inputs.
    if executed:
        check_artifacts()
    result = {"schema": "mef-comprehensive-package-verification-v1", "status": "PASS",
              "scope": "Research artifact integrity, pinned sources, cross-table contracts and saved evidence receipts; optional explicit offline reexecution only",
              "base_commit": sources["base_commit"], "artifact_files": files,
              "artifact_integrity_checks_including_submanifests": artifact_checks,
              "distinct_pinned_git_sources": git_pins, "same_batch_source_files": same_batch,
              "document_targets_checked": links, "json_files_parsed": json_files,
              "python_files_syntax_checked": python_files, "cross_tables": cross,
              "evidence_receipts": receipts, "evidence_reexecuted_by_this_invocation": executed,
              "client_executed": False, "lua_executed": False, "server_executed": False,
              "deployment_ready": False, "gameplay_verified": False,
              "official_mef_grammar_proved": False, "formal_status_changed": False}
    if args.result:
        args.result.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n")
    print(json.dumps(result, ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
