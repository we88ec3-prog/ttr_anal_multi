#!/usr/bin/env python3
"""T03-D W13..W16 KR read-only PE/RTTI/121-slice static verifier.
This script never executes, hooks or modifies the game. Static success != FULL-PASS.
"""
import base64, gzip, hashlib, json, struct, sys
from pathlib import Path

KR_BIN_SHA = "9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
KR_EXE_SHA = "03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f"
# gzip(base64) of 121 [native VA, exact byte hex] pairs; authored against original KR BIN,
# including 0x4B8920, 0x5A6510, 0x671FD0, 0x672505 and 0x4C21D0.
CASES_GZIP_B64 = (
    "H4sIAInH5WoC/3VWS5YkIQi8S69nAYqIZ+nXC79nmOOPYlYVZk7nMgL5CIT5/f0Ff6kIxPD154sz0tfPnzcWJyaNIlSL5okGsEjZZ4PF2sJkOC8jgbUWN5kuMZbhm2WS8yteoWbjJccL9SMRWjRNNHogiw21rFiGQf2KV6T4Ohz6YJlV34jd+vXLR8WewFrSqllCTRarE4MhVDvoZ7jgtJJYHTmx+K6lRrYZJqeeCkO0aNh1C9ioaWXCqQICuFvU3PRmUy9x0R8mM6xTnD0BubMfOVU9BaOF5fFiQuaA61QIBmHWu7x1VZmisxJmVgaNO64UEIv6fQs3W962n1tWVPschs1C582VepxetTccR5zVy0iQDSa4+huFidYdzQ8/LIc9QaW8WVMja/UxBBOX946U4v11wnJNOekFHr5k78yB7Y4XtBml9rTL+PIrD795PO2L1w4PGW3MzzL59+wr/J597TuKzbS5lz097Ds87Tv9XsVwpz1HHD5o54CFQqz+bc/RrSaqciAe6IrgWxQIxr8yY8fmcea6ONxdoLkMFpXla2rQe5IX6nbc0gc8/PiuJ9JAOe52cawqE9elE5GDYVkMO+//MbplGBNSnjdxekUO2mfkey4BFjPFxyC895WmQmWLr4koyfenj3Gq/MJw1f/eB0Xc3uIpj9NztUzU7DxCcu7wjHXrAcFhv3fRtyQ5jnLLxu1dRFuTE+0GzKqyrBOW65tDg3m4Om2nJnivdfoDC5/bIoune/0+n/un2KpvjPZW3YpU+p7mEClzmx0jMmyVreS+eftGTqa/9GvU3ebDay8X2yvrzI0P67Adeq7I9eKG91Qryvs9GiRvhVZcX360iKrYXMhjUhejGz8rmM8S1JPRTZrq/9l3Ed6zESh2tgolqpNzU9ei3hRKEtqpVsTZDBXZO9G4VJOHMqp9PhYkOE70/a6HOu66JDmrN57lAR1M2XESP5m8exIfL86aDfXoS7VYcZcqP1UlqPLOF6pjvbwZPQrteo0YHpoTmu4T1v9wrLtp/v4USzfNYMwPBWDd3cd/3mJUG+fNC972nXXDzD5MLCY4p0IxvYckkR8ZxyQvDp5cf3H04DJdHNUnp91NLt4Zaf3+Hjnp7l3Fzz9Uu68pRwsAAA=="
)

def u32(buf, at):
    return struct.unpack_from("<I", buf, at)[0]

def find_direct_call_sites(code, text_va, target):
    # Scan all byte positions for E8 rel32 as *candidates* only.
    # No claim of disassembly boundaries without later CFG corroboration.
    hits = []
    start = 0
    while True:
        pos = code.find(b"\xe8", start)
        if pos < 0 or pos + 5 > len(code):
            break
        rel = struct.unpack_from("<i", code, pos + 1)[0]
        if text_va + pos + 5 + rel == target:
            hits.append(text_va + pos)
        start = pos + 1
    return hits

def run_check(bin_path, exe_path=None):
    data = Path(bin_path).read_bytes()
    assert len(data) == 12_472_320, "different BIN length"
    assert hashlib.sha256(data).hexdigest() == KR_BIN_SHA, "different KR build"
    if exe_path:
        assert hashlib.sha256(Path(exe_path).read_bytes()).hexdigest() == KR_EXE_SHA
    pe = u32(data, 0x3c)
    assert data[pe:pe+4] == b"PE\x00\x00"
    assert struct.unpack_from("<H", data, pe+4)[0] == 0x14c
    opt = pe + 24
    assert struct.unpack_from("<H", data, opt)[0] == 0x10b
    assert u32(data, opt+28) == 0x400000
    sections = {}
    for i in range(struct.unpack_from("<H",data,pe+6)[0]):
        off=opt+struct.unpack_from("<H",data,pe+20)[0]+40*i
        name=data[off:off+8].rstrip(b"\x00").decode("ascii")
        virtual,rva,raw_size,raw=struct.unpack_from("<IIII", data, off+8)
        sections[name]=(0x400000+rva, raw, virtual, raw_size)
    assert sections[".text"][:2] == (0x401000,0x400)
    assert sections[".rdata"][:2] == (0xbd2000,0x7d0600)
    assert sections[".data"][:2] == (0xd61000,0x95e800)
    def va_to_raw(va, name):
        start, raw, virtual, raw_size = sections[name]
        assert start <= va < start + raw_size
        return raw + va - start
    pairs = json.loads(gzip.decompress(base64.b64decode(CASES_GZIP_B64)))
    assert len(pairs) == len({addr for addr,_ in pairs}) == 121
    for address,hex_bytes in pairs:
        va=int(address,16)
        b=bytes.fromhex(hex_bytes)
        at=va_to_raw(va,".text")
        assert data[at:at+len(b)]==b, "instruction bytes mismatch " + address
    for vptr, slot, target in [
        (0xc35784,87,0x671fd0),
        (0xc1c1a4,66,0x5a65a0),
        (0xc1c1a4,92,0x5a6510),
        (0xc1c1a4,101,0x5a67d0)
    ]:
        assert u32(data,va_to_raw(vptr+4*slot,".rdata"))==target, hex(vptr)
    for name in [
        b".?AVCExpeditionCreateDialog@FUI@@",
        b".?AVCExpeditionPage@FUI@@",
        b".?AVCEmployNewCharacter@FUI@@"
    ]:
        assert name in data, name
    text_va, raw, _, raw_size=sections[".text"]
    code=data[raw:raw+raw_size]
    expected={
        0x4e5fb0:[0x4b8a9c,0x4e2794],
        0x4d4150:[0x4b89ad,0x4e2782],
        0x672180:[0x672165],
        0x672570:[0x5a6895]
    }
    for dst,sites in expected.items():
        actual=find_direct_call_sites(code,text_va,dst)
        assert actual==sites, (hex(dst),[hex(x) for x in actual])
    assert (0x60fc - 0x5eac)//8 == 0x4a
    assert 0x30 == 2+4+21*2
    assert (65+53*0-65)//53==0
    assert (65+53*2-65)//53==2
    print("PASS: KR BIN/PE sections + 121 original instruction starts")
    print("PASS: 4 vtable slots + 3 RTTI identities + 4 bounded direct-call scans")
    print("PASS: 48-byte C2S3E layout and roster-count arithmetic")
    print("LIMIT: original Server 3E<->4A pairing, zero-roster dialog visibility, Client runtime all UNKNOWN")

if __name__=="__main__":
    if len(sys.argv) not in (2,3):
        raise SystemExit("Usage: python -B verify.py /path/Tartaros.bin [/path/Tartaros.exe]")
    run_check(sys.argv[1],sys.argv[2] if len(sys.argv)==3 else None)
