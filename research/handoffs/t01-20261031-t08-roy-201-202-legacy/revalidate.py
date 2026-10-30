#!/usr/bin/env python3
"""T01 selected KR BIN original-byte checks for T08 branch integration, NOT source FULL-PASS."""
import hashlib,json,argparse
from pathlib import Path
P=[
(0x4dfbc9,"8d4508"),(0x4dfc19,"8d4d08"),(0x4dfc1e,"e86d6c2d00"),
(0x7b6890,"558bec"),(0x7b698e,"894104"),(0x7b6991,"eb0e"),(0x7b6ae6,"8908"),
(0x4b297a,"3b053cb1fa00"),(0x4b2980,"7407"),(0x4b2982,"8b7010"),
(0x7b868b,"8b7e2083c008"),(0x7b86de,"8d7e04e83a14f6ff"),(0x7f6fbf,"6a30"),(0x7f6fc1,"8bf8"),
(0x4aec77,"83790400751b"),(0x4afa37,"85db7553"),(0x805d02,"c6862ca0000002"),
(0x8068b0,"558bec535657"),(0x807b40,"558bec83e4f8"),(0x807bfc,"babb0b0000"),
(0x807c18,"ba681a0000"),(0x807d66,"66394b04"),(0x8079f0,"8b85f8efffff891166894104"),
(0x8079bd,"8a14038a5c03ff32da"),(0x806ec4,"ff157c22bd00"),
(0x7b8a50,"558bec6aff68c68b9100"),(0x7bb240,"558bec6aff689eb79200"),
(0x7a4c50,"558bec6aff6863799000"),(0x4ca460,"558bec6aff6820899000"),
(0x7a63c0,"558bec6aff6876bd9200"),(0x7a8e10,"558bec83ec0c"),(0x4e0f60,"558bec83ec0c"),
(0x4ca660,"8b490c85c974088b018b106a01ffd2c3"),(0x7a3920,"85c974098b018b50086a01ffd2c3")
]
p=argparse.ArgumentParser();p.add_argument("bin");a=p.parse_args()
b=Path(a.bin).read_bytes()
assert len(b)==12472320
assert hashlib.sha256(b).hexdigest()=="9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
rows=[]
for va,s in P:
 exp=bytes.fromhex(s);off=va-0x400c00;got=b[off:off+len(exp)]
 rows.append({"va":f"0x{va:08X}","expected":exp.hex(),"actual":got.hex(),"ok":exp==got})
assert all(x["ok"] for x in rows), [x for x in rows if not x["ok"]]
print(json.dumps({"result":"PASS","checks":len(P),"file_size":len(b),"whole_report_fullpass":False},indent=2))
