#!/usr/bin/env python3
"""T01 RR-0008 E68 selective KR source audit; read-only, no Client execution."""
import hashlib, json, struct, sys
from pathlib import Path
TARGET = "9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
STP = "2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b"
TEXT_BIAS, RDATA_BIAS, DATA_BIAS = 0x400C00, 0x401A00, 0x402800
CHECKS = {
  0x4ADF3D:"c7801402000090214b00", 0x4B21FD:"0fbf7602",
  0x4B2206:"e805df0400", 0x4B2210:"3bfb0f86ae000000",
  0x4B221C:"0fb64801", 0x500110:"33c08d8fd05e0000",
  0x50012B:"83f814", 0x47B143:"c78648020000ffffffff",
  0x47B2EF:"898348020000", 0x47B4C9:"898648020000",
  0x47D558:"8b8648020000", 0x47D55E:"898720010000",
  0x47D693:"68a0b2fa00", 0x47B5EB:"81bf4802000061ea0000",
  0x47B63D:"8b8f48020000", 0x561ED1:"8b473c8b4f38",
  0x561EE8:"3bc3741f", 0x565756:"837e2800",
  0x56575D:"c6868900000001", 0x4A3B91:"b842000000",
  0x4A3B96:"668945fc884dfe8855ff",
}
DIRECT = {
  0x47B2B0:[0x47D36D],0x47B5C0:[0x47D5B7],
  0x47D530:[0x47D9DA],0x565720:[0x47B64A,0x561EF3],
  0x4B2190:[],
}
def audit(bin_path,stp_path):
    data=Path(bin_path).read_bytes()
    stp=Path(stp_path).read_bytes()
    assert len(data)==12472320 and hashlib.sha256(data).hexdigest()==TARGET
    assert len(stp)==11241597 and hashlib.sha256(stp).hexdigest()==STP
    assert data[:2]==b"MZ"
    pe=struct.unpack_from("<I",data,0x3C)[0]
    assert data[pe:pe+4]==b"PE\x00\x00"
    n,opt=struct.unpack_from("<H",data,pe+6)[0],struct.unpack_from("<H",data,pe+20)[0]
    sections={}
    for i in range(n):
        p=pe+24+opt+i*40
        name=data[p:p+8].split(b"\x00")[0].decode()
        sections[name]=struct.unpack_from("<IIII",data,p+8)
    assert struct.unpack_from("<I",data,pe+52)[0]==0x400000
    assert sections[".text"][1:]==(0x1000,sections[".text"][2],0x400)
    assert sections[".rdata"][1]==0x7D2000 and sections[".rdata"][3]==0x7D0600
    assert sections[".data"][1]==0x961000 and sections[".data"][3]==0x95E800
    for addr,want in CHECKS.items():
        have=data[addr-TEXT_BIAS:addr-TEXT_BIAS+len(want)//2].hex()
        assert have==want,(hex(addr),want,have)
    for vp,col,td,name in [
      (0xC02F3C,0xC68ACC,0xF7D864,b".?AVCScenarioReviewSceneItem@FUI@@"),
      (0xC02D9C,0xC68B30,0xF7D890,b".?AVCScenarioReviewChapterItem@FUI@@")]:
        assert struct.unpack_from("<I",data,vp-RDATA_BIAS-4)[0]==col
        assert struct.unpack_from("<I",data,col-RDATA_BIAS+12)[0]==td
        assert data[td-DATA_BIAS+8:td-DATA_BIAS+8+len(name)]==name
    found={t:[] for t in DIRECT}
    begin,end=sections[".text"][3],sections[".text"][3]+sections[".text"][2]
    for raw in range(begin,end-4):
        if data[raw]==0xE8:
            dest=TEXT_BIAS+raw+5+struct.unpack_from("<i",data,raw+1)[0]
            if dest in found:found[dest].append(TEXT_BIAS+raw)
    assert found==DIRECT,found
    lua=bytes(v^0xFF for v in stp[0xA1C010:0xA1C21A])
    assert stp[:4]==b"STPD" and len(lua)==522
    assert hashlib.sha256(lua).hexdigest()=="1fc158a28915b6f0047941cb8a5c00534aa81c5538d153f1f05b5b2ff012eedc"
    assert all(x in lua for x in [b"Quest #1001 / Scene #1",
      b"function tutorial_start()",b"Register(tutorial_start)"])
    return {"passed":True,"byte_windows":len(CHECKS),"rtti_types":2,
      "e8_targets":{hex(k):[hex(x) for x in v] for k,v in found.items()},
      "event_lua_bytes":len(lua),"runtime_tested":False,
      "original_server_wire_tested":False,
      "scope":"selective BIN-rooted static review; not whole report FULL-PASS"}
if __name__=="__main__":
    if len(sys.argv)!=3:raise SystemExit("Usage: python -B revalidate.py Tartaros.bin Event.stp")
    print(json.dumps(audit(sys.argv[1],sys.argv[2]),indent=2))
