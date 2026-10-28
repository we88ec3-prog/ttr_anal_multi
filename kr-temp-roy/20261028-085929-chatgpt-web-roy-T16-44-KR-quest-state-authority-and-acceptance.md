# T16-44 — KR 任務狀態權威、重登續接與 T16 驗收規格

- 執行日期：2026-10-28 Asia/Taipei
- 研究類型：GitHub T01 來源稽核 + KR BIN 舊證據約束的交叉核對；不可讀原始 resource 全文的限制明示。

## 來源、方法與證據界線
- 倉庫：`we88ec3-prog/ttr_anal_multi`，基準 `main`：`d0fce702b42c89cd8ba2fd077ddbdfde341da19f`（本輪開始時核對）。
- 主要新來源：`shared/integrations/T01-20261028-06/{README.md,resource-source-audit.json,pending.json,NEXT-QUERIES.md}`；`kr/tasks/T16/{README.md,task.json}`；既有 `kr-temp-roy/T16-1…40` 原稿。
- KR 原始 BIN：`/mnt/data/Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪重新以本機 sha256sum 核對。EXE SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- 資源稽核紀錄源自 T01 靜態讀取與校驗，**不是本輪已讀取資源內容全文**。`kr-temp-roy/T16-local-20261028/evidence/resources/...` 是歷史本地工作區路徑，未出現在目前 GitHub 同路徑；GitHub 的 `kr/evidence/<SHA>.txt` 具有非 UTF-8 內容，現有 UTF-8 fetch 介面拒絕，不能據此假稱本輪已還原其欄位或 Lua 指令。這是 **ACCESS-BLOCKED-RAW-CONTENT**，不是「資源不存在」。
- 證據等級：**S**=可讀原始內容與直接來源核對；**B**=原生 BIN 指令直接證明的有限事實；**A**=T01 來源/解碼/SHA 稽核事實；**H**=歷史研究待交叉驗證；**U**=尚未證明。不得把 A/H 提升為 S。
- KR/TC 必須隔離；歷史 fixture、模擬服及 005F type6 本地修補不等於原生規則。原件唯讀；不執行客戶端或歷史程式，不更改其他 task 的 owner/catalog。

## 權威證據分類：資料存在 ≠ 官方寫入
| 類別 | 已確認 | 不足以推出 |
|---|---|---|
| Lua Event bytes | T01 比對 KR TutorialBase/Main/qbase chunk SHA、解碼指令數 | server quest completion rule |
| XML 資源 | QuestInfo、QuestTalk 等 root/child SHA、封裝 offset | 官方判定／已交付狀態 |
| 客戶端腳本橋 | BIN `0x006F4A50`、`0x006F4DD0` 與 `Tutorial_EntryPoint` 名稱路徑 | client 是任務進度權威 |
| UI/鍵值解析 | T16-20/29/36/37 `QUESTSTATE`、`TutoQuest`、`HasQuest` 等相關字串／容器路徑 | 完成旗標一定寫入磁碟或帳號 |
| transport/dispatch | T16-17..28 封包 handler 和幾個候選路徑 | 已識別合法 quest progress opcode |
| T01 integration | resource + source byte consistency, 29 限定觀察/缺口 | backend 全語義／可玩性已驗收 |

## 原版權威閉環所需五段
1. **request**：由何行為送出 quest related packet？payload quest/step namespace + counter？
2. **validation**：伺服器如何證明事件合法，如指定場景、角色、勝利、NPC、前置？
3. **write**：權威狀態何時改變，是 accepted、active、objective complete、turn-in、completed 哪一種？
4. **notify**：client 收到哪個 opcode/key，何時驅動 GUI、NPC/Quest status？
5. **restore**：server 快照/事件重放何時傳回？角色 vs 帳號 scope、重複領取幂等性如何？

目前沒有足夠原生來源把五段對應同一 quest ID，應依節點保留 `unknown`。

## 測試矩陣（待具備授權環境，由本地執行）
| Case | 前提 | 動作 | 需要觀察 | 目前 |
|---|---|---|---|---|
| Q-A | 已存在角色、第一次進教學 | tutorial entry | startup quest snapshot/step | 未執行 |
| Q-B | 教學 step 進行中 | 中途斷線重登 | state 是否持續、跳回哪一步 | 未執行 |
| Q-C | scenario14 勝利/失敗分支 | 依合法流程結算 | 是否寫 Quest16 progress | 未執行 |
| Q-D | Quest16 terminal | 回城／對話 | Quest16 completed/Quest15 offer | 未執行 |
| Q-E | 已完成角色 | 重複同一完成事件 | 重複獎勵、後端拒絕行為 | 未執行 |
| Q-F | 角色 A 已完成 | 切角色 B | character/account scope | 未執行 |
| Q-G | TC 同名流程 | 比對 TC 自身資源 | 是否與 KR 語義差異 | 未執行 |

## 跨任務交付
T16 應交 T02：精確業務 opcode/payload；交 T14：關卡結果→quest event 合約；交 T07：任務請求的場景參數；交 T15：需保存的任務欄位及何時 snapshot。以上只有找到來源後才能由 `unknown` 變成 confirmed。T04 不應被要求建立教學旗標或預設初值。

## 本輪驗收判斷
- **A 級來源可追溯：通過**（來源 SHA、carrier offset、Lua 靜態 parse 數、XML root/children 已整理）。
- **B 級 client entry 與部分 XML loader：先前研究部分確認**，此次沒有超出原生結論的升級。
- **新手教學每一步可追溯：未通過**（缺 Lua 指令/常數全文）。
- **Quest16 完成／Quest15 出現：未通過**（缺 XML row、network/server writer）。
- **Server authority 和跨登入續接：未通過**（T01 pending 明列）。
- **KR/TC 版本混用：禁止**。TC Lua、QuestInfo、QuestTalk 原始 SHA 皆不同；需逐 row/事件比對。

## 後續解阻優先順序
1. 將 Git 保存的原始 `kr/evidence/<SHA>.txt` 經可處理二進位的介面讀取，核對 bytes 與 audit SHA，匯出**只含可分析資料的文本／Lua 靜態 disassembly 與 XML row**，不需啟動客戶端。
2. 取得 `kr-TutorialMain.lua.json`／`kr-TutorialBase.lua.json` 與 `QuestInfo` 16/15 原始 row（包含前置及談話指派）；若原始 script 用的不是 ID 16/15，記錄衝突。
3. 梳理候選 opcode 到真正的 dispatcher、writer 與對應 UI notice，必須有位元組或官方流量反證。
4. 只在相關跨任務 owner 的介面變更時提出需求，不擅改 T02/T07/T14/T15 的方法主責。

## 交付聲明
本份是完整的**權威缺口與驗收研究原稿**，不是完整遊戲功能還原。本輪沒有執行客戶端、修改原件或進行 server 測試。GitHub 僅在使用者本次明示完成四份後推送。