"""Persist manual source/version-scoped decisions, without changing source files."""
from capture import *
audit=json.loads((D/'code-block-audit.json').read_text(encoding='utf-8'))
frozen=json.loads((D/'frozen-sources.json').read_text(encoding='utf-8'))
CLAIMS={
177:[
([5,5],'Original KR binary SHA identity independently matches.','P177-A',[0x7b7fd0]),
([8,8],'.text VA/raw/virtual-size mapping is section-specific and matches original PE.','P177-A',[0x7b7fd0]),
([13,13],'Mode entry7B7FD0 and ret4 are valid;7B7FA0 lies within prior7B7F30 immediate bytes.','P177-A',[0x7b7fd0,0x7b7f30]),
([14,14],'ECX constant1 dominates payload+44 store and is unchanged through its loop; caller-dependent value claim is corrected.','P177-B',[0x7b7fd0]),
([15,15],'First collection slot+4 callbacks precede second collection payload+44=1; both normal exits set container+30=1.','P177-B',[0x7b7fd0]),
([16,16],'Disable drains each second-collection payload before clearing+44, then first-collection slot+8 callbacks, then container+30=0.','P177-B',[0x7b8030,0x7dd1f0]),
([17,17],'One raw E8 site per mode target; both actual caller roots push literal addressFE173C, not loaded slot value.','P177-C',[0x7aad40,0x7ab020,0x7b7fd0,0x7b8030]),
([18,18],'Drain has precisely two raw E8 candidates, tied to mode disable and zero manager count; indirect/tail/external exclusions retained.','P177-C',[0x7b8030,0x7dd100]),
([19,19],'ECX->ESI manager decrement uses+5C; only zero triggers drain/+44clear/name-array cleanup.','P177-D',[0x7dd100,0x7dc510]),
([20,20],'Signed mode44>=1 locks+64 and appends; otherwise nonnull item cleanup/free; mode is not established as reference count.','P177-E',[0x7dd1a0,0x7bb350,0x7bd850,0x89120c]),
([21,21],'ESI drain ABI, valid caller owner values and normal end=begin path; zero third transfer argument.','P177-F',[0x7dd1f0,0x7b8030,0x7dd100]),
([29,37],'All nine raw E8 candidate sets, counts and listed byte values match independent exhaustive section scan.','P177-C',[]),
([41,47],'All seven rel32 examples recompute their exact stated targets.','P177-C',[]),
([53,65],'Both mode-flow diagrams match full roots, callback/write ordering and literal global-address argument.','P177-B',[0x7aad40,0x7ab020,0x7b7fd0,0x7b8030]),
([67,67],'First-collection dereference levels and distinct container/payload offsets are preserved; no cross-type field identity inferred.','P177-B',[0x7b7fd0]),
([71,80],'Producer/drain diagram matches signed gate, caller push order, two drain sites, lock/append/process/end-reset normal paths.','P177-E',[0x7a86b0,0x7be5f0,0x7dd1a0,0x7dd1f0]),
([82,82],'Release inputESI is pointer-slot; resource and dereferenced owner are passed in correct two stack-argument order; callee ret8.','P177-E',[0x7be5f0,0x7a86b0,0x7dd1a0]),
([86,86],'Count-result caller skips destruction for nonzero; zero branch drains/clears/names, returns reloaded count, without unique-lifetime claim.','P177-D',[0x7b8090,0x7dd100,0x7dc510,0x7dcf40,0x7b8680]),
([90,90],'Same owner+64 lock address reaches imported Enter/LeaveCriticalSection on normal path.','P177-F',[0x7dd1f0]),
([91,91],'Initial length is(end-begin)>>2; loop refreshes begin/end rather than a fixed-size snapshot.','P177-F',[0x7dd1f0]),
([92,92],'Each slot VALUE is pushed to precleanup, then slot reread gates cleanup/free/zeroing; no universal nonnull/reentrancy claim.','P177-F',[0x7dd1f0,0x7be0f0,0x7bd850,0x89120c]),
([93,93],'Tail EAX-EAX subtraction yields zero length; normal returning callee preserves EBX; stored end equals begin.','P177-F',[0x7dd1f0]),
([94,94],'Drain body has no direct frame/time-counter reads; does not exclude indirect callbacks or prove frame schedule.','P177-F',[0x7dd1f0]),
([98,98],'Actor add/remove/bulk-clear direct candidate sets differ and their complete bodies have no direct drain call.','P177-G',[0x4dff30,0x4dfbc0,0x4dfe90]),
([99,100],'Specific component release calls provide bounded bridge, not actor/resource/manager owner equality or server-policy recovery.','P177-G',[0x4c7db0,0x4c8360,0x7be5f0]),
([106,111],'Summary repeats already closed entry/constant/address/count/candidate/zero-length facts.','P177-H',[0x7b7fd0,0x7b8030,0x7dd100,0x7dd1f0]),
([112,124],'Inference, unknown indirect/writer/ownership/thread/frame/backend statements are explicitly unasserted and remain unknown.','P177-H',[]),
([128,128],'Arbitrary caller windows are expressly not claimed as function entries; actual roots independently supplied.','P177-H',[0x7aad40,0x7ab020,0x7b8090,0x7a86b0]),
([519,560],'All42 appendix raw E8 byte candidates and their exact target arithmetic match the independent full-section candidate set.','P177-C',[])],
197:[
([4,5],'Original KR SHA and .text VA/raw mapping match independent source/PE checks.','P197-A',[0x4dfc30]),
([11,11],'Secondary container address is ESI-owner+18, sentinel+1C;8438C0 signed exact find differs from main unsigned82EF00.','P197-A',[0x4dfc30,0x8438c0,0x82ef00]),
([12,12],'Nonnull owner+F8 cache is cleared only when its pointed first DWORD equals the input key.','P197-B',[0x4dfc30]),
([13,13],'Nonnull secondary node+10 payload is directly heap-freed then node-erased; no actor virtual+14/+0 calls in this path.','P197-B',[0x4dfc30,0x89120c,0x7b6890]),
([14,14],'Main owner+8/C tree is traversed by4DFC90, payload+88 predicate gates virtual precleanup/deletion/erase.','P197-C',[0x4dfc90,0x7b6890,0x49e6a0]),
([18,18],'Offsets and static vslots do not prove dynamic payload class or unique indirect call target.','P197-C',[0x4dfc30,0x4dfc90]),
([22,22],'The two paths have different payload release ABIs, as directly shown by virtual versus direct-free operations.','P197-C',[0x4dfc30,0x4dfc90]),
([28,34],'Stated native window facts are supported; shared ownership, complete destructor strategies, runtime/server remain explicitly incomplete.','P197-C',[0x4dfc30,0x4dfc90])],
200:[
([4,5],'Original KR SHA and .text VA/raw mapping match independent source/PE checks.','P200-A',[0x4dff30]),
([11,11],'Actor+4 WORD is zero-extended for key; actor+88 is a different predicate. The phrase not-same-index is ambiguous between key domain and container.','P200-A',[0x4dff30,0x4dfc90]),
([12,12],'Exact-find equality tail makes non-sentinel an exact key match; absent branch invokes real node construction/linking/balancing insert.','P200-B',[0x4dff30,0x82ef00,0x57ef20,0x82f200,0x44bd00]),
([13,13],'Duplicate branch formats a warning via6EDB60 with key/format and has no direct replacement-actor allocation/free.','P200-C',[0x4dff30,0x6edb60,0x6ed980]),
([14,14],'Main key removal uses the same exact-find key interface; new actor ownership for duplicates is not inferred.','P200-D',[0x4dfbc0,0x82ef00]),
([18,34],'Other dynamic payload/alias/destructor/runtime/server limits remain unasserted; same offsets do not merge owners.','P200-D',[0x4dff30,0x4dfbc0,0x4dfc30])]
}
BLOCK_SUMMARIES={177:[
'Mode enable/disable dataflow diagram: actual literal address push, first/second collection traversal, callback offsets and mode writes.',
'Two producers/two consumers diagram: signed gate, lock/append/immediate destruction, ESI drain and end reset.',
'Complete enable root: first virtual loop, constant1 second loop, both return paths and stack cleanup.',
'Complete disable root: drain before gate clear, separate callback loop, mode0 and ret4.',
'Caller window in7AAD40: lazy initialization context, literal global-address push and mode call; truncated last MOV is completed from raw target.',
'Caller window in7AB020: init context and literal push to disable; tail truncated PUSH is completed from raw target.',
'Complete manager decrement root: flags from add-1, zero-only drain/clear/names loop, count return, SEH normal epilogue.',
'Complete producer root: signed mode, same lock, vector append ABI, immediate null test and cleanup/free, ret8.',
'Complete drain root: ESI ABI, per-slot value argument, conditional cleanup/free, refreshed bounds, zero transfer length and end reset.',
'Caller window in7B8090: sentinel/no-entry, manager payload, count test, conditional destruction, index erase.',
'Caller window in7A86B0: resource owner+60 decrement,74/78 gates, resource/owner push order, immediate release branch.',
'Release root window: pointer-slot ESI, null return, owner dereference,60 decrement,74/78 producer gate, immediate precleanup/destruction. Full root supplies omitted tail.'],
197:['Complete secondary key-removal root:18/1C lookup, cache comparison, nonnull direct-free and iterator erase, padding separated.','Complete main predicate-removal root:8/C traversal,88 DWORD predicate, virtual calls, iterator output and nonmatching successor.'],
200:['Complete registration-root window:WORD key, exact find, absent insert, duplicate warning; explicit tail byte directives interpreted as raw excerpt.','Complete main key-removal root:sentinel guard, three controller slots, virtual object cleanup then iterator/node erase.','Complete secondary key-removal root:18/1C, cache, direct-free then erase, long-instruction continuation and padding separated.']}
reports=[]
for r in audit['reports']:
    num=r['number'];matrix=[]
    for k,(lines,text,sec,roots) in enumerate(CLAIMS[num],1):
        ambiguous=num==200 and lines==[11,11]
        matrix.append(dict(id=f'T08-{num}-FULL-C{k:02}',source_lines=lines,claim=text,verdict='PARTIAL_CLARIFICATION' if ambiguous else 'PASS_DOCUMENT_STATED_SCOPE',manual_evidence_section=sec,evidence_files=[f'native-cfg/{a:08x}.json' for a in roots],scope='Exact authored native assertion and explicitly preserved limits; not whole-function/runtime/server completion.'))
    blocks=[]
    for b,summary in zip(r['blocks'],BLOCK_SUMMARIES[num],strict=True):
        blocks.append(dict(id=b['id'],source_lines=[b['fence_start'],b['fence_end']],content_sha256=b['content_sha256'],language=b['language'],semantic_summary=summary,verdict='PASS_AS_AUTHORED_BOUNDED_CODE_OR_FLOW_WINDOW',all_rows_reviewed=True,raw_byte_and_operand_record='code-block-audit.json',unasserted='Dynamic target identity, exception/concurrency/runtime guarantees stay unknown when the source says unknown.'))
    reports.append(dict(number=num,source=r['source'],source_sha256=r['source_sha256'],git_blob_sha=r['git_blob_sha'],lines=r['line_count'],verdict='PARTIAL_CLARIFICATION' if num==200 else 'FULL_PASS_DOCUMENT_SCOPED',all_substantive_native_claims_adjudicated=True,all_native_claims_passed=num!=200,all_code_blocks_reviewed=True,all_quoted_code_rows_reviewed=True,native_claims=matrix,code_blocks=blocks,native_task_complete=False,whole_function_semantic_complete=False,reviewer='Codex T01 / review_t08_new',review_date='2026-10-29 Asia/Taipei',metadata_scope='Author research dates, past tool actions, no-push-at-authoring and research-round history remain historical self-reports rather than native behavioral acceptance.',limits=['Original KR SHA only.','Author-declared unknowns remain unknown; no gameplay or official backend acceptance.','Native facts concern valid-object/container invariants and stated normal-return paths; no new full exception or concurrent mutation guarantee.']))
save(D/'results.json',dict(schema='t01-full-source-semantic-review-v2',base_commit=frozen['base_commit'],target_sha256=H,assigned_reports=3,reviewed_reports=3,document_scoped_full_pass=2,partial_clarification=1,failed_new_sources=0,total_native_claim_rows=sum(len(r['native_claims']) for r in reports),total_code_blocks=sum(len(r['code_blocks']) for r in reports),reports=reports))
def oldrow(n):
    q=json.loads((OLD/'assigned-sources.json').read_text(encoding='utf-8'));return next(r for r in q['rows'] if r['number']==n)
def newrow(n):return next(r for r in reports if r['number']==n)
issues=[]
for oldn,newn,scope,closed in [
(173,177,'Constant1 source, valid function entry, all affected+44 enable/disable writes and ordering, signed gate versus count, caller input/provenance and replacement code window.',[
'173 variable/caller-ECX writer replaced by177 L14 constant1 dominator and complete enable CFG.',
'173 bad7B7FA0 entry replaced by177 L13 and code block3 actual7B7FD0 root; old bad excerpt preserved with oldFAILED blob.',
'Both zero-writer paths and gate ordering verified through full7B8030/7DD100/7DD1A0/F0 roots, not just one write.',
'Other writers/global type/universal lifetime remain explicitly unknown, rather than inherited caller-dependent claim.']),
(196,197,'Main versus secondary container base/sentinel, LEA address, matching predicate, virtual versus direct-free payload cleanup, iterator relation and unsupported double-tree shared-actor premise.',[
'197 L11-13 and block1 bind secondary path4DFC30 toESI+18/1C and direct payload-free.',
'197 L14 and block2 bind4DFC90 toEAX-owner+8/C, payload+88 predicate, virtual precleanup/deletion and iterator erase.',
'The erroneous oldLEA/load/different-tree premise is not inherited; exact instructions are supplied in new blocks.',
'197 L29 explicitly leaves whether two containers share objects unknown; no new double-free or synchronization guarantee is asserted.'])]:
    old=oldrow(oldn);new=newrow(newn)
    issues.append(dict(id=f'T01-RETURN-T08-{oldn}-001',old_source=old['source'],old_git_blob_sha=old['git_blob_sha'],old_sha256=old['sha256'],old_document_verdict='FAILED',old_verdict_unchanged=True,new_source=new['source'],new_git_blob_sha=new['git_blob_sha'],new_sha256=new['source_sha256'],new_document_verdict=new['verdict'],affected_scope=scope,all_return_affected_claims_closed=True,closure_evidence=closed,proposed_return_status='RESOLVED',resolution_scope='The fixed issue is resolved by independently revalidated later author source; this does not change the old source version to FULL_PASS.',require_republication_of_identical_bytes=False,request_basis='User requested continuation and revalidation of existing corrective source versions; parent integrator will apply README return-status update.'))
issues.append(dict(id='historical-T08-200-lower-bound-only-rejection',proposed_return_status='WITHDRAWN_UNCHANGED',reason='82EF00 tail verifies key equality; old rejection remains invalid.',current_source=newrow(200)['source'],git_blob_sha=newrow(200)['git_blob_sha'],independent_open_item='L11 index word has key-domain/container ambiguity; PARTIAL_CLARIFICATION only, not a proven source error or revival of old rejection.'))
save(D/'issue-resolution.json',dict(target_sha256=H,issues=issues,original_sources_rewritten=False,task_readme_changed=False,git_actions_performed=False))
save(D/'clarification-items.json',dict(items=[dict(source=newrow(200)['source'],git_blob_sha=newrow(200)['git_blob_sha'],source_lines=[11,11],status='PARTIAL_CLARIFICATION',confirmed_source_defect=False,create_needs_fix_return=False,wording='此欄位與 actor+0x88 複合ID比對不是同一索引',why='Could mean distinct key domains or distinct containers; context does not unambiguously assert different containers.',native_facts='4DFF56 and4DFC96 both compute owner+8 main-tree address; WORD actor+4 key and DWORD actor+88 predicate are distinct.',suggested_clarification='同一 owner+8 主樹；actor+4 的查找 key 與 actor+88 的篩選 predicate 不同。')]))
print(json.dumps(dict(full_pass=2,partial_clarification=1,native_claims=sum(len(r['native_claims']) for r in reports),blocks=sum(len(r['code_blocks']) for r in reports)),ensure_ascii=False))
