from review import *
import struct,zlib,os,xml.etree.ElementTree as ET
manifest=json.loads((D/'resource-inputs.json').read_text(encoding='utf8'))
KEY=bytearray([0x30,0xe7])
for i in range(2,1024):KEY.append((KEY[i-2]+KEY[i-1]+0x13-(0x56 if i==0x17c else 0))&255)
OPS='MOVE LOADK LOADBOOL LOADNIL GETUPVAL GETGLOBAL GETTABLE SETGLOBAL SETUPVAL SETTABLE NEWTABLE SELF ADD SUB MUL DIV MOD POW UNM NOT LEN CONCAT JMP EQ LT LE TEST TESTSET CALL TAILCALL RETURN FORLOOP FORPREP TFORLOOP SETLIST CLOSE CLOSURE VARARG'.split()
class Chunk:
    def __init__(self,b):self.b=b;self.p=12;self.protos=[];assert b[:12]==bytes.fromhex('1b4c75615100010404040800')
    def take(self,n):
        assert self.p+n<=len(self.b);v=self.b[self.p:self.p+n];self.p+=n;return v
    def u(self,n=4):return int.from_bytes(self.take(n),'little')
    def string(self):
        n=self.u()
        if n==0:return None
        b=self.take(n);assert b[-1]==0;return b[:-1].decode('utf8',errors='replace')
    def proto(self,parent=None):
        idx=len(self.protos);r=dict(index=idx,parent=parent,start=self.p,source=self.string(),first=self.u(),last=self.u(),nups=self.u(1),params=self.u(1),vararg=self.u(1),stack=self.u(1));self.protos.append(r)
        r['code_offset']=self.p+4;r['words']=[self.u() for _ in range(self.u())];const=[]
        for _ in range(self.u()):
            t=self.u(1)
            if t==0:v=None
            elif t==1:v=bool(self.u(1))
            elif t==3:v=struct.unpack('<d',self.take(8))[0]
            elif t==4:v=self.string()
            else:raise ValueError(t)
            const.append(v)
        r['constants']=const;r['children']=[self.proto(idx) for _ in range(self.u())];r['lines']=[self.u() for _ in range(self.u())]
        r['locals']=[dict(name=self.string(),start=self.u(),end=self.u()) for _ in range(self.u())];r['upvalue_names']=[self.string() for _ in range(self.u())];r['end']=self.p
        code=[]
        for pc,w in enumerate(r['words']):
            op=w&63;a=(w>>6)&255;c=(w>>14)&511;b=(w>>23)&511;bx=w>>14;row=dict(pc=pc,raw_offset=r['code_offset']+pc*4,word=hex(w),op=OPS[op],A=a,B=b,C=c,Bx=bx,sBx=bx-131071)
            if op in [1,5,7]:row['constant']=const[bx]
            if op in [22,31,32]:row['target']=pc+1+bx-131071;assert 0<=row['target']<=len(r['words'])
            if op==28:row.update(arguments=b-1 if b else 'open',results=c-1 if c else 'open')
            code.append(row)
        r['decoded']=code;return idx
def main():
    wanted={'Event/TutorialBase.lua','Event/TutorialMain.lua','Event/qbase.lua','Table/QuestInfo.xml','Table/QuestTalk.xml','Table/ScenarioBookContents.xml','Table/TutCheckPointList.xml'}
    out=[];carriers={}
    for m in manifest:
        if m['resource_path'] not in wanted:continue
        carrier=pathlib.Path(m['container']) if m.get('container') else None
        supplied_root=os.environ.get('T01_'+m['version'].upper()+'_ROOT')
        if carrier and supplied_root:carrier=pathlib.Path(supplied_root)/carrier.name
        supplied_root=os.environ.get('T01_'+m['version'].upper()+'_ROOT')
        if carrier and supplied_root:carrier=pathlib.Path(supplied_root)/carrier.name
        if carrier:
            if str(carrier) not in carriers:
                raw=carrier.read_bytes();assert hashlib.sha256(raw).hexdigest()==m['container_sha256'];carriers[str(carrier)]=raw
            raw=bytes(x^255 for x in carriers[str(carrier)][m['raw_offset']:m['raw_offset']+m['stored_size']]);assert hashlib.sha256(raw).hexdigest()==m['stored_xor_decoded_sha256']
            if raw[:2]==b'EX':
                sz,expanded,off=struct.unpack_from('<III',raw,4);payload=raw[off:off+sz]
                if raw[2]==1:payload=bytes(x^KEY[i%1024] for i,x in enumerate(payload))
                else:assert raw[2]==0
                b=zlib.decompress(payload);assert len(b)==expanded
            else:b=raw
        else:b=pathlib.Path(m['source']).read_bytes()
        assert hashlib.sha256(b).hexdigest()==m['sha256']
        formal=next((R/v/'evidence'/(m['sha256']+'.txt') for v in ['kr','tc','unclassified'] if (R/v/'evidence'/(m['sha256']+'.txt')).exists()),None)
        assert formal is not None and b==formal.read_bytes(),m['resource_path']
        row={k:m[k] for k in ['version','resource_path','sha256','container','container_sha256','raw_offset','stored_size'] if k in m};row.update(bytes=len(b),independent_carrier_decode=True)
        if b.startswith(b'\x1bLua'):
            ch=Chunk(b);ch.proto();assert ch.p==len(b);row.update(prototypes=len(ch.protos),instruction_words=sum(len(p['words']) for p in ch.protos),full_consumption=True)
            audit.save(D/'lua'/(m['version']+'-'+pathlib.Path(m['resource_path']).name+'.json'),dict(source=row,prototypes=ch.protos))
        elif m['resource_path'].endswith('.xml'):
            txt=b.decode(m['encoding']).lstrip('\ufeff');root=ET.fromstring(txt[txt.index('?>')+2:] if txt.startswith('<?xml') else txt);row.update(root=root.tag,children=len(root))
            row['quest15_16']=[dict(tag=e.tag,attributes=e.attrib,text=e.text,children=[dict(tag=x.tag,attributes=x.attrib,text=x.text) for x in e]) for e in root if e.get('id') in ['15','16']]
        out.append(row)
    audit.save(D/'resource-recheck.json',dict(members=out,carrier_hashes={k:hashlib.sha256(v).hexdigest() for k,v in carriers.items()},lua_semantics_reference='https://www.lua.org/source/5.1/lvm.c.html#luaV_execute',limits='Static decode only. Lua metadata/global names do not prove native API side effects or server policy.'))
    print([(r['version'],r['resource_path'],r.get('prototypes'),r.get('instruction_words'),r.get('children')) for r in out])
if __name__=='__main__':main()
