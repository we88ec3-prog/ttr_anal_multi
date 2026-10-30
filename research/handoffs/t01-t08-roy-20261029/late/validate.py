from read_sources import *
def run():
    proposal=json.loads((D/'proposal.json').read_text(encoding='utf8'))
    intake=json.loads((R/'research/intake/index.json').read_text(encoding='utf8'))
    canon=json.loads((R/'research/claims/index.json').read_text(encoding='utf8'))
    cr=canon.get('items',canon.get('claims'));ci={x['id']:x for x in cr}
    groups={x['key']:x for x in proposal['groups']};assert len(groups)==25
    assert all(k.startswith('late-') for k in groups)
    assert all(x['evidence_level'] in ['PARTIAL','UNKNOWN','REFUTED'] and not x['quality_inheritance'] for x in groups.values())
    assert proposal['source_count']==proposal['processed']==48 and proposal['remaining']==0 and proposal['new_full_pass']==0
    allowed={158:'CLM-CLIENT-0001',177:'CLM-CLIENT-0002',197:'CLM-CLIENT-0003'}
    seen=set();levels={}
    for s in proposal['sources']:
        n=s['number'];assert n not in seen;seen.add(n)
        raw=(R/s['source_file']).read_bytes();assert hashlib.sha256(raw).hexdigest()==s['source_sha256'];assert hashlib.sha1(b'blob '+str(len(raw)).encode()+b'\0'+raw).hexdigest()==s['source_blob_sha']
        assert s['narrative_read'] and not s['new_native_verification'] and not s['new_document_full_pass'] and not s['code_blocks_native_reviewed_this_intake']
        assert s['client_version']=='kr' and len(s['target_sha256'])==64
        assert s['bounded_observation'] and s['disposition'] and s['unknowns']
        if n in allowed:
            assert s['claim_keys']==[] and s['existing_claim_ids']==[allowed[n]]
            item=next(i for i in intake['items'] if i['source_file']==s['source_file'])
            assert item['integration_status']=='CONFLICT_CHECKED' and item['claim_ids']==s['existing_claim_ids']
            assert ci[allowed[n]]['evidence_level']=='NATIVE_VERIFIED' and ci[allowed[n]]['source_blob_sha']==s['source_blob_sha']
        else:
            assert s['claim_keys'] and not s['existing_claim_ids']
            for link in s['claim_links']:
                assert link['claim_key'] in groups
                lo,hi=link['source_lines'];lines=raw.decode('utf8').splitlines();assert 1<=lo<=hi<=len(lines)
                assert link['observation'] and link['line_excerpts']
                for x in link['line_excerpts']:assert lines[x['line']-1]==x['text']
    assert seen==set(range(153,201))
    for g in groups.values():
        levels[g['evidence_level']]=levels.get(g['evidence_level'],0)+1
        assert g['supporting_sources'] and g['limitations'] and 'affected_spec_ids' in g and g['spec_mapping'].startswith('unknown')
    # Exact known-history navigation must remain present; this validator does not adjudicate semantics.
    byn={s['number']:s for s in proposal['sources']}
    for n,k in {153:'refuted-erase-argument-role',155:'refuted-erase-window',157:'refuted-erase-argument-role',173:'refuted-variable-mode-writer',183:'refuted-tree-label',187:'refuted-wrapper-coordinate',196:'refuted-secondary-tree-conflation'}.items():assert 'late-'+k in byn[n]['claim_keys']
    assert any('lower-bound-only' in x for x in byn[200]['conflict_disposition'])
    result=dict(status='PASS',meaning='Identity, schema, citations and anti-promotion checks only; no native semantics newly certified.',source_versions=48,remaining=0,existing_canonical_links_preserved=3,new_extractions=45,groups=len(groups),group_levels=levels,new_document_full_pass=0,rea_calls=0)
    (D/'validation.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8');print(json.dumps(result,ensure_ascii=False))
if __name__=='__main__':run()
