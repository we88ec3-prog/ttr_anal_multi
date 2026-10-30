#!/usr/bin/env python3
"""Standalone read-only KR phase3 rooted-CFG, window and Table.stp hash verifier.
Usage: python verify_phase3.py <Tartaros.bin> <Table.stp> <phase3.zip>
All supplied resources stay local; no original assets are uploaded/modified.
"""
import sys,hashlib,zipfile,json,collections,re,struct,zlib,xml.etree.ElementTree as ET
from pathlib import Path
assert len(sys.argv)==4,"Expected: BIN Table.stp phase3.zip"
BIN,STP,ZIP=map(Path,sys.argv[1:])
b=BIN.read_bytes();t=STP.read_bytes();zdata=ZIP.read_bytes()
assert hashlib.sha256(b).hexdigest()=="9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
assert hashlib.sha256(t).hexdigest()=="09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442"
assert hashlib.sha256(zdata).hexdigest()=="245465cc52c9673d560a05155ce978652103b34f56fe3e7732eacf96dd7e119c"
with zipfile.ZipFile(ZIP) as z:
    names=z.namelist()
    def load(suffix):
        matches=[n for n in names if n.endswith(suffix)]
        assert len(matches)==1,(suffix,matches)
        return json.loads(z.read(matches[0]))
    roots=[n for n in names if re.search(r"/native-cfg/root-.*\.json$",n)]
    assert len(roots)==19,len(roots)
    totals=collections.Counter()
    for name in roots:
        d=json.loads(z.read(name))
        inst={int(i["va"],16):i for i in d["instructions"]}
        assert int(d["root"],16) in inst
        edges=collections.defaultdict(list)
        for edge in d["edges"]:
            src=int(edge["from"],16);dst=int(edge["to"],16)
            assert src in inst
            if edge["kind"]=="fallthrough":assert dst==src+inst[src]["size"]
            if edge["kind"]!="call":assert dst in inst
            edges[src].append(edge)
        # A native rooted CFG must include every normal direct successor. 0x50554C
        # calls the throw/error path 0x87DB30 and has no normal fallthrough into
        # padding/jump-table data; this exception is explicit, not inferred.
        for va,node in inst.items():
            outgoing=edges.get(va,[])
            kinds=[e["kind"] for e in outgoing]
            nxt=va+node["size"]
            if node["op"] in ("ret","retn","retf","int3","ud2","hlt"):
                assert not outgoing,(hex(va),"terminal with successor")
            elif node["op"].startswith("j") and node["op"]!="jmp":
                assert sorted(kinds)==["branch","fallthrough"],(hex(va),kinds)
                assert any(e["kind"]=="fallthrough" and int(e["to"],16)==nxt for e in outgoing)
            elif node["op"]=="jmp":
                assert "branch" in kinds or "indexed-branch" in kinds,(hex(va),kinds)
                assert "fallthrough" not in kinds
            elif va==0x50554c and node["op"]=="call" and node["arg"]=="0x87db30":
                assert not outgoing
            else:
                assert len(outgoing)==1 and outgoing[0]["kind"]=="fallthrough"
                assert int(outgoing[0]["to"],16)==nxt
        for va,i in inst.items():
            raw=b[va-0x400c00:va-0x400c00+i["size"]]
            assert raw.hex()==i["bytes"].lower()
            assert not any((va+j) in inst for j in range(1,i["size"]))
            if raw[0]==0xe8 and len(raw)==5 or raw[0]==0xe9 and len(raw)==5:
                target=(va+5+int.from_bytes(raw[1:],"little",signed=True))&0xffffffff
            elif raw[0]==0xeb and len(raw)==2 or 0x70<=raw[0]<=0x7f and len(raw)==2:
                target=(va+2+int.from_bytes(raw[1:],"little",signed=True))&0xffffffff
            elif raw[0]==0x0f and len(raw)==6 and 0x80<=raw[1]<=0x8f:
                target=(va+6+int.from_bytes(raw[2:],"little",signed=True))&0xffffffff
            else:target=None
            if target is not None:
                m=re.search(r"0x[0-9a-fA-F]+",i["arg"])
                assert m and int(m.group(0),16)==target
                for e in edges[va]:
                    if e["kind"]=="branch":assert int(e["to"],16)==target
                totals["direct"]+=1
        todo=[int(d["root"],16)];seen=set()
        while todo:
            va=todo.pop()
            if va in seen:continue
            seen.add(va);todo.extend(int(e["to"],16) for e in edges[va] if e["kind"]!="call")
        assert set(inst)==seen
        totals["instructions"]+=len(inst);totals["edges"]+=len(d["edges"])
    assert (totals["instructions"],totals["edges"],totals["direct"])==(4464,4905,1046)
    cross=load("/native-window-source-crosswalk.json")
    types=collections.Counter()
    for x in cross:
        root=load("/native-cfg/"+x["normal_rooted_asm_ref"].split("/")[-1])
        va=int(x["bad_original_window"],16)
        containing=[i for i in root["instructions"] if int(i["va"],16)<=va<int(i["va"],16)+i["size"]]
        assert len(containing)==1
        types["start" if va==int(containing[0]["va"],16) else "interior"]+=1
    assert len(cross)==28 and types=={"start":2,"interior":26}
    calls=load("/native-call-list-crosscheck.json")
    assert len(calls["rows"])==71
    for q in calls["rows"]:
        va=int(q["source_instruction"],16);raw=b[va-0x400c00:va-0x400c00+5]
        size=2 if raw[0]==0xeb else 5
        assert (raw[0]==0xe8 if q["claimed_opcode"]=="call" else raw[0] in (0xeb,0xe9))
        assert (va+size+int.from_bytes(raw[1:size],"little",signed=True))&0xffffffff==int(q["claimed_target"],16)
assert [struct.unpack_from("<I",b,0x505554-0x400c00+4*i)[0] for i in range(6)]==[0x504de2,0x504df4,0x504deb,0x504dfd,0x504e06,0x504e0f]
with zipfile.ZipFile(ZIP) as z:
    matching=[n for n in z.namelist() if n.endswith("/native-cfg/root-00504740.json")]
    assert len(matching)==1
    case=json.loads(z.read(matching[0]))
    indexed=sorted(int(e["to"],16) for e in case["edges"] if e["from"].lower()=="0x00504d9e" and e["kind"]=="indexed-branch")
    assert indexed==sorted([0x504de2,0x504df4,0x504deb,0x504dfd,0x504e06,0x504e0f])
key=bytearray([0x30,0xe7])
for i in range(2,1024):key.append((key[i-2]+key[i-1]+0x13-(0x56 if i==0x17c else 0))&255)
for name,off,size,sha in [("QuestInfo",4345872,204056,"5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60"),("QuestTalk",4550672,52404,"b136fddf1696ff73c5780c269604b5670e35cbb416cd8cce4274aa05865edd28")]:
 raw=bytes(x^255 for x in t[off:off+size]);assert raw[:2]==b"EX" and raw[2]==1
 stored,expanded,p=struct.unpack_from("<III",raw,4)
 dec=zlib.decompress(bytes(x^key[i%1024] for i,x in enumerate(raw[p:p+stored])))
 assert len(dec)==expanded and hashlib.sha256(dec).hexdigest()==sha
 root=ET.fromstring(dec.decode("utf-8-sig"));assert root.tag==name
print("PASS: 19 roots, 4464 instructions, 4905 edges, 28 windows, 71 calls, 2 XML")
