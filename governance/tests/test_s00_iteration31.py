"""Regression protection for S00 Iteration31's proposed Quest/Reward domain scope."""
import json
import shutil
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "governance"))
from check_s00_iteration31 import MATRIX, SOURCES, CASES, check  # noqa: E402

FILES = [MATRIX, *SOURCES, CASES, "shared/targets.json", "design/decisions/index.json"]


class Iteration31Tests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        for path in FILES:
            dest = self.root / path
            dest.parent.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(ROOT / path, dest)

    def update(self, name, fn):
        path = self.root / name
        d = json.loads(path.read_text(encoding="utf-8"))
        fn(d)
        path.write_text(json.dumps(d, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")

    def reject(self, text):
        errors = check(self.root)
        self.assertTrue(any(text in e for e in errors), errors)

    def test_current_contract_is_source_pinned_and_not_executed(self):
        self.assertEqual(check(self.root), [])
        d = json.loads((self.root / MATRIX).read_text(encoding="utf-8"))
        self.assertEqual(len(d["packages"]), 4)
        self.assertFalse(d["policy"]["server_c05_implemented"])
        self.assertEqual(d["migration"]["sqlite_next_number"], "UNALLOCATED_NOT_APPLIED")

    def test_source_blob_fingerprint_mutated(self):
        self.update(MATRIX,lambda d:d["source_blobs"][0].update(git_blob_sha="0"*40))
        self.reject("Source Git blob mismatch")

    def test_source_file_changed_without_review(self):
        self.update(SOURCES[0],lambda d:d.update(kind="NORMATIVE"))
        self.reject("Source Git blob mismatch")

    def test_quest_source_gate_promoted(self):
        self.update(MATRIX,lambda d:d["original_gates_snapshot"][0].update(evidence_state="NATIVE_VERIFIED"))
        self.reject("original gate evidence/owner/status promoted")

    def test_original_owner_changed(self):
        self.update(MATRIX,lambda d:d["original_gates_snapshot"][1].update(owner_tasks=["S00"]))
        self.reject("original gate evidence/owner/status promoted")

    def test_fake_server_implementation_claim(self):
        self.update(MATRIX,lambda d:d["policy"].update(server_c05_implemented=True))
        self.reject("Forbidden native/completion claim")

    def test_original_client_compatibility_enable_rejected(self):
        self.update(MATRIX,lambda d:d["policy"].update(native_adapter_enabled=True))
        self.reject("Forbidden native/completion claim")

    def test_adr_not_silently_approved(self):
        self.update("design/decisions/index.json",lambda d:next(x for x in d["items"] if x["id"]=="ADR-0007").update(status="APPROVED"))
        self.reject("ADR-0007 must remain PROPOSED")

    def test_quest_and_world_states_separate(self):
        self.update(MATRIX,lambda d:d["states"].update(separation="Quest15 AVAILABLE == WorldReady"))
        self.reject("Quest/Scenario/Tutorial/World separation")

    def test_reward_type2_not_assumed_currency(self):
        self.update(MATRIX,lambda d:d["prohibitions"].remove("NO_QUEST16_REWARD_TYPE2_AS_CURRENCY"))
        self.reject("Missing mandatory no-go")

    def test_migration_number_not_reused(self):
        self.update(MATRIX,lambda d:d["migration"].update(sqlite_next_number="3"))
        self.reject("centrally allocated and unapplied")

    def test_provider_version_not_outdated(self):
        self.update(MATRIX,lambda d:d["migration"].update(sqlite_base_version=1))
        self.reject("centrally allocated and unapplied")

    def test_server_snapshot_not_claimed_native(self):
        self.update(MATRIX,lambda d:d["server_snapshot"].update(ci_conclusion="CLIENT_NATIVE_VERIFIED"))
        self.reject("Remote Server CI falsely represented")

    def test_duplicate_case_detected(self):
        self.update(MATRIX,lambda d:d["packages"][1].update(test_cases=["I31-T01",*d["packages"][1]["test_cases"][1:]]))
        self.reject("Every I31 case must belong to exactly one")

    def test_cycle_detected(self):
        self.update(MATRIX,lambda d:d["packages"][0].update(depends_on=["S31-04"]))
        self.reject("Dependency cycle")

    def test_wrong_quest_gate_detected(self):
        self.update(MATRIX,lambda d:d["packages"][1].update(gate_ids=["E17-Z"]))
        self.reject("unregistered native evidence gate")

    def test_missing_case_detected(self):
        f=self.root / CASES
        f.write_text(f.read_text(encoding="utf-8").replace("| I31-T24 |","| MISSING-T24 |"),encoding="utf-8")
        self.reject("Expected 24 unique NOT_RUN")

    def test_missing_server_source_anchor_rejected(self):
        self.update(MATRIX,lambda d:d["server_snapshot"]["anchors"][0].update(git_blob_sha="bogus"))
        self.reject("Unsafe/malformed Server blob record")


if __name__ == "__main__":
    unittest.main()
