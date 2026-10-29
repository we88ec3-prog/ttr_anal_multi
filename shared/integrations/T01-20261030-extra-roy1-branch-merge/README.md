# 2026-10-30 — `extra/roy1` → `main` 正式 Git Merge 整合收據

**整合類型：保存 Git 雙親歷史的真正 Merge，僅收納原始研究 Markdown。不是 S00、T01、RR 的原生內容驗收。**

## 分支與精確快照

- Repo：`we88ec3-prog/ttr_anal_multi`
- 整合前 main：`b333883409e7895c0a1ebb67b71346b499804c2a`
- 整合前 extra/roy1：`29f3c50ff64d8f788d05d9846dbaac17b4e27745`
- 共同祖先：`5cb495f4561833e0a123bbded14b76266ac1f201`
- 比對顯示 extra/roy1 **ahead 51 commits、behind 40 commits**。
- 完整差異：**37 個 added、0 modified、0 deleted、0 conflict**；全在 `kr-extra-roy/`。檢查兩棵目錄 Git tree，既存相同路徑的 blob SHA 均未更動。
- 做法：以 main 原樹為主，直接引用 extra/roy1 原 Git blob SHA 新增 37 檔，新增本收據與 [精確 37 筆檔名／SHA manifest](manifest.json)；建立第一父 main、第二父 extra/roy1 的合併 Commit。原作者研究原稿完全保留。
- 未修改 `AGENTS.md`、Task README/task.json、RR 台帳、CLAIM、S00 SPEC/GAP/TEST、shared verified-knowledge；不覆寫任何先前 main 上的 T01 已審核版本。

## 本次納入的研究

新增研究涵蓋 RR-0001／0004 frame/send scheduler 與 mode boundary、RR-0005 登入／選服→Connect、IOCP async I/O、連線關閉及 pool 回收、以及 RR-0008 Scene key writer/caller。來源最末段為：

- [E50：同 key map replacement、Pool+48／Pool+28、Conn+A0B8 Interlocked I/O、S2C 長度下界](../../kr-extra-roy/20261030-022552-chatgpt-web-roy-E50-RR0005-map-replacement-pool48-atomic-IO-lifecycle.md)
- 精確原始 E50 Git blob：`f4bd62ce69cf96cc35b566bf62721a586f4f51c7`，來源原稿 96370 bytes。

以上為**來源作者的限定研究主張**，並非此次 Git Merge 做過所有函式、上下游、錯誤路徑與 wire 封包的獨立原生驗收。

## 未變更的權威狀態

- 開工核對 `research/requests/index.json`（main blob `6f652f1b763a4198bbc580f86cb9f7703001ffc3`），RR-0001～0008 仍是主線原始台帳。來源 E50 明言 RR-0005 `PENDING/QUEUED`、尚無正式認領；本 Merge **不進行 CLAIMED、SUBMITTED、IN_REVIEW、ACCEPTED 等轉移**。
- E50 明列未完成「相同登入 first wire/Server reply、舊 Conn 所有權、所有非同步 I/O 路徑平衡、handler 長度下界」，故保留 **Client 待逆向**；Server 原版內部規則不可由限定 native 間接推出。
- 現有其他 Task 原稿與 T01 認定保留；即使合併原稿包含 BIN-first assembly，也不能自動成為 FULL-PASS 或 `NATIVE_VERIFIED`。
- **Server 待開發**：相容登入/回覆語義、失敗流程及持久化後續依 S00 的 SPEC/ADR 分別設計。
- **跨功能待整合**：T02 與 T03/T16 及 S00 的來源依賴仍須按 source SHA 與 claims 整合。
- **待遊玩驗證**：沒有啟動原版 Client、操作真實 Server 或完成動態封包驗收。
- 此次僅提供安全、可追溯的原稿 merge，沒有製作新的 Server 規格或替代既有 T01 審核。

## Git 原件驗證方法

來源 Tree `dcfa8ef5ae5fb701731b134c70a9883210a2759c` 與主線原 `a265879a7d5a5e15f4901989e32bd3b70648ead7` 的 `kr-extra-roy` 檔名與 blob SHA 比較，新增 37 檔均屬 `100644 blob`；GitHub compare 亦回傳全 37 `added`。所有新檔直接以原 blob SHA 建 tree，**未改動文字、未轉碼、未重建任一原稿**。檔案與 bytes 見 manifest；發布後需遠端比對 Merge parents、source-tree blob 與正式 RR 台帳不變。
