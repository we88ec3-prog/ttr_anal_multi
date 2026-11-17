#!/usr/bin/env python3
"""Read-only verification of selected qbase/camera/map evidence.

Parses original bytes as data. Never executes Lua or launches the Client.
The read-set check verifies disclosed identities, not a new whole-corpus search.
"""
import argparse
import hashlib
import importlib.util
import json
from pathlib import Path
import struct
import sys
import xml.etree.ElementTree as ET

sys.dont_write_bytecode = True

def check(ok, msg):
    if not ok:
        raise ValueError(msg)

def sha(b):
    return hashlib.sha256(b).hexdigest()

def read(path):
    return json.loads(path.read_text())

def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--originals', type=Path, required=True)
    ap.add_argument('--repo', type=Path, required=True)
    ap.add_argument('--evidence-dir', type=Path, default=Path(__file__).resolve().parent)
    args = ap.parse_args()
    ev = args.evidence_dir
    manifest = read(ev/'source-manifest.json')
    hp = args.repo/manifest['helper']['path']
    check(sha(hp.read_bytes()) == manifest['helper']['sha256'], 'Pinned parser identity')
    spec = importlib.util.spec_from_file_location('pinned_parser', hp)
    p = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(p)
    bi, si = manifest['originals']
    pe = p.PE(args.originals/bi['file'], bi)
    archive = p.STPD(args.originals/si['file'], si)
    raw = (args.originals/si['file']).read_bytes()

    def member(meta):
        ident = archive.files[meta['path']]
        size, first, last = archive.blocks[ident]
        at = 16 + first*1024
        check((ident,size,first,last,at) == (meta['block_id'],meta['stored_length'],
              meta['first_block'],meta['last_block'],meta['stored_offset']), 'STP member mapping')
        stored = archive.data[at:at+size]
        check(sha(raw[at:at+size]) == meta['raw_stored_sha256'], 'Raw member SHA')
        check(sha(stored) == meta['xor_restored_sha256'], 'Restored member SHA')
        data = p.ex_decode(stored)
        check(len(data) == meta['decoded_size'] and sha(data) == meta['decoded_sha256'], 'Decoded member SHA')
        return data

    selected = read(ev/'selected-script-evidence.json')
    q = selected['qbase']
    qdata = member(q['member'])
    check(qdata[:12].hex() == q['lua_header_hex'], 'Lua header')
    protos = p.read_lua51_prototypes(qdata)
    check(len(protos) == q['total_prototypes'], 'Prototype count')
    root = protos[0]
    opnames = ['MOVE','LOADK','LOADBOOL','LOADNIL','GETUPVAL','GETGLOBAL','GETTABLE',
               'SETGLOBAL','SETUPVAL','SETTABLE','NEWTABLE','SELF','ADD','SUB','MUL',
               'DIV','MOD','POW','UNM','NOT','LEN','CONCAT','JMP','EQ','LT','LE',
               'TEST','TESTSET','CALL','TAILCALL','RETURN','FORLOOP','FORPREP',
               'TFORLOOP','SETLIST','CLOSE','CLOSURE','VARARG']

    def instructions(pr, rows):
        for r in rows:
            pc=r['pc']; w=pr['words'][pc]
            check(w == int(r['word_hex'],16), 'Lua word')
            check(pr['code_offset']+pc*4 == r['chunk_offset'], 'Lua word offset')
            check((opnames[w&63],(w>>6)&255,(w>>23)&511,(w>>14)&511,w>>14,(w>>14)-131071) ==
                  (r['op'],r['A'],r['B'],r['C'],r['Bx'],r['sBx']), 'Lua decoded operands')
            if 'constant' in r:
                check(pr['constants'][w>>14] == r['constant'], 'Lua constant reference')
            if 'child_prototype' in r:
                check(pr['children'][w>>14] == r['child_prototype'], 'Lua closure reference')
            if 'destination_pc' in r:
                check(pc+1+(w>>14)-131071 == r['destination_pc'], 'Lua jump destination')

    instructions(root,q['root_binding'])
    for r in q['selected_prototypes']:
        pr=protos[r['index']]
        check(pr['code_offset']==r['code_offset'] and pr['words']==r['words'] and
              pr['constants']==r['constants'] and pr['params']==r['params'], 'Selected Lua prototype')
        instructions(pr,r['instructions'])
    for index, name, pc in [(5,'OnYesTriggered',25),(9,'OnEndTalk',33),
                            (14,'PlayCameraNoWait',43),(15,'PlayCamera',45),
                            (19,'CheckConfirmMessage',53),(60,'LoadMap',135),(75,'Register',171)]:
        closure=root['words'][pc-1]; setter=root['words'][pc]
        check((closure&63)==36 and (setter&63)==7, 'Closure-to-global opcodes')
        check(root['children'][closure>>14]==index and root['constants'][setter>>14]==name,
              'Closure-to-global mapping')
        check((closure>>6)&255 == (setter>>6)&255, 'Closure register continuity')
    for index in (5,9,19):
        check(all(opnames[w&63] in {'GETGLOBAL','SETGLOBAL','RETURN','EQ','JMP','LOADK'}
                  for w in protos[index]['words']), 'Callback is flag/return-only')
    check(protos[5]['constants']==['g_yesTriggered','TRUE'] and len(protos[5]['words'])==3,
          'OnYesTriggered constants')
    check(protos[9]['constants']==['g_scenePlaying','FALSE'] and len(protos[9]['words'])==3,
          'OnEndTalk constants')
    check(protos[19]['constants']==['g_noTriggered','FALSE',0.0,'g_yesTriggered',1.0],
          'CheckConfirmMessage constants')
    camera=protos[14]
    check(camera['constants'][5:9]==['Event/CameraWorks/','CameraWorks','LoadRel','Play'],
          'Camera prefix and consumer names')
    check(camera['words'][20:30]==[0x14201,0x240,0x4024215,0x18245,0x4c1c246,
          0x4000280,0x28002c0,0x3000300,0x3800340,0x280425c], 'Camera filename dataflow words')
    check(protos[60]['constants']==['Q','LoadMap'] and
          protos[60]['words']==[0x45,0xc04046,0x80,0x100405c,0x80001e], 'Q.LoadMap forwarder')
    seq=member(selected['sequence']['member']).decode('euc_kr').splitlines()
    for r in selected['sequence']['selected_lines']:
        check(seq[r['line']-1]==r['text'], 'Selected original seq line')
    c=selected['camera_resource']
    cr=ET.fromstring(member(c['member']).decode('euc_kr'))
    check(cr.tag==c['root_tag'], 'Camera XML root')
    frames=[dict(tag=e.tag,attributes=e.attrib,children=[dict(tag=x.tag,attributes=x.attrib) for x in e]) for e in cr]
    check(frames==c['frames'], 'Camera XML keyframes')

    native=read(ev/'native-script-consumers.json')
    for w in native['windows']+native['strings']:
        pe.verify_window(w)
    def call(site,target):
        data=pe.at(site,5)
        check(data[0]==0xe8 and site+5+struct.unpack_from('<i',data,1)[0]==target, 'Native direct call')
    calls=[(0x54e8d0,0x54ea20),(0x54e8df,0x54eba0),(0x54eeda,0x54f0a0),
           (0x54e9c4,0x7974d0),(0x7974d2,0x796ee0),(0x796f30,0x72ee30),
           (0x796f55,0x72f110),(0x796f69,0x72e2e0),(0x796f73,0x72e2e0),
           (0x56060d,0x565e40),(0x5606e8,0x567500),(0x5697a0,0x56a300),
           (0x563d37,0x8968e3),(0x563d45,0x7c1e00)]
    for site,target in calls:
        call(site,target)
    for va,hexbytes in [(0x54ebb8,'c705301efe0090e95400'),(0x54ec09,'68a0ee5400'),
                         (0x54f0a6,'a1301efe00'),(0x54f1ee,'ff55f8'),
                         (0x567518,'c7050828fe00403c5600'),(0x567569,'6860975600'),
                         (0x569796,'8b0d0828fe00'),(0x56a352,'ff5508')]:
        check(pe.at(va,len(bytes.fromhex(hexbytes))).hex()==hexbytes, 'Native indirect-binding bytes')

    rs=manifest['exploratory_read_set']
    rb=(ev/rs['file']).read_bytes()
    check(sha(rb)==rs['sha256'], 'Read-set document identity')
    readers=json.loads(rb)['members']
    check(len(readers)==rs['members'], 'Read-set count')
    for r in readers:
        size,first,last=archive.blocks[archive.files[r['path']]]
        at=16+first*1024
        data=p.ex_decode(archive.data[at:at+size])
        check(len(data)==r['decoded_size'] and sha(data)==r['decoded_sha256'], 'Read-set member identity')
    print(json.dumps(dict(status='PASS',selected_members=3,selected_qbase_prototypes=7,
                         native_windows=len(native['windows']),native_strings=len(native['strings']),
                         direct_call_operands=len(calls),disclosed_read_set_identities=len(readers),
                         scope='bounded static bytes/dataflow evidence; neither whole-program nor runtime certification'),indent=2))

if __name__=='__main__':
    main()
