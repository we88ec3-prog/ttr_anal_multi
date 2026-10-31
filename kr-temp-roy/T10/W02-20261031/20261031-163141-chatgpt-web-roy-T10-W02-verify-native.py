#!/usr/bin/env python3
"""KR T10 W02 offline read-only native BIN audit; does not load/execute game."""
import sys, json, hashlib, struct, pathlib
if len(sys.argv)!=3:
    sys.exit("Usage: python verify_w02.py Tartaros.bin W02-native-audit.json")
a=json.loads(pathlib.Path(sys.argv[2]).read_text(encoding="utf-8"))
b=pathlib.Path(sys.argv[1]).read_bytes()
assert len(b)==a["target_bytes"]
assert hashlib.sha256(b).hexdigest()==a["target_sha256"]
bias=int(a["PE_text"]["va_raw_bias"],16)
for x in a["assertions"]:
    ofs=int(x["va"],16)-bias
    expect=bytes.fromhex(x["bytes_hex"])
    assert b[ofs:ofs+len(expect)]==expect,x["id"]
for w in a["windows"]:
    p=int(w["start_va"],16)-bias
    q=int(w["end_exclusive_va"],16)-bias
    assert hashlib.sha256(b[p:q]).hexdigest()==w["sha256"],w["id"]
j=a["jump_table"]
out=struct.unpack_from("<4I",b,int(j["VA"],16)-bias)
assert [hex(i) for i in out]==j["target_words"]
for target, expected in a["direct_E8_rel32_candidate_sites"].items():
    matches=[]
    for ofs in range(0x400,0x7d0600-5):
        if b[ofs]!=0xe8: continue
        rel=struct.unpack_from("<i",b,ofs+1)[0]
        if bias+ofs+5+rel==int(target,16):matches.append(hex(bias+ofs))
    assert matches==expected,(target,matches)
print("PASS",len(a["assertions"]),"byte anchors,",len(a["windows"]),"SHA256 windows,","V dispatch table and direct-call candidate scan")
