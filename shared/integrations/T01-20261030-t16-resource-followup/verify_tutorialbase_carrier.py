#!/usr/bin/env python3
"""Read-only KR Event.stp TutorialBase member provenance check; no game code is executed."""
from pathlib import Path
from hashlib import sha256
import sys
p=Path(sys.argv[1] if len(sys.argv)>1 else "Event.stp")
b=p.read_bytes()
expected_stp="2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b"
assert len(b)==11241597 and sha256(b).hexdigest()==expected_stp,"KR Event.stp mismatch"
offset,length=10645520,1416
raw=b[offset:offset+length]
decoded=bytes(ch^255 for ch in raw)
assert decoded[:12]==bytes.fromhex("1b4c75615100010404040800"),"Lua 5.1 header mismatch"
expected="26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744"
assert len(decoded)==1416 and sha256(decoded).hexdigest()==expected,"TutorialBase hash mismatch"
print(f"KR Event.stp validated: {expected_stp}")
print(f"TutorialBase.lua carrier offset={offset}, len={length}, SHA256={expected}")
print("Lua prototype count 6/instruction count 72 was verified by a separate complete Lua 5.1 proto parser; this script only rechecks the member hash.")
