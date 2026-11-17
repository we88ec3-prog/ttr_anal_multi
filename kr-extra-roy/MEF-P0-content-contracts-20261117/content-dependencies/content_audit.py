#!/usr/bin/env python3
"""Source-pinned, read-only audit of two complete original scene functions.

Never executes Lua, Client code, archived programs or a Server. The accepted
syntax is deliberately bounded: one no-argument function containing only
literal direct calls, followed by Register(function). A new construct fails
closed; a successful parse is not a simulation of native execution.
"""
from __future__ import annotations
import argparse
from collections import Counter, defaultdict
import hashlib
import importlib.util
import json
from pathlib import Path
import sys
import zipfile

sys.dont_write_bytecode = True

HERE = Path(__file__).resolve().parent
BASE_COMMIT = "ac7e668ef19b91f86f05074d660aba10612c9a5f"
AUDIT_HELPER = "kr-extra-roy/MEF-comprehensive-contracts-20261117/resources/resource_audit.py"
SCENES = [(119, 3, "Phindous_YuriandRazed_Boss"), (2440, 5, "Aisen_01_After")]
PHASES = {"Phase1", "Phase2", "Phase3", "Phase4", "RevPhase1", "RevPhase2", "RevPhase3", "RevPhase4"}
NON_RESOURCE = PHASES | {"SetTransitionType", "HideOriginalObjs", "MoveCamera", "RotCamera", "wait", "WaitForObjectsStop", "RotateObject", "Q.DeleteAllObject", "RestoreMap", "FadeOut", "FadeIn"}
RESOURCE = {"SetFinalMusic", "LoadMap", "CreateObject", "PlayMusic", "PlayCamera", "PlayCameraNoWait", "PlaySound", "AniObject", "WalkObject", "OpenTalkScene", "FlyingObject", "DoProlog"}


def sha(data):
    return hashlib.sha256(data).hexdigest()


def require(condition, detail):
    if not condition:
        raise ValueError(detail)


def dump(path, value):
    require(not Path(path).is_symlink(), "derived output must not overwrite a symlink target")
    Path(path).write_text(json.dumps(value, ensure_ascii=False, indent=2)+"\n", encoding="utf-8")


def check_output_directory(output, repo, sources, supplemental):
    out = output.resolve()
    for root in (sources.resolve(), supplemental.resolve()):
        require(out != root and root not in out.parents and out not in root.parents,
                "output must not overlap original source directories")
    root = repo.resolve()
    require(root not in out.parents or out == HERE or HERE in out.parents,
            "repository writes are restricted to this research package")
    require(out != root, "repository root is not an output directory")
    return out


def load_helper(repo):
    manifest = json.loads((HERE/"source-manifest.json").read_text())
    pin = next(p for p in manifest["published_pins"] if p["path"] == AUDIT_HELPER)
    path = repo/AUDIT_HELPER
    if sha(path.read_bytes()) != pin["sha256"]:
        raise ValueError("published lexer helper differs")
    spec = importlib.util.spec_from_file_location("p0_resource_lexer", path)
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod


def whole_function(text, h):
    """Consume EVERY token; reject a branch, assignment, alias or expression."""
    tokens = h.lua_tokens(text)
    at = 0

    def take(raw=None, kind=None):
        nonlocal at
        if at >= len(tokens):
            raise ValueError("unexpected end of source")
        t = tokens[at]
        if raw is not None and t["raw"] != raw or kind is not None and t["kind"] != kind:
            raise ValueError(f"unsupported token {t['raw']} at line {t['line']}")
        at += 1
        return t

    take("function")
    name = take(kind="name")["raw"]
    take("("); take(")")
    calls = []
    while at < len(tokens) and tokens[at]["raw"] != "end":
        first = take(kind="name")
        function = first["raw"]
        if at < len(tokens) and tokens[at]["raw"] == ".":
            take(".")
            function += "."+take(kind="name")["raw"]
        if function not in NON_RESOURCE | RESOURCE:
            raise ValueError("unsupported scene call "+function)
        take("(")
        args, arg = [], []
        while True:
            t = take()
            if t["raw"] in (",", ")") and t["kind"] == "symbol":
                if arg:
                    value = h.literal(arg)
                    if isinstance(value, dict) and "unresolved_expression" in value:
                        raise ValueError(f"nonliteral argument to {function}: {value}")
                    args.append(value); arg = []
                elif t["raw"] == "," or args:
                    raise ValueError("empty argument")
                if t["raw"] == ")":
                    break
            else:
                arg.append(t)
        calls.append({"function": function, "line": first["line"], "args": args,
                      "source_call_sha256": sha(text[first["start"]:t["end"]].encode())})
        if at < len(tokens) and tokens[at]["raw"] == ";":
            take(";")
    take("end"); take("Register"); take("("); take(name); take(")")
    if at != len(tokens):
        raise ValueError("unconsumed source after Register")
    return name, calls, len(tokens)


def parser_checks(h):
    # These are synthetic ANALYZER tests, not native fixtures or gameplay tests.
    good = 'function T() -- PlayMusic("fake")\n PlayMusic("a\\046ogg") Q.DeleteAllObject() end Register(T)'
    name, calls, _ = whole_function(good, h)
    require(name == "T" and [c["function"] for c in calls] == ["PlayMusic", "Q.DeleteAllObject"], "analyzer positive control")
    require(calls[0]["args"] == ["a.ogg"], "analyzer escaped literal control")
    bad = [
        'function T() if TRUE then PlayMusic("a") end end Register(T)',
        'function T() x=1 end Register(T)',
        'function T() PlayMusic(prefix.."a") end Register(T)',
        'function T() PlayMusic("a") end Register(T) PlayMusic("b")',
        'function T() Unknown() end Register(T)',
    ]
    for source in bad:
        try:
            whole_function(source, h)
        except ValueError:
            continue
        raise AssertionError("unsupported syntax was silently accepted")
    return {"accepted_comment_string_qualified_call_case": 1, "rejected_unbounded_cases": len(bad)}


def audit(repo, sources, supplemental):
    require(not sys.flags.optimize, "run without -O/PYTHONOPTIMIZE; reused source parser checks must remain enabled")
    h = load_helper(repo)
    parser_result = parser_checks(h)
    manifest = json.loads((HERE/"source-manifest.json").read_text())
    for p in manifest["originals"]:
        root = supplemental if p["group"] == "supplemental" else sources
        b = (root/p["file"]).read_bytes()
        require(len(b) == p["bytes"] and sha(b) == p["sha256"], "original source mismatch: "+p["file"])
    STP = h.load_stp_reader(repo)
    archives = {n: STP(root/n) for root, n in [
        (sources, "06-Event.stp"), (sources, "07-Table.stp"),
        (sources, "10-BoundMap.stp"), (supplemental, "Base.stp")]}
    used = {}

    def read(carrier, name):
        body, meta = archives[carrier].get(name)
        used[carrier+":"+name] = meta
        return body

    def xml(carrier, name):
        return h.xml_root(read(carrier, name))

    zpath = supplemental/"Tartaros-Web-AI-W1-W2-W3-input.zip"
    with zipfile.ZipFile(zpath) as z:
        zip_names = z.namelist()
        zip_local = {n.removeprefix("local-resources/"): n for n in zip_names if n.startswith("local-resources/") and not n.endswith("/")}
        zip_payloads = {k: z.read(v) for k, v in zip_local.items()}
    inventory = [(carrier, n) for carrier, ar in archives.items() for n in ar.files]
    inventory.extend((zpath.name, n) for n in zip_local)

    def lookup(request=None, basename=None):
        exact = [{"carrier": c, "member": n} for c, n in inventory if request is not None and n == request]
        casefold = [{"carrier": c, "member": n} for c, n in inventory if request is not None and h.ascii_key(n) == h.ascii_key(request)]
        names = [{"carrier": c, "member": n} for c, n in inventory if basename is not None and h.ascii_key(n.rsplit("/", 1)[-1]) == h.ascii_key(basename)]
        return {"requested_path": request, "requested_basename": basename,
                "exact_members": exact, "ascii_casefold_candidates": casefold, "basename_candidates": names,
                "inventory_status": "EXACT_MEMBER_PRESENT" if exact else "BASENAME_CANDIDATE_PRESENT" if names else "CASE_VARIANT_CANDIDATE" if casefold else "NOT_IN_SUPPLIED_INDEXES",
                "native_selected_path": None, "native_open_parse_render_success": None}

    scene_root = xml("06-Event.stp", "Event/SceneList.xml")
    actor_root = xml("07-Table.stp", "Table/_ActorList.xml")
    map_root = xml("07-Table.stp", "Table/_MapList.xml")
    sys_map_root = xml("07-Table.stp", "Table/_SysMapList.xml")
    talk_root = xml("07-Table.stp", "Table/ScenarioTalkTable.xml")
    sets = xml("07-Table.stp", "Table/TalkTableSet.xml")
    npc_root = xml("07-Table.stp", "Table/npctable.xml")
    sound_root = xml("07-Table.stp", "Table/_Sound.xml")
    sound_list = read("07-Table.stp", "Table/_SoundList.txt").decode("utf-8")
    prolog_root = xml("07-Table.stp", "Table/Prolog.xml")
    talk_members = [h.attrs(n)["path"] for n in h.elements(sets, "set")]
    all_talks = defaultdict(list)
    for order, member in enumerate(talk_members):
        root = xml("07-Table.stp", member)
        for i, node in enumerate(h.elements(root, "talk")):
            a = h.attrs(node)
            if "id" not in a:
                continue
            text = "".join(node.itertext())
            all_talks[int(a["id"])].append({"member": member, "set_ordinal": order, "row_ordinal": i,
                "attributes": dict(node.attrib), "text_chars": len(text), "text_utf8_sha256": sha(text.encode())})

    nodes = []

    def dep(scene, role, source, selector, path=None, basename=None, proof=None, missing=None, parents=None):
        ident = f"{scene}:{role}:{len(nodes)+1:04d}"
        row = {"id": ident, "scene": scene, "role": role, "source": source, "selector": selector,
               "proven_path_rule": proof, "inventory": lookup(path, basename),
               "parents": parents or [], "missing": missing or [], "ready": False,
               "required_feature_policy": "must be set by Server content profile; no blanket asset-failure inference"}
        if role in ("default_appearance_item_catalog", "appearance_item_catalog"):
            row["native_absence_behavior"] = "7A7240 returns 0 when model-specific and common-model descriptors both miss; this attempt does not prove scene failure"
            row["full_visual_target_status"] = "appearance fidelity unverified until a descriptor is selected and loaded"
        nodes.append(row)
        return ident

    scene_results = []
    descriptor_results = {}
    for quest, scene_idx, func in SCENES:
        key = f"Q{quest}/{scene_idx}"
        member = f"Event/Sequences/{func}.seq"
        raw = read("06-Event.stp", member)
        name, calls, token_count = whole_function(raw.decode("utf-8-sig"), h)
        require(name == func, "scene function mismatch")
        selectors = [dict(n.attrib) for n in scene_root.iter() if h.attrs(n).get("questidx") == str(quest) and h.attrs(n).get("sceneidx") == str(scene_idx)]
        require(len(selectors) == 1 and selectors[0]["funcName"] == func, "selector is not uniquely bound")
        src = {"carrier": "06-Event.stp", "member": member, "decoded_sha256": sha(raw)}
        seq_id = dep(key, "sequence", {"member": "Event/SceneList.xml", "row": selectors[0]},
                     {"namespace": "QuestScene", "quest": quest, "scene": scene_idx}, path=member,
                     proof="SceneList funcName -> Event/Sequences/<funcName>.seq; bounded Register name agrees")
        call_inventory = [{"ordinal": i, "line": c["line"], "function": c["function"], "arity": len(c["args"]),
                           "source_call_sha256": c["source_call_sha256"],
                           "class": "phase_global" if c["function"] in PHASES else "direct_native" if c["function"].startswith("Q.") else "coroutine_helper" if c["function"] == "wait" else "qbase_helper",
                           "dependency_disposition": "expanded" if c["function"] in RESOURCE else "runtime_context_and_lifecycle_contract"}
                          for i, c in enumerate(calls)]
        slot_rows = {}
        for c in calls:
            a, fn = c["args"], c["function"]
            if fn == "CreateObject":
                slot, model = int(a[0]) & 0xffff, int(a[1]) & 0xffff
                if slot in slot_rows:
                    raise ValueError("selected bounded scene now repeats a Create slot")
                slot_rows[slot] = {"slot_word": slot, "model_word": model, "source_line": c["line"],
                    "raw_initial_action": a[5], "collector_actions": {(1 if int(a[5]) == 0 else int(a[5])) & 0xffff},
                    "formal_implicit_actions": [1, 4], "formal_implicit_condition": "model+0x70 and materialized resource exist; a request is not success",
                    "avatar_parameter": a[7], "explicit_item_word": int(a[8]) & 0xffff,
                    "symbolic_show_argument": a[6],
                    "baseline_FALSE_value": {"lua_type": "number", "value": 0, "qbase_helper_isVisible_number": 1, "native_integer32_result": 1, "condition": "published Boot initialization succeeds and binding is not subsequently overwritten; see sibling ABI adoption"},
                    "action_sources": [{"line": c["line"], "function": fn}]}
            elif fn in ("WalkObject", "AniObject"):
                slot = int(a[0]) & 0xffff
                require(slot in slot_rows, "action before selected scene Create")
                if fn == "WalkObject":
                    # This is the separate 55CED0 native PREPASS callback:
                    # 55D188 test / 55D18A jns / 55D18C mov4. Formal qbase
                    # helper P26 replaces exactly -1, not every negative.
                    action = (4 if int(a[5]) < 0 else int(a[5])) & 0xffff
                    collected = int(a[4]) != 0
                else:
                    action, collected = int(a[1]) & 0xffff, True
                if collected:
                    slot_rows[slot]["collector_actions"].add(action)
                slot_rows[slot]["action_sources"].append({"line": c["line"], "function": fn, "action_word": action,
                                                        "collected": collected, "gate": a[4] if fn == "WalkObject" else None,
                                                        "layer": "native_prepass_callback; not formal qbase helper"})
        for row in slot_rows.values():
            row["collector_actions"] = sorted(row["collector_actions"])
            row["required_action_ids"] = sorted(set(row["collector_actions"]) | {1, 4})

        models = []
        for model in sorted({r["model_word"] for r in slot_rows.values()}):
            catalog = []
            effective = None
            for ci, cat in enumerate(actor_root):
                ca = h.attrs(cat)
                if h.ascii_key(cat.tag) != "objcategory":
                    continue
                for ri, actor in enumerate(cat):
                    aa = h.attrs(actor)
                    if h.ascii_key(actor.tag) != "actor" or aa.get("id") != str(model):
                        continue
                    admitted = int(ca["id"]) != 3
                    catalog.append({"category_id": int(ca["id"]), "category_ordinal": ci,
                                    "row_ordinal": ri, "pre_as_source_metadata_only": aa.get("pre"),
                                    "file": aa.get("file"), "admitted": admitted})
                    if admitted:
                        effective = aa["file"]
            require(effective is not None, "selected model has no admitted ActorList file")
            base_name = effective+".abf"
            wanted = sorted({a for r in slot_rows.values() if r["model_word"] == model for a in r["required_action_ids"]})
            mid = dep(key, "model_descriptor", {"member": "Table/_ActorList.xml", "matching_rows": catalog},
                      {"namespace": "QModelLowWord", "value": model, "PRE": "NOT_A_KEY_FIELD", "effective_file_stem": effective},
                      basename=base_name, proof="Actor.ID map; category 3 excluded; later accepted ID overwrites FILE; FILE+.abf -> CHA_ABF -> selected entry.directory+entry.filename",
                      missing=["same-version CHA_ABF cache/scanned entry", "Master.stp AttachedPackage binding", "actual native descriptor selection/open"], parents=[seq_id])
            candidates = lookup(basename=base_name)["basename_candidates"]
            available = [c for c in candidates if c["carrier"] == "Base.stp"]
            modelrow = {"model_word": model, "slots": sorted(s for s, r in slot_rows.items() if r["model_word"] == model),
                        "catalog_rows": catalog, "effective_file": effective, "required_actions": wanted,
                        "descriptor_dependency": mid, "descriptor_candidates": available,
                        "descriptor_status": "BLOCKED_MISSING_ORIGINAL_SOURCE", "native_selected_path": None}
            if len(available) == 1:
                dname = available[0]["member"]
                root = xml("Base.stp", dname)
                chars = h.elements(root, "Character")
                require(len(chars) == 1, "descriptor Character count differs")
                ch = chars[0]; ca = h.attrs(ch)
                actions = []
                for n in h.elements(ch, "Animation"):
                    aa = h.attrs(n)
                    if int(aa["id"]) in wanted:
                        actions.append({"id": int(aa["id"]), "file": aa["file"], "children": [{"tag": c.tag, "attributes": dict(c.attrib)} for c in n]})
                require({a["id"] for a in actions} == set(wanted), "selected animation declarations incomplete")
                modelrow["descriptor_status"] = "REAL_DESCRIPTOR_PARSED_RUNTIME_BINDING_BLOCKED"
                modelrow["descriptor_details"] = {"member": dname, "root": root.tag, "character_attributes": dict(ch.attrib),
                    "declared_animation_count": len(h.elements(ch, "Animation")), "selected_animations": actions,
                    "tag_counts": dict(sorted(Counter(n.tag for n in ch.iter()).items()))}
                descriptor_results[dname] = modelrow["descriptor_details"]
                symbolic_base = f"<selected CHA_ABF[{base_name.upper()}].directory>Avatar/{ca['relativepath']}"
                for role, filename in [("model_base_payload", ca["basefile"])]+[("model_texture", h.attrs(n)["file"]) for n in h.elements(ch, "Texture")]:
                    dep(key, role, {"carrier": "Base.stp", "member": dname}, {"model_word": model, "file": filename}, basename=filename,
                        proof="conditional base: selected CHA_ABF.directory + Avatar/ + RelativePath + BaseFile when resource+F4=0" if role == "model_base_payload" else "TextureList File -> resource+74 vector;7C5600 adds Texture/ to conditional base prefix;7C4310 appends File and submits key/path through FE1AE0",
                        missing=["actual selected descriptor directory", "referenced payload", "native format/semantic acceptance"], parents=[mid])
                    nodes[-1]["symbolic_requested_path"] = symbolic_base+("Texture/" if role == "model_texture" else "")+filename
                    nodes[-1]["symbolic_path_condition"] = "same parsed RelativePath descriptor and resource+F4=0; placeholder is not a concrete selected directory"
                for action in actions:
                    aid = dep(key, "animation_payload", {"carrier": "Base.stp", "member": dname}, {"model_word": model, "action": action["id"], "file": action["file"]}, basename=action["file"],
                        proof="default resource base prefix from7C5670; Ani/ helper7C5710; file extension/path branch remains explicitly conditional",
                        missing=["actual selected descriptor directory", "animation payload/format acceptance"], parents=[mid])
                    nodes[-1]["symbolic_requested_path"] = symbolic_base+"Ani/"+action["file"]
                    nodes[-1]["symbolic_path_condition"] = "same parsed descriptor, resource+F4=0 and the non-ASD animation branch; no alternate packed-format acceptance claimed"
                    for child in action["children"]:
                        aa = {k.lower(): v for k, v in child["attributes"].items()}
                        if "folder" in aa and "file" in aa:
                            dep(key, "animation_"+child["tag"].lower(), {"carrier": "Base.stp", "member": dname, "action": action["id"]},
                                {"model_word": model, "Folder": aa["folder"], "File": aa["file"]}, path=aa["folder"]+aa["file"],
                                proof="descriptor-declared Folder+File; declaration is not selected payload/open evidence",
                                missing=["referenced payload and any transitive declarations"], parents=[aid])
            else:
                nodes[-1]["missing"].append("descriptor bytes; transitive actions/meshes/textures/default-avatar children cannot yet be enumerated")
            models.append(modelrow)

        attachments = []
        default_items = []
        for model in sorted({r["model_word"] for r in slot_rows.values()}):
            default_key = (model + 31000) & 0xffff
            item = {"model_word": model, "derived_default_item_word": default_key, "variant_byte": 0, "type_byte": 0,
                    "attempt_only": True, "does_not_prove_descriptor_or_attachment_exists": True}
            item["dependency"] = dep(key, "default_appearance_item_catalog", {"native_chain": "562F8B->4C6FB0 A+88/A+8C;4C7E2D..58->7A4C50 D+18;4D101A..29"},
                item.copy(), path="Character/Cha/Items.ipk", proof="default item=(D.modelLowWord+0x7918)&0xffff ->7A7240; model-specific/common fallback uses the same appearance catalog",
                missing=["Items.ipk and recursive Include files", "matching optional default descriptor and attached payloads; lookup may miss"], parents=[seq_id])
            default_items.append(item)
        for row in slot_rows.values():
            if row["explicit_item_word"]:
                item = {"q_slot": row["slot_word"], "model_word": row["model_word"], "item_word": row["explicit_item_word"], "variant_byte": 0, "type_byte": 0}
                item["dependency"] = dep(key, "appearance_item_catalog", {**src, "line": row["source_line"]}, item.copy(),
                    path="Character/Cha/Items.ipk", proof="48CF01 ->7AC7E0 IPK/Include/ItemList/EffectList ->7ACA80; QCreate ->7A7240 model-specific key then common model0 fallback",
                    missing=["Items.ipk and recursive Include files", "matching descriptor/File and attached payloads"], parents=[seq_id])
                attachments.append(item)

        cameras, maps, talks, images, music, sounds, prologs = [], [], [], [], [], [], []
        for c in calls:
            fn, a = c["function"], c["args"]
            origin = {**src, "line": c["line"], "function": fn}
            if fn in ("PlayCamera", "PlayCameraNoWait"):
                path = "Event/CameraWorks/"+a[0]
                cid = dep(key, "camera", origin, {"name": a[0]}, path=path, proof="qbase helper -> Q camera binding -> Event/CameraWorks/ prefix", parents=[seq_id])
                cr = xml("06-Event.stp", path)
                cameras.append({"line": c["line"], "dependency": cid, "member": path, "root": cr.tag,
                                "framepos_tokens": [h.attrs(n)["framepos"] for n in cr.iter() if "framepos" in h.attrs(n)]})
            elif fn == "LoadMap":
                stem = a[0].rsplit(".", 1)[0]
                rows = [dict(n.attrib) for n in h.elements(map_root, "map") if h.attrs(n).get("map", "").lower() == stem.lower()]
                fid = dep(key, "field_descriptor", origin, {"basename": a[0], "group": "MAP_FLD"}, basename=a[0],
                    proof="563C40 ->7C1E00 basename+.fld -> MAP_FLD; parser v+4=7ED180 repeats group lookup;79C590/543500 concat entry.directory+filename ->72EE30/72F110",
                    missing=["same-version MAP_FLD cache/scanned entry", "Master mount", "FLD and its referenced geometry/environment payloads"], parents=[seq_id])
                bounds = []
                for name in sorted({r["BOUND"] for r in rows if r.get("BOUND")}):
                    path = "BoundMap/"+name+".bnd"
                    bid = dep(key, "world_bound_metadata", {"member": "Table/_MapList.xml", "matching_map_ids": [r["ID"] for r in rows if r.get("BOUND") == name]},
                        {"bound_stem": name}, path=path, proof="MapList BOUND join; Q.LoadMap does not thereby prove a BND load or select Server map ID", parents=[fid])
                    if path in archives["10-BoundMap.stp"].files:
                        raw_bound = read("10-BoundMap.stp", path)
                        bounds.append({"dependency": bid, "path": path, "bytes": len(raw_bound), "sha256": sha(raw_bound)})
                nearby = []
                if key == "Q2440/5":
                    # Deliberately not a general rule stripping S/D suffixes.
                    # These separately named records are candidates, NOT edges
                    # proven to be requested by Q.LoadMap(town014S.fld).
                    nearby_sys = [dict(n.attrib) for n in h.elements(sys_map_root, "map") if h.attrs(n).get("map") == "town014"]
                    path = "BoundMap/town014.bnd"
                    bb = read("10-BoundMap.stp", path)
                    nearby = [{"system_map_rows": nearby_sys, "system_map_source": "Table/_SysMapList.xml", "bound_member": path,
                               "bound_bytes": len(bb), "bound_sha256": sha(bb), "edge_to_town014S_proven": False,
                               "reason": "different MAP literal; no S-suffix removal or BND selection rule inferred"}]
                maps.append({"line": c["line"], "dependency": fid, "argument": a[0], "maplist_rows": rows,
                             "selected_map_id": None, "bound_evidence": bounds, "unjoined_nearby_name_candidates": nearby, "server_runtime_instance": None})
            elif fn == "OpenTalkScene":
                matches = [n for n in talk_root.iter() if h.attrs(n).get("id") == str(a[0]) and h.attrs(n).get("scene") == str(a[1])]
                require(len(matches) == 1, "scenario talk selector not unique")
                dialogrows = [dict(n.attrib) for n in h.elements(matches[0], "Talk")]
                detail = []
                for i, row in enumerate(dialogrows):
                    require(("char" in row) != ("npc" in row), "talk row kind is ambiguous")
                    display_kind = "char" if "char" in row else "npc"
                    char, talkid = int(row[display_kind]), int(row["talk"])
                    texts = all_talks[talkid]
                    require(bool(texts), "talk key absent from active tables")
                    require(len(texts) == 1, "selected talk key is not uniquely represented in the active tables")
                    tid = dep(key, "talk_text", {"member": "Table/ScenarioTalkTable.xml", "scenario": a[0], "scene": a[1], "talk_ordinal": i},
                        {"namespace": "TalkKey", "value": talkid, "display_actor_key": char}, path=texts[0]["member"],
                        proof="ScenarioTalk -> unique current-source active TalkTableSet PATH table and talk id; text hashes retained instead of story text", parents=[seq_id])
                    npcs = [dict(n.attrib) for n in npc_root.iter() if h.attrs(n).get("id") == str(char)]
                    did = dep(key, "display_actor_portrait", {"member": "Table/ScenarioTalkTable.xml", "talk_key": talkid},
                        {"namespace": "DisplayActor", "value": char, "text_face_attributes": [x["attributes"].get("face") for x in texts]}, path="Image/TalkNPC.xml",
                        proof="NPC base/display extension key; portrait/face needs actual extension and image resources",
                        missing=["TalkNPC.xml extension and selected face/portrait payloads"], parents=[tid])
                    vid = dep(key, "talk_voice", {"member": "Table/ScenarioTalkTable.xml", "talk_key": talkid},
                        {"talk_key": talkid, "version_order": list(range(32, -1, -1)), "locale_probe_template": "Sound/Scenario/%02d/Locale", "voice_template": f"Sound/Scenario/%02d/V{talkid:05d}.ogg", "alternate_extension": ".wav"},
                        proof="49FED0 versions32..0; two-byte JP Locale skips version;49FD10->80D230 Sound prefix and format probe; first resource result selected",
                        missing=["version Locale files", "voice payload candidates", "native selected voice/open result"], parents=[tid])
                    detail.append({"row": row, "source_kind": display_kind, "native_record_kind": 0 if display_kind == "char" else 1,
                                   "display_consumer_uses_key_without_kind_branch": True,
                                   "text_dependency": tid, "text_matches": texts, "display_dependency": did, "npctable_matches": npcs, "voice_dependency": vid})
                talks.append({"line": c["line"], "scenario_id": a[0], "scene_id": a[1], "rows": detail})
            elif fn == "FlyingObject":
                iid = dep(key, "direct_image", origin, {"path_literal": a[0]}, path=a[0], proof="FlyingObject -> Q.SpawnImage texture request", missing=["DDS payload"], parents=[seq_id])
                images.append({"line": c["line"], "path": a[0], "dependency": iid})
            elif fn == "PlayMusic":
                path = "Sound/"+a[0]
                aid = dep(key, "music", origin, {"name": a[0]}, path=path, proof="Sound base prefix; actual selected format/resource remains unobserved", missing=["audio payload"], parents=[seq_id])
                music.append({"line": c["line"], "dependency": aid, "path": path, "soundlist_rows": [line for line in sound_list.splitlines() if line.split()[-1:] == [path]]})
            elif fn == "PlaySound":
                path = a[0]
                aid = dep(key, "direct_sound", origin, {"literal": path}, path=path, proof="literal requested sound key; Sound declaration retained separately", missing=["audio payload"], parents=[seq_id])
                sounds.append({"line": c["line"], "dependency": aid, "path": path, "declarations": [dict(n.attrib) for n in h.elements(sound_root, "Sound") if h.attrs(n).get("file") == path.removeprefix("Sound/")]})
            elif fn == "DoProlog":
                candidates = [n for n in h.elements(prolog_root, "Prolog") if h.attrs(n).get("idx") == str(a[0])]
                require(len(candidates) == 1, "Prolog selector not unique")
                dialogs = []
                pid = dep(key, "prolog_table", origin, {"namespace": "PrologIdx", "value": a[0]}, path="Table/Prolog.xml", proof="513560 parses idx and Dialog rows; DoProlog -> Q.Prolog queue", parents=[seq_id])
                for i, dialog in enumerate(h.elements(candidates[0], "Dialog")):
                    path = h.attrs(dialog)["picturepath"]
                    lines = ["".join(n.itertext()) for n in h.elements(dialog, "Line")]
                    iid = dep(key, "prolog_picture", {"member": "Table/Prolog.xml", "idx": a[0], "dialog_ordinal": i},
                        {"PicturePath": path}, path=path, proof="row+1C PicturePath ->55F370->736B00 texture -> owner+8 ->55FC50 draw", missing=["DDS payload"], parents=[pid])
                    voice = f"Sound/Scenario/Prologue/P{a[0]:02d}_{i:02d}.ogg"
                    vid = dep(key, "prolog_voice", {"member": "Table/Prolog.xml", "idx": a[0], "dialog_ordinal": i},
                        {"prolog_idx": a[0], "ordinal": i}, path=voice, proof="row+38 ordinal;55F470->4A03F0 format Scenario/Prologue/P%02d_%02d.ogg -> Sound resource helper", missing=["voice payload", "native selected format"], parents=[pid])
                    dialogs.append({"ordinal": i, "line_count": len(lines), "text_lines_sha256": [sha(x.encode()) for x in lines], "picture": path, "picture_dependency": iid, "voice_candidate": voice, "voice_dependency": vid})
                prologs.append({"idx": a[0], "dependency": pid, "dialogs": dialogs, "unique_pictures": sorted({d["picture"] for d in dialogs})})
        scene_results.append({"key": key, "selector_rows": selectors, "sequence_source": src,
            "static_parse": {"accepted_scope": "entire single straight-line function plus matching Register; every token consumed", "token_count": token_count, "function_body_call_count": len(calls), "unconsumed_tokens": 0, "executed": False},
            "call_inventory": call_inventory, "slots": list(slot_rows.values()), "models": models, "explicit_attachment_items": attachments, "default_attachment_lookup_attempts": default_items,
            "cameras": cameras, "maps": maps, "talk_scenes": talks, "music": music, "sounds": sounds, "direct_images": images, "prologs": prologs,
            "empty_final_music": {"lines": [c["line"] for c in calls if c["function"] == "SetFinalMusic" and c["args"] == [""]], "meaning": "append0 retains current finalMusic; not an empty audio dependency or clear operation"},
            "implicit_context_frontiers": ["default item lookups are enumerated; matching descriptors and AvatarList children for missing models remain unavailable", "shared Q dialogue/prolog/image UI frames/fonts", "pre-existing finalMusic/map/camera/audio state and mounted/cache version"],
            "audit_scope_complete": True, "full_transitive_payload_enumeration_complete": False,
            "exact_runtime_selection_status": "BLOCKED_MISSING_ORIGINAL_SOURCE", "ready": False})

    # Recheck the bounded original world join, and retain it as a distinct namespace.
    zmeta = []
    for path in ["Table/QuestInfo.xml", "Table/_CaseList.xml", "Field/MapFlow/CHART_scenario_chicken_01.xml", "Field/Cluster/CLUST_scenario_chicken_01.xml"]:
        raw = zip_payloads[path]
        zmeta.append({"carrier": zpath.name, "member": zip_local[path], "decoded_length": len(raw), "decoded_sha256": sha(raw), "original_full_carrier_reverified": False})
    prior = json.loads((repo/"kr-extra-roy/MEF-comprehensive-contracts-20261117/resources/supplemental-audit.json").read_text())
    for p in zmeta:
        old = next(x for x in prior["zip_inventory"]["local_resource_metadata"] if x["path"] == p["member"])
        require(p["decoded_sha256"] == old["sha256"], "ZIP world join source changed")
    # Bind each dependency layer to the exact member read, without exporting
    # original content. Native-only source edges pin the target binary instead.
    def member_pin(meta):
        return {"carrier": meta["carrier"], "carrier_sha256": meta["carrier_sha256"],
                "decoded_sha256": meta["decoded_sha256"], "decoded_bytes": meta["decoded_length"], "block_id": meta["block_id"]}

    for node in nodes:
        source = node["source"]
        if "member" in source:
            candidates = [m for m in used.values() if m["path"] == source["member"] and ("carrier" not in source or m["carrier"] == source["carrier"])]
            require(len(candidates) == 1, "dependency source is not uniquely pinned: "+node["id"])
            source.update(member_pin(candidates[0]))
        elif "native_chain" in source:
            source["binary_sha256"] = next(p["sha256"] for p in manifest["originals"] if p["file"] == "02-Tartaros.bin")
            source["native_evidence_file"] = "native-evidence.json"
        for field in ("exact_members", "ascii_casefold_candidates", "basename_candidates"):
            for item in node["inventory"][field]:
                meta = used.get(item["carrier"]+":"+item["member"])
                if meta:
                    item.update(member_pin(meta))
    world = {"source": "same-byte ZIP members; prior bounded join reused", "source_members": zmeta,
             "original_data_join": prior["selected_data_join"],
             "Q_scene_to_world_entity_equivalence": False,
             "server_candidate_comparison": "See parent SERVER-ADOPTION.md; selectedCluster4/models1001,1001,1001,1022 is not original Cluster19/model1086 or a Q-slot identity."}
    frontier = []
    for node in nodes:
        if node["missing"] or node["inventory"]["inventory_status"] == "NOT_IN_SUPPLIED_INDEXES":
            frontier.append({"dependency": node["id"], "role": node["role"], "scene": node["scene"], "selector": node["selector"], "requested_path": node["inventory"]["requested_path"], "requested_basename": node["inventory"]["requested_basename"], "missing": node["missing"], "status": "BLOCKED_MISSING_ORIGINAL_SOURCE"})
    output = {"schema": "MEF_TWO_SCENE_CONTENT_AUDIT_V1", "classification": "RESEARCH_ONLY_NOT_NATIVE_MEF", "base_commit": BASE_COMMIT,
              "ready": False, "deployment_artifact": False, "parser_checks": parser_result,
              "inventory_scope": {"stp_members": {c: len(a.files) for c, a in archives.items()}, "zip_total_entries": len(zip_names), "zip_local_resource_entries": len(zip_local),
                                  "parsed_base_descriptor_count": len(descriptor_results), "not_all_base_members_parsed": True,
                                  "negative_inventory_does_not_prove_installed_absence": True},
              "talkset_scope": {"active_members": len(talk_members), "rows": sum(len(x) for x in all_talks.values()), "text_exported": False},
              "resolution_rules": {
                  "prepass_walk": {"callback": "55CED0 installed by 55D6A0", "gate": "numeric arg5=0 skips collection", "action": "signed native integer arg6<0 becomes4 before WORD truncation", "evidence": "reused bridge prepass_walk 55D17D..55D191", "formal_helper_is_distinct": "qbase P26 only replaces numeric -1 with4; see sibling ABI adoption"},
                  "actor_id_file_map": {"key": "Actor.ID", "excluded_category": 3, "PRE_used": False, "repeated_key": "last accepted FILE assignment wins", "evidence": "prior resource-selection/native-evidence.json"},
                  "file_index_basename": {"cache_entry_builder": "7198F0", "scan_builder": "718FB0", "normalization": "7198B0; default ASCII upper, locale-sensitive CRT branch retained", "duplicate_key": "first accepted entry retained; later new entry destroyed", "actual_entry_order_observed": False},
                  "package_mount": {"startup": "48BD30->713740", "root_carrier": "Master.stp", "embedded_name": "Master0z", "binding": "7135B0 AttachedPackage ->715620", "same_virtual_directory": "714D50 reuses case-insensitive directory; later successful AttachedPackage writes provider+100", "actual_master_and_mount_observed": False},
                  "package_read": {"path_lookup": "714C50", "member_lookup": "7155B0; native file node+11C equals member entry+44", "precedence": "mounted package hit before existing published loose-file fallback; fallback restrictions/prefix still apply", "native_filename_to_member_id_grammar_claimed": False},
                  "field_descriptor": {"group": "MAP_FLD", "selected_path_rule": "entry.directory + entry.filename", "consumer": "7ED180 ->79C590/543500 ->72F110 ->714770", "actual_entry_observed": False}
              },
              "scenes": scene_results, "dependency_nodes": nodes, "world_data_context": world}
    members = {"schema": "MEF_CONTENT_MEMBER_EVIDENCE_V1", "stp_members_read": [used[k] for k in sorted(used)], "zip_members_read": zmeta,
               "complete_original_members_exported": False}
    missing = {"schema": "MEF_CONTENT_FRONTIER_V1", "ready": False, "status": "BLOCKED_MISSING_ORIGINAL_SOURCE",
               "entry_count": len(frontier), "entries": frontier,
               "global_required_sources": ["same-version Master.stp (Master0z/AttachedPackage tree)", "same-version fcs.flu or exact generated CHA_ABF/MAP_FLD scan entries", "Character/Cha/Items.ipk and recursive Include/descriptor/payload carriers", "Image/TalkNPC.xml and selected portrait/face images", "actual model/animation/texture/effect/FLD/audio/image payloads", "installed version, package/loose-file roots, cache and resource overrides"],
               "shared_context_frontiers": ["UI frames/font resources and persistent map/camera/audio state are inherited context, not silently satisfied by scene file existence", "missing 13 model descriptors prevent an exhaustive descendant list; manifest records every reached frontier rather than inventing children"]}
    return {"scene-dependencies.json": output, "member-evidence.json": members, "dependency-frontier.json": missing}


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--repo", required=True, type=Path)
    ap.add_argument("--sources", required=True, type=Path)
    ap.add_argument("--supplemental", required=True, type=Path)
    ap.add_argument("--output", required=True, type=Path)
    args = ap.parse_args()
    args.output = check_output_directory(args.output, args.repo, args.sources, args.supplemental)
    result = audit(args.repo, args.sources, args.supplemental)
    args.output.mkdir(parents=True, exist_ok=True)
    for name, value in result.items():
        dump(args.output/name, value)
    print(json.dumps({"status": "AUDIT_COMPLETE_WITH_EXPLICIT_FRONTIERS", "ready": False,
                      "scene_count": len(result["scene-dependencies.json"]["scenes"]),
                      "dependency_nodes": len(result["scene-dependencies.json"]["dependency_nodes"])}, ensure_ascii=False))


if __name__ == "__main__":
    main()
