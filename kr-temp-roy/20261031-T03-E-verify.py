#!/usr/bin/env python3
"""Read-only KR T03-E W17-W20 native verifier. 485 exact original byte slices.
Does NOT execute Client, validate original Server, or assert T01 FULL-PASS.
"""
import argparse,base64,zlib,json,hashlib,struct
from pathlib import Path
SHA_BIN="9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
SHA_EXE="03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f"
B64="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"
def u16(b,p):return struct.unpack_from("<H",b,p)[0]
def u32(b,p):return struct.unpack_from("<I",b,p)[0]
def main():
 a=argparse.ArgumentParser()
 a.add_argument("bin",type=Path);a.add_argument("--exe",type=Path)
 o=a.parse_args()
 b=o.bin.read_bytes()
 assert len(b)==12472320 and hashlib.sha256(b).hexdigest()==SHA_BIN,"wrong target"
 if o.exe:assert hashlib.sha256(o.exe.read_bytes()).hexdigest()==SHA_EXE,"wrong EXE"
 pe=u32(b,0x3c)
 assert b[pe:pe+4]==b"PE\x00\x00" and u16(b,pe+4)==0x14c
 opt=pe+24
 assert u16(b,opt)==0x10b and u32(b,opt+28)==0x400000
 sections={}
 for i in range(u16(b,pe+6)):
  q=opt+u16(b,pe+20)+i*40
  name=b[q:q+8].split(b"\x00")[0].decode()
  vs,rva,rs,raw=struct.unpack_from("<IIII",b,q+8)
  sections[name]=(0x400000+rva,raw,vs,rs)
 assert sections[".text"]==(0x401000,0x400,0x7d01f0,0x7d0200)
 assert sections[".rdata"][:2]==(0xbd2000,0x7d0600)
 def rawread(va,n,section):
  start,raw,virtual,size=sections[section]
  assert start<=va and va+n<=start+size
  return b[raw+va-start:raw+va-start+n]
 entries=json.loads(zlib.decompress(base64.b64decode(B64)))
 assert len(entries)==485 and len({a for a,_ in entries})==485
 for v,hexbytes in entries:
  va=int(v,16);expect=bytes.fromhex(hexbytes)
  assert rawread(va,len(expect),".text")==expect,v
 assert u32(rawread(0xc0d160,4,".rdata"),0)==0x4fda30
 assert rawread(0x49337a,6,".text")==bytes.fromhex("89 90 b8 04 00 00")
 assert rawread(0x5a69a0+0x33,1,".text")==b"\x04"
 assert u32(rawread(0x5a6988+4*4,4,".text"),0)==0x5a68d8
 assert 0xf8d9e0+0x6924==0xf94304
 assert 10*0x210==0x14a0 and 65+53*2==171 and 2+53*2==108
 print("PASS: 485/485 exact native KR instruction slices; SHA/PE/vtable/event-map/stride")
 print("LIMIT: static evidence, original Server transaction/UI runtime/T01 review NOT_VERIFIED")
if __name__=="__main__":main()
