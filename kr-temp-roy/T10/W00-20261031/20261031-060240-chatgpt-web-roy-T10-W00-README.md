# T10-W00 — 原版 KR 七筆 T01 退回勘誤：可複驗交付索引

日期：2026-10-31（Asia/Taipei）；目標原件 `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。唯讀 GNU objdump x86 + Python bytes/hash 比對；不執行、修改、連線遊戲。

此目錄的修正是 T10-W00 在使用者授權下提交的原生證據修復包；**保留原始 7 篇原稿不覆寫，也未自行調整 T01 狀態為 RESOLVED / FULL-PASS**。

| 通知 | 舊 Git blob | 勘誤 | 修正核心 |
|---|---|---|---|
| `T01-RETURN-T10-116-ROW5-PROVENANCE-001` | `8da51d9e77d3d900bc73743bddc82891f6829c15` | [20261031-060240-chatgpt-web-roy-T10-W00-116-correction.md](20261031-060240-chatgpt-web-roy-T10-W00-116-correction.md) | 000A Row A/B callback/row[4]/ESP def-use |
| `T01-RETURN-T10-055-EVIDENCE-001` | `61c1e3bca931c781be72db549bed483202cfff1a` | [20261031-060240-chatgpt-web-roy-T10-W00-055-correction.md](20261031-060240-chatgpt-web-roy-T10-W00-055-correction.md) | 錯位 x86 指令視窗 |
| `T01-RETURN-T10-056-EVIDENCE-001` | `e2da2b34e1c97aeffd192d5af7a258f80b50c527` | [20261031-060240-chatgpt-web-roy-T10-W00-056-correction.md](20261031-060240-chatgpt-web-roy-T10-W00-056-correction.md) | 偽 CALL 撤回 |
| `T01-RETURN-T10-062-001` | `43ca57972ac64ad0752ce37c419331ff120befda` | [20261031-060240-chatgpt-web-roy-T10-W00-062-correction.md](20261031-060240-chatgpt-web-roy-T10-W00-062-correction.md) | 40-byte clear 優先於特殊樹 init |
| `T01-RETURN-T10-063-001` | `82b83636f00ded1be14216c7529a686fad331a16` | [20261031-060240-chatgpt-web-roy-T10-W00-063-correction.md](20261031-060240-chatgpt-web-roy-T10-W00-063-correction.md) | writer 無 reader 的 ESI<=27 gate |
| `T01-RETURN-T10-007-001` | `d99588c94a6647acffb036ef497b66377d22e200` | [20261031-060240-chatgpt-web-roy-T10-W00-007-correction.md](20261031-060240-chatgpt-web-roy-T10-W00-007-correction.md) | pointer load vs WORD store |
| `T01-RETURN-T10-026-001` | `c82bc8c3c53f304faecab0911f214b89440d1784` | [20261031-060240-chatgpt-web-roy-T10-W00-026-correction.md](20261031-060240-chatgpt-web-roy-T10-W00-026-correction.md) | 549980 / 549C60 函式邊界 |

## 可複驗原始資料

- [30 項精確 bytes asserts／11 個 SHA256 來源窗口](20261031-060240-chatgpt-web-roy-T10-W00-native-byte-audit.json)，皆已在本次上傳的原件通過。
- `T10-116` 的具體 Row B 矩陣、Row A `S+18`/ `S+38` 別名、虛函式 `ret 8/12` 及 `0x546100`、`0x546EF0` 來源已獨立記錄；更進一步指出 virtual44 可寫 output+4，不能把 E4 初始化擴大為每條 runtime 的固定終值。
- 055/056、062、063、007、026 的過度主張分別撤回，只保留有 BIN 支持之局部結果。這些不是遊玩、Server 權威、技能時窗或完整 C→S↔S→C 語意驗收。

## W00 交付與後續（按不同驗收階段區分）

**W00 原稿交付：7/7 已建立新增勘誤；原生機器碼錨點 30/30 檢查 PASS。** T01 需要逐項對受影響肯定主張、CFG、caller/callee、實際多型 owner、及本修正版本做**正式重驗**，通過後才可依既定退回流程標 RESOLVED。保留所有歷史 SOURCE SHA；RR、T11/T02/T12 主責、shared verified-knowledge、SPEC/GAP/TEST 未在本批變更。

仍未完成之 Client 靜態研究：完整 polymorphic callback/高 WORD、000A 是否某玩家按鍵的直接 wire 結果、S2C ACK/remote motion、取消/連段時窗。純 Server-only 未知應交 S00 依既有規格，不以此當停止可推進 Client 逆向的理由。W01/W02 請復用勘誤而非已被反證的固定 B0/函式範圍。
