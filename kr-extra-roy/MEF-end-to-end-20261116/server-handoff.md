# `.mef` 流程交接：Server 與內容開發需求

日期：2026-11-16（Asia/Taipei）。本文件是 `extra/roy1` 的研究交付附件，供 S00 依既有流程去重、整合；**不是新增 RR／REQ 台帳，也不修改任何正式需求、審查、實作或人測狀態**。

既有上位需求為 `REQ-0019`、`REQ-0021`，對應 `SPEC-FLOW-0001`、`SPEC-SCENE-0001`、`SPEC-CHAR-0001`；既有 MEF／城鎮服務交接沿用 SFD-0015／SFD-0016 的範圍。這些 ID 來自本輪核對的 main `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`，不表示其狀態已因本報變更。普通怪自主決策的正式 `RR-0013` 仍屬 T13／QUEUED，本輪不接管。

## 1. 可開始開發的最小單位

建議將第一個交付單位定為**一段有限 Q 演出**：發布相符版本的內容 → 已知 SceneList 雙鍵選中 `.seq` → 有限預掃描宣告依賴 → 正式登記 callback → 合法載入新 Lua 模組 → 使用自己的 Q slots 建立、走位、等待停止 → 明確清理與 End → Server 依目前執行狀態安排適用的等待解除。

這個單位能使用已證 Client 能力開發；其中新增 `.seq`／模組是**相容新內容設計**，不是原版 MEF 專屬格式復原。本輪只交靜態設計與分析，沒有新增可部署的 `.seq/.mef`，沒有修改原始資源。普通戰鬥長駐腳本、可戰鬥世界生怪與死亡／群組完成觀察，仍須下列 Client 介面缺口先成立。

## 2. Server 開發需求清單

下表每列是對既有需求的實作補充，不自行分配新的正式 REQ ID。

| 開發項目 | 玩家情境與實作內容 | 已確認的 Client 契約 | 完成條件／不得猜填的部分 |
|---|---|---|---|
| 內容版本與發布 | 進入新一段內容前取得正確檔案與依賴；記錄 build、hash、邏輯路徑及來源 | 原 launcher 啟動前 HTTP／gzip／普通檔交付；遊戲資源 resolver 有 package、fallback、checksum 與快取條件 | 真正被 loader 開到的內容與 manifest 相符；不能以磁碟有檔案代替可見性，不自造遊戲 TCP 傳檔 opcode |
| 索引生命週期 | 將可達的 quest／scene 雙鍵與 funcName 對應到內容版本 | `0047` 讀兩個 signed WORD，從已載入 SceneList 取 funcName，形成 `Event/Sequences/<funcName>.seq` | 索引在啟動時已載入正確版本；不把 MapID、Case、QuestInfoID、TRIGGER 名稱當同一鍵，也不假設每次 0047 都重讀 XML |
| 啟動排程與 busy | 同一 Client 的演出請求要序列化，重送需能辨識當前狀態 | Q busy 不排隊；normal／review 入口在 busy 檢查前仍會寫模式欄位 | Server 保存目前內容鍵、版本與執行階段；不能盲目重送當冪等操作，不能假設 Client 暫存第二段 |
| 雙階段內容產生 | 同一規劃產出有限依賴宣告與正式行為；使用本輪有界 stage 契約 | prepass Register 同步執行；formal Register 延後 resume；兩 VM 分離且各自可保留 globals | 預掃描有限返回且不等待遊戲事件；模型／動作集合與正式行為一致；phase 設計須維持實際 binding 與時序前提 |
| 當次 phase 與生命期 | 避免舊 global 值把依賴階段誤認成正式執行 | 本輪 lexical local 設計有 CLOSURE／RETURN upvalue、coroutine.create 與普通 list 強參照鏈支持 | 保持原 binding、正常 Register 返回及非重入；每 VM 獨立 local；不把 Register 返回當依賴全部收集成功，不執行會 yield 的 module 頂層 |
| 依賴與 API 檢查 | 在發布前檢查 slots、models、actions、參數數量與數值型別 | prepass slot/model/action 是 WORD，正式 Q slot 是 DWORD，actor ID 另有位寬；first-model、Create-before-action、tail-relative 參數窗已有原件 | 不用假 model／座標；拒絕碰撞、不同 model 共用 prepass slot、正式重複 Create、錯誤 arity、依賴缺失 |
| 輸入數值 ABI | 教學或演出切換操作狀態時，內容參數必須符合原 marshaller | Tutorial.SetKeymapEnabled 的 boolean tag 轉 0；數字非零清 mask `0x2`，0 設 bit2。lb.ChangeKeymapType 接受數字 0／1 複製鍵位表 | 對已核介面使用明確數字與正確 arity；不以 true 代表已啟用，不把 closure 回傳值當 ACK；兩介面都不解除 controller+58 |
| 模組載入與匯出 | 有版本且每次可辨識的 export；載入後才呼 entry | global DoFile 使用當前 Lua state，number 0／1；不回傳 module table；頂層在受保護 C 執行層 | 清除本次 export 位置、比較 `status == 0`、驗證當次版本與 entry；頂層有限定義並返回；不可把 lb.DoFile 的 0 當可靠成功 |
| 演出所有權 | 每段管理自己的一組 Q actors、動作與等待 | Q slot 是可用本地參照；Q 物件是 CEventActor；IsAllObjectsStopped 看整棵 Q tree 的 pending bit | 排他或明確共享所有權；移動停止與自然抵達／死亡不同；不可用空 DeleteObject、Show 或重複 Create 當真正回收／替換 |
| 固定 Tutorial 物件範圍 | 若重用該教學流程，確保固定物件鍵與教學 context 合法 | InsertIsilia 建 CActor／model4／world key F000；IsIsiliaFound 是同 key 的幾何觀察；DeleteObject 參數低 BYTE 左移 8 位，原版傳 240 | 固定 key 不與其他物件重名；不是任意 EntityId API。禁止傳 F000 期待刪同 key；不能把視野發現改名為擊殺／清組 |
| 正常結束 | 演出自行完成後恢復對應狀態 | MoCo 正常 return 不自動 End；Q End、coroutine remove、Q actor delete、UI／mask 是不同操作 | 明確收尾次序；在需要時採已證 DeleteAll；不能只等待 coroutine list 變空或一個資源 event |
| 回報與等待解除 | 演出完成、略過、取消後回到可操作狀態 | C2S 003F 為 8-byte application，含雙鍵 low16 與末 WORD 1；既有略過分支也可送。S2C 00EB application `EB 00` 只解除 wait／mask `0x2` | 以 Server 自有狀態關聯該回報；不把末 WORD 1 命名為新 MEF 成功，不把 00EB 當 Stop／清 qco／結果 ACK；End 後解除時序需對應當前合法 field |
| 非零 quest 的收尾條件 | 若使用非零 quest 避開 seen-skip，仍須有可達完成路徑 | normal active End 在 `M+38!=0` 時還要求 CheckConfirmMessage 結果為 1 才送 003F | 不把避開 skip 與保證送回報混成同一條件；選擇既有相容內容流程，不捏造無條件 ACK |
| 取消、轉場與重入 | 玩家跳過／離開／換場後，舊內容不得誤影響新一場 | ordinary 005F type2/4 與 F4355 不普遍保證 Stop／清 qco；removeAll 不會停止目前正執行的 Lua frame | 按實際 Stop、clear、field/page 路由規劃；instance/generation 是 Server 自訂追蹤欄位，沒有證據時不得放入原 wire 未有的位置 |
| 任務／資產提交 | 對話或演出結束後，決定任務完成、獎勵、金錢與背包變更 | 演出回報、移動停止、物件移除與任務完成各有不同語意 | Server 實作權威判定、持久化與相容刷新；不以播放成功或 003F 單獨發獎 |

證據分別見主報告的流程表及下列原稿：

- [檔案交付](../20261114-183651-chatgpt-web-roy1-MEF-delivery-windows.md)
- [選取與索引](../MEF-entry-lifecycle-events-20261114/entry.md)
- [DoFile 與 C 邊界](../MEF-complete-flow-20261115/script-lifecycle/report.md)
- [資源 resolver](../MEF-complete-flow-20261115/resource-gates/report.md)
- [MoCo 排程](../MEF-runtime-contracts-20261115/scheduler/report.md)
- [輸入與 End](../MEF-runtime-contracts-20261115/input-lifecycle/report.md)
- [完整 00EB／003F 契約](../MEF-world-integration-20261115/wire/report.md)
- [依賴 consumer](../MEF-content-contracts-20261116/bridge/report.md)
- [Q 物件與清理](../MEF-content-contracts-20261116/actors/report.md)
- [停止 observer](../MEF-content-contracts-20261116/observers/report.md)
- [本輪 phase／閉包契約](entry/report.md)
- [本輪輸入 ABI／debug hook 與 runner 邊界](runner/report.md)
- [本輪固定 Tutorial 物件與 UI state](world/report.md)

## 3. 尚不能由 Server 自行猜補的 Client 介面

| Client 待逆向 | 精確待閉合處 | 目前反證／不適用路線 | 解除條件 |
|---|---|---|---|
| 原生 MapList MEF 首次 caller | TRIGGER 名稱實際成為 loader 的 path/buffer，再進 parser/executor | 已查 map reader 只查名稱後丟棄／覆寫；通用 Lua loader 存在不等於已被它呼叫 | 新正向 caller/dataflow；或另採明確標示的新相容 caller 設計，不能偽稱已找到原生鏈 |
| 普通戰鬥背景 runner | 合法登記、owner、持續 tick、正常玩家控制、pause/cancel/reentry | Q active 仍寫 controller+58；清 input mask 不解除它；T 已知入口有場景限制；普通 UI/checkpoint tick 不是 Lua 登記介面 | 一條具體可達的完整 runner 契約；未取得前只承諾有限 Q 用途 |
| 世界 typed identity | 本地建立結果、可供腳本／Server 同時使用的穩定身分、更新／移除同一物件 | lb.CreateObjectEx 不回 ID；猜 counter 不可靠；0007 hit 不採用；Q slot 不等於 world EntityId | 真正已註冊的 handle/ID 暴露或另一條相容結果鏈，並閉合碰撞與生命週期 |
| 普通死亡／清組 observer | 正確 world actor/group/state writer → 可用 Lua getter／callback → 同次內容 consumer | Q停止、HUD、文字、003F、001A不能取代；004C／004E ordinary接法已被具體路由反證 | 帶正確對象或群組語意的原生可達 reader/callback；不把 Tutorial flag 重新命名成普通怪死亡 |
| 普通怪自主行為 | 敵對實例的 target/skill producer 與控制歸屬 | SubAI model<=9 與 supplied-relation following 的既有邊界 | 依正式 T13 RR-0013 接續；不以本輪有限 Q 演出代替 |

上述不是官方 Server 內部演算法未知。它們是仍未證明的 Client 可呼叫介面，必須保留；Server 的內容政策、流程對帳與保存則可照第 2 節實作。

## 4. 分開記錄開發完成與替代驗收

最小正常流程驗收應選一段有來源的內容鍵與資源，逐段記錄：所選版本、雙階段依賴、正式 callback 已開始、Q slot 對象、走位停止、明確 End、適用等待解除及輸入恢復。沒有當次 trace，離線 verifier 通過只代表證據／契約一致。

若要聲稱某項工作已從 Server 移交 Client，須指明**停發哪個原 Server 指令後，同一個操作仍由 Client 完成**，並比對最終世界／進度狀態。Server 仍代做生怪、開門、清場或自動前進的測試，不計為那些功能已被 MEF 接手。這項驗收定義沿用現行 MEF 功能追蹤，並未要求本輪啟動遊戲或執行暫緩的錯誤／壓力測試。

失敗、取消、重入、版本競爭等契約已列出，實際擴大測試仍依使用者的測試優先序與後續排程。主線需求與正式 RR 狀態由 S00／T01 各自接收；本研究不自行標記 ACCEPTED、STABLE 或 FULL-PASS。
