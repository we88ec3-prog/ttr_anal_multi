#!/usr/bin/env python3
"""Read-only static verification. Does not start the Client, execute Lua, or fetch Git objects."""
import argparse
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys

sys.dont_write_bytecode = True

def check(ok, reason):
    if not ok:
        raise ValueError(reason)

def sha(data):
    return hashlib.sha256(data).hexdigest()

def read(path):
    return json.loads(path.read_text())

def num(value):
    return int(value, 0) if isinstance(value, str) else value

def decode(path, start, end):
    out = subprocess.check_output(['objdump', '-D', '-Mintel', '--insn-width=16',
        f'--start-address={start}', f'--stop-address={end+15}', str(path)], text=True)
    rows = []
    for line in out.splitlines():
        m = re.match(r'^\s*([0-9a-f]+):\s*((?:[0-9a-f]{2}\s+)+)\s*(.*)$', line)
        if m and int(m[1], 16) < end:
            rows.append(dict(va=hex(int(m[1], 16)), hex=bytes.fromhex(m[2]).hex(), asm=m[3].strip()))
    return rows

def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--bin', type=Path, required=True)
    ap.add_argument('--event-stp', type=Path, required=True)
    ap.add_argument('--repo', type=Path, required=True)
    ap.add_argument('--evidence-dir', type=Path, default=Path(__file__).resolve().parent)
    ap.add_argument('--wire-dir', type=Path, help='Defaults to sibling ../wire')
    ap.add_argument('--sources', type=Path, help='Optional original navigation .c directory; otherwise only tree identities are rechecked')
    args = ap.parse_args()
    ev = args.evidence_dir
    m = read(ev/'source-manifest.json')
    for name, ident in m['artifacts'].items():
        data = (ev/name).read_bytes()
        check(len(data) == ident['size'] and sha(data) == ident['sha256'], 'Artifact identity: '+name)

    helper = m['helper']
    hp = args.repo/helper['path']
    check(sha(hp.read_bytes()) == helper['sha256'], 'Pinned static PE/STP/Lua parser helper')
    spec = importlib.util.spec_from_file_location('pinned_mef_parser', hp)
    p = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(p)
    bi, si = m['originals']
    pe = p.PE(args.bin, bi)
    ar = p.STPD(args.event_stp, dict(si, bytes=si['size']))

    native = read(ev/'native-windows.json')
    by_id = {}
    all_ins = {}
    instructions = 0
    for w in native['records']:
        check(w['id'] not in by_id, 'Unique record ID')
        by_id[w['id']] = w
        start, end = num(w['va']), num(w['end_exclusive'])
        check(end-start == w['size'], 'Window extent: '+w['id'])
        data = pe.at(start, w['size'])
        check(pe.raw_of(start, w['size']) == num(w['raw_offset']), 'PE raw mapping: '+w['id'])
        check(data.hex() == w['hex'] and sha(data) == w['sha256'], 'Original bytes: '+w['id'])
        if w['kind'] == 'code':
            actual = [r for r in decode(args.bin, num(w['decode_origin']), end) if num(r['va']) >= start]
            check(actual == w['instructions'], 'Full-boundary original decode: '+w['id'])
            cursor = start
            for row in actual:
                check(num(row['va']) == cursor, 'Continuous instruction boundary')
                bb = bytes.fromhex(row['hex'])
                check(pe.at(cursor, len(bb)) == bb, 'Instruction bytes')
                all_ins[cursor] = row
                cursor += len(bb)
            check(cursor == end, 'End boundary: '+w['id'])
            instructions += len(actual)

    def exact(va, text):
        bb = bytes.fromhex(text)
        check(pe.at(va, len(bb)) == bb, f'Key original anchor {va:x}')

    routes = read(ev/'routes.json')
    tables = read(ev/'field-dispatch-tables.json')
    # Rebuild every post-loop write of the complete primary initializer.
    regs = {'ecx': 0xbf2375}
    stores = []
    for row in by_id['common_primary_initialize']['instructions']:
        if num(row['va']) < 0x4add6f:
            continue
        asm = row['asm']
        a = re.fullmatch(r'mov\s+(e[a-z]{2}),0x([0-9a-f]+)', asm)
        if a:
            regs[a[1]] = int(a[2], 16)
            continue
        a = re.fullmatch(r'mov\s+DWORD PTR \[eax\+0x([0-9a-f]+)\],(0x[0-9a-f]+|e[a-z]{2})', asm)
        if a:
            value = int(a[2],16) if a[2].startswith('0x') else regs[a[2]]
            stores.append(dict(va=row['va'], offset=hex(int(a[1],16)), value=hex(value)))
            continue
        check(asm in ('pop    esi','pop    ebx','ret'), 'Unclassified primary initializer operation')
    check(stores == tables['common_primary']['fixed_stores'] and len(stores) == 202, 'Complete primary fixed-store set')
    handlers = {num(s['offset']): num(s['value']) for s in stores if num(s['offset']) % 8 == 4}
    check(len(handlers) == 101 and 0x264 not in handlers and handlers[0x274] == 0x4b3570, '004C/004E primary results')
    exact(0x4add52, '8d5008bed50b0000b97523bf00')
    exact(0x4add60, 'c742fc407d4b00890a83c2084e75f1')
    for q in tables['common_primary']['queries']:
        off = 4+num(q['opcode'])*8
        check(num(q['offset']) == off and num(q['handler']) == handlers.get(off,0x4b7d40), 'Primary query')

    sm = []
    for row in by_id['scene_manager_initialize']['instructions']:
        if num(row['va']) < 0x4b7ddf:
            continue
        a = re.fullmatch(r'mov\s+DWORD PTR ds:0x([0-9a-f]+),(0x[0-9a-f]+|ecx)',row['asm'])
        if a:
            sm.append(dict(va=row['va'],absolute=hex(int(a[1],16)),value=hex(0xbf2375 if a[2]=='ecx' else int(a[2],16))))
        else:
            check(row['asm']=='ret', 'Unclassified scene-manager initializer operation')
    check(sm == tables['scene_manager_primary']['fixed_stores'] and len(sm) == 28, 'Complete scene-manager fixed-store set')
    exact(0x4b7dc0,'b8002dfd00bac07e4b00b97523bf00')
    exact(0x4b7dd0,'8950fc890883c0083da88bfd007cf1')
    for op in (0x4c,0x4e):
        off=0xfd2cf8+4+8*op
        check(not any(num(s['absolute']) in (off,off+4) for s in sm),'Scene-manager selected default slots')

    for st, rid in zip(tables['secondary_tables'],
        ('mission_secondary_initialize','scenario_field_construct','tutorial_field_construct')):
        rows=by_id[rid]['instructions'];got=[];writes=[]
        for row in rows:
            asm=row['asm']
            # The entire selected initializer contains no conditional branch or indirect call.
            check(not re.match(r'j[a-z]+\s',asm), 'No unexplained secondary initializer branch')
            if asm.startswith('call'):
                check(re.fullmatch(r'call\s+0x(?:4add50|89e860)',asm) is not None, 'Only common table initialization and memset')
            a=re.fullmatch(r'mov\s+DWORD PTR \[esi\+0x([0-9a-f]+)\],(0x[0-9a-f]+|eax)',asm)
            if a:
                off=int(a[1],16)
                check(0x5eac<=off<0xbd54, 'Secondary write extent')
                writes.append(off)
                if (off-0x5eac)%8==0:
                    check(a[2].startswith('0x'),'Direct secondary handler constant')
                    got.append(dict(va=row['va'],offset=hex(off),opcode=hex((off-0x5eac)//8),handler=hex(int(a[2],16))))
        check(got == st['handler_stores'] and len(writes)==2*len(got), 'Every secondary handler and metadata write')
        for q in st['queries']:
            off=0x5eac+8*num(q['opcode'])
            handler=next((r['handler'] for r in got if num(r['offset'])==off),'0x0')
            check(num(q['offset'])==off and q['handler']==handler,'Secondary selected query')
    exact(0x4bc6e0,'68a85e00008d86ac5e00006a0050')
    exact(0x4c46f7,'68a85e00008d86ac5e00006a0050')
    exact(0x4c4ac7,'68a85e00008d86ac5e00006a0050')
    exact(0x4b7d40,'8b01ff600c')
    exact(0x422805,'b805400080')

    for c in routes['classes']:
        vt,col,td=map(num,(c['vtable'],c['complete_object_locator'],c['type_descriptor']))
        check(struct.unpack('<I',pe.at(vt-4,4))[0] == col, 'Vtable COL')
        check(struct.unpack('<I',pe.at(col+12,4))[0] == td, 'COL type')
        check(pe.at(td+8,len(c['rtti'])+1)==c['rtti'].encode()+b'\0','RTTI identity')
        for slot,target in c['slots'].items():
            check(struct.unpack('<I',pe.at(vt+num(slot),4))[0]==num(target),'Concrete virtual slot')
    for r in routes['direct_calls']:
        site,target=num(r['site']),num(r['target']);bb=pe.at(site,5)
        check(site in all_ins and bb[0]==0xe8 and site+5+struct.unpack_from('<i',bb,1)[0]==target,'Selected direct-call operand')
    for s in routes['selected_jump_tables']:
        i=(num(s['event'])-num(s['subtracted_base']))&0xffffffff
        check(i==num(s['index']) and num(s['byte_table'])+i==num(s['byte_address']),'Switch byte index')
        selector=pe.at(num(s['byte_address']),1)[0]
        check(selector==s['selector'] and num(s['target_table'])+4*selector==num(s['target_address']),'Switch dword selector')
        check(struct.unpack('<I',pe.at(num(s['target_address']),4))[0]==num(s['target']),'Switch destination')

    # Specific producer/owner/argument anchors. Full windows and their CFG remain reviewable.
    for va,bb in [
      (0x48d7d4,'bec8f3fd00b8840ffc00'),
      (0x4aa5ab,'a30418fe00'),(0x4aa5b7,'891d0018fe00'),
      (0x4ab958,'c7058018fe0010a54a00'),(0x4ab9a9,'6840ca4a00'),
      (0x4acf96,'a10418fe00'),(0x4acff0,'ff550c'),(0x4acffe,'c7410803000000'),
      (0x4abbe0,'a10018fe00'),(0x4abbea,'a30418fe00'),
      (0x4c4f75,'0fb74802'),(0x4c4f7c,'b8880ffc00'),(0x4c4f89,'c70001000000'),
      (0x4b3595,'0fb74002'),(0x4b3599,'8b0df818fe00'),(0x4b359f,'894108'),
      (0x4b35d5,'68da430f00'),(0x506e4a,'a3f818fe00'),
      (0x6bc0f6,'a1f818fe008b7008'),(0x6bc126,'b928000000'),(0x6bc132,'668975e2'),(0x6bc14c,'6a0d'),
      (0x58aaf6,'6a14'),(0x58ab09,'c7000c7bc400c74004ffffffffc74008ffffffff89480c895010'),
      (0x58ab5f,'be6c5cf900'),(0x595d80,'3d5c430f0076123d42440f00730b'),
      (0x595d91,'8b9098010000ffd2'),
      (0x587a68,'c706a4d9c100'),(0x587abe,'c745e404000000'),
      (0x588076,'c706f4f5c100'),(0x5880d8,'c745e40f000000'),
      (0x5b9736,'6840ddc0006a0068c8f3fd00'),(0x5c3666,'6840ddc0006a0068c8f3fd00')]:
        exact(va,bb)
    # F43DA is below 5A4310's first range; selected second-table target is the return.
    check(((0xf43da-0xf43db)&0xffffffff)>0x24,'Base first switch default')
    check(0xf43da not in (0xf4406,0xf4363,0xf43a1,0xf4427),'Mission page selected defaults')
    check(0xf43da not in (0xf4406,0xf4401),'Scenario page selected defaults')

    q = read(ev/'lua-evidence.json')['qbase']
    member = q['member'];ident=ar.files[member['path']]
    size,first,last=ar.blocks[ident];offset=16+first*1024
    check((ident,size,first,last,offset)==(member['block_id'],member['stored_length'],member['first_block'],member['last_block'],member['stored_offset']),'qbase physical mapping')
    stored=ar.data[offset:offset+size]
    raw=args.event_stp.read_bytes()
    check(sha(raw[offset:offset+size])==member['raw_stored_sha256'],'qbase raw block SHA')
    check(sha(stored)==member['xor_restored_sha256'],'qbase restored SHA')
    data=p.ex_decode(stored)
    check(len(data)==member['decoded_size'] and sha(data)==member['decoded_sha256'],'qbase decoded SHA')
    check(data[:12].hex()==q['lua_header_hex'],'qbase Lua 5.1 header')
    protos=p.read_lua51_prototypes(data);root=protos[0]
    check(len(protos)==q['total_prototypes'],'qbase prototype count')
    ops=['MOVE','LOADK','LOADBOOL','LOADNIL','GETUPVAL','GETGLOBAL','GETTABLE','SETGLOBAL','SETUPVAL','SETTABLE','NEWTABLE','SELF','ADD','SUB','MUL','DIV','MOD','POW','UNM','NOT','LEN','CONCAT','JMP','EQ','LT','LE','TEST','TESTSET','CALL','TAILCALL','RETURN','FORLOOP','FORPREP','TFORLOOP','SETLIST','CLOSE','CLOSURE','VARARG']
    def lua_rows(pr,rows):
        for r in rows:
            pc=r['pc'];w=pr['words'][pc]
            check(w==int(r['word_hex'],16) and pr['code_offset']+pc*4==r['chunk_offset'],'Lua word/raw chunk offset')
            check((ops[w&63],(w>>6)&255,(w>>23)&511,(w>>14)&511,w>>14,(w>>14)-131071)==(r['op'],r['A'],r['B'],r['C'],r['Bx'],r['sBx']),'Lua operands')
            if 'constant' in r:check(pr['constants'][w>>14]==r['constant'],'Lua constant')
            if 'child_prototype' in r:check(pr['children'][w>>14]==r['child_prototype'],'Lua prototype target')
            if 'destination_pc' in r:check(pc+1+(w>>14)-131071==r['destination_pc'],'Lua jump')
    lua_rows(root,q['root_binding'])
    for r in q['selected_prototypes']:
        pr=protos[r['index']]
        check(pr['words']==r['words'] and pr['constants']==r['constants'] and pr['params']==r['params'] and pr['code_offset']==r['code_offset'],'Selected qbase body')
        lua_rows(pr,r['instructions'])
        check(all(ops[w&63] in {'GETGLOBAL','SETGLOBAL','RETURN','EQ','JMP','LOADK'} for w in pr['words']),'Flag/return-only qbase callback body')
    for index,name,pc in [(5,'OnYesTriggered',25),(9,'OnEndTalk',33),(19,'CheckConfirmMessage',53)]:
        closure,setter=root['words'][pc-1],root['words'][pc]
        check(closure&63==36 and setter&63==7 and root['children'][closure>>14]==index and root['constants'][setter>>14]==name and (closure>>6)&255==(setter>>6)&255,'Root closure/global binding')

    # Source navigation stays read-only and offline. Tree pins do not imply local .c bytes were supplied.
    env=dict(os.environ,GIT_NO_LAZY_FETCH='1',GIT_OPTIONAL_LOCKS='0')
    nav_verified=0
    for pin in m['source_pins']:
        out=subprocess.check_output(['git','-c','protocol.allow=never','ls-tree',pin['commit'],'--',pin['path']],cwd=args.repo,env=env,text=True).strip()
        check(out and out.split('\t',1)[1]==pin['path'] and out.split()[2]==pin['blob'],'Offline Git tree pin: '+pin['path'])
        if args.sources and pin['role'].startswith(('navigation_','bounded_navigation_')):
            bb=(args.sources/Path(pin['path']).name).read_bytes()
            blob=hashlib.sha1(b'blob '+str(len(bb)).encode()+b'\0'+bb).hexdigest()
            check(len(bb)==pin['size'] and sha(bb)==pin['sha256'] and blob==pin['blob'],'Navigation content identity')
            nav_verified+=1

    wire=args.wire_dir or ev.parent/'wire'
    for n,ident in m['same_round_dependency']['artifacts'].items():
        check(sha((wire/n).read_bytes())==ident['sha256'],'Frozen sibling wire identity: '+n)
    wt=read(wire/'frontend-table.json')
    check(wt['fixed_store_count']==591 and wt['unique_handler_overrides']==197,'Complete frontend initializer set')
    for op in ('0x4c','0x4e'):
        row=next(q for q in wt['query_results'] if q['opcode']==op)
        check(row['handler']=='0x494360' and row['this_adjust']==0 and row['overrides']==[],'Frontend selected default')
    wn={r['id']:r for r in read(wire/'native-windows.json')['records']}
    deps=routes['frontend_dependency']['source_windows']
    for rid in deps:
        w=wn[rid];bb=pe.at(num(w['va']),w['length'])
        check(pe.raw_of(num(w['va']),w['length'])==num(w['raw']) and bb.hex()==w['hex'] and sha(bb)==w['sha256'],'Sibling frontend raw window: '+rid)

    actual=dict(records=len(native['records']),code_windows=sum(w['kind']=='code' for w in native['records']),record_bytes=sum(w['size'] for w in native['records']),decoded_instructions=instructions,classes=len(routes['classes']),selected_jump_tables=len(routes['selected_jump_tables']),direct_calls=len(routes['direct_calls']),common_fixed_stores=len(stores),common_handler_overrides=len(handlers),scene_manager_fixed_stores=len(sm),selected_qbase_prototypes=len(q['selected_prototypes']),source_pins=len(m['source_pins']),navigation_files=len(read(ev/'read-set.json')['native_navigation_files']))
    check(actual==m['stats'],'Declared finite evidence counts')
    print(json.dumps(dict(status='PASS',scope='bounded static original-byte/dataflow verification; no Client/Lua execution, no whole-program or runtime certification',**actual,source_navigation_contents_rechecked=nav_verified,source_navigation_contents_supplied=bool(args.sources),sibling_frontend_windows_rechecked=len(deps),artifact_hashes_checked=len(m['artifacts'])),ensure_ascii=False,indent=2))

if __name__ == '__main__':
    main()
