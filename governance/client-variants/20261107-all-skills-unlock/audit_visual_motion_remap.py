"""Bounded motion remap writer and explicit items.ipk include closure. Read-only."""
from pathlib import Path
import sys,json,re,hashlib,struct,xml.etree.ElementTree as E
R=Path(sys.argv[1]) if len(sys.argv)>1 else Path(r'E:\Tartaros\workspace');O=R.parent/'origin';D=R/'runtime-observations/2026-11-05-all-skills'
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest()
binpath=O/'Tartaros.bin';assert sha(binpath.read_bytes())=='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
a,w=Archive(O/'Character/Cha/Base.stp'),Archive(R/'Character/Cha/Base.stp');members=[]
def read(n):
 b,wb=a.read(n),w.read(n);assert b==wb
 members.append({'carrier':'Character/Cha/Base.stp','member':n,'originalSha256':sha(b),'workingSha256':sha(wb),'equal':True})
 return E.fromstring(re.sub(r'^\s*<\?xml[^?]*\?>','',b.decode('euc-kr')))
root=read('Cha/items.ipk');includes=[n.get('File') for n in root.findall('Include')]
j=json.loads((D/'all-role-motion-joins.json').read_text(encoding='utf-8'));roles={Path(r['abf_member']).stem.lower():r for r in j['roles']}
rows=[];includeCoverage=[]
for declared in includes:
 member=declared.removeprefix('Character/');t=read(member);found=0
 role=roles.get(Path(member).stem.split('_')[0].lower())
 for node in t.iter():
  motions=node.find('Motions')
  if motions is None:continue
  found+=1;aliases=[]
  for m in motions.findall('Motion'):
   k,v=int(m.get('Key')),int(m.get('Value'));entry={'declaredAttributes':dict(m.attrib),'sourceAction':k,'replacementAction':v}
   if role:
    for label,ident in [('sourceActionResource',k),('replacementActionResource',v)]:
     md=[x for x in role['motion_metadata'] if x['motion_id']==ident]
     entry[label]=[{z:x[z] for z in ['motion_id','abf_file','asd_member','asd_sha256','header_matches_abf']} for x in md]
   aliases.append(entry)
  rows.append({'member':member,'parentTag':node.tag,'parentAttributes':dict(node.attrib),'role':role['role'] if role else None,'aliases':aliases,'authority':'EXPLICIT_ITEM_AVATAR_MOTIONS_KEY_VALUE_ACTION_ALIAS_NOT_ACTIVE_SKILL_DISPATCH'})
 includeCoverage.append({'declaredFile':declared,'resolvedMember':member,'rootTag':t.tag,'motionDeclarationParents':found})
sourceDir=R/'anal-multi/kr-bulk-roy/9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91/functions'
claims={
 '7a4c50':'IS3D::CDoll constructor creates remap sentinel at +0x80, size at +0x84.',
 '7aca80':'NEW_WRITER: Avatar branch allocates CItemBase, sets +0x20=Part+100; child Motions/Motion Key/Value pair inserted using 57EF20/82F200 into object+0x3C (sentinel +0x40). Source tag literals corroborated by fixed instruction bytes.',
 '7d4d00':'CItemBase constructor initializes map sentinel +0x40/size+0x44; class vtable named.',
 '7a90f0':'NEW_WRITER_CALLER: iterates load/equipment descriptors; global FE1B60 lookup returns item; calls 7D5CD0(base resource, visual+0x7C), then refreshes current action through 7A7800.',
 '7d5cd0':'NEW_WRITER: source map at item+0x40; iterates pair key+0x0C/value+0x10; checks source action against baseResource+0xD8 object virtual+8; inserts pairs into supplied destination map via 57EF20/82F200. Register/custom ABI still partial.',
 '57ef20':'Allocates tree node and copies pair [0],[1] into node+0x0C/+0x10; helper itself is generic.',
 '7a7800':'Consumer: optional remap from CDoll+0x80 sentinel then resource action lookup at base+0xD8; not an active skill producer.',
 '7add40':'Item object file path loader: XML/EX prefix gate ->7D5060; not the Motions writer.',
 '7d5060':'CItemBase visual object parser contains EquipIdentifier, Object, Texture and ReplaceObject; not the reviewed Avatar Motions Key/Value writer.'}
sources=[{'address':'0x'+k,'path':str((sourceDir/('0x'+k+'.c')).relative_to(R)).replace('\\','/'),'sha256':sha((sourceDir/('0x'+k+'.c')).read_bytes()),'boundedClaim':v} for k,v in claims.items()]
# Fixed original PE windows only; no provider, disassembler installation or target execution.
f=binpath.open('rb');f.seek(0x3c);pe=struct.unpack('<I',f.read(4))[0];f.seek(pe+4);_,ns,_,_,_,ol,_=struct.unpack('<HHIIIHH',f.read(20));op=f.read(ol);base=struct.unpack_from('<I',op,28)[0];secs=[struct.unpack_from('<IIII',f.read(40),8) for _ in range(ns)]
def rawread(va,size):
 rva=va-base
 for vs,rv,sz,off in secs:
  if rv<=rva and rva+size<=rv+max(vs,sz):f.seek(off+rva-rv);return f.read(size)
 raise ValueError(hex(va))
windows=[]
for va,size in [(0x7ad989,5),(0x7ad99b,5),(0x7ad9e2,5),(0x7ada1b,5),(0x7ada6c,5)]:
 b=rawread(va,size);literalva=struct.unpack_from('<I',b,1)[0];lit=rawread(literalva,64).split(b'\0')[0]
 windows.append({'instructionVa':hex(va),'bytesHex':b.hex(),'bytesSha256':sha(b),'fixedOpcode':hex(b[0]),'literalVa':hex(literalva),'literalAscii':lit.decode('ascii'),'authority':'FIXED_RAW_BYTES_CORROBORATE_LITERAL_POINTER; not whole-function-disassembly proof'})
f.close()
previous=D/'basic-bridge-producer-boundary.json'
result={'schema':'TARTAROS_VISUAL_MOTION_REMAP_WRITER_AUDIT_V1','sourceBinSha256':'9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91','priorCoveredBoundary':{'file':previous.name,'sha256':sha(previous.read_bytes()),'scope':'7A7800 consumer only; map writer was not closed.'},'newSourceIdentities':sources,'fixedInstructionLiteralWindows':windows,'carrier':{'relativePath':'Character/Cha/Base.stp','originalSha256':sha((O/'Character/Cha/Base.stp').read_bytes()),'workingSha256':sha((R/'Character/Cha/Base.stp').read_bytes())},'sourceMembers':members,'explicitIncludeCoverage':includeCoverage,'declaredAvatarAliases':rows,'summary':{'explicitIncludes':len(includes),'membersMatched':len(members),'avatarParents':len(rows),'aliases':sum(len(r['aliases']) for r in rows),'uniqueActionPairs':sorted({(x['sourceAction'],x['replacementAction']) for r in rows for x in r['aliases']}),'newOpenableActiveSkillMappings':0},'answer':'The reviewed source of CDoll motion remap is Avatar/item Motions Key/Value action substitution; all matched explicit includes declare only SIT15->SIT_Yukata255 and STAND17->STAND_Yukata256. This is not evidence for active-ID->motion dispatch.','unknowns':['Other code may populate this remap map; complete whole-program writer coverage is not claimed.','Saved decompilation omits custom ABI args; no full fresh native validation.','Action alias data does not establish active skills, numeric family variant selection, target/payment/damage or ScriptLevel.'],'limitations':['No original modification, game execution/attach, provider retry, MEF search, Server/Host/shared modification or Git commit.','No archive directory scan beyond the already-known Base.stp and the items.ipk explicitly declared Include closure.','No generic101, numeric order, same matrix slot or arbitrary variant selection.']}
p=D/'visual-motion-remap-writer-audit.json';p.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf-8');print(json.dumps({'path':str(p),'sha256':sha(p.read_bytes()),'summary':result['summary']}))
