#!/usr/bin/env python3
"""Validate S00 Server requirement provenance and link integrity, not Client semantics."""
from __future__ import annotations

import argparse
import json
from pathlib import Path, PurePosixPath

ROOT = Path(__file__).resolve().parents[1]
KINDS = {"CODE_ANALYSIS", "GAME_RUNTIME_OBSERVATION", "PLAYER_ADMIN_REQUEST"}
STATUSES = {"CANDIDATE", "UNDER_REVIEW", "APPROVED", "DEFERRED", "REJECTED"}
PRIORITIES = {"P0", "P1", "P2", "P3"}
CATEGORIES = {"CLIENT_COMPATIBILITY", "SERVER_DESIGN", "PRODUCT_FEATURE", "OPERATIONS"}


def _read(root: Path, path: str):
    return json.loads((root / path).read_text(encoding="utf-8"))


def _safe_path(root: Path, path):
    if not isinstance(path, str) or not path or "\\" in path:
        return False
    posix = PurePosixPath(path)
    if posix.is_absolute() or ".." in posix.parts or path.startswith("./"):
        return False
    local = (root / path).resolve()
    return local.is_relative_to(root.resolve()) and local.is_file()


def evaluate(root: Path = ROOT):
    errors = []
    try:
        registry = _read(root, "design/requirements/index.json")
        links = {
            kind: {item["id"]: item for item in _read(root, path)["items"]}
            for kind, path in (
                ("claim_ids", "research/claims/index.json"),
                ("spec_ids", "spec/spec-index.json"),
                ("rr_ids", "research/requests/index.json"),
                ("gap_ids", "design/gaps/index.json"),
                ("adr_ids", "design/decisions/index.json"),
                ("feedback_ids", "design/feedback/index.json"),
            )
        }
        targets = _read(root, "shared/targets.json")
    except (OSError, KeyError, ValueError, TypeError) as exc:
        return {"errors": [f"cannot load S00 requirement inputs: {exc}"], "summary": {}}
    if registry.get("schema") != "s00-server-requirements-v1" or not isinstance(registry.get("items"), list):
        return {"errors": ["server requirements schema/items invalid"], "summary": {}}
    if registry.get("supported_discovery_channels") != sorted(KINDS):
        errors.append("supported_discovery_channels must be the exact three approved channels")
    if not isinstance(registry.get("suggested_not_yet_enabled"), list):
        errors.append("suggested_not_yet_enabled must be a list")
    seen = set()
    counts = {k: 0 for k in sorted(KINDS)}
    for i, r in enumerate(registry["items"]):
        tag = r.get("id", f"items[{i}]") if isinstance(r, dict) else f"items[{i}]"
        if not isinstance(r, dict):
            errors.append(f"{tag}: not an object")
            continue
        rid = r.get("id")
        if not isinstance(rid, str) or not rid.startswith("REQ-") or not rid[4:].isdigit():
            errors.append(f"{tag}: invalid REQ ID")
        if rid in seen:
            errors.append(f"{tag}: duplicate requirement")
        seen.add(rid)
        if r.get("status") not in STATUSES or r.get("priority") not in PRIORITIES:
            errors.append(f"{tag}: unsupported status/priority")
        if r.get("category") not in CATEGORIES:
            errors.append(f"{tag}: unsupported category")
        if not r.get("title") or not r.get("need"):
            errors.append(f"{tag}: missing title/need")
        if not isinstance(r.get("acceptance_criteria"), list) or not all(
            isinstance(v, str) and v.strip() for v in r["acceptance_criteria"]
        ) or not r["acceptance_criteria"]:
            errors.append(f"{tag}: missing acceptance criteria")
        v = r.get("client_version")
        if v not in {"kr", "tc", None}:
            errors.append(f"{tag}: version not kr/tc/null")
        if v in {"kr", "tc"} and r.get("target_sha256") != targets.get(v, {}).get("sha256"):
            errors.append(f"{tag}: mismatch original target SHA")
        if v is None and r.get("target_sha256") is not None:
            errors.append(f"{tag}: version-neutral requirement must not claim original target SHA")
        if r.get("status") == "APPROVED" and not _safe_path(root, r.get("approval_ref")):
            errors.append(f"{tag}: APPROVED requires an existing explicit maintainer approval record")
        for key, table in links.items():
            ref_ids = r.get(key, [])
            if not isinstance(ref_ids, list) or len(set(map(str, ref_ids))) != len(ref_ids):
                errors.append(f"{tag}: {key} not a distinct list")
                continue
            for ref_id in ref_ids:
                ref = table.get(ref_id)
                if ref is None:
                    errors.append(f"{tag}: missing {key} reference {ref_id}")
                elif ref.get("client_version") in {"kr", "tc"}:
                    if ref.get("client_version") != v:
                        errors.append(f"{tag}: {key} version conflict {ref_id}")
        observations = r.get("discoveries")
        if not isinstance(observations, list) or not observations:
            errors.append(f"{tag}: must include at least one actual discovery")
            continue
        for j, o in enumerate(observations):
            label = f"{tag}.discoveries[{j}]"
            if not isinstance(o, dict):
                errors.append(f"{label}: not an object")
                continue
            channel = o.get("channel")
            if channel not in KINDS:
                errors.append(f"{label}: unsupported discovery channel {channel}")
                continue
            counts[channel] += 1
            if channel == "CODE_ANALYSIS":
                claims = o.get("claim_ids")
                if not isinstance(claims, list) or not claims:
                    errors.append(f"{label}: source-scoped code analysis requires CLM links")
                    continue
                if not o.get("observation") or not o.get("limitations"):
                    errors.append(f"{label}: code analysis requires bounded observation and limitations")
                for claim in claims:
                    c = links["claim_ids"].get(claim)
                    if c is None:
                        errors.append(f"{label}: unknown claim {claim}")
                    elif c.get("client_version") != v:
                        errors.append(f"{label}: code claim is from a different Client build")
                    if claim not in r.get("claim_ids", []):
                        errors.append(f"{label}: discovery claim missing from requirement-level claim_ids {claim}")
            elif channel == "GAME_RUNTIME_OBSERVATION":
                # An actual gameplay observation needs explicit prior authorization.
                for name in ("observation_ref", "authorization_ref"):
                    if not _safe_path(root, o.get(name)):
                        errors.append(f"{label}: runtime requires existing public-safe {name}")
                for name in ("environment", "observed", "reproduction"):
                    if not isinstance(o.get(name), str) or not o[name].strip():
                        errors.append(f"{label}: runtime missing {name}")
                if v not in {"kr", "tc"} or o.get("target_sha256") != targets.get(v, {}).get("sha256"):
                    errors.append(f"{label}: runtime must pin a matching Client version and SHA")
            else:
                if o.get("requester_role") not in {"PLAYER", "ADMINISTRATOR"}:
                    errors.append(f"{label}: requested feature needs PLAYER/ADMINISTRATOR role")
                if not isinstance(o.get("request_text"), str) or not o["request_text"].strip():
                    errors.append(f"{label}: feature request needs actual request content")
                if not _safe_path(root, o.get("request_record_ref")):
                    errors.append(f"{label}: feature request needs a public-safe internal request record")
                # Historical protocol documents and operations/security notes
                # supplied by a player/admin are USER REQUEST attachments,
                # not separate origins or automatically native Client proof.
                materials = o.get("reference_materials", [])
                if not isinstance(materials, list):
                    errors.append(f"{label}: reference_materials must be a list")
                else:
                    for material in materials:
                        if (not isinstance(material, dict)
                                or not all(isinstance(material.get(key), str) and
                                           material[key].strip()
                                           for key in ("description", "location", "provenance_note"))):
                            errors.append(f"{label}: user reference material requires "
                                          "description/location/provenance_note")
                # Never elevate a product request to historical Client behavior.
    return {
        "schema": "s00-server-requirement-check-v1",
        "policy": "Reference/check only. Origin is not a claim of native correctness, observed runtime behavior, or approval.",
        "errors": sorted(set(errors)),
        "summary": {"requirements": len(registry["items"]), "discovery_counts": counts,
                    "approved": sum(x.get("status") == "APPROVED" for x in registry["items"] if isinstance(x, dict))},
    }


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--root", type=Path, default=ROOT)
    p.add_argument("--check", action="store_true")
    p.add_argument("--json", action="store_true")
    a = p.parse_args()
    result = evaluate(a.root.resolve())
    if a.json:
        print(json.dumps(result, indent=2, ensure_ascii=False))
    else:
        print("S00 Server requirements:", result["summary"])
        for e in result["errors"]:
            print("ERROR", e)
    if a.check and result["errors"]:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
