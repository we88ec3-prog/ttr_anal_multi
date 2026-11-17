#!/usr/bin/env python3
"""Offline KR binding census and post-End evidence checks; no target execution.
Writes reports only with --out to a separate directory. Never writes game files.
The optional qbase check imports only the SHA-pinned, reviewed data parser.
"""
from __future__ import annotations
import argparse, collections, csv, hashlib, importlib.util, json, re, struct, subprocess, sys
from pathlib import Path
SHA='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
PARSER_SHA='3a7e2751274b9c1cc43f514e8ab13a5b48ff5983251f847334e213baab0381d2'
NS={0xfe1774:'lb',0xfe1800:'Tutorial',0xfe1e24:'CameraWorks',0xfe1f20:'PREPASS.Q',0xfe1f2c:'Fade',0xfe2764:'Prolog',0xfe2774:'Q',0xfe317c:'ScenarioTalkTable'}
REB=[0x4a1581,0x4aa64c,0x54eacc,0x55e4c1,0x55e901,0x55fe21,0x565eec,0x6bdacc]
SUP=[0x6f66c2,0x6f7685,0x704624,0x707464,0x707514,0x70751f,0x70774c,0x70824a,0x70833d,0x7091df,0x70a102,0x70b3d2,0x70b4dc]
LIB=[(0x701e10,0xc0be48,'debug'),(0x7028eb,0xc0bd20,'math'),(0x7052da,0xc0bca0,'string'),(0x7075e8,0xc0bb90,'_G'),(0x7077aa,0xc0bc68,'coroutine'),(0x7090cd,0xc0bb20,'FILE_metatable'),(0x7092c5,0xc0bac0,'io'),(0x709de0,0xc0ba10,'os'),(0x70b420,0xc0b93c,'package'),(0x70b70a,0xc0b9b8,'package_globals'),(0x70cc00,0xc0b968,'table')]

def need(ok,why):
    if not ok: raise ValueError(why)
def digest(b): return hashlib.sha256(b).hexdigest()
class PE:
    def __init__(self,path):
        self.path=Path(path);self.b=self.path.read_bytes();need(digest(self.b)==SHA,'KR BIN identity')
        u=lambda o:struct.unpack_from('<I',self.b,o)[0]
        p=u(0x3c);o=p+24
        need(self.b[:2]==b'MZ' and self.b[p:p+4]==b'PE\0\0','PE header')
        need(struct.unpack_from('<H',self.b,p+4)[0]==0x14c and struct.unpack_from('<H',self.b,o)[0]==0x10b,'PE32/i386')
        self.base=u(o+28);need(self.base==0x400000,'base');h=o+struct.unpack_from('<H',self.b,p+20)[0];self.sections=[]
        for i in range(struct.unpack_from('<H',self.b,p+6)[0]):
            s=h+40*i;vs,rv,rs,ro=struct.unpack_from('<IIII',self.b,s+8)
            self.sections.append((self.b[s:s+8].rstrip(b'\0').decode(),self.base+rv,rs,ro))
    def raw(self,v,n=1):
        ss=[o+v-a for _,a,s,o in self.sections if a<=v and v+n<=a+s]
        need(len(ss)==1,'Raw-backed address '+hex(v));return ss[0]
    def at(self,v,n):
        r=self.raw(v,n);return self.b[r:r+n]
    def u32(self,v): return struct.unpack('<I',self.at(v,4))[0]
    def string(self,v):
        r=self.raw(v);e=self.b.index(0,r);need(e-r<4096,'String bound');return self.b[r:e].decode('ascii')
    def rels(self,t):
        if not hasattr(self,'_transfers'):
            _,a,n,o=next(s for s in self.sections if s[0]=='.text');d=self.b[o:o+n]
            result=collections.defaultdict(list)
            for op in (0xe8,0xe9):
                k=-1
                while True:
                    k=d.find(bytes([op]),k+1)
                    if k<0 or k+5>len(d):break
                    target=(a+k+5+struct.unpack_from('<i',d,k+1)[0])&0xffffffff
                    result[target].append((a+k,op))
            self._transfers={key:sorted(value) for key,value in result.items()}
        return self._transfers.get(t,[])
    def absolute(self,t):
        out=[]
        for name,a,n,o in self.sections:
            if name not in ('.text','.rdata','.data'):continue
            d=self.b[o:o+n];k=-1
            while True:
                k=d.find(struct.pack('<I',t),k+1)
                if k<0:break
                out.append([name,hex(a+k)])
        return out
    def decode(self,a,z):
        txt=subprocess.check_output(['objdump','-D','-Mintel','--insn-width=16','--start-address='+hex(a),'--stop-address='+hex(z+15),str(self.path)],text=True)
        out=[];cursor=a
        for line in txt.splitlines():
            m=re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*(.*)',line)
            if not m or not a<=int(m[1],16)<z:continue
            v=int(m[1],16);b=bytes.fromhex(m[2]);asm=m[3].strip()
            need(v==cursor and '(bad)' not in asm and b==self.at(v,len(b)),'Decode '+hex(v));cursor+=len(b);out.append((v,b.hex(),asm))
        need(cursor==z,'Exact endpoint '+hex(z));return out

def census(pe):
    _,a,n,o=next(s for s in pe.sections if s[0]=='.text');d=pe.b[o:o+n];rows=[]
    for m in re.finditer(re.escape(bytes.fromhex('558bec8b4508538b1d')),d):
        v=a+m.start()
        if pe.at(v+19,7)!=bytes.fromhex('b8eed8ffffc705'):continue
        slot=pe.u32(v+9);need(slot in NS,'Unclassified namespace')
        need(pe.at(v+0x94,5)==bytes.fromhex('5b5dc20400'),'Registrar end')
        need(pe.rels_target(v+0x6e)==0x6f55b0,'Registrar closure call')
        calls=pe.rels(v);need(len(calls)==1 and calls[0][1]==0xe8,'Registrar caller')
        name=pe.string(pe.u32(v+89));native=pe.u32(v+30)
        status='PREPASS_STUB' if slot==0xfe1f20 else ('STUB' if native in (0x476430,0x550450,0x5f5d10) else ('NOT_COUNT_QUERY' if name=='GetObjectCount' else 'INHERITED_BOUNDED'))
        pe.decode(v,v+0x99)
        rows.append([NS[slot]+'.'+name,hex(v),hex(calls[0][0]),hex(pe.u32(v+26)),hex(native),hex(pe.u32(v+106)),hex(pe.u32(v+89)),status])
    need(len(rows)==122,'Template population changed')
    # Complete bounded E8/E9 set to the selected sink, not a whole-program no-other-API proof.
    sites=pe.rels(0x6f55b0);need(all(op==0xe8 for _,op in sites),'Unexpected tail caller')
    reg={int(r[1],16)+0x6e for r in rows};classes=[]
    for v,op in sites:
        kind=('regular_registrar' if v in reg else 'receiver_rebind' if v in REB else 'prepass_default' if 0x55d7e0<=v<0x55e2d1 else 'prepass_collect' if 0x55d6a0<=v<0x55d7e0 else 'formal_global' if v in (0x6f43c1,0x6f43e8) else 'runtime_support' if v in SUP else 'UNCLASSIFIED')
        need(kind!='UNCLASSIFIED','Unclassified closure site '+hex(v));classes.append([hex(v),kind])
    counts=dict(collections.Counter(k for _,k in classes));need(counts=={'regular_registrar':122,'receiver_rebind':8,'prepass_collect':6,'prepass_default':72,'formal_global':2,'runtime_support':13},'Sink partition')
    need(pe.absolute(0x6f55b0)==[] and pe.absolute(0x6f6590)==[],'Unexpected literal pointer')
    need(pe.rels(0x6f6590)==[(v,0xe8) for v,_,_ in LIB],'Register table callers')
    libs=[]
    for call,table,name in LIB:
        x=table;values=[]
        while pe.u32(x):
            need(len(values)<128,'Table terminator');values.append([pe.string(pe.u32(x)),hex(pe.u32(x+4))]);x+=8
        libs.append({'group':name,'call':hex(call),'table':hex(table),'entries':len(values),'table_sha256':digest(pe.at(table,x-table+8))})
    need(pe.at(0x55e508,10)==bytes.fromhex('c705281ffe00105d5f00'),'Prepass stub assignment')
    return {'schema':'bounded-native-surface-v1','binary_sha256':SHA,'scope':'Exact registrar template and direct E8/E9 calls to 6F55B0/6F6590 in raw-backed .text; excludes computed/inlined/DLL/runtime-rebound routes','formal_names':121,'prepass_duplicate_names':1,'namespace_counts':dict(collections.Counter(r[0].split('.')[0] for r in rows if not r[0].startswith('PREPASS.'))),'registrar_columns':['name','registrar','caller','target_slot','native','closure','name_va','status'],'registrars':rows,'closure_site_columns':['VA','class'],'closure_sites':classes,'closure_site_counts':counts,'literal_sink_pointers':[],'library_tables':libs,'formal_extra_globals':[['PrintStackStatus','0x6f4420'],['DoFile','0x6f48a0']]}
def rels_target(self,v):
    b=self.at(v,5);need(b[0] in (0xe8,0xe9),'Direct transfer');return (v+5+struct.unpack_from('<i',b,1)[0])&0xffffffff
PE.rels_target=rels_target

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--bin',type=Path,required=True);p.add_argument('--event',type=Path);p.add_argument('--prior-parser',type=Path);p.add_argument('--out',type=Path)
    a=p.parse_args();need(not sys.flags.optimize,'Do not use optimized Python');root=Path(__file__).resolve().parent;pe=PE(a.bin)
    actual=census(pe);expected=json.loads((root/'surface-census.json').read_text());need(actual==expected,'Census full result')
    with (root/'capability-matrix.tsv').open() as f: matrix=list(csv.DictReader(f,delimiter='\t'))
    formal={r[0]:r for r in actual['registrars'] if not r[0].startswith('PREPASS.')}
    need(len(matrix)==121 and {r['name'] for r in matrix}==set(formal),'Matrix exact formal names')
    for row in matrix:
        ref=formal[row['name']]
        need([row['registrar'],row['caller'],row['native'],row['closure'],row['semantic_basis']]==[ref[1],ref[2],ref[4],ref[5],ref[7]],'Matrix address/source tuple')
    proof=json.loads((root/'native-proof.json').read_text());total=0;all_asm=[];boundaries=set()
    for name,s,e,raw,sha,count in proof['windows']:
        s=int(s,16);e=int(e,16);need(pe.raw(s,e-s)==int(raw,16) and digest(pe.at(s,e-s))==sha,'Window '+name)
        ins=pe.decode(s,e);need(len(ins)==count,'Instruction count '+name);total+=count;boundaries.update(v for v,_,_ in ins)
        all_asm.append('; '+name+'\n'+'\n'.join(hex(v)+' '+h+' '+t for v,h,t in ins))
    for row in actual['registrars']:
        boundaries.add(int(row[1],16)+0x6e)  # Complete registrar decoding checked in census().
    need(all(int(v,16) in boundaries for v,_ in actual['closure_sites']),'All 223 closure sites on decoded boundaries')
    for name,v,h in proof['anchors']:need(pe.at(int(v,16),len(bytes.fromhex(h))).hex()==h,'Anchor '+name)
    for name,v,h in proof['data']:need(pe.at(int(v,16),len(bytes.fromhex(h))).hex()==h,'Data '+name)
    for v,t in proof['calls']:need(pe.rels_target(int(v,16))==int(t,16),'Call '+v)
    resource_checked=False
    if a.event or a.prior_parser:
        need(a.event and a.prior_parser,'Supply event and parser together')
        need(digest(a.prior_parser.read_bytes())==PARSER_SHA,'Pinned read-only parser')
        spec=importlib.util.spec_from_file_location('pinned_data_parser',a.prior_parser);mod=importlib.util.module_from_spec(spec);spec.loader.exec_module(mod)
        data,meta=mod.STP(a.event).get('Event/qbase.lua');q=json.loads((root/'qbase-evidence.json').read_text());need(meta==q['member'],'Member identity');ps=mod.lua(data)
        for sl in q['slices']:
            pr=ps[sl['prototype']];need([hex(w) for w in pr['words'][sl['pc_begin']:sl['pc_end']]]==sl['words'] and pr['constants']==sl['constants'],'Selected Lua words')
        resource_checked=True
    result={'status':'PASS','scope':'Bounded census, exact BIN windows/anchors, selected original Lua data; not all-feature completion or gameplay','formal_binding_names':121,'registrars':122,'closure_calls':223,'library_table_calls':11,'native_windows':len(proof['windows']),'decoded_instructions':total,'anchors':len(proof['anchors']),'vtable_data':len(proof['data']),'direct_calls':len(proof['calls']),'original_qbase_checked':resource_checked,'client_executed':False,'lua_executed':False,'server_executed':False,'originals_modified':False,'all_mef_functions_complete':False,'official_mef_format_proven':False,'uninterrupted_entry_B_closed':False}
    if a.out:
        out=a.out.resolve();need(out not in (root,a.bin.parent.resolve()),'Output must be separate');out.mkdir(parents=True,exist_ok=True)
        (out/'native-disassembly.asm').write_text('\n\n'.join(all_asm)+'\n');(out/'verification-result.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n')
    print(json.dumps(result,ensure_ascii=False,indent=2))
if __name__=='__main__':
    try:main()
    except (ValueError,OSError,KeyError,subprocess.CalledProcessError) as exc:print('FAIL: '+str(exc),file=sys.stderr);sys.exit(1)
