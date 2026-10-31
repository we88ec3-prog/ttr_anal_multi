#!/usr/bin/env python3
"""W07 KR original BIN assertions, read-only. Audit consistency != T01 FULL-PASS."""
from pathlib import Path
import hashlib,json,struct,sys
if len(sys.argv) not in (3,4):
    sys.exit("usage: python verify-native.py Tartaros.bin W07-native-audit.json [W07-S00-matrix.json]")
data=Path(sys.argv[1]).read_bytes()
m=json.loads(Path(sys.argv[2]).read_text(encoding="utf-8"))
o=m["original_bin"]
assert len(data)==o["bytes"] and hashlib.sha256(data).hexdigest()==o["sha256"],"KR BIN mismatch"
bias=int(o["pe32_text_va_minus_raw"],16)
for x in m["anchors"]:
    raw=int(x["va"],16)-bias
    needle=bytes.fromhex(x["hex"])
    assert data[raw:raw+len(needle)]==needle,x["name"]
for x in m["windows"]:
    i=int(x["va_start"],16)-bias
    j=int(x["va_end_exclusive"],16)-bias
    assert hashlib.sha256(data[i:j]).hexdigest()==x["sha256"],x["name"]
p=m["result_opcode_0x000E_jump_table"]
i=int(p["va"],16)-bias
actual=struct.unpack_from("<9I",data,i)
assert tuple(actual)==tuple(int(t,16) for t in p["targets"]),"opcode000E switch"
if len(sys.argv)==4:
    x=json.loads(Path(sys.argv[3]).read_text(encoding="utf-8"))
    assert len(x["scenarios"])==12,"expected 12 player scenarios"
    assert len(x["iteration29_tests"])==24,"expected 24 I29 plan-only cases"
    assert {t["test_id"] for t in x["iteration29_tests"]}=={f"I29-T{i:02d}" for i in range(1,25)}
    assert all(t["status"]=="PLAN_ONLY_NOT_RUN" for t in x["iteration29_tests"])
    assert all(t["native_client_pass"] is False for t in x["iteration29_tests"])
    assert all(v["status"]=="CLIENT_STATIC_SCOPED_NOT_FULL_PASS" for v in x["client_contracts"])
    assert x["policy"]["native_adapter_enabled"] is False
    assert x["policy"]["server_mock_is_original_protocol"] is False
# only geometry and precedence symbolic checks, NOT packet or Server runtime:
for mask,column in [(1,1),(2,2),(4,3),(3,4),(5,5),(6,6),(7,4)]:
    f=lambda m: 4 if m&3==3 else 5 if m&5==5 else 6 if m&6==6 else 1 if m&1 else 2 if m&2 else 3 if m&4 else None
    assert f(mask)==column
assert (6+5*818)<=4096 and (6+5*819)>4096
print("PASS",len(m["anchors"]),"native anchors,",len(m["windows"]),"hash windows, 9 jump-table entries; matrix geometry plan-only")
