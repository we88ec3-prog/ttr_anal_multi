"""Regression checks for the S00 dispatch inbox and life-cycle protocol."""
import json
import sys
import tempfile
import unittest
from pathlib import Path

ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/"research"/"dispatch"))
from dispatch import blob_sha, inbox_text, read, sync, transition, validate  # noqa: E402

DATE="2026-10-29"
BASE="a"*40

class DispatchTests(unittest.TestCase):
    def setUp(self):
        self.temp=tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root=Path(self.temp.name)
        for rel in ["research/requests/index.json","design/gaps/index.json"]:
            fp=self.root/rel
            fp.parent.mkdir(parents=True,exist_ok=True)
            source=ROOT/rel
            fp.write_bytes(source.read_bytes())
        # Snapshot isolates the test from later real claims or new dispatches.
        gaps={"schema":"s00-gap-index-v1","items":[{"id":"GAP-DEMO","status":"OPEN"}]}
        (self.root/"design/gaps/index.json").write_text(json.dumps(gaps),encoding="utf-8")
        fixture={
            "schema":"s00-research-request-index-v1",
            "items":[{
                "id":"RR-9001","title":"Verify a synthetic task lifecycle",
                "owner_task":"T03","client_version":"kr",
                "status":"PENDING","gap_ids":["GAP-DEMO"],"question":"Research a specific native gate",
                "dispatch":{
                    "state":"QUEUED","priority":"P0","acceptance_criteria":"Produce scoped evidence",
                    "claim":None,"submission":None,"review":None,
                    "events":[{"from":None,"to":"QUEUED","actor":"S00","date":DATE,"note":"Test queued"}]
                }
            }]
        }
        (self.root/"research/requests/index.json").write_text(
            json.dumps(fixture,ensure_ascii=False,indent=2),encoding="utf-8")
        sync(self.root,fixture["items"])

    def do(self,state,actor="agent",**kwargs):
        return transition(self.root,"RR-9001",state,actor,DATE,
                          kwargs.pop("note","Scope-limited research event"),**kwargs)

    def test_task_inboxes_are_derived_not_separate_writable_state(self):
        rows=read(self.root)["items"]
        self.assertIn("RR-9001",inbox_text("T03",rows))
        self.assertNotIn("RR-9001",inbox_text("T04",rows))
        self.assertIn("目前無待處理",inbox_text("T01",rows))
        self.assertEqual(validate(self.root,boot=False),[])

    def test_report_and_acceptance_require_review(self):
        self.do("CLAIMED",branch="t03/rr-9001",base=BASE)
        self.do("IN_PROGRESS")
        fp=self.root/"kr-temp-roy"/"report.md"
        fp.parent.mkdir(parents=True,exist_ok=True)
        fp.write_text("# Bounded research\n",encoding="utf-8")
        with self.assertRaises(ValueError):
            self.do("ACCEPTED",actor="S00",outcomes=["SPEC-TEST"])
        self.do("SUBMITTED",report="kr-temp-roy/report.md")
        with self.assertRaises(ValueError):
            self.do("ACCEPTED",actor="S00",outcomes=["SPEC-TEST"])
        self.do("IN_REVIEW",actor="T01")
        with self.assertRaises(ValueError):
            self.do("ACCEPTED",actor="untrusted-reviewer",outcomes=["SPEC-TEST"])
        self.do("ACCEPTED",actor="S00",outcomes=["SPEC-TEST"])
        row=read(self.root)["items"][0]
        self.assertEqual(row["status"],"RESOLVED")
        self.assertEqual(row["dispatch"]["submission"]["report_blob_sha"],blob_sha(fp.read_bytes()))
        self.assertEqual(validate(self.root,boot=False),[])
        with self.assertRaises(ValueError):
            self.do("IN_PROGRESS")
        fp.write_text("# Silently altered research\n",encoding="utf-8")
        self.assertTrue(any("modified submission report" in e for e in validate(self.root,boot=False)))

    def test_duplicate_claim_and_missing_evidence_rejected(self):
        with self.assertRaises(ValueError):
            self.do("CLAIMED",branch="no-baseline")
        self.do("CLAIMED",branch="t03/rr-9001",base=BASE)
        with self.assertRaises(ValueError):
            self.do("CLAIMED",branch="other/rr-9001",base=BASE)
        with self.assertRaises(ValueError):
            self.do("IN_PROGRESS",actor="different-agent")
        self.do("IN_PROGRESS")
        with self.assertRaises(ValueError):
            self.do("SUBMITTED",report="kr-temp-roy/does-not-exist.md")

    def test_stale_inbox_and_bad_status_caught(self):
        p=self.root/"research/dispatch/inbox/T03.md"
        p.write_text("broken",encoding="utf-8")
        # Full bootstrap checks would also require README/AGENTS; inbox must still fail.
        self.assertTrue(any("stale generated inbox" in e for e in validate(self.root,boot=True)))
        sync(self.root,read(self.root)["items"])
        data=read(self.root)
        data["items"][0]["status"]="RESOLVED"
        (self.root/"research/requests/index.json").write_text(json.dumps(data),encoding="utf-8")
        self.assertTrue(any("status disagrees" in e for e in validate(self.root,boot=False)))

    def test_invalid_history_rejected(self):
        obj=read(self.root)
        obj["items"][0]["dispatch"]["events"].append({
            "from":"QUEUED","to":"ACCEPTED","actor":"fake","date":DATE,"note":"bypass review"
        })
        (self.root/"research/requests/index.json").write_text(json.dumps(obj),encoding="utf-8")
        self.assertTrue(any("forbidden history" in e for e in validate(self.root,boot=False)))

if __name__=="__main__":
    unittest.main()
