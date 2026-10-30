# T16-064 — T01 原始審核退回勘誤（新增文件，不改原稿）

建立時間：`2026-10-29T21:21:45.967286+08:00`；版別 `KR`。

## 精確來源及適用範圍

- 原稿：`kr-temp-roy/20261028-110252-chatgpt-web-roy-T16-64-KR-end-to-end-quest16-quest15-evidence-gates.md`
- **舊原稿 Git blob SHA**：`dee3295e7cdde882aae96b277d224160420608c8`
- T01 通知：`T01-RETURN-T16-064-89ddf3e8`
- first-party BIN SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- **未取得新 Git blob SHA，因為沒有上傳 GitHub**。本勘誤對 source claims 的修正只在明列範圍生效。

## 修正內容


### TutorialBase 原始資料來源／hash 修正 — `T01-RETURN-T16-064-89ddf3e8`

- 歷史原稿使用的 56-hex 偽 SHA：`26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744`，**不是合法 SHA256**。
- T01 carrier-bound 解碼記錄中的 member SHA256：`26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744`（64 hex；1,416 bytes，6 prototypes，72 instruction words；此為 **T01 已核對來源**，本次沒有直接獲得該原始 Lua member 重新 hash）。
- 將本原稿所有錯誤 SHA、來源表、未解清單、交接複述依實際檔案出處更正；歷史 API 取得 404 **只表示當時該路徑不可讀**，不能宣稱原始 member 永遠缺失。
- 查閱 `shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json`、`resource-recheck.json` 與 carrier bound metadata；需逐項修正任何據「404」推論的資料不可得結論。
- **不提高**：原始 Server Quest16→15 決策、C→S/S→C wire、整個 Lua scripts、任何未逐條驗過的 prototype semantic。

## 修正影響／驗收門檻

- **Client 待逆向**：此勘誤沒有證成任何新的 Quest S→C wire opcode 或 Quest16→15 接取 UI 閉環。
- **Server 待開發**：相容 Server 的任務前置、解鎖、持久化由 S00 SPEC/ADR 獨立設計，不可由局部 ASM 冒稱官方判斷。
- **跨功能待整合**：如涉及 T02 framing/網路、T06 UI 等，由相關 Task 的原始證據及 T01 claim-level review 處理。
- **待遊玩驗證**：未執行原 Client 或動態封包測試。
- **T01 狀態**：GitHub 仍為 `NEEDS_FIX`/`NEEDS_QUALIFICATION`；待來源 Task 將此勘誤審核／提交後，才能提出 `READY_FOR_REVIEW`，且 T01 通過才可 `RESOLVED`。

## 原始來源／交叉引用

- `kr/tasks/T16/README.md` 上固定退回 ID 和精確 blob SHA。
- `shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json`；`shared/integrations/T01-20261029-continuation-02/t16/README.md`。
- `shared/verified-knowledge/README.md` 的有界條目不等於本篇 FULL-PASS。
