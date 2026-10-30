# T10-107 — 兩套 T10-101/102 與 T10-103～106 合併後證據整合（非新原生段落）

## 性質和來源
本檔為**合併後比較／勘誤導覽**，不虛構已完成新的大型 BIN-first 研究段落；正式原稿保持唯讀。2026-10-28（Asia/Taipei）研究分支 `t10/roy/chatgpt-web` 接收 `roy/t10-101-103-20261028`，GitHub PR #4 merge commit `0b6f61e56a345085cad6121ce04bc27c5e3b9b8d`，比較來源分支到工作分支 behind=0；main 沒有被當作合併目標。現有實體 KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本次重新計算）；以下新資料流主張以已合併 Markdown 的第一手 BIN assembly 摘錄為依據，**這一份比較文件本身未重反組譯或重新審核全部 assembly**。舊原稿及新原稿各自的原生驗證界線維持。

## 原稿索引與重號原因
- 工作分支既有 `20261028-200349-...-T10-101-KR-virtual-dispatch-second-domain.md`：`0x5961C0` 29個函式表指標候選、`0xFDF624` 第二事件域、成功結果 append；尚缺 caller/producer/socket。
- 工作分支既有 `20261028-201500-...-T10-102-KR-event-container-cleanup-and-caller-matrix.md`：`0x5960B0 → 0x596C90`、owner+0xC0/+0xD0/+0xE0 三容器回收。
- 此次合併 `20261028-1843-...-T10-101-phase-writer-consumption-and-transport.md`：普通 phase 非零 writer 與事件結果消耗、邏輯 ID13→C2S000A 的有條件鏈。
- 此次合併 `20261028-1855-...-T10-102-directinput-key44-and-battle-tick-order.md`：DirectInput Keyboard、Key44=DIK_Z、UI消耗先於戰鬥tick的一條路徑。
- 此次合併 `20261028-1906-...-T10-103-input-skill-matrix-and-tick-countdown.md`：controller bit 組合、SkillMatrix 列欄及 tick 計數。
- 此次合併 `20261028-1914-...-T10-104-actor-3e8-property4-and-force-effect.md`：actor+3E8 與派生 property4 的本地效果。
- 此次合併 `20261028-1919-...-T10-105-paramupdate-handler-and-property-dispatch.md`：資料 buffer 的 `2+6N` 列解析及 actor setter。
- 此次合併 `20261028-1942-...-T10-106-queue-header-key-and-dispatch-bases.md`：queue record→`0x4930E0`→`0x48AAD0`→active state→ParamUpdate 的條件分派鏈。

## 新舊主張差異及整合處置
| 議題 | 原有 101/102 | 合併原稿新增證據 | 整合評級／不應越界 |
|---|---|---|---|
| phase1/2/3 來源 | 只見 `0x6D4CE0` reader 和清零，非零 writer 未定位 | `0x4914AC` 固定 ECX=`0xFB8830` 調用 `0x6D1480`；`+0x7D4` 為 `0xFB9004`，old/new 對應 1/2/3 | **新補證，不是矛盾**；override vector producer 仍不明 |
| 結果列表作用 | `0x596351`/`0x596570` 追加12-byte node，未知 consumer，明確否定直接當 combo queue | 合併101記 `0xF95CD8`、`0x74F780` dispatch、`0x490D40→0x6D4A30` 依事件結果清 phase、`0x750550` 釋放 | **新補證**：有條件的消耗／去重，不是連段排程 |
| 事件 dispatch 可達性 | 29處 vtable/table pointer 候選、+0xEC/+0xF0 callback | 合併101追 `virtual+0x16C` 及實例候選表與 caller | **新補證**，只對已證 owner/table 成立 |
| Z 與 Key44 | XML Key44/ID13 是 Z 的候選，未完整驗證裝置 | 合併102追 DirectInput GUID_SysKeyboard、256-byte GetDeviceState、DIK_Z=0x2C | **新補證**，實際工作 bank/自訂鍵位仍未知 |
| Z→上行 | 未證發包 | 合併101/102 有條件地追 ID13 phase1/2→controller bit0→row→C2S `0x000A` 路徑 | **部分確認**，不等於每按一次必送一包、opcode頻率/值都已閉合 |
| 技能矩陣與計時 | 舊101/102未分析 | 合併103 `54F270` column優先序、SkillMatrix `row*11+column`、tick decrement | **新補證**，不等於原版 combo 毫秒窗口 |
| 角色+3E8與回覆 | 舊稿沒有 S2C 真正閉環 | 合併104～106 提供 property4 actor setter、ParamUpdate buffer 及 queue header key0 應用分派 | **新補證但仍有缺口**：socket framing/queue enqueue 未完全閉合；key0不直接升格wire opcode；與Z普攻因果未知 |
| 清理三容器 | 舊102有 `0x596C90` 三容器證據 | 合併101～106主要研究其他資料流，沒有足以直接否定三容器鏈 | **並行保留**，不得把 cleanup 等同攻擊取消 |

## 合併後玩家情境驗收矩陣
| 情境 | 現有 Client 已證/部分證 | C→S | S→C→動作 | 未完成 |
|---|---|---|---|---|
| 預設映射、鍵盤 Z 短按 | DirectInput索引、logical phase、controller bit0 和批次路徑有條件接通 | `000A` **有條件上行**；次數、必要gate未知 | 仍無 Z 專屬接受/拒絕→motion 閉環 | 實際 bank、UI攔截、完整 socket 寫出與回應 |
| 持按／連按／放開 Z | logical phase2/3 已有 producer | 個別時序/批次/抑制仍未知 | 連段／取消時窗未知 | 完整 per-frame dataflow、封包抓取或既有原生 handler 定位 |
| 施放中再次 Z | matrix、actor狀態 gate 局部已找到 | 不能保證立即/延後/不發包 | 未閉合 | 前後搖、技能 phase、server 裁決 |
| 施放中鍵盤與滑鼠移動 | 兩種 producer 尚未分別閉合 | 未知 | 未知 | 各自的輸入與雙向同步路徑 |
| 類別2 queue 且 header key0 | 有界通向 ParamUpdate，property4 可修改派生 actor+3E8 | 非上行結論 | **部分收到的資料消費鏈**，但不證實為 Z 的回覆 | socket→queue producer；handler 真實 wire key 來源 |

## 重大新結果與後續決策
此次來源分支的 101～106 對**先前尚未定位的 phase writer、DirectInput producer、C2S000A有條件鏈與 queue→ParamUpdate 有界鏈**提供實質增量；應視為新的研究結果並納入長期理解。沒有原稿名稱相同而內容衝突到須刪改舊稿的情況，兩個 T10-101 和兩個 T10-102 互補並存。**本檔編為 T10-107 僅供避開重號及記錄整合結果，不冒稱為另一次新的 BIN-first 大型批次。**

下一步研究應從 **T10-108** 起（若以本整合補號作 107），優先驗證 `0x4930E0` 的 queue record 從 socket 收包到 enqueue 的真實來源，再追 C2S000A 的發送最終出口、local/remote actor motion及技能中分別移動；不重複已證的 generic cleanup。尚未有本次新增完整遊玩閉環，不能設 native_complete。

## GitHub 權限
本輪 GitHub 實際寫入只限使用者明確指定的 **source→T10 分支 merge**。此整合核對原稿依既有規範先保留本地，除非使用者另外授權，不直接 commit/push。本輪未改 main、其他 Task、task.json、owner、catalog。