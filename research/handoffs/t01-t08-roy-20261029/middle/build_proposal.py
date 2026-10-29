"""R0/R1 intake only. Manual content-derived links; hashes never confer semantics."""
import json,pathlib,hashlib,re,collections
D=pathlib.Path(__file__).resolve().parent;R=D.parents[3]
TARGET='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
base=json.loads((D.parent/'sources.json').read_text(encoding='utf-8'))
src=[q for q in base['sources'] if q['scope']=='middle'];assert len(src)==48
mapping_path='shared/integrations/T01-20261029-semantic-review/t08-early/mapping-reviews.json'
mapping={q['source']:q for q in json.loads((R/mapping_path).read_text(encoding='utf-8'))['reviews']}
# Unique functional groups, not a new claim per manuscript. These statements
# deliberately distinguish research reports from facts adopted by T01/S00.
groups=[
 ('bucket-storage','PARTIAL','來源研究將全域22桶的配置、插入、count讀取與內嵌owner消費分開；僅可作Client容器來源導航，不能從相同stride推得同一實例或Server entity規則。','15個直接xref不是alias/間接引用完備證明；count重設不是entry釋放；索引有效範圍與每幀頻率未確證。'),
 ('callback-slot-boundary','PARTIAL','callback配置/註冊、callback+04空方法候選與+0C分桶方法是不同調度職責；entry本身的+0C又屬另一型別，整合時保留三者區隔。','取自來源有界研究，未新做R3；不同this及動態vptr不可互換；129-resolved的閉合主張受既有FAILED限制。'),
 ('callback-owner-gap','UNKNOWN','真正dispatcher到callback owner實參的精確PE座標鏈仍需依修正版確認；早期明示未知與129後稿聲稱已解分別保留。','129-static未找到caller不是不存在證明；129-resolved已因座標/derived boundary退回，不能拿其已解敘述覆蓋未知或當規範依據。'),
 ('core-interface','PARTIAL','來源區分manager handle、配置核心、callback與manager+EC介面，並將EC建構參數來源和幾何/dispatch虛槽作有限研究導航。','C++類名、具體虛方法、handle地址與handle內容均不可混同；不據此認定場景主更新或渲染Server契約。'),
 ('plane-buffer','PARTIAL','來源先記錄0x60/24-float幾何係數初始化與讀取，118/119後稿提出非初始化writer及平面生成數學，120明示為歷史缺口的後續研究。','僅按來源萃取，沒有新原生品質認證；不是camera/視錐類型證明；stack矩陣拷貝不是heap writer；法線單位長與具體owner未知。'),
 ('update-schedule-gap','UNKNOWN','兩條幾何更新入口與participant回呼職責有研究線索，真正外層觸發、頻率及與場景更新之關聯未確證。','不能把float參數、相鄰call或once初始化guard當逐幀/固定FPS/同一主迴圈。'),
 ('b-queue-causality-gap','UNKNOWN','B佇列排序/前N執行與22桶派送的時間順序，不能直接當entry execute造成入桶的資料因果鏈；此橋接仍是S00具體阻塞時才需R2的問題。','涉及129-resolved及130..152的肯定座標推論均被隔離；不得由相鄰執行順序推出Server生成、刪除或事件順序。'),
 ('b-entry-score-gap','UNKNOWN','B entry具體型別、其+04執行/+08浮點評分目標與分數語意仍需同一物件來源鏈；不採距離/相機/畫面優先級命名。','原稿排序候選/partial_sort只是演算法形態；資料表DWORD不能單憑值確定動態類別；146/149/152的入口中段反證受錯誤text映射影響，已撤出有效反證。'),
 ('b-writer-scope-gap','UNKNOWN','137..140的局部writer未找到與141..144聲稱找到Host+0C append屬來源研究進展；在精確PE修正版複驗前只能導航producer、guard、grow/alias問題。','局部位移搜尋不是無writer證明；不得自動接受後稿已確認措辭或全量平移其code/data；是否還有其他producer、實際grow與邊界仍未解。'),
 ('record-vector-owner-gap','UNKNOWN','按名稱登記record+20、A-array及group子陣列的append不可因共用helper誤認成B queue producer；修正映射後仍需按實參owner確證此區隔。','133..135原版本FAILED，所述具體地址和ABI不作規範來源；名稱記錄是否間接觸發B、record完整壽命及計數業務意義未知。'),
 ('host-lifetime-gap','UNKNOWN','候選Host建構、embedded vptr、holder/control pair與兩階段release研究尚未連到同一B entry的入列/執行/析構時序；沒有UAF或安全存活保證結論。','145..152原版本FAILED；shared/weak-like是推論而非STL符號；同offset不是同一Host，B內未見retain不證明全域無保護。'),
 ('coordinate-repair','UNKNOWN','既有T01精確映射裁決已指出129-resolved及130..152的來源座標問題；舊flat文字區與PE相差0x400須逐點更正，資料/vtable絕對值保持其自身節區解讀。','只引用既有24份來源版本裁決，沒有新native驗證；7A8310/7A8E10等有效PE入口不能再被舊錯位反解排除；不全量平移data/vtables，不翻改歷史FAILED。')
]
G={k:dict(key='middle-'+k,assertion=a,evidence_level=e,limits=[l,'R1研究導航；不升NATIVE_VERIFIED、不改歷史全文審核、不直接形成Server wire/data契約。'],conflicts=[],affected_spec_ids=[],server_impact='Client scheduling/geometry/container navigation only; no existing entity/rendering Server SPEC asserted by this intake.') for k,e,a,l in groups}
# Every range below was read in the actual narrative, not inferred from name.
# Tuples: canonical functional group keys, precise source line ranges, note.
M={
106:('bucket-storage plane-buffer',[(12,12),(33,33),(132,146),(196,196),(243,245),(270,277)],'manager+98是否alias全域在此稿仍未知；直接xref/初始化不等於完整consumer或正常writer。'),
107:('bucket-storage callback-owner-gap',[(26,28),(42,42),(59,65),(79,83),(113,117)],'caller實值producer alias與診斷count reader分離；owner/全域consumer仍未知。'),
108:('bucket-storage core-interface plane-buffer callback-owner-gap',[(34,36),(70,72),(102,102),(130,133)],'manager+8係數alias與分桶owner是不同來源；調度虛槽語意未解析。'),
109:('callback-slot-boundary core-interface',[(6,6),(21,23),(30,30)],'callback配置/參與者集合及vtable slot分開；真正+0C caller未驗。'),
110:('core-interface',[(7,7),(29,29),(42,42)],'manager+EC取得介面研究；不能與場景vtable或具體graphics class混同。'),
111:('bucket-storage callback-owner-gap',[(7,7),(25,25),(35,35)],'count清零不等於槽清零/物件free；owner仍由caller提供。'),
112:('plane-buffer core-interface callback-owner-gap',[(7,7),(23,23),(35,39),(49,49)],'初始化、manager+8讀者、非初始化writer缺口分開，動態方案未執行。'),
113:('callback-slot-boundary core-interface',[(22,22),(30,33),(46,46),(60,62)],'+04與+0C不同；manager地址不是直接桶heap。'),
114:('core-interface',[(20,20),(41,41),(60,60),(74,78)],'核心0x470與callback4-byte不同配置；EC建構參數/容器語意保守。'),
115:('callback-slot-boundary bucket-storage callback-owner-gap',[(28,28),(55,59),(73,77)],'四個stage不是完整集合，count reset不推出free；排除callback+04作consumer caller。'),
116:('plane-buffer callback-owner-gap',[(23,23),(42,48),(62,64)],'初始化/free、heap讀取與stack矩陣copy區隔；當時writer未找到。'),
117:('callback-slot-boundary callback-owner-gap',[(7,7),(27,27),(38,38),(47,47)],'slot/type不可混同；runtime owner identity明示未確認。'),
118:('plane-buffer',[(7,7),(35,35),(75,75)],'後稿提出非初始化writer補早稿缺口；時間增量與相機視錐仍暫定。'),
119:('plane-buffer',[(7,7),(23,23),(44,44),(70,70)],'矩陣stack copy、平面運算與測試分開；camera owner與單位法線未知。'),
120:('plane-buffer update-schedule-gap callback-owner-gap',[(7,7),(23,23),(59,62)],'118 writer是研究進展，不把兩入口直接叫每幀或同一場景主更新。'),
121:('callback-slot-boundary callback-owner-gap',[(10,10),(31,31),(45,45),(62,64)],'註冊不等於實際消費；未知+0C dispatcher與owner保留。'),
122:('bucket-storage callback-owner-gap',[(10,10),(71,74),(88,90)],'22桶配置/free與producer分離；合法index全面保證及consumer未知。'),
123:('update-schedule-gap plane-buffer',[(10,10),(40,43),(58,61)],'有guard的多階段不是全線性必經；float參數不證明FPS。'),
124:('update-schedule-gap plane-buffer callback-owner-gap',[(10,10),(45,48),(62,71)],'第二入口的陣列/初始化不同；不再次搜尋118已提出的writer。'),
125:('callback-slot-boundary callback-owner-gap',[(8,8),(40,42),(54,57)],'原稿提出5F5D10單ret；接受作研究線索，動態vptr前提及owner缺口保留。'),
126:('bucket-storage',[(8,8),(55,55),(64,69)],'15 direct uses局部普查與固定桶10enqueue，不能證明alias consumer不存在。'),
127:('bucket-storage callback-owner-gap',[(50,52),(64,67)],'22 count reset屬caller owner，不能直接當global週期清零/thread-safe。'),
128:('callback-owner-gap callback-slot-boundary bucket-storage',[(8,12),(35,35),(50,56)],'靜態未閉合owner；動態斷點僅計畫，沒有執行授權或結果。'),
130:('b-queue-causality-gap b-writer-scope-gap coordinate-repair',[(8,10),(218,218),(247,247),(253,259)],'排除FAILED原稿的嚴格順序/ABI肯定結論；僅保留需重建不同容器與caller時序的研究問題。'),
131:('b-entry-score-gap b-queue-causality-gap b-writer-scope-gap coordinate-repair',[(136,136),(252,252),(275,283)],'partial_sort是候選；B writer、entry score、owner壽命與22桶因果未解，正向座標結論隔離。'),
132:('record-vector-owner-gap b-writer-scope-gap b-queue-causality-gap coordinate-repair',[(83,83),(111,111),(122,124),(145,153)],'第二caller完整owner身分未閉合，A append不能充B；所有具體flat地址需修稿。'),
133:('record-vector-owner-gap coordinate-repair',[(12,12),(148,148),(160,163)],'record+20與B排除主張不升原生；保留名稱記錄到B的間接生成/壽命缺口。'),
134:('record-vector-owner-gap coordinate-repair',[(10,10),(80,80),(150,152),(161,161)],'source計數意義未知，子容器+4/+14不是B+ B4；需精確PE重證。'),
135:('record-vector-owner-gap b-writer-scope-gap coordinate-repair',[(10,10),(98,100),(154,160)],'共用append helper的EDI owner實參需分開；局部搜尋不能否定B writer。'),
136:('b-queue-causality-gap host-lifetime-gap coordinate-repair',[(189,189),(192,198),(201,201)],'0長helper不直接證明安全/free；先後不等資料流，entry/vptr與writer仍缺。'),
137:('b-writer-scope-gap coordinate-repair',[(12,14),(77,81)],'局部區段固定offset陰性結果不是producer不存在；FAILED座標保留不採。'),
138:('b-entry-score-gap coordinate-repair',[(12,12),(64,66),(84,88)],'manager/entry/callback不是同一型別的研究警示；入口中段疑點受flat映射反證撤出，肯定地址/型別結論不採。'),
139:('b-entry-score-gap b-queue-causality-gap coordinate-repair',[(96,98),(142,142),(157,161)],'比較與執行slot分離只作研究問題；分數方向/距離及每次非空未證。'),
140:('b-queue-causality-gap b-entry-score-gap b-writer-scope-gap coordinate-repair',[(12,12),(79,82),(86,96)],'明示未知entry/append/因果及未執行動態方案；不接受矩陣已確認欄位作native。'),
141:('b-writer-scope-gap b-entry-score-gap coordinate-repair',[(11,13),(91,93)],'141提出後續writer但原版FAILED；保留未知entry/到22桶缺口，不憑新時間戳蓋過限制。'),
142:('b-writer-scope-gap host-lifetime-gap coordinate-repair',[(202,205),(219,219)],'guard/虛slot語意、上游頻率及+0C壽命待修正版；不按offset認Host。'),
143:('b-writer-scope-gap coordinate-repair',[(11,11),(102,110)],'vector形態只是推論，grow實際容量/其他producer未知；舊指令座標不採。'),
144:('b-queue-causality-gap b-entry-score-gap coordinate-repair',[(11,11),(103,109)],'後稿聲稱producer閉合不能越過FAILED；B score/execute→22桶明示未知可導航。'),
145:('host-lifetime-gap b-entry-score-gap coordinate-repair',[(11,11),(59,63),(79,79)],'Host候選仍缺構造到producer ECX實例鏈；不把同offset當同型別。'),
146:('b-entry-score-gap coordinate-repair',[(11,11),(46,46),(94,94)],'rdata不可套text flat；但以錯位code說7A8310/7A8E10非入口已被T01反證，排除此negative。'),
147:('host-lifetime-gap coordinate-repair',[(46,46),(68,70),(83,83)],'raw embedded pointer未見retain不是UAF；保留同實例retain/release/移除/時序缺口。'),
148:('b-entry-score-gap b-queue-causality-gap host-lifetime-gap coordinate-repair',[(27,33),(35,45),(49,53)],'具體ECX→constructor鏈、vptr及execute→22桶未閉合；動態方案未執行。'),
149:('host-lifetime-gap b-entry-score-gap coordinate-repair',[(63,63),(91,103),(145,148),(160,162)],'ABI強反證來自錯誤text映射，不採為方法無效證明；pattern零xref不證不可達。'),
150:('host-lifetime-gap b-entry-score-gap b-queue-causality-gap coordinate-repair',[(14,16),(121,121),(167,167),(189,193),(222,226)],'holder pair/control與embedded entry不同；shared/weak只是推論，舊ABI反證隔離。'),
151:('host-lifetime-gap b-entry-score-gap coordinate-repair',[(13,17),(39,39),(76,78),(169,169),(209,211),(257,270)],'雙計數/conditional release研究需修映射後驗；不能據slot值說無效入口或已確證destroy/free。'),
152:('b-entry-score-gap b-queue-causality-gap host-lifetime-gap coordinate-repair',[(12,16),(90,90),(113,124)],'保留raw搜尋非完備、無runtime/UAF及因果鏈限制；排除錯位code的非法入口結論。')}
out=[]
for q in src:
    p=R/q['source_file'];raw=p.read_bytes();lines=raw.decode('utf-8-sig').splitlines()
    assert hashlib.sha256(raw).hexdigest()==q['source_sha256']
    assert hashlib.sha1(b'blob '+str(len(raw)).encode()+b'\0'+raw).hexdigest()==q['source_blob_sha']
    n=int(re.search(r'T08-(\d+)',p.name)[1]);old=mapping.get(q['source_file'])
    if n==129:
        if 'static-audit' in p.name:ks,rs,note=('callback-owner-gap callback-slot-boundary',[(28,28),(41,41),(54,54),(67,72),(89,93)],'129同號早稿明示未解；與resolved後稿保留不同來源版本，不能以後稿聲稱覆寫。')
        else:ks,rs,note=('callback-owner-gap b-queue-causality-gap coordinate-repair',[(9,11),(140,140),(145,148),(154,156)],'129同號後稿聲稱已解，但此精確blob已FAILED；owner closure不採為規範事實，僅記其runtime/頻率/entry語意未解。')
    else:ks,rs,note=M[n]
    keys=['middle-'+k for k in ks.split()]
    excerpts=[]
    for a,b in rs:
        assert 1<=a<=b<=len(lines)
        excerpts.append(dict(start=a,end=b,text='\n'.join(lines[a-1:b])))
    conflict=[]
    if old:
        assert old['git_blob_sha']==q['source_blob_sha'] and old['sha256']==q['source_sha256']
        conflict=[dict(kind='EXISTING_FAILED_EXACT_SOURCE',decision_file=mapping_path,source_blob_sha=q['source_blob_sha'],historical_verdict=old['review_state'],return_id=old['return_id'],disposition='Exclude asserted native address attribution/derived call-boundary/ABI claims. Use only explicit gaps and source-history navigation; no automatic remap or quality upgrade.',repair='Per verified code span correct PE coordinates and recompute CFG/call targets. Preserve rdata absolute values and data/vtables; require separate corrected version.')]
        for k in ks.split():G[k]['conflicts'].append(q['source_file'])
    elif n in range(106,129) or n==129:
        conflict=[dict(kind='LIMITED_RESEARCH_NOT_FULL_DOCUMENT_ACCEPTANCE',disposition='Source affirmative wording remains attributed PARTIAL research; no new native verification. Early unknowns preserved as dated research, not timeless absence claims.')]
    out.append(dict(source_file=q['source_file'],source_blob_sha=q['source_blob_sha'],source_sha256=q['source_sha256'],source_intake_id=q['source_intake_id'],client_version='kr',target_sha256=TARGET,claim_keys=keys,source_lines=excerpts,observations=note,disposition='UNKNOWN_ONLY_GAP_NAVIGATION; EXCLUDE_REFUTED_COORDINATE_AND_DERIVED_POSITIVES' if old else 'PARTIAL_RESEARCH_OR_EXPLICIT_UNKNOWN_ONLY; NO_NATIVE_UPGRADE',conflicts=conflict,historical_verdict_preserved='FAILED' if old else q['historical_status'],risk='R2_COORDINATE_REPAIR_REQUIRED' if old else 'R1_BOUNDED_RESEARCH',workflow='CONFLICT_CHECKED_PROPOSAL',new_native_verification=False))
assert len(out)==48 and sum(s['historical_verdict_preserved']=='FAILED' for s in out)==24
for g in G.values():
    g['limitations']=g.pop('limits')
    g['conflicts']=[dict(kind='EXACT_FAILED_SOURCE_EXCLUDED',sources=g['conflicts'],decision_file=mapping_path)] if g['conflicts'] else []
    g['source_count']=sum(g['key'] in s['claim_keys'] for s in out)
    assert g['source_count']
proposal=dict(schema='t01-t08-roy-middle-r0-r1-proposal-v1',base_main=base['base_main'],source_head=base['source_head'],scope='T08-106..152 including two distinct129 versions',mode='R0/R1_ONLY',read_method='Actual narrative read by reviewer, including causal/unknown/revision qualifications; selected exact line excerpts linked manually. ASM/pseudocode blocks not re-certified.',summary=dict(sources=48,narratives_read=48,uncompleted_sources=0,canonical_groups=len(G),historical_failed_sources_quarantined=24,new_native_verified_claims=0,new_full_document_passes=0),groups=list(G.values()),sources=out,deduplication=dict(method='Exact functional boundary, owner provenance, buffer and version; repeated source references share canonical keys.',existing_claim_index='research/claims/index.json',existing_native_claims_reused=[],note='No existing bucket/plane/B-entry canonical item found in current claim index; no new Task-classified formal verified knowledge created.'),r2_stop=dict(reason='Identity, bounded use and known conflicts recorded. Stop R1; do not expand native analysis.',open_questions=['Exact corrected-PE source version for129-resolved and130..152','Concrete B entry constructor→producer→execute/score identity and22bucket causal edge','Same-instance Host holder/entry lifetime protection','Outer geometry update triggers/frequency andscene relationship'],prohibited_shortcuts=['No all-program -0x400 shift','No data/vtable pointer shifting','No FAILED→PARTIAL/FULL_PASS historical overwrite','No runtime breakpoint execution from a proposed plan','No zero-xref→unreachable inference']),affected_spec_policy='No existing Server specification directly governs these Client geometry/render scheduling details; affected_spec_ids left empty rather than inventing a contract. S00 may request a concrete R2 blocker later.')
D.mkdir(parents=True,exist_ok=True)
(D/'proposal.json').write_text(json.dumps(proposal,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
print(json.dumps(proposal['summary'],ensure_ascii=False))
