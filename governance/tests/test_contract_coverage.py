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
    "research/claims/index.json", "research/intake/index.json",
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
    def test_forged_test_status_does_not_remove_synthetic_blocker(self):
        p = self.root / "conformance/test-index.json"
        data = json.loads(p.read_text(encoding="utf-8"))
        data["items"][0]["status"] = "ORIGINAL_CLIENT_COMPATIBILITY"
        p.write_text(json.dumps(data), encoding="utf-8")
        result = evaluate(self.root)
        self.assertTrue(any("not an approved provenance class" in e for e in result["errors"]))
        self.assertEqual(result["summary"]["review_candidates"], 0)

    def test_unknown_evidence_claim_does_not_count_as_proof(self):
        self.mutate(lambda x: x.update(evidence_refs=["CLM-DOES-NOT-EXIST"]))
        self.mutate(lambda x: x["facets"].update(connection_context="EVIDENCE_BACKED"))
        self.assertTrue(any("unregistered evidence claim" in e for e in evaluate(self.root)["errors"]))

    def test_partial_claim_does_not_auto_upgrade_evidence_facet(self):
        self.mutate(lambda x: x.update(evidence_refs=["CLM-NET-0001"]))
        self.mutate(lambda x: x["facets"].update(connection_context="EVIDENCE_BACKED"))
        self.assertTrue(any("lacks scoped native review" in e for e in evaluate(self.root)["errors"]))

    def test_cross_version_claim_cannot_support_evidence(self):
        self.mutate(lambda x: x.update(evidence_refs=["CLM-NET-0001"]))
        self.mutate(lambda x: x["facets"].update(connection_context="EVIDENCE_BACKED"))
        p = self.root / "research/claims/index.json"
        data = json.loads(p.read_text(encoding="utf-8"))
        next(x for x in data["items"] if x["id"] == "CLM-NET-0001")["client_version"] = "tc"
        p.write_text(json.dumps(data), encoding="utf-8")
        self.assertTrue(any("source/target lineage mismatch" in e for e in evaluate(self.root)["errors"]))

if __name__ == "__main__":
    unittest.main()
