#!/usr/bin/env python3
"""Read-only aggregate verifier for MEF runtime-contract evidence."""
import argparse
from collections import defaultdict
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
ENV = dict(os.environ, GIT_NO_LAZY_FETCH="1", GIT_OPTIONAL_LOCKS="0",
           GIT_TERMINAL_PROMPT="0", GIT_NO_REPLACE_OBJECTS="1", PYTHONDONTWRITEBYTECODE="1")


def check(ok, message):
    if not ok:
        raise AssertionError(message)


def sha(data):
    return hashlib.sha256(data).hexdigest()


def load(path):
    return json.loads(path.read_text(encoding="utf-8"))


def pins_in(value):
    """Normalize identity records; do not infer that a pinned source was read."""
    if isinstance(value, dict):
        if all(k in value for k in ("commit", "path")) and ("git_blob" in value or "blob" in value):
            yield value["commit"], value["path"], value.get("git_blob", value.get("blob"))
        if all(k in value for k in ("repo_commit", "repo_path", "repo_blob")):
            yield value["repo_commit"], value["repo_path"], value["repo_blob"]
        for child in value.values():
            yield from pins_in(child)
    elif isinstance(value, list):
        for child in value:
            yield from pins_in(child)


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--originals", type=Path, required=True)
    ap.add_argument("--repo", type=Path, required=True)
    ap.add_argument("--coroutine", type=Path)
    args = ap.parse_args()
    repo, originals = args.repo.resolve(), args.originals.resolve()
    manifest = load(HERE / "source-manifest.json")
    artifact = load(HERE / "artifact-manifest.json")
    for row in artifact["files"]:
        path = repo / row["path"]
        data = path.read_bytes()
        check(len(data) == row["bytes"] and sha(data) == row["sha256"], "artifact hash: " + row["path"])
    for row in manifest["originals"]:
        data = (originals / row["file"]).read_bytes()
        check(len(data) == row["bytes"] and sha(data) == row["sha256"], "original: " + row["file"])

    normalized = {}
    for subgroup in manifest["subgroups"]:
        file = HERE / subgroup["manifest"]
        check(sha(file.read_bytes()) == subgroup["sha256"], "subgroup manifest hash")
        for commit, path, blob in pins_in(load(file)):
            key = (commit, path)
            check(key not in normalized or normalized[key] == blob, "conflicting source pin: " + path)
            normalized[key] = blob
    by_commit = defaultdict(dict)
    for (commit, path), blob in normalized.items():
        by_commit[commit][path] = blob
    for commit, expected in by_commit.items():
        output = subprocess.check_output(["git", "ls-tree", "-r", commit, "--", *sorted(expected)],
                                         cwd=repo, env=ENV, text=True)
        actual = {}
        for line in output.splitlines():
            header, path = line.split("\t", 1)
            actual[path] = header.split()[2]
        check(actual == expected, "source tree identities: " + commit)

    def run(script, options):
        process = subprocess.run([sys.executable, "-B", str(HERE / script), *map(str, options)],
                                 cwd=repo, env=ENV, capture_output=True, text=True)
        check(process.returncode == 0, script + " failed:\n" + process.stdout + process.stderr)
        result = json.loads(process.stdout)
        check(result.get("status") == "PASS", "missing verification success: " + script)
        return result

    scheduler_options = ["--repo", repo, "--sources", originals]
    if args.coroutine:
        scheduler_options += ["--coroutine", args.coroutine.resolve()]
    results = {
        "scheduler": run("scheduler/verify_evidence.py", scheduler_options),
        "input-lifecycle": run("input-lifecycle/verify_evidence.py", ["--bin", originals / "02-Tartaros.bin",
            "--event-stp", originals / "06-Event.stp", "--repo", repo]),
        "ui-lifecycle": run("ui-lifecycle/reproduce.py", ["--bin", originals / "02-Tartaros.bin",
            "--repo", repo, "--check-deliverables"]),
        "vm-lifetime": run("vm-lifetime/verify_evidence.py", ["--bin", originals / "02-Tartaros.bin", "--repo", repo]),
    }

    code_count = instruction_count = 0
    for row in load(HERE / "scheduler/native-windows.json")["windows"]:
        if row["kind"] != "code":
            continue
        start, end = int(row["va"], 16), int(row["end_exclusive"], 16)
        output = subprocess.check_output(["objdump", "-d", "-M", "intel", "--insn-width=16",
            "--start-address=" + hex(start), "--stop-address=" + hex(end + 15), str(originals / "02-Tartaros.bin")],
            env=ENV, text=True)
        cursor, data = start, bytearray()
        for line in output.splitlines():
            m = re.match(r"^\s*([0-9a-f]+):\s*((?:[0-9a-f]{2}\s+)+)\s*(.*)$", line)
            if not m:
                continue
            va = int(m[1], 16)
            if va >= end:
                break
            code = bytes.fromhex(m[2])
            check(va == cursor and "(bad)" not in m[3] and not m[3].startswith(".byte"), "scheduler instruction decode")
            cursor += len(code)
            data.extend(code)
            instruction_count += 1
        check(cursor == end and data.hex() == row["hex"], "scheduler complete instruction endpoint: " + row["id"])
        code_count += 1

    md_files = [repo / manifest["primary_report"], *sorted(HERE.rglob("*.md"))]
    link_count, tree_only = 0, []
    for file in md_files:
        text = file.read_text(encoding="utf-8")
        for target in re.findall(r"(?<!!)\[[^\]]+\]\(([^\s)]+)(?:\s+[^)]*)?\)", text):
            if re.match(r"^[a-zA-Z][a-zA-Z0-9+.-]*:", target) or target.startswith("#"):
                continue
            local = (file.parent / target.split("#", 1)[0]).resolve()
            check(local.is_relative_to(repo), "link outside repository: " + target)
            link_count += 1
            if local == HERE / "verification-result.json":
                # This aggregate output is created only after this verifier succeeds.
                continue
            if local.exists():
                continue
            path = local.relative_to(repo).as_posix()
            entry = subprocess.check_output(["git", "ls-tree", manifest["work_parent"], "--", path],
                                            cwd=repo, env=ENV, text=True).strip()
            check(bool(entry) and entry.split("\t", 1)[1] == path, "missing evidence link: " + target)
            tree_only.append(path)

    print(json.dumps({
        "status": "PASS", "scope": "Static original-byte/prototype/source/contract verification; no Client or Lua execution",
        "work_parent": manifest["work_parent"], "main_baseline": manifest["main_baseline"],
        "artifact_files": len(artifact["files"]), "unique_commit_path_pins": len(normalized),
        "source_commits": sorted(by_commit),
        "scheduler_additional_disassembly": {"code_windows": code_count, "instruction_records": instruction_count,
            "complete_instruction_endpoints": True},
        "markdown_links": {"checked": link_count, "tree_only_sparse_paths": sorted(set(tree_only))},
        "subgroup_results": results,
        "limits": ["First new MEF caller remains unproven", "No runtime or gameplay validation", "No T01 FULL-PASS or RR status update"]
    }, ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
