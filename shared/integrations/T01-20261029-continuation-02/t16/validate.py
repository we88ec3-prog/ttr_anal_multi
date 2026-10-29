from verify import *
def validate():
    a=json.loads((D/'source-block-instruction-audit.json').read_text(encoding='utf8'))
    n=json.loads((D/'native-evidence.json').read_text(encoding='utf8'))
    d=json.loads((D/'decisions.json').read_text(encoding='utf8'))
    c=json.loads((D/'claim-matrix.json').read_text(encoding='utf8'))
    blocks=json.loads((D/'code-block-matrix.json').read_text(encoding='utf8'))
    t=json.loads((D/'pe-data-and-imports.json').read_text(encoding='utf8'))
    failures=[];count=0
    for report in a['reports']:
        q=next(x for x in Q if x['number']==report['number']);b=(R/q['source']).read_bytes()
        assert hashlib.sha256(b).hexdigest()==q['sha256']
        assert hashlib.sha1(b'blob '+str(len(b)).encode()+b'\0'+b).hexdigest()==q['git_blob_sha']
        for row in report['instruction_rows']:
            count+=1;va=int(row['va'],16);raw=audit.data(va,len(bytes.fromhex(row['bytes'])))
            assert raw.hex(' ')==row['bytes']
            assert row['rooted_instruction_boundary']
            assert row['explicit_bytes_equal'] is not False
            ins=next(audit.md.disasm(audit.data(va,15),va,count=1))
            equal=normalize(row['source'])==normalize(f'{ins.mnemonic} {ins.op_str}')
            assert row['normalized_instruction_equal']==equal
            if not equal:failures.append((q['number'],row['line'],row['va']))
    assert failures==[(70,116,'0x807bdd'),(71,36,'0x806958'),(71,134,'0x807dad')]
    assert count==379 and len(blocks['blocks'])==20 and len(c['claims'])==41
    assert len(n['functions'])==30
    assert all(not x['cfg']['overlaps'] and not x['cfg']['external_tail_branches'] for x in n['functions'].values())
    for k,v in n['functions'].items():
        fresh=audit.cfg(int(k,16));assert fresh==v['cfg']
    assert audit.offset(0xc51748)==0x84fd48
    assert t['vtable']['entries'][3:6]==['0x8068b0','0x8069a0','0x806a00']
    for va,hexbytes in [(0x80620c,'8d8e1c500000'),(0x806234,'8dbe1c500000'),(0x807bd8,'ba33260000'),(0x80695a,'33c0'),(0x807dab,'8bf8'),(0x807dad,'e8eec2ffff')]:
        assert audit.data(va,len(bytes.fromhex(hexbytes)))==bytes.fromhex(hexbytes)
    assert d['source_reviews_complete']==3 and d['original_document_full_pass']==0
    assert all(not r['original_document_full_pass'] and r['all_code_blocks_reviewed'] and r['full_text_read'] for r in d['reports'])
    # Assurance against test-only acceptance: native byte/CFG assertions do not set semantic verdicts.
    result=dict(status='PASS',meaning='Reproduction and audit consistency passed; expected original-source errors remain, no original promoted.',source_versions=3,whole_source_full_pass=0,claim_groups=41,code_blocks=20,instruction_rows=379,expected_instruction_mismatches=failures,functions=30,target_sha256=audit.H)
    audit.save(D/'validation-result.json',result);print(json.dumps(result,ensure_ascii=False))
if __name__=='__main__':validate()
