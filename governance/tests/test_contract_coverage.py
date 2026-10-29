"""Regression tests for S00 source-scoped contract-level readiness."""
import json
import shutil
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "governance"))
from check_contract_coverage import evaluate  # noqa: E402

FILES = [
    "conformance/contract-coverage.json", "spec/spec-index.json",
    "design/gaps/index.json", "research/requests/index.json",
    "conformance/test-index.json", "shared/targets.json",
]

class ContractCoverageTests(unittest.TestCase):
    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory()
        self.addCleanup(self.temporary.cleanup)
        self.root = Path(self.temporary.name)
        for rel in FILES:
            p = self.root / rel
            p.parent.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(ROOT / rel, p)

    def mutate(self, operation):
        p = self.root / FILES[0]
        value = json.loads(p.read_text(encoding="utf-8"))
        operation(value["items"][0])
        p.write_text(json.dumps(value, ensure_ascii=False), encoding="utf-8")

    def test_baseline_is_consistent_but_no_wire_contract_ready(self):
        report = evaluate(self.root)
        self.assertEqual(report["errors"], [], report["errors"])
        self.assertEqual(report["summary"]["total"], 7)
        self.assertEqual(report["summary"]["blocked"], 7)
        self.assertEqual(report["summary"]["review_candidates"], 0)
        self.assertTrue(any("OFFLINE_SYNTHETIC_ONLY" in x
                            for x in report["contracts"][0]["blockers"]))
        self.assertTrue(any("RR-0001=QUEUED" in x
                            for x in report["contracts"][0]["blockers"]))

    def test_unregistered_spec_reference_is_rejected(self):
        self.mutate(lambda x: x["spec_ids"].append("SPEC-MISSING"))
        self.assertTrue(any("unknown spec_ids SPEC-MISSING" in e
                            for e in evaluate(self.root)["errors"]))

    def test_invalid_version_and_sha_are_rejected(self):
        self.mutate(lambda x: x.update(client_version="tc"))
        problems = evaluate(self.root)["errors"]
        self.assertTrue(any("Client version/SHA mismatch" in e for e in problems))
        self.assertTrue(any("cross-Client version" in e for e in problems))

    def test_transport_command_can_be_na_but_layout_cannot(self):
        self.mutate(lambda x: x["facets"].update(byte_layout="NOT_APPLICABLE"))
        self.assertTrue(any("illegal NOT_APPLICABLE on byte_layout" in e
                            for e in evaluate(self.root)["errors"]))

    def test_evidence_backed_claim_requires_proof_references(self):
        self.mutate(lambda x: x["facets"].update(connection_context="EVIDENCE_BACKED"))
        self.assertTrue(any("EVIDENCE_BACKED facet needs explicit proof" in e
                            for e in evaluate(self.root)["errors"]))

if __name__ == "__main__":
    unittest.main()
