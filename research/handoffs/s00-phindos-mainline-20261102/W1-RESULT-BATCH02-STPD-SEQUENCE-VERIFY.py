#!/usr/bin/env python3
"""W1 BATCH02: read-only original KR STPD index / TTEX quest-scene verification.
No Client/Server execution, no EX v1 decompression, no original file modification.
Usage: python -B W1-RESULT-BATCH02-STPD-SEQUENCE-VERIFY.py Table.stp Event.stp
"""
import hashlib
import re
import struct
import sys
from pathlib import Path

TABLE_SHA = "09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442"
EVENT_SHA = "2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b"
QUESTS = {15, 117, 118, 119, 120, 121, 122, 123, 124, 131, 132, 133}


def u32(b, at):
    return struct.unpack_from("<I", b, at)[0]


def open_pack(path, expected):
    raw = Path(path).read_bytes()
    assert hashlib.sha256(raw).hexdigest() == expected
    assert raw[:4] == b"STPD"
    b = bytes(x ^ 255 for x in raw)
    index_pos = u32(b, 4)
    assert raw[index_pos:index_pos+4] == b"STPI"
    assert u32(b, index_pos+4) == len(raw)-index_pos
    count = u32(b, index_pos-32)+1
    recbase = index_pos-count*32
    assert recbase >= 16
    assert all(u32(b, recbase+n*32) == n for n in range(count))
    return b, b[index_pos+8:], recbase, count


def member(b, recbase, record_id):
    row_id, stored_size, first, last = struct.unpack_from(
        "<4I", b, recbase+record_id*32)
    assert row_id == record_id and last >= first
    begin = first*1024+16
    assert begin+stored_size <= len(b)
    stored = b[begin:begin+stored_size]
    md5 = b[recbase+record_id*32+16:recbase+record_id*32+32]
    if stored.startswith(b"EX\x01\x00"):
        packed_len, original_len, hdr_len = struct.unpack_from("<3I", stored, 4)
        assert hdr_len == 16 and stored_size == packed_len+hdr_len
        return stored, {"kind": "EX", "stored": stored_size,
                        "declared_decoded": original_len}
    assert hashlib.md5(stored).digest() == md5
    return stored, {"kind": "PLAIN", "stored": stored_size,
                    "source_md5": md5.hex()}


def catalog_id(idx, name):
    n = name.encode("ascii")
    p = idx.find(n)
    assert p >= 15, name
    assert idx[p-15] == 0 and struct.unpack_from("<H", idx, p-2)[0] == len(n)
    return u32(idx, p-14)


def archive_checks(table_path, event_path):
    tb, ti, tr, tn = open_pack(table_path, TABLE_SHA)
    eb, ei, er, en = open_pack(event_path, EVENT_SHA)
    assert tn == 1026 and en == 7382
    for name in ("QuestInfo.xml", "QuestTalk.xml", "SceneList.xml"):
        no = catalog_id(ti, name) + 1
        stored, spec = member(tb, tr, no)
        assert spec["kind"] == "EX"
        print("Table", name, "catalog+1 record", no, spec)
    no = catalog_id(ei, "SceneList.xml") + 1
    stored, spec = member(eb, er, no)
    assert spec["kind"] == "EX"
    print("Event SceneList.xml", "catalog+1 record", no, spec)
    stats = {"seq": 0, "ttex": 0, "aligned": 0}
    matches = []
    for m in re.finditer(rb"[A-Za-z0-9_./-]+\.seq", ei, re.I):
        name = m.group().decode("ascii")
        at = m.start()
        if at < 15 or ei[at-15] != 0:
            continue
        if struct.unpack_from("<H", ei, at-2)[0] != len(name):
            continue
        record_id = u32(ei, at-14) + 1
        if record_id >= en:
            continue
        data, spec = member(eb, er, record_id)
        stats["seq"] += 1
        assert spec["kind"] == "PLAIN"
        header = re.search(
            rb"--\s*Quest\s*#\s*(\d+)\s*/\s*Scene\s*#\s*(\d+)\s*-\s*Function\s*([^\r\n]+)",
            data[:500])
        if not header:
            continue
        stats["ttex"] += 1
        quest, scene = int(header[1]), int(header[2])
        function = header[3].decode("ascii").strip()
        assert name.lower() == (function+".seq").lower()
        stats["aligned"] += 1
        if quest in QUESTS:
            maps = re.findall(rb'LoadMap\("([^"]*)"\)', data)
            matches.append((quest, scene, function, record_id,
                            [x.decode("ascii", "replace") for x in maps]))
    assert stats == {"seq": 1839, "ttex": 1836, "aligned": 1836}, stats
    assert len(matches) == 35
    assert (117,1,"Phindous_LittleTrouble",6816,["town001D.fld"]) in matches
    assert (132,5,"Phindous_pathofAlsmeer_Boss_After",6828,["town002D.fld"]) in matches
    assert (133,1,"Alsmeer_Justice_Talk01",5629,["town002D.fld"]) in matches
    print("PASS", stats, "35 target author-script scenes / MD5 verified")
    print("NOTE: author scene headers are not proof of runtime SceneList routing or quest settlement")


if __name__ == "__main__":
    assert len(sys.argv) == 3, "usage: script Table.stp Event.stp"
    archive_checks(sys.argv[1], sys.argv[2])
