"""Finite dependency availability audit. No Client execution or mesh interpretation."""
from pathlib import Path
import collections, gzip, hashlib, json, sys

ROOT = Path(__file__).resolve().parents[4]
sys.path[:0] = [str(ROOT/'anal/python_deps'), str(ROOT/'anal')]
from stp_resources import Archive
from build_native_index import PE
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

sha = lambda b: hashlib.sha256(b).hexdigest()
here = Path(__file__).parent
target = '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
pe = PE(ROOT/'Tartaros.bin')
assert sha(pe.data) == target
assert pe.read(0xc40f60,5) == b'.gb3\0' and pe.read(0xc40f68,5) == b'.emf\0'
md = Cs(CS_ARCH_X86, CS_MODE_32)
decoded = list(md.disasm(pe.read(0x6d7560,0x200),0x6d7560))
selected = [i for i in decoded if 0x6d7672 <= i.address < 0x6d7702]
native = {'targetSha256': target, 'function': '006D7560',
          'selection': 'Whole instructions decoded from frozen function start; selected7672..7700',
          'windowSha256': sha(pe.read(0x6d7672,0x90)),
          'instructions': [{'address': hex(i.address), 'text': i.mnemonic+' '+i.op_str} for i in selected],
          'boundedConclusion': 'After714550 returns0, length>4 and case-insensitive .gb3 suffix succeeds, copies .emf over the suffix and retries714550.',
          'limits': 'No proof here that every EFF model lookup reaches this function or that714550 implements all archive/disk search rules.'}
source = ROOT/'anal-multi/kr-bulk-roy'/target/'functions/0x6d7560.c'
native['bulkSourceSha256'] = sha(source.read_bytes())
catalogue = json.loads((here/'action-preview-catalogue-v2.json').read_bytes())
prior_path = ROOT/'runtime-observations/2026-11-05-all-skills/numeric-family-explicit-link-audit.json'
prior_bytes = prior_path.read_bytes()
assert sha(prior_bytes) == catalogue['priorNumericAuditSha256']
prior = json.loads(prior_bytes)
effect_structures = {r['member']: r for r in prior['referencedEffectStructures']}
requested = collections.defaultdict(set)
for action in catalogue['entries']:
    for effect in action['effectReferences']:
        structure = effect_structures[effect['member']]
        for name in structure['declaredFiles']:
            requested[name].add(effect['member'])

relative = 'Effect/Object.stp'
original_path = ROOT.parent/'origin'/relative
working_path = ROOT/relative
original_raw, working_raw = original_path.read_bytes(), working_path.read_bytes()
assert original_raw == working_raw
original, working = Archive(original_path), Archive(working_path)
index = collections.defaultdict(list)
for member in original.files:
    index[member.replace('\\','/').rsplit('/',1)[-1].casefold()].append(member)
rows = []
for name, effects in sorted(requested.items()):
    basename = name.replace('\\','/').rsplit('/',1)[-1]
    suffix = Path(basename).suffix.lower()
    assert suffix in ('.gb3','.ptc')
    # A finite same-stem availability comparison, NOT proof of loader resolution.
    candidate = str(Path(basename).with_suffix('.emf')) if suffix == '.gb3' else basename
    matches = index[candidate.casefold()]
    assert len(matches) == 1, (name, matches)
    member = matches[0]
    data = original.read(member)
    assert data == working.read(member)
    row = {'declaredFile': name, 'referencingEffects': sorted(effects),
           'carrier': relative, 'member': member, 'memberSha256': sha(data),
           'originalWorkingEqual': True,
           'association': 'SAME_STEM_EMF_WITH_BOUNDED_GENERAL_FALLBACK_NOT_EFFECT_LOADER_CLOSURE' if suffix == '.gb3'
                          else 'EXACT_PTC_BASENAME_AVAILABILITY_NOT_LOADER_PROOF',
           'decodedArchiveMemberBytes': len(data)}
    if suffix == '.gb3':
        assert data[:2] == b'\x1f\x8b'
        decompressed = gzip.decompress(data)
        row.update({'gzipContainerValid': True, 'uncompressedBytes': len(decompressed),
                    'uncompressedSha256': sha(decompressed),
                    'payloadInterpretation': 'OPAQUE_NOT_A_MESH_OR_TEXTURE_PARSE'})
    rows.append(row)
out = {'schema': 'ACTION_OBJECT_DEPENDENCY_AVAILABILITY_BOUNDARY_V1',
       'authority': 'FINITE_ARCHIVE_MEMBER_IDENTITY_AND_GZIP_INTEGRITY_ONLY',
       'actionCatalogueSha256': sha((here/'action-preview-catalogue-v2.json').read_bytes()),
       'priorNumericAuditSha256': sha(prior_bytes),
       'boundedNativeFallback': native,
       'carrier': {'path': relative, 'originalWorkingSha256': sha(original_raw)},
       'summary': {'actions': len(catalogue['entries']),
                   'referencedEffectMembers': len({r for e in requested.values() for r in e}),
                   'uniqueDeclaredFiles': len(rows),
                   'gb3SameStemEmfCandidates': sum(r['declaredFile'].lower().endswith('.gb3') for r in rows),
                   'ptcExactBasenames': sum(r['declaredFile'].lower().endswith('.ptc') for r in rows)},
       'rows': rows,
       'limits': ['Only existing direct EFF declaredFiles referenced by the pinned294 actions; no whole archive/MEF rescan.',
                  'A general GB3-to-EMF suffix fallback is verified in one bounded function; complete EFF loader/path resolution is not established.',
                  'Gzip integrity does not decode/validate geometry, encryption, textures, nested dependencies or rendering.',
                  'This supplies no skill/motion assignment and does not prove all Client resources are present.',
                  'EMF object members are not evidence of native MEF AI/script contents.',
                  'Originals and Client unchanged; raw compressed/decompressed assets are not exported.']}
dest = here/'action-object-dependency-availability-v1.json'
dest.write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
print(json.dumps({'summary': out['summary'], 'sha256': sha(dest.read_bytes())}))
