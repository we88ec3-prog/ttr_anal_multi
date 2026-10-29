"""Inspect two known KR client outbound auth payload shapes; NOT an auth server."""
from dataclasses import dataclass
@dataclass(frozen=True)
class AuthShape:
    command:int
    slot_a:bytes
    slot_b:bytes
    tail:bytes
    last_word:int

def inspect_local_auth(payload:bytes)->AuthShape:
    if len(payload)<2:
        raise ValueError("need two command bytes")
    op=int.from_bytes(payload[:2],"little")
    if op==0x00E8 and len(payload)==112:
        return AuthShape(op,payload[2:53],payload[53:104],payload[104:110],
                         int.from_bytes(payload[110:112],"little"))
    if op==0x000F and len(payload)==214:
        if payload[206:210]!=b"\x01\x00\x01\x00" or payload[210:212]!=b"\x34\x00":
            raise ValueError("synthetic 0F constants mismatch")
        return AuthShape(op,payload[2:104],payload[104:206],payload[206:212],
                         int.from_bytes(payload[212:214],"little"))
    raise ValueError("outside this offline shape subset; not a native rejection verdict")
