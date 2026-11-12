#!/usr/bin/env python3
"""KR T03-A read-only SHA, PE mapping and 23 native byte-slice verifier."""
from pathlib import Path
import hashlib, struct, sys
EXPECTED = "9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
SLICES = {
  0x8068DE:"8d 86 50 a0 00 00",0x8068F3:"50",
  0x8068F7:"8d 48 14",0x8068FC:"89 78 18",
  0x806903:"6a 01",0x806905:"89 11",
  0x806909:"51",0x80690A:"52",0x806912:"ff 15 b8 25 bd 00",
  0x806961:"81 c6 b8 a0 00 00",0x806967:"56",
  0x806968:"ff 15 84 22 bd 00",
  0x80697A:"81 c6 b8 a0 00 00",0x806980:"56",
  0x806981:"ff 15 84 22 bd 00",
  0x806A0A:"8d 86 30 a0 00 00",0x806A2E:"8d 48 14",
  0x806A3B:"c7 01 00 10 00 00",
  0x806A43:"51",0x806A4C:"ff 15 bc 25 bd 00",
  0x806DE4:"8d b8 30 a0 00 00",
  0x806E7D:"8d b8 50 a0 00 00",0x806E83:"3b d7"
}
def check(path:Path):
  data=path.read_bytes()
  assert hashlib.sha256(data).hexdigest()==EXPECTED, "Wrong KR BIN SHA"
  pe=struct.unpack_from("<I",data,0x3c)[0]
  assert data[pe:pe+4]==b"PE\0\0"
  assert struct.unpack_from("<H",data,pe+4)[0]==0x14c
  opt=pe+24
  assert struct.unpack_from("<H",data,opt)[0]==0x10b
  assert struct.unpack_from("<I",data,opt+28)[0]==0x400000
  count=struct.unpack_from("<H",data,pe+6)[0]
  size=struct.unpack_from("<H",data,pe+20)[0]
  sections={}
  for i in range(count):
    off=opt+size+i*40
    name=data[off:off+8].rstrip(b"\0").decode("ascii")
    vs,va,rs,rp=struct.unpack_from("<IIII",data,off+8)
    sections[name]=(va+0x400000,rp,vs,rs)
  assert sections[".text"][:2]==(0x401000,0x400)
  assert sections[".rdata"][:2]==(0xBD2000,0x7D0600)
  assert sections[".data"][:2]==(0xD61000,0x95E800)
  for va,s in SLICES.items():
    expected=bytes.fromhex(s)
    raw=sections[".text"][1]+va-sections[".text"][0]
    assert data[raw:raw+len(expected)]==expected, f"Mismatch {va:#x}/{raw:#x}"
  print("PASS: KR source SHA/PE32 and",len(SLICES),"native raw instruction slices")
  print("Send: OVERLAPPED=Conn+A050, WSABUF=Conn+A064, counter=Conn+A0B8")
  print("Recv: OVERLAPPED=Conn+A030, WSABUF=Conn+A044")
  print("Static slices only; not T01 FULL-PASS / runtime or official Server packet evidence.")
if __name__=="__main__":
  if len(sys.argv)!=2: raise SystemExit("Usage: python -B verify_t03_a_wsasend.py /path/Tartaros.bin")
  check(Path(sys.argv[1]))
