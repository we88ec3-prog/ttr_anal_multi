"""Read-only bounded original PE and selected combat resource metadata. No game/Lua execution."""
import argparse, hashlib, json, struct, sys
from pathlib import Path
import xml.etree.ElementTree as ET
from inspect_tutorial_bounds_resource import members
from inspect_first_tutorial_cluster import decode

BIN_SHA = '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--workspace', type=Path, required=True)
    p.add_argument('--binary', type=Path, required=True)
    p.add_argument('--capstone-path', type=Path, required=True)
    p.add_argument('--output', type=Path, required=True)
    p.add_argument('--animation-timing', action='store_true', help='Additional bounded ASD frame/FPS and cooldown-counter windows')
    p.add_argument('--stats-mapping', action='store_true', help='Recheck complete 5C record decoder and distinguish DWORD/WORD destinations')
    p.add_argument('--resource-ratios', action='store_true', help='Recheck character parameter2/3 visual ratios and jump-table cases')
    args = p.parse_args()
    assert args.output.suffix == '.json' and not args.output.exists()
    sys.path.insert(0, str(args.capstone_path))
    import capstone
    b = args.binary.read_bytes(); assert hashlib.sha256(b).hexdigest() == BIN_SHA
    pe = struct.unpack_from('<I', b, 0x3c)[0]; base = struct.unpack_from('<I', b, pe+52)[0]
    sections=[]
    for n in range(struct.unpack_from('<H', b, pe+6)[0]):
        at=pe+24+struct.unpack_from('<H', b, pe+20)[0]+40*n
        _,rva,size,raw=struct.unpack_from('<4I', b, at+8); sections.append((base+rva,size,raw))
    def read(va,size):
        for start,count,raw in sections:
            if start<=va and va+size<=start+count:return b[raw+va-start:raw+va-start+size]
        raise ValueError(hex(va))
    assert read(0x436c40,5).hex()=='8b01ff6028'
    assert struct.unpack('<I',read(0xc073e8+0x28,4))[0]==0x4b0640
    assert struct.unpack('<I',read(0xc0fb1c+0x3c,4))[0]==0x545c50
    health_scale=struct.unpack('<d',read(0xc556d8,8))[0]
    assert abs(health_scale-.0001)<1e-10
    assert struct.pack('<I',0xc556d8) in read(0x4ce7f0,0x180)
    md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
    windows=[]
    spans=[(0x436c40,5),(0x4b19d0,48),(0x545c50,100),(0x4d1e34,53),(0x4ce7f0,144),
           (0x4b0770,18),(0x4b07af,7),(0x4b0819,7),(0x4b0b55,16)]
    if args.animation_timing:
        assert struct.unpack('<I',read(0xc5029c+0x10,4))[0]==0x7d8ca0
        assert struct.unpack('<I',read(0xc5029c+0x0c,4))[0]==0x7d8d20
        spans += [(0x7d9630,85),(0x7d8ca0,20),(0x545e20,0x110),(0x5452c0,0x130),(0x54f200,80)]
    if args.stats_mapping:
        spans += [(0x4d41a0,104)]
        for va, expected in [(0x4d41a7,'8b5004895150'),(0x4d41ad,'8b5008895158'),
                             (0x4d41b3,'8b500c895154'),(0x4d41b9,'0fb75010895140'),
                             (0x4d41c0,'0fb75012895148'),(0x4d41c7,'0fb75014895144')]:
            assert read(va,len(bytes.fromhex(expected))).hex()==expected
        assert read(0x4d4207,1)==b'\xc3'
    resource_cases = None
    if args.resource_ratios:
        targets=struct.unpack('<11I',read(0x4ceb5c,44)); keys=read(0x4ceb88,30)
        resource_cases={str(i+1):hex(targets[keys[i]]) for i in range(3)}
        assert resource_cases=={'1':'0x4ce83b','2':'0x4ce880','3':'0x4ce8c5'}
        assert struct.unpack('<d',read(0xc557e8,8))[0]==100.0
        assert read(0x4ce884,6).hex()=='8983b4030000'
        assert read(0x4ce8c9,6).hex()=='8983b8030000'
        assert read(0x4ce8a6,6).hex()=='dc35e857c500'
        assert read(0x4ce8eb,6).hex()=='dc35e857c500'
        spans += [(0x4ce880,69),(0x4ce8c5,69)]
    for va,size in spans:
        ins=list(md.disasm(read(va,size),va)); count=sum(i.size for i in ins)
        windows.append({'start':hex(va),'end_exclusive':hex(va+count),'bytes':read(va,count).hex(),
                        'instructions':[{'va':hex(i.address),'bytes':i.bytes.hex(),'op':i.mnemonic+' '+i.op_str} for i in ins]})
    instructions={i['va']:i['op'] for w in windows for i in w['instructions']}
    assert '0x3c' in ' '.join(i['op'] for i in windows[1]['instructions'])
    assert instructions['0x545c80']=='cmp word ptr [ebp + 0x10], ax'
    assert instructions['0x4b0770']=='imul eax, eax, 0xd'
    assert instructions['0x4b07af']=='movzx edx, word ptr [ebx]'
    assert instructions['0x4b0819']=='movzx edx, word ptr [ebx + 2]'
    if args.animation_timing:
        assert '0x3e0f83e1' in ' '.join(instructions.values())
        assert '0x54f200' in ' '.join(i['op'] for w in windows if w['start']=='0x5452c0' for i in w['instructions'])
    selected={
      'Character/Cha/Base.stp':('ad5e92f9ef63afa1c2f5849823291c8ae3de7f885ece24fef1b6d771b03a9185',['Cha/Isla.abf']),
      'Character/Mon/Base.stp':('1854de2926ffe7c6172a4b350900f3b5b1e03d9f1757fc22d50b440515ec6957',['Mon/03_Assassin.abf']),
      'Character/Cha/Avatar/04_Isla.stp':('d2fe08d2fbb542f150fabdca2f344f1e0bb38ddaf4d47dc7f5900eac6fb1acfe',
        [f'04_Isla/Asd/Isla_SKILL01_0{i}.asd' for i in range(1,8)]+['04_Isla/Asd/Isla_WSLASH01.asd','04_Isla/Asd/Isla_SSLASH01.asd'])}
    resources=[]
    for archive,(pin,names) in selected.items():
        for name,raw in members((args.workspace/archive).read_bytes(),pin,names).items():
            data=decode(raw); text=data.decode('euc-kr')
            tree=ET.fromstring('<Root>'+text+'</Root>') if name.endswith('.asd') else ET.fromstring(text)
            row={'archive':archive,'archive_sha256':pin,'member':name,'member_sha256':hashlib.sha256(data).hexdigest()}
            if name.endswith('.abf'):
                row['animations']=[e.attrib for e in tree.iter('Animation') if 101<=int(e.get('ID'))<=109 or int(e.get('ID')) in [1,4,6,7]]
            else:
                row['headers']=[e.attrib for e in tree.iter('AnimationHeader')]
                row['splits']=[e.attrib for e in tree.iter('SpliteData')]
            resources.append(row)
    result={'target_sha256':BIN_SHA,'tool':'Capstone '+capstone.__version__,
            'classification':'bounded byte recheck plus resource metadata, not FULL-PASS or official Server rules',
            'health_scale':health_scale,'windows':windows,'resources':resources,
            'character_parameter_cases':resource_cases,
            'limits':['No damage formula, official AI, wave/placement or cancel-window proof.',
                      'ASD negative Delay and mixed FPS require parser/timeline analysis; no blanket Length/FPS timing rule.']}
    args.output.write_bytes((json.dumps(result,ensure_ascii=False,indent=2)+'\n').encode('utf8'))
    print(json.dumps({'windows':len(windows),'resource_members':len(resources),'output':str(args.output)}))
if __name__=='__main__':main()
