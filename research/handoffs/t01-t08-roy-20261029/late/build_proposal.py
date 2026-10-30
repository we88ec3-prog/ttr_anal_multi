from read_sources import *
BASE='610a822b15346c9e0b69edd4e104c2076f2b59ac';HEAD='5816884ef481995a9fe0d92277b1dde06aff32e8'
MASTER=json.loads((D.parent/'sources.json').read_text(encoding='utf8'))
FROZEN={x['number']:x for x in MASTER['sources'] if x['scope']=='late'}
assert set(FROZEN)==set(range(153,201))
CANON={158:'CLM-CLIENT-0001',177:'CLM-CLIENT-0002',197:'CLM-CLIENT-0003'}
GROUPS={}
COMMON=['R0/R1 來源接收及有限主張導航；本批未執行 REA、未重新核驗 BIN，也不新增全文或主張 FULL-PASS。','KR 指定 SHA 限定；不能以相同 offset、helper 或 actor 名稱認定不同結構同實例。','affected_spec_ids 尚未由 S00 配對；不得直接作為協定欄位、Server 規則或可部署實作。']
def group(k,a,level='PARTIAL',limits=(),conflicts=(),related=()):
    key='late-'+k;GROUPS[key]=dict(key=key,assertion=a,evidence_level=level,evidence_scope='Only source-linked narrative intervals and their explicitly bounded research observations.',limits=COMMON+list(limits),limitations=COMMON+list(limits),conflicts=list(conflicts),specids=[],affected_spec_ids=[],spec_mapping='unknown; S00 determines actual dependency',related_existing_claim_ids=list(related),quality_inheritance=False)

group('actor-index-removal','原稿分開描述主樹 +8 的單 key 移除、actor+88 條件遍歷、actor+4 低 byte 篩選和整表清理；查找、controller callback、actor virtual cleanup 與節點回收按各入口分離。',limits=['4DFBC0/4DFC90/4DFD40/4DFE90 的來源觀察不證明相同runtime觸發；+88不是已證0007 owner+9C。'])
group('node-erase-contract','原稿將 7B6890 的節點 unlink／balance／free／iterator 輸出與 caller 的 actor cleanup 分開；共享 helper 不等於相同容器或物件所有權。',conflicts=['153/157 erase ABI需按既有退回區分 search-key storage與out-iterator；155錯位碼塊不得當精確結構證據。'])
group('row-removal-candidates','原稿描述 4B28D0 的 WORD ID陣列候選接收路徑及 4B3710 的 WORD|06000000 條件key；與0007的26-byte建立row不同。',limits=['本批未確認移除入口的dispatcher opcode、網路方向、全buffer安全或封包時序。'],conflicts=['157的4B297C錯位及erase ABI退回仍NEEDS_FIX；不繼承其所有碼塊。'])
group('getter-history-correction','154/156 曾暫稱40F060為key轉換／定位；後續158及160/163/164將它改述為GameInfo lazy getter，複合key由caller形成並留在stack。',limits=['更正導航以既有CLM-CLIENT-0001的精確scope為準；其他來源相似文字僅PARTIAL。'],related=['CLM-CLIENT-0001'])
group('actor-derived-cleanup','原稿依4D1710／4D0B80建構vptr和C0C9DC／C0C824表值，提出CMonster／CEventActor兩個具體個案的slot+14預清理及slot0(flag1) deleting-wrapper次序。',limits=['只限實際具有指定vptr的個案；不能推出所有actor、完整析構或GPU資源free。'])
group('precleanup-binding-slots','原稿描述4C8360在+364和+164起128槽的nested+24非零時呼叫7BE5F0；這與清空actor外層slots及最終actor free分層。',limits=['每格非零與+24條件不可省略；未證所有slots均有資源。'])
group('child-secondary-interface','原稿將actor+15C指向child後的child+8介面作this-adjust，再由該介面vptr+8間接呼叫；它先於其他nested binding cleanup。',limits=['child建構、vptr值及實際target unknown，不能套actor主vtable或object+F0次表。'])
group('base-actor-finalization','原稿描述4C7B90基底清理多組欄位／容器、128項及25項槽、引用控制塊及4C7DB0子清理；與4C8360預清理不同。',limits=['外部alias、所有派生類、失敗回滾、allocator pairing與exception／thread安全未封閉。'])
group('resource-slot-release','原稿以7BE5F0的可寫slot輸入，描述resource及其owner計數、+74/+78 gate、延遲或立即分支，並區分清nested+24 slot與清actor陣列項。',limits=['空slot回傳EAX及非標準register ABI保留各來源限制；counter業務含義、全引用平衡unknown。'])
group('nested-collection-disposal','原稿描述7BE0F0對item begin/end內node+8 payload先vslot+8，再條件vslot0(1)，清payload並重設+74；7BD850另外回收pointer vector及storage。',limits=['不是所有caller必經此路徑；非空node invariant、真實多型target及allocator語意未完整驗證。'])
group('resource-deferred-queue','原稿以owner+44的signed gate區分7DD1A0 queue／immediate，7BB350向+7C vector寫指標，7DD1F0 drain逐槽清理；mode stop及manager引用歸零是已列caller候選。',limits=['不是全局延遲政策或每frame排程；相同offset不合併owner；raw E8只作候選。'],conflicts=['173常數1寫入曾被誤稱可變ECX，177已修復；舊173仍FAILED。'],related=['CLM-CLIENT-0002'])
group('resource-reuse-counters','原稿描述7DCFB0先增owner+60，再由+7C/+80尾端pop復用或配置7C資源；release減+60，而manager+5C是另一欄位。',limits=['正常路徑局部對偶不保證NULL／配置失敗／wrapper例外全平衡；不證跨frame復用頻率。'])
group('mode-collection-order','原稿區分模式啟用時第一集合callback+4、第二集合payload+44=1與container+30，以及停用時先drain／清44再第一集合callback+8。',limits=['新來源僅PARTIAL；正式精確模式scope引用CLM-CLIENT-0002。'],related=['CLM-CLIENT-0002'])
group('manager-name-index-release','原稿描述manager+5C歸零時drain／清44，再經FE173C名稱索引；7DC510查找sentinel後由payload vcall+C零返回才作vcall0及index erase。',limits=['實際payload vptr、名稱索引owner與scene actor主樹同源未知；不把7B8680當RB tree。'],conflicts=['183把7B8680稱樹節點移除已被確證反駁，相關名稱須改hash/index-node。'])
group('manager-buffer-finalization','原稿描述7DCF40以EDI為manager基址，先free+4C向量項、再free+7C buffer／清欄位和同步資源、最後回收+4C storage。',limits=['非標準ABI；所有0C item內部資源／異常安全與scene actor erase關係未封閉。'])
group('wrapper-resource-bridge','原稿描述30-byte wrapper與7C-byte resource分層，wrapper+2C接acquire結果；新配置依manager+44呼7BDF90作名稱／Provider binding，復用則走7BE5B0。',limits=['vptr、binding業務名稱只是研究標籤；失敗回退、完整所有權、同實例來源尚未驗完。'],conflicts=['187的7F6FC1 push30座標錯誤保留；後篇191的有限wrapper關係不自動修復187舊碼塊。'])
group('scene-resource-interface','原稿以4C7DB4／4C838C等有限callsite連到7BE5F0，再到資源producer；scene actor樹移除、名稱索引和manager pool仍分開。',limits=['局部call存在不等於每個actor具有同wrapper/resource/manager；不能把erase等價於drain。'])
group('actor-registration-duplicate','原稿描述4DFF30以actor+4 WORD作查詢key，absent時插入、duplicate時走訊息分支；與+88 predicate不同，但owner+8主樹相同。',conflicts=['200 L11「不是同一索引」可能指key域或容器，維持PARTIAL需澄清；82EF00 lower-bound-only舊拒因已撤銷，不能復活。'],limits=['duplicate後新actor的上游釋放責任unknown。'])
group('unknown-client-protocol-lifetime','仍缺移除接收器精確opcode／業務方向、actor+88 key正式schema、child與payload具體target、跨層同指標所有權、完整失敗／重入／併發及runtime觸發；原版Server生成時點／波次／AI不由這些本地資源helper決定。','UNKNOWN',limits=['UNKNOWN是待補問題，不能轉作預設packet值、Server流程或無條件free保證。'])
group('refuted-erase-argument-role','153／157舊稿把erase傳參中的stack slot當key；既有原件反證區分傳82EF00的key地址與傳7B6890的out-iterator地址，slot被重用後不再保持原key角色。','REFUTED',conflicts=['T01-RETURN-T08-153-ABI-001','T01-RETURN-T08-157-001'])
group('refuted-erase-window','155舊碼塊在7B698E指令中途重起，虛構7B698F/90/92等instruction rows，不能作該處精確CFG證據。','REFUTED',conflicts=['T01-RETURN-T08-155-ASM-001'])
group('refuted-variable-mode-writer','173將7B8006的ECX視為caller待定可變來源；既有反證7B7FFE mov ecx,1支配該store，且真入口是7B7FD0。','REFUTED',conflicts=['T01-RETURN-T08-173-001 RESOLVED by177; old173 source remainsFAILED'],related=['CLM-CLIENT-0002'])
group('refuted-tree-label','183將7B8680描述為ordered-tree節點移除；既有反證為string hash/mask、bucket及list unlink/free，不能當RB tree旋轉／調整。','REFUTED',conflicts=['T01-RETURN-T08-183-001'])
group('refuted-wrapper-coordinate','187把7F6FC1寫為push30；既有原件反證push30在7F6FBF，7F6FC1為mov EDI,EAX，保存manager。','REFUTED',conflicts=['T01-RETURN-T08-187-001'])
group('refuted-secondary-tree-conflation','196把4DFC90歸owner+18次級樹；既有反證4DFC96 LEA EDI,[EAX+8]是主樹，真正次級路徑為4DFC30 owner+18。','REFUTED',conflicts=['T01-RETURN-T08-196-001 RESOLVED by197; old196 source remainsFAILED'],related=['CLM-CLIENT-0003'])

# Each mapping below was chosen after reading the source narrative, not by its filename.
# Format: primary functional group, precise source-line interval, finite content observation.
OBS={
153:('actor-index-removal',[14,42],'單鍵、+88 predicate、低byte篩選與整表清理各自分路；不假設相同receiver實例。'),
154:('row-removal-candidates',[15,17],'4B2AB9讀WORD、cursor+2後call4DFBC0；未命名正式opcode。'),
155:('node-erase-contract',[11,19],'7B6890只處理node結構與free／iterator，不代caller銷毀actor。'),
156:('actor-index-removal',[17,31],'並列single ID、compound predicate、type bulk、full clear與script容器。'),
157:('row-removal-candidates',[16,18],'長度門檻和WORD cursor前進，缺失ID不等於整包中止；仍缺dispatcher。'),
158:('existing',[12,174],'已正式關聯getter／stack composite-key及receiver ABI，沿用精確既有scope。'),
159:('actor-index-removal',[67,72],'查中後三槽controller、無先行payload null check的vcall+14、再vcall0及node erase。'),
160:('getter-history-correction',[14,38],'明確撤回key converter，並把null invariant與node/actor cleanup分開。'),
161:('actor-derived-cleanup',[12,25],'兩組建構vptr和slot0/14目標個案，其他derived actor不泛化。'),
162:('precleanup-binding-slots',[14,20],'4C8360處理+364及128個+164槽nested+24，不宣稱清外層slots。'),
163:('row-removal-candidates',[12,30],'區分4-byte／2-byte prelude和WORD來源，rdata pointer負掃描不排除dispatch。'),
164:('actor-derived-cleanup',[18,34],'具體derived wrappers、預清理、actor destructor和node erase分層。'),
165:('base-actor-finalization',[14,23],'基底vptr更新、+368/+160/+364/128slots/25slots與base結尾，不保證全部heap free。'),
166:('resource-slot-release',[14,22],'slot非空才走resource owner減量與+74/+78分支；只清被傳slot。'),
167:('base-actor-finalization',[14,21],'預清理只release nested+24，終結清理free item並清actor slots；重入未知。'),
168:('scene-resource-interface',[16,28],'建立／移除、預清理、基底、nested release及tree erase層級矩陣。'),
169:('resource-deferred-queue',[15,18],'owner+44 signed gate，>=1 append+7C，另一支清item；非global policy。'),
170:('nested-collection-disposal',[13,17],'item begin/end中的node+8先vslot8再條件vslot0，最後item+74=0。'),
171:('nested-collection-disposal',[15,32],'7BD850清dynamic pointer vector；7BB350寫DWORD、alias guard／擴容仍有限。'),
172:('resource-deferred-queue',[39,51],'producer／consumer層級整合；owner+44 writer與drain時序保持待查。'),
173:('resource-deferred-queue',[13,20],'原稿列兩個清44路徑，但非零writer可變ECX說法已撤回。'),
174:('resource-deferred-queue',[10,19],'7DD1F0持owner+64並消費+7C/+80，與producer欄位匹配但runtime未知。'),
175:('resource-deferred-queue',[11,22],'release→queue或immediate→drain；7A8741另個caller不等於0007 actor。'),
176:('resource-deferred-queue',[12,25],'gate、producer、consumer、清44與lock矩陣；不推每frame政策。'),
177:('existing',[13,21],'既有collection mode／producer gate關聯保留，修復173但不翻舊FAILED。'),
178:('mode-collection-order',[10,14],'先第一集合callback再第二集合設mode，停用先drain後callback；FE173C位址與槽值區分。'),
179:('manager-name-index-release',[10,14],'manager+5C減到0才drain及delegate7DC510，FE173C槽值與模式地址容器不同。'),
180:('scene-resource-interface',[14,18],'actor registry與drain無該direct E8不代表無多跳release；兩種owner保持隔離。'),
181:('resource-reuse-counters',[15,20],'acquire先+60++，pool pop重設或allocate7C；與manager+5C區分。'),
182:('wrapper-resource-bridge',[15,18],'新配置有mode條件binding，復用走7BE5B0；mode stop不自證沒有並發producer。'),
183:('manager-name-index-release',[15,18],'7DD100回傳零才析構manager與移除索引；原稿7B8680樹標籤另記反證。'),
184:('scene-resource-interface',[15,29],'release→enqueue→reuse或drain雙出口，不把actor erase視為pool owner結束。'),
185:('manager-name-index-release',[13,25],'ECX/EDX索引與string、sentinel guard後payload callback+C零返回才erase。'),
186:('manager-buffer-finalization',[13,29],'EDI manager，+4C項與storage及+7C buffer／lock分開回收。'),
187:('wrapper-resource-bridge',[13,25],'wrapper+2C引用資源，+60對偶不代表全部失敗分支平衡；allocation座標另記已確證錯誤。'),
188:('scene-resource-interface',[13,25],'actor registry、erase與resource counter／pool分層；缺具體wrapper同源。'),
189:('manager-name-index-release',[10,20],'lookup→sentinel→vcall+C→conditional0／erase，未取得payload動態vptr。'),
190:('resource-reuse-counters',[10,20],'acquire+60++與release--只是局部對偶，配置失敗／NULL及跨thread平衡待查。'),
191:('wrapper-resource-bridge',[10,20],'wrapper、resource acquire、名稱Provider binding及解除各自分邊，不把index erase當wrapper destructor。'),
192:('scene-resource-interface',[10,22],'actor→component cleanup→release→pool只具有限callsite，缺完整實例來源。'),
193:('actor-derived-cleanup',[19,36],'指定C0C9DC主vptr個案對slot14／0與具體helper，不泛化所有actor。'),
194:('actor-index-removal',[14,24],'4DFE90逐actor vcall14再0，之後整樹clear和global callback；非逐node erase。'),
195:('child-secondary-interface',[12,30],'actor+15C→child+8介面→slot8；不把主actor vptr借給child。'),
196:('refuted-secondary-tree-conflation',[10,26],'主張4DFC90為owner+18次樹及雙表ownership風險，其前提已被197更正。'),
197:('existing',[11,18],'既有secondary4DFC30與main4DFC90精確區分／清理scope沿用；舊196不翻判。'),
198:('actor-index-removal',[11,14],'actor+4讀byte與WORD參數比較，types0/1/6/7限定分支，再有條件cleanup／erase。'),
199:('actor-index-removal',[11,14],'sentinel遍歷／virtual cleanup／整樹clear，與4DFC90 per-node erase iterator策略不同。'),
200:('actor-registration-duplicate',[11,14],'actor+4 WORD key與duplicate分支；+88 predicate不等於不同tree。'),
}
EXTRA={153:[('node-erase-contract',[18,20]),('refuted-erase-argument-role',[20,20])],154:[('getter-history-correction',[117,117])],155:[('refuted-erase-window',[21,254])],156:[('getter-history-correction',[20,29])],157:[('refuted-erase-argument-role',[192,249]),('getter-history-correction',[194,194])],164:[('precleanup-binding-slots',[20,25])],167:[('resource-slot-release',[14,17])],168:[('base-actor-finalization',[18,20])],171:[('resource-deferred-queue',[17,24])],173:[('refuted-variable-mode-writer',[10,19])],179:[('manager-buffer-finalization',[13,14])],183:[('refuted-tree-label',[16,16])],187:[('refuted-wrapper-coordinate',[21,21]),('resource-reuse-counters',[13,17])],193:[('precleanup-binding-slots',[54,66])],194:[('actor-derived-cleanup',[22,24])]}

def run():
    rows=[]
    for q in Q:
        n=q['number'];f=FROZEN[n];lines=read(q)
        assert f['source_file']==q['source'] and f['source_blob_sha']==q['git_blob_sha'] and f['source_sha256']==q['sha256']
        k,rng,obs=OBS[n];links=[]
        if n not in CANON:
            links.append(dict(claim_key='late-'+k,source_lines=rng,observation=obs))
            for ek,er in EXTRA.get(n,[]):links.append(dict(claim_key='late-'+ek,source_lines=er,observation=GROUPS['late-'+ek]['assertion']))
            # Unknowns are explicitly linked to actual limitation prose, not invented from the title.
            candidates=[i for i,l in enumerate(lines,1) if ('未知' in l or '待驗' in l or '未證' in l or '未確認' in l) and not re.match(r'^\s*[0-9a-fA-F]{6,8}:',l)]
            if candidates:links.append(dict(claim_key='late-unknown-client-protocol-lifetime',source_lines=[candidates[0],candidates[-1]],observation='來源明示的有限範圍／未證事項；不能用省略的語意填預設值。'))
        exact=[]
        for link in links:
            lo,hi=link['source_lines'];assert 1<=lo<=hi<=len(lines)
            link['line_excerpts']=[dict(line=i,text=lines[i-1]) for i in range(lo,hi+1) if lines[i-1].strip() and not re.match(r'^\s*(?:0x)?[0-9a-fA-F]{6,8}:',lines[i-1])][:10]
            exact.append(link)
        conflict=[]
        for link in links:conflict.extend(GROUPS[link['claim_key']]['conflicts'])
        if n in [154,156]:conflict.append('Historical converter wording corrected by158/CLM-CLIENT-0001; preserve old source and do not inferquality inheritance.')
        if n==157:conflict.append('T01-RETURN-T08-157-001 also retains4B297C mid-instruction window; thisR1 doesnotreuse itasexactnative evidence.')
        if n==200:conflict.extend(['Current documentPARTIAL: index term ambiguous, notcertifieddistinctcontainer.','Prior lower-bound-only rejection withdrawn;82EF00 exact-key terminalcheck must remain acknowledged.'])
        if n in CANON:
            assert f['before_integration_status']=='CONFLICT_CHECKED' and CANON[n] in f['prior_claim_ids']
        rows.append(dict(number=n,source_file=q['source'],source_blob_sha=q['git_blob_sha'],source_sha256=q['sha256'],client_version='kr',target_sha256='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91',source_head=HEAD,source_intake_id=f['source_intake_id'],historical_status=f['historical_status'],before_integration_status=f['before_integration_status'],integration_action='KEEP_EXISTING_CONFLICT_CHECKED' if n in CANON else 'R0_R1_EXTRACTION_PROPOSED',claim_keys=list(dict.fromkeys(x['claim_key'] for x in links)),existing_claim_ids=[CANON[n]] if n in CANON else [],source_lines=rng,bounded_observation=obs,claim_links=exact,conflict_disposition=list(dict.fromkeys(conflict)) or ['No additional confirmed contradiction found in this bounded R1 navigation; not full native conflict closure.'],unknowns=['Runtime／allindirect targets／server policies notcertified; see actual source limitations.'],narrative_read=True,code_blocks_native_reviewed_this_intake=False,new_native_verification=False,new_document_full_pass=False,quality_inheritance=False))
    for row in rows:
        row['disposition']=('保留既有 CONFLICT_CHECKED intake 與既有 NATIVE_VERIFIED claim 精確關聯；不重寫品質、不新增pass。' if row['number'] in CANON else '已讀敘述並完成R0/R1功能去重及已知衝突導航；新群僅PARTIAL/UNKNOWN或既有確證REFUTED，不作全文／新主張原生驗收。')
    used={key for x in rows for key in x['claim_keys']};assert used==set(GROUPS),set(GROUPS)-used
    for key,g in GROUPS.items():g['supporting_sources']=[dict(source_file=x['source_file'],source_blob_sha=x['source_blob_sha'],source_sha256=x['source_sha256'],source_lines=l['source_lines']) for x in rows for l in x['claim_links'] if l['claim_key']==key]
    proposal=dict(schema='t01-t08-roy-r0-r1-subagent-proposal-v1',scope='late T08-153..200',base_main=BASE,source_head=HEAD,source_count=48,processed=48,remaining=0,new_source_extractions=45,existing_preserved=3,new_full_pass=0,risk='R0/R1 only; confirmed historic refutations are reused, no newR2/R3',groups=list(GROUPS.values()),sources=rows)
    (D/'proposal.json').write_text(json.dumps(proposal,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print('sources',len(rows),'groups',len(GROUPS),'existing',len(CANON),'remaining',0)
if __name__=='__main__':run()
