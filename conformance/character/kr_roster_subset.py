"""Structural KR command-2 roster subset. Does NOT certify native error handling."""
from dataclasses import dataclass
HEADER=65
RECORD=53
class UnsafeRoster(ValueError): pass
@dataclass(frozen=True)
class Entry:
    offset:int
    name:str
    raw_id:int
    byte_2f:int
    byte_30:int
    dword_2a:int
    dword_31:int

def parse_synthetic_roster(payload:bytes):
    """Conservative safe harness; neither a complete Client parser nor legal character test."""
    if len(payload)<HEADER:
        raise UnsafeRoster("unsafe incomplete prefix; native behavior not established")
    n=(len(payload)-HEADER)//RECORD
    out=[]
    for i in range(n):
        base=HEADER+i*RECORD
        r=payload[base:base+RECORD]
        # A synthetic fixture safety limit, NOT proven native copy capacity.
        terminator=next((j for j in range(0,0x2A,2) if r[j:j+2]==b"\x00\x00"),None)
        if terminator is None:
            raise UnsafeRoster("name not NUL terminated within conservative synthetic field")
        out.append(Entry(base,r[:terminator].decode("utf-16-le"),r[0x2E],r[0x2F],r[0x30],
                         int.from_bytes(r[0x2A:0x2E],"little"),
                         int.from_bytes(r[0x31:0x35],"little")))
    return out,payload[HEADER+n*RECORD:]
