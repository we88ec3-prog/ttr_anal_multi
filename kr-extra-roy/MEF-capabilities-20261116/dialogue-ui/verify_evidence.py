#!/usr/bin/env python3
"""Read-only checks for the bounded Q dialogue/UI capability and argument contract.

Inputs are original bytes and pinned local Git objects. No network/fetch, Git
mutation, Lua execution/compilation, client execution, or game resource output.
PE/Lua readers are adapted from the separately pinned published verifier.
Only an explicitly requested verification-result JSON may be written.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys
from collections import Counter
import xml.etree.ElementTree as ET
import zlib
sys.dont_write_bytecode=True

def check(ok,why):
    if not ok:raise ValueError(why)
def sha(b):return hashlib.sha256(b).hexdigest()
def blob(b):return hashlib.sha1(b'blob '+str(len(b)).encode()+b'\0'+b).hexdigest()
def load(p):return json.loads(p.read_text())

class PE:
    def __init__(self,path,identity):
        self.path=path;self.b=path.read_bytes()
        check(len(self.b)==identity['size'] and sha(self.b)==identity['sha256'],'Original BIN identity')
        p=struct.unpack_from('<I',self.b,0x3c)[0]
        check(self.b[p:p+4]==b'PE\0\0' and struct.unpack_from('<H',self.b,p+4)[0]==0x14c,'PE32 i386')
        check(struct.unpack_from('<H',self.b,p+24)[0]==0x10b,'PE32 optional header')
        n=struct.unpack_from('<H',self.b,p+6)[0];opt=struct.unpack_from('<H',self.b,p+20)[0]
        self.base=struct.unpack_from('<I',self.b,p+52)[0]
        check(self.base==int(identity['imagebase'],0),'ImageBase')
        self.sections=[]
        for i in range(n):
            q=p+24+opt+40*i;vs,rva,rs,raw=struct.unpack_from('<4I',self.b,q+8)
            self.sections.append((self.b[q:q+8].rstrip(b'\0').decode(),self.base+rva,rs,raw))
    def raw(self,va,n):
        for _,start,size,raw in self.sections:
            if start<=va and va+n<=start+size:return raw+va-start
        raise ValueError('Not raw-backed '+hex(va))
    def at(self,va,n):
        p=self.raw(va,n);return self.b[p:p+n]
    def u32(self,va):return struct.unpack('<I',self.at(va,4))[0]
    def string(self,va):
        p=self.raw(va,1);q=self.b.index(b'\0',p,p+512);return self.b[p:q].decode('ascii')
    def disasm(self,start,end):
        cmd=['objdump','-D','-Mintel','--insn-width=16','--start-address='+hex(start),'--stop-address='+hex(end+15),str(self.path)]
        out=subprocess.run(cmd,capture_output=True,text=True,check=True).stdout;rows=[]
        for line in out.splitlines():
            m=re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*(.*)',line)
            if not m:continue
            a=int(m[1],16)
            if a>=end:continue
            b=bytes.fromhex(m[2]);rows.append(dict(va=hex(a),raw=hex(self.raw(a,len(b))),hex=b.hex(),asm=m[3].strip()))
        return rows

def parse_lua(data):
    check(data[:12].hex()=='1b4c75615100010404040800','Original Lua 5.1 fixed header')
    pos=12;protos=[]
    def take(fmt):
        nonlocal pos
        n=struct.calcsize('<'+fmt);check(pos+n<=len(data),'Lua scalar bounds')
        r=struct.unpack_from('<'+fmt,data,pos);pos+=n;return r
    def string():
        nonlocal pos
        n=take('I')[0]
        if not n:return None
        check(pos+n<=len(data) and data[pos+n-1]==0,'Lua string bounds')
        s=data[pos:pos+n-1].decode('ascii');pos+=n;return s
    def proto(parent):
        nonlocal pos
        idx=len(protos);p=dict(index=idx,parent=parent);protos.append(p)
        p['source']=string();p['first'],p['last']=take('II')
        p['nups'],p['params'],p['vararg'],p['stack']=take('BBBB')
        n=take('I')[0];p['code_offset']=pos;p['words']=list(take('I'*n));constants=[]
        for _ in range(take('I')[0]):
            t=take('B')[0]
            if t==0:v=None
            elif t==1:v=bool(take('B')[0])
            elif t==3:v=take('d')[0]
            elif t==4:v=string()
            else:raise ValueError('Unknown original constant tag '+str(t))
            constants.append(v)
        p['constants']=constants;p['children']=[proto(idx) for _ in range(take('I')[0])]
        take('I'*take('I')[0])
        for _ in range(take('I')[0]):string();take('II')
        for _ in range(take('I')[0]):string()
        return idx
    proto(None);check(pos==len(data),'Complete original Lua carrier consumed');return protos

OPS='MOVE LOADK LOADBOOL LOADNIL GETUPVAL GETGLOBAL GETTABLE SETGLOBAL SETUPVAL SETTABLE NEWTABLE SELF ADD SUB MUL DIV MOD POW UNM NOT LEN CONCAT JMP EQ LT LE TEST TESTSET CALL TAILCALL RETURN FORLOOP FORPREP TFORLOOP SETLIST CLOSE CLOSURE VARARG'.split()
def word_row(p,pc):
    w=p['words'][pc];op=w&63;a=(w>>6)&255;b=w>>23;c=(w>>14)&511;bx=w>>14
    r=dict(pc=pc,chunk_offset=p['code_offset']+4*pc,word=w,hex=struct.pack('<I',w).hex(),opcode=op,mnemonic=OPS[op],A=a,B=b,C=c,Bx=bx)
    if op in(1,5,7):r['constant']=p['constants'][bx]
    if op==36:r['child_prototype']=p['children'][bx]
    if op in(6,9,11,23,24,25):r['RK_constants']={k:p['constants'][v-256] for k,v in [('B',b),('C',c)] if v>=256}
    return r

def verify_lua(actual,saved):
    check(len(actual)==saved['prototype_count'],'Original prototype count')
    check(sum(len(p['words']) for p in actual)==saved['instruction_words'],'Original instruction-word count')
    count=0
    for s in saved['selected_prototypes']:
        p=actual[s['index']]
        for k,v in s.items():
            if k in ('word_count','selected_words'):continue
            check(p[k]==v,'Original prototype field '+k)
        check(len(p['words'])==s['word_count'],'Original prototype word count')
        for r in s['selected_words']:
            check(word_row(p,r['pc'])==r,'Original Lua operand row');count+=1
    return count

def ex_decode(data):
    if data[:2]!=b'EX':return data
    mode=data[2];compressed,expanded,offset=struct.unpack_from('<III',data,4)
    check(mode in (0,1) and offset>=16 and offset+compressed<=len(data),'EX bounds')
    payload=data[offset:offset+compressed]
    if mode:
        key=[0x30,0xe7]
        for i in range(2,1024):key.append((key[i-2]+key[i-1]+0x13-(0x56 if i==0x17c else 0))&255)
        payload=bytes(v^key[i%1024] for i,v in enumerate(payload))
    result=zlib.decompress(payload);check(len(result)==expanded,'EX expanded size');return result

class STPD:
    def __init__(self,path,expected):
        self.raw=path.read_bytes();raw=self.raw
        check(len(raw)==expected['bytes'] and sha(raw)==expected['sha256'],'STP identity')
        check(raw[:4]==b'STPD','STPD header');self.data=bytes(v^255 for v in raw);b=self.data
        index=struct.unpack_from('<I',b,4)[0];check(raw[index:index+4]==b'STPI','STPI header')
        pos=index+8;self.files={}
        def node(parent):
            nonlocal pos
            length=struct.unpack_from('<H',b,pos)[0];pos+=2
            name=b[pos:pos+length].decode('ascii').rstrip('\0');pos+=length
            kind=b[pos];pos+=1;path='/'.join(filter(None,(parent,name)))
            if kind in (1,2):
                count=struct.unpack_from('<I',b,pos)[0];pos+=12
                for _ in range(count):node(path)
            elif kind==0:
                _,ident=struct.unpack_from('<II',b,pos);pos+=16;self.files[path]=ident
            else:raise ValueError('STPI kind '+str(kind))
        node('');check(pos==len(b),'STPI complete index consumption')
        table=struct.unpack_from('>I',b,12)[0];count=struct.unpack_from('<I',b,table)[0];self.blocks={}
        for i in range(count):
            ident,size,first,last=struct.unpack_from('<4I',b,table+4+i*32)
            check(ident not in self.blocks,'Duplicate STPD block id');self.blocks[ident]=(size,first,last)
    def member(self,path):
        ident=self.files[path];n,first,last=self.blocks[ident];off=16+first*1024
        check(last>=first and n<=(last-first+1)*1024 and off+n<=len(self.raw),'Member bounds')
        stored=self.data[off:off+n];decoded=ex_decode(stored)
        meta=dict(virtual_path=path,block_id=ident,stored_length=n,first_block=first,last_block=last,
                  stored_offset=off,raw_stored_sha256=sha(self.raw[off:off+n]),xor_restored_sha256=sha(stored),
                  xor_restored_prefix_hex=stored[:16].hex(),decoded_length=len(decoded),
                  decoded_sha256=sha(decoded),decoded_prefix_hex=decoded[:12].hex())
        return decoded,meta

def resource_evidence(archive):
    """Inspect only named members and explicitly declared TalkTableSet PATHs, in RAM."""
    members=[];roots={}
    selected=['Table/Prolog.xml','Table/ScenarioTalkTable.xml','Table/TalkTableSet.xml','Table/npctable.xml','Table/Book.txt']
    for path in selected:
        data,meta=archive.member(path);members.append(meta)
        if path.endswith('.xml'):roots[path]=ET.fromstring(data)
    paths=[e.attrib['PATH'] for e in roots['Table/TalkTableSet.xml']]
    talkids=[];counts=[]
    for path in paths:
        data,meta=archive.member(path);members.append(meta);root=ET.fromstring(data);rows=list(root.findall('Talk'))
        ids=[int(e.attrib['id']) for e in rows];talkids+=ids
        counts.append(dict(path=path,root=root.tag,rows=len(rows),
          attribute_names=dict(Counter(k for x in rows for k in x.attrib)),
          text_rows=sum(bool((e.text or '').strip()) for e in rows),
          ids_sha256=sha(json.dumps(ids,separators=(',',':')).encode())))
    scene=roots['Table/ScenarioTalkTable.xml'];scene_rows=list(scene);trs=list(scene.iter('Talk'))
    pairs=[(int(x.attrib['id']),int(x.attrib['scene'])) for x in scene_rows]
    def talk_key(x):return int(next(v for k,v in x.attrib.items() if k.lower()=='talk'))
    num_talks=[talk_key(x) for x in trs];keys=set(talkids);missing=sorted(set(num_talks)-keys)
    pair_counts=Counter(pairs);missing_scenes=[];empty_scenes=[]
    for i,x in enumerate(scene_rows):
        rows=list(x.iter('Talk'));pair=pairs[i]
        if not rows:empty_scenes.append(dict(row_index=i,id=pair[0],scene=pair[1]))
        absent=[talk_key(t) for t in rows if talk_key(t) not in keys]
        if absent:missing_scenes.append(dict(row_index=i,id=pair[0],scene=pair[1],absent_talk_keys=absent))
    pro=roots['Table/Prolog.xml'];dialogs=list(pro.iter('Dialog'));lines=list(pro.iter('Line'))
    book,_=archive.member('Table/Book.txt')
    return dict(schema='mef-r11-dialogue-resource-evidence-v1',
      archive=dict(file='07-Table.stp',bytes=len(archive.raw),sha256=sha(archive.raw)),
      selection='Only five named members and 26 PATH dependencies declared by Table/TalkTableSet.xml; no whole archive content extraction',members=members,
      prolog=dict(root=pro.tag,entries=len(pro),dialogs=len(dialogs),lines=len(lines),
        picture_attributes=sum('PicturePath' in x.attrib for x in dialogs),idx_values=[int(x.attrib['idx']) for x in pro],
        max_line_utf16_units=max(len((x.text or '').encode('utf-16-le'))//2 for x in lines),text='UTF-8 XML literal; line payloads deliberately omitted'),
      scenario_talk=dict(root=scene.tag,scenes=len(scene_rows),talk_rows=len(trs),unique_pairs=len(set(pairs)),duplicate_pairs=len(pairs)-len(set(pairs)),
        duplicate_pair_details=[dict(id=k[0],scene=k[1],rows=v) for k,v in sorted(pair_counts.items()) if v>1],
        scenario_attributes=dict(Counter(k for x in scene for k in x.attrib)),talk_attributes=dict(Counter(k for x in trs for k in x.attrib)),
        msg_attribute_count=sum(any(k.lower()=='msg' for k in x.attrib) for x in scene),zero_row_scenes=len(empty_scenes),empty_scene_details=empty_scenes,
        declared_talk_keys=len(set(num_talks)),missing_talk_keys_count=len(missing),missing_talk_keys=missing,
        missing_talk_reference_rows=sum(n not in keys for n in num_talks),missing_reference_scenes=missing_scenes,
        actor_kind_counts=dict(Counter('char' if any(k.lower()=='char' for k in x.attrib) else 'npc' if any(k.lower()=='npc' for k in x.attrib) else 'missing' for x in trs))),
      npctable=dict(archive_path='Table/npctable.xml',native_spelling='Table/NPCTable.xml',root=roots['Table/npctable.xml'].tag,npcs=len(roots['Table/npctable.xml']),
        names='NAME literals decoded by native UTF-8 reader; not copied here',
        face_extension='Image/TalkNPC.xml separately supplies/extends display actors and face groups; absent under that exact archive index path; no claim that every char key must exist in npctable.xml',
        image_talknpc_exact_archive_path_present='Image/TalkNPC.xml' in archive.files),
      talk_table_set=dict(root=roots['Table/TalkTableSet.xml'].tag,declared_paths=paths,loaded_members=len(paths),total_talk_rows=len(talkids),unique_talk_ids=len(keys),duplicate_talk_ids=len(talkids)-len(keys),members=counts),
      book=dict(path='Table/Book.txt',decoded_length=len(book),numeric_token_count=len(book.decode('ascii').split()),purpose='two three-component configuration vectors; content values omitted'))

def pe_imports(pe):
    p=struct.unpack_from('<I',pe.b,0x3c)[0];at=struct.unpack_from('<I',pe.b,p+24+104)[0]+pe.base
    result=[]
    while pe.u32(at) or pe.u32(at+12):
        original=pe.u32(at);library=pe.string(pe.u32(at+12)+pe.base);first=pe.u32(at+16);i=0
        while pe.u32(pe.base+(original or first)+4*i):
            entry=pe.u32(pe.base+(original or first)+4*i);slot=pe.base+first+4*i
            if slot in (0xbd230c,0xbd21cc,0xbd25a0):result.append(dict(iat=hex(slot),library=library,name=pe.string(pe.base+entry+2)))
            i+=1
        at+=20
    return result

def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--originals',type=Path,required=True)
    ap.add_argument('--repo',type=Path,required=True)
    ap.add_argument('--evidence-dir',type=Path,default=Path(__file__).resolve().parent)
    ap.add_argument('--out',type=Path,help='Optional result JSON only; stdout always contains result')
    args=ap.parse_args();e=args.evidence_dir;manifest=load(e/'source-manifest.json')
    originals={r['file']:r for r in manifest['originals']}
    for name,r in originals.items():
        b=(args.originals/name).read_bytes();check(len(b)==r['bytes'] and sha(b)==r['sha256'],'Original '+name)
    def git(*argv):
        return subprocess.check_output(['git','--no-optional-locks','-C',str(args.repo),*argv])
    parent=manifest['public_parent'];main_sha=manifest['main']
    check(parent=='af97bbd29c892e031eef7a3bc3a98cb79f1be729','Published R10 pin')
    check(main_sha=='03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc','Main pin')
    check(git('show','-s','--format=%T',parent).decode().strip()==manifest['parent_tree'],'Public parent tree')
    check(git('show','-s','--format=%P',parent).decode().strip().split()==manifest['parent_parents'],'Public parent parents')
    check(git('merge-base',parent,main_sha).decode().strip()==main_sha,'Public main ancestry')
    prior={}
    for p in manifest['git_pins']:
        check(p['commit'] in (parent,main_sha),'Only public direct dependency commits')
        b=git('show',p['commit']+':'+p['path'])
        check(len(b)==p['bytes'] and sha(b)==p['sha256'] and blob(b)==p['git_blob_sha1'],'Pinned Git blob '+p['path'])
        prior[p['path']]=b
    native=load(e/'native-windows.json');pe=PE(args.originals/native['binary']['file'],native['binary'])
    ids={};instructions={};nbytes=0;asm=['; R11 bounded original native evidence. VA/raw/opcodes are authoritative; labels are analysis labels.']
    for w in native['windows']:
        check(w['id'] not in ids,'Unique window id');ids[w['id']]=w
        a=int(w['start'],0);end=int(w['end_exclusive'],0);bs=bytes.fromhex(w['hex'])
        check(end-a==w['length']==len(bs) and sha(bs)==w['sha256'],'Native window length/hash '+w['id'])
        check(pe.raw(a,len(bs))==int(w['raw'],0) and pe.at(a,len(bs))==bs,'Original native bytes '+w['id'])
        actual=pe.disasm(a,end);check(actual==w['instructions'],'Original disassembly '+w['id'])
        at=a
        for r in actual:
            check(int(r['va'],0)==at and '(bad)' not in r['asm'] and not r['asm'].startswith('.byte'),'Aligned instruction stream '+w['id'])
            at+=len(bytes.fromhex(r['hex']));instructions[r['va']]=r
        check(at==end,'Complete window instruction coverage '+w['id']);nbytes+=len(bs)
        asm+=['',f"; [{w['id']}] {w['start']}..{w['end_exclusive']} raw={w['raw']} sha256={w['sha256']} kind={w['kind']}"]
        asm += [f"{r['va']:>10} raw={r['raw']:>10}  {r['hex']:<32} {r['asm']}" for r in actual]
    check((e/'native-windows.asm').read_text()=='\n'.join(asm)+'\n','ASM artifact derives exactly from checked rows')
    for d in native['data']:
        a=int(d['va'],0);bs=bytes.fromhex(d['hex'])
        check(len(bs)==d['length'] and sha(bs)==d['sha256'] and pe.raw(a,len(bs))==int(d['raw'],0) and pe.at(a,len(bs))==bs,'Native data anchor '+d['id'])
        if d['kind']=='ascii_nul':check(bs==d['value'].encode('ascii')+b'\0','Named original ASCII anchor')
    check(pe_imports(pe)==native['imports'],'Original imported time and string-conversion APIs')
    bindings=load(e/'bindings.json');old=json.loads(prior['kr-extra-roy/MEF-control-flow-20261116/world/bindings.json'])
    for r in bindings['rows']:
        a=int(r['registrar'],0);slot=int(r['slot'],0);target=int(r['native'],0);closure=int(r['closure'],0);nva=int(r['name_va'],0)
        bs=pe.at(a,153)
        check(b'\xc7\x05'+struct.pack('<II',slot,target) in bs,'Normal target-slot producer '+r['full_name'])
        check(b'\x68'+struct.pack('<I',nva) in bs and b'\x68'+struct.pack('<I',closure) in bs,'Name/closure registration '+r['full_name'])
        check(pe.string(nva)==r['name'],'Registered spelling '+r['full_name'])
        call=int(r['call_site'],0);op=pe.at(call,5)
        check(op[0]==0xe8 and call+5+struct.unpack('<i',op[1:])[0]==a,'Constructor registrar caller '+r['full_name'])
        if r['namespace']!='ScenarioTalkTable':
            p=next(x for x in old['rows'] if x['full_name']==r['full_name'])
            check(all(p[k]==r[k] for k in ('namespace','name','full_name','registrar','root','call_site','slot','native','name_va','closure')),'Published normal binding tuple '+r['full_name'])
    def has(window,fragment):
        check(any(fragment in x['asm'] for x in ids[window]['instructions']),'Semantic opcode anchor '+window+' '+fragment)
    check(pe.at(0x550450,3).hex()=='c20800','BalloonTalk ret8 stub')
    for key,address in [('Q_InsertText_closure','0x56a300'),('Q_Dialogue_closure','0x56a430'),('Q_BalloonTalk_closure','0x56a220'),('Q_NumberPanel_closure','0x56a4b0'),('Q_BattlePanel_closure','0x56a220'),('Q_BurstStruck_closure','0x56a4b0')]:has(key,'call   '+address)
    has('talkbox_display_row','mov    edx,DWORD PTR [ecx+0x24]')
    has('talkbox_display_row','mov    DWORD PTR [ebp-0x34],0x0')
    has('talkbox_open','add    eax,0x20');has('talkbox_start','mov    DWORD PTR [esi+0xa0],ecx')
    for name in ['auto_talk_update_1','auto_talk_update_2']:has(name,'0x5dc')
    has('dialogue_text_draw','call   0x735ba0');has('font_glyph_draw','call   0x735c90')
    has('fieldpanel_bucket_id','mov    eax,0x15');has('fieldpanel_render_forward','[eax+0x28]')
    has('q_burst_struck','0x3c');has('q_burst_struck','0x24');has('q_burst_struck','0xe')
    for va,target in [(0xc4fd10,0x7be660),(0xc4fd14,0x7bed00),(0xc4fd18,0x7beda0),(0xc4ff98,0x7d1310),(0xc3eb44+0xec,0x6bd5a0),(0xc3eb44+0x114,0x6bd4f0)]:
        check(pe.u32(va)==target,'Typed virtual consumer '+hex(va))
    lua=load(e/'lua-evidence.json');ea=STPD(args.originals/lua['archive']['file'],lua['archive']);qb,qmeta=ea.member('Event/qbase.lua')
    check(qmeta==lua['member'],'Original qbase locator and identity');p=parse_lua(qb);nwords=verify_lua(p,lua)
    check(any(word_row(p[17],pc)['mnemonic']=='LOADBOOL' and word_row(p[17],pc)['B']==1 for pc in range(len(p[17]['words']))),'OpenTalkScene uses true')
    check(any(word_row(p[18],pc)['mnemonic']=='LOADBOOL' and word_row(p[18],pc)['B']==0 for pc in range(len(p[18]['words']))),'OpenAutoTalkScene uses false')
    check('BattlePanel' in p[57]['constants'] and 'NumberPanel' in p[57]['constants'] and 4.0 in p[57]['constants'],'Original helper two-consumer split')
    resources=load(e/'resource-evidence.json');ta=STPD(args.originals/resources['archive']['file'],resources['archive'])
    check(resource_evidence(ta)==resources,'All selected archive locators, dependent members and schema/key aggregates')
    contracts=load(e/'contracts.json');names={r['full_name'] for r in bindings['rows']}
    check({c['name'] for c in contracts['capabilities']}==names and len(names)==16,'Finite 16-capability coverage')
    for c in contracts['capabilities']:
        check(c['visible_effect'] and c['wait_contract'] and c['preconditions'] and c['limits'],'Capability contract fields')
        for name in c['native_window_flow']:check(name in ids,'Linked capability evidence '+name)
    for state in contracts['scenario_state_machine']:
        for name in state['windows']:check(name in ids,'Linked state transition evidence '+name)
    checksums=load(e/'deliverables-manifest.json')
    for r in checksums['files']:
        b=(e/r['path']).read_bytes();check(len(b)==r['bytes'] and sha(b)==r['sha256'],'Deliverable integrity '+r['path'])
    check('verification-result.json' not in [r['path'] for r in checksums['files']],'No result self-hash cycle')
    result=dict(status='PASS',scope='Static source identity, exact native opcodes/disassembly, normal bindings, original qbase words, selected declared XML data and contract references; not Client execution or gameplay acceptance',
      public_parent=parent,main=main_sha,binary_sha256=native['binary']['sha256'],
      counts=dict(originals=len(originals),git_pins=len(manifest['git_pins']),native_windows=len(ids),native_instruction_rows=sum(len(w['instructions']) for w in native['windows']),native_window_bytes=nbytes,data_anchors=len(native['data']),imports=len(native['imports']),normal_bindings=len(names),qbase_prototypes=lua['prototype_count'],qbase_total_words=lua['instruction_words'],selected_qbase_words=nwords,table_members=len(resources['members']),declared_talk_table_members=resources['talk_table_set']['loaded_members'],capabilities=len(contracts['capabilities']),scenario_state_transitions=len(contracts['scenario_state_machine']),deliverables_hashed=len(checksums['files'])),
      resource_findings=dict(scene_rows=resources['scenario_talk']['scenes'],talk_rows=resources['scenario_talk']['talk_rows'],missing_referenced_talk_keys=resources['scenario_talk']['missing_talk_keys_count'],duplicate_scene_pairs=resources['scenario_talk']['duplicate_pair_details'],empty_scenes=resources['scenario_talk']['empty_scene_details']),
      tools=dict(python=sys.version.split()[0],objdump=subprocess.check_output(['objdump','--version'],text=True).splitlines()[0]),
      negative_scope=['No Lua/Client execution','No game resource output','No original BIN/STP or complete decoded member in deliverables','No network or Git mutation','PASS does not mean T01 FULL-PASS, RR ACCEPTED or playable acceptance'])
    output=json.dumps(result,ensure_ascii=False,indent=2)+'\n'
    if args.out:
        target=args.out.resolve();protected=[(args.originals/r).resolve() for r in originals]+[(e/r['path']).resolve() for r in checksums['files']]+[(e/'deliverables-manifest.json').resolve()]
        check(target not in protected,'Result may not overwrite an input');target.write_text(output)
    print(output,end='')

if __name__=='__main__':
    try:main()
    except Exception as exc:
        print(json.dumps(dict(status='FAIL',error=str(exc)),ensure_ascii=False,indent=2));sys.exit(1)

