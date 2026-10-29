"""Manual R1 narrative extraction for44 exact source versions, no native work."""
import pathlib,json,hashlib,collections
D=pathlib.Path(__file__).resolve().parent;R=D.parents[3]
inventory=json.loads((D.parent/'sources.json').read_text(encoding='utf-8'))
sources=[q for q in inventory['sources'] if q['scope']=='middle'];assert len(sources)==44
TARGET='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
HISTORY='shared/integrations/T01-20261029-semantic-review/t10/DECISIONS.md'
C02='shared/integrations/T01-20261029-continuation-02/t10/decisions.json'
defs=[
('mapping-query','PARTIAL','來源描述6D4DC0依兩參數選一般bank或特殊樹，將DWORD集合追加到caller輸出；與runtime byte reader或非零phase writer分開。','6D4DC0、6D43F0、FB8834/FDF3F4映射查詢的來源有限資料流。','E8候選數不是action row數/全可達caller；lookup-or-create不能寫成純唯讀；MapButton/特殊ID的完整行為不由查詢本身確定。'),
('mapping-format','PARTIAL','594610等來源將映射集合交594A80/594570組裝文字/資料；WORD矩陣索引與phase byte不是同一型別，不能直接當動作執行者。','594610及caller、formatter與×11/WORD矩陣的來源描述。','僅已描述的格式化分支，不宣稱所有6D4DC0 caller均UI；UI用途也不證設定保存、runtime動作或完整receiver。'),
('state-reader','PARTIAL','來源把6D4CE0的一般0..39 byte查詢、特殊10001..19999樹節點byte與查無/越界預設零區分；reader guard只屬該reader。','6D4CE0、FB9004、FDF630查詢與default return來源。','零回傳不必表示未收到按鍵；讀取guard不能搬到清零writer，值1/3不能逕稱press/release。'),
('state-clear','PARTIAL','初始化、bank切換、雙模式reset及list-indexed clear是不同零值寫入scope；可作清理路徑導航，不是找到非零事件producer。','6D0750/6D1A70/6D4A30及內部list loop的零值寫入來源子集。','062初始化順序及063 writer<=39 guard明確排除；mode/時機、list ID上游合法值域和事件語意未確證。'),
('literal-census','PARTIAL','來源的FB9004七個literal位置是有界直接參照盤點，需分清operand內常量位置與指令起點；負面搜尋不能證明無間接writer。','原稿7處FB9004 byte-pattern/直接xref分類。','不是完整CFG/alias覆蓋，不能把原始bytes一致當全文pass；053附錄邊界/泛稱已確認仍受continuation02限制。'),
('polymorphic-consumer','PARTIAL','來源把5961C0/59624E/59643F的byte reader結果與+EC/+F0多型判定/回呼分開；物件與this的fallback需依實際receiver理解。','5961C0一般/特殊ID迭代、phase1/3與多型slot來源描述。','沒有具體vptr/ctor和motion writer不命名AttackPress/Release/cancel；不同receiver相同slot不證同類別；056錯位視窗頭排除。'),
('command68','PARTIAL','548918家族依指定索引、byte==1及FBA798 gate構造局部command68並從FBA854 virtual+10派送；28..37是迴圈索引，非十段普攻。','548918/548957局部命令建構及派送前提的來源範圍。','真實receiver、client-only或network來源、actor transition/Server確認仍未知；不把局部命令當wire協定。'),
('state-flag-boundary','PARTIAL','547240嚴格>500ms有條件狀態機、546780狀態對WORD旗標及多路合成只可作局部研究；timer不自動是連段/V長按窗口。','原稿所述547240/546780局部狀態旗標與OR/byte選擇介面。','不新驗native，保留早期限定審核；CHAIN_WINDOW=.65是AI替代，SubAI>60不等玩家秒數，未知queue/cancel不可補值。'),
('xml-resource','PARTIAL','來源從主XML路徑/欄位讀取、fallback及原始資源字面列追蹤Type/Key/MapButton/ModKey；081後稿取得XML補早稿缺料，但預設表不等玩家現用配置或招式opcode。','6D08F0主XML解析、packed DWORD/vector、fallback以及081/082的XML字面子集。','Type0 MapButton13..16↔Key44..47與Type1不同映射只作來源字面資訊；DIK解讀待producer證明，Type1基本Key45缺列不證X禁用，Extra高ID/ModKey須另分。'),
('working-bank','PARTIAL','來源區分三個0x280 bank、0/1來源向工作bank2的vector-slot傳遞及active bank指標；XML只有idx0/1，工作bank2不等XML Type2。','FB8834/FB8AB4/FB8D34、6D1A70、6D1BE0、4A1440的來源範圍。','不是raw pointer等於鍵碼或簡單memcpy；完整方向/alias/EH與mode負值合法性及設定何時生效依各稿限制，未作全native重驗。'),
('external-pairs','PARTIAL','來源把6D0D10外部整數配對→工作bank2 slot/vector與Extra XML/DLL字串候選區別；此非runtime鍵盤phase writer，也不是已重建完整使用者存檔格式。','Virualkey.dll/Extra字串、6D0D10整數解析及FB8D34 DWORD追加來源。','檔名副檔名不證DLL載入API，來源編碼/保存writer、索引上界及後續reader未完整確證；vector grow策略不是輸入時間。'),
('fb73e8-mode','PARTIAL','來源將FB73E8在5961C0內限定ID13/14的局部分支，與5A46xx布林變化/5A55E0模式及子物件狀態切換作交叉導航。','084/086/087/088之FB73E8讀者、初始化零writer和mode切換來源。','局部排除不是全遊戲停用15/16；非零權威writer及flag業務語意未解，不能命名戰鬥姿態、普通攻擊或連段。'),
('phase-writer-gap','UNKNOWN','配置bank非零DWORD writer與runtime FB9004/FDF630 byte writer不是同一證據；scan-code→phase1/3的同實體producer鏈仍須具體補證。','各稿明示非零phase writer、鍵盤/DIK輸入及same-instance alias缺口。','保留早稿當時未知，不聲稱所有後續研究仍未知；R1只作缺口導航，避免用census零結果否定producer。'),
('motion-authority-gap','UNKNOWN','輸入/命令到具體actor motion啟動、完成、next-action queue/cancel及Client/Server權威的完整因果仍不由這些局部scope確立。','45..88明示Z held/連打、V tap-held、timer/tier、motion/queue/cancel缺口。','不借用500ms、AI .65或SubAI>60補原版規則；跨T08/T09/T11/T02須證具體receiver/interface，沒有新Server契約。'),
('reset-order-refuted','REFUTED','062第12行稱特殊域6D1DA0初始化先於普通40-byte清零的順序，已被既有T01反證否定；不能作reset時序規範。','只排除062第一支初始化與普通清零的具體先後敘述。','沿用T01-RETURN-T10-062-001；實際普通store→可選特殊初始化→特殊樹clear。其他reset/零值主旨保留PARTIAL，舊來源FAILED不改。'),
('clear-guard-refuted','REFUTED','063第12行將ESI<=0x27守衛放進6D4CAE indexed clear路徑的主張已被既有T01反證否定。','只排除063捏造的本地writer range guard及由此推得任意ID安全。','沿用T01-RETURN-T10-063-001；reader的<=39不屬writer。上游list ID合法值域仍未知，不從本地無guard宣稱漏洞。')]
G={k:dict(key='middle-'+k,assertion=a,evidence_level=e,evidence_scope=scope,limits=[lim,'R1來源子範圍整合；本輪沒有新native驗證/全文FULLPASS/runtime/Server驗收。'],conflicts=[],affected_spec_ids=[],existing_claim_ids=[],source_refs=[]) for k,e,a,scope,lim in defs}
# Read actual narratives; hand-selected line ranges and content-specific notes.
M={
45:('mapping-query mapping-format state-flag-boundary phase-writer-gap',[(11,15),(19,21),(367,379),(383,390)],'兩種mapping來源、lookup-or-create及formatter位元域，不把查詢/輸出集合當phase寫入或Z/V動作。'),
46:('state-reader state-clear mapping-query phase-writer-gap',[(13,23),(266,269)],'reader/clear/mapping vector三型別分離，特殊域未命名、direct E8不等完備控制流。'),
47:('mapping-format mapping-query motion-authority-gap',[(13,23),(468,471)],'594610條件查詢及formatter；輸出用途/動作接點不能由文字組裝推得。'),
48:('mapping-format state-reader command68 state-flag-boundary motion-authority-gap',[(13,32),(535,538)],'A/B/C各局部路徑未以同instance/frame閉合，索引數不等段數、SubAI不等玩家時間。'),
49:('polymorphic-consumer state-reader phase-writer-gap',[(11,22),(603,605)],'兩callsite與+EC/+F0 receiver來源區隔，不能名為player controller或motion writer。'),
50:('literal-census state-clear phase-writer-gap',[(11,24),(218,220)],'literal位置在operand內，七命中不等寫入全集；clear不是keyup。'),
51:('mapping-format mapping-query polymorphic-consumer phase-writer-gap',[(11,22),(657,659)],'WORD矩陣/單byte/映射DWORD不同；逐條附錄和地址未新簽核，不借泛稱已確認升格。'),
52:('state-flag-boundary command68 polymorphic-consumer motion-authority-gap',[(13,35),(369,371)],'flag轉換、byte==1與reader predicate不直接是actor motion/取消；保留T11界線。'),
53:('literal-census phase-writer-gap',[(11,25),(268,280)],'直接參照census核心與附錄資格分開，按既有continuation02保留PARTIAL。'),
54:('state-clear phase-writer-gap',[(11,11),(255,267)],'四種清零前提/caller不同，不稱同一event writer/V放開。'),
55:('state-reader state-clear phase-writer-gap',[(11,11),(244,256)],'特殊樹節點零值和一般陣列不同；附錄頭錯位及泛稱指令已確認須限定。'),
56:('polymorphic-consumer phase-writer-gap',[(11,15),(278,290)],'真正reader calls作有限導航；596430錯位視窗頭及假call排除，不解釋attack/cancel。'),
57:('mapping-format phase-writer-gap',[(11,15),(247,259)],'caller/×11/WORD核心取來源PARTIAL，未採continuation03候選判決，也未認全部附錄。'),
58:('command68 motion-authority-gap',[(11,11),(236,248)],'28..37索引長度非十段普攻；只PARTIAL，receiver仍待證，不借continuation03。'),
59:('state-flag-boundary motion-authority-gap',[(11,11),(380,392)],'500ms/flags/合流scope與V/連段含義分開；只沿來源及已提交歷史。'),
60:('phase-writer-gap motion-authority-gap',[(11,11),(239,251)],'端到端writer→action→controller→motion/queue未閉合，不用.65補缺口。'),
61:('state-clear phase-writer-gap',[(12,12),(130,138)],'初始化gate及配置清零不是每frame keyevent，物件型別/頻率/row載入時序仍缺。'),
62:('state-clear reset-order-refuted motion-authority-gap',[(12,12),(157,165)],'只採雙模式reset/clear和selector未命名；第一支特殊初始化在普通清零之前的語句隔離REFUTED。'),
63:('state-clear clear-guard-refuted phase-writer-gap',[(12,12),(86,94)],'只採特殊域樹節點零值/ordinary indexed clear及list namespace缺口；<=27 writer guard隔離REFUTED。'),
64:('state-reader phase-writer-gap',[(12,12),(104,112)],'reader零回傳可含查無/越界，不判遊戲沒收到按鍵，也不搬guard到writer。'),
65:('polymorphic-consumer motion-authority-gap',[(12,12),(172,180)],'return==1到多態predicate，不直接寫motion；具體vptr/ctor/caller仍缺。'),
66:('mapping-query mapping-format phase-writer-gap',[(12,12),(194,202)],'mapping bank與phase array分開；XML/action/output三欄需同來源證明。'),
67:('command68 motion-authority-gap',[(12,12),(115,123)],'FBA798/FBA854+10的局部gate，不當十段/持續蓄氣或完整wire契約。'),
68:('state-clear state-reader command68 phase-writer-gap motion-authority-gap',[(12,12),(164,172)],'clear/read/command三節點各自有界；完整非零writer與actor queue指標鏈未閉合。'),
69:('xml-resource phase-writer-gap',[(13,13),(129,131),(143,154)],'路徑/欄位字串不證檔案已成功開啟或parser library；早稿缺實際XML為當時狀態。'),
70:('xml-resource',[(13,13),(101,103),(118,126)],'Type/Key/MapButton/ModKey轉整數分支，需各register來源，不把row index當Z/V。'),
71:('xml-resource mapping-query',[(13,13),(70,72),(83,91)],'0x280/0x10 bank布局是配置，row上界/第4DWORD未閉合，不當runtime writer。'),
72:('xml-resource external-pairs phase-writer-gap',[(13,13),(79,81),(93,101)],'packed DWORD追加與end+=4是mapping writer；grow與位元域/action還有限制。'),
73:('xml-resource',[(13,13),(67,69),(81,89)],'容量1.5倍/元素上界不是held閾值；allocator/copy/EH未逐指令驗。'),
74:('xml-resource',[(13,13),(120,122),(135,143)],'native fallback存在的來源線索不等玩家個人設定；常數不按ASCII硬綁Z/V。'),
75:('working-bank state-clear',[(13,13),(84,86),(100,108)],'mode地址/active指標與清零分開；signed>=3不自證負值合法性。'),
76:('external-pairs xml-resource',[(13,13),(80,82),(94,105)],'Virualkey.dll非Extra.xml；字串命名不證載入API/開檔成功。'),
77:('external-pairs',[(13,13),(103,105),(117,125)],'兩整數→slot/DWORD與main packed欄不同，合法上界及真實來源/reader未閉合。'),
78:('working-bank',[(13,13),(123,125),(138,146)],'default bank→FB8D34複製候選，不從caller直接當deep copy或全部動作立即生效。'),
79:('phase-writer-gap xml-resource state-reader',[(13,13),(142,144),(155,163)],'找到config非零writer不等phase writer，鄰接/global高byte不證alias。'),
80:('xml-resource working-bank phase-writer-gap motion-authority-gap',[(13,13),(187,191),(205,213)],'配置局部鏈完整是來源措辭，不升全文/原生玩法；bank選用與runtime/motion缺口保留。'),
81:('xml-resource phase-writer-gap motion-authority-gap',[(10,28),(48,68),(88,100)],'XML原件由正式內容定址鏡像取得，404不等不存在；Key44..47 DIK是待producer證明的解讀，預設非現用。'),
82:('mapping-query mapping-format xml-resource working-bank external-pairs polymorphic-consumer phase-writer-gap',[(12,18),(22,47),(72,72),(87,94),(123,138),(143,171)],'三bank/外部回填與文字formatter分開；Type1 MapButton13..16存在，只有基本Key45/Mod0缺列，Extra不能全域否定。'),
83:('working-bank external-pairs xml-resource motion-authority-gap',[(9,11),(27,31),(58,68)],'三bank及兩整數回填有研究支持，來源檔名/保存/現用配置/Type1 fallback仍缺。'),
84:('polymorphic-consumer fb73e8-mode phase-writer-gap motion-authority-gap',[(36,42),(47,63),(65,65)],'補edi/esi路徑的後續研究，phase名不升Press/Release；ID13/14 gate只該函式當下分支。'),
85:('state-clear state-reader phase-writer-gap',[(7,10),(142,144)],'採clear/list-domain scope；泛稱先初始化不覆蓋062精確時序反證，reader guard仍不能搬入clear。'),
86:('fb73e8-mode motion-authority-gap',[(7,10),(204,206)],'初始化零writer不是非零來源；模式/子物件狀態切換不自稱普攻/取消。'),
87:('polymorphic-consumer mapping-query phase-writer-gap fb73e8-mode',[(7,10),(135,137)],'配置query不限UI，phase介面不同；EC/F0 owning class與scan-code→writer因果仍缺。'),
88:('xml-resource working-bank polymorphic-consumer fb73e8-mode phase-writer-gap motion-authority-gap',[(7,19),(98,100)],'研究進展與完整native_complete分開，ID/map不是opcode，未以.65/500ms補玩法。')}
out=[]
for q in sources:
 n=q['number'];ks,ranges,note=M[n];p=R/q['source_file'];b=p.read_bytes();lines=b.decode('utf-8-sig').splitlines()
 assert hashlib.sha256(b).hexdigest()==q['source_sha256'];assert hashlib.sha1(b'blob '+str(len(b)).encode()+b'\0'+b).hexdigest()==q['source_blob_sha']
 excerpts=[dict(start=a,end=z,text='\n'.join(lines[a-1:z])) for a,z in ranges];assert all(1<=a<=z<=len(lines) for a,z in ranges)
 conflicts=[];excluded=[]
 if n in [62,63]:
  k='reset-order-refuted' if n==62 else 'clear-guard-refuted';item='T01-RETURN-T10-062-001' if n==62 else 'T01-RETURN-T10-063-001'
  excluded=[dict(source_lines=[12,12],claim_key='middle-'+k,disposition='REFUTED_EXACT_SCOPE_ONLY',decision_ref=HISTORY,return_id=item)]
  conflicts=[dict(key=item,description=G[k]['assertion'],refs=[HISTORY,'kr/tasks/T10/README.md'],disposition='Preserve FAILED source; isolate precise false scope. Other bounded clear/namespace and explicit unknown scopes remain separately attributed PARTIAL/UNKNOWN.',r2_if_needed='Separate corrected source/new SHA and exact affected CFG/dataflow, only if design depends on this order/guard.')]
 if n in [53,55,56]:
  conflicts.append(dict(key='CONTINUATION02_APPENDIX_SCOPE',description='Existing full examination retained PARTIAL; misaligned window heads/generic instruction confirmation require qualification; explicit raw tail truncations are not semantic failures.',refs=[C02,'kr/tasks/T10/README.md'],disposition='Retain bounded core asPARTIAL; no whole-appendix certification or new author notice.',r2_if_needed='Reuse committed canonical excerpts and request separately qualified source only if precise instructions are needed.'))
 if n==85:conflicts.append(dict(key='RESET_ORDER_DO_NOT_GENERALIZE',description='General initialize/clear prose must not override062 exact order counterevidence.',refs=[HISTORY],disposition='Only accept independent zero-store/domain scope; no new REFUTED verdict or author notice.',r2_if_needed='Use existing exact sequence, not generic ordering prose.'))
 s=dict(source_file=q['source_file'],source_blob_sha=q['source_blob_sha'],source_sha256=q['source_sha256'],source_intake_id=q['source_intake_id'],client_version='kr',target_sha256=TARGET,claim_keys=['middle-'+k for k in ks.split()],source_lines=excerpts,disposition='R1_BOUNDED_SUBSET_WITH_EXACT_REFUTED_SCOPE_EXCLUDED' if excluded else 'R1_SOURCE_RESEARCH_AND_EXPLICIT_UNKNOWNS_ONLY',observations=note,limits=['Only cited narrative subsets; no codeblock/full-function/full-document certification.','Quality is not inherited across sources or from bytes/hashes.'],excluded_scopes=excluded,conflicts=conflicts,historical_status_preserved=q['historical_status'],new_native_verification=False)
 out.append(s)
 for k in ks.split():
  for a,z in ([(12,12)] if G[k]['evidence_level']=='REFUTED' else ranges):
   G[k]['source_refs'].append(dict(source_file=q['source_file'],source_blob_sha=q['source_blob_sha'],source_sha256=q['source_sha256'],source_lines=[a,z],scope_observation=note,quality_inheritance=False))
  if conflicts:G[k]['conflicts']+=conflicts
# Check canonical registry semantically, not by task. No existing assertion is
# equivalent to these input/config/phase scopes; transport claims remain distinct.
claims=json.loads((R/'research/claims/index.json').read_text(encoding='utf-8'))['items']
assert all(g['source_refs'] for g in G.values())
proposal=dict(schema='t01-t10-roy-middle-r0-r1-proposal-v1',base_main=inventory['base_main'],source_head=inventory['source_head'],scope='middle45..88',mode='R0_R1_ONLY',summary=dict(sources=44,narratives_read=44,unfinished_sources=0,groups=len(G),evidence_levels=dict(collections.Counter(g['evidence_level'] for g in G.values())),sources_with_existing_refuted_scope=2,appendix_qualification_sources=3,new_native_verified=0,new_full_document_pass=0),groups=list(G.values()),sources=out,canonical_review=dict(registry='research/claims/index.json',checked_claim_ids=[x['id'] for x in claims],existing_equivalent_claim_ids=[],related_but_not_equivalent=['CLM-NET-0005','CLM-NET-0006','CLM-CLIENT-0019','CLM-CLIENT-0022'],disposition='Do not merge query/config/phase/command68 claims into transport/actor-slot/scene-dispatch claims merely because shared methods/slot offsets exist; parent may deduplicate overlapping T10 scope proposals.'),review_policy=dict(history_refs=[HISTORY,C02,'kr/tasks/T10/README.md'],excluded_uncommitted_candidates='No continuation03 candidate verdict used.',stop='R1 identity, actual narrative bounded extraction, conflict scope and S00 navigation complete. No native re-audit.',r2_open=['Same-instance scan-code→nonzerophase writer','Concrete+EC/+F0 receiver→motion/queue/cancel','Actual active/user setting andfallback','Reset list ID invariant andcorrected062/063 source if depended upon'],server_impact='No existing Server specification directly asserted by these local input/config paths. affected_spec_ids empty; local68 is not automatically wire command.',new_author_notice=False))
D.mkdir(parents=True,exist_ok=True);(D/'proposal.json').write_text(json.dumps(proposal,ensure_ascii=False,indent=2)+'\n',encoding='utf-8');print(json.dumps(proposal['summary']))
