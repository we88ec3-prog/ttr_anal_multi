# T16 — 固定研究設定（ChatGPT Project 參考文件）

> 2026-10-28 修訂。T16 **以原始 Client ↔ Server 雙向封包及 Client 任務狀態效果為分析目標**。跨 Task 大型批次、三輪深入門檻、BIN-first、完整 Markdown 與 GitHub 提交權限，依 `02-PROJECT-SHARED-INSTRUCTIONS.md`；短期段號／Commit／待辦只放 `04-T16-NEXT-CHAT.md`。

## 0. T16 專用 Git 分支與新對話同步（2026-10-28 新增）

- Repository：`we88ec3-prog/ttr_anal_multi`。**T16 唯一研究工作分支固定為 `t16/roy/chatgpt-web`**。往後所有 T16 完整技術原稿及 T16 專用文件，取得使用者當次明確 Commit／Push 授權後，**只能提交到該分支，不得直接推送 `main`**。
- **每次新對話開工時，在開始任何新的 T16 正式研究段落前，必須先核對 GitHub 最新 `main` 與 `t16/roy/chatgpt-web`，並把最新 `main` Merge 進 `t16/roy/chatgpt-web`**；方向只能是 **`main → t16/roy/chatgpt-web`**，不可反向 Merge。須取得 GitHub 實際成功結果，並核對合併後工作分支已包含最新主線變更，才可開始分析。
- 如 GitHub 工具無法執行 Merge、發生衝突、無法確認主線已納入工作分支，**明示同步阻塞並停止新的正式研究段落**；不得以覆寫檔案、複製部分內容、建立空提交或聲稱「分支源自主線」代替實際 Merge／驗證。即使兩分支當時相同，也必須查證已同步，不能猜測。
- 已存在於 `main` 的 T16-65～92 既有原稿與歷史提交**保留**，不移動、不重寫。新研究往專用分支累積；將 T16 分支整合回 `main` **須使用者另外明確要求**，不得擅自操作。
- **新對話先同步**是使用者固定核准的開工程序，**不是新研究自動 Commit／Push 的授權**。只有使用者明確要求提交才 Commit／Push；一經授權，提交完整 Markdown 並遠端逐檔讀回比對。
- `03` 僅放固定規則；`04-T16-NEXT-CHAT.md` 記錄最近正式段號、工作分支／main 最新狀態、上次 SHA、下一研究入口與當次阻塞，作為新對話單次上傳交接，不自動推 GitHub。

## 1. 任務範圍與最終目標

- T16：**任務與劇情流程（Quest & Story Progression）**。正式研究新手教學（P0）、主線起始／解鎖（P0）、後續主線（P1）、支線（P2，阻塞主線者提前）。
- **核心問題**：玩家的操作或任務事件讓原始 Client **發出什麼 C→S 封包**？Client **收到什麼 S→C 封包**、由哪個 handler 接收、改動哪些狀態，使任務完成、NPC 顯示可接任務、下一章節開放、劇情／UI 更新？玩家點選接取下一任務時，Client 又發出什麼封包？
- **不以逆向原版 Server 內部實作為驗收前提**。Server 如何判定通關、如何檢查任務前置、如何寫入資料庫，屬**需要開發 Server 的部分**；只從 Client 實際收發規格推導相容實作需求，絕不可猜稱官方內部邏輯。
- 對 KR／TC 分別驗證原件和證據，不互搬 ID、opcode、欄位或位址。當前對話與後續交接 **只研究 KR**，除非使用者另有明確要求。

## 2. 固定優先序（以封包為主線）

### P0 — Client → Server

- 玩家接任務、交付、完成條件、NPC 對話、教學事件、要求進入／返回任務關卡：從 UI／Lua／native caller → 本地 gate → packet builder → queue／dispatcher → socket output 查證。
- 每種行為明確列出是否發包、何時發包、opcode（需證明是 wire opcode）、長度、欄位、實際來源、發送次數與前置；只查到本地 4-byte buffer 不得擅稱已送到 Server。

### P0 — Server → Client

- 從接收／decode／opcode dispatcher 追到任務回覆 handler、任務狀態 cache writer、NPC 可接取列表、UI／劇情 consumer。
- 逐項查 Client 收到什麼才認定任務**已接受／已完成／可交付／可接下一任務**；區分 Server 下發的可接清單、更新旗標、Client 自行依已有狀態推算與未知。
- 解鎖下一任務後，還要繼續追**玩家實際接取下一任務的 C→S 封包**以及接收確認／拒絕回覆。

### P1 — 任務條件與本地腳本

- 原版 QuestInfo／QuestTalk、TutorialBase／TutorialMain、NPC／對話／劇情依賴。以它們如何產生封包或消費回覆為中心研究，避免在無封包進展時反覆盤點 XML/Lua loader。
- 完整前置條件可以幫助相容 Server 設計，但**缺原版 Server 演算法不代表 Client 分析未完成**。

### P2 — 重登／進度保存（低優先）

- 先確認 Client 是否送出要求紀錄階段的封包，或僅在登入後接受 Server 角色任務 snapshot；發包與否皆需有明確觀察範圍，不以未找到當作不存在。
- 持久化資料表、DB transaction、角色保存／恢復實作由 T15 或 Server 開發處理；T16 記錄 Client 相關要求、收到的資料與如何恢復畫面。

## 3. 分工與原始證據

- T02：封包 framing、socket／dispatcher 底層；T16：任務業務訊息 opcode、欄位與 client 狀態結果。T07：場景／關卡切換；T14：勝敗、目標、結算；T15：持久化；T03/T04：登入與初始角色。T08 等供 NPC／實體／劇情關聯證據。**不覆寫他人 Task、owner、catalog、原稿**。
- GitHub：`we88ec3-prog/ttr_anal_multi`；T16 正式 `kr/tasks/T16/{README.md,task.json}`，既有研究原稿 `kr-temp-roy/`，未來 T16 新稿在 **`t16/roy/chatgpt-web`** 的 T16 研究目錄提交；以分支中的既有路徑為準，不任意變更 owner／catalog。
- KR 已知版本校驗參考：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；每次讀取實檔仍須重新核對並確認 PE section 映射。其他 KR 資源依原件 SHA。
- AI/fixture、舊 patch、原版 client 與 Server 規則明確隔離；尤其舊 `005F type6` 資料不能當作官方回應證據。原始檔唯讀，不自行啟動、patch 或上傳二進位資源。

## 4. 每段必要交付

- 玩家場景 → Client 本地判斷 → **C→S**（opcode/長度/欄位/發送 call chain）→ **S→C**（opcode/長度/欄位/handler）→ Client 任務／NPC／UI／劇情效果 → Server **待開發**需求，製成逐情境矩陣。
- 分級：**原生已確認／部分確認／合理推測／unknown／相容 Server 待開發**。未追完 socket／handler 不得捏造封包識別碼、完成條件、Server 原版演算法。
- Markdown 保留原始 BIN bytes/assembly、VA/raw、callers/callees、CFG、分支、vtable、對象欄位、封包偏移、偽碼、反證與下輪入口；對話報告以玩家理解的進度為主。大型批次與 `NNN-2`／`NNN-3` 門檻依 `02`。
- 研究完成 ≠ 可玩驗收；以 Client 可驗證的雙向互動與清楚的剩餘 unknown 評估進度。

## 5. 新對話與提交

1. 讀 `02-PROJECT-SHARED-INSTRUCTIONS.md`、本 `03`、使用者單次上傳的 `04-T16-NEXT-CHAT.md`。
2. **先核對 GitHub 最新 `main` 與 `t16/roy/chatgpt-web`，執行 `main → t16/roy/chatgpt-web` Merge，驗證成功與最新主線納入後才開始新 T16 正式研究。失敗／衝突就停止正式研究並回報，不可略過。**
3. 再讀同步後工作分支的 `AGENTS.md`、`HANDOFF.md`、`shared/CLIENT-MODIFICATION-POLICY.md`、`kr/tasks/T16/{README.md,task.json}`、最近完整研究原稿及必要的跨 Task 證據。
4. 以 KR 原件 BIN-first 大型批次開展研究，按三輪深入門檻交付完整 Markdown；無提交授權仍須提供可下載原稿。
5. **只有使用者明確要求時才將 T16 原稿 Commit／Push 至 `t16/roy/chatgpt-web`**，且每次遠端逐檔讀回。禁止自動推 `main`；欲把 T16 分支整合回 `main` 必須再次獲得明確指示。
6. `04-T16-NEXT-CHAT.md` 僅供新對話交接，由使用者本次上傳；沒有額外授權不要上傳 GitHub。
