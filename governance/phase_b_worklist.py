#!/usr/bin/env python3
"""Read-only Phase B RR intake view. No Agent activation or contract promotion."""
from __future__ import annotations

import argparse
import json
import re
from collections import Counter
from pathlib import Path

from check_s00_readiness import assess

ROOT = Path(__file__).resolve().parents[1]
ACTIONS = {
    "QUEUED": "Task agent may propose CLAIMED on its branch; only merged main is a published claim.",
    "CLAIMED": "Assigned claimant must confirm current main and transition IN_PROGRESS.",
    "IN_PROGRESS": "Assigned claimant researches only the bounded RR and submits exact report blob.",
    "SUBMITTED": "T01/S00 should review the submitted source and compare RR acceptance criteria.",
    "IN_REVIEW": "T01/S00 should record an evidence-scoped decision; S00 owns final ACCEPTED.",
    "NEEDS_REVISION": "Source Task should address the bounded review objection; do not create a duplicate RR.",
    "BLOCKED": "S00 should identify a concrete unblock condition; do not assume an Agent is active.",
    "ACCEPTED": "S00 may assess scoped SPEC/GAP/TEST changes separately; acceptance is not stability.",
    "CANCELLED": "Preserve historical context and do not reopen without a separate approved request.",
}
PRIORITY = {"P0": 0, "P1": 1, "P2": 2, "P3": 3}


def _load(root: Path, path: str):
    return json.loads((root / path).read_text(encoding="utf-8"))


def _ids(index):
    return {x["id"]: x for x in index["items"]}


def _distinct(values):
    return sorted(set(values))


def evaluate(root: Path = ROOT, *, task: str | None = None, version: str | None = "kr"):
    """Calculate the current public RR worklist; only invalid references are errors."""
    errors = []
    if task is not None and not re.fullmatch(r"T(?:0[1-9]|1[0-6])", task):
        errors.append("task must be T01..T16")
    if version is not None and version not in {"kr", "tc"}:
        errors.append("version must be kr or tc")

    try:
        requests = _ids(_load(root, "research/requests/index.json"))
        gaps = _ids(_load(root, "design/gaps/index.json"))
        specs = _ids(_load(root, "spec/spec-index.json"))
        tests = _ids(_load(root, "conformance/test-index.json"))
        targets = _load(root, "shared/targets.json")
        coverage = _load(root, "conformance/contract-coverage.json")["items"]
        roadmap = _load(root, "governance/s00-roadmap.json")
        readiness = assess(root)
    except (OSError, ValueError, KeyError, TypeError) as exc:
        return {"errors": errors + [f"cannot load S00 indices: {exc}"],
                "summary": {}, "requests": []}

    errors.extend(readiness["errors"])
    milestone_rank = {p["id"]: i for i, p in enumerate(readiness["packages"])}
    milestones = {p["id"]: p for p in roadmap["milestones"]}

    if not isinstance(coverage, list):
        errors.append("contract coverage items must be a list")
        coverage = []

    work = []
    for rid, rr in requests.items():
        ver = rr.get("client_version")
        if ver not in {"kr", "tc"}:
            errors.append(f"{rid}: invalid client version {ver}")
        d = rr.get("dispatch", {})
        state = d.get("state")
        if state not in ACTIONS:
            errors.append(f"{rid}: unsupported dispatch state {state}")
        if d.get("priority") not in PRIORITY:
            errors.append(f"{rid}: unsupported priority {d.get('priority')}")
        for gid in rr.get("gap_ids", []):
            gap = gaps.get(gid)
            if gap is None:
                errors.append(f"{rid}: missing GAP {gid}")
            elif gap.get("client_version") != ver:
                errors.append(f"{rid}: cross-version GAP {gid}")
            elif gap.get("owner_task") != rr.get("owner_task"):
                errors.append(f"{rid}: owner mismatch with GAP {gid}")
        linked = [m for m in roadmap["milestones"] if rid in m.get("rr_ids", [])]
        # A valid RR can be a non-gating research backlog item (e.g. RR-0006).
        # Do not silently insert it into the S00 delivery roadmap.
        for m in linked:
            if m["phase"] == "B" and rr.get("owner_task") not in m.get("research_owners", []):
                errors.append(f"{rid}: missing milestone research owner {m['id']}")
        cov_rows = [c for c in coverage if rid in c.get("rr_ids", [])]
        for c in cov_rows:
            if c.get("client_version") != ver or c.get("target_sha256") != targets.get(ver, {}).get("sha256"):
                errors.append(f"{rid}: coverage version/target mismatch {c.get('id')}")
            for sid in c.get("spec_ids", []):
                if sid not in specs:
                    errors.append(f"{rid}: unknown coverage SPEC {sid}")
            for gid in c.get("gap_ids", []):
                if gid not in gaps:
                    errors.append(f"{rid}: unknown coverage GAP {gid}")

        # Contract-impact links belong to this RR, not every SPEC/TEST in a
        # shared milestone. B-CONTRACT, for example, spans multiple owners.
        relevant_spec_ids = _distinct(
            [sid for c in cov_rows for sid in c.get("spec_ids", [])]
            + [sid for gid in rr.get("gap_ids", [])
               for sid in gaps.get(gid, {}).get("affected_spec_ids", [])]
        )
        milestone_spec_ids = _distinct(
            [sid for m in linked for sid in m.get("spec_ids", [])]
        )
        related_test_ids = _distinct(
            [tid for sid in relevant_spec_ids for tid in specs.get(sid, {}).get("test_ids", [])]
        )
        for sid in relevant_spec_ids:
            s = specs.get(sid)
            if s is None:
                errors.append(f"{rid}: unknown SPEC {sid}")
            elif s.get("client_version") != ver:
                errors.append(f"{rid}: cross-version SPEC {sid}")
        for tid in related_test_ids:
            test = tests.get(tid)
            if test is None:
                errors.append(f"{rid}: unknown TEST {tid}")
            elif test.get("client_version") != ver:
                errors.append(f"{rid}: cross-version TEST {tid}")

        if task is not None and rr.get("owner_task") != task:
            continue
        if version is not None and ver != version:
            continue

        ordered_packages = sorted((m["id"] for m in linked),
                                  key=lambda mid: (milestone_rank.get(mid, 9999), mid))
        work.append({
            "rr_id": rid,
            "client_version": ver,
            "target_sha256": targets.get(ver, {}).get("sha256"),
            "owner_task": rr.get("owner_task"),
            "title": rr.get("title", ""),
            "priority": d.get("priority"),
            "dispatch_state": state,
            "next_action": ACTIONS.get(state, "Invalid state: stop"),
            "published_claim": d.get("claim") if state not in {"QUEUED", "CANCELLED"} else None,
            "has_submission": bool(d.get("submission")),
            "request_question": rr.get("question", ""),
            "acceptance_criteria": d.get("acceptance_criteria", ""),
            "gap_ids": _distinct(rr.get("gap_ids", [])),
            "spec_ids": relevant_spec_ids,
            "milestone_spec_ids": milestone_spec_ids,
            "coverage_ids": _distinct(c["id"] for c in cov_rows),
            "test_ids": related_test_ids,
            "milestone_ids": ordered_packages,
            "delivery_mapping": "MILESTONE" if ordered_packages else "RESEARCH_BACKLOG",
            "blocked_milestones": [mid for mid in ordered_packages
                                    if milestone_rank.get(mid) is None or
                                    next((p["status"] for p in readiness["packages"] if p["id"] == mid), "BLOCKED") == "BLOCKED"],
        })

    work.sort(key=lambda x: (
        0 if x["dispatch_state"] in {"SUBMITTED", "IN_REVIEW"} else 1,
        PRIORITY.get(x["priority"], 999),
        min((milestone_rank.get(mid, 9999) for mid in x["milestone_ids"]), default=9999),
        x["owner_task"] or "",
        x["rr_id"]))
    counts = Counter(x["dispatch_state"] for x in work)
    return {
        "schema": "s00-phase-b-readonly-worklist-v1",
        "policy": "Read-only. Not an RR ledger, Agent wakeup, published claim, original native verification, or Server compatibility assessment.",
        "errors": _distinct(errors),
        "summary": {
            "selected_requests": len(work),
            "states": dict(sorted(counts.items())),
            "new_submissions": sum(x["dispatch_state"] in {"SUBMITTED", "IN_REVIEW"} for x in work),
            "ready_to_be_claimed": counts.get("QUEUED", 0),
            "blocked_phase_b_packages": sum(x["status"] == "BLOCKED" and x["phase"] == "B"
                                            for x in readiness["packages"]),
            "research_backlog_without_milestone": sum(
                x["delivery_mapping"] == "RESEARCH_BACKLOG" for x in work),
            "target_version_filter": version,
            "task_filter": task,
        },
        "requests": work,
    }


def markdown(report):
    lines = [
        "# S00 Phase B — read-only intake worklist",
        "",
        "> Generated from committed registries. Not a claim, acceptance decision, or real Client test.",
        "",
        f"Selected RR: {report['summary'].get('selected_requests', 0)}; "
        f"review queue: {report['summary'].get('new_submissions', 0)}; "
        f"queued: {report['summary'].get('ready_to_be_claimed', 0)}.",
        "",
        "| RR | Owner | Priority | State | Milestones | Coverage |",
        "| --- | --- | --- | --- | --- | --- |",
    ]
    for row in report["requests"]:
        lines.append(f"| {row['rr_id']} | {row['owner_task']} | {row['priority']} | "
                     f"{row['dispatch_state']} | {', '.join(row['milestone_ids']) or '—'} | "
                     f"{', '.join(row['coverage_ids']) or '—'} |")
    for row in report["requests"]:
        lines += ["", f"## {row['rr_id']}: {row['title']}",
                  f"- Next: {row['next_action']}",
                  f"- Evidence scope: {row['client_version']} / {row['target_sha256']}",
                  f"- Gaps: {', '.join(row['gap_ids']) or 'none'}",
                  f"- Directly related specs (GAP/COV links): {', '.join(row['spec_ids']) or 'none'}",
                  f"- Broader milestone specs (context only): {', '.join(row['milestone_spec_ids']) or 'none'}",
                  f"- Tests linked to directly related specs: {', '.join(row['test_ids']) or 'none'}",
                  f"- Acceptance criteria (from authoritative RR): {row['acceptance_criteria'] or 'UNSPECIFIED'}"]
    if report["errors"]:
        lines += ["", "## Integrity errors", *[f"- {e}" for e in report["errors"]]]
    return "\n".join(lines) + "\n"


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=ROOT)
    parser.add_argument("--task", help="Optional task filter, T01..T16")
    parser.add_argument("--version", choices=("kr", "tc"), default="kr")
    parser.add_argument("--format", choices=("json", "markdown"), default="markdown")
    parser.add_argument("--check", action="store_true", help="Fail only for inconsistent links, not open work")
    args = parser.parse_args()
    report = evaluate(args.root.resolve(), task=args.task, version=args.version)
    print(json.dumps(report, ensure_ascii=False, indent=2) if args.format == "json" else markdown(report))
    if args.check and report["errors"]:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
