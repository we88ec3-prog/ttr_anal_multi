"""Read-only identity comparison of selected original windows with specified v2."""
import argparse
import hashlib
import json
from pathlib import Path
import struct


def sha(data):return hashlib.sha256(data).hexdigest()


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--client',type=Path,required=True);p.add_argument('--expected-client-sha',required=True);p.add_argument('--output',type=Path,required=True)
    o=p.parse_args();analysis=Path(__file__).resolve().parents[2];data=o.client.read_bytes();assert sha(data)==o.expected_client_sha.lower()
    assert o.output.resolve()!=o.client.resolve()
    pe=struct.unpack_from('<I',data,60)[0];assert data[pe:pe+4]==b'PE\0\0' and struct.unpack_from('<H',data,pe+4)[0]==0x14c
    opt=pe+24;assert struct.unpack_from('<H',data,opt)[0]==0x10b
    base=struct.unpack_from('<I',data,opt+28)[0];assert base==0x400000
    table=opt+struct.unpack_from('<H',data,pe+20)[0];sections=[struct.unpack_from('<IIII',data,table+i*40+8) for i in range(struct.unpack_from('<H',data,pe+6)[0])]
    source_paths=[
        ('SCENARIO-PRESENTATION-ABANDON-20261124/intro-stop-source.json','a22255bfda0de57dbf2d020e8ff2800e7e10e16af43c8f989e904dae124c6423'),
        ('SCENARIO-PRESENTATION-ABANDON-20261124/town-stop-source.json','ea1c0fcccd2c72b41437dbefb4961a511d6a46b9d4ee4a8f2a19dbe5b433e0c4'),
        ('SCENARIO-PRESENTATION-ABANDON-20261124/native-boundary.json','4374fe061ec096c1801853faa4b453867e88ff2ba20cc36f6b7cb21b2b6071f8'),
        ('SCENARIO-ABANDON-REQUEST-20261124/native-sources.json','750823d6a5a37e0e56cc20c5d6633ee5f7cb4c902a5b4886f50639a779e0eb77')]
    sources=[];selected={}
    for name,digest in source_paths:
        raw=(analysis/'kr-extra-roy'/name).read_bytes();assert sha(raw)==digest;r=json.loads(raw)
        assert r['sourceSha256']=='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
        sources.append(dict(reference=name,sha256=digest))
        for window in r['windows']:
            key=(int(window['start'],16),int(window['stop'],16));expected=window['sha256']
            assert key not in selected or selected[key]==expected;selected[key]=expected
    rows=[]
    for (first,last),expected in sorted(selected.items()):
        n=last-first;offset,=[raw+first-base-rva for _,rva,length,raw in sections if rva<=first-base and first-base+n<=rva+length]
        digest=sha(data[offset:offset+n]);rows.append(dict(start=hex(first),stop=hex(last),bytes=n,candidateRawOffset=hex(offset),originalCodeSha256=expected,candidateCodeSha256=digest,equal=digest==expected))
    assert sha(o.client.read_bytes())==o.expected_client_sha.lower()
    result=dict(schema='SPECIFIED_V2_SELECTED_ABANDON_CODE_COMPARISON_V1',clientFile=o.client.name,clientSha256=sha(data),clientBytes=len(data),
        sourceSha256='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91',sources=sources,windows=rows,
        allSelectedWindowsEqual=all(r['equal'] for r in rows),clientExecuted=False,clientModified=False,originalClientCompatibility='UNKNOWN_RUNTIME',
        limitations=['Only selected constructor/registration/context/Stop/confirmation/sender code windows;not whole executable,assets or runtime acceptance.',
            'Equality preserves the original bounded source conditions;does not prove current Q active,input/UI reachability or native cleanup ACK.'])
    o.output.write_bytes((json.dumps(result,indent=2)+'\n').encode());print('Compared '+str(len(rows))+' selected v2 windows;equal='+str(result['allSelectedWindowsEqual'])+'; '+sha(o.output.read_bytes()))


if __name__=='__main__':main()
