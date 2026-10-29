from audit import *
out=R/'shared/integrations/T01-20261029-semantic-review/t08-early'
pre=json.loads((out/'preflight.json').read_text(encoding='utf-8'))
report=[]
for x in pre:
    if not x['mismatches']:continue
    rows=[]
    for e in x['mismatches']:
        va=int(e['va'],16);b=bytes.fromhex(e['expected']);shifted=data(va-0x400,len(b));rows.append(e|dict(affine_candidate_va=hex(va-0x400),affine_candidate_raw=hex(offset(va-0x400)),affine_candidate_bytes=shifted.hex(' '),affine_candidate_equal=shifted==b))
    report.append(dict(source=x['source'],git_blob_sha=x['git_blob_sha'],sha256=x['sha256'],number=x['number'],declared_va_failures=len(rows),minus_400_matches=sum(e['affine_candidate_equal'] for e in rows),rows=rows,decision='FAILED_SOURCE_MAPPING',scope='The original claimed PE/code VA attribution is disproven. This rejects the source version; it does not certify its other semantic claims or an automatic rewritten version. Raw file spans can match despite false VA labels; .rdata absolute pointers and immediate operands must not be shifted.',repair='Provide a separate corrected source version identifying actual PE VA for each code range, direct-call endpoint and branch; retain original SHA. Re-decode complete CFG and recheck vtable/ABI and source identity. T01 supplies this per-row map as a correction proposal, not a blanket rebase.'))
save(out/'mapping-findings.json',dict(target_sha256=H,sections=sections,reports=report))
print([(x['number'],x['declared_va_failures'],x['minus_400_matches']) for x in report])
for a in [0x7a8310,0x7a8e10,0x4ca660,0x7a3920,0x7a4c50,0x7a63c0]:
    print(hex(a),[(hex(i.address),i.mnemonic,i.op_str) for i in md.disasm(data(a,24),a)])
