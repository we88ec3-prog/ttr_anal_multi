"""Read-only bounded CSquare entry/init instruction evidence. Not an official exit contract."""
import argparse, json, sys
from pathlib import Path
from verify_working_copy_login_ranges import mapped, ORIGINAL

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--binary',type=Path,required=True)
    p.add_argument('--capstone-path',type=Path,required=True)
    p.add_argument('--output',type=Path,required=True)
    a=p.parse_args(); assert a.output.suffix=='.json' and not a.output.exists()
    digest,read=mapped(a.binary); assert digest==ORIGINAL
    sys.path.insert(0,str(a.capstone_path))
    import capstone
    md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
    windows=[]
    for va,maximum in [(0x4b9090,768),(0x4bbc10,1280)]:
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
    result={'target_sha256':digest,'tool':'Capstone '+capstone.__version__,'windows':windows,
            'classification':'Bounded original-byte recheck, not FULL-PASS or official Server exit protocol',
            'limitations':['First-ret windows are not exhaustive CFG/callee review.',
                          '69 tail byte meanings, official Town/Map/spawn association and loading rendering remain partial.',
                          '43 is CSquare initialization progress, not map-ready or tutorial completion proof.',
                          'No Client execution, process access, packet send, account mutation or Quest16 completion assertion.']}
    a.output.write_bytes((json.dumps(result,ensure_ascii=False,indent=2)+'\n').encode('utf8'))
    print(json.dumps({'windows':len(windows),'output':str(a.output)}))

if __name__=='__main__':main()
