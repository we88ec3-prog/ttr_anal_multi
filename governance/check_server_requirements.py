#!/usr/bin/env python3
"""Read-only Server requirements discovered from code, runtime or user requests.

This validates origin and references, never asserts original Server semantics.
"""
import argparse
import json
import re
from collections import Counter
from pathlib import Path, PurePosixPath

ROOT = Path(__file__).resolve().parents[1]
ORIGINS = {"CODE_ANALYSIS", "RUNTIME_OBSERVATION", "USER_REQUEST"}
EVIDENCE = {
    "CODE_ANALYSIS": "CLIENT_STATIC_BOUNDED",
    "RUNTIME_OBSERVATION": "RUNTIME_RECORDED",
    "USER_REQUEST": "USER_INTENT_ONLY",
}
DIRECTIONS = {"SERVER_SEND", "SERVER_RECEIVE", "STATE_OR_POLICY", "UNKNOWN"}
STATES = {"CANDIDATE"}
SHA256 = re.compile(r"^[0-9a-f]{64}$")


def _json(root, path):
    return json.loads((root / path).read_text(encoding="utf-8"))


def _path(root, value):
    if not isinstance(value, str) or not value or "\\" in value:
        return None
    p = PurePosixPath(value)
    if p.is_absolute() or ".." in p.parts:
        return None
    file = (root / value).resolve()
    if not file.is_relative_to(root.resolve()) or not file.is_file():
        return None
    return file


def evaluate(root=ROOT):
    errors = []
    try:
        index = _json(root, "spec/server-requirements/index.json")
        claims = {x["id"]: x for x in _json(root, "research/claims/index.json")["items"]}
        specs = {x["id"]: x for x in _json(root, "spec/spec-index.json")["items"]}
        gaps = {x["id"]: x for x in _json(root, "design/gaps/index.json")["items"]}
        requests = {x["id"]: x for x in _json(root, "research/requests/index.json")["items"]}
        targets = _json(root, "shared/targets.json")
    except (OSError, ValueError, TypeError, KeyError) as exc:
        return {"errors": [f"cannot read requirement registry references: {exc}"],
                "summary": {}, "items": []}

    if index.get("schema") != "s00-server-requirement-candidates-v1" or not isinstance(index.get("items"), list):
        return {"errors": ["invalid Server requirements schema/items"], "summary": {}, "items": []}
    ids = set()
    for row in index["items"]:
        if not isinstance(row, dict):
            errors.append("non-object Server requirement")
            continue
        rid = row.get("id")
        if not isinstance(rid, str) or not re.fullmatch(r"SRQ-[0-9]{4,}", rid) or rid in ids:
            errors.append(f"invalid or repeated ID {rid}")
            continue
        ids.add(rid)
        origin = row.get("origin")
        if origin not in ORIGINS:
            errors.append(f"{rid}: invalid origin {origin}; historical supplied materials belong to USER_REQUEST")
        if row.get("evidence_status") != EVIDENCE.get(origin):
            errors.append(f"{rid}: origin/evidence_status mismatch")
        if row.get("status") not in STATES:
            errors.append(f"{rid}: CANDIDATE-only registry cannot publish {row.get('status')}")
        if row.get("direction") not in DIRECTIONS:
            errors.append(f"{rid}: unsupported Server direction")
        if not isinstance(row.get("requirement"), str) or not row["requirement"].strip():
            errors.append(f"{rid}: empty requirement")
        if not isinstance(row.get("unknowns"), list):
            errors.append(f"{rid}: unknowns must be a list")
        ver = row.get("client_version")
        if ver not in {"kr", "tc", None}:
            errors.append(f"{rid}: unknown Client version")
        if ver in {"kr", "tc"} and row.get("target_sha256") != targets.get(ver, {}).get("sha256"):
            errors.append(f"{rid}: Client target SHA mismatch")
        if ver is None and row.get("target_sha256") is not None:
            errors.append(f"{rid}: versionless requirement cannot claim a Client SHA")
        claims_used = row.get("source_claim_ids")
        if not isinstance(claims_used, list):
            errors.append(f"{rid}: source_claim_ids must be a list")
            claims_used = []
        for field, reg in (("source_claim_ids", claims),
                           ("spec_ids", specs), ("gap_ids", gaps), ("rr_ids", requests)):
            values = row.get(field)
            if not isinstance(values, list):
                errors.append(f"{rid}: {field} must be a list")
                continue
            for ref in values:
                actual = reg.get(ref) if isinstance(ref, str) else None
                if actual is None:
                    errors.append(f"{rid}: missing {field} link: {ref}")
                elif ver in {"kr", "tc"} and actual.get("client_version") != ver:
                    errors.append(f"{rid}: cross-version {field} link: {ref}")
        source = _path(root, row.get("source_path"))
        if source is None:
            errors.append(f"{rid}: origin source_path missing or unsafe")
        if origin == "CODE_ANALYSIS":
            if not claims_used or not any(
                    claims.get(cid, {}).get("source_file") == row.get("source_path")
                    for cid in claims_used if isinstance(cid, str)):
                errors.append(f"{rid}: code finding needs at least one source-aligned registered CLM; "
                              "no second runtime/user origin is required")
        if origin == "RUNTIME_OBSERVATION":
            if source is None or not row.get("authorized_record_ref"):
                errors.append(f"{rid}: runtime observation needs an authorized, retained record")
        if origin == "USER_REQUEST" and claims_used and row.get("evidence_status") == "USER_INTENT_ONLY":
            # A user may cite additional code, but that does not upgrade the
            # request into original Client evidence on its own.
            pass
        materials = row.get("reference_materials")
        if not isinstance(materials, list):
            errors.append(f"{rid}: reference_materials must be a list")
        else:
            for entry in materials:
                if (not isinstance(entry, dict) or not entry.get("description")
                        or not entry.get("location") or not entry.get("provenance_note")):
                    errors.append(f"{rid}: historical/reference attachment must say where it came from "
                                  "and that it has not been automatically validated")
    count = Counter(row.get("origin") for row in index["items"] if isinstance(row, dict))
    return {"errors": sorted(set(errors)), "summary": {
        "candidates": len(index["items"]),
        "origin_counts": dict(sorted(count.items())),
        "approved_contracts": 0,
        "note": "origin classification does not certify original Client or Server behavior"
    }, "items": [{"id": row.get("id"), "origin": row.get("origin"),
                  "direction": row.get("direction"), "status": row.get("status")}
                 for row in index["items"] if isinstance(row, dict)]}


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
        print("S00 Server requirements:", result["summary"])
        for error in result["errors"]:
            print("ERROR:", error)
    if args.check and result["errors"]:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
