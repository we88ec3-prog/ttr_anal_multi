"""Exact path candidates from original FCS records and finite STPD indexes; no game execution."""
from pathlib import Path, PurePosixPath
from datetime import datetime, timezone
import hashlib, json, platform, runpy
H=Path(__file__).resolve().parent;R=H.parents[2];E=H/'evidence'
sha=lambda b:hashlib.sha256(b).hexdigest()
read=lambda p:json.loads(p.read_text(encoding='utf-8-sig'))
def save(p,v):p.write_text(json.dumps(v,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
def norm(p):return p.replace('\\','/').casefold()
join=read(E/'town-fcs-logical-key-join-v1.json');mo3=read(E/'town-fcs-mo3-record-review-v2.json');prior=read(E/'town-fld-dependency-candidates-v1.json');zone=read(E/'town-zone-dependency-candidates-v2.json')
raw=(R/'fcs.flu').read_bytes();assert sha(raw)==join['source_sha256']==mo3['source_sha256']
api=runpy.run_path(str(H/'inspect_town_resources.py'))
needed=['Map/Object/Gb3.stp','Map/Object/MapEffect.stp','Map/Object/Mo3.stp']
expected={x['module']:x['source_sha256'] for x in prior['archives']}
expected.update({x['module']:x['source_sha256'] for x in zone['observed']})
archives=[];index={};payloads={}
for name in needed:
    r,d,f,b=api['archive'](R/name);assert sha(r)==expected[name]
    archives.append({'path':name,'sha256':sha(r),'member_count':len(f)})
    for member,ident in f.items():
        full=str(PurePosixPath(name).parent/member)
        index.setdefault(norm(full),[]).append({'archive':name,'member':member,'block_id':ident,'block':list(b[ident]),'virtual_root_assumption':'archive parent directory + full internal member path'})
    payloads[name]=(d,b)

def verify_record(row):
    off=row['source_offset'];b=raw[off:off+0x218];assert len(b)==0x218 and sha(b)==row['record_sha256']
    for at,end,key in [(0,0x10,'category_name'),(0x10,0x114,'text_at_0x10'),(0x114,0x218,'text_at_0x114')]:
        assert b[at:end].split(b'\0',1)[0].decode('ascii')==row[key]
    return row['text_at_0x10']+row['text_at_0x114']
rows=[];digests={}
for doc in join['observed']:
    assert sha((E/doc['document']).read_bytes())==doc['sha256']
    for item in doc['cache_items']:
        records=item['matched_fcs_records']
        if not records and item['fld_cache_name'].lower().endswith('.mo3'):
            records=[x for x in mo3['observed'] if x['text_at_0x114'].lower()==item['fld_cache_name'].lower()]
        row={'document':doc['document'],'fld_cache_name':item['fld_cache_name'],'record_paths':[]}
        for rec in records:
            virtual=verify_record(rec)
            is_gb3=virtual.lower().endswith('.gb3')
            candidate=virtual[:-4]+'.emf' if is_gb3 else virtual
            found=index.get(norm(candidate),[])
            checked=[]
            for x in found:
                key=(x['archive'],x['member'])
                if key not in digests:
                    d,b=payloads[x['archive']];p,packed=api['read_member'](d,b,x['block_id'])
                    digests[key]={'decoded_sha256':sha(p),'decoded_bytes':len(p),'packed_sha256':packed,'first16_hex':p[:16].hex(),'meaning':'Container payload bytes only; no model parsing or successful load acceptance'}
                checked.append(x|digests[key])
            row['record_paths'].append({'record_index':rec['record_index'],'source_offset':rec['source_offset'],'record_sha256':rec['record_sha256'],'fcs_virtual_path':virtual,'virtual_path_exact_index_matches':index.get(norm(virtual),[]),'candidate_path':candidate,'candidate_rule':'Conditional gb3->emf suffix from separately saved native helper; actual activation not proved' if is_gb3 else 'Exact original MO3 filename; dedicated native consumer not accepted','full_path_casefold_index_matches':checked,'virtual_loose_file_exists':(R/virtual.replace('\\','/')).is_file(),'candidate_loose_file_exists':(R/candidate.replace('\\','/')).is_file()})
        rows.append(row)
summary={}
for doc in join['observed']:
    selected=[x for x in rows if x['document']==doc['document']]
    summary[doc['document']]={'cache_names':len(selected),'with_fcs_record':sum(bool(x['record_paths']) for x in selected),'with_full_candidate_path':sum(any(y['full_path_casefold_index_matches'] for y in x['record_paths']) for x in selected),'without_full_candidate_path':[x['fld_cache_name'] for x in selected if not any(y['full_path_casefold_index_matches'] for y in x['record_paths'])]}
now=datetime.now(timezone.utc).isoformat()
v={'id':'T06-roy-exact-fcs-archive-path-join-v1','status':'待整合','at':now,'source_sha256':sha(raw),'module':'fcs.flu / two FLD documents / three STPD archives','address_range':'FCS source offsets and STPD block IDs per row','tool_version':'Python '+platform.python_version()+'; source-bound resource join; native helper references retained REA6.5/Ghidra12.1.4','input_evidence':[{'path':'evidence/'+p.name,'sha256':sha(p.read_bytes())} for p in [E/'town-fcs-logical-key-join-v1.json',E/'town-fcs-mo3-record-review-v2.json',E/'town-fld-dependency-candidates-v1.json',E/'town-zone-dependency-candidates-v2.json',E/'resource-suffix-phase9-review-v1.json']],'archives':archives,'summary':summary,'rows':rows,'observed':'Exact source record bytes and full directory/filename candidates compared with freshly decoded finite STPD indexes, with matching selected payload hashes.','inference':'Full-path candidate availability narrows resource absence questions; it does not establish archive mount rules or runtime selection.','conditions':['Same sourceFCS/archive/FLD hashes as recorded; casefold comparison and separator normalization only.','Archive-parent + member path is an analyst namespace candidate, not newly accepted engine mount semantics.','For.gb3 use.emf only under separately observed native fallback conditions, not unconditional conversion.'],'limitations':['MO3 dedicated native consumer and archive mount reachability remain unverified.','No recursive texture/animation dependency closure, successful model parsing, collision/spawn or town transition acceptance.','NormalTown1/2 to Map182/183 pairing and T07 scene/reset/ready sequence still incomplete.','No game launch/attach, targetAPI, packet, source resource or server modification.']}
save(E/'town-fcs-exact-archive-path-join-v1.json',v)
with (H/'findings.jsonl').open('a',encoding='utf-8') as f:f.write(json.dumps(v|{'rows':'See evidence/town-fcs-exact-archive-path-join-v1.json'},ensure_ascii=False)+'\n')
c=read(H/'changes.json');c['pending'].append('town-fcs-exact-archive-path-join-v1.json: full directory/name candidates and selected payload hashes pending; namespace and conditional suffix reachability not accepted');c['updated_at']=now;save(H/'changes.json',c)
p=read(H/'progress.json');p.update(updated_at=now,active_tool='None; finite archive path join complete',running_jobs=[],next_action='Review exact-path join result for any unmatched two-town cache entries. Preserve archive mount and MO3consumer as unknown; do not expand unrelated graphics. T07 scene lifecycle, backend mapping and T04/T09spawn remain dependencies; user testingv2 not yet reported.');p['last_resource_query']={'review':'evidence/town-fcs-exact-archive-path-join-v1.json','saved':True};save(H/'progress.json',p)
with (H/'CHECKPOINT.md').open('a',encoding='utf-8') as f:f.write('\n## 兩村完整FCS候選路徑核對 '+now+'\n前goal turn為progress（修復PE映像拒絕並提供v2）；本輪核對FCS原始recordbytes、兩份FLD SHA及三封裝SHA，fresh解析有限STPD indexes，保存town-fcs-exact-archive-path-join-v1.json，摘要 '+json.dumps(summary,ensure_ascii=False)+'。選定payload hashes同檔，未反覆保存大快照。\n這是完整路徑候選而非僅stem；archive-parent+member仍標分析者namespace假設，.gb3轉.emf具條件，不宣稱已載入。MO3consumer/mount、texture遞迴、兩村官方配對／spawn／T07順序與runtime未證。新成果待整合；正式170artifact/13claim/1correction不變。最後Python索引／原始byte查詢已保存，無執行中工具，未啟動遊戲。\n下一次先檢查JSON summary unmatched項目；若已全有候選，就不要把「有候選」擴張成可玩，回到兩村切城所缺場景介面與backendmapping的分工依賴。v2尚待使用者實測，不自行發包或啟動。\n')
print(json.dumps({'summary':summary,'unique_payloads':len(digests),'output':'evidence/town-fcs-exact-archive-path-join-v1.json'}))
