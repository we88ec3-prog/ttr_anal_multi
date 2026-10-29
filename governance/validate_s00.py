#!/usr/bin/env python3
"""Phase-A S00 registry integrity checks. Not a semantic or compatibility verifier."""
import argparse
import hashlib
import json
import re
from pathlib import Path

FILES = {
    "SPEC": ("spec/spec-index.json", "s00-spec-index-v1"),
    "CLM": ("research/claims/index.json", "s00-claim-index-v1"),
    "RR": ("research/requests/index.json", "s00-research-request-index-v1"),
    "GAP": ("design/gaps/index.json", "s00-gap-index-v1"),
    "ADR": ("design/decisions/index.json", "s00-adr-index-v1"),
    "FB": ("design/feedback/index.json", "s00-feedback-index-v1"),
    "TEST": ("conformance/test-index.json", "s00-test-index-v1"),
    "SRC": ("research/intake/index.json", "s00-source-intake-v1"),
}
MATURITY = {"DRAFT", "REVIEWED", "STABLE", "DEPRECATED"}
LEVEL = {"NATIVE_VERIFIED", "PARTIAL", "INFERRED", "UNKNOWN", "REFUTED"}
GAP_TYPES = {
    "CLIENT_PROTOCOL_UNKNOWN", "CLIENT_BEHAVIOR_UNKNOWN",
    "SERVER_DESIGN_UNDECIDED", "SPEC_CONTRADICTION", "TEST_MISSING",
}
SHA256 = re.compile(r"^[0-9a-f]{64}$")
SHA1 = re.compile(r"^[0-9a-f]{40}$")

def validate(root: Path) -> list[str]:
    errors = []
    tables = {}
    seen = set()

    def fail(label, reason):
        errors.append(f"{label}: {reason}")

    def objpath(path, label):
        if not isinstance(path, str) or not path or path.startswith("/"):
            fail(label, "invalid path")
            return None
        full = (root / path).resolve()
        if not full.is_relative_to(root.resolve()) or not full.is_file():
            fail(label, f"missing/unsafe file {path}")
            return None
        return full

    def load(name, path, schema):
        full = objpath(path, name)
        if full is None:
            return []
        try:
            value = json.loads(full.read_text(encoding="utf-8"))
        except (ValueError, OSError) as exc:
            fail(name, f"invalid JSON: {exc}")
            return []
        if not isinstance(value, dict) or value.get("schema") != schema:
            fail(name, f"schema must equal {schema}")
            return []
        rows = value.get("items")
        if not isinstance(rows, list):
            fail(name, "items must be an array")
            return []
        return rows

    for category, (path, schema) in FILES.items():
        rows = load(category, path, schema)
        tables[category] = {}
        for i, row in enumerate(rows):
            label = f"{category}[{i}]"
            if not isinstance(row, dict):
                fail(label, "item is not an object")
                continue
            item_id = row.get("id")
            if not isinstance(item_id, str) or not re.fullmatch(category + r"-[A-Z0-9-]+", item_id):
                fail(label, "invalid ID")
                continue
            if item_id in seen:
                fail(label, "duplicate ID " + item_id)
                continue
            seen.add(item_id)
            tables[category][item_id] = row

    targets_path = objpath("shared/targets.json", "targets")
    targets = {}
    if targets_path:
        try:
            targets = json.loads(targets_path.read_text(encoding="utf-8"))
        except (ValueError, OSError) as exc:
            fail("targets", str(exc))

    def version(row, item_id):
        v = row.get("client_version")
        if v not in {"kr", "tc"}:
            fail(item_id, "client_version must be kr or tc")
            return
        actual = row.get("target_sha256")
        if actual is not None and actual != targets.get(v, {}).get("sha256"):
            fail(item_id, "target SHA differs from shared/targets.json")

    def refs(row, key, category, item_id):
        values = row.get(key, [])
        if not isinstance(values, list):
            fail(item_id, key + " must be a list")
            return
        for value in values:
            if value not in tables[category]:
                fail(item_id, f"{key} unresolved: {value}")
            elif row.get("client_version") in {"kr", "tc"}:
                target = tables[category][value]
                if target.get("client_version") in {"kr", "tc"} and target["client_version"] != row["client_version"]:
                    fail(item_id, f"{key} cross-version reference {value}")

    for item_id, row in tables["SPEC"].items():
        version(row, item_id)
        if row.get("maturity") not in MATURITY:
            fail(item_id, "invalid maturity")
        if row.get("contract_status") not in {"UNKNOWN", "PARTIAL", "DEFINED"}:
            fail(item_id, "invalid contract_status")
        objpath(row.get("spec_path"), item_id)
        for key, kind in [("claim_ids", "CLM"), ("adr_ids", "ADR"), ("gap_ids", "GAP"), ("test_ids", "TEST")]:
            refs(row, key, kind, item_id)
        if row.get("maturity") == "STABLE":
            if row.get("contract_status") != "DEFINED" or row.get("gap_ids") or row.get("unknowns"):
                fail(item_id, "STABLE requires defined contract with no unresolved blockers")
            if not row.get("test_ids") or not (row.get("claim_ids") or row.get("adr_ids")):
                fail(item_id, "STABLE requires tests and traceable evidence/decision")

    for item_id, row in tables["GAP"].items():
        version(row, item_id)
        if row.get("type") not in GAP_TYPES:
            fail(item_id, "invalid gap type")
        if row.get("status") not in {"OPEN", "IN_REVIEW", "RESOLVED", "BLOCKED"}:
            fail(item_id, "invalid gap status")
        if not row.get("resolution_criteria"):
            fail(item_id, "missing resolution criteria")
        refs(row, "affected_spec_ids", "SPEC", item_id)
        for source in row.get("source_refs", []):
            objpath(source, item_id)

    for item_id, row in tables["RR"].items():
        version(row, item_id)
        if row.get("status") not in {"PENDING", "ACTIVE", "RESOLVED", "BLOCKED"}:
            fail(item_id, "invalid request status")
        if not row.get("question"):
            fail(item_id, "missing research question")
        refs(row, "gap_ids", "GAP", item_id)

    for item_id, row in tables["SRC"].items():
        version(row, item_id)
        if row.get("integration_status") not in {
            "REGISTERED", "CLAIMS_EXTRACTED", "CONFLICT_CHECKED", "SPEC_CONSUMABLE"
        }:
            fail(item_id, "invalid integration_status")
        source = objpath(row.get("source_file"), item_id)
        blob = row.get("source_blob_sha")
        digest = row.get("source_sha256")
        if not isinstance(blob, str) or not SHA1.fullmatch(blob):
            fail(item_id, "invalid source Git blob SHA")
        if not isinstance(digest, str) or not SHA256.fullmatch(digest):
            fail(item_id, "invalid source SHA256")
        if source and isinstance(blob, str) and SHA1.fullmatch(blob) and isinstance(digest, str) and SHA256.fullmatch(digest):
            contents = source.read_bytes()
            if hashlib.sha256(contents).hexdigest() != digest:
                fail(item_id, "source SHA256 mismatch")
            git_blob = hashlib.sha1(b"blob " + str(len(contents)).encode() + b"\x00" + contents).hexdigest()
            if git_blob != blob:
                fail(item_id, "source Git blob SHA mismatch")
        refs(row, "claim_ids", "CLM", item_id)
        if row.get("integration_status") in {"CLAIMS_EXTRACTED", "CONFLICT_CHECKED", "SPEC_CONSUMABLE"} and not row.get("claim_ids"):
            fail(item_id, "promoted source must enumerate bounded claim IDs")
        if row.get("integration_status") == "SPEC_CONSUMABLE" and not row.get("conflict_disposition"):
            fail(item_id, "SPEC_CONSUMABLE requires explicit conflict disposition")

    for item_id, row in tables["CLM"].items():
        version(row, item_id)
        if row.get("evidence_level") not in LEVEL:
            fail(item_id, "invalid evidence level")
        if not row.get("assertion") or not row.get("evidence_scope"):
            fail(item_id, "missing bounded assertion or scope")
        objpath(row.get("source_file"), item_id)
        if not isinstance(row.get("source_blob_sha"), str) or not SHA1.fullmatch(row["source_blob_sha"]):
            fail(item_id, "invalid source git blob SHA")
        if row.get("evidence_level") == "NATIVE_VERIFIED":
            proof = objpath(row.get("native_review_ref"), item_id)
            if proof and row.get("target_sha256") != targets.get(row.get("client_version"), {}).get("sha256"):
                fail(item_id, "NATIVE_VERIFIED needs exact original target SHA")
            if not row.get("evidence_refs"):
                fail(item_id, "NATIVE_VERIFIED requires scoped native evidence references")
        refs(row, "affected_spec_ids", "SPEC", item_id)

    for kind in ("TEST", "ADR", "FB"):
        for item_id, row in tables[kind].items():
            if row.get("client_version") is not None:
                version(row, item_id)
            refs(row, "spec_ids", "SPEC", item_id)

    return errors

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=Path(__file__).resolve().parents[1])
    args = parser.parse_args()
    errors = validate(args.root)
    if errors:
        for error in errors:
            print("ERROR", error)
        raise SystemExit(1)
    print("S00 registry integrity OK. This is not an original-client semantic verdict or Server compatibility test.")

if __name__ == "__main__":
    main()
