"""Original-byte Buff map writer and bounded visual cleanup; no target execution."""
from pathlib import Path
import hashlib,json,sys
R=Path(sys.argv[1]) if len(sys.argv)>1 else Path(r'E:/Tartaros/workspace')
D=R/'runtime-observations/2026-11-05-all-skills'
sys.path[:0]=[str(R/'anal/python_deps'),str(R/'anal')]
from build_native_index import PE
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
T='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
p=PE(R/'Tartaros.bin');sha=lambda b:hashlib.sha256(b).hexdigest();assert sha(p.data)==T
md=Cs(CS_ARCH_X86,CS_MODE_32);windows=[];decoded={}
for start,end in [(0x4c9840,0x4c9a16),(0x4ca0b0,0x4ca12a),(0x4c83c0,0x4c8447)]:
    raw=p.read(start,end-start);ins=list(md.disasm(raw,start))
    assert sum(i.size for i in ins)==end-start and ins[-1].mnemonic=='ret'
    starts={i.address for i in ins}
    for i in ins:
        if i.mnemonic.startswith('j') and i.op_str.startswith('0x'):
            target=int(i.op_str,16)
            assert start<=target<end and target in starts
    decoded[start]={i.address:i for i in ins}
    windows.append({'start':hex(start),'endExclusive':hex(end),'sha256':sha(raw),
                    'continuousDecodeAndLocalBranchesChecked':True,
                    'instructions':[{'va':hex(i.address),'text':i.mnemonic+' '+i.op_str} for i in ins]})
anchors={0x4c9840:{0x4c986e:'edi, cx',0x4c9871:'dword ptr [ebp - 0x10], edi',
    0x4c9966:'dword ptr [esi + ecx*4 + 0x164], eax',0x4c9970:'eax, [esi + 0x3f0]',
    0x4c9976:'0x4ca0b0',0x4c997e:'word ptr [eax], bx',0x4c998f:'dl, byte ptr [ebp + 8]',
    0x4c9992:'byte ptr [eax + 2], dl',0x4c99a3:'cl, byte ptr [ebp + 0xc]',
    0x4c99a6:'byte ptr [eax + 3], cl'},
    0x4ca0b0:{0x4ca0d0:'word ptr [eax + 0xc], cx',0x4ca116:'eax, 0x10',0x4ca122:'eax, [ebx + 0x10]'},
    0x4c83c0:{0x4c83ca:'dword ptr [esi + 0x36c], 0',0x4c83ed:'ecx, [esi + 0x3f0]',
    0x4c83f3:'0x826280',0x4c83fa:'edx, dword ptr [esi + 0x3f4]',0x4c8426:'dword ptr [ebx], 0',
    0x4c8436:'edi, 0x80'}}
for start,values in anchors.items():
    for va,text in values.items():assert decoded[start][va].op_str==text,(hex(va),decoded[start][va].op_str)
bulk=R/'anal-multi/kr-bulk-roy'/T/'functions'
sources=[{'path':str((bulk/f'0x{va:x}.c').relative_to(R)),
          'sha256':sha((bulk/f'0x{va:x}.c').read_bytes())} for va in decoded]
out={'schema':'BUFF_SNAPSHOT_WRITER_ROOT_REVIEW_V1','targetSha256':T,
     'writer':{'entry':'4C9840','actorRegister':'ESI','idRegister':'CX zero-extended to saved DWORD',
        'map':'actor+3F0 keyed by WORD BuffId;4CA0B0 searches node keyWORD+0C or inserts and returns value+10',
        'value':'WORD+0 BuffId, BYTE+2 first stack argument, BYTE+3 second stack argument',
        'uiJoin':'Independent68B260/68B750 UI audit consumes value low24: low16 ID, bits16..23 BuffExplain level; highbyte remains opaque.',
        'visual':'Also stores a named attachment at actor+164+BuffId*4. Existing visual-only audit did not exclude this map writer.',
        'bounds':'No proved generic BuffId bound at this writer. Lab emitter restricts to reviewed IDs1..4/levels1..5, not arbitrary indices.'},
     'cleanupHelper':{'entry':'4C83C0','gate':'Only when actor+36C==0',
        'mechanism':'Loops indices0..127; if map lookup is sentinel and indexed visual exists, releases/removes it and zeroes slot.',
        'scope':'Helper behavior only; complete caller scheduling and actual Client visual result remain unverified.'},
     'wireBoundary':{'sourceLayout':'0077 actor replacement route independently reviewed in companion dispatch artifact',
        'auxiliaryByte':'Preserved in map highbyte, not proven remaining seconds/count. Zero is an explicit lab emission candidate only.',
        'time':'No remaining-time field established by this writer/UI chain.',
        'officialServerTiming':'UNRESOLVED'},'sources':sources,'originalWindows':windows,
     'limitations':['Bounded functions/anchors only, not whole Task/native contract acceptance.',
        'No original code/resource changes, target execution/attachment, provider retry or packet send.']}
f=D/'buff-snapshot-writer-root-review.json'
f.write_text(json.dumps(out,indent=2)+'\n',encoding='utf8');print(sha(f.read_bytes()))
