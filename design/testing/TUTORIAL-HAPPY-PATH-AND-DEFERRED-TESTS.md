# 新帳號完成新手教學進入廣場：正流程與待測試清單

最新正流程：15個cases，三怪已納入第六列真TCP／SQLite旅程，包含持續正常輸入下的
AI命中、三怪全滅、勝利保存、返回與蘋果招募。208方法／10正向方法／198暫緩。
見 [world定時更新修正](../../governance/s00-iterations/S00-20261101-CONTINUOUS-INPUT-WORLD-TICK.md)。
這不是壓測或Client完整驗收；其他測試仍暫緩。

最新排程：戰鬥第一優先（REQ-0016）。蘋果招募通過；後續兩段劇情後留原地另記REQ-0017，
於戰鬥之後修復。完整正常教學→廣場目標不變；其他測試仍暫緩。

最新v4人測：蘋果招募出現，使用者確認後進入下一段教學。下一提示內容與後續出口待核對，
不能把這段通過當完整教學／廣場驗收。

最新人工結果：v3 編隊頁關閉、首戰完成並返回；載入畫面仍 UNCONFIRMED。
蘋果家劇情後停住，招募接續候選已通過13正流程合成案例，人測待回。
見 [REQ-0015規劃](../../governance/s00-iterations/S00-20261101-PINKO-RECRUITMENT.md)。
招募重送／錯序／並行／斷線恢復／過期lease／部分傳送與DB失敗列待測，現在不執行。
下列舊版待回文字保留歷史；後續任務／戰鬥／廣場仍待完成。

最新：[05/09教學進場候選](../../governance/s00-iterations/S00-20261101-TUTORIAL-ENTRY-PHASE.md)。
13正流程合成通過；v3人工編隊關閉、換場、攻擊／返回結果待回。entry-pending重送、
錯階段09、斷線／過期lease／partial-send與UI事件競態記為待測，現在不執行。

最新：[首戰載入與B0誤判修正](../../governance/s00-iterations/S00-20261101-TUTORIAL-FIRST-BATTLE.md)。
13 positive cases／5旅程rows／9方法；總207方法、198暫緩。使用者v1設定完成仍卡編隊頁；
v2不等B0直接初始化，實際進場結果待回。AI反擊、成本、波次、Quest14/16、獎勵及廣場
仍是當前正常流程開發，沒有因先做單敵prototype而取消。
新增待測：戰鬥／裝備及結算重送、active-run重登、過期lease／死亡與勝利競態、
kit／win DB失敗與partial send、migration部分狀態／未知版本、clock及combo邊界；現在不執行。

v2人工已確認換圖／敵人出現，但編隊頁仍開著、缺原版換場畫面（直接停頓進場）。
先修完整scene／UI／loading及返回生命周期，再請使用者繼續戰鬥；不當作已可戰鬥。

最新：[NPC保留／首戰編隊](../../governance/s00-iterations/S00-20261101-TUTORIAL-NPC-AND-FORMATION.md)。
**使用者實測切角後伊莉西亞仍在，編隊頁可看到她**。目前12 positive cases／9方法，
總207方法、198暫緩。停在編隊頁，未按入戰。預選伊莉西亞體驗由使用者確認目前正確，
僅要求釐清來源，不把它列bug或臆造官方鎖定規則。
新增待測：targeted-delete／舊input生命週期、unknown prefix、重複grant／編隊請求、
lease／grant競態、交易或分段傳送失敗、錯scene／未取得角色、編隊容量／強制名單邊界；
現在不執行。正常戰場載入、技能／戰鬥、結束返回及後續任務仍屬當前開發。

目前最新：[移動、朝向與切角候選](../../governance/s00-iterations/S00-20261101-TUTORIAL-MOVEMENT-CAMERA-SWITCH.md)。
**實測通過人物／HUD、方向鍵第一T、滑鼠移動與視角教學**；切角前出現朝向及殘留跑動bug。
新版補正常轉段／silent release stop、東向64及static Server pose切角，11 positive cases通過，
仍207方法／9正向方法／198暫緩；人工新版測到切角後下一T待回。
額外待測：watchdog／輸入同時抵達、過期lease／取消／partial read清理、壓縮層邊界、
資源SHA／格式不符、動態barrier、長時鐘間隙／倒退、長距離漂移與碰撞校準；現在不執行。

最新：[教學world候選與來源限制](../../governance/s00-iterations/S00-20261101-TUTORIAL-WORLD-BOOTSTRAP.md)。
仍207方法／9正向／198暫緩；旅程Theory增加world OFF/ON兩列，本次10 positive cases通過。
人工測到第一T點後下一段提示即停，結果待回。地圖／人物／移動尚未以遊戲驗收。
新增待測：foreign entity／role、重複B0／intro、未知input flags、多record、部分傳送／取消、
切角競態、斷線／重登、Client tick濫用、長時間漂移／碰撞權威／持久化、安全與壓測；現在不執行。
正常切角、後續教學／戰鬥／進廣場仍是當前開發正流程，不因上述待測而推遲。

使用者 2026-11-01 指示：「停權等不在新手教學進入廣場的正流程等測試請做紀錄現在不測試以後再測試，之後的都先專注在正流程的測試，其餘測試都先記錄為待測試，並整理出待測試清單」。

本文件是目前的**測試排程與待測試清單**，不取代唯一 REQ/RR/GAP/SPEC/TEST 台帳，不批准未知封包或移除既有保護。所有待測項目目前皆為 **DEFERRED／待測試（目前暫緩）**；只有使用者之後重新排程才執行。不要把它們當成現階段正流程完成的前置測試。

## 現在只測這條正流程

| 階段 | 正常操作與完成證據 | 現況／下一步 |
| --- | --- | --- |
| P01 建立新帳號 | 後台以指定 Client profile 建立一個有效的新帳號；該帳號尚無角色 | 已建立隔離測試帳號，指定工作副本正常登入已達 AUTHACCEPTED；帳號未有實際 Client 創角證據 |
| P02 登入成功 | 指定工作副本送出正常登入，Server 驗證，Client 接受正確回覆並顯示下一畫面 | 指定工作副本實測 C02 成功、回覆163B並顯示選服畫面；見本次 runtime 報告 |
| P03 選服／頻道 | 正常選擇一個有效項目並完成後續連線接續 | 工作副本人工正流程於06:33:01 UTC出現 PRIMARYHANDOFFACCEPTED；選服／分流身分接續已通過，後續已送空清單並收到C2S24，但使用者仍在選服；下一個初始化請求待補 |
| P04 創角／選角 | 新帳號建立第一個有效角色、出現在可操作清單並正常選取 | Server domain 有正向前置；實際 Client 未完成 |
| P05 進入新手教學 | 正確場景載入、角色可見、可以正常控制 | 待實作／實測 |
| P06 教學操作／戰鬥 | 依教學正常移動、NPC 互動、攻擊／技能、擊敗指定目標 | 待實作／實測；不加壓測或非法操作 |
| P07 任務／獎勵／離場 | 按正常順序完成教學任務並正常領取一次獎勵、觸發離場 | 待實作／實測；不加重送或重複領取案例 |
| P08 進入廣場 | 同一次旅程正常進入廣場，場景／角色／必要 NPC 可見，控制可操作 | 最終階段目標；尚未完成 |

以單一新帳號、單一有效 Session、正常輸入及預期操作順序推進。正流程遇到實際阻塞就排查該阻塞，必要的編譯、資料／索引格式核對與測試環境清理可以做。不得跳過未完成步驟，或把 Server mock、domain／合成測試成功宣稱為 Client 已完成教學進入廣場。

## 待測試清單（現在不執行）

下列 DT 編號只用於此清單導覽，不是正式 TEST-* 或新需求 ID。每項排程狀態均為 **待測試（目前暫緩）**；新增發現歸入對應列並補重現條件，不因已有測試程式就自動執行。

| ID | 待測範圍／案例 | 以後的驗證目標 |
| --- | --- | --- |
| DT-01 | N 天停權、永久停權、解封、停權到期、已登入時停權 | 帳號／Session 處置一致且保留紀錄 |
| DT-02 | 錯誤帳密、未知帳號、失敗次數鎖定及到期解鎖 | 拒絕、節流／鎖定不誤傷其他帳號 |
| DT-03 | 非法／空白／超長帳號與密碼、非 ASCII／未知 codepage、舊 credential profile 轉換 | 輸入政策與錯誤回應、既有 hash 保護 |
| DT-04 | 重複帳號／角色名稱、大小寫碰撞、非法角色名、角色槽已滿 | 不覆寫既有資料、不多消耗槽位 |
| DT-05 | 未登入、偽造／過期／撤銷 Session、跨帳號查詢與選角 | 權限隔離及 owner 檢查 |
| DT-06 | 雙登入、重登、舊 Session／舊 socket 清理、新舊 lease 競態 | 舊連線不能撤銷或操作新 Session |
| DT-07 | 登入／轉場斷線、idle timeout、取消、shutdown、中途重連 | 清理與恢復、無資料遺失或懸掛 |
| DT-08 | 同 socket 重複登入、封包重送／重播、亂序、重複建立或領獎 | 冪等／唯一性、不重複寫入或發獎 |
| DT-09 | 故意拆包／黏包、短幀、超長／零長、壞 checksum、未知 marker／opcode、壓縮錯誤 | parser 邊界、隔離與明確錯誤處理 |
| DT-10 | 多帳號／多連線併發、同名競爭、slot 競爭、登入／停權競態 | 交易／鎖／CAS 與資源界線 |
| DT-11 | DB 未建立／不可用／鎖定、provider 失敗、交易 rollback、磁碟錯誤 | 不假成功、不 fallback 空資料來源 |
| DT-12 | SQLite／PostgreSQL migration、未知版本、schema 漂移、多 provider 差異 | 唯一配號、版本與結構核對、失敗回復 |
| DT-13 | 備份、還原、故障復原、過期 Session prune／維護 | 完整性及可恢復性；不覆寫原資料 |
| DT-14 | 日誌 ACL、容量／輪替／保留、queue 滿／drop、IO 失敗、敏感欄位遮蔽專項 | 觀測可靠且不洩漏帳密／wire secret |
| DT-15 | WEB 後台 Host／Origin／CSRF、權限、未授權來源、限流／帳號枚舉 | 管理與安全邊界；正常建帳號以外功能待測 |
| DT-16 | 大量連線、長時間 soak、吞吐／延遲、memory／handle／thread、backpressure | 壓力、效能、資源回收與容量 |
| DT-17 | Encounter／Actor 錯 owner、stale generation、錯版本／狀態、重複事件 | 權威狀態與 fencing，不跨場景修改 |
| DT-18 | 非法技能／目標、取消／冷卻／費用邊界、異常傷害／死亡／重複擊殺 | 戰鬥負向、邊界及作弊情境 |
| DT-19 | 任務錯序、條件不足、重複交付／領獎、獎勵空間／上限、NPC 距離邊界 | 任務／經濟一致性與異常回應 |
| DT-20 | 教學／轉場／獎勵 commit 前後 crash、離場中斷、重登 checkpoint 恢復 | 任務與世界狀態可恢復且不重複發獎 |
| DT-21 | 其他 Client SHA、TC／KR 跨版本、不同語系／作業系統相容性專項 | 不把目前工作副本結果外推其他版本 |
| DT-22 | 部署、跨主機／多節點、外部曝光、正式安全／營運驗收 | 獨立部署與正式營運門檻 |
| DT-23 | 後台查詢／分頁／稽核／備份等正常建帳號之外的管理操作 | 管理產品驗收，與目前遊玩主線分開 |

## 主 Lobby 交接新增待測案例

以下為2026-11-01[主Lobby交接開發](../../governance/s00-iterations/S00-20261101-PRIMARY-LOBBY-HANDOFF.md)新增的具體待測輸入；**全部待測試（目前暫緩），本輪未執行**，沿用上方DT分組，不新增正式TEST ID。

| 對應類別 | 新增待測條件 |
| --- | --- |
| DT-03／05 | 修改alias／名稱／proof任一欄、跨帳號proof、空值／非ASCII；確認不建立或轉移Session |
| DT-01／05 | grant到期、Session到期／撤銷、簽發後停權；確認舊grant不能登入 |
| DT-08 | 同一proof第二次或跨連線重放、重複簽發；確認最多一次交接 |
| DT-06／10 | 雙登入／renew／選角與redeem競爭、source完成與target到達的交錯、舊close對新lease的影響 |
| DT-07 | grant前或交接中非預期斷線、idle timeout、取消／shutdown、retained grant到期清理；正常planned handoff已在正向路徑，不代表這些恢復測試已通過 |
| DT-10／16 | 多次並行redeem、64筆容量、alias碰撞／耗盡、長期無後續呼叫的資源回收 |
| DT-11 | 消耗grant前後provider失敗／DB鎖、transaction commit取消或錯誤，檢查無假成功／無空provider fallback |
| DT-09／21 | 錯SHA、非57B、constant/NUL/padding違反、本機profile以外編碼、不同版本／未知marker |
| DT-05／22 | key2 auxiliary與primary角色隔離；不可用第二次主Session Claim取代；其真正訊息仍需來源 |
| DT-12／20／22 | process重啟／多process／多節點、持久化grant、PostgreSQL轉移實作與復原政策 |
| DT-14 | reply／handoff／digest的log與例外遮蔽、owned buffer清除專項，不從ToString實作推稱已完成驗證 |
| DT-15／22 | 64bit短效proof對外曝光前的限流／線路保護／猜測風險審查，不以loopback正向PASS核准正式部署 |

## 已有測試與歷史結果怎麼處理

- 已做過的停權、壞封包、重送、舊 Session、併發、DB／日誌故障等結果保留，不改寫為「從未測過」。它們的**下一次測試**現在列為待測／暫緩。
- Server `51c5c740a4c5e9bc9e72f520b673a458e0e7361a`（合併 `b9453e7`）的 135 unit＋108 protocol，以及當時 WEB 停權／Session 清理的合成 PASS，仍只屬該提交與當時範圍；不是本次新執行或實際 Client 驗收。
- 原 Client、教學戰鬥／任務／廣場尚未做的負向／故障案例，保留為尚未取得證據，不能借用 domain／synthetic PASS 填補。
- 測試程式、SFD 與既有保護不刪除；現階段 CI／本地命令改用明確正流程 allowlist。混合正負向的舊測試整個暫緩，不為了方便而夾帶執行。
- Server 私庫另存 `docs/deferred-test-inventory.json`，以純來源盤點列出目前 **207 個 xUnit 方法定義：9 個明確正流程前置、198 個目前暫緩**。其中2項核對13／7A候選布局，最新2項是正常57B candidate與SQLite主Lobby交接到創角選角；並非遊戲登入成功。此數字不展開 Theory 資料列，也不代表所有方法本輪已執行；舊的正負向混合或非目前 allowlist 的方法同樣先暫緩。生成器只讀取來源，不載入測試組件。
- S00 的文件／索引一致性檢查與編譯屬交付維護，不是停權、故障或併發的 Server／遊玩行為測試，不因此擴大遊玩驗收聲稱。

## 執行紀錄要求

新增出口候選待測範圍（本輪不執行）：錯序／重播1000/10/12/13/14、正常結束與載入失敗同shape、
43重複／缺少／逾時／晚B0、切場景期間partial-send／斷線／lease過期、完成持久化與重登恢復。
目前只做獨立開關的正常「首戰→招募／劇情→69/43→廣場移動停止」TCP合成列；
不是完整Quest16／Client到達驗收，詳[出口規劃](../../governance/s00-iterations/S00-20261101-ORDERED-TUTORIAL-EXIT-CANDIDATE.md)。
廣場NPC另待測：模型／資源缺漏、不同NPC互動、半途傳送失敗、重複生成／切場景清理、
動態阻擋／角色體積與可達路徑；靜態點clear不能取代這些案例。
詳[NPC來源與候選限制](../../governance/s00-iterations/S00-20261101-SQUARE-NPC-CANDIDATES.md)。

每次只記：正流程階段、Client／Server SHA、測試帳號用途、正常操作步驟、實際結果、證據位置與下一個阻塞。新發現的非正流程案例填上方待測清單，**當下先不測**；待使用者重新排程後逐項記執行日期、適用版本與結果。暫緩不等於通過或不需要測。

## 登入回覆實驗接續

詳見 [本次觀察](../../governance/s00-iterations/S00-20261101-LOGIN-REPLY-RUNTIME.md)。新增一項真 TCP／SQLite 合成正向登入回覆與主線交接前置；此合成測試本身不代表真遊戲成功；另有06:33:01 UTC人工正流程的 primary 交接實測通過證據。正常選服遇到的阻塞如實記錄。DT-07／09／11／14 另待測：傳送取消／部分傳送、primary shape／未知 post-login command、provider／日誌失效、跨 listener 計數與 buffer 生命週期；現在不執行。

## 空角色清單接續

[零角色清單實驗](../../governance/s00-iterations/S00-20261101-EMPTY-ROSTER-EXPERIMENT.md)已接入transaction-authorized SQLite與69B候選回覆，第8個正流程前置通過。真遊戲roster/UI尚待人工正常操作，不能以合成C2S24升格。DT-05／09／11／14另記：非零DB名單／stale lease不可fallback空清單、header/name邊界、傳送／日誌失效、跨listener清理；現在全部待測，不執行。

## 冒險團命名／教學入口片段

[本輪完整規劃](../../governance/s00-iterations/S00-20261101-EXPEDITION-NAME-TUTORIAL-ENTRY.md)已對應私庫獨立opt-in實作，9個正向前置通過。
下一段連測為正常登入→選服→角色／命名→教學第一畫面；角色控制／移動仍待後段資料。
starter1/3、Unicode唯一性與30分鐘Session為Server實驗配置，不是官方需求。
DT-03/04/05/06/07/10/11/12/14/22另記：名稱邊界／正規化碰撞、不同帳號角色集合、
舊revision與續期後close、重送／重登、元件migration失敗／回復、C05多元件／PostgreSQL、
長連線到期與資源壓力；現在全部暫緩，沒有移除原測試或用正常PASS替代。
