#!/usr/bin/env python3
"""Independent T01 decoding of bounded high-risk contracts, not game execution."""
import hashlib
import json
from pathlib import Path
import re
import struct
import subprocess

ROOT=Path(__file__).resolve().parent
BIN=Path('/workspace/scratch/d850068ce350/project_sources/02-Tartaros.bin')
EXPECTED='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
data=BIN.read_bytes()
assert hashlib.sha256(data).hexdigest()==EXPECTED
pe=struct.unpack_from('<I',data,0x3c)[0]
assert data[:2]==b'MZ' and data[pe:pe+4]==b'PE\0\0'
assert struct.unpack_from('<H',data,pe+4)[0]==0x14c
opt=pe+24
assert struct.unpack_from('<H',data,opt)[0]==0x10b
base=struct.unpack_from('<I',data,opt+28)[0]
assert base==0x400000
table=opt+struct.unpack_from('<H',data,pe+20)[0]
sections=[]
for n in range(struct.unpack_from('<H',data,pe+6)[0]):
    p=table+n*40
    virtual_size,rva,raw_size,raw=struct.unpack_from('<IIII',data,p+8)
    sections.append(dict(name=data[p:p+8].rstrip(b'\0').decode(),va=base+rva,
                         virtual_size=virtual_size,raw_size=raw_size,raw=raw))
def raw(va,n):
    found=[s['raw']+va-s['va'] for s in sections if s['va']<=va and va+n<=s['va']+s['raw_size']]
    assert len(found)==1
    return found[0]
def at(va,n):
    offset=raw(va,n)
    return data[offset:offset+n]

windows=[
    ('point_delta',0x4b32e0,0x4b3347),
    ('point_first_match',0x544940,0x54499f),
    ('point_native_setter',0x4a9460,0x4a94c0),
    ('point_status',0x543b30,0x54401f),
    ('point_candidate',0x544730,0x5447ef),
    ('point_nearest_dispatch',0x544a00,0x544b60),
    ('report_003f',0x4a39a0,0x4a39ec),
    ('q_start_and_skip',0x561760,0x561db0),
    ('q_end',0x561db0,0x5620aa),
    ('wait_unlock',0x562250,0x56231e),
    ('packet_00eb',0x4b6190,0x4b61fd),
]
summary=[];blocks=[];starts={}
for name,a,z in windows:
    cmd=['objdump','-D','-Mintel','--insn-width=16','--start-address='+hex(a),
         '--stop-address='+hex(z+15),str(BIN)]
    output=subprocess.check_output(cmd,text=True)
    cursor=a;rows=[]
    for line in output.splitlines():
        match=re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*(.*)',line)
        if not match:continue
        va=int(match[1],16)
        if not a<=va<z:continue
        b=bytes.fromhex(match[2]);asm=match[3].strip()
        assert va==cursor and b==at(va,len(b)) and '(bad)' not in asm and '.byte' not in asm
        cursor+=len(b);rows.append((va,b.hex(),asm))
        if va in starts:assert starts[va]==(b.hex(),asm)
        starts[va]=(b.hex(),asm)
    assert cursor==z
    summary.append(dict(id=name,va=hex(a),end_exclusive=hex(z),raw=hex(raw(a,z-a)),
                        bytes=z-a,sha256=hashlib.sha256(at(a,z-a)).hexdigest(),
                        decoded_instructions=len(rows)))
    blocks.append('; '+name+' '+hex(a)+'..'+hex(z)+'\n'+
                  '\n'.join(f'{va:08X}  {b:<32} {asm}' for va,b,asm in rows))

# These concrete operands and CFG destinations are the bounded claim anchors.
anchors={
 0x4b3327:'0fb64805', 0x4b332b:'0fb65004', 0x4b332f:'0fb74002',
 0x54496f:'660fbe5d0c', 0x54497b:'740f', 0x54498f:'8a4d10',
 0x543b77:'888b05010000', 0x544739:'80b90501000000',
 0x54479a:'83b90001000000', 0x5447a3:'837d1000',
 0x5447bc:'c6810401000001', 0x5447e0:'c6810401000000',
 0x4a39b5:'b83f000000', 0x4a39be:'b801000000', 0x4a39dc:'6a08',
 0x5618d2:'e9af040000', 0x562307:'83253088fb00fd',
}
anchor_rows=[]
for va,h in anchors.items():
    assert va in starts and starts[va][0]==h
    anchor_rows.append(dict(va=hex(va),hex=h,asm=starts[va][1]))
calls=[(0x4b333b,0x544940),(0x4a94b6,0x544940),(0x544993,0x543b30),
       (0x5618c8,0x4a39a0),(0x5618cd,0x5620b0),(0x561fb0,0x4a39a0),
       (0x561fe0,0x4a39a0),(0x561fe5,0x5620b0),(0x4b61e5,0x562250)]
for site,target in calls:
    assert site in starts and at(site,1)==b'\xe8'
    assert site+5+struct.unpack('<i',at(site+1,4))[0]==target
result=dict(status='PASS_BOUNDED_INDEPENDENT_DECODE',target_sha256=EXPECTED,
            pe_sections=sections,windows=summary,anchors=anchor_rows,
            direct_calls=[dict(site=hex(a),target=hex(b)) for a,b in calls],
            semantic_status='PARTIAL_NOT_FULL_PASS',client_executed=False,
            lua_executed=False,server_executed=False,
            limitation='Concrete selected instructions and bounded control/dataflow only; excludes complete packet/frontend graph, caller aliases and gameplay.')
(ROOT/'independent-native.asm').write_text('\n\n'.join(blocks)+'\n')
(ROOT/'independent-native.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n')
print(json.dumps(dict(status=result['status'],windows=len(summary),anchors=len(anchors),
                     direct_calls=len(calls),decoded_instructions=sum(r['decoded_instructions'] for r in summary)),indent=2))
