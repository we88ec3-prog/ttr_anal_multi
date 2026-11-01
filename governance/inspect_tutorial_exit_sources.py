"""Read-only bounded CSquare entry/init instruction evidence. Not an official exit contract."""
import argparse, hashlib, json, struct, sys
from pathlib import Path
from verify_working_copy_login_ranges import mapped, ORIGINAL

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--binary',type=Path,required=True)
    p.add_argument('--capstone-path',type=Path,required=True)
    p.add_argument('--output',type=Path,required=True)
    p.add_argument('--quest-context',action='store_true')
    p.add_argument('--original-table',type=Path)
    a=p.parse_args(); assert a.output.suffix=='.json' and not a.output.exists()
    digest,read=mapped(a.binary); assert digest==ORIGINAL
    sys.path.insert(0,str(a.capstone_path))
    import capstone
    md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
    windows=[]
    spans=[(0x4b9090,768),(0x4bbc10,1280)]
    if a.quest_context:
        spans += [(0x5020b0,256),(0x4fda30,128),(0x502170,256),(0x44aa10,352),(0x44ab70,256),(0x4b1bf0,2048)]
    for va,maximum in spans:
        instructions=[]
        for i in md.disasm(read(va,maximum),va):
            instructions.append(i)
            if i.mnemonic=='ret':break
        assert instructions[-1].mnemonic=='ret'
        size=sum(i.size for i in instructions)
        windows.append({'start':hex(va),'end_exclusive':hex(va+size),'bytes':read(va,size).hex(),
                        'instructions':[{'va':hex(i.address),'bytes':i.bytes.hex(),'op':i.mnemonic+' '+i.op_str} for i in instructions]})
    first=' '.join(i['op'] for i in windows[0]['instructions'])
    second=' '.join(i['op'] for i in windows[1]['instructions'])
    assert 'call 0x4bbb70' in first and 'call 0x4b7d50' in first
    assert 'byte ptr [ecx + 3]' in first and 'byte ptr [ecx + 4]' in first
    assert 'call 0x548540' in second
    assert any(i['va']=='0x4bbe86' and i['op']=='mov eax, 0x43' for i in windows[1]['instructions'])
    assert any(i['op'].startswith('mov byte ptr') and i['op'].endswith(', 0xa') for i in windows[1]['instructions'])
    quest_resources=None
    if a.quest_context:
        ops={i['va']:i['op'] for w in windows for i in w['instructions']}
        registration=' '.join(i['op'] for w in windows if w['start']=='0x5020b0' for i in w['instructions'])
        assert 'dword ptr [0xfab61c], 0x502170' in registration
        assert 'dword ptr [0xfab5c4], 0x5030c0' in registration
        assert ops['0x4b2094']=='movzx edx, word ptr [ebx + 3]'
        assert ops['0x4b2098']=='mov dword ptr [0xfab1bc], edx'
        assert a.original_table is not None
        from inspect_tutorial_bounds_resource import members
        from inspect_first_tutorial_cluster import decode
        import xml.etree.ElementTree as ET
        pin='09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442'
        name='Table/QuestInfo.xml'
        raw=members(a.original_table.read_bytes(),pin,[name])[name]; data=decode(raw,max_expanded=3_000_000)
        quest_digest=hashlib.sha256(data).hexdigest()
        assert quest_digest=='5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60'
        tree=ET.fromstring(data.decode('utf-8-sig')); rows=[]
        for ident in ('14','16','15'):
            q=tree.find(f".//Quest[@id='{ident}']"); assert q is not None
            rows.append({'quest':{k:v for k,v in q.attrib.items() if k!='subject'},
                         'children':[{'tag':e.tag,'attributes':e.attrib} for e in q.iter() if e is not q]})
        quest_resources={'archive_sha256':pin,'member':name,'member_sha256':quest_digest,'selected_rows':rows}
    result={'target_sha256':digest,'tool':'Capstone '+capstone.__version__,'windows':windows,
            'classification':'Bounded original-byte recheck, not FULL-PASS or official Server exit protocol',
            'limitations':['First-ret windows are not exhaustive CFG/callee review.',
                          '69 tail byte meanings, official Town/Map/spawn association and loading rendering remain partial.',
                          '43 is CSquare initialization progress, not map-ready or tutorial completion proof.',
                          'No Client execution, process access, packet send, account mutation or Quest16 completion assertion.']}
    if a.quest_context:
        result['quest_resources']=quest_resources
        result['illustrative_bitmap_not_sent']={'quests':[14,16],'word0':(1<<14)|(1<<16),
                                                'bytes':struct.pack('<HI',0x6f,(1<<14)|(1<<16)).hex()}
    a.output.write_bytes((json.dumps(result,ensure_ascii=False,indent=2)+'\n').encode('utf8'))
    print(json.dumps({'windows':len(windows),'output':str(a.output)}))

if __name__=='__main__':main()
