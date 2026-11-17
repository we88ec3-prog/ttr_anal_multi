#!/usr/bin/env python3
"""Verify the narrow Q model 1086 catalog selection study without target execution.

Reads pinned originals, published parser/navigation and bounded native windows.
Writes only a research receipt when --result is supplied. Never runs Client,
Lua, archived programs, or a Server; never produces native cache/assets.
"""
import argparse
import hashlib
import importlib.util
import json
from pathlib import Path
import re
import struct
import subprocess
import sys
import xml.etree.ElementTree as ET

if sys.flags.optimize:
    raise RuntimeError("Run without -O: assertions are evidence checks")

HERE = Path(__file__).resolve().parent


def sha(data):
    return hashlib.sha256(data).hexdigest()


def read_json(path):
    return json.loads(Path(path).read_text(encoding="utf-8"))


def pe_sections(data):
    assert data[:2] == b"MZ"
    nt = struct.unpack_from("<I", data, 0x3c)[0]
    assert data[nt:nt+4] == b"PE\0\0"
    machine, count = struct.unpack_from("<HH", data, nt+4)
    opt = nt+24
    opt_size = struct.unpack_from("<H", data, nt+20)[0]
    assert machine == 0x14c and struct.unpack_from("<H", data, opt)[0] == 0x10b
    base = struct.unpack_from("<I", data, opt+28)[0]
    sections = []
    for i in range(count):
        at = opt+opt_size+40*i
        size, rva, raw_size, raw = struct.unpack_from("<IIII", data, at+8)
        sections.append((rva, raw_size, raw))
    return base, sections


def raw_offset(va, base, sections):
    rva = va-base
    for start, size, raw in sections:
        if start <= rva < start+size:
            return raw+rva-start
    raise ValueError(f"VA has no file-backed section: {va:#x}")


def disassemble(binary, anchor, end):
    out = subprocess.check_output([
        "objdump", "-d", "-Mintel", "--insn-width=16",
        "--start-address="+hex(anchor), "--stop-address="+hex(end), str(binary)
    ], text=True)
    rows = []
    for line in out.splitlines():
        m = re.match(r"\s*([0-9a-f]+):\s*\t([0-9a-f ]+)\t(.+)$", line)
        if m:
            rows.append({"va": "0x"+m[1], "bytes": bytes.fromhex(m[2]).hex(),
                         "asm": m[3].strip()})
    return rows


def xml_root(data):
    m = re.search(br"encoding=['\"]([^'\"]+)", data[:160])
    enc = m[1].decode("ascii") if m else "utf-8-sig"
    return ET.fromstring(data.decode(enc).lstrip("\ufeff \t\r\n"))


def attrs(node):
    return {k.upper(): v for k, v in node.attrib.items()}


def selected_observations(stp, sources, supplemental):
    table = stp.STP(sources/"07-Table.stp")
    body, table_meta = table.get("Table/_ActorList.xml")
    rows = []
    effective = None
    for ci, category in enumerate(xml_root(body)):
        ca = attrs(category)
        if category.tag.upper() != "OBJCATEGORY":
            continue
        for ri, actor in enumerate(category):
            aa = attrs(actor)
            if actor.tag.upper() != "ACTOR" or aa.get("ID") != "1086":
                continue
            row = {"category_ordinal_zero_based": ci, "actor_ordinal_zero_based": ri,
                   "category_id": int(ca["ID"]), "id": int(aa["ID"]),
                   "pre": int(aa["PRE"]), "file": aa["FILE"],
                   "admitted_by_category_not_three": int(ca["ID"]) != 3}
            rows.append(row)
            if row["admitted_by_category_not_three"]:
                effective = row["file"]
    assert effective is not None
    basename = effective+".abf"
    base = stp.STP(supplemental/"Base.stp")
    # This candidate comparison is an inventory operation. It does not emulate
    # locale-sensitive CRT normalization, mounted search order, or fcs.flu.
    matches = sorted(name for name in base.files
                     if name.rsplit("/", 1)[-1].upper() == basename.upper())
    assert matches == ["Mon/02_Stoncken.abf"]
    descriptor, descriptor_meta = base.get(matches[0])
    root = xml_root(descriptor)
    characters = [n for n in root.iter() if n.tag.upper() == "CHARACTER"]
    assert len(characters) == 1
    selected_actions = [1, 4, 8, 11, 101, 103]
    actions = []
    for n in characters[0].iter():
        a = attrs(n)
        if n.tag.upper() == "ANIMATION" and int(a["ID"]) in selected_actions:
            actions.append({"id": int(a["ID"]), "file": a["FILE"]})
    return {
        "model_id": 1086,
        "actorlist_member": table_meta,
        "matching_source_rows": rows,
        "effective_file_stem_under_proven_id_map_rule": effective,
        "requested_descriptor_basename": basename,
        "ascii_upper_inventory_key": basename.upper(),
        "base_member_count": len(base.files),
        "base_basename_matches": matches,
        "descriptor_member": descriptor_meta,
        "descriptor_root": root.tag,
        "character_attributes": dict(characters[0].attrib),
        "selected_action_declarations": sorted(actions, key=lambda a: a["id"]),
    }


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--sources", type=Path, required=True)
    ap.add_argument("--supplemental", type=Path, required=True)
    ap.add_argument("--repo", type=Path, required=True)
    ap.add_argument("--result", type=Path)
    args = ap.parse_args()
    manifest = read_json(HERE/"source-manifest.json")
    for item in manifest["originals"]:
        directory = args.supplemental if item.get("group") == "supplemental" else args.sources
        data = (directory/item["file"]).read_bytes()
        assert len(data) == item["bytes"] and sha(data) == item["sha256"], item["file"]
    for item in manifest["published_pins"]:
        body = subprocess.check_output(["git", "show", item["commit"]+":"+item["path"]], cwd=args.repo)
        assert len(body) == item["bytes"] and sha(body) == item["sha256"], item["path"]
        if item["role"] == "read_only_stp_parser":
            parser_pin = item
    parser_path = args.repo/parser_pin["path"]
    assert sha(parser_path.read_bytes()) == parser_pin["sha256"]
    spec = importlib.util.spec_from_file_location("pinned_stp", parser_path)
    stp = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(stp)
    binary = args.sources/"02-Tartaros.bin"
    data = binary.read_bytes()
    base, sections = pe_sections(data)
    native = read_json(HERE/"native-evidence.json")
    assert native["binary_sha256"] == sha(data)
    checked_bytes = 0
    for record in native["windows"]:
        start, end, anchor = (int(record[k], 16) for k in ("va", "end", "function_anchor"))
        off = raw_offset(start, base, sections)
        raw = data[off:off+end-start]
        assert off == int(record["raw_offset"], 16)
        assert len(raw) == record["length"] and sha(raw) == record["sha256"]
        rows = disassemble(binary, anchor, end)
        rows = [r for r in rows if start <= int(r["va"], 16) < end]
        assert rows == record["instructions"], record["id"]
        assert int(rows[0]["va"], 16) == start
        assert int(rows[-1]["va"], 16)+len(bytes.fromhex(rows[-1]["bytes"])) == end
        assert b"".join(bytes.fromhex(r["bytes"]) for r in rows) == raw
        assert not any("(bad)" in r["asm"] or ".byte" in r["asm"] for r in rows)
        checked_bytes += len(raw)
    for record in native["strings"]:
        off = raw_offset(int(record["va"], 16), base, sections)
        payload = record["value"].encode("ascii")+b"\0"
        assert int(record["raw_offset"], 16) == off
        assert data[off:off+len(payload)] == payload and sha(payload) == record["sha256"]
    reuse_bytes = 0
    for record in native["reused_windows"]:
        off = raw_offset(int(record["va"], 16), base, sections)
        assert sha(data[off:off+record["length"]]) == record["sha256"]
        reuse_bytes += record["length"]
    selection = read_json(HERE/"selection-result.json")
    assert selected_observations(stp, args.sources, args.supplemental) == selection["observations"]
    assert selection["conclusions"]["selected_PRE_status"] == "NOT_A_MODEL_CATALOG_KEY_FIELD"
    assert selection["conclusions"]["native_selected_descriptor_path"] is None
    assert selection["ready"] is False and selection["deployment_artifact"] is False
    receipt = {
        "schema": "MEF_MODEL_SELECTION_VERIFICATION_V1", "status": "PASS_REPRODUCIBLE_RESEARCH",
        "original_count": len(manifest["originals"]), "published_pin_count": len(manifest["published_pins"]),
        "native_window_count": len(native["windows"]), "native_window_bytes": checked_bytes,
        "native_string_count": len(native["strings"]),
        "reused_window_count": len(native["reused_windows"]), "reused_window_bytes": reuse_bytes,
        "source_model_rows": len(selection["observations"]["matching_source_rows"]),
        "effective_file_stem": selection["observations"]["effective_file_stem_under_proven_id_map_rule"],
        "descriptor_basename": selection["observations"]["requested_descriptor_basename"],
        "selected_PRE_status": selection["conclusions"]["selected_PRE_status"],
        "native_selected_descriptor_path": None, "ready": False, "deployment_artifact": False,
        "verifier_sha256": sha(Path(__file__).read_bytes()),
        "target_execution": False, "native_cache_or_asset_output": False,
    }
    output = json.dumps(receipt, ensure_ascii=False, indent=2)+"\n"
    if args.result:
        args.result.write_text(output, encoding="utf-8")
    print(output, end="")


if __name__ == "__main__":
    main()
