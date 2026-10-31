#!/usr/bin/env python3
"""RR-0006 KR native byte audit + synthetic framing model, no target execution.
Never labels synthetic samples as official wire captures or T01 FULL-PASS.
"""
import argparse, hashlib, json, struct, zlib
from pathlib import Path
EXPECTED_SHA='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
PREFIX={
  0x806a3b:'c7 01 00 10 00 00', # WSARecv WSABUF.len=4096
  0x806e08:'e8 33 0d 00 00',   # IOCP->parser
  0x806e0d:'85 c0 8b 45 e4 74 0f', # return status -> repost/failure
  0x806e6e:'c7 80 b0 a0 00 00 01 00 00 00',
  0x807bb0:'0f b7 33 33 c9 66 3b f1',
  0x807bc3:'66 3b f2 0f 87 51 02 00 00',
  0x807bdd:'c7 44 24 20 04 00 00 00',
  0x807bea:'c7 44 24 18 01 00 00 00',
  0x807bf2:'c7 44 24 20 08 00 00 00',
  0x807c06:'c7 44 24 1c 01 00 00 00',
  0x807c7c:'bf 58 33 fe 00', # pool address
  0x807c81:'e8 2a f9 ff ff', # pool acquired BEFORE bounds
  0x807c93:'3b 7c 24 14', # pointer bounds check
  0x807cc3:'3b ca 0f 83 0b 01 00 00', # end>=RxMax -> bypass recycle
  0x807cd4:'80 f2 7c', # compressed XOR seed
  0x807d0e:'e8 7d f4 f1 ff', # 727190 inflate wrapper
  0x807d16:'85 c0 75 65', # failed inflate -> empty node path
  0x807d35:'34 b6', # obbb checksum XOR seed
  0x807d66:'66 39 4b 04', # compare header checksum
  0x807d83:'83 78 04 00', # node+4 positive dispatch gate
  0x807d90:'e8 7b c5 ff ff', # recycle prework
  0x807d97:'e8 54 f9 ff ff', # pool return
  0x807dad:'e8 ee c2 ff ff', # app enqueue
  0x807db2:'0f b7 13 03 54 24 20', # advance by wire length+header
  0x807dcb:'83 f8 04 0f 83 dc fd ff ff', # next complete frame
  0x807dd6:'8b 7c 24 14', # bypass node+4 decision, orphan only if reached
  0x807e03:'56 53 57 e8 e5 94 08 00', # compact remainder
  0x807e1d:'33 c0', # parser failure
  0x807e53:'81 fe 00 10 00 00', # copy upper cap
  0x8075e3:'74 1f', # allocation null branch
  0x807604:'33 f6', # allocation null: esi=0
  0x80760f:'89 86 08 10 00 00', # deref at +1008 if esi null
  0x8076c7:'ff 47 54', # pool active++
  0x80771d:'ff 4f 54', # pool active--
}
CALLS={0x807b40:[0x806e08],0x8075b0:[0x807c81],0x8076f0:[0x807d97],0x807e50:[0x807d7a]}

def parse_synthetic(stream):
    """An independent mathematical model of E59's branch gates; NOT client execution."""
    consumed=0; result=[]
    while len(stream)-consumed>=4:
        n,marker=struct.unpack_from('<HH',stream,consumed)
        if not 1<=n<=4096: return False,consumed,result,stream[consumed:]
        hdr=8 if marker==0x2633 else 6 if marker==0x0BBB else 4
        if len(stream)-consumed<n+hdr: break
        body=stream[consumed+hdr:consumed+hdr+n]
        payload=None
        if marker in (0x2633,0x0BBB):
            prev=0x7c if marker==0x2633 else 0xb6
            decoded=bytearray()
            for c in body:
                p=c^prev;decoded.append(p);prev=p
            if marker==0x0BBB:
                if sum(decoded)&0xffff == struct.unpack_from('<H',stream,consumed+4)[0]: payload=bytes(decoded)
            else:
                try:
                    p=zlib.decompress(decoded)
                    if 0<len(p)<=4096: payload=p
                except zlib.error: pass
        else: payload=body
        result.append((hex(marker),payload))
        consumed+=n+hdr
    return True,consumed,result,stream[consumed:]

def wrap_synthetic(marker,plaintext,extra=b'\0\0\0\0',checksum_corrupt=False):
    """Artificial test bytes; neither source nor format proof from original Server."""
    if marker==0x2633:
        blob=zlib.compress(plaintext); seed=0x7c; hdr=struct.pack('<HH',len(blob),marker)+extra
    elif marker==0x0BBB:
        blob=plaintext; seed=0xb6; cks=(sum(blob)+(1 if checksum_corrupt else 0))&0xffff
        hdr=struct.pack('<HHH',len(blob),marker,cks)
    else: return struct.pack('<HH',len(plaintext),marker)+plaintext
    previous=seed; ciphertext=bytearray()
    for byte in blob:
        c=byte^previous; ciphertext.append(c);previous=byte
    return hdr+bytes(ciphertext)

def main(path):
    data=Path(path).read_bytes(); sha=hashlib.sha256(data).hexdigest()
    assert sha==EXPECTED_SHA,(sha,'wrong KR binary')
    pe=struct.unpack_from('<I',data,0x3c)[0]
    assert data[:2]==b'MZ' and data[pe:pe+4]==b'PE\x00\x00'
    count=struct.unpack_from('<H',data,pe+6)[0]
    st=pe+24+struct.unpack_from('<H',data,pe+20)[0]
    sections={}
    for i in range(count):
        k=st+40*i
        sections[data[k:k+8].split(b'\x00')[0].decode('ascii')]=struct.unpack_from('<IIII',data,k+8)
    assert sections['.text']==(0x7d01f0,0x1000,0x7d0200,0x400)
    base=0x401000; raw=0x400; code=data[raw:raw+0x7d01f0]
    for va,hexstr in PREFIX.items():
        actual=code[va-base:va-base+len(bytes.fromhex(hexstr))]
        assert actual==bytes.fromhex(hexstr),(hex(va),actual.hex(),hexstr)
    for dst,expected in CALLS.items():
        found=[]
        for i in range(len(code)-4):
            if code[i]==0xe8 and base+i+5+struct.unpack_from('<i',code,i+1)[0]==dst:
                found.append(base+i)
        assert found==expected,(hex(dst),[hex(x) for x in found])
    tests=0
    def check(condition):
        nonlocal tests
        tests+=1;assert condition
    plain=b'\x13\x00\x01\x02'
    a=wrap_synthetic(0x2633,plain)
    b=wrap_synthetic(0x2633,plain,extra=b'\xff\xde\xad\xbe')
    check(parse_synthetic(a)[2][0][1]==plain)
    check(parse_synthetic(b)[2][0][1]==plain)
    check(parse_synthetic(wrap_synthetic(0x0bbb,plain))[2][0][1]==plain)
    check(parse_synthetic(wrap_synthetic(0x0bbb,plain,checksum_corrupt=True))[2][0][1] is None)
    check(parse_synthetic(wrap_synthetic(0x22d7,plain))[2][0][1]==plain)
    check(parse_synthetic(wrap_synthetic(0x9999,plain))[2][0][1]==plain)
    check(parse_synthetic(a[:3])[2]==[])
    check(parse_synthetic(a[:-1])[2]==[])
    check(parse_synthetic(a+wrap_synthetic(0x22d7,plain))[2]==[(hex(0x2633),plain),(hex(0x22d7),plain)])
    check(parse_synthetic(wrap_synthetic(0x0bbb,plain,True) if False else wrap_synthetic(0x0bbb,plain,checksum_corrupt=True)+wrap_synthetic(0x22d7,plain))[2]==[(hex(0x0bbb),None),(hex(0x22d7),plain)])
    check(parse_synthetic(b'\x00\x00\xd7\x22')[0] is False)
    check(parse_synthetic(b'\x01\x10\xd7\x22')[0] is False)
    check(parse_synthetic(wrap_synthetic(0x22d7,plain) + b'\x02')[3]==b'\x02')
    # Cumulative upper bound on normal partial frame: max residual 4096+8-1=4103,
    # next WSARecv maximum=4096, combined=8199 < allocated Rx 0x5000.
    check((4096+8-1)+4096==8199)
    check(8199<0x5000)
    # parser's strict comparison fails if end pointer equals 0x5000 exactly;
    # that cannot occur from the above well-formed single-post invariant.
    check(0x5000 not in range(0,8200))
    print(json.dumps({'result':'PASS','sha256':sha,'native_prefix_checks':len(PREFIX),'direct_call_targets':{hex(k):[hex(v) for v in vs] for k,vs in CALLS.items()},'synthetic_checks':tests,'scope':'native structural guards + independent math; NOT client runtime or original Server pcap'},ensure_ascii=False,indent=2))

if __name__=='__main__':
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('original_bin');args=ap.parse_args();main(args.original_bin)
