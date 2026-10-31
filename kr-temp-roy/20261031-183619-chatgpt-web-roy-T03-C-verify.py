#!/usr/bin/env python3
"""T03-C bounded KR native slice verification; no game execution."""
import hashlib,struct,sys
from pathlib import Path
EXPECTED="9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
SLICES=[
  [
    "4c30a5",
    "e8 96 11 00 00"
  ],
  [
    "4c30aa",
    "85 db"
  ],
  [
    "4c30be",
    "0f b7 0b"
  ],
  [
    "4c30c1",
    "83 c7 03"
  ],
  [
    "4c30c4",
    "e8 47 44 04 00"
  ],
  [
    "4c30c9",
    "80 7b 02 00"
  ],
  [
    "4c30f6",
    "68 50 b0 bf 00"
  ],
  [
    "4c30ff",
    "83 c7 0a"
  ],
  [
    "4c3107",
    "0f b6 4e 08"
  ],
  [
    "4c3112",
    "0f b7 06"
  ],
  [
    "4c311a",
    "0f b6 56 09"
  ],
  [
    "4c312a",
    "e8 e1 44 04 00"
  ],
  [
    "4c314a",
    "68 43 42 0f 00"
  ],
  [
    "5075c0",
    "8b 7e 18"
  ],
  [
    "5075ce",
    "e8 cd 05 00 00"
  ],
  [
    "507657",
    "89 55 98"
  ],
  [
    "507695",
    "0f b7 ce"
  ],
  [
    "50769b",
    "c1 e1 10"
  ],
  [
    "50769e",
    "0b cf"
  ],
  [
    "5076af",
    "e8 3c 87 f7 ff"
  ],
  [
    "507721",
    "e8 ea 03 00 00"
  ],
  [
    "5077a3",
    "39 02"
  ],
  [
    "5077ea",
    "8b 48 44"
  ],
  [
    "507851",
    "83 45 08 60"
  ],
  [
    "507913",
    "39 02"
  ],
  [
    "66b93c",
    "a1 54 1b fe 00"
  ],
  [
    "66b94a",
    "e8 d1 0d 00 00"
  ],
  [
    "66b9d5",
    "e8 56 0e 00 00"
  ],
  [
    "66b9e3",
    "e8 38 00 00 00"
  ],
  [
    "66b9e9",
    "e8 e2 01 00 00"
  ],
  [
    "66c0c1",
    "8b 81 f0 00 00 00"
  ],
  [
    "66c0f9",
    "8b 81 f4 00 00 00"
  ],
  [
    "66c132",
    "e8 89 b7 e9 ff"
  ],
  [
    "66c141",
    "e8 0a b6 e9 ff"
  ],
  [
    "66c17e",
    "83 3d 94 42 f9 00 00"
  ],
  [
    "66c18b",
    "85 db"
  ],
  [
    "66c193",
    "85 f6"
  ],
  [
    "66c1a7",
    "e8 14 96 e2 ff"
  ],
  [
    "66c21d",
    "83 fb 04"
  ],
  [
    "66c22a",
    "83 fb 05"
  ],
  [
    "66c247",
    "e8 74 95 e2 ff"
  ],
  [
    "66c629",
    "8b 48 10"
  ],
  [
    "66c62c",
    "81 f9 09 07 00 00"
  ],
  [
    "66c637",
    "8b 8e f0 00 00 00"
  ],
  [
    "66c643",
    "e8 88 f5 ff ff"
  ],
  [
    "66c667",
    "81 f9 0a 07 00 00"
  ],
  [
    "66c678",
    "3b 51 20"
  ],
  [
    "66c6b9",
    "e8 d2 f9 ff ff"
  ],
  [
    "66c6c4",
    "81 f9 78 05 00 00"
  ],
  [
    "66c6d5",
    "3b 51 20"
  ],
  [
    "66c711",
    "33 c9"
  ],
  [
    "66c713",
    "e8 78 f9 ff ff"
  ],
  [
    "4956f7",
    "6a 01"
  ],
  [
    "4957e0",
    "6a 02"
  ],
  [
    "4957e4",
    "68 e0 20 00 00"
  ],
  [
    "4957ea",
    "ff d2"
  ],
  [
    "4957fd",
    "68 de 20 00 00"
  ],
  [
    "495803",
    "ff d2"
  ],
  [
    "495807",
    "85 ff"
  ],
  [
    "49580f",
    "85 db"
  ],
  [
    "495817",
    "83 be 60 bf 00 00 00"
  ],
  [
    "495838",
    "e8 a2 0b 37 00"
  ],
  [
    "495853",
    "e8 78 08 37 00"
  ],
  [
    "49585e",
    "c7 80 b0 a0 00 00 01 00 00 00"
  ],
  [
    "495868",
    "c7 86 60 bf 00 00 00 00 00 00"
  ],
  [
    "495935",
    "6a 39"
  ],
  [
    "49595b",
    "89 be 64 bf 00 00"
  ],
  [
    "495962",
    "89 9e 68 bf 00 00"
  ],
  [
    "49597e",
    "8b 0d 54 a8 fb 00"
  ],
  [
    "4959b0",
    "68 1c 5a c0 00"
  ],
  [
    "4959cc",
    "6a 01"
  ],
  [
    "806fc3",
    "83 3d 58 a8 fb 00 00"
  ]
]
def main(p):
 b=Path(p).read_bytes()
 assert len(b)==12472320 and hashlib.sha256(b).hexdigest()==EXPECTED,"wrong KR BIN"
 pe=struct.unpack_from("<I",b,0x3c)[0]
 assert b[pe:pe+4]==b"PE\0\0"
 assert struct.unpack_from("<H",b,pe+4)[0]==0x14c
 opt=pe+24
 assert struct.unpack_from("<H",b,opt)[0]==0x10b
 assert struct.unpack_from("<I",b,opt+28)[0]==0x400000
 sec=opt+struct.unpack_from("<H",b,pe+20)[0]
 sections={}
 for i in range(struct.unpack_from("<H",b,pe+6)[0]):
  at=sec+40*i
  name=b[at:at+8].rstrip(b"\0").decode("ascii")
  virtual,rva,rawsize,raw=struct.unpack_from("<IIII",b,at+8)
  sections[name]=(0x400000+rva,raw,virtual,rawsize)
 assert sections[".text"][:2]==(0x401000,0x400)
 assert sections[".rdata"][:2]==(0xbd2000,0x7d0600)
 assert sections[".data"][:2]==(0xd61000,0x95e800)
 assert len(SLICES)==len({v for v,_ in SLICES})
 for vas,hexvalue in SLICES:
  va=int(vas,16); expected=bytes.fromhex(hexvalue)
  raw=va-sections[".text"][0]+sections[".text"][1]
  assert b[raw:raw+len(expected)]==expected,"instruction mismatch "+vas
 assert 0x92+3+2*10==0xa9
 assert 6+3+2*10==29
 print("PASS",len(SLICES),"representative C native instruction slices, PE/SHA and group arithmetic")
 print("LIMIT: static exact bytes, not original Server response, T01 FULL-PASS or runtime UI")
if __name__=="__main__":
 if len(sys.argv)!=2: raise SystemExit("Usage: python -B verify.py /path/Tartaros.bin")
 main(sys.argv[1])
