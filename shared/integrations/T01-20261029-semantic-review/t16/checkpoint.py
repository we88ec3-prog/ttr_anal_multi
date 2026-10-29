from decisions import *

write_decisions()
dec=json.loads((D/'decisions.json').read_text(encoding='utf8'))
pending=[x|{'whole_document_state':'NOT_CERTIFIED','bounded_state':'PENDING','next_work':('Prose read during checkpoint preparation; native assertions not finalized.' if 69<=x['number']<=78 else 'Requires full prose, fenced blocks, claim inventory and native semantic review.')} for x in Q if x['number'] not in DECISIONS]
audit.save(D/'pending-sources.json',dict(total=len(pending),whole_document_remaining=97,sources=pending))

proposals=[]
def proposal(ids,issue,counterevidence,correction,refs):
    for x in Q:
        if x['number'] in ids:
            proposals.append(x|dict(issue=issue,counterevidence=counterevidence,required_correction=correction,evidence=refs,original_document_full_pass=False,scope='Counterexample confirmed; supported independent claims survive. Remaining assertions are not automatically passed.'))

proposal([2], 'Native return polarity is inverted in conceptual pseudocode', '6F4A94 initializes ESI=1; absent resource reaches 6F4BCF and returns EAX=ESI. Normal parse success sets ESI=0.', 'Represent zero-success/nonzero-failure native status. Do not use false to represent missing-file return without an explicit inversion wrapper.', ['native-functions.json:6F4A50'])
proposal([5], 'Pseudocode advances the callback result instead of the original Shout node', 'ESI retains original node; virtual +14 result is EAX; next iteration reads [ESI+40]. Null callback result skips append.', 'Maintain original-node iterator separately from converted callback result and preserve null-result branch.', ['native-functions.json:53FEB0'])
proposal([13], 'Final signed tree inequality is reversed', '843901 cmp esi,[edx+C]; 843904 jl sentinel. ESI is search key. Lower-bound best >= key; absent key5 with candidate7 must return sentinel.', 'Return head if best==head or key<best.key. Preserve signed comparison and calling convention.', ['native-functions.json:8438D0'])
bad_hash_ids=[45,46,48,49,52,54,56,60,61,62,63,64,67,68]
proposal(bad_hash_ids, 'TutorialBase exact-source SHA is malformed (56 hex characters)', 'Claimed 26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744 is56 chars. Carrier-bound decoded member SHA256 is26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744,1416 bytes,6prototypes,72instructions.', 'Correct source identity and lookup path; distinguish historical connector404 from actual member absence. Do not treat previously inaccessible content as permanent missing evidence.', ['resource-recheck.json','lua/kr-TutorialBase.lua.json','resources.py','tables-and-xrefs.json'])
proposal([46], 'Lua CALL C=2 means one result, not two', 'KR TutorialMain prototype5 PC20/40/136 raw words0080801C/0100801C/0080801C have C=2. Lua5.1 VM computes nresults=GETARG_C(i)-1.', 'Correct all three return counts to1; preserve arguments B-1 and coroutine/local-only interpretation. Primary reference: https://www.lua.org/source/5.1/lvm.c.html#luaV_execute', ['lua/kr-TutorialMain.lua.json','resources.py'])
proposal([92], 'Four reported instruction coordinates are wrong', '62E5CD is push eax;62E5CE starts8D45C8 lea eax,[ebp-38].5B6CCF is8B5314 mov edx,[ebx+14];5B6CD0 is interior.62F70A is mov esi,[FB114C];62F706 lies inside instruction62F700.62E659 is push esi and call starts62E65A.', 'Repair coordinates and re-render complete rooted CFGs62E490/5B6BE0/62F640. Preserve supported owner-to-lookup/read relationship; no false unconditional-zero inference from truncated fallthrough.', ['instruction-source-audit.json','native-functions.json','checkpoint-critical-cfg.json'])
boundary_ids=[1,9,20,21,22,26,29,30,31,33,34,36,40,50,51,65]
for no in boundary_ids:
    proposal([no], 'Appendix window starts or resumes inside a different instruction', DECISIONS[no][1], 'Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.', ['instruction-boundary-candidates.json','native-functions.json','instruction-source-audit.json'])
audit.save(D/'return-proposals.json',dict(proposal_count=len(proposals),proposals=proposals))
critical=[audit.cfg(x) for x in [0x62e490,0x5b6be0,0x62f640]]
audit.save(D/'checkpoint-critical-cfg.json',dict(binary_sha256=audit.H,functions=critical,execution='Static decode only; target was never executed.'))
audit.save(D/'claim-matrix.json',dict(scope='Selected exact claims only; this is not an exhaustive whole-source matrix.',claims=[dict(source=p['source'],git_blob_sha=p['git_blob_sha'],claim=p['issue'],state='COUNTEREXAMPLE_CONFIRMED',native_evidence=p['counterevidence'],repair=p['required_correction'],evidence=p['evidence']) for p in proposals]))

counts=collections.Counter(x['review_state'] for x in dec['rows'])
readme='''# T16 semantic-review checkpoint — 2026-10-29

User requested a staged stop. Original source versions:97. Whole-source semantic certifications: **0**. All97 remain uncertified as whole documents. No original report is promoted by this checkpoint.

72 source versions have bounded findings:33 BOUNDED_FAILED,30 BOUNDED_SUPPORTED,9 SOURCE_ONLY. These states refer to selected exact claims and observed counterexamples, not complete report acceptance. Their prose was read; not every fenced code block, provenance assertion and affirmative claim has a completed claim-level audit. Accordingly every row explicitly sets original_document_full_pass=false and all_substantive_claims_reviewed=false.

25 source versions lack a finalized bounded decision (IDs69–92 including the second73 version). Prose69–78 was read but findings were not finalized;79–92 require continued review, except92 has a confirmed coordinate counterexample saved separately. Exact source paths, blob and SHA identities appear in pending-sources.json. All97 need exhaustive claim inventories and whole-source closure before whole-document certification.

Evidence: decisions.json contains bounded source findings; claim-matrix.json and return-proposals.json contain precise confirmed counterexamples and proposed corrections. instruction-source-audit.json checks11,916 explicit addressed ASM rows and finds3 byte mismatches in92; that does not prove instruction boundaries or semantics. native-functions.json saves109 candidate-root recursive static CFGs and cached Ghidra evidence (14,436 decoded instructions). Roots and pseudocode remain evidence requiring review. checkpoint-critical-cfg.json independently saves full rooted CFGs for92.

resources.py independently decodes14 KR/TC carrier members and statically parses Lua5.1 without execution; resource-recheck.json and lua/*.json preserve results. tables.py independently checks PE imports, selected vtables and raw E8 candidate sets. Exact target SHA256:9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91.

Key returns: Lua46 C=2 gives1 result;14 reports cite a malformed56-character TutorialBase SHA although the correct original carrier member is available;13 reverses signed tree equality test;5 conflates original iterator and callback result;2 inverts native return polarity;92 has four wrong instruction coordinates while its central owner/lookup relation survives.16 source versions contain mid-instruction appendix rows. Corrections should retain independently supported findings and explicit backend/gameplay unknowns.

Reproduction: Python with capstone5.0.6, review.py audit / cfg, resources.py, tables.py, checkpoint.py. Current helper import comes from E:/Tartaros/workspace/t01-work-20261029/audit.py and capstone vendor there; parent will package portability. Original game/carriers are read-only and were never executed, attached, modified or loaded as executable code. Parent handles integration; no commit/push was performed here.
'''
(D/'README.md').write_text(readme,encoding='utf8')
print(dict(counts=counts,pending=len(pending),returns=len(proposals),whole_certified=0))
