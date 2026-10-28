# KR T08 — 本地接手：封包引發的關卡變化與無法在 Web 閉合的證據缺口

> 定位：T08 的**研究交接與待驗證清單**，不是原版協定定稿或伺服器實作規格。來源：GitHub T08 README、T08-KNOWLEDGE-BASE、T08-193～200 研究原稿，以及現行 `AGENTS.md`、`HANDOFF.md` 和 `shared/CLIENT-MODIFICATION-POLICY.md`。僅以 KR 韓版原始證據推論 KR；不把 TC 或 AI fixture 視為 KR 原版。

## 1. 核心目標：從收到的封包追到玩家看到的關卡變化

優先建立每一類 **S→C 收包 → 拆包/分派 → handler → 寫入場景/Actor/狀態/事件 → 玩家看見的效果** 的完整證據鏈。每個情境另追 **Server 為何發送此封包**（若無原版 Server，必須標為「無法由 Client 單獨證明，待本地取得原生 Server／封包擷取／可靠資料」）。不可僅因能找到 handler，就宣稱已知道伺服器何時觸發、封包所有欄位、播放事件或怪物死亡條件。

| 玩家可見情境 | 現有可回溯入口 | 已確認的限定證據 | 本地尚待閉合 |
|---|---|---|---|
| 收到資料後出現怪物／實體 | **S2C 0007** → `0x004AE4D0`，後接物件建構及 `0x004DFF30` 登記 | **已確認**前置 2 bytes，單筆 26 bytes；type 1 路徑可建 CMonster | 封包實際全部欄位/單位/座標、所有 type 分支、每筆 key、重複 ID 處理；從 socket → 0007 handler 的完整分派；Server 生成時間/波次/位置決策 |
| 收到資料後物件消失 | **命令 26** → `0x004B28D0`；**命令 81** → `0x004B3710`；`0x004DFBC0` 個別移除、`0x004DFE90` 整表清理為相關底層入口 | **已確認有限移除路徑**；多型預清理與 Actor 析構另有 T08-193～200 直接證據 | 26/81 的實際 framing/opcode 域、長度、key/id 來源與分支、兩者各自何時採用；與死亡、切場景、斷線的**因果關係未證明**；不可把任一命令概稱為死亡包 |
| 收到資料後場景狀態／表現改變 | **命令 151** → `0x00494750 → 0x004D2E40 → 0x004C9840 → 0x004CA0B0` | **已確認限定狀態同步呼叫鏈** | 封包欄位、實際動作／顯示／狀態含義；事件 8 **未證明為 OnDeath**，也**未證明 151 直接觸發事件 8** |
| 收到控制權／關聯資訊 | **S2C 000A** | README 僅確認 owner 與 actor/related 類欄位及控制槽登記 | 封包完整欄位和接收路徑；**控制槽登記不等於怪物生成或 AI 決策接管** |
| 收到某封包觸發關卡事件、下一波、關卡結束 | **尚無完整已確認 S2C→事件→場景效果鏈** | 目前不能指定可用的原版 opcode 或事件參數 | 搜尋 T02 dispatch 與 T07/T06/T14 的分工證據；逐事件建立 packet→event handler→script/scene writer→observable effect；原版 Server 觸發條件缺失須轉本地工作項，不以 fixture/AI 補猜 |

**重要：** 上述「命令 26/81/151」沿用 T08 研究筆記的命令編號；除非已驗原始封包 dispatch，**不自動等同 wire 層完整 opcode**。正式 T08 管理建立/登記/移除的資料界面；關卡決策主責仍屬 T06/T07/T14 等，T08 記錄跨 Task 收件/寫入/副作用 interface。

## 2. Web 已有成果，避免本地重做

- S2C 0007 每筆 26 bytes、type 1 建立 CMonster；場景主登記 `0x004DFF30`、個別移除 `0x004DFBC0`、整表 `0x004DFE90`。
- CMonster 建構主 vptr `0x00C0C9DC`；主表 `+0x14` 可解析 `0x004D1F80 → 0x004C8360`（特定 CMonster 型別的資源預清理）；主表 `+0x00` 指向 `0x004D18D0` deleting destructor。**其他派生類型不能照抄。**
- T08-196～200 已辨認兩套樹的部分查找、條件移除、迭代和重複 key 分支；兩棵樹是否共享 actor 指標/所有權**仍待確認**。
- 共用資源的引用解除、復用池、drain 和清理**不等於**每次 Actor 移除都同步 drain，也不等於 Server 發生死亡。

## 3. 移交本地的阻塞（不要在 Web 空轉）

以下屬本地可運用完整工作樹/反編譯器/其他可依法取得資料做更大範圍驗證，或因無原版 Server 而必須標記不可證實：

1. **P0 / 版本與完整來源：** 對照 KR 原始 `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`、`Tartaros.exe`（不同 PE）、本地完整 DLL／資源／腳本／工作樹，逐功能確認哪些 source 實際存在。Web 目前對主程式外部檔、動態路徑、完整 runtime 的可觀測性有限；**不能把「Web 沒取得」等同「原版不存在」**。
2. **P0 / 封包端到端：** 由 T02 socket 收包、長度/封包邊界、指令分派一路追到 0007、000A、命令 26/81/151，填真實欄位、byte offset、計數、key、座標及事件轉換，附原始 assembly/封包或可靠 trace。
3. **P0 / Server 缺失：** 原版 Server 發送 0007、移除命令、關卡事件封包的真實決策條件、怪物波次與生成時間/位置，**沒有 Server 原始碼或原生封包證據就不能還原為已確認規則**。本地可蒐集合法來源、實際 packet trace、原版資源與歷史日誌；不可用 AI fixture 假充原版。
4. **P0 / 事件/關卡副作用：** 定位任何 S2C→腳本/事件 dispatcher→Scene/Actor 改變的具體鏈；各事件至少記「原始 wire opcode/domain、handler、payload field、writer、可見效果、觸發上下游、證據等級」。跨 T06/T07/T14 協作，不搶他們的玩法決策主責。
5. **P1 / 不同 Actor 虛表：** 追 CMonster 以外的 vtable `+0x14/+0x00` 真目標、`actor+0x15C` 次級物件 vptr；用本地 Ghidra/REA 的型別、xref 與 CFG 排除 byte-scan 誤判。
6. **P1 / 兩棵樹與所有權：** 追主/次索引插入者、節點 payload 真型別、是否指向相同 actor、雙重刪除防護、`owner+0xF8` 持有者及 key 語意。
7. **P1 / 資源失敗/回收：** wrapper/resource/manager 指標鏈、`+0x5C/+0x60` 增減與配置失敗回滾、pool reuse/drain 多執行緒與跨 frame 時機。這些不是原版 Server 生成規則。
8. **P2 / 動態驗收：** 在**另經授權的本地測試環境**，以不破壞原檔的最小診斷／遊戲流程確認結果：收到建立包後生成 N 筆、同 ID 重複包、指定移除、全部清場、事件前後、重進關卡、死亡與場景切換。當前 Repo 原檔唯讀/不執行或附加之規定繼續生效；**本清單不構成執行或修改目標授權**。

## 4. 本地交付格式／停止條件

每一待補案至少交付：`玩家情境 → packet bytes/版本/opcode domain → recv dispatcher → handler VA → 欄位/分支 → actor/scene/event writer → 玩家可見結果 → Server 證據或不可證實聲明 → 是否已有可測實作`，分列**原生確認／部分確認／AI 替代／資訊缺失／待補開發**，且附 SHA 和引用來源。不可宣稱「缺乏 Server」便可自行設計並稱原版；若需用相容替代方案，須與原生證據分開。

- Web 後續避免只追 resources 内部析構而忽略 **S2C 封包輸入造成的關卡效果**；與既有 T08 正式範圍和其他 Task 的邊界同時維持。
- 本地先讀 `kr/tasks/T08/task.json`、`kr/tasks/T08/README.md`、本檔、`shared/source-review-status.json`、T08-KNOWLEDGE-BASE 與具體分段原稿；判斷新工作是否由 T02/T06/T07/T14 主責。
- 本文件只建「待本地驗證清單」，**不更改 task owner/state、不聲稱已完成、未自行修改遊戲或伺服器**。
