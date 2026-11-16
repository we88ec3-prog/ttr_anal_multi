"""Build a local, text-only Taiwan overlay over the existing KR story archive.

Does not execute the game, rewrite inputs, or export game resources to Git.
All non-whitelisted XML fields and all other archive members must remain equal.
"""
from __future__ import annotations

import argparse
import collections
import hashlib
import json
from pathlib import Path
import re
import struct
import sys
import xml.etree.ElementTree as ET
from xml.parsers import expat
from xml.sax.saxutils import escape
import zlib

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "anal"))
from stp_resources import Archive

BASE_SHA = "d6200a07615432c027c5d1f8058e9b37b58a00ee1e69a8cbb6989108bb5c6d85"
TC_SHA = "d0a7980cfa72d41f18ed21da4804b7a5939e86a93d40f07bdcb68d0645a76a84"
TABLES = ["Table/_ActorList.xml", "Table/SkillActiveTable.xml",
          "Table/SkillPassiveTable.xml", "Table/SkillSupportTable.xml",
          "Table/skillexplaintable.xml", "Table/PracticeExplainTable.xml"]
SIGNATURES = {TABLES[1]: ("type", "form", "attribute"),
              TABLES[2]: ("group", "type"),
              TABLES[3]: ("group", "type", "targetskill")}
FORMAT = re.compile(r"%(?:\d+\$)?[-+ #0]*(?:\d+|\*)?(?:\.(?:\d+|\*))?[hlL]*[sdifuoxXegGcpaAn]|\{\d+(?:[,:][^{}]*)?\}")


def sha(data):
    return hashlib.sha256(data).hexdigest()


def save(path, value):
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes((json.dumps(value, ensure_ascii=False, indent=2) + "\n").encode("utf-8"))


def write_immutable(path, data):
    path.parent.mkdir(parents=True, exist_ok=True)
    if path.exists():
        assert path.read_bytes() == data, f"Refusing to overwrite different artifact: {path}"
    else:
        with path.open("xb") as stream:
            stream.write(data)


def segment(tag, attrs, ordinal):
    keys = ("ID", "no", "val", "level", "type")
    parts = [(key, attrs[key]) for key in keys if key in attrs]
    if tag == "ACTOR" and "FILE" in attrs:
        parts.append(("FILE", attrs["FILE"]))
    # Identity fields rather than positional pairing across versions.
    return (tag, tuple(parts)) if parts else (tag, (("ordinal", str(ordinal)),))


def index_xml(raw):
    parser = expat.ParserCreate()
    stack, nodes = [], {}

    def start(tag, attrs):
        ordinal = 0
        if stack:
            parent = stack[-1]
            ordinal = parent["counts"][tag]
            parent["counts"][tag] += 1
            parent["children"] += 1
        parent_path = stack[-1]["path"] if stack else ()
        part = segment(tag, attrs, ordinal)
        key = parent_path + (part,)
        occurrence = 0
        while key in nodes:
            # Preserve duplicate non-target rows (e.g. monster variants) without
            # conflating them. NPC category6 is independently uniqueness-checked.
            occurrence += 1
            key = parent_path + ((part[0], part[1] + (("occurrence", str(occurrence)),)),)
        begin = parser.CurrentByteIndex
        # These shipped XML documents have no '>' inside quoted attributes.
        end = raw.index(b">", begin) + 1
        node = dict(path=key, tag=tag, attrs=attrs, start=begin, open_end=end,
                    children=0, counts=collections.Counter(), text="")
        nodes[key] = node
        stack.append(node)

    def text(value):
        if stack:
            stack[-1]["text"] += value

    def end(_):
        node = stack.pop()
        node["close_start"] = parser.CurrentByteIndex

    parser.StartElementHandler = start
    parser.EndElementHandler = end
    parser.CharacterDataHandler = text
    parser.Parse(raw, True)
    return nodes


def practice_signatures(archive):
    result, conflicts, sources = {}, set(), []
    includes = ET.fromstring(archive.read("Table/Skill/PracticeList.xml"))
    for include in includes:
        member = include.get("File")
        if not member or member not in archive.files:
            continue
        body = archive.read(member)
        sources.append(dict(member=member, sha256=sha(body)))
        for node in ET.fromstring(body).iter("Practice"):
            targets = sorted({tuple(sorted((k, v) for k, v in mod.attrib.items()
                                           if k != "Value"))
                              for mod in node.iter("Modifier")})
            signature = (node.get("CharID"), node.get("Category"), targets)
            ident = node.get("ID")
            if ident in result and result[ident] != signature:
                conflicts.add(ident)
            result[ident] = signature
    for ident in conflicts:
        result.pop(ident)
    return result, sorted(conflicts), sources


def valid_text(old, new):
    if not new or not new.strip():
        return "empty-taiwan-text"
    if collections.Counter(FORMAT.findall(old)) != collections.Counter(FORMAT.findall(new)):
        return "format-placeholder-mismatch"
    # Supplied descriptions use escaped <br> markup. Keep it as display text,
    # never import arbitrary XML elements or executable markup.
    markup = re.findall(r"<[^>]*>", new)
    if any(re.fullmatch(r"<br\s*/?>", item, re.I) is None for item in markup):
        return "unreviewed-rich-text-tag"
    return None


def root_row(node, tag):
    for name, attrs in node["path"]:
        if name == tag:
            return dict(attrs)
    return {}


def merge_table(member, old, taiwan, safe_skills, safe_practices):
    before, tc = index_xml(old), index_xml(taiwan)
    edits, approved, changed_text, fallbacks, visible_text = [], {}, [], [], []
    stats = collections.Counter()
    for path, node in before.items():
        fields = []
        if member == TABLES[0]:
            category = root_row(node, "OBJCATEGORY").get("ID")
            if node["tag"] == "ACTOR" and category == "6":
                fields = [("attribute", "NAME")]
        elif member in SIGNATURES:
            if node["tag"] in ("SKILL", "TYPE") and "name" in node["attrs"]:
                fields = [("attribute", "name")]
        elif member == TABLES[4] and node["tag"] == "EXPLAIN":
            fields = [("text", None)]
        elif member == TABLES[5]:
            if node["tag"] == "PRACTICE":
                fields = [("attribute", "NAME")]
            elif node["tag"] in ("Explain", "LEVEL") and not node["children"]:
                fields = [("text", None)]
        for kind, attr in fields:
            old_value = node["attrs"].get(attr, "") if kind == "attribute" else node["text"]
            stats["eligible_fields"] += 1
            donor = tc.get(path)
            ident = root_row(node, "PRACTICE").get("ID") if member == TABLES[5] else root_row(node, "SKILL").get("no")
            reason = None
            if donor is None:
                reason = "identity-not-in-taiwan"
            elif member in SIGNATURES and ident not in safe_skills[member]:
                reason = "skill-kind-signature-mismatch"
            elif member == TABLES[4] and ident not in safe_skills[TABLES[1]]:
                reason = "active-skill-identity-not-verified"
            elif member == TABLES[5] and ident not in safe_practices:
                reason = "practice-target-identity-not-verified"
            new_value = "" if donor is None else donor["attrs"].get(attr, "") if kind == "attribute" else donor["text"]
            if reason is None and not old_value.strip() and not new_value.strip():
                stats["blank_both_preserved_fields"] += 1
                visible_text.append(old_value)
                continue
            if reason is None:
                reason = valid_text(old_value, new_value)
            if reason:
                stats["fallback_fields"] += 1
                fallbacks.append(dict(path=repr(path), field=attr or "text", reason=reason))
                visible_text.append(old_value)
                continue
            visible_text.append(new_value)
            if any("\uac00" <= char <= "\ud7af" for char in new_value):
                stats["taiwan_text_still_contains_hangul_fields"] += 1
            if old_value == new_value:
                stats["already_equal_fields"] += 1
                continue
            if kind == "attribute":
                tag_bytes = old[node["start"]:node["open_end"]]
                matches = list(re.finditer(rb"\b" + attr.encode("ascii") + rb'\s*=\s*([\'"])(.*?)\1', tag_bytes, re.S))
                assert len(matches) == 1
                match = matches[0]
                begin = node["start"] + match.start(2)
                end = node["start"] + match.end(2)
                replacement = escape(new_value, {'"': "&quot;", "'": "&apos;"}).encode("utf-8")
            else:
                assert node["children"] == 0
                begin, end = node["open_end"], node["close_start"]
                assert old[begin:end].find(b"<") == -1
                replacement = escape(new_value).encode("utf-8")
            edits.append((begin, end, replacement))
            approved[(path, kind, attr)] = new_value
            changed_text.append(new_value)
            stats["changed_fields"] += 1
            numeric = lambda value: collections.Counter(re.findall(r"\d+(?:\.\d+)?%?", value))
            if numeric(old_value) != numeric(new_value):
                stats["changed_fields_with_numeric_token_difference"] += 1
    merged = old
    previous = len(old) + 1
    for begin, end, replacement in sorted(edits, reverse=True):
        assert 0 <= begin <= end < previous
        previous = begin
        merged = merged[:begin] + replacement + merged[end:]
    after = index_xml(merged)
    assert before.keys() == after.keys()
    for path, a in before.items():
        b = after[path]
        assert a["tag"] == b["tag"] and a["children"] == b["children"]
        assert a["attrs"].keys() == b["attrs"].keys()
        for attr, value in a["attrs"].items():
            assert b["attrs"][attr] == approved.get((path, "attribute", attr), value)
        assert b["text"] == approved.get((path, "text", None), a["text"])
    ET.fromstring(merged)
    return merged, dict(stats), fallbacks, changed_text, visible_text


def pack_archive(base, changed):
    old_table = struct.unpack_from(">I", base.data, 12)[0]
    old_index = struct.unpack_from("<I", base.data, 4)[0]
    count = struct.unpack_from("<I", base.data, old_table)[0]
    names = {ident: path for path, ident in base.files.items()}
    result, entries = bytearray(base.data[:16]), []
    for i in range(count):
        entry = bytearray(base.data[old_table + 4 + i * 32:old_table + 4 + (i + 1) * 32])
        ident, size, first, last = struct.unpack_from("<4I", entry)
        name = names[ident]
        if name in changed:
            payload = changed[name]
            compressed = zlib.compress(payload)
            block = b"EX\0\0" + struct.pack("<III", len(compressed), len(payload), 16) + compressed
        else:
            block = base.data[16 + first * 1024:16 + first * 1024 + size]
        new_first = (len(result) - 16) // 1024
        blocks = (len(block) + 1023) // 1024
        result.extend(block)
        result.extend(bytes(blocks * 1024 - len(block)))
        struct.pack_into("<4I", entry, 0, ident, len(block), new_first, new_first + blocks - 1)
        if name in changed:
            entry[16:32] = hashlib.md5(block).digest()
        entries.append(entry)
    table = len(result)
    result.extend(struct.pack("<I", count) + b"".join(entries))
    index = len(result)
    result.extend(base.data[old_index:])
    struct.pack_into(">I", result, 12, table)
    struct.pack_into("<I", result, 4, index)
    packed = bytearray(value ^ 255 for value in result)
    packed[:4] = b"STPD"
    packed[index:index + 4] = b"STPI"
    return bytes(packed)


def main():
    cli = argparse.ArgumentParser(description=__doc__)
    cli.add_argument("--root", type=Path, default=ROOT)
    args = cli.parse_args()
    root = args.root.resolve()
    base_path = root / "TC_UI/Table.story-zh-tw-v3.stp"
    tc_path = root.parent / "tc_workspace/Table.stp"
    assert sha(base_path.read_bytes()) == BASE_SHA, "Story base SHA mismatch"
    assert sha(tc_path.read_bytes()) == TC_SHA, "Taiwan source SHA mismatch"
    base, tc = Archive(base_path), Archive(tc_path)
    out = root / "CLIENT/build/zh-tw-v3-resources/Table.story-zh-tw-v3.stp"
    report_dir = root / "CLIENT/evidence/20261105-variant-text"
    safe_skills, skill_signature_fallbacks = {}, {}
    for member, attrs in SIGNATURES.items():
        before, donor = ET.fromstring(base.read(member)), ET.fromstring(tc.read(member))
        index = {e.get("no"): e for e in donor}
        assert len(index) == len(donor)
        safe_skills[member] = {e.get("no") for e in before if e.get("no") in index
                              and all(e.get(attr) == index[e.get("no")].get(attr) for attr in attrs)}
        skill_signature_fallbacks[member] = sorted({e.get("no") for e in before} - safe_skills[member])
    bp, bc, bs = practice_signatures(base)
    tp, tconf, ts = practice_signatures(tc)
    safe_practices = {key for key in bp if key in tp and bp[key] == tp[key]}
    changed, summaries, all_fallbacks, glyph_text, visible_text = {}, {}, [], [], []
    members = []
    for member in TABLES:
        old, taiwan = base.read(member), tc.read(member)
        merged, counts, fallbacks, translated, visible = merge_table(member, old, taiwan, safe_skills, safe_practices)
        if merged != old:
            changed[member] = merged
        summaries[member] = counts
        all_fallbacks.extend(dict(member=member, **entry) for entry in fallbacks)
        glyph_text.extend(translated)
        visible_text.extend(visible)
        members.append(dict(member=member, base_sha256=sha(old), taiwan_sha256=sha(taiwan), output_sha256=sha(merged)))
    packed = pack_archive(base, changed)
    write_immutable(out, packed)
    rebuilt = Archive(out)
    assert rebuilt.files == base.files
    for member in base.files:
        assert rebuilt.read(member) == changed.get(member, base.read(member)), member
    # Existing dialogue/synopsis bytes are preserved relative to the story-v3 base.
    actors = ET.fromstring(base.read(TABLES[0])).find("OBJCATEGORY[@ID='6']")
    donor_actors = ET.fromstring(tc.read(TABLES[0])).find("OBJCATEGORY[@ID='6']")
    assert len({e.get("ID") for e in actors}) == len(actors)
    assert len({e.get("ID") for e in donor_actors}) == len(donor_actors)
    groups = collections.defaultdict(list)
    for e in actors:
        groups[e.get("FILE")].append(e.get("ID"))
    duplicates = [dict(file=file, ids=ids) for file, ids in groups.items() if len(ids) > 1]
    tc_by_id = {e.get("ID"): e for e in donor_actors}
    actor_conflicts = [dict(id=e.get("ID"), base_file=e.get("FILE"), taiwan_file=tc_by_id[e.get("ID")].get("FILE"))
                       for e in actors if e.get("ID") in tc_by_id and e.get("FILE") != tc_by_id[e.get("ID")].get("FILE")]
    glyphs = "".join(sorted({char for text in glyph_text for char in text if ord(char) > 127}))
    write_immutable(report_dir / "glyphs.txt", glyphs.encode("utf-8"))
    visible_glyphs = "".join(sorted({char for text in visible_text for char in text if ord(char) > 127}))
    write_immutable(report_dir / "glyphs-all-visible-fields.txt", visible_glyphs.encode("utf-8"))
    manifest = dict(schema="client-text-overlay-v1", runtime_verified=False,
                    source=dict(base_sha256=BASE_SHA, taiwan_sha256=TC_SHA), output_sha256=sha(packed),
                    output_bytes=len(packed), archive_members=len(base.files), changed_members=len(changed),
                    unmodified_members_byte_equal=len(base.files) - len(changed),
                    field_summaries=summaries, members=members,
                    npc_category="6", npc_base_count=len(actors), npc_taiwan_count=len(donor_actors),
                    npc_duplicate_file_groups=duplicates, npc_same_id_different_file=actor_conflicts,
                    skill_signature_fallbacks=skill_signature_fallbacks,
                    practice_identity_safe_count=len(safe_practices),
                    practice_identity_kr_conflicts=bc, practice_identity_tc_conflicts=tconf,
                    practice_definition_sources=dict(base=bs, taiwan=ts),
                    fallback_fields=len(all_fallbacks), glyph_count=len(glyphs),
                    glyphs_sha256=sha(glyphs.encode("utf-8")),
                    visible_fields_glyph_count=len(visible_glyphs),
                    visible_fields_glyphs_sha256=sha(visible_glyphs.encode("utf-8")),
                    validation=dict(nontext_fields_unchanged=True, original_story_bytes_preserved=True,
                                    all_members_roundtrip=True, placeholder_checks=True,
                                    rich_text_restricted_to_br=True),
                    limitations=["Static resource candidate; native mounting, UI layout and rendering require human test.",
                                 "Translations follow the supplied Taiwan version; numeric prose can differ from KR balance.",
                                 "Unmatched or ambiguous identities and empty text fall back; no FILE-only NPC guesses.",
                                 "No original files, gameplay fields, executable or account data modified."])
    save(report_dir / "manifest.json", manifest)
    save(report_dir / "fallbacks.json", all_fallbacks)
    print(json.dumps({key: manifest[key] for key in ("output_sha256", "output_bytes", "changed_members", "field_summaries", "fallback_fields", "glyph_count")}, ensure_ascii=True))


if __name__ == "__main__":
    main()
