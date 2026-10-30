#!/usr/bin/env python3
"""Read-only S00 REQ-backed delivery slices; blocked is not original Client compatibility."""
from __future__ import annotations

import argparse
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
PATH = "governance/s00-requirement-slices.json"
REFS = {
    "requirement_ids": ("design/requirements/index.json", "items"),
    "blocking_rr_ids": ("research/requests/index.json", "items"),
    "context_rr_ids": ("research/requests/index.json", "items"),
    "gap_ids": ("design/gaps/index.json", "items"),
    "spec_ids": ("spec/spec-index.json", "items"),
}
FIELDS = set(REFS) | {"id", "title", "priority", "depends_on", "goal",
                      "acceptance", "next_owners", "notes"}


def _read(root: Path, path: str):
    return json.loads((root / path).read_text(encoding="utf-8"))


def assess(root: Path = ROOT, requested_slice: str | None = None):
    errors = []
    try:
        plan = _read(root, PATH)
        target = _read(root, "shared/targets.json")
        tables = {
            name: {row["id"]: row for row in _read(root, path)[key]}
            for name, (path, key) in REFS.items()
        }
    except (OSError, ValueError, KeyError, TypeError) as exc:
        return {"errors": [f"unable to read canonical sources: {exc}"], "summary": {}, "slices": []}
    if plan.get("schema") != "s00-requirement-slices-v1":
        errors.append("invalid delivery slice schema")
    version = plan.get("client_version")
    if version not in {"kr", "tc"} or plan.get("target_sha256") != target.get(version, {}).get("sha256"):
        errors.append("slice plan Client target SHA/version mismatch")
    rows = plan.get("slices")
    if not isinstance(rows, list) or not rows:
        return {"errors": errors + ["slices must be nonempty"], "summary": {}, "slices": []}
    by_id = {}
    for i, row in enumerate(rows):
        if not isinstance(row, dict) or not isinstance(row.get("id"), str):
            errors.append(f"slice[{i}] is not a valid object/ID")
            continue
        ident = row["id"]
        if ident in by_id:
            errors.append(f"{ident} duplicated")
        by_id[ident] = row
        missing = FIELDS - set(row)
        if missing:
            errors.append(f"{ident} missing fields: {sorted(missing)}")
            continue
        if not isinstance(row["priority"], int) or isinstance(row["priority"], bool) or row["priority"] < 0:
            errors.append(f"{ident} priority is not nonnegative integer")
        if not isinstance(row["acceptance"], list) or not row["acceptance"] or not all(isinstance(x, str) and x.strip() for x in row["acceptance"]):
            errors.append(f"{ident} lacks acceptance criteria")
        if not isinstance(row["next_owners"], list) or not row["next_owners"]:
            errors.append(f"{ident} lacks owners")
        for field, table in tables.items():
            items = row[field]
            if not isinstance(items, list) or len(items) != len(set(map(str, items))):
                errors.append(f"{ident} {field} invalid or duplicated")
                continue
            for ref in items:
                item = table.get(ref)
                if item is None:
                    errors.append(f"{ident} {field} missing {ref}")
                elif item.get("client_version") not in {None, version}:
                    errors.append(f"{ident} {field} cross-version {ref}")
        overlap = set(row["blocking_rr_ids"]) & set(row["context_rr_ids"])
        if overlap:
            errors.append(f"{ident} repeats RR as blocking and context: {sorted(overlap)}")
    # Stable Kahn order. Cyclic graphs fail closed; table order has no semantic meaning.
    incoming = {sid: 0 for sid in by_id}
    children = {sid: [] for sid in by_id}
    for sid, row in by_id.items():
        for dep in row.get("depends_on", []):
            if dep not in by_id or dep == sid:
                errors.append(f"{sid} missing/self dependency {dep}")
            else:
                incoming[sid] += 1
                children[dep].append(sid)
    def sortkey(sid):
        return (by_id[sid].get("priority", 999), sid)
    ready = sorted((sid for sid, n in incoming.items() if n == 0), key=sortkey)
    order = []
    while ready:
        sid = ready.pop(0)
        order.append(sid)
        for next_sid in children[sid]:
            incoming[next_sid] -= 1
            if incoming[next_sid] == 0:
                ready.append(next_sid)
                ready.sort(key=sortkey)
    if len(order) < len(by_id):
        errors.append("delivery slices contain dependency cycle")
        order.extend(sorted(set(by_id) - set(order), key=sortkey))

    output = []
    status_by = {}
    for sid in order:
        row = by_id[sid]
        if not FIELDS.issubset(row):
            continue
        requirements = [tables["requirement_ids"][x] for x in row["requirement_ids"]
                        if x in tables["requirement_ids"]]
        blocking_rr = [tables["blocking_rr_ids"][x] for x in row["blocking_rr_ids"]
                       if x in tables["blocking_rr_ids"]]
        context_rr = [tables["context_rr_ids"][x] for x in row["context_rr_ids"]
                      if x in tables["context_rr_ids"]]
        gaps = [tables["gap_ids"][x] for x in row["gap_ids"] if x in tables["gap_ids"]]
        specs = [tables["spec_ids"][x] for x in row["spec_ids"] if x in tables["spec_ids"]]
        missing = []
        for r in requirements:
            if r.get("status") != "APPROVED":
                missing.append(f"{r['id']}={r.get('status','UNKNOWN')}")
        for r in blocking_rr:
            state = r.get("dispatch", {}).get("state", "UNKNOWN")
            if state != "ACCEPTED":
                missing.append(f"{r['id']}={state}")
        for g in gaps:
            if g.get("status") != "RESOLVED":
                missing.append(f"{g['id']}={g.get('status')}")
        for s in specs:
            if s.get("maturity") not in {"REVIEWED", "STABLE"} or s.get("contract_status") != "DEFINED":
                missing.append(f"{s['id']}={s.get('maturity')}/{s.get('contract_status')}")
        for dep in row["depends_on"]:
            if status_by.get(dep) != "REVIEW_CANDIDATE":
                missing.append(f"dependency:{dep}")
        status = "DISCOVERY_REQUIRED" if not row["requirement_ids"] else ("BLOCKED" if missing else "REVIEW_CANDIDATE")
        # Even REVIEW_CANDIDATE would require separate T01/S00 and permitted runtime tests.
        status_by[sid] = status
        output.append({
            "id": sid, "title": row["title"], "status": status, "goal": row["goal"],
            "requirement_ids": [r["id"] for r in requirements],
            "discovery_channels": sorted({o["channel"] for r in requirements
                                         for o in r.get("discoveries", []) if "channel" in o}),
            "blocking_rr": [{"id": r["id"], "state": r.get("dispatch", {}).get("state", "UNKNOWN")}
                            for r in blocking_rr],
            "context_rr": [{"id": r["id"], "state": r.get("dispatch", {}).get("state", "UNKNOWN")}
                           for r in context_rr],
            "open_gaps": [g["id"] for g in gaps if g.get("status") != "RESOLVED"],
            "spec_status": [{"id": s["id"], "maturity": s.get("maturity"),
                             "contract_status": s.get("contract_status")} for s in specs],
            "blockers": missing if requirements else ["NEEDS_FIRST_AUTHENTIC_REQUIREMENT_OR_CODE_FINDING"] + missing,
            "depends_on": row["depends_on"],
            "acceptance": row["acceptance"],
            "next_owners": row["next_owners"],
            "notes": row["notes"],
        })
    if requested_slice is not None:
        output = [r for r in output if r["id"] == requested_slice]
        if not output:
            errors.append(f"unknown/invalid slice {requested_slice}")
    return {
        "schema": "s00-slice-readiness-v1",
        "policy": "Planning only, never approval, native source truth or demonstrated playable Client compatibility.",
        "errors": sorted(set(errors)),
        "summary": {"selected": len(output),
                    "blocked": sum(x["status"] == "BLOCKED" for x in output),
                    "discovery_required": sum(x["status"] == "DISCOVERY_REQUIRED" for x in output),
                    "review_candidates": sum(x["status"] == "REVIEW_CANDIDATE" for x in output)},
        "slices": output,
    }


def markdown(data):
    lines = ["# S00 — REQ-based Server delivery slices (non-normative)", "",
             "> Status describes **design readiness only**; no original Client execution or wire compatibility is implied.", ""]
    for row in data["slices"]:
        lines.extend([
            f"## {row['id']}: {row['title']} [{row['status']}]",
            f"- Goal: {row['goal']}",
            f"- REQ: {', '.join(row['requirement_ids']) or 'NONE — DISCOVERY REQUIRED'}",
            f"- Discovery: {', '.join(row['discovery_channels']) or 'NONE'}",
            f"- Blocking RR: {', '.join(x['id']+'='+x['state'] for x in row['blocking_rr']) or 'NONE'}",
            f"- Context RR (not silently treated as fulfilled): {', '.join(x['id']+'='+x['state'] for x in row['context_rr']) or 'NONE'}",
            f"- Open GAP: {', '.join(row['open_gaps']) or 'NONE'}",
            f"- Unresolved gates: {', '.join(row['blockers']) or 'NONE — HUMAN REVIEW STILL REQUIRED'}",
            f"- Owners: {', '.join(row['next_owners'])}", "- Acceptance:" 
        ])
        lines.extend(f"  - {entry}" for entry in row["acceptance"])
        lines.extend([f"- Boundaries: {row['notes']}", ""])
    if data["errors"]:
        lines.extend(["## Structural errors", *["- " + e for e in data["errors"]]])
    return "\n".join(lines) + "\n"


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--root", type=Path, default=ROOT)
    p.add_argument("--slice", dest="requested_slice")
    p.add_argument("--check", action="store_true", help="Fail only for structurally inconsistent links/cycles")
    p.add_argument("--format", choices=("json", "markdown"), default="markdown")
    a = p.parse_args()
    result = assess(a.root.resolve(), a.requested_slice)
    print(json.dumps(result, indent=2, ensure_ascii=False) if a.format == "json" else markdown(result))
    if a.check and result["errors"]:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
