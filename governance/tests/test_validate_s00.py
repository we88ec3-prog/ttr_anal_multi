"""S00: source identity, bounded claims, references, and Stable-gate regression."""
import hashlib
import json
import shutil
import sys
import tempfile
import unittest
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/"governance"))
from validate_s00 import FILES,validate

class S00IndexTests(unittest.TestCase):
    def setUp(self):
        self.tmp=tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root=Path(self.tmp.name)
        paths={value[0] for value in FILES.values()}
        paths.add("shared/targets.json")
        paths.add("kr/tasks/T02/task.json")
        paths.add("kr/tasks/T03/task.json")
        for index_path in [value[0] for value in FILES.values()]:
            index=json.loads((ROOT/index_path).read_text(encoding="utf-8"))
            for row in index["items"]:
                for key in ("spec_path","source_file","fixture_path","test_path","native_review_ref","path"):
                    if row.get(key):paths.add(row[key])
                for s in row.get("source_refs",[]):paths.add(s)
                for evidence_ref in row.get("evidence_refs", []):
                    paths.add(evidence_ref)
        for path in paths:
            dest=self.root/path
            dest.parent.mkdir(parents=True,exist_ok=True)
            shutil.copy2(ROOT/path,dest)

    def edit(self,path,mutate):
        p=self.root/path
        obj=json.loads(p.read_text(encoding="utf-8"))
        mutate(obj)
        p.write_text(json.dumps(obj,ensure_ascii=False),encoding="utf-8")

    def test_current_indexes_valid(self):
        self.assertEqual(validate(self.root),[])

    def test_reference_and_gate_protection(self):
        self.edit("spec/spec-index.json",lambda d:d["items"][0]["gap_ids"].append("GAP-FAKE"))
        self.assertTrue(any("unresolved" in x for x in validate(self.root)))

    def test_unproven_stable_rejected(self):
        self.edit("spec/spec-index.json",lambda d:d["items"][0].update({"maturity":"STABLE"}))
        self.assertTrue(any("STABLE requires" in x for x in validate(self.root)))

    def test_source_integrity_is_checked(self):
        p=self.root/"kr/evidence/f398779b1e129b0150f009451dc72b51b1cb9b88e9f2aa5c43b4eeeac02e0e94.txt"
        p.write_bytes(p.read_bytes()+b"\naccidental tampering\n")
        self.assertTrue(any("source SHA256 mismatch" in x for x in validate(self.root)))

    def test_source_must_have_claims_before_promotion(self):
        def mutate(d):
            entry=d["items"][0]
            entry["integration_status"]="SPEC_CONSUMABLE"
            entry["claim_ids"]=[]
        self.edit("research/intake/index.json",mutate)
        self.assertTrue(any("promoted source must" in x for x in validate(self.root)))

    def test_server_adr_proposal_cannot_be_normative(self):
        def mutate(d):
            d["items"][0]["normative"] = True
        self.edit("design/decisions/index.json", mutate)
        self.assertTrue(any("PROPOSED ADR cannot be normative" in x for x in validate(self.root)))

    def test_reviewed_spec_cannot_use_unapproved_adr(self):
        def mutate(d):
            d["items"][0]["maturity"] = "REVIEWED"
            d["items"][0]["adr_ids"] = ["ADR-0001"]
        self.edit("spec/spec-index.json", mutate)
        self.assertTrue(any("unapproved ADR" in x for x in validate(self.root)))

    def test_native_verified_claim_requires_scoped_evidence(self):
        def remove_proof(doc):
            claim = next(r for r in doc["items"] if r["id"] == "CLM-CLIENT-0063")
            self.assertEqual(claim["evidence_level"], "NATIVE_VERIFIED")
            claim.pop("evidence_refs", None)
        self.edit("research/claims/index.json", remove_proof)
        self.assertTrue(any("CLM-CLIENT-0063: NATIVE_VERIFIED requires scoped native evidence references"
                            in err for err in validate(self.root)))

    def test_native_verified_claim_missing_reference_is_rejected(self):
        def break_proof(doc):
            claim = next(r for r in doc["items"] if r["id"] == "CLM-CLIENT-0063")
            claim["evidence_refs"] = ["research/handoffs/missing-native-proof.json"]
        self.edit("research/claims/index.json", break_proof)
        self.assertTrue(any("CLM-CLIENT-0063: missing/unsafe file" in err for err in validate(self.root)))

    def test_native_verified_claim_duplicate_reference_is_rejected(self):
        def duplicate_proof(doc):
            claim = next(r for r in doc["items"] if r["id"] == "CLM-CLIENT-0063")
            claim["evidence_refs"] = [claim["evidence_refs"][0]] * 2
        self.edit("research/claims/index.json", duplicate_proof)
        self.assertTrue(any("CLM-CLIENT-0063: NATIVE_VERIFIED evidence_refs must not contain duplicates"
                            in err for err in validate(self.root)))

    def test_wrong_client_target_is_rejected(self):
        self.edit("spec/spec-index.json",lambda d:d["items"][0].update({"client_version":"tc"}))
        self.assertTrue(any("target SHA differs" in x for x in validate(self.root)))

if __name__=="__main__":
    unittest.main()
