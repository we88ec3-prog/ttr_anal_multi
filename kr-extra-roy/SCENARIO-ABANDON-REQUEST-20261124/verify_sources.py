"""Read-only bounded Scenario abandon source verification; no Client execution."""
import argparse
import hashlib
import importlib.util
import json
from pathlib import Path
import struct
import sys

SHA='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
FUNCTIONS=['0x597380','0x5974d0','0x5978d0','0x53ba20','0x5a4310','0x59bd80','0x5afe70']
WINDOWS=[(0x597380,0x5974c3),(0x5974d0,0x597894),(0x5978d0,0x597a22),(0x53ba20,0x53ba73)]


def sha(data):return hashlib.sha256(data).hexdigest()


def main():
    p=argparse.ArgumentParser(description=__doc__)
    for name in ['bin','bulk-directory','capstone-directory','output']:p.add_argument('--'+name,type=Path,required=True)
    o=p.parse_args();data=o.bin.read_bytes();assert sha(data)==SHA
    pe=struct.unpack_from('<I',data,60)[0];assert data[pe:pe+4]==b'PE\0\0'
    assert struct.unpack_from('<H',data,pe+4)[0]==0x14c
    optional=pe+24;assert struct.unpack_from('<H',data,optional)[0]==0x10b
    base=struct.unpack_from('<I',data,optional+28)[0];start=optional+struct.unpack_from('<H',data,pe+20)[0]
    sections=[struct.unpack_from('<IIII',data,start+i*40+8) for i in range(struct.unpack_from('<H',data,pe+6)[0])]
    def raw(address,size):
        offsets=[offset+address-base-rva for _,rva,length,offset in sections if rva<=address-base and address-base+size<=rva+length]
        assert len(offsets)==1
        return offsets[0]
    sys.path.insert(0,str(o.capstone_directory.resolve()));import capstone
    assert capstone.__version__=='5.0.6'
    decoder=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
    decoder_dll=o.capstone_directory/'capstone/lib/capstone.dll'
    windows=[];all_instructions=[]
    for first,last in WINDOWS:
        offset=raw(first,last-first);code=data[offset:offset+last-first]
        instructions=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str) for i in decoder.disasm(code,first)]
        assert sum(len(bytes.fromhex(i['bytes'])) for i in instructions)==len(code)
        windows.append(dict(start=hex(first),stop=hex(last),rawOffset=hex(offset),sha256=sha(code),instructions=instructions))
        all_instructions+=instructions
    # Exact source anchors; addresses are from original function-entry decoding.
    asm=[i['mnemonic']+' '+i['operands'] for i in all_instructions]
    for target in ['0x5974d0','0x53ba20']:
        assert 'call '+target in asm
    assert any(i['mnemonic']=='push' and i['operands']=='0x2af9' for i in all_instructions)
    assert any(i['mnemonic']=='push' and i['operands']=='3' for i in all_instructions)
    anchors={0x53ba4b:'b85d000000',0x53ba50:'668945fc',0x53ba54:'c645fe00',0x53ba62:'8b5210',0x53ba65:'6a03',0x53ba67:'8d45fc',0x53ba6d:'ffd2'}
    decoded={int(i['address'],16):i for i in all_instructions}
    for address,expected in anchors.items():assert decoded[address]['bytes']==expected
    mode2_index=data[raw(0x5978a8,1)];assert mode2_index==0
    mode2_target=struct.unpack_from('<I',data,raw(0x597894+4*mode2_index,4))[0];assert mode2_target==0x597689
    assert decoded[mode2_target]['bytes']=='817d0cf92a0000'
    assert decoded[0x597692]['bytes']=='bf02000000' and decoded[0x597697]['bytes']=='6a24'
    # Compiled message-map record, not XML ordinal: id36,key/default-text pointers.
    record=bytes.fromhex('240000006c8ec1007817c100');assert data.count(record)==1
    key=b'kGiveupScenario\0';offset=raw(0xc18e6c,len(key));assert data[offset:offset+len(key)]==key
    sources=[];index=o.bulk_directory/SHA/'index.jsonl';rows={}
    for line in index.read_text(encoding='utf-8').splitlines():
        row=json.loads(line)
        if row.get('address') in FUNCTIONS and row.get('status')=='ok':rows[row['address']]=row
    for address in FUNCTIONS:
        row=rows[address];assert row['source_sha256']==SHA
        pseudo=o.bulk_directory/SHA/row['pseudocode_path'];assert sha(pseudo.read_bytes())==row['pseudocode_sha256']
        evidence=o.bulk_directory/SHA/row['batch_path'];assert sha(evidence.read_bytes())==row['batch_sha256']
        original=json.loads(evidence.read_bytes())
        sources.append(dict(address=address,pseudocodeSha256=row['pseudocode_sha256'],evidenceSha256=row['batch_sha256'],evidenceId=original['evidence_id'],status='ARCHIVED_GHIDRA_SAVED_UNREVIEWED_BOUNDED_USE'))
    assert sha(o.bin.read_bytes())==SHA
    result=dict(schema='SCENARIO_ABANDON_NATIVE_BOUNDED_SOURCES_V1',sourceSha256=SHA,sourceUnchanged=True,capstoneVersion=capstone.__version__,capstoneDllSha256=sha(decoder_dll.read_bytes()),
        archivedGhidraSources=sources,messageMap=dict(id=36,key='kGiveupScenario',rawRecordOffset=hex(data.index(record)),recordHex=record.hex()),mode2Switch=dict(index=mode2_index,target=hex(mode2_target)),windows=windows,
        clientExecuted=False,clientModified=False,fullFunctionReview=False,originalClientCompatibility='UNKNOWN',
        limitations=['Selected original entry-aligned windows and archived Ghidra pseudocode,not whole-function or whole-Client proof.',
        'Mode2/control0x2af9 selects confirmation kind2/message36. Affirmative path checks manager+0x5ed8 before sending existing005D/00.',
        'Manager+0x5ed8 concrete type and downed input reachability remain UNKNOWN;not authority to implement unconditional abort or infer official return policy.',
        'Raw root Table.stp is a modified working copy and not admitted here;no XML ordinal-to-message-ID assumption.',
        'No new Ghidra import or repeated timed-out query;reuse frozen REA/Ghidra Evidence.'])
    o.output.write_bytes((json.dumps(result,indent=2)+'\n').encode());print('PASS bounded original windows/archive identities '+sha(o.output.read_bytes()))


if __name__=='__main__':main()
