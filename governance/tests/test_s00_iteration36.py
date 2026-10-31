"""Iteration36: source-bound PG4/Server ownership regression suite. No DB/Client execution."""
import json
import shutil
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/"governance"))
from check_s00_iteration36 import validate, MODEL, REPORT, HISTORICAL, T01_REPORT

FILES = [MODEL,REPORT,HISTORICAL,T01_REPORT,
         "shared/targets.json","design/requirements/index.json",
         "design/decisions/index.json","governance/check_s00_iteration35.py",
         "governance/tests/test_s00_iteration35.py"]


class Iteration36Tests(unittest.TestCase):
    def setUp(self):
        self.t = tempfile.TemporaryDirectory()
        self.addCleanup(self.t.cleanup)
        self.root = Path(self.t.name)
        for name in FILES:
            dest=self.root/name
            dest.parent.mkdir(parents=True,exist_ok=True)
            shutil.copyfile(ROOT/name,dest)

    def modify(self,path,action):
        f=self.root/path
        d=json.loads(f.read_text(encoding="utf-8"))
        action(d)
        f.write_text(json.dumps(d,ensure_ascii=False,indent=2)+"\n",encoding="utf-8")

    def fail_has(self,msg):
        problems=validate(self.root)
        self.assertTrue(any(msg in x for x in problems),problems)

    def test_current_release_is_non_normative(self):
        self.assertEqual([],validate(self.root))
        d=json.loads((self.root/MODEL).read_text(encoding="utf-8"))
        self.assertEqual(12,len(d["cases"]))
        self.assertEqual(4,d["server_delta"]["postgres_v4"]["version"])

    def test_historical_no_receipt_pin_immutable(self):
        self.modify(HISTORICAL,lambda d:d["slots"][0].update(state="APPROVED"))
        self.fail_has("Iteration35 historical blob")

    def test_stale_server_snapshot_cannot_appear_current(self):
        self.modify(MODEL,lambda d:d["server_delta"].update(head_sha="a"*40))
        self.fail_has("Source-pinned actual Server diff changed")

    def test_compare_commits_count_pinned(self):
        self.modify(MODEL,lambda d:d["server_delta"].update(ahead=33))
        self.fail_has("Source-pinned actual Server diff changed")

    def test_migration_source_blob_pinned(self):
        self.modify(MODEL,lambda d:d["server_delta"]["sources"][0].update(git_blob_sha="0"*40))
        self.fail_has("Nine exact actual Server source blobs")

    def test_postgres_four_reserved_for_web(self):
        self.modify(MODEL,lambda d:d["server_delta"]["postgres_v4"].update(allocated_to="C05"))
        self.fail_has("Postgres v4 is source allocation")

    def test_actual_prod_db_not_inferred(self):
        self.modify(MODEL,lambda d:d["server_delta"]["postgres_v4"].update(production_db_migrated="YES"))
        self.fail_has("not a production DB observation")

    def test_pg_v5_not_preallocated(self):
        self.modify(MODEL,lambda d:d["server_delta"]["c05"].update(postgres_next_version_assigned=True))
        self.fail_has("PG 004 reserved")

    def test_c05_p01_not_implemented(self):
        self.modify(MODEL,lambda d:d["server_delta"]["c05"].update(p01="VERIFIED"))
        self.fail_has("PG 004 reserved")

    def test_no_native_adapter_upgrade(self):
        self.modify(MODEL,lambda d:d["server_delta"]["c05"].update(native_adapter_enabled=True))
        self.fail_has("PG 004 reserved")

    def test_pg_web_not_publicly_exposed(self):
        self.modify(MODEL,lambda d:d["server_delta"]["postgres_v4"].update(remote_ip_cidr="IMPLEMENTED"))
        self.fail_has("Unproven remote")

    def test_t16_report_source_pin(self):
        f=self.root/T01_REPORT
        f.write_text(f.read_text(encoding="utf-8")+"extra\n",encoding="utf-8")
        self.fail_has("T01/T16-134 source intake falsely promoted")

    def test_t16_134_not_full_pass(self):
        self.modify(MODEL,lambda d:d["t01_concurrent_source"].update(native_full_pass=True))
        self.fail_has("T01/T16-134 source intake falsely promoted")

    def test_formal_req_not_approved(self):
        self.modify("design/requirements/index.json",lambda d:next(x for x in d["items"] if x["id"]=="REQ-0008").update(status="APPROVED"))
        self.fail_has("Formal REQ/ADR")

    def test_formal_adr_still_proposed(self):
        self.modify("design/decisions/index.json",lambda d:next(x for x in d["items"] if x["id"]=="ADR-0006").update(status="APPROVED"))
        self.fail_has("Formal REQ/ADR")

    def test_pg_legacy_candidate_migration_baseline_rejected(self):
        f=self.root/"governance/check_s00_iteration35.py"
        f.write_text(f.read_text(encoding="utf-8").replace('baseline = 2 if provider == "SQLITE" else 4','baseline = 2 if provider == "SQLITE" else 3'),encoding="utf-8")
        self.fail_has("Iteration35 candidate still accepts stale PG3")

    def test_downstream_acceptance_not_fake_pass(self):
        self.modify(MODEL,lambda d:d["cases"][0].update(execution="PASS"))
        self.fail_has("downstream tests must remain NOT_RUN")

    def test_server_test_claim_not_permitted(self):
        self.modify(MODEL,lambda d:d["harness"].update(server_tests_run_by_s00=True))
        self.fail_has("Checker cannot claim actual Server")


if __name__=="__main__":
    unittest.main()
