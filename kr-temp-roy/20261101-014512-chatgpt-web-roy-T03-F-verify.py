#!/usr/bin/env python3
"""T03-F bounded original KR BIN verifier. Never executes/patches Client."""
import hashlib,struct,sys
from pathlib import Path
BIN_SHA="9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
EXE_SHA="03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f"
# Exact original .text raw byte SHA of continuous native instruction ranges.
RANGES=[
("employ_event",0x6bf2a0,0x6bf304,"9a57663a4a7022bc9d7e665c0174b422f909695fbcbe01800b4fb22a45aaaf6e"),
("employ_data",0x6bf310,0x6bf463,"a5db001151b46b6b2546f4c9cd90de43009ebd7298b9da5c4c0e61bbe679d3e5"),
("employ_alt_ui",0x6bfae0,0x6bfb3d,"11b8828a189039795168dc44eee37acd0843aab1e1891383e6737036a38bf3fb"),
("sender33",0x4a38d0,0x4a38ff,"5aa549d9b5859fe82384b7cbec7add1d5b57b5ce5474692f0eafa44fbd0f74da"),
("secondary33_ui",0x5aae80,0x5aaf35,"48eac3657fbdfd7eac7591c83c6b41693c40e908702a8f6ce756e223ed979558"),
("other_33_ui",0x6ba2c0,0x6ba358,"33ef4d4be7859fcd67b64cda7aa2a16c9b35fedccadf6333aa85ca9ebde06326"),
("other_33_builder",0x6ba360,0x6ba3af,"ff5de85bf697c95fc624d6752184d47327da94bd102b0175ad842e22ae3364c8"),
("other_33_key",0x6ba730,0x6ba74a,"510933d7f3dd2a75c56c69e18ecacba1513ee36c9d36b611ec0aa7bf205c2807"),
("event_F431F",0x4a98d0,0x4a9948,"6d9bbc7f9c9412a62acf969ac5aef63fe6427402114425d40192aa6c5f370cbe"),
("default_s2c",0x4b7ec0,0x4b7ef1,"d0f1c5f3408f218cc32c7ef1ba89ea8f4ade78cd5113d8c52330f9e6131eedf9"),
("scene_register",0x4b7dc0,0x4b7ec0,"fa48613974a308ddf6c2eb90bea82195fc9d77023c4c918585f5e6dc6bcb7f32"),
("delta_writer",0x4e2730,0x4e27a5,"77a83462bf7fb515ae77f6214a8db0fe946d6d86c6698ed6b54f15eedf80070f"),
("record_writer",0x4d4150,0x4d419d,"6a579dcbf1504b8db20b0865abf134521ef85fb7728a178c7ab80968ac03f9d4"),
("b6_event",0x4b5dd0,0x4b5e4a,"5d0f992120af2956a0be03e67960edb3fa717654c4aa39e1ae4f4d5bfb1f51f8"),
("page_role_ui",0x5a68d8,0x5a6905,"da540fb1996406213ee01f01484c55e84636d97085303e6f4a9815d4252c6172")]
# Representative independently addressed machine instructions across key new chains.
SLICES={
0x6bf2a6:"81 78 10 78 05 00 00",0x6bf2c5:"83 b8 4c 5f 00 00 01",
0x6bf2d5:"e8 06 08 00 00",0x6bf2fa:"e8 d1 45 de ff",
0x4a38d4:"83 3d 98 a7 fb 00 00",0x4a38db:"b8 33 00 00 00",
0x4a38f1:"6a 02",0x4a38f7:"6a 00",0x4a38f9:"ff d2",
0x5aaea9:"81 7f 10 1f 43 0f 00",0x5aaeb2:"83 7f 14 00",
0x5aaed2:"e8 39 44 11 00",0x5aaf11:"ba 33 00 00 00",
0x5aaf27:"6a 02",0x5aaf2d:"6a 00",0x5aaf2f:"ff d0",
0x6ba2e6:"81 7a 10 78 05 00 00",0x6ba336:"0f b6 4e 29",
0x6ba33b:"68 1f 43 0f 00",0x6ba730:"55",0x6ba733:"83 7d 08 0d",
0x6ba739:"e8 22 fc ff ff",0x6ba38b:"b8 33 00 00 00",
0x6ba3a1:"6a 02",0x6ba3a7:"6a 00",0x6ba3a9:"ff d2",
0x4a992a:"68 1f 43 0f 00",0x6bf38f:"83 fe 09",
0x6bf39a:"69 c0 10 02 00 00",0x6bf3a0:"03 05 04 43 f9 00",
0x6bf3a6:"83 78 5c 00",0x4b7ec3:"83 b9 ac 5e 00 00 00"}
def u16(buf,pos):return struct.unpack_from("<H",buf,pos)[0]
def u32(buf,pos):return struct.unpack_from("<I",buf,pos)[0]
def main(bin_path,exe_path=None):
    b=Path(bin_path).read_bytes()
    assert len(b)==12472320 and hashlib.sha256(b).hexdigest()==BIN_SHA,"KR BIN version mismatch"
    if exe_path:assert hashlib.sha256(Path(exe_path).read_bytes()).hexdigest()==EXE_SHA
    pe=u32(b,0x3c)
    assert b[pe:pe+4]==b"PE\x00\x00" and u16(b,pe+4)==0x14c
    opt=pe+24
    assert u16(b,opt)==0x10b and u32(b,opt+28)==0x400000
    section_start=opt+u16(b,pe+20)
    sections={}
    for i in range(u16(b,pe+6)):
        q=section_start+40*i
        name=b[q:q+8].split(b"\x00")[0].decode()
        virtual,rva,raw_size,raw=struct.unpack_from("<IIII",b,q+8)
        sections[name]=(0x400000+rva,virtual,raw,raw_size)
    assert sections[".text"][:3]==(0x401000,0x7d01f0,0x400)
    assert sections[".rdata"][:3]==(0xbd2000,0x18e07c,0x7d0600)
    def at(va,section=".text"):
        start,vs,raw,rs=sections[section]
        assert start<=va<start+rs,(hex(va),section)
        return raw+va-start
    for label,start,end,hashv in RANGES:
        actual=hashlib.sha256(b[at(start):at(end-1)+1]).hexdigest()
        assert actual==hashv,label
    for va,hexbytes in SLICES.items():
        expected=bytes.fromhex(hexbytes)
        assert b[at(va):at(va)+len(expected)]==expected,hex(va)
    for cell,target in {
        0xc3f180:0x6bf2a0,0xc3f164:0x65d550,0xc33db4:0x65d550,
        0xc3e2e8:0x6ba2c0,0xc3e278:0x6ba730
    }.items():
        assert u32(b,at(cell,".rdata"))==target,hex(cell)
    assert b".?AVCEmployNewCharacter@FUI@@" in b
    assert b".?AVCCharChangeDialog@FUI@@" in b
    # Direct literal addresses only, excluding register-computed/indirect setters.
    text_bytes=b[0x400:0x400+0x7d0200]
    assert text_bytes.find(bytes.fromhex("94 2e fd 00"))<0
    print("PASS:",len(RANGES),"exact original native ranges,",
          len(SLICES),"specific instruction slices, PE/SHA, 5 vtable cells, 2 RTTI")
    print("NOT VALIDATED: official Server pairing, Client runtime, full T01 semantic review")
if __name__=="__main__":
    if len(sys.argv) not in (2,3):
        raise SystemExit("Usage: python -B T03-F-verify.py Tartaros.bin [Tartaros.exe]")
    main(sys.argv[1],sys.argv[2] if len(sys.argv)==3 else None)
