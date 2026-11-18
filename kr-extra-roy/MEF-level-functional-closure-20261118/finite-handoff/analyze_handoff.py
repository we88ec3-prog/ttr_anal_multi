#!/usr/bin/env python3
"""Read-only level projection and native evidence reproduction. No target execution."""
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
BASE = "09799b117f01e577be56dee3e909e1cde25b855f"
READER = "kr-extra-roy/MEF-world-identity-scene-interaction-20261117/stp_reader.py"
VARIANTS = ["story-q119-clear-scene.scenario.json", "story-q119-owner-continuity.scenario.json",
            "story-q119-node-delay.scenario.json"]
NARRATIVE = "governance/client-variants/20261107-town2-mainline/resources/alsmeer-full-mainline-content-candidate.json"
WINDOWS = [
    ("N01", 0x560170, 0x56038a, "NEW_PERSISTENCE_JOIN", "Q manager constructor normal prefix; allocation failure branches leave window"),
    ("N02", 0x561760, 0x5618dc, "REUSED_START_GATE", "normal Start prefix through the seen-skip branch; accepted path continues at end"),
    ("N03", 0x561db0, 0x5620aa, "REUSED_END_JOIN", "complete normal/review End body"),
    ("N04", 0x5623a0, 0x56243c, "NEW_PERSISTENCE_JOIN", "complete seen-key writer"),
    ("N05", 0x562440, 0x5624ab, "NEW_PERSISTENCE_JOIN", "complete seen-key reader"),
    ("N06", 0x713cc0, 0x713d49, "NEW_FILE_CONSUMER_JOIN", "file constructor/open prefix through initial seek operations; subsequent checks outside window"),
    ("N07", 0x713de0, 0x713e01, "NEW_FILE_CONSUMER_JOIN", "complete close method"),
    ("N08", 0x713e50, 0x713e6f, "NEW_FILE_CONSUMER_JOIN", "complete read method"),
    ("N09", 0x713e70, 0x713e8f, "NEW_FILE_CONSUMER_JOIN", "complete write method"),
]


def require(ok, message):
    if not ok:
        raise ValueError(message)


def sha(data):
    return hashlib.sha256(data).hexdigest()


def git(repo, *args):
    env = {**os.environ, "GIT_NO_LAZY_FETCH": "1", "GIT_OPTIONAL_LOCKS": "0", "GIT_TERMINAL_PROMPT": "0"}
    return subprocess.check_output(["git", "-C", str(repo), *args], env=env)


def pe_sections(data):
    pe = struct.unpack_from("<I", data, 60)[0]
    require(data[pe:pe+4] == b"PE\0\0", "PE signature")
    machine, count = struct.unpack_from("<HH", data, pe+4)
    opt = pe+24
    require(machine == 0x14c and struct.unpack_from("<H", data, opt)[0] == 0x10b, "PE32/i386")
    base = struct.unpack_from("<I", data, opt+28)[0]
    table = opt + struct.unpack_from("<H", data, pe+20)[0]
    result = []
    for i in range(count):
        _, rva, size, raw = struct.unpack_from("<4I", data, table+i*40+8)
        result.append((base+rva, raw, size))
    return result


def raw_for(sections, va, length):
    hits = [raw+va-start for start, raw, size in sections if start <= va and va+length <= start+size]
    require(len(hits) == 1, "unique PE raw mapping")
    return hits[0]


def disassemble(path, start, end):
    output = subprocess.check_output(["objdump", "-d", "-Mintel", "--insn-width=16",
                                      f"--start-address={start}", f"--stop-address={end}", str(path)], text=True)
    rows, cursor = [], start
    for line in output.splitlines():
        m = re.match(r"\s*([0-9a-f]+):\s+((?:[0-9a-f]{2} )*[0-9a-f]{2})\s+(.+)$", line)
        if m:
            va, code, asm = int(m[1], 16), m[2].replace(" ", ""), m[3].strip()
            require(va == cursor and "(bad)" not in asm and not asm.startswith(".byte"), "instruction alignment")
            rows.append({"va": hex(va), "hex": code, "asm": asm})
            cursor += len(bytes.fromhex(code))
    require(cursor == end, "partial terminal instruction")
    return rows


def native_evidence(binary_path):
    binary = binary_path.read_bytes()
    sections = pe_sections(binary)
    records, assembly = [], ["; Bounded original BIN evidence. Never executed.\n"]
    for ident, start, end, classification, scope in WINDOWS:
        raw = raw_for(sections, start, end-start)
        data = binary[raw:raw+end-start]
        insns = disassemble(binary_path, start, end)
        require(b"".join(bytes.fromhex(x["hex"]) for x in insns) == data, "disassembly/original bytes")
        records.append({"id": ident, "va": hex(start), "end_exclusive": hex(end), "raw": raw,
                        "bytes": len(data), "sha256": sha(data), "hex": data.hex(),
                        "instruction_count": len(insns), "classification": classification, "scope": scope})
        assembly.append("; " + ident + " " + scope)
        assembly.extend(f"{int(r['va'],16):08X}  {r['hex']:<32} {r['asm']}" for r in insns)
        assembly.append("")
    strings = []
    for ident, va, value in [("D01", 0xc10704, b"CSL.scn\0"), ("D02", 0xc059a4, b"wb\0"),
                             ("D03", 0xbed1e0, b"rb\0")]:
        raw = raw_for(sections, va, len(value))
        require(binary[raw:raw+len(value)] == value, "file literal")
        strings.append({"id": ident, "va": hex(va), "raw": raw, "hex": value.hex(), "text": value[:-1].decode()})
    slots = []
    for offset, target in [(4,0x713de0),(0x10,0x713e50),(0x14,0x713e70)]:
        va = 0xc44204+offset
        raw = raw_for(sections, va, 4)
        require(struct.unpack_from("<I", binary, raw)[0] == target, "file vtable target")
        slots.append({"vtable": "0xc44204", "offset": hex(offset), "va": hex(va), "raw": raw, "target": hex(target)})
    return {"schema": "LEVEL_FINITE_NATIVE_EVIDENCE_V1", "binary_sha256": sha(binary), "windows": records,
            "strings": strings, "vtable_slots": slots,
            "scope": "Bounded static native joins; no runtime file was read, written, removed or modified."}, "\n".join(assembly)+"\n"


def source_check(repo, sources):
    manifest = json.loads((HERE/"source-manifest.json").read_text())
    require(manifest["base_commit"] == BASE, "analysis baseline")
    result = {}
    for row in manifest["git_sources"]:
        ref = row["commit"]+":"+row["path"]
        data = git(repo, "show", ref)
        require(git(repo, "rev-parse", ref).decode().strip() == row["blob"], "Git blob")
        require(len(data) == row["bytes"] and sha(data) == row["sha256"], "Git source identity")
        result[row["path"]] = data
    for row in manifest["originals"]:
        data = (sources/row["file"]).read_bytes()
        require(len(data) == row["bytes"] and sha(data) == row["sha256"], "original identity")
    return result, manifest


def project_content(repo, sources, source_bytes):
    require((repo/READER).read_bytes() == source_bytes[READER], "STP helper differs from pinned source")
    spec = importlib.util.spec_from_file_location("level_handoff_stp", repo/READER)
    reader = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(reader)
    event, master = reader.STP(sources/"06-Event.stp"), reader.STP(sources/"11-Master.stp")
    members = []
    def member(archive, name):
        data, meta = archive.get(name)
        meta.pop("prefix", None)
        members.append(meta)
        return data
    data = member(event, "Event/SceneList.xml")
    m = re.search(br"encoding=['\"]([^'\"]+)", data[:160])
    scenes = list(ET.fromstring(data.decode(m[1].decode() if m else "utf-8-sig").lstrip("\ufeff \r\n\t")).iter("SCENE"))
    scene_hits = []
    for scene in range(1, 6):
        hits = [r for r in scenes if r.get("questIdx") == "119" and r.get("sceneIdx") == str(scene)]
        require(len(hits) == 1, "Q119 scene unique")
        row = hits[0]
        name = "Event/Sequences/"+row.get("funcName")+".seq"
        seq = member(event, name)
        scene_hits.append({"quest":119,"scene":scene,"attributes":dict(row.attrib),"path":name,
                           "decoded_sha256":sha(seq),"parser_branch":"text" if seq[0] != 0x1b else "binary"})
    prop = member(master, "Master0z/Event/AttachedPackage")
    require(prop.rstrip(b"\0") == b"Event", "Event mount")
    variants = []
    for name in VARIANTS:
        path = "design/scenario-content/"+name
        data = source_bytes[path]
        definitions = json.loads(data)["definitions"]
        matches = [x for x in definitions if x["id"] == "story-quest-119"]
        require(len(matches) == 1, "unique Q119 definition")
        definition = matches[0]
        nodes = []
        for n in definition["nodes"]:
            nodes.append({"node": n["node"], "map": n["map"], "spawn": n["spawn"], "portal": n["portal"],
                          "encounter_models": [e["model"] for e in n["encounters"]], "rules": n["rules"],
                          "signals": n.get("signals", []), "timedReinforcements": n.get("timedReinforcements", [])})
        variants.append({"path":path,"sha256":sha(data),"definition_id":definition["id"],
                         "preserve_owner_across_nodes":definition.get("preserveOwnerAcrossNodes",False),"nodes":nodes})
    narrative = json.loads(source_bytes[NARRATIVE])
    def collect(value):
        found = []
        if isinstance(value, dict):
            if value.get("quest") == 119:
                found.append(value)
            for x in value.values(): found.extend(collect(x))
        elif isinstance(value, list):
            for x in value: found.extend(collect(x))
        return found
    found = collect(narrative)
    require(len(found) == 1, "unique narrative Q119")
    selected = found[0]
    return {"schema":"LEVEL_FINITE_CONTENT_PROJECTION_V1","scene_list_rows":len(scenes),"q119_selectors":scene_hits,
            "members":members,"variants_are_alternatives_not_merged":True,"variants":variants,
            "q119_narrative":selected,"narrative_path":NARRATIVE,"narrative_sha256":sha(source_bytes[NARRATIVE]),
            "source_ordinal_and_authored_node_are_distinct":True,"new_scene_keys_allocated":False,
            "target_content_created_or_deployed":False,"complete_decoded_members_exported":False}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--repo", type=Path, required=True)
    parser.add_argument("--sources", type=Path, required=True)
    args = parser.parse_args()
    require(not sys.flags.optimize, "run without -O")
    source_bytes, manifest = source_check(args.repo, args.sources)
    projection = project_content(args.repo, args.sources, source_bytes)
    require(projection == json.loads((HERE/"content-projection.json").read_text()), "content projection differs")
    native, assembly = native_evidence(args.sources/"02-Tartaros.bin")
    require(native == json.loads((HERE/"native-evidence.json").read_text()), "native evidence differs")
    require(assembly == (HERE/"native-evidence.asm").read_text(), "native assembly differs")
    previous = json.loads(source_bytes["kr-extra-roy/MEF-end-to-end-20261116/entry/native-windows.json"])
    previous_by_id = {r["id"]: r for r in previous["records"]}
    for current_id, old_id in [("N02", "q_start_and_skip"), ("N03", "q_end")]:
        row = next(r for r in native["windows"] if r["id"] == current_id)
        old = previous_by_id[old_id]
        offset = int(row["va"], 16)-int(old["va"], 16)
        old_bytes = bytes.fromhex(old["hex"])
        require(0 <= offset and offset+row["bytes"] <= len(old_bytes), "reused span extent")
        require(bytes.fromhex(row["hex"]) == old_bytes[offset:offset+row["bytes"]], "reused upstream evidence differs")
    contract = json.loads((HERE/"handoff-contract.json").read_text())
    node = projection["variants"][0]["nodes"][3]
    require(contract["selected_level"] == {"quest":119,"node":node["node"],"map":node["map"],"point":node["portal"]}, "selected point")
    require(contract["replay"]["persistent_seen_file"] == "CSL.scn" and
            contract["replay"]["client_restart_proves_unseen"] is False and
            contract["replay"]["normal_end_and_seen_skip_share_003f"] is True, "replay constraints")
    require(contract["q119_existing_path"]["requires_extra_finite_q"] is False and
            contract["q119_existing_path"]["authoritative_state_from"] == "committed_server_mef_state", "Q119 authority")
    require(contract["proposed_after_rebuild_hook"]["implemented"] is False, "proposed hook mislabelled")
    result = {"status":"PASS_BOUNDED_LEVEL_HANDOFF_EVIDENCE","base_commit":BASE,
              "git_sources":len(manifest["git_sources"]),"originals":len(manifest["originals"]),
              "native_windows":len(native["windows"]),"native_bytes":sum(r["bytes"] for r in native["windows"]),
              "native_instructions":sum(r["instruction_count"] for r in native["windows"]),
              "native_file_vtable_slots":len(native["vtable_slots"]),"resource_members":len(projection["members"]),
              "q119_selectors":len(projection["q119_selectors"]),"configuration_variants":len(projection["variants"]),
              "persistent_seen_policy_rejoined":True,"target_executed":False,"deployed":False}
    print(json.dumps(result, ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
