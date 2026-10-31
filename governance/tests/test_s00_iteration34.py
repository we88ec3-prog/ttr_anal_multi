"""Iteration34 source-pinned planning and no-unearned-implementation regressions."""
import json
import shutil
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "governance"))
from check_s00_iteration34 import MATRIX, CASES, PLAN, SOURCE33, validate

FILES = [MATRIX, CASES, PLAN, *SOURCE33, "shared/targets.json",
         "design/requirements/index.json", "design/decisions/index.json"]


class Iteration34Tests(unittest.TestCase):
    def setUp(self):
        t = tempfile.TemporaryDirectory()
        self.addCleanup(t.cleanup)
        self.root = Path(t.name)
        for name in FILES:
            target = self.root / name
            target.parent.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(ROOT / name, target)

    def update(self, path, fn):
        f = self.root / path
        obj = json.loads(f.read_text(encoding="utf-8"))
        fn(obj)
        f.write_text(json.dumps(obj, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")

    def expect(self, phrase):
        errors = validate(self.root)
        self.assertTrue(any(phrase in e for e in errors), errors)

    def test_baseline_is_only_a_plan(self):
        self.assertEqual([], validate(self.root))
        m = json.loads((self.root / MATRIX).read_text(encoding="utf-8"))
        self.assertEqual(16, len(m["cases"]))
        self.assertEqual(8, len(m["r0_preflight"]))
        self.assertFalse(m["server_delta"]["c05_implemented"])

    def test_iteration33_anchor_tamper(self):
        self.update(MATRIX, lambda x: x["s00_baseline"]["iteration33_plan"].update(git_blob_sha="f"*40))
        self.expect("Source Git blob mismatch")

    def test_iteration33_upstream_content_mutation(self):
        f = self.root / SOURCE33[0]
        f.write_text(f.read_text(encoding="utf-8")+"\nmodified\n", encoding="utf-8")
        self.expect("Source Git blob mismatch")

    def test_new_server_fake_implementation(self):
        self.update(MATRIX, lambda x: x["server_delta"].update(c05_implemented=True))
        self.expect("Unearned Server/Client")

    def test_server_comparison_count_drift(self):
        self.update(MATRIX, lambda x: x["server_delta"].update(compare_ahead=22))
        self.expect("Fixed actual Server comparison")

    def test_fake_remote_admin_capability(self):
        self.update(MATRIX, lambda x: x["server_delta"].update(remote_ip_cidr_implemented=True))
        self.expect("Unearned Server/Client")

    def test_pretend_pg_web_admin_implemented(self):
        self.update(MATRIX, lambda x: x["server_delta"].update(postgres_web_admin_implemented=True))
        self.expect("Unearned Server/Client")

    def test_pretend_original_client_success(self):
        self.update(MATRIX, lambda x: x["server_delta"].update(native_client_compatibility_verified=True))
        self.expect("Unearned Server/Client")

    def test_fake_server_ci_scope(self):
        self.update(MATRIX, lambda x: x["server_delta"]["ci_results"][0].update(scope="NATIVE_CLIENT_PASSED"))
        self.expect("Server CI snapshot")

    def test_missing_real_server_source_anchor(self):
        self.update(MATRIX, lambda x: x["server_delta"]["observed_paths"].pop())
        self.expect("Seven Server snapshot source")

    def test_same_req_cannot_be_registered_twice(self):
        self.update(MATRIX, lambda x: x["alignment"][2].update(id="REQ-0007"))
        self.expect("Duplicate or missing REQ reuse")

    def test_local_admin_cannot_be_full_production(self):
        self.update(MATRIX, lambda x: x["alignment"][0].update(observed="PRODUCTION_APPROVED"))
        self.expect("Admin scope promoted")

    def test_r0_not_approved_by_design(self):
        self.update(MATRIX, lambda x: x["r0_preflight"][0].update(state="PASS"))
        self.expect("R0 preflight silently approved")

    def test_p01_cannot_depend_on_native_wire(self):
        self.update(MATRIX, lambda x: x["p01_proposed_api"].update(native_wire=True))
        self.expect("P01 cannot bypass")

    def test_p01_requires_fingerprint(self):
        self.update(MATRIX, lambda x: x["p01_proposed_api"]["input_fields"].remove("RequestFingerprint"))
        self.expect("P01 cannot bypass")

    def test_case_cannot_claim_execution(self):
        self.update(MATRIX, lambda x: x["cases"][3].update(execution_status="PASS"))
        self.expect("may not claim runtime")

    def test_missing_markdown_case(self):
        f = self.root / CASES
        f.write_text(f.read_text(encoding="utf-8").replace("| I34-T16 |", "| OMIT-T16 |"),encoding="utf-8")
        self.expect("Acceptance Markdown/JSON mismatch")

    def test_migration_unallocated_until_approved(self):
        self.update(MATRIX, lambda x: x["governance"].update(next_migrations="SQLite_v3_ALLOCATED"))
        self.expect("Unapproved C05 migration")

    def test_no_implicit_native_gate(self):
        self.update(MATRIX, lambda x: x["governance"].update(native_adapter_enabled=True))
        self.expect("Unearned governance")

    def test_existing_adr_not_automatically_approved(self):
        self.update("design/decisions/index.json", lambda x:
                    next(item for item in x["items"] if item["id"] == "ADR-0007").update(status="APPROVED"))
        self.expect("ADR-0007 must remain PROPOSED")


if __name__ == "__main__":
    unittest.main()
