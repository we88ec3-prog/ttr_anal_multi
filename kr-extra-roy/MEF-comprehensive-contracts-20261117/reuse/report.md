# MEF 可重用生命週期：圖片勘誤、第二次 Start 與兩段演出交接

日期：2026-11-17。研究分支：`extra/roy1`；取證基準提交 `5ef4ab8870ea1c65c6c7497901302d851f5c7a51`。這是新增的靜態分析與相容內容設計，不是 Client／Server 實作、遊玩通過、官方 MEF parser／grammar 完成。原 BIN、Event.stp 均唯讀；沒有執行 Lua、遊戲、Server 或封包。本包不變更既有 A1 規格及其鍵政策。

## 1. 本輪結論

**最重要的更正是：`Q.FlyingObject` 會先取消 Q 目前保存的圖片，再建立新圖片。** 前輪把「只保存最後 handle」推成「再次建立不先取消舊圖」，與原件 `56496A → 564A60` 相反。原先的完整 ASM 已保存這條 call；錯在解讀與合成模型，並非原件或窗口缺失。不能因舊模型測試 PASS 就沿用錯誤語義。[本包 `q_flying_create`、`q_flying_cancel`；完整更正索引見 [errata.json](errata.json)]

另一個可實作的進展是把第二次 Start 的資源更新接到真正引用與回載 consumer：**Start(B) 先替換 level 3 模型層，再載入 B 的正式腳本；B callback 第一行呼 `DeleteAllObject` 會再提交空的 level 3 替換，連 B 剛建立的該層也會清掉。** 因此「先 End A，另開清理 scene，開頭 DeleteAll，再建立 B」不是純粹清理 A 的契約。若需要 A、B 相互獨立，建議在 A 還有合法執行時機且持有全 Q 樹時收尾 A，該 level 工作返回後才 End A，再允許 B Start；level event不代表所有CDoll callback/release都已drain。[`q_start`、`q_delete_all`；[CDoll補證](../reuse-followup/report.md) §6–9]

**追加原件補證已確認：正常保留CDoll具有自己的resource+5C引用，且有效CDoll請求會回載同一catalog+54 resource。** 所以不能從清level3推導保留actor必然被卸載，也不能把+54非NULL時跳過早期按需配置當成無法恢復。Q.CreateObject實際是 `56322E→4D0FE0→4C7DF0(actor,1)` 的immediate路徑。原先本包§5／§8尚未閉合的這一條鏈已由附錄完成，本文同步收窄；仍保留state3不自動retry、資產／render readiness與全工作drain的界線。[CDoll補證 §4–8；本包§5]

## 2. 原件、交付與計數邊界

| 原件／依據 | 固定識別與用途 |
|---|---|
| KR BIN | 12,472,320 bytes；SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE32/i386，ImageBase `0x400000` |
| Event.stp | 11,241,597 bytes；SHA-256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b` |
| 選定 qbase | `Event/qbase.lua`，block 7378；解碼 11,836 bytes；SHA-256 `d6e01d85194f452d56961252d797a0e671d7e34a11fe07e96155220f27ee4cc3` |
| Git 依據 | 31 個固定 blob，包括既有 R9/R10/R11、前輪生命週期報告、A1／one-shot 與本輪用到的 bulk 偽碼；詳 [source-manifest.json](source-manifest.json) |

[native-evidence.json](native-evidence.json) 保存 12 個完整函式 body、7,150 bytes、2,192 個連續解碼指令起點、34 個錨點與22條 direct call；同一內容可讀版是 [native-evidence.asm](native-evidence.asm)。窗口皆有 VA、exclusive end、真正 PE raw mapping、原始 hex、SHA-256。`NEW_DOWNSTREAM_JOIN` 表示本輪新接資源退駐／回載 consumer；`REUSED_*` 表示既有函式用於跨 run 接合；`ERRATUM_REJOIN` 是更正舊語義。這些數字不是新增 API 數或全程式覆蓋率。

[qbase-evidence.json](qbase-evidence.json) 從原 Event 重新讀出76個 prototype 的結構，逐欄核對選定6個 prototype、40個 instruction words，以及 root 的7個初始 words；它不執行 chunk、不發布完整腳本。

所有名稱、參數完整 ABI 與121名稱總盤點由整體研究的另一子題負責；本包不重做該工作，也不把前輪 post-End tick、圖片 release/delete、camera Stop/Detach/Pop、全 pool StopMusic 再算成新能力。

## 3. 圖片建立的正確替換契約

### 3.1 真正順序

完整 `564940..564A5B` 是正常 `Q.FlyingObject` 的 native target，完整 `564A60..564AFB` 是 `Q.DelFlyingObject`。沿用原 bindings、正常 Q receiver `M=FB73C0` 與共享圖片 owner `FB7358`，原件順序如下。[`q_flying_create`、`q_flying_cancel`]

| 順序 | 指令錨點 | 意義 |
|---:|---|---|
| 1 | `564968 mov ebx,ecx`；`56496A call 564A60` | 先以同一 Q receiver 取消先前保存的 handle |
| 2 | cancel 中 `564AB4` 讀 `M+40`；`564AC6` 查共享圖片樹 | 有匹配節點和物件才改它，缺失則繼續 |
| 3 | `564ADD mov [image+14],0`；`564AE4 mov [M+40],FFFFFFFF` | 舊圖標記 alive=0；無論是否找到都清最後 handle |
| 4 | `56496F push 70`；`564971 call 891268` | 取消返回後才配置新物件，繼續 constructor／參數設定 |
| 5 | `564A32 call 82F200`；`564A44 mov [M+40],ecx` | 新物件進共享樹，Q 保存新的內部 handle |

因此串行呼叫 `FlyingObject(A)`、`FlyingObject(B)`，即使兩張都使用 hold=-1，B 的建立前綴已向 A 發出取消。之後再 `DelFlyingObject()` 是取消 B；前輪「只有 B 會被刪，A 一直留著」的合成預期應標 **SUPERSEDED**。這項更正不需要假設換 scene、換 Q slot 或新增 API。[上述 complete bodies；[reference_model.py](reference_model.py)]

### 3.2 仍須區分取消、實體回收與共享 owner

先取消並不等於同步 destructor。前輪已證 alive=0 的圖片需要後續合格 manager pass 才 release、deleting destructor、erase；這條已完成的 consumer 本輪沿用。因此短時間內可能仍有一個待回收舊物件與一個新物件，不能把「替換已發出」寫成「記憶體已即時回收」。manager 的排隊／group／delay gate 也不由本輪取消順序消除。[來源 pin：`MEF-feature-lifecycle-20261117/REPORT.md` §6.2–6.3、同包 `native-evidence.asm`]

Q 的取消仍只有一個受追蹤 handle，並非所有 `Tutorial` 或其他共享圖片的全域清掃。舊圖若已自然移除，查表可能找不到；取消仍清 `M+40`，新圖再正常發布。handle wrap、其他 owner 破壞 tracking、任意 runtime 重綁均不在這個正常串行結論中。[`q_flying_cancel`、前輪共享 manager 證據]

取消位於 allocation／constructor 之前，也沒有由該完整 body 建立「後面失敗就回復舊圖」的交易契約。這裡只主張已發出的取消不能當成未發生；不把 allocation 失敗描寫成有正常錯誤回傳的安全 API。[`q_flying_create`]

### 3.3 跨 End／Start 的圖片交接

在所選正常 Start 本體沒有直接清 `M+40`，正常 End 也不是圖片總 reset。若 A 圖仍由該 handle 追蹤，B 的第一個 `FlyingObject` 會取消 A 圖。這可作明確的「新圖取代舊圖」策略；若需求是 A 自然完整淡出，再開始 B，就必須由內容時間與可達入口另定順序，不能一面建立 B，一面承諾 A 的自然終點不受干擾。[`q_start`；前輪正常 End；本節替換鏈]

原 qbase 的 `FlyingObject` helper 只傳7參數給 `Q.FlyingObject` 再呼 `yield` 一次；它沒有回傳可查的完成 token，也沒有一個「圖片自然刪除」ACK。`DelFlyingObject` helper 則直接呼 native取消。不能用 helper 返回或一次 yield 作實際畫面完成判斷。[qbase P38／P39]

## 4. 第二次 Start 實際重設什麼

下表限定同一 Client context、相同正常原件 bindings／globals；外部 UI event、callee、腳本與其他 owner 仍可另外改狀態。完整 Start 的直接觀察不構成「一切間接效果絕不存在」的全稱定理。[`q_start` 完整 body；來源 pin：VM lifetime／scheduler、A1、one-shot、前輪生命週期]

| 狀態 | 正常 accepted Start 的實際工作 | 第二次使用的契約 |
|---|---|---|
| Q active／quest／scene | 檢查 `M+28`；accepted 後寫 `M+38/+3C` 和 active=1 | 不能把 busy Start 當已啟動；也不能由欄位寫入猜 callback成功 |
| review flag | `5617C6` 先清 `M+89`，位於 busy return 之前 | 重送 Start 不是完全無 side effect 的讀取 |
| Q actor tree | Start 本體沒有直接呼 `DeleteAllObject`／清 Q tree | End A 後保留的 slot 不會因 Start B 自動成為空 slot |
| 最後圖片 handle | Start 本體沒有直接寫 `M+40` 或 call `564A60` | B 首圖按§3取消繼承的上一張；沒有首圖則不能由 Start 假定已取消 |
| Camera current／snapshot | Start 不是 Stop＋Detach＋Pop 的配對 reset | 舊 work／共享 snapshot 必須由已知持有者處理；無新原生 owner token |
| 模型預掃描 | `561AF3` 呼 prepass，`561AFA` 更新 `M+70` | 同一 prepass VM 重用，但這次 collector會先清；不是重建所有 Lua globals |
| level 3 模型工作 | job+4=3，job+8=1；提交並 wait | 不論新collector是否空，都有 level3 replace語義；見§5 |
| 正式 VM／qco | 仍用 `[M]` 的 wrapper；模型工作之後 `561C7D` 才載正式 seq | Start 本體不先重建 qco；正常 End 的清理才是已知邊界 |
| 最終音樂字串 | `561A06..561A17` 用空字串設定 `M+44` | 上一段尚未被 RestoreMap 消費的 finalMusic 策略不能默認跨 Start保存；不等於當場Stop音樂 |
| point gate | 正式 loader 返回後 `561CCE` 清 `FB7A04` | 不是清世界物件、圖片或相機snapshot；也不是成功 ACK |
| 模型目前層級 | 正式 loader 之後 `561CF8..561CFF` 設level2 | 不應把「prepass用level3」外推所有之後工作都固定在3 |
| seen／map backup／共享flags | 本體無通用全reset；具體既有consumer各自管理 | 同鍵重試、單層map backup、show/slow/letterbox都保留既有約束 |

完整Start的seen／skip分支還會在 `5618CD` 呼native Stop（`5620B0`）；本包絕不把Start全體說成「完全不呼任何cleanup」。所列清樹／圖片／camera直接call缺席是指定入口的有界檢查。Start還會在某個前置flag非0時先清 `FBAB24` 並將 world+AC 設0.1，這發生在active gate前；後續 `5619D1` 發出 `F4358` event，既有研究已把它接到頁面/controller切換。因此「Start不直接清camera current」不表示完整第二次啟動一定保留原畫面、相機或正常戰鬥操控。這也是有限插播 A 與不中斷 B 必須分開的原因。[`q_start`；來源 pin：`MEF-one-shot-followup-20261116/REPORT.md`]

### 4.1 coroutine 與兩個 VM

預掃描 `55D6A0` 先 `55E2E0` 清 collector，清其音樂字串，再重綁六個收集 globals，最後以 `P+4` 的同一 wrapper載seq；`Register` 的這一版是 `55D560` 同步執行callback。正式 qbase `Register`（P75）則 `coroutine.create(f)` 後交 `f_registerCoroutine`（P1）加入既有 qco。兩者不是同一輪「先清 coroutine再跑一次」。[本包 `prepass_load`、`prepass_register`、qbase P1/P75；VM lifetime原報告]

正式 `f_removeAllCoroutines`（P3）呼 qco的方法；正常 End 才呼到該函式。P2把 `Q.EndCutScene` 交給既有 scheduler；其用途須依前輪已解的異常處理分支理解，不能把 callback單純 return當成自動正常End。若內容需要後續cleanup，應在 End之前的合法排程完成；End之後追加 `wait;cleanup` 不是另一個背景runner。[qbase P2/P3；scheduler原報告、前輪正常End]

不建議用重新載 `qbase.lua` 猜測重設：它會重新建立qco及其他全域，並非已證的每run生命周期API；也沒有替圖片、模型、camera或Server run自動完成配對。

## 5. 模型預載層、CDoll引用與 actor生命週期

### 5.1 Start(B) 的前置資源工作

`561B38` 設level3，`561B3F` 設replace=1；`561B63` 從collector取低WORD模型值加入向量。`561BF9 → 79DCE0`提交後，`561C03`以無限等待值等待event，再close handle，之後才 `561C7D → 6F4A50`載入正式seq。Wait返回值未在此作成功／失敗分支，不能升格為全部模型／動作已成功載入的ACK。[`q_start`]

`7A03B0`工作從owner的四層 stack處理模型引用；replace非0時，以job+4為起點清除相應及更高層。level3因此只處理第3層。它在 `7A0529` 對舊模型資源+5C減1，對新向量中的有效模型在 `7A0701`加1，最後再依每個受影響模型的總引用狀態選擇續駐／回載或卸載。[`model_replace_worker`]

新collector為空不會跳過「替換舊3層」；它只是沒有新模型可加回。若B也要求同模型，減1再加1在最後處理之前完成，或其他低層／已正常apply的CDoll仍持有該模型，總引用非0就不走零引用卸載。追加的 `79EB03`／`79ED76` 證明CDoll取得／放回的正是同一R+5C；預載層不是全部持有者。[同body；CDoll補證 §5–6]

### 5.2 不是只清一個帳本：零引用會走實際釋放

| 接點 | 原件動作 |
|---|---|
| `7A098E..7A0995` | resource+5C非0，呼 `7C5BE0` 續駐／回載路徑 |
| `7A099C..7A09A2` | 引用為0且resource+60非0，呼 `7C4FF0` |
| `7C5018` | `7C4FF0`再要求resource+58==1才執行主要卸載 |
| `7C50CE → 7C4100` | 遍歷模型子項／其指標向量，對非NULL呼 deleting virtual(1)，清指標與子項state，縮掉向量 |
| `7C50D5 → 7C4940` | 在+60非0時釋放選定檔名資源、呼另個清理owner；若+EC非NULL則delete並清pointer；最後+60=0 |
| `7C50DA` | 將resource+58=0 |
| `7C5C0F..7C5C1B` | 回載反向gate為+5C非0且+60==0；正常所選路徑末尾設+58=1 |

這條鏈證明總引用為零時確有實際釋放；**不能據此推導正常保留的Q actor會因單清level3失去模型**。已正常apply且尚未放回的CDoll引用仍計入R+5C，使所選replace最終走非零路徑。零引用反例只適用於沒有CDoll及其他持有者的前提。Q tree是否含actor、Doll狀態、預載層與資產readiness仍須分開；本包沒有提供同時證明全部模型／動作已可畫的Lua完成查詢。[本包資源body；CDoll補證 §5–8]

### 5.3 `DeleteAllObject` 的完整作用域

`563A70..563C37`先清全Q actor tree，並在 `563B1D → 823850`移除樹節點；然後建立空向量job，`563B61` replace=1、`563B67` level3，提交後等待；最後清M+60的按需模型集合。它沒有把M+70 collector一併重建或清空。[`q_delete_all`]

因此 `Start(B) → Register(B) → B callback: DeleteAllObject → CreateObject(B)` 有兩個明確作用範圍：

1. B的正式callback之前已跑過新level3 replace；A的預載層被替換，但正常保留CDoll的引用不因此消失。
2. B callback中的全清又提交空level3 replace；它不會辨識「這些lease是B剛準備的所以保留」。

後面的 `CreateObject` 已有明確回載鏈：`5630BE`在catalog+54非NULL時雖跳過 `541610`，但 `56322E`仍呼Q專用 `4D0FE0`，傳1到共同初始化後發出immediate CDoll request。worker `79E9D1`取同record+54的R、`79EB03`加引用，再 `79F045→7C5BE0`以R+60==0作resident回載gate；資產與instance正常產出後apply原D。因此不能把這個排序單憑清level3判成必然無法顯示。正常event／state1仍不等於所有part、motion及render readiness已成功，failed state3亦不由tick自動retry。[`q_create_actor`；CDoll補證 §4–8]

還須分清完成邊界：DeleteAll清Q tree後排入的level工作，與Doll request／deferred apply／release是不同工作。等待level event不等於全部queue drain；pending request/result透過strong pair保留原D，callback仍指向原D，並非依B當前slot重找actor。[CDoll補證 §6–7]

既有same-slot規則亦維持：正式Q樹key是DWORD、預掃描key低WORD、actor身份含低BYTE；已存在slot不被正常CreateObject簡單替換。單一 `DeleteObject`仍是stub。不能以「換slot就好」略過資源、身份別名及真實slot配置，也不能在本包杜撰新slot數字。[來源 pin：`MEF-content-contracts-20261116/actors/report.md`]

## 6. 兩種可落實但尚待內容綁定的規格

下面是 **NOT_NATIVE_MEF** 設計契約，不是已部署seq。機讀版本見 [reuse-contracts.json](reuse-contracts.json)。不偷偷新增scene key、替換A1的`quest=0/scene=32760`政策、加入原生owner token或假定新slot無衝突。

### 6.1 有限效果 F：單一合法入口啟動，native自行結束

初版可選正數淡入／淡出計數、有限hold的單張圖片，或前輪已證的有限FadeIn。發布前要綁定真實資源路徑、hash、Client內容版本及合法入口；目前保持UNBOUND。若會接在上一段之後，先明確選「新圖片取代上張」或「上張自然結束後才開始」，禁止同時承諾兩者。[§3；前輪有限fade/image鏈]

需要Q結束後繼續時，End只終止腳本排程，有限native效果依既有gate自行推進；不在End後排一個幻想中的Lua timer來清理。這種最小內容應避免新增持續Q actor、需要還原的camera snapshot、永久hide/slow/letterbox、未定義的共享音樂切換與map backup。這是降低整合依賴的內容規格，不是聲稱這些能力永遠不能用。

完成條件分三層：靜態資料與ABI綁定；實際畫面/聲音與時間驗收；Server業務結果。`003F`、`00EB`、一次yield或圖片消失都不升格成三層共同成功ACK。沒有已證完成getter時，驗收只能靠選定測試與可觀察畫面，Server timeout只記錄政策結果。[A1、one-shot與前輪Server handoff]

### 6.2 連續兩段 S：先選場景邊界，再配資源

| 方式 | 可採用條件 | 必須處理的缺口 |
|---|---|---|
| 同一次Start內的phase A→B | 同一演出控制權、兩階段內容能在同一qco中明確排序；不要求每phase獨立Server run | 預掃描同步掃完整callback；ClearObjects在prepass不會重設collector。同一slot改model可能仍只收第一個model，不能默認後段依賴已準備。中途DeleteAll清level3，但有效CDoll回載鏈已閉合；仍需真實slot/model/action表、資產與render gate，以及全Q樹清理ownership |
| A完整收尾／End後再Start B | A持有全Q tree與用到的共享狀態，能在End前完成cleanup；B有已綁定且通過seen／skip政策的合法入口 | B的scene/quest、slot/model/action、資源都要實際綁定；禁止以A1同鍵重送當重播，也不預先指定不存在的第二鍵 |

若需求是「同一scene key第二次播放」，本輪只證機制可在哪些狀態保留／替換，尚未建立可以通過既有seen／skip政策的重播契約。A1原本一次／Client epoch限制仍有效。需要重播時，Server需求應先定義何時允許、如何拒絕重送、如何與Client版本和已播狀態對齊，再找真實可用內容入口；不是任意加1換key。[`q_start` seen分支；A1／one-shot原規格]

### 6.3 合法清理的必要偏序

以下只在確認同一內容仍持有共享狀態的前提使用。它是整合時的必要依賴，並非所有內容都必須觸碰每個owner。

- **停止自己的camera work → 解除自己的current → 配對恢復自己建立的snapshot。** Detach先清current會讓後續Stop失去該入口；pop沒有原生run token，不得盲pop或重試耗掉別人的frame。若AttachCamera依賴Q actor，先完成camera停止／解除，再移除actor。
- **完成本段角色操作 → DeleteAllObject（限全Q樹都由本段持有）→ 等待函式內level工作返回 → normal End → 下一次Start/prepass。** 這避免B剛建立的level3被A的尾端全清掃掉；不能把這個wait提升成全部Doll request／apply／release完成的barrier。
- 圖片若不跨End：明確Del後才End；取消與物理刪除分開驗收。圖片若刻意跨End：以自然有限終點或下一張替換策略管理，不再把它算作必須保留的多張Q永久圖。
- 自己改過的world visibility、slow flag、letterbox及map/camera配對，依已知baseline還原；音樂依共享pool政策保留或切換。這些收尾與圖片標記通常可各自完成，但都必須在要求其完成的handoff邊界前有合法執行時機。
- End之後不可期待原qco自動完成剩下步驟；active Stop也不是inactive reset的替代品。外部取消若沒有可達cleanup入口，就保持「尚未完成中斷清理契約」。

上述Stop／Detach／Pop、normalEnd、旗標與音樂的native子鏈復用前輪；本輪新增的是它們與下一次prepass／模型替換的先後關係。Camera快照、全Q樹、圖片最後handle及音樂pool並未獲得新的per-run原生owner識別。本包規格中的run紀錄只可由整合層／Server持有，不能冒充Client已提供token。

## 7. Server開發需求

| 需求 | 建議的可交付行為 | 與Client證據的界線 |
|---|---|---|
| 演出run排他與重送處理 | 為Client context記錄允許內容、前段狀態、取消/超時、下一段是否可派發；同請求去重 | 這是Server實作；不得假定Client busy Start完全無side effect |
| 內容／資源manifest | 綁scene tuple、路徑、原件版本、hash、model/action/slot與需要的owner | 所有實值須驗證後填；不使用示意key作正式配置 |
| 串行handoff政策 | 要求A cleanup完成的可觀察證據或明確降級政策後才放B；未知即記unknown/timeout | 既有003F不證明全owner回收；沒有新ready/cleanup ACK不能杜撰 |
| 中斷與斷線策略 | 不把中斷當成功；保存權威任務/場景進度，定義重新入場/恢復路徑 | Client inactive Stop不能當全清；真正可達cleanup入口仍需Client證據 |
| 單次／重播政策 | 保留A1一次政策；另設重播內容版本與合法入口驗證工作 | Server決定可重播不等於原Client seen gate被解除 |
| 戰鬥與業務權威 | 怪物群、傷害/HP/死亡、掉落、通關、解鎖、資產與持久化仍由Server實作 | Q actor模型退駐／圖片替換不提供world群組死亡事件 |

不要把以上需求塞進「Client待逆向」而停止Server開發；同時不要因Server能建立狀態機，就聲稱缺少的Client cleanup ACK／不中斷首次入口已存在。

## 8. 未閉合鏈與下一步解除條件

| 優先 | 具體問題／候選 | 已知來源 | 下一證據與解除條件 |
|---|---|---|---|
| 已閉合 | 同一catalog+54資源的CDoll取得／回載／釋放及render接點 | [CDoll補證](../reuse-followup/report.md)：實際Q direct call傳1；`79EB03/79ED76`對稱引用；`79F045→7C5BE0` | 正常有界鏈已完成，不再列P0未知。限制為catalog identity、資產／instance成功、callback執行與render gate；state3不自動retry |
| P0整合 | 單Start兩phase需要換模型但沿用相同slot | R9 prepass first-slot model／action union、ClearObjects stub；本包DeleteAll；CDoll正常回載已證 | 給真實兩phase slot/model/action表，逐筆核prepass與正式取值、全樹清理ownership及資產gate。新slot只能經真實分配檢查後選，不能當預設解法 |
| P1 | 跨Start的camera／snapshot完整restore是否被F4358及新work干擾 | Start `5619D1`；R11 camera、one-shot頁面事件鏈 | 在相同context把前後controller及camera current/snapshot所有具體writer接好，選定真正場景流測畫面；目前只有有條件持有契約 |
| P1 | 外部中斷A後沒有A callback，如何合法清全Q樹並界定pending callback完成 | qco清除；Stop active gate；CDoll strong hold及level event非全queue drain | 找實際可達的cleanup／transition teardown及所需drain證據。不能把正常Doll誤判成僅因level3替換便卸載；另開scene亦不能冒稱A-only清理 |
| P1按需求 | 同一state3 CDoll原地重試 | CDoll補證 `7A5CA1`排除3；`7A913A`寫3 | 若產品確需此能力，追合法caller到D+24其他writer，或採具owner條件的全清重建。正常同R回載成立不等於該failed物件已有retry入口 |
| P1 | 原版callback重新入場／共享receiver重綁 | 正式和prepass VM共存、R11／本輪總ABI工作 | 以真實table binding和receiver globals writer核哪個VM呼到哪個owner；不要靠函式名稱或上次保存closure當永久instance handle |
| P2 | 相同scene鍵合法再播及Client seen一致性 | Start seen分支；A1／one-shot | 綁定已驗證的場景列、入口和明確重播政策，核skip分支與003F順序；目前保留未配置，禁止猜新鍵 |

這些是可繼續的具體靜態工作，不是因本輪未執行遊戲就宣稱永遠無法完成。原官方MEF首次reader/grammar、不中斷普通戰鬥B入口仍由整體研究另列，不由本包的圖片勘誤或資源交接掩蓋。

## 9. 驗證、勘誤效力與重跑

驗證器讀原件、核PE mapping與完整指令端點、檢查22條call和三組順序、逐個核固定Git來源blob，審讀並以實際SHA pin匯入data-only parser重查原Event/qbase。它沒有聲稱完成全程式資料流形式證明或所有callee副作用排除。

新 [reference_model.py](reference_model.py) 的10個案例是 **SYN**：6項圖片取消／延後回收案例，加4項明示 **zero-doll projection** 的預載層案例。後4項只適用於沒有CDoll與其他持有者，已改名與加註，不能推論正常保留Doll的駐留結果。完整的Doll lease、同R回載、callback強持有與失敗gate正反例見 [補證的12項SYN](../reuse-followup/reference_model.py)。這些都不是原Client模擬或遊玩測試。

需要特別聲明歷史驗證器的版本pin：`MEF-full-surface-native-continuation-20261116/audit.py`硬編parser SHA `3a7e2751...`，但基準Git的 `MEF-parser-executor-storage-20261114/verify_evidence.py` 真實blob為 `8e6e3c51c55a0bb155f05165b496d7d519fb7b7e`，SHA為 `8eb16bbc06940769197b2a3446c66a024a3e98d1c44f035ce69c4fee36212a56`。工作檔與Git內容一致、不是CRLF差異。本輪完整審讀現存版本後以後者pin使用其資料reader；**沒有把舊總包當成本輪重新跑過PASS**，也沒有改舊檔來掩蓋差異。[source manifest]

重跑命令（把原件及repo參數換成自己的唯讀來源路徑）：

```bash
python -B verify_evidence.py \
  --bin /path/to/02-Tartaros.bin \
  --event /path/to/06-Event.stp \
  --repo /path/to/ttr_anal_multi \
  --out verification-result.json
```

實際結果存 [verification-result.json](verification-result.json)。PASS只表示本包列明來源、機械檢查與明示合成例一致，不表示部署、Server完成、RR ACCEPTED、T01 FULL-PASS或官方MEF全功能完成。舊完整ASM的真實字節仍有效；被更正的是指定報告敘述與指定SYN預期，效力範圍逐項記在 [errata.json](errata.json)。
