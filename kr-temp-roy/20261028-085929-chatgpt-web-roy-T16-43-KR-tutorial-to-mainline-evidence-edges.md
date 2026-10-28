# T16-43 — KR 新手教學尾端 → Quest16 → Quest15 的逐箭頭證據審核

- 執行日期：2026-10-28 Asia/Taipei
- 研究類型：GitHub T01 來源稽核 + KR BIN 舊證據約束的交叉核對；不可讀原始 resource 全文的限制明示。

## 來源、方法與證據界線
- 倉庫：`we88ec3-prog/ttr_anal_multi`，基準 `main`：`d0fce702b42c89cd8ba2fd077ddbdfde341da19f`（本輪開始時核對）。
- 主要新來源：`shared/integrations/T01-20261028-06/{README.md,resource-source-audit.json,pending.json,NEXT-QUERIES.md}`；`kr/tasks/T16/{README.md,task.json}`；既有 `kr-temp-roy/T16-1…40` 原稿。
- KR 原始 BIN：`/mnt/data/Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪重新以本機 sha256sum 核對。EXE SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- 資源稽核紀錄源自 T01 靜態讀取與校驗，**不是本輪已讀取資源內容全文**。`kr-temp-roy/T16-local-20261028/evidence/resources/...` 是歷史本地工作區路徑，未出現在目前 GitHub 同路徑；GitHub 的 `kr/evidence/<SHA>.txt` 具有非 UTF-8 內容，現有 UTF-8 fetch 介面拒絕，不能據此假稱本輪已還原其欄位或 Lua 指令。這是 **ACCESS-BLOCKED-RAW-CONTENT**，不是「資源不存在」。
- 證據等級：**S**=可讀原始內容與直接來源核對；**B**=原生 BIN 指令直接證明的有限事實；**A**=T01 來源/解碼/SHA 稽核事實；**H**=歷史研究待交叉驗證；**U**=尚未證明。不得把 A/H 提升為 S。
- KR/TC 必須隔離；歷史 fixture、模擬服及 005F type6 本地修補不等於原生規則。原件唯讀；不執行客戶端或歷史程式，不更改其他 task 的 owner/catalog。

## 核心問題
最新 T01 整合 `pending.json` 把以下內容列為**未閉合後端缺口**：
- `scenario14 official completion/return TUTO`
- `Lua terminal to server Quest16 complete to Quest15 available`
- `exact resume/account/character scope`

`NEXT-QUERIES.md` 同樣列出 `scenario14` 合法結算/返回 TUTO，以及 Lua 末端→server Quest16→廣場 Quest15。這是**研究路線和測試目標**，不是已證實原版遊戲必然依上述箭頭轉換。

## 逐箭頭審核矩陣
| 邊 | 已有證據 | 缺的關鍵證據 | 狀態 |
|---|---|---|---|
| Tutorial entry → Lua dispatch | KR BIN T16-1..40 記錄 `0x004A8A60` 等，T01 有原版 Lua chunk 成員 SHA | Lua 全域／事件具體分支 | B+A 部分確認 |
| Lua step → scene14 action | Event.stp／Lua 來源有保存且可校驗 | Lua instruction 和 scene ID 的直接資料流 | U |
| scenario14 result → TUTO return | 其它 task（T07/T14）相關進度和 T01 pending | 原版結果/返回 opcode、合法狀態轉換 | U |
| Lua terminal → Quest16 completion | `TutorialMain.lua` 來源存在；T01 明列缺口 | Lua 實際 terminal callback + client packet + server verify | U |
| Quest16 completed → Quest15 available | Quest XML 來源存在；T01 明列缺口 | 原版 prerequisite 欄位和伺服器 offer/availability handler | U |
| Quest15 available → acceptance → first mainline | QuestInfo/QuestTalk/ScenarioBook 來源索引 | NPC/quest row/accept packet/完成標記 | U |
| logout → login resume | T15/T03 研究界面 | character/account scope, snapshot, resume policy | U |

## 關於已知索引／UI 的反證
- `0x00FE18DC` 與 `0x008438C0`、`0x0053EBA0` 曾在 T16-9~16 識別出索引查找與 16-byte vector consumer；索引不一定是 quest progression persistence。
- `TutoQuest`、`HasQuest` 等欄位的原生字串命中本身是結構資料證據，不等於運行時 quest writer。
- T16-17..32 研究過 handler 表、訊息接收與候選函式，但尚無 confirmed opcode→payload→quest writer 完整鏈。
- 不能把 `005F type6` 的歷史測試修補、fixture 或 AI backend 實作視為原生 `tutorial complete` 訊號。

## 交接 T02/T07/T14/T15 所需證據契約
- **T02**：封包 envelope/handler 路徑、network opcode、解碼欄位及接收後 dispatch；T16 只解釋 quest 業務欄位。
- **T07**：進場／離場/返回 TUTO 的原生情境、場景 Id 域及 ready gating。
- **T14**：scenario14 stage 勝敗、結算及獎勵；T16 只研究「完成結果如何推進 Quest16」。
- **T15**：哪個進度值跨登入保存、角色/帳號界線、重登後數值來源；T16 描述狀態語義。

## 具體候選伺服器端假設（不得視為已確認）
A. 回合/場景成功先由伺服器合法結算，再通知 tutorial stage；B. 腳本直接發出 quest stage completion request；C. server 初始 quest 狀態隨角色 snapshot 恢復。三者都符合少量客戶端 UI 現象，現階段無法排他。必須保留多假設直到封包或 server 原件出現。

## 優先驗收實驗（僅規格，不執行）
1. 從一個 T04 已建立的角色開始，擷取進教學前、scenario14 前、勝利/失敗後、返回 TUTO 後、Quest16 完成後、Quest15 出現時的可信 server/client 狀態快照。
2. 每次僅觸發一個事件，標記所收到的 opcode、payload 差分及 UI 提示，避免一個 UI 變化被誤當成後端 flag。
3. 斷線重登、改選另一個角色、失敗重試、重複領獎建立反證測試。
4. 以 KR/TC 分離的原始 QuestInfo、Lua 常數逐項對照，否則 outcome `unknown`。

## 限制及本次實際進度
本輪新增的是：**把原本『缺少資源』修正成『來源已驗證、全文存取仍受限』**，並將 T01 的明示 `Quest16→Quest15` 缺口和 1~40 BIN 證據逐箭頭對齊。不是原版教學結束鏈已完成；不得寫作「Quest16 已可完成」。