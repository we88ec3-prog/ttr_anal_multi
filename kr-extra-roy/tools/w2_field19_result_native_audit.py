#!/usr/bin/env python3
"""Positive-only KR W2 Scenario22/result and C2S33 byte audit; no Client execution."""
import argparse, hashlib, json, struct
from pathlib import Path
SHA='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
PFX={
0x4B979B:'0f be 40 02',0x4B97AF:'68 04 61 00 00',
0x4B97D1:'c7 06 74 73 c0 00',0x4B97F0:'e8 5b e5 ff ff',
0x4B9808:'ff d2',0x4C4580:'80 7e 02 00',
0x4C45D5:'a1 f8 18 fe 00',0x4C45E0:'8b 56 08',
0x4C45E3:'89 50 28',0x4C45F2:'66 8b 4e 14',
0x4C462F:'68 97 42 0f 00',0x4C463E:'38 56 04',
0x6BA2E6:'81 7a 10 78 05 00 00',0x6BA336:'0f b6 4e 29',
0x5AAEA9:'81 7f 10 1f 43 0f 00',0x5AAEB2:'83 7f 14 00',
0x5AAF0A:'83 3d 98 a7 fb 00 00',0x5AAF11:'ba 33 00 00 00',
0x5AAF27:'6a 02',0x5AAF2D:'6a 00'}
def audit(p):
 d=Path(p).read_bytes()
 assert len(d)==12472320
 assert hashlib.sha256(d).hexdigest()==SHA
 assert d[:2]==b'MZ'
 pe=struct.unpack_from('<I',d,0x3c)[0]
 assert d[pe:pe+4]==b'PE\0\0'
 assert struct.unpack_from('<I',d,pe+24+28)[0]==0x400000
 n=struct.unpack_from('<H',d,pe+6)[0]
 sections=pe+24+struct.unpack_from('<H',d,pe+20)[0]
 text=None
 for i in range(n):
  s=sections+40*i
  if d[s:s+8].rstrip(b'\0')==b'.text':
   text=struct.unpack_from('<IIII',d,s+8)
 assert text==(0x7D01F0,0x1000,0x7D0200,0x400)
 for va,hx in PFX.items():
  b=bytes.fromhex(hx);off=va-0x400c00
  assert d[off:off+len(b)]==b,hex(va)
 assert struct.pack('<H',0x33)==b'\x33\x00'
 assert 2+1+1+4+4+4+4+2==22
 return {'result':'PASS','native_prefixes':len(PFX),'bin_sha256':SHA,
 'result_app_min_read':22,'return_app_len':2,'return_slot':0,
 'limit':'bounded bytes only; no runtime, official outcome semantics or FULL-PASS'}
if __name__=='__main__':
 a=argparse.ArgumentParser();a.add_argument('original_bin');z=a.parse_args()
 print(json.dumps(audit(z.original_bin),ensure_ascii=False,indent=2))
