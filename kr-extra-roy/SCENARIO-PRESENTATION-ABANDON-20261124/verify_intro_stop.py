"""Bound the normal Town CSquare inheritance of the already verified0038 Stop."""
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
        rows=[r+va-base-v for _,v,l,r in sections if v<=va-base and va-base+size<=v+l]
        assert len(rows)==1;return rows[0]
    prior=analysis/'kr-extra-roy/SCENARIO-PRESENTATION-ABANDON-20261124/town-stop-source.json'
    assert sha(prior.read_bytes())=='ea1c0fcccd2c72b41437dbefb4961a511d6a46b9d4ee4a8f2a19dbe5b433e0c4'
    inherited=json.loads(prior.read_bytes());assert inherited['sourceSha256']==SHA and inherited['contract']['activeQStopBeforeSubtypePreload']
    sys.path.insert(0,str(o.capstone_directory.resolve()));import capstone
    assert capstone.__version__=='5.0.6';decoder=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
    windows=[]
    for first in [0x4bbb70,0x4bbba0]:
        offset=raw(first,512);instructions=[]
        for i in decoder.disasm(data[offset:offset+512],first):
            instructions.append(dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str))
            if i.mnemonic=='ret':break
        assert instructions[-1]['mnemonic']=='ret'
        # These selected straight-line constructor/reset prefixes have no
        # conditional/tail branches;no function-wide review is promoted.
        assert not any(i['mnemonic'].startswith('j') for i in instructions)
        size=sum(len(bytes.fromhex(i['bytes'])) for i in instructions)
        windows.append(dict(start=hex(first),stop=hex(first+size),rawOffset=hex(offset),sha256=sha(data[offset:offset+size]),instructions=instructions))
    ctor=windows[0]['instructions'];reset=windows[1]['instructions']
    assert [i['operands'] for i in ctor if i['mnemonic']=='call']==['0x4add50','0x4bbba0']
    assert any(i['mnemonic']=='mov' and i['operands'].endswith(', 0xc06fb0') for i in ctor)
    assert any(i['mnemonic']=='lea' and '0x5eac' in i['operands'] for i in reset)
    assert any(i['mnemonic']=='push' and i['operands']=='0x5ea8' for i in reset)
    stores=[i for i in reset if i['mnemonic']=='mov' and i['operands'].startswith('dword ptr [')]
    assert len(stores)==10 and all('[esi + 0x' in i['operands'] for i in stores)
    offsets=[int(i['operands'].split('[esi + 0x')[1].split(']')[0],16) for i in stores]
    assert all(v>=0x5eac for v in offsets) and 0x38*8+4==0x1c4<0x5eac
    rows={};addresses={'0x4bbb70','0x4bbba0'}
    for line in (o.bulk_directory/SHA/'index.jsonl').read_text(encoding='utf-8').splitlines():
        r=json.loads(line)
        if r.get('address') in addresses and r.get('status')=='ok':rows[r['address']]=r
    sources=[]
    for address in sorted(addresses):
        r=rows[address];assert r['source_sha256']==SHA
        assert sha((o.bulk_directory/SHA/r['pseudocode_path']).read_bytes())==r['pseudocode_sha256']
        source=o.bulk_directory/SHA/r['batch_path'];assert sha(source.read_bytes())==r['batch_sha256']
        sources.append(dict(address=address,pseudocodeSha256=r['pseudocode_sha256'],evidenceSha256=r['batch_sha256'],evidenceId=json.loads(source.read_bytes())['evidence_id'],review='ARCHIVED_GHIDRA_BOUNDED_REUSE'))
    assert sha(o.bin.read_bytes())==SHA
    result=dict(schema='TOWN_CSQUARE_INTRO_STOP_INHERITANCE_V1',sourceSha256=SHA,sourceUnchanged=True,
        priorTownStopSourceSha256=sha(prior.read_bytes()),windows=windows,archivedSources=sources,
        csquareVtable='0xc06fb0',inherited0038Slot='0x1c4',localResetStart='0x5eac',localResetBytes='0x5ea8',localCallbackStoreOffsets=[hex(v) for v in offsets],
        capstoneVersion=capstone.__version__,capstoneDllSha256=sha((o.capstone_directory/'capstone/lib/capstone.dll').read_bytes()),
        clientExecuted=False,clientModified=False,fullFunctionReview=False,newGhidraImport=False,
        limitations=['Normal already-loaded Town uses existing69/7 CSquare bootstrap;this does not prove all modes or actualv2 input reachability.',
            'Reuse prior inherited0038 active-Q Stop/Town preload contract;not a new Stop-only packet.',
            'Server Intro phase is not a native active/cleanup ACK;human rendering/input remains pending.'])
    o.output.write_bytes((json.dumps(result,indent=2)+'\n').encode());print('PASS Town CSquare Intro Stop inheritance '+sha(o.output.read_bytes()))


if __name__=='__main__':main()
