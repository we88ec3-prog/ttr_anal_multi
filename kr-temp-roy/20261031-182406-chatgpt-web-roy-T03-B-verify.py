#!/usr/bin/env python3
"""KR T03-B W05..W08: read-only bounded native PE/bytes verifier, not Client runtime."""
import hashlib
import struct
import sys
from pathlib import Path

TARGET_SHA256="9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
CHECKS=[
  [
    ["0x6d6321",
    "c7 00 1c b0 bf 00"
  ],
  [
    ["0x6d6340",
    "c7 40 08 52 00 00 00"
  ],
  [
    ["0x440793",
    "8b 41 08"
  ],
  [
    ["0x440796",
    "83 f8 52"
  ],
  [
    ["0x4407c2",
    "e8 99 2b 06 00"
  ],
  [
    ["0x4407f7",
    "e8 b4 29 06 00"
  ],
  [
    ["0x440822",
    "e8 89 29 06 00"
  ],
  [
    ["0x4a31e3",
    "b9 0f 00 00 00"
  ],
  [
    ["0x4a31ec",
    "66 89 8d c4 fe ff ff"
  ],
  [
    ["0x4a31f3",
    "c7 45 92 01 00 01 00"
  ],
  [
    ["0x4a31fa",
    "c7 45 96 34 00 00 00"
  ],
  [
    ["0x4a327d",
    "66 89 55 98"
  ],
  [
    ["0x4a32a3",
    "e8 a5 fb 3e 00"
  ],
  [
    ["0x4a32b6",
    "68 d6 00 00 00"
  ],
  [
    ["0x4a32c4",
    "ff d2"
  ],
  [
    ["0x4a33ab",
    "b9 e8 00 00 00"
  ],
  [
    ["0x4a33b0",
    "66 89 4c 24 74"
  ],
  [
    ["0x4a33b5",
    "66 8b 8a 80 bf 00 00"
  ],
  [
    ["0x4a33c5",
    "66 89 8c 24 e6 00 00 00"
  ],
  [
    ["0x4a3454",
    "53 ff d6"
  ],
  [
    ["0x4a3475",
    "ff d6"
  ],
  [
    ["0x4a34aa",
    "ff d6"
  ],
  [
    ["0x4a34c8",
    "ff d6"
  ],
  [
    ["0x4a34d3",
    "6a 33"
  ],
  [
    ["0x4a34e6",
    "6a 33"
  ],
  [
    ["0x4a34fc",
    "6a 70"
  ],
  [
    ["0x4a3505",
    "ff d2"
  ],
  [
    ["0x4c323b",
    "c7 86 44 5f 00 00 a0 37 4c 00"
  ],
  [
    ["0x4c325b",
    "c7 86 7c 62 00 00 10 3c 4c 00"
  ],
  [
    ["0x4c37d3",
    "8d 46 20"
  ],
  [
    ["0x4c37e7",
    "8b 15 08 a8 fb 00"
  ],
  [
    ["0x4c3800",
    "ff 15 cc 21 bd 00"
  ],
  [
    ["0x4c3821",
    "8a 56 16"
  ],
  [
    ["0x4c3824",
    "80 fa 05"
  ],
  [
    ["0x4c3949",
    "84 d2"
  ],
  [
    ["0x4c3951",
    "8d 7e 02"
  ],
  [
    ["0x4c3960",
    "66 8b 08"
  ],
  [
    ["0x4c3973",
    "0f 84 b7 00 00 00"
  ],
  [
    ["0x4c3979",
    "8b 5e 18"
  ],
  [
    ["0x4c39a3",
    "0f b6 7e 17"
  ],
  [
    ["0x4c39b2",
    "8a 9e 90 00 00 00"
  ],
  [
    ["0x4c39c3",
    "8a 96 86 00 00 00"
  ],
  [
    ["0x4c39f8",
    "e8 5c 01 3d 00"
  ],
  [
    ["0x4c39fd",
    "89 9f a0 68 00 00"
  ],
  [
    ["0x4c3a03",
    "8b 46 1c"
  ],
  [
    ["0x4c3a0a",
    "8d 8e 92 00 00 00"
  ],
  [
    ["0x4c3a10",
    "e8 6b f6 ff ff"
  ],
  [
    ["0x4c3a15",
    "80 be 90 00 00 00 00"
  ],
  [
    ["0x4c3a24",
    "e8 47 f7 ff ff"
  ],
  [
    ["0x4c3a29",
    "33 c0"
  ],
  [
    ["0x4c3c16",
    "8b 48 02"
  ],
  [
    ["0x4c3c1a",
    "8d 48 06"
  ],
  [
    ["0x4c3c1d",
    "e8 5e f4 ff ff"
  ],
  [
    ["0x4c30aa",
    "85 db"
  ],
  [
    ["0x4c30be",
    "0f b7 0b"
  ],
  [
    ["0x4c30c1",
    "83 c7 03"
  ],
  [
    ["0x4c30c9",
    "80 7b 02 00"
  ],
  [
    ["0x4c30ff",
    "83 c7 0a"
  ],
  [
    ["0x4c3107",
    "0f b6 4e 08"
  ],
  [
    ["0x4c311a",
    "0f b6 56 09"
  ],
  [
    ["0x4c31e4",
    "c7 87 54 bd 00 00 01 00 00 00"
  ],
  [
    ["0x4c31ee",
    "ff 15 a0 25 bd 00"
  ],
  [
    ["0x4c31f4",
    "68 41 42 0f 00"
  ],
  [
    ["0x4c31f9",
    "89 87 58 bd 00 00"
  ]
]

def main(filename):
    data=Path(filename).read_bytes()
    assert len(data)==12472320 and hashlib.sha256(data).hexdigest()==TARGET_SHA256
    pe=struct.unpack_from("<I",data,0x3c)[0]
    assert data[pe:pe+4]==b"PE\0\0"
    assert struct.unpack_from("<H",data,pe+4)[0]==0x14c
    opt=pe+24
    assert struct.unpack_from("<H",data,opt)[0]==0x10b
    base=struct.unpack_from("<I",data,opt+28)[0]
    assert base==0x400000
    section_start=opt+struct.unpack_from("<H",data,pe+20)[0]
    sections={}
    for i in range(struct.unpack_from("<H",data,pe+6)[0]):
        off=section_start+i*40
        name=data[off:off+8].split(b"\0")[0].decode()
        virtual,rva,raw_size,raw=struct.unpack_from("<IIII",data,off+8)
        sections[name]=(base+rva,virtual,raw,raw_size)
    assert sections[".text"][:3]==(0x401000,0x7d01f0,0x400)
    assert sections[".rdata"][:3]==(0xbd2000,0x18e07c,0x7d0600)
    assert sections[".data"][:3]==(0xd61000,0x2873d8,0x95e800)
    assert len(CHECKS)==len({v for v,_ in CHECKS})==64
    for va_str,hexbytes in CHECKS:
        va=int(va_str,16)
        raw=sections[".text"][2]+va-sections[".text"][0]
        expected=bytes.fromhex(hexbytes)
        assert data[raw:raw+len(expected)]==expected,hex(va)
    raw_vptr=sections[".rdata"][2]+0xbfb04c-sections[".rdata"][0]
    assert struct.unpack_from("<I",data,raw_vptr)[0]==0x440790
    raw_lo=sections[".text"][2]
    raw_hi=raw_lo+sections[".text"][3]
    positions=[]
    start=raw_lo
    while True:
        j=data.find(bytes.fromhex("08 a8 fb 00"),start,raw_hi)
        if j<0:break
        positions.append(j)
        start=j+1
    assert len(positions)==7
    assert 0xfba808-sections[".data"][0]>=sections[".data"][3]
    assert 0x13*8+0x5eac==0x5f44
    assert 0x7a*8+0x5eac==0x627c
    assert 0x92+3+2*10==0xa9 and 6+3+2*10==29
    print("PASS: source SHA/PE32 + 64 original instruction slices")
    print("PASS: vtable mode pointer, 7 direct global references, virtual-zero tail, handler stride & synthetic cursor arithmetic")
    print("LIMIT: no Client execution, no Server first-message or official request-reply pairing")
if __name__=="__main__":
    if len(sys.argv)!=2:
        raise SystemExit("Usage: python -B verify.py /path/Tartaros.bin")
    main(sys.argv[1])
