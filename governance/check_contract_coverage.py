#!/usr/bin/env python3
"""Validate/inspect S00 contract coverage, without changing any registry state.

A BLOCKED result is correct until supporting source, RR, GAP, SPEC, and
non-synthetic contract tests exist. This does NOT validate native semantics.
"""
import argparse
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
COVERAGE = "conformance/contract-coverage.json"
FACETS = {
    "command_identity", "connection_context", "byte_layout",
    "request_reply_pairing", "error_semantics", "test_provenance",
}
STATUSES = {"UNKNOWN", "PARTIAL", "EVIDENCE_BACKED", "NOT_APPLICABLE",
            "OFFLINE_ONLY", "NONE"}
KINDS = {"TRANSPORT", "APPLICATION", "CLIENT_RESOURCE"}

def _read(root, path):
    return json.loads((root / path).read_text(encoding="utf-8"))

def evaluate(root=ROOT):
    result = {"errors": [], "contracts": [], "summary": {}}
    errors = result["errors"]
    try:
        registry = _read(root, COVERAGE)
        specs = {r["id"]: r for r in _read(root, "spec/spec-index.json")["items"]}
        gaps = {r["id"]: r for r in _read(root, "design/gaps/index.json")["items"]}
        requests = {r["id"]: r for r in _read(root, "research/requests/index.json")["items"]}
        tests = {r["id"]: r for r in _read(root, "conformance/test-index.json")["items"]}
        claims = {r["id"]: r for r in _read(root, "research/claims/index.json")["items"]}
        sources = {r["id"]: r for r in _read(root, "research/intake/index.json")["items"]}
        target = _read(root, "shared/targets.json")
    except (OSError, ValueError, KeyError, TypeError) as exc:
        errors.append(f"failed loading coverage sources: {exc}")
        return result
    if registry.get("schema") != "s00-contract-coverage-v1":
        errors.append("unsupported coverage schema")
    rows = registry.get("items")
    if not isinstance(rows, list) or not rows:
        errors.append("coverage items must be nonempty array")
        return result
    seen = set()
    for i, row in enumerate(rows):
        if not isinstance(row, dict):
            errors.append(f"coverage[{i}] not an object")
            continue
        label = row.get("id")
        if not isinstance(label, str) or not label.startswith("COV-") or label in seen:
            errors.append(f"bad or duplicate coverage ID at index {i}")
            continue
        seen.add(label)
        reasons = []
        kind = row.get("kind")
        if kind not in KINDS:
            errors.append(f"{label}: unsupported kind")
        ver = row.get("client_version")
        if ver not in {"kr", "tc"} or row.get("target_sha256") != target.get(ver, {}).get("sha256"):
            errors.append(f"{label}: Client version/SHA mismatch")
        if not row.get("name") or not row.get("notes"):
            errors.append(f"{label}: purpose and uncertainty note required")
        facets = row.get("facets")
        if not isinstance(facets, dict) or set(facets) != FACETS:
            errors.append(f"{label}: facet fields must exactly match coverage schema")
            continue
        for name, state in facets.items():
            if state not in STATUSES:
                errors.append(f"{label}: invalid facet state {name}={state}")
                continue
            if state == "NOT_APPLICABLE" and not (name == "command_identity" and kind in {"TRANSPORT", "CLIENT_RESOURCE"}):
                errors.append(f"{label}: illegal NOT_APPLICABLE on {name}")
            if state in {"OFFLINE_ONLY", "NONE"} and name != "test_provenance":
                errors.append(f"{label}: test-only state on {name}")
            if name == "test_provenance" and state == "PARTIAL":
                errors.append(f"{label}: use explicit OFFLINE_ONLY/NONE for incomplete test provenance")
            if state == "EVIDENCE_BACKED":
                refs = row.get("evidence_refs")
                if not isinstance(refs, list) or not refs:
                    errors.append(f"{label}: EVIDENCE_BACKED facet needs explicit proof references")
                else:
                    for cid in refs:
                        claim = claims.get(cid) if isinstance(cid, str) else None
                        if claim is None:
                            errors.append(f"{label}: unregistered evidence claim {cid}")
                            reasons.append(f"claim:{cid}=UNVERIFIED")
                            continue
                        src = sources.get(claim.get("source_intake_id"))
                        if (claim.get("client_version") != ver or
                                claim.get("target_sha256") != row.get("target_sha256") or
                                src is None or src.get("client_version") != ver or
                                src.get("target_sha256") != row.get("target_sha256") or
                                claim.get("source_file") != src.get("source_file") or
                                claim.get("source_blob_sha") != src.get("source_blob_sha") or
                                cid not in src.get("claim_ids", [])):
                            errors.append(f"{label}: evidence claim {cid} source/target lineage mismatch")
                            reasons.append(f"claim:{cid}=SOURCE_MISMATCH")
                        if (claim.get("evidence_level") != "NATIVE_VERIFIED" or
                                not claim.get("native_review_ref") or not claim.get("evidence_refs")):
                            errors.append(f"{label}: evidence claim {cid} lacks scoped native review")
                            reasons.append(f"claim:{cid}=NOT_NATIVE_VERIFIED")
            if state not in {"EVIDENCE_BACKED", "NOT_APPLICABLE"}:
                reasons.append(f"facet:{name}={state}")
        for field, table in [("spec_ids", specs), ("gap_ids", gaps), ("rr_ids", requests)]:
            values = row.get(field)
            if not isinstance(values, list) or not values:
                errors.append(f"{label}: missing {field}")
                continue
            if len(values) != len(set(values)):
                errors.append(f"{label}: duplicate {field}")
            for v in values:
                if v not in table:
                    errors.append(f"{label}: unknown {field} {v}")
                elif table[v].get("client_version") != ver:
                    errors.append(f"{label}: {field} cross-Client version {v}")
        for sid in row.get("spec_ids", []):
            if sid not in specs:
                continue
            s = specs[sid]
            if s.get("maturity") not in {"REVIEWED", "STABLE"} or s.get("contract_status") != "DEFINED":
                reasons.append(f"{sid}={s.get('maturity')}/{s.get('contract_status')}")
            testids = s.get("test_ids", [])
            if not testids:
                reasons.append(f"{sid}=NO_REGISTERED_TEST")
            else:
                # Phase B's only certified TEST category is offline synthetic.
                # Do not treat a renamed status as a source-backed conformance run.
                for tid in testids:
                    test = tests.get(tid)
                    if test is None:
                        errors.append(f"{sid}: unknown TEST reference {tid}")
                        reasons.append(f"{sid}=TEST_MISSING")
                    elif test.get("client_version") != ver:
                        errors.append(f"{sid}: TEST {tid} cross-Client version")
                        reasons.append(f"{sid}=TEST_VERSION_MISMATCH")
                    elif test.get("status") != "OFFLINE_SYNTHETIC":
                        errors.append(
                            f"{sid}: TEST {tid} status {test.get('status')} is not an "
                            "approved provenance class; Phase B requires a separate "
                            "reviewed evidence/test schema before promotion"
                        )
                        reasons.append(f"{sid}=TEST_PROVENANCE_UNREVIEWED")
                reasons.append(f"{sid}=OFFLINE_SYNTHETIC_ONLY")
        for gid in row.get("gap_ids", []):
            if gid in gaps and gaps[gid].get("status") != "RESOLVED":
                reasons.append(f"{gid}={gaps[gid].get('status')}")
        for rid in row.get("rr_ids", []):
            if rid in requests and requests[rid].get("dispatch", {}).get("state") != "ACCEPTED":
                reasons.append(f"{rid}={requests[rid].get('dispatch',{}).get('state')}")
        # Ready is a *candidate* for separate human audit, not an automatic publication.
        result["contracts"].append({
            "id": label, "kind": kind, "status": "BLOCKED" if reasons else "REVIEW_CANDIDATE",
            "blockers": sorted(set(reasons)),
        })
    result["summary"] = {
        "total": len(result["contracts"]),
        "blocked": sum(x["status"] == "BLOCKED" for x in result["contracts"]),
        "review_candidates": sum(x["status"] == "REVIEW_CANDIDATE" for x in result["contracts"]),
        "errors": len(errors),
    }
    return result

def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--root", type=Path, default=ROOT)
    p.add_argument("--check", action="store_true", help="fail only on malformed references/states, not on blocked contracts")
    p.add_argument("--json", action="store_true", help="print machine-readable report")
    args = p.parse_args()
    report = evaluate(args.root.resolve())
    if args.json:
        print(json.dumps(report, ensure_ascii=False, indent=2))
    else:
        print("S00 contract coverage (NOT original Client compatibility)")
        for row in report["contracts"]:
            print(f"{row['id']}: {row['status']}; blockers={len(row['blockers'])}")
        print("Summary:", report["summary"])
        for error in report["errors"]:
            print("ERROR:", error)
    if args.check and report["errors"]:
        raise SystemExit(1)

if __name__ == "__main__":
    main()
