#!/usr/bin/env python3
"""Read-only P0-9/10 evidence replay; never executes game, Lua or Server code.

Only an explicitly named --receipt is written. Evidence is compared, not rebuilt.
Python, jsonschema and GNU objdump are required. Run without -O.
"""
import argparse
from collections import deque
import hashlib
import importlib.util
import json
import math
from pathlib import Path
import re
import struct
import subprocess
import sys
import xml.etree.ElementTree as ET

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent


def require(ok, message):
    if not ok:
        raise ValueError(message)


def sha(data):
    return hashlib.sha256(data).hexdigest()


def canonical(obj):
    return json.dumps(obj, ensure_ascii=False, sort_keys=True, indent=2) + "\n"


def read_json(path):
    return json.loads(path.read_text(encoding="utf-8"))


def module(path, name):
    spec = importlib.util.spec_from_file_location(name, path)
    result = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(result)
    return result


def identities(repo, sources, server_sources, manifest):
    baseline = manifest["baseline_commit"]
    for item in manifest["git_sources"]:
        blob = subprocess.check_output(["git", "rev-parse", baseline + ":" + item["path"]], cwd=repo, text=True).strip()
        require(blob == item["git_blob"], "Git path/blob changed: " + item["path"])
        data = subprocess.check_output(["git", "cat-file", "blob", blob], cwd=repo)
        require(len(data) == item["bytes"] and sha(data) == item["sha256"], "Git source bytes: " + item["path"])
        if item.get("worktree_input"):
            require((repo / item["path"]).read_bytes() == data, "Worktree input drift: " + item["path"])
    for item in manifest["originals"]:
        data = (sources / item["path"]).read_bytes()
        require(len(data) == item["bytes"] and sha(data) == item["sha256"], "Original identity: " + item["path"])
    for item in manifest["server_sources"]["files"]:
        data = (server_sources / item["path"]).read_bytes()
        require(len(data) == item["bytes"] and sha(data) == item["sha256"], "Server source bytes: " + item["path"])
        blob = hashlib.sha1(b"blob " + str(len(data)).encode("ascii") + b"\0" + data).hexdigest()
        require(blob == item["git_blob"], "Server blob identity: " + item["path"])
    return {"git_objects": len(manifest["git_sources"]), "originals": len(manifest["originals"]),
            "private_server_files": len(manifest["server_sources"]["files"])}


def native(binary, window_specs):
    data = binary.read_bytes()
    pe = struct.unpack_from("<I", data, 0x3c)[0]
    require(data[pe:pe + 4] == b"PE\0\0", "PE signature")
    count = struct.unpack_from("<H", data, pe + 6)[0]
    optlen = struct.unpack_from("<H", data, pe + 20)[0]
    base = struct.unpack_from("<I", data, pe + 52)[0]
    sections = [struct.unpack_from("<IIII", data, pe + 24 + optlen + 40 * i + 8) for i in range(count)]

    def at(va, length):
        rva = va - base
        matches = [raw + rva - rv for vs, rv, rs, raw in sections if rv <= rva and rva + length <= rv + rs]
        require(len(matches) == 1, "Unique VA mapping: " + hex(va))
        raw = matches[0]
        return raw, data[raw:raw + length]

    output, text_parts = [], []
    for spec in window_specs:
        start, end = int(spec["start"], 16), int(spec["end"], 16)
        raw, piece = at(start, end - start)
        item = dict(spec, raw=hex(raw), bytes=len(piece), sha256=sha(piece), hex=piece.hex())
        if spec.get("kind", "code") == "code":
            result = subprocess.check_output(["objdump", "-d", "-Mintel", "--insn-width=16",
                "--start-address=" + hex(start), "--stop-address=" + hex(end), str(binary)], text=True)
            instructions = []
            for line in result.splitlines():
                m = re.match(r"\s*([0-9a-f]+):\s*((?:[0-9a-f]{2} )+)\s*(.*)", line)
                if not m:
                    continue
                va, rawhex, asm = int(m[1], 16), m[2].replace(" ", ""), m[3].strip()
                require("(bad)" not in asm and ".byte" not in asm, "Complete instruction window: " + spec["id"])
                instructions.append((va, bytes.fromhex(rawhex), asm))
            cursor = start
            for va, rawbytes, asm in instructions:
                require(va == cursor and piece[va - start:va - start + len(rawbytes)] == rawbytes,
                        "Native decode/raw identity: " + spec["id"])
                cursor += len(rawbytes)
            require(cursor == end, "Native window exact extent: " + spec["id"])
            text_parts += ["# " + spec["id"] + " " + hex(start) + ".." + hex(end),
                           *[f"{va:08x}  {bb.hex():32}  {asm}" for va, bb, asm in instructions], ""]
            if spec["id"] == "N03-region-scan-and-base-return":
                tail = [(va, asm) for va, bb, asm in instructions if va >= 0x832e1a]
                require(not any("[ebp-0x4]" in asm for va, asm in tail), "Region local unexpectedly reused")
                require(sum(asm.startswith("ret") for va, asm in tail) == 3, "Base-only return branches")
            item["instruction_count"] = len(instructions)
        output.append(item)
    require(struct.unpack("<I", at(0xc0c8c4 + 0x2c, 4)[1])[0] == 0x4d1250, "CEventObject parameter vtable")
    require(struct.unpack("<I", at(0xc0c8c4 + 0x30, 4)[1])[0] == 0x4d1370, "CEventObject initializer vtable")
    require(struct.unpack("<I", at(0x4aed90 + 7 * 4, 4)[1])[0] == 0x4ae8d6, "type7 factory branch")
    require(struct.unpack("<I", at(0xc0c8c0, 4)[1])[0] == 0xc6ac18, "CEventObject COL pointer")
    require(struct.unpack("<I", at(0xc6ac18 + 12, 4)[1])[0] == 0xf7e854, "CEventObject type descriptor pointer")
    require(at(0xf7e854 + 8, 19)[1] == b".?AVCEventObject@@\0", "Native RTTI class name")
    require(struct.unpack("<d", at(0xc55ba8, 8)[1])[0] == struct.unpack("<f", struct.pack("<f", 0.8))[0],
            "Category0 native radius multiplier")
    return {"schema": "MEF_P0_GATE_NATIVE_WINDOWS_V1", "binary_sha256": sha(data), "windows": output}, "\n".join(text_parts)


def cell_digest(cells):
    return sha(b"".join(struct.pack("<I", c) for c in sorted(cells)))


def geometry(repo, sources, manifest):
    reader = module(repo / manifest["helpers"]["stp"], "gate_stp")
    helper = module(repo / manifest["helpers"]["geometry"], "gate_geometry")
    table, bounds = reader.STP(sources / "07-Table.stp"), reader.STP(sources / "10-BoundMap.stp")
    maps, map_meta = table.get("Table/_MapList.xml")
    row = next(x.attrib for x in ET.fromstring(maps) if x.attrib.get("ID") == "635")
    data, meta = bounds.get("BoundMap/" + row["BOUND"] + ".bnd")
    bound = helper.Bound(data, meta)
    original = read_json(repo / "design/scenario-content/story-q119-region-hold.scenario.json")["definitions"][0]["nodes"][-1]
    clear = read_json(HERE / "candidate-clear-delay.scenario.json")
    held = read_json(HERE / "candidate-region-hold.scenario.json")
    import jsonschema
    schema = read_json(repo / "design/scenario-content/local-scenario-definition.schema.json")
    jsonschema.validate(clear, schema)
    jsonschema.validate(held, schema)
    node = held["definitions"][0]["nodes"][-1]
    require(node["map"] == 635 and node["spawn"] == original["spawn"] and node["encounters"] == original["encounters"],
            "Candidate preserves selected map/spawn/required encounters")
    require(node["signals"] == original["signals"], "Candidate hold signal changes")
    for candidate, source_name in [(clear, "story-q119-barrier.scenario.json"), (held, "story-q119-region-hold.scenario.json")]:
        baseline = read_json(repo / "design/scenario-content" / source_name)
        expected = json.loads(json.dumps(baseline))
        changed = expected["definitions"][0]["nodes"][-1]
        changed["portal"].update(x=431.5, y=401.5, radius=2)
        changed["barriers"][0].update(minX=427, minY=397, maxX=428, maxY=405)
        if "marker" in changed["barriers"][0]:
            changed["barriers"][0]["marker"].update(x=425.5, y=401.5, radius=1)
        require(candidate == expected, "Candidate has unexpected delta: " + source_name)
    extra = bound.overlay(node["barriers"])
    start, goal = bound.cell(node["spawn"]), bound.cell(node["portal"])
    opened = bound.flood(start, set())
    closed = bound.flood(start, extra)
    pocket = bound.flood(goal, extra)
    eight, pending = {start}, deque([start])
    while pending:
        cell = pending.popleft()
        x, y = cell % bound.w, cell // bound.w
        for dx, dy in [(1,0),(-1,0),(0,1),(0,-1),(1,1),(1,-1),(-1,1),(-1,-1)]:
            xx, yy = x + dx, y + dy
            nxt = yy * bound.w + xx
            if 0 <= xx < bound.w and 0 <= yy < bound.h and nxt not in eight and not bound.blocked[nxt] and nxt not in extra:
                eight.add(nxt)
                pending.append(nxt)
    require(goal not in eight and goal in opened and len(extra) == 8, "True separation candidate")
    require(opened == closed | pocket | extra and not closed & pocket, "Exact component partition")

    def circle(point, radius):
        cells = set()
        for y in range(math.floor(point["y"] - radius) - 1, math.ceil(point["y"] + radius) + 1):
            for x in range(math.floor(point["x"] - radius) - 1, math.ceil(point["x"] + radius) + 1):
                dx = max(x - point["x"], 0, point["x"] - (x + 1))
                dy = max(y - point["y"], 0, point["y"] - (y + 1))
                if dx * dx + dy * dy <= radius * radius + 1e-12:
                    require(0 <= x < bound.w and 0 <= y < bound.h, "Circle inside map")
                    cells.add(y * bound.w + x)
        require(bound.w == bound.wx and bound.h == bound.wy, "This exact cell/disk cover assumes unit cells")
        return {"center": [point["x"], point["y"]], "radius": radius,
                "conservative_disk_intersecting_cells": len(cells), "cells_sha256": cell_digest(cells),
                "static_blocked": sum(bool(bound.blocked[c]) for c in cells),
                "closed_spawn_side": len(cells & closed), "closed_eight_neighbor_spawn_side": len(cells & eight),
                "closed_exit_side": len(cells & pocket), "overlay": len(cells & extra)}

    native_multiplier = struct.unpack("<f", struct.pack("<f", 0.8))[0]
    native_radius = struct.unpack("<f", struct.pack("<f", native_multiplier * node["portal"]["radius"]))[0]
    circles = {"exit_server": circle(node["portal"], 2), "exit_client": circle(node["portal"], native_radius),
               "region_hold": circle(node["signals"][0]["region"], 2),
               "barrier_marker": circle(node["barriers"][0]["marker"], 1)}
    for name, value in circles.items():
        require(value["static_blocked"] == value["overlay"] == 0, "Whole-circle blocked cell: " + name)
        side = "closed_exit_side" if name.startswith("exit_") else "closed_spawn_side"
        require(value[side] == value["conservative_disk_intersecting_cells"], "Whole-circle ownership: " + name)

    def route(point, overlay):
        witness = bound.route_witness(node["spawn"], point, overlay)
        require(witness is not None and all(s["blocked_samples"] == 0 for s in witness["segments"]), "Required point path")
        checked = set()
        corners = witness["cell_center_corners"]
        for a, b in zip(corners, corners[1:]):
            require(a["x"] == b["x"] or a["y"] == b["y"], "Axis aligned grid route")
            for y in range(math.floor(min(a["y"], b["y"])), math.floor(max(a["y"], b["y"])) + 1):
                for x in range(math.floor(min(a["x"], b["x"])), math.floor(max(a["x"], b["x"])) + 1):
                    c = y * bound.w + x
                    require(not bound.blocked[c] and c not in overlay, "Continuous centerline cell route")
                    checked.add(c)
        witness["whole_axis_segment_cells_checked"] = len(checked)
        return witness

    points = {"monster_" + str(i): p for i, p in enumerate(node["encounters"])}
    points.update(region_hold=node["signals"][0]["region"], barrier_marker=node["barriers"][0]["marker"],
                  gate_approach={"x": 426.5, "y": 401.5})
    routes = {name: route(p, extra) for name, p in points.items()}
    routes["exit_open"] = route(node["portal"], set())
    old_extra = bound.overlay(original["barriers"])
    return {"schema": "MEF_P0_GATE_GEOMETRY_V1", "map_row": row, "bound": bound.metadata,
        "policy": "Server layer0/1 nonzero union; point movement; all diagonal neighbors admitted for closed separation check",
        "map_member": {k:v for k,v in map_meta.items() if k != "prefix"},
        "original": {"portal": original["portal"], "barriers": original["barriers"],
                     "closed_bypass": bound.route_witness(original["spawn"], original["portal"], old_extra)},
        "candidate": {"spawn": node["spawn"], "portal": node["portal"], "barriers": node["barriers"],
            "native_category0_multiplier": native_multiplier,
            "overlay_cells": len(extra), "overlay_cells_originally_walkable": sum(not bound.blocked[c] for c in extra),
            "open_component_cells": len(opened), "closed_spawn_cells": len(closed), "closed_exit_cells": len(pocket),
            "closed_eight_neighbor_spawn_cells": len(eight), "closed_exit_reachable": goal in eight,
            "closed_component_sha256": cell_digest(closed), "pocket_sha256": cell_digest(pocket),
            "circles": circles, "routes": routes,
            "gate_crossing_open": bound.segment(points["gate_approach"], node["portal"]),
            "gate_crossing_closed": bound.segment(points["gate_approach"], node["portal"], extra)},
        "limits": ["No Client execution, mesh or actor-radius validation", "Candidate files are not installed", "No claim that CEventObject animation changes collision"]}


def resources(repo, sources, manifest):
    reader = module(repo / manifest["helpers"]["stp"], "gate_resource_stp")
    table = reader.STP(sources / "07-Table.stp")
    objects, obj_meta = table.get("Table/EventObjects.xml")
    actors, actor_meta = table.get("Table/_ActorList.xml")
    portals, portal_meta = table.get("Table/_PortalList.xml")
    states = {o.attrib["ID"]: [s.attrib for s in o] for o in ET.fromstring(objects).findall("./OBJECTS/OBJ")}
    matches, unmatched = [], []
    for category in ET.fromstring(actors):
        for obj in category:
            row = obj.attrib
            if category.attrib.get("ID") != "7" or not any(word in row.get("FILE", "").lower() for word in ("door", "gate")):
                continue
            item = {"model": int(row["ID"]), "actor_category": 7, "actor_row": row,
                    "declared_states": states.get(row["ID"], []), "state_names_known": False,
                    "collision_toggle_proven": False}
            (matches if row["ID"] in states else unmatched).append(item)
    return {"schema": "MEF_GATE_RESOURCE_JOIN_V1", "members": [{k:v for k,v in m.items() if k != "prefix"}
              for m in (obj_meta, actor_meta, portal_meta)], "event_objects": len(states),
            "event_states": sum(map(len, states.values())), "gate_named_models_with_states": matches,
            "gate_named_models_without_event_state_row": unmatched,
            "portal_effect_rows": [e.attrib for e in ET.fromstring(portals).iter() if e.attrib],
            "scope": "Exact table join and native consumer, not model-file availability or open/closed motion semantics"}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--repo", type=Path, default=HERE.parents[2])
    parser.add_argument("--sources", type=Path, required=True)
    parser.add_argument("--server-sources", type=Path, required=True)
    parser.add_argument("--receipt", type=Path)
    args = parser.parse_args()
    require(not sys.flags.optimize, "Run without -O")
    manifest = read_json(HERE / "source-manifest.json")
    checked = identities(args.repo, args.sources, args.server_sources, manifest)
    for item in read_json(HERE / "artifact-manifest.json")["files"]:
        data = (HERE / item["path"]).read_bytes()
        require(len(data) == item["bytes"] and sha(data) == item["sha256"], "Package artifact identity: " + item["path"])
    result, asm = native(args.sources / "02-Tartaros.bin", manifest["native_windows"])
    require(result == read_json(HERE / "native-evidence.json"), "Native evidence differs")
    require(asm == (HERE / "native-evidence.asm").read_text(encoding="utf-8"), "Native disassembly differs")
    geo = geometry(args.repo, args.sources, manifest)
    require(geo == read_json(HERE / "geometry-evidence.json"), "Geometry evidence differs")
    resource = resources(args.repo, args.sources, manifest)
    require(resource == read_json(HERE / "resource-evidence.json"), "Resource evidence differs")
    receipt = {"schema": "MEF_P0_GATE_VERIFY_RECEIPT_V1", "status": "PASS", "baseline": manifest["baseline_commit"],
               "server_commit": manifest["server_sources"]["commit"], "identity_checks": checked,
               "native_windows": len(result["windows"]), "gate_model_joins": len(resource["gate_named_models_with_states"]),
               "closed_exit_reachable": geo["candidate"]["closed_exit_reachable"],
               "open_exit_route_steps": geo["candidate"]["routes"]["exit_open"]["steps"],
               "readonly_analysis_only": True, "gameplay_or_server_execution": False}
    if args.receipt:
        args.receipt.write_text(canonical(receipt), encoding="utf-8")
    print(canonical(receipt), end="")


if __name__ == "__main__":
    main()
