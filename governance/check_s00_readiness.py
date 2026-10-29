#!/usr/bin/env python3
"""S00 read-only roadmap integrity and planning readiness (NOT native validation).

It never changes SPEC/RR/GAP state and cannot declare a Client-compatible Server.
The "review_candidate" result is not STABLE, ACCEPTED, tested, or released.
"""
import argparse
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
PLAN_PATH = "governance/s00-roadmap.json"
MUST = {"id", "name", "phase", "priority", "owner", "research_owners",
        "depends_on", "spec_ids", "gap_ids", "rr_ids", "test_ids",
        "acceptance", "handoff_to"}


def _load(root, path):
    return json.loads((root / path).read_text(encoding="utf-8"))


def assess(root=ROOT):
    errors = []
    def error(message):
        errors.append(message)
    plan = _load(root, PLAN_PATH)
    spec = {i["id"]: i for i in _load(root, "spec/spec-index.json")["items"]}
    gap = {i["id"]: i for i in _load(root, "design/gaps/index.json")["items"]}
    rr = {i["id"]: i for i in _load(root, "research/requests/index.json")["items"]}
    test = {i["id"]: i for i in _load(root, "conformance/test-index.json")["items"]}
    if plan.get("schema") != "s00-delivery-roadmap-v1":
        error("roadmap schema mismatch")
    if plan.get("client_version") not in {"kr", "tc"}:
        error("roadmap client_version invalid")
    target = _load(root, "shared/targets.json").get(plan.get("client_version"), {}).get("sha256")
    if plan.get("target_sha256") != target:
        error("roadmap Client SHA differs from registered target")
    items = plan.get("milestones")
    if not isinstance(items, list) or not items:
        return {"errors": errors + ["roadmap milestones must be nonempty list"], "packages": [], "summary": {}}
    ids = [m.get("id") for m in items if isinstance(m, dict)]
    if len(ids) != len(items) or len(set(ids)) != len(ids):
        error("duplicate or invalid milestone ID")
    ordered = {x["id"]: x for x in items if isinstance(x, dict) and isinstance(x.get("id"), str)}
    for m in items:
        if not isinstance(m, dict):
            error("milestone is not an object")
            continue
        mid = m["id"]
        if not MUST.issubset(m):
            error(f"{mid}: missing mandatory fields {sorted(MUST - set(m))}")
            continue
        if m["phase"] not in {"B", "C", "D", "E"}:
            error(f"{mid}: invalid phase")
        if not isinstance(m["priority"], int) or m["priority"] < 0:
            error(f"{mid}: invalid priority")
        if not isinstance(m["acceptance"], list) or not m["acceptance"] or not all(isinstance(x, str) and x.strip() for x in m["acceptance"]):
            error(f"{mid}: missing explicit acceptance conditions")
        for attr, table in [("spec_ids", spec), ("gap_ids", gap), ("rr_ids", rr), ("test_ids", test)]:
            values = m[attr]
            if not isinstance(values, list):
                error(f"{mid}: {attr} must be list")
                continue
            for ref in values:
                if ref not in table:
                    error(f"{mid}: unresolved {attr} {ref}")
                    continue
                rec = table[ref]
                if rec.get("client_version") not in {None, plan["client_version"]}:
                    error(f"{mid}: cross-version {attr} {ref}")
        for dep in m["depends_on"]:
            if dep not in ordered or dep == mid:
                error(f"{mid}: unresolved/recursive dependency {dep}")
        for rid in m["rr_ids"]:
            if rid in rr and rr[rid].get("owner_task") not in m["research_owners"] and m["phase"] == "B":
                # S00 is permitted to consume another Task's RR; research_owners must list the producer.
                error(f"{mid}: missing origin research owner for {rid}")
        # Preserve acyclic graph; an RR can be used in several packages.
    colors = {}
    def visit(mid):
        if colors.get(mid) == 1:
            error(f"{mid}: roadmap dependency cycle")
            return
        if colors.get(mid) == 2:
            return
        colors[mid] = 1
        for dep in ordered[mid].get("depends_on", []):
            if dep in ordered:
                visit(dep)
        colors[mid] = 2
    for mid in ordered:
        visit(mid)

    packages = []
    for m in items:
        if not isinstance(m, dict) or not MUST.issubset(m):
            continue
        blockers = []
        for ref in m["gap_ids"]:
            if ref in gap and gap[ref].get("status") != "RESOLVED":
                blockers.append(f"{ref}={gap[ref].get('status','?')}")
        for ref in m["rr_ids"]:
            if ref in rr:
                state = rr[ref].get("dispatch", {}).get("state", "?")
                if state != "ACCEPTED":
                    blockers.append(f"{ref}={state}")
        for ref in m["spec_ids"]:
            if ref in spec:
                s = spec[ref]
                if s.get("maturity") not in {"REVIEWED", "STABLE"} or s.get("contract_status") != "DEFINED":
                    blockers.append(f"{ref}={s.get('maturity','?')}/{s.get('contract_status','?')}")
        # All current tests are synthetic. They are useful planning inputs but do
        # not fulfill evidence-backed wire or runtime acceptance on their own.
        for ref in m["test_ids"]:
            if ref in test and test[ref].get("status") == "OFFLINE_SYNTHETIC":
                blockers.append(f"{ref}=OFFLINE_SYNTHETIC_ONLY")
        for dep in m["depends_on"]:
            p = next((p for p in packages if p["id"] == dep), None)
            if p is None or p["status"] != "REVIEW_CANDIDATE":
                blockers.append(f"dependency:{dep}")
        if m["phase"] != "B":
            blockers.append("EXTERNAL_REVIEW_REQUIRED")
        if m["phase"] == "B" and not m["test_ids"]:
            blockers.append("NO_REGISTERED_CONFORMANCE_TEST")
        packages.append({"id": m["id"], "phase": m["phase"],
                         "status": "BLOCKED" if blockers else "REVIEW_CANDIDATE",
                         "blockers": blockers,
                         "spec_count": len(m["spec_ids"]),
                         "research_count": len(m["rr_ids"])})
    summary = {"specs": len(spec),
               "specs_reviewed_or_stable": sum(s["maturity"] in {"REVIEWED", "STABLE"} for s in spec.values()),
               "gaps_open": sum(g["status"] != "RESOLVED" for g in gap.values()),
               "requests_queued": sum(r.get("dispatch", {}).get("state") == "QUEUED" for r in rr.values()),
               "requests_accepted": sum(r.get("dispatch", {}).get("state") == "ACCEPTED" for r in rr.values()),
               "tests_offline_synthetic": sum(t.get("status") == "OFFLINE_SYNTHETIC" for t in test.values()),
               "packages_blocked": sum(p["status"] == "BLOCKED" for p in packages)}
    return {"errors": errors, "packages": packages, "summary": summary}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=ROOT)
    parser.add_argument("--json", action="store_true", help="machine-readable gate snapshot")
    parser.add_argument("--check", action="store_true", help="fail on roadmap reference/schema errors, NOT on blocked work")
    args = parser.parse_args()
    result = assess(args.root.resolve())
    if args.json:
        print(json.dumps(result, indent=2, ensure_ascii=False))
    else:
        print("S00 Planning Readiness (not Client/Server compatibility)")
        for p in result["packages"]:
            print(f"  {p['id']}: {p['status']}; blockers={len(p['blockers'])}")
            for reason in p["blockers"]:
                print(f"    - {reason}")
        print("Summary:", result["summary"])
        for error in result["errors"]:
            print("ERROR:", error)
    if result["errors"] and args.check:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
