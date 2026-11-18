#!/usr/bin/env python3
"""Read-only bounded MEF capability evidence checks.

Reads fixed Git blobs, PE bytes and six selected STP members. Does not execute
Client, Server, Lua, a wire sender, or a database. The only optional write is
the explicitly requested local evidence receipt. Standard library only.
"""
import argparse
import hashlib
import json
import struct
import subprocess
import sys
import types
import xml.etree.ElementTree as ET
from pathlib import Path

sys.dont_write_bytecode = True
BASE = "60c1c1a5dc7a73902d9dbb50361d5148e8b30058"
BIN_SHA = "9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
TABLE_SHA = "09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442"
OWN = Path(__file__).resolve().parent
MEMBERS = (
    "Table/QuestInfo.xml", "Table/ShopInfo.xml", "Table/Product.xml",
    "Table/npctable.xml", "Table/TutCheckPointList.xml", "Table/_ActorList.xml",
)


def sha(data):
    return hashlib.sha256(data).hexdigest()


def require(condition, message):
    if not condition:
        raise ValueError(message)


def git_blob(repo, path):
    return subprocess.check_output(["git", "-C", str(repo), "show", BASE + ":" + path])


def jload(path):
    return json.loads(Path(path).read_text(encoding="utf-8"))


class PE:
    def __init__(self, data):
        self.data = data
        off = struct.unpack_from("<I", data, 0x3C)[0]
        require(data[off:off + 4] == b"PE\0\0", "PE signature")
        require(struct.unpack_from("<H", data, off + 4)[0] == 0x14C, "i386 target")
        n = struct.unpack_from("<H", data, off + 6)[0]
        opt = off + 24
        require(struct.unpack_from("<H", data, opt)[0] == 0x10B, "PE32 target")
        self.base = struct.unpack_from("<I", data, opt + 28)[0]
        section = opt + struct.unpack_from("<H", data, off + 20)[0]
        self.sections = []
        for i in range(n):
            at = section + i * 40
            _, rva, size, raw = struct.unpack_from("<4I", data, at + 8)
            self.sections.append((rva, size, raw))

    def offset(self, va, size):
        for rva, stored, raw in self.sections:
            delta = va - self.base - rva
            if 0 <= delta and delta + size <= stored:
                return raw + delta
        raise ValueError("Span not backed by one PE section: " + hex(va))

    def read(self, va, size):
        raw = self.offset(va, size)
        return self.data[raw:raw + size]


def read_stp_class(repo, manifest):
    pin = next(x for x in manifest["git_sources"] if x["id"] == "S25")
    source = git_blob(repo, pin["path"])
    require(sha(source) == pin["sha256"], "fixed STP reader hash")
    module = types.ModuleType("fixed_stp_reader_npc_progression")
    module.__file__ = str(repo / pin["path"])
    # This imports a fixed, reviewed, read-only Python parser, never game Lua.
    exec(compile(source, module.__file__, "exec"), module.__dict__)
    return module.STP


def selected_resource_facts(repo, table, manifest):
    archive = read_stp_class(repo, manifest)(table)
    require(archive.sha == TABLE_SHA, "Table carrier SHA")
    roots, metadata = {}, []
    for member in MEMBERS:
        payload, meta = archive.get(member)
        # Never store original member bodies or prefix bytes.
        meta = {k: v for k, v in meta.items() if k not in ("carrier", "prefix")}
        metadata.append(meta)
        roots[member] = ET.fromstring(payload)
    qroot = roots["Table/QuestInfo.xml"]
    quests = []
    for key in (119, 120, 2842):
        row = next(x for x in qroot if x.tag == "Quest" and x.get("id") == str(key))
        quests.append({
            "id": key,
            "attributes": {k: row.attrib[k] for k in ("type", "town", "field", "level", "giver", "finisher", "subtype") if k in row.attrib},
            "demands": [int(x.attrib["id"]) for x in row.findall("./Demands/Demand")],
            "rewards_etc": [{"type": int(x.attrib["type"]), "value": int(x.attrib["value"])} for x in row.findall("./RewardsEtc/Reward")],
            "content_ids": [int(x.attrib["id"]) for x in row.findall("./Contents/Content")],
            "accept_action": [dict(x.attrib) for x in row.findall("./AcceptAction")],
            "complete_action": [dict(x.attrib) for x in row.findall("./CompleteAction")],
        })
    shop = next(x for x in roots["Table/ShopInfo.xml"] if x.tag == "SHOP" and x.get("NO") == "2")
    product = next(x for x in roots["Table/Product.xml"] if x.tag == "PRODUCT" and x.get("PRODUCT") == "2614")
    npc = next(x for x in roots["Table/npctable.xml"] if x.tag == "NPC" and x.get("ID") == "10030")
    cat6 = next(x for x in roots["Table/_ActorList.xml"] if x.tag == "OBJCATEGORY" and x.get("ID") == "6")
    models = []
    for key in (10030, 10047):
        models.append({"model": key, "category": 6, "rows": [
            {k: x.attrib[k] for k in ("ID", "PRE", "FILE", "SCALE") if k in x.attrib}
            for x in cat6 if x.get("ID") == str(key)]})
    point = next(x for x in roots["Table/TutCheckPointList.xml"] if x.get("id") == "1")
    return {
        "members": metadata,
        "quests": quests,
        "shop2": {
            "shop": {k: shop.attrib[k] for k in ("NO", "TOWN", "TYPE", "NPC")},
            "product_declarations": len(shop.findall("PRODUCT")),
            "includes_product2614": any(x.get("NO") == "2614" for x in shop.findall("PRODUCT")),
            "product": {k: product.attrib[k] for k in ("PRODUCT", "ITEM", "LEELOO", "SELL_LEELOO", "LEVELUP_DISABLED")},
            "npc": {k: npc.attrib[k] for k in ("ID", "TYPE")},
            "talkset_count": len(list(npc.iter("TALKSET"))),
            "selected_actor_catalog": models,
        },
        "tutorial_point1": {k: point.attrib[k] for k in ("id", "x", "y", "range", "active", "effect")},
    }


def verify(args):
    repo = Path(args.repo).resolve()
    manifest = jload(OWN / "source-manifest.json")
    require(manifest["baseline_commit"] == BASE, "source baseline")
    git_checks = []
    for pin in manifest["git_sources"]:
        blob = git_blob(repo, pin["path"])
        object_id = hashlib.sha1(b"blob " + str(len(blob)).encode() + b"\0" + blob).hexdigest()
        require(sha(blob) == pin["sha256"] and len(blob) == pin["length"] and object_id == pin["git_blob"], "Git source " + pin["id"])
        git_checks.append(pin["id"])
    raw = Path(args.bin).read_bytes()
    require(sha(raw) == BIN_SHA, "original BIN SHA")
    pe = PE(raw)
    require(pe.base == 0x400000, "image base")
    evidence = jload(OWN / "native-evidence.json")
    source_lookup = {x["id"]: x for x in manifest["git_sources"]}
    inherited_cache = {}
    for win in evidence["windows"]:
        va, length = int(win["va"], 16), win["length"]
        data = pe.read(va, length)
        require(hex(pe.offset(va, length)) == win["raw"], "PE mapping " + win["id"])
        require(sha(data) == win["sha256"] and data.hex() == win["hex"], "Native span " + win["id"])
        if ":" in win["source"]:
            sid, old_id = win["source"].split(":", 1)
            if sid in ("S18", "S19", "S20", "S23"):
                if sid not in inherited_cache:
                    inherited_cache[sid] = json.loads(git_blob(repo, source_lookup[sid]["path"]))
                source_windows = inherited_cache[sid]["windows"]
                old = next(x for x in source_windows if x.get("id", x.get("start")) == old_id)
                if "hex" in old:
                    require(data.hex() == old["hex"], "inherited original bytes " + win["id"])
                elif isinstance(old.get("bytes"), str):
                    require(data.hex() == old["bytes"], "inherited original bytes " + win["id"])
                elif "sha256" in old:
                    require(sha(data) == old["sha256"], "inherited original hash " + win["id"])
                else:
                    raise ValueError("Inherited evidence has no byte identity: " + win["id"])
    published_ranges = {
        "N-objective-update": "abe0b512ab1f8040080f69b57805bc2d3f103b974e847ceea925802f450f4891",
        "N-objective-existing": "8ae7cbf7d28c28fc41659648a0b4fd06d57b06a74a130716242281dce4cad32c",
        "N-objective-register": "1b9adff1f9edf103f5df738dd73c350f029a3682f13890d1b74be8d7cbd728dc",
        "N-objective-ready": "a22f902f69d9539f33fb26c4e710302ab03aad3a0e4032e0d9e245d879a83381",
        "N-objective-writer": "2e51b1fd03403ad3eff0262885eae8a4d4ec13a682dc4b86923c80582ed2f1fc",
        "N-type3-source-copy": "6ff8c0de5e7d91b85c396965c213fa13586d307b2bb29c1582a93fe46599faca",
        "N-type3-record-insert": "f70d7e540777fd63eab69aee5ac3adbba7b319b88169289be0f9d6ae87d492a3",
    }
    for ident, expected_hash in published_ranges.items():
        span = next(x for x in evidence["windows"] if x["id"] == ident)
        require(span["sha256"] == expected_hash, "published range " + ident)
    # Independently check exact bridge semantics from bytes, not just doc text.
    require(pe.read(0x4C45EC, 14).hex() == "8b5610895030668b4e1466894834", "result payload copy into manager +30/+34")
    require(pe.read(0x6BA4C2, 3).hex() == "8b4b32", "SkillExp result +32 read")
    require(pe.read(0x6351F2, 6).hex() == "8b8984000000", "Quest reward record +84")
    require(struct.unpack("<I", pe.read(0x50555C, 4))[0] == 0x504DEB, "type 3 jump target")
    require(struct.unpack("<3I", pe.read(0xD68958, 12))[:2] == (0x164, 0xC13F8C), "Quest SkillExp label row")
    require(struct.unpack("<3I", pe.read(0xD699F0, 12))[:2] == (0x2C6, 0xC12484), "result SkillExp label row")
    # The ordinary snapshot/register and delta distinction is a fixed contract.
    require(pe.read(0x4A94B6, 5)[0] == 0xE8 and 0x4A94BB + struct.unpack("<i", pe.read(0x4A94B7, 4))[0] == 0x544940, "Lua point setter target")
    actual = selected_resource_facts(repo, args.table, manifest)
    expected = jload(OWN / "data-evidence.json")
    require(actual == expected["original_table_facts"], "selected Table facts and metadata")
    q119 = next(x for x in actual["quests"] if x["id"] == 119)
    require(q119["demands"] == [118] and q119["rewards_etc"] == [
        {"type": 2, "value": 5850}, {"type": 3, "value": 40}, {"type": 4, "value": 900}], "Q119 original data")
    policy = jload(OWN / "authored-policy-example.json")
    split = jload(OWN / "capability-split.json")
    adapters = jload(OWN / "adapter-contracts.json")
    offload = jload(OWN / "offload-plan.json")
    require(policy["native_format_claim"] is False and policy["accepted_by_existing_loader"] is False and policy["executable_lua"] is False, "proposal is not native loader claim")
    require(split["server_executed_mef_is_mef"] is True and len(split["capabilities"]) == 12, "twelve capability splits")
    require(len(adapters["adapters"]) == 8, "eight adapters")
    require(all(x["measurements_available"] is False and x["claimed_saving_percent"] is None for x in offload["situations"]), "no invented benchmark")
    require(all(x["server_mef_only_cpu_offload_claim"] is False for x in split["capabilities"]), "Server interpreter is not Client CPU offload")
    require(all(x["client_lua_db_write_claim"] is False for x in split["capabilities"]), "no Lua DB claim")
    require(adapters["generic_server_result_to_lua"]["status"] == "UNPROVEN_PUBLIC_BRIDGE", "dynamic bridge boundary")
    finite = adapters["finite_dispatch_route"]
    require(finite["status"] == "DESIGN_COMPOSITION_OF_PROVEN_INTERFACES_NOT_DEPLOYED", "finite dispatch remains an undeployed composition")
    require(finite["requires_generic_event_injection_into_resident_lua"] is False and finite["requires_ordinary_background_B"] is False, "finite selection does not require generic resident event bridge")
    require(finite["trigger_transports_arbitrary_event_payload"] is False, "0047 remains a selector, not event payload transport")
    require(policy["q119"]["clear_fact_delivery"]["finite_client_sequence"]["generic_resident_lua_bridge_required"] is False, "Q119 finite alternative matches adapter")
    pins = source_lookup
    route = json.loads(git_blob(repo, pins["S12"]["path"]))["definitions"][0]
    nodes = route["nodes"]
    projected = [{"node": x["node"], "map": x["map"], "portal_key": x["portal"]["key"], "preRegisterClosed": x["portal"].get("preRegisterClosed", False)} for x in nodes]
    require(projected == expected["existing_q119_portal_policy"], "existing route portal facts")
    require([x["preRegisterClosed"] for x in projected] == [False, False, False, True], "do not rewrite original candidate policy")
    require(policy["q119"]["proposed_all_points_pre_registered"] is True, "explicit proposed delta")
    schema = json.loads(git_blob(repo, pins["S13"]["path"]))
    require(schema["additionalProperties"] is False and schema["$defs"]["rule"]["properties"]["event"]["enum"] == ["Entry", "GroupCleared", "InteractZ"], "existing finite event engine")
    require(policy["new_event_engine_required"] is False, "reuse existing event engine")
    artifact_manifest = jload(OWN / "artifact-manifest.json")
    for item in artifact_manifest["artifacts"]:
        content = (OWN / item["path"]).read_bytes()
        require(sha(content) == item["sha256"] and len(content) == item["length"], "artifact " + item["path"])
    return {
        "schema": "MEF_NPC_PROGRESSION_STATIC_RECEIPT_V1",
        "status": "PASS",
        "classification": "BOUNDED_STATIC_EVIDENCE_AND_SELF_AUTHORED_DESIGN_CONSISTENCY",
        "baseline_commit": BASE,
        "bin_sha256": BIN_SHA,
        "table_sha256": TABLE_SHA,
        "git_sources_verified": len(git_checks),
        "native_windows_verified": len(evidence["windows"]),
        "native_bytes_verified_sum_with_overlap": sum(x["length"] for x in evidence["windows"]),
        "selected_table_members_verified": len(MEMBERS),
        "capability_splits_verified": len(split["capabilities"]),
        "adapters_verified": len(adapters["adapters"]),
        "artifacts_verified": len(artifact_manifest["artifacts"]),
        "semantic_checks": ["type3 Quest SkillExp and result projection", "Lua checkpoint common setter", "Q119 actual rewards", "existing portal policy differs from proposed preload", "existing finite event engine reused", "Server MEF is inside scope", "no invented CPU saving", "no Client DB binding", "no invented dynamic result bridge", "GroupCleared-to0047 finite selection is independent of generic resident Lua event injection"],
        "client_executed": False, "server_executed": False, "lua_executed": False,
        "database_modified": False, "wire_sent": False, "git_modified": False,
        "playability_verified_this_round": False, "formal_status_changed": False,
        "limits": ["Existing Server behavior is documented evidence; its external source/deployment was not reexecuted.", "Only named original spans and members are verified; not whole-program or FULL-PASS.", "Authored policy is an integration proposal, not loaded Client content or existing-schema extension."],
    }


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--repo", default=str(OWN.parents[2]))
    parser.add_argument("--bin", required=True)
    parser.add_argument("--table", required=True)
    parser.add_argument("--receipt", type=Path)
    args = parser.parse_args()
    result = verify(args)
    out = json.dumps(result, ensure_ascii=False, indent=2) + "\n"
    if args.receipt:
        require(args.receipt.resolve().parent == OWN, "receipt must stay in this evidence package")
        args.receipt.write_text(out, encoding="utf-8")
    print(out, end="")


if __name__ == "__main__":
    main()
