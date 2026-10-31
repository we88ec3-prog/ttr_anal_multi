#!/usr/bin/env python3
"""Read-only T14 WP03 KR BIN anchor verifier. No Client execution or patching."""
import hashlib, json, struct, sys
from pathlib import Path
EXPECTED_SHA="9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
def h16(b,o): return struct.unpack_from("<H",b,o)[0]
def h32(b,o): return struct.unpack_from("<I",b,o)[0]
def run(name):
    b=Path(name).read_bytes();sha=hashlib.sha256(b).hexdigest()
    assert sha==EXPECTED_SHA,("wrong native source",sha)
    pe=h32(b,0x3c);assert b[:2]==b"MZ" and b[pe:pe+4]==b"PE\x00\x00"
    assert h16(b,pe+4)==0x14c
    opt=pe+24;assert h16(b,opt)==0x10b
    img=h32(b,opt+28);sec=opt+h16(b,pe+20)
    sections=[]
    for i in range(h16(b,pe+6)):
        off=sec+40*i
        sections.append((b[off:off+8].split(b"\0")[0].decode(),img+h32(b,off+12),h32(b,off+20),h32(b,off+16)))
    audit=json.loads(Path(__file__).with_name("native-window-audit.json").read_text())
    assert audit["source_sha256"]==sha
    for w in audit["windows"]:
        va=int(w["va"],16);want=bytes.fromhex(w["bytes"])
        ss=[s for s in sections if s[1]<=va and va+len(want)<=s[1]+s[3]]
        assert len(ss)==1,w["va"]
        s=ss[0];raw=s[2]+va-s[1]
        assert raw==int(w["raw"],16),w["va"]
        assert b[raw:raw+len(want)]==want,w["va"]
    assert len(audit["switch_table_0x4B9994"])==8
    for row in audit["switch_table_0x4B9994"]:
        va=int(row["table_va"],16);ss=next(s for s in sections if s[1]<=va<s[1]+s[3])
        assert h32(b,ss[2]+va-ss[1])==int(row["case_va"],16),row
    print(json.dumps({"result":"PASS","sha256":sha,"windows":len(audit["windows"]),"switch_entries":8,"scope":"bounded static PE bytes only"}))
if __name__=="__main__":
    run(sys.argv[1] if len(sys.argv)>1 else "Tartaros.bin")
