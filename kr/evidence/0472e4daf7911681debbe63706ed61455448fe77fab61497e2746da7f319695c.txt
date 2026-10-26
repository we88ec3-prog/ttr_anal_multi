"""Independent byte binding for fresh framing review; no target code execution."""
import hashlib,json,platform,struct
from pathlib import Path
BASE=Path(__file__).resolve().parent
raw=(BASE.parents[2]/'Tartaros.bin').read_bytes()
source_sha=hashlib.sha256(raw).hexdigest()
assert source_sha=='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
pe=struct.unpack_from('<I',raw,0x3c)[0]
n=struct.unpack_from('<H',raw,pe+6)[0];opt=struct.unpack_from('<H',raw,pe+20)[0]
base=struct.unpack_from('<I',raw,pe+52)[0]
sections=[struct.unpack_from('<IIII',raw,pe+24+opt+i*40+8) for i in range(n)]
def at(va,size):
    rva=va-base
    matches=[off+rva-r for vs,r,rs,off in sections if r<=rva and rva+size<=r+rs]
    assert len(matches)==1
    off=matches[0];return off,raw[off:off+size]
checks=[(0x807a87,'8d5a04'),(0x807a8a,'b8681a0000'),(0x807a97,'81fb00100000'),
        (0x80786d,'8d4706'),(0x807887,'3d00100000'),(0x807901,'80f2b6'),
        (0x807a37,'b801000000'),(0x807b0d,'b801000000')]
results=[]
for va,expected in checks:
    off,b=at(va,len(bytes.fromhex(expected)))
    results.append(dict(va=hex(va),file_offset=off,expected=expected,actual=b.hex(),ok=b.hex()==expected))
records=[]
for va in ['807a70','807830','807b40','8061a0','806ad0']:
    p=BASE/f'evidence/native-{va}.json';d=json.loads(p.read_text(encoding='utf-8'))
    assert d['provider']['version']=='12.1.4'
    assert d['analysis_profile']['digest']=='3c06738e45e144d5f073edbd3244c6bff46222f389525fe659bc92dca2ccdece'
    assert d['normalized_result']['procedure']['address']=='0x'+va
    # Full subject identity is carried verbatim; no runtime authority inferred.
    assert source_sha in json.dumps(d['subject'])
    ranges=[]
    for r in d['normalized_result']['procedure']['body']['ranges']:
        start=int(r['start'],16);end=int(r['end'],16)
        off,b=at(start,end-start+1)
        ranges.append(dict(start=r['start'],end_inclusive=r['end'],file_offset=off,sha256=hashlib.sha256(b).hexdigest()))
    records.append(dict(file=p.relative_to(BASE).as_posix(),sha256=hashlib.sha256(p.read_bytes()).hexdigest(),
                        evidence_id=d['evidence_id'],body=d['normalized_result']['procedure']['body'],source_ranges=ranges,
                        limits=d['limitations'],subject=d['subject']))
out=dict(status='待整合',tool='Python '+platform.python_version(),source_sha256=source_sha,
         checks=results,all_ok=all(r['ok'] for r in results),native_records=records,
         limits=['Byte identity and matching provider-specific dossiers; no target execution',
                 'No claim that complete body ranges establish semantic completion',
                 '807830 decompiler void prototype disagrees with explicit EAX return instructions'])
(BASE/'evidence/native-contract-checks.json').write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
print(json.dumps({'all_ok':out['all_ok'],'checks':len(results),'records':len(records)}))
