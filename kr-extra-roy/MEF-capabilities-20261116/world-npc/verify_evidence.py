#!/usr/bin/env python3
"""Read-only verification of bounded R11 world/NPC evidence; never runs game code."""
from pathlib import Path
import argparse, hashlib, json, os, re, struct, subprocess, sys, types
from xml.etree import ElementTree as ET
sys.dont_write_bytecode=True
ROOT=Path(__file__).resolve().parent
CHECKS=0
def check(ok,label):
    global CHECKS
    CHECKS+=1
    if not ok:raise ValueError(label)
def digest(b):return hashlib.sha256(b).hexdigest()
def j(name):return json.loads((ROOT/name).read_text())
def number(x):return int(x,16) if isinstance(x,str) else x
def git_read(repo,ref):
    env=dict(os.environ,GIT_NO_LAZY_FETCH='1',GIT_OPTIONAL_LOCKS='0')
    return subprocess.check_output(['git','cat-file','-p',ref],cwd=repo,env=env)

class PE:
    def __init__(self,path):
        self.path=path;self.data=path.read_bytes()
        check(self.data[:2]==b'MZ','PE DOS signature')
        p=struct.unpack_from('<I',self.data,0x3c)[0]
        check(self.data[p:p+4]==b'PE\0\0','PE signature')
        check(struct.unpack_from('<H',self.data,p+24)[0]==0x10b,'PE32')
        n=struct.unpack_from('<H',self.data,p+6)[0];opt=struct.unpack_from('<H',self.data,p+20)[0]
        self.base=struct.unpack_from('<I',self.data,p+24+28)[0]
        self.sections=[]
        for i in range(n):
            q=p+24+opt+40*i;vs,rva,rs,raw=struct.unpack_from('<4I',self.data,q+8)
            self.sections.append((self.base+rva,rs,raw))
    def raw(self,va,n=1):
        for a,size,r in self.sections:
            if a<=va and va+n<=a+size:return r+va-a
        raise ValueError(f'VA outside file-backed PE section: {va:#x}/{n}')
    def read(self,va,n):
        off=self.raw(va,n);return self.data[off:off+n]
    def u32(self,va):return struct.unpack('<I',self.read(va,4))[0]
    def string(self,va):
        r=self.raw(va);return self.data[r:self.data.index(0,r)].decode('ascii')
    def dis(self,a,e):
        out=subprocess.check_output(['objdump','-D','-Mintel','--insn-width=16','--start-address='+hex(a),'--stop-address='+hex(e+15),str(self.path)],text=True)
        rows=[]
        for line in out.splitlines():
            m=re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*(.*)',line)
            if m and int(m[1],16)<e:
                v=int(m[1],16);b=bytes.fromhex(m[2]);rows.append({'va':hex(v),'raw':hex(self.raw(v,len(b))),'hex':b.hex(),'asm':m[3].strip()})
        return rows

def verify(args):
    manifest=j('source-manifest.json');native=j('native-windows.json');contracts=j('contracts.json')
    bindings=j('bindings.json')['rows'];resources=j('resources.json')
    pe=PE(args.bin);table_bytes=args.table.read_bytes()
    originals={p['name']:p for p in manifest['originals']}
    for name,b in [('02-Tartaros.bin',pe.data),('07-Table.stp',table_bytes)]:
        check(digest(b)==originals[name]['sha256'],name+' SHA256')
        check(len(b)==originals[name]['bytes'],name+' size')
    check(digest(pe.data)==native['source_sha256'],'native evidence BIN pin')
    check(pe.base==number(native['image_base']),'PE image base')
    windows={w['id']:w for w in native['windows']}
    check(len(windows)==len(native['windows']),'unique windows')
    instructions={}
    for w in native['windows']:
        a=number(w['va']);e=number(w['end']);b=pe.read(a,e-a)
        check(len(b)==w['length'],'window length '+w['id'])
        check(pe.raw(a,len(b))==number(w['raw']),'raw mapping '+w['id'])
        check(b.hex()==w['hex'],'original bytes '+w['id'])
        check(digest(b)==w['sha256'],'window SHA256 '+w['id'])
        if w['kind']=='code':
            decoded=pe.dis(a,e)
            check(decoded==w['instructions'],'assembly '+w['id'])
            at=a
            for ins in decoded:
                check(number(ins['va'])==at,'instruction boundary '+ins['va'])
                at+=len(bytes.fromhex(ins['hex']))
                instructions[(w['id'],ins['va'])]=ins
            check(at==e,'instruction endpoint '+w['id'])
            check(b''.join(bytes.fromhex(i['hex'])for i in decoded)==b,'instruction coverage '+w['id'])
    # Mirror the reviewable ASM artifact from verified JSON, without writing it.
    asm=[]
    for w in native['windows']:
        asm+=['; '+w['id']+' | '+w['role'],'; VA '+w['va']+'..'+w['end']+' raw '+w['raw']+' length '+str(w['length'])+' sha256 '+w['sha256']]
        if w['kind']=='code':asm +=[i['va']+'  '+i['hex'].ljust(32)+' '+i['asm'] for i in w['instructions']]
        else:asm +=['db '+w['hex']]
        asm+=['']
    check((ROOT/'native-windows.asm').read_text()=='\n'.join(asm),'ASM artifact matches verified JSON')
    for r in bindings:
        w=windows[r['registrar_window']];b=bytes.fromhex(w['hex'])
        pattern=b'\xc7\x05'+struct.pack('<II',number(r['slot']),number(r['native']))
        check(pattern in b,'binding target '+r['full_name'])
        check(b'\x68'+struct.pack('<I',number(r['name_va'])) in b,'binding name immediate '+r['full_name'])
        check(pe.string(number(r['name_va']))==r['name'],'binding name string '+r['full_name'])
        check(b'\x68'+struct.pack('<I',number(r['closure'])) in b,'binding closure '+r['full_name'])
        site=number(r['call_site']);x=pe.read(site,5)
        check(x[0]==0xe8 and site+5+struct.unpack('<i',x[1:])[0]==number(r['registrar']),'constructor registers '+r['full_name'])
    for t in contracts['types']:
        v=number(t['vtable']);col=number(t['col']);td=number(t['type_descriptor'])
        check(pe.u32(v-4)==col,'RTTI COL '+t['name'])
        check(pe.u32(col+12)==td,'RTTI descriptor '+t['name'])
        check(pe.string(td+8)==t['rtti'],'RTTI name '+t['name'])
        for off,target in t['selected_slots'].items():
            target=number(target);check(pe.u32(v+number(off))==target,'method slot '+t['name']+off)
            check(0x400000<=target<0xbd0000,'selected slot is code, not adjacent COL '+t['name']+off)
    for c in contracts['direct_calls']:
        ins=instructions[(c['window'],c['site'])];b=bytes.fromhex(ins['hex']);a=number(c['site'])
        check(len(b)==5 and b[0]==0xe8,'call encoding '+c['site'])
        check(a+5+struct.unpack('<i',b[1:])[0]==number(c['target']),'call target '+c['site'])
        check(windows[c['target_window']]['va']==c['target'],'call target window '+c['site'])
    for a in contracts['instruction_anchors']:
        i=instructions[(a['window'],a['site'])]
        check(i['hex']==a['hex'] and i['asm']==a['asm'],'semantic anchor '+a['site'])
    for api in contracts['apis']:
        check(len(api['arguments'])==api['arity'],'API arity '+api['name'])
        check(api['name'] in {r['full_name']for r in bindings},'API normal binding '+api['name'])
        check(all(w in windows for w in api['evidence']),'API evidence '+api['name'])
    for chain in contracts['chains']:
        check(all(w in windows for w in chain['windows']),'chain evidence '+chain['id'])
    # Additional typed checks that prevent two materially misleading generalizations.
    npc=next(t for t in contracts['types']if t['name']=='CNPC')
    check(npc['selected_slots']['0x30']=='0x4d2820','CNPC initializes through its own virtual30')
    check(pe.read(0x4d2824,2)==b'\x6a\x01','CNPC immediate model load argument')
    check(pe.read(0x4a0b4d,4)==bytes.fromhex('6a006a0c'),'CreateObject fixed direction0/scale12')
    check(pe.u32(0xc0cf2c)==0x4e0520,'world animation executor first slot')
    check(pe.string(0xc4fdec)=='Face.SKIN','actual face skin literal')
    # Fixed Git content pins; no fetch/checkout/update is performed.
    source_data={}
    for p in manifest['pins']:
        b=git_read(args.repo,p['commit']+':'+p['path'])
        check(len(b)==p['bytes'],'Git size '+p['path'])
        check(digest(b)==p['sha256'],'Git SHA256 '+p['path'])
        check(hashlib.sha1(b'blob '+str(len(b)).encode()+b'\0'+b).hexdigest()==p['blob'],'Git blob '+p['path'])
        source_data[p['path']]=b
    helper='governance/client-variants/20261105-zh-tw-v3/tools/stp_resources.py'
    parser=types.ModuleType('pinned_read_only_stpd_parser')
    exec(compile(source_data[helper],helper,'exec'),parser.__dict__)
    archive=parser.Archive(args.table)
    check(digest(table_bytes)==resources['archive_sha256'],'Table evidence archive hash')
    roots={}
    for m in resources['members']:
        ident=archive.files[m['member']];size,first,last=archive.blocks[ident];b=archive.read(m['member'])
        check((ident,size,first,last)==(m['block_id'],m['encoded_size'],m['first_sector'],m['last_sector']),'STPD locator '+m['member'])
        check(len(b)==m['decoded_size'] and digest(b)==m['decoded_sha256'],'decoded member '+m['member'])
        roots[Path(m['member']).name]=ET.fromstring(b)
    town=roots['_TownList.xml'].find("./TOWN[@ID='1']")
    roster=sorted(int(x.get('ID'))for x in town.findall('./NPCLIST/NPC'))
    check(roster==resources['town1_roster'],'Town1 NPC roster')
    check(all('X'not in x.attrib and 'Y'not in x.attrib for x in town.findall('./NPCLIST/NPC')),'roster has no NPC XY attrs')
    shops=roots['ShopInfo.xml'].findall("./SHOP[@TOWN='1']")
    got=[]
    for s in shops:
        npc=roots['npctable.xml'].find(f"./NPC[@ID='{s.get('NPC')}']")
        a=roots['_ActorList.xml'].find(f"./OBJCATEGORY[@ID='6']/ACTOR[@ID='{s.get('NPC')}']")
        got.append({'shop_no':int(s.get('NO')),'town':1,'type':int(s.get('TYPE')),'npc_id':int(s.get('NPC')),'product_declarations':len(s.findall('PRODUCT')),'npc_type':int(npc.get('TYPE')),'has_talkset':npc.find('./TALKLIST/TALKSET') is not None,'in_town_roster':int(s.get('NPC')) in roster,'category6_actor':dict(a.attrib) if a is not None else None})
    check(got==resources['town1_shops'],'Town1 shop/NPC/model joins')
    check(sum(s['product_declarations']for s in got)==42,'Town1 direct product declarations')
    for a in resources['selected_category6_models']:
        actual=roots['_ActorList.xml'].find(f"./OBJCATEGORY[@ID='6']/ACTOR[@ID='{a['ID']}']")
        check(actual is not None and actual.attrib==a,'selected category6 actor '+a['ID'])
    for name,expected in manifest.get('artifact_sha256',{}).items():
        check(digest((ROOT/name).read_bytes())==expected,'deliverable SHA256 '+name)
    return {'status':'PASS','scope':'bounded original static evidence; no Client/Lua/Server execution; not T01 ACCEPTED',
            'source_bin_sha256':digest(pe.data),'source_table_sha256':digest(table_bytes),
            'counts':{'checks':CHECKS,'native_windows':len(windows),'code_windows':sum(w['kind']=='code'for w in windows.values()),'native_bytes':sum(w['length']for w in windows.values()),'bindings':len(bindings),'types':len(contracts['types']),'apis':len(contracts['apis']),'chains':len(contracts['chains']),'direct_calls':len(contracts['direct_calls']),'instruction_anchors':len(contracts['instruction_anchors']),'Git_pins':len(manifest['pins']),'resource_members':len(resources['members'])},
            'main':manifest['main'],'parent':manifest['parent'],
            'inputs_read_only':True,'Git_lazy_fetch':False,
            'artifact_sha256':{p.name:digest(p.read_bytes())for p in sorted(ROOT.iterdir())if p.is_file() and p.name not in ['verification-result.json','source-pins.json']}}

def main():
    cli=argparse.ArgumentParser(description=__doc__)
    cli.add_argument('--repo',type=Path,required=True)
    cli.add_argument('--bin',type=Path,required=True)
    cli.add_argument('--table',type=Path,required=True)
    cli.add_argument('--out',type=Path,help='optional derived JSON result only; default stdout')
    args=cli.parse_args()
    result=verify(args);text=json.dumps(result,ensure_ascii=False,indent=2)+'\n'
    if args.out:
        check(args.out.resolve() not in {args.bin.resolve(),args.table.resolve()},'output is not an original')
        check(args.out.suffix=='.json','derived output must be JSON')
        args.out.write_text(text)
    print(text,end='')
if __name__=='__main__':main()
