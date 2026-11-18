#!/usr/bin/env python3
"""Read-only verification of P0-3/4 source pins, native evidence and authoring data.

This never loads the PE, Lua or Server code. It uses host objdump only as a decoder.
No artifact is rewritten unless the caller explicitly supplies --receipt.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import math
from pathlib import Path
import re
import struct
import subprocess
import sys
import xml.etree.ElementTree as ET

if sys.flags.optimize:
    raise RuntimeError("Run without -O; assertions are evidence checks.")


def sha(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def blob(data: bytes) -> str:
    return hashlib.sha1(b"blob " + str(len(data)).encode() + b"\0" + data).hexdigest()


def git_bytes(repo: Path, commit: str, path: str) -> bytes:
    return subprocess.check_output(["git", "-C", str(repo), "show", f"{commit}:{path}"])


class PE:
    def __init__(self, data: bytes):
        self.data = data
        pe = struct.unpack_from("<I", data, 0x3c)[0]
        assert data[pe:pe + 4] == b"PE\0\0"
        self.base = struct.unpack_from("<I", data, pe + 52)[0]
        count = struct.unpack_from("<H", data, pe + 6)[0]
        start = pe + 24 + struct.unpack_from("<H", data, pe + 20)[0]
        self.sections = []
        for index in range(count):
            p = start + index * 40
            virtual_size, rva, size, raw = struct.unpack_from("<IIII", data, p + 8)
            self.sections.append((rva, raw, size, virtual_size))

    def offset(self, va: int, size: int) -> int:
        for rva, raw, backed, _ in self.sections:
            rel = va - self.base - rva
            if 0 <= rel and rel + size <= backed:
                return raw + rel
        raise AssertionError(f"Unbacked PE interval: {va:#x}+{size:#x}")

    def read(self, va: int, size: int) -> bytes:
        raw = self.offset(va, size)
        return self.data[raw:raw + size]


def disassemble(binary: Path, start: int, end: int) -> list[dict]:
    # Decode beyond the requested end, then reject a boundary that cuts an instruction.
    output = subprocess.check_output([
        "objdump", "-d", "-Mintel", "--insn-width=16",
        f"--start-address={start}", f"--stop-address={end + 16}", str(binary)
    ], text=True)
    result = []
    next_va = start
    pattern = re.compile(r"\s*([0-9a-f]+):\s*((?:[0-9a-f]{2}\s+)+)\s*(.*)")
    for line in output.splitlines():
        m = pattern.fullmatch(line)
        if not m:
            continue
        va = int(m[1], 16)
        if va >= end:
            break
        raw = bytes.fromhex(m[2])
        assert va == next_va, (hex(next_va), line)
        assert va + len(raw) <= end, f"Instruction crosses endpoint: {line}"
        assert "(bad)" not in m[3] and ".byte" not in m[3], line
        result.append({"va": hex(va), "hex": raw.hex(), "asm": m[3]})
        next_va += len(raw)
    assert next_va == end, (hex(next_va), hex(end))
    return result


def behavior_audit(schema: dict, documents: dict[str, dict]) -> dict:
    # Schema validation plus the relations enforced by the inspected typed loader.
    # This is not execution of LocalTutorialCombat and is not a live gameplay test.
    import jsonschema
    jsonschema.Draft202012Validator.check_schema(schema)
    validator = jsonschema.Draft202012Validator(schema)
    rows, errors = [], []
    for path, document in sorted(documents.items()):
        for error in sorted(validator.iter_errors(document), key=lambda e: str(e.path)):
            errors.append({"path": path, "field": list(error.path), "error": error.message})
        ids = [p["id"] for p in document["profiles"]]
        if len(ids) != len(set(ids)):
            errors.append({"path": path, "error": "duplicate profile ID in one document"})
        for p in document["profiles"]:
            checks = {
                "follow_attack_hit_order": p["followDistance"] < p["attackRange"] <= p["hitRange"],
                "windup_recovery_cooldown_order": p["windupSeconds"] <= p["recoverySeconds"] <= p["attackCooldownSeconds"],
                "aggro_leash_order": p.get("aggroRange") is None or p.get("leashRadius") is None or p["aggroRange"] <= p["leashRadius"],
                "finite_values": all(math.isfinite(v) for v in p.values() if isinstance(v, (float, int))),
            }
            attacks = p.get("attacks") or []
            attack_ids = [a["id"] for a in attacks]
            checks["unique_attack_ids"] = len(attack_ids) == len(set(attack_ids))
            details = []
            for a in attacks:
                checks["attack:" + a["id"]] = (
                    a["attackRange"] <= a["hitRange"]
                    and a["windupSeconds"] <= a["recoverySeconds"] <= a["cooldownSeconds"]
                    and a.get("minimumHealthFraction", 0) <= a.get("maximumHealthFraction", 1)
                    and (not a.get("projectile") or a["attackRange"] <= a["projectile"]["maximumDistance"])
                )
                details.append({
                    "id": a["id"], "damage_form": a.get("damageForm", "physical"),
                    "health_band": [a.get("minimumHealthFraction", 0), a.get("maximumHealthFraction", 1)],
                    "projectile": bool(a.get("projectile")),
                    "attack_range": a["attackRange"], "hit_range": a["hitRange"],
                })
            for check, passed in checks.items():
                if not passed:
                    errors.append({"path": path, "profile": p["id"], "error": check})
            rows.append({
                "path": path, "id": p["id"], "maximum_health": p["maximumHealth"],
                "movement_speed": p["movementSpeed"], "native_movement_speed": p["nativeMovementSpeed"],
                "native_signed16_speed_safe": 1 <= p["nativeMovementSpeed"] <= 32767,
                "pursues": p.get("canPursue", True), "aggro_range": p.get("aggroRange"),
                "leash_radius": p.get("leashRadius"), "attack_choices": details,
                "legacy_melee_fallback": not attacks, "typed_relations": checks,
            })
    return {
        "schema": "MEF_P0_ACTORS_BEHAVIOR_AUDIT_V1", "scope": "immutable analysis-repository authoring corpus; no Server execution",
        "document_count": len(documents), "profile_occurrences": len(rows),
        "unique_profile_names": len({p["id"] for p in rows}),
        "profiles_with_aggro_leash": sum(p["aggro_range"] is not None and p["leash_radius"] is not None for p in rows),
        "stationary_profiles": sum(not p["pursues"] for p in rows),
        "profiles_with_explicit_attacks": sum(bool(p["attack_choices"]) for p in rows),
        "explicit_attack_count": sum(len(p["attack_choices"]) for p in rows),
        "projectile_attack_count": sum(a["projectile"] for p in rows for a in p["attack_choices"]),
        "health_gated_attack_count": sum(a["health_band"] != [0, 1] for p in rows for a in p["attack_choices"]),
        "schema_errors": errors, "status": "PASS" if not errors else "FAIL",
        "all_existing_native_speeds_signed16_safe": all(p["native_signed16_speed_safe"] for p in rows),
        "schema_native_speed_range": [schema["properties"]["profiles"]["items"]["properties"]["nativeMovementSpeed"]["minimum"], schema["properties"]["profiles"]["items"]["properties"]["nativeMovementSpeed"]["maximum"]],
        "recommended_native_speed_range": [1, 32767],
        "schema_gap": "Schema/typed ushort admits 32768..65535, but CMonster property6 uses MOVSX16; existing rows are safe.",
        "rows": rows,
    }


def bullet_resource_audit(reader_source: bytes, table: Path) -> dict:
    # Reuse the exact pinned, read-only host STPD parser. This parses archive/XML data;
    # it is not execution of target game code. No decoded resource is written out.
    namespace = {"__name__": "mef_p0_pinned_stp_reader"}
    exec(compile(reader_source, "pinned_stp_reader.py", "exec"), namespace)
    archive = namespace["STP"](table)
    data, member = archive.get("Table/Blt2.blt")
    root = ET.fromstring(data.decode("euc-kr"))
    assert root.tag == "BulletList"
    rows = list(root)
    ids = [int(row.attrib["Type"]) for row in rows]
    assert len(ids) == len(set(ids))
    selected = []
    for row in rows:
        if int(row.attrib["Type"]) in (1, 22, 43, 48, 55):
            selected.append({
                "type": int(row.attrib["Type"]),
                "declared_speed": float(row.attrib["Speed"]),
                "file": dict(row.find("File").attrib),
                "time": dict(row.find("Time").attrib),
                "radius": dict(row.find("Radius").attrib),
                "curve": dict(row.find("Curve").attrib) if row.find("Curve") is not None else None,
            })
    return {
        "schema": "MEF_P0_BULLET_RESOURCE_AUDIT_V1", "member": member,
        "table_index_members": len(archive.files), "bullet_rows": len(rows),
        "unique_type_ids": len(set(ids)), "type_min": min(ids), "type_max": max(ids),
        "types_contiguous_1_to_228": sorted(ids) == list(range(1, 229)),
        "declared_main_effect_rows": sum(bool(r.find("File").get("EffectFile")) for r in rows),
        "declared_ground_effect_rows": sum(bool(r.find("File").get("GroundTargetingEffect")) for r in rows),
        "declared_impact_effect_rows": sum(bool(r.find("File").get("ImpactEffect")) for r in rows),
        "curve_rows": sum(r.find("Curve") is not None for r in rows),
        "selected_bounded_rows": selected,
        "actor_model_key_rule": "0x02000000 | uint16(Bullet.Type), native 4F5486..4F5498",
        "limits": "Declarations/key/consumer proved. Effect payload resolution and rendered appearance untested. Speed/Lifetime/Radius declarations do not prove CBullet applies them as collision/damage rules.",
    }


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--repo", type=Path, default=Path(__file__).resolve().parents[3])
    parser.add_argument("--sources", type=Path, default=Path("/workspace/scratch/3e083e35831f/project_sources"))
    parser.add_argument("--server-sources", type=Path, default=Path("/workspace/scratch/3e083e35831f/analysis/mef_p0_level_server_sources_20261118"))
    parser.add_argument("--receipt", type=Path)
    args = parser.parse_args()
    package = Path(__file__).resolve().parent
    manifest = json.loads((package / "source-manifest.json").read_text())
    native = json.loads((package / "native-evidence.json").read_text())
    contracts = json.loads((package / "capability-contracts.json").read_text())
    artifact_manifest = json.loads((package / "artifact-manifest.json").read_text())
    git_data = {}
    for pin in manifest["git_sources"]:
        data = git_bytes(args.repo, pin["commit"], pin["path"])
        assert len(data) == pin["bytes"] and sha(data) == pin["sha256"] and blob(data) == pin["git_blob"], pin["path"]
        git_data[pin["path"]] = data
    for pin in manifest["server_sources"]["files"]:
        data = (args.server_sources / pin["path"]).read_bytes()
        assert len(data) == pin["bytes"] and sha(data) == pin["sha256"] and blob(data) == pin["git_blob"], pin["path"]
        for identifier in pin.get("identifiers", []):
            assert identifier.encode() in data, (pin["path"], identifier)
    original = manifest["original"]
    binary = args.sources / original["filename"]
    binary_bytes = binary.read_bytes()
    assert len(binary_bytes) == original["bytes"] and sha(binary_bytes) == original["sha256"]
    for original_data in manifest.get("data_originals", []):
        data = (args.sources / original_data["filename"]).read_bytes()
        assert len(data) == original_data["bytes"] and sha(data) == original_data["sha256"]
    pe = PE(binary_bytes)
    instruction_count = 0
    for window in native["windows"]:
        start, end = int(window["start"], 16), int(window["end"], 16)
        data = pe.read(start, end - start)
        assert len(data) == window["bytes"] and sha(data) == window["sha256"] and pe.offset(start, len(data)) == int(window["raw"], 16), window["id"]
        if window["kind"] == "code":
            instructions = disassemble(binary, start, end)
            assert instructions == window["instructions"], window["id"]
            assert b"".join(bytes.fromhex(i["hex"]) for i in instructions) == data, window["id"]
            instruction_count += len(instructions)
        else:
            assert data.hex() == window["hex"], window["id"]
    instruction_map = {i["va"]: i for w in native["windows"] if w["kind"] == "code" for i in w["instructions"]}
    for assertion in native["assertions"]:
        kind = assertion["kind"]
        if kind == "instruction":
            assert re.search(assertion["pattern"], instruction_map[assertion["va"]]["asm"]), assertion
        elif kind == "u32":
            assert struct.unpack("<I", pe.read(int(assertion["va"], 16), 4))[0] == int(assertion["value"], 16), assertion
        elif kind == "bytes":
            value = bytes.fromhex(assertion["hex"])
            assert pe.read(int(assertion["va"], 16), len(value)) == value, assertion
        elif kind == "double":
            assert struct.unpack("<d", pe.read(int(assertion["va"], 16), 8))[0] == assertion["value"], assertion
        else:
            raise AssertionError(f"Unknown assertion {kind}")
    schema_path = "design/scenario-content/local-monster-behavior.schema.json"
    documents = {p: json.loads(data) for p, data in git_data.items() if p.endswith(".monster-behavior.json")}
    audit = behavior_audit(json.loads(git_data[schema_path]), documents)
    assert audit == json.loads((package / "behavior-audit.json").read_text())
    assert audit["status"] == "PASS"
    bullet_audit = bullet_resource_audit(
        git_data["kr-extra-roy/MEF-world-identity-scene-interaction-20261117/stp_reader.py"],
        args.sources / "07-Table.stp")
    assert bullet_audit == json.loads((package / "bullet-resource-audit.json").read_text())
    evidence_ids = {w["id"] for w in native["windows"]}
    assert len({c["id"] for c in contracts["capabilities"]}) == len(contracts["capabilities"])
    for capability in contracts["capabilities"]:
        assert capability["evidence"] and set(capability["evidence"]) <= evidence_ids, capability["id"]
        assert capability["status"] in {"NATIVE_STATIC_CLOSED", "SERVER_SOURCE_PRESENT", "ADAPTER_REQUIRED", "CLIENT_JOIN_UNPROVEN"}, capability["id"]
    for pin in artifact_manifest["files"]:
        data = (package / pin["path"]).read_bytes()
        assert len(data) == pin["bytes"] and sha(data) == pin["sha256"], pin["path"]
    result = {
        "schema": "MEF_P0_ACTORS_VERIFICATION_V1", "status": "PASS",
        "analysis_baseline": manifest["analysis_baseline"],
        "server_commit": manifest["server_sources"]["commit"],
        "binary_sha256": original["sha256"],
        "git_source_pins": len(manifest["git_sources"]),
        "external_server_files_verified_from_actual_bytes": len(manifest["server_sources"]["files"]),
        "native_windows": len(native["windows"]), "native_window_bytes": sum(w["bytes"] for w in native["windows"]),
        "native_instructions": instruction_count, "native_assertions": len(native["assertions"]),
        "behavior_documents": audit["document_count"], "profile_occurrences": audit["profile_occurrences"],
        "bullet_resource_rows": bullet_audit["bullet_rows"],
        "capabilities": len(contracts["capabilities"]), "artifacts": len(artifact_manifest["files"]),
        "client_executed": False, "lua_executed": False, "server_executed": False,
        "originals_modified": False, "production_ready_claim": False,
        "limits": "Static byte/source/schema consistency; not an integration, latency, gameplay or visual-asset acceptance test.",
    }
    rendered = json.dumps(result, ensure_ascii=False, indent=2) + "\n"
    if args.receipt:
        args.receipt.write_text(rendered)
    print(rendered, end="")
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (AssertionError, OSError, subprocess.CalledProcessError, ValueError) as exc:
        print(json.dumps({"status": "FAIL", "error": str(exc)}, ensure_ascii=False), file=sys.stderr)
        raise SystemExit(1)
