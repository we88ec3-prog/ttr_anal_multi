# T08 — 固定研究設定（Project 參考文件）

> 僅保留 **T08 專屬**資訊；大型批次、第一手原始資料驗證、Markdown 筆記格式、多 Agent 隔離與 Commit 權限均依 `02-PROJECT-SHARED-INSTRUCTIONS.md`／Project Instructions 執行。本文件無更新時，新對話不必重新提供。

## 0. 專屬 Git 分支與新對話合併（2026-10-28）

- T08 專屬工作分支為 **`t08/roy/chatgpt-web`**；repo `we88ec3-prog/ttr_anal_multi`。日後 T08 原稿與專屬設定獲使用者明確授權提交時，**僅 Commit／Push 至此分支**，不直接提交 `main`，也不改其他 Task、owner、catalog 或 T01 內容。既有 `main` 原稿仍以其歷史位置保留。
- **每次新對話在任何新 T08 正式研究前**：先讀 GitHub 最新 `main` 與 `t08/roy/chatgpt-web`，將最新 `main` **Merge 進** `t08/roy/chatgpt-web`，並驗證 Merge 已成功且主線變更確實包含於 T08 分支。方向是 `main → t08/roy/chatgpt-web`，**絕不反向 Merge**；若工具不支援、合併失敗、內容有衝突或驗證不足，應回報並**停止新正式段落**，不能靠覆寫文件冒充已同步。
- 這項新對話 Merge 程序屬使用者明確要求的分支同步規範；**並不代表可自動 Commit／Push 新研究成果**。新原稿仍須有使用者明確授權才可提交，成功後逐份遠端讀回比對。
- `03` 只保留長期方法與 Git 流程；當前段號、兩分支 SHA、近期缺口與未提交筆記由新對話單次上傳的 `04-T08-NEXT-CHAT.md` 負責。**新對話啟動指令獨立提供，不放在 04。** `04` 亦不自動推 GitHub。

## 研究標的與範圍

- Task ID：`T08`；研究《星空幻想 Online》（Tartaros Online）的 Windows PE32／x86 客戶端。
- 長期目標：追查 CMonster、AvatarBase、場景物件與元件生命週期、資源管理、網路命令與狀態同步、場景主更新／調度；保留可回溯至原始機器碼的證據。
- 不由第1段重跑；由使用者在**每次新對話另外上傳**的 `04-T08-NEXT-CHAT.md` 判定最新下一段，不假設 `04` 常駐於專案來源或 GitHub。

## 第一手檔案與資料位置

- 原始檔案：`Tartaros.bin`、`Tartaros.exe`；BIN SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。優先檢查實際是否可用並核對 hash；檔案不能存取時可先參照 GitHub 已存證據，必要時才請求重新提供。
- 已知 PE32 映射：`.text` VA `0x00401000`／檔案位移 `0x400`；`.rdata` VA `0x00BD2000`／位移 `0x007D0600`；`.data` VA `0x00D61000`／位移 `0x0095E800`。遇映射不一致須以原始 PE header 核實。
- GitHub：`we88ec3-prog/ttr_anal_multi`；完整反編譯資料在 `kr-bulk-roy/9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91/{functions,raw}/`。**使用者會主動通知反編譯資料更新**，無須每段反覆檢查更新。
- 研究者識別：`chatgpt-web roy`；個人筆記目錄：`kr-temp-roy/`；檔名：`YYYYMMDD-HHMMSS-chatgpt-web-roy-T08-主題.md`。
- T08 長期知識庫：`kr-temp-roy/T08-KNOWLEDGE-BASE.md`，詳細證據以分段研究原稿為準。

## T08 固定研究優先序：封包造成的場景效果

- **P0：以 Server → Client 收包為起點，追至玩家可見的場景結果。** 每種情境至少追 `socket/收包 → framing/opcode domain → dispatcher → handler → actor/scene/event writer → 玩家可見效果`，同時記錄 packet bytes、長度、欄位、參數來源、條件、版本、原始證據及未確認的連結。沒有找到完整收包鏈不得聲稱原版 wire opcode 已確立；找到 handler 也不等於證實 Server 觸發時機。
- 必須個別核對：**怪物／NPC／場景實體生成、指定移除、整批清除、場景狀態變更、事件觸發、下一波及關卡結果**。優先追蹤場景功能所依賴的網路輸入，不因早期已分析大量物件析構和資源池而持續在相同 helper 重複盤點。
- 既有有界入口：**S2C 0007**（前置 2 bytes、每筆 26 bytes，type 1 可走 CMonster 建立），**S2C 000A**（owner／actor-related 控制關聯），**命令 26／81**（部分移除流程），**命令 151**（部分狀態同步鏈）。命令編號未必等同 wire 層完整 opcode；完整封包資料、效果與時序須逐項核實。**事件 8 不得直接稱為 OnDeath，也不得聲稱命令 151 已證明觸發事件 8**。
- **P1：必要的 Client 物件與資源資料流。** 如封包 handler 通往物件建立／索引／多型移除／清理被阻塞，可追 CMonster、AvatarBase、雙樹、vtable、wrapper、資源所有權；以打通特定玩家情境的功能鏈為目的，而非不斷深掘與封包無關的資源 helper。
- **P2：缺失的 Server 決策規則。** 原版 Server 若不可得，**生成時間、波次、地點、關卡事件判斷、死亡決策**不得由 Client handler、AI fixture 或假設直接寫為原版規則；只記錄 Client 所要求／接收／消費的證據，將原版不可證實部分明列「資訊缺失／待本地補證」。

## Web 與本地協作的固定交付規則

- Web 應先完成能由現有 KR 原生 BIN／完整反編譯／GitHub 證據直接閉合的 Client 流程。遇到完整程式相依檔、腳本、外部資源、真實網路流量、動態型別或 runtime 觀察不足時，須輸出**可交付本地的具體阻塞清單**，列來源、已證範圍、待查地址／封包、所需證據與可驗收結果；**不能將 Web 無法取得視為原版不存在**。
- 原版 Server 程式或流量缺失時，不以「猜測伺服器會做什麼」取代原版證據，也不要無限重複無法閉合的同一假設；交由本地依法取得可用原生資料與跨 Task 驗證。沒有明確授權不執行、附加、patch 原始客戶端；如需遊戲測試，另依專案政策取得授權。
- 研究分工：T02 負責 socket／framing／底層 dispatcher；T08 負責**收到相關業務資料後對 Actor 建立、登記、移除與相關場景副作用的 Client 介面**；關卡生成決策、波次、切場景及事件規則涉及 T06／T07／T14 等主責，應引用與交接，不自行接管或修改他人的 owner/catalog。
- 每段 Markdown 新增一個玩家情境表：`收到何種原生封包 → 已證明的 handler／欄位 → 寫入者及場景變化 → 玩家可見效果 → 未證實 Server 行為 → 本地待追查項`；原生確認／部分確認／合理推測／AI 替代／資訊缺失／待補開發分欄，不得以函式量或段號代替可玩驗收。
- 本地長期接手清單（GitHub）：`kr/tasks/T08/LOCAL-FOLLOWUP-PACKET-STAGE-EFFECTS.md`；以該檔與 `kr/tasks/T08/{README.md,task.json}` 的最新遠端內容為準。這裡只保留固定方法，**不在 03 維護當前段號、最新 Commit 或短期待辦**；具體下一段入口由 04 提供。

## T08 特定的歷史證據邊界

- `[0x00FE173C]` 指向 heap 名稱索引，而 `0x00FE1740` 是**另一套**內嵌名稱樹；切勿混用兩者的 `node+0x24` payload。
- `0x8C` bytes 名稱管理物件不可當作 `0xB4` bytes 多型 Binding Provider；Provider vptr `0x00C50A8C` 與次級 vptr `0x00C50ABC` 已有分段研究。
- `0x007D170B～0x007D178F` 證實存在**管理器內嵌**分桶 consumer；尚未證實它消費全域 `[0x00FB7740]` 的分桶。
- `[0x00FB76B0]` 六組四 float 係數的寫入者尚未定位；不應未驗證即稱為相機視錐。
- `resource+0x20`、`resource+0x1C`、`binding+0x80` 等欄位依指標來源判定，不逕自稱為動畫時間／死亡／技能狀態。
- 不將場景事件8直接命名為 `OnDeath`；命令151與事件8的直接觸發關係尚未證實。

## 固定參考順序

1. 使用者在本次新對話上傳的 `04-T08-NEXT-CHAT.md`：最新段號、待提交內容、優先任務。
2. `kr-temp-roy/T08-KNOWLEDGE-BASE.md`：長期研究脈絡與證據修正。
3. 需要的 T08 分段 Markdown 原稿與 `kr-bulk-roy/` 函式資料；以 BIN 做關鍵驗證。

短期段號、最新 Commit SHA、研究待辦**不維護於本文件**，以免固定指令頻繁變動。

## T08 交接文件的存放約定

- `02-PROJECT-SHARED-INSTRUCTIONS.md` 與本 `03` 為專案共用／T08 固定參考來源。
- `04-T08-NEXT-CHAT.md` 為**新對話單次上傳文件**；準備交接時生成最新 Markdown，交由使用者在下一個對話上傳。
- 現階段**不把 `04` 自動提交 GitHub**；未來改用 GitHub 管理須由使用者另行明確提出。
