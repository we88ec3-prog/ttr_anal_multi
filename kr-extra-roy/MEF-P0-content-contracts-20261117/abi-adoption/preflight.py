#!/usr/bin/env python3
"""Strict, data-only normal-binding authoring review. NOT_NATIVE_MEF.

This is not a Lua parser, compiler, executor, publisher, or deployment gate.
All native definitions are loaded only after their pinned content is checked.
Original SEQ/helper review is separate; native-call plans never rewrite them.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import math
from pathlib import Path
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
SCHEMA = "ttr-mef-p0-native-call-plan-v1"
BIN_SHA = "9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"


def sha(data):
    return hashlib.sha256(data).hexdigest()


def strict_loads(text):
    """Reject duplicate keys and JavaScript non-finite JSON extensions."""
    def pairs(items):
        out = {}
        for key, value in items:
            if any(0xD800 <= ord(char) <= 0xDFFF for char in key):
                raise ValueError("JSON key contains a lone Unicode surrogate")
            if key in out:
                raise ValueError("duplicate JSON key: " + key)
            out[key] = value
        return out

    def constant(value):
        raise ValueError("non-finite JSON constant: " + value)

    return json.loads(text, object_pairs_hook=pairs, parse_constant=constant)


def read_pinned(repo):
    manifest = strict_loads((HERE / "source-manifest.json").read_text())
    cache = {}
    for row in manifest["repository_sources"]:
        if row.get("runtime_input"):
            path = repo / row["path"]
            raw = path.read_bytes()
            if len(raw) != row["bytes"] or sha(raw) != row["sha256"]:
                raise ValueError("pinned definition differs: " + row["path"])
            cache[row["id"]] = strict_loads(raw.decode("utf-8"))
    return manifest, cache


def numeric(value):
    if type(value) not in (int, float):
        return False
    try:
        return math.isfinite(value)
    except (OverflowError, TypeError):
        return False


def validate(doc, repo=None):
    repo = Path(repo) if repo is not None else HERE.parents[2]
    manifest, sources = read_pinned(repo)
    definitions = sources["ABI"]["bindings"]
    known = {row["name"]: row for row in definitions}
    observations = {row["name"]: row for row in sources["OBSERVATIONS"]["records"]}
    abi_pin = next(row for row in manifest["repository_sources"] if row["id"] == "ABI")
    errors, warnings, effects = [], [], []

    def issue(destination, code, message, call_index=None, argument=None):
        destination.append({"code": code, "call_index": call_index,
                            "argument": argument, "message": message})

    def keys(value, expected, label, index=None):
        if not isinstance(value, dict):
            issue(errors, "OBJECT_SHAPE", label + " must be an object", index)
            return False
        unknown = sorted(set(value) - set(expected))
        missing = sorted(set(expected) - set(value))
        if unknown or missing:
            issue(errors, "EXACT_FIELDS", label + ": missing=" + str(missing) +
                  ", unknown=" + str(unknown), index)
            return False
        return True

    if keys(doc, ("schema", "format", "target", "calls"), "plan"):
        if doc["schema"] != SCHEMA or doc["format"] != "NOT_NATIVE_MEF":
            issue(errors, "FORMAT_IDENTITY", "Only the explicit research plan schema is accepted")
        if keys(doc["target"], ("client_version", "bin_sha256", "abi_contract_sha256"), "target"):
            expected = {"client_version": "kr", "bin_sha256": BIN_SHA,
                        "abi_contract_sha256": abi_pin["sha256"]}
            if doc["target"] != expected:
                issue(errors, "TARGET_IDENTITY", "Target and ABI definitions must match the pinned original")
        calls = doc["calls"]
    else:
        calls = doc.get("calls", []) if isinstance(doc, dict) else []
    if not isinstance(calls, list) or not calls:
        issue(errors, "CALL_LIST", "calls must be an explicit nonempty array")
        calls = []

    for index, call in enumerate(calls):
        if not keys(call, ("name", "args", "result"), "call", index):
            continue
        name, args, result = call["name"], call["args"], call["result"]
        if not isinstance(name, str) or name not in known:
            issue(errors, "UNKNOWN_BINDING", "Only the pinned 121 normal dot-call bindings are accepted", index)
            continue
        row = known[name]
        if row["binding_status"] in ("STUB", "NOT_COUNT_QUERY"):
            issue(errors, "NONFUNCTIONAL_ENTRY", "This name does not implement the requested capability/count", index)
        if not isinstance(args, list):
            issue(errors, "ARGUMENT_SHAPE", "args must be an explicit array", index)
            continue
        if len(args) != row["argument_count"]:
            issue(errors, "EXACT_ARITY", "Native reads last N slots; missing arguments are not explicit nil", index)
            continue
        for argument, (value, kind) in enumerate(zip(args, row["argument_kinds"]), 1):
            if kind in ("integer32", "float32"):
                ok = numeric(value)
                if kind == "integer32":
                    ok = ok and -2147483648 <= value <= 2147483647 and int(value) == value
                else:
                    ok = ok and abs(value) <= 3.4028234663852886e38
                if not ok:
                    issue(errors, "NUMERIC_ABI", "Use a finite explicit " + kind +
                          "; boolean/nil/numeric string coercion is not authoring policy", index, argument)
            elif kind == "string":
                # Only this exact empty-string effect has an adopted native contract.
                allowed_empty = name == "Q.SetFinalMusic" and argument == 1
                if not isinstance(value, str) or "\0" in value or (not value and not allowed_empty) or any(0xD800 <= ord(char) <= 0xDFFF for char in value):
                    issue(errors, "STRING_ABI", "Explicit NUL-free string required; empty exception is SetFinalMusic only", index, argument)
                elif any(ord(char) > 127 for char in value):
                    issue(warnings, "STRING_ENCODING_UNPROVED", "JSON Unicode does not establish the Client narrow-string encoding or selected resource bytes", index, argument)
            elif kind == "lua_truthiness":
                if type(value) is not bool:
                    issue(errors, "BOOLEAN_ABI", "Use an explicit boolean; Lua numeric 0 and empty string are truthy", index, argument)
            else:
                issue(errors, "UNSUPPORTED_KIND", "Unknown pinned argument kind", index, argument)

        if name in ("Tutorial.SetControlStatus", "Tutorial.GetControlStatus"):
            if not numeric(args[0]) or not 0 <= args[0] <= 31:
                issue(errors, "CONTROL_INDEX", "The selected CTutorialController layout is index 0..31", index, 1)
        if name == "Q.GetLeaderPosN" and (type(args[0]) not in (int, float) or args[0] not in (0, 1, 2)):
            issue(errors, "LEADER_COMPONENT", "Only selector 0/1/2 is adopted; invalid selector also returns ambiguous zero", index, 1)

        if not isinstance(result, dict) or "mode" not in result:
            issue(errors, "RESULT_SHAPE", "result must declare an explicit mode", index)
            continue
        mode = result["mode"]
        if mode == "discard":
            keys(result, ("mode",), "discard result", index)
        elif mode in ("read_number", "compare_number"):
            if not row["produces_new_lua_value"]:
                issue(errors, "NO_VALUE_PRODUCER", "C callback return count 1 is not a newly produced success value", index)
            expected_fields = ("mode", "purpose", "context") if mode == "read_number" else ("mode", "purpose", "context", "operator", "value")
            if keys(result, expected_fields, "numeric result", index):
                expected_purpose = "LOADER_DIAGNOSTIC_ONLY" if name == "lb.DoFile" else "LOCAL_OBSERVATION_ONLY"
                if result["purpose"] != expected_purpose:
                    issue(errors, "RESULT_PURPOSE", "A query/loader value is not a world result, cleanup ACK or business success", index)
                expected_context = "lb.DoFile:open_failure_and_execution_success_share_zero" if name == "lb.DoFile" else (name + ":" + observations[name]["evidence_id"] if name in observations else None)
                if result["context"] != expected_context:
                    issue(errors, "OBSERVATION_CONTEXT", "Use the exact pinned query scope; the label does not prove runtime owner identity", index)
                if mode == "compare_number":
                    if result["operator"] not in ("==", "~=", "<", "<=", ">", ">=") or not numeric(result["value"]):
                        issue(errors, "NUMERIC_COMPARISON", "Explicit finite numeric comparison required; boolean truthiness is forbidden", index)
                    if name == "lb.DoFile":
                        issue(errors, "LOADER_NOT_SUCCESS_PREDICATE", "Loader status may be recorded but this plan cannot promote a numeric comparison to loaded/success", index)
        else:
            issue(errors, "RESULT_MODE", "Use discard/read_number/compare_number; truthiness/ACK modes are not supported", index)

        if name in observations:
            issue(warnings, "OBSERVATION_BOUNDARY", observations[name]["ambiguities"], index)
        if name == "lb.DoFile":
            issue(warnings, "LOADER_ZERO_AMBIGUOUS", "Zero can mean open failure or successful execution; exports/version and legal loader context need separate proof", index)
        if name in ("Tutorial.IsCharacterAvailable", "Q.Book"):
            issue(warnings, "IGNORED_SELECTOR", "The formal integer does not select an arbitrary character/book", index)
        if name == "Q.FlyingObject":
            effects.append({"call_index": index, "effect": "CANCEL_PREVIOUS_Q_TRACKED_IMAGE_BEFORE_ALLOCATION",
                            "source": "reuse:q_flying_create@0x56496a", "physical_reclamation_proved_now": False})
            issue(warnings, "IMAGE_REPLACEMENT", "A later Q image replaces the tracked predecessor; this is not a simultaneous multi-image API or global owner sweep", index)
        if name == "Q.DelFlyingObject":
            effects.append({"call_index": index, "effect": "CANCEL_CURRENT_Q_TRACKED_IMAGE",
                            "physical_reclamation_proved_now": False})
        if name == "Q.SetFinalMusic" and isinstance(args[0], str) and "\0" not in args[0]:
            # A leading literal ASCII space is accepted as the clear marker by the
            # adopted authoring policy. Other locale whitespace needs explicit review.
            if args[0] == "":
                effect = "APPEND_ZERO_RETAINS_CURRENT_FINAL_MUSIC"
            elif args[0].startswith(" "):
                effect = "CLEAR_ON_LEADING_ASCII_SPACE"
                issue(warnings, "CTYPE_CONTEXT_UNPROVED", "ASCII-space clear assumes the verified default narrow-character classification; changed locale/ctype state requires separate review", index, 1)
            else:
                effect = "APPEND_NOT_REPLACE_REQUIRES_PRIOR_STATE_REVIEW"
                if args[0][0].isspace():
                    issue(errors, "UNREVIEWED_WHITESPACE", "Only literal ASCII space is adopted as a clear marker; do not generalize Unicode whitespace", index, 1)
            effects.append({"call_index": index, "effect": effect, "immediate_playback": False})
            issue(warnings, "FINAL_MUSIC_STATE", "Setter append/clear/retain and accepted Start assign-clear are distinct; RestoreMap consumption is separate", index)

    return {"schema": "ttr-mef-p0-authoring-review-v1",
            "status": "REJECTED" if errors else "AUTHORING_CONTRACT_PASS_ONLY",
            "format": "NOT_NATIVE_MEF", "target_bin_sha256": BIN_SHA,
            "abi_contract_sha256": abi_pin["sha256"], "calls_checked": len(calls),
            "errors": errors, "warnings": warnings, "declared_native_effects": effects,
            "deployment_ready": False, "gameplay_verified": False,
            "client_executed": False, "lua_executed": False, "server_executed": False,
            "remaining_gates": ["actual typed receiver and legal entry/pump", "real selected resource bytes and complete dependencies",
                                "Client narrow-string encoding, path identity and actual payload bytes",
                                "finalMusic default narrow-character/locale classification when using the ASCII-space clear policy",
                                "prepass/formal correspondence", "same-context owner and exit contract",
                                "existing Server adoption and normal Client play validation"]}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("plan", type=Path)
    parser.add_argument("--repo", type=Path, default=HERE.parents[2])
    args = parser.parse_args()
    try:
        result = validate(strict_loads(args.plan.read_text(encoding="utf-8")), args.repo)
    except (OSError, ValueError, TypeError, KeyError) as error:
        result = {"status": "REJECTED", "errors": [{"code": "INPUT_OR_SOURCE_ERROR", "message": str(error)}],
                  "format": "NOT_NATIVE_MEF", "deployment_ready": False, "gameplay_verified": False,
                  "client_executed": False, "lua_executed": False, "server_executed": False}
    print(json.dumps(result, ensure_ascii=False, indent=2, allow_nan=False))
    return 1 if result["errors"] else 0


if __name__ == "__main__":
    raise SystemExit(main())
