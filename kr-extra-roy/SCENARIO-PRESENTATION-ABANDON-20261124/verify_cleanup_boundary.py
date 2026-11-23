"""Verify the existing abandon branch and distinct active-Q Stop boundary offline."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import sys


SHA='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
def sha(data):return hashlib.sha256(data).hexdigest()
def read(path):return json.loads(path.read_bytes())


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    for name in ['bin','bulk-directory','capstone-directory','output']:parser.add_argument('--'+name,type=Path,required=True)
    o=parser.parse_args();analysis=Path(__file__).resolve().parents[2]
    original=o.bin.read_bytes();assert sha(original)==SHA
    pe=struct.unpack_from('<I',original,60)[0];assert original[pe:pe+4]==b'PE\0\0' and struct.unpack_from('<H',original,pe+4)[0]==0x14c
    optional=pe+24;assert struct.unpack_from('<H',original,optional)[0]==0x10b
    base=struct.unpack_from('<I',original,optional+28)[0];table=optional+struct.unpack_from('<H',original,pe+20)[0]
    sections=[struct.unpack_from('<IIII',original,table+i*40+8) for i in range(struct.unpack_from('<H',original,pe+6)[0])]
    def offset(va,size):
        matches=[raw+va-base-rva for _,rva,length,raw in sections if rva<=va-base and va-base+size<=rva+length]
        assert len(matches)==1;return matches[0]
    abandon=analysis/'kr-extra-roy/SCENARIO-ABANDON-REQUEST-20261124/native-sources.json'
    assert sha(abandon.read_bytes())=='750823d6a5a37e0e56cc20c5d6633ee5f7cb4c902a5b4886f50639a779e0eb77'
    prior=read(abandon);assert prior['sourceSha256']==SHA
    saved=analysis/'kr-extra-roy/MEF-control-flow-20261116/presentation/native-windows.json'
    presentation=read(saved);assert presentation['binary']['sha256']==SHA
    stop=next(v for v in presentation['records'] if v['id']=='q_stop')
    branch=next(v for v in prior['windows'] if v['start']=='0x5978d0')
    sys.path.insert(0,str(o.capstone_directory.resolve()));import capstone
    assert capstone.__version__=='5.0.6'
    decoder=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
    windows=[];decoded={}
    for name,first,last,expected in [('abandon_confirmation',0x5978d0,0x597a22,branch['sha256']),
        ('active_q_stop',int(stop['va'],16),int(stop['end'],16),stop['sha256'])]:
        raw=offset(first,last-first);code=original[raw:raw+last-first];assert sha(code)==expected
        instructions=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str) for i in decoder.disasm(code,first)]
        assert sum(len(bytes.fromhex(i['bytes'])) for i in instructions)==len(code)
        decoded.update({int(i['address'],16):i for i in instructions})
        windows.append(dict(id=name,start=hex(first),stop=hex(last),rawOffset=hex(raw),sha256=expected,instructions=instructions))
    expected={0x597942:('mov','esi, 1'),0x597947:('sub','eax, esi'),0x597949:('je','0x5979bd'),
        0x59794b:('sub','eax, esi'),0x59794d:('je','0x59798c'),0x597965:('call','0x5624b0'),
        0x59796c:('push','0x10'),0x597974:('call','dword ptr [0xbd244c]'),
        0x59798c:('call','0x41a4d0'),0x597991:('cmp','dword ptr [eax + 0x5ed8], ebx'),
        0x597997:('je','0x597a10'),0x59799e:('cmp','dword ptr [eax + 0x5ed8], ebx'),
        0x5979a6:('call','0x53ba20'),0x5979ba:('ret','4'),
        0x5624e7:('xor','esi, esi'),0x56251e:('cmp','dword ptr [edi + 0x28], esi'),
        0x562521:('je','0x562891'),0x56268b:('call','0x563fa0'),
        0x562694:('call','0x563a70'),0x56269d:('call','0x562b00'),0x56288c:('call','0x561db0')}
    for va,(mnemonic,operands) in expected.items():assert (decoded[va]['mnemonic'],decoded[va]['operands'])==(mnemonic,operands),(hex(va),decoded[va])
    # Only the selected local kind2 branch, not transitive unknown callbacks.
    calls=[i['operands'] for va,i in decoded.items() if 0x59798c<=va<0x5979bd and i['mnemonic']=='call']
    assert calls==['0x41a4d0','0x41a4d0','0x53ba20']
    # Resolve the sibling branch's imported target from the PE import table.
    # A Stop before posting WM_CLOSE is not the kind2 abandon path.
    imports=struct.unpack_from('<I',original,optional+104)[0];names={};descriptor=offset(base+imports,20)
    while True:
        lookup,stamp,forwarder,dll,iat=struct.unpack_from('<IIIII',original,descriptor)
        if not any([lookup,stamp,forwarder,dll,iat]):break
        index=0
        while True:
            entry=struct.unpack_from('<I',original,offset(base+(lookup or iat)+index*4,4))[0]
            if entry==0:break
            if not entry&0x80000000:
                start=offset(base+entry+2,1);name=original[start:original.index(b'\0',start)].decode('ascii')
                names[base+iat+index*4]=name
            index+=1
        descriptor+=20
    assert names[0xbd244c]=='PostMessageW'
    addresses={'0x5978d0','0x5624b0','0x561db0','0x53ba20','0x4bca90'};rows={}
    for line in (o.bulk_directory/SHA/'index.jsonl').read_text(encoding='utf-8').splitlines():
        r=json.loads(line)
        if r.get('address') in addresses and r.get('status')=='ok':rows[r['address']]=r
    sources=[]
    for address in sorted(addresses):
        r=rows[address];assert r['source_sha256']==SHA
        assert sha((o.bulk_directory/SHA/r['pseudocode_path']).read_bytes())==r['pseudocode_sha256']
        raw=o.bulk_directory/SHA/r['batch_path'];assert sha(raw.read_bytes())==r['batch_sha256']
        sources.append(dict(address=address,pseudocodeSha256=r['pseudocode_sha256'],evidenceSha256=r['batch_sha256'],evidenceId=read(raw)['evidence_id'],review='ARCHIVED_GHIDRA_BOUNDED_REUSE_NOT_FULL_FUNCTION_REVIEW'))
    assert sha(o.bin.read_bytes())==SHA
    result=dict(schema='SCENARIO_PRESENTATION_ABANDON_CLEANUP_BOUNDARY_V1',sourceSha256=SHA,sourceUnchanged=True,
        priorAbandonEvidenceSha256=sha(abandon.read_bytes()),priorPresentationWindowsSha256=sha(saved.read_bytes()),
        capstoneVersion=capstone.__version__,capstoneDllSha256=sha((o.capstone_directory/'capstone/lib/capstone.dll').read_bytes()),
        archivedSources=sources,windows=windows,kind2LocalDirectCalls=calls,
        siblingBranchImport=dict(iat='0xbd244c',name=names[0xbd244c],message=16),
        conclusions=dict(kind2SkipsSiblingStopCall=True,stopRequiresActiveQForMainCleanup=True,stopBulkCleanupPrecedesEnd=True),
        clientExecuted=False,clientModified=False,newGhidraImport=False,fullFunctionReview=False,
        limitations=['Direct kind2 branch only;no global absence claim over all indirect callbacks or runtime input reachability.',
            'Existing Mission0031 Stop handler is not proof of Scenario handler registration or an authorized new cancellation packet.',
            'Current scene cleanup/field dispatch and legal selected Stop sequence remain integration requirements.',
            'End/003F/input unlock/map replacement are separate;no cleanup ACK is invented.'])
    o.output.write_bytes((json.dumps(result,indent=2)+'\n').encode())
    print('PASS bounded kind2/Stop cleanup boundary '+sha(o.output.read_bytes()))


if __name__=='__main__':main()
