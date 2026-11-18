#!/usr/bin/env python3
"""Read-only Master/STP analysis. Never executes target code or extracted content.

PackingRules below is an observed, fully consumed data layout for the pinned
Master only. It is not a native MEF parser or an authoring/packing specification.
Only metadata, selected joins and derived contracts are exported.
"""
from __future__ import annotations
import argparse
from collections import Counter, defaultdict
import hashlib
import importlib.util
import json
from pathlib import Path
import struct
import subprocess
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
PRIOR = "kr-extra-roy/MEF-P0-content-contracts-20261117/content-dependencies/"
READER = "kr-extra-roy/MEF-world-identity-scene-interaction-20261117/stp_reader.py"
BASE = "5ed4833b805949fabe260aea77e3fe0fd8e86bfa"


def sha(b):
    return hashlib.sha256(b).hexdigest()


def require(ok, why):
    if not ok:
        raise ValueError(why)


def key(s):
    require(s.isascii(), "ASCII source names required by this bounded analysis")
    return s.replace("\\", "/").strip("/").lower()


def load_json(p):
    return json.loads(Path(p).read_text(encoding="utf-8"))


def dump(p, value):
    p = Path(p)
    require(not p.is_symlink(), "output symlink rejected")
    p.write_text(json.dumps(value, ensure_ascii=False, indent=2)+"\n", encoding="utf-8")


def check_output(out, repo, sources, supplemental):
    out = out.resolve()
    for source in [sources.resolve(), supplemental.resolve()]:
        require(out != source and source not in out.parents and out not in source.parents,
                "output overlaps original source tree")
    repo = repo.resolve()
    require(out != repo and (repo not in out.parents or out == HERE or HERE in out.parents),
            "repository output restricted to this analysis subpackage")
    return out


def sources_checked(repo, sources, supplemental):
    require(not sys.flags.optimize, "do not use Python -O: reused STP parser has assertions")
    manifest = load_json(HERE/"source-manifest.json")
    for p in manifest["originals"]:
        root = supplemental if p["group"] == "supplemental" else sources
        b = (root/p["file"]).read_bytes()
        require(len(b) == p["bytes"] and sha(b) == p["sha256"], "original differs: "+p["file"])
    for p in manifest["published_pins"]:
        ref = p["source_commit"]+":"+p["path"]
        b = subprocess.check_output(["git", "show", ref], cwd=repo)
        blob = subprocess.check_output(["git", "rev-parse", ref], cwd=repo, text=True).strip()
        require(blob == p["git_blob"] and sha(b) == p["sha256"] and len(b) == p["bytes"],
                "published pin differs: "+p["path"])
        if p.get("loaded_by_analyzer"):
            require((repo/p["path"]).read_bytes() == b, "loaded helper differs from pinned Git source")
    spec = importlib.util.spec_from_file_location("master_stp_reader", repo/READER)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module.STP, manifest


def index_tree(raw):
    """Independent bounded index walk, retaining directory order and metadata."""
    require(raw[:4] == b"STPD", "Master STPD header")
    b = bytes(v ^ 255 for v in raw)
    index = struct.unpack_from("<I", b, 4)[0]
    require(16 <= index < len(b)-8 and raw[index:index+4] == b"STPI", "Master STPI bounds")
    pos = index+8
    nodes, files = [], {}

    def take(n):
        nonlocal pos
        require(0 <= n <= len(b)-pos, "truncated STPI field")
        out = b[pos:pos+n]
        pos += n
        return out

    def walk(parent, depth=0):
        require(depth < 128, "unexpected Master tree depth")
        start = pos
        size = struct.unpack("<H", take(2))[0]
        name = take(size).decode("ascii").rstrip("\0")
        require(name and "\0" not in name and "/" not in name and "\\" not in name,
                "unexpected index node name")
        kind = take(1)[0]
        path = "/".join(filter(None, [parent, name]))
        row = {"ordinal": len(nodes), "path": path, "kind": kind, "index_offset": start}
        nodes.append(row)
        if kind in (1, 2):
            count, unknown1, unknown2 = struct.unpack("<III", take(12))
            row.update(child_count=count, unassigned_dwords=[unknown1, unknown2])
            require(count <= len(b)-pos, "impossible child count")
            for _ in range(count):
                walk(path, depth+1)
        elif kind == 0:
            a, ident, c, d = struct.unpack("<IIII", take(16))
            require(path not in files, "duplicate exact member name")
            files[path] = ident
            row.update(block_id=ident, unassigned_dwords=[a, c, d])
        else:
            raise ValueError("unexpected STPI kind")
        row["subtree_end"] = pos

    walk("")
    require(pos == len(b), "unconsumed Master index bytes")
    require(nodes[0]["path"] == "Master0z" and nodes[0]["kind"] == 2, "Master root identity")
    return nodes, files, index


def packing_rules(b):
    """Observed 897-record layout: count, two strings, two bytes, eight strings."""
    require(len(b) >= 4, "PackingRules header")
    count = struct.unpack_from("<I", b)[0]
    require(count <= len(b)//22, "PackingRules count bounds")
    pos = 4

    def string():
        nonlocal pos
        require(pos+2 <= len(b), "PackingRules string length")
        n = struct.unpack_from("<H", b, pos)[0]
        pos += 2
        require(n <= len(b)-pos, "PackingRules string bounds")
        s = b[pos:pos+n].decode("ascii")
        pos += n
        require("\0" not in s, "PackingRules unexpected embedded NUL")
        return s

    rows = []
    for i in range(count):
        start = pos
        package, directory = string(), string()
        require(pos+2 <= len(b), "PackingRules two flag bytes")
        flags = list(b[pos:pos+2])
        pos += 2
        extensions = [string() for _ in range(8)]
        rows.append({"ordinal": i, "offset": start, "end": pos,
                     "row_sha256": sha(b[start:pos]), "package": package,
                     "source_directory": directory, "unassigned_flag_bytes": flags,
                     "extensions": extensions})
    require(pos == len(b), "unconsumed PackingRules bytes")
    return rows


def route_candidates(path, bindings):
    """Providers on this path in native parent-before-child lookup order.

    A parent provider miss permits a child attempt. This is deliberately NOT
    'longest prefix wins' and never claims an unavailable provider opened.
    """
    norm = key(path)
    return [r for r in sorted(bindings, key=lambda r: (r["virtual_directory"].count("/"), r["ordinal"]))
            if norm.startswith(key(r["virtual_directory"])+"/")]


def compact_binding(r):
    return {k: r[k] for k in ["ordinal", "virtual_directory", "carrier_path", "member",
                             "decoded_sha256", "packing_rule_ordinal", "packing_rule_sha256"]}


def analyze(repo, sources, supplemental):
    STP, manifest = sources_checked(repo, sources, supplemental)
    master_path = sources/"11-Master.stp"
    master = STP(master_path)
    nodes, files, index = index_tree(master_path.read_bytes())
    require(files == master.files, "independent index traversal differs from pinned reader")
    require(len(set(files.values())) == len(files) == len(master.blocks), "Master unique ID/block coverage")
    used, bodies = [], {}
    for path in files:
        body, meta = master.get(path)
        require(not body.startswith(b"EX"), "unexpected Master payload requires independent decode extension")
        bodies[path] = body
        meta = dict(meta)
        meta.pop("prefix", None)
        used.append(meta)
    rules = packing_rules(bodies["Master0z/PackingRules"])
    by_package = defaultdict(list)
    for r in rules:
        by_package[key(r["package"])].append(r)
    bindings = []
    for ordinal, (name, body) in enumerate(bodies.items()):
        if not name.endswith("/AttachedPackage"):
            continue
        package = body.decode("ascii")
        require(0 < len(body) < 512 and "\0" not in package, "native mount buffer contract")
        directory = name[len("Master0z/"):-len("/AttachedPackage")]
        matching = by_package[key(package)]
        require(len(matching) == 1, "binding must match exactly one PackingRules row")
        rule = matching[0]
        require(key(rule["source_directory"]) == key(directory), "packing rule directory differs")
        bindings.append({"ordinal": ordinal, "virtual_directory": directory,
                         "carrier_path": package.replace("\\", "/")+".stp", "member": name,
                         "decoded_sha256": sha(body), "packing_rule_ordinal": rule["ordinal"],
                         "packing_rule_sha256": rule["row_sha256"]})
    require(len(bindings) == len(rules) == 897 and len(bodies) == 899, "pinned Master counts")
    require(len({key(r["virtual_directory"]) for r in bindings}) == len(bindings), "duplicate virtual binding")
    require(len({key(r["carrier_path"]) for r in bindings}) == len(bindings), "duplicate carrier path")
    by_dir = {key(r["virtual_directory"]): r for r in bindings}
    dirs = [r for r in nodes if r["kind"] in (1, 2)]
    require(len({key(r["path"]) for r in dirs}) == len(dirs), "case-insensitive directory alias")

    prior = load_json(repo/PRIOR/"scene-dependencies.json")
    frontier = load_json(repo/PRIOR/"dependency-frontier.json")
    prior_members = load_json(repo/PRIOR/"member-evidence.json")
    models = [m for s in prior["scenes"] for m in s["models"]]
    model_map = {m["model_word"]: m for m in models}
    require(len(model_map) == 15, "prior scene model count")
    # Inventory evidence is used only to derive a conditional request. It does
    # not choose a CHA_ABF cache entry or treat the basename as a category ID.
    model_routes = []
    for m in models:
        matches = [r for r in bindings if "/avatar/" in key(r["virtual_directory"])
                   and key(r["virtual_directory"].rsplit("/", 1)[-1]) == key(m["effective_file"])]
        model_routes.append({"model_word": m["model_word"], "descriptor_basename": m["effective_file"]+".abf",
                             "catalog_namespace": "admitted Actor.ID -> FILE; PRE is not key",
                             "same_stem_avatar_mounts": [compact_binding(r) for r in matches],
                             "descriptor_directory_candidates": [r["virtual_directory"].split("/Avatar/")[0]+"/" for r in matches],
                             "status": "SEARCH_TARGET_ONLY_NOT_SELECTED_CHA_ABF_ENTRY",
                             "native_selected_path": None})

    archive_specs = [(sources/"06-Event.stp", "Event", "Event.stp"),
                     (sources/"07-Table.stp", "Table", "Table.stp"),
                     (sources/"10-BoundMap.stp", "Map/BoundMap", "Map/BoundMap.stp"),
                     (supplemental/"Base.stp", "Character/Mon", "Character/Mon/Base.stp")]
    supplied, original_members = {}, {}
    for path, directory, carrier in archive_specs:
        archive = STP(path)
        roots = {name.split("/", 1)[0] for name in archive.files}
        require(len(roots) == 1, "supplied carrier root count")
        root = next(iter(roots))
        require(key(root) == key(directory.rsplit("/", 1)[-1]), "carrier root does not match selected virtual directory")
        require(key(by_dir[key(directory)]["carrier_path"]) == key(carrier), "supplied carrier route differs")
        supplied[carrier] = {"source_file": path.name, "sha256": archive.sha,
                             "index_members": len(archive.files), "root": root,
                             "virtual_directory": directory,
                             "binding_status": "STRUCTURAL_ROOT_MATCH_CONDITIONAL_ON_DEPLOYMENT",
                             "actual_deployed_carrier_identity_observed": False}
        original_members[path.name] = archive
    # Re-read every prior selected member rather than trusting the old hash
    # ledger. No original member is exported.
    reread = []
    for entry in prior_members["stp_members_read"]:
        archive = original_members[entry["carrier"]]
        body, meta = archive.get(entry["path"])
        require(meta == entry, "prior member no longer matches: "+entry["path"])
        reread.append({"carrier": entry["carrier"], "path": entry["path"], "decoded_sha256": sha(body)})

    resolved = []
    for dep in prior["dependency_nodes"]:
        role, inv = dep["role"], dep["inventory"]
        paths, conditions = [], []
        if inv["requested_path"]:
            paths = [inv["requested_path"]]
            if role == "world_bound_metadata":
                paths = ["Map/"+inv["requested_path"]]
                conditions.append("mapping supplied archive root to declared mount; not proof Q.LoadMap requests BND")
        elif role == "model_descriptor":
            m = next(r for r in model_routes if r["model_word"] == dep["selector"]["value"])
            paths = [s+m["descriptor_basename"] for s in m["descriptor_directory_candidates"]]
            conditions.append("same-stem Master search target only; CHA_ABF selected entry remains missing")
        elif role in ["model_base_payload", "model_texture", "animation_payload"]:
            model = model_map[dep["selector"]["model_word"]]
            details = model.get("descriptor_details")
            require(details is not None, "payload node without source descriptor")
            # Both available descriptor members have Mon roots. The conditional
            # native prefix still requires the cache entry and R+F4==0.
            prefix = "Character/Mon/Avatar/"+details["character_attributes"]["RelativePath"]
            suffix = {"model_base_payload": "", "model_texture": "Texture/", "animation_payload": "Ani/"}[role]
            paths = [prefix+suffix+dep["selector"]["file"]]
            conditions.append("if CHA_ABF selects supplied Mon descriptor with directory Character/Mon/ and R+F4==0")
        elif role == "talk_voice":
            talk = dep["selector"]["talk_key"]
            paths = [f"Sound/Scenario/{v:02d}/V{talk:05d}.ogg" for v in range(32, -1, -1)]
            conditions.append("32..0 probe order; Locale JP skip and actual ogg/wav helper outcome remain required")
        else:
            conditions.append("MAP_FLD selected entry required; Field.stp xml/mef rule does not locate a .fld")
        paths_with_routes = [{"request": p, "variant": "original_reference", "providers_in_lookup_order": [compact_binding(r) for r in route_candidates(p, bindings)]} for p in paths]
        if role in ["model_texture", "direct_image", "prolog_picture"]:
            for p in paths:
                packed = p.rsplit(".", 1)[0]+".etf"
                paths_with_routes.append({"request": packed, "variant": "conditional_native_etf",
                                          "condition": "737D40: original714550 probe returns0; no fallback merely because original decode failed",
                                          "providers_in_lookup_order": [compact_binding(r) for r in route_candidates(packed, bindings)]})
        if role == "model_base_payload":
            for p in paths:
                packed = p.rsplit(".", 1)[0]+".emf"
                paths_with_routes.append({"request": packed, "variant": "conditional_native_emf",
                                          "condition": "7D0920 first physical load; FB79A8(manager+300)!=0 and original714550 probe=0",
                                          "providers_in_lookup_order": [compact_binding(r) for r in route_candidates(packed, bindings)]})
        resolved.append({"dependency": dep["id"], "role": role, "scene": dep["scene"],
                         "requests": paths_with_routes, "conditions": conditions,
                         "prior_referenced_candidate_bytes_present": bool(inv["exact_members"] or inv["basename_candidates"]),
                         "actual_native_selection_observed": False, "ready": False})

    # Only selected/relevant provider mappings are published. The complete
    # decoded AttachedPackage and PackingRules payloads remain local.
    selected_dirs = {"Field", "Event", "Table", "Map/BoundMap", "Map/MiniMap", "Character/Cha", "Character/Mon", "Character/Npc", "Character/Obj", "Image", "Image/Prologue", "Effect"}
    selected_dirs.update(r["virtual_directory"] for r in bindings if r["virtual_directory"].startswith("UI/"))
    selected_dirs.update(r["virtual_directory"] for row in model_routes for r in row["same_stem_avatar_mounts"])
    selected_dirs.update(r["virtual_directory"] for r in bindings if r["virtual_directory"].startswith("Sound/Scenario/"))
    selected = [compact_binding(r) for r in bindings if r["virtual_directory"] in selected_dirs]
    selected_rules = []
    for r in rules:
        if any(r["ordinal"] == b["packing_rule_ordinal"] for b in selected):
            selected_rules.append({"ordinal": r["ordinal"], "offset": r["offset"], "end": r["end"],
                                   "row_sha256": r["row_sha256"], "normalized_package": r["package"].replace("\\", "/")+".stp",
                                   "extensions": [s for s in r["extensions"] if s],
                                   "unassigned_flag_bytes": r["unassigned_flag_bytes"]})
    delta = []
    for entry in frontier["entries"]:
        gaps = [s for s in entry["missing"] if "master" in s.lower()]
        delta.append({"dependency": entry["dependency"], "role": entry["role"],
                      "superseded_missing_source_statements": gaps,
                      "new_master_result": "DECLARED_MOUNT_TREE_PARSED" if gaps else "NEW_ROUTING_CONTEXT_AVAILABLE",
                      "remaining_original_gaps": [s for s in entry["missing"] if s not in gaps],
                      "runtime_mount_and_cache_selection_observed": False,
                      "status": "BLOCKED_MISSING_ORIGINAL_SOURCE_OR_SELECTED_CONTEXT", "ready": False})
    require(len(delta) == 108 and len(resolved) == 132, "prior graph scope changed")
    extension_sets = Counter(tuple(s for s in r["extensions"] if s) for r in rules)
    summary = {
        "schema": "MEF_MASTER_RESOURCE_CLOSURE_V1", "classification": "RESEARCH_ONLY_NOT_NATIVE_MEF",
        "base_commit": BASE, "master_sha256": master.sha, "master_bytes": master_path.stat().st_size,
        "index_offset": index, "index_nodes": len(nodes), "file_members": len(files),
        "directories_excluding_root": len(dirs)-1, "attached_packages": len(bindings),
        "packing_rules": {"decoded_bytes": len(bodies["Master0z/PackingRules"]),
                          "decoded_sha256": sha(bodies["Master0z/PackingRules"]),
                          "rows": len(rules), "unconsumed_bytes": 0, "binding_joins": len(bindings),
                          "layout_status": "OBSERVED_DATA_LAYOUT_NOT_NATIVE_PARSER_CONTRACT",
                          "flag_semantics": "UNASSIGNED", "extension_sets": [{"extensions": list(k), "count": v} for k, v in sorted(extension_sets.items())]},
        "casefold_directory_duplicates": 0, "casefold_provider_duplicates": 0,
        "root_encflag_u32": struct.unpack("<I", bodies["Master0z/EncFlag"])[0],
        "root_encsetting_present": "Master0z/EncSetting" in bodies,
        "loader_encsetting_default": 1, "encflag_is_not_encsetting": True,
        "mef_evidence": {"member_files": [s for s in files if s.lower().endswith(".mef")],
                         "declared_carrier": "Field.stp", "declared_extensions": ["xml", "mef"],
                         "native_grammar_or_entry_proven": False},
        "lua_member_files": [s for s in files if s.lower().endswith(".lua")],
        "supplied_provider_candidates": supplied,
        "selected_mount_bindings": selected, "selected_packing_rule_facts": selected_rules,
        "lookup_policy": "parent provider first; child provider only after parent miss; no longest-prefix assumption",
        "resolved_source_gate": "MASTER_ORIGINAL_AND_DECLARED_MOUNT_TREE",
        "resource_ready": False, "actual_native_selection_observed": False,
        "full_transitive_payload_enumeration_complete": False, "target_execution": False,
        "complete_decoded_members_exported": False}
    return {
        "master-summary.json": summary,
        "master-member-evidence.json": {"schema": "MEF_MASTER_MEMBER_EVIDENCE_V1", "members": used, "complete_decoded_members_exported": False},
        "selected-resource-routes.json": {"schema": "MEF_MASTER_SELECTED_ROUTES_V1", "model_search_targets": model_routes, "dependency_count": len(resolved), "dependencies": resolved, "selected_source_members_rechecked": reread},
        "p0-frontier-delta.json": {"schema": "MEF_MASTER_P0_FRONTIER_DELTA_V1", "prior_frontier_entries": 108,
                                   "entries": delta, "remaining_blocked_entries": len(delta),
                                   "master_missing_statements_superseded": sum(bool(r["superseded_missing_source_statements"]) for r in delta),
                                   "missing_model_descriptor_payloads": 13,
                                   "native_payloads_added_by_master": 0, "resource_ready": False}}


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--repo", type=Path, required=True)
    ap.add_argument("--sources", type=Path, required=True)
    ap.add_argument("--supplemental", type=Path, required=True)
    ap.add_argument("--output", type=Path, required=True)
    args = ap.parse_args()
    out = check_output(args.output, args.repo, args.sources, args.supplemental)
    result = analyze(args.repo, args.sources, args.supplemental)
    out.mkdir(parents=True, exist_ok=True)
    for name, value in result.items():
        dump(out/name, value)
    print(json.dumps({"status": "GENERATED_BOUNDED_MASTER_ANALYSIS", "files": list(result), "resource_ready": False}))


if __name__ == "__main__":
    try:
        main()
    except (ValueError, OSError, UnicodeError, subprocess.CalledProcessError) as e:
        print(json.dumps({"status": "FAIL", "error": str(e)}), file=sys.stderr)
        sys.exit(1)
