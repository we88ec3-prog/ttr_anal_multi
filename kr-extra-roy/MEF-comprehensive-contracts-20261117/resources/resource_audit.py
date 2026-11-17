#!/usr/bin/env python3
"""Read-only, source-pinned MEF resource audit; never executes Lua or a Client.

Outputs are research JSON, not game resources. The lexical scan is a bounded
inventory of direct calls in text .seq members, not an execution/call graph.
"""
from __future__ import annotations

import argparse
from collections import Counter, defaultdict
import hashlib
import importlib.util
import json
from pathlib import Path
import re
import sys
import xml.etree.ElementTree as ET
import zipfile

SOURCE_SHA = {
    "06-Event.stp": "2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b",
    "07-Table.stp": "09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442",
    "10-BoundMap.stp": "07d8f3a20aa4a396312c60927431a53a89dce6370ef8bb8192bd8d8eca1dd6b8",
}
HELPER = "kr-extra-roy/MEF-world-identity-scene-interaction-20261117/stp_reader.py"
HELPER_SHA = "14cb262d8abfaabadcf3160d9cf4e404587dca8b4273175de3a1549170f1c9dd"
DEPENDENCY_CALLS = {
    "CreateObject", "AniObject", "WalkObject", "WarpObject", "LoadMap",
    "PlayMusic", "SetFinalMusic", "PlaySound", "PlayTalkSound",
    "PlayCamera", "PlayCameraNoWait", "FlyingObject", "DoProlog",
    "OpenTalkScene", "OpenAutoTalkScene",
}
SCENE_MEMBER = "Event/Sequences/Phindous_YuriandRazed_Boss.seq"
IMAGE_MEMBER = "Event/Sequences/Aisen_01_After.seq"
SUPPLEMENTAL_SHA = {
    "Base.stp": "1854de2926ffe7c6172a4b350900f3b5b1e03d9f1757fc22d50b440515ec6957",
    "Tartaros-Web-AI-W1-W2-W3-input.zip": "7587e67dd012a020f0276c8cfd6b791ad07f8f5e7867931481c94aa30abf3e1a",
}


def sha(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def dump(path: Path, value) -> None:
    path.write_text(json.dumps(value, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")


def ascii_key(value: str) -> str:
    # Index names in this STP reader are ASCII; this is an audit candidate key,
    # deliberately not a claim to reproduce native member-ID construction.
    return value.replace("\\", "/").translate(str.maketrans("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "abcdefghijklmnopqrstuvwxyz"))


def xml_root(data: bytes):
    match = re.search(br"encoding=['\"]([^'\"]+)", data[:160])
    encoding = match[1].decode("ascii") if match else "utf-8-sig"
    text = data.decode(encoding)
    # Analysis-only accommodation: retain original hashes; do not rewrite data.
    return ET.fromstring(text.lstrip("\ufeff \t\r\n"))


def attrs(node):
    return {ascii_key(k): v for k, v in node.attrib.items()}


def elements(root, name):
    return [n for n in root.iter() if ascii_key(n.tag) == ascii_key(name)]


def lua_tokens(text: str):
    """Tokenize Lua 5.1 text without executing it.

    Discard line and long comments; keep short/long strings as indivisible
    tokens. Handle escaped quotes, decimal escapes and escaped newlines.
    Preserve physical line and source offsets for bounded excerpts.
    """
    tokens = []
    pos, line, length = 0, 1, len(text)

    def emit(kind, start, end, value=None):
        nonlocal pos, line
        raw = text[start:end]
        tokens.append({"kind": kind, "raw": raw, "value": value if value is not None else raw,
                       "line": line, "start": start, "end": end})
        line += raw.count("\n")
        pos = end

    while pos < length:
        c = text[pos]
        if c.isspace():
            line += int(c == "\n")
            pos += 1
            continue
        if text.startswith("--", pos):
            long = re.match(r"\[(=*)\[", text[pos + 2:])
            if long:
                closing = "]" + long[1] + "]"
                end = text.find(closing, pos + 2 + len(long[0]))
                if end < 0:
                    raise ValueError(f"unterminated long comment at line {line}")
                end += len(closing)
            else:
                end = text.find("\n", pos)
                if end < 0:
                    end = length
            line += text[pos:end].count("\n")
            pos = end
            continue
        if c in "\"'":
            start, quote, value = pos, c, []
            end = pos + 1
            while end < length and text[end] != quote:
                if text[end] != "\\":
                    if text[end] in "\r\n":
                        raise ValueError(f"unescaped string newline at line {line}")
                    value.append(text[end])
                    end += 1
                    continue
                end += 1
                if end >= length:
                    raise ValueError("unterminated string escape")
                esc = text[end]
                if esc.isdigit():
                    dec = re.match(r"[0-9]{1,3}", text[end:])[0]
                    n = int(dec)
                    if n > 255:
                        raise ValueError("Lua decimal escape >255")
                    value.append(chr(n))
                    end += len(dec)
                elif esc in "\r\n":
                    if esc == "\r" and text[end:end + 2] == "\r\n":
                        end += 1
                    value.append("\n")
                    end += 1
                else:
                    value.append({"a": "\a", "b": "\b", "f": "\f", "n": "\n", "r": "\r", "t": "\t", "v": "\v"}.get(esc, esc))
                    end += 1
            if end >= length:
                raise ValueError(f"unterminated string at line {line}")
            emit("string", start, end + 1, "".join(value))
            continue
        long = re.match(r"\[(=*)\[", text[pos:])
        if long:
            closing = "]" + long[1] + "]"
            end = text.find(closing, pos + len(long[0]))
            if end < 0:
                raise ValueError(f"unterminated long string at line {line}")
            value = text[pos + len(long[0]):end]
            if value.startswith("\r\n"):
                value = value[2:]
            elif value.startswith(("\n", "\r")):
                value = value[1:]
            emit("string", pos, end + len(closing), value)
            continue
        name = re.match(r"[A-Za-z_][A-Za-z_0-9]*", text[pos:])
        if name:
            emit("name", pos, pos + len(name[0]))
            continue
        number = re.match(r"(?:0[xX][0-9a-fA-F]+|(?:[0-9]+(?:\.[0-9]*)?|\.[0-9]+)(?:[eE][+-]?[0-9]+)?)", text[pos:])
        if number:
            emit("number", pos, pos + len(number[0]))
            continue
        symbol = next((p for p in ("...", "..", "==", "~=", "<=", ">=") if text.startswith(p, pos)), c)
        emit("symbol", pos, pos + len(symbol))
    return tokens


def literal(argument):
    if len(argument) == 1:
        t = argument[0]
        if t["kind"] == "string":
            return t["value"]
        if t["kind"] == "number":
            raw = t["raw"]
            n = int(raw, 16) if raw.lower().startswith("0x") else float(raw)
            return int(n) if int(n) == n else n
        if t["kind"] == "name" and t["raw"] in ("TRUE", "FALSE", "true", "false", "nil"):
            return {"symbol": t["raw"]}
    if len(argument) == 2 and argument[0]["raw"] in ("+", "-") and argument[1]["kind"] == "number":
        n = literal(argument[1:])
        return -n if argument[0]["raw"] == "-" else n
    return {"unresolved_expression": "".join(t["raw"] for t in argument)}


def direct_calls(text: str):
    tokens = lua_tokens(text)
    calls, unsupported = [], []
    for i, t in enumerate(tokens):
        if t["kind"] != "name" or t["raw"] not in DEPENDENCY_CALLS:
            continue
        if i and tokens[i - 1]["raw"] in (".", ":", "function"):
            continue
        if i + 1 >= len(tokens):
            continue
        if tokens[i + 1]["raw"] != "(":
            if tokens[i + 1]["kind"] == "string" or tokens[i + 1]["raw"] == "{":
                unsupported.append({"line": t["line"], "function": t["raw"], "reason": "non-parenthesized call syntax"})
            continue
        depth, args, start = 0, [], i + 2
        for j in range(i + 2, len(tokens)):
            raw = tokens[j]["raw"] if tokens[j]["kind"] == "symbol" else None
            if raw == ")" and depth == 0:
                if j > start:
                    args.append(tokens[start:j])
                calls.append({"function": t["raw"], "line": t["line"], "args": [literal(a) for a in args],
                              "excerpt": text[t["start"]:tokens[j]["end"]]})
                break
            if raw == "," and depth == 0:
                args.append(tokens[start:j])
                start = j + 1
            elif raw in ("(", "{", "["):
                depth += 1
            elif raw in (")", "}", "]"):
                depth -= 1
        else:
            raise ValueError(f"unclosed call {t['raw']} at line {t['line']}")
    return calls, unsupported


def load_stp_reader(repo: Path):
    path = repo / HELPER
    if sha(path.read_bytes()) != HELPER_SHA:
        raise ValueError("pinned read-only STP helper differs")
    spec = importlib.util.spec_from_file_location("mef_resource_stp", path)
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod.STP


def audit_supplemental(directory, archives, selected_evidence, STP):
    for name, expected in SUPPLEMENTAL_SHA.items():
        if sha((directory / name).read_bytes()) != expected:
            raise ValueError("supplemental source mismatch: " + name)
    base = STP(directory / "Base.stp")
    names = sorted(base.files)
    data, descriptor_meta = base.get("Mon/02_Stoncken.abf")
    root = xml_root(data)
    characters = elements(root, "Character")
    if len(characters) != 1:
        raise ValueError("selected original descriptor Character count changed")
    character = characters[0]
    wanted = sorted({n for row in selected_evidence["prepass_integer_collector_replay"] for n in row["actions"]})
    actions = []
    for n in elements(character, "Animation"):
        if int(attrs(n)["id"]) in wanted:
            actions.append({"attributes": dict(n.attrib), "children": [{"tag": c.tag, "attributes": dict(c.attrib)} for c in n]})
    wanted_values = set(wanted)
    found_values = {int(attrs(n)["id"]) for n in elements(character, "Animation") if int(attrs(n)["id"]) in wanted_values}
    if found_values != wanted_values:
        raise ValueError("selected action declaration set differs")
    payload_names = [attrs(character)["basefile"]]
    payload_names.extend(attrs(n)["file"] for n in elements(character, "Texture"))
    payload_names.extend(r["attributes"]["File"] for r in actions)
    nested_declared_paths = sorted({c["attributes"]["Folder"] + c["attributes"]["File"] for r in actions for c in r["children"] if "Folder" in c["attributes"] and "File" in c["attributes"]})
    zip_path = directory / "Tartaros-Web-AI-W1-W2-W3-input.zip"
    with zipfile.ZipFile(zip_path) as z:
        zip_infos = z.infolist()
        z_names = sorted(n.filename for n in zip_infos)
        # Read bytes only; do not extract files or run archived scripts/instructions.
        manifest_data = z.read("MANIFEST.json")
        manifest = json.loads(manifest_data)
        declared = {r["path"]: r for r in manifest["files"]}
        if len(declared) != len(manifest["files"]) or len(z_names) != len(set(z_names)):
            raise ValueError("duplicate archive/manifest paths")
        verified = 0
        local_meta, table_comparisons = [], []
        for info in zip_infos:
            raw = z.read(info.filename)
            if info.filename != "MANIFEST.json":
                record = declared.get(info.filename)
                if record is None or len(raw) != record["bytes"] or sha(raw) != record["sha256"]:
                    raise ValueError("ZIP manifest mismatch: " + info.filename)
                verified += 1
            if info.filename.startswith("local-resources/"):
                rec = {"path": info.filename, "bytes": len(raw), "sha256": sha(raw), "zip_crc32": f"{info.CRC:08x}",
                       "declared_origin_carrier_sha256": declared[info.filename].get("carrier_sha256"),
                       "declared_origin_member": declared[info.filename].get("member"),
                       "origin_full_carrier_reverified": False}
                local_meta.append(rec)
                member = info.filename.removeprefix("local-resources/")
                if member in archives["07-Table.stp"].files:
                    original, original_meta = archives["07-Table.stp"].get(member)
                    table_comparisons.append({"path": info.filename, "current_original_member": original_meta,
                                              "exact_bytes_equal": raw == original})
        if set(declared) != set(z_names) - {"MANIFEST.json"}:
            raise ValueError("ZIP manifest membership mismatch")
        def zxml(path):
            return xml_root(z.read(path))
        quest = next(n for n in elements(zxml("local-resources/Table/QuestInfo.xml"), "Quest") if attrs(n).get("id") == "119")
        cases = [n for n in elements(zxml("local-resources/Table/_CaseList.xml"), "CASE") if attrs(n).get("stage") == attrs(quest)["field"]]
        chart_path = "local-resources/Field/MapFlow/CHART_scenario_chicken_01.xml"
        cluster_path = "local-resources/Field/Cluster/CLUST_scenario_chicken_01.xml"
        chart, cluster = zxml(chart_path), zxml(cluster_path)
        chart_nodes = [{"node_id": attrs(n).get("id"), "title": attrs(n).get("title"), "type": attrs(n).get("type"),
                        "map_rows": [dict(c.attrib) for c in n if ascii_key(c.tag) == "map"]}
                       for n in elements(chart, "Node") if any(ascii_key(c.tag) == "map" and attrs(c).get("id") == "635" for c in n)]
        cluster_rows = [{"cluster_attributes": dict(n.attrib), "object_attributes": dict(c.attrib)}
                        for n in elements(cluster, "CLUSTER") for c in n if ascii_key(c.tag) == "object" and attrs(c).get("id") == "1086"]
        z_assets = [n.removeprefix("local-resources/") for n in z_names if n.startswith("local-resources/")]
    all_names = [p for a in list(archives.values()) + [base] for p in a.files] + z_assets
    payload_checks = [{"declared_basename": value, "basename_candidates_in_supplied_four_stp_and_zip": [p for p in all_names if ascii_key(Path(p).name) == ascii_key(value)],
                       "native_full_path": None} for value in sorted(set(payload_names))]
    nested_checks = [{"declared_folder_plus_file": value, "exact_members_in_supplied_four_stp_and_zip": [p for p in all_names if p == value]} for value in nested_declared_paths]
    return {
        "schema": "MEF_RESOURCE_SUPPLEMENTAL_AUDIT_V1", "deployment_artifact": False, "ready": False,
        "sources": [{"file": name, "bytes": (directory / name).stat().st_size, "sha256": digest,
                     "provenance_scope": "supplemental supplied resource; runtime installation/version binding not observed"} for name, digest in SUPPLEMENTAL_SHA.items()],
        "base_inventory": {"member_count": len(names), "extension_counts": dict(sorted(Counter(Path(n).suffix for n in names).items())),
                           "names_sha256": sha("\n".join(names).encode("ascii")), "names_digest_rule": "sorted ASCII paths joined LF, no terminal LF",
                           "all_under_Mon": all(n.startswith("Mon/") for n in names),
                           "soma_stem_candidates": [n for n in names if ascii_key(Path(n).stem) == "soma"]},
        "descriptor": {"metadata": descriptor_meta, "root": root.tag, "character_attributes": dict(character.attrib),
                       "texture_declarations": [dict(n.attrib) for n in elements(character, "Texture")],
                       "animation_declaration_count": len(elements(character, "Animation")), "selected_required_action_ids": wanted,
                       "selected_action_declarations": actions, "payload_basename_checks": payload_checks, "nested_explicit_path_checks": nested_checks,
                       "actual_native_catalog_selection": None,
                       "association_evidence": "Actual supplied Mon/02_Stoncken.abf has CharacterList and requested action IDs; its stem matches the three original category1 FILE rows. The sibling resource-selection study proves ID-only key, PRE exclusion and basename/path rules; actual runtime CHA_ABF directory and mount binding remain unobserved."},
        "zip_inventory": {"entries": len(z_names), "manifest_entries_verified": verified,
                          "local_resource_entries": len(z_assets), "names_sha256": sha("\n".join(z_names).encode("utf-8")),
                          "names_digest_rule": "sorted UTF-8 paths joined LF, no terminal LF", "manifest_sha256": sha(manifest_data),
                          "schema": manifest.get("schema"), "local_resource_metadata": sorted(local_meta, key=lambda r: r["path"]),
                          "original_table_byte_comparisons": sorted(table_comparisons, key=lambda r: r["path"]),
                          "archived_instructions_executed_or_adopted": False},
        "selected_data_join": {"quest119_attributes": {k: v for k, v in quest.attrib.items() if ascii_key(k) != "subject"},
                               "matching_case_rows": [dict(n.attrib) for n in cases], "chart_member": chart_path, "map635_nodes": chart_nodes,
                               "cluster_member": cluster_path, "model1086_cluster_rows": cluster_rows,
                               "limit": "Data join supports Field26/Case107/Map635/cluster19 context; it does not assign Q119/3 to a runtime node, recover spawn coordinates or define official Server rules. Cluster PRE belongs to world data; the sibling native selection study establishes that Q model catalog keys do not use PRE. MapChart editor x/y are not exported as spawn geometry."},
        "current_dependency_state": {"model_descriptor_candidate_obtained": True, "six_requested_action_declarations_obtained": True,
                                    "native_model_descriptor_selection_proven": False, "model_motion_texture_effect_audio_payloads_obtained": False,
                                    "soma_descriptor_obtained": False, "dialogue_image_extension_obtained": False,
                                    "original_three_carrier_camera_findings_changed": False,
                                    "full_official_MEF_format_obtained": False},
    }


def audit(sources: Path, repo: Path, supplemental: Path | None = None):
    STP = load_stp_reader(repo)
    archives = {}
    inventories = []
    for filename, digest in SOURCE_SHA.items():
        path = sources / filename
        if sha(path.read_bytes()) != digest:
            raise ValueError(f"source mismatch: {filename}")
        arc = archives[filename] = STP(path)
        names = sorted(arc.files)
        inventories.append({"carrier": filename, "size": path.stat().st_size, "sha256": digest,
                            "member_count": len(names), "extension_counts": dict(sorted(Counter(Path(n).suffix.lower() for n in names).items())),
                            "names_sha256": sha("\n".join(names).encode("ascii")),
                            "names_digest_rule": "ASCII sorted full paths joined by LF without trailing LF"})
    event, table, bound = (archives[n] for n in SOURCE_SHA)
    member_records = {}
    case_index = defaultdict(list)
    for filename, arc in archives.items():
        for name in arc.files:
            case_index[ascii_key(name)].append({"carrier": filename, "path": name})

    def read(arc, path):
        data, meta = arc.get(path)
        member_records[(meta["carrier"], path)] = meta
        return data

    def inventory_lookup(path):
        exact = [{"carrier": filename, "path": path} for filename, arc in archives.items() if path in arc.files]
        candidates = sorted(case_index.get(ascii_key(path), []), key=lambda r: (r["carrier"], r["path"]))
        return {"requested_path": path, "status": "EXACT_MEMBER_PRESENT" if exact else ("CASE_VARIANT_CANDIDATE" if candidates else "NOT_IN_SUPPLIED_CARRIER_INDEX"),
                "exact_members": exact, "ascii_casefold_candidates": candidates,
                "native_open_parser_render_success": None}

    seqs, compiled, lexer_errors, unsupported, all_calls = {}, [], [], [], []
    for name in sorted(event.files):
        if not name.endswith(".seq"):
            continue
        data, meta = event.get(name)
        if data.startswith(b"\x1bLua"):
            compiled.append(meta)
            continue
        try:
            text = data.decode("utf-8-sig")
            calls, uns = direct_calls(text)
        except (UnicodeError, ValueError) as exc:
            lexer_errors.append({"member": name, "error": str(exc), "metadata": meta})
            continue
        seqs[name] = (text, calls, meta)
        unsupported.extend({"member": name, **r} for r in uns)
        all_calls.extend({"member": name, **r} for r in calls)

    camera_refs, camera_dynamic, camera_misses = [], [], []
    for c in all_calls:
        if c["function"] not in ("PlayCamera", "PlayCameraNoWait"):
            continue
        if not c["args"] or not isinstance(c["args"][0], str):
            camera_dynamic.append({k: c[k] for k in ("member", "line", "function", "args")})
            continue
        lookup = inventory_lookup("Event/CameraWorks/" + c["args"][0])
        ref = {"member": c["member"], "line": c["line"], "function": c["function"], **lookup}
        camera_refs.append(ref)
        if lookup["status"] != "EXACT_MEMBER_PRESENT":
            read(event, c["member"])
            camera_misses.append({**ref, "excerpt": c["excerpt"], "member_decoded_sha256": seqs[c["member"]][2]["decoded_sha256"]})

    # Inventory shape observations do not reproduce TinyXML's recovery or
    # native numeric conversion, interpolation, or the renderer.
    cam_observations = {k: [] for k in ("xml_parse_errors", "leading_bom_or_ascii_whitespace", "non_lowercase_keyframe_tags",
                                        "duplicate_numeric_framepos", "decreasing_numeric_framepos", "non_python_float_framepos", "zero_keyframes")}
    cam_shapes = []
    for name in sorted(n for n in event.files if n.endswith(".cam")):
        data, meta = event.get(name)
        try:
            root = xml_root(data)
        except (UnicodeError, ET.ParseError) as exc:
            cam_observations["xml_parse_errors"].append({"member": name, "error": str(exc), "decoded_sha256": meta["decoded_sha256"],
                                                       "raw_prefix_hex": data[:24].hex()})
            continue
        if data.startswith(b"\xef\xbb\xbf") or data[:1] in (b" ", b"\t", b"\r", b"\n"):
            cam_observations["leading_bom_or_ascii_whitespace"].append(name)
        nodes = [n for n in root if ascii_key(n.tag) == "keyframe"]
        if any(n.tag != "keyframe" for n in nodes):
            cam_observations["non_lowercase_keyframe_tags"].append(name)
        if not nodes:
            cam_observations["zero_keyframes"].append(name)
        numbers = []
        raw_positions = []
        for i, n in enumerate(nodes):
            token = attrs(n).get("framepos")
            raw_positions.append(token)
            try:
                numbers.append(float(token))
            except (ValueError, TypeError):
                cam_observations["non_python_float_framepos"].append({"member": name, "keyframe_index": i, "token": token})
        if len(numbers) != len(set(numbers)):
            cam_observations["duplicate_numeric_framepos"].append(name)
        if any(y < x for x, y in zip(numbers, numbers[1:])):
            cam_observations["decreasing_numeric_framepos"].append(name)
        cam_shapes.append({"member": name, "root": root.tag, "keyframes": len(nodes), "positions": raw_positions, "decoded_sha256": meta["decoded_sha256"]})
    camera = {
        "scope": "direct parenthesized global PlayCamera/PlayCameraNoWait calls in successfully lexed textual .seq members only; no execution, reachability, aliases, dynamic call graph or Lua bytecode analysis",
        "text_sequence_members": len(seqs), "compiled_sequence_members_excluded": compiled,
        "lexer_errors": lexer_errors, "unsupported_call_syntax": unsupported,
        "dependency_direct_call_occurrences": dict(sorted(Counter(c["function"] for c in all_calls).items())),
        "literal_camera_call_occurrences": len(camera_refs),
        "literal_camera_unique_paths": len({r["requested_path"] for r in camera_refs}),
        "exact_path_miss_occurrences": len(camera_misses),
        "exact_path_miss_unique_paths": len({r["requested_path"] for r in camera_misses}),
        "case_variant_candidates": [r for r in camera_misses if r["status"] == "CASE_VARIANT_CANDIDATE"],
        "absent_even_after_audit_casefold": [r for r in camera_misses if r["status"] == "NOT_IN_SUPPLIED_CARRIER_INDEX"],
        "unresolved_camera_expressions": camera_dynamic,
        "camera_member_count": sum(n.endswith(".cam") for n in event.files),
        "shape_audit_policy": "Python ElementTree after stripping leading BOM/ASCII whitespace, and ASCII tag folding for inspection only; no native validity or gameplay failure verdict",
        "shape_summary_counts": {k: len(v) for k, v in cam_observations.items()},
        "shape_observations": cam_observations,
        "all_shapes_sha256": sha(json.dumps(cam_shapes, sort_keys=True, ensure_ascii=True, separators=(",", ":")).encode()),
        "ready": False,
    }

    scenelist = xml_root(read(event, "Event/SceneList.xml"))
    for ref in camera_misses:
        function = Path(ref["member"]).stem
        ref["exact_scene_selector_rows"] = [dict(n.attrib) for n in scenelist.iter() if attrs(n).get("funcname") == function]
    camera["camera_miss_references_without_exact_scene_selector"] = sum(not r["exact_scene_selector_rows"] for r in camera_misses)
    camera["selector_join_scope"] = "Exact SceneList.funcName = sequence basename join only; selected rows do not prove runtime invocation or Server scene authorization."
    actorlist = xml_root(read(table, "Table/_ActorList.xml"))
    maplist = xml_root(read(table, "Table/_MapList.xml"))
    talks = xml_root(read(table, "Table/ScenarioTalkTable.xml"))
    talksets = xml_root(read(table, "Table/TalkTableSet.xml"))
    npcs = xml_root(read(table, "Table/npctable.xml"))
    soundroot = xml_root(read(table, "Table/_Sound.xml"))
    soundlist_text = read(table, "Table/_SoundList.txt").decode("utf-8")
    scene_text, scene_calls, scene_meta = seqs[SCENE_MEMBER]
    read(event, SCENE_MEMBER)
    selected_scenes = [dict(n.attrib) for n in scenelist.iter() if attrs(n).get("questidx") == "119" and attrs(n).get("sceneidx") == "3"]
    selected_rows = []
    for category in elements(actorlist, "OBJCATEGORY"):
        for actor in elements(category, "ACTOR"):
            if attrs(actor).get("id") == "1086":
                selected_rows.append({"category": attrs(category).get("id"), "row": dict(actor.attrib)})

    # Replay only the already-proved integer collector transformations over
    # this straight-line original sample. This is not a Lua VM/interpreter.
    collector = {}
    arity = {"CreateObject": 9, "AniObject": 3, "WalkObject": 7, "WarpObject": 7}
    for c in scene_calls:
        fn, a = c["function"], c["args"]
        if fn not in arity:
            continue
        if len(a) != arity[fn]:
            raise ValueError(f"selected sample arity changed: {fn}")
        if fn == "CreateObject":
            slot, model, action = a[0], a[1], a[5]
            if any(type(v) is not int for v in (slot, model, action)):
                raise ValueError("selected integer sample changed")
            key = slot & 0xFFFF
            if key not in collector:
                collector[key] = {"slot_word": key, "model_word": model & 0xFFFF, "actions": set(), "source_lines": []}
                action = 1 if action == 0 else action
            collector[key]["actions"].add(action & 0xFFFF)
            collector[key]["source_lines"].append(c["line"])
            continue
        slot = a[0] & 0xFFFF
        if slot not in collector:
            continue
        if fn == "AniObject":
            action = a[1]
        else:
            gate, action, default = (a[4], a[5], 4) if fn == "WalkObject" else (a[5], a[6], 1)
            if not gate:
                continue
            action = default if action < 0 else action
        collector[slot]["actions"].add(action & 0xFFFF)
        collector[slot]["source_lines"].append(c["line"])
    for row in collector.values():
        row["actions"] = sorted(row["actions"])

    selected_camera_name = next(c["args"][0] for c in scene_calls if c["function"] == "PlayCamera")
    selected_camera_path = "Event/CameraWorks/" + selected_camera_name
    selected_camera = xml_root(read(event, selected_camera_path))
    camera_detail = {"lookup": inventory_lookup(selected_camera_path), "root": selected_camera.tag,
                     "framepos_tokens": [attrs(n).get("framepos") for n in elements(selected_camera, "keyframe")],
                     "offset_args_from_original_call": next(c["args"][1:] for c in scene_calls if c["function"] == "PlayCamera"),
                     "numeric_offsets_are_not_new_spawn_coordinates": True}
    map_arg = next(c["args"][0] for c in scene_calls if c["function"] == "LoadMap")
    map_stem = map_arg.removesuffix(".fld")
    map_rows = [dict(n.attrib) for n in elements(maplist, "MAP") if attrs(n).get("map") == map_stem]
    bounds = sorted({"BoundMap/" + attrs(n)["bound"] + ".bnd" for n in elements(maplist, "MAP") if attrs(n).get("map") == map_stem and "bound" in attrs(n)})
    for path in bounds:
        if path in bound.files:
            read(bound, path)
    talk_scene_rows = [n for n in elements(talks, "Scenario") if attrs(n).get("id") == "12" and attrs(n).get("scene") == "11"]
    if len(talk_scene_rows) != 1:
        raise ValueError("selected dialogue row uniqueness changed")
    dialogue_rows = [dict(n.attrib) for n in elements(talk_scene_rows[0], "Talk")]
    keys = {int(attrs(n)["talk"]) for n in elements(talk_scene_rows[0], "Talk")}
    actors = {int(attrs(n).get("char", attrs(n).get("npc"))) for n in elements(talk_scene_rows[0], "Talk")}
    text_matches, active_talksets = [], []
    total_text_rows = 0
    for node in elements(talksets, "SET"):
        path = attrs(node)["path"]
        root = xml_root(read(table, path))
        active_talksets.append(path)
        for i, n in enumerate(elements(root, "Talk")):
            total_text_rows += 1
            ident = int(attrs(n)["id"])
            if ident in keys:
                txt = "".join(n.itertext())
                text_matches.append({"talk_key": ident, "member": path, "talk_row_index": i,
                                     "attributes": dict(n.attrib), "text_character_count": len(txt), "text_utf8_sha256": sha(txt.encode("utf-8"))})
    display_npc_matches = [dict(n.attrib) for n in elements(npcs, "NPC") if int(attrs(n).get("id", "-1")) in actors]
    soundbase = [dict(n.attrib) for n in elements(soundroot, "SoundBaseDir")]
    requested_sounds = sorted({c["args"][0] for c in scene_calls if c["function"] in ("PlaySound", "PlayTalkSound")})
    sound_rows = []
    for path in requested_sounds:
        file_key = path.removeprefix("Sound/")
        sound_rows.append({"request": inventory_lookup(path), "declaration_rows": [dict(n.attrib) for n in elements(soundroot, "Sound") if attrs(n).get("file") == file_key]})
    music_args = [c["args"][0] for c in scene_calls if c["function"] == "PlayMusic"]
    music = [{"argument": value, "request": inventory_lookup("Sound/" + value),
              "sound_list_rows": [line for line in soundlist_text.splitlines() if line.split()[-1:] == ["Sound/" + value]]} for value in music_args]
    selected_evidence = {
        "case": "original Q119 scene3; data dependencies only, no execution or stage/instance binding assertion",
        "scene_list_rows": selected_scenes, "sequence": SCENE_MEMBER,
        "dependency_call_excerpts": scene_calls,
        "model_catalog_candidates": selected_rows,
        "model_catalog_resolution": {"selected_PRE": None, "descriptor_path": None, "action_descriptors": None, "model_or_texture_payloads": None,
                                     "reason": "ActorList is metadata; three category1 PRE rows share model1086/FILE02_Stoncken. No CharacterList/action/avatar/texture carrier is supplied; descriptor path not invented."},
        "prepass_integer_collector_replay": list(collector.values()),
        "collector_is_not_complete_transitive_dependency_preflight": True,
        "camera": camera_detail,
        "map": {"original_argument": map_arg, "matching_maplist_rows": map_rows, "selected_map_id": None,
                "bound_members": [inventory_lookup(p) for p in bounds],
                "field_payload_lookup_by_basename": [r for group in case_index.values() for r in group if Path(r["path"]).name.lower() == map_arg.lower()],
                "caller_to_field_root_path": None,
                "note": "MapList stem join establishes candidate rows and BOUND; it does not choose a Server map/instance/portal or prove Q.LoadMap consumes this BND."},
        "dialogue": {"scene_attributes": dict(talk_scene_rows[0].attrib), "rows": dialogue_rows,
                     "active_talkset_count": len(active_talksets), "active_text_row_count_recheck": total_text_rows,
                     "text_matches": text_matches, "display_actor_keys": sorted(actors), "npctable_matches": display_npc_matches,
                     "display_extension_lookup": inventory_lookup("Image/TalkNPC.xml"),
                     "voice_resolution": None, "voice_note": "Native talk ID -> voice selector is known, but audio carrier/version/localization/selection result is not supplied; no filename is invented."},
        "sound_base_declarations": soundbase, "sounds": sound_rows, "music": music,
        "final_music_empty": any(c["function"] == "SetFinalMusic" and c["args"] == [""] for c in scene_calls),
        "final_music_empty_note": "Empty final music is not a required Sound/ file; RestoreMap fallback depends on prior runtime state.",
        "ready": False,
    }
    image_text, image_calls, image_meta = seqs[IMAGE_MEMBER]
    read(event, IMAGE_MEMBER)
    image_call = next(c for c in image_calls if c["function"] == "FlyingObject")
    image_evidence = {
        "case": "one original image dependency from Q2440 scene5; not a complete audit of this longer scene",
        "scene_list_rows": [dict(n.attrib) for n in scenelist.iter() if attrs(n).get("questidx") == "2440" and attrs(n).get("sceneidx") == "5"],
        "sequence": IMAGE_MEMBER, "call_excerpt": image_call,
        "image": inventory_lookup(image_call["args"][0]), "ready": False,
    }
    result = {
        "carrier-inventory.json": {"schema": "MEF_RESOURCE_INVENTORY_RESEARCH_V1", "carriers": inventories,
                                   "scope": "supplied three archive indexes only; original Client installation, overlays, ordinary files and mounted runtime packages unknown",
                                   "queried_extensions_absent_from_indexes": [extension for extension in (".fld", ".dds", ".ogg", ".wav", ".mef")
                                                                             if not any(Path(name).suffix.lower() == extension for arc in archives.values() for name in arc.files)],
                                   "deployment_artifact": False},
        "camera-audit.json": camera,
        "selected-dependencies.json": {"schema": "MEF_RESOURCE_DEPENDENCY_AUDIT_V1", "deployment_artifact": False,
                                       "source_scope": "initial Event/Table/BoundMap audit; additive Base/ZIP findings are separately in supplemental-audit.json when provided",
                                       "selected_scene": selected_evidence, "selected_image": image_evidence, "ready": False},
        "member-evidence.json": {"schema": "MEF_BOUNDED_MEMBER_LOCATORS_V1", "members": [member_records[k] for k in sorted(member_records)],
                                 "note": "Locators/hashes plus bounded selected excerpts in companion reports; no whole original sequence, Lua chunk, model, camera or text archive exported."},
    }
    if supplemental is not None:
        result["supplemental-audit.json"] = audit_supplemental(supplemental, archives, selected_evidence, STP)
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--sources", type=Path, required=True)
    parser.add_argument("--repo", type=Path, required=True)
    parser.add_argument("--output-dir", type=Path, required=True)
    parser.add_argument("--supplemental", type=Path, help="directory containing the pinned Base.stp and W1/W2/W3 ZIP; data-only additive audit")
    parser.add_argument("--require-ready", action="store_true", help="exit 2 for unresolved dependencies; audit files still written")
    args = parser.parse_args()
    if args.sources.resolve() == args.output_dir.resolve() or args.sources.resolve() in args.output_dir.resolve().parents:
        parser.error("research output must not be inside the original source directory")
    if args.supplemental and (args.supplemental.resolve() == args.output_dir.resolve() or args.supplemental.resolve() in args.output_dir.resolve().parents):
        parser.error("research output must not be inside the supplemental source directory")
    result = audit(args.sources, args.repo, args.supplemental)
    args.output_dir.mkdir(parents=True, exist_ok=True)
    for filename, value in result.items():
        dump(args.output_dir / filename, value)
    camera = result["camera-audit.json"]
    print(json.dumps({"audit_completed": True, "ready": False, "text_sequences": camera["text_sequence_members"],
                      "literal_camera_calls": camera["literal_camera_call_occurrences"],
                      "exact_camera_misses": camera["exact_path_miss_occurrences"],
                      "case_variant_candidates": len(camera["case_variant_candidates"]),
                      "absent_after_audit_casefold": len(camera["absent_even_after_audit_casefold"]),
                      "files": sorted(result)}, ensure_ascii=False))
    return 2 if args.require_ready else 0


if __name__ == "__main__":
    sys.exit(main())
