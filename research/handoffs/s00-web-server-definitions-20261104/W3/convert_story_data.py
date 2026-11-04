#!/usr/bin/env python3
"""Convert the supplied W1/W2/W3 evidence package into a reviewable story catalog.

Python 3.9+, standard library only.  This is an offline data conversion, not a
game server, MEF reader, quest interpreter, or native-evidence certification.
See --help.  Input bytes are read only; output must be outside the input tree.
"""
from __future__ import annotations

import argparse
import codecs
import csv
import hashlib
import io
import json
import os
import re
import sys
import tempfile
from collections import Counter, defaultdict
from pathlib import Path, PurePosixPath
from xml.etree import ElementTree as ET


VERSION = "1.0.0"
T16 = "git-evidence/research/handoffs/kr-quest-runtime-20261103-v0.1.0/"
S00 = "git-evidence/governance/s00-iterations/"
ROUTE = S00 + "S00-20261104-ALSMEER-STORY-CONTINUATION.md"
BASELINE = S00 + "evidence/S00-20261104-ALSMEER-RESOURCE-BASELINE.json"
OUTPUT_NAMES = ("story-catalog.json", "source-map.csv", "validation-report.json")
DEFAULT_QUESTS = (117, 118, 119, 120, 121, 122, 123, 124, 131, 132)
SHA256 = re.compile(r"^[0-9a-f]{64}$")
GIT_REF = re.compile(r"^https://github\.com/([^/]+/[^/]+)/blob/([0-9a-f]{40})/(.+)$")
SCENE_KEY = re.compile(r"^(?:scene:)?(\d+)/(\d+)$")
SIMPLE_DOMAINS = {
    "quest", "chapter", "npc", "town", "field", "map", "case", "item",
    "character", "scenario", "quest_rewards_etc_type", "quest_rewards_item_type",
}
EXPECTED_DOMAINS = {
    "quest": "quest", "chapter": "chapter", "chapter_town": "town",
    "npc": "npc", "giver": "npc", "finisher": "npc", "town": "town",
    "field": "field", "case": "case", "map": "map", "scene": "scene",
    "destination_map": "map", "destination_town": "town",
}
SOURCE_MAP_COLUMNS = (
    "output_file", "output_pointer", "input_path", "input_format", "input_pointer",
    "csv_record", "csv_line_start", "csv_line_end", "column", "input_sha256",
    "package_snapshot_commit", "source_ref", "source_sha256", "source_commit",
    "source_git_blob_sha1", "source_member", "carrier_sha256", "evidence_kind",
    "source_availability", "transformation",
)


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def json_bytes(value):
    return (json.dumps(value, ensure_ascii=False, sort_keys=True, indent=2,
                       allow_nan=False) + "\n").encode("utf-8")


def compact(value):
    return json.dumps(value, ensure_ascii=False, sort_keys=True, separators=(",", ":"))


def pointer_part(value):
    return str(value).replace("~", "~0").replace("/", "~1")


def join_pointer(pointer, key):
    return pointer + "/" + pointer_part(key)


def typed(domain, value):
    return None if value is None else {"domain": domain, "value": value}


def value_of(value):
    return value.get("value") if isinstance(value, dict) else None


def scene(quest, index):
    return {"domain": "scene", "quest": typed("quest", quest), "scene_index": index}


def scene_tuple(value):
    if isinstance(value, dict) and value.get("domain") == "scene":
        return (value_of(value.get("quest")), value.get("scene_index"))
    if isinstance(value, str):
        match = SCENE_KEY.fullmatch(value)
        if match:
            return (int(match[1]), int(match[2]))
    return None


def within(path, parent):
    try:
        path.relative_to(parent)
        return True
    except ValueError:
        return False


def walk(value, pointer=""):
    yield pointer, value
    if isinstance(value, dict):
        for key, child in value.items():
            yield from walk(child, join_pointer(pointer, key))
    elif isinstance(value, list):
        for index, child in enumerate(value):
            yield from walk(child, join_pointer(pointer, index))


class Converter:
    def __init__(self, root, selected):
        self.root = root
        self.selected = selected
        self.cache = {}
        self.read_files = {}
        self.issues = []
        self.unknowns = []
        self.maps = []
        self.manifest = {}
        self.manifest_entries = {}
        self.manifest_audit = []
        self.member_audit = []
        self.source_index_audit = []
        self.content_manifest_audit = []
        self.sources = {}
        self.source_status = {}
        self.csv_tables = {}
        self.row_locations = {}
        self.stats = Counter()
        self._issue_keys = set()
        self._unknown_keys = set()

    def issue(self, code, message, path=None, pointer=None, severity="ERROR",
              responsibility="CONVERTER", **details):
        item = {"code": code, "severity": severity, "responsibility": responsibility,
                "message": message, "input_path": path, "input_pointer": pointer}
        item.update(details)
        key = compact(item)
        if key not in self._issue_keys:
            self._issue_keys.add(key)
            self.issues.append(item)

    def unknown(self, code, message, path=None, pointer=None,
                responsibility="SERVER_DEVELOPMENT", **details):
        item = {"code": code, "status": "UNKNOWN", "responsibility": responsibility,
                "message": message, "input_path": path, "input_pointer": pointer}
        item.update(details)
        key = compact(item)
        if key not in self._unknown_keys:
            self._unknown_keys.add(key)
            self.unknowns.append(item)

    def safe_path(self, relative):
        if not isinstance(relative, str) or not relative or "\\" in relative:
            raise ValueError("Expected a nonempty package-relative POSIX path")
        parts = PurePosixPath(relative)
        if parts.is_absolute() or ".." in parts.parts or ":" in parts.parts[0]:
            raise ValueError("Path leaves the package")
        result = (self.root / relative).resolve()
        if not within(result, self.root):
            raise ValueError("Path or symlink leaves the package")
        return result

    def read(self, relative, role, required=True):
        try:
            path = self.safe_path(relative)
            if not path.is_file():
                if required:
                    self.issue("INPUT_FILE_MISSING", "Required input is not in the package.", relative)
                return None
            if relative not in self.cache:
                self.cache[relative] = path.read_bytes()
            data = self.cache[relative]
            record = self.read_files.setdefault(relative, {
                "path": relative, "sha256": sha256(data), "bytes": len(data), "roles": []})
            if role not in record["roles"]:
                record["roles"].append(role)
            return data
        except (OSError, ValueError) as exc:
            self.issue("INPUT_PATH_UNREADABLE", str(exc), relative)
            return None

    def load_json(self, relative, default=None):
        data = self.read(relative, "PARSED_JSON")
        if data is None:
            return default

        def unique_object(pairs):
            result = {}
            for key, value in pairs:
                if key in result:
                    self.issue("DUPLICATE_JSON_MEMBER", "Duplicate JSON object key.",
                               relative, key=key)
                result[key] = value
            return result

        try:
            result = json.loads(data.decode("utf-8-sig"), object_pairs_hook=unique_object,
                                parse_constant=lambda x: (_ for _ in ()).throw(ValueError(x)))
            if default is not None and not isinstance(result, type(default)):
                self.issue("JSON_TOP_LEVEL_TYPE", "JSON root has the wrong container type.", relative,
                           expected_type=type(default).__name__, actual_type=type(result).__name__)
                return default
            return result
        except (ValueError, UnicodeError) as exc:
            self.issue("JSON_PARSE_ERROR", str(exc), relative)
            return default

    def load_text(self, relative):
        data = self.read(relative, "PARSED_TEXT")
        if data is None:
            return ""
        try:
            return data.decode("utf-8-sig")
        except UnicodeError as exc:
            self.issue("TEXT_DECODE_ERROR", str(exc), relative)
            return ""

    def load_xml(self, member):
        relative = "local-resources/" + member
        data = self.read(relative, "PARSED_XML", required=False)
        if data is None:
            self.unknown("RAW_MEMBER_NOT_PROVIDED", "Raw member is unavailable; retain supplied projections.",
                         relative, responsibility="INPUT_COMPLETENESS", member=member)
            return None
        header = re.search(br"encoding\s*=\s*[\"']([^\"']+)[\"']", data[:256], re.I)
        encoding = header[1].decode("ascii") if header else "utf-8"
        if data.startswith(codecs.BOM_UTF8):
            encoding = "utf-8-sig"
        try:
            text = data.decode(encoding)
            if "<!DOCTYPE" in text.upper() or "<!ENTITY" in text.upper():
                raise ValueError("DTD/entity declarations are not supported")
            tree = ET.fromstring(text)
            self.read_files[relative]["decoded_encoding"] = encoding
            return tree
        except (ValueError, LookupError, UnicodeError, ET.ParseError) as exc:
            self.issue("XML_PARSE_ERROR", str(exc), relative)
            return None

    def verify_manifest(self):
        self.manifest = self.load_json("MANIFEST.json", {})
        entries = self.manifest.get("files", [])
        if not isinstance(entries, list):
            self.issue("MANIFEST_SHAPE", "MANIFEST.files must be an array.", "MANIFEST.json", "/files")
            return
        for index, entry in enumerate(entries):
            relative = entry.get("path")
            if relative in self.manifest_entries:
                self.issue("DUPLICATE_MANIFEST_PATH", "Duplicate manifest path.", "MANIFEST.json",
                           f"/files/{index}", duplicated_path=relative)
            self.manifest_entries[relative] = entry
            data = self.read(relative, "HASH_ONLY", required=False)
            actual = sha256(data) if data is not None else None
            expected = entry.get("sha256")
            record = {"path": relative, "manifest_pointer": f"/files/{index}",
                      "expected_sha256": expected, "actual_sha256": actual,
                      "expected_bytes": entry.get("bytes"),
                      "actual_bytes": len(data) if data is not None else None,
                      "classification": entry.get("classification"),
                      "member": entry.get("member"),
                      "carrier_sha256": entry.get("carrier_sha256"),
                      "original_member_sha_match": entry.get("original_member_sha_match"),
                      "status": "MATCH" if data is not None and actual == expected
                      and len(data) == entry.get("bytes") else "MISSING_OR_MISMATCH"}
            self.manifest_audit.append(record)
            if record["status"] != "MATCH":
                self.issue("MANIFEST_INTEGRITY", "Manifest hash/size does not match available bytes.",
                           "MANIFEST.json", f"/files/{index}", file=relative,
                           expected_sha256=expected, actual_sha256=actual)
            if not isinstance(expected, str) or not SHA256.fullmatch(expected):
                self.issue("INVALID_SHA256", "Manifest SHA256 must be 64 lowercase hex digits.",
                           "MANIFEST.json", f"/files/{index}/sha256")
            if entry.get("member", "").startswith("Table/") and entry.get("original_member_sha_match") is not True:
                self.unknown("TABLE_ORIGINAL_MEMBER_UNVERIFIED",
                             "Local bytes match the upload manifest; original-member identity is not established.",
                             "MANIFEST.json", f"/files/{index}/original_member_sha_match",
                             responsibility="INPUT_COMPLETENESS", member=entry["member"],
                             declared_original_match=entry.get("original_member_sha_match"))

    def source_file_candidates(self, source_ref):
        root = source_ref.split("#", 1)[0]
        if "!" in root:
            return ["local-resources/" + root.split("!", 1)[1]]
        match = GIT_REF.fullmatch(root)
        if match:
            if match[1] != "we88ec3-prog/ttr_anal_multi":
                return []
            return ["git-evidence/" + match[3]]
        if root.startswith("evidence/"):
            return [T16 + root]
        if root.startswith(("governance/", "kr/", "kr-temp-roy/", "shared/", "research/")):
            return ["git-evidence/" + root]
        return []

    def verify_sources(self, source_index, source_members, content_manifest, baseline):
        by_hash = defaultdict(list)
        for row in self.manifest_audit:
            if row["status"] == "MATCH":
                by_hash[row["actual_sha256"]].append(row["path"])
        for index, record in enumerate(source_index.get("sources", [])):
            ref = record.get("source_ref", "")
            key = ref.split("#", 1)[0]
            if key in self.sources:
                self.issue("DUPLICATE_SOURCE_REF", "Duplicate source-index reference.",
                           T16 + "source-index.json", f"/sources/{index}", source_ref=ref)
            self.sources[key] = record
            expected = record.get("source_sha")
            if not isinstance(expected, str) or not SHA256.fullmatch(expected):
                self.issue("INVALID_SOURCE_SHA256", "Source SHA256 is not a 64-hex content hash.",
                           T16 + "source-index.json", f"/sources/{index}")
            candidates = self.source_file_candidates(ref)
            present = [(path, self.cache[path]) for path in candidates if path in self.cache]
            exact = [(path, data) for path, data in present if sha256(data) == expected]
            via_hash = sorted(by_hash.get(expected, []))
            if exact:
                path, data = exact[0]
                status = "CONTENT_SHA_MATCH"
            elif via_hash:
                path = via_hash[0]
                data = self.cache[path]
                status = "CONTENT_SHA_MATCH_VIA_OTHER_PACKAGE_PATH"
            else:
                path, data = present[0] if present else (None, None)
                status = "HISTORICAL_VERSION_NOT_PROVIDED" if present else "NOT_IN_PACKAGE"
            audit = {"source_ref": ref, "source_index_pointer": f"/sources/{index}",
                     "expected_sha256": expected, "available_path": path,
                     "available_sha256": sha256(data) if data is not None else None,
                     "status": status, "commit": record.get("commit"),
                     "git_blob_sha1": record.get("git_blob_sha1"),
                     "git_blob_check": "NOT_PERFORMED", "carrier_sha256": record.get("carrier_sha256")}
            if status.startswith("CONTENT_SHA_MATCH") and record.get("git_blob_sha1"):
                actual_blob = hashlib.sha1(b"blob " + str(len(data)).encode("ascii") + b"\0" + data).hexdigest()
                audit["calculated_git_blob_sha1"] = actual_blob
                audit["git_blob_check"] = "MATCH" if actual_blob == record["git_blob_sha1"] else "MISMATCH"
                if audit["git_blob_check"] != "MATCH":
                    self.issue("SOURCE_GIT_BLOB_MISMATCH", "Content SHA matches but Git blob SHA does not.",
                               T16 + "source-index.json", f"/sources/{index}", source_ref=ref)
            self.source_index_audit.append(audit)
            self.source_status[key] = status
            if not status.startswith("CONTENT_SHA_MATCH"):
                self.unknown(status, "The exact referenced source version cannot be rehashed from this package.",
                             T16 + "source-index.json", f"/sources/{index}",
                             responsibility="INPUT_COMPLETENESS", source_ref=ref,
                             expected_sha256=expected, available_path=path,
                             available_sha256=audit["available_sha256"])

        original_by_member = {}
        for index, source in enumerate(source_members):
            member = source.get("member")
            if member in original_by_member:
                self.issue("DUPLICATE_ORIGINAL_MEMBER", "Duplicate original member record.",
                           T16 + "evidence/source-members.json", f"/{index}", member=member)
            original_by_member[member] = source
            local = "local-resources/" + member
            data = self.cache.get(local)
            actual = sha256(data) if data is not None else None
            status = "MATCH" if actual == source.get("sha256") else "NOT_IN_PACKAGE" if data is None else "MISMATCH"
            self.member_audit.append({"origin": "T16_SOURCE_MEMBERS", "pointer": f"/{index}",
                                      "member": member, "expected_sha256": source.get("sha256"),
                                      "actual_sha256": actual, "status": status,
                                      "original_carrier_sha256": source.get("archive_sha256"),
                                      "local_carrier_sha256": self.manifest_entries.get(local, {}).get("carrier_sha256")})
            if status == "MISMATCH":
                self.issue("ORIGINAL_MEMBER_MISMATCH", "Local member differs from the original-member record.",
                           T16 + "evidence/source-members.json", f"/{index}", member=member)
            elif status == "NOT_IN_PACKAGE":
                self.unknown("ORIGINAL_MEMBER_NOT_PROVIDED", "Original member is indexed but absent in this upload.",
                             T16 + "evidence/source-members.json", f"/{index}",
                             responsibility="INPUT_COMPLETENESS", member=member, expected_sha256=source.get("sha256"))
        for entry in self.manifest_entries.values():
            member = entry.get("member", "")
            if not member.startswith("Table/"):
                continue
            original = original_by_member.get(member)
            actual = sha256(self.cache[entry["path"]]) if entry["path"] in self.cache else None
            expected = original.get("sha256") if original else None
            declared = entry.get("original_member_sha_match")
            status = "MATCH" if original and actual == expected else "UNKNOWN_ORIGINAL_MEMBER" if not original else "MISMATCH"
            self.member_audit.append({"origin": "UPLOAD_TABLE_MEMBER", "member": member,
                                      "declared_original_member_sha_match": declared,
                                      "expected_original_sha256": expected, "actual_sha256": actual,
                                      "status": status, "local_carrier_sha256": entry.get("carrier_sha256")})
            if declared is True and status != "MATCH":
                self.issue("ORIGINAL_MATCH_CLAIM_UNCONFIRMED", "Manifest claims an original match that cannot be confirmed.",
                           "MANIFEST.json", member=member)
        for member, expected in baseline.get("sourceMembers", {}).items():
            path = "local-resources/" + member
            actual = sha256(self.cache[path]) if path in self.cache else None
            status = "MATCH" if actual == expected else "NOT_IN_PACKAGE" if actual is None else "MISMATCH"
            self.member_audit.append({"origin": "S00_SOURCE_MEMBERS", "member": member,
                                      "expected_sha256": expected, "actual_sha256": actual, "status": status})
            if status == "MISMATCH":
                self.issue("S00_MEMBER_MISMATCH", "S00 member hash differs from uploaded bytes.", BASELINE,
                           "/sourceMembers/" + pointer_part(member), member=member)
            elif status == "NOT_IN_PACKAGE":
                self.unknown("S00_MEMBER_NOT_PROVIDED", "S00 member is absent.", BASELINE,
                             "/sourceMembers/" + pointer_part(member), responsibility="INPUT_COMPLETENESS", member=member)

        for index, record in enumerate(content_manifest.get("files", [])):
            local = T16 + record.get("path", "")
            data = self.read(local, "HISTORICAL_MANIFEST_HASH_ONLY", required=False)
            expected = record.get("sha256")
            actual = sha256(data) if data is not None else None
            status = "MATCH" if actual == expected else "NOT_IN_PACKAGE" if data is None else "MISMATCH"
            self.content_manifest_audit.append({"path": local, "expected_sha256": expected,
                                                "actual_sha256": actual, "status": status})
            if status == "MISMATCH":
                self.issue("T16_CONTENT_HASH_MISMATCH", "T16 content-manifest mismatch.",
                           T16 + "content-manifest.json", f"/files/{index}", file=local)
            elif status == "NOT_IN_PACKAGE":
                self.unknown("HISTORICAL_PACKAGE_FILE_NOT_PROVIDED",
                             "File belonged to the historical T16 package and is not required to execute this new converter.",
                             T16 + "content-manifest.json", f"/files/{index}",
                             responsibility="INPUT_COMPLETENESS", member=record.get("path"), expected_sha256=expected)

    def load_csvs(self, contracts):
        for contract in contracts.get("tables", []):
            filename = contract.get("file", "")
            path = T16 + filename
            data = self.read(path, "PARSED_CSV")
            rows = []
            self.csv_tables[filename] = rows
            if data is None:
                continue
            try:
                reader = csv.DictReader(io.StringIO(data.decode("utf-8-sig"), newline=""))
                columns = contract.get("columns", [])
                names = [column["name"] for column in columns]
                if reader.fieldnames != names:
                    self.issue("CSV_COLUMNS", "CSV columns/order differ from csv-contracts.json.", path,
                               expected=names, actual=reader.fieldnames)
                if len(reader.fieldnames or []) != len(set(reader.fieldnames or [])):
                    self.issue("DUPLICATE_CSV_COLUMN", "Duplicate CSV column.", path)
                previous_line = reader.line_num
                seen = set()
                for number, raw in enumerate(reader, 1):
                    start_line = previous_line + 1
                    previous_line = reader.line_num
                    row = {}
                    if None in raw or any(value is None for value in raw.values()):
                        self.issue("CSV_ROW_WIDTH", "CSV row has the wrong number of cells.", path,
                                   csv_record=number)
                    for column in columns:
                        name = column["name"]
                        cell = raw.get(name)
                        if cell in ("", None):
                            row[name] = None
                            if column.get("required_nonempty"):
                                self.issue("CSV_REQUIRED_VALUE", "Required CSV cell is empty.", path,
                                           csv_record=number, column=name)
                            continue
                        kind = column["cell_type"]
                        try:
                            if kind == "integer":
                                if not re.fullmatch(r"-?\d+", cell):
                                    raise ValueError("Not an integer literal")
                                value = int(cell)
                            elif kind == "boolean":
                                if cell.lower() not in ("true", "false"):
                                    raise ValueError("Not a true/false literal")
                                value = cell.lower() == "true"
                            elif kind == "json":
                                value = json.loads(cell)
                            elif kind == "string":
                                value = cell
                            else:
                                raise ValueError("Unsupported declared cell type " + kind)
                            row[name] = value
                        except (ValueError, TypeError) as exc:
                            row[name] = cell
                            self.issue("CSV_CELL_TYPE", str(exc), path, csv_record=number,
                                       column=name, declared_type=kind)
                    key = tuple(compact(row.get(key)) for key in contract.get("primary_key", []))
                    if key in seen:
                        self.issue("DUPLICATE_ID", "Duplicate CSV primary key.", path,
                                   csv_record=number, key_fields=contract.get("primary_key"), key=list(key))
                    seen.add(key)
                    self.row_locations[(filename, len(rows))] = {
                        "csv_record": number, "csv_line_start": start_line, "csv_line_end": reader.line_num}
                    rows.append(row)
                self.stats["csv_rows_checked"] += len(rows)
                self.stats["csv_tables_checked"] += 1
            except (UnicodeError, csv.Error) as exc:
                self.issue("CSV_PARSE_ERROR", str(exc), path)

    def index_unique(self, records, getter, path, prefix):
        result = {}
        for index, record in enumerate(records):
            key = getter(record)
            if key is None:
                self.issue("MISSING_ID", "Record has no usable ID.", path, f"{prefix}/{index}")
                continue
            if key in result:
                self.issue("DUPLICATE_ID", "Duplicate canonical ID; first row retained for diagnostics.",
                           path, f"{prefix}/{index}", duplicated_id=key)
                continue
            result[key] = (index, record)
        return result

    def check_equal(self, actual, expected, path, pointer, label):
        self.stats["equality_checks"] += 1
        if actual != expected:
            if isinstance(actual, set):
                actual = sorted(actual)
            if isinstance(expected, set):
                expected = sorted(expected)
            self.issue("PROJECTION_MISMATCH", label, path, pointer, actual=actual, expected=expected)

    def validate_evidence_and_domains(self, value, path):
        for pointer, node in walk(value):
            if not isinstance(node, dict):
                continue
            if "source_ref" in node and "source_sha" in node:
                ref = node.get("source_ref")
                sha = node.get("source_sha")
                root = ref.split("#", 1)[0] if isinstance(ref, str) else ""
                if node.get("source_sha_algorithm") == "git-blob-sha1":
                    # Migration supporting_sources intentionally separate SHA1
                    # object identity from SHA256 content identity.
                    declared_blob = sha
                    sha = node.get("source_content_sha256")
                    if not isinstance(declared_blob, str) or not re.fullmatch(r"[0-9a-f]{40}", declared_blob):
                        self.issue("INVALID_GIT_BLOB_SHA1", "Declared Git blob SHA1 is invalid.", path, pointer)
                    elif root in self.sources and self.sources[root].get("git_blob_sha1") != declared_blob:
                        self.issue("GIT_BLOB_REFERENCE_MISMATCH", "Supporting source Git blob differs from source-index.", path, pointer)
                if not isinstance(sha, str) or not SHA256.fullmatch(sha):
                    self.issue("INVALID_SOURCE_SHA256", "Evidence source_sha is not a SHA256 content hash.",
                               path, pointer)
                elif root not in self.sources:
                    self.issue("UNINDEXED_SOURCE_REFERENCE", "Evidence source is absent from source-index.",
                               path, pointer, source_ref=ref)
                elif self.sources[root].get("source_sha") != sha:
                    self.issue("SOURCE_REFERENCE_SHA_MISMATCH", "Evidence disagrees with source-index SHA256.",
                               path, pointer, source_ref=ref)
                self.stats["source_reference_checks"] += 1
            domain = node.get("domain")
            if "typed_key" in node:
                # id-values has a descriptive domain column surrounding an
                # actual typed_key object; the row itself is not that object.
                if isinstance(node["typed_key"], dict) and node["typed_key"].get("domain") != domain:
                    self.issue("DOMAIN_MIXUP", "ID registry domain column and typed_key disagree.", path, pointer)
                domain = None
            if domain == "opaque token":
                self.unknown("DESCRIPTIVE_TOKEN_NOT_A_TYPED_ID", "Migration metadata describes an opaque token; no numeric identity is invented.", path, pointer, responsibility="CROSS_FUNCTION_INTEGRATION")
                domain = None
            if isinstance(domain, str):
                self.stats["typed_reference_checks"] += 1
                if domain in SIMPLE_DOMAINS:
                    if type(node.get("value")) is not int:
                        self.issue("TYPED_ID_VALUE", "Typed ID value must remain an integer.", path, pointer, domain=domain)
                elif domain == "scene":
                    if not isinstance(node.get("quest"), dict) or node["quest"].get("domain") != "quest" or type(node.get("scene_index")) is not int:
                        self.issue("SCENE_DOMAIN", "Scene must retain its QuestID and scene index.", path, pointer)
                elif domain not in {"portal", "portal_effect", "monster", "formation_token", "runtime_entity", "quest_content"}:
                    self.issue("UNKNOWN_TYPED_DOMAIN", "Unsupported typed domain; not coerced to another ID.", path, pointer, domain=domain)
            for key, expected in EXPECTED_DOMAINS.items():
                child = node.get(key)
                if isinstance(child, dict) and child.get("domain") != expected:
                    self.issue("DOMAIN_MIXUP", "Typed field has the wrong ID domain.", path,
                               join_pointer(pointer, key), expected_domain=expected, actual_domain=child.get("domain"))
            for key, expected in [("quest_refs", "quest"), ("demand_ids", "quest"),
                                  ("unlock_candidates", "quest"), ("source_order", "scene"),
                                  ("owned_character_ids", "character")]:
                for index, child in enumerate(node.get(key, []) or []):
                    if not isinstance(child, dict) or child.get("domain") != expected:
                        self.issue("DOMAIN_MIXUP", "Typed reference list has the wrong ID domain.", path,
                                   join_pointer(join_pointer(pointer, key), index), expected_domain=expected)
            if isinstance(node.get("raw_type"), dict):
                expected = {"RewardsEtc": "quest_rewards_etc_type", "RewardsItem": "quest_rewards_item_type"}.get(node.get("raw_container"))
                if expected and node["raw_type"].get("domain") != expected:
                    self.issue("DOMAIN_MIXUP", "Reward type domain differs from its raw container.", path,
                               pointer + "/raw_type", expected_domain=expected, actual_domain=node["raw_type"].get("domain"))

    def validate_canonical(self, definitions, flows, entries):
        dindex = self.index_unique(definitions, lambda x: value_of(x.get("id")), T16 + "quest-definitions.json", "/definitions")
        findex = self.index_unique(flows, lambda x: x.get("flow_id"), T16 + "quest-flows.json", "/flows")
        eindex = self.index_unique(entries, lambda x: x.get("entry_id"), T16 + "scenario-entries.json", "/entries")
        cindex = self.index_unique(self.csv_tables.get("quest-catalog.csv", []), lambda x: x.get("quest_id"), T16 + "quest-catalog.csv", "/rows")
        wire_ids = {x.get("adapter_id") for x in self.csv_tables.get("quest-wire-map.csv", [])}
        sindex = self.index_unique(self.csv_tables.get("quest-scenes.csv", []), lambda x: (x.get("quest_id"), x.get("scene_index")), T16 + "quest-scenes.csv", "/rows")
        for path, obj in [(T16 + "quest-definitions.json", {"definitions": definitions}),
                          (T16 + "quest-flows.json", {"flows": flows}),
                          (T16 + "scenario-entries.json", {"entries": entries})]:
            self.validate_evidence_and_domains(obj, path)
        for name, rows in self.csv_tables.items():
            self.validate_evidence_and_domains(rows, T16 + name)
        self.check_equal(set(cindex), set(dindex), T16 + "quest-catalog.csv", None,
                         "Canonical Quest IDs and CSV Quest IDs differ.")
        for qid, (di, definition) in dindex.items():
            p = f"/definitions/{di}"
            if definition.get("id", {}).get("domain") != "quest":
                self.issue("DOMAIN_MIXUP", "Definition.id must be a quest.", T16 + "quest-definitions.json", p + "/id")
            sd = definition.get("source_data", {})
            for field, domain in [("demand_ids", "quest")]:
                for item in sd.get(field, []):
                    if item.get("domain") != domain:
                        self.issue("DOMAIN_MIXUP", "Prerequisite is not a QuestID.", T16 + "quest-definitions.json", p + "/source_data/" + field)
                    if value_of(item) not in dindex:
                        self.unknown("QUEST_REFERENCE_NOT_IN_SELECTED_SOURCE_ROWS", "Prerequisite Quest row is not provided; keep external reference.",
                                     T16 + "quest-definitions.json", p + "/source_data/" + field,
                                     responsibility="INPUT_COMPLETENESS", quest_id=qid, referenced_id=item)
            for item in definition.get("unlock_candidates", []):
                if item.get("domain") != "quest":
                    self.issue("DOMAIN_MIXUP", "Successor is not a QuestID.", T16 + "quest-definitions.json", p + "/unlock_candidates")
                if value_of(item) not in dindex:
                    self.unknown("SUCCESSOR_ROW_NOT_PROVIDED", "Successor Quest is outside supplied rows.", T16 + "quest-definitions.json", p + "/unlock_candidates", responsibility="INPUT_COMPLETENESS", quest_id=qid, referenced_id=item)
            expected_successors = {other for other, (_, target) in dindex.items()
                                   if qid in [value_of(x) for x in target.get("source_data", {}).get("demand_ids", [])]}
            declared_successors_in_package = {value_of(x) for x in definition.get("unlock_candidates", []) if value_of(x) in dindex}
            self.check_equal(declared_successors_in_package, expected_successors, T16 + "quest-definitions.json", p + "/unlock_candidates", "Successor candidates disagree with inverse Demands in provided rows.")
            for field, index in [("flow_ref", findex), ("scenario_entry_ref", eindex)]:
                ref = definition.get(field)
                if ref is not None and ref not in index:
                    self.issue("MISSING_REFERENCE", "Canonical reference does not exist.", T16 + "quest-definitions.json", p + "/" + field, referenced_id=ref)
            if definition.get("flow_ref") in findex:
                flow = findex[definition["flow_ref"]][1]
                if qid not in [value_of(x) for x in flow.get("quest_refs", [])]:
                    self.issue("FLOW_QUEST_MISMATCH", "Referenced flow does not list this Quest.", T16 + "quest-definitions.json", p + "/flow_ref")
            if definition.get("scenario_entry_ref") in eindex:
                entry = eindex[definition["scenario_entry_ref"]][1]
                self.check_equal(value_of(entry.get("quest")), qid, T16 + "quest-definitions.json", p + "/scenario_entry_ref", "Scenario entry belongs to another Quest.")
            if definition.get("activation") != "DRAFT_BLOCKED":
                self.issue("UNSUPPORTED_ACTIVATION", "This converter does not approve or enable content; source activation changed.", T16 + "quest-definitions.json", p + "/activation")
            chapter_scenes = []
            for ci, chapter in enumerate(sd.get("chapters", [])):
                for item in chapter.get("source_order", []):
                    skey = scene_tuple(item)
                    chapter_scenes.append(skey)
                    if skey not in sindex:
                        self.issue("MISSING_SCENE_REFERENCE", "Chapter scene is absent from quest-scenes.csv.", T16 + "quest-definitions.json", p + f"/source_data/chapters/{ci}", scene=item)
                    elif skey[0] != qid:
                        self.issue("SCENE_QUEST_MISMATCH", "Chapter binding crosses QuestID.", T16 + "quest-definitions.json", p + f"/source_data/chapters/{ci}")
                    else:
                        row = sindex[skey][1]
                        self.check_equal(row.get("chapter_id"), value_of(chapter.get("chapter")), T16 + "quest-scenes.csv", None, "Scene chapter differs from canonical binding.")
                        self.check_equal(row.get("chapter_town_id"), value_of(chapter.get("chapter_town")), T16 + "quest-scenes.csv", None, "Scene chapter town differs from canonical chapter town.")
            if qid not in cindex:
                continue
            ci, row = cindex[qid]
            expected = {
                "quest_id": qid, "name_ko": definition.get("display_name", {}).get("ko_raw"),
                "name_zh_tw_working": definition.get("display_name", {}).get("zh_tw_working_translation"),
                "quest_type_raw": sd.get("quest_type_raw"), "town_id": value_of(sd.get("town")),
                "field_id": value_of(sd.get("field")), "level_raw": sd.get("level_raw"),
                "giver_npc_id": value_of(sd.get("giver")), "finisher_npc_id": value_of(sd.get("finisher")),
                "demands": [value_of(x) for x in sd.get("demand_ids", [])],
                "demand_operator_raw": sd.get("demand_operator_raw"),
                "chapter_ids": [value_of(x.get("chapter")) for x in sd.get("chapters", [])],
                "chapter_town_ids": [value_of(x.get("chapter_town")) for x in sd.get("chapters", [])],
                "scene_keys": [f"{x[0]}/{x[1]}" for x in chapter_scenes],
                "contents_presence": "PRESENT" if sd.get("contents_present") else "ABSENT",
                "accept_action_raw": sd.get("accept_action_raw"), "complete_action_raw": sd.get("complete_action_raw"),
                "quest_talk_presence": "PRESENT" if sd.get("quest_talk_row_present") else "ABSENT",
                "flow_ref": definition.get("flow_ref"), "activation": definition.get("activation"),
            }
            if definition.get("scenario_entry_ref") in eindex:
                entry = eindex[definition["scenario_entry_ref"]][1]
                expected["case_id_candidate"] = value_of(entry.get("case"))
                expected["case_join_status"] = {
                    "QUEST_FIELD_EQUALS_CASE_STAGE_CANDIDATE": "CANDIDATE_BY_FIELD_EQUALS_CASE_STAGE"
                }.get(entry.get("join_kind"), entry.get("join_kind"))
            else:
                expected["case_id_candidate"] = None
                expected["case_join_status"] = None
            for field, value in expected.items():
                self.check_equal(row.get(field), value, T16 + "quest-catalog.csv", f"/rows/{ci}/{field}", "CSV/canonical field projection differs.")

        for filename in ("quest-objectives.csv", "quest-rewards.csv", "quest-scenes.csv", "quest-npc-scenes.csv", "quest-scenario-entries.csv"):
            for index, row in enumerate(self.csv_tables.get(filename, [])):
                if row.get("quest_id") not in dindex:
                    self.issue("MISSING_QUEST_REFERENCE", "CSV row refers to a missing Quest.", T16 + filename, f"/rows/{index}", quest_id=row.get("quest_id"))
        for (qid, si), (index, row) in sindex.items():
            if scene_tuple(row.get("scene_key")) != (qid, si):
                self.issue("SCENE_KEY_MISMATCH", "Scene key, QuestID, and scene index disagree.", T16 + "quest-scenes.csv", f"/rows/{index}")
        expected_scene_keys = {scene_tuple(item) for _, definition in dindex.values()
                               for chapter in definition.get("source_data", {}).get("chapters", [])
                               for item in chapter.get("source_order", [])}
        self.check_equal(set(sindex), expected_scene_keys, T16 + "quest-scenes.csv", None,
                         "Canonical chapter/CSV scene membership key sets differ.")
        expected_associations = {(qid, role, skey) for skey in sindex for qid in [skey[0]]
                                 for role in ("giver", "finisher")
                                 if qid in dindex and dindex[qid][1].get("source_data", {}).get(role) is not None}
        actual_associations = {(row.get("quest_id"), row.get("npc_role"), scene_tuple(row.get("scene_key")))
                               for row in self.csv_tables.get("quest-npc-scenes.csv", [])}
        self.check_equal(actual_associations, expected_associations, T16 + "quest-npc-scenes.csv", None,
                         "Quest/role/scene membership projections are missing or extra.")
        for index, row in enumerate(self.csv_tables.get("quest-npc-scenes.csv", [])):
            qid = row.get("quest_id")
            skey = scene_tuple(row.get("scene_key"))
            if skey not in sindex:
                self.issue("MISSING_SCENE_REFERENCE", "NPC association points to a missing scene.", T16 + "quest-npc-scenes.csv", f"/rows/{index}")
            elif skey[0] != qid:
                self.issue("SCENE_QUEST_MISMATCH", "NPC association scene belongs to another Quest, even if the NPC is shared.", T16 + "quest-npc-scenes.csv", f"/rows/{index}/scene_key", quest_id=qid, scene_quest_id=skey[0])
            if qid in dindex:
                role = row.get("npc_role")
                expected_npc = value_of(dindex[qid][1].get("source_data", {}).get(role))
                if role in ("giver", "finisher"):
                    self.check_equal(row.get("npc_id"), expected_npc, T16 + "quest-npc-scenes.csv", f"/rows/{index}/npc_id", "NPC role projection disagrees with definition.")

        object_lookup = {}
        for qid, (_, definition) in dindex.items():
            for group, keyfield in [("objectives", "objective_key"), ("rewards", "reward_key")]:
                for obj in definition.get(group, []):
                    key = (group, qid, obj.get(keyfield))
                    if key in object_lookup:
                        self.issue("DUPLICATE_ID", "Duplicate objective/reward key.", T16 + "quest-definitions.json", duplicated_id=key)
                    object_lookup[key] = obj
        for filename, group, keyfield in [("quest-objectives.csv", "objectives", "objective_key"), ("quest-rewards.csv", "rewards", "reward_key")]:
            expected_keys = {(qid, key) for (kind, qid, key) in object_lookup if kind == group}
            if group == "rewards":
                expected_keys.update((qid, f"q{qid}.reward_policy") for qid, (_, definition) in dindex.items() if definition.get("rewards") == [])
            actual_keys = {(row.get("quest_id"), row.get(keyfield)) for row in self.csv_tables.get(filename, [])}
            self.check_equal(actual_keys, expected_keys, T16 + filename, None, "Canonical/CSV projection key sets differ; a row is missing or extra.")
            for index, row in enumerate(self.csv_tables.get(filename, [])):
                obj = object_lookup.get((group, row.get("quest_id"), row.get(keyfield)))
                if obj is None:
                    qid = row.get("quest_id")
                    definition = dindex.get(qid, (None, {}))[1]
                    if group == "rewards" and row.get("reward_key") == f"q{qid}.reward_policy" and definition.get("rewards") == []:
                        # Explicit placeholder for an unbound reward plan is
                        # part of this CSV contract, not an actual reward row.
                        self.check_equal(row.get("status"), definition.get("reward_policy_status"), T16 + filename, f"/rows/{index}/status", "Reward-policy placeholder status differs.")
                        for field in ("raw_container", "raw_type", "raw_value", "raw_item", "raw_count", "grant_domain", "recipient_scope", "publication_adapter_id"):
                            self.check_equal(row.get(field), None, T16 + filename, f"/rows/{index}/{field}", "Reward-policy placeholder must not invent a grant value.")
                        continue
                    self.issue("MISSING_REFERENCE", "CSV objective/reward has no canonical object.", T16 + filename, f"/rows/{index}")
                    continue
                for field, actual in row.items():
                    if field == "quest_id":
                        continue
                    if field in ("source_ref", "source_sha", "evidence_kind", "unknowns"):
                        expected = obj.get("source", {}).get(field)
                    else:
                        expected = obj.get(field)
                    self.check_equal(actual, expected, T16 + filename, f"/rows/{index}/{field}", "CSV objective/reward projection differs.")

        node_lookup = {}
        for flowid, (fi, flow) in findex.items():
            path = T16 + "quest-flows.json"
            prefix = f"/flows/{fi}"
            nodes = self.index_unique(flow.get("nodes", []), lambda x: x.get("node_id"), path, prefix + "/nodes")
            for qi, reference in enumerate(flow.get("quest_refs", [])):
                if reference.get("domain") != "quest":
                    self.issue("DOMAIN_MIXUP", "Flow.quest_refs must contain QuestIDs.", path, prefix + f"/quest_refs/{qi}")
                elif value_of(reference) not in dindex:
                    self.issue("MISSING_QUEST_REFERENCE", "Flow QuestID is absent from canonical definitions.", path, prefix + f"/quest_refs/{qi}")
            if flow.get("entry_node") not in nodes:
                self.issue("MISSING_ENTRY_NODE", "Flow entry node does not exist.", path, prefix + "/entry_node")
            if flow.get("activation") != "DRAFT_BLOCKED":
                self.issue("UNSUPPORTED_ACTIVATION", "Flow activation cannot be promoted by this converter.", path, prefix + "/activation")
            for nodeid, (ni, node) in nodes.items():
                node_lookup[(flowid, nodeid)] = node
                for edge in node.get("next", []):
                    if edge.get("to") not in nodes:
                        self.issue("MISSING_NODE_REFERENCE", "Flow edge points outside its flow.", path, prefix + f"/nodes/{ni}/next", target=edge.get("to"))
                adapter = (node.get("wait") or {}).get("wire_adapter_id")
                if adapter is not None and adapter not in wire_ids:
                    self.issue("MISSING_ADAPTER_REFERENCE", "Flow wait references an absent wire adapter.", path, prefix + f"/nodes/{ni}/wait", adapter_id=adapter)
                for pp, obj in walk(node.get("input", {})):
                    if isinstance(obj, dict) and obj.get("domain") == "scene" and scene_tuple(obj) not in sindex:
                        self.issue("MISSING_SCENE_REFERENCE", "Flow input scene is absent.", path, prefix + f"/nodes/{ni}/input" + pp, scene=obj)
        self.check_equal({(row.get("flow_id"), row.get("node_id")) for row in self.csv_tables.get("quest-nodes.csv", [])},
                         set(node_lookup), T16 + "quest-nodes.csv", None, "Canonical/CSV flow-node key sets differ.")
        self.check_equal({row.get("entry_id") for row in self.csv_tables.get("quest-scenario-entries.csv", [])},
                         set(eindex), T16 + "quest-scenario-entries.csv", None, "Canonical/CSV Scenario key sets differ.")
        for entryid, (ei, entry) in eindex.items():
            if entry.get("status") != "DRAFT_BLOCKED" or entry.get("quest_completion_on_instance_result") is not False:
                self.issue("UNSUPPORTED_SCENARIO_ACTIVATION", "Scenario must preserve blocked status and must not turn instance result into Quest completion.", T16 + "scenario-entries.json", f"/entries/{ei}")
            if value_of(entry.get("quest")) not in dindex:
                self.issue("MISSING_QUEST_REFERENCE", "Scenario QuestID is absent from definitions.", T16 + "scenario-entries.json", f"/entries/{ei}/quest")
        for index, row in enumerate(self.csv_tables.get("quest-nodes.csv", [])):
            node = node_lookup.get((row.get("flow_id"), row.get("node_id")))
            if node is None:
                self.issue("MISSING_NODE_REFERENCE", "CSV node has no canonical flow/node.", T16 + "quest-nodes.csv", f"/rows/{index}")
                continue
            for field, actual in row.items():
                if field == "flow_id":
                    continue
                if field in ("source_ref", "source_sha", "evidence_kind"):
                    expected = node.get("source", {}).get(field)
                elif field == "unknowns":
                    expected = node.get("unknowns")
                else:
                    expected = node.get({"precondition": "preconditions", "wait_receipt": "wait"}.get(field, field))
                self.check_equal(actual, expected, T16 + "quest-nodes.csv", f"/rows/{index}/{field}", "CSV flow node projection differs.")
        for index, row in enumerate(self.csv_tables.get("quest-scenario-entries.csv", [])):
            entry = eindex.get(row.get("entry_id"), (None, None))[1]
            if entry is None:
                self.issue("MISSING_REFERENCE", "CSV scenario has no canonical entry.", T16 + "quest-scenario-entries.csv", f"/rows/{index}")
                continue
            for field, actual in row.items():
                if field in ("source_ref", "source_sha", "evidence_kind", "unknowns"):
                    continue  # Combined provenance is preserved, not flattened to provenance[0].
                if field in ("quest_id", "field_id", "case_id"):
                    expected = value_of(entry.get(field[:-3]))
                else:
                    expected = entry.get(field)
                self.check_equal(actual, expected, T16 + "quest-scenario-entries.csv", f"/rows/{index}/{field}", "CSV scenario projection differs.")
        return dindex, findex, eindex, cindex, sindex

    def add_map(self, output_pointer, input_path, input_pointer="", source=None,
                kind="JSON_POINTER", transformation="COPY_PRESERVING_SOURCE_STATUS", row=None, column=None):
        source = source if isinstance(source, dict) else {}
        ref = source.get("source_ref", "")
        root = ref.split("#", 1)[0] if isinstance(ref, str) else ""
        index = self.sources.get(root, {})
        match = GIT_REF.fullmatch(root)
        member = root.split("!", 1)[1] if "!" in root else ""
        entry = self.manifest_entries.get("local-resources/" + member, {})
        record = dict.fromkeys(SOURCE_MAP_COLUMNS, "")
        record.update({"output_file": "story-catalog.json", "output_pointer": output_pointer,
                       "input_path": input_path, "input_format": kind, "input_pointer": input_pointer,
                       "input_sha256": self.read_files.get(input_path, {}).get("sha256", ""),
                       "package_snapshot_commit": self.manifest.get("source_analysis_commit", ""),
                       "source_ref": ref, "source_sha256": source.get("source_sha", ""),
                       "source_commit": index.get("commit") or (match[2] if match else ""),
                       "source_git_blob_sha1": index.get("git_blob_sha1", ""), "source_member": member,
                       "carrier_sha256": index.get("carrier_sha256") or entry.get("carrier_sha256", ""),
                       "evidence_kind": source.get("evidence_kind", "EXISTING_EVIDENCE_PROJECTION"),
                       "source_availability": self.source_status.get(root, "INPUT_FILE_HASHED; ORIGINAL_SOURCE_NOT_ASSERTED"),
                       "transformation": transformation})
        if row is not None:
            record.update(row)
        if column is not None:
            record["column"] = column
        self.maps.append(record)

    def map_tree(self, value, out, path, ptr, inherited=None):
        source = inherited
        if isinstance(value, dict):
            if isinstance(value.get("source"), dict):
                source = value["source"]
            elif "source_ref" in value and "source_sha" in value:
                source = value
        if isinstance(value, dict) and value:
            for key, child in value.items():
                self.map_tree(child, join_pointer(out, key), path, join_pointer(ptr, key), source)
        elif isinstance(value, list) and value:
            for index, child in enumerate(value):
                self.map_tree(child, join_pointer(out, index), path, join_pointer(ptr, index), source)
        else:
            self.add_map(out, path, ptr, source=source)

    def map_csv(self, row, out, filename, index):
        source = {key: row.get(key) for key in ("source_ref", "source_sha", "evidence_kind")}
        for column in row:
            self.add_map(join_pointer(out, column), T16 + filename, source=source,
                         kind="CSV_CELL", row=self.row_locations.get((filename, index)), column=column,
                         transformation="CSV_CONTRACT_PARSE; EMPTY_CELL_TO_NULL")

    def collect_unknowns(self, value, path, prefix, quest_id=None):
        for pp, obj in walk(value, prefix):
            if isinstance(obj, dict) and {"code", "field", "responsibility", "reason"}.issubset(obj):
                responsibility = {"SERVER_DESIGN": "SERVER_DEVELOPMENT", "INTEGRATION": "CROSS_FUNCTION_INTEGRATION"}.get(obj["responsibility"], obj["responsibility"])
                message = obj["reason"]
                annotations = {}
                if obj["code"] == "MAP_GRAPH_RESOURCE_MISSING":
                    supplemental = []
                    for field in ("mapflow_member", "cluster_member"):
                        member = value.get(field) if isinstance(value, dict) else None
                        if not isinstance(member, str):
                            continue
                        local = "local-resources/" + member
                        data = self.cache.get(local)
                        expected = self.manifest_entries.get(local, {}).get("sha256")
                        actual = sha256(data) if data is not None else None
                        supplemental.append({"member": member, "input_path": local,
                                             "expected_upload_sha256": expected, "actual_sha256": actual,
                                             "availability": "PRESENT_HASH_MATCH" if actual is not None and actual == expected
                                             else "NOT_IN_PACKAGE" if actual is None else "HASH_MISMATCH"})
                    message = "Historical T16 snapshot blocker retained unchanged; it does not describe current supplemental-member availability. See current_package_members. Available supplemental bytes do not enable the T16 package or establish runtime trigger/completion semantics."
                    annotations = {"blocker_scope": "HISTORICAL_T16_SNAPSHOT",
                                   "original_source_reason": obj["reason"],
                                   "current_package_members": supplemental,
                                   "original_blocking_issue_preserved": True,
                                   "activation": "DRAFT_BLOCKED"}
                self.unknown(obj["code"], message, path, pp, responsibility=responsibility,
                             quest_id=quest_id, unresolved_field=obj["field"], unblock_evidence=obj.get("unblock_evidence"),
                             **annotations)
            if isinstance(obj, dict) and obj.get("op") == "predicate":
                self.unknown("PREDICATE_REQUIRES_IMPLEMENTATION",
                             "Predicate and arguments are preserved; this converter supplies no runtime evaluator or approval.",
                             path, pp, quest_id=quest_id, predicate=obj.get("name"), args=obj.get("args"))
            if isinstance(obj, dict) and "op" in obj and obj.get("op") not in ("predicate", "all", "any", "not"):
                self.unknown("UNSUPPORTED_CONDITION_OPERATOR", "Unknown condition operator is retained without interpretation.",
                             path, pp, responsibility="CROSS_FUNCTION_INTEGRATION", quest_id=quest_id, operator=obj.get("op"))
            if isinstance(obj, dict) and isinstance(obj.get("unknowns"), list):
                for ui, message in enumerate(obj["unknowns"]):
                    self.unknown("INHERITED_SOURCE_UNKNOWN", message, path, pp + f"/unknowns/{ui}",
                                 responsibility="AS_CLASSIFIED_BY_SOURCE", quest_id=quest_id,
                                 source_ref=obj.get("source_ref"), evidence_kind=obj.get("evidence_kind"))
            if obj is None and any(token in pp.split("/") for token in (
                "policy", "objectives", "settlement", "rewards", "completion_rule_ref", "admission_policy_ref",
                "allowed_formation_policy_ref", "geometry_binding_ref", "multiplayer_party_contract")):
                self.unknown("UNBOUND_FIELD_RETAINED", "Source null is preserved; no zero/default/no-reward policy is inferred.",
                             path, pp, quest_id=quest_id)

    def parse_route(self, text):
        routes = {}
        for number, line in enumerate(text.splitlines(), 1):
            cells = [cell.strip() for cell in line.strip().strip("|").split("|")]
            if len(cells) != 3 or not cells[0].isdigit():
                continue
            qid = int(cells[0])
            if qid in routes:
                self.issue("DUPLICATE_ROUTE_ID", "Duplicate Quest in S00 route table.", ROUTE, f"line:{number}", quest_id=qid)
                continue
            npc_match = re.match(r"(\d+)", cells[1])
            routes[qid] = {"line": number, "npc": int(npc_match[1]) if npc_match else None,
                           "npc_label": cells[1], "description": cells[2]}
        if not routes:
            self.issue("ROUTE_TABLE_MISSING", "No supported Quest/NPC/route Markdown table was found.", ROUTE)
        return routes

    def verify_raw_resources(self, dindex, cindex, baseline):
        # Re-read only bounded members explicitly supplied by this work package.
        map_tree = self.load_xml("Table/_MapList.xml")
        case_tree = self.load_xml("Table/_CaseList.xml")
        town_tree = self.load_xml("Table/_TownList.xml")
        quest_tree = self.load_xml("Table/QuestInfo.xml")

        def xml_index(tree, tag, attribute, member):
            records = {}
            if tree is None:
                return records
            for node in tree.findall(tag):
                key = node.get(attribute)
                if key in records:
                    self.issue("DUPLICATE_XML_ID", "Duplicate raw XML ID.", "local-resources/" + member, key=key)
                records[key] = node
            return records

        raw_maps = xml_index(map_tree, "MAP", "ID", "Table/_MapList.xml")
        raw_cases = xml_index(case_tree, "CASE", "ID", "Table/_CaseList.xml")
        raw_towns = xml_index(town_tree, "TOWN", "ID", "Table/_TownList.xml")
        raw_quests = xml_index(quest_tree, "Quest", "id", "Table/QuestInfo.xml")
        for qid in self.selected:
            definition = dindex.get(qid, (None, {}))[1]
            sd = definition.get("source_data", {})
            raw = raw_quests.get(str(qid))
            if raw is None:
                self.issue("RAW_QUEST_REFERENCE_MISSING", "Selected Quest is absent from the supplied QuestInfo member.", "local-resources/Table/QuestInfo.xml", quest_id=qid)
                continue
            self.check_equal(sd.get("raw_attributes"), dict(raw.attrib), T16 + "quest-definitions.json", None, "Canonical Quest attributes differ from the actual raw member.")
            for raw_key, key, is_typed in [("id", "id", True), ("town", "town", True),
                                           ("field", "field", True), ("giver", "giver", True),
                                           ("finisher", "finisher", True), ("type", "quest_type_raw", False),
                                           ("subtype", "subtype_raw", False), ("level", "level_raw", False)]:
                raw_value = int(raw.get(raw_key)) if raw.get(raw_key) is not None else None
                actual = value_of(definition.get("id")) if key == "id" else value_of(sd.get(key)) if is_typed else sd.get(key)
                self.check_equal(actual, raw_value, T16 + "quest-definitions.json", f"/definitions/{dindex[qid][0]}/source_data/{key}", "Typed/raw scalar differs from actual QuestInfo attribute.")
            self.check_equal(definition.get("display_name", {}).get("ko_raw"), raw.get("subject"), T16 + "quest-definitions.json", f"/definitions/{dindex[qid][0]}/display_name/ko_raw", "Korean raw name differs from QuestInfo.")
            for tag, key in [("Contents", "contents_present"), ("RewardsEtc", "reward_etc_present"), ("RewardsItem", "reward_items_present")]:
                self.check_equal(sd.get(key), raw.find(tag) is not None, T16 + "quest-definitions.json", f"/definitions/{dindex[qid][0]}/source_data/{key}", "Raw source-node presence was changed in the canonical projection.")
            for tag, key in [("AcceptAction", "accept_action_raw"), ("CompleteAction", "complete_action_raw")]:
                element = raw.find(tag)
                actual = None if element is None else dict(element.attrib)
                self.check_equal(sd.get(key), actual, T16 + "quest-definitions.json", f"/definitions/{dindex[qid][0]}/source_data/{key}", "Action metadata differs from actual QuestInfo node.")
            reward_etc = raw.find("RewardsEtc")
            reward_items = raw.find("RewardsItem")
            raw_reward_rows = []
            if reward_etc is not None:
                for reward in reward_etc.findall("Reward"):
                    raw_reward_rows.append(("RewardsEtc", int(reward.get("type")), int(reward.get("value")), None, None))
            if reward_items is not None:
                for reward in reward_items.findall("Item"):
                    raw_reward_rows.append(("RewardsItem", int(reward_items.get("type")), None, int(reward.get("idx")), int(reward.get("value"))))
            canonical_reward_rows = [(x.get("raw_container"), value_of(x.get("raw_type")), x.get("raw_value"), x.get("raw_item"), x.get("raw_count")) for x in definition.get("rewards", [])]
            self.check_equal(canonical_reward_rows, raw_reward_rows, T16 + "quest-definitions.json", f"/definitions/{dindex[qid][0]}/rewards", "Canonical reward metadata differs from actual QuestInfo; display channels are not grant policy.")
            if qid in cindex:
                ci, row = cindex[qid]
                raw_etc_projection = None if reward_etc is None else {"attributes": dict(reward_etc.attrib), "rewards": [dict(x.attrib) for x in reward_etc.findall("Reward")]}
                self.check_equal(row.get("raw_reward_etc"), raw_etc_projection, T16 + "quest-catalog.csv", f"/rows/{ci}/raw_reward_etc", "CSV reward metadata differs from actual QuestInfo.")
                start, end = row.get("decoded_byte_start"), row.get("decoded_byte_end_exclusive")
                data = self.cache.get("local-resources/Table/QuestInfo.xml")
                if data is not None and type(start) is int and type(end) is int and 0 <= start <= end <= len(data):
                    self.check_equal(sha256(data[start:end]), row.get("row_sha256"), T16 + "quest-catalog.csv", f"/rows/{ci}/row_sha256", "Quest row byte range does not reproduce row_sha256.")
                else:
                    self.issue("QUEST_ROW_BYTE_RANGE", "Quest row byte range is missing or outside the source bytes.", T16 + "quest-catalog.csv", f"/rows/{ci}")
            demand_node = raw.find("Demands")
            demands = [] if demand_node is None else [int(x.get("id")) for x in demand_node if x.get("id") is not None]
            self.check_equal(demands, [value_of(x) for x in sd.get("demand_ids", [])], "local-resources/Table/QuestInfo.xml", f"/QuestInfo/Quest[@id='{qid}']/Demands", "Demand projection differs from raw Quest row.")

        self.index_unique(baseline.get("scenarios", []), lambda x: x.get("case"), BASELINE, "/scenarios")
        self.index_unique(baseline.get("maps", []), lambda x: x.get("map"), BASELINE, "/maps")
        case_resources = []
        for bi, scenario_data in enumerate(baseline.get("scenarios", [])):
            cid = scenario_data.get("case")
            field = scenario_data.get("field")
            raw = raw_cases.get(str(cid))
            if raw is not None:
                self.check_equal(raw.get("STAGE"), str(field), BASELINE, f"/scenarios/{bi}/field", "S00 Field/Case STAGE relation differs from raw Case metadata.")
                self.check_equal(raw.get("MAPFLOW"), scenario_data.get("mapFlow"), BASELINE, f"/scenarios/{bi}/mapFlow", "S00 mapflow differs from raw Case metadata.")
                self.check_equal(raw.get("CLUSTER"), scenario_data.get("cluster"), BASELINE, f"/scenarios/{bi}/cluster", "S00 cluster differs from raw Case metadata.")
            else:
                self.issue("MISSING_CASE_REFERENCE", "S00 Case is absent from the raw Case table.", BASELINE, f"/scenarios/{bi}/case", case_id=cid)
            chart_member = "Field/MapFlow/" + str(scenario_data.get("mapFlow"))
            cluster_member = "Field/Cluster/" + str(scenario_data.get("cluster"))
            chart = self.load_xml(chart_member)
            cluster = self.load_xml(cluster_member)
            chart_nodes = []
            edges = []
            if chart is not None:
                for node in chart.findall("./NodeList/Node"):
                    chart_nodes.append({"source_node_id": int(node.get("id")),
                                        "map_choices": [{"map": typed("map", int(x.get("id"))), "percent_raw": x.get("percent")} for x in node.findall("Map")],
                                        "editor_coordinates_raw": {key: node.get(key) for key in ("x", "y", "arrayx", "arrayy")}})

                def visit(node, parent=None):
                    current = int(node.get("id"))
                    if parent is not None:
                        edges.append({"from_source_node": parent, "to_source_node": current,
                                      "trigger_policy": None, "status": "RESOURCE_LINK_ONLY"})
                    for child in node.findall("Node"):
                        visit(child, current)

                for start in chart.findall("./NodeLink/Node"):
                    visit(start)
            by_node = self.index_unique(chart_nodes, lambda x: x.get("source_node_id"), "local-resources/" + chart_member, "/NodeList")
            edge_keys = {(x["from_source_node"], x["to_source_node"]) for x in edges}
            for edge in edges:
                if edge["from_source_node"] not in by_node or edge["to_source_node"] not in by_node:
                    self.issue("MISSING_CHART_NODE", "MapChart edge references an unknown node.", "local-resources/" + chart_member, edge=edge)
            raw_clusters = []
            if cluster is not None:
                for cluster_set in cluster.findall("CLUSTERSET"):
                    for group in cluster_set.findall("CLUSTER"):
                        raw_clusters.append({"cluster_set_id": int(cluster_set.get("ID")),
                                             "cluster": int(group.get("ID")),
                                             "members": [{"model": int(x.get("ID")), "pre": int(x.get("PRE")), "count": int(x.get("COUNT"))} for x in group.findall("OBJECT")]})
            self.index_unique(raw_clusters, lambda x: (x["cluster_set_id"], x["cluster"]), "local-resources/" + cluster_member, "/CLUSTERSET/CLUSTER")
            source_clusters = scenario_data.get("sourceClusters", [])
            if cluster is not None:
                projected = [{"cluster": x["cluster"], "members": x["members"]} for x in raw_clusters]
                self.check_equal(projected, source_clusters, BASELINE, f"/scenarios/{bi}/sourceClusters", "S00 raw cluster projection differs from uploaded Cluster XML.")
            cluster_ids = {x["cluster"] for x in raw_clusters}
            nodes = scenario_data.get("nodes", [])
            for ni, node in enumerate(nodes):
                node_id = node.get("sourceNode")
                map_id = node.get("map")
                if node_id not in by_node:
                    self.issue("MISSING_CHART_NODE", "S00 candidate refers to an absent MapChart node.", BASELINE, f"/scenarios/{bi}/nodes/{ni}")
                elif map_id not in [value_of(x.get("map")) for x in by_node[node_id][1]["map_choices"]]:
                    self.issue("NODE_MAP_MISMATCH", "S00 node/MapID does not match raw MapChart.", BASELINE, f"/scenarios/{bi}/nodes/{ni}")
                if str(map_id) not in raw_maps:
                    self.issue("MISSING_MAP_REFERENCE", "Scenario MapID is absent from _MapList.", BASELINE, f"/scenarios/{bi}/nodes/{ni}/map", map_id=map_id)
                if node.get("selectedCluster") not in cluster_ids:
                    self.issue("MISSING_CLUSTER_REFERENCE", "S00 selected cluster is not in the supplied Cluster member.", BASELINE, f"/scenarios/{bi}/nodes/{ni}/selectedCluster")
                if ni and (nodes[ni - 1].get("sourceNode"), node_id) not in edge_keys:
                    self.issue("CHART_ORDER_MISMATCH", "S00 ordered candidate nodes do not follow a declared directed Chart edge.", BASELINE, f"/scenarios/{bi}/nodes/{ni}")
            case_resources.append({
                "case": typed("case", cid), "field_metadata": typed("field", field),
                "mapflow_member": chart_member, "cluster_member": cluster_member,
                "resource_graph": {"nodes_in_file_order": chart_nodes, "directed_edges": edges,
                                   "classification": "RAW_RESOURCE_LINKS_NOT_RUNTIME_TRANSITIONS"},
                "s00_candidate_selection": scenario_data,
                "s00_candidate_selection_classification": "SERVER_CANDIDATE_NOT_NATIVE_MEF",
                "native_spawn_positions": None, "native_victory_condition": None,
                "status": "DRAFT_BLOCKED", "baseline_pointer": f"/scenarios/{bi}",
            })
        for index, entry in enumerate(baseline.get("maps", [])):
            mapid = entry.get("map")
            raw = raw_maps.get(str(mapid))
            if raw is None:
                self.issue("MISSING_MAP_REFERENCE", "S00 map has no raw _MapList row.", BASELINE, f"/maps/{index}", map_id=mapid)
            else:
                self.check_equal(raw.get("MAP"), entry.get("model"), BASELINE, f"/maps/{index}/model", "Map model differs from raw MapList.")
                self.check_equal(str(raw.get("BOUND")) + ".bnd", entry.get("bound"), BASELINE, f"/maps/{index}/bound", "Map bound name differs from raw MapList.")
            self.unknown("BOUND_BYTES_NOT_IN_PACKAGE", "BND hash and positions are S00 evidence only; no BND bytes are in this package.",
                         BASELINE, f"/maps/{index}", responsibility="INPUT_COMPLETENESS",
                         map_id=mapid, bound_name=entry.get("bound"), expected_sha256=entry.get("sha256"),
                         carrier_sha256=baseline.get("carriers", {}).get("bounds"))
        return case_resources, raw_maps, raw_towns, raw_cases, raw_quests

    def validate_relations(self, dindex, eindex, sindex, raw_maps, raw_towns, raw_cases, raw_quests):
        relation_domains = {
            "declares_demand": ("quest", "quest"), "declares_field": ("quest", "field"),
            "declares_giver": ("quest", "npc"), "declares_finisher": ("quest", "npc"),
            "declares_town": ("quest", "town"), "member_of_chapter": ("quest", "chapter"),
            "declares_scene_member": ("quest", "scene"), "declares_stage": ("case", "field"),
            "candidate_case_by_stage_equality": ("field", "case"),
            "references_cluster": ("case", "resource_member"), "references_mapflow": ("case", "resource_member"),
            "declares_bound": ("map", "resource_name"), "declares_map": ("map", "resource_name"),
            "declares_trigger": ("map", "resource_name"), "selects_map_resource": ("scenario_node", "map"),
            "binds_func_sequence": ("scene", "sequence_member"), "lists_npc": ("town", "npc"),
        }
        known = defaultdict(set)
        for domain, records in [("map", raw_maps), ("case", raw_cases), ("town", raw_towns), ("quest", raw_quests)]:
            known[domain].update(str(key) for key in records)
        for _, definition in dindex.values():
            sd = definition.get("source_data", {})
            for key, domain in [("field", "field"), ("giver", "npc"), ("finisher", "npc")]:
                if value_of(sd.get(key)) is not None:
                    known[domain].add(str(value_of(sd[key])))
            known["chapter"].update(str(value_of(x.get("chapter"))) for x in sd.get("chapters", []))
        known["scene"].update(f"{quest}/{index}" for quest, index in sindex)
        for row in self.csv_tables.get("id-values.csv", []):
            key = row.get("typed_key")
            if row.get("presence") == "PRESENT" and isinstance(key, dict) and "value" in key:
                known[key.get("domain")].add(str(key["value"]))
        for node in raw_cases.values():
            if node.get("STAGE") is not None:
                known["field"].add(node.get("STAGE"))
        for node in raw_towns.values():
            known["npc"].update(x.get("ID") for x in node.findall("./NPCLIST/NPC"))
        for index, row in enumerate(self.csv_tables.get("id-relations.csv", [])):
            relation = row.get("relation")
            expected = relation_domains.get(relation)
            if expected is None:
                self.unknown("UNSUPPORTED_RELATION", "Relation is preserved but its domain contract is not supported.", T16 + "id-relations.csv", f"/rows/{index}", responsibility="CROSS_FUNCTION_INTEGRATION", relation=relation)
                continue
            actual = (row.get("from_domain"), row.get("to_domain"))
            if actual != expected:
                self.issue("DOMAIN_MIXUP", "Relation endpoint domains differ from the relation contract.", T16 + "id-relations.csv", f"/rows/{index}", relation=relation, expected_domains=list(expected), actual_domains=list(actual))
                continue
            for side in ("from", "to"):
                domain, key = row.get(side + "_domain"), row.get(side + "_id")
                normalized = key.removeprefix("scene:") if isinstance(key, str) and domain == "scene" else key
                if domain in known and normalized not in known[domain]:
                    if domain in {"quest", "case", "map", "town"} and known[domain]:
                        self.issue("MISSING_RELATION_REFERENCE", "Typed reference is absent from the provided full raw ID table.", T16 + "id-relations.csv", f"/rows/{index}/{side}_id", domain=domain, referenced_id=key)
                    else:
                        self.unknown("RELATION_TARGET_NOT_IN_KNOWN_ROWS", "Typed reference cannot be resolved from provided bounded rows; it is not replaced with another numeric domain.", T16 + "id-relations.csv", f"/rows/{index}/{side}_id", responsibility="INPUT_COMPLETENESS", domain=domain, referenced_id=key)
            if relation == "declares_scene_member" and scene_tuple(row.get("to_id")):
                self.check_equal(str(scene_tuple(row["to_id"])[0]), row.get("from_id"), T16 + "id-relations.csv", f"/rows/{index}", "Scene relation crosses QuestID.")
            source_id, target_id = row.get("from_id"), row.get("to_id")
            raw_quest = raw_quests.get(source_id)
            raw_case = raw_cases.get(source_id)
            raw_map = raw_maps.get(source_id)
            if relation in ("declares_field", "declares_town", "declares_giver", "declares_finisher") and raw_quest is not None:
                self.check_equal(target_id, raw_quest.get(relation.removeprefix("declares_")), T16 + "id-relations.csv", f"/rows/{index}/to_id", "Quest relation disagrees with actual QuestInfo attribute.")
            elif relation == "declares_demand" and raw_quest is not None:
                if target_id not in [node.get("id") for node in raw_quest.findall("./Demands/Demand")]:
                    self.issue("RELATION_VALUE_MISMATCH", "Demand relation is not declared by raw QuestInfo.", T16 + "id-relations.csv", f"/rows/{index}")
            elif relation in ("declares_stage", "references_mapflow", "references_cluster") and raw_case is not None:
                attribute, prefix = {"declares_stage": ("STAGE", ""), "references_mapflow": ("MAPFLOW", "Field/MapFlow/"), "references_cluster": ("CLUSTER", "Field/Cluster/")}[relation]
                self.check_equal(target_id, prefix + raw_case.get(attribute), T16 + "id-relations.csv", f"/rows/{index}/to_id", "Case relation differs from actual CaseList.")
            elif relation == "candidate_case_by_stage_equality" and target_id in raw_cases:
                self.check_equal(source_id, raw_cases[target_id].get("STAGE"), T16 + "id-relations.csv", f"/rows/{index}/from_id", "Candidate Field/Case equality differs from raw STAGE.")
            elif relation in ("declares_bound", "declares_map", "declares_trigger") and raw_map is not None:
                self.check_equal(target_id, raw_map.get(relation.removeprefix("declares_").upper()), T16 + "id-relations.csv", f"/rows/{index}/to_id", "Map relation differs from actual MapList.")
            elif relation == "binds_func_sequence" and scene_tuple(source_id) in sindex:
                self.check_equal(target_id, sindex[scene_tuple(source_id)][1].get("sequence_member"), T16 + "id-relations.csv", f"/rows/{index}/to_id", "Scene/sequence member relation differs from scene projection.")
            elif relation == "lists_npc" and source_id in raw_towns:
                if target_id not in [node.get("ID") for node in raw_towns[source_id].findall("./NPCLIST/NPC")]:
                    self.issue("RELATION_VALUE_MISMATCH", "Town/NPC relation differs from actual TownList.", T16 + "id-relations.csv", f"/rows/{index}")
        for entryid, (index, entry) in eindex.items():
            cid = value_of(entry.get("case"))
            raw = raw_cases.get(str(cid))
            if raw is None:
                self.issue("MISSING_CASE_REFERENCE", "Canonical Scenario Case is not in raw CaseList.", T16 + "scenario-entries.json", f"/entries/{index}/case", case_id=cid)
                continue
            self.check_equal(value_of(entry.get("field")), int(raw.get("STAGE")), T16 + "scenario-entries.json", f"/entries/{index}/field", "Scenario Field/Case relation differs from raw STAGE metadata.")
            for field, prefix, attribute in [("mapflow_member", "Field/MapFlow/", "MAPFLOW"), ("cluster_member", "Field/Cluster/", "CLUSTER")]:
                self.check_equal(entry.get(field), prefix + raw.get(attribute), T16 + "scenario-entries.json", f"/entries/{index}/{field}", "Scenario member reference differs from actual CaseList.")

    def build_s00_route(self, qid, route, definition, scene_rows, baseline, out):
        description = route.get("description", "")
        line = route.get("line")
        self.unknown("S00_ROUTE_PROSE_NOT_EXECUTABLE",
                     "Only explicit scene indices, Field/Case pairs, ordered MapIDs, named presentation phases and an explicit destination are projected. Remaining prose, map-control lifecycle, admission, outcome and return timing are not converted into executable conditions.",
                     ROUTE, f"line:{line}", responsibility="SERVER_DEVELOPMENT",
                     quest_id=qid, raw_description=description)
        source = {"source_ref": "https://github.com/we88ec3-prog/ttr_anal_multi/blob/" + str(self.manifest.get("source_analysis_commit")) + "/" + ROUTE.removeprefix("git-evidence/"), "source_sha": self.read_files.get(ROUTE, {}).get("sha256"),
                  "evidence_kind": "SERVER_CANDIDATE_DESIGN"}
        field_case = re.search(r"Field(\d+)\s*/\s*Case(\d+)", description)
        maps_match = re.search(r"Map(\d+(?:→\d+)+)", description)
        ordered_maps = [int(x) for x in maps_match[1].split("→")] if maps_match else []
        narrative_match = re.match(r"scene(\d+(?:→\d+)*)", description)
        narrative = [int(x) for x in narrative_match[1].split("→")] if narrative_match else []
        scheduled = field_case is not None
        sd = definition.get("source_data", {})
        field = int(field_case[1]) if scheduled else value_of(sd.get("field"))
        case_id = int(field_case[2]) if scheduled else None
        baseline_scenario = next((x for x in baseline.get("scenarios", []) if x.get("case") == case_id), None)
        if scheduled and baseline_scenario is None:
            self.issue("MISSING_S00_SCENARIO", "Explicit S00 route Case has no resource-baseline entry.", ROUTE, f"line:{line}", quest_id=qid, case_id=case_id)
        if baseline_scenario:
            self.check_equal(ordered_maps, [x.get("map") for x in baseline_scenario.get("nodes", [])], ROUTE, f"line:{line}", "Route Map order differs from S00 ordered node selection.")
        if not narrative:
            self.unknown("UNSUPPORTED_ROUTE_NARRATIVE", "Route narrative prefix is not in the supported sceneN[→N] syntax.", ROUTE, f"line:{line}", responsibility="CROSS_FUNCTION_INTEGRATION", quest_id=qid, raw_description=description)
        if scheduled:
            self.check_equal(value_of(sd.get("field")), field, ROUTE, f"line:{line}", "Route FieldID differs from raw Quest metadata.")
        self.check_equal(value_of(sd.get("giver")), route.get("npc"), ROUTE, f"line:{line}", "Route NPC differs from Quest giver ID.")
        by_scene = {x.get("scene_index"): x for _, x in scene_rows}
        map_models = {x.get("map"): x.get("model") for x in baseline.get("maps", [])}
        destination = re.search(r"終點Town(\d+)\s*/\s*Map(\d+)", description)
        cues = []

        def add_cue(phase, si, assigned_maps=None, map_rule=None):
            row = by_scene.get(si)
            if row is None:
                self.issue("MISSING_ROUTE_SCENE", "S00 schedule references a scene absent from the T16 projection.", ROUTE, f"line:{line}", quest_id=qid, scene_index=si)
            models = []
            if row:
                for call in row.get("selected_calls") or []:
                    match = re.search(r'\bLoadMap\(\s*"([^"\n]+)"', call.get("source", ""))
                    if match:
                        models.append(re.sub(r"\.fld$", "", match[1], flags=re.I))
            # Only the explicit route's Case/Map context can disambiguate a model.
            contextual = [mid for mid in ordered_maps if map_models.get(mid) in models]
            if phase == "RETURN_PRESENTATION" and destination:
                destination_map = int(destination[2])
                if map_models.get(destination_map) in models:
                    contextual = [destination_map]
                    map_rule = "S00_EXPLICIT_DESTINATION_PLUS_LOADMAP"
            if assigned_maps is not None:
                contextual = assigned_maps
            cue = {"phase": phase, "scene": scene(qid, si),
                   "presentation_models": models, "presentation_maps": [typed("map", mid) for mid in contextual],
                   "map_resolution": map_rule or ("S00_ROUTE_CASE_CONTEXT_PLUS_LOADMAP" if contextual else "UNKNOWN_NO_UNIQUE_ROUTE_MAP_BINDING"),
                   "trigger_condition": None, "classification": "S00_SERVER_CANDIDATE_SCHEDULE",
                   "receipt_is_quest_completion": False, "receipt_is_reward_settlement": False}
            cues.append(cue)
            self.unknown("CUE_TRIGGER_UNBOUND", "S00 cue label/model association is retained; no official MEF trigger or executable predicate is supplied.",
                         ROUTE, f"line:{line}", responsibility="SERVER_DEVELOPMENT", quest_id=qid,
                         scene=scene(qid, si), phase=phase)

        for si in narrative:
            add_cue("NARRATIVE_BEFORE_SCENARIO" if scheduled else "NARRATIVE", si)
        used = set(narrative)
        if scheduled:
            every = re.search(r"各圖進場(\d+(?:/\d+)+)", description)
            special = re.search(r"scene(\d+)對應第[^圖]+圖(\d+)", description)
            ordinary = re.search(r"(?<!各圖)進場(\d+)", description)
            if every:
                scenes = [int(x) for x in every[1].split("/")]
                if len(scenes) != len(ordered_maps):
                    self.issue("CUE_MAP_ARITY", "Per-map scene cue count differs from explicit map count.", ROUTE, f"line:{line}")
                for index, si in enumerate(scenes):
                    assigned = [ordered_maps[index]] if index < len(ordered_maps) else []
                    add_cue("MAP_ENTRY", si, assigned, "S00_EXPLICIT_PER_MAP_SCHEDULE")
                    used.add(si)
            elif special:
                si, mid = int(special[1]), int(special[2])
                if mid not in ordered_maps:
                    self.issue("CUE_MAP_OUTSIDE_ROUTE", "Explicit cue MapID is outside route.", ROUTE, f"line:{line}")
                add_cue("MAP_ENTRY", si, [mid], "S00_EXPLICIT_MAP_ID")
                used.add(si)
            elif ordinary:
                si = int(ordinary[1])
                add_cue("MAP_ENTRY", si)
                used.add(si)
            for label, phase in [("Boss", "BOSS_PRESENTATION"), ("清怪後", "AFTER_CLEAR_PRESENTATION"), ("返回", "RETURN_PRESENTATION")]:
                match = re.search(label + r"(\d+)", description)
                if match:
                    si = int(match[1])
                    add_cue(phase, si)
                    used.add(si)
        for si in sorted(set(by_scene) - used):
            add_cue("UNCLASSIFIED_SOURCE_SCENE", si)
            self.unknown("UNSUPPORTED_ROUTE_SCENE_CONDITION", "Scene is present but not assigned a supported S00 route cue.", ROUTE, f"line:{line}", responsibility="CROSS_FUNCTION_INTEGRATION", quest_id=qid, scene=scene(qid, si))
        result = {
            "status": "DRAFT_CANDIDATE", "executable": False,
            "classification": "SERVER_CANDIDATE_NOT_NATIVE_MEF", "raw_description": description,
            "npc": typed("npc", route.get("npc")), "npc_label_from_s00": route.get("npc_label"),
            "narrative_scene_sequence": [scene(qid, si) for si in narrative],
            "scenario_scheduled": scheduled,
            "field_metadata": sd.get("field"), "case_metadata": typed("case", case_id),
            "instance_admission_policy": None,
            "scenario_entry_ref_from_t16": definition.get("scenario_entry_ref"),
            "scenario_entry_application": "SEPARATE_S00_SCHEDULE" if scheduled else "NOT_SCHEDULED_BY_THIS_ROUTE",
            "ordered_maps": [typed("map", mid) for mid in ordered_maps],
            "scene_cues": cues,
            "result_and_return": {"result_contract": None, "return_contract": None,
                                  "destination_town": typed("town", int(destination[1])) if destination else None,
                                  "destination_map": typed("map", int(destination[2])) if destination else None,
                                  "destination_status": "S00_EXPLICIT_CANDIDATE" if destination else "NOT_EXPLICIT_IN_ROUTE_ROW"},
            "formal_acceptance": {"rule": None, "distinct_from_narrative_start": True},
            "formation": {"policy": None, "distinct_from_scenario_creation": True,
                          "applicability": "CANDIDATE_REQUIRES_ADMISSION" if scheduled else "NOT_SCHEDULED"},
            "formal_completion": {"rule": None, "status": "UNKNOWN"},
            "reward_settlement": {"rule": None, "status": "UNKNOWN"},
            "t16_flow_relation": "PARALLEL_CANDIDATE_VERSION_NOT_MERGED_INTO_EXECUTABLE_GRAPH",
            "source_line": line,
        }
        for field in result:
            self.add_map(out + "/" + field, ROUTE, f"line:{line}", source,
                         kind="MARKDOWN_TABLE_ROW", transformation="BOUNDED_S00_ROUTE_GRAMMAR; CANDIDATE_ONLY")
        return result

    def build(self):
        self.verify_manifest()
        source_index = self.load_json(T16 + "source-index.json", {})
        source_members = self.load_json(T16 + "evidence/source-members.json", [])
        content_manifest = self.load_json(T16 + "content-manifest.json", {})
        contracts = self.load_json(T16 + "csv-contracts.json", {})
        baseline = self.load_json(BASELINE, {})
        route_text = self.load_text(ROUTE)
        self.verify_sources(source_index, source_members, content_manifest, baseline)
        self.load_csvs(contracts)
        definition_file = self.load_json(T16 + "quest-definitions.json", {})
        flow_file = self.load_json(T16 + "quest-flows.json", {})
        entry_file = self.load_json(T16 + "scenario-entries.json", {})
        candidate_chain = self.load_json(T16 + "candidate-chain.json", {})
        definitions = definition_file.get("definitions", [])
        flows = flow_file.get("flows", [])
        entries = entry_file.get("entries", [])
        dindex, findex, eindex, cindex, sindex = self.validate_canonical(definitions, flows, entries)
        routes = self.parse_route(route_text)
        case_resources, raw_maps, raw_towns, raw_cases, raw_quests = self.verify_raw_resources(dindex, cindex, baseline)
        self.validate_relations(dindex, eindex, sindex, raw_maps, raw_towns, raw_cases, raw_quests)
        chain = candidate_chain.get("chain", [])
        if len(chain) != len(set(chain)):
            self.issue("DUPLICATE_CHAIN_ID", "Candidate chain repeats a QuestID.", T16 + "candidate-chain.json", "/chain")
        for index, qid in enumerate(chain):
            if index == 0:
                continue
            if qid in dindex:
                actual_demands = [value_of(x) for x in dindex[qid][1].get("source_data", {}).get("demand_ids", [])]
                self.check_equal(actual_demands, [chain[index - 1]], T16 + "candidate-chain.json", f"/chain/{index}", "Declared candidate-chain edge differs from the raw Demand projection.")
            else:
                self.unknown("CANDIDATE_CHAIN_ROW_MISSING", "Candidate-chain Quest row is not provided.", T16 + "candidate-chain.json", f"/chain/{index}", responsibility="INPUT_COMPLETENESS", quest_id=qid)
        baseline_quests = self.index_unique(baseline.get("quests", []), lambda x: x.get("quest"), BASELINE, "/quests")
        baseline_scenes = self.index_unique(baseline.get("scenes", []), lambda x: (x.get("quest"), x.get("scene")), BASELINE, "/scenes")
        selected = set(self.selected)
        quests = []
        used_flows, used_entries = set(), set()
        external_ids = set()
        for qid in self.selected:
            if qid not in dindex or qid not in cindex or qid not in routes:
                self.issue("SELECTED_QUEST_INCOMPLETE", "Selected Quest needs canonical definition, CSV projection, and S00 route row.", quest_id=qid)
                continue
            di, definition = dindex[qid]
            ci, projection = cindex[qid]
            sd = definition.get("source_data", {})
            out = f"/quests/{len(quests)}"
            scene_rows = [(index, row) for index, row in enumerate(self.csv_tables.get("quest-scenes.csv", [])) if row.get("quest_id") == qid]
            npc_rows = [(index, row) for index, row in enumerate(self.csv_tables.get("quest-npc-scenes.csv", [])) if row.get("quest_id") == qid]
            objective_rows = [(index, row) for index, row in enumerate(self.csv_tables.get("quest-objectives.csv", [])) if row.get("quest_id") == qid]
            reward_rows = [(index, row) for index, row in enumerate(self.csv_tables.get("quest-rewards.csv", [])) if row.get("quest_id") == qid]
            if definition.get("flow_ref"):
                used_flows.add(definition["flow_ref"])
            else:
                self.unknown("T16_FLOW_NOT_PROVIDED", "No canonical T16 flow is bound to this Quest; S00 route projection is a separate candidate, not an invented executable flow.", T16 + "quest-definitions.json", f"/definitions/{di}/flow_ref", quest_id=qid, responsibility="SERVER_DEVELOPMENT")
            if definition.get("scenario_entry_ref"):
                used_entries.add(definition["scenario_entry_ref"])
            predecessors = sd.get("demand_ids", [])
            successors = definition.get("unlock_candidates", [])
            for ref in predecessors + successors:
                if value_of(ref) not in selected:
                    external_ids.add(value_of(ref))
            self.collect_unknowns(definition, T16 + "quest-definitions.json", f"/definitions/{di}", qid)
            route = self.build_s00_route(qid, routes[qid], definition, scene_rows, baseline, out + "/s00_route")
            quest = {
                "quest_id": qid, "id": definition.get("id"), "activation": "DRAFT_BLOCKED",
                "definition": definition, "catalog_projection": projection,
                "predecessors": predecessors, "successors": successors,
                "scene_bindings": [row for _, row in scene_rows],
                "npc_scene_associations": [row for _, row in npc_rows], "s00_route": route,
                "objective_projection": [row for _, row in objective_rows],
                "reward_projection": [row for _, row in reward_rows],
                "source_locations": {"definition": {"path": T16 + "quest-definitions.json", "json_pointer": f"/definitions/{di}"},
                                     "catalog": {"path": T16 + "quest-catalog.csv", **self.row_locations.get(("quest-catalog.csv", ci), {})}},
            }
            self.add_map(out + "/quest_id", T16 + "quest-definitions.json", f"/definitions/{di}/id/value", sd.get("source"))
            self.map_tree(quest["id"], out + "/id", T16 + "quest-definitions.json", f"/definitions/{di}/id", sd.get("source"))
            self.map_tree(definition, out + "/definition", T16 + "quest-definitions.json", f"/definitions/{di}")
            self.map_csv(projection, out + "/catalog_projection", "quest-catalog.csv", ci)
            self.map_tree(predecessors, out + "/predecessors", T16 + "quest-definitions.json", f"/definitions/{di}/source_data/demand_ids", sd.get("source"))
            self.map_tree(successors, out + "/successors", T16 + "quest-definitions.json", f"/definitions/{di}/unlock_candidates")
            for index, (row_index, row) in enumerate(scene_rows):
                self.map_csv(row, out + f"/scene_bindings/{index}", "quest-scenes.csv", row_index)
                key = (qid, row.get("scene_index"))
                if key in baseline_scenes:
                    bi, bscene = baseline_scenes[key]
                    for field, source_field in [("function_name", "function"), ("sequence_sha256", "sha256"), ("selected_calls", "calls")]:
                        self.check_equal(row.get(field), bscene.get(source_field), BASELINE, f"/scenes/{bi}/{source_field}", "S00 scene projection differs from T16 scene projection.")
                else:
                    self.issue("MISSING_S00_SCENE", "T16 selected scene has no S00 baseline projection.", BASELINE, quest_id=qid, scene_index=row.get("scene_index"))
                self.collect_unknowns(row, T16 + "quest-scenes.csv", f"/rows/{row_index}", qid)
            for index, (row_index, row) in enumerate(npc_rows):
                self.map_csv(row, out + f"/npc_scene_associations/{index}", "quest-npc-scenes.csv", row_index)
            for key, filename, rows in [("objective_projection", "quest-objectives.csv", objective_rows),
                                        ("reward_projection", "quest-rewards.csv", reward_rows)]:
                for index, (row_index, row) in enumerate(rows):
                    self.map_csv(row, out + f"/{key}/{index}", filename, row_index)
                    self.collect_unknowns(row, T16 + filename, f"/rows/{row_index}", qid)
            if qid in baseline_quests:
                bi, bq = baseline_quests[qid]
                for field, expected in [("giver", value_of(sd.get("giver"))), ("finisher", value_of(sd.get("finisher"))),
                                        ("fieldRaw", value_of(sd.get("field"))), ("levelRaw", sd.get("level_raw")),
                                        ("demands", [value_of(x) for x in predecessors])]:
                    self.check_equal(bq.get(field), expected, BASELINE, f"/quests/{bi}/{field}", "S00 Quest projection differs from T16 canonical definition.")
            else:
                self.issue("MISSING_S00_QUEST", "S00 baseline has no selected Quest row.", BASELINE, quest_id=qid)
            quests.append(quest)

        shared_flows, shared_entries = [], []
        for flowid in sorted(used_flows):
            if flowid in findex:
                fi, flow = findex[flowid]
                self.map_tree(flow, f"/shared/flows/{len(shared_flows)}", T16 + "quest-flows.json", f"/flows/{fi}")
                self.collect_unknowns(flow, T16 + "quest-flows.json", f"/flows/{fi}")
                shared_flows.append(flow)
        for entryid in sorted(used_entries):
            if entryid in eindex:
                ei, entry = eindex[entryid]
                self.map_tree(entry, f"/shared/scenario_entries/{len(shared_entries)}", T16 + "scenario-entries.json", f"/entries/{ei}")
                self.collect_unknowns(entry, T16 + "scenario-entries.json", f"/entries/{ei}", value_of(entry.get("quest")))
                shared_entries.append(entry)
        for index, case in enumerate(case_resources):
            bi = int(case["baseline_pointer"].split("/")[-1])
            self.map_tree(case["s00_candidate_selection"], f"/shared/case_resources/{index}/s00_candidate_selection", BASELINE, f"/scenarios/{bi}")
            self.add_map(f"/shared/case_resources/{index}/resource_graph", "local-resources/" + case["mapflow_member"], "/MapChart", kind="XML_XPATH", transformation="RESOURCE_GRAPH_PROJECTION; NO_RUNTIME_TRIGGER_INFERRED")
        map_resources = []
        for index, bmap in enumerate(baseline.get("maps", [])):
            record = {"map": typed("map", bmap.get("map")), "s00_baseline": bmap,
                      "classification": "S00_CANDIDATE_POSITIONS_NOT_NATIVE_PLACEMENT",
                      "bound_bytes_verification": "NOT_IN_PACKAGE", "runtime_enabled": False}
            self.map_tree(bmap, f"/shared/map_resources/{index}/s00_baseline", BASELINE, f"/maps/{index}")
            map_resources.append(record)
        dictionaries = self.csv_tables.get("id-dictionary.csv", [])
        for index, row in enumerate(dictionaries):
            self.map_csv(row, f"/shared/id_dictionary/{index}", "id-dictionary.csv", index)
        wire_adapters = self.csv_tables.get("quest-wire-map.csv", [])
        for index, row in enumerate(wire_adapters):
            self.map_csv(row, f"/shared/wire_adapters/{index}", "quest-wire-map.csv", index)
            self.collect_unknowns(row, T16 + "quest-wire-map.csv", f"/rows/{index}")
            for blocked_index, blocked in enumerate(row.get("blocked_fields") or []):
                self.unknown("WIRE_ADAPTER_FIELD_UNBOUND", "Wire adapter retains this unbound field; this converter supplies no packet value.",
                             T16 + "quest-wire-map.csv", f"/rows/{index}/blocked_fields/{blocked_index}",
                             responsibility="CLIENT_RESEARCH", adapter_id=row.get("adapter_id"), field=blocked)
        id_relations = self.csv_tables.get("id-relations.csv", [])
        for index, row in enumerate(id_relations):
            self.map_csv(row, f"/shared/id_relations/{index}", "id-relations.csv", index)
        external = []
        for qid in sorted(x for x in external_ids if x is not None):
            di, definition = dindex.get(qid, (None, {}))
            item = {"id": typed("quest", qid), "scope": "EXTERNAL_TO_SELECTED_STORY_ROUTE",
                    "source_row_present": bool(definition), "activation": definition.get("activation", "UNKNOWN"),
                    "predecessors": definition.get("source_data", {}).get("demand_ids"),
                    "successors": definition.get("unlock_candidates"), "definition_pointer": f"/definitions/{di}" if di is not None else None}
            if di is not None:
                self.add_map(f"/external_quest_references/{len(external)}", T16 + "quest-definitions.json", f"/definitions/{di}", transformation="EXTERNAL_BOUNDARY_PROJECTION")
            external.append(item)
        catalog = {
            "schema_version": "1.0.0", "model_kind": "W3_OFFLINE_STORY_CATALOG_NOT_NATIVE_MEF",
            "activation": "DRAFT_BLOCKED", "runtime_enabled": False, "converter_version": VERSION,
            "source_package": {"manifest_sha256": self.read_files.get("MANIFEST.json", {}).get("sha256"),
                               "package_snapshot_commit": self.manifest.get("source_analysis_commit"),
                               "t16_baseline_commit": source_index.get("baseline_commit"),
                               "t16_supplementary_analysis_commit": source_index.get("supplementary_analysis_commit"),
                               "t16_server_candidate_commit": source_index.get("server_candidate_commit"),
                               "selected_quest_ids": list(self.selected)},
            "semantic_boundaries": {
                "acceptance_is_completion": False, "scene_receipt_is_completion": False,
                "scene_receipt_is_reward_settlement": False,
                "field_metadata_implies_instance_admission": False,
                "chapter_town_equals_quest_town": False,
                "scene_loadmap_globally_identifies_map_id": False,
                "resource_graph_edge_is_runtime_trigger": False,
                "t16_blocked_package_enabled": False,
                "native_verification_or_spec_maturity_promoted": False,
                "t16_flows_and_s00_schedules_are_separate_versions": True,
            },
            "quests": quests, "external_quest_references": external,
            "shared": {"flows": shared_flows, "scenario_entries": shared_entries,
                       "case_resources": case_resources, "map_resources": map_resources,
                       "id_dictionary": dictionaries, "id_relations": id_relations,
                       "wire_adapters": wire_adapters,
                       "candidate_chain": candidate_chain,
                       "input_csv_null_policy": contracts.get("blank_policy"),
                       "s00_limitations": baseline.get("limits")},
            "source_manifest": {"member_checks": self.member_audit,
                                "references": self.source_index_audit,
                                "note": "Content identity checks do not certify native semantics, historical runtime success, or activation."},
        }
        self.map_tree(candidate_chain, "/shared/candidate_chain", T16 + "candidate-chain.json", "")
        self.stats["selected_quests_converted"] = len(quests)
        self.stats["selected_scenes_converted"] = sum(len(q["scene_bindings"]) for q in quests)
        self.stats["selected_npc_scene_associations"] = sum(len(q["npc_scene_associations"]) for q in quests)
        self.stats["s00_scenario_routes"] = sum(q["s00_route"]["scenario_scheduled"] for q in quests)
        self.stats["s00_case_resources"] = len(case_resources)
        self.stats["s00_map_resources"] = len(map_resources)
        self.stats["selected_canonical_flows"] = len(shared_flows)
        self.stats["selected_canonical_scenarios"] = len(shared_entries)
        return catalog

    def render_map(self):
        buffer = io.StringIO(newline="")
        writer = csv.DictWriter(buffer, fieldnames=SOURCE_MAP_COLUMNS, lineterminator="\n")
        writer.writeheader()
        for row in sorted(self.maps, key=lambda x: (x["output_pointer"], x["input_path"], x["input_pointer"], str(x["csv_record"]), str(x["column"]))):
            writer.writerow(row)
        return buffer.getvalue().encode("utf-8-sig")

    def report(self, catalog_bytes, map_bytes):
        errors = sum(x["severity"] == "ERROR" for x in self.issues)
        warnings = sum(x["severity"] == "WARNING" for x in self.issues)
        return {
            "schema_version": "1.0.0", "converter_version": VERSION,
            "structural": {"status": "PASS" if errors == 0 else "FAIL", "errors": errors, "warnings": warnings,
                           "scope": "Upload/content/source SHA, declared CSV types/PKs, bounded canonical projections, typed domains, references, raw Quest rows, S00 route/scene/Case/Map/Chart/Cluster consistency; not full JSON Schema or native semantics."},
            "activation": {"status": "DRAFT_BLOCKED", "runtime_enabled": False,
                           "t16_blockers_preserved": True, "formal_quest_completion_authorized": False,
                           "reward_settlement_authorized": False},
            "execution": {"offline_only": True, "network_used": False, "server_or_client_executed": False,
                          "historical_scripts_executed": False, "game_negative_fault_concurrency_suites_executed": False,
                          "source_files_modified": False},
            "counts": dict(sorted(self.stats.items())),
            "source_map_rows": len(self.maps), "selected_quest_ids": list(self.selected),
            "output_sha256": {"story-catalog.json": sha256(catalog_bytes), "source-map.csv": sha256(map_bytes)},
            "read_files": [{**row, "roles": sorted(row["roles"])} for _, row in sorted(self.read_files.items())],
            "manifest_audit": self.manifest_audit,
            "content_manifest_audit": self.content_manifest_audit,
            "member_audit": self.member_audit,
            "source_index_audit": self.source_index_audit,
            "issues": sorted(self.issues, key=compact), "unknowns": sorted(self.unknowns, key=compact),
            "unknowns_by_responsibility": dict(sorted(Counter(x["responsibility"] for x in self.unknowns).items())),
            "interpretation": "PASS means this bounded offline conversion is consistent. DRAFT/UNKNOWN, absent original members, historical version differences and unbound conditions in the source models remain. No FULL-PASS, CLM/SPEC/ADR approval, gameplay acceptance or T16 activation is implied.",
        }


def parse_quest_ids(value):
    try:
        values = tuple(int(x.strip()) for x in value.split(","))
    except ValueError as exc:
        raise argparse.ArgumentTypeError("Quest IDs must be comma-separated integers") from exc
    if not values or any(x <= 0 for x in values) or len(values) != len(set(values)):
        raise argparse.ArgumentTypeError("Quest IDs must be positive and unique")
    return values


def publish_outputs(output, payloads, overwrite):
    output.mkdir(parents=True, exist_ok=True)
    # Preflight the entire set before changing any output.  --overwrite applies
    # only to the three known filenames; never removes other files/directories.
    for name in OUTPUT_NAMES:
        path = output / name
        if path.is_symlink():
            raise ValueError("Refusing to write an output symlink: " + name)
        if path.exists() and (not overwrite or not path.is_file()):
            raise ValueError("Output exists; choose another directory or explicitly use --overwrite: " + name)
    staged = []
    try:
        for name, data in payloads.items():
            descriptor, temporary = tempfile.mkstemp(prefix=".w3-", dir=output)
            with os.fdopen(descriptor, "wb") as stream:
                stream.write(data)
            staged.append((Path(temporary), output / name))
        for temporary, target in staged:
            if overwrite:
                os.replace(temporary, target)
            else:
                # Exclusive creation also refuses a file created since preflight.
                with target.open("xb") as stream:
                    stream.write(temporary.read_bytes())
                temporary.unlink()
    finally:
        for temporary, _ in staged:
            if temporary.exists():
                temporary.unlink()


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--input", required=True, type=Path, help="Unpacked package root containing MANIFEST.json and git-evidence/")
    parser.add_argument("--output", required=True, type=Path, help="Output directory outside the input tree")
    parser.add_argument("--quests", type=parse_quest_ids, default=DEFAULT_QUESTS,
                        help="Comma-separated QuestIDs; default: 117,118,119,120,121,122,123,124,131,132")
    parser.add_argument("--overwrite", action="store_true", help="Explicitly replace only the three converter output files")
    args = parser.parse_args(argv)
    root = args.input.resolve()
    output = args.output.resolve()
    if not root.is_dir():
        parser.error("--input must be an existing unpacked directory")
    if within(output, root) or within(root, output):
        parser.error("Input and output directory trees must be separate; sources are read only")
    if any((output / name).exists() for name in OUTPUT_NAMES) and not args.overwrite:
        parser.error("Output exists; choose a new directory or explicitly use --overwrite")
    converter = Converter(root, args.quests)
    try:
        catalog = converter.build()
    except (OSError, ValueError, TypeError, KeyError, AttributeError, IndexError) as exc:
        # Unknown input shapes must leave a diagnostic artifact, not a Python
        # traceback or a falsely complete catalog.  CLI/output-path errors are
        # handled separately and never authorize writes into the source tree.
        converter.issue("CONVERSION_INCOMPLETE", "Unsupported or malformed input shape: " + type(exc).__name__ + ": " + str(exc))
        converter.maps.clear()
        converter.stats["selected_quests_converted"] = 0
        converter.stats["selected_scenes_converted"] = 0
        catalog = {"schema_version": "1.0.0", "model_kind": "W3_OFFLINE_STORY_CATALOG_NOT_NATIVE_MEF",
                   "activation": "DRAFT_BLOCKED", "runtime_enabled": False,
                   "conversion_status": "INCOMPLETE_SEE_VALIDATION_REPORT", "quests": []}
    try:
        catalog_data = json_bytes(catalog)
        map_data = converter.render_map()
        report = converter.report(catalog_data, map_data)
        report_data = json_bytes(report)
        publish_outputs(output, dict(zip(OUTPUT_NAMES, (catalog_data, map_data, report_data))), args.overwrite)
    except (OSError, ValueError, TypeError, KeyError) as exc:
        print("Conversion could not finish: " + str(exc), file=sys.stderr)
        return 2
    print("Offline conversion: {status}; quests={quests}; scenes={scenes}; errors={errors}; activation=DRAFT_BLOCKED".format(
        status=report["structural"]["status"], quests=report["counts"].get("selected_quests_converted", 0),
        scenes=report["counts"].get("selected_scenes_converted", 0), errors=report["structural"]["errors"]))
    return 0 if report["structural"]["errors"] == 0 else 1


if __name__ == "__main__":
    sys.exit(main())
