#!/usr/bin/env python3
"""Recheck bounded, reused native/resource evidence for custom MEF profiles.

This reads originals as data and pinned Git objects. It never starts a Client,
Server, Lua interpreter, archive executable, network request or Git mutation.
Only this analysis helper and an identity-checked, published STPD data reader run.
"""
from __future__ import annotations
import argparse
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys
import xml.etree.ElementTree as ET

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
BASE = "60c1c1a5dc7a73902d9dbb50361d5148e8b30058"
READER = "kr-extra-roy/MEF-world-identity-scene-interaction-20261117/stp_reader.py"


def require(ok, message):
    if not ok:
        raise ValueError(message)


def sha(data):
    return hashlib.sha256(data).hexdigest()


def git(repo, *args):
    env = {**os.environ, "GIT_NO_LAZY_FETCH": "1", "GIT_OPTIONAL_LOCKS": "0", "GIT_TERMINAL_PROMPT": "0"}
    return subprocess.check_output(["git", "-C", str(repo), *args], env=env)


def load_reader(repo, source_bytes):
    require((repo / READER).read_bytes() == source_bytes[READER], "STPD helper working copy differs from pin")
    spec = importlib.util.spec_from_file_location("mef_delivery_stpd_reader", repo / READER)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module.STP


def pe_sections(data):
    pe = struct.unpack_from("<I", data, 60)[0]
    require(data[pe:pe + 4] == b"PE\0\0", "PE signature")
    machine, count = struct.unpack_from("<HH", data, pe + 4)
    opt = pe + 24
    require(machine == 0x14C and struct.unpack_from("<H", data, opt)[0] == 0x10B, "PE32 i386")
    base = struct.unpack_from("<I", data, opt + 28)[0]
    table = opt + struct.unpack_from("<H", data, pe + 20)[0]
    rows = []
    for i in range(count):
        off = table + 40 * i
        virtual_size, rva, raw_size, raw = struct.unpack_from("<4I", data, off + 8)
        rows.append((base + rva, raw, raw_size))
    return rows


def raw_for(sections, va, length):
    matches = [raw + va - start for start, raw, size in sections if start <= va and va + length <= start + size]
    require(len(matches) == 1, "no unique raw-backed PE mapping")
    return matches[0]


def disassemble(path, start, end):
    output = subprocess.check_output([
        "objdump", "-d", "-Mintel", "--insn-width=16",
        f"--start-address={start}", f"--stop-address={end}", str(path)
    ], text=True)
    rows = []
    for line in output.splitlines():
        match = re.match(r"\s*([0-9a-f]+):\s+((?:[0-9a-f]{2} )*[0-9a-f]{2})\s+(.+)$", line)
        if match:
            rows.append({"va": hex(int(match[1], 16)), "hex": match[2].replace(" ", ""), "asm": match[3].strip()})
    cursor = start
    for row in rows:
        require(int(row["va"], 16) == cursor, "disassembly coverage gap")
        require("(bad)" not in row["asm"] and not row["asm"].startswith(".byte"), "invalid or partial instruction")
        cursor += len(bytes.fromhex(row["hex"]))
    require(cursor == end, "partial terminal instruction")
    return rows


def resource_summary(STP, sources):
    archives = {name: STP(sources / name) for name in ("06-Event.stp", "07-Table.stp", "11-Master.stp")}
    members = []

    def read(carrier, path):
        data, meta = archives[carrier].get(path)
        # Hash/identity only; do not export full members, including tiny properties.
        meta.pop("prefix", None)
        members.append(meta)
        return data

    def xml(data):
        match = re.search(br"encoding=['\"]([^'\"]+)", data[:160])
        return ET.fromstring(data.decode(match[1].decode() if match else "utf-8-sig").lstrip("\ufeff \r\n\t"))

    scene_data = read("06-Event.stp", "Event/SceneList.xml")
    rows = list(xml(scene_data).iter("SCENE"))
    selected = []
    for scene in range(1, 6):
        hits = [r for r in rows if r.get("questIdx") == "119" and r.get("sceneIdx") == str(scene)]
        require(len(hits) == 1, "Q119 selector must be unique")
        row = hits[0]
        path = "Event/Sequences/" + row.attrib["funcName"] + ".seq"
        seq = read("06-Event.stp", path)
        require(seq and seq[0] != 0x1B, "selected SEQ must use parser text branch")
        selected.append({"quest": 119, "scene": scene, "attributes": dict(row.attrib), "literal_path": path,
                         "decoded_sha256": sha(seq), "parser_branch": "text", "replaced_or_deployed": False})
    for path in ("Event/qbase.lua", "Event/TutorialBase.lua", "Event/TutorialMain.lua"):
        read("06-Event.stp", path)
    tutorial = xml(read("07-Table.stp", "Table/TutCheckPointList.xml"))
    tutorial_rows = [dict(n.attrib) for n in tutorial if n.attrib]
    # Only the two mode facts needed by this profile, not the small whole table.
    tutorial_modes = [{"id": r.get("id"), "active": r.get("active")} for r in tutorial_rows if r.get("id") in ("1", "4")]
    event_props = [name for name in archives["11-Master.stp"].files if name == "Master0z/Event/AttachedPackage"]
    require(len(event_props) == 1, "exact Event mount property")
    prop = read("11-Master.stp", event_props[0])
    require(prop.rstrip(b"\0") == b"Event", "Event AttachedPackage basename")
    candidate = {"questIdx": 0, "sceneIdx": 32760, "funcName": "compat_point_once_a_v1", "endBehavior": 0}
    collisions = {
        "key": sum(r.get("questIdx") == "0" and r.get("sceneIdx") == "32760" for r in rows),
        "func_name": sum(r.get("funcName") == candidate["funcName"] for r in rows),
        "archive_path": int("Event/Sequences/compat_point_once_a_v1.seq" in archives["06-Event.stp"].files),
        "scope": "supplied_original_only_not_merged_release",
        "candidate_is_native_reservation": False,
        "candidate_is_deployed": False,
    }
    return {"schema": "MEF_SERVER_CONTENT_ROUTE_EVIDENCE_V1", "id": "R01", "scene_rows": len(rows),
            "configured_selectors": selected, "legacy_a1_candidate": candidate, "legacy_candidate_collisions": collisions,
            "tutorial_table_rows": len(tutorial_rows), "tutorial_selected_modes": tutorial_modes,
            "event_mount": {"virtual_directory": "Event", "carrier": "Event.stp",
            "master_property": event_props[0], "runtime_selected": False}, "members": members,
            "complete_decoded_members_exported": False, "originals_modified": False}


def verify(args):
    require(not sys.flags.optimize, "run without -O")
    repo, sources = args.repo.resolve(), args.sources.resolve()
    manifest = json.loads((HERE / "source-manifest.json").read_text())
    require(manifest["baseline"] == BASE, "baseline mismatch")
    source_bytes = {}
    for pin in manifest["git_sources"]:
        data = git(repo, "show", pin["commit"] + ":" + pin["path"])
        require(len(data) == pin["bytes"] and sha(data) == pin["sha256"], "Git source hash: " + pin["path"])
        require(git(repo, "rev-parse", pin["commit"] + ":" + pin["path"]).decode().strip() == pin["blob"], "Git blob identity")
        source_bytes[pin["path"]] = data
    originals = {}
    for pin in manifest["originals"]:
        data = (sources / pin["file"]).read_bytes()
        require(len(data) == pin["bytes"] and sha(data) == pin["sha256"], "original identity: " + pin["file"])
        originals[pin["file"]] = data
    binary = originals["02-Tartaros.bin"]
    sections = pe_sections(binary)
    native = json.loads((HERE / "native-proof.json").read_text())
    instruction_count = 0
    for row in native["windows"]:
        start, end = int(row["va"], 16), int(row["end_exclusive"], 16)
        raw = raw_for(sections, start, end - start)
        require(raw == row["raw"] and sha(binary[raw:raw + end - start]) == row["sha256"], "native window " + row["id"])
        # The full prior evidence is pinned separately; these are reused spans.
        require(row["origin_path"] in source_bytes and row["classification"] == "REUSED_NATIVE_PROFILE_JOIN", "native reuse provenance")
        prior = json.loads(source_bytes[row["origin_path"]])
        if row["origin_id"] == "report_builder":
            origin = prior["report_builder"]
        else:
            origins = prior.get("records", prior.get("windows", []))
            origin = next(r for r in origins if r.get("id", r.get("tag")) == row["origin_id"])
        origin_start = int(origin.get("va", origin.get("start_va")), 16)
        origin_bytes = bytes.fromhex(origin.get("hex", origin.get("bytes_hex", "")))
        require(origin_start <= start < end <= origin_start + len(origin_bytes), "span outside pinned upstream bytes")
        require(origin_bytes[start - origin_start:end - origin_start] == binary[raw:raw + end - start], "upstream evidence bytes differ")
        if row["kind"] == "code":
            decoded = disassemble(sources / "02-Tartaros.bin", start, end)
            require(len(decoded) == row["instructions"], "instruction boundary count")
            instruction_count += len(decoded)
    for anchor in native["anchors"]:
        value = bytes.fromhex(anchor["hex"])
        raw = raw_for(sections, int(anchor["va"], 16), len(value))
        require(binary[raw:raw + len(value)] == value, "native anchor " + anchor["id"])
    STP = load_reader(repo, source_bytes)
    resources = resource_summary(STP, sources)
    require(resources == json.loads((HERE / "resource-evidence.json").read_text()), "selected resource join differs")
    event = STP(sources / "06-Event.stp")
    qbase = event.get("Event/qbase.lua")[0]
    lua = json.loads((HERE / "lua-proof.json").read_text())
    original_coro = source_bytes[lua["coroutine_original_path"]]
    words = 0
    for row in lua["slices"]:
        data = qbase if row["source"] == "Event/qbase.lua" else original_coro
        offset = row["code_offset"]
        expected = b"".join(struct.pack("<I", v) for v in row["words"])
        require(data[offset:offset + len(expected)] == expected, "selected Lua words " + row["id"])
        words += len(row["words"])
    contracts = json.loads((HERE / "contracts.json").read_text())
    require(contracts["product_premise"]["mef_is_server_development"] is True, "product architecture premise")
    require(contracts["delivery"]["game_tcp_raw_script_receiver_proven"] is False, "unsupported blob receiver")
    require(contracts["delivery"]["official_mef_grammar_required"] is False, "wrong product prerequisite")
    profiles = {p["id"]: p for p in contracts["profiles"]}
    require(profiles["Q_FINITE"]["ordinary_background_B_required"] is False, "B must not block finite Q")
    require(profiles["TUTORIAL_INTERACTIVE"]["ordinary_background_B_required"] is False, "B must not block Tutorial")
    require(profiles["ORDINARY_BACKGROUND_B"]["static_end_to_end_closed"] is False, "B status inflated")
    template = json.loads((HERE / "delivery-manifest.template.json").read_text())
    require(template["deployment_state"] == "UNBOUND_NOT_DEPLOYED", "template is not a deployed release")
    require(template["selector"]["quest"] is None and template["selector"]["scene"] is None, "unassigned selector")
    require(template["new_success_ack"] is None, "invented success acknowledgement")
    return {"status": "PASS_BOUNDED_STATIC_PROFILE_EVIDENCE", "baseline": BASE,
            "git_sources": len(source_bytes), "originals": len(originals), "native_windows": len(native["windows"]),
            "native_bytes": sum(int(r["end_exclusive"], 16) - int(r["va"], 16) for r in native["windows"]),
            "decoded_instructions": instruction_count, "native_anchors": len(native["anchors"]),
            "selected_members": len(resources["members"]), "configured_selector_routes": len(resources["configured_selectors"]),
            "selected_lua_slices": len(lua["slices"]), "selected_lua_words": words,
            "semantics_newly_discovered": False, "new_output": "capability-first delivery and authoring contracts",
            "target_executed": False, "lua_executed": False, "server_executed": False,
            "deployed": False, "playability_verified": False, "official_grammar_required": False}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--repo", type=Path, required=True)
    parser.add_argument("--sources", type=Path, required=True)
    result = verify(parser.parse_args())
    print(json.dumps(result, ensure_ascii=False, indent=2))
