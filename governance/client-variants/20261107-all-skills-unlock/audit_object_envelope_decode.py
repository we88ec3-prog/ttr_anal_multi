"""Finite421-model offline transform audit; exports hashes, never model assets."""
from pathlib import Path
import collections, gzip, hashlib, json, re, sys

ROOT = Path(__file__).resolve().parents[4]
sys.path[:0] = [str(ROOT/'anal/python_deps'),str(ROOT/'anal')]
from build_native_index import PE
from stp_resources import Archive
from capstone import Cs, CS_ARCH_X86, CS_MODE_32
from decode_object_envelope import decode_object_member, transform_blocks, SEED_WORDS

sha = lambda data: hashlib.sha256(data).hexdigest()
here = Path(__file__).parent
target = '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
pe = PE(ROOT/'Tartaros.bin')
assert sha(pe.data) == target
md = Cs(CS_ARCH_X86, CS_MODE_32)
windows = []
for address,length in [(0x733ea0,0xec),(0x7cc000,0x94)]:
    raw = pe.read(address,length)
    ins = list(md.disasm(raw,address))
    assert sum(i.size for i in ins) == length and ins[-1].mnemonic == 'ret'
    windows.append({'address':hex(address),'length':length,'sha256':sha(raw),
                    'instructions':[{'address':hex(i.address),'text':i.mnemonic+' '+i.op_str} for i in ins]})
seed = []
for item in windows[0]['instructions']:
    match = re.fullmatch(r'mov dword ptr \[ebp - (0x[0-9a-f]+)\], (0x[0-9a-f]+)',item['text'])
    if match and 0x68 <= int(match[1],16) <= 0x84:
        seed.append(int(match[2],16))
assert tuple(seed) == SEED_WORDS
preflight_ins = list(md.disasm(pe.read(0x6d7560,0x2d0),0x6d7560))
preflight_scope = [i for i in preflight_ins if i.address in (0x6d7640,0x6d77a5)]
assert [i.op_str for i in preflight_scope] == ['ecx, dword ptr [edi + 0xf882e8]','edi, 0x6c']

prior_path = here/'action-object-dependency-availability-v1.json'
prior_raw = prior_path.read_bytes()
assert sha(prior_raw) == '19ecc804c63eb024d2a60fd13476b81236e3cc91073103d42e31954b71c2f873'
prior = json.loads(prior_raw)
original = Archive(ROOT.parent/'origin/Effect/Object.stp')
working = Archive(ROOT/'Effect/Object.stp')
numeric_path = ROOT/'runtime-observations/2026-11-05-all-skills/numeric-family-explicit-link-audit.json'
assert sha(numeric_path.read_bytes()) == prior['priorNumericAuditSha256']
relations = json.loads(numeric_path.read_bytes())['matrixSkillTalentRelations']
needles = [(r['role'],r['active'],Path(r['practiceMember']).stem.encode('ascii').lower()) for r in relations]
rows = []
for row in prior['rows']:
    if not row['declaredFile'].lower().endswith('.gb3'): continue
    data = original.read(row['member'])
    assert data == working.read(row['member']) and sha(data) == row['memberSha256']
    envelope = gzip.decompress(data)
    assert sha(envelope) == row['uncompressedSha256']
    header,body = decode_object_member(data)
    assert transform_blocks(header+body) == envelope
    lower = body.lower()
    hits = [{'role':role,'active':active,'practiceStem':needle.decode('ascii')}
            for role,active,needle in needles if needle in lower]
    rows.append({'declaredFile':row['declaredFile'],'member':row['member'],
                 'memberSha256':sha(data),'headerHex':header.hex(),
                 'mode':int.from_bytes(header[4:6],'little'), 'bodyBytes':len(body),
                 'bodySha256':sha(body),'roundTripToInflatedEnvelope':True,
                 'exactNewPracticeStemByteHits':hits})

sources = []
for address in [0x6d7560,0x79bce0,0x7d0920,0x7cbee0,0x7cbf70,0x7cc000,0x716eb0,0x733ea0]:
    p = ROOT/'anal-multi/kr-bulk-roy'/target/'functions'/f'0x{address:x}.c'
    sources.append({'address':hex(address),'sha256':sha(p.read_bytes())})
out = {'schema':'OBJECT_ENVELOPE_TRANSFORM_BOUNDARY_V1_NOT_NATIVE_MEF',
       'authority':'BOUNDED_NATIVE_TRANSFORM_AND_FINITE_OPAQUE_BODY_AUDIT_NOT_MESH_PARSE',
       'targetSha256':target,'dependencyReportSha256':sha(prior_raw),
       'decoderSha256':sha((here/'decode_object_envelope.py').read_bytes()),
       'windows':windows,'bulkSources':sources,
       'preflightScope':{'fixedTableAddress':'00F882E8','entryCount':27,
                         'tablePointerBytesSha256':sha(pe.read(0xf882e8,27*4)),
                         'instructions':[{'address':hex(i.address),'text':i.mnemonic+' '+i.op_str} for i in preflight_scope]},
       'correctionToPriorScope':'6D7560 applies its suffix fallback while checking a fixed27-entry resource list, not a proven general EFF loader. Prior availability hashes remain valid.',
       'pathBoundary':'79BCE0 constructs a same-path/same-stem EMF name when manager+300 is enabled and714550 original lookup returns0; direct caller7D0920 also references7CBEE0/7CBF70. Hidden-register/return ABI and complete caller branches remain outside this transform audit.',
       'transform':'7CC000 uses WORD+4:0/2 XOR128bytes at+8;1/2 XOR128bytes at end-128, then passes body+8/length-8 to862450.733EA0 expands32seed bytes to128 using byte(seed[i%32]*i) and XORs32groups of4bytes.',
       'summary':{'members':len(rows),'modeCounts':dict(collections.Counter(r['mode'] for r in rows)),
                  'newPracticeStemsChecked':len(needles),'membersWithExactPracticeStemHits':sum(bool(r['exactNewPracticeStemByteHits']) for r in rows)},
       'rows':rows,
       'limits':['Only421 already referenced object members; no archive inventory/MEF search repeated.',
                 'Opaque payloads are not claimed to be standard NIF or successfully parsed geometry.',
                 'Exact stem byte hits, if any, are not a skill/motion dispatch relationship; absence does not rule out indirect/numeric links.',
                 'Only modes0/1/2 and minimum136bytes supported; no unobserved-format compatibility claim.',
                 'No native game execution, attachment, model export, Client/Server gameplay change or full-function FULL-PASS.']}
dest = here/'object-envelope-transform-boundary-v1.json'
dest.write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
print(json.dumps({'summary':out['summary'],'sha256':sha(dest.read_bytes())}))
