#!/usr/bin/env python3
"""W1 Batch04, read-only verification of uploaded SceneList.xml and original KR Event.stp.
Usage:
  python -B W1-RESULT-BATCH04-VERIFY.py SceneList.xml Event.stp Tartaros.bin W1-RESULT-BATCH04-SCENE-JOIN.json
No Client execution, Server mutation, quest settlement or negative tests.
"""
import hashlib
import json
import re
import struct
import sys
from collections import Counter
from pathlib import Path
from xml.etree import ElementTree as ET

SHA_XML="8d2e6a053b71750bfbd5337545446170f03316b185b2fdd94163bebe7146ba25"
SHA_EVENT="2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b"
SHA_BIN="9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"

def check_hash(path, sha):
    b=Path(path).read_bytes()
    assert hashlib.sha256(b).hexdigest()==sha,(path,"source-sha-mismatch")
    return b

def run(xml_path,event_path,bin_path,json_path):
    xml=check_hash(xml_path,SHA_XML)
    ev=check_hash(event_path,SHA_EVENT)
    check_hash(bin_path,SHA_BIN)
    text=xml.decode("euc-kr").replace('encoding="euc-kr"','encoding="utf-8"',1)
    root=ET.fromstring(text)
    assert root.tag=="SCENESET" and len(root)==1687
    lookup={}
    for node in root:
        a=node.attrib
        key=(int(a["questIdx"]),int(a["sceneIdx"]))
        lookup.setdefault(key,[]).append((a["funcName"],int(a["endBehavior"])))
    assert len(lookup)==1685
    data=json.loads(Path(json_path).read_text(encoding="utf-8"))
    assert len(data["w1_scenes"])==35
    assert sum(len(q["dialogue_keys_source_order"]) for q in data["dialogue_by_quest_from_batch03"])==118
    assert ev[:4]==b"STPD"
    v=bytes(x^0xff for x in ev)
    stpi=struct.unpack_from("<I",v,4)[0]
    assert ev[stpi:stpi+4]==b"STPI"
    last=struct.unpack_from("<I",v,stpi-32)[0]
    records=stpi-(last+1)*32
    for item in data["w1_scenes"]:
        q,s,fn=item["quest_id"],item["scene_id"],item["scene_list_funcName"]
        assert (fn,0) in lookup[(q,s)],(q,s,fn)
        fileid=item["event_seq_member_id"]
        assert fileid<=last
        rid,size,first,end=struct.unpack_from("<IIII",v,records+fileid*32)
        assert rid==fileid and size<=1024*(end-first+1)
        content=v[first*1024+16:first*1024+16+size]
        assert hashlib.md5(content).hexdigest()==item["event_seq_member_md5"]
        assert hashlib.md5(content).digest()==v[records+fileid*32+16:records+fileid*32+32]
        match=re.search(rb'--\s*Quest\s*#\s*(\d+)\s*/\s*Scene\s*#\s*(\d+)\s*-\s*Function\s*([^\r\n]+)',content[:500])
        assert match and (int(match[1]),int(match[2]),match[3].decode().strip())==(q,s,fn)
        assert re.search(rb'\bRegister\(\s*'+re.escape(fn.encode())+rb'\s*\)',content)
    # EX member is still encrypted/compressed; declared decoded length only.
    index=v[stpi+8:]
    marker=index.find(b"SceneList.xml")
    assert marker>=15
    begin=stpi+8+marker
    assert v[begin-15]==0
    fid=struct.unpack_from("<I",v,begin-14)[0]+1
    assert fid==7379
    rid,size,first,_=struct.unpack_from("<IIII",v,records+fid*32)
    payload=v[first*1024+16:first*1024+16+size]
    assert rid==7379 and payload[:4]==b"EX\x01\x00"
    compressed_size,decoded_size,header_size=struct.unpack_from("<III",payload,4)
    assert compressed_size+header_size==size and header_size==16
    assert decoded_size==len(xml)==158269
    counts=Counter(x["quest_id"] for x in data["w1_scenes"])
    assert dict(counts)=={15:4,117:1,118:1,119:5,120:3,121:1,122:5,123:1,124:7,131:1,132:5,133:1}
    print("PASS 35/35 SceneList→original Event.stp TTEX source key/name/MD5 joins")
    print("PASS uploaded SceneList decoded-size matches Event.stp EX member header")
    print("NOT VERIFIED: EX-member byte identity, Client triggering, Quest settlement, reward, persistence")

if __name__=="__main__":
    if len(sys.argv)!=5:
        raise SystemExit("usage: verify.py SceneList.xml Event.stp Tartaros.bin W1-RESULT-BATCH04-SCENE-JOIN.json")
    run(*sys.argv[1:])
