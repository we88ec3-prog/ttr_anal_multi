"""Bounded original constructor inheritance and exact three debuff EFF members."""
from pathlib import Path
import hashlib,json,sys,xml.etree.ElementTree as E
R=Path(sys.argv[1]) if len(sys.argv)>1 else Path(r'E:/Tartaros/workspace')
D=R/'runtime-observations/2026-11-05-all-skills'
sys.path[:0]=[str(R/'anal/python_deps'),str(R/'anal')]
from build_native_index import PE
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest()
T='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
p=PE(R/'Tartaros.bin');assert sha(p.data)==T
m=Cs(CS_ARCH_X86,CS_MODE_32);windows=[];decoded={}
for start,end in [(0x4d1710,0x4d1759),(0x4c7070,0x4c7253),(0x4ae671,0x4ae69d)]:
 b=p.read(start,end-start);ins=list(m.disasm(b,start));assert sum(i.size for i in ins)==len(b)
 decoded[start]={i.address:i for i in ins}
 windows.append(dict(start=hex(start),endExclusive=hex(end),sha256=sha(b),
  scope='CONTIGUOUS_PREFIX_NOT_WHOLE_FUNCTION_OR_ALL_BRANCHES',
  instructions=[dict(va=hex(i.address),text=i.mnemonic+' '+i.op_str) for i in ins]))
anchors={0x4d1710:{0x4d1736:'edi, dword ptr [ebp + 8]',0x4d1739:'edi',0x4d173a:'0x4c7070',0x4d1749:'dword ptr [edi], 0xc0c9dc'},
 0x4c7070:{0x4c7098:'ebx, dword ptr [ebp + 8]',0x4c70be:'esi, esi',0x4c70ea:'dword ptr [ebx + 0x36c], esi',
  0x4c71f7:'dword ptr [ebx + 0x3f8], esi',0x4c720d:'dword ptr [ebx + 0x3f4], eax',
  0x4c7213:'dword ptr [eax], eax',0x4c721b:'dword ptr [eax + 4], eax',0x4c7224:'dword ptr [eax + 8], eax',
  0x4c722d:'byte ptr [eax + 0x14], 1',0x4c7237:'byte ptr [ecx + 0x15], 1',
  0x4c7241:'dword ptr [ebx + 0x400], esi',0x4c7247:'dword ptr [ebx + 0x404], esi',0x4c724d:'dword ptr [ebx + 0x408], esi'},
 0x4ae671:{0x4ae692:'0x4d1710'}}
for base,rows in anchors.items():
 for va,operand in rows.items():assert decoded[base][va].op_str==operand,(hex(va),decoded[base][va].op_str)
bulk=R/'anal-multi/kr-bulk-roy'/T/'functions'
sources=[dict(path=str((bulk/f'0x{va:x}.c').relative_to(R)),sha256=sha((bulk/f'0x{va:x}.c').read_bytes())) for va in [0x4d1710,0x4c7070,0x4ae4d0]]
original=Archive(R.parent/'origin/Table.stp');work=Archive(R/'Table.stp')
b=original.read('Table/_BuffList.xml');assert b==work.read('Table/_BuffList.xml')
rows={int(n.get('ID')):n.get('FILE') for n in E.fromstring(b.decode('utf-8-sig')) if n.get('ID') in ['12','28','39']}
assert rows=={12:'S_Dbuff_BasisHolding01.eff',28:'S_Dbuff_BasisFrostbite01.eff',39:'S_Dbuff_BasisStun01.eff'}
oe=Archive(R.parent/'origin/Effect/Effect.stp');we=Archive(R/'Effect/Effect.stp');effects=[]
for bid,name in rows.items():
 found=[f for f in oe.files if f.replace('\\','/').split('/')[-1].casefold()==name.casefold()];assert len(found)==1
 data=oe.read(found[0]);assert data==we.read(found[0])
 effects.append(dict(buff=bid,file=name,member=found[0],sha256=sha(data),workingEqualsOriginal=True))
companions=[]
P=R/'s00-runtime-dev/governance/client-variants/20261107-all-skills-unlock'
for name in ['buff-snapshot-command-dispatch-v1.json','buff-snapshot-writer-root-review.json']:
 companions.append(dict(file=name,sha256=sha((P/name).read_bytes())))
out=dict(schema='MONSTER_BUFF_INHERITANCE_BOUNDARY_V1',targetSha256=T,
 claim='Known monster constructor passes its same object pointer to common actor constructor, initializing the same +3F0 replacement-tree storage used by0077. No actor-class filter is established in the previously reviewed receiver.',
 authority='BOUNDED_ORIGINAL_PREFIX_AND_COMPANION_RECEIVER_NOT_OFFICIAL_SERVER_BEHAVIOR',
 anchors=anchors,originalWindows=windows,sources=sources,companions=companions,
 tableMember=dict(member='Table/_BuffList.xml',sha256=sha(b)),effectMembers=effects,
 adoption='Separate type1-monster-only lab snapshot may use reviewed IDs12/28/39 levels1..5. Full per-included-actor replacement, auxiliary byte0 as lab policy. No owner or arbitrary-ID widening.',
 limitations=['Existing spawn type1 selection/registration is prior bounded evidence, not fully re-audited here.',
  'Prefix success-path anchors only, not entire constructor/callees/exception paths or full Task verification.',
  'Exact EFF membership/hash equality is not full dependency closure or proof of actual rendering/cleanup scheduling.',
  'No native grant/proc/expiry timing, duration-byte interpretation, gameplay effect, AI authority or MEF completion established.',
  'No original Client launch/attachment, provider retry, resource mutation, packet sending or negative tests.'])
f=D/'monster-buff-inheritance-boundary-v1.json';f.write_text(json.dumps(out,indent=2)+'\n',encoding='utf8');print(sha(f.read_bytes()))
