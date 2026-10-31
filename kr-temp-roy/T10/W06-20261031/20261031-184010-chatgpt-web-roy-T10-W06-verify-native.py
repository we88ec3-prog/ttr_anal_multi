#!/usr/bin/env python3
"""Read-only T10 W06 KR BIN native checksum and battle-result switch-table audit."""
import hashlib, json, pathlib, struct, sys
if len(sys.argv) != 3:
    sys.exit("usage: python verify-native.py Tartaros.bin W06-native-audit.json")
data=pathlib.Path(sys.argv[1]).read_bytes()
audit=json.loads(pathlib.Path(sys.argv[2]).read_text(encoding="utf-8"))
assert len(data)==audit["bin_size"],"wrong binary size"
assert hashlib.sha256(data).hexdigest()==audit["bin_sha256"],"wrong KR original binary"
bias=int(audit["text_va_minus_raw"],16)
for window in audit["windows"]:
    low=int(window["start_va"],16)-bias
    high=int(window["end_va_exclusive"],16)-bias
    assert hashlib.sha256(data[low:high]).hexdigest()==window["sha256"],window["id"]
for item in audit["anchors"]:
    pos=int(item["va"],16)-bias
    expected=bytes.fromhex(item["hex"])
    assert data[pos:pos+len(expected)]==expected,item["va"]
table=audit["result_case_jump_table"]
start=int(table["va"],16)-bias
actual=struct.unpack_from("<9I",data,start)
expect=[int(v,16) for v in table["targets"]]
assert list(actual)==expect, "incorrect nine-way battle-result dispatch"
assert len(expect)==9 and expect[7]==0x4b18d9
print(f"PASS: {len(audit['windows'])} SHA256 windows; {len(audit['anchors'])} native instructions; 9 case targets.")
