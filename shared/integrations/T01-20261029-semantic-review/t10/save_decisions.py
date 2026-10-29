import json,pathlib,hashlib,re
D=pathlib.Path(__file__).resolve().parent
p=json.loads((D/'preflight.json').read_text(encoding='utf-8'))
passes={
53:[('literal census','Seven complete FB9004 literal occurrences, original .text raw→VA and reader/zero-store classifications.','semantic-anchors.json:literal_positions.0xfb9004; cfg/006d4a30.json; cfg/006d4ce0.json')],
55:[('special-key clear','Special ID10001..19999 path searches FDF630, checks sentinel FDF634 and writes node+10 byte zero; distinct from ordinary indexed storage.','cfg/006d4a30.json; semantic-anchors.json:6D4C2F/6D4CAE')],
56:[('reader callsites','Two direct E8 byte candidates to6D4CE0 independently rescanned; both valid calls within5961C0; nearby virtual offsets EC/F0 read from caller-specific receivers, identity unknown.','semantic-anchors.json:direct_E8_byte_candidates.0x6d4ce0; cfg/005961c0.json')],
58:[('command loop','EBX starts0 and ESI28; postincrement signed ESI<38 loop gives28..37; phase1 and globalFBA798==0 gate construct WORD68 plus counter+1 and indirect+10 dispatch.','semantic-anchors.json:548918..5489B3; cfg/005961c0.json is unrelated; exact source quoted rows in preflight.json')],
59:[('state and mask','Local unsigned elapsed>500 branch and state2/3/4→mask08/80/40 are distinct from three source OR and priority-selected byte. No Z/V naming is admitted.','semantic-anchors.json:547308/54730D/5467B8/5467BD/5467C5; cfg/00546780.json')],
64:[('guarded reader','Special unsigned range uses keyed tree byte, non-special ordinary index<=39 readsFB9004+ESI; remaining paths return zero. Zero has multiple local causes.','cfg/006d4ce0.json')],
65:[('reader consumer','Ordinary getter call reaches phase-specific polymorphic callbacks after global/local ID gates; receiver provenance remains unknown. No direct actor motion write claimed.','cfg/005961c0.json')],
67:[('command gate','Conditional command68 payload and vptr+10 receiver come from FBA854 only when FBA798==0; postincrement loop limit is not attack-stage count.','semantic-anchors.json:54898D/548992/5489B0/5489B3; preflight.json exact quoted source rows')],
97:[('result node','Phase callback success feeds caller result container;74D700 allocates12 bytes, installs two links and DWORD event ID at+8; caller checks count capacity then links new node. Allocation failure throws and is not success.','cfg/005961c0.json; cfg/0074d700.json'),('scope separation','This list is downstream of phase reading/callback, not phase producer; no motion/attack queue identity is asserted or established.','cfg/005961c0.json; source explicit unknowns')],
98:[('selector predicate','761010 requires owner+68 nonzero, traverses owner+64 links, returns node+8 only for !bit19 && bit8 && !bit12; no match returnsNULL.','cfg/00761010.json'),('listener bucket','596140 receives owner inEAX and key inEDI, looks up owner+80; phase1/3 dispatch EC/F0 on node+8 receivers, first nonzeroAL returns1; exhaustion/miss returns0.','cfg/00596140.json')],
99:[('literal scan','All18 raw4-byte FB73E8 occurrences and VA mapping independently rescanned; literal positions are not function entries.','semantic-anchors.json:literal_positions.0xfb73e8'),('zero writer','560239 storesEBX initialized zero at560197; intervening native path retainsEBX under normal callee-preserved ABI, no direct local write1 established. Alias/nonzero writers remain unknown.','cfg/00560170.json; semantic-anchors.json:560197/560239')],
}
fails={7:('T01-RETURN-T10-007-001','5467F1 is pointer load; actual WORD store is5467F4; correct main dataflow retained.'),26:('T01-RETURN-T10-026-001','549D54 belongs independent549C60, not549980; function boundary/caller attribution false.'),62:('T01-RETURN-T10-062-001','First reset branch clears ordinary40bytes before the optional6D1DA0 initialization call, contrary to the stated initialize-then-clear order.'),63:('T01-RETURN-T10-063-001','Clear path at6D4CAE has no ESI<=27 guard; reader guard cannot be transferred to writer.')}
gapnums={16,20,24,28,32,40,48,52,60,68,80,88,96,100}
rows=[]
for x in p['rows']:
    n=x['number'];rebase='-REBASE-' in x['source']
    row={k:x[k] for k in ['source','sha256','git_blob_sha','task','number','historical_review_references']}
    row.update(reviewer='Codex T01 / review_t10',date='2026-10-29 Asia/Taipei',original_binary_sha256=p['source_binary_sha256'],source_bytes_checked=True,byte_rows=len(x['asm_checks']),core_narrative_read=True,whole_function_or_gameplay_complete=False,source_whole_document_certified=False,all_affirmative_claims_reviewed=False)
    if not rebase and n in fails:
        rid,reason=fails[n];row.update(status='FAILED',all_affirmative_claims_reviewed=False,return_id=rid,decision=reason,scope='Original version is disproved by a decisive native counterexample; remaining affirmative claims not silently certified.',report='DECISIONS.md')
    elif not rebase and n in passes:
        row.update(status='PARTIAL',bounded_claim_review_state='FULL_PASS_FOR_LISTED_SCOPE_ONLY',decision='Only the explicitly conditioned positive native claims listed below pass; source whole-document approval is NOT granted, and original unknowns/candidate language retained.',claims=[dict(id=f'T10-{n:03d}-C{i+1}',topic=a,assertion=b,evidence=c,verdict='FULL_PASS',source_document_full_pass=False) for i,(a,b,c) in enumerate(passes[n])],conditions=['Only original KR SHA and normal-return/caller-validity conditions in cited instructions.','Raw literal/E8 enumerations are bounded byte facts, not global alias or callgraph completeness.','Function names and gameplay labels remain tentative where source explicitly says so.'])
    elif not rebase and n in gapnums:
        row.update(status='PARTIAL',all_affirmative_claims_reviewed=False,decision='Boundary/gap narrative read. Its positive referenced native subclaims still require complete per-source claim matrix and pseudocode/callee closure; no automatic FULL_PASS from cited earlier drafts.')
    else:
        row.update(status='PARTIAL',all_affirmative_claims_reviewed=False,decision='All quoted native byte rows checked and core narrative read; full remaining positive assertions, pseudocode, type/vtable/callee boundaries are not all certified in this checkpoint.')
    source=pathlib.Path('E:/Tartaros/workspace/t01-integration-20261029')/x['source']
    text=source.read_text(encoding='utf-8-sig')
    blocks=[]
    for i,m in enumerate(re.finditer(r'```([^\n]*)\n(.*?)```',text,re.S),1):
        blocks.append(dict(index=i,language=m[1].strip(),start_line=text[:m.start()].count('\n')+1,end_line=text[:m.end()].count('\n')+1,content_sha256=hashlib.sha256(m[2].encode('utf-8')).hexdigest(),whole_block_semantics_certified=False,next_step='Check all instruction boundaries, actual operands and every positive pseudocode/dataflow assertion; use cited CFG where already present.'))
    row['codeblocks_pending_full_semantic_signoff']=blocks
    row['next_steps']=['Complete a line-referenced matrix of every substantive affirmative claim, including all codeblocks listed here; the narrative view is not sufficient.','For each positive claim close relevant CFG, caller/callee, register/stack/value-flow and type/vtable boundaries; preserve source-declared unknowns.','Resolve any applicable return item with a separate corrected-source SHA/blob and revalidate affected claims; do not mark original failed version FULL_PASS.']
    if n in {53,55,56} and not rebase:row['specific_boundary_followup']='Quoted windows include mid-instruction/invalid-start decoder fragments (examples548950,6D4BBF/6D4D40,596440 respectively). Source caveats must be evaluated against each affirmative ASM claim; this checkpoint certifies neither those fragments nor the complete appendix.'
    rows.append(row)
counts={s:sum(x['status']==s for x in rows) for s in sorted({x['status'] for x in rows})}
out=dict(schema='t01-source-semantic-decisions-v2',base_commit='a4d58fd21dd40cfd5cc645a829e52e59b23cecaa',review_complete=False,stop_reason='User explicitly requested stage closure; no further sources expanded.',source_count=len(rows),counts=counts,source_whole_document_certified_count=0,bounded_full_pass_claim_count=sum(len(r.get('claims',[])) for r in rows),sources_with_bounded_full_pass_claims=sum(bool(r.get('claims')) for r in rows),notes=['Stage closure: 98-source assignment remains incomplete.','FULL_PASS is only each precise conditioned claim; it does not certify the source document, all code/functions/gameplay or promote historical sources.','FAILED is original-source rejection supported by a decisive counterexample, not proof every other statement was audited.'],rows=rows)
(D/'decisions.json').write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
print(json.dumps(counts))
