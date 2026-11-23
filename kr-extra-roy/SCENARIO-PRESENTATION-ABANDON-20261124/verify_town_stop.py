"""Original Scenario inheritance/0038 Town preload Stop proof;no target execution."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import sys


SHA='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
def sha(data):return hashlib.sha256(data).hexdigest()


def main():
    p=argparse.ArgumentParser(description=__doc__)
    for name in ['bin','bulk-directory','capstone-directory','output']:p.add_argument('--'+name,type=Path,required=True)
    o=p.parse_args();analysis=Path(__file__).resolve().parents[2];data=o.bin.read_bytes();assert sha(data)==SHA
    pe=struct.unpack_from('<I',data,60)[0];assert data[pe:pe+4]==b'PE\0\0' and struct.unpack_from('<H',data,pe+4)[0]==0x14c
    opt=pe+24;assert struct.unpack_from('<H',data,opt)[0]==0x10b
    base=struct.unpack_from('<I',data,opt+28)[0];table=opt+struct.unpack_from('<H',data,pe+20)[0]
    sections=[struct.unpack_from('<IIII',data,table+i*40+8) for i in range(struct.unpack_from('<H',data,pe+6)[0])]
    def raw(va,size):
        matches=[r+va-base-v for _,v,l,r in sections if v<=va-base and va-base+size<=v+l]
        assert len(matches)==1;return matches[0]
    saved=analysis/'kr-extra-roy/MEF-complete-flow-20261115/scene-cancellation/native-windows.json';prior=json.loads(saved.read_bytes());assert prior['target_sha256']==SHA
    inherited=[next(w for w in prior['windows'] if w['id'].startswith(prefix)) for prefix in ['N04_','N05_']]
    sys.path.insert(0,str(o.capstone_directory.resolve()));import capstone
    assert capstone.__version__=='5.0.6';decoder=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
    windows=[];decoded={}
    ranges=[(w['id'],int(w['va'],16),int(w['end_exclusive'],16),w['sha256']) for w in inherited]
    ranges.append(('existing_0038_handler',0x4b1bf0,0x4b218c,None))
    for name,first,last,expected in ranges:
        offset=raw(first,last-first);code=data[offset:offset+last-first]
        if expected is not None:assert sha(code)==expected
        instructions=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str) for i in decoder.disasm(code,first)]
        assert sum(len(bytes.fromhex(i['bytes'])) for i in instructions)==len(code)
        decoded.update({int(i['address'],16):i for i in instructions});windows.append(dict(id=name,start=hex(first),stop=hex(last),rawOffset=hex(offset),sha256=sha(code),instructions=instructions))
    anchors={0x4adf2d:('mov','dword ptr [eax + 0x1c4], 0x4b1bf0'),
        0x4c46f2:('call','0x4add50'),0x4c4705:('mov','dword ptr [esi], 0xc073b4'),
        0x4b1d07:('push','0'),0x4b1d09:('mov','ecx, 0xfb73c0'),0x4b1d0e:('call','0x5624b0'),
        0x4b1d13:('movzx','eax, byte ptr [ebx + 2]'),0x4b1d1a:('je','0x4b1deb'),
        0x4b1e09:('call','0x552fc0'),0x4b2050:('movzx','ecx, word ptr [ebx + 3]'),
        0x4b2054:('push','ecx'),0x4b205a:('call','0x540a40')}
    for va,pair in anchors.items():assert (decoded[va]['mnemonic'],decoded[va]['operands'])==pair,(hex(va),decoded[va])
    assert 0x38*8+4==0x1c4
    # Scenario's local callback initialization begins beyond the inherited table.
    ctor=[i for va,i in decoded.items() if 0x4c46f0<=va<0x4c4750]
    assert any(i['mnemonic']=='lea' and '0x5eac' in i['operands'] for i in ctor)
    addresses={'0x4add50','0x4c46f0','0x4b1bf0'};rows={}
    for line in (o.bulk_directory/SHA/'index.jsonl').read_text(encoding='utf-8').splitlines():
        r=json.loads(line)
        if r.get('address') in addresses and r.get('status')=='ok':rows[r['address']]=r
    sources=[]
    for address in sorted(addresses):
        r=rows[address];assert r['source_sha256']==SHA
        assert sha((o.bulk_directory/SHA/r['pseudocode_path']).read_bytes())==r['pseudocode_sha256']
        evidence=o.bulk_directory/SHA/r['batch_path'];assert sha(evidence.read_bytes())==r['batch_sha256']
        sources.append(dict(address=address,pseudocodeSha256=r['pseudocode_sha256'],evidenceSha256=r['batch_sha256'],evidenceId=json.loads(evidence.read_bytes())['evidence_id'],review='ARCHIVED_REA_GHIDRA_BOUNDED_REUSE'))
    assert sha(o.bin.read_bytes())==SHA
    result=dict(schema='SCENARIO_INHERITED_TOWN_CONTEXT_STOP_SOURCE_V1',sourceSha256=SHA,sourceUnchanged=True,
        priorSceneConstructorWindowsSha256=sha(saved.read_bytes()),archivedSources=sources,windows=windows,
        capstoneVersion=capstone.__version__,capstoneDllSha256=sha((o.capstone_directory/'capstone/lib/capstone.dll').read_bytes()),
        packet=dict(command=56,subtype=0,bytes=9,townOffset=3,exampleTown1='380000010000000000'),
        contract=dict(inheritedByScenario=True,activeQStopBeforeSubtypePreload=True,stopOnlyPacket=False,
            candidateOrder=['existing Town0038 on current ready Scenario','existing69/7 Town handoff','existing43 loading confirmation','remaining Town snapshot without duplicate0038']),
        clientExecuted=False,clientModified=False,newGhidraImport=False,fullFunctionReview=False,
        limitations=['Selected normal ready Scenario only;Town0038 also mutates context/preloads,not a generic Stop-only opcode.',
            'Packet ordering is a Server reconstruction choice;humanv2 rendering/input/native coroutine acceptance remains pending.',
            'No new selector,resource,wire generation or cancelACK;Intro/ReturnScene/Q15 presentations are separate.'])
    o.output.write_bytes((json.dumps(result,indent=2)+'\n').encode());print('PASS inherited Scenario Town0038 Stop '+sha(o.output.read_bytes()))


if __name__=='__main__':main()
