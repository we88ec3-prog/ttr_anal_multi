#!/usr/bin/env python3
"""Read-only T10-W01 KR native byte and window SHA256 audit. Never runs the target."""
import hashlib, json, pathlib, sys
if len(sys.argv) != 3:
    raise SystemExit("usage: python verify_w01.py /path/to/Tartaros.bin w01-native-audit.json")
p, auditpath = map(pathlib.Path,sys.argv[1:])
b = p.read_bytes()
a = json.loads(auditpath.read_text(encoding="utf-8"))
assert hashlib.sha256(b).hexdigest() == a["target_sha256"], "Target SHA mismatch"
assert len(b) == a["target_size_bytes"], "Target size mismatch"
bad = []
for c in a["checks"]:
    offset = int(c["raw"],16)
    expected=bytes.fromhex(c["hex"])
    if b[offset:offset+len(expected)] != expected:
        bad.append(c["id"])
for w in a["windows"]:
    start=int(w["va_start"],16)-0x400c00
    end=int(w["va_end_exclusive"],16)-0x400c00
    if hashlib.sha256(b[start:end]).hexdigest() != w["sha256"]:
        bad.append("window:"+w["id"])
for s in a["rdata_string_evidence"]:
    off=int(s["raw"],16)
    if b[off:off+len(s["ascii"]) +1] != s["ascii"].encode("ascii")+b"\0":
        bad.append("string:"+s["ascii"])
print("T10-W01 static audit", "PASS" if not bad else "FAIL", 
      "checks",len(a["checks"]),"windows",len(a["windows"]),
      "strings",len(a["rdata_string_evidence"]), "mismatches",bad)
raise SystemExit(1 if bad else 0)
