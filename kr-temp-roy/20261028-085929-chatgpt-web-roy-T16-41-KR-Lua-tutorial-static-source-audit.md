# T16-41 — KR Tutorial Lua 靜態來源復核與腳本控制契約

- 執行日期：2026-10-28 Asia/Taipei
- 研究類型：GitHub T01 來源稽核 + KR BIN 舊證據約束的交叉核對；不可讀原始 resource 全文的限制明示。

## 來源、方法與證據界線
- 倉庫：`we88ec3-prog/ttr_anal_multi`，基準 `main`：`d0fce702b42c89cd8ba2fd077ddbdfde341da19f`（本輪開始時核對）。
- 主要新來源：`shared/integrations/T01-20261028-06/{README.md,resource-source-audit.json,pending.json,NEXT-QUERIES.md}`；`kr/tasks/T16/{README.md,task.json}`；既有 `kr-temp-roy/T16-1…40` 原稿。
- KR 原始 BIN：`/mnt/data/Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪重新以本機 sha256sum 核對。EXE SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- 資源稽核紀錄源自 T01 靜態讀取與校驗，**不是本輪已讀取資源內容全文**。`kr-temp-roy/T16-local-20261028/evidence/resources/...` 是歷史本地工作區路徑，未出現在目前 GitHub 同路徑；GitHub 的 `kr/evidence/<SHA>.txt` 具有非 UTF-8 內容，現有 UTF-8 fetch 介面拒絕，不能據此假稱本輪已還原其欄位或 Lua 指令。這是 **ACCESS-BLOCKED-RAW-CONTENT**，不是「資源不存在」。
- 證據等級：**S**=可讀原始內容與直接來源核對；**B**=原生 BIN 指令直接證明的有限事實；**A**=T01 來源/解碼/SHA 稽核事實；**H**=歷史研究待交叉驗證；**U**=尚未證明。不得把 A/H 提升為 S。
- KR/TC 必須隔離；歷史 fixture、模擬服及 005F type6 本地修補不等於原生規則。原件唯讀；不執行客戶端或歷史程式，不更改其他 task 的 owner/catalog。

## 直接新增的來源資訊
T01 `resource-source-audit.json` 記錄 `Event.stp`（KR）SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`，大小 11,241,597 bytes。成員：

| 名稱 | SHA256 | 封裝 raw offset | stored size | Lua 靜態驗證 |
|---|---|---:|---:|---|
| `Event/TutorialBase.lua` | `26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744` | 10,645,520 | 1,416 | 6 prototypes／72 instruction words |
| `Event/TutorialMain.lua` | `662f8416ac7f865b94b15d6ea3145e9a59fbbbaaa8e3be6521c4cff636344809` | 10,647,568 | 5,480 | 11 prototypes／558 instruction words |
| `Event/qbase.lua` | `d6e01d85194f452d56961252d797a0e671d7e34a11fe07e96155220f27ee4cc3` | — | — | 76 prototypes／906 instruction words |

以上 Lua 指令數是 `lua_static_validation` 所保存的**反組譯核對結果**，不是教學任務步數；`full_consumption_and_saved_code_match=true` 代表來源解碼消耗與保存的 code 一致，不代表每一條業務分支已解釋。T01 宣稱可從封裝獨立重解成員並比對，來源文字在本輪 GitHub 介面仍不可見。

## 與 KR BIN 的狹義交叉核對
| BIN VA | 舊研究所見 | 目前可支撐的意義 | 不得推論 |
|---|---|---|---|
| `0x004A89AF` | 路徑為 `TutorialBase.lua`，經 `0x006F4A50` 腳本載入 | 有對應真正資源成員且 SHA 確認 | 腳本的所有全域函式、任務關閉條件 |
| `0x004A8A31` | `TutorialMain.lua` 和 `Synopsis_EntryPoint` | 有不同的具名調用入口 | `Synopsis` 等同結束教學 |
| `0x004A8B5F` | `TutorialMain.lua` 和 `Tutorial_EntryPoint` | 客戶端存在第二個具名入口 | 進入即代表任務重設、已完成 |
| `0x006F4A50` | 原生讀取、BOM/parse 路徑 | 腳本檔進入 Lua VM 的一般介面 | 任務流程由此函式決定 |
| `0x006F4DD0` | 命名 Lua 函式查找與執行 | VM bridge 的責任邊界 | 伺服器端權威已確認 |

## 教學流程分解為可驗證的最小證據任務
1. 取回靜態 Lua JSON 或原始 chunk bytes，以**版本 SHA** 作識別；枚舉 11 個 TutorialMain 與 6 個 TutorialBase prototype 的 parent/child、常數表、全域讀寫與分支地址。
2. 建立 Lua 層 node/event 表：entry、condition、callback、UI prompt、jump-to、terminal；沒有明確語意即 `unknown`。
3. 與 `qbase.lua` 的 76 個 prototype 分辨共用 helper 與教學專屬呼叫；避免由名稱猜 `QuestComplete` 的網路權威。
4. 將每個 Lua 事件映射到 `0x006F4DD0` 的 caller 或遊戲內註冊 handler，若無直接來源記 `unknown`。
5. 針對教學尾端保留 `Scenario14 -> TUTO -> Quest16` 為**整合追查目標**，不能把它當已完成的原版狀態機。

## 明確結論與未解事項
- **已確認 A**：兩個 KR Lua chunk 在 Event.stp 中有特定 SHA／offset；各自 prototype/word 數有稽核記錄。KR 與 TC Lua hashes 不同（TC TutorialMain `c235ac4959f21925c207d4e9a746c2fac473c54a0d1ea7144f12d6b33300f938`），不得共享完整流程。
- **部分確認 B/H**：VM 入口與具名符號橋已由前述原生 BIN 研究找到。
- **未完成 U**：Lua 具體事件序列、每一步成功判定、tutorial terminal/writer、重新進入與中斷續接。
- **後續必要原件**：保存的 `kr-TutorialMain.lua.json`、`kr-TutorialBase.lua.json`、`kr-qbase.lua.json` 或經 SHA 核對的 Lua chunk bytes；勿用未驗證的自然語言教學攻略取代。