"""Synthetic Phase-B baseline for regression tests only.

The live repository RR/decision registries advance through real dispatch
transitions. Tests that exercise the *original* all-queued scenario must
restore that scenario in their own temporary copy, not require production
registries to roll back or weaken the CI integrity checks.
"""
import json
from pathlib import Path


def reset_queued_fixture(root: Path, *, empty_review_ledger: bool = False) -> None:
    """Reset *temporary checkout* RR state to a consistent pre-claim fixture."""
    path = root / "research/requests/index.json"
    data = json.loads(path.read_text(encoding="utf-8"))
    for item in data["items"]:
        item["status"] = "PENDING"
        dispatch = item["dispatch"]
        dispatch["state"] = "QUEUED"
        dispatch.pop("claim", None)
        dispatch.pop("submission", None)
        dispatch.pop("review", None)
        dispatch["events"] = [{
            "from": None,
            "to": "QUEUED",
            "actor": "S00 synthetic fixture",
            "date": "2026-10-29",
            "note": "Isolated regression fixture; never published as a real transition",
        }]
    path.write_text(json.dumps(data, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    if empty_review_ledger:
        path = root / "governance/reviews/index.json"
        review = json.loads(path.read_text(encoding="utf-8"))
        review["items"] = []
        path.write_text(json.dumps(review, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
