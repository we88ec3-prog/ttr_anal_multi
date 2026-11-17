#!/usr/bin/env python3
"""Read-only static evidence verifier for the ordinary-field one-shot study.
No Client/Lua/Server execution, network fetch, Git write, or game-resource output.
The STPD and Lua inspection helpers below are reused from published R14,
blob 07615c139a6f19221355110cba857807559f7298, which adapts the R2 parser
blob 8e6e3c51c55a0bb155f05165b496d7d519fb7b7e. They parse data, not execute Lua.
GNU objdump and Python standard library required. Run without -O.
"""
import argparse, hashlib, json, re, struct, subprocess, sys, zlib
from pathlib import Path
import xml.etree.ElementTree as ET
if sys.flags.optimize:
    raise RuntimeError("Run without -O: assertions are evidence checks")
def sha(b):return hashlib.sha256(b).hexdigest()
def ex_decode(data):
 if data[:2]!=b'EX':return data
 mode=data[2];n,size,off=struct.unpack_from('<III',data,4)
 assert mode in (0,1) and off>=16 and off+n<=len(data)
 payload=data[off:off+n]
 if mode:
  key=[0x30,0xe7]
  for i in range(2,1024):key.append((key[i-2]+key[i-1]+0x13-(0x56 if i==0x17c else 0))&255)
  payload=bytes(v^key[i%1024] for i,v in enumerate(payload))
 result=zlib.decompress(payload);assert len(result)==size
 return result
class STP:
 def __init__(self,path):
  self.path=Path(path);raw=self.path.read_bytes();assert raw[:4]==b'STPD'
  self.sha=sha(raw);self.b=bytes(x^255 for x in raw);b=self.b;idx=struct.unpack_from('<I',b,4)[0]
  assert raw[idx:idx+4]==b'STPI';p=idx+8;self.files={}
  def node(parent):
   nonlocal p
   n=struct.unpack_from('<H',b,p)[0];p+=2
   name=b[p:p+n].decode('ascii').rstrip('\0');p+=n;kind=b[p];p+=1;path='/'.join(filter(None,[parent,name]))
   if kind in (1,2):
    count=struct.unpack_from('<I',b,p)[0];p+=12
    for _ in range(count):node(path)
   elif kind==0:
    _,ident=struct.unpack_from('<II',b,p);p+=16;self.files[path]=ident
   else:raise ValueError(kind)
  node('');assert p==len(b)
  table=struct.unpack_from('>I',b,12)[0];n=struct.unpack_from('<I',b,table)[0]
  self.blocks={}
  for i in range(n):
   ident,size,first,last=struct.unpack_from('<4I',b,table+4+i*32);self.blocks[ident]=(size,first,last)
 def get(self,name):
  ident=self.files[name];size,first,last=self.blocks[ident];off=16+first*1024
  assert size<=(last-first+1)*1024
  raw=self.b[off:off+size];decoded=ex_decode(raw)
  return decoded,dict(carrier=self.path.name,carrier_sha256=self.sha,path=name,block_id=ident,stored_offset=off,stored_length=size,first_block=first,last_block=last,stored_sha256=sha(raw),decoded_length=len(decoded),decoded_sha256=sha(decoded),prefix=decoded[:12].hex())
