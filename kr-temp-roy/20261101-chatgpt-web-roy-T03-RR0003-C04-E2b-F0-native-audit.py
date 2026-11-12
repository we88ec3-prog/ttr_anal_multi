#!/usr/bin/env python3
"""RR-0003 KR-only, offline original-bin-first login C04 E2b/F0 source audit.
Never runs Client, accesses credentials, or contacts a server.
Byte checks, direct-call scan and safe synthetic DTO boundaries are bounded evidence;
not T01 FULL-PASS, runtime wire/Server-first response, or proof of indirect absence.
"""
from pathlib import Path
import argparse
import hashlib
import json
import struct

EXPECTED_SHA = '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
IMAGE_BASE = 0x400000
VA_BASE = 0x401000
RAW_BASE = 0x400
TEXT_VSZ = 0x7D01F0
TEXT_RAW_SIZE = 0x7D0200
CHECKS = {
    0x66DE20:'55 8b ec',
    0x66DE85:'8b b0 48 01 00 00',
    0x66DEE6:'e8 15 84 06 00',
    0x66DF09:'b8 d4 ac fb 00',
    0x66DF0E:'e8 ed 84 06 00',
    0x6D6300:'6a 64',
    0x6D6321:'c7 00 1c b0 bf 00',
    0x6D6340:'c7 40 08 52 00 00 00',
    0x6D6400:'55 8b ec',
    0x6D641B:'6a 00',
    0x6D6424:'e8 e7 f1 db ff',
    0x6D6429:'85 c0',
    0x6D642B:'75 6b',
    0x6D649B:'8b 0e',
    0x6D649F:'8b 52 30',
    0x6D64A7:'ff d2',
    0x440280:'55 8b ec',
    0x440441:'68 c0 af bf 00',
    0x440446:'ff 15 8c 21 bd 00',
    0x440494:'c7 40 08 40 00 00 00',
    0x4404DF:'c7 40 08 52 00 00 00',
    0x44052D:'c7 40 08 54 00 00 00',
    0x440793:'8b 41 08',
    0x440796:'83 f8 52',
    0x4407C2:'e8 99 2b 06 00',
    0x4407CB:'83 f8 54',
    0x4407F7:'e8 b4 29 06 00',
    0x440822:'e8 89 29 06 00',
    0x4A31E3:'b9 0f 00 00 00',
    0x4A31EC:'66 89 8d c4 fe ff ff',
    0x4A31F3:'c7 45 92 01 00 01 00',
    0x4A31FA:'c7 45 96 34 00 00 00',
    0x4A3266:'8b 0d 18 13 fb 00',
    0x4A326C:'66 8b 91 80 bf 00 00',
    0x4A327D:'66 89 55 98',
    0x4A3281:'e8 c7 fb 3e 00',
    0x4A32A3:'e8 a5 fb 3e 00',
    0x4A32B6:'68 d6 00 00 00',
    0x4A32C2:'6a 01',
    0x4A32C4:'ff d2',
    0x4A33AB:'b9 e8 00 00 00',
    0x4A33B0:'66 89 4c 24 74',
    0x4A33B5:'66 8b 8a 80 bf 00 00',
    0x4A33CD:'e8 6e c1 fd ff',
    0x4A340C:'e8 bf 09 29 00',
    0x4A3436:'e8 85 af fc ff',
    0x4A34D3:'6a 33',
    0x4A34E6:'6a 33',
    0x4A34FC:'6a 70',
    0x4A3503:'6a 01',
    0x4A3505:'ff d2',
    0x47F59E:'a1 08 a8 fb 00',
    0x47F5D9:'8b 15 08 a8 fb 00',
    0x4C3821:'8a 56 16',
    0x4C3824:'80 fa 05',
    0x4C3949:'84 d2',
    0x4C3979:'8b 5e 18',
    0x4C3A03:'8b 46 1c',
    0x8069EB:'e8 e0 f6 ff ff',
    0x804AD6:'e8 c5 16 00 00',
    0x806202:'0f be 86 2c a0 00 00',
    0x806223:'e8 08 16 00 00',
    0x80623A:'e8 31 18 00 00',
}
DIRECT_CALLS = {
    0x66DE20:[0x66E23B,0x66E257,0x66E3E0],
    0x440790:[], # no immediate direct E8 in .text; not absence of indirect calls
    0x4A3360:[0x4407C2],
    0x4A31B0:[0x4407F7,0x440822],
    0x6D6400:[0x66DF0E],
}

def verify(path):
    data=path.read_bytes()
    assert len(data)==12472320, 'unexpected original-bin length'
    sha=hashlib.sha256(data).hexdigest()
    assert sha==EXPECTED_SHA, 'original KR BIN SHA mismatch: '+sha
    assert data[:2]==b'MZ'
    off=struct.unpack_from('<I',data,0x3C)[0]
    assert data[off:off+4]==b'PE\0\0'
    assert struct.unpack_from('<I',data,off+24+28)[0]==IMAGE_BASE
    nsections=struct.unpack_from('<H',data,off+6)[0]
    sec=off+24+struct.unpack_from('<H',data,off+20)[0]
    sections={}
    for i in range(nsections):
        s=sec+i*40
        nm=data[s:s+8].split(b'\0')[0].decode('ascii')
        sections[nm]=struct.unpack_from('<IIII',data,s+8)
    assert sections['.text']==(TEXT_VSZ,0x1000,TEXT_RAW_SIZE,RAW_BASE), sections['.text']
    txt=data[RAW_BASE:RAW_BASE+TEXT_VSZ]
    for va,raw_hex in CHECKS.items():
        expected=bytes.fromhex(raw_hex)
        assert txt[va-VA_BASE:va-VA_BASE+len(expected)]==expected, f'{va:#x} native mismatch'
    for dst,known in DIRECT_CALLS.items():
        found=[];start=0
        while (idx:=txt.find(b'\xE8',start))>=0:
            if idx+5<=len(txt):
                rel=struct.unpack_from('<i',txt,idx+1)[0]
                if VA_BASE+idx+5+rel==dst: found.append(VA_BASE+idx)
            start=idx+1
        assert found==known, (hex(dst),list(map(hex,found)),list(map(hex,known)))
    # Static original rdata literal: serverIp.ini and candidate mode markers.
    rdata=sections['.rdata']; offset=lambda va: rdata[3]+va-(IMAGE_BASE+rdata[1])
    assert data[offset(0xBFAFC0):offset(0xBFAFC0)+13]==b'serverIp.ini\0'
    assert data[offset(0xBFAFD0):offset(0xBFAFD0)+6]==b'Rlyeh\0'
    assert data[offset(0xBF2375)]==0 # E8 mode compare target is NUL, not a named enum
    assert struct.unpack_from('<I',data,offset(0xBFB04C))[0]==0x440790 # ctor vtable+0x30
    assert data[offset(0xBFAFD8):offset(0xBFAFD8)+33]==b'81F91496CFC348A89F5AF83CBCDCEAE8\0'
    # Builder DTO canonical extent; synthetic-only and not a captured packet.
    assert (2+51+51+6+2)==112
    assert (2+51*2+51*2+4+2+2)==214
    return dict(result='PASS',bin_sha256=sha,pe_text=sections['.text'],native_byte_assertions=len(CHECKS),direct_call_targets={hex(k):list(map(hex,v)) for k,v in DIRECT_CALLS.items()},synthetic_layout_lengths=[112,214],scope='bounded static only, no Client execution/packet capture/Server policy')

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('original_bin',type=Path)
    a=p.parse_args()
    print(json.dumps(verify(a.original_bin),indent=2,ensure_ascii=False))
