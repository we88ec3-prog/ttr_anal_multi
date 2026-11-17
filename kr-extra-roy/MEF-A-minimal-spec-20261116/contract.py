#!/usr/bin/env python3
"""A1-v1 OFFLINE specification helpers. No sockets, DB, Lua or game-file writes.
Validation proves consistency of supplied records, NOT Client readiness/deployment.
Exchange is a policy model, not a production Server implementation.
"""
from __future__ import annotations
import argparse
import hashlib
import json
import math
import re
import struct
from dataclasses import dataclass
from pathlib import Path

SCENE = (0, 32760)
FUNC = "compat_point_once_a_v1"
SEQ_PATH = "Event/Sequences/" + FUNC + ".seq"
ROW = struct.Struct("<HbBfffBB")
START = struct.pack("<Hhh", 0x47, *SCENE)
END_REPORT = struct.pack("<HHHH", 0x3F, *SCENE, 1)
RELEASE = struct.pack("<H", 0xEB)
BIN_SHA = "9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
FIELDS = {
    "profile_id", "client_bin_sha256", "field_type", "field_instance",
    "connection_id", "client_epoch", "snapshot_generation", "snapshot_sha256",
    "snapshot_evidence", "point_key", "point_category", "expected_before",
    "desired", "release_id", "release_point_key", "release_point_category",
    "sequence_sha256", "scene_list_sha256", "release_evidence", "timeout_ms"
}

class ContractError(ValueError):
    pass

def require(ok: bool, reason: str) -> None:
    if not ok:
        raise ContractError(reason)

def integer(value: object, low: int, high: int, field: str) -> int:
    require(type(value) is int and low <= value <= high, "invalid integer: " + field)
    return value  # type: ignore[return-value]

def digest(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()

@dataclass(frozen=True)
class Point:
    key: int
    category: int
    enabled: int
    x: float
    y: float
    radius: float
    tail0: int
    tail1: int

def parse_snapshot(data: bytes) -> list[Point]:
    require(type(data) is bytes, "snapshot must be bytes")
    require(len(data) >= 2 and data[:2] == b"\x27\x00", "not application 0027")
    require((len(data) - 2) % ROW.size == 0, "fractional 0027 row")
    return [Point(*ROW.unpack_from(data, p)) for p in range(2, len(data), ROW.size)]

def validate_binding(binding: dict, snapshot: bytes) -> dict:
    """Compare run snapshot to a prebuilt release target; never chooses a new live target."""
    require(type(binding) is dict and set(binding) == FIELDS, "missing/unknown Binding fields")
    b = binding
    require(b["profile_id"] == "A1-v1", "wrong profile")
    require(b["client_bin_sha256"] == BIN_SHA, "wrong KR Client")
    require(b["field_type"] in ("Mission", "Scenario"), "ordinary field required")
    for key in ("field_instance", "connection_id", "client_epoch", "snapshot_evidence",
                "release_id", "release_evidence"):
        require(type(b[key]) is str and bool(b[key].strip()), "missing evidence/context: " + key)
    for key in ("snapshot_sha256", "sequence_sha256", "scene_list_sha256"):
        require(type(b[key]) is str and re.fullmatch(r"[0-9a-f]{64}", b[key]) is not None,
                "invalid SHA256: " + key)
    integer(b["snapshot_generation"], 0, 2**63-1, "snapshot_generation")
    integer(b["timeout_ms"], 1, 2**31-1, "timeout_ms")
    key = integer(b["point_key"], 0, 65535, "point_key")
    category = integer(b["point_category"], 0, 127, "point_category")
    require(category in (0, 2, 3), "unsupported category in A1-v1")
    require(integer(b["release_point_key"], 0, 65535, "release_point_key") == key,
            "run point differs from immutable release literal")
    require(integer(b["release_point_category"], 0, 127, "release_point_category") == category,
            "run category differs from immutable release literal")
    require(integer(b["expected_before"], 0, 1, "expected_before") == 0 and
            integer(b["desired"], 0, 1, "desired") == 1, "A1-v1 is only 0 -> 1")
    require(digest(snapshot) == b["snapshot_sha256"], "snapshot hash mismatch")
    hits = [p for p in parse_snapshot(snapshot) if (p.category, p.key) == (category, key)]
    require(len(hits) == 1, "target missing or duplicated")
    target = hits[0]
    require(target.enabled == 0, "target is not initially disabled")
    require(all(math.isfinite(v) for v in (target.x, target.y, target.radius)) and
            target.radius > 0, "invalid target geometry; legality still requires provenance")
    return {
        "schema": "ttr.compat-point-a1.plan.v1", "classification": "NOT_NATIVE_MEF",
        "scene": list(SCENE), "sequence_path": SEQ_PATH,
        "target": {"category": category, "key": key, "enabled": 1},
        "start_application_hex": START.hex(), "expected_report_hex": END_REPORT.hex(),
        "release_application_hex": RELEASE.hex(),
        "same_field_instance": b["field_instance"], "snapshot_sha256": digest(snapshot),
        "result": "SUPPLIED_CONTRACT_CONSISTENT_ONLY", "deployed": False,
        "point_verified": False, "input_restored": False
    }

@dataclass
class Exchange:
    """Pure policy reference. Persist ledger/outbox BEFORE real enqueue in production.
    Context arguments come from SERVER state, never from invented Client wire fields.
    """
    connection_id: str
    client_epoch: str
    field_instance: str
    snapshot_generation: int
    state: str = "PREPARED"
    point_verified: bool = False
    input_restored: bool = False

    def context(self) -> tuple[str, str, str, int]:
        return (self.connection_id, self.client_epoch,
                self.field_instance, self.snapshot_generation)

    def dispatch(self, used: set[tuple[str, int, int]]) -> bytes:
        require(self.state == "PREPARED", "dispatch state")
        token = (self.client_epoch, *SCENE)
        require(token not in used, "scene already consumed in this Client epoch")
        used.add(token)  # model: outcome uncertainty never grants retry permission
        self.state = "SENT"
        return START

    def accept_report(self, payload: bytes, context: tuple[str, str, str, int]) -> bytes | None:
        if self.state != "SENT" or payload != END_REPORT:
            return None
        if context != self.context():
            self.state = "UNCERTAIN"
            return None
        self.state = "END_REPORTED"
        return RELEASE  # caller must enqueue; this is NOT proof it was sent/handled

    def mark_release_enqueued(self) -> None:
        require(self.state == "END_REPORTED", "release state")
        self.state = "RELEASE_ENQUEUED_UNVERIFIED"

    def fail(self) -> None:
        self.state = "UNCERTAIN"  # no retry, unlock, reward, or success implication


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("binding", type=Path, help="RunBinding referencing an immutable release")
    parser.add_argument("snapshot", type=Path, help="prior 0027 APPLICATION bytes, not TCP frame")
    args = parser.parse_args()
    try:
        plan = validate_binding(json.loads(args.binding.read_text(encoding="utf-8")),
                                args.snapshot.read_bytes())
        print(json.dumps(plan, ensure_ascii=False, indent=2))
        return 0
    except (ContractError, OSError, ValueError, TypeError) as exc:
        print(json.dumps({"result": "REJECTED", "error": str(exc)}, ensure_ascii=False))
        return 1

if __name__ == "__main__":
    raise SystemExit(main())
