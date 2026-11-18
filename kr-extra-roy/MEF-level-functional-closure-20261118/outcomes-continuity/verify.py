#!/usr/bin/env python3
"""Read-only verification of level outcome analysis; never runs the game or Server.

The immutable Git baseline is the input. Current worktree/HEAD is not evidence.
Original BIN is read as data for bounded PE mappings, calls, RTTI and bytes.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import struct
import subprocess
import sys
from pathlib import Path

sys.dont_write_bytecode = True

HERE = Path(__file__).resolve().parent
BASELINE = "09799b117f01e577be56dee3e909e1cde25b855f"


def sha(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def git_bytes(repo: Path, path: str) -> bytes:
    return subprocess.check_output(["git", "show", f"{BASELINE}:{path}"], cwd=repo)


def git_blob(repo: Path, path: str) -> str:
    return subprocess.check_output(
        ["git", "rev-parse", f"{BASELINE}:{path}"], cwd=repo, text=True
    ).strip()


class PE:
    def __init__(self, data: bytes):
        self.data = data
        pe = struct.unpack_from("<I", data, 0x3C)[0]
        assert data[pe:pe + 4] == b"PE\0\0"
        assert struct.unpack_from("<H", data, pe + 4)[0] == 0x14C
        opt = pe + 24
        assert struct.unpack_from("<H", data, opt)[0] == 0x10B
        self.base = struct.unpack_from("<I", data, opt + 28)[0]
        self.sections = []
        start = opt + struct.unpack_from("<H", data, pe + 20)[0]
        for i in range(struct.unpack_from("<H", data, pe + 6)[0]):
            p = start + i * 40
            name = data[p:p + 8].rstrip(b"\0").decode("ascii")
            vs, va, size, raw = struct.unpack_from("<IIII", data, p + 8)
            self.sections.append((name, va, size, raw))

    def offset(self, va: int, count: int) -> int:
        rva = va - self.base
        for _, section_rva, raw_size, raw in self.sections:
            if section_rva <= rva and rva + count <= section_rva + raw_size:
                return raw + rva - section_rva
        raise ValueError(f"VA is not wholly file-backed: {va:#x}+{count:#x}")

    def read(self, va: int, count: int) -> bytes:
        p = self.offset(va, count)
        return self.data[p:p + count]

    def u32(self, va: int) -> int:
        return struct.unpack("<I", self.read(va, 4))[0]

    def rel32(self, va: int) -> int:
        b = self.read(va, 5)
        assert b[0] in (0xE8, 0xE9), f"not a rel32 call/jump at {va:#x}"
        return va + 5 + struct.unpack("<i", b[1:])[0]


def projection(document: dict, source_id: str) -> dict:
    """Project existing authored normal routes, without evaluating a runtime engine."""
    result = {"source_id": source_id, "definitions": []}
    for definition in document["definitions"]:
        nodes = {}
        for node in definition["nodes"]:
            spawns = [("initial", e) for e in node.get("encounters", [])]
            for kind in ("reinforcements", "timedReinforcements"):
                for wave in node.get(kind, []):
                    spawns.extend((wave["id"], e) for e in wave.get("encounters", []))
            drops = node.get("groundDrops", [])
            if "groundDrop" in node:
                drops = [node["groundDrop"]]
            loot = []
            for drop in drops:
                matching = [
                    (wave, e) for wave, e in spawns
                    if e["model"] == drop["monster"]
                    and e.get("pre", 1) == drop.get("pre", 1)
                    and (not drop.get("initialOnly", False) or wave == "initial")
                    and ("waveId" not in drop or wave == drop["waveId"])
                ]
                loot.append({
                    "product": drop["product"], "quantity_each": drop["quantity"],
                    "matching_spawns": len(matching),
                    "chance_basis_points": drop.get("chanceBasisPoints", 10000),
                    "wave_id": drop.get("waveId"),
                    "initial_only": drop.get("initialOnly", False),
                    "guaranteed_units": len(matching) * drop["quantity"]
                    if drop.get("chanceBasisPoints", 10000) in (None, 10000) else None,
                })
            edges = [
                {"action": r["action"], "target": r.get("targetNode")}
                for r in node.get("rules", [])
                if r["event"] == "InteractZ" and r["action"] in ("NextNode", "Result")
            ]
            edges.extend(
                {"action": r["action"], "target": r.get("targetNode")}
                for r in node.get("alternativeExits", [])
            )
            boss = node.get("requiredBoss")
            matching_boss = None
            if boss:
                matching_boss = sum(
                    e["model"] == boss["model"]
                    and e.get("pre", 1) == boss.get("pre", 1)
                    and ("waveId" not in boss or wave == boss["waveId"])
                    for wave, e in spawns
                )
                assert matching_boss == 1, (source_id, node["node"], matching_boss)
            nodes[node["node"]] = {
                "node": node["node"], "map": node["map"], "spawn_count": len(spawns),
                "defeat_experience": sum(e.get("defeatExperience", 0) for _, e in spawns),
                "clear_experience": node.get("clearExperience", 0),
                "portal_key": node["portal"]["key"],
                "portal_pre_register_closed": node["portal"].get("preRegisterClosed"),
                "required_boss": boss, "required_boss_matches": matching_boss,
                "loot": loot, "edges": edges,
            }
        routes = []

        def visit(key: int, prefix: list[int]) -> None:
            assert key not in prefix, (source_id, "cycle", prefix, key)
            path = prefix + [key]
            for edge in nodes[key]["edges"]:
                if edge["action"] == "NextNode":
                    assert edge["target"] in nodes
                    visit(edge["target"], path)
                else:
                    assert edge["action"] == "Result"
                    defeat = sum(nodes[k]["defeat_experience"] for k in path)
                    stage = sum(nodes[k]["clear_experience"] for k in path)
                    stage += definition.get("completionExperience", 0)
                    guaranteed = {}
                    for k in path:
                        for row in nodes[k]["loot"]:
                            if row["guaranteed_units"] is not None:
                                name = str(row["product"])
                                guaranteed[name] = guaranteed.get(name, 0) + row["guaranteed_units"]
                    routes.append({
                        "nodes": path, "maps": [nodes[k]["map"] for k in path],
                        "defeat_experience": defeat,
                        "clear_and_completion_experience": stage,
                        "scenario_experience_sum": defeat + stage,
                        "guaranteed_generated_units": guaranteed,
                    })

        visit(definition["entryNode"], [])
        assert routes, source_id
        result["definitions"].append({
            "id": definition["id"], "entry_node": definition["entryNode"],
            "preserve_owner_across_nodes": definition.get("preserveOwnerAcrossNodes", False),
            "completion_experience": definition.get("completionExperience", 0),
            "nodes": list(nodes.values()), "normal_full_clear_routes": routes,
        })
    return result


def verify(repo: Path, original: Path) -> dict:
    manifest = json.loads((HERE / "source-manifest.json").read_text())
    assert manifest["baseline_commit"] == BASELINE
    sources = {}
    for s in manifest["git_sources"]:
        assert s["commit"] == BASELINE
        data = git_bytes(repo, s["path"])
        assert len(data) == s["length"], s["id"]
        assert sha(data) == s["sha256"], s["id"]
        assert git_blob(repo, s["path"]) == s["git_blob"], s["id"]
        assert s["id"] not in sources
        sources[s["id"]] = data

    native = json.loads((HERE / "native-evidence.json").read_text())
    binary = original.read_bytes()
    identity = manifest["original_bin"]
    assert len(binary) == identity["length"] and sha(binary) == identity["sha256"]
    pe = PE(binary)
    assert pe.base == 0x400000
    for w in native["windows"]:
        va = int(w["va"], 16)
        b = pe.read(va, w["length"])
        assert pe.offset(va, len(b)) == w["raw_offset"], w["id"]
        assert sha(b) == w["sha256"] and b.hex() == w["hex"], w["id"]
    for a in native["assertions"]:
        va = int(a["va"], 16)
        if a["kind"] == "rel32":
            assert pe.rel32(va) == int(a["target"], 16), a["id"]
        elif a["kind"] == "u32":
            assert pe.u32(va) == int(a["value"], 16), a["id"]
        elif a["kind"] == "bytes":
            expected = bytes.fromhex(a["hex"])
            assert pe.read(va, len(expected)) == expected, a["id"]
        elif a["kind"] == "cstring":
            expected = a["value"].encode("ascii") + b"\0"
            assert pe.read(va, len(expected)) == expected, a["id"]
        else:
            raise ValueError(a["kind"])

    saved = json.loads((HERE / "outcome-projections.json").read_text())
    calculated = [projection(json.loads(sources[s]), s) for s in saved["scenario_source_ids"]]
    assert calculated == saved["scenario_projections"]
    for p in calculated:
        if p["source_id"] in ("C03", "C04"):
            route = p["definitions"][0]["normal_full_clear_routes"][0]
            assert route["defeat_experience"] == 68
            assert route["clear_and_completion_experience"] == 30
        if p["source_id"] in ("C05", "C06", "C07", "C08"):
            for route in p["definitions"][0]["normal_full_clear_routes"]:
                assert (route["defeat_experience"], route["clear_and_completion_experience"]) == (56, 20)
    story = json.loads(sources["C12"])
    quest = next(q for q in story["quests"] if q["quest"] == 119)
    assert saved["q119_story_projection"] == {
        "quest": 119, "npc": quest["npc"], "field": quest["scenario"]["field"],
        "case": quest["scenario"]["case"], "intro_scenes": quest["introScenes"],
        "return_scenes": quest["returnScenes"], "return_town": quest["returnTown"],
        "nodes": [{"ordinal": i + 1, "source_node": n["sourceNode"], "map": n["map"],
                   "enter_scenes": n["enterScenes"], "clear_scenes": n["clearScenes"]}
                  for i, n in enumerate(quest["scenario"]["nodes"])],
    }
    wallet = json.loads(sources["C13"])
    assert saved["q119_wallet_projection"] == wallet
    facts = json.loads(sources["S23"])["original_table_facts"]["quests"]
    q119_facts = next(q for q in facts if q["id"] == 119)
    rewards = {r["type"]: r["value"] for r in q119_facts["rewards_etc"]}
    assert rewards == {2: 5850, 3: 40, 4: 900}
    assert next(x for x in wallet["rewards"] if x["quest"] == 119)["leeLoo"] == rewards[4]
    assert next(q for q in facts if q["id"] == 120)["attributes"]["level"] == "8"
    assert saved["q119_reward_arithmetic"] == {
        "fixed_quest_experience": 5850, "defeat_experience": 68,
        "clear_experience": 10, "completion_experience": 20,
        "final_transaction_experience": 5880, "first_complete_total_experience": 5948,
        "conditional_wallet_lee_loo": 900,
        "fixed_reward_source": "S12", "effective_growth_source": "S04",
        "wallet_source": "C13", "wallet_requires_matching_enabled_policy": True,
    }

    contracts = json.loads((HERE / "lifecycle-contracts.json").read_text())
    assert contracts["analysis_only"] and not contracts["runtime_observed_this_round"]
    assert contracts["mef_is_server_development"]
    ids = {x["id"] for x in contracts["transitions"]}
    assert len(ids) == len(contracts["transitions"])
    for t in contracts["transitions"]:
        assert set(t["sources"]) <= set(sources), t["id"]
        assert set(t.get("after", [])) <= ids, t["id"]
    assert contracts["q119_clear_handoff"]["ordered_transition_ids"] == [
        "L05", "L06", "L07", "L08", "L09", "L10", "L11"
    ]
    assert contracts["q119_clear_handoff"]["pre_rebuild_setter_survives"] is False
    assert contracts["q119_clear_handoff"]["default_after_rebuild_points_use_committed_flags"] is True
    assert contracts["q119_clear_handoff"]["new_finite_after_rebuild_adapter_is_existing_implementation"] is False
    for p in contracts["result_profiles"]:
        assert p["result_direction"] == "S2C"
        assert p["return_direction"] == "C2S"
        assert p["client_result_is_reward_commit"] is False
    assert {(p["result_type"], p["return_opcode"]) for p in contracts["result_profiles"]} == {
        (0, "0033"), (2, "0019"), (3, "0019")
    }
    assert contracts["item_use_direction_distinction"] == {
        "S2C_0021": "ground_drop_snapshot_rows", "C2S_0021": "bag_direct_use",
        "S2C_0022": "result_mode", "C2S_0022": "quickslot_use"
    }
    assert contracts["persistence_policy"]["mid_battle_reconnect"] == "restart_unfinished_instance"
    assert not contracts["persistence_policy"]["lua_vm_is_persistent_checkpoint"]
    assert all(not row["new_runtime_pass_claim"] for row in contracts["player_progress"])
    return {
        "schema": "MEF_LEVEL_OUTCOMES_VERIFICATION_V1", "result": "PASS",
        "baseline_commit": BASELINE, "git_sources_verified": len(sources),
        "original_bin_sha256": sha(binary), "native_windows_verified": len(native["windows"]),
        "native_assertions_verified": len(native["assertions"]),
        "scenario_files_projected": len(calculated),
        "definitions_projected": sum(len(p["definitions"]) for p in calculated),
        "normal_routes_projected": sum(len(d["normal_full_clear_routes"]) for p in calculated for d in p["definitions"]),
        "transition_contracts_checked": len(contracts["transitions"]),
        "result_profiles_checked": len(contracts["result_profiles"]),
        "runtime_observed_this_round": False, "game_or_server_or_lua_executed": False,
        "original_files_modified": False,
        "coverage": "fixed-source identity; bounded native data/calls/RTTI; authored normal-route projection; outcome contract invariants",
        "limits": ["No live Client, Server, packet capture or database transaction was run.",
                   "Normal-route configured totals are not proof of a runtime reward receipt.",
                   "Existing implementation and older test states are adopted from pinned project records.",
                   "No official MEF format, scene ACK or unspecified cancellation path is inferred."],
    }


def main() -> None:
    p = argparse.ArgumentParser()
    p.add_argument("--repo", type=Path, default=HERE.parents[2])
    p.add_argument("--original-bin", type=Path, required=True)
    p.add_argument("--output", type=Path)
    a = p.parse_args()
    receipt = verify(a.repo, a.original_bin)
    text = json.dumps(receipt, ensure_ascii=False, indent=2) + "\n"
    if a.output:
        a.output.write_text(text, encoding="utf-8")
    print(text, end="")


if __name__ == "__main__":
    main()
