#!/usr/bin/env python3
"""Read-only A1 original identity, selected witnesses and offline contract checks.
Requires the restored pinned previous study for its data-only STPD parser.
No fetch, git changes, Lua/Client/Server execution, or game-resource output.
"""
from __future__ import annotations
import argparse
import hashlib
import importlib.util
import io
import json
from pathlib import Path
import re
import struct
import subprocess
import sys
import unittest
import xml.etree.ElementTree as ET
from contract import SCENE, FUNC, SEQ_PATH, START, END_REPORT, RELEASE, BIN_SHA, require

EVENT_SHA = "2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b"
PINS = {
    "REPORT.md": "874e3fffdd2f727f47042ae475dd955f2248b8ff5b54039221446b642937ac7d",
    "native-evidence.json": "e0ee16a7797962ad04f6073afebaa71c57bd4fb2beead2ba9e034ee5f59f8f50",
    "resource-evidence.json": "f89878280db43f663b2092a782f1afbeb355c485605e99725524445c28ac2770",
    "verify_evidence.py": "3a7e2751274b9c1cc43f514e8ab13a5b48ff5983251f847334e213baab0381d2"
}

def sha(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()

def verify(args) -> dict:
    require(not sys.flags.optimize, "do not run with -O")
    folder = Path(__file__).resolve().parent
    e = json.loads((folder / "evidence.json").read_text(encoding="utf-8"))
    for name, expected in PINS.items():
        require(sha((args.prior / name).read_bytes()) == expected, "prior pin: " + name)
    spec = importlib.util.spec_from_file_location("pinned_data_parser", args.prior / "verify_evidence.py")
    require(spec is not None and spec.loader is not None, "parser import")
    prior = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(prior)  # verified read-only definitions; not its CLI or game code
    b = args.bin.read_bytes()
    require(sha(b) == BIN_SHA == e["bin_sha256"], "original KR BIN SHA")
    pe = struct.unpack_from("<I", b, 0x3c)[0]
    require(b[:2] == b"MZ" and b[pe:pe+4] == b"PE\0\0", "PE signature")
    require(struct.unpack_from("<H", b, pe+4)[0] == 0x14c, "i386")
    opt = pe + 24
    require(struct.unpack_from("<H", b, opt)[0] == 0x10b, "PE32")
    base = struct.unpack_from("<I", b, opt+28)[0]
    require(base == 0x400000, "image base")
    first = opt + struct.unpack_from("<H", b, pe+20)[0]
    sections = [struct.unpack_from("<IIII", b, first + i*40+8)
                for i in range(struct.unpack_from("<H", b, pe+6)[0])]
    def at(va: int, n: int, raw: int) -> bytes:
        hits = [p+va-base-v for _,v,size,p in sections if base+v <= va and va+n <= base+v+size]
        require(hits == [raw], "section mapping: " + hex(va))
        return b[raw:raw+n]
    for a in e["anchors"]:
        expected = bytes.fromhex(a["hex"])
        require(at(int(a["va"],0), len(expected), int(a["raw"],0)) == expected, a["id"])
    w = e["report_builder"]
    code = bytes.fromhex(w["hex"])
    require(at(int(w["va"],0),len(code),int(w["raw"],0)) == code and sha(code) == w["sha256"], "003F bytes")
    text = subprocess.check_output(["objdump", "-D", "-Mintel", "--insn-width=16",
        "--start-address="+w["va"], "--stop-address="+w["end"], str(args.bin)], text=True)
    actual = []
    for line in text.splitlines():
        m = re.match(r"\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*(.*)",line)
        if m: actual.append(dict(va=hex(int(m[1],16)),hex=bytes.fromhex(m[2]).hex(),asm=m[3].strip()))
    require(actual == w["instructions"], "003F decoded instruction agreement")
    cursor = int(w["va"],0)
    for ins in actual:
        require(int(ins["va"],0) == cursor and "(bad)" not in ins["asm"], "instruction boundary")
        cursor += len(bytes.fromhex(ins["hex"]))
    require(cursor == int(w["end"],0), "complete 003F builder")
    require(sha(args.event.read_bytes()) == EVENT_SHA, "original Event carrier")
    stp = prior.STP(args.event)
    data, meta = stp.get("Event/SceneList.xml")
    root = ET.fromstring(data.decode("utf-8-sig"))
    rows = [(int(x.attrib["questIdx"]),int(x.attrib["sceneIdx"]),x.attrib["funcName"]) for x in root]
    k = e["candidate_key_check"]
    require(meta == k["scene_list"], "SceneList member identity")
    require(root.tag == k["root"] and root[0].tag == k["row_tag"] and len(rows) == k["rows"], "XML shape")
    require(sum(a==0 for a,b,c in rows) == k["quest0_rows"], "quest0 row count")
    require(max(b for a,b,c in rows if a==0) == k["quest0_max"], "quest0 max")
    require(sum((a,b)==SCENE for a,b,c in rows) == k["key_matches"] == 0, "candidate collision")
    require(sum(c.casefold()==FUNC.casefold() for a,b,c in rows) == k["name_matches"] == 0, "func collision")
    require(sum(p.casefold()==SEQ_PATH.casefold() for p in stp.files) == k["archive_path_matches"] == 0, "path collision")
    require(len(stp.files) == k["file_count"], "archive index count")
    profile = json.loads((folder / "profile.json").read_text(encoding="utf-8"))
    require((profile["scene"]["questIdx"],profile["scene"]["sceneIdx"]) == SCENE, "profile scene")
    require(profile["scene"]["funcName"] == FUNC and profile["sequence_path"] == SEQ_PATH, "profile path")
    require(profile["applications"] == dict(start=START.hex(),end_report=END_REPORT.hex(),release=RELEASE.hex()), "application vectors")
    require(profile["target_binding"] is None and profile["deployment_status"] == "UNBOUND_NOT_DEPLOYABLE", "no fake deployment")
    import test_contract
    stream = io.StringIO()
    suite = unittest.defaultTestLoader.loadTestsFromTestCase(test_contract.ContractTests)
    result = unittest.TextTestRunner(stream=stream).run(suite)
    require(result.wasSuccessful(), stream.getvalue())
    return dict(status="PASS", scope="Pinned prior identities, selected BIN bytes, SceneList candidate and synthetic format/policy checks",
        original_bin_sha256=BIN_SHA, original_event_sha256=EVENT_SHA,
        prior_files_matched_publication_manifest=len(PINS), native_anchors=len(e["anchors"]),
        report_builder_bytes=len(code), report_builder_instructions=len(actual),
        scene_list_rows=len(rows), candidate_key=list(SCENE), candidate_collision=False,
        offline_contract_tests=result.testsRun, server_or_client_tests_run=False,
        client_executed=False,lua_executed=False,server_executed=False,game_resources_modified=False,
        deployment="UNBOUND_NOT_DEPLOYABLE", specification="IMPLEMENTABLE_DESIGN_NOT_S00_STABLE",
        limits=["Not a Client readiness query, T01 FULL-PASS, formal proof or gameplay acceptance",
                "Candidate absence is limited to the supplied original, not all future overlays",
                "Synthetic Binding/Exchange checks do not execute native Client or production Server"])

def main() -> int:
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--bin", type=Path, required=True)
    p.add_argument("--event", type=Path, required=True)
    p.add_argument("--prior", type=Path, required=True)
    a = p.parse_args()
    try:
        print(json.dumps(verify(a),ensure_ascii=False,indent=2)); return 0
    except (ValueError,OSError,KeyError,struct.error,subprocess.CalledProcessError) as exc:
        print(json.dumps(dict(status="FAIL",error=str(exc)),ensure_ascii=False),file=sys.stderr); return 1

if __name__ == "__main__":
    raise SystemExit(main())
