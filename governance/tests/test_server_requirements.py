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
        self.assertEqual(r["summary"]["requirements"], 5)
        self.assertEqual(r["summary"]["approved"], 0)
        self.assertEqual(r["summary"]["discovery_counts"],
                         {"CODE_ANALYSIS": 5, "GAME_RUNTIME_OBSERVATION": 0, "PLAYER_ADMIN_REQUEST": 0})

    def test_duplicate_requirements_rejected(self):
        self.edit(lambda d: d["items"].append(d["items"][0].copy()))
        self.assertTrue(any("duplicate requirement" in s for s in evaluate(self.root)["errors"]))

    def test_code_discovery_requires_real_claim_reference(self):
        self.edit(lambda d: d["items"][0]["discoveries"][0].update(claim_ids=["CLM-FAKE"]))
        self.assertTrue(any("unknown claim" in s for s in evaluate(self.root)["errors"]))

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
        self.assertEqual(r["summary"]["requirements"], 5)
        self.assertEqual(r["summary"]["discovery_counts"]["PLAYER_ADMIN_REQUEST"], 2)

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
