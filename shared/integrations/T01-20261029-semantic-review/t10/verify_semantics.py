"""Reproduce bounded instruction/CFG/dataflow anchors used by the manual review.

Never executes target code. Decoder output and assertions are evidence anchors,
not an automatic document- or function-wide semantic verdict.
"""
import sys,pathlib,json,struct,hashlib,xml.etree.ElementTree as ET
sys.path.insert(0,str(pathlib.Path(__file__).resolve().parents[1]/'support'))
from audit import R,W,B,H,data,offset,cfg,save,sections
D=pathlib.Path(__file__).resolve().parent
ENTRIES=[0x546100,0x546780,0x547240,0x546850,0x546b50,0x546d50,0x6d4dc0,0x6d43f0,0x6d1da0,0x6d4a30,0x6d4ce0,0x5961c0,0x596140,0x761010,0x74d700,0x50c640,0x50cac0,0x54f270,0x54f4e0,0x54adc0,0x548ff0,0x549980,0x549c60,0x549e10,0x54a050,0x81a8e0,0x4cd6f0,0x4c90c0,0x545f30,0x5464c0,0x6d0750,0x6d08f0,0x6d0d10,0x6d1a70,0x6d1be0,0x6d6240,0x594610,0x594a80,0x594570,0x5a55e0,0x5a5760,0x5a57a0,0x5a45c0,0x560170,0x4a1440,0x4dff30,0x4dffb0]
allcfg={a:cfg(a) for a in ENTRIES}
for a,c in allcfg.items():
    assert not c['overlaps'],hex(a)
    save(D/'cfg'/f'{a:08x}.json',c)
lookup={int(x['va'],16):x for c in allcfg.values() for x in c['instructions']}
checks=[]
def anchor(a,b,reason):
    actual=data(a,len(bytes.fromhex(b)));assert actual==bytes.fromhex(b),(hex(a),actual.hex(),b)
    checks.append(dict(va=hex(a),raw=hex(offset(a)),bytes=b,assertion=reason,decoded=lookup.get(a)))
anchor(0x5467a4,'e8 97 0a 00 00','caller→state helper direct edge')
anchor(0x5467b8,'83 cb 40','return4 branch adds mask40')
anchor(0x5467bd,'81 cb 80 00 00 00','return3 branch adds mask80')
anchor(0x5467c5,'83 cb 08','return2 branch adds mask08')
anchor(0x5467f1,'8b 55 10','word-output pointer load; source T10-7 must not call this instruction a store')
anchor(0x5467f4,'66 89 1a','actual word-output store')
anchor(0x5462bf,'51','actor+3E8 value pushed after load at5462B4')
anchor(0x5462dd,'e8 8e 8f 00 00','controller→availability edge')
anchor(0x5462e6,'c6 44 24 17 01','predicate true sets local flag')
anchor(0x5462f6,'c6 44 24 17 01','predicate false/nonzero actor field also sets local flag')
anchor(0x546302,'66 21 53 02','remaining branch masks word with DX=8000 from5462FD')
anchor(0x547308,'3d f4 01 00 00','unsigned elapsed tick compare500')
anchor(0x54730d,'76 4f','unsigned <=500 exits; >500 may change state')
anchor(0x548918,'33 db','command index counter starts0')
anchor(0x54891a,'8d 73 1c','index starts28')
anchor(0x5489b0,'83 fe 26','postincrement compares38; body indexes28..37')
anchor(0x5489b3,'0f 8c 67 ff ff ff','signed loop bound backedge')
anchor(0x54898d,'66 89 4c 24 14','WORD68 store from ECX=68 at548985')
anchor(0x548992,'88 54 24 16','payload byte=EBX+1, not actor combo stage')
anchor(0x6d4c2f,'77 51','non-special ID goes to6D4C82')
anchor(0x6d4cae,'c6 86 04 90 fb 00 00','indexed clear with no <=27 guard in this path')
anchor(0x6d4d98,'0f b6 86 04 90 fb 00','separate guarded indexed reader')
anchor(0x549c4e,'c2 10 00','549980 actual normal-return end precedes549C60')
anchor(0x549c60,'55 8b ec 83 e4 f8','independent549C60 prologue owns549D54 call')
anchor(0x549d54,'e8 17 55 00 00','availability call inside549C60')
anchor(0x596245,'8b f7','reader receives ESI=ordinary ID held in EDI')
anchor(0x59624e,'e8 8d ea 13 00','ordinary phase reader edge')
anchor(0x59643f,'e8 9c e8 13 00','extended phase reader edge')
anchor(0x59635f,'e8 9c 73 1b 00','successful callback path allocates result node')
anchor(0x74d706,'6a 0c','result node allocation size12')
anchor(0x74d71a,'89 08','node next/first link initialized from arg1')
anchor(0x74d71f,'89 50 04','node previous/second link initialized from arg2')
anchor(0x74d72b,'89 11','node+8 receives DWORD dereference of arg3')
anchor(0x560197,'33 db','initialization writer EBX=0')
anchor(0x560239,'89 1d e8 73 fb 00','global store receives zero EBX')
anchor(0x76102c,'c1 ea 13','selector tests bit19')
anchor(0x761036,'c1 ea 08','selector tests bit8')
anchor(0x76103e,'c1 e9 0c','selector tests bit12')
anchor(0x6d0c88,'68 34 8d fb 00','destination bank2 pointer argument')
anchor(0x6d0c8d,'e8 4e 0f 00 00','bank-copy helper edge')
textsection=next(s for s in sections if s['name']=='.text');start=textsection['raw'];end=start+textsection['raw_size'];tb=B[start:end]
def literals(value):
    pat=struct.pack('<I',value);hits=[];i=0
    while (i:=tb.find(pat,i))>=0:hits.append(hex(textsection['va']+i));i+=1
    return hits
def calls(target):
    hits=[]
    for i in range(len(tb)-4):
        if tb[i]==0xe8 and textsection['va']+i+5+struct.unpack_from('<i',tb,i+1)[0]==target:hits.append(hex(textsection['va']+i))
    return hits
scans={hex(t):calls(t) for t in [0x6d4dc0,0x6d4ce0,0x6d4a30,0x594610,0x546780,0x4cd6f0]}
assert len(scans['0x6d4dc0'])==29
assert scans['0x6d4ce0']==['0x59624e','0x59643f']
assert scans['0x6d4a30']==['0x490dfc','0x58a607']
assert scans['0x546780']==['0x546263']
assert scans['0x4cd6f0']==['0x4a0fd8','0x4ae609']
assert len(literals(0xfb9004))==7 and len(literals(0xfb73e8))==18
xml_results=[]
for h in ['6194d2ff4b51eacfb64b03698a10dfea57041b2e714de9a762ea139fffe82b18','6c019693bf60589feb2f3ff6aec651f83ddc0d8103e1358f0ad9c19caf8ac973']:
    p=R/'kr/evidence'/f'{h}.txt';b=p.read_bytes();assert hashlib.sha256(b).hexdigest()==h;root=ET.fromstring(b)
    types=[]
    for t in root:
        types.append(dict(attributes=t.attrib,keys=[n.attrib for n in t]))
    xml_results.append(dict(path=p.relative_to(R).as_posix(),sha256=h,root=root.tag,attributes=root.attrib,types=types))
save(D/'semantic-anchors.json',dict(binary_sha256=H,sections=sections,checks=checks,direct_E8_byte_candidates=scans,literal_positions={hex(x):literals(x) for x in [0xfb9004,0xfb9014,0xfb73e8]},xml=xml_results,limitations=['All machine assertions are supporting anchors. Manual source-version/claim decisions are separate.','Recursive decoder does not expand indirect dispatch, jump tables, EH unwinding or called procedures automatically.','Raw E8 census is candidate enumeration, not proof of global callgraph completeness.']))
print(json.dumps(dict(anchors=len(checks),cfgs=len(allcfg),quoted_byte_verification='see preflight.json',semantic_promotion='none by this script')))
