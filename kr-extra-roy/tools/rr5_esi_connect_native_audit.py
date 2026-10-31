#!/usr/bin/env python3
"""Offline, read-only KR RR-0005 supplement: UI ESI -> Connect, key0/2 gates.

Accepts a known Tartaros.bin, never starts or modifies the game.
Requires only the Python standard library. This is a bounded static byte audit,
NOT T01 FULL-PASS, runtime socket evidence, or an all-callsites CFG proof.
"""
from pathlib import Path
import argparse
import hashlib
import json
import struct

SHA = '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
VA_BASE, TEXT_RAW, TEXT_LEN, TEXT_RAW_SIZE = 0x401000, 0x400, 0x7D01F0, 0x7D0200
NATIVE = {
    0x48ABA1: '89 3d 18 13 fb 00',       # Client* global writer
    0x48ACB6: '89 9f 60 bf 00 00',       # BF60=0
    0x48ACBC: '89 9f 64 bf 00 00',       # BF64=0
    0x48ACC2: '89 9f 68 bf 00 00',       # BF68=0
    0x66C1A0: '56',                      # host push
    0x66C1A1: '8b 35 18 13 fb 00',       # ESI global Client*
    0x66C1A7: 'e8 14 96 e2 ff',          # -> 0x4957C0
    0x66C240: '56',
    0x66C241: '8b 35 18 13 fb 00',
    0x66C247: 'e8 74 95 e2 ff',
    0x4957C0: '55 8b ec 83 ec 44',
    0x4957E0: '6a 02 6a 00 68 e0 20 00 00', # key0 port 0x20E0
    0x4957F2: '6a 02 6a 02',              # key2 lane
    0x4957FD: '68 de 20 00 00',          # port 0x20DE
    0x495817: '83 be 60 bf 00 00 00',    # incoming ESI+BF60
    0x495832: '8b 86 60 bf 00 00',
    0x49583E: 'b9 7e 00 00 00',          # WORD 0x7E
    0x495843: '6a 02',                   # n=2
    0x49584C: '8b 8e 60 bf 00 00',
    0x495853: 'e8 78 08 37 00',          # enqueue, return unchecked
    0x49585E: 'c7 80 b0 a0 00 00 01 00 00 00', # mark old key1
    0x495868: 'c7 86 60 bf 00 00 00 00 00 00', # clear BF60
    0x495935: '6a 39',                   # key0 n=57
    0x49593D: 'ff d2',                   # send local builder
    0x49594B: 'ff d2',                   # post receive key0
    0x495959: 'ff d2',                   # post receive key2
    0x49595B: '89 be 64 bf 00 00',      # BF64 key0
    0x495962: '89 9e 68 bf 00 00',      # BF68 key2
    0x495968: 'b8 01 00 00 00',         # success return
    0x49597B: 'c2 04 00',               # ret 4
    0x495755: '68 df 20 00 00',         # key1 port 0x20DF
    0x495794: '89 b3 60 bf 00 00',      # BF60=key1 Conn*
}
DIRECT_CALLS = {
    0x4957C0: [0x66C1A7, 0x66C247],
    0x495610: [0x6D6377, 0x6D6424, 0x6D6508, 0x6D65C8, 0x6D670C, 0x6D696C],
    0x8060D0: [0x495853, 0x8069EB],
}

def audit(path):
    data = path.read_bytes()
    assert len(data) == 12472320, 'unexpected file size'
    sha = hashlib.sha256(data).hexdigest()
    assert sha == SHA, 'KR version SHA256 mismatch: ' + sha
    assert data[:2] == b'MZ', 'DOS header'
    off = struct.unpack_from('<I', data, 0x3c)[0]
    assert data[off:off+4] == b'PE\x00\x00', 'PE header'
    num = struct.unpack_from('<H', data, off+6)[0]
    opth = off + 24
    assert struct.unpack_from('<I', data, opth+28)[0] == 0x400000, 'image base'
    section_table = opth + struct.unpack_from('<H', data, off+20)[0]
    sections = {}
    for i in range(num):
        k = section_table + i*40
        name = data[k:k+8].split(b'\x00')[0].decode('ascii', 'replace')
        sections[name] = struct.unpack_from('<IIII', data, k+8)
    virtual_size, rva, raw_size, raw_start = sections['.text']
    assert (virtual_size, rva, raw_size, raw_start) == (TEXT_LEN, 0x1000, TEXT_RAW_SIZE, TEXT_RAW)
    buf = data[TEXT_RAW:TEXT_RAW+TEXT_LEN]
    for va, hx in NATIVE.items():
        expect = bytes.fromhex(hx)
        assert buf[va-VA_BASE:va-VA_BASE+len(expect)] == expect, f'bytes differ at {va:#x}'
    calls = {}
    for dst in DIRECT_CALLS:
        found = []
        pos = 0
        while (pos := buf.find(b'\xe8', pos)) != -1:
            if pos+5 <= len(buf):
                target = VA_BASE+pos+5+struct.unpack_from('<i', buf, pos+1)[0]
                if target == dst:
                    found.append(VA_BASE+pos)
            pos += 1
        assert found == DIRECT_CALLS[dst], f'direct CALL sites differ for {dst:#x}: {found}'
        calls[hex(dst)] = [hex(x) for x in found]
    return {'status':'PASS','sha256':sha,'native_instruction_prefixes':len(NATIVE),
            'bounded_direct_call_targets':calls,'text_va':hex(VA_BASE),
            'limits':'E8 raw hit scan requires instruction-boundary review; no runtime/wire proof; no global indirect-call proof.'}

if __name__ == '__main__':
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('bin_path', type=Path)
    args = ap.parse_args()
    print(json.dumps(audit(args.bin_path), ensure_ascii=False, indent=2))
