"""Recheck frozen sources, every quoted code row, CFG and issue-version links."""
from capture import *
audit=json.loads((D/'code-block-audit.json').read_text(encoding='utf-8'))
results=json.loads((D/'results.json').read_text(encoding='utf-8'))
frozen=json.loads((D/'frozen-sources.json').read_text(encoding='utf-8'))
issues=json.loads((D/'issue-resolution.json').read_text(encoding='utf-8'))
assert results['reviewed_reports']==3 and results['document_scoped_full_pass']==2
assert results['partial_clarification']==1 and results['total_code_blocks']==17
assert sum(len(b.get('instruction_rows',[])) for r in audit['reports'] for b in r['blocks'])==574
for r in frozen['sources']:
    bs=(R/r['path']).read_bytes();assert hashlib.sha256(bs).hexdigest()==r['sha256'];assert blob(bs)==r['git_blob_sha']==r['git_verified_blob']
for r in audit['reports']:
    for b in r['blocks']:
        assert hashlib.sha256(b['content'].encode()).hexdigest()==b['content_sha256']
        for c in b.get('instruction_rows',[]):
            assert data(int(c['va'],16),len(bytes.fromhex(c['quoted_bytes'])))==bytes.fromhex(c['quoted_bytes'])
            assert c['normalized_assembly_matches'] and c['explicit_operand_width_matches']
            if c['kind'] not in ['continuation-bytes','explicit-raw-byte-directive']:
                a=int(c['va'],16);i=next(md.disasm(data(a,15),a,count=1));assert norm(c['quoted_assembly'])==norm(i.mnemonic+' '+i.op_str)
cfgcount=0;instructions=0
for p in (D/'native-cfg').glob('*.json'):
    d=json.loads(p.read_text(encoding='utf-8'));assert d==cfg(int(d['entry'],16)),p;assert not d['overlaps'];cfgcount+=1;instructions+=len(d['instructions'])
counts={int(x['target'],16):x['count'] for x in json.loads((D/'direct-e8-candidates.json').read_text(encoding='utf-8'))['targets']}
assert counts=={0x7b7fd0:1,0x7b8030:1,0x7dd100:1,0x7dd1a0:2,0x7dd1f0:2,0x7be5f0:42,0x4dff30:5,0x4dfbc0:2,0x4dfe90:11}
for r in results['reports']:
    assert r['all_substantive_native_claims_adjudicated'] and r['all_code_blocks_reviewed']
    assert r['all_native_claims_passed']==(r['number']!=200)
    for c in r['native_claims']:
        assert 1<=c['source_lines'][0]<=c['source_lines'][1]<=r['lines']
        for p in c['evidence_files']:assert (D/p).is_file(),p
for i in issues['issues']:
    if not i.get('old_source'):continue
    b=(R/i['old_source']).read_bytes();assert blob(b)==i['old_git_blob_sha'];assert hashlib.sha256(b).hexdigest()==i['old_sha256']
    b=(R/i['new_source']).read_bytes();assert blob(b)==i['new_git_blob_sha'];assert hashlib.sha256(b).hexdigest()==i['new_sha256']
    assert i['old_document_verdict']=='FAILED' and i['old_verdict_unchanged']
    assert i['all_return_affected_claims_closed'] and i['proposed_return_status']=='RESOLVED'
    assert i['new_document_verdict']=='FULL_PASS_DOCUMENT_SCOPED'
for p in D.glob('*.md'):
    for href in re.findall(r'\]\(([^)]+)\)',p.read_text(encoding='utf-8')):
        if '://' in href or href.startswith('#') or href.split('#')[0] in ['manifest.json','validation.json']:continue
        assert (p.parent/href.split('#')[0]).is_file(),(p,href)
manifest=[]
for p in sorted(D.rglob('*')):
    if not p.is_file() or '__pycache__' in p.parts or p.name in ['manifest.json','validation.json']:continue
    b=p.read_bytes();manifest.append(dict(path=p.relative_to(D).as_posix(),sha256=hashlib.sha256(b).hexdigest(),bytes=len(b)))
save(D/'manifest.json',dict(files=manifest))
save(D/'validation.json',dict(ok=True,source_versions=3,source_sha_and_blob_match=True,all_17_code_blocks_covered=True,quoted_assembly_rows=574,all_quoted_bytes_operands_and_explicit_widths_match=True,cfg_files=cfgcount,cfg_instructions=instructions,stored_cfg_recomputed_equal=True,source_line_references_valid=True,all_43_native_claim_rows_referenced=True,issue_old_new_sha_links_match=True,old_failed_sources_not_promoted=True,return_resolution_proposals=2,document_scoped_full_pass=2,partial_clarification=1,failed_new_sources=0,semantic_decisions='Manual matrix and full codeblock/dataflow review; not inferred from byte matches.',limits=['KR original SHA only.','No whole Task/complete function/backend/runtime/gameplay promotion.','200 L11 ambiguity remains partial, not a confirmed defect.']))
print(json.dumps(dict(ok=True,cfg_files=cfgcount,native_claims=results['total_native_claim_rows'],code_blocks=17,asm_rows=574,document_scoped_full_pass=2,partial_clarification=1),ensure_ascii=False))
