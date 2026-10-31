#!/usr/bin/env python3
"""T08-204: verify bounded KR Actor/CDoll/render-stage native byte edges.

Usage: python -B T08-204-native-pe-verifier.py /path/to/Tartaros.bin
Does not prove T01 FULL-PASS, live GPU pixels or external asset availability.
"""
from pathlib import Path
import hashlib
import struct
import sys

SHA256 = '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
TEXT_BIAS = 0x400C00
RDATA_BIAS = 0x401A00
CODE = {
    0x4D193E:'e8 ad 64 ff ff', 0x4D2827:'e8 c4 55 ff ff',
    0x4C7E21:'39 bb 70 03 00 00', 0x4C7E2D:'8b 83 8c 00 00 00',
    0x4C7E39:'8b b3 88 00 00 00', 0x4C7E3F:'68 70 01 00 00',
    0x4C7E5D:'e8 ee cd 2d 00', 0x4C7E7B:'e8 e0 25 00 00',
    0x4C7E80:'8d bb 5c 01 00 00', 0x4C7E92:'e8 c9 90 01 00',
    0x4C7ECC:'0f b7 8b 88 03 00 00', 0x4C7ED9:'e8 c2 ef 2d 00',
    0x4C7EDE:'80 7d 0c 00', 0x4C7EED:'e8 7e 0f 2e 00',
    0x4C7F02:'c7 83 70 03 00 00 01 00 00 00',
    0x4C7FBD:'c7 40 24 01 00 00 00',
    0x4D1AE0:'e9 9b 6a ff ff', 0x4D2894:'e8 e7 5c ff ff',
    0x4D2A2A:'e8 a1 5d ff ff', 0x4C85AD:'e8 de 22 00 00',
    0x4C85BE:'89 bb ac 00 00 00', 0x4C85C8:'e8 d3 03 00 00',
    0x4C87D9:'83 be 70 03 00 00 00', 0x4C87E6:'8b 86 5c 01 00 00',
    0x4C87FA:'e8 51 d4 2d 00', 0x4C887F:'e8 ac fd 2d 00',
    0x4C8897:'8b 86 68 03 00 00',
    0x7A4CB2:'c7 46 08 b0 f6 c4 00',
    0x7A4CB9:'c7 46 0c c0 f6 c4 00',
    0x7A4CC3:'89 5e 1c', 0x7A4ED0:'89 9e 24 01 00 00',
    0x7A63ED:'83 7f 1c 00', 0x7A63F7:'83 bf 24 01 00 00 00',
    0x7A65D9:'8b 35 38 a8 fb 00', 0x7A65E5:'83 c7 0c',
    0x7A6651:'83 86 b8 00 00 00 04',
    0x7BB2F0:'8b 8e b4 00 00 00',
    0x7BB2FB:'8b 42 04', 0x7BB2FE:'ff d0',
    0x7BB330:'89 9e b8 00 00 00',
    0x7A8327:'83 bb a0 00 00 00 00',
    0x7A8362:'8b 43 10', 0x7A8367:'0f 84 fd 01 00 00',
    0x7A8353:'e8 d8 c0 02 00', 0x7A8385:'e8 76 ed ff ff',
    0x7A5C93:'80 7b 28 00', 0x7A5CAE:'39 73 1c',
    0x7A5D81:'89 83 24 01 00 00', 0x7A5D9E:'89 bb 24 01 00 00',
    0x7A91B5:'89 4b 1c', 0x7A6EFB:'8b 43 18',
    0x7A6F15:'3b 05 94 0e fc 00', 0x7A6F23:'85 c0',
    0x7A6F3A:'e8 d1 9b ff ff', 0x7A6F8B:'c6 43 28 01',
    0x7D34D4:'d9 43 5c', 0x7D34EB:'8b 35 40 77 fb 00',
    0x7D3515:'89 1c 88',
}
VTABLE={
    'CMonster+20':(0xC0C9DC,0x20,0x4D1AE0),
    'CNPC+20':(0xC0CA9C,0x20,0x4D2890),
    'CMonster+24':(0xC0C9DC,0x24,0x4D1AF0),
    'CNPC+24':(0xC0CA9C,0x24,0x4D28C0),
    'CMonster+30':(0xC0C9DC,0x30,0x4D1910),
    'CNPC+30':(0xC0CA9C,0x30,0x4D2820),
    'CDoll_primary+8':(0xC4F67C,0x8,0x7A63C0),
    'CDoll_embedded_C+4':(0xC4F6C0,0x4,0x7A8310),
    'CDoll_embedded_C+8':(0xC4F6C0,0x8,0x7A8E10),
    'CDoll_embedded_8+8':(0xC4F6B0,0x8,0x7A57C0),
}
EDGES={
    0x4D193E:0x4C7DF0,0x4D2827:0x4C7DF0,
    0x4D2894:0x4C8580,0x4D2A2A:0x4C87D0,
    0x4C87FA:0x7A5C50,0x4C7E5D:0x7A4C50,
    0x4C7ED9:0x7A6EA0,0x4C7EED:0x7A8E70,
    0x7A8353:0x7D4430,
}
JUMPS={0x4D1AE0:0x4C8580}

def verify(path):
    binary=Path(path).read_bytes()
    assert len(binary)==12472320, 'Unexpected original KR BIN size'
    assert hashlib.sha256(binary).hexdigest()==SHA256, 'Wrong original KR BIN'
    for va,hexcode in CODE.items():
        offset=va-TEXT_BIAS
        expected=bytes.fromhex(hexcode)
        assert binary[offset:offset+len(expected)]==expected, f'Native code mismatch 0x{va:X}'
    for name,(vptr,delta,target) in VTABLE.items():
        actual=struct.unpack_from('<I',binary,vptr+delta-RDATA_BIAS)[0]
        assert actual==target, f'Vtable mismatch {name}: 0x{actual:X}'
    for site,target in EDGES.items():
        offset=site-TEXT_BIAS
        assert binary[offset]==0xE8, f'No E8 at 0x{site:X}'
        relative=int.from_bytes(binary[offset+1:offset+5],'little',signed=True)
        assert ((site+5+relative)&0xFFFFFFFF)==target, f'Call mismatch 0x{site:X}'
    for site,target in JUMPS.items():
        offset=site-TEXT_BIAS
        assert binary[offset]==0xE9
        relative=int.from_bytes(binary[offset+1:offset+5],'little',signed=True)
        assert ((site+5+relative)&0xFFFFFFFF)==target, f'Jump mismatch 0x{site:X}'
    print('BIN_SHA256_PASS')
    print(f'CODE_ANCHORS_PASS={len(CODE)}; VTABLE_SLOTS_PASS={len(VTABLE)}; E8_PASS={len(EDGES)}; E9_PASS={len(JUMPS)}')
    print('No proof of actual visible pixels, original asset filename mapping, or T01 FULL-PASS')

if __name__=='__main__':
    if len(sys.argv)!=2:
        raise SystemExit('Usage: verify.py Tartaros.bin')
    verify(sys.argv[1])
