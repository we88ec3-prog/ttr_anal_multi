#!/usr/bin/env python3
"""Read-only RR submission preflight. No native semantics or Server compatibility verdict."""
from __future__ import annotations

import argparse
import hashlib
import json
import re
from pathlib import Path, PurePosixPath

from phase_b_worklist import evaluate as worklist_evaluate

ROOT = Path(__file__).resolve().parents[1]
SHA1 = re.compile(r"^[0-9a-f]{40}$")
REPORT_STATES = {"SUBMITTED", "IN_REVIEW", "NEEDS_REVISION", "ACCEPTED"}
DECIDED = {"ACCEPTED", "NEEDS_REVISION"}


def _load(root: Path, path: str):
    return json.loads((root / path).read_text(encoding="utf-8"))


def _safe_source(root: Path, path: str):
    """Reject absolute, traversal, Windows separator and symlink escapes."""
    if not isinstance(path, str) or not path or "\\" in path:
        return None
    rel = PurePosixPath(path)
    if rel.is_absolute() or any(x in {".", ".."} for x in rel.parts):
        return None
    target = (root / path).resolve()
    if not target.is_relative_to(root.resolve()) or not target.is_file():
        return None
    return target


def _blob_sha(data: bytes):
    return hashlib.sha1(b"blob " + str(len(data)).encode() + b"\x00" + data).hexdigest()


def _report_integrity(root: Path, submission):
    errors = []
    if not isinstance(submission, dict):
        return None, ["missing RR submission metadata"]
    path = submission.get("report_path")
    sha = submission.get("report_blob_sha")
    file = _safe_source(root, path)
    if file is None:
        errors.append("missing or unsafe submitted report path")
    if not isinstance(sha, str) or not SHA1.fullmatch(sha):
        errors.append("missing or invalid submission Git blob SHA")
    if file is not None and isinstance(sha, str) and SHA1.fullmatch(sha):
        if _blob_sha(file.read_bytes()) != sha:
            errors.append("submitted report Git blob SHA mismatch")
    return {"path": path, "sha": sha, "file_exists": file is not None}, errors


def evaluate(root: Path = ROOT, *, rr_id: str | None = None,
             task: str | None = None, version: str = "kr"):
    """Produce actionable, non-normative manual review questions from committed indices."""
    base = worklist_evaluate(root, task=task, version=version)
    errors = list(base["errors"])
    try:
        rr = {x["id"]: x for x in _load(root, "research/requests/index.json")["items"]}
        gaps = {x["id"]: x for x in _load(root, "design/gaps/index.json")["items"]}
        specs = {x["id"]: x for x in _load(root, "spec/spec-index.json")["items"]}
        cov = {x["id"]: x for x in _load(root, "conformance/contract-coverage.json")["items"]}
        tests = {x["id"]: x for x in _load(root, "conformance/test-index.json")["items"]}
        targets = _load(root, "shared/targets.json")
    except (OSError, ValueError, KeyError, TypeError) as exc:
        return {"errors": sorted(set(errors + [f"cannot load review inputs: {exc}"])),
                "summary": {}, "items": []}
    selected = base["requests"]
    if rr_id is not None:
        selected = [row for row in selected if row["rr_id"] == rr_id]
        if not selected:
            errors.append(f"RR {rr_id} not found in selected Task/version scope")
    items = []
    for row in selected:
        rid = row["rr_id"]
        source = rr[rid]
        state = row["dispatch_state"]
        d = source.get("dispatch") or {}
        err = []
        sub = None
        if state in REPORT_STATES:
            sub, err = _report_integrity(root, d.get("submission"))
            errors.extend(f"{rid}: {reason}" for reason in err)
        # This is about artifact presence and reference integrity only;
        # it does not parse or certify original binary semantics.
        if err:
            result = "INVALID_SUBMISSION"
        elif state in {"SUBMITTED", "IN_REVIEW"}:
            result = "ARTIFACT_PRESENT_FOR_MANUAL_REVIEW"
        elif state in DECIDED:
            result = "RECORDED_DECISION_NOT_SPEC_APPROVAL"
        else:
            result = "NOT_SUBMITTED"
        issue_specs = [
            {"id": sid, "maturity": specs[sid]["maturity"],
             "contract_status": specs[sid]["contract_status"],
             "unknowns": specs[sid].get("unknowns", []),
             "test_ids": specs[sid].get("test_ids", [])}
            for sid in row["spec_ids"] if sid in specs
        ]
        issue_gaps = [
            {"id": gid, "status": gaps[gid]["status"],
             "resolution_criteria": gaps[gid].get("resolution_criteria", "")}
            for gid in row["gap_ids"] if gid in gaps
        ]
        issue_cov = [
            {"id": cid, "facets": cov[cid].get("facets", {})}
            for cid in row["coverage_ids"] if cid in cov
        ]
        issue_tests = [
            {"id": tid, "status": tests[tid]["status"]}
            for tid in row["test_ids"] if tid in tests
        ]
        if row["target_sha256"] != targets.get(row["client_version"], {}).get("sha256"):
            errors.append(f"{rid}: original target SHA differs from registered version")
        items.append({
            "rr_id": rid, "owner_task": row["owner_task"],
            "client_version": row["client_version"],
            "target_sha256": row["target_sha256"],
            "dispatch_state": state,
            "mechanical_preflight": result,
            "artifact": sub,
            "artifact_errors": err,
            "research_criteria": d.get("acceptance_criteria"),
            "direct_specs": issue_specs,
            "gaps": issue_gaps,
            "coverage": issue_cov,
            "tests": issue_tests,
            "milestone_context_only": row["milestone_ids"],
            "review_steps": [
                "T01: verify version, original SHA, report blob, relevant native function/offset, branches and contradictions.",
                "S00: compare bounded finding against every specific RR acceptance condition; preserve unproven values as UNKNOWN.",
                "S00: separately review direct SPEC fields, GAP closure criteria, COV facets and TEST provenance.",
                "S00: if a decision is published, synchronize canonical RR dispatch and review ledger; do not auto-promote SPEC.",
            ] if state in REPORT_STATES else [
                "No submitted research to review. Do not fabricate evidence, verdict or report.",
            ],
        })
    return {
        "schema": "s00-phase-b-submission-preflight-v1",
        "policy": "Read-only structural review packet. ARTIFACT_PRESENT is not accepted, native verified, spec stable, or Client/Server compatible.",
        "errors": sorted(set(errors)),
        "summary": {
            "selected": len(items),
            "pending_manual_review": sum(x["mechanical_preflight"] == "ARTIFACT_PRESENT_FOR_MANUAL_REVIEW" for x in items),
            "invalid_submissions": sum(x["mechanical_preflight"] == "INVALID_SUBMISSION" for x in items),
            "not_submitted": sum(x["mechanical_preflight"] == "NOT_SUBMITTED" for x in items),
        },
        "items": items,
    }


def markdown(report):
    lines = [
        "# S00 — RR submission preflight (non-normative)",
        "",
        "> File integrity alone does not establish native meaning, original Client compatibility or a published RR decision.",
        "",
        f"Items: {report['summary'].get('selected', 0)}; "
        f"artifact-present for manual review: {report['summary'].get('pending_manual_review', 0)}; "
        f"invalid: {report['summary'].get('invalid_submissions', 0)}.",
        "",
    ]
    for item in report["items"]:
        lines.extend([
            f"## {item['rr_id']} / {item['owner_task']} — {item['mechanical_preflight']}",
            f"- Version / target: {item['client_version']} / {item['target_sha256']}",
            f"- Dispatch state: {item['dispatch_state']}",
            f"- Submission: {item['artifact']['path'] if item['artifact'] else 'NONE'}",
            f"- Git blob: {item['artifact']['sha'] if item['artifact'] else 'NONE'}",
            f"- Direct SPEC: {', '.join(s['id'] for s in item['direct_specs']) or 'NONE'}",
            f"- GAP: {', '.join(g['id'] for g in item['gaps']) or 'NONE'}",
            f"- COV: {', '.join(c['id'] for c in item['coverage']) or 'NONE'}",
            f"- TEST: {', '.join(t['id'] + '=' + t['status'] for t in item['tests']) or 'NONE'}",
            f"- Milestones (context only): {', '.join(item['milestone_context_only']) or 'NONE'}",
            "- Original RR completion conditions:",
            item["research_criteria"] or "UNKNOWN",
            "- Manual-review steps:",
        ])
        lines.extend(f"  - {step}" for step in item["review_steps"])
        lines.extend(f"- Artifact error: {e}" for e in item["artifact_errors"])
        lines.append("")
    if report["errors"]:
        lines.extend(["## Structural errors", *[f"- {x}" for x in report["errors"]]])
    return "\n".join(lines) + "\n"


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--root", type=Path, default=ROOT)
    p.add_argument("--rr")
    p.add_argument("--task")
    p.add_argument("--version", choices=("kr", "tc"), default="kr")
    p.add_argument("--format", choices=("json", "markdown"), default="markdown")
    p.add_argument("--check", action="store_true", help="Fail only for invalid refs/recorded submission; never for queued/unknown research")
    args = p.parse_args()
    result = evaluate(args.root.resolve(), rr_id=args.rr, task=args.task, version=args.version)
    print(json.dumps(result, ensure_ascii=False, indent=2) if args.format == "json" else markdown(result))
    if args.check and result["errors"]:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
