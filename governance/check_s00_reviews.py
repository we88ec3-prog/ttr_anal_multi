#!/usr/bin/env python3
"""S00 RR decision ledger integrity, not a native or compatibility verdict."""
from __future__ import annotations

import argparse
import hashlib
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SHA1 = re.compile(r"^[0-9a-f]{40}$")
DECISIONS = {"ACCEPTED", "NEEDS_REVISION"}

def _read(root, path):
    return json.loads((root / path).read_text(encoding="utf-8"))

def _blob_sha(contents):
    return hashlib.sha1(b"blob " + str(len(contents)).encode() + b"\x00" + contents).hexdigest()

def _safe_file(root, path, prefix=None):
    if not isinstance(path, str) or not path or path.startswith("/") or "\\" in path:
        return None
    if prefix and not path.startswith(prefix):
        return None
    file = (root / path).resolve()
    if not file.is_relative_to(root.resolve()) or not file.is_file():
        return None
    return file

def evaluate(root=ROOT):
    errors = []
    try:
        ledger = _read(root, "governance/reviews/index.json")
        requests = {x["id"]: x for x in _read(root, "research/requests/index.json")["items"]}
        targets = _read(root, "shared/targets.json")
        valid_outcomes = set()
        for path in ("spec/spec-index.json", "research/claims/index.json",
                     "design/gaps/index.json", "conformance/test-index.json"):
            valid_outcomes.update(x["id"] for x in _read(root, path)["items"])
    except (ValueError, OSError, KeyError, TypeError) as exc:
        return {"errors": [f"unable to read review registries: {exc}"], "summary": {}}
    if ledger.get("schema") != "s00-rr-review-index-v1" or not isinstance(ledger.get("items"), list):
        return {"errors": ["invalid RR review ledger schema/items"], "summary": {}}
    by_rr = {}
    ids = set()
    for row in ledger["items"]:
        if not isinstance(row, dict):
            errors.append("non-object review ledger row")
            continue
        rid, rrid = row.get("id"), row.get("rr_id")
        if not isinstance(rid, str) or rid in ids:
            errors.append(f"invalid/duplicate review ID: {rid}")
        ids.add(rid)
        if rrid in by_rr:
            errors.append(f"{rrid}: duplicate active review (use one current decision)")
        by_rr[rrid] = row
        request = requests.get(rrid)
        if request is None:
            errors.append(f"{rid}: unknown request {rrid}")
            continue
        d = request.get("dispatch", {})
        review = d.get("review") or {}
        submission = d.get("submission") or {}
        if row.get("decision") not in DECISIONS or row.get("decision") != d.get("state") or review.get("decision") != row.get("decision"):
            errors.append(f"{rid}: decision differs from RR dispatch/review")
        if row.get("client_version") != request.get("client_version") or row.get("target_sha256") != targets.get(request.get("client_version"), {}).get("sha256"):
            errors.append(f"{rid}: version/target mismatch")
        expected_actors = {"S00"} if row.get("decision") == "ACCEPTED" else {"S00", "T01"}
        if row.get("actor") not in expected_actors or review.get("actor") != row.get("actor"):
            errors.append(f"{rid}: reviewer authority differs from RR dispatch")
        outcomes = row.get("outcome_refs")
        if not isinstance(outcomes, list) or not outcomes or any(x not in valid_outcomes for x in outcomes):
            errors.append(f"{rid}: missing/unresolved published outcome references")
        if outcomes != review.get("outcome_refs"):
            errors.append(f"{rid}: outcome refs disagree with RR review")
        report = _safe_file(root, submission.get("report_path"))
        if report is None or not isinstance(submission.get("report_blob_sha"), str) or not SHA1.fullmatch(submission["report_blob_sha"]) or (report and _blob_sha(report.read_bytes()) != submission.get("report_blob_sha")):
            errors.append(f"{rid}: missing/unverifiable submitted research blob")
        path = row.get("review_path")
        proof = _safe_file(root, path, prefix="governance/reviews/")
        if proof is None or not isinstance(row.get("review_blob_sha"), str) or not SHA1.fullmatch(row["review_blob_sha"]) or (proof and _blob_sha(proof.read_bytes()) != row.get("review_blob_sha")):
            errors.append(f"{rid}: missing/unverifiable bounded decision record")
    for rrid, request in requests.items():
        d = request.get("dispatch", {})
        if d.get("state") in DECISIONS and rrid not in by_rr:
            errors.append(f"{rrid}: {d['state']} requires S00 review ledger evidence")
    return {"errors": errors, "summary": {"review_records": len(ledger["items"]), "errors": len(errors)}}

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=ROOT)
    parser.add_argument("--check", action="store_true")
    parser.add_argument("--json", action="store_true")
    args = parser.parse_args()
    result = evaluate(args.root.resolve())
    if args.json:
        print(json.dumps(result, indent=2, ensure_ascii=False))
    else:
        print("S00 RR review ledger:", result["summary"])
        for error in result["errors"]:
            print("ERROR:", error)
    if args.check and result["errors"]:
        raise SystemExit(1)

if __name__ == "__main__":
    main()
