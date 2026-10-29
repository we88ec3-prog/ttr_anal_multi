"""Offline KR frame subset from PARTIAL static analysis, NOT original Client emulator."""
from dataclasses import dataclass

PLAIN=0x1A68
XOR=0x0BBB

class FrameError(ValueError): pass
class UnsupportedMarker(FrameError): pass
class ChecksumMismatch(FrameError): pass

@dataclass(frozen=True)
class Frame:
    marker: int
    payload: bytes

def encode_plain(payload: bytes) -> bytes:
    if not (1 <= len(payload) <= 4092):
        raise FrameError("local plain writer capacity")
    return len(payload).to_bytes(2,"little")+PLAIN.to_bytes(2,"little")+payload

def encode_xor(payload: bytes) -> bytes:
    if not (1 <= len(payload) <= 4090):
        raise FrameError("local XOR writer capacity")
    body=bytes(x^(0xB6 if i==0 else payload[i-1]) for i,x in enumerate(payload))
    return len(payload).to_bytes(2,"little")+XOR.to_bytes(2,"little")+(sum(payload)&0xffff).to_bytes(2,"little")+body

def decode_one(data: bytes):
    """Conservative subset: unknown markers/errors are harness policy, not proven native behavior."""
    if len(data)<4:
        return None
    length=int.from_bytes(data[:2],"little")
    marker=int.from_bytes(data[2:4],"little")
    if not 1<=length<=4096:
        raise FrameError("native receiver length gate")
    if marker not in (PLAIN,XOR):
        raise UnsupportedMarker(hex(marker))
    header=6 if marker==XOR else 4
    if len(data)<header+length:
        return None
    body=data[header:header+length]
    if marker==XOR:
        plain=bytearray()
        previous=0xB6
        for x in body:
            cur=x^previous
            plain.append(cur)
            previous=cur
        body=bytes(plain)
        if sum(body)&0xffff!=int.from_bytes(data[4:6],"little"):
            raise ChecksumMismatch("offline harness rejection policy")
    return Frame(marker,body),header+length

def decode_available(data: bytes):
    frames=[]
    used=0
    while used<len(data):
        result=decode_one(data[used:])
        if result is None: break
        frame,count=result
        frames.append(frame)
        used+=count
    return frames,data[used:]
