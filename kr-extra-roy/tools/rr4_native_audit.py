#!/usr/bin/env python3
"""RR-0004 bounded, read-only KR Tartaros.bin static verification.
No game execution, patching or network use. Standard library only.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct

EXPECTED_HASH = '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
EXPECTED = {
    0xA02C: [0x805D04, 0x806205],
    0x5010: [0x7438C4],
    0xA014: [0x7D1913],
    0x500C: [0x8077C0, 0x8077CC, 0x80789C, 0x807A21, 0x807AAD, 0x807AFC],
}
PREFIXES = {
    0x805D02: 'c6 86 2c a0 00 00 02',
    0x806202: '0f be 86 2c a0 00 00',
    0x8059E9: 'e8 62 05 00 00',
    0x806218: '74 15 48 74 01 48',
    0x806223: 'e8 08 16 00 00',
    0x80623A: 'e8 31 18 00 00',
    0x806246: '0f 84 58 01 00 00',
    0x80624F: '8b 0b',
    0x806275: 'ff 8e 78 a0 00 00',
    0x8063A4: '83 be b4 a0 00 00 01',
    0x807887: '3d 00 10 00 00',
    0x8078A2: '81 fa 00 40 00 00',
    0x807A97: '81 fb 00 10 00 00',
    0x807AB3: '81 f9 00 40 00 00',
    0x7438C3: 'b8 10 50 00 00',
    0x7D1910: '8b 8c b7 14 a0 00 00',
}
def main():
    a = argparse.ArgumentParser(description=__doc__)
    a.add_argument('bin', type=Path)
    args = a.parse_args()
    data = args.bin.read_bytes()
    digest = hashlib.sha256(data).hexdigest()
    assert digest == EXPECTED_HASH, f'Unexpected KR version / hash: {digest}'
    assert data[:2] == b'MZ'
    pe = struct.unpack_from('<I', data, 0x3c)[0]
    assert data[pe:pe+4] == b'PE\0\0'
    nsect = struct.unpack_from('<H', data, pe+6)[0]
    optional = pe+24
    image_base = struct.unpack_from('<I', data, optional+28)[0]
    section_start = optional+struct.unpack_from('<H', data, pe+20)[0]
    text_section = None
    for k in range(nsect):
        off = section_start+40*k
        if data[off:off+8].split(b'\0')[0] == b'.text':
            virt_size, rva, raw_size, raw_off = struct.unpack_from('<IIII', data, off+8)
            text_section = (image_base+rva, raw_off, virt_size, raw_size)
            break
    assert text_section is not None
    va0, raw0, virt_size, raw_size = text_section
    assert (va0,raw0,virt_size,raw_size) == (0x401000,0x400,0x7d01f0,0x7d0200)
    code = data[raw0:raw0+virt_size]
    def scan_num(n):
        needle = n.to_bytes(4, 'little')
        found,start = [],0
        while (pos := code.find(needle,start)) >= 0:
            found.append(va0+pos)
            start = pos+1
        return found
    for value,expected in EXPECTED.items():
        actual = scan_num(value)
        assert actual == expected, f'{value:#x}: {actual} != {expected}'
    for va,hexdump in PREFIXES.items():
        exp = bytes.fromhex(hexdump)
        pos = raw0+va-va0
        assert data[pos:pos+len(exp)] == exp, f'bad native bytes @ {va:#x}'
    # Synthetic number gates, not a runtime test or original packet capture.
    def choose(n,used,mode):
        if n <= 0 or n > 4096 or used < 0: return 'NONE'
        if mode != 0 and n+6 <= 4096 and used+n+6 <= 16384:
            return '0BBB'
        if n+4 <= 4096 and used+n+4 <= 16384:
            return '1A68'
        return 'NONE'
    vectors = [(57,0,2,'0BBB'),(4090,0,2,'0BBB'),
               (4091,0,2,'1A68'),(4092,0,2,'1A68'),
               (4093,0,2,'NONE'),(4096,0,2,'NONE'),
               (57,0,0,'1A68'),(1,16377,2,'0BBB'),
               (1,16378,2,'1A68'),(1,16379,2,'1A68'),
               (1,16380,2,'NONE'),(0,0,2,'NONE')]
    for n,used,mode,out in vectors:
        assert choose(n,used,mode) == out,(n,used,mode,out)
    print(json.dumps({'status':'PASS','sha256':digest,
        'text':{'virtual_address':hex(va0),'raw_offset':hex(raw0),'virtual_size':virt_size},
        'literal_operand_hits':{hex(k):[hex(x) for x in v] for k,v in EXPECTED.items()},
        'verified_instruction_prefixes':len(PREFIXES),
        'synthetic_guard_vectors':len(vectors),
        'limits':'Literal scan cannot exclude indirect alias/memcpy; synthetic vectors are not wire captures.'
        },ensure_ascii=False,indent=2))
if __name__ == '__main__':
    main()
