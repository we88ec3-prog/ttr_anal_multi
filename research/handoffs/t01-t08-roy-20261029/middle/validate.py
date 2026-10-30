"""Mechanical identity/link validator only; never grants semantic acceptance."""
import pathlib,json,hashlib,collections
D=pathlib.Path(__file__).resolve().parent;R=D.parents[3]
p=json.loads((D/'proposal.json').read_text(encoding='utf-8'))
inventory=json.loads((D.parent/'sources.json').read_text(encoding='utf-8'))
expected={q['source_file']:q for q in inventory['sources'] if q['scope']=='middle'}
assert len(p['sources'])==len(expected)==48
assert set(s['source_file'] for s in p['sources'])==set(expected)
groups={g['key']:g for g in p['groups']};assert len(groups)==len(p['groups'])==12
assert all(k.startswith('middle-') for k in groups)
assert all(g['evidence_level'] in ['PARTIAL','UNKNOWN'] for g in groups.values())
linked=collections.Counter();failed=0;excerpts=0
for s in p['sources']:
    q=expected[s['source_file']];raw=(R/s['source_file']).read_bytes();lines=raw.decode('utf-8-sig').splitlines()
    assert s['source_blob_sha']==q['source_blob_sha']==hashlib.sha1(b'blob '+str(len(raw)).encode()+b'\0'+raw).hexdigest()
    assert s['source_sha256']==q['source_sha256']==hashlib.sha256(raw).hexdigest()
    assert s['claim_keys'] and all(k in groups for k in s['claim_keys'])
    linked.update(s['claim_keys'])
    assert s['disposition'] and s['observations'] and s['source_lines']
    for x in s['source_lines']:
        assert x['text']=='\n'.join(lines[x['start']-1:x['end']]);excerpts+=1
    if s['historical_verdict_preserved']=='FAILED':
        failed+=1
        assert all(groups[k]['evidence_level']=='UNKNOWN' for k in s['claim_keys'])
        assert s['disposition'].startswith('UNKNOWN_ONLY')
        assert any(c['kind']=='EXISTING_FAILED_EXACT_SOURCE' for c in s['conflicts'])
    assert not s['new_native_verification']
assert failed==24 and set(linked)==set(groups)
assert all(g['source_count']==linked[g['key']] for g in p['groups'])
result=dict(status='PASS',meaning='R0 identities, exact narrative excerpts, links, scope and FAILED quarantine only; not semantic verification.',sources=48,unfinished=0,groups=12,failed_sources_quarantined=24,new_native_verified=0,new_full_document_pass=0,source_excerpt_ranges=excerpts,evidence_levels=dict(collections.Counter(g['evidence_level'] for g in groups.values())))
(D/'validation.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
print(json.dumps(result,ensure_ascii=False))
