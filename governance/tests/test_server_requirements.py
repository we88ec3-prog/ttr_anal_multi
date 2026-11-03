"""Regression tests: Server requirements are one catalog with three evidence channels."""
import json
import shutil
import sys
import tempfile
import unittest
from pathlib import Path, PurePosixPath

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "governance"))
from check_server_requirements import evaluate  # noqa: E402

PATHS = [
    "design/requirements/index.json", "research/claims/index.json",
    "spec/spec-index.json", "research/requests/index.json",
    "design/gaps/index.json", "design/decisions/index.json",
    "design/feedback/index.json", "shared/targets.json",
    "design/requirements/requests/2026-10-31-admin-web-account-operations.md",
    "design/requirements/requests/2026-10-31-game-tcp-observability.md",
    "design/requirements/requests/2026-11-01-local-login-runtime.md",
    "governance/s00-iterations/S00-20261101-STANDARD-USER-CLIENT-LAUNCH.md",
    "governance/s00-iterations/S00-20261101-LOGIN-REPLY-RUNTIME.md",
    "governance/s00-iterations/S00-20261101-EMPTY-ROSTER-EXPERIMENT.md",
    "governance/s00-iterations/S00-20261101-EXPEDITION-NAME-TUTORIAL-ENTRY.md",
    "governance/s00-iterations/S00-20261101-TUTORIAL-MOVEMENT-CAMERA-SWITCH.md",
    "governance/s00-iterations/S00-20261101-TUTORIAL-NPC-AND-FORMATION.md",
    "governance/s00-iterations/S00-20261101-TUTORIAL-FIRST-BATTLE.md",
    "governance/s00-iterations/S00-20261101-PINKO-RECRUITMENT.md",
    "governance/s00-iterations/S00-20261101-COMBAT-PRIORITY-AND-EXIT-BLOCKER.md",
    "governance/s00-iterations/S00-20261101-V7-PLAYER-RESULT-AND-COMBAT-FIX.md",
    "governance/s00-iterations/S00-20261101-COMBAT-EXIT-V8-DEPLOYMENT.md",
    "research/handoffs/s00-phindos-mainline-20261102/README.md",
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

        # Copy any additional evidence files referenced by today's requirement catalog.
        # Missing/unsafe references are intentionally not synthesized: evaluate() must fail closed.
        registry = json.loads((self.root / PATHS[0]).read_text(encoding="utf-8"))
        references = {
            discovery[key]
            for requirement in registry["items"]
            for discovery in requirement.get("discoveries", [])
            for key in ("observation_ref", "authorization_ref", "request_record_ref")
            if isinstance(discovery.get(key), str)
        }
        for p in sorted(references - set(PATHS)):
            rel = PurePosixPath(p)
            if rel.is_absolute() or ".." in rel.parts or "\\" in p or p.startswith("./"):
                continue
            source = (ROOT / p).resolve()
            if not source.is_relative_to(ROOT.resolve()) or not source.is_file():
                continue
            dest = self.root / p
            dest.parent.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(source, dest)

    def edit(self, fn):
        path = self.root / PATHS[0]
        doc = json.loads(path.read_text(encoding="utf-8"))
        fn(doc)
        path.write_text(json.dumps(doc, ensure_ascii=False), encoding="utf-8")

    def add_safe_file(self, path, contents):
        dest = self.root / path
        dest.parent.mkdir(parents=True, exist_ok=True)
        dest.write_text(contents, encoding="utf-8")

    def test_fixture_includes_all_registered_public_safe_provenance(self):
        # Keep sandboxed test fixtures in sync with the real requirement catalog.
        # Missing records must not be bypassed by weakening evaluate()'s checks.
        catalog = json.loads((ROOT / PATHS[0]).read_text(encoding="utf-8"))
        referenced = set()
        field_names = {
            "GAME_RUNTIME_OBSERVATION": ("observation_ref", "authorization_ref"),
            "PLAYER_ADMIN_REQUEST": ("request_record_ref",),
        }
        for requirement in catalog["items"]:
            for discovery in requirement["discoveries"]:
                for field in field_names.get(discovery["channel"], ()):
                    ref = discovery.get(field)
                    if ref:
                        referenced.add(ref)
        self.assertEqual(referenced - set(PATHS), set())

    def test_canonical_code_findings_not_approved(self):
        r = evaluate(self.root)
        self.assertEqual(r["errors"], [])
        items = json.loads((self.root / PATHS[0]).read_text(encoding="utf-8"))["items"]
        self.assertEqual(r["summary"]["requirements"], len(items))
        self.assertEqual(r["summary"]["approved"], 0)
        self.assertEqual(r["summary"]["discovery_counts"], {
            channel: sum(d["channel"] == channel for req in items for d in req["discoveries"])
            for channel in ("CODE_ANALYSIS", "GAME_RUNTIME_OBSERVATION", "PLAYER_ADMIN_REQUEST")
        })


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
        access = found["REQ-0006"]
        self.assertEqual(len(access["discoveries"]), 2)
        self.assertEqual(access["discoveries"][1]["request_text"],
                         "目前先不管權限，指定的IP與URL就能管理")
        self.assertIn("來源 IP/CIDR allowlist", access["acceptance_criteria"][0])
        self.assertTrue(any("不顯示管理員登入頁" in x for x in access["acceptance_criteria"]))
        self.assertEqual(found["REQ-0007"]["adr_ids"], ["ADR-0004"])
        self.assertNotIn("ADR-0002", access["adr_ids"])
        self.assertEqual(evaluate(self.root)["errors"], [])

    def test_game_tcp_observability_is_separate_candidate_user_request(self):
        records = json.loads((self.root / PATHS[0]).read_text(encoding="utf-8"))["items"]
        log = next(r for r in records if r["id"] == "REQ-0009")
        self.assertEqual(log["category"], "OPERATIONS")
        self.assertIsNone(log["client_version"])
        self.assertIsNone(log["target_sha256"])
        self.assertEqual(log["status"], "CANDIDATE")
        self.assertEqual(log["rr_ids"], [])
        self.assertEqual(log["gap_ids"], [])
        self.assertEqual(log["claim_ids"], [])
        self.assertEqual(log["discoveries"][0]["channel"], "PLAYER_ADMIN_REQUEST")
        self.assertEqual(log["discoveries"][0]["requester_role"], "ADMINISTRATOR")
        self.assertEqual(log["discoveries"][0]["request_record_ref"],
                         "design/requirements/requests/2026-10-31-game-tcp-observability.md")
        self.assertTrue(any("密碼" in v for v in log["acceptance_criteria"]))
        self.assertEqual(evaluate(self.root)["errors"], [])

    def test_game_tcp_observability_record_missing_fails_closed(self):
        path = self.root / "design/requirements/requests/2026-10-31-game-tcp-observability.md"
        path.unlink()
        self.assertTrue(any("feature request needs a public-safe internal request record" in e
                            for e in evaluate(self.root)["errors"]))

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
        baseline = evaluate(self.root)["summary"]["discovery_counts"]["GAME_RUNTIME_OBSERVATION"]
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
        self.assertEqual(r["summary"]["discovery_counts"]["GAME_RUNTIME_OBSERVATION"], baseline + 1)
        self.assertEqual(r["summary"]["approved"], 0)

    def test_player_and_admin_both_share_same_existing_requirement(self):
        baseline = evaluate(self.root)["summary"]
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
        self.assertEqual(r["summary"]["requirements"], baseline["requirements"])
        self.assertEqual(r["summary"]["discovery_counts"]["PLAYER_ADMIN_REQUEST"],
                         baseline["discovery_counts"]["PLAYER_ADMIN_REQUEST"] + 2)

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
        before = json.loads((self.root / PATHS[0]).read_text(encoding="utf-8"))["items"][0]
        removed_code = sum(d["channel"] == "CODE_ANALYSIS" for d in before["discoveries"])
        baseline_code = evaluate(self.root)["summary"]["discovery_counts"]["CODE_ANALYSIS"]
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
        self.assertEqual(r["summary"]["discovery_counts"]["CODE_ANALYSIS"],
                         baseline_code - removed_code)

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
