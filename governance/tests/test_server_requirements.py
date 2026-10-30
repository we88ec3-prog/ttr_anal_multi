"""Regression tests: Server requirements are one catalog with three evidence channels."""
import json
import shutil
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "governance"))
from check_server_requirements import evaluate  # noqa: E402

PATHS = [
    "design/requirements/index.json", "research/claims/index.json",
    "spec/spec-index.json", "research/requests/index.json",
    "design/gaps/index.json", "design/decisions/index.json",
    "design/feedback/index.json", "shared/targets.json",
    "design/requirements/requests/2026-10-31-admin-web-account-operations.md",
]


class ServerRequirementTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)
        for p in PATHS:
            dest = self.root / p
            dest.parent.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(ROOT / p, dest)

    def edit(self, fn):
        path = self.root / PATHS[0]
        doc = json.loads(path.read_text(encoding="utf-8"))
        fn(doc)
        path.write_text(json.dumps(doc, ensure_ascii=False), encoding="utf-8")

    def add_safe_file(self, path, contents):
        dest = self.root / path
        dest.parent.mkdir(parents=True, exist_ok=True)
        dest.write_text(contents, encoding="utf-8")

    def test_canonical_code_findings_not_approved(self):
        r = evaluate(self.root)
        self.assertEqual(r["errors"], [])
        self.assertEqual(r["summary"]["requirements"], 8)
        self.assertEqual(r["summary"]["approved"], 0)
        self.assertEqual(r["summary"]["discovery_counts"],
                         {"CODE_ANALYSIS": 5, "GAME_RUNTIME_OBSERVATION": 0, "PLAYER_ADMIN_REQUEST": 3})


    def test_admin_web_v1_three_requests_trace_to_actual_user_request(self):
        records = json.loads((self.root / PATHS[0]).read_text(encoding="utf-8"))["items"]
        found = {r["id"]: r for r in records}
        for rid in ("REQ-0006", "REQ-0007", "REQ-0008"):
            req = found[rid]
            self.assertEqual(req["client_version"], None)
            self.assertEqual(req["status"], "CANDIDATE")
            self.assertEqual(req["discoveries"][0]["channel"], "PLAYER_ADMIN_REQUEST")
            self.assertEqual(req["discoveries"][0]["requester_role"], "ADMINISTRATOR")
            self.assertEqual(req["discoveries"][0]["request_record_ref"],
                             "design/requirements/requests/2026-10-31-admin-web-account-operations.md")
            self.assertEqual(req["rr_ids"], [])
            self.assertEqual(req["claim_ids"], [])
        self.assertEqual(set(found["REQ-0008"]["adr_ids"]), {"ADR-0004", "ADR-0005"})
        self.assertEqual(evaluate(self.root)["errors"], [])

    def test_admin_web_request_record_missing_fails_closed(self):
        path = self.root / "design/requirements/requests/2026-10-31-admin-web-account-operations.md"
        path.unlink()
        errors = evaluate(self.root)["errors"]
        self.assertTrue(any("feature request needs a public-safe internal request record" in e
                            for e in errors))

    def test_duplicate_requirements_rejected(self):
        self.edit(lambda d: d["items"].append(d["items"][0].copy()))
        self.assertTrue(any("duplicate requirement" in s for s in evaluate(self.root)["errors"]))

    def test_code_discovery_requires_real_claim_reference(self):
        self.edit(lambda d: d["items"][0]["discoveries"][0].update(claim_ids=["CLM-FAKE"]))
        self.assertTrue(any("unknown claim" in s for s in evaluate(self.root)["errors"]))

    def test_code_claim_must_be_consistent_with_top_level_requirement(self):
        self.edit(lambda d: d["items"][0].update(claim_ids=[]))
        self.assertTrue(any("discovery claim missing" in x for x in evaluate(self.root)["errors"]))

    def test_mutated_cross_version_requirement_is_rejected(self):
        self.edit(lambda d: d["items"][0].update(client_version="tc"))
        errors = evaluate(self.root)["errors"]
        self.assertTrue(any("mismatch original target SHA" in s for s in errors))
        self.assertTrue(any("version conflict" in s for s in errors))

    def test_runtime_statement_requires_real_authorization_and_trace(self):
        def edit(d):
            d["items"][0]["discoveries"].append({
                "channel": "GAME_RUNTIME_OBSERVATION",
                "environment": "mock fixture only", "observed": "mock", "reproduction": "mock",
                "target_sha256": d["items"][0]["target_sha256"],
                "observation_ref": "test/never-exists.md",
                "authorization_ref": "test/no-authorization.md",
            })
        self.edit(edit)
        self.assertTrue(any("runtime requires existing public-safe" in s
                            for s in evaluate(self.root)["errors"]))

    def test_mock_runtime_with_both_record_paths_is_structurally_allowed(self):
        # Mechanically accepted synthetic test fixture does not authorize actual Client execution.
        self.add_safe_file("design/requirements/observations/mock.md", "synthetic mock only")
        self.add_safe_file("design/requirements/authorizations/mock.md", "mock permission record")
        def edit(d):
            d["items"][0]["discoveries"].append({
                "channel": "GAME_RUNTIME_OBSERVATION",
                "environment": "mock fixture", "observed": "mock outcome",
                "reproduction": "mock steps", "target_sha256": d["items"][0]["target_sha256"],
                "observation_ref": "design/requirements/observations/mock.md",
                "authorization_ref": "design/requirements/authorizations/mock.md",
            })
        self.edit(edit)
        r = evaluate(self.root)
        self.assertEqual(r["errors"], [])
        self.assertEqual(r["summary"]["discovery_counts"]["GAME_RUNTIME_OBSERVATION"], 1)
        self.assertEqual(r["summary"]["approved"], 0)

    def test_player_and_admin_both_share_same_existing_requirement(self):
        for name in ("player", "admin"):
            self.add_safe_file(f"design/requirements/requests/{name}.md", "internal sample, no real user data")
        def edit(d):
            for role, name in (("PLAYER", "player"), ("ADMINISTRATOR", "admin")):
                d["items"][0]["discoveries"].append({
                    "channel": "PLAYER_ADMIN_REQUEST",
                    "requester_role": role,
                    "request_text": "synthetic feature request",
                    "request_record_ref": f"design/requirements/requests/{name}.md",
                })
        self.edit(edit)
        r = evaluate(self.root)
        self.assertEqual(r["errors"], [])
        self.assertEqual(r["summary"]["requirements"], 8)
        self.assertEqual(r["summary"]["discovery_counts"]["PLAYER_ADMIN_REQUEST"], 5)

    def test_historical_protocol_and_ops_safety_are_user_request_material(self):
        # Test-only player/admin discovery: not a real user submission.
        self.add_safe_file("design/requirements/requests/historical-test.md",
                           "synthetic mocked request, not authentic Client traffic")
        def edit(d):
            d["items"][0]["discoveries"].append({
                "channel": "PLAYER_ADMIN_REQUEST",
                "requester_role": "ADMINISTRATOR",
                "request_text": "Please review an old protocol note and access safety.",
                "request_record_ref": "design/requirements/requests/historical-test.md",
                "reference_materials": [{
                    "description": "unverified old Server log",
                    "location": "attachment://test-only",
                    "provenance_note": "mock historical note; not authenticated"
                }],
            })
        self.edit(edit)
        self.assertEqual(evaluate(self.root)["errors"], [])
        self.edit(lambda d: d["items"][0]["discoveries"][-1].update(
            channel="HISTORICAL_PROTOCOL_ARTIFACT"))
        self.assertTrue(any("unsupported discovery channel" in x
                            for x in evaluate(self.root)["errors"]))

    def test_user_historical_material_needs_provenance_note(self):
        self.add_safe_file("design/requirements/requests/mock-reference.md",
                           "synthetic request")
        def edit(d):
            d["items"][0]["discoveries"].append({
                "channel": "PLAYER_ADMIN_REQUEST",
                "requester_role": "PLAYER",
                "request_text": "Please research an old Server log.",
                "request_record_ref": "design/requirements/requests/mock-reference.md",
                "reference_materials": [{
                    "description": "old protocol", "location": "attachment://mock"
                }],
            })
        self.edit(edit)
        self.assertTrue(any("user reference material requires" in x
                            for x in evaluate(self.root)["errors"]))

    def test_user_request_is_not_original_client_evidence(self):
        self.add_safe_file("design/requirements/requests/mock.md", "synthetic")
        def edit(d):
            d["items"][0]["discoveries"] = [{
                "channel": "PLAYER_ADMIN_REQUEST",
                "requester_role": "PLAYER", "request_text": "mock request",
                "request_record_ref": "design/requirements/requests/mock.md",
            }]
        self.edit(edit)
        r = evaluate(self.root)
        self.assertEqual(r["errors"], [])
        self.assertEqual(r["summary"]["approved"], 0)
        self.assertEqual(r["summary"]["discovery_counts"]["CODE_ANALYSIS"], 4)

    def test_unapproved_other_discovery_source_fails_closed(self):
        self.edit(lambda d: d["items"][0]["discoveries"][0].update(channel="SERVER_IMPLEMENTATION_FEEDBACK"))
        self.assertTrue(any("unsupported discovery channel" in s for s in evaluate(self.root)["errors"]))

    def test_approved_requires_maintainer_record(self):
        self.edit(lambda d: d["items"][0].update(status="APPROVED"))
        self.assertTrue(any("APPROVED requires" in s for s in evaluate(self.root)["errors"]))

    def test_check_never_writes_to_authoritative_indices(self):
        original = {p: (self.root / p).read_bytes() for p in PATHS}
        _ = evaluate(self.root)
        self.assertEqual(original, {p: (self.root / p).read_bytes() for p in PATHS})


if __name__ == "__main__":
    unittest.main()
