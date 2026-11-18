#!/usr/bin/env python3
"""Read-only audit of the pinned authored scenario corpus and static BND geometry.

No game, Lua, Server, network, original-file write, or full decoded-member export.
The BND policy is the existing Server layer-0/1 nonzero union, not a claim about
native collision, dynamic actors, mesh geometry, or runtime acceptance.
"""
import argparse
from array import array
from collections import Counter, deque
import copy
import hashlib
import importlib.util
import json
import math
from pathlib import Path
import struct
import subprocess
import sys
import xml.etree.ElementTree as ET
import zlib


HERE = Path(__file__).resolve().parent
REPO = HERE.parents[2]


def sha(data):
    return hashlib.sha256(data).hexdigest()


def require(ok, message):
    if not ok:
        raise ValueError(message)


def read_json(path):
    return json.loads(path.read_text(encoding="utf-8"))


def canonical(obj):
    return json.dumps(obj, ensure_ascii=False, indent=2, sort_keys=True) + "\n"


def verify_sources(manifest):
    """Read cited documents from the fixed commit; strictly pin all live inputs.

    Mutable navigation documents may advance after this study. That must not
    replace historical evidence or force the current worktree back in time.
    JSON data/evidence and Python helpers are actually consumed from the
    worktree below, so their bytes must still equal the pinned Git object.
    """
    baseline = manifest["baseline_commit"]
    pinned_paths = set()
    strict_paths = set()
    for source in manifest["git_sources"]:
        path = source["path"]
        require(source["commit"] == baseline, "source commit differs from fixed baseline")
        blob = subprocess.check_output(
            ["git", "rev-parse", "--verify", baseline + ":" + path], cwd=REPO, text=True).strip()
        require(blob == source["git_blob"], "baseline path/blob identity: " + path)
        data = subprocess.check_output(["git", "cat-file", "blob", blob], cwd=REPO)
        require(len(data) == source["length"] and sha(data) == source["sha256"],
                "pinned Git source bytes: " + path)
        require(hashlib.sha1(b"blob " + str(len(data)).encode("ascii") + b"\0" + data).hexdigest() == blob,
                "Git object content identity: " + path)
        pinned_paths.add(path)
        if Path(path).suffix.lower() != ".md":
            require((REPO / path).read_bytes() == data, "worktree input/helper drift: " + path)
            strict_paths.add(path)
    actual_inputs = set(manifest["scenario_paths"]) | {
        manifest["stp_reader"], manifest["native_spans_source"],
        "design/scenario-content/local-scenario-definition.schema.json",
        "design/scenario-content/story-q119-patrol.monster-behavior.json",
        "governance/s00-iterations/evidence/S00-20261111-CHECKPOINT1-MANUAL-INTENT.json"
    }
    require(actual_inputs <= strict_paths, "actual parsed/executed input is not strictly worktree-pinned")
    return {"fixed_git_objects": len(pinned_paths), "strict_worktree_inputs_and_helpers": len(strict_paths),
            "fixed_git_document_sources": len(pinned_paths - strict_paths)}


class Bound:
    def __init__(self, data, metadata):
        require(data[:21] == b"MapTool Reinforce 1.0", "BND signature")
        self.version, self.w, self.h, self.wx, self.wy = struct.unpack_from("<IIIff", data, 0x20)
        require(self.version in (0, 2) and 0 < self.w <= 2048 and 0 < self.h <= 2048,
                "BND version or grid bounds")
        require(self.wx > 0 and self.wy > 0, "BND world bounds")
        self.blocked = bytearray(self.w * self.h)
        cursor = 0x234
        layers = []
        for i in range(32):
            offset, length, expanded, count = struct.unpack_from("<4I", data, 0x34 + 16 * i)
            if not count:
                continue
            require(i in (0, 1) and offset == cursor and count == self.w * self.h
                    and expanded == count * 4, "BND layer shape")
            inflater = zlib.decompressobj()
            raw = inflater.decompress(data[offset:offset + length])
            require(inflater.eof and not inflater.unused_data and len(raw) == expanded,
                    "BND compressed layer")
            nonzero = 0
            for j, (v,) in enumerate(struct.iter_unpack("<I", raw)):
                if v:
                    self.blocked[j] = 1
                    nonzero += 1
            layers.append({"layer": i, "offset": offset, "stored_length": length,
                           "expanded_length": expanded, "sha256": sha(raw), "nonzero_cells": nonzero})
            cursor += length
        require([x["layer"] for x in layers] == [0, 1] and cursor == len(data), "BND complete extent")
        self.labels = array("I", [0]) * (self.w * self.h)
        self.next_label = 0
        self.component_sizes = {}
        self.metadata = {k: v for k, v in metadata.items() if k != "prefix"}
        self.metadata.update({"version": self.version, "grid": [self.w, self.h],
                              "world_extent": [self.wx, self.wy], "layers": layers,
                              "union_blocked_cells": sum(self.blocked)})

    def cell(self, p):
        x, y = p["x"], p["y"]
        if not (math.isfinite(x) and math.isfinite(y) and 0 <= x < self.wx and 0 <= y < self.wy):
            return None
        return int(y * self.h / self.wy) * self.w + int(x * self.w / self.wx)

    def walkable(self, p, extra=None):
        c = self.cell(p)
        return c is not None and not self.blocked[c] and (extra is None or c not in extra)

    def flood(self, start, extra=None):
        if start is None or self.blocked[start] or (extra is not None and start in extra):
            return set() if extra is not None else 0
        if extra is None and self.labels[start]:
            return self.labels[start]
        self.next_label += 1
        label = self.next_label
        seen = {start} if extra is not None else None
        if seen is None:
            self.labels[start] = label
        q = deque([start])
        total = 0
        while q:
            c = q.popleft()
            total += 1
            x = c % self.w
            adjacent = []
            if x:
                adjacent.append(c - 1)
            if x + 1 < self.w:
                adjacent.append(c + 1)
            if c >= self.w:
                adjacent.append(c - self.w)
            if c + self.w < self.w * self.h:
                adjacent.append(c + self.w)
            for n in adjacent:
                if self.blocked[n] or (extra is not None and n in extra):
                    continue
                if seen is not None:
                    if n in seen:
                        continue
                    seen.add(n)
                else:
                    if self.labels[n]:
                        continue
                    self.labels[n] = label
                q.append(n)
        if seen is not None:
            return seen
        self.component_sizes[label] = total
        return label

    def connected(self, spawn, point):
        a, b = self.cell(spawn), self.cell(point)
        if a is None or b is None or self.blocked[a] or self.blocked[b]:
            return False
        return self.flood(a) == self.flood(b)

    def route_witness(self, start_point, end_point, extra):
        start, end = self.cell(start_point), self.cell(end_point)
        if not self.walkable(start_point, extra) or not self.walkable(end_point, extra):
            return None
        parents = {start: None}
        q = deque([start])
        while q and end not in parents:
            c = q.popleft()
            x = c % self.w
            adjacent = ([c - 1] if x else []) + ([c + 1] if x + 1 < self.w else [])
            adjacent += ([c - self.w] if c >= self.w else [])
            adjacent += ([c + self.w] if c + self.w < self.w * self.h else [])
            for n in adjacent:
                if n not in parents and not self.blocked[n] and n not in extra:
                    parents[n] = c
                    q.append(n)
        if end not in parents:
            return None
        route, cursor = [], end
        while cursor is not None:
            route.append(cursor)
            cursor = parents[cursor]
        route.reverse()
        corners = [route[0]]
        for i in range(1, len(route) - 1):
            if route[i] - route[i - 1] != route[i + 1] - route[i]:
                corners.append(route[i])
        if len(route) > 1:
            corners.append(route[-1])
        require(len(corners) <= 64, "bounded route-witness corner count")
        points = [{"x": ((c % self.w) + 0.5) * self.wx / self.w,
                   "y": ((c // self.w) + 0.5) * self.wy / self.h} for c in corners]
        return {"steps": len(route) - 1, "cell_center_corners": points,
                "segments": [self.segment(a, b, extra) for a, b in zip(points, points[1:])],
                "scope": "derived static point route; excludes actor width and native scene geometry"}

    def segment(self, a, b, extra=None, step=0.25):
        dist = math.hypot(a["x"] - b["x"], a["y"] - b["y"])
        intervals = max(1, math.ceil(dist / step))
        failures = []
        for k in range(intervals + 1):
            p = {d: a[d] + (b[d] - a[d]) * k / intervals for d in ("x", "y")}
            if not self.walkable(p, extra):
                failures.append([round(p["x"], 6), round(p["y"], 6)])
        return {"distance": round(dist, 6), "sample_step_max": step,
                "samples": intervals + 1, "blocked_samples": len(failures), "first_blocked": failures[:1]}

    def disk_samples(self, circle, step=0.25):
        r = circle["radius"]
        m = math.floor(r / step)
        require(m <= 100, "bounded disk sampling limit")
        total = blocked = 0
        for ix in range(-m, m + 1):
            for iy in range(-m, m + 1):
                if (ix * step) ** 2 + (iy * step) ** 2 <= r * r + 1e-12:
                    total += 1
                    p = {"x": circle["x"] + ix * step, "y": circle["y"] + iy * step}
                    blocked += not self.walkable(p)
        return {"sample_spacing": step, "samples": total, "blocked_samples": blocked,
                "scope": "sampled points only; not continuous geometry or actor-radius proof"}

    def overlay(self, barriers):
        result = set()
        for b in barriers:
            require(0 <= b["minX"] < b["maxX"] <= self.wx
                    and 0 <= b["minY"] < b["maxY"] <= self.wy, "barrier rectangle extent")
            for y in range(max(0, math.floor(b["minY"] * self.h / self.wy) - 1),
                           min(self.h, math.ceil(b["maxY"] * self.h / self.wy) + 1)):
                for x in range(max(0, math.floor(b["minX"] * self.w / self.wx) - 1),
                               min(self.w, math.ceil(b["maxX"] * self.w / self.wx) + 1)):
                    cx, cy = (x + 0.5) * self.wx / self.w, (y + 0.5) * self.wy / self.h
                    if b["minX"] <= cx < b["maxX"] and b["minY"] <= cy < b["maxY"]:
                        result.add(y * self.w + x)
        return result


def all_points(node):
    yield "spawn", "spawn", node["spawn"]
    portals = [("portal", node["portal"])] + [(f"alternativeExits/{i}/portal", e["portal"])
                                               for i, e in enumerate(node.get("alternativeExits", []))]
    for loc, p in portals:
        yield loc, "exit", p
        condition = p.get("condition") or {}
        if condition.get("activationRegion"):
            yield loc + "/condition/activationRegion", "exit_region", condition["activationRegion"]
    for group_loc, group in [("", node)] + [(f"{kind}/{i}/", g)
                for kind in ("reinforcements", "timedReinforcements") for i, g in enumerate(node.get(kind, []))]:
        if group.get("activationRegion"):
            yield group_loc + "activationRegion", "wave_region", group["activationRegion"]
        for i, e in enumerate(group.get("encounters", [])):
            yield f"{group_loc}encounters/{i}", "monster", e
            for j, p in enumerate(e.get("patrol", [])):
                yield f"{group_loc}encounters/{i}/patrol/{j}", "patrol_waypoint", p
    for i, signal in enumerate(node.get("signals", [])):
        if signal.get("region"):
            yield f"signals/{i}/region", "signal_region", signal["region"]
        if signal.get("interaction"):
            inter = signal["interaction"]
            yield f"signals/{i}/interaction/region", "manual_region", inter["region"]
            if inter.get("markerKey") is not None:
                yield f"signals/{i}/interaction/marker", "manual_marker", inter["region"]
    for i, h in enumerate(node.get("hazards", [])):
        yield f"hazards/{i}/region", "hazard_region", h["region"]
    for i, b in enumerate(node.get("barriers", [])):
        if b.get("marker"):
            yield f"barriers/{i}/marker", "barrier_marker", b["marker"]


def native_points(binary, prior, manual_prior):
    pe = struct.unpack_from("<I", binary, 0x3c)[0]
    require(binary[pe:pe + 4] == b"PE\0\0", "PE signature")
    sections, optlen = struct.unpack_from("<H", binary, pe + 6)[0], struct.unpack_from("<H", binary, pe + 20)[0]
    imagebase = struct.unpack_from("<I", binary, pe + 24 + 28)[0]
    require(imagebase == 0x400000, "PE image base")
    mapping = []
    for i in range(sections):
        a = pe + 24 + optlen + 40 * i
        virtual_size, rva, raw_size, raw = struct.unpack_from("<4I", binary, a + 8)
        mapping.append((rva, raw_size, raw))
    selected = []
    ids = {"N-lua-status", "N-point-lookup", "N-point-gate", "N-point-snapshot", "N-point-set"}
    for w in prior["windows"]:
        if w["id"] not in ids:
            continue
        rva, raw = int(w["va"], 16) - imagebase, int(w["raw"], 16)
        require(any(a <= rva and rva + w["length"] <= a + size and raw == off + rva - a
                    for a, size, off in mapping), "native span VA/raw mapping")
        piece = binary[raw:raw + w["length"]]
        require(sha(piece) == w["sha256"] and piece.hex() == w["hex"], "native point evidence identity")
        selected.append({k: w[k] for k in ("id", "va", "raw", "length", "sha256")})
    require(len(selected) == len(ids), "native point span set")
    for w in manual_prior["nativeWindows"]:
        rva = int(w["start"], 16) - imagebase
        length = w["bytes"]
        matches = [off + rva - a for a, size, off in mapping if a <= rva and rva + length <= a + size]
        require(len(matches) == 1, "manual intent span mapping")
        raw = matches[0]
        require(sha(binary[raw:raw + length]) == w["sha256"], "manual intent evidence identity")
        selected.append({"id": "manual-" + w["start"], "va": w["start"], "raw": hex(raw),
                         "length": length, "sha256": w["sha256"]})
    return selected


def build(originals):
    manifest = read_json(HERE / "source-manifest.json")
    verify_sources(manifest)
    corpus = manifest["scenario_paths"]
    require(corpus == sorted(str(p.relative_to(REPO)) for p in (REPO / "design/scenario-content").glob("*.scenario.json")),
            "scenario file set drift")
    originals_data = {}
    for s in manifest["originals"]:
        p = originals / s["filename"]
        b = p.read_bytes()
        require(len(b) == s["length"] and sha(b) == s["sha256"], "original identity: " + p.name)
        originals_data[s["role"]] = b
    reader_path = REPO / manifest["stp_reader"]
    spec = importlib.util.spec_from_file_location("pinned_read_only_stp", reader_path)
    reader = importlib.util.module_from_spec(spec)
    sys.dont_write_bytecode = True
    spec.loader.exec_module(reader)
    table = reader.STP(originals / "07-Table.stp")
    bound_stp = reader.STP(originals / "10-BoundMap.stp")
    map_data, map_meta = table.get("Table/_MapList.xml")
    map_rows = ET.fromstring(map_data).findall(".//MAP")
    if not map_rows:
        map_rows = list(ET.fromstring(map_data))
    ids = {}
    for row in map_rows:
        key = int(row.attrib["ID"])
        require(key not in ids, "MapList duplicate ID")
        ids[key] = row.attrib
    bounds, joins, counts, issues, nodes_out = {}, {}, Counter(), [], []
    maps_excluding_branch_example = set()
    feature_nodes, overlap_findings = [], []
    profiles = read_json(REPO / "design/scenario-content/story-q119-patrol.monster-behavior.json")
    profiles = {p["id"]: p for p in profiles["profiles"]}
    for rel in corpus:
        doc = read_json(REPO / rel)
        counts["scenario_files"] += 1
        for di, definition in enumerate(doc["definitions"]):
            counts["definition_occurrences"] += 1
            for node in definition["nodes"]:
                counts["node_occurrences"] += 1
                identity = {"file": rel, "definition_index": di, "definition_id": definition["id"],
                            "node": node["node"], "map_id": node["map"]}
                maprow = ids.get(node["map"])
                if not rel.endswith("/branch-example.scenario.json"):
                    maps_excluding_branch_example.add(node["map"])
                require(maprow is not None and maprow.get("BOUND"), "unresolved map/BND identity")
                member = "BoundMap/" + maprow["BOUND"] + ".bnd"
                if member not in bounds:
                    data, metadata = bound_stp.get(member)
                    bounds[member] = Bound(data, metadata)
                bound = bounds[member]
                joins[node["map"]] = {"map_id": node["map"], "MAP": maprow.get("MAP"),
                                      "BOUND": maprow["BOUND"], "TRIGGER": maprow.get("TRIGGER"), "bound_member": member}
                point_counts = Counter()
                failed = []
                for loc, kind, point in all_points(node):
                    point_counts[kind] += 1
                    counts["point_" + kind] += 1
                    state = ("outside_map" if bound.cell(point) is None else
                             "blocked_cell" if not bound.walkable(point) else
                             "different_static_component" if not bound.connected(node["spawn"], point) else "reachable")
                    if state != "reachable":
                        counts["point_status_" + state] += 1
                        finding = {**identity, "location": loc, "kind": kind,
                                   "x": point["x"], "y": point["y"], "status": state}
                        issues.append(finding)
                        failed.append(loc)
                    else:
                        counts["point_status_reachable"] += 1
                portals = [("portal", node["portal"])] + [(f"alternativeExits/{i}/portal", e["portal"])
                                                           for i, e in enumerate(node.get("alternativeExits", []))]
                for a in range(len(portals)):
                    for b in range(a + 1, len(portals)):
                        la, pa = portals[a]
                        lb, pb = portals[b]
                        dist = math.hypot(pa["x"] - pb["x"], pa["y"] - pb["y"])
                        if dist < pa["radius"] + pb["radius"]:
                            overlap_findings.append({**identity, "a": la, "b": lb, "keys": [pa["key"], pb["key"]],
                                "center_distance": round(dist, 6), "server_radii_sum": pa["radius"] + pb["radius"],
                                "native_category0_disks_overlap": dist < 0.8 * (pa["radius"] + pb["radius"]),
                                "interpretation": "potential simultaneous focus region; activation conditions not evaluated here"})
                nodes_out.append({**identity, "point_counts": dict(point_counts), "nonreachable_locations": failed})
                special = bool(node.get("barriers") or node.get("hazards") or
                               any(s.get("event") == "RegionHeld" or s.get("interaction") for s in node.get("signals", [])) or
                               any(e.get("patrol") for g in [node] + node.get("reinforcements", []) + node.get("timedReinforcements", [])
                                   for e in g.get("encounters", [])))
                if not special:
                    continue
                feature = {**identity}
                if node.get("barriers"):
                    overlay = bound.overlay(node["barriers"])
                    reachable = bound.flood(bound.cell(node["spawn"]), overlay)
                    feature["barriers"] = {"count": len(node["barriers"]), "overlay_cells": len(overlay),
                        "previously_walkable_cells_blocked": sum(not bound.blocked[c] for c in overlay),
                        "spawn_cell_blocked": not bound.walkable(node["spawn"], overlay),
                        "main_exit_reachable_while_closed": bound.cell(node["portal"]) in reachable,
                        "closed_barrier_route_witness": bound.route_witness(node["spawn"], node["portal"], overlay),
                        "direct_spawn_to_exit_open": bound.segment(node["spawn"], node["portal"]),
                        "direct_spawn_to_exit_closed": bound.segment(node["spawn"], node["portal"], overlay),
                        "centers_on_closed_cells": [loc for loc, _, p in all_points(node) if bound.cell(p) in overlay]}
                    region_details = []
                    for i, signal in enumerate(node.get("signals", [])):
                        if signal.get("region"):
                            region_details.append({"signal_index": i, "event": signal["event"],
                                "center_reachable_while_closed": bound.cell(signal["region"]) in reachable,
                                "spawn_to_center": bound.segment(node["spawn"], signal["region"], overlay),
                                "disk": bound.disk_samples(signal["region"])})
                    feature["signal_regions"] = region_details
                if node.get("hazards"):
                    feature["hazards"] = [{"id": h["id"], "spawn_to_center": bound.segment(node["spawn"], h["region"]),
                                            "disk": bound.disk_samples(h["region"])} for h in node["hazards"]]
                interactions = []
                for signal in node.get("signals", []):
                    if signal.get("interaction"):
                        inter = signal["interaction"]
                        interactions.append({"key": inter["key"], "marker_key": inter.get("markerKey"),
                            "region": inter["region"], "spawn_to_center": bound.segment(node["spawn"], inter["region"]),
                            "disk": bound.disk_samples(inter["region"])})
                if interactions:
                    feature["interactions"] = interactions
                patrols = []
                for gi, group in enumerate([node] + node.get("reinforcements", []) + node.get("timedReinforcements", [])):
                    for ei, encounter in enumerate(group.get("encounters", [])):
                        if not encounter.get("patrol"):
                            continue
                        profile_id = encounter.get("aiProfile", node.get("aiProfile"))
                        profile = profiles[profile_id]
                        route = [encounter] + encounter["patrol"] + [encounter]
                        segments = [bound.segment(a, b) for a, b in zip(route, route[1:])]
                        distances = [round(math.hypot(p["x"] - encounter["x"], p["y"] - encounter["y"]), 6)
                                     for p in encounter["patrol"]]
                        patrols.append({"group_index": gi, "encounter_index": ei, "profile_id": profile_id,
                            "profile_leash_radius": profile["leashRadius"], "waypoint_spawn_distances": distances,
                            "all_waypoints_within_leash": all(d <= profile["leashRadius"] for d in distances),
                            "all_segment_lengths_in_bounds": all(0 < s["distance"] <= 256 for s in segments),
                            "profile_aggro_range": profile["aggroRange"],
                            "route_length": round(sum(s["distance"] for s in segments), 6),
                            "segments_including_return": segments})
                if patrols:
                    feature["patrols"] = patrols
                    if rel.endswith("story-q119-patrol-detour.scenario.json"):
                        probe = {"x": 414.5, "y": 355.5}
                        corner = {"x": 414.5, "y": 361.5}
                        home = node["encounters"][0]
                        feature["detour_probe"] = {"from": probe, "via": corner,
                            "home": {k: home[k] for k in ("x", "y")}, "direct": bound.segment(probe, home),
                            "via_segments": [bound.segment(probe, corner), bound.segment(corner, home)]}
                feature_nodes.append(feature)
    native = native_points(originals_data["bin"], read_json(REPO / manifest["native_spans_source"]),
        read_json(REPO / "governance/s00-iterations/evidence/S00-20261111-CHECKPOINT1-MANUAL-INTENT.json"))
    counts["unique_map_ids"] = len(joins)
    counts["unique_map_ids_excluding_branch_example"] = len(maps_excluding_branch_example)
    counts["unique_bound_members"] = len(bounds)
    counts["nodes_with_nonreachable_points"] = sum(bool(n["nonreachable_locations"]) for n in nodes_out)
    counts["potential_exit_circle_overlaps"] = len(overlap_findings)
    repair = read_json(HERE / "content-remediation.json")
    repair_doc = copy.deepcopy(read_json(REPO / repair["source"]))
    repair_results = []
    require(len(repair["nodes"]) == len(repair_doc["definitions"][0]["nodes"]), "repair node count")
    for patch, node in zip(repair["nodes"], repair_doc["definitions"][0]["nodes"]):
        require(patch["node"] == node["node"] and patch["map"] == node["map"], "repair node identity")
        node["spawn"].update(patch["spawn"])
        node["portal"].update(patch["portal"])
        require(len(patch["encounters"]) == len(node["encounters"]), "repair encounter shape")
        require(len(patch["alternative_portals"]) == len(node.get("alternativeExits", [])), "repair exit shape")
        for point, encounter in zip(patch["encounters"], node["encounters"]):
            encounter.update(point)
        for point, exit in zip(patch["alternative_portals"], node.get("alternativeExits", [])):
            exit["portal"].update(point)
        bound = bounds[joins[node["map"]]["bound_member"]]
        points = []
        for loc, kind, p in all_points(node):
            require(bound.connected(node["spawn"], p), "repair center reachability")
            segment = bound.segment(node["spawn"], p)
            require(segment["blocked_samples"] == 0, "repair direct route")
            item = {"location": loc, "kind": kind, "x": p["x"], "y": p["y"], "spawn_to_point": segment}
            if kind == "exit":
                item["disk"] = bound.disk_samples(p)
                require(item["disk"]["blocked_samples"] == 0, "repair exit disk samples")
            points.append(item)
        if node.get("alternativeExits"):
            p, q = node["portal"], node["alternativeExits"][0]["portal"]
            require(math.hypot(p["x"] - q["x"], p["y"] - q["y"]) > p["radius"] + q["radius"],
                    "repair exit circle separation")
        repair_results.append({"node": node["node"], "map_id": node["map"], "points": points})
    return {"schema": "MEF_LEVEL_SPATIAL_CONTENT_AUDIT_V1", "baseline_commit": manifest["baseline_commit"],
        "policy": "SERVER_STATIC_BND_LAYER0_1_NONZERO_UNION_FOUR_NEIGHBOR_POINT_REACHABILITY",
        "scope": {"analysis_only": True, "runtime_executed": False, "full_member_exported": False,
                  "native_collision_proven": False, "radius_or_3d_clearance_proven": False,
                  "all_scenarios_are_active_releases": False},
        "counts": dict(sorted(counts.items())), "maplist_member": {k: v for k, v in map_meta.items() if k != "prefix"},
        "maplist_row_count": len(map_rows), "map_joins": [joins[k] for k in sorted(joins)],
        "bound_members": [bounds[k].metadata for k in sorted(bounds)], "node_results": nodes_out,
        "nonreachable_points": issues, "potential_exit_circle_overlaps": overlap_findings,
        "feature_geometry": feature_nodes, "revalidated_native_point_spans": native,
        "branch_example_coordinate_remediation": {"status": "STATIC_CHECKED_NOT_APPLIED", "nodes": repair_results}}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--originals", type=Path, required=True)
    parser.add_argument("--write-evidence", action="store_true", help="only writes derived evidence in this analysis directory")
    args = parser.parse_args()
    result = build(args.originals)
    target = HERE / "spatial-evidence.json"
    if args.write_evidence:
        target.write_text(canonical(result), encoding="utf-8")
    else:
        require(read_json(target) == result, "spatial evidence drift")
    print(canonical({"result": "PASS", "scope": "static corpus audit, not runtime/game PASS", "counts": result["counts"],
                     "spatial_evidence_sha256": sha(target.read_bytes())}), end="")


if __name__ == "__main__":
    main()
