#!/usr/bin/env python3
"""T01 T16 limited independent native/resource revalidation. No target execution."""
import hashlib,struct,sys
from pathlib import Path
if len(sys.argv)!=3: raise SystemExit("python revalidate.py /path/Tartaros.bin /path/Event.stp")
bin=Path(sys.argv[1]).read_bytes(); evt=Path(sys.argv[2]).read_bytes()
assert hashlib.sha256(bin).hexdigest()=="9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
assert hashlib.sha256(evt).hexdigest()=="2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b"
S=[
("err117-mode1",0x636bbe,0x636c08,"de0f854fa7efe3e49b8b3cc4580748b2f8cca0bb780afb1153ad9697dc9fcee1","bin"),
("err117-mode3",0x636c84,0x636cfa,"3099070a534bbe39f8a0239dea9968031f3be268fcf9163a577c36de611f0e66","bin"),
("err117-action",0x636df8,0x636e06,"0684c2080a73774ed3775d0db06007be298203ca6f076ba3538f076d9caa2b40","bin"),
("err117-36sender",0x636e42,0x636eb9,"0cda34dd348d278422c5a6adb64da226307f643cbff0c0342c5f1b6ad43d95e6","bin"),
("err117-independent36",0x4b3510,0x4b356c,"71b378cac33808dc4419240471935b14535edabd107b8ca1bad0664f8b14793c","bin"),
("err117-talkboxQID",0x63654e,0x6365ab,"839b88b1592adce784a18729c6a94a987e22e21b5e6ac85233cd25f02becb511","bin"),
("err117-talkboxPointer",0x636687,0x6366b8,"162e0536de27bebb43565a850e73ff5ea8701db587c6663327873fbece7eb0e9","bin"),
("err117-mode2UI",0x5b6dae,0x5b6e30,"89dabd3a9353d095083c6d10d3c5911ae76e8da1b187ac8110688ee45a133533","bin"),
("T16-126-actor",0x543700,0x543798,"921438da7b461f1a924af7f69549f8a34fed2a522a2f65a80c56e852a11788dd","bin"),
("T16-127-event",0x5442cc,0x54431f,"18e83f78cbaaad6dc739473abc27af657f0a7e0f2814ef8637450472e9d36cda","bin"),
("T16-128-dispatch",0x5020b0,0x50216b,"653496619415053f4a7b39a8dd78dbfeac7cb1038015dfc2e7ea030a0e53afb8","bin"),
("T16-129-event-list",0x5607d0,0x56087d,"4ceb084e68d83dabed5b6c7d14a4238b5f32688e2dc189e08216d0ef636accd7","bin"),
("T16-130-table-list",0x47dd08,0x47de40,"37d340668f99d3b2cb6b6a2b309aec1d2af19bdac891f24c45813439e7d7b9da","bin"),
("T16-131-controller",0x503040,0x5030bf,"bb262cf90e46e985bd2ffca7af9d529db9ddb6552659ee17e9674ad05bea3a53","bin"),
("T16-132-first",0x47d530,0x47d5f8,"aed007a244e9e261b6eda3cc31ddaa6df8588c7eeaad11c38b80ea204727c65a","bin"),
("Scene1",0x96943e,0x9696a6,"e0a3e5809ea2d39116b4a11adb9e2d3c9173d89c16cdfe8343e8f7f563de5deb","stp"),
("Scene2",0x96883e,0x968c4f,"1ba55891d8ef770a868128ba0ebd18fff44524128e70d066b8faf67441f2b012","stp"),
("Scene3",0x8c1c3e,0x8c2276,"3c848c3f678426bd46899c18cf923688900168e9638d9c8d7a694ebd9b7e09ee","stp"),
("Scene4",0x96903e,0x9691d8,"d6ca315a6eb92441b1271a7e9581328e9a0689afbf95bdca2b0812b53eb4dda2","stp"),
("qbase compiled",0xa20810,0xa2364c,"d6e01d85194f452d56961252d797a0e671d7e34a11fe07e96155220f27ee4cc3","stp")]
for name,start,end,expect,source in S:
 raw=bin[start-0x400c00:end-0x400c00] if source=="bin" else bytes(x^255 for x in evt[start:end])
 actual=hashlib.sha256(raw).hexdigest()
 if actual!=expect:raise AssertionError((name,expect,actual))
assert struct.unpack_from("<I",bin,0xc0f860-0x401a00)[0]==0x544070
for action,case,target in [(0xf438a,11,0x5b7fed),(0xf438b,12,0x5b7fff),(0xf43d9,30,0x5b8167)]:
 idx=action-0xf4364
 slot=bin[0x5b8460-0x400c00+idx]
 assert slot==case
 assert struct.unpack_from("<I",bin,0x5b8394-0x400c00+slot*4)[0]==target
print("PASS",len(S),"original source SHA slices, vtable and 3 original action jump-table paths; NOT WHOLE-FILE FULL_PASS")
