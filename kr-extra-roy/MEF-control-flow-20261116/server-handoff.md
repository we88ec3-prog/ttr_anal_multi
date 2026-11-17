# MEF 控制流程：Server 開發與內容整合交接

本文件承接已公開 R9 的 [完整 Server 交接](../MEF-end-to-end-20261116/server-handoff.md)，補入本輪錯誤控制、清理 owner 與演出 observer 的實作要求。上位沿用 `REQ-0019`／`REQ-0021`、`SPEC-FLOW-0001`／`SPEC-SCENE-0001`／`SPEC-CHAR-0001`；本文件不是新 REQ／RR 台帳，不變更正式狀態。基準 main `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc` 與 R9 `ad9ea950216923b5e351a7501d38e006df57a4c6` 的來源均已固定。

## 1. 可交付的開發單位

第一個具體單位仍是**有限、排他的 Q 演出**：相符版本內容與SceneList → 有限prepass依賴 → formal outer → 有限module頂層 → inner entry逐次執行 → 分類return／error → 依持有資源清理 → 必要後置條件成立後最後End → Server依原回報與自己保存的run狀態對帳。

這是相容新內容設計，不是原生MEF檔案規格復原。合法場景雙鍵、funcName、資源路徑、export key、版本、model／slot／座標尚未配置；本輪沒有產出部署資源、模擬成功或遊戲執行結果。ordinary戰鬥長駐腳本仍受第4節Client缺口阻擋。

## 2. Server 待開發：完整責任與完成條件

| 開發項目 | 具體工作 | 已證Client契約／驗收限制 |
|---|---|---|
| 內容發布與可見性 | 保存build、邏輯path、來源、hash、依賴；按已知更新通道發佈與啟動 | launcher交付、package優先、checksum與cache分別成立；檔案落地不能代替實際loader選取。沒有新的gameTCP傳檔opcode。 |
| 場景索引／請求 | 管理quest／scene雙鍵到funcName的合法版本；確保啟動時索引一致 | 0047讀signed WORD雙鍵，選`Event/Sequences/<funcName>.seq`；不是任意path或blob。MapID、TRIGGER、QuestInfoID不能混當同一鍵。 |
| 接納與序列化 | 同一Client只安排合法的排他Q run；保存已要求、接納、正式開始、結果與取消狀態 | busy不排隊，mode可在busy檢查前被改；盲重送不等價安全重試。 |
| 依賴／型別檢查 | 內容產生器檢查prepass WORD slots/models/actions、正式DWORD Q slots與actor位寬；核先Create後動作、模型一致與合法參數 | collector錯誤可能留下部分結果；wait/event/helper return並非全依賴成功ACK。拒絕猜造model／座標。 |
| 雙階段與module export | 實作R9當次lexical phase；每次辨識本run export／版本，module頂層有限不yield | prepass同步、formal延後；兩VM各有持續globals；DoFile numeric0成功／1失敗但兩者都truthy，不回module table。 |
| 新outer／inner adapter | qco只登記outer；inner只由outer持有；每次visit最多resume一次，零resume引數，context由closure傳入 | 普通inner error可回outer；create／capacity／outer／cleanup/native故障不在普遍catch保證內。這是待實作內容層，不需假造Client native callback。 |
| 內容結果分類 | 分開normal return、普通Lua error、協作取消、timeout、skipped、未知中斷；對return payload給明確業務定義 | `resume(true,false)`是正常return；error TValue可為nil/false/table，不能用error值truthiness。正常return不自動End、不自動發獎。 |
| run身分與對帳 | Server自有session／generation／run identity，關聯目前雙鍵、版本及狀態；處理遲到或重複回報 | 原003F沒有新run token，不能把自訂欄位塞入未證wire位置；inner local結果也沒有自動傳回Server。 |
| effect acquisition ledger | 記錄已確認持有的Q tree／image handle／T tracking／camera works／override depth／map snapshot／display flags；保存partial/unknown狀態 | ledger不是transaction；native錯誤前可能已部分改變，不能一律當未發生。共享native singleton需要排他或已證仲裁。 |
| 正常清理順序 | 按合法owner挑選cleanup；參考Stop原順序camera works→RestoreMap→DeleteAllObject→EndCameraOverride→display→image sweep→End | End先清active；End後Stop跳bulk。相機pop會先移除再比名；map只有一份且Restore會改backup。不能把重試當無副作用reset。 |
| 型別化圖片取消 | Q圖片、Tutorial Skip／Scaling分開管理；納入共用G sweep跨namespace影響 | Q.Del僅mark；Skip／Scaling需T標記後下一eligible tick才回收；Stop sweep單獨不標T。CFlyingImage predicate不同可被同步sweep。 |
| 非同步清理結果 | 分別保存cleanup requested、必要後置條件、錯誤與pending；必要條件未完成不能標restored | sepia End置4，需後續3次native update到0；圖片有自己的刪除時機。呼叫返回不等於視覺完成，沒有本輪已證固定timeout。 |
| 演出observer使用 | Prolog、Book、Q stopped作各自編排條件，保留開始與取消／失敗狀態 | Prolog0可因缺key／close；Book State2須FB72AC==0；Q stopped不含死亡；圖片wrapper只yield一次，不wait完成。 |
| 輸入恢復 | 分開input mask、current controller、page／dialog與其他owner；使用原numeric ABI | mask `0x2`是bit index1；清mask不清controller+58；Q pause前仍有controller writer，world正countdown另可寫busy。 |
| 原wire回覆／等待解除 | 按原場景路由與保存的run狀態處理003F和適用00EB | 003F 8-byte application為雙鍵low16＋末WORD1，skip也可送；nonzeroquest End要求converted CheckConfirmMessage==1。00EB只解dialog／mask，不是Stop／result ACK。 |
| 取消／斷線／轉場策略 | 明定外部owner取消、timeout、重入、舊generation事件的處理；選用已證合法路由 | suspended outer被移除不會自行跑cleanup；當前frame可能仍執行。不存在本輪新增的wire取消旗標setter，不可假設協作取消能由Server直接寫Lua context。 |
| 權威戰鬥與群組 | Server實作HP／死亡、encounter membership、剩餘數量與移除／重生／換圖原因；區分成功、失敗與取消 | 演出inactive、圖片消失、走位停止不能取代ordinary戰鬥結果。Client ordinary observer未閉合時，Server規則完成不等於MEF替代已完成。 |
| 任務／資產持久化 | 依權威條件提交進度、獎勵、角色與背包／金錢變更，處理重複與取消 | 003F或resume true單獨均不足以發獎；不以導航里程碑代替正式結算。 |

來源：[完整流程主稿](../20261116-092138-chatgpt-web-roy1-MEF-control-flow.md)、[supervisor](supervisor/report.md)、[presentation](presentation/report.md)、[runner](runner/report.md)、[world](world/report.md)，以及上方固定R9交接內的逐項原件引用。

## 3. 建議的結果模型與取消邊界

下表是Server／新內容待實作的概念欄位，**不是原件封包欄位或已存在的Client回報API**。若某個local結果尚無已證傳輸介面，Server只能記錄「不可觀察／未確認」，不能假設收到它。

| 概念 | 目的 | 已有觀察限制 |
|---|---|---|
| requested／accepted／formal_started | 不混淆發請求、busy gate與entry真正開始 | 原wire未對每階段提供本輪新增ACK。 |
| entry_outcome | returned／Lua error／cooperative cancel／unknown | inner普通error可讓outer分類；外部中斷／outer失敗可能無local結果。 |
| result_payload | 有明確業務定義的至多一值結果 | false/nil與Lua錯誤布林分開；沒有自動wire傳輸。 |
| cleanup_attempted／cleanup_errors | 保留每個已選步驟與錯誤 | 不能只用單一done bit覆蓋partial狀態。 |
| pending_native_effects | 記錄仍需native frame／owner的釋放 | 必要pending未解前，所選supervisor骨架不標restored或成功End。 |
| original_003f_observed | 原協定回報事實及所關聯雙鍵 | 不證明module開始、成功或所有資源恢復。 |
| authoritative_result | Server的成功／失敗／取消、持久化與獎勵 | 由權威任務／戰鬥條件決定，非演出getter替代。 |

所選adapter在必要cleanup條件成立後才最後End並立即return。如果cleanup policy不成立或自身失敗，可能留下active Q；Server不能把outer return／list空視為恢復，必須有與實際Client owner相容的外部失敗策略。該策略尚未配置，本輪沒有把00EB或不存在的Q.Stop當通用重置。

## 4. Client 待逆向：Server 不能猜補的介面

| 缺口 | 本輪後仍欠的具體證據 | 已完成的有界排除／限制 |
|---|---|---|
| nativeMEF首載入／schema／executor | MapList.TRIGGER名稱真正進path/buffer、open與parser/executor的正向鏈 | R4/R5所查caller；本輪RestoreMap是FB74B0／FLD；新module設計不是原生caller。 |
| ordinary背景Lua runner | callable登記／storage→普通場景recurringproducer→同owner input／pause／cancel／reentry | R7/R8既有pump／checkpoint，R9debughook，本輪圖片Register與fixedUIevent均不能供此完整契約。 |
| 世界typed identity | 可供腳本與Server協調的已註冊ID/handle輸出，包含位寬／collision／update／remove | lbCreateObjectEx不pushID、0007 hit skip；Q slot、image DWORD、固定Isilia不同域。 |
| ordinary死亡／清組observer | 同world對象／group的writer→Lua getter或真實callbackcaller→普通contextconsumer | Prolog／Book／Q stop／Tutorialflags是其他語義；fixedUIevent沒有補出它。 |
| 更強的演出終止保證 | Book FB72AC完整writer/reset；特定缺資源／空內容行為；PrologCloseCallback真實nativecaller | 已證局部state machine及nativeclose不保證所有情境終止，也不證native會叫同名Lua函式。 |

ordinary敵人自主決策的主責仍依T13／RR-0013；本輪不重派、不修改QUEUED、不把有限演出或權威Server設計冒稱該RR已完成。

## 5. 跨功能整合與驗收

先由內容端配置有來源的合法鍵與資源，完成唯一outer的bridge／module／entry、相符依賴和typed cleanup policy。再由Server使用原協定安排單一正常run，觀察實際選中資源、正式entry、演出對象、必要native完成條件、End、適用回報／wait解除與輸入恢復。

有限Q演出的驗收不能冒稱ordinary戰鬥交接。若主張某原Server責任已由MEF接手，需明確停發那項原Server指令，取得Client仍完成同一操作、世界／進度結果相同的對照。Server仍代做生怪／開門／清組的測試，只能驗證目前混合流程。

本輪只做唯讀靜態核對。故障／壓力／取消／重入／斷線等案例已列設計界線，實際擴大測試遵守現行正常流程優先序與後續排程；沒有擅自執行。正式T01核驗、S00接收、Server實作與人測各留原責任及狀態。
