#!/usr/bin/env python3
"""Read-only verification of bounded native evidence and proposed contracts.

Requires Python 3, git and GNU objdump. Does not run Client, Server, Lua, target
DLLs, network operations or a game-state implementation. Writes only stdout.
The optional caller redirect may save the JSON receipt.
"""

import argparse
import datetime
import hashlib
import json
import pathlib
import re
import struct
import subprocess
import sys


def require(ok, message):
    if not ok:
        raise ValueError(message)


def digest(data):
    return hashlib.sha256(data).hexdigest()


def read_json(path):
    return json.loads(path.read_text(encoding="utf-8"))


class PE:
    def __init__(self, data):
        self.data = data
        require(data[:2] == b"MZ", "not MZ")
        pe = struct.unpack_from("<I", data, 0x3C)[0]
        require(data[pe:pe + 4] == b"PE\0\0", "not PE")
        require(struct.unpack_from("<H", data, pe + 4)[0] == 0x14C, "not x86")
        opt = pe + 24
        require(struct.unpack_from("<H", data, opt)[0] == 0x10B, "not PE32")
        self.image_base = struct.unpack_from("<I", data, opt + 28)[0]
        section_start = opt + struct.unpack_from("<H", data, pe + 20)[0]
        self.sections = []
        for i in range(struct.unpack_from("<H", data, pe + 6)[0]):
            p = section_start + 40 * i
            name = data[p:p + 8].rstrip(b"\0").decode("ascii")
            virtual_size, rva, raw_size, raw_offset = struct.unpack_from("<IIII", data, p + 8)
            self.sections.append((name, rva, raw_size, raw_offset, virtual_size))

    def raw(self, va, size):
        rva = va - self.image_base
        for _, start, length, raw, _ in self.sections:
            if start <= rva and rva + size <= start + length:
                return raw + rva - start
        raise ValueError("range outside initialized PE sections: " + hex(va))

    def view(self, va, size):
        p = self.raw(va, size)
        return self.data[p:p + size]


def disassemble(binary, start, end):
    output = subprocess.check_output(
        ["objdump", "-d", "-Mintel", "--insn-width=16",
         "--start-address=" + hex(start), "--stop-address=" + hex(end), str(binary)],
        text=True,
    )
    result = []
    for line in output.splitlines():
        match = re.match(r"^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2} )+)\s+(.+)$", line)
        if match:
            result.append((int(match[1], 16), bytes.fromhex(match[2]), match[3].strip()))
    require(result, "empty disassembly")
    return result


def proposed_clear(case):
    """Only a small review model for proposed observer data; not game code."""
    members = {key: dict(value) for key, value in case["members"].items()}
    seen = set()
    for event in case["events"]:
        key = event["actor"]
        if event.get("run", "current") != "current" or key not in members:
            continue
        member = members[key]
        if event["generation"] != member["generation"]:
            continue
        identity = (key, event["generation"], event["event_id"])
        if identity in seen:
            continue
        seen.add(identity)
        if member["state"] == "alive":
            member["state"] = event["reason"]
    return bool(case["sealed"] and members and
                all(m["state"] == "defeat" for m in members.values()))


def main():
    require(__debug__, "Python -O is not allowed")
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--bin", type=pathlib.Path, required=True)
    parser.add_argument("--repo", type=pathlib.Path,
                        default=pathlib.Path(__file__).resolve().parents[3])
    args = parser.parse_args()
    here = pathlib.Path(__file__).resolve().parent
    source = read_json(here / "source-manifest.json")
    native = read_json(here / "native-evidence.json")
    contracts = read_json(here / "capability-contracts.json")
    artifact_manifest = read_json(here / "artifact-manifest.json")

    for artifact in artifact_manifest["artifacts"]:
        path = here / artifact["path"]
        require(path.parent == here, "artifact outside package")
        payload = path.read_bytes()
        require(len(payload) == artifact["bytes"] and digest(payload) == artifact["sha256"],
                "artifact mismatch: " + artifact["path"])

    original = args.bin.read_bytes()
    require(len(original) == native["binary_bytes"], "BIN length mismatch")
    require(digest(original) == native["binary_sha256"], "BIN SHA256 mismatch")
    require(source["originals"][0]["sha256"] == native["binary_sha256"], "source identity mismatch")
    pe = PE(original)
    require(pe.image_base == int(native["image_base"], 0), "image base mismatch")

    for pin in source["pins"]:
        spec = pin["commit"] + ":" + pin["path"]
        blob = subprocess.check_output(["git", "rev-parse", spec], cwd=args.repo, text=True).strip()
        payload = subprocess.check_output(["git", "cat-file", "blob", blob], cwd=args.repo)
        require(blob == pin["blob"], "Git blob mismatch: " + pin["path"])
        require(len(payload) == pin["bytes"] and digest(payload) == pin["sha256"],
                "Git content mismatch: " + pin["path"])

    roots = {}
    instruction_sites = {}
    for window in native["windows"]:
        start, end = int(window["start"], 0), int(window["end"], 0)
        root = (int(window["root"], 0), int(window["root_end"], 0))
        if root not in roots:
            roots[root] = disassemble(args.bin, *root)
        instructions = [(a, b, c) for a, b, c in roots[root] if start <= a < end]
        require(instructions and instructions[0][0] == start, "unaligned excerpt start: " + window["id"])
        require(instructions[-1][0] + len(instructions[-1][1]) == end,
                "unaligned excerpt end: " + window["id"])
        payload = pe.view(start, end - start)
        require(pe.raw(start, end - start) == int(window["raw"], 0), "raw map mismatch")
        require(len(payload) == window["bytes"] and digest(payload) == window["sha256"],
                "native hash mismatch: " + window["id"])
        require(b"".join(b for _, b, _ in instructions) == payload, "decode gap")
        expected = [(int(i["va"], 0), bytes.fromhex(i["hex"])) for i in window["instructions"]]
        require([(a, b) for a, b, _ in instructions] == expected, "instruction boundary mismatch")
        require(all(".byte" not in c and "(bad)" not in c for _, _, c in instructions), "bad decode")
        instruction_sites.update({a: b for a, b, _ in instructions})

    for slot in native["vtable_slots"]:
        va = int(slot["va"], 0)
        payload = pe.view(va, 4)
        require(va == int(slot["owner_vtable"], 0) + int(slot["slot"], 0), "slot offset mismatch")
        require(payload.hex() == slot["hex"] and digest(payload) == slot["sha256"], "slot bytes mismatch")
        require(int.from_bytes(payload, "little") == int(slot["target"], 0), "vtable target mismatch")

    for reuse in native["reused_windows"]:
        start, end = int(reuse["start"], 0), int(reuse["end"], 0)
        payload = pe.view(start, end - start)
        require(len(payload) == reuse["bytes"] and digest(payload) == reuse["sha256"], "reused native mismatch")
        require(any(p["path"] == reuse["source_path"] and p["commit"] == reuse["commit"]
                    for p in source["pins"]), "missing immutable reused source")

    wanted = native["direct_e8_e9_candidates"]["targets"]
    found = {target: [] for target in wanted}
    section = next(s for s in pe.sections if s[0] == ".text")
    code = original[section[3]:section[3] + section[2]]
    base = pe.image_base + section[1]
    for i in range(len(code) - 4):
        if code[i] in (0xE8, 0xE9):
            target = hex(base + i + 5 + struct.unpack_from("<i", code, i + 1)[0])
            if target in found:
                found[target].append({"site": hex(base + i), "opcode": hex(code[i]), "hex": code[i:i + 5].hex()})
    require(found == wanted, "bounded E8/E9 candidate set changed")
    for candidates in found.values():
        for candidate in candidates:
            require(instruction_sites.get(int(candidate["site"], 0)) == bytes.fromhex(candidate["hex"]),
                    "raw-byte candidate not rooted as a real instruction")

    native_ids = {"native:" + w["id"] for w in native["windows"]}
    source_ids = {"source:" + p["path"] for p in source["pins"]}
    caps = contracts["capabilities"]
    require(len({c["id"] for c in caps}) == len(caps), "duplicate capability ID")
    for cap in caps:
        require(cap["analysis_status"] == "BOUNDED_ANALYSIS_COMPLETE", "unexpected status")
        require(cap["new_runtime_implementation"] is False and cap["new_runtime_acceptance"] is False,
                "unsupported runtime completion")
        require(cap["priority"] in ("P0", "P1", "P2"), "invalid priority")
        require(cap["evidence"] and set(cap["evidence"]) <= native_ids | source_ids,
                "unresolved evidence reference: " + cap["id"])
    require(contracts["proposed_observer_contract"]["status"] ==
            "PROPOSED_ADAPTER_DATA_NOT_EXISTING_LUA_API_OR_OPCODE", "adapter provenance missing")
    for case in contracts["proposed_observer_examples"]:
        require(proposed_clear(case) == case["expected_clear"], "proposed review-model case failed: " + case["id"])
    performance = contracts["performance_claims"]
    require(performance["measured_cpu_reduction_percent"] is None and
            performance["measured_network_reduction_percent"] is None, "unmeasured performance number")
    require(performance["target_executed"] is False, "target execution claim")
    report = (here / "report.md").read_text(encoding="utf-8")
    require("Q.IsObjectStopped" not in report and "Q.IsAllObjectsStopped" in report, "Q observer name")
    require("source-pins.json" not in report, "stale source filename")

    print(json.dumps({
        "schema": "mef-world-offload-verification-v1",
        "status": "PASS",
        "verified_at_utc": datetime.datetime.now(datetime.timezone.utc).isoformat(),
        "baseline_commit": source["baseline_commit"],
        "original_bin_sha256": digest(original),
        "artifacts": len(artifact_manifest["artifacts"]),
        "immutable_source_pins": len(source["pins"]),
        "rooted_native_windows": len(native["windows"]),
        "native_code_bytes": sum(w["bytes"] for w in native["windows"]),
        "typed_vtable_slots": len(native["vtable_slots"]),
        "reused_native_ranges": len(native["reused_windows"]),
        "finite_direct_target_censuses": len(found),
        "capabilities": len(caps),
        "proposed_observer_model_cases": len(contracts["proposed_observer_examples"]),
        "client_executed": False,
        "server_executed": False,
        "lua_executed": False,
        "network_used": False,
        "formal_task_or_rr_changed": False,
        "runtime_play_acceptance": False,
        "scope": "Read-only source/native consistency and proposed contract review model; not T01 FULL-PASS, RR acceptance, deployment or game acceptance.",
    }, ensure_ascii=False, indent=2))


if __name__ == "__main__":
    try:
        main()
    except (OSError, ValueError, subprocess.CalledProcessError) as error:
        print(json.dumps({"status": "FAIL", "error": str(error)}, ensure_ascii=False))
        sys.exit(1)
