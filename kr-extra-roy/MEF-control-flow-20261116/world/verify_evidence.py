#!/usr/bin/env python3
"""Read-only verification of selected MEF round10 world/presentation evidence.

Reads original PE/STPD, local pinned Git objects and this evidence package.
Never launches Client/Lua, fetches Git objects, or writes original inputs.
An optional --out writes only a derived JSON verification result.
PASS is byte/structure/selected-contract verification, not gameplay acceptance.
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
import types

CHECKS = {}


def check(condition, label, group='structure'):
    if not condition:
        raise ValueError(label)
    CHECKS[group] = CHECKS.get(group, 0) + 1


def digest(data):
    return hashlib.sha256(data).hexdigest()


def number(value):
    return int(value, 0) if isinstance(value, str) else value


def read_json(path):
    return json.loads(path.read_text())


def git_blob(repo, commit, path):
    env = dict(os.environ, GIT_NO_LAZY_FETCH='1', GIT_TERMINAL_PROMPT='0')
    return subprocess.check_output(['git', '-c', 'maintenance.auto=false',
                                    'show', commit + ':' + path], cwd=repo, env=env)


def disassemble(binary, start, end, raw_of):
    result = subprocess.check_output(
        ['objdump', '-D', '-Mintel', '--insn-width=16',
         '--start-address=' + hex(start), '--stop-address=' + hex(end + 15), str(binary)],
        text=True)
    out = []
    for line in result.splitlines():
        m = re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*(.*)', line)
        if m and int(m[1], 16) < end:
            va = int(m[1], 16)
            b = bytes.fromhex(m[2])
            out.append(dict(va=hex(va), raw=hex(raw_of(va, len(b))),
                            hex=b.hex(), asm=m[3].strip()))
    return out


OPNAMES = ('MOVE LOADK LOADBOOL LOADNIL GETUPVAL GETGLOBAL GETTABLE SETGLOBAL '
           'SETUPVAL SETTABLE NEWTABLE SELF ADD SUB MUL DIV MOD POW UNM NOT LEN '
           'CONCAT JMP EQ LT LE TEST TESTSET CALL TAILCALL RETURN FORLOOP FORPREP '
           'TFORLOOP SETLIST CLOSE CLOSURE VARARG').split()


def decode(p):
    out = []
    for pc, word in enumerate(p['words']):
        op = word & 63
        a, c, b = (word >> 6) & 255, (word >> 14) & 511, (word >> 23) & 511
        bx, sbx = word >> 14, (word >> 14) - 131071
        d = dict(pc=pc, decoded_member_offset=p['code_offset'] + pc * 4,
                 hex=struct.pack('<I', word).hex(), word=hex(word), op=OPNAMES[op],
                 A=a, B=b, C=c, Bx=bx, sBx=sbx)
        if op in (1, 5, 7):
            d['constant'] = p['constants'][bx]
        if op in (6, 9, 12, 13, 14, 15, 16, 17, 23, 24, 25):
            if b >= 256:
                d['RK_B'] = p['constants'][b - 256]
            if c >= 256:
                d['RK_C'] = p['constants'][c - 256]
        if op in (22, 31, 32):
            d['target'] = pc + 1 + sbx
        if op in (28, 29):
            d['arguments'], d['results'] = b - 1, c - 1
        if op == 36:
            d['child_prototype'] = p['children'][bx]
        out.append(d)
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--bin', required=True, type=Path)
    ap.add_argument('--event-stp', required=True, type=Path)
    ap.add_argument('--repo', required=True, type=Path)
    ap.add_argument('--evidence-dir', type=Path, default=Path(__file__).resolve().parent)
    ap.add_argument('--out', type=Path)
    a = ap.parse_args()
    e = a.evidence_dir
    source = read_json(e/'source-manifest.json')
    native = read_json(e/'native-windows.json')
    contracts = read_json(e/'contracts.json')
    bindings = read_json(e/'bindings.json')
    lua = read_json(e/'lua-evidence.json')
    blobs = {}
    for pin in source['git_sources']:
        data = git_blob(a.repo, pin['commit'], pin['path'])
        check(len(data) == pin['bytes'] and digest(data) == pin['sha256'], 'Git content '+pin['path'], 'git_pins')
        oid = hashlib.sha1(b'blob '+str(len(data)).encode()+b'\0'+data).hexdigest()
        check(oid == pin['blob'], 'Git blob '+pin['path'], 'git_pins')
        blobs[pin['commit']+':'+pin['path']] = data
    request_pin = next(p for p in source['git_sources'] if p['path'] == 'research/requests/index.json')
    requests = json.loads(blobs[request_pin['commit']+':'+request_pin['path']])
    req = next(x for x in requests['items'] if x['id'] == 'RR-0013')
    check(req == source['selected_request'], 'Pinned RR-0013 exact selected item', 'scope')
    check(req['owner_task'] == 'T13' and req['dispatch']['state'] == 'QUEUED'
          and req['dispatch']['priority'] == 'P0' and req['dispatch']['claim'] is None,
          'RR-0013 scope boundary, no claim/change', 'scope')
    for pin in source.get('peer_sources', []):
        path = (e/pin['path']).resolve()
        data = path.read_bytes()
        check(len(data) == pin['bytes'] and digest(data) == pin['sha256'], 'Peer fixed source '+pin['path'], 'peer_pins')
    parser_pin = source['parser_source']
    helper = blobs[parser_pin['commit']+':'+parser_pin['path']]
    check(digest(helper) == '8eb16bbc06940769197b2a3446c66a024a3e98d1c44f035ce69c4fee36212a56', 'Read-only parser exact pin', 'source_parser')
    parser = types.ModuleType('pinned_r10_parser'); parser.__file__ = parser_pin['path']
    exec(compile(helper, parser_pin['path'], 'exec'), parser.__dict__)
    pe = parser.PE(a.bin, native['binary'])
    boundaries = set()
    for w in native['windows']:
        pe.verify_window(w)
        check(number(w['end']) - number(w['va']) == w['length'], w['id']+' extent', 'windows')
        if w['kind'] == 'code':
            actual = disassemble(a.bin, number(w['va']), number(w['end']), pe.raw_of)
            check(actual == w['instructions'], w['id']+' regenerated asm', 'disassembly')
            cursor = number(w['va'])
            for ins in actual:
                check(number(ins['va']) == cursor and '(bad)' not in ins['asm'], w['id']+' valid continuous instruction', 'boundaries')
                boundaries.add(cursor); cursor += len(bytes.fromhex(ins['hex']))
            check(cursor == number(w['end']), w['id']+' final boundary', 'boundaries')

    peer_native_count = 0
    if source.get('peer_sources'):
        peer = read_json(e/'../runner/native-windows.json')
        required = {'F11':0x5537f0,'F12':0x553740,'F13':0x4a9db0,'F14':0x80f010,'F15':0x87af60}
        for ident,va in required.items():
            w = next(x for x in peer['records'] if x['id']==ident)
            pe.verify_window(w)
            check(number(w['va'])==va,ident+' shared consumer original bytes','peer_native')
            peer_native_count += 1

    def at(v,n): return pe.at(number(v),n)
    def u32(v): return struct.unpack('<I',at(v,4))[0]
    def cstr(v):
        off=pe.raw_of(number(v),1); return pe.data[off:pe.data.index(0,off)].decode('ascii')
    def direct(v,t,label):
        v,t=number(v),number(t); b=at(v,5)
        check(v in boundaries and b[0]==0xe8 and v+5+struct.unpack_from('<i',b,1)[0]==t,label,'calls')
    for edge in contracts['direct_calls']: direct(edge['va'],edge['target'],edge['role'])
    counts={ns:0 for ns in ['lb','Tutorial','Q','Prolog']}
    names=set()
    for x in bindings['rows']:
        r=number(x['registrar']); counts[x['namespace']]+=1; names.add(x['full_name'])
        direct(x['call_site'],r,x['full_name']+' actual registrar call')
        b=at(r,x['length'])
        check(b.hex()==x['hex'] and digest(b)==x['sha256'] and pe.raw_of(r,len(b))==number(x['raw']), x['full_name']+' original registrar bytes','bindings')
        check(at(r+0x18,2)==b'\xc7\x05' and u32(r+0x1a)==number(x['slot']) and u32(r+0x1e)==number(x['native']),x['full_name']+' native slot','bindings')
        check(at(r+0x58,1)==b'\x68' and u32(r+0x59)==number(x['name_va']) and cstr(x['name_va'])==x['name'],x['full_name']+' name','bindings')
        check(at(r+0x69,1)==b'\x68' and u32(r+0x6a)==number(x['closure']),x['full_name']+' Lua closure','bindings')
    check(counts==dict(lb=14,Tutorial=31,Q=63,Prolog=1) and len(names)==109,'Finite109 public registrar inventory','bindings')
    selected={'Q.FlyingObject':(0x564940,0x569950),'Q.DelFlyingObject':(0x564a60,0x5699b0),'Q.Prolog':(0x564ba0,0x569ad0),'Q.IsPrologRunning':(0x564c50,0x569b30),'Q.Book':(0x565140,0x569d90),'Q.IsBookFlying':(0x565270,0x569e50),'Prolog.OnClose':(0x55f950,0x55ff10)}
    for name,(target,cl) in selected.items():
        row=next(x for x in bindings['rows'] if x['full_name']==name)
        check(number(row['native'])==target and number(row['closure'])==cl,name+' selected API/native mapping','contracts')
    for x in contracts['anchors']:
        check(number(x['va']) in boundaries and at(x['va'],len(bytes.fromhex(x['hex'])))==bytes.fromhex(x['hex']),x['role'],'contract_anchors')
    for t in contracts['types']:
        v=number(t['vptr']);col=number(t['col'])
        check(u32(v-4)==col and u32(col+12)==number(t['type_descriptor']) and cstr(number(t['type_descriptor'])+8)==t['type_name'],t['name']+' original RTTI chain','types')
        for off,target in t['slots'].items():check(u32(v+number(off))==number(target),t['name']+' selected slot'+off,'types')
    for x in contracts['floats']:
        check(struct.unpack('<'+x['format'],at(x['va'],struct.calcsize(x['format'])))[0]==x['value'],'Native float '+x['id'],'contracts')
    check(u32(0xbd25a0)+pe.base==0xd5f00c and cstr(0xd5f00e)=='timeGetTime','GetTime original import identity','contracts')
    check(at(0x553880,3)==bytes.fromhex('8b4224') and at(0x553887,2)==bytes.fromhex('85c0') and at(0x553889,2)==bytes.fromhex('7525'),'shared tick tests alive slot+24 before delete','contracts')
    check(at(0x553765,3)==bytes.fromhex('8b5028') and at(0x55376a,2)==bytes.fromhex('85c0') and at(0x55376c,2)==bytes.fromhex('752e'),'shared sweep preserves nonzero slot+28','contracts')
    check([u32(0x553c50+4*i)for i in range(5)]==[0x553b79,0x553b84,0x553b9a,0x553be9,0x553c05], 'Flying five-way state jump data','contracts')
    check([u32(0x57fbe0+4*i)for i in range(4)]==[0x57fae8,0x57fb47,0x57fb70,0x57fbd4], 'Book four-way phase jump data','contracts')
    check(at(0x80f010,4)==bytes.fromhex('8b4114c3') and at(0x80f020,4)==bytes.fromhex('8b4118c3'), 'Distinct alive/protection field getters','contracts')
    check(at(0x553ef1,3)==bytes.fromhex('895e18') and at(0x553ebb,2)==bytes.fromhex('33db'), 'CFlyingImage base protected+18 initializes zero','contracts')
    check(at(0x55f8d0,6)==bytes.fromhex('c70600000000') and at(0x57fbd4,3)==bytes.fromhex('897b74'),'Prolog and Book distinct active clears','contracts')
    check(u32(0xc3f5f4+0xec)==0x6c0da0 and u32(0xc3f5f4+0x140)==0x6c0cd0 and u32(0xc3f5f4+0xd4)==0x6c0cb0, 'Typed Prolog UI input routes','contracts')
    check(u32(0xc11294+0xc)==0x581090 and u32(0xc112b4+0xc)==0x581300 and u32(0xc112d4+0xc)==u32(0xc112f4+0xc)==0x5818c0, 'Four typed book tick routes','contracts')

    stp=parser.STPD(a.event_stp,lua['carrier']); ev=a.event_stp.read_bytes(); chunks={}
    for item in lua['members']:
        m=item['member']; chunk=stp.verify_member(m)
        check(digest(ev[m['stored_offset']:m['stored_offset']+m['stored_length']])==m['stored_sha256'],'Original stored qbase bytes','lua_identity')
        protos=parser.read_lua51_prototypes(chunk); chunks[m['virtual_path']]=protos
        check(len(protos)==m['prototype_count'] and sum(len(x['words'])for x in protos)==m['instruction_count'],'qbase76 prototypes906 words','lua_identity')
        for q in item['selected_prototypes']:
            real=protos[q['index']]
            for key,value in real.items():check(q[key]==value,'P'+str(q['index'])+' '+key,'lua_prototypes')
            code=chunk[q['code_offset']:q['code_offset']+4*len(q['words'])]
            check(code.hex()==q['code_hex'] and digest(code)==q['code_sha256'] and decode(real)==q['decoded'],'P'+str(q['index'])+' code and decode','lua_prototypes')
    ps=chunks['Event/qbase.lua']; root=decode(ps[0]); found={}
    for i,ins in enumerate(root[:-1]):
        if ins['op']=='CLOSURE' and root[i+1]['op']=='SETGLOBAL' and root[i+1]['A']==ins['A']:
            found[root[i+1]['constant']]=ins['child_prototype']
    for name,idx in [('PrologCloseCallback',8),('WaitForProlog',12),('WaitForBook',13),('FlyingObject',38),('DelFlyingObject',39),('DoProlog',46),('Book',53)]:
        check(found.get(name)==idx,'Actual root global binding '+name,'lua_contracts')
    for idx,getter in [(12,'IsPrologRunning'),(13,'IsBookFlying')]:
        q=decode(ps[idx]); check(q[0].get('constant')=='yield' and q[3].get('RK_C')==getter and q[4]['results']==1 and q[5]['op']=='EQ' and q[5]['A']==0 and q[5].get('RK_C')==1 and q[6]['target']==11 and q[7].get('constant')=='wait' and q[8].get('constant')==100 and q[10]['target']==2,'P'+str(idx)+' initialyield; while numeric1 wait100 loop','lua_contracts')
    q=decode(ps[38]);check(ps[38]['params']==7 and q[1].get('RK_C')=='FlyingObject' and q[9]['arguments']==7 and q[9]['results']==0 and q[10].get('constant')=='yield' and q[11]['arguments']==0,'P38 seven arguments, discard result, yield once','lua_contracts')
    q=decode(ps[39]);check(q[1].get('RK_C')=='DelFlyingObject' and q[2]['arguments']==0 and q[2]['results']==0,'P39 noarg mark deletion','lua_contracts')
    for idx,method,wait in [(46,'Prolog','WaitForProlog'),(53,'Book','WaitForBook')]:
        q=decode(ps[idx]);check(ps[idx]['params']==1 and q[1].get('RK_C')==method and q[3]['arguments']==1 and q[3]['results']==0 and q[4].get('constant')==wait and q[5]['arguments']==0,'P'+str(idx)+' launch then corresponding wait','lua_contracts')
    q=decode(ps[8]);check(q[3].get('constant')=='Prolog' and q[4].get('RK_C')=='OnClose' and q[5]['arguments']==0 and q[5]['results']==0,'P8 local helper invokes public Prolog.OnClose','lua_contracts')

    result=dict(status='PASS',validation='Static original bytes, original Lua parse, native disassembly, pinned local Git and selected structural contracts',binary_sha256=native['binary']['sha256'],event_sha256=lua['carrier']['sha256'],main_commit=source['main_commit'],previous_round_commit=source['previous_round_commit'],counts=dict(windows=len(native['windows']),code_windows=sum(w['kind']=='code'for w in native['windows']),finite_bindings=len(bindings['rows']),selected_new_bindings=len(selected),peer_native_windows=peer_native_count,git_sources=len(source['git_sources']),peer_sources=len(source.get('peer_sources',[])),selected_lua_prototypes=sum(len(i['selected_prototypes'])for i in lua['members']),checks=sum(CHECKS.values())),checks_by_group=CHECKS,verifier_sha256=digest(Path(__file__).read_bytes()),limits=['Not T01 FULL-PASS or Client/Server runtime/gameplay acceptance','No game or Lua execution, network fetch, original edits or repository writes','Ordinary world actor/group result→Lua observer remains Client待逆向','Server authority rules remain Server待開發','Book FB72AC lifecycle and runtime resource validity are outside this bounded closure','Finite four constructor roots do not prove no other dynamic public APIs exist'])
    output=json.dumps(result,ensure_ascii=False,indent=2)+'\n'
    if a.out:
        protected={a.bin.resolve(),a.event_stp.resolve(),Path(__file__).resolve()}
        protected.update(x.resolve()for x in e.iterdir()if x.is_file()and x.name!='verification-result.json')
        check(a.out.resolve()not in protected,'Derived output may not overwrite an input','output_guard')
        a.out.write_text(output)
    print(output,end='')

if __name__ == '__main__':
    try:
        main()
    except (AssertionError,ValueError,OSError,KeyError,subprocess.CalledProcessError) as exc:
        print(json.dumps(dict(status='FAIL',error=str(exc),checks_by_group=CHECKS),ensure_ascii=False,indent=2),file=sys.stderr)
        sys.exit(1)
