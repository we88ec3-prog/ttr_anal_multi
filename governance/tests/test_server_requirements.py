"""S00 Server requirement source categories are discovery origins, not proof grades."""
import json
import shutil
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "governance"))
from check_server_requirements import evaluate  # noqa: E402

INDEXES = [
    "spec/server-requirements/index.json",
    "research/claims/index.json",
    "research/requests/index.json",
    "spec/spec-index.json",
    "design/gaps/index.json",
    "shared/targets.json",
]


class ServerRequirementTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)
        for rel in INDEXES:
            dst = self.root / rel
            dst.parent.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(ROOT / rel, dst)
        rows = json.loads((self.root / INDEXES[0]).read_text(encoding="utf-8"))["items"]
        for row in rows:
            source = self.root / row["source_path"]
            source.parent.mkdir(parents=True, exist_ok=True)
            source.write_text("test-only copy of source path", encoding="utf-8")

    def mutate(self, fn):
        p = self.root / INDEXES[0]
        data = json.loads(p.read_text(encoding="utf-8"))
        fn(data["items"])
        p.write_text(json.dumps(data), encoding="utf-8")

    def test_existing_four_candidates_three_active_origins(self):
        report = evaluate(self.root)
        self.assertEqual(report["errors"], [], report["errors"])
        self.assertEqual(report["summary"]["candidates"], 4)
        self.assertEqual(report["summary"]["origin_counts"], {
            "CODE_ANALYSIS": 3, "USER_REQUEST": 1
        })
        self.assertEqual(report["summary"]["approved_contracts"], 0)

    def test_code_analysis_alone_can_discover_server_sends(self):
        self.assertEqual(evaluate(self.root)["errors"], [])
        self.assertEqual(
            [x["origin"] for x in evaluate(self.root)["items"]][:3],
            ["CODE_ANALYSIS"] * 3)

    def test_user_request_needs_no_native_code_claim(self):
        self.mutate(lambda rows: rows[3].update(source_claim_ids=[]))
        self.assertEqual(evaluate(self.root)["errors"], [])

    def test_historical_material_is_attachment_under_user_request(self):
        def add(rows):
            rows[3]["reference_materials"] = [{
                "description": "old Server protocol fragment (hypothetical test)",
                "location": "user-provided://historical-version-not-verified",
                "provenance_note": "User-provided historical note; authenticity unverified"
            }]
        self.mutate(add)
        self.assertEqual(evaluate(self.root)["errors"], [])
        self.mutate(lambda rows: rows[3].update(origin="HISTORICAL_PROTOCOL_ARTIFACT"))
        self.assertTrue(any("invalid origin" in x for x in evaluate(self.root)["errors"]))

    def test_unreviewed_user_attachment_is_not_native_evidence(self):
        self.mutate(lambda rows: rows[3].update(
            reference_materials=[{"description": "old packet", "location": "somewhere"}]))
        self.assertTrue(any("historical/reference attachment" in x for x in evaluate(self.root)["errors"]))

    def test_missing_claim_link_cannot_be_sourced_as_code(self):
        self.mutate(lambda rows: rows[0].update(source_claim_ids=[]))
        self.assertTrue(any("source-aligned registered CLM" in x for x in evaluate(self.root)["errors"]))

    def test_no_cross_version_evidence_in_kr_requirement(self):
        self.mutate(lambda rows: rows[0].update(
            source_claim_ids=["CLM-DOES-NOT-EXIST"]))
        self.assertTrue(any("missing source_claim_ids link" in x for x in evaluate(self.root)["errors"]))

    def test_runtime_requires_authorization_and_a_record(self):
        self.mutate(lambda rows: rows[3].update(
            origin="RUNTIME_OBSERVATION", evidence_status="RUNTIME_RECORDED"))
        self.assertTrue(any("authorized, retained record" in x for x in evaluate(self.root)["errors"]))
        self.mutate(lambda rows: rows[3].update(authorized_record_ref="test-only-authorized-record"))
        self.assertEqual(evaluate(self.root)["errors"], [])

    def test_candidate_index_cannot_self_publish_approved(self):
        self.mutate(lambda rows: rows[0].update(status="APPROVED"))
        self.assertTrue(any("CANDIDATE-only" in x for x in evaluate(self.root)["errors"]))

    def test_no_index_mutation(self):
        before = {p: (self.root / p).read_bytes() for p in INDEXES}
        evaluate(self.root)
        self.assertEqual(before, {p: (self.root / p).read_bytes() for p in INDEXES})


if __name__ == "__main__":
    unittest.main()
