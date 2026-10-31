"""Iteration40 bounded T01 merge / C04 login receive planning safety tests."""
import json
import shutil
import sys
import tempfile
import unittest
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/"governance"))
from check_s00_iteration40 import evaluate
FILES=[
"governance/s00-iterations/S00-ITERATION-40-C04-LOGIN-M2-ACCEPTANCE.json",
"governance/s00-iterations/S00-20261101-ITERATION-40-T01-SYNC-C04-LOGIN-RECEIVE-DELIVERY.md",
"design/requirements/index.json","research/requests/index.json",
"design/gaps/index.json","research/claims/index.json",
"research/intake/index.json","shared/targets.json",
]
class Iteration40Tests(unittest.TestCase):
    def setUp(self):
        self.temp=tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root=Path(self.temp.name)
        for f in FILES:
            dest=self.root/f
            dest.parent.mkdir(parents=True,exist_ok=True)
            shutil.copyfile(ROOT/f,dest)

    def mutate(self,change):
        p=self.root/FILES[0]
        j=json.loads(p.read_text(encoding="utf-8"))
        change(j)
        p.write_text(json.dumps(j,ensure_ascii=False),encoding="utf-8")

    def test_baseline(self):
        r=evaluate(self.root)
        self.assertEqual(r["errors"],[])
        self.assertEqual(r["summary"]["gates"],15)
        self.assertEqual(r["summary"]["milestones"],5)

    def test_native_source_cannot_be_raised_to_full_pass(self):
        self.mutate(lambda x:x["gates"][12].update(status="PASS"))
        self.assertTrue(any("Cannot declare" in v for v in evaluate(self.root)["errors"]))

    def test_source_claim_inheritance_must_remain_partial(self):
        self.mutate(lambda x:x["known_source_claims"][0].update(id="CLM-NET-0001"))
        self.assertTrue(any("source claim not correctly bounded" in v for v in evaluate(self.root)["errors"]))

    def test_missing_native_rr_fails(self):
        self.mutate(lambda x:x["reused_rrs"].append("RR-9999"))
        self.assertTrue(any("missing/duplicated/unknown" in v for v in evaluate(self.root)["errors"]))

    def test_original_runtime_cannot_be_falsely_passed(self):
        self.mutate(lambda x:x["milestones"][2].update(is_original_client_verified=True))
        self.assertTrue(any("falsely claims" in v for v in evaluate(self.root)["errors"]))

    def test_no_implicit_client_execution_permission(self):
        self.mutate(lambda x:x["authorization"].update(original_client_test_performed=True))
        self.assertTrue(any("cannot self-certify" in v for v in evaluate(self.root)["errors"]))

    def test_no_original_client_target_drift(self):
        self.mutate(lambda x:x.update(kr_bin_sha256="0"*64))
        self.assertTrue(any("target pin mismatch" in v for v in evaluate(self.root)["errors"]))

    def test_no_new_rr_without_registry(self):
        self.mutate(lambda x:x["formal_registry_mutations"].update(new_rr=1))
        self.assertTrue(any("cannot change formal registry" in v for v in evaluate(self.root)["errors"]))

if __name__=="__main__":
    unittest.main()
