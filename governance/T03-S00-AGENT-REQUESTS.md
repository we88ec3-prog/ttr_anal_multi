# S00 → T03：登入/選服/角色清單/選角/教學場景定向研究交接

日期 2026-10-29。基準：`codex/s00-t01-phase-a-20261029`；原始資料分支 `extra/roy1@44a610968a228d4104e39457891e4fc565a3790c` 的 E01–E16 已**原檔保留**在 `kr-extra-roy/`。仍須遵守原本 T02/T03/T05/T06/T07 主責。

## 先讀這些，不重做已結論的部分

1. [S00 流程草案](../spec/session-account/SPEC-FLOW-0001.md) 與 [T03 SceneList/Lua 有界依賴](../spec/world/SPEC-SCENE-0001.md)。
2. [原研究分支增量及後續修正](PHASE-B-T03-EXTRA-ROY1.md)：E06、E08、E13→E14→E15→E16 的修正與反證。
3. [T03 主責研究](../kr/tasks/T03/README.md)；[T02 與連線/分派](../spec/protocol/T02-EVIDENCE-INVENTORY.md)。
4. [來源主張索引](../research/claims/index.json)：CLM-AUTH、CLM-CHAR、CLM-NET、CLM-SCENE；均有明確 PARTIAL 限制。

## 最小有效研究問題（只需 Server 相容所需）

**P0 — RR-0002 / GAP-CHAR-0001：**依現有 command2/選角 C2S=42 研究，找 Client 真正接收的選角成功／失敗 S2C handler、命令號、必要欄位、狀態 gate 與回覆先後。不要臆造 42→43、42→69 或簡單 request+1。

**P0 — RR-0003 / GAP-AUTH-0001：**確認 0x13 登入結果真正來自哪個命令路由、status 欄位/群組陣列合法邊界、選服後第一個 Server 必須回覆的訊息，依證據填入 flow 而非逐步猜。

**P0 — RR-0005 / GAP-NET-0002：**將登入結果與 T02 `0x495610/0x4957C0` Connect 分支對起來，明確指定 slot、pipeline、切線條件、第一個 C2S 與 S2C 消息；port 8414/8415/8416 是已見靜態常數而非官方即時權威。

**P1 — RR-0008 / GAP-SCENE-0001：**從「已確認的選角 S2C handler」追其 state writer 是否到 `0x47B5C0` 的 `[object+0x248]`，是否調用 `0x565720` 並提供 `(questIdx,sceneIdx)`；對照 E16 中 `EndCutScene` 的同入口復用。找不到則保留 UNKNOWN，不設 `(1001,1)` 為官方初登參數。

## Agent 分工

無 REA Agent：首先比對 E13/E14/E15/E16 更正、T03 既有證據與 slot/state/gate，直接交付可稽核索引和精確缺口。只有需要原始 BIN 新呼叫邊、間接 writer、未知 S2C handler 才交桌面 REA Agent。**不能因有 REA 而重新跑已完成的 E01–E16。**

## 請交給 S00 的輸出

每項都要有 Client 原始 SHA、exact source path/blob、函式/offset/資料方向、**已確認 vs 未證實**、Server 影響、受影響 SPEC/GAP、反例、測試/重現條件。非原生 Server 帳號與首登政策另建 ADR；不寫進 Client 原生結論。未經本次明確授權不執行/修改原始 Client 或推送其他 Task 的研究正文；這一階段仍未啟用外部 Issues。

**停止條件**：以最小可用 C2S/S2C / Session 狀態閉環為優先，不以閱讀原稿數量或逆向函式覆蓋率作成功指標。
