"""Bound NPC checkpoint publication and enable-byte consumer to original KR bytes."""
import argparse, hashlib, json, sys
from pathlib import Path
from verify_working_copy_login_ranges import mapped, ORIGINAL


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--binary',type=Path,required=True)
    p.add_argument('--capstone-path',type=Path,required=True)
    p.add_argument('--output',type=Path,required=True)
    a=p.parse_args(); assert not a.output.exists()
    sha,read=mapped(a.binary); assert sha==ORIGINAL
    sys.path.insert(0,str(a.capstone_path))
    import capstone
    md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
    registration=[]
    for i in md.disasm(read(0x4add50,4096),0x4add50):
        registration.append(i)
        if i.mnemonic=='ret': break
    assert registration[-1].mnemonic=='ret'
    end=registration[-1].address+registration[-1].size
    windows=[]
    for start,stop in [(0x4add50,end),(0x4b2af0,0x4b2cc4),(0x543700,0x543b2a),(0x544730,0x5447ef)]:
        raw=read(start,stop-start); ins=list(md.disasm(raw,start))
        assert sum(i.size for i in ins)==len(raw) and ins[-1].mnemonic=='ret'
        boundaries={i.address for i in ins}
        for i in ins:
            if i.mnemonic.startswith('j') and i.op_str.startswith('0x'):
                target=int(i.op_str,16)
                if start<=target<stop: assert target in boundaries
        windows.append({'start':hex(start),'end_exclusive':hex(stop),'sha256':hashlib.sha256(raw).hexdigest(),
                        'bytes':raw.hex(),'instructions':[{'va':hex(i.address),'op':i.mnemonic+' '+i.op_str} for i in ins]})
    ops={i['va']:i['op'] for w in windows for i in w['instructions']}
    assert any(i['op']=='mov dword ptr [eax + 0x13c], 0x4b2af0' for i in windows[0]['instructions'])
    assert (0x13c-4)//8==0x27 and (0x13c-4)%8==0
    expected={'0x4b2b65':'call 0x5449a0','0x4b2b8e':'add edi, 0x12',
              '0x4b2bae':'movzx edx, byte ptr [edi + 1]',
              '0x4b2bb2':'fld dword ptr [edi - 4]',
              '0x4b2bb5':'movzx ecx, byte ptr [edi]',
              '0x4b2bb9':'movzx edx, byte ptr [edi - 0xd]',
              '0x4b2bbf':'movzx edx, word ptr [edi - 0x10]',
              '0x4b2bcb':'movsx dx, byte ptr [edi - 0xe]',
              '0x4b2bd5':'call 0x543700',
              '0x54378d':'mov byte ptr [ebx + 0x105], al',
              '0x544739':'cmp byte ptr [ecx + 0x105], 0'}
    assert all(ops[k]==v for k,v in expected.items())
    result={'classification':'BOUNDED_CHECKPOINT_WIRE_AND_ENABLE_CONSUMER_NOT_QUEST_COMPLETION',
            'target_sha256':sha,'tool':'Capstone '+capstone.__version__,'windows':windows,
            'layout':{'command':'0x27','header_bytes':2,'row_bytes':18,
                      'row_offsets':{'0':'WORD key','2':'signed byte category','3':'byte enable',
                                     '4':'float X','8':'float Y','12':'float radius','16':'byte automatic','17':'byte auxiliary'}},
            'limits':['Row labels follow constructor/interaction source; not official enum names.',
                      'Opcode27 alone is not quest acceptance or a scene-start ACK.',
                      'Configured NPC positions/radius and publication order remain Server candidates.',
                      'Actor existence does not prove an enabled checkpoint or successful dialogue.',
                      'No live Client, UI callback success, full quest completion or village arrival verified.']}
    with a.output.open('x',encoding='utf-8',newline='\n') as f:
        json.dump(result,f,ensure_ascii=False,indent=2);f.write('\n')
    print(json.dumps({'windows':len(windows),'assertions':len(expected)+2,'row_bytes':18,'command':'0x27'}))


if __name__=='__main__':main()
